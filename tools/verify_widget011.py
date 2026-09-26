#!/usr/bin/env python3
"""Pin the four original widget bodies, recorded virtual slots and next static boundary.
Original-body identity is not a completeness/equivalence or gameplay claim.
"""
from pathlib import Path
import argparse,csv,hashlib,json,re,struct
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
 names={p.stem for p in (root/'runtime011/generated').glob('*.inc')}
 if names!={'sub_8209CD08','sub_8209DF48','sub_8209CE40','sub_8209CE48'}:raise ValueError('Unexpected widget slice')
 records=[]
 for name in sorted(names):
  stored=(root/'runtime011/generated'/f'{name}.inc').read_bytes();body=fs[name].encode()
  if stored!=body:raise ValueError('Changed original body: '+name)
  address=int(name[4:],16);n=len(re.findall(r'^\s*// [a-z]',fs[name],re.M))*4
  if address in pdata and pdata[address]!=n:raise ValueError('Extent disagrees with .pdata: '+name)
  raw=image[address-0x82000000:address-0x82000000+n]
  if len(raw)!=n:raise ValueError('Truncated original code')
  records.append(dict(symbol=name,address=address,original_bytes=n,original_sha256=sha(raw),generated_source=src[name],body_sha256=sha(body),pdata_bytes=pdata.get(address),pc_trace_observed=(name!='sub_8209CE40')))
 # These are exactly the ten function slots, not bytes of strings following them.
 address=0x8204043c
 words=list(struct.unpack_from('>10I',image,address-0x82000000))
 if words != [0x8209dce8,0x8209db88,0x8209de50,0x8209df48,0x8209cd98,0x8209ce40,0x8209ce48,0x8209ce50,0x8209ce88,0x8208c5d8]:raise ValueError('Original widget vtable changed')
 table=dict(address=hex(address),slots=[dict(offset=i*4,target=hex(w))for i,w in enumerate(words)])
 manifest=dict(image_sha256=sha(image),functions=records,widget_vtable=table)
 p=root/'runtime011/provenance.json'
 if write:p.write_text(json.dumps(manifest,indent=2)+'\n')
 elif json.loads(p.read_text())!=manifest:raise ValueError('Pinned widget provenance changed')
 from verify_owner010 import verify as prior_verify
 prior=prior_verify(root)
 for name in ['sub_820759A8','sub_8209DE50','sub_820915F0','sub_8209CC98']:
  if name not in fs:raise ValueError('Missing next-boundary original code')
 call=0x82075b68;word=int.from_bytes(image[call-0x82000000:call-0x82000000+4],'big')
 disp=word&0x03fffffc
 if disp&0x02000000:disp-=0x04000000
 if word != 0x4e800421 or 'ctx.lr = 0x82075B6C;' not in fs['sub_820759A8']:raise ValueError('Expected observed original indirect call')
 if struct.unpack_from('>I',image,0x820401e0+12-0x82000000)[0] != 0x8209cd08:raise ValueError('Container render slot mismatch')
 nextbound=dict(scope='Static observations only; neither outer renderer nor update chain is ported/executed by this diagnostic.',outer_renderer='0x820759a8',original_extent=pdata.get(0x820759a8),call_address=hex(call),instruction=f'{word:08x}',instruction_kind='bctrl; target observed at capture, not a direct-branch encoding',container_vtable='0x820401e0',render_slot=12,return_address='0x82075b6c',widget_update_slot=8,widget_update='0x8209de50',direct_update_calls=re.findall(r'\n\s*(sub_\w+)\(ctx, base\);',fs['sub_8209DE50']))
 return dict(result='passed',new_functions=records,prior_render_entries=prior['unique_render_entries'],new_render_entries=4,unique_render_entries=prior['unique_render_entries']+4,mode_entries=2,widget_vtable=table,next_boundary=nextbound,scope='Original bodies/extents verified; captured container rendering, not live update/input execution.')
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--root',type=Path,default=R);p.add_argument('--write-manifest',action='store_true');a=p.parse_args();print(json.dumps(verify(a.root,a.write_manifest),indent=2))
