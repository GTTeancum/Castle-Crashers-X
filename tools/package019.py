#!/usr/bin/env python3
from __future__ import annotations
from pathlib import Path
import argparse,hashlib,json,zipfile
W=Path(__file__).resolve().parents[1]
PREFIX='CastleCrashers-Checkpoint-019'
BASE=json.loads((W/'package-manifest018.json').read_text())
BASE_PATHS={x['path'] for x in BASE['files']}
NEW_EXACT={
 'CHECKSUMS-018.sha256','package-manifest018.json','CHECKPOINT-019.md','README-019.md','WORKLOG-019.md',
 'README.md','build-status019.json','build_update019.sh','renderer019/CMakeLists.txt','tools/package019.py'
}
NEW_PREFIXES=('runtime019/','host-bin019/','logs/checkpoint019/build-final/')
EXCLUDED_PARTS={'__pycache__','.pytest_cache'}
def digest(p:Path)->str:
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(4*1024*1024),b''): h.update(b)
 return h.hexdigest()
def selected(p:Path)->bool:
 if not p.is_file() or p.is_symlink(): return False
 r=p.relative_to(W).as_posix(); parts=p.relative_to(W).parts
 if r in {'CHECKSUMS.sha256','CHECKSUMS-019.sha256','package-manifest019.json'}: return False
 if any(x in EXCLUDED_PARTS for x in parts): return False
 # Never package CMake build/cache trees for the new renderer.
 if r.startswith('renderer019/build-') or '/CMakeFiles/' in r or r.endswith('/CMakeCache.txt'): return False
 return r in BASE_PATHS or r in NEW_EXACT or r.startswith(NEW_PREFIXES)
def main():
 ap=argparse.ArgumentParser(); ap.add_argument('--output',type=Path,default=W.parent/(PREFIX+'.zip')); a=ap.parse_args()
 files=sorted((p for p in W.rglob('*') if selected(p)),key=lambda p:p.relative_to(W).as_posix())
 records=[{'path':p.relative_to(W).as_posix(),'bytes':p.stat().st_size,'sha256':digest(p)} for p in files]
 manifest={
  'format':'cc-checkpoint019-inventory','base_checkpoint':'018','files':records,
  'file_count':len(records),'uncompressed_bytes':sum(x['bytes'] for x in records),
  'excludes':['BIOS/MCPX/EEPROM/HDD','full extracted game and original LIVE container','external SDK/tool source snapshots including nxdk','CMake build caches/intermediate objects','installed font files'],
  'scope':'Private cumulative original-code port checkpoint. 019 closes the observed sub_820CBBF0 presentation/resource path and stops at sub_820CB988; 011 remains latest native/xemu acceptance.'
 }
 mp=W/'package-manifest019.json'; mp.write_text(json.dumps(manifest,indent=2)+'\n')
 cs=W/'CHECKSUMS-019.sha256'; cs.write_text(''.join(f"{x['sha256']}  {x['path']}\n" for x in records)+f"{digest(mp)}  package-manifest019.json\n")
 # Verify the recorded non-self-referential inventory before archiving.
 for rec in records:
  p=W/rec['path']
  if p.stat().st_size!=rec['bytes'] or digest(p)!=rec['sha256']: raise SystemExit('inventory changed: '+rec['path'])
 a.output.parent.mkdir(parents=True,exist_ok=True)
 with zipfile.ZipFile(a.output,'w',zipfile.ZIP_DEFLATED,compresslevel=6,allowZip64=True) as z:
  for p in files+[mp,cs]: z.write(p,PREFIX+'/'+p.relative_to(W).as_posix())
 print(json.dumps({'archive':str(a.output),'bytes':a.output.stat().st_size,'sha256':digest(a.output),'included_files':len(files)+2,'inventory_files':len(records),'payload_bytes':manifest['uncompressed_bytes']},indent=2))
if __name__=='__main__': main()
