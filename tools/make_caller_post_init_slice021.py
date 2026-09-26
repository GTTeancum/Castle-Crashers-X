#!/usr/bin/env python3
"""Regenerate the WIP 023 sub_82070AC8 post-Init continuation slice.

The executed fragment is copied byte-for-byte from the sealed generated
corpus, from the first instruction after `bl 0x820a7990` (0x82070BA4)
through the end of the function: the remaining one-time initialization,
the loc_82070DB0 main game loop (update sub_82075C88 / render
sub_820759A8 / frame pacing), the shutdown path, and the original return.
Wrapper header/pragmas are diagnostic scaffolding;
runtime021/verify_provenance.py checks the exact layout this script
produces.
"""
import hashlib
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(root / 'tools'))
from extract_generated021 import expected  # noqa: E402

orig = expected('sub_82070AC8').decode()
call = '\tsub_820A7990(ctx, base);\n'
st = orig.index(call) + len(call)
en = orig.rindex('}')
frag = orig[st:en]
want = ('DEFINE_REX_FUNC(sub_82070AC8_post_init) {\n'
        '\tREX_FUNC_PROLOGUE();\n'
        '\tPPCRegister temp{};\n'
        '\t(void)temp;\n'
        '#pragma clang diagnostic push\n'
        '#pragma clang diagnostic ignored "-Wunused-label"\n' + frag +
        '#pragma clang diagnostic pop\n'
        '}\n')
out = root / 'runtime021/generated/sub_82070AC8_post_init.inc'
out.write_bytes(want.encode())
print('fragment bytes:', len(frag.encode()),
      'sha256:', hashlib.sha256(frag.encode()).hexdigest())
