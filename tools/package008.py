#!/usr/bin/env python3
"""Private cumulative checkpoint. Excludes SDKs, firmware, full game and caches."""
from pathlib import Path
import argparse,hashlib,json,zipfile
W=Path(__file__).resolve().parents[1];PREFIX='CastleCrashers-Checkpoint-008'
KEEP_BUILD={
 'pc/build008/castle_crashers','pc/build004/castle_crashers','pc/build/castle_crashers',
 'renderer008/build-release/cc_scene_preview','renderer008/build-release/cc_scene_preview_soft','renderer008/build-release/cc_tree_tests_soft','renderer008/build-release/cc_fixture_tests','renderer008/build-release/runtime/cc_tree_tests',
 'renderer007/build-release/cc_caller_preview','renderer007/build-release/cc_caller_preview_soft','renderer007/build-release/runtime/cc_caller_tests','renderer007/build-release/runtime/cc_caller_tests_soft','renderer007/build-release/runtime/cc_fused_tests',
 'renderer006/build-release/cc_live_preview','runtime006/build-release/cc_quad_tests'}
def selected(p):
 r=p.relative_to(W);parts=r.parts;s=r.as_posix()
 if not p.is_file() or p.is_symlink():return False
 if s in KEEP_BUILD:return True
 if any(x in ('.git','__pycache__','pc-user') or x.startswith(('build','regression'))for x in parts[:-1]):return False
 if s.startswith('castle-crashers-port/extracted/'):return False
 if p.name=='CHECKSUMS.sha256' or p.name.startswith('package-manifest'):return False
 if any(t in p.name.lower()for t in ('eeprom','test-hdd','mcpx','4627_debug')):return False
 if p.suffix in ('.o','.obj','.pyc','.a','.lib','.so','.partial','.ttf','.otf','.woff','.woff2') or p.name.endswith(('.cpp.d','.c.d')):return False
 if p.suffix=='.su' and 'stack-usage' not in s:return False
 if p.suffix=='.iso' and s!='nxdk-scene008/CastleCrashers-SceneOwner008.iso':return False
 if p.name in ('pid','xvfb.pid','STOP'):return False
 return True
def digest(p):
 h=hashlib.sha256()
 with p.open('rb')as f:
  for b in iter(lambda:f.read(4*1024*1024),b''):h.update(b)
 return h.hexdigest()
def main():
 ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--output',type=Path,default=W.parent/(PREFIX+'.zip'));a=ap.parse_args()
 files=sorted((p for p in W.rglob('*')if selected(p)),key=lambda p:p.relative_to(W).as_posix())
 records=[dict(path=p.relative_to(W).as_posix(),bytes=p.stat().st_size,sha256=digest(p))for p in files]
 manifest=dict(format='cc-checkpoint008-inventory',files=records,file_count=len(files),uncompressed_bytes=sum(r['bytes']for r in records),excludes=['BIOS/MCPX/EEPROM/HDD','full extracted game','external SDK packages/sources','build caches/intermediate objects','installed font files'],scope='Private user-game-derived original-code diagnostic, not live gameplay or an asset-free public release.')
 mp=W/'package-manifest008.json';mp.write_text(json.dumps(manifest,indent=2)+'\n')
 cs=W/'CHECKSUMS.sha256';cs.write_text(''.join(x['sha256']+'  '+x['path']+'\n'for x in records)+digest(mp)+'  package-manifest008.json\n')
 with zipfile.ZipFile(a.output,'w',zipfile.ZIP_DEFLATED,compresslevel=6,allowZip64=True)as z:
  for p in files+[mp,cs]:z.write(p,PREFIX+'/'+p.relative_to(W).as_posix())
 print(json.dumps(dict(archive=str(a.output),bytes=a.output.stat().st_size,sha256=digest(a.output),included_files=len(files)+2,payload_bytes=manifest['uncompressed_bytes']),indent=2))
if __name__=='__main__':main()
