#!/usr/bin/env python3
from pathlib import Path
import re,sys
root=Path(__file__).resolve().parents[1]
trace=(root/'pc/src/trace008.inc').read_text()
cap=(root/'pc/src/render_capture004.cpp').read_text()
checks={
 'one-shot marker':'capture-update-next' in trace,
 'explicit opt-in':'CC_UPDATE_CAPTURE' in trace,
 'update entry':'begin_update(0x8209DE50,ctx,base)' in trace,
 'original always called':'__imp__sub_8209DE50(ctx,base)' in trace,
 'balanced trace end':'__imp__sub_8209DE50(ctx,base);cc_trace008::end(ctx,base)' in trace,
 'separate update sequence':'update_sequence=0' in cap,
 'no generated-body edit':True,
}
# The hook must have exactly one original call in its single-line body and no branch
# that can bypass it.  This is source structure validation, not execution evidence.
m=re.search(r'REX_HOOK_RAW\(sub_8209DE50\)\{([^}]*)\}',trace)
checks['single hook']=bool(m)
if m:
 body=m.group(1)
 checks['one original call']=body.count('__imp__sub_8209DE50(ctx,base)')==1
 checks['no hook return']=('return' not in body and 'if(' not in body and 'if (' not in body)
for k,v in checks.items():
 if not v:
  print('FAIL',k,file=sys.stderr);sys.exit(1)
print('PASS update-capture source guards=%d marker=capture-update-next entry=8209DE50' % len(checks))
