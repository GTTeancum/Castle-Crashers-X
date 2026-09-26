#!/usr/bin/env python3
"""Regenerate the WIP 021 sub_820A7990 post-graphics continuation slice.

The executed fragment is copied byte-for-byte from the sealed generated
corpus, from loc_820A7B34 through the function's return. Wrapper header,
pragmas, and closing brace are diagnostic scaffolding and are not claimed as
original body bytes; runtime021/verify_provenance.py checks the exact layout
this script produces.
"""
import hashlib
from pathlib import Path

root = Path(__file__).resolve().parents[1]
src = (root / 'pc/generated/default/castle_crashers_recomp.6.cpp').read_text()
needle = 'DEFINE_REX_FUNC(sub_820A7990) {'
start = src.index(needle)
level = 0
seen = False
for pos in range(start, len(src)):
    if src[pos] == '{':
        level += 1
        seen = True
    elif src[pos] == '}':
        level -= 1
        if seen and level == 0:
            orig = src[start:pos + 1]
            break
label = orig.index('loc_820A7B34:')
st = orig.index('\n', label) + 1
frag = orig[st:orig.rindex('}')]
want = ('DEFINE_REX_FUNC(sub_820A7990_platform_post_graphics) {\n'
        '\tREX_FUNC_PROLOGUE();\n'
        '\tPPCRegister temp{};\n'
        '// Wrapper scaffolding: loc_820A7DC4 is targeted only by the error\n'
        '// path in the earlier (already-executed) part of sealed sub_820A7990.\n'
        '#pragma clang diagnostic push\n'
        '#pragma clang diagnostic ignored "-Wunused-label"\n' + frag +
        '#pragma clang diagnostic pop\n'
        '}\n')
out = root / 'runtime021/generated/sub_820A7990_platform_post_graphics.inc'
out.write_bytes(want.encode())
print('fragment bytes:', len(frag.encode()),
      'sha256:', hashlib.sha256(frag.encode()).hexdigest())
