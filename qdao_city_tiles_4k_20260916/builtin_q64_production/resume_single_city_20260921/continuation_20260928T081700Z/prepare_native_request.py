import argparse, datetime, hashlib, json
from pathlib import Path
from PIL import Image

p=argparse.ArgumentParser(description='Prepare exact native source crops and builtin requests only; no image generation.')
p.add_argument('--run',required=True)
p.add_argument('--name',required=True)
p.add_argument('--source',required=True)
p.add_argument('--source-sha',required=True)
p.add_argument('--box',type=int,nargs=4,required=True)
p.add_argument('--prompt-file',required=True)
a=p.parse_args()
run=Path(a.run); source=Path(a.source)
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
assert sha(source)==a.source_sha, 'Source changed concurrently'
crop=run/'requests'/(a.name+'.context.png')
assert not crop.exists(), 'Never overwrite prior request inputs'
with Image.open(source) as im:
    im.load()
    x0,y0,x1,y1=a.box
    assert 0<=x0<x1<=im.width and 0<=y0<y1<=im.height
    part=im.crop(a.box)
    part.save(crop)
assert sha(source)==a.source_sha, 'Source changed during cropping'
root=Path('E:/work/image')
session=root/'qdao_city_tiles_4k_20260916/builtin_q64_production/resume_single_city_20260921'
refs=[crop,root/'designs/gameplay-ui/04-guild.png',session/'next_tile_r08_c08/correction-20260923T114016880544Z/native-ivory-material-reference.png']
payload={'prompt':Path(a.prompt_file).read_text(encoding='utf-8-sig'),'referenced_image_paths':[str(x).replace('\\','/') for x in refs],'transparent_background':False}
record={'preparedAtUtc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'tool':'image_gen.imagegen','payload':payload,'configSnapshot':'../config.snapshot.json','sourceCandidateSha256':a.source_sha,'sourcePath':str(source),'cropLTRB':a.box,'desiredNativePixels':[x1-x0,y1-y0],'submittedModel':None,'submittedQuality':None,'actualModel':None,'actualQuality':None,'status':'prepared_not_submitted'}
for suffix,data in [('.request.json',record),('.references.json',[{'path':str(x).replace('\\','/'),'sha256':sha(x)} for x in refs])]:
    with (run/'requests'/(a.name+suffix)).open('x',encoding='utf-8') as f:
        json.dump(data,f,ensure_ascii=False,indent=2);f.write('\n')
print(json.dumps({'context':str(crop),'sha256':sha(crop),'request':str(run/'requests'/(a.name+'.request.json'))}))
