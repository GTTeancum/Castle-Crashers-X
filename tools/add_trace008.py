"""Install opt-in memory/call tracing in generated PC functions without editing bodies.
Only macro definitions are wrapped; the corresponding original SDK load/store executes.
Original GPU backends are deliberately excluded at their observed replacement boundary.
"""
from pathlib import Path
r=Path(__file__).resolve().parents[1]
if 'CC_SCENE_TRACE008' in (r/'pc/CMakeLists.txt').read_text():
 raise SystemExit('008 migration already installed. Use tools/install_trace008_headers.py for code regeneration.')
header=r/'pc/src/trace008.h'
s='''#pragma once
#include <cstdint>
namespace cc_trace008 {
extern thread_local bool enabled;
void access(uint8_t*, uint32_t, unsigned, bool);
void function(const char*);
void indirect(uint32_t);
}
'''
for n in (8,16,32,64):
 s+=f'''inline uint{n}_t cc008_original_load{n}(uint8_t* base,uint32_t a) {{ return REX_LOAD_U{n}(a); }}
inline void cc008_original_store{n}(uint8_t* base,uint32_t a,uint{n}_t v) {{ REX_STORE_U{n}(a,v); }}
#undef REX_LOAD_U{n}
#define REX_LOAD_U{n}(a) ([&]() {{ uint32_t t=uint32_t(a); if(cc_trace008::enabled)cc_trace008::access(base,t,{n//8},false); return cc008_original_load{n}(base,t); }}())
#undef REX_STORE_U{n}
#define REX_STORE_U{n}(a,v) ([&]() {{ uint32_t t=uint32_t(a); uint{n}_t u=(v); if(cc_trace008::enabled)cc_trace008::access(base,t,{n//8},true); cc008_original_store{n}(base,t,u); }}())
'''
s+='''inline void cc008_original_prologue(uint8_t* base) { REX_FUNC_PROLOGUE(); }
#undef REX_FUNC_PROLOGUE
#define REX_FUNC_PROLOGUE() do { cc008_original_prologue(base); if(cc_trace008::enabled)cc_trace008::function(__func__); } while(0)
inline void cc008_original_dispatch(PPCContext& ctx,uint8_t* base,uint32_t address) { REX_CALL_INDIRECT_FUNC(address); }
#undef REX_CALL_INDIRECT_FUNC
#define REX_CALL_INDIRECT_FUNC(a) do { uint32_t address_=uint32_t(a); if(cc_trace008::enabled)cc_trace008::indirect(address_); cc008_original_dispatch(ctx,base,address_); } while(0)
'''
header.write_text(s)
for p in (r/'pc/generated/default').glob('castle_crashers_funcs.*.h'):
 t=p.read_text(); t+='\n#ifdef CC_SCENE_TRACE008\n#include "src/trace008.h"\n#endif\n';p.write_text(t)
c=r/'pc/CMakeLists.txt';c.write_text(c.read_text()+'''\noption(CC_SCENE_TRACE008 "Trace original scene subtree memory/calls" OFF)
if(CC_SCENE_TRACE008)
  if(NOT CC_RENDER_CAPTURE)
    message(FATAL_ERROR "CC_SCENE_TRACE008 requires CC_RENDER_CAPTURE")
  endif()
  target_compile_definitions(castle_crashers PRIVATE CC_SCENE_TRACE008=1)
endif()
''')
