// SPDX-License-Identifier: MIT
#include "selftest.h"
#include <array>
namespace cc::update014 {
using namespace cc::tree;
static bool bind_ok(void*,uint32_t,const uint32_t[20]) { return true; }
static bool draw_ok(void*,const Draw&) { return true; }
static Sink sink() { return {nullptr,bind_ok,draw_ok}; }
static bool put(AddressSpace& m,uint32_t a,unsigned n,uint64_t v) {
  return m.store_be(a,n,v)==cc::xbox::MemoryError::ok;
}
static bool get(AddressSpace& m,uint32_t a,unsigned n,uint64_t& v) {
  return m.load_be(a,n,v)==cc::xbox::MemoryError::ok;
}
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
  const auto r=invoke(0x8209CC98,ctx,w.memory,sink());
  if(r.error==Error::memory && r.address==0x8225e62c && r.dispatches==1) mask|=4;
  return mask;
}
uint32_t synthetic_chain_test() noexcept {
  // Static storage keeps this target self-test off the compiler stack. It is
  // diagnostic state only and is never substituted for captured game state.
  static std::array<uint8_t,4096> stack;
  static std::array<uint8_t,128> widget;
  static std::array<uint8_t,12288> owner;
  static std::array<uint8_t,512> manager;
  static std::array<uint8_t,1536> game_manager;
  static std::array<uint8_t,64> sentinel,node,movie_vt;
  static std::array<uint8_t,128> movie;
  static std::array<uint8_t,256> parser,parser_parent,parser_owner_link,static_constants;
  static std::array<uint8_t,128> parser_vt;
  static std::array<uint8_t,4> manager_global,game_manager_global,active_global;
  stack.fill(0);widget.fill(0);owner.fill(0);manager.fill(0);game_manager.fill(0);sentinel.fill(0);
  node.fill(0);movie.fill(0);movie_vt.fill(0);parser.fill(0);parser_parent.fill(0);
  parser_owner_link.fill(0);parser_vt.fill(0);static_constants.fill(0);
  manager_global.fill(0);game_manager_global.fill(0);active_global.fill(0);
  AddressSpace m;
  if(m.map(0x30000,stack.size(),stack.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x40000,widget.size(),widget.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x50000,owner.size(),owner.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x60000,manager.size(),manager.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x64000,game_manager.size(),game_manager.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x61000,sentinel.size(),sentinel.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x61100,node.size(),node.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x62000,movie.size(),movie.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x62100,movie_vt.size(),movie_vt.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x63000,parser.size(),parser.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x63100,parser_parent.size(),parser_parent.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x63200,parser_owner_link.size(),parser_owner_link.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x63400,parser_vt.size(),parser_vt.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x82042500,static_constants.size(),static_constants.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x8225e62c,4,manager_global.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x8225e61c,4,game_manager_global.data(),3)!=cc::xbox::MemoryError::ok ||
     m.map(0x822666dc,4,active_global.data(),3)!=cc::xbox::MemoryError::ok) return 0;
  uint32_t mask=0; uint64_t v=0;
  Context c{}; c.r1.u32=0x30800; c.f1.f64=1.0/60.0;
  if(!put(m,0x82042540,4,0)||!put(m,0x82042544,4,0x3f800000u)||
     !put(m,0x8204254c,4,0x40a00000u)) return 0;
  Context gm=c; gm.r3.u32=0x64000;
  auto gm_result=invoke(0x820A1AC0,gm,m,sink());
  if(gm_result.error!=Error::ok || !put(m,0x8225e61c,4,0x64000)) return 0;
  // Map hit via manager+76 map object.
  if(!put(m,0x60000+80,4,0x61000)||!put(m,0x61000+4,4,0x61100)||
     !put(m,0x61000+29,1,1)||!put(m,0x61100+0,4,0x61000)||
     !put(m,0x61100+4,4,0x61000)||!put(m,0x61100+8,4,0x61000)||
     !put(m,0x61100+12,4,0x40000)||!put(m,0x61100+29,1,0)) return 0;
  // Direct lookup is tested through the same mapped address space using spare widget bytes.
  if(!put(m,0x40000,4,0x40000)) return 0;
  c.r3.u32=0x60000+76;c.r4.u32=0x40000;
  auto r=invoke(0x82097720,c,m,sink());
  if(r.error==Error::ok && c.r3.u32==0x61110) mask|=1;
  // Full wrapper chain.
  if(!put(m,0x40000+24,1,1)||!put(m,0x40000+96,4,0x50000)||
     !put(m,0x8225e62c,4,0x60000)||!put(m,0x60000+72,4,0)||!put(m,0x60000+8,4,0x40000)||
     !put(m,0x50000+10316,4,0x0badc0de)||!put(m,0x50000+10345,1,1)||
     !put(m,0x50000+10340,4,0x40000000u)||!put(m,0x50000+0,4,0x62000)||
     !put(m,0x62000+0,4,0x62100)||!put(m,0x62100+12,4,0x820772B0u)||
     !put(m,0x50000+72,4,0x63000)||!put(m,0x63000+0,4,0x63400)||
     !put(m,0x63000+156,4,0x63100)||!put(m,0x63100+76,4,0x63200)||
     !put(m,0x63200+156,4,0x50000)||!put(m,0x63400+84,4,0x82088A08u)||
     !put(m,0x63400+88,4,0x8208A228u)) return mask;
  c={};c.r1.u32=0x30800;c.r3.u32=0x40000;c.f1.f64=1.0/60.0;
  r=invoke(0x8209DE50,c,m,sink());
  if(r.error==Error::ok && r.dispatches==3 &&
     get(m,0x60000+88,4,v) && v==0x61110) mask|=2;
  if(get(m,0x50000+10340,4,v) && v!=0x40000000u &&
     get(m,0x822666dc,4,v) && v==0) mask|=4;
  return mask;
}
}
