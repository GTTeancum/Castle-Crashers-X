#!/usr/bin/env python3
import re,sys
from pathlib import Path
for p in (Path(__file__).resolve().parents[1]/'pc/generated/default').glob('*recomp.*.cpp'):
 t=p.read_text();ms=list(re.finditer(r'DEFINE_REX_FUNC\((\w+)\)\s*\{',t))
 for i,m in enumerate(ms):
  if m[1] in sys.argv[1:]:print(t[m.start():ms[i+1].start() if i+1<len(ms) else len(t)])
