"""Idempotent trace include injection; never change a generated function body."""
from pathlib import Path
r=Path(__file__).resolve().parents[1]
for p in (r/'pc/generated/default').glob('castle_crashers_funcs.*.h'):
 t=p.read_text()
 if '#include "src/trace008.h"' not in t:
  p.write_text(t+'\n#ifdef CC_SCENE_TRACE008\n#include "src/trace008.h"\n#endif\n')
print('Trace macro include installed (generated function bodies unchanged).')
