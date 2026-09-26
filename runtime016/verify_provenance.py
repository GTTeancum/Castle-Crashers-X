#!/usr/bin/env python3
from pathlib import Path
import hashlib,re,sys
root=Path(__file__).resolve().parents[1]
sources=[p.read_text() for p in sorted((root/'pc/generated/default').glob('castle_crashers_recomp.*.cpp'))]

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

# Verify every exact body that runtime016 itself includes. Inherited runtime008/
# runtime010/runtime011 bodies are already sealed by their checkpoint inputs.
bodies=(root/'runtime016/bodies.inc').read_text()
local_includes=re.findall(r'#include "generated/([^"/]+)\.inc"',bodies)
slices={'sub_820701D0_manager_slice','sub_820701D0_startup_prefix'}
names=[n for n in local_includes if n not in slices]
if len(names)!=len(set(names)):
    raise SystemExit('duplicate local generated include in runtime016/bodies.inc')
for name in names:
    actual=(root/'runtime016/generated'/(name+'.inc')).read_bytes(); want=expected(name)
    if actual!=want:
        print('FAIL',name,'differs from sealed generated source',file=sys.stderr);sys.exit(1)
    print('PASS provenance %-16s bytes=%d sha256=%s' % (name,len(actual),hashlib.sha256(actual).hexdigest()))

# Verify the older manager mid-function diagnostic slice against the sealed body.
src=next(s for s in sources if 'DEFINE_REX_FUNC(sub_820701D0) {' in s)
st=src.index('loc_82070434:',src.index('DEFINE_REX_FUNC(sub_820701D0) {'))
en=src.index('loc_820704C4:',st)
frag=src[st:en]
actual=(root/'runtime016/generated/sub_820701D0_manager_slice.inc').read_text()
frag_without_label=frag.split('\n',1)[1]
if frag_without_label not in actual:
    print('FAIL manager slice differs from sealed sub_820701D0 [0x82070434,0x820704C4)',file=sys.stderr);sys.exit(1)
if 'REX_STORE_U32(ctx.r10.u32 + -6612, ctx.r31.u32);' not in actual:
    print('FAIL manager slice lacks 0x8225E62C store',file=sys.stderr);sys.exit(1)
print('PASS manager slice source=820701D0 range=82070434..820704C4 bytes=%d sha256=%s' %
      (len(frag_without_label.encode()),hashlib.sha256(frag_without_label.encode()).hexdigest()))

# Verify the checkpoint-016 diagnostic prefix is exactly the original function
# entry through loc_82070694, plus only the renamed wrapper and diagnostic return.
start=src.index('DEFINE_REX_FUNC(sub_820701D0) {')
end=src.index('loc_82070694:',start)+len('loc_82070694:')
want=src[start:end].replace('DEFINE_REX_FUNC(sub_820701D0)','DEFINE_REX_FUNC(sub_820701D0_startup_prefix)',1)
want+='\n\t// Checkpoint 016 diagnostic stop: exact original prefix ends at 0x82070694.\n\treturn;\n}\n'
actual_prefix=(root/'runtime016/generated/sub_820701D0_startup_prefix.inc').read_text()
if actual_prefix!=want:
    print('FAIL startup prefix differs from sealed sub_820701D0 entry..0x82070694',file=sys.stderr);sys.exit(1)
for store in [
    'REX_STORE_U32(ctx.r10.u32 + -6612, ctx.r31.u32);', # 8225E62C manager
    'REX_STORE_U32(ctx.r11.u32 + -6648, ctx.r3.u32);',  # 8225E608 state pool
    'REX_STORE_U32(ctx.r11.u32 + -6596, ctx.r3.u32);',  # 8225E63C system state
]:
    if store not in actual_prefix:
        print('FAIL startup prefix missing expected original global store '+store,file=sys.stderr);sys.exit(1)
print('PASS startup prefix source=820701D0 range=entry..82070694 bytes=%d sha256=%s' %
      (len(want.encode()),hashlib.sha256(want.encode()).hexdigest()))

# Bind immutable constants and the 10,500-object virtual initializer to the
# sealed mapped image.
image=(root/'castle-crashers-port/reference/default.image.bin').read_bytes(); BASE=0x82000000
def be32(addr):
    off=addr-BASE
    if off<0 or off+4>len(image): raise SystemExit(f'address outside image: {addr:08x}')
    return int.from_bytes(image[off:off+4],'big')
if be32(0x820146A0)!=0x3f666666:
    raise SystemExit('FAIL sealed manager constant 0x820146A0')
if be32(0x8203E878+80)!=0x820867B8:
    raise SystemExit('FAIL sealed state-pool vtable +80')
print('PASS sealed manager constant 820146A0=3f666666 (0.9f)')
print('PASS sealed state-pool vtable [8203E8C8]=820867B8')
print('PASS exact generated bodies=%d plus_manager_slice=1 plus_startup_prefix=1' % len(names))
