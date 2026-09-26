#!/usr/bin/env python3
"""Check the unchanged original/generated caller slice and vtable provenance."""
from pathlib import Path
import hashlib,json,struct,csv,re
R=Path(__file__).resolve().parents[1]
def verify():
 m=json.loads((R/'runtime007/provenance.json').read_text());image=(R/'castle-crashers-port/reference/default.image.bin').read_bytes()
 digest=lambda b:hashlib.sha256(b).hexdigest()
 if digest(image)!=m['image_sha256']:raise ValueError('Wrong original image')
 pdata={int(x['candidate_start'],16):((int(x['packed_metadata'],16)>>8)&0x3fffff)*4 for x in csv.DictReader((R/'castle-crashers-port/reports/pdata_candidates.csv').open())}
 out=[]
 for f in m['functions']:
  a=int(f['address'],16);n=f['original_bytes'];raw=image[a-0x82000000:a-0x82000000+n]
  if len(raw)!=n or digest(raw)!=f['original_sha256']:raise ValueError('Wrong raw extent '+f['symbol'])
  s=(R/f['generated_source']).read_text();start=s.index('DEFINE_REX_FUNC('+f['symbol']+')');end=s.find('\nDEFINE_REX_FUNC(',start+1);b=(s[start:end if end>=0 else len(s)].rstrip()+'\n').encode()
  if digest(b)!=f['body_sha256'] or b!=(R/'runtime007/generated'/f"{f['symbol']}.inc").read_bytes():raise ValueError('Changed body '+f['symbol'])
  # Function length in original .pdata independently agrees where present.
  if a in pdata and pdata[a]!=n:raise ValueError(f'pdata length mismatch {a:08x}: {pdata[a]} vs {n}')
  out.append(dict(symbol=f['symbol'],address=f['address'],bytes=n,unchanged=True,pdata_length=pdata.get(a),last_instruction=f'{struct.unpack_from(">I",raw,n-4)[0]:08x}'))
 slots={40:0x820a74e0,60:0x820a7488,92:0x820a89f8,108:0x820a8dd8,116:0x820a9308}
 for offset,want in slots.items():
  if struct.unpack_from('>I',image,0x42048+offset)[0]!=want:raise ValueError('Vtable mismatch')
 return dict(result='passed',new_original_bodies=len(out),functions=out,vtable='0x82042048',checked_slots=slots)
if __name__=='__main__':print(json.dumps(verify(),indent=2))
