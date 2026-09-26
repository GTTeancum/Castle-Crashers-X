#!/usr/bin/env python3
"""Read back the built XISO and validate its XBE container layout (not execution)."""
import hashlib,json,os,struct,subprocess,tempfile
from pathlib import Path
w=Path(__file__).resolve().parents[1]
base=w/'nxdk-probe'
nxdk=Path(os.environ.get('NXDK_DIR',str(w.parent/'buildkit/sources/nxdk')))
def digest(p):return hashlib.sha256(p.read_bytes()).hexdigest()
with tempfile.TemporaryDirectory(prefix='cc-probe003-') as tmp:
 subprocess.run([str(nxdk/'tools/extract-xiso/build/extract-xiso'),'-x','-d',tmp,str(base/'CastleCrashers-RuntimeProbe003.iso')],check=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
 roundtrip={n:digest(base/'bin'/n)==digest(Path(tmp)/n) for n in ('default.xbe','player.pak')}
 if not all(roundtrip.values()): raise SystemExit('XISO roundtrip mismatch')
p=base/'bin/default.xbe';data=p.read_bytes()
if len(data)<0x178 or data[:4]!=b'XBEH':raise SystemExit('Missing XBE header')
u32=lambda off:struct.unpack_from('<I',data,off)[0]
load=u32(0x104);headers=u32(0x108);image=u32(0x10c);n=u32(0x11c);table=u32(0x120)-load
if not(0<n<=100 and 0<=table<=len(data)-n*0x38 and headers<=len(data)):raise SystemExit('Invalid section table')
sections=[]
for i in range(n):
 off=table+i*0x38
 flags,va,virtual_bytes,raw,raw_bytes,name=struct.unpack_from('<6I',data,off)
 if raw+raw_bytes>len(data) or va<load or va+virtual_bytes>load+image:raise SystemExit('Invalid section extent')
 nameoff=name-load
 if not 0<=nameoff<len(data):raise SystemExit('Invalid section name pointer')
 terminator=data.find(b'\0',nameoff)
 if terminator<0:raise SystemExit('Unterminated section name')
 sections.append({'name':data[nameoff:terminator].decode('ascii'),'flags':flags,'guest_va':hex(va),'virtual_bytes':virtual_bytes,'file_offset':raw,'file_bytes':raw_bytes})
out={'scope':'XBE container and XISO byte roundtrip; no Xbox execution','xbe_bytes':len(data),'xbe_sha256':digest(p),'xiso_bytes':(base/'CastleCrashers-RuntimeProbe003.iso').stat().st_size,'xiso_sha256':digest(base/'CastleCrashers-RuntimeProbe003.iso'),'section_count':n,'sections':sections,'xiso_exact_roundtrip':roundtrip}
print(json.dumps(out,indent=2))
