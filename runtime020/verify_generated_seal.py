#!/usr/bin/env python3
from __future__ import annotations
import hashlib,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
numbered=[]
for p in ROOT.glob('CHECKSUMS-*.sha256'):
    m=re.fullmatch(r'CHECKSUMS-(\d+)\.sha256',p.name)
    if m:numbered.append((int(m.group(1)),p))
checksums=max(numbered)[1] if numbered else ROOT/'CHECKSUMS.sha256'
if not checksums.is_file():raise SystemExit('no checkpoint checksum seal found')
expected={}
for raw in checksums.read_text().splitlines():
    raw=raw.strip()
    if raw and '  ' in raw:
        digest,rel=raw.split('  ',1);expected[rel]=digest.lower()
files=sorted((ROOT/'pc/generated/default').glob('castle_crashers_recomp.*.cpp'))
assert len(files)==17,f'expected 17 sealed generated translation units, got {len(files)}'
for p in files:
    rel=p.relative_to(ROOT).as_posix();want=expected.get(rel)
    if want is None:raise SystemExit(f'missing sealed hash for {rel} in {checksums.name}')
    got=hashlib.sha256(p.read_bytes()).hexdigest()
    if got!=want:raise SystemExit(f'generated source changed: {rel}: {got} != {want}')
print(f'PASS generated-seal translation_units={len(files)} source={checksums.name}')
