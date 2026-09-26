// SPDX-License-Identifier: MIT
#include "selftest.h"
#include <cstring>
namespace cc::widget011 {
using namespace cc::tree;
struct Output { Case* c; uint32_t texture, used{}; bool fail_bind{},fail_draw{}; };
static bool bind(void* p,uint32_t d,const uint32_t*) {auto& o=*static_cast<Output*>(p);o.texture=d;return !o.fail_bind;}
static bool draw(void* p,const Draw& d) {
 auto& o=*static_cast<Output*>(p);if(o.fail_draw||o.used>=o.c->draws)return false;
 auto e=o.c->expected+o.used*draw_bytes;
 if(o.texture!=little32(e)||d.primitive!=13||d.count!=4||d.stride!=24||d.blend!=little32(e+8)||std::memcmp(d.vertices,e+80,96))return false;
 for(unsigned i=0;i<16;++i)if(d.projection[i]!=little32(e+16+4*i))return false;
 ++o.used;return true;
}
uint32_t self_test(const Fixtures& f,Workspace& w) noexcept {
 uint32_t mask=0;
 for(uint32_t t=0;t<control_count;++t) {
  Case c;if(restore(f,0,w,c)!=FixtureError::ok||c.entry!=0x8209cd08)return mask;
  Output out{&c,c.initial_texture};uint32_t entry=c.entry,budget=200000;
  uint64_t head=0,vt=0;
  if(w.memory.load_be(c.initial.r3.u32+12,4,head)!=cc::xbox::MemoryError::ok || !head || head>0xffffffe7u ||
     w.memory.load_be(uint32_t(head),4,vt)!=cc::xbox::MemoryError::ok || vt>0xffffffe7u) return mask;
  auto set=[&](uint32_t a,unsigned n,uint64_t v){return w.memory.store_be(a,n,v)==cc::xbox::MemoryError::ok;};
  if(t==1)entry=0xdeadbeef;
  if(t==2)budget=1;
  if(t==3&&!set(uint32_t(vt)+24,4,0xdeadbeef))return mask;
  if(t==4)out.fail_bind=true;
  if(t==5)out.fail_draw=true;
  if(t==6&&!set(uint32_t(head)+20,4,head))return mask;
  if(t==7)w.memory=AddressSpace{};
  if(t==8&&!set(uint32_t(head)+20,4,0xfeedbeef))return mask;
  if(t==9&&!set(c.initial.r3.u32+12,4,0))return mask;
  if(t==10&&!set(uint32_t(vt)+12,4,0xdeadbeef))return mask;
  if(t==11)w.ctx.r1.u64=1;
  if(t==12) {
   auto ctx=c.initial;ctx.r4.u64=0;
   auto e=invoke(0x8209ce40,ctx,w.memory,{&out,bind,draw});
   if(e.error!=Error::ok)return mask;
   ctx=c.initial;e=invoke(0x8209ce48,ctx,w.memory,{&out,bind,draw});
   if(e.error!=Error::ok||ctx.r3.u64)return mask;
  }
  if(t==13)w.ctx.r3.u64=0xfffffff0;
  if(t==14) {
   auto ctx=c.initial;ctx.r4.u64=0x1234567800000001ull;
   auto e=invoke(0x8209ce40,ctx,w.memory,{&out,bind,draw});
   if(e.error!=Error::ok)return mask;
   ctx=c.initial;e=invoke(0x8209ce48,ctx,w.memory,{&out,bind,draw});
   if(e.error!=Error::ok||ctx.r3.u64!=1)return mask;
  }
  auto r=invoke(entry,w.ctx,w.memory,{&out,bind,draw},budget);
  bool good=false;
  switch(t) {
   case 0:case 14:good=r.error==Error::ok&&out.used==c.draws&&check_stores(c,w)&&callee_saved(c,w.ctx);break;
   case 1:good=r.error==Error::entry;break;
   case 2:good=r.error==Error::capacity;break;
   case 3:case 10:good=r.error==Error::dispatch&&r.address==0xdeadbeef;break;
   case 4:good=r.error==Error::texture;break;
   case 5:good=r.error==Error::quad&&r.quad_error==uint32_t(cc::quad::Error::sink);break;
   case 6:good=r.error==Error::cycle;break;
   case 7:case 8:good=r.error==Error::memory;break;
   case 9:case 12:good=r.error==Error::ok&&out.used==0&&r.tree_visits==0&&r.bind_calls==0&&callee_saved(c,w.ctx);break;
   case 11:case 13:good=r.error==Error::context;break;
  }
  if(good)mask|=1u<<t;
 }
 return mask;
}
}
