#!/usr/bin/env python3
"""Fail-closed post-codegen repair for this build's over-scanned byte switch.
Preserve the guest-computed CTR instead of assuming an unproved index bound.
No game service is replaced by a success stub.
"""
from pathlib import Path
import hashlib, sys
OLD_SHA='0dba0595336fc9cde234201b337b098bda119dcd773ea20d031185a951936611'
MARKER='// CC_SWITCH_CTR_REPAIR_V1'
PATCHED_SHA='a7f8496b0abd16298c5a91c560152b82a78347b9c27d2a33d9e00aecd68057a1'

def repair(root: Path) -> None:
    hits=[p for p in (root/'generated/default').glob('*_recomp.*.cpp') if 'DEFINE_REX_FUNC(sub_82112BC0) {' in p.read_text()]
    if len(hits)!=1: raise ValueError('Expected exactly one sub_82112BC0 definition')
    p=hits[0];s=p.read_text();start=s.index('DEFINE_REX_FUNC(sub_82112BC0) {')+len('DEFINE_REX_FUNC(sub_82112BC0) {')
    end=s.find('\nDEFINE_REX_FUNC(',start)
    if end<0:end=len(s)
    body=s[start:end]
    if MARKER in body:
        if hashlib.sha256(body.encode()).hexdigest()!=PATCHED_SHA:
            raise ValueError('Previously repaired function changed; refusing to ignore edits')
        print('Computed-CTR switch repair already applied');return
    if hashlib.sha256(body.encode()).hexdigest()!=OLD_SHA: raise ValueError('Generated function changed; inspect before patching')
    a=body.index('\tswitch (ctx.r11.u32) {');b=body.index('\nloc_82112C08:',a)
    replacement='''\t// CC_SWITCH_CTR_REPAIR_V1
\t// Original PPC has already computed CTR from the byte-offset table.
\tswitch (ctx.ctr.u32) {
\tcase 0x82112C08: goto loc_82112C08;
\tcase 0x82112C38: goto loc_82112C38;
\tcase 0x82112D10:
\t\tsub_82112D10(ctx, base);
\t\treturn;
\tdefault:
\t\t// Unknown mappings must be reported by the SDK, never ignored.
\t\tREX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
\t\treturn;
\t}
'''
    p.write_text(s[:start]+body[:a]+replacement+body[b:]+s[end:]);print('Applied computed-CTR switch repair:',p.name)

if __name__=='__main__':
    try: repair(Path(__file__).resolve().parents[1])
    except (OSError,ValueError) as exc: print('SWITCH REPAIR FAILED:',exc,file=sys.stderr);sys.exit(1)
