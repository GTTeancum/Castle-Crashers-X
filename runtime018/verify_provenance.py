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

# Verify every exact body that runtime018 itself includes. Inherited runtime008/
# runtime010/runtime011 bodies are already sealed by their checkpoint inputs.
bodies=(root/'runtime018/bodies.inc').read_text()
local_includes=re.findall(r'#include "generated/([^"/]+)\.inc"',bodies)
slices={'sub_820701D0_manager_slice','sub_820701D0_startup_full','sub_82070AC8_renderer_prefix','sub_820A7990_platform_prefix'}
names=[n for n in local_includes if n not in slices]
if len(names)!=len(set(names)):
    raise SystemExit('duplicate local generated include in runtime018/bodies.inc')
for name in names:
    actual=(root/'runtime018/generated'/(name+'.inc')).read_bytes(); want=expected(name)
    if actual!=want:
        print('FAIL',name,'differs from sealed generated source',file=sys.stderr);sys.exit(1)
    print('PASS provenance %-16s bytes=%d sha256=%s' % (name,len(actual),hashlib.sha256(actual).hexdigest()))

# Verify the older manager mid-function diagnostic slice against the sealed body.
src=next(s for s in sources if 'DEFINE_REX_FUNC(sub_820701D0) {' in s)
st=src.index('loc_82070434:',src.index('DEFINE_REX_FUNC(sub_820701D0) {'))
en=src.index('loc_820704C4:',st)
frag=src[st:en]
actual=(root/'runtime018/generated/sub_820701D0_manager_slice.inc').read_text()
frag_without_label=frag.split('\n',1)[1]
if frag_without_label not in actual:
    print('FAIL manager slice differs from sealed sub_820701D0 [0x82070434,0x820704C4)',file=sys.stderr);sys.exit(1)
if 'REX_STORE_U32(ctx.r10.u32 + -6612, ctx.r31.u32);' not in actual:
    print('FAIL manager slice lacks 0x8225E62C store',file=sys.stderr);sys.exit(1)
print('PASS manager slice source=820701D0 range=82070434..820704C4 bytes=%d sha256=%s' %
      (len(frag_without_label.encode()),hashlib.sha256(frag_without_label.encode()).hexdigest()))

# Verify checkpoint 018's full startup body. The generated source is preserved
# exactly except for the local wrapper name, allowing the public entry to remain
# bounded by the host adapter while executing the complete original function.
src=next(s for s in sources if 'DEFINE_REX_FUNC(sub_820701D0) {' in s)
orig=expected('sub_820701D0').decode()
want=orig.replace('DEFINE_REX_FUNC(sub_820701D0)','DEFINE_REX_FUNC(sub_820701D0_startup_full)',1)
actual_full=(root/'runtime018/generated/sub_820701D0_startup_full.inc').read_text()
if actual_full!=want:
    print('FAIL full startup wrapper differs from sealed sub_820701D0',file=sys.stderr);sys.exit(1)
for store in [
    'REX_STORE_U32(ctx.r10.u32 + -6612, ctx.r31.u32);', # 8225E62C manager
    'REX_STORE_U32(ctx.r11.u32 + -6648, ctx.r3.u32);',  # 8225E608 state pool
    'REX_STORE_U32(ctx.r11.u32 + -6596, ctx.r3.u32);',  # 8225E63C system state
    'REX_STORE_U32(ctx.r11.u32 + -6600, ctx.r29.u32);', # 8225E638 worker handles
    'REX_STORE_U32(ctx.r11.u32 + -6640, ctx.r3.u32);',  # 8225E610 lookup state
]:
    if store not in actual_full:
        print('FAIL full startup missing expected original global store '+store,file=sys.stderr);sys.exit(1)
print('PASS full startup source=820701D0 range=entry..return bytes=%d sha256=%s' %
      (len(want.encode()),hashlib.sha256(want.encode()).hexdigest()))


# Verify the original sub_82070AC8 caller prefix through renderer publication.
orig=expected('sub_82070AC8').decode()
stop='\t// bl 0x820a7990\n'
want=orig[:orig.index(stop)].replace('DEFINE_REX_FUNC(sub_82070AC8)','DEFINE_REX_FUNC(sub_82070AC8_renderer_prefix)',1)
want+='\t// Checkpoint 018 diagnostic stop: next original instruction is bl 0x820A7990.\n\t(void)temp;\n\treturn;\n}\n'
actual=(root/'runtime018/generated/sub_82070AC8_renderer_prefix.inc').read_text()
if actual!=want:
    print('FAIL renderer caller prefix differs from sealed sub_82070AC8',file=sys.stderr);sys.exit(1)
print('PASS renderer caller prefix source=82070AC8 range=entry..before_820A7990 bytes=%d sha256=%s' %
      (len(actual.encode()),hashlib.sha256(actual.encode()).hexdigest()))

# Verify PlatformRenderer::Init through the first graphics-device helper call.
orig=expected('sub_820A7990').decode()
stop='\t// bl 0x820befd0\n'
want=orig[:orig.index(stop)].replace('DEFINE_REX_FUNC(sub_820A7990)','DEFINE_REX_FUNC(sub_820A7990_platform_prefix)',1)
want+='\t// Checkpoint 018 diagnostic stop: next original instruction is bl 0x820BEFD0.\n\treturn;\n}\n'
actual=(root/'runtime018/generated/sub_820A7990_platform_prefix.inc').read_text()
if actual!=want:
    print('FAIL PlatformRenderer::Init prefix differs from sealed sub_820A7990',file=sys.stderr);sys.exit(1)
print('PASS platform init prefix source=820A7990 range=entry..before_820BEFD0 bytes=%d sha256=%s' %
      (len(actual.encode()),hashlib.sha256(actual.encode()).hexdigest()))


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
if be32(0x820005CC)!=0x000101be:
    raise SystemExit('FAIL sealed loader import-variable token 0x820005CC')
print('PASS sealed loader import-variable token [820005CC]=000101be (patched only by bounded host loader fixture)')
if be32(0x82000694)!=0x0001001b:
    raise SystemExit('FAIL sealed ExThreadObjectType token 0x82000694')
for i in range(613):
    if be32(0x82229938+i*40)!=i:
        raise SystemExit(f'FAIL sealed lookup key {i}')
print('PASS sealed thread object token [82000694]=0001001b')
print('PASS sealed lookup keys 0..612 at 82229938 stride=40')
if be32(0x82042678)!=0x42680000:
    raise SystemExit('FAIL sealed PlatformRenderer refresh threshold 0x82042678')
print('PASS sealed PlatformRenderer refresh threshold [82042678]=42680000 (58.0f)')
print('PASS exact generated bodies=%d plus_manager_slice=1 plus_full_startup_wrapper=1 plus_renderer_caller_prefix=1 plus_platform_init_prefix=1' % len(names))
