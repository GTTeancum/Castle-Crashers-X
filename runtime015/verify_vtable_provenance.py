#!/usr/bin/env python3
from pathlib import Path
import struct,sys
root=Path(__file__).resolve().parents[1]
image=(root/'castle-crashers-port/reference/default.image.bin').read_bytes()
BASE=0x82000000
def be32(addr):
    off=addr-BASE
    if off < 0 or off+4 > len(image):
        raise SystemExit(f'FAIL vtable address out of image: {addr:08x}')
    return struct.unpack_from('>I',image,off)[0]
checks=[
    ('Game/controller vtable +0x0c',0x8203E118+0x0c,0x820772B0),
    ('Parser vtable +84dec',0x8203F510+84,0x82088A08),
    ('Parser vtable +88dec',0x8203F510+88,0x8208A228),
]
for label,addr,want in checks:
    got=be32(addr)
    if got != want:
        print(f'FAIL {label}: got={got:08x} want={want:08x}',file=sys.stderr);sys.exit(1)
    print(f'PASS {label}: [{addr:08x}]={got:08x}')
# Constructor constants are also checked in sealed generated bodies so the table
# addresses are tied to the exact classes used by the owner path.
src='\n'.join(p.read_text() for p in (root/'pc/generated/default').glob('castle_crashers_recomp.*.cpp'))
for fn,store in [('sub_82075410','stw r8,0(r31)'),('sub_82094048','stw r9,0(r30)')]:
    n=f'DEFINE_REX_FUNC({fn}) {{'
    if n not in src or store not in src[src.index(n):src.find('\nDEFINE_REX_FUNC(',src.index(n)+1) if src.find('\nDEFINE_REX_FUNC(',src.index(n)+1)!=-1 else len(src)]:
        print(f'FAIL constructor provenance {fn}',file=sys.stderr);sys.exit(1)
    print(f'PASS constructor provenance {fn}')
