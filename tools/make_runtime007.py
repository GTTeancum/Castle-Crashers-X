from pathlib import Path
import re,json,hashlib,csv
r=Path(__file__).resolve().parents[1]; out=r/'runtime007';(out/'generated').mkdir(parents=True,exist_ok=True)
names=['sub_820A9068','sub_820855D8','sub_82085110','sub_820A7488','sub_820A74E0','sub_820A8DD8','sub_82127A08','sub_82127AE8','__savegprlr_25','__restgprlr_25','__savefpr_19','__restfpr_19','__savegprlr_27','__restgprlr_27','__savegprlr_28','__restgprlr_28']
# Function starts for compiler helpers taken from original direct branch comments.
addrs={'__savegprlr_25':0x8212990c,'__restgprlr_25':0x8212995c,'__savefpr_19':0x8212a834,'__restfpr_19':0x8212a880,'__savegprlr_27':0x82129914,'__restgprlr_27':0x82129964,'__savegprlr_28':0x82129918,'__restgprlr_28':0x82129968}
image=(r/'castle-crashers-port/reference/default.image.bin').read_bytes(); records=[]
for p in (r/'pc/generated/default').glob('*recomp.*.cpp'):
 text=p.read_text(); ms=list(re.finditer(r'DEFINE_REX_FUNC\((\w+)\)',text))
 for i,m in enumerate(ms):
  name=m[1]
  if name not in names:continue
  b=text[m.start():ms[i+1].start() if i+1<len(ms) else len(text)].rstrip()+'\n'
  (out/'generated'/f'{name}.inc').write_text(b)
  addr=addrs.get(name) or int(name[4:],16)
  n=len(re.findall(r'^\s*// [a-z]',b,re.M))*4
  records.append(dict(symbol=name,address=f'0x{addr:08X}',original_bytes=n,original_sha256=hashlib.sha256(image[addr-0x82000000:addr-0x82000000+n]).hexdigest(),generated_source=p.relative_to(r).as_posix(),body_sha256=hashlib.sha256(b.encode()).hexdigest()))
assert len(records)==len(names)
(out/'provenance.json').write_text(json.dumps({'image_sha256':hashlib.sha256(image).hexdigest(),'functions':records,'extent_method':'One instruction per generated assembly comment. These selected bodies contain no inline switch data; original terminal instructions recorded by audit.'},indent=2)+'\n')
