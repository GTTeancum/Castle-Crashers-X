#!/usr/bin/env python3
"""Create the private project checkpoint, excluding firmware, full game, SDKs and caches.
Checksums describe included bytes; SHA-256 is not a signature/authentication claim.
"""
from pathlib import Path
import argparse,hashlib,json,stat,zipfile
W=Path(__file__).resolve().parents[1]
PREFIX='CastleCrashers-Checkpoint-006'
KEEP_BUILD={'pc/build004/castle_crashers','pc/build/castle_crashers','renderer006/build-release/cc_live_preview','runtime006/build-release/cc_quad_tests'}
def selected(p):
 r=p.relative_to(W);parts=r.parts;s=r.as_posix()
 if not p.is_file() or p.is_symlink():return False
 if s in KEEP_BUILD:return True
 if any(x in ('.git','__pycache__','pc-user') or x.startswith(('build-','regression006-')) or x=='build' or x=='build004' for x in parts[:-1]):return False
 if s.startswith('castle-crashers-port/extracted/'):return False
 if p.name in ('CHECKSUMS.sha256','package-manifest006.json'):return False
 if any(t in p.name.lower()for t in ('eeprom','test-hdd','mcpx','4627_debug')):return False
 if p.suffix in ('.o','.obj','.pyc','.a','.lib','.so','.partial') or p.name.endswith(('.cpp.d','.c.d')):return False
 if p.suffix=='.su' and not s.startswith('logs/checkpoint006/native-stack-usage/'):return False
 if p.suffix=='.iso' and s!='nxdk-bridge006/CastleCrashers-GameQuadBridge006.iso':return False
 return True
def digest(p):
 h=hashlib.sha256()
 with p.open('rb')as f:
  for b in iter(lambda:f.read(4*1024*1024),b''):h.update(b)
 return h.hexdigest()
def main():
 ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--output',type=Path,default=W.parent/(PREFIX+'.zip'));a=ap.parse_args()
 files=sorted((p for p in W.rglob('*')if selected(p)),key=lambda p:p.relative_to(W).as_posix())
 records=[{'path':p.relative_to(W).as_posix(),'bytes':p.stat().st_size,'sha256':digest(p)}for p in files]
 manifest={'format':'cc-checkpoint006-inventory','files':records,'file_count':len(files),'uncompressed_bytes':sum(r['bytes']for r in records),'excludes':['firmware/MCPX/EEPROM/HDD','full extracted game','external SDKs and source snapshots','build caches/intermediate objects'],'scope':'Private user-game-derived source/capture diagnostic, not an asset-free public release.'}
 mp=W/'package-manifest006.json';mp.write_text(json.dumps(manifest,indent=2)+'\n')
 checksum=W/'CHECKSUMS.sha256';checksum.write_text(''.join(r['sha256']+'  '+r['path']+'\n'for r in records)+digest(mp)+'  package-manifest006.json\n')
 with zipfile.ZipFile(a.output,'w',zipfile.ZIP_DEFLATED,compresslevel=6,allowZip64=True)as z:
  for p in files+[mp,checksum]:z.write(p,PREFIX+'/'+p.relative_to(W).as_posix())
 print(json.dumps({'archive':str(a.output),'bytes':a.output.stat().st_size,'sha256':digest(a.output),'included_files':len(files)+2,'payload_bytes':manifest['uncompressed_bytes']},indent=2))
if __name__=='__main__':main()
