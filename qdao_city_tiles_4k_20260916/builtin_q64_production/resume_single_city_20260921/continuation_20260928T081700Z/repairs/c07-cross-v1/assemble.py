from pathlib import Path
import sys, json, hashlib
from datetime import datetime,timezone
import numpy as np
from PIL import Image,ImageDraw

out=Path(__file__).resolve().parent
session=out.parents[2]
art=session.parents[1]
mode=sys.argv[1] if len(sys.argv)>1 else 'initial'
assert mode in ['initial','limited4','third-limited4']
if mode!='initial':
    out=out/mode
    out.mkdir(exist_ok=False)
tool=art/'builtin_q64_production/tools/mechanical_join.py'
sys.path.insert(0,str(tool.parent))
sys.path.insert(0,str(session/'tools/vendor'))
from mechanical_join import registered_join
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
source=session/'next_tile_r08_c07/continuation-20260923/qa-repair-20260923/repaired-v1/r08_c07.png'
repairs=Path(__file__).resolve().parent.parent
native=repairs/('c07-cross-1024-1024.native.png' if mode=='third-limited4' else 'c07-cross-2048-3072.native.png')
assert sha(source)=='7e60bc705c1b750cad18bffa9f486f7be680835c1ee3bf0f692f0202325699e6'
assert sha(native)==('6d307ab0ef51bc97c801b0bd1193e4a602bf8dd251cd95c201ccd2d81a5887c9' if mode=='third-limited4' else '762725311f0c44dfac2c7d595090db1a363eb91cd6240852dfee94b641382763')
rect=(397,397,1651,1651) if mode=='third-limited4' else (1421,2445,2675,3699)
source_im=Image.open(source).convert('RGB')
context=np.array(source_im.crop(rect)); raw=np.array(Image.open(native).convert('RGB'))
assert raw.shape==context.shape==(1254,1254,3)
yy,xx=np.mgrid[:1254,:1254]
dist=np.minimum.reduce([xx,yy,1253-xx,1253-yy])
a=np.clip((dist-32)/112,0,1)
a=a*a*(3-2*a)
mask=np.rint(a*255).astype(np.uint8)
joined,flow,correction,mechanical=registered_join(context,raw,mask,max_shift=8.0 if mode=='initial' else 4.0,flow_inner=300.0,flow_full=120.0,tone_inner=330.0,tone_full=150.0,match_tone=True)
Image.fromarray(mask).save(out/'mask.png')
Image.fromarray(joined).save(out/'joined-native.png')
candidate=source_im.copy();candidate.paste(Image.fromarray(joined),rect[:2]);candidate.save(out/'r08_c07.png')
ca=np.array(candidate); orig=np.array(source_im)
unchanged=ca==orig
changed=np.any(~unchanged,axis=2); ys,xs=np.where(changed)
assert not changed[:rect[1]].any() and not changed[rect[3]:].any()
assert not changed[:,:rect[0]].any() and not changed[:,rect[2]:].any()
def board(name,crops):
    width=max(c[1][2]-c[1][0] for c in crops)
    height=sum(c[1][3]-c[1][1]+30 for c in crops)+12
    im=Image.new('RGB',(width+24,height),'#191f20');d=ImageDraw.Draw(im);y=12;items=[]
    for label,r in crops:
        d.text((12,y),label,fill='white');y+=24
        im.paste(candidate.crop(r),(12,y));items.append({'label':label,'rectLTRB':r,'boardXY':[12,y]});y+=r[3]-r[1]+6
    path=out/(name+'.png');im.save(path);return {'file':str(path),'sha256':sha(path),'pieces':items,'nativeNoScale':True}
boards=[]
# entire transition belt each side, wider than the 330px correction zone
L,T,R,B=rect
boards.append(board('qa-top-bottom', [('top belt',(L-41,T-45,R+41,T+345)),('bottom belt',(L-41,B-359,R+41,B+41))]))
boards.append(board('qa-left-right',[('left belt',(L-41,T-45,L+349,B+41)),('right belt',(R-350,T-45,R+41,B+41))]))
record={'schemaVersion':1,'createdAtUtc':datetime.now(timezone.utc).isoformat(),'kind':'local native overlap repair experiment, unselected until reviewed','source':{'file':str(source),'sha256':sha(source),'pixels':[4096,4096]},'nativeReturn':{'file':str(native),'sha256':sha(native),'pixels':[1254,1254],'actualModel':None,'actualQuality':None,'notResized':True},'sourceRectLTRB':rect,'tool':{'file':str(tool),'sha256':sha(tool)},'mechanicalJoin':mechanical,'mask':{'file':str(out/'mask.png'),'sha256':sha(out/'mask.png'),'rule':'distance to all 4 source rectangle edges; alpha=0 at distance<=32; smoothstep((distance-32)/112), alpha=255 at distance>=144; single composite only','compositePassCount':1,'noSecondFeather':True},'candidate':{'file':str(out/'r08_c07.png'),'sha256':sha(out/'r08_c07.png'),'pixels':[4096,4096]},'joinedNative':{'file':str(out/'joined-native.png'),'sha256':sha(out/'joined-native.png'),'pixels':[1254,1254]},'actualChangedBoundsLTRB':[int(xs.min()),int(ys.min()),int(xs.max()+1),int(ys.max()+1)],'changedPixelCount':int(changed.sum()),'outsideRectangleUnchanged':True,'qaBoards':boards,'formalArtAcceptancePassed':False,'allSeamsMustBeRecheckedAfterCombination':True,'sharedRecordsModified':False,'sourceShaAtEnd':sha(source)}
(out/'assembly.json').write_text(json.dumps(record,ensure_ascii=False,indent=2),encoding='utf-8')
print(json.dumps({'candidate':record['candidate'],'mechanicalJoin':mechanical,'actualChangedBoundsLTRB':record['actualChangedBoundsLTRB'],'qaBoards':boards},ensure_ascii=False))
