from pathlib import Path
from datetime import datetime,timezone
import sys,io,json,hashlib
import numpy as np
from PIL import Image,ImageDraw
base=Path(__file__).resolve().parent
out=base/'cumulative-v1';out.mkdir(exist_ok=False)
session=base.parents[2];repairs=base.parent
tool=session.parents[1]/'builtin_q64_production/tools/mechanical_join.py'
sys.path.insert(0,str(tool.parent))
from mechanical_join import registered_join
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def pngsha(im):
    b=io.BytesIO();im.save(b,format='PNG');return hashlib.sha256(b.getvalue()).hexdigest()
candidate=Image.open(base/'limited4/r08_c07.png').convert('RGB')
initial=sha(base/'limited4/r08_c07.png')
assert initial=='956cb34c3248f2a7f7336d500e6d2da0fe67a78341ae8bc31bf04e6b7cf42d61'
yy,xx=np.mgrid[:1254,:1254];d=np.minimum.reduce([xx,yy,1253-xx,1253-yy]);a=np.clip((d-32)/112,0,1);mask=np.rint(a*a*(3-2*a)*255).astype(np.uint8)
steps=[]
third=Image.open(base/'third-limited4/joined-native.png').convert('RGB')
candidate.paste(third,(397,397))
steps.append({'id':'third-x1024-y1024','parentSha256':initial,'outputTransientPngSha256':pngsha(candidate),'operation':'paste already composited native rectangle once; no second feather; disjoint from initial region','input':{'file':str(base/'third-limited4/joined-native.png'),'sha256':sha(base/'third-limited4/joined-native.png')},'sourceRectLTRB':[397,397,1651,1651]})
jobs=[('carving-v2','c07-carving-vertical-v2.native.png','0a457007f2340687f0c1dc32f9b9a08ba79b86e514a8c86af8b1a3cc216080a7',(2445,397,3699,1651)),('fourth-x2048-y2048','c07-cross-2048-2048.native.png','8719a5bc4b8d364c67527f07dd58ad0c040be9af0e5ac8f4cb377ebe4b35bc13',(1421,1421,2675,2675)),('fifth-x3072-y3072','c07-cross-3072-3072.native.png','2bcd401d19987daeedd3cfc595ecad023f89a53bf04c3154ef4e312ccfe3bf3c',(2445,2445,3699,3699))]
for id,name,expected,rect in jobs:
    native=repairs/name;assert sha(native)==expected
    parent=pngsha(candidate);before=np.array(candidate)
    ctx=np.array(candidate.crop(rect));raw=np.array(Image.open(native).convert('RGB'));assert raw.shape==ctx.shape==(1254,1254,3)
    joined,flow,corr,report=registered_join(ctx,raw,mask,max_shift=4.0,flow_inner=300.0,flow_full=120.0,tone_inner=330.0,tone_full=150.0,match_tone=True)
    candidate.paste(Image.fromarray(joined),rect[:2]);after=np.array(candidate)
    changes=np.any(before!=after,axis=2);L,T,R,B=rect
    assert not changes[:T].any() and not changes[B:].any() and not changes[:,:L].any() and not changes[:,R:].any()
    steps.append({'id':id,'parentSha256':parent,'outputTransientPngSha256':pngsha(candidate),'input':{'file':str(native),'sha256':expected,'pixels':[1254,1254]},'sourceRectLTRB':rect,'contextSource':'immediately previous cumulative candidate, never original baseline','mechanicalJoin':report,'changedPixelCount':int(changes.sum()),'outsideRectangleUnchanged':True,'singleCompositeMask':{'zeroUntilDistance':32,'fullAtDistance':144,'curve':'smoothstep','compositePassCount':1}})
    print(json.dumps({'step':id,'sha':steps[-1]['outputTransientPngSha256']}),flush=True)
candidate.save(out/'r08_c07.png')
regions=[('first',(1421,2445,2675,3699)),('third',(397,397,1651,1651))]+[(id,rect) for id,_,_,rect in jobs]
boards=[]
for id,rect in regions:
    L,T,R,B=rect
    p=out/(id+'-final-context.png');candidate.crop(rect).save(p)
    # all four complete transition belts, native 1:1; captions are outside source pixels
    h=Image.new('RGB',(1360,866),'#191f20');dr=ImageDraw.Draw(h)
    strips=[(L-41,T-45,R+41,T+345),(L-41,B-359,R+41,B+41)]
    for i,r in enumerate(strips):
        dr.text((12,12+i*420),id+(' top' if i==0 else ' bottom'),fill='white');h.paste(candidate.crop(r),(12,36+i*420))
    hp=out/(id+'-top-bottom.png');h.save(hp)
    v=Image.new('RGB',(810,1400),'#191f20');dr=ImageDraw.Draw(v)
    stripsv=[(L-41,T-45,L+349,B+41),(R-350,T-45,R+41,B+41)]
    for i,r in enumerate(stripsv):
        dr.text((12+i*403,12),id+(' left' if i==0 else ' right'),fill='white');v.paste(candidate.crop(r),(12+i*403,36))
    vp=out/(id+'-left-right.png');v.save(vp)
    boards.append({'id':id,'rectLTRB':rect,'context':{'file':str(p),'sha256':sha(p)},'topBottom':{'file':str(hp),'sha256':sha(hp),'sourceRects':strips},'leftRight':{'file':str(vp),'sha256':sha(vp),'sourceRects':stripsv},'allSourcePixelsUnscaled':True})
record={'createdAtUtc':datetime.now(timezone.utc).isoformat(),'initialCandidate':{'file':str(base/'limited4/r08_c07.png'),'sha256':initial},'tool':{'file':str(tool),'sha256':sha(tool)},'script':{'file':str(Path(__file__).resolve()),'sha256':sha(__file__)},'steps':steps,'candidate':{'file':str(out/'r08_c07.png'),'sha256':sha(out/'r08_c07.png'),'pixels':[4096,4096]},'qaBoards':boards,'status':'working_candidate_pending_local_review_not_selected','formalArtAcceptancePassed':False,'actualModel':None,'actualQuality':None,'sharedRecordsModified':False,'retention':'Intermediate cumulative PNG bytes were only held in memory; hashes identify deterministic PNG encoding at each step. Original native returns remain intact.'}
(out/'assembly.json').write_text(json.dumps(record,ensure_ascii=False,indent=2),encoding='utf-8')
print(json.dumps(record['candidate']))
