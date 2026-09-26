#!/usr/bin/env python3
from pathlib import Path
import hashlib,sys
root=Path(__file__).resolve().parents[1]
sources=[p.read_text() for p in (root/'pc/generated/default').glob('castle_crashers_recomp.*.cpp')]
def expected(name):
    needle=f'DEFINE_REX_FUNC({name}) {{'
    for src in sources:
        if needle not in src: continue
        start=src.index(needle);level=0;seen=False
        for pos in range(start,len(src)):
            if src[pos]=='{': level+=1;seen=True
            elif src[pos]=='}':
                level-=1
                if seen and level==0:return (src[start:pos+1]+'\n').encode()
    raise RuntimeError(name)
names=['__savegprlr_29','__restgprlr_29','sub_8208C5D8','sub_8209CC98','sub_8209DE50','sub_82097720','sub_820915F0','__savegprlr_22','__restgprlr_22','sub_820B6D10','sub_820B6D48','sub_82082390','sub_8208BE40','sub_8208AB98','sub_820936B0','sub_82094530','sub_82094420','sub_820772B0','sub_820A1AC0','sub_82088A08','sub_8208A228','sub_8208AE78',
       'sub_82097650','sub_82099A80','sub_82099968','sub_82097AC8','sub_82099680','sub_820986F0','sub_8209BDD8','sub_8209BF18','sub_820B5EB8','sub_820744C8','sub_82075098','__savegprlr_26','__restgprlr_26']
for name in names:
    actual=(root/'runtime015/generated'/(name+'.inc')).read_bytes(); want=expected(name)
    if actual!=want:
        print('FAIL',name,'differs from sealed generated source',file=sys.stderr);sys.exit(1)
    print('PASS provenance %-16s bytes=%d sha256=%s' % (name,len(actual),hashlib.sha256(actual).hexdigest()))
# Verify the mid-function diagnostic slice against the sealed original body.
src=next(s for s in sources if 'DEFINE_REX_FUNC(sub_820701D0) {' in s)
st=src.index('loc_82070434:',src.index('DEFINE_REX_FUNC(sub_820701D0) {'))
en=src.index('loc_820704C4:',st)
frag=src[st:en]
actual=(root/'runtime015/generated/sub_820701D0_manager_slice.inc').read_text()
# The entry label is represented by the C++ function entry; the translated
# instruction text following that label must otherwise be byte-for-byte present.
frag_without_label=frag.split('\n',1)[1]
if frag_without_label not in actual:
    print('FAIL manager slice differs from sealed sub_820701D0 [0x82070434,0x820704C4)',file=sys.stderr);sys.exit(1)
if 'REX_STORE_U32(ctx.r10.u32 + -6612, ctx.r31.u32);' not in actual:
    print('FAIL manager slice lacks 0x8225E62C store',file=sys.stderr);sys.exit(1)
print('PASS manager slice source=820701D0 range=82070434..820704C4 bytes=%d sha256=%s' %
      (len(frag_without_label.encode()),hashlib.sha256(frag_without_label.encode()).hexdigest()))
# Bind the manager's immutable float initializer to the sealed mapped image.
image=(root/'castle-crashers-port/reference/default.image.bin').read_bytes()
image_base=0x82000000
const_addr=0x820146A0
const_bits=image[const_addr-image_base:const_addr-image_base+4]
if const_bits != bytes.fromhex('3f666666'):
    print('FAIL sealed 0x820146A0 constant is %s, expected 3f666666' % const_bits.hex(), file=sys.stderr);sys.exit(1)
print('PASS sealed manager constant 820146A0=3f666666 (0.9f)')
print('PASS exact generated bodies=%d plus_manager_slice=1' % len(names))
