#!/usr/bin/env python3
"""Verify this build's exact image, hook prologues, generated bodies and vtable bytes.
Checks version/provenance, not complete renderer semantics or target execution.
"""
import hashlib,json,struct,sys
from pathlib import Path
w=Path(__file__).resolve().parents[1]
m=json.loads((w/'renderer004/boundaries.json').read_text())
image=(w/'castle-crashers-port/reference/default.image.bin').read_bytes()
if hashlib.sha256(image).hexdigest()!=m['image_sha256']:raise SystemExit('Wrong original image')
for hook in m['hooks']:
 addr=int(hook['address'],16);raw=image[addr-0x82000000:addr-0x82000000+32]
 if hashlib.sha256(raw).hexdigest()!=hook['prologue_sha256']:raise SystemExit('Changed hook prologue')
 text=(w/hook['generated_file']).read_text();start=text.index('DEFINE_REX_FUNC('+hook['symbol']+')');end=text.find('\nDEFINE_REX_FUNC(',start+1)
 if end<0:end=len(text)
 body=text[start:end].rstrip()+'\n'
 if hashlib.sha256(body.encode()).hexdigest()!=hook['generated_body_sha256']:raise SystemExit('Changed generated hook body')
 if 'vtable_offset' in hook:
  actual=struct.unpack_from('>I',image,int(m['vtable_address'],16)-0x82000000+hook['vtable_offset'])[0]
  if actual!=addr:raise SystemExit('Changed PlatformRenderer vtable slot')
print('PASS: image hash, four hook prologues/generated bodies, and three vtable entries match.')
