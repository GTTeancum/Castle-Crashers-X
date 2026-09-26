#!/usr/bin/env python3
"""Check new owner bodies against original generated code and original PPC extents.
--write-manifest records the verified extraction; normal runs compare the pinned record.
Entry counts include overlapping compiler helper extents, not game-coverage percentages.
"""
from pathlib import Path
import argparse,csv,hashlib,json,re
R=Path(__file__).resolve().parents[1]
def sha(b):return hashlib.sha256(b).hexdigest()
def verify(root=R,write=False):
 image=(root/'castle-crashers-port/reference/default.image.bin').read_bytes()
 if sha(image)!='964aa6b9d993beb8ad9a986d0555e47c36b4b5716b0b8377c6631ae8b39c03ab':raise ValueError('Wrong original image')
 pdata={int(x['candidate_start'],16):((int(x['packed_metadata'],16)>>8)&0x3fffff)*4 for x in csv.DictReader((root/'castle-crashers-port/reports/pdata_candidates.csv').open())}
 fs={};src={}
 for p in sorted((root/'pc/generated/default').glob('*recomp.*.cpp')):
  text=p.read_text();matches=list(re.finditer(r'DEFINE_REX_FUNC\((\w+)\)',text))
  for i,m in enumerate(matches):
   if m[1] in fs:raise ValueError('Duplicate generated function')
   fs[m[1]]=text[m.start():matches[i+1].start() if i+1<len(matches) else len(text)].rstrip()+'\n';src[m[1]]=p.relative_to(root).as_posix()
 names={p.stem for p in (root/'runtime010/generated').glob('*.inc')}
 if names!={'sub_82091248','sub_82083658','sub_82086810','__savegprlr_24','__restgprlr_24'}:raise ValueError('Unexpected owner slice')
 addresses={n:int(n[4:],16) for n in names if n.startswith('sub_')}
 for body in fs.values():
  for a,n in re.findall(r'// b(?:l)? (0x[0-9a-f]+)\n\s*(?:ctx\.lr = [^;]+;\n\s*)?(\w+)\(ctx, base\)',body):
   if n in names:
    v=int(a,16)
    if n in addresses and addresses[n]!=v:raise ValueError('Conflicting original helper entry')
    addresses[n]=v
 records=[]
 for name in sorted(names):
  stored=(root/'runtime010/generated'/f'{name}.inc').read_bytes();body=fs[name].encode()
  if stored!=body:raise ValueError('Changed original generated body: '+name)
  address=addresses[name];n=len(re.findall(r'^\s*// [a-z]',fs[name],re.M))*4
  if address in pdata and pdata[address]!=n:raise ValueError('Function extent disagrees with .pdata: '+name)
  raw=image[address-0x82000000:address-0x82000000+n]
  if len(raw)!=n:raise ValueError('Short original extent')
  records.append(dict(symbol=name,address=address,original_bytes=n,original_sha256=sha(raw),generated_source=src[name],body_sha256=sha(body),pdata_bytes=pdata.get(address)))
 manifest=dict(image_sha256=sha(image),functions=records)
 path=root/'runtime010/provenance.json'
 if write:path.write_text(json.dumps(manifest,indent=2)+'\n')
 elif json.loads(path.read_text())!=manifest:raise ValueError('Pinned owner provenance changed')
 from verify_scene008 import verify as prior_verify
 prior=prior_verify(root);before={x['symbol']for x in prior['checks']};render=before|names
 call_site=0x8209dfac-4;word=int.from_bytes(image[call_site-0x82000000:call_site-0x82000000+4],'big')
 candidates=[(a,n) for a,n in pdata.items()if a<=call_site<a+n]
 out=dict(result='passed',new_functions=records,prior_render_entries=len(before),new_render_entries=len(names-before),unique_render_entries=len(render),mode_entries=2,scope='Verified original bodies/extents, not live update/menu execution or disjoint code coverage.',upper_caller=dict(return_address='0x8209dfac',call_address=hex(call_site),instruction=f'{word:08x}',enclosing_pdata=[dict(address=hex(a),bytes=n)for a,n in candidates]))
 return out
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--root',type=Path,default=R);p.add_argument('--write-manifest',action='store_true');a=p.parse_args();print(json.dumps(verify(a.root,a.write_manifest),indent=2))
