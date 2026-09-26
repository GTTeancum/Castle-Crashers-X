#!/usr/bin/env python3
"""Package Checkpoint 015 from the cumulative 014 payload plus the 015 delta."""
from __future__ import annotations
from pathlib import Path
import argparse, hashlib, json, zipfile
W=Path(__file__).resolve().parents[1]
PREFIX='CastleCrashers-Checkpoint-015'
BASE=json.loads((W/'package-manifest014.json').read_text())
BASE_PATHS={x['path'] for x in BASE['files']}
NEW_EXACT={
 'CHECKSUMS-014.sha256','package-manifest014.json','CHECKPOINT-015.md','README-015.md','WORKLOG-015.md',
 'README.md','build-status015.json','build_update015.sh','renderer015/CMakeLists.txt','tools/package015.py'
}
NEW_PREFIXES=('runtime015/','host-bin015/','logs/checkpoint015/build-final/')
def digest(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(4*1024*1024),b''):h.update(b)
 return h.hexdigest()
def selected(p):
 if not p.is_file() or p.is_symlink():return False
 r=p.relative_to(W).as_posix()
 if r in {'CHECKSUMS.sha256','CHECKSUMS-015.sha256','package-manifest015.json'}:return False
 if r in BASE_PATHS or r in NEW_EXACT or r.startswith(NEW_PREFIXES):
  parts=p.relative_to(W).parts
  if '__pycache__' in parts:return False
  if r.startswith('runtime015/') and any(x.startswith('build') for x in parts[1:-1]):return False
  return True
 return False
def main():
 ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--output',type=Path,default=W.parent/(PREFIX+'.zip'));a=ap.parse_args()
 files=sorted((p for p in W.rglob('*') if selected(p)),key=lambda p:p.relative_to(W).as_posix())
 records=[{'path':p.relative_to(W).as_posix(),'bytes':p.stat().st_size,'sha256':digest(p)} for p in files]
 manifest={'format':'cc-checkpoint015-inventory','base_checkpoint':'014','files':records,'file_count':len(records),'uncompressed_bytes':sum(x['bytes'] for x in records),'excludes':['BIOS/MCPX/EEPROM/HDD','full extracted game and original LIVE container','external SDK/tool source snapshots including nxdk','build caches/intermediate objects','installed font files'],'scope':'Private cumulative original-code port checkpoint. 015 host original-manager/update closure; 011 remains latest native Xbox/xemu acceptance.'}
 mp=W/'package-manifest015.json';mp.write_text(json.dumps(manifest,indent=2)+'\n')
 cs=W/'CHECKSUMS-015.sha256';cs.write_text(''.join(f"{x['sha256']}  {x['path']}\n" for x in records)+f"{digest(mp)}  package-manifest015.json\n")
 a.output.parent.mkdir(parents=True,exist_ok=True)
 with zipfile.ZipFile(a.output,'w',zipfile.ZIP_DEFLATED,compresslevel=6,allowZip64=True) as z:
  for p in files+[mp,cs]:z.write(p,PREFIX+'/'+p.relative_to(W).as_posix())
 print(json.dumps({'archive':str(a.output),'bytes':a.output.stat().st_size,'sha256':digest(a.output),'included_files':len(files)+2,'payload_bytes':manifest['uncompressed_bytes']},indent=2))
if __name__=='__main__':main()
