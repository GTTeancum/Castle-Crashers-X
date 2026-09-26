// SPDX-License-Identifier: MIT
#include "selftest.h"
namespace cc::update012 {
using namespace cc::tree;
static bool bind_ok(void*,uint32_t,const uint32_t[20]) { return true; }
static bool draw_ok(void*,const Draw&) { return true; }
uint32_t captured_boundary_test(const Fixtures& f, Workspace& w) noexcept {
  uint32_t mask=0; Case c;
  if(!f.count || restore(f,0,w,c)!=FixtureError::ok) return mask;
  if(c.entry==0x8209CD08) mask|=1;
  uint64_t head=0,vt=0,update=0;
  if(w.memory.load_be(c.initial.r3.u32+12,4,head)!=cc::xbox::MemoryError::ok || !head) return mask;
  if(w.memory.load_be(uint32_t(head),4,vt)!=cc::xbox::MemoryError::ok || !vt) return mask;
  if(w.memory.load_be(uint32_t(vt)+8,4,update)!=cc::xbox::MemoryError::ok) return mask;
  if(update==0x8209DE50) mask|=2;
  auto ctx=c.initial; ctx.f1.f64=1.0/60.0;
  const auto r=invoke(0x8209CC98,ctx,w.memory,{nullptr,bind_ok,draw_ok});
  if(r.error==Error::memory && r.address==0x8225e62c && r.dispatches==1) mask|=4;
  return mask;
}
}
