#!/usr/bin/env python3
"""Check that the prototype uses the exact generated game leaf and original PPC bytes."""
import hashlib,json
from pathlib import Path
w=Path(__file__).resolve().parents[1]; d=w/'xbox-runtime'
meta=json.loads((d/'leaf-provenance.json').read_text())
s=(w/meta['source_file']).read_text(); i=s.index('DEFINE_REX_FUNC(sub_820B20C8)');j=s.index('\nDEFINE_REX_FUNC(',i+1)
expected=s[i:j].rstrip()+'\n'
if (d/'leaf_820b20c8.generated.inc').read_text()!=expected: raise SystemExit('FAIL: generated body changed')
if hashlib.sha256(expected.encode()).hexdigest()!=meta['generated_body_sha256']: raise SystemExit('FAIL: body digest changed')
b=(w/'castle-crashers-port/reference/default.image.bin').read_bytes()[0xb20c8:0xb20f0]
if len(b)!=40 or hashlib.sha256(b).hexdigest()!=meta['guest_sha256']: raise SystemExit('FAIL: original PPC bytes changed')
print('PASS: exact generated body and 40-byte original PPC leaf hashes match')
