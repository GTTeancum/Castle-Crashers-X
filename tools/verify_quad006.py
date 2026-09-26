#!/usr/bin/env python3
"""Verify exact generated function bodies and their original Xbox 360 image extents."""
from pathlib import Path
import hashlib,json

def digest(data):return hashlib.sha256(data).hexdigest()
def verify(root):
 m=json.loads((root/'runtime006/provenance.json').read_text())
 image=(root/'castle-crashers-port/reference/default.image.bin').read_bytes()
 if digest(image)!=m['image_sha256']:raise ValueError('Original image hash mismatch')
 results=[]
 for item in m['functions']:
  offset=int(item['address'],16)-0x82000000;n=item['original_bytes']
  if offset<0 or offset+n>len(image) or digest(image[offset:offset+n])!=item['original_sha256']:raise ValueError('Original code extent changed: '+item['symbol'])
  text=(root/item['generated_source']).read_text();start=text.index('DEFINE_REX_FUNC('+item['symbol']+')');end=text.find('\nDEFINE_REX_FUNC(',start+1)
  body=text[start:end if end>=0 else len(text)].rstrip()+'\n'
  actual=(root/'runtime006/generated'/f"{item['symbol']}.inc").read_bytes()
  if digest(body.encode())!=item['body_sha256'] or actual!=body.encode():raise ValueError('Generated body mismatch: '+item['symbol'])
  results.append({'symbol':item['symbol'],'original_bytes':n,'unchanged_body':True,'original_hash_match':True})
 return {'result':'passed','functions':results,'scope':'Provenance of these bodies; not full-game or every shader-path equivalence'}
if __name__=='__main__':print(json.dumps(verify(Path(__file__).resolve().parents[1]),indent=2))
