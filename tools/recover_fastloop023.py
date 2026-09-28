"""Quick recovery loop against the short CC_FRAME_BUDGET probe: resolves
dispatch@ / unsupported@ misses on game bodies anywhere in the run (not just
caller_post_init), stopping at imports, shims and anything else."""
import os,re,subprocess,sys,pathlib
root=pathlib.Path(r'D:\Programming\GitHub\Castle-Crashers-X')
sys.path.insert(0,str(root/'tools'))
from extract_generated021 import expected
reg=(root/'pc/generated/default/castle_crashers_register.cpp').read_text(encoding='latin1')
def rd(p): return (root/p).read_bytes().decode('latin1')
def wr(p,s): (root/p).write_bytes(s.encode('latin1'))
budget=sys.argv[1] if len(sys.argv)>1 else '5'
last=None
for it in range(60):
    r=subprocess.run(['cmake','--build',str(root/'renderer021/build-release'),'-j8'],capture_output=True,text=True)
    if r.returncode: print(r.stdout[-3000:]); sys.exit('BUILD FAILED')
    env=dict(os.environ,CC_FRAME_BUDGET=budget)
    r=subprocess.run([str(root/'renderer021/build-release/cc_update_boundary_tests.exe'),
        str(root/'renderer011/startup.cct'),str(root/'castle-crashers-port/reference/default.image.bin'),
        str(root/'game-data/extracted')],capture_output=True,text=True,env=env)
    out=r.stdout+r.stderr
    fails=re.findall(r'TRACE020 fail error=(\d+) address=([0-9a-f]+)',out)
    fails=[f for f in fails if f[1]!='00021000']
    if not fails:
        print('NO FAIL (rc=%d)'%r.returncode)
        print('\n'.join(l for l in out.splitlines() if re.search(r'crt_|caller_post_init|FAIL line|profile_init',l)))
        break
    err,addr=fails[0]; a=int(addr,16)
    if (err,a)==last: print('no progress',err,addr); break
    last=(err,a)
    name='sub_%08X'%a
    if err not in ('4','9') or ('SetFunction(0x%08X, %s)'%(a,name)) not in reg:
        print('STOP err=%s addr=%s'%(err,addr))
        print('\n'.join(l for l in out.splitlines() if re.search(r'TRACE020|crt_|FAIL line',l))[:3000])
        break
    s=rd('runtime021/bodies.inc')
    if re.search(r'static void %s\(Context& ctx'%name,s):
        print('STOP hand shim',name); break
    s='\n'.join(l for l in s.split('\n') if not re.search(r'HARD_\w+\(%s\b'%name,l))
    have=set(re.findall(r'#include "generated/([^"]+)\.inc"',s))|set(re.findall(r'static void (\w+)\(Context& ctx',s))
    for rt in ('runtime008','runtime010','runtime011'):
        t=rd(rt+'/bodies.inc'); have|=set(re.findall(r'#include "generated/([^"]+)\.inc"',t))|set(re.findall(r'static void (\w+)\(Context& ctx',t))
    have.discard(name)
    todo=[name]; seen=set(have); order=[]
    while todo:
        n=todo.pop(0)
        if n in seen: continue
        seen.add(n); b=expected(n); (root/'runtime021/generated'/(n+'.inc')).write_bytes(b); order.append(n)
        for c in set(re.findall(r'\t(\w+)\(ctx, base\);',b.decode())):
            if not c.startswith('__imp__') and c not in seen: todo.append(c)
    anchor='#include "generated/sub_820A7470.inc"'
    s=s.replace(anchor,anchor+'\n'+'\n'.join('#include "generated/%s.inc"'%n for n in order),1)
    wr('runtime021/bodies.inc',s)
    d=rd('runtime021/decls.inc'); d+=''.join('static void %s(Context&, Machine&);\n'%n for n in order if '%s(Context'%n not in d); wr('runtime021/decls.inc',d)
    alld=''.join(rd(rt+'/dispatch.inc').lower() for rt in ('runtime008','runtime010','runtime011','runtime021'))
    if err=='4' and ('0x%08x'%a) not in alld:
        wr('runtime021/dispatch.inc',rd('runtime021/dispatch.inc')+'case 0x%08X: %s(ctx,base); return;\n'%(a,name))
    print('[%d] %s@%s wired %s'%(it,err,addr,','.join(order)))
