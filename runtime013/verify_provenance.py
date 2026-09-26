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
names=['__savegprlr_29','__restgprlr_29','sub_8208C5D8','sub_8209CC98','sub_8209DE50','sub_82097720','sub_820915F0']
for name in names:
 actual=(root/'runtime013/generated'/(name+'.inc')).read_bytes(); want=expected(name)
 if actual!=want:
  print('FAIL',name,'differs from sealed generated source',file=sys.stderr);sys.exit(1)
 print('PASS provenance %-16s bytes=%d sha256=%s' % (name,len(actual),hashlib.sha256(actual).hexdigest()))
print('PASS exact generated bodies=%d' % len(names))
