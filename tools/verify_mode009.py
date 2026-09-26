#!/usr/bin/env python3
"""Check the exact supplied original bytes/bodies and all direct mode query sites."""
from pathlib import Path
import hashlib,json,re
w=Path(__file__).resolve().parents[1]
m=json.loads((w/'port009/provenance.json').read_text())
hash_=lambda b:hashlib.sha256(b).hexdigest()
image=(w/'castle-crashers-port/reference/default.image.bin').read_bytes()
if hash_(image)!=m['image_sha256']:raise SystemExit('Original image identity mismatch')
for row in m['entries']:
 text=(w/row['source']).read_text();q=re.search(r'DEFINE_REX_FUNC\('+row['name']+r'\).*?(?=\nDEFINE_REX_FUNC|\Z)',text,re.S)
 if not q:raise SystemExit('Missing original generated entry')
 body=q[0].rstrip()+'\n';off=int(row['address'],16)-0x82000000
 if body!=(w/row['included']).read_text() or hash_(body.encode())!=row['body_sha256']:
  raise SystemExit('Generated-body provenance mismatch')
 if hash_(image[off:off+row['bytes']])!=row['original_sha256']:raise SystemExit('Original byte mismatch')
for row in m['license_callers']:
 s=(w/row['file']).read_text();q=re.search(r'DEFINE_REX_FUNC\('+row['name']+r'\).*?(?=\nDEFINE_REX_FUNC|\Z)',s,re.S)
 if not q or hash_((q[0].rstrip()+'\n').encode())!=row['body_sha256']:raise SystemExit('Mode consumer changed')
 if not row['clears_overlapped_argument'] or not row['tests_bit_zero']:raise SystemExit('Unsupported mode contract')
print(json.dumps({'result':'passed','original_image_sha256':m['image_sha256'],'original_entries':len(m['entries']),'direct_synchronous_bit0_consumers':len(m['license_callers'])},indent=2))
