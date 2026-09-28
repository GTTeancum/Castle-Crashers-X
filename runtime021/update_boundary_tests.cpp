// SPDX-License-Identifier: MIT
// Checkpoint 020: bounded acceptance through map-hit lookup and timeline owner entry.
#include "../runtime008/fixtures.h"
#include "selftest.h"
#include "cc_log.h"
#ifdef CC_XBOX_DRIVER
#include <hal/video.h>
#include <windows.h>
#endif
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <vector>
#include <string>
namespace cc { namespace tree { void set_exact_texture_bind(bool) noexcept; } }

using namespace cc::tree;
static uint64_t assertions = 0;
#ifdef CC_XBOX_DRIVER
[[noreturn]] static void cc_fail_exit() { for(;;) { Sleep(1000); } } // keep failure text on screen
#else
[[noreturn]] static void cc_fail_exit() { std::exit(1); }
#endif
#define CHECK(x) do { ++assertions; if (!(x)) { \
  cc_elog("FAIL line %d: %s\n",__LINE__,#x); cc_fail_exit(); } } while(0)
static bool bind_ok(void*,uint32_t,const uint32_t[20]) { return true; }
static bool draw_ok(void*,const Draw&) { return true; }
static Sink sink() { return {nullptr,bind_ok,draw_ok}; }
static void store(AddressSpace& m,uint32_t a,unsigned n,uint64_t v) {
  CHECK(m.store_be(a,n,v)==cc::xbox::MemoryError::ok);
}
static void synthetic_controls() {
  std::array<uint8_t,4096> stack{};
  std::array<uint8_t,128> root{};
  std::array<uint8_t,256> nodes{};
  std::array<uint8_t,64> vt{};
  AddressSpace m;
  CHECK(m.map(0x10000,stack.size(),stack.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x20000,root.size(),root.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x21000,nodes.size(),nodes.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x22000,vt.size(),vt.data(),3)==cc::xbox::MemoryError::ok);
  Context c{};
  c.r1.u32=0x10800; c.r3.u32=0x20000; c.f1.f64=1.0/60.0;
  c.r31.u64=0x1122334455667788ull; c.f31.u64=0x8877665544332211ull;
  c.lr=0x12345678;
  const auto initial=c;

  // Visibility must gate the head access: the deliberately unmapped head is never read.
  store(m,0x20000+24,1,0);
  store(m,0x20000+12,4,0xdeadbeef);
  auto r=invoke(0x8209CC98,c,m,sink());
  CHECK(r.error==Error::ok && r.dispatches==0 && r.functions==1);
  CHECK(c.r1.u64==initial.r1.u64 && c.r31.u64==initial.r31.u64 &&
        c.f31.u64==initial.f31.u64 && c.lr==initial.lr);

  // A visible container with no children is also a clean no-op.
  c=initial; store(m,0x20000+24,1,1); store(m,0x20000+12,4,0);
  r=invoke(0x8209CC98,c,m,sink());
  CHECK(r.error==Error::ok && r.dispatches==0 && r.functions==1);

  // Two synthetic container children dispatch the same unchanged original update walker.
  // The child containers are hidden, so the recursive calls terminate immediately.
  store(m,0x20000+12,4,0x21000);
  store(m,0x21000+0,4,0x22000); store(m,0x21000+20,4,0x21080); store(m,0x21000+24,1,0);
  store(m,0x21080+0,4,0x22000); store(m,0x21080+20,4,0); store(m,0x21080+24,1,0);
  store(m,0x22000+8,4,0x8209CC98);
  c=initial; r=invoke(0x8209CC98,c,m,sink());
  CHECK(r.error==Error::ok && r.dispatches==2 && r.functions==3 && r.deepest_dispatch==1);
  CHECK(c.r1.u64==initial.r1.u64 && c.r31.u64==initial.r31.u64 &&
        c.f31.u64==initial.f31.u64 && c.lr==initial.lr);

  // Cycles are rejected in preflight before generated code can loop forever.
  store(m,0x21000+20,4,0x21000); c=initial;
  r=invoke(0x8209CC98,c,m,sink());
  CHECK(r.error==Error::cycle && r.address==0x21000);
}
static void map_hit_and_wrapper_controls() {
  // First prove the unchanged 0x82097720 ordered-map lookup can take a genuine
  // hit path without touching any of its allocation/insertion dependencies.
  {
    std::array<uint8_t,4096> stack{};
    std::array<uint8_t,128> map{};
    std::array<uint8_t,64> sentinel{};
    std::array<uint8_t,64> node{};
    std::array<uint8_t,16> key{};
    AddressSpace m;
    CHECK(m.map(0x70000,stack.size(),stack.data(),3)==cc::xbox::MemoryError::ok);
    CHECK(m.map(0x80000,map.size(),map.data(),3)==cc::xbox::MemoryError::ok);
    CHECK(m.map(0x81000,sentinel.size(),sentinel.data(),3)==cc::xbox::MemoryError::ok);
    CHECK(m.map(0x82000,node.size(),node.data(),3)==cc::xbox::MemoryError::ok);
    CHECK(m.map(0x83000,key.size(),key.data(),3)==cc::xbox::MemoryError::ok);
    store(m,0x80000+4,4,0x81000);
    store(m,0x81000+4,4,0x82000); store(m,0x81000+29,1,1);
    store(m,0x82000+0,4,0x81000); store(m,0x82000+4,4,0x81000);
    store(m,0x82000+8,4,0x81000); store(m,0x82000+12,4,0x44440000);
    store(m,0x82000+29,1,0); store(m,0x83000,4,0x44440000);
    Context c{}; c.r1.u32=0x70800; c.r3.u32=0x80000; c.r4.u32=0x83000;
    auto r=invoke(0x82097720,c,m,sink());
    CHECK(r.error==Error::ok && c.r3.u32==0x82010 && r.functions==1);
  }

  std::array<uint8_t,4096> stack{};
  std::array<uint8_t,128> widget{};
  std::array<uint8_t,12288> owner{};
  std::array<uint8_t,1536> game_manager{};
  std::array<uint8_t,512> manager_tls{};
  std::array<uint8_t,2048> manager_allocator{};
  std::array<uint8_t,16384> manager_heap{};
  std::array<uint8_t,16> manager_allocator_table{};
  std::array<uint8_t,1> manager_lazy_guard{};
  std::array<uint8_t,4> manager_float_constant{};
  std::array<uint8_t,128> movie{};
  std::array<uint8_t,64> movie_vt{};
  std::array<uint8_t,256> parser{}, parser_parent{}, parser_owner_link{};
  std::array<uint8_t,64> parser_entries{};
  std::array<uint8_t,128> parser_vt{};
  std::array<uint8_t,256> static_constants{};
  std::array<uint8_t,4> manager_global{};
  std::array<uint8_t,4> game_manager_global{};
  std::array<uint8_t,4> active_global{};
  AddressSpace m;
  CHECK(m.map(0x30000,stack.size(),stack.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x40000,widget.size(),widget.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x50000,owner.size(),owner.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x64000,game_manager.size(),game_manager.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x68000,manager_tls.size(),manager_tls.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x70000,manager_allocator.size(),manager_allocator.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x71000,manager_heap.size(),manager_heap.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x822673c0,manager_allocator_table.size(),manager_allocator_table.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x8228a7b7,manager_lazy_guard.size(),manager_lazy_guard.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x820146a0,manager_float_constant.size(),manager_float_constant.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x62000,movie.size(),movie.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x62100,movie_vt.size(),movie_vt.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x63000,parser.size(),parser.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x63100,parser_parent.size(),parser_parent.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x63200,parser_owner_link.size(),parser_owner_link.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x63300,parser_entries.size(),parser_entries.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x63400,parser_vt.size(),parser_vt.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x82042500,static_constants.size(),static_constants.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x8225e62c,4,manager_global.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x8225e61c,4,game_manager_global.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x822666dc,4,active_global.data(),3)==cc::xbox::MemoryError::ok);
  Context initial{}; initial.r1.u32=0x30800; initial.r3.u32=0x40000; initial.r13.u32=0x68000;
  initial.f1.f64=1.0/60.0; initial.r29.u64=0x1111222233334444ull;
  initial.r30.u64=0x5555666677778888ull; initial.r31.u64=0x9999aaaabbbbccccull;
  initial.f31.u64=0x123456789abcdef0ull; initial.lr=0x13572468;

  // Initialize the GameManager state used by 0x820772B0 with its exact original
  // constructor. Only the three immutable float constants read by that constructor
  // are mapped from the sealed image: 0.0f, 1.0f and 5.0f.
  store(m,0x82042540,4,0x00000000u);
  store(m,0x82042544,4,0x3f800000u);
  store(m,0x8204254c,4,0x40a00000u);
  Context gm=initial; gm.r3.u32=0x64000;
  auto gm_result=invoke(0x820A1AC0,gm,m,sink());
  CHECK(gm_result.error==Error::ok);
  store(m,0x8225e61c,4,0x64000);
  uint64_t gmcheck=~0ull;
  CHECK(m.load_be(0x64000+20,4,gmcheck)==cc::xbox::MemoryError::ok && gmcheck==0);
  CHECK(m.load_be(0x64000+1185,1,gmcheck)==cc::xbox::MemoryError::ok && gmcheck==0);

  // Hidden update remains a clean original early-out.
  store(m,0x40000+24,1,0); auto c=initial;
  auto r=invoke(0x8209DE50,c,m,sink());
  CHECK(r.error==Error::ok && r.functions==3 && r.dispatches==0);
  CHECK(c.r1.u64==initial.r1.u64 && c.r29.u64==initial.r29.u64 &&
        c.r30.u64==initial.r30.u64 && c.r31.u64==initial.r31.u64 &&
        c.f31.u64==initial.f31.u64 && c.lr==initial.lr);

  // Exercise the original owner initialization directly. The exact 0x82094420
  // path performs its no-resize 0x820936B0 insertion, exact 0x82094530 lookup,
  // Xbox-scaled timer wrappers, and 0x8208AB98 empty-parser return. With no
  // parser stream attached, this observed shape completes without fabricating
  // a movie object or scene virtual.
  store(m,0x50000+10316,4,0x0badc0de); store(m,0x50000+10345,1,0);
  store(m,0x50000+72,4,0x63000);
  store(m,0x63000+156,4,0x63100); store(m,0x63100+76,4,0x63200);
  store(m,0x63200+156,4,0x50000);
  store(m,0x63000+0,4,0x63400);
  store(m,0x63400+84,4,0x82088A08u); store(m,0x63400+88,4,0x8208A228u);
  store(m,0x63000+112,4,0x63300); store(m,0x63000+116,4,4);
  Context init=initial; init.r3.u32=0x50000;
  r=invoke(0x820915F0,init,m,sink());
  CHECK(r.error==Error::ok);
  uint64_t v=0;
  CHECK(m.load_be(0x50000+10344,1,v)==cc::xbox::MemoryError::ok && v==1);
  CHECK(m.load_be(0x50000+10346,1,v)==cc::xbox::MemoryError::ok && v==1);
  CHECK(m.load_be(0x63000+108,4,v)==cc::xbox::MemoryError::ok && v==1);
  CHECK(m.load_be(0x63300,2,v)==cc::xbox::MemoryError::ok && v==1);
  CHECK(m.load_be(0x50000+8248,4,v)==cc::xbox::MemoryError::ok && v==0);
  cc_log("init_chain result=%s funcs=%u inserted_key=%u\n",name(r.error),r.functions,1u);

  // Empty-depth path with a real synthetic RB-tree hit: wrapper -> exact
  // 0x82097720 hit -> exact 0x820915F0 active-timeline body -> the first
  // statically proven controller virtual. The sealed constructor installs
  // vtable 0x8203E118 and its +0x0C slot is exact original 0x820772B0.
  // The GameManager global is initialized by original 0x820A1AC0, and the
  // parser +84/+88 virtuals are sealed-vtable-derived 0x82088A08/0x8208A228.
  // With the empty synthetic parser/list state, exact 0x8208AE78 also returns
  // cleanly, allowing the entire 0x8209DE50 wrapper to finish.
  // Build and publish the manager with the original sub_820701D0 instruction
  // slice. Unlike checkpoint 014, no manager object, sentinel, node, stack
  // depth, or initial map key is hand-authored here. The initializer creates
  // the key=0 root context that 0x8209DE50 naturally returns to on unwind.
  store(m,0x6810c,1,0);
  store(m,0x822673c0,4,0x70000);
  store(m,0x8228a7b7,1,1);
  store(m,0x70000+8,4,0x71000); store(m,0x70000+12,4,0x75000);
  store(m,0x70000+16,4,0x71000); store(m,0x70000+24,4,1); store(m,0x70000+32,4,16);
  store(m,0x71000+0,4,0); store(m,0x71000+4,4,0);
  store(m,0x71000+8,4,0x4000); store(m,0x71000+12,4,0);
  store(m,0x820146a0,4,0x3f666666u);
  Context manager_init=initial; manager_init.r13.u32=0x68000;
  manager_init.r24.u32=0x822673c0; manager_init.r28.u32=0;
  auto manager_result=invoke(0x82070434,manager_init,m,sink());
  CHECK(manager_result.error==Error::ok);
  uint64_t manager_word=0;
  CHECK(m.load_be(0x8225e62c,4,manager_word)==cc::xbox::MemoryError::ok);
  const uint32_t manager_ptr=uint32_t(manager_word);
  CHECK(manager_ptr==0x71010);
  CHECK(m.load_be(manager_ptr+88,4,manager_word)==cc::xbox::MemoryError::ok);
  const uint32_t root_context_value=uint32_t(manager_word);
  CHECK(root_context_value==0x71150);

  store(m,0x40000+24,1,1); store(m,0x40000+96,4,0x50000);
  store(m,0x50000+10345,1,1); store(m,0x50000+10340,4,0x40000000u); // 2.0f
  store(m,0x50000+0,4,0x62000); store(m,0x62000+0,4,0x62100);
  store(m,0x62100+12,4,0x820772B0u);
  store(m,0x822666dc,4,0);
  c=initial; r=invoke(0x8209DE50,c,m,sink());
  cc_log("active_chain result=%s@%08x funcs=%u dispatches=%u\n",name(r.error),r.address,r.functions,r.dispatches);
  CHECK(r.error==Error::ok && r.dispatches==3);
  CHECK(m.load_be(manager_ptr+72,4,v)==cc::xbox::MemoryError::ok && v==0);
  CHECK(m.load_be(manager_ptr+88,4,v)==cc::xbox::MemoryError::ok && v==root_context_value);
  CHECK(m.load_be(0x822666dc,4,v)==cc::xbox::MemoryError::ok && v==0);
  CHECK(m.load_be(0x50000+10340,4,v)==cc::xbox::MemoryError::ok && v!=0x40000000u);
  cc_log("synthetic_chain manager=%08x root_value=%08x timeline_result=%s timeline_bits=%08x\n",
              manager_ptr, root_context_value, name(r.error), uint32_t(v));
}
static void manager_initializer_controls() {
  // Execute the original sub_820701D0 manager-construction instruction slice
  // from 0x82070434 through the store to global 0x8225E62C. This is a
  // diagnostic mid-function entry with explicit register/memory preconditions;
  // it is not treated as an original callable function boundary.
  std::array<uint8_t,4096> stack{};
  std::array<uint8_t,512> tls{};
  std::array<uint8_t,2048> allocator{};
  std::array<uint8_t,16384> heap{};
  std::array<uint8_t,16> allocator_table{};
  std::array<uint8_t,1> lazy_guard{};
  std::array<uint8_t,4> float_constant{};
  std::array<uint8_t,4> manager_global{};
  std::array<uint8_t,16> second_key{};
  AddressSpace m;
  CHECK(m.map(0x30000,stack.size(),stack.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x68000,tls.size(),tls.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x70000,allocator.size(),allocator.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x71000,heap.size(),heap.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x822673c0,allocator_table.size(),allocator_table.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x8228a7b7,lazy_guard.size(),lazy_guard.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x820146a0,float_constant.size(),float_constant.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x8225e62c,manager_global.size(),manager_global.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x69000,second_key.size(),second_key.data(),3)==cc::xbox::MemoryError::ok);

  // Exact allocator routines are used. The synthetic fixture provides one
  // ordinary free extent and marks the process-wide lazy init guard complete,
  // so unobserved OS allocation/critical-section paths remain hard boundaries.
  store(m,0x6810c,1,0);          // r13+268 allocator-table index
  store(m,0x822673c0,4,0x70000); // allocator table[0]
  store(m,0x8228a7b7,1,1);       // allocator lazy-init guard already initialized
  store(m,0x70000+8,4,0x71000);  // heap low bound
  store(m,0x70000+12,4,0x75000); // heap high bound
  store(m,0x70000+16,4,0x71000); // free-list head
  store(m,0x70000+24,4,1);       // accounting bucket carried into used blocks
  store(m,0x70000+32,4,16);      // allocator alignment
  store(m,0x71000+0,4,0);
  store(m,0x71000+4,4,0);
  store(m,0x71000+8,4,0x4000);
  store(m,0x71000+12,4,0);
  store(m,0x820146a0,4,0x3f666666u);        // sealed-image 0.9f loaded by the initializer slice

  Context c{};
  c.r1.u32=0x30800;
  c.r13.u32=0x68000;
  c.r24.u32=0x822673c0;
  c.r28.u32=0;
  c.lr=0x0badf00d;
  auto r=invoke(0x82070434,c,m,sink());
  cc_log("manager_init result=%s@%08x funcs=%u memops=%u global=%08x\n",
              name(r.error),r.address,r.functions,r.memory_ops,c.r31.u32);
  CHECK(r.error==Error::ok);
  uint64_t v=0;
  CHECK(m.load_be(0x8225e62c,4,v)==cc::xbox::MemoryError::ok);
  const uint32_t manager=uint32_t(v);
  CHECK(manager==0x71010);
  CHECK(m.load_be(manager+72,4,v)==cc::xbox::MemoryError::ok && v==0);
  CHECK(m.load_be(manager+100,4,v)==cc::xbox::MemoryError::ok && v==0x3f666666u);
  CHECK(m.load_be(manager+8,4,v)==cc::xbox::MemoryError::ok && v==0);
  CHECK(m.load_be(manager+80,4,v)==cc::xbox::MemoryError::ok);
  const uint32_t sentinel=uint32_t(v);
  CHECK(sentinel==0x710b0);
  CHECK(m.load_be(sentinel+4,4,v)==cc::xbox::MemoryError::ok);
  const uint32_t node=uint32_t(v);
  CHECK(node==0x71140);
  CHECK(m.load_be(node+12,4,v)==cc::xbox::MemoryError::ok && v==0);
  CHECK(m.load_be(node+29,1,v)==cc::xbox::MemoryError::ok && v==0);
  CHECK(m.load_be(manager+88,4,v)==cc::xbox::MemoryError::ok && v==node+16);
  CHECK(m.load_be(node+20,4,v)==cc::xbox::MemoryError::ok && v==0x71170);
  cc_log("manager_init global=%08x sentinel=%08x root=%08x value=%08x nested_sentinel=%08x\n",
              manager,sentinel,node,node+16,0x71170u);
  store(m,0x69000,4,0x40000);
  Context k{}; k.r1.u32=0x30800; k.r13.u32=0x68000; k.r3.u32=manager+76; k.r4.u32=0x69000;
  auto kr=invoke(0x82097720,k,m,sink());
  cc_log("manager_second_insert result=%s@%08x funcs=%u memops=%u ret=%08x\n",
              name(kr.error),kr.address,kr.functions,kr.memory_ops,k.r3.u32);
}


static void startup_full_controls(const char* image_path) {
  std::FILE* stream=std::fopen(image_path,"rb");
  CHECK(stream!=nullptr);
  std::fseek(stream,0,SEEK_END);
  const long image_size=std::ftell(stream);
  std::fseek(stream,0,SEEK_SET);
  CHECK(image_size>0);
  std::vector<uint8_t> image(static_cast<size_t>(image_size));
  CHECK(std::fread(image.data(),1,image.size(),stream)==image.size());
  std::fclose(stream);
  CHECK(image.size()==0x2d0000u);
  std::array<uint8_t,0x10000> stack{};
  std::array<uint8_t,0x1000> tls{};
  std::array<uint8_t,0x1000> allocator{};
  std::vector<uint8_t> heap(0x1000000);
  AddressSpace m;
  CHECK(m.map(0x82000000,uint32_t(image.size()),image.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x30000,stack.size(),stack.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x68000,tls.size(),tls.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x70000,allocator.size(),allocator.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x71000,uint32_t(heap.size()),heap.data(),3)==cc::xbox::MemoryError::ok);

  // Keep only the process allocator's already-initialized platform state as a
  // host fixture. All game constants, vtables and writable globals begin as a
  // mutable copy of the sealed mapped image.
  store(m,0x6810c,1,0);
  store(m,0x822673c0,4,0x70000);
  store(m,0x8228a7b7,1,1);
  store(m,0x70000+8,4,0x71000);
  store(m,0x70000+12,4,0x1071000);
  store(m,0x70000+16,4,0x71000);
  store(m,0x70000+24,4,1);
  store(m,0x70000+32,4,16);
  store(m,0x71000+0,4,0);
  store(m,0x71000+4,4,0);
  store(m,0x71000+8,4,0x1000000);
  store(m,0x71000+12,4,0);

  Context c{};
  c.r1.u32=0x3f000;
  c.r13.u32=0x68000;
  c.lr=0x0c0160c0;
  auto r=invoke(0x820701d0,c,m,sink(),12000000);
  cc_log("startup_full result=%s@%08x funcs=%u dispatch=%u memops=%u r1=%08x r31=%08x\n",
              name(r.error),r.address,r.functions,r.dispatches,r.memory_ops,c.r1.u32,c.r31.u32);
  CHECK(r.error==Error::ok);
  CHECK(c.r1.u32==0x3f000u);
  CHECK(c.lr==0x0c0160c0u);

  uint64_t v=0;
  CHECK(m.load_be(0x8225e630,4,v)==cc::xbox::MemoryError::ok && v!=0); const uint32_t label_owner=uint32_t(v);
  CHECK(m.load_be(0x8225e604,4,v)==cc::xbox::MemoryError::ok && v!=0); const uint32_t small_state=uint32_t(v);
  CHECK(m.load_be(0x8225e620,4,v)==cc::xbox::MemoryError::ok && v!=0); const uint32_t input_state=uint32_t(v);
  CHECK(m.load_be(0x8225e60c,4,v)==cc::xbox::MemoryError::ok && v!=0); const uint32_t hash_state=uint32_t(v);
  CHECK(m.load_be(0x8225e600,4,v)==cc::xbox::MemoryError::ok && v!=0); const uint32_t pool_state=uint32_t(v);
  CHECK(m.load_be(0x8225e62c,4,v)==cc::xbox::MemoryError::ok && v!=0); const uint32_t manager=uint32_t(v);
  CHECK(m.load_be(0x8225e614,4,v)==cc::xbox::MemoryError::ok && v!=0); const uint32_t async_state=uint32_t(v);
  CHECK(m.load_be(0x8225e634,4,v)==cc::xbox::MemoryError::ok && v!=0); const uint32_t event_state=uint32_t(v);
  CHECK(m.load_be(0x8225e61c,4,v)==cc::xbox::MemoryError::ok && v!=0); const uint32_t game_manager=uint32_t(v);
  CHECK(m.load_be(0x8225e608,4,v)==cc::xbox::MemoryError::ok && v!=0); const uint32_t state_pool=uint32_t(v);
  CHECK(m.load_be(0x8225e63c,4,v)==cc::xbox::MemoryError::ok && v!=0); const uint32_t system_state=uint32_t(v);
  CHECK(m.load_be(0x8225e638,4,v)==cc::xbox::MemoryError::ok && v!=0); const uint32_t worker_handles=uint32_t(v);
  CHECK(m.load_be(0x8225e610,4,v)==cc::xbox::MemoryError::ok && v!=0); const uint32_t lookup_state=uint32_t(v);
  CHECK(label_owner>=0x71000 && label_owner<0x1071000);
  CHECK(small_state>=0x71000 && small_state<0x1071000);
  CHECK(input_state>=0x71000 && input_state<0x1071000);
  CHECK(hash_state>=0x71000 && hash_state<0x1071000);
  CHECK(pool_state>=0x71000 && pool_state<0x1071000);
  CHECK(manager>=0x71000 && manager<0x1071000);
  CHECK(async_state>=0x71000 && async_state<0x1071000);
  CHECK(event_state>=0x71000 && event_state<0x1071000);
  CHECK(game_manager>=0x71000 && game_manager<0x1071000);
  CHECK(state_pool>=0x71000 && state_pool<0x1071000);
  CHECK(system_state>=0x71000 && system_state<0x1071000);
  CHECK(worker_handles>=0x71000 && worker_handles<0x1071000);
  CHECK(lookup_state>=0x71000 && lookup_state<0x1071000);
  for (unsigned i=0;i<5;++i) {
    CHECK(m.load_be(worker_handles+i*4,4,v)==cc::xbox::MemoryError::ok &&
          v==0xF1000001u+i);
  }
  CHECK(m.load_be(lookup_state+0,4,v)==cc::xbox::MemoryError::ok && v==613);
  CHECK(m.load_be(lookup_state+4,4,v)==cc::xbox::MemoryError::ok && v==9);
  CHECK(m.load_be(lookup_state+8,4,v)==cc::xbox::MemoryError::ok && v==0); // English
  CHECK(m.load_be(lookup_state+12,4,v)==cc::xbox::MemoryError::ok && v!=0);
  const uint32_t lookup_table=uint32_t(v);
  CHECK(lookup_table>=0x71000 && lookup_table<0x1071000);
  for (unsigned i=0;i<613;++i) {
    CHECK(m.load_be(lookup_table+i*4,4,v)==cc::xbox::MemoryError::ok &&
          v==0x82229938u+i*40u);
  }
  CHECK(m.load_be(async_state+0,1,v)==cc::xbox::MemoryError::ok && v==0);
  CHECK(m.load_be(async_state+8,4,v)==cc::xbox::MemoryError::ok && v==0);
  CHECK(m.load_be(event_state,4,v)==cc::xbox::MemoryError::ok && v!=0);
  const uint32_t event_payload=uint32_t(v)-4;
  CHECK(event_payload>=0x71000 && event_payload<0x1071000);
  CHECK(m.load_be(event_payload+0,4,v)==cc::xbox::MemoryError::ok && v==4);
  CHECK(m.load_be(event_payload+6,2,v)==cc::xbox::MemoryError::ok && v==0xffff);
  CHECK(m.load_be(game_manager+20,4,v)==cc::xbox::MemoryError::ok && v==0);
  CHECK(m.load_be(game_manager+1185,1,v)==cc::xbox::MemoryError::ok && v==0);
  CHECK(m.load_be(state_pool+0,4,v)==cc::xbox::MemoryError::ok && v==0x8203eee0u);
  CHECK(m.load_be(state_pool+112492,4,v)==cc::xbox::MemoryError::ok && v!=0);
  const uint32_t state_block=uint32_t(v);
  CHECK(state_block>=0x71000 && state_block<0x1071000);
  CHECK(m.load_be(state_pool+28,4,v)==cc::xbox::MemoryError::ok && v==state_block);
  CHECK(m.load_be(state_block+0,4,v)==cc::xbox::MemoryError::ok && v!=0);
  // English language (0) and North America region (0) since the port's
  // console reports XGAME_REGION_NA_ALL / XC_LANGUAGE_ENGLISH.
  CHECK(m.load_be(system_state+0,4,v)==cc::xbox::MemoryError::ok && v==0);
  CHECK(m.load_be(system_state+4,4,v)==cc::xbox::MemoryError::ok && v==0);
  CHECK(m.load_be(system_state+8,1,v)==cc::xbox::MemoryError::ok && v==1);
  CHECK(m.load_be(system_state+12,4,v)==cc::xbox::MemoryError::ok && v==640);
  CHECK(m.load_be(system_state+16,4,v)==cc::xbox::MemoryError::ok && v==480);
  CHECK(m.load_be(manager+100,4,v)==cc::xbox::MemoryError::ok && v==0x3f666666u);
  CHECK(m.load_be(manager+80,4,v)==cc::xbox::MemoryError::ok && v!=0); const uint32_t sentinel=uint32_t(v);
  CHECK(m.load_be(sentinel+4,4,v)==cc::xbox::MemoryError::ok && v!=0); const uint32_t root=uint32_t(v);
  CHECK(m.load_be(root+12,4,v)==cc::xbox::MemoryError::ok && v==0);
  CHECK(m.load_be(manager+88,4,v)==cc::xbox::MemoryError::ok && v==root+16);
  // sub_8209CA70's bounded %i shim must have produced the first startup label.
  CHECK(m.load_be(0x8228a7bc,4,v)==cc::xbox::MemoryError::ok && v==1);
  CHECK(m.load_be(label_owner+12,4,v)==cc::xbox::MemoryError::ok && v!=0);
  const uint32_t label_table=uint32_t(v);
  CHECK(m.load_be(label_table,4,v)==cc::xbox::MemoryError::ok && v!=0);
  const uint32_t label_page=uint32_t(v);
  CHECK(m.load_be(label_page,4,v)==cc::xbox::MemoryError::ok && v!=0);
  const uint32_t label_object=uint32_t(v);
  CHECK(m.load_be(label_object+28,4,v)==cc::xbox::MemoryError::ok && v==1);
  CHECK(m.load_be(label_object+32,1,v)==cc::xbox::MemoryError::ok && v==uint8_t('1'));
  CHECK(m.load_be(label_object+33,1,v)==cc::xbox::MemoryError::ok && v==0);

  // The critical-section host boundary is reached six times inside the exact
  // 14,656-byte constructor; the prefix does not enter any lock operation.
  for (unsigned i=0;i<6;++i) {
    const uint32_t cs=pool_state+14488+i*28;
    for (unsigned j=0;j<28;++j) {
      CHECK(m.load_be(cs+j,1,v)==cc::xbox::MemoryError::ok && v==0);
    }
  }
  cc_log("startup_full globals label=%08x small=%08x input=%08x hash=%08x pool=%08x manager=%08x async=%08x event=%08x game_manager=%08x state_pool=%08x system_state=%08x workers=%08x lookup=%08x state_block=%08x sentinel=%08x root=%08x\n",
              label_owner,small_state,input_state,hash_state,pool_state,manager,async_state,event_state,game_manager,state_pool,system_state,worker_handles,lookup_state,state_block,sentinel,root);
}


static void renderer_caller_prefix_controls(const char* image_path) {
  std::FILE* stream=std::fopen(image_path,"rb");
  CHECK(stream!=nullptr);
  std::fseek(stream,0,SEEK_END);
  const long image_size=std::ftell(stream);
  std::fseek(stream,0,SEEK_SET);
  CHECK(image_size>0);
  std::vector<uint8_t> image(static_cast<size_t>(image_size));
  CHECK(std::fread(image.data(),1,image.size(),stream)==image.size());
  std::fclose(stream);
  CHECK(image.size()==0x2d0000u);
  std::array<uint8_t,0x10000> stack{};
  std::array<uint8_t,0x1000> tls{};
  std::array<uint8_t,0x1000> allocator{};
  std::vector<uint8_t> heap(0xE00000);  // game heap: level 1 high-water 13.3 MiB (retail budget)
  std::array<uint8_t,0x1000> platform_globals{};
  std::array<uint8_t,0x1000> thread_state{};
  AddressSpace m;
  CHECK(m.map(0x82000000,uint32_t(image.size()),image.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x30000,stack.size(),stack.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x68000,tls.size(),tls.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x70000,allocator.size(),allocator.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x71000,uint32_t(heap.size()),heap.data(),3)==cc::xbox::MemoryError::ok);
  // Graphics arena 0x02000000..0x02500000. The device init places the 2 MiB
  // command ring at 0x0200F140 and two 640x480x32 surfaces (0x12C000 each)
  // at 0x02211770 and 0x02344FA0. Only the 360 GPU consumes them; the port
  // draws from the game's draw calls. Options (host) / port policy (Xbox):
  // alias both surfaces onto one block, and back the ring with one 256 KiB
  // block repeated over its 2 MiB.
  // Default on (identical instruction and memory-op counts with and without
  // aliasing: the game never reads these back). CC_GFX_ALIAS=none disables.
  const char* gfx_alias_env = std::getenv("CC_GFX_ALIAS");
  const std::string gfx_alias = gfx_alias_env ? gfx_alias_env : "surfaces,ring";
  const bool alias_surfaces = gfx_alias.find("surfaces") != std::string::npos;
  const bool alias_ring = gfx_alias.find("ring") != std::string::npos;
  static std::vector<uint8_t> graphics_heap;
  {
    // Pieces are packed into one compact backing block; aliased ranges share
    // storage, so only the distinct bytes are allocated (5 MiB -> ~2.1 MiB).
    struct Piece { uint32_t lo, len; int share; };  // share: -1 own storage, else index
    constexpr uint32_t ring_lo = 0x0200F140u, ring_len = 0x200000u;
    constexpr uint32_t surf_a = 0x02211770u, surf_b = 0x02344FA0u, surf_len = 0x12C000u;
    std::vector<Piece> pieces = {
      {0x02000000u, ring_lo - 0x02000000u, -1},
      {ring_lo + ring_len, surf_a - (ring_lo + ring_len), -1},
      {surf_a, surf_len, -1},
      {surf_a + surf_len, surf_b - (surf_a + surf_len), -1},
      {surf_b, surf_len, alias_surfaces ? 2 : -1},
      {surf_b + surf_len, 0x02500000u - (surf_b + surf_len), -1},
    };
    const size_t ring_piece = pieces.size();
    if (alias_ring) {
      pieces.push_back({ring_lo, 0x40000u, -1});
      for (uint32_t a = ring_lo + 0x40000u; a < ring_lo + ring_len; a += 0x40000u)
        pieces.push_back({a, 0x40000u, int(ring_piece)});
    } else {
      pieces.push_back({ring_lo, ring_len, -1});
    }
    std::vector<size_t> offset(pieces.size());
    size_t total = 0;
    for (size_t i = 0; i < pieces.size(); ++i)
      if (pieces[i].share < 0) { offset[i] = total; total += pieces[i].len; }
    graphics_heap.assign(total, 0);
    for (size_t i = 0; i < pieces.size(); ++i) {
      const size_t off = pieces[i].share < 0 ? offset[i] : offset[size_t(pieces[i].share)];
      CHECK(m.map(pieces[i].lo, pieces[i].len, graphics_heap.data() + off, 3) == cc::xbox::MemoryError::ok);
    }
    cc_log("graphics_arena backing=%uK surfaces_aliased=%d ring_aliased=%d\n",
           unsigned(total >> 10), int(alias_surfaces), int(alias_ring));
  }
  CHECK(m.map(0x02500000,uint32_t(platform_globals.size()),platform_globals.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x02501000,uint32_t(thread_state.size()),thread_state.data(),3)==cc::xbox::MemoryError::ok);

  // Same narrow process fixture as startup_full_controls. Everything the game
  // publishes after this point must come from original translated code.
  store(m,0x6810c,1,0);
  store(m,0x822673c0,4,0x70000);
  store(m,0x8228a7b7,1,1);
  store(m,0x70000+8,4,0x71000);
  store(m,0x70000+12,4,0x1071000);
  store(m,0x70000+16,4,0x71000);
  store(m,0x70000+24,4,1);
  store(m,0x70000+32,4,16);
  store(m,0x71000+0,4,0);
  store(m,0x71000+4,4,0);
  store(m,0x71000+8,4,0x1000000);
  store(m,0x71000+12,4,0);
  // The sealed image carries unresolved Xbox loader tokens in imported-variable
  // slots. Model only the exact variable slots reached by this graphics path, and
  // provide the exact TLS shape consumed by sub_82136728.
  store(m,0x820005cc,4,0x02500000u);
  // Xbox kernel ordinal 89 is KeDebugMonitorData. The real loader resolves
  // this variable import to an address containing a null pointer when no debugger is attached.
  store(m,0x8200068c,4,0x02500004u);
  store(m,0x02500004u,4,0u);
  // Xbox kernel ordinal 614 is KeCertMonitorData. The loader resolves
  // this variable slot; the bounded fixture exposes the documented null state.
  store(m,0x820005d0,4,0x02500008u);
  store(m,0x02500008u,4,0u);
  // Xbox kernel ordinal 449 is VdHSIOCalibrationLock, a loader-resolved
  // critical-section variable. Keep its 28-byte object separate from other
  // platform globals so sub_820D19E8 can exercise the exact lock path.
  store(m,0x82000594,4,0x0250000cu);
  for (uint32_t i=0;i<28u;++i) store(m,0x0250000cu+i,1,0u);
  // Xbox kernel ordinal 448 is VdGpuClockInMHz. Xenia's kernel model maps
  // this loader-resolved variable to the documented Xenos 500 MHz clock.
  store(m,0x82000580,4,0x02500028u);
  store(m,0x02500028u,4,500u);
  store(m,0x68100,4,0x02501000u);
  store(m,0x02501000u+332u,4,0x44556677u);
  // The exact file wrappers publish GetLastError-style state through the same
  // per-thread block already resolved via [r13+256]=0x02501000 (owner cookie
  // at +332, last error at +352); no separate error-block fixture is needed.
  // Xbox kernel ordinal 403 is XexExecutableModuleHandle, a loader-resolved
  // variable. The fixture resolves it to a slot holding a null module handle,
  // so exact sub_820B7880 takes its default 1 MiB heap-reserve path without
  // querying the XEX header.
  store(m,0x82000600,4,0x0250002Cu);
  store(m,0x0250002Cu,4,0u);
  // Xbox kernel ordinal 173 is KeTimeStampBundle, a loader-resolved variable
  // (InterruptTime u64, SystemTime u64, TickCount u32). The game's Live layer
  // reads TickCount through exact sub_82136F58. The bundle lives in the
  // platform-globals page and is advanced every frame from the virtual
  // timebase by the KeDelayExecutionThread frame contract.
  store(m,0x82000704,4,0x02500100u);
  for (uint32_t i=0;i<24u;i+=4u) store(m,0x02500100u+i,4,0u);
  // Guest arena backing the bounded NtAllocateVirtualMemory contract used by
  // the exact CRT heap (reservations start at 0x04000000).
  // WIP 023: the frame loop's pak loader parses whole asset files through
  // CRT heap blocks (logo.pak alone is 1.3 MiB), so the startup-era 1 MiB
  // arena starves it and the loader retries forever. 8 MiB covers the
  // observed intro assets; exhaustion still fails closed.
  // Retail 64 MB budget (TODO.md): 20 KB used by level 1 of 1 MiB reserved.
  static std::vector<uint8_t> heap_arena(0x100000);
  CHECK(m.map(0x04000000u,uint32_t(heap_arena.size()),heap_arena.data(),3)==cc::xbox::MemoryError::ok);
  // Guest arena backing the single observed MmAllocatePhysicalMemoryEx main
  // pool (16 MiB + guard page) requested by exact sub_8209BC98 after Init.
  // Retail budget: the game reserves 16 MiB but uses 3.9 MiB (high-water)
  // once SOUNDS.PAK's unused MP3 data is stripped; only 4.5 MiB is backed and
  // any access beyond it fails closed.
  static std::vector<uint8_t> main_pool_arena(0x480000);
  CHECK(m.map(0x10000000u,uint32_t(main_pool_arena.size()),main_pool_arena.data(),3)==cc::xbox::MemoryError::ok);
  // Cursor arena backing the smaller observed physical blocks (font/texture
  // memory allocated write-combined by the exact font loader).
  // Retail budget: fonts, rasterizer scratch and pak/sound buffers (the
  // texture cache and small blocks have zones of their own below).
  static std::vector<uint8_t> phys_arena(0x00480000);  // level 1 high-water 3.3 MiB
  CHECK(m.map(0x12000000u,uint32_t(phys_arena.size()),phys_arena.data(),3)==cc::xbox::MemoryError::ok);
  // Small-block zone of the same allocator (<= 4 KiB blocks), kept apart so
  // they cannot fragment the large-block arena.
  static std::vector<uint8_t> phys_small_arena(0x00100000);  // high-water 0.26 MiB
  CHECK(m.map(0x1E000000u,uint32_t(phys_small_arena.size()),phys_small_arena.data(),3)==cc::xbox::MemoryError::ok);
  // Texture stub zone: the loader's full-size texture blocks, each cut to a
  // 16-byte stub once recorded (the largest transient block is 2 MiB).
  static std::vector<uint8_t> tex_stub_arena(0x00180000);  // high-water 1.07 MiB
  CHECK(m.map(0x1D000000u,uint32_t(tex_stub_arena.size()),tex_stub_arena.data(),3)==cc::xbox::MemoryError::ok);
  // Texture cache zone (buddy allocator, 4 MiB) for the DXT5 texture cache.
  static std::vector<uint8_t> tex_zone_arena(0x00400000);
  CHECK(m.map(0x1C000000u,uint32_t(tex_zone_arena.size()),tex_zone_arena.data(),3)==cc::xbox::MemoryError::ok);

  // Execute the exact CRT heap initialization (sub_820B7880 -> exact
  // sub_820B93B0) that original startup performs before any game code runs.
  // The exact heap then serves every later original allocation on this path.
  {
    Context hc{};
    hc.r1.u32=0x3f000;
    hc.r13.u32=0x68000;
    hc.lr=0x0c0160c0;
    auto hr=invoke(0x820b7880,hc,m,sink(),200000);
    uint64_t hv=0;
    const bool hok=m.load_be(0x82290B3Cu,4,hv)==cc::xbox::MemoryError::ok;
    cc_log("crt_heap_init result=%s@%08x funcs=%u memops=%u r3=%08x handle=%08x\n",
                name(hr.error),hr.address,hr.functions,hr.memory_ops,hc.r3.u32,
                hok?uint32_t(hv):0xffffffffu);
    CHECK(hr.error==Error::ok);
    CHECK(hc.r3.u32==1u);
    CHECK(hok && hv!=0u);
  }

  // WIP 023: execute the exact CRT _mtinit (sub_8212A630), the second
  // startup step the sealed XEX entry performs before game code: it
  // allocates the CRT TLS index (KeTlsAlloc fixture), publishes the
  // per-thread-data accessors, and creates the main thread's ptd through
  // the exact CRT heap. Without it the frame loop's first rand()-family
  // call reads TLS index -1.
  {
    Context tc{};
    tc.r1.u32=0x3f000;
    tc.r13.u32=0x68000;
    tc.lr=0x0c0160c0;
    auto tr=invoke(0x8212a630,tc,m,sink(),400000);
    uint64_t tls_index=0xffffffffu, ptd=0;
    const bool iok=m.load_be(0x82157A08u,4,tls_index)==cc::xbox::MemoryError::ok;
    const bool pok=m.load_be(0x82157A04u,4,ptd)==cc::xbox::MemoryError::ok;
    cc_log("crt_mtinit result=%s@%08x funcs=%u memops=%u r3=%08x tls_index=%08x ptd=%08x\n",
                name(tr.error),tr.address,tr.functions,tr.memory_ops,tc.r3.u32,
                iok?uint32_t(tls_index):0xffffffffu,pok?uint32_t(ptd):0u);
    CHECK(tr.error==Error::ok);
    CHECK(tc.r3.u32==1u);           // _mtinit success
    CHECK(iok && tls_index<64u);    // CRT TLS index allocated
    CHECK(pok && ptd!=0u);          // main-thread ptd published
  }

  // WIP 023: the remaining CRT startup steps, run exactly as the sealed XEX
  // entry (xstart) does after _mtinit: exact sub_820B7730 walks the
  // pre-initializer table 0x82150000..0x8215000C (the onexit-table setup
  // sub_82127E48 and sub_8212E7E8), then exact sub_820B7650 (_cinit, r3=1)
  // walks the C initializers 0x8215005C..0x82150068 and the sixteen C++
  // static constructors 0x82150010..0x82150058. Without these, every global
  // object the game builds at startup (including the Live layer's
  // allocator) was left unconstructed.
  {
    Context pc{};
    pc.r1.u32=0x3f000;
    pc.r13.u32=0x68000;
    pc.lr=0x0c0160c0;
    auto pr=invoke(0x820b7730,pc,m,sink(),400000);
    uint64_t tb=0;
    const bool tok=m.load_be(0x82290CACu,4,tb)==cc::xbox::MemoryError::ok;
    cc_log("crt_preinit result=%s@%08x r3=%08x onexit_table=%08x\n",
                name(pr.error),pr.address,pc.r3.u32,tok?uint32_t(tb):0u);
    CHECK(pr.error==Error::ok);
    CHECK(pc.r3.u32==0u);
    CHECK(tok && tb!=0u);

    Context cc{};
    cc.r1.u32=0x3f000;
    cc.r13.u32=0x68000;
    cc.lr=0x0c0160c0;
    cc.r3.u64=1u;
    auto cr=invoke(0x820b7650,cc,m,sink(),4000000);
    cc_log("crt_cinit result=%s@%08x funcs=%u memops=%u r3=%08x\n",
                name(cr.error),cr.address,cr.functions,cr.memory_ops,cc.r3.u32);
    CHECK(cr.error==Error::ok);
    CHECK(cc.r3.u32==0u);
  }

  Context c{};
  c.r1.u32=0x3f000;
  c.r13.u32=0x68000;
  c.lr=0x0c0160c0;
  auto r=invoke(0x82070ac8,c,m,sink(),12000000);
  cc_log("renderer_prefix result=%s@%08x funcs=%u dispatch=%u memops=%u r1=%08x r3=%08x lr=%08x\n",
              name(r.error),r.address,r.functions,r.dispatches,r.memory_ops,
              c.r1.u32,c.r3.u32,uint32_t(c.lr));
  CHECK(r.error==Error::ok);
  CHECK(c.r1.u32==0x3eee0u);       // original sub_82070AC8 frame remains live at the diagnostic stop
  CHECK(c.r3.u32==0x3ef50u);       // original argument prepared for PlatformRenderer::Init
  CHECK(c.lr==0x82070b84u);        // last completed original call was sub_820A7668

  uint64_t v=0;
  CHECK(m.load_be(0x8225e628,4,v)==cc::xbox::MemoryError::ok && v!=0);
  const uint32_t renderer=uint32_t(v);
  CHECK(renderer>=0x71000u && renderer+30216u<=0x1071000u);
  CHECK(m.load_be(renderer+0,4,v)==cc::xbox::MemoryError::ok && v==0x82042048u);
  CHECK(m.load_be(renderer+4,4,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(renderer+29128,4,v)==cc::xbox::MemoryError::ok && v==3u);
  CHECK(m.load_be(renderer+29136,4,v)==cc::xbox::MemoryError::ok && v==1u);
  CHECK(m.load_be(renderer+29828,1,v)==cc::xbox::MemoryError::ok && v==0u);
  // The caller also performs the second-stage small-state setup after startup.
  CHECK(m.load_be(0x8225e604,4,v)==cc::xbox::MemoryError::ok && v!=0);
  const uint32_t small_state=uint32_t(v);
  CHECK(m.load_be(small_state+4,1,v)==cc::xbox::MemoryError::ok && v==1u);
  cc_log("renderer_prefix published=%08x next_original_call=820A7990 platform_renderer_init\n",renderer);

  // Continue at the exact PlatformRenderer::Init entry using the state and stack
  // prepared by the original caller. This prefix consumes XGetVideoMode and
  // stops immediately before the first graphics-device helper.
  auto pr=invoke(0x820a7990,c,m,sink(),20000);
  cc_log("platform_init_prefix result=%s@%08x funcs=%u memops=%u r1=%08x r3=%08x r4=%08x r7=%08x r8=%08x\n",
              name(pr.error),pr.address,pr.functions,pr.memory_ops,c.r1.u32,c.r3.u32,c.r4.u32,c.r7.u32,c.r8.u32);
  CHECK(pr.error==Error::ok);
  CHECK(c.r1.u32==0x3ed30u);
  CHECK(c.r3.u32==0u && c.r4.u32==1u && c.r5.u32==0u && c.r6.u32==0u);
  CHECK(c.r7.u32==0x3edd0u);
  CHECK(c.r8.u32==renderer+4u);
  CHECK(m.load_be(0x3edd0u+0,4,v)==cc::xbox::MemoryError::ok && v==640u);
  CHECK(m.load_be(0x3edd0u+4,4,v)==cc::xbox::MemoryError::ok && v==480u);
  CHECK(m.load_be(renderer+28712,1,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(renderer+28713,1,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(renderer+28714,1,v)==cc::xbox::MemoryError::ok && v==0u);
  cc_log("platform_init_prefix presentation=640x480 next_original_call=820BEFD0 graphics_device_helper\n");

  // Enter the first graphics-device helper with the exact registers and stack
  // produced above. Original game-side code allocates/zeros the lower renderer,
  // initializes engines/rings/resources, executes the large sub_820CB988 state
  // fanout and command-buffer flush path, closes the EDRAM/HSIO finalization,
  // and returns through sub_820CC100/sub_820BEFD0. The lower graphics object is
  // published to renderer+4 only by that original successful return path.
  auto gr=invoke(0x820befd0,c,m,sink(),1000000);
  cc_log("graphics_init_prefix result=%s@%08x funcs=%u memops=%u r1=%08x r3=%08x r4=%u\n",
              name(gr.error),gr.address,gr.functions,gr.memory_ops,c.r1.u32,c.r3.u32,c.r4.u32);
  CHECK(gr.error==Error::ok);
  CHECK(c.r1.u32==0x3ed30u);         // returned to the still-live PlatformRenderer::Init frame
  CHECK(c.r3.u32==0u);               // sub_820BEFD0 success HRESULT
  const uint32_t device=0x02000080u;

  // WIP 021 now resumes the still-live original PlatformRenderer::Init frame at
  // the verified successful post-graphics branch (0x820A7B34), rather than
  // manually stepping the first setter/restoration calls. The provenance-bound
  // continuation executes the original first sub_820C2C98, exact sub_820C13B8
  // (including exact sub_821368C0), the second sub_820C2C98, then the resolved
  // renderer-vtable slot +28 target: exact sub_820A85E8. On the observed state
  // its guard byte renderer+28715 is still zero, so the exact body takes its
  // beqlr-cr6 early return without any store or further dispatch, and the
  // diagnostic slice stops at its fail-closed return before the original
  // caller continuation at lr=0x820A7BC8 (first unrecovered call: 0x820AA5B8).
  c.r3.u32=0u; c.lr=0x820A7B18u;
  auto ps=invoke(0x820a7b34,c,m,sink(),400000);
  cc_log("platform_post_graphics result=%s@%08x funcs=%u memops=%u r1=%08x lr=%08x r3=%08x r4=%08x r5=%08x r6=%08x r7=%08x r8=%08x r9=%08x r10=%08x ctr=%08x\n",
              name(ps.error),ps.address,ps.functions,ps.memory_ops,c.r1.u32,uint32_t(c.lr),c.r3.u32,c.r4.u32,c.r5.u32,c.r6.u32,c.r7.u32,c.r8.u32,c.r9.u32,c.r10.u32,c.ctr.u32);
  CHECK(ps.error==Error::ok);
  CHECK(ps.address==0u);
  // The continuation now executes the closed exact sub_820A85E8 vtable call,
  // the presentation-state stores, and the full 17-iteration loc_820A7BF0
  // shader-descriptor loop: exact sub_820AA5B8/sub_820AA488 load each
  // descriptor's shader files from the container through the bounded
  // NtCreateFile/NtQueryInformationFile/NtReadFile/NtClose contracts, the
  // exact CRT heap serves the file buffers, exact XMemCpy (sub_82136390)
  // copies microcode, and exact sub_820C0440/sub_820C0330/sub_820C01C0
  // create the vertex/pixel shader objects and vertex declarations. The two
  // container-absent names (SobelEdge.xpu, VertexColorFillPS.xpu) take the
  // original error path. The slice then runs the post-loop setup and stops
  // before the first still-unrecovered call bl 0x820A8190.
  // The slice now runs the complete remaining sub_820A7990 suffix: exact
  // sub_820A8190, the SetVertexShader/SetPixelShader/SetVertexDeclaration
  // chain (sub_820BFEE8/sub_820BFC30/sub_820C00B8), exact sub_820BB6A8,
  // sub_820BD0F8, sub_820BCF50, the final sub_820C44A0 640x480 resource
  // published at renderer+8, the success result store, and the original
  // epilogue. PlatformRenderer::Init has therefore returned to the still-live
  // original sub_82070AC8 frame.
  CHECK(ps.functions==2277u);
  CHECK(ps.memory_ops==67417u); // +30 over pre-WIP022: doorbell read-index writebacks
  CHECK(c.r1.u32==0x0003eee0u);       // caller sub_82070AC8 frame restored
  CHECK(c.r3.u32==0x0003ef50u);       // original result-struct argument returned
  CHECK(m.load_be(0x0003ef50u,4,v)==cc::xbox::MemoryError::ok && v==0u); // Init result: success
  CHECK(m.load_be(0x0003ef54u,4,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(renderer+8,4,v)==cc::xbox::MemoryError::ok && v!=0u); // tail sub_820C44A0 resource
  // Durable presentation-state stores executed after the vtable call and
  // before the fail-closed loc_820A7BF0 loop stop.
  cc_log("post_vtable_presentation f30=%08x f31=%08x r28=%08x fields=[28740..28752]\n",
              uint32_t(m.load_be(renderer+28756,4,v)==cc::xbox::MemoryError::ok?v:~0ull),
              uint32_t(m.load_be(renderer+28760,4,v)==cc::xbox::MemoryError::ok?v:~0ull),
              uint32_t(m.load_be(renderer+29124,4,v)==cc::xbox::MemoryError::ok?v:~0ull));
  CHECK(m.load_be(renderer+28740,4,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(renderer+28744,4,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(renderer+28748,4,v)==cc::xbox::MemoryError::ok && v==640u);
  CHECK(m.load_be(renderer+28752,4,v)==cc::xbox::MemoryError::ok && v==480u);
  CHECK(m.load_be(renderer+29124,4,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(renderer+28756,4,v)==cc::xbox::MemoryError::ok && v==0x00000000u); // stfs f30 = 0.0f
  CHECK(m.load_be(renderer+28760,4,v)==cc::xbox::MemoryError::ok && v==0x3f800000u); // stfs f31 = 1.0f
  // Exact sub_820A85E8 observed-branch evidence: at the vtable call the guard
  // byte renderer+28715 was still zero, so the color-conversion path was not
  // taken and renderer+28736..28739 remain untouched. The original post-loop
  // code then stores the guard byte (r29=1).
  CHECK(m.load_be(renderer+28715,1,v)==cc::xbox::MemoryError::ok && v==1u);
  CHECK(m.load_be(renderer+28736,4,v)==cc::xbox::MemoryError::ok && v==0u);
  // Durable shader-descriptor table published by the exact loop: the table
  // pointer and running counter, slot 0's created vertex shader, pixel
  // shader, and vertex declaration, and the exact microcode bytes XMemCpy
  // copied from the container's GenericVS.xvu into the first shader object
  // (validating the byte-exact copy path end to end).
  CHECK(m.load_be(renderer+30176,4,v)==cc::xbox::MemoryError::ok && v==renderer+29836u);
  CHECK(m.load_be(renderer+30208,4,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(renderer+29836+0,4,v)==cc::xbox::MemoryError::ok && v==0u); // slot 0 result: success
  CHECK(m.load_be(renderer+29836+8,4,v)==cc::xbox::MemoryError::ok && v!=0u);
  CHECK(m.load_be(renderer+29836+12,4,v)==cc::xbox::MemoryError::ok && v!=0u);
  CHECK(m.load_be(renderer+29836+16,4,v)==cc::xbox::MemoryError::ok && v!=0u);
  CHECK(m.load_be(0x0233DE68u+0,4,v)==cc::xbox::MemoryError::ok && v==0x102a1101u);
  CHECK(m.load_be(0x0233DE68u+4,4,v)==cc::xbox::MemoryError::ok && v==0x0000011cu);
  CHECK(m.load_be(0x0233DE68u+8,4,v)==cc::xbox::MemoryError::ok && v==0x0000009cu);
  CHECK(m.load_be(0x0233DE68u+12,4,v)==cc::xbox::MemoryError::ok && v==0x00000024u);
  CHECK(m.load_be(renderer+4,4,v)==cc::xbox::MemoryError::ok && v==device);
  // Allocation/object publication contract from sub_820BEF28/sub_820CC088.
  CHECK(m.load_be(device-4,4,v)==cc::xbox::MemoryError::ok && v==0x02000000u);
  CHECK(m.load_be(0x02500000u,4,v)==cc::xbox::MemoryError::ok && v==device);
  CHECK(m.load_be(device+60,4,v)==cc::xbox::MemoryError::ok && v==1u);
  // With the per-thread block correctly resolved (owner cookie at
  // [0x02501000+332]), the device retains the checkpoint-020 owner canary.
  CHECK(m.load_be(device+10888,4,v)==cc::xbox::MemoryError::ok && v==0x44556677u);
  CHECK(m.load_be(device+10892,4,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(device+16728,4,v)==cc::xbox::MemoryError::ok && v==0x02005e80u);
  CHECK(m.load_be(device+23980,4,v)==cc::xbox::MemoryError::ok && v==0x0c000000u);
  CHECK(m.load_be(device+16716,4,v)==cc::xbox::MemoryError::ok && v==0u);

  // Exact default ring setup from sub_820C7548: 32 KiB primary, 2 MiB
  // secondary, 64 KiB chunks, and its two small descriptor allocations.
  CHECK(m.load_be(device+14836,4,v)==cc::xbox::MemoryError::ok && v==0x02007140u);
  CHECK(m.load_be(device+14840,4,v)==cc::xbox::MemoryError::ok && v==0x0200f140u);
  CHECK(m.load_be(device+10896,4,v)==cc::xbox::MemoryError::ok && v==0x0220f140u);
  CHECK(m.load_be(device+10900,4,v)==cc::xbox::MemoryError::ok && v==0x0220f1a0u);
  CHECK(m.load_be(device+14896,4,v)==cc::xbox::MemoryError::ok && v==0x02007140u);
  CHECK(m.load_be(device+14904,4,v)==cc::xbox::MemoryError::ok && v==0x0200f140u);
  CHECK(m.load_be(device+14912,4,v)==cc::xbox::MemoryError::ok && v==65536u);
  CHECK(m.load_be(device+14900,4,v)==cc::xbox::MemoryError::ok && v==8191u);
  CHECK(m.load_be(device+14936,4,v)==cc::xbox::MemoryError::ok && v==524288u);
  CHECK(m.load_be(device+10908,4,v)==cc::xbox::MemoryError::ok && v==15u); // post-restore command-state phase
  // WIP 022: the fixture GPU publishes its caught-up read index through the
  // descriptor at every doorbell, so the word now equals the submission phase.
  CHECK(m.load_be(0x0220f140u+0,4,v)==cc::xbox::MemoryError::ok && v==uint64_t(15));
  CHECK(m.load_be(0x0220f140u+4,4,v)==cc::xbox::MemoryError::ok && v==0x0200f13cu);
  CHECK(m.load_be(device+10924,2,v)==cc::xbox::MemoryError::ok && v==1u);
  CHECK(m.load_be(device+10926,2,v)==cc::xbox::MemoryError::ok && v==2048u);

  // sub_820BEAC8 state/command allocations and its source cardinality.
  CHECK(m.load_be(device+23996,4,v)==cc::xbox::MemoryError::ok && v==32u);
  CHECK(m.load_be(device+23984,4,v)==cc::xbox::MemoryError::ok && v==0x0220f1c0u);
  CHECK(m.load_be(device+23992,4,v)==cc::xbox::MemoryError::ok && v==0x0220f460u);
  CHECK(m.load_be(device+23988,4,v)==cc::xbox::MemoryError::ok && v>0u);

  // sub_820D7708 derives exactly two worker classes from 0x0c000000. The
  // bounded scheduler records thread creation/priority but does not run either
  // infinite/async worker routine concurrently.
  CHECK(m.load_be(device+11804,4,v)==cc::xbox::MemoryError::ok && v==0x0220f660u);
  CHECK(m.load_be(device+10984,4,v)==cc::xbox::MemoryError::ok && v==2u);
  CHECK(m.load_be(device+10988,4,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(device+10948,4,v)==cc::xbox::MemoryError::ok && v==0x02007140u);
  CHECK(m.load_be(device+10956,4,v)==cc::xbox::MemoryError::ok && v==8191u);
  CHECK(m.load_be(device+11028,4,v)==cc::xbox::MemoryError::ok && v==0xc0000000u);
  CHECK(m.load_be(device+11320,4,v)==cc::xbox::MemoryError::ok && v==2u);
  CHECK(m.load_be(device+11532,4,v)==cc::xbox::MemoryError::ok && v==0xf1000001u);
  CHECK(m.load_be(device+11612,4,v)==cc::xbox::MemoryError::ok && v==0xf1000002u);

  // sub_820BF930 owns the next 8 KiB command/state workspace; sub_820D7920
  // then installs deterministic baseline GPU state before sub_820CBBF0.
  CHECK(m.load_be(device+13780,4,v)==cc::xbox::MemoryError::ok && v==0x0220f730u);
  CHECK(m.load_be(device+13784,4,v)==cc::xbox::MemoryError::ok && v!=0u);
  CHECK(m.load_be(device+13788,4,v)==cc::xbox::MemoryError::ok && v!=0u);
  CHECK(m.load_be(device+14816,4,v)==cc::xbox::MemoryError::ok && v!=0u);
  CHECK(m.load_be(device+14820,4,v)==cc::xbox::MemoryError::ok && v!=0u);
  CHECK(m.load_be(device+11824,8,v)==cc::xbox::MemoryError::ok && v==0x00000000ffffffffull);
  CHECK(m.load_be(device+10428,4,v)==cc::xbox::MemoryError::ok && v==0x20002000u);
  CHECK(m.load_be(device+10708,4,v)==cc::xbox::MemoryError::ok && v==0x000ff000u);
  CHECK(m.load_be(device+10772,4,v)==cc::xbox::MemoryError::ok && v==16u);
  CHECK(m.load_be(device+10628,4,v)==cc::xbox::MemoryError::ok && v==14u);
  CHECK(m.load_be(device+10768,4,v)==cc::xbox::MemoryError::ok && v==14u);
  CHECK(m.load_be(device+10604,4,v)==cc::xbox::MemoryError::ok && v==8u);
  CHECK(m.load_be(device+10580,4,v)==cc::xbox::MemoryError::ok && v==4u);
  CHECK(m.load_be(device+10824,4,v)==cc::xbox::MemoryError::ok && v==2u);
  CHECK(m.load_be(device+10916,4,v)==cc::xbox::MemoryError::ok && v==0x0000200eu); // final state fanout

  // Exact sub_820CBBF0 resource/publication contract for the observed 640x480
  // presentation. These three pointers come from original resource constructors;
  // none are dummy nonzero handles. The first owns a 640*480*4 backing allocation.
  CHECK(m.load_be(device+14828,4,v)==cc::xbox::MemoryError::ok && v==0x02211730u);
  CHECK(m.load_be(device+14832,4,v)==cc::xbox::MemoryError::ok && v==0x0233d770u);
  CHECK(m.load_be(device+14824,4,v)==cc::xbox::MemoryError::ok && v==0x0233dad0u);
  CHECK(m.load_be(0x02211730u+32,4,v)==cc::xbox::MemoryError::ok && v!=0u);
  CHECK(m.load_be(0x8223191cu,4,v)==cc::xbox::MemoryError::ok && v==0x0233d7a0u);
  CHECK(m.load_be(0x0233d7a0u+28,4,v)==cc::xbox::MemoryError::ok && v==5664u);
  for (uint32_t i=0;i<15;i++)
    CHECK(m.load_be(0x0233d7a0u+32+i*4,4,v)==cc::xbox::MemoryError::ok && v==0xffffffffu);
  CHECK(m.load_be(0x0233d7a0u+32+15*4,4,v)==cc::xbox::MemoryError::ok && v==0u);

  // Presentation state copied by original sub_820CBBF0 after surface creation.
  CHECK(m.load_be(device+13544,4,v)==cc::xbox::MemoryError::ok && v==640u);
  CHECK(m.load_be(device+13548,4,v)==cc::xbox::MemoryError::ok && v==480u);
  CHECK(m.load_be(device+13552,4,v)==cc::xbox::MemoryError::ok && v==0x18280186u);
  CHECK(m.load_be(device+13584,4,v)==cc::xbox::MemoryError::ok && v==0x2d200196u);
  CHECK(m.load_be(device+21544,4,v)==cc::xbox::MemoryError::ok && v==1280u);
  CHECK(m.load_be(device+21548,4,v)==cc::xbox::MemoryError::ok && v==720u);

  // WIP 021 first PlatformRenderer suffix setter now consumes additional
  // cached GPU state after the Checkpoint 020 invalidation baseline. Bind the
  // exact deterministic post-setter values rather than retaining the older
  // pre-suffix invalidation values.
  // Word 2 gains the shader/declaration dirty bits set by the exact
  // descriptor-loop creations (0x...101e0fe8 -> 0x...181e0fef).
  const uint64_t post_suffix_state64[5] = {
    0xffffffffffffffffull, 0xffffffffffffffffull,
    0xff8013a0181e0fefull, 0xff80000bffffffffull,
    0xffffffd000080000ull
  };
  for (uint32_t i=0;i<5u;++i)
    CHECK(m.load_be(device+i*8u,8,v)==cc::xbox::MemoryError::ok && v==post_suffix_state64[i]);
  for (uint32_t i=0;i<41u;++i)
    CHECK(m.load_be(device+23380u+i*4u,4,v)==cc::xbox::MemoryError::ok && v==0xffffffffu);
  CHECK(m.load_be(0x822303a0u,4,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(device+21588u,4,v)==cc::xbox::MemoryError::ok && v!=0u);
  CHECK(m.load_be(device+21592u,4,v)==cc::xbox::MemoryError::ok && v!=0u);

  // Exact sub_821368C0 is now closed for the observed loader state. The loader
  // resolves KeDebugMonitorData through 0x8200068C to 0x02500004, whose service
  // object is null in this fixture, so the exact body returns r3=0 and performs
  // no indirect dispatch. Exact sub_820CF858 then completes and sub_820C13B8
  // unwinds normally before the caller reaches the later renderer-vtable call.
  CHECK(m.load_be(0x8200068cu,4,v)==cc::xbox::MemoryError::ok && v==0x02500004u);
  CHECK(m.load_be(0x02500004u,4,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(device+10943u,1,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(device+21536u,4,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(device+21540u,4,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(renderer+28720u,4,v)==cc::xbox::MemoryError::ok && v==640u);
  CHECK(m.load_be(renderer+28724u,4,v)==cc::xbox::MemoryError::ok && v==480u);
  CHECK(m.load_be(renderer+0u,4,v)==cc::xbox::MemoryError::ok && v==0x82042048u);
  CHECK(m.load_be(0x82042048u+28u,4,v)==cc::xbox::MemoryError::ok && v==0x820A85E8u);
  uint64_t cf9_f16720=0,cf9_f16724=0,cf9_f21576=0,cf9_f21580=0,cf9_f21584=0;
  uint64_t cf9_f21600=0,cf9_f21608=0,cf9_f21616=0,cf9_f21620=0,cf9_f21648=0;
  CHECK(m.load_be(device+16720u,4,cf9_f16720)==cc::xbox::MemoryError::ok);
  CHECK(m.load_be(device+16724u,4,cf9_f16724)==cc::xbox::MemoryError::ok);
  CHECK(m.load_be(device+21576u,4,cf9_f21576)==cc::xbox::MemoryError::ok);
  CHECK(m.load_be(device+21580u,4,cf9_f21580)==cc::xbox::MemoryError::ok);
  CHECK(m.load_be(device+21584u,4,cf9_f21584)==cc::xbox::MemoryError::ok);
  CHECK(m.load_be(device+21600u,8,cf9_f21600)==cc::xbox::MemoryError::ok);
  CHECK(m.load_be(device+21608u,8,cf9_f21608)==cc::xbox::MemoryError::ok);
  CHECK(m.load_be(device+21616u,4,cf9_f21616)==cc::xbox::MemoryError::ok);
  CHECK(m.load_be(device+21620u,4,cf9_f21620)==cc::xbox::MemoryError::ok);
  CHECK(m.load_be(device+21648u,4,cf9_f21648)==cc::xbox::MemoryError::ok);
  cc_log("cf9d0_state f16720=%08x f16724=%08x tdiff=%08x tlo=%08x thi=%08x q0=%016llx q1=%016llx copy0=%08x copy1=%08x state=%u r7=%08x\n",
              uint32_t(cf9_f16720),uint32_t(cf9_f16724),uint32_t(cf9_f21576),uint32_t(cf9_f21584),uint32_t(cf9_f21580),
              (unsigned long long)cf9_f21600,(unsigned long long)cf9_f21608,uint32_t(cf9_f21616),uint32_t(cf9_f21620),uint32_t(cf9_f21648),c.r7.u32);

  // On this observed branch the presentation flags are clear, so exact
  // sub_820CF9D0 skips both indirect setup branches. The prior timing/sample
  // slots were zero, making the elapsed-delta zero; it snapshots the current
  // timebase split into the two 32-bit timing words, clears both queued 64-bit
  // values, leaves state 0, and reaches sub_820CF858 directly.
  CHECK(cf9_f16720==0u);
  CHECK(cf9_f16724==0u);
  CHECK(cf9_f21576==0u);
  CHECK(cf9_f21584==0u);       // high 32 bits of this short-run timebase sample
  CHECK(cf9_f21580!=0u);       // low 32 bits; wall-clock dependent
  CHECK(cf9_f21600==0u);
  CHECK(cf9_f21608==0u);
  CHECK(cf9_f21616==0u);
  CHECK(cf9_f21620==0u);
  CHECK(cf9_f21648==0u);

  // The accepted second VdRetrainEDRAM call returns zero without touching its
  // two output words, then exact sub_820D19E8 unwinds normally.
  CHECK(m.load_be(0x0003e260u,4,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(0x0003e264u,4,v)==cc::xbox::MemoryError::ok && v==0u);
  // VdPersistDisplay writes only the token through its second argument. The
  // slot deliberately retains the now-freed opaque value; the token itself
  // remains guest-inaccessible. Reaching VdRetrainEDRAM proves the bounded
  // MmFreePhysicalMemory call returned through exact original code.
  CHECK(m.load_be(0x0003eb40u,4,v)==cc::xbox::MemoryError::ok && v==0x02600000u);
  CHECK(m.check(0x02600000u,64u,1u)!=cc::xbox::MemoryError::ok);

  // Exact sub_820CF728 publishes its observed presentation arguments into the
  // durable device block before the platform refresh and then returns.
  const uint32_t cf728_device_words[6]={
    0x28280106u,640u,480u,0x02211000u,0x0200361cu,0x02003b1cu
  };
  for(uint32_t i=0;i<6u;++i)
    CHECK(m.load_be(device+21680u+i*4u,4,v)==cc::xbox::MemoryError::ok &&
          v==cf728_device_words[i]);
  // Bounded second VdQueryVideoMode output at device+21704.
  CHECK(m.load_be(device+21704u,4,v)==cc::xbox::MemoryError::ok && v==640u);
  CHECK(m.load_be(device+21708u,4,v)==cc::xbox::MemoryError::ok && v==480u);
  CHECK(m.load_be(device+21724u,4,v)==cc::xbox::MemoryError::ok && v==0x42700000u);
  CHECK(m.load_be(device+21732u,4,v)==cc::xbox::MemoryError::ok && v==0x4au);
  // Caller emits four exact command dwords before VdPersistDisplay.
  const uint32_t persist_packet[4]={0xc0022100u,0x00001e4eu,0xfffffffeu,0x00000000u};
  for(uint32_t i=0;i<4u;++i)
    CHECK(m.load_be(0x020122e0u+i*4u,4,v)==cc::xbox::MemoryError::ok &&
          v==persist_packet[i]);
  // The accepted second retrain lets exact sub_820C6F68 publish the next
  // command region at 0x0201F37C. The second exact sub_820C2C98 reached by the
  // original PlatformRenderer caller subsequently advances the live ring write
  // pointer to 0x0201F73C before the new renderer-vtable boundary.
  CHECK(m.load_be(device+48u,4,v)==cc::xbox::MemoryError::ok && v==0x0201f73cu);
  CHECK(m.load_be(device+52u,4,v)==cc::xbox::MemoryError::ok && v==0x0202f37cu);
  CHECK(m.load_be(device+56u,4,v)==cc::xbox::MemoryError::ok && v==0x0202f2dcu);
  CHECK(m.load_be(device+14928u,4,v)==cc::xbox::MemoryError::ok && v==0x0201f380u);
  // The old VdPersistDisplay input words were transient stack state. The later
  // second setter legitimately reuses that stack region, so do not treat those
  // retired 0x0003EB58 bytes as durable at this deeper boundary.
  // Exact sub_820C0580 uses a 1,648-byte local frame at 0x0003E340..0x0003E9AF.
  // That legitimately reuses the retired D1788/D1260 scaler stack bytes, so
  // those transient stack buffers are no longer durable at this deeper boundary.
  // Preserve only device/ring state that original code copied out of them.

  // One-shot VdGetCurrentDisplayInformation contract: exact caller consumed only
  // display_width, display_height, and actual_display_width from the zeroed
  // 0x58-byte stack block. The stack area is subsequently reused by exact
  // callees, so bind the durable device copies. Trusted kernel-model current
  // mode is 1280x720.
  uint64_t di=0;
  CHECK(m.load_be(device+21544u,4,di)==cc::xbox::MemoryError::ok && di==1280u);
  CHECK(m.load_be(device+21548u,4,di)==cc::xbox::MemoryError::ok && di==720u);
  CHECK(m.load_be(device+21552u,4,di)==cc::xbox::MemoryError::ok && di==1280u);

  // The VdGetSystemCommandBuffer outputs were stack-resident temporaries.
  // The later second setter reuses that stack region; durable command/ring
  // effects below remain the acceptance surface at this deeper boundary.

  // First exact sub_820CDF20 packet emitted before command-buffer acquisition.
  const uint32_t first_cdf20_addr=0x0200f940u;
  const uint32_t first_cdf20_words[4]={0xc0025800u,0x80000003u,0x0220f180u,0xdeadbeefu};
  uint64_t q=0;
  for(uint32_t i=0;i<4u;++i)
    CHECK(m.load_be(first_cdf20_addr+i*4u,4,q)==cc::xbox::MemoryError::ok && q==first_cdf20_words[i]);

  // Bounded observed VdSwap contract: trusted kernel-model packet shape with
  // identity virtual->physical mapping accepted only for this deterministic
  // low-memory fixture. Exact sub_820C7458 reserved 64 words at +4 from the
  // prior write pointer, so the block spans 0x0200F950..0x0200FA4C.
  const uint32_t swap_addr=0x0200f950u;
  const uint32_t swap_head[12]={
    0x00054800u, 0x85000002u, 0x02211006u, 0x003be27fu,
    0x00001414u, 0x00000000u, 0x00000200u, 0xc0036400u,
    0x53574150u, 0x02211000u, 0x00000280u, 0x000001e0u
  };
  for(uint32_t i=0;i<12u;++i)
    CHECK(m.load_be(swap_addr+i*4u,4,q)==cc::xbox::MemoryError::ok && q==swap_head[i]);
  for(uint32_t i=12u;i<64u;++i)
    CHECK(m.load_be(swap_addr+i*4u,4,q)==cc::xbox::MemoryError::ok && q==0x80000000u);

  // Original code advances to the end of the 64-word swap block, then emits a
  // second exact sub_820CDF20 packet for slot 0x0220F184.
  const uint32_t second_cdf20_addr=0x0200fa50u;
  const uint32_t second_cdf20_words[4]={0xc0025800u,0x80000003u,0x0220f184u,0xdeadbeefu};
  for(uint32_t i=0;i<4u;++i)
    CHECK(m.load_be(second_cdf20_addr+i*4u,4,q)==cc::xbox::MemoryError::ok && q==second_cdf20_words[i]);
  // Exact sub_820C0BC0 takes the r4=-1 flag path after the swap/display-info
  // suffix. In this fixture device+23980 has bit 0x4 clear, so it skips the
  // optional sub_820C08B8 call, appends this 16-dword sequence, and reaches
  // exact sub_820D1788. D1788 now completes through the bounded scaler-command
  // initializer and exact copy/flush path before C0BC0 reaches and completes sub_820C0A98.
  uint64_t flags23980=0;
  CHECK(m.load_be(device+23980u,4,flags23980)==cc::xbox::MemoryError::ok && (flags23980&4u)==0u);
  const uint32_t c0bc0_addr=0x0200faa0u;
  const uint32_t c0bc0_words[16]={
    6515u,0x00010000u,6500u,1u,6515u,0u,0xc0043c00u,3u,
    6515u,0u,1u,256u,6226u,0u,6200u,1u
  };
  for(uint32_t i=0;i<16u;++i)
    CHECK(m.load_be(c0bc0_addr+i*4u,4,q)==cc::xbox::MemoryError::ok && q==c0bc0_words[i]);

  uint64_t wptr=0,di44=0,di48=0,di52=0;
  CHECK(m.load_be(device+48,4,wptr)==cc::xbox::MemoryError::ok);
  CHECK(m.load_be(device+21544u,4,di44)==cc::xbox::MemoryError::ok);
  CHECK(m.load_be(device+21548u,4,di48)==cc::xbox::MemoryError::ok);
  CHECK(m.load_be(device+21552u,4,di52)==cc::xbox::MemoryError::ok);
  // Closing the second retrain lets exact sub_820C6F68 publish the next 64 KiB
  // command region before sub_820CF9D0. Exact sub_820CF9D0 then advances to sub_820CF858. Bind the exact durable device fields.
  uint64_t s14912=0,s14916=0,s14928=0,s14932=0,s14940=0,d52=0,d56=0;
  CHECK(m.load_be(device+14912u,4,s14912)==cc::xbox::MemoryError::ok && s14912==65536u);
  CHECK(m.load_be(device+14916u,4,s14916)==cc::xbox::MemoryError::ok && s14916==0x0202f40cu);
  CHECK(m.load_be(device+14928u,4,s14928)==cc::xbox::MemoryError::ok && s14928==0x0201f380u);
  CHECK(m.load_be(device+14932u,4,s14932)==cc::xbox::MemoryError::ok && s14932==0x54u);
  CHECK(m.load_be(device+14940u,4,s14940)==cc::xbox::MemoryError::ok && s14940==13u);
  CHECK(m.load_be(device+52u,4,d52)==cc::xbox::MemoryError::ok && d52==0x0202f37cu);
  CHECK(m.load_be(device+56u,4,d56)==cc::xbox::MemoryError::ok && d56==0x0202f2dcu);
  cc_log("post_restore_ring s14912=%08x s14916=%08x s14928=%08x s14932=%08x s14940=%08x d52=%08x d56=%08x next=820A7BC8_before_820AA5B8\n",
              uint32_t(s14912),uint32_t(s14916),uint32_t(s14928),uint32_t(s14932),uint32_t(s14940),uint32_t(d52),uint32_t(d56));
  cc_log("post_c0bc0 device21544=%u device21548=%u device21552=%u wptr=%08x packet=%08x..%08x\n",
              uint32_t(di44),uint32_t(di48),uint32_t(di52),uint32_t(wptr),c0bc0_addr,c0bc0_addr+60u);
  CHECK(wptr==0x0201f73cu);
  // Exact post-free sub_820C7228 appends twelve dwords before the second
  // sub_820D19E8 call. Bind that new durable ring tail at the first newly
  // reached platform boundary.
  const uint32_t post_free_tail[12]={
    0xc0003b00u,0x00007fffu,0xc0025800u,0x00000003u,
    0x0220f146u,0x020122ecu,0xc0025800u,0x00000003u,
    0x0220f142u,0x0000000du,0x00000000u,0x00000000u
  };
  for(uint32_t i=0;i<12u;++i)
    CHECK(m.load_be(0x020122f0u+i*4u,4,q)==cc::xbox::MemoryError::ok &&
          q==post_free_tail[i]);
  // Exact sub_820C8E98 reserves/emits 2309 dwords beginning at 0x0200FE88.
  // Hash the complete packet and the exact 17-dword sub_820C7228 tail that
  // follows it so this deeper boundary binds durable ring output, not stack.
  const uint32_t c8e98_start=0x0200fe88u;
  uint64_t c8e98_hash=1469598103934665603ull;
  for(uint32_t i=0;i<2309u;++i) {
    CHECK(m.load_be(c8e98_start+i*4u,4,q)==cc::xbox::MemoryError::ok);
    c8e98_hash^=uint32_t(q); c8e98_hash*=1099511628211ull;
  }
  const uint32_t c8e98_tail_start=c8e98_start+2309u*4u;
  uint64_t c8e98_tail_hash=1469598103934665603ull;
  for(uint32_t i=0;i<17u;++i) {
    CHECK(m.load_be(c8e98_tail_start+i*4u,4,q)==cc::xbox::MemoryError::ok);
    c8e98_tail_hash^=uint32_t(q); c8e98_tail_hash*=1099511628211ull;
  }
  CHECK(c8e98_hash==0x1de1b325315c84acull);
  CHECK(c8e98_tail_hash==0x1ca6adb697e47ca5ull);
  cc_log("c8e98_packet start=%08x words=2309 hash=%016llx tail=%08x words=17 tail_hash=%016llx\n",
              c8e98_start,(unsigned long long)c8e98_hash,c8e98_tail_start,(unsigned long long)c8e98_tail_hash);
  // Exact sub_820C0A98 writes six dwords beginning immediately after the prior
  // write pointer. The observed format 0x28280106 does not equal 0x28280136,
  // so its final comparison-dependent word is zero. Exact sub_820C0BC0 then
  // appends twelve more dwords before calling exact sub_820C0580. Bind all 18 words.
  const uint32_t c0a98_suffix_addr=0x0200fe40u;
  const uint32_t c0a98_suffix_words[18]={
    0xc0022100u,0x00001841u,0xfffff8ffu,0x00000000u,0x00001930u,0x00000000u,
    0x00001844u,0x02211000u,0x00001838u,0x00000000u,0xc0043c00u,0x00000003u,
    0x00001973u,0x00000000u,0x00000001u,0x00000100u,0x00001852u,0x00000001u
  };
  for(uint32_t i=0;i<18u;++i)
    CHECK(m.load_be(c0a98_suffix_addr+i*4u,4,q)==cc::xbox::MemoryError::ok &&
          q==c0a98_suffix_words[i]);
  // VdInitializeScalerCommandBuffer returns 200, so exact D1788 copies 800
  // bytes from stack+192 to the command ring at r30+4 and advances device+48
  // to the last copied dword. Bind all 200 destination words.
  const uint32_t scaler_copy_start=0x0200fb20u;
  // The initializer produces 200 NOP dwords and exact D1788 copies all 200.
  // The immediately following exact sub_820C7228 command/flush work rewrites
  // only the last 16 dwords. Bind the final durable ring image precisely.
  for (uint32_t i=0;i<184u;++i)
    CHECK(m.load_be(scaler_copy_start+i*4u,4,q)==cc::xbox::MemoryError::ok &&
          q==0x80000000u);
  const uint32_t scaler_tail[16]={
    0xc0003b00u,0x00007fffu,0xc0025800u,0x00000003u,
    0x0220f146u,0x0200fdfcu,0xc0025800u,0x00000003u,
    0x0220f142u,0x00000009u,0x00000000u,0x00000000u,
    0x00000000u,0x00000000u,0x00000000u,0x00000000u
  };
  for (uint32_t i=0;i<16u;++i)
    CHECK(m.load_be(scaler_copy_start+(184u+i)*4u,4,q)==cc::xbox::MemoryError::ok &&
          q==scaler_tail[i]);
  cc_log("post_scaler_init final_wptr=%08x copy_start=%08x nops=184 tail_words=16 persist_free=closed second_retrain=closed next=820A7BC8_before_820AA5B8\n",
              uint32_t(wptr),scaler_copy_start);
  cc_log("vdswap_packet addr=%08x frontbuffer=%08x size=%ux%u persist_free=closed second_retrain=closed next=820A7BC8_before_820AA5B8\n",
              swap_addr,swap_head[9],swap_head[10],swap_head[11]);

  cc_log("graphics_state device=%08x ring=%08x secondary=%08x descriptor=%08x workers=2 resources=%08x,%08x,%08x output_published=%08x hsio=ok\n",
              device,0x02007140u,0x0200f140u,0x0220f140u,0x02211730u,0x0233d770u,0x0233dad0u,device);

  // WIP 023: with PlatformRenderer::Init returned, resume the original
  // sub_82070AC8 caller at 0x82070BA4 with the live restored registers and
  // run the loc_82070DB0 main game loop. Each frame executes the original
  // update (sub_82075C88), render (sub_820759A8), VdSwap present and EDRAM
  // retrain against the fixtures (idle pad on port 0, no user music). The
  // bounded KeDelayExecutionThread contract stops the diagnostic at the
  // third frame's pacing sleep with Error::capacity -" a deliberate frame
  // budget, never a faked exit path.
  cc::tree::set_exact_texture_bind(true);
  // Unlimited op budget (0xFFFFFFFF): the 10,000-frame limit ends the run;
  // op/function counters wrap deterministically at 32 bits.
  auto pi=invoke(0x82070ba4,c,m,sink(),0xFFFFFFFFu);
  cc_log("caller_post_init result=%s@%08x funcs=%u memops=%u r1=%08x lr=%08x r3=%08x r4=%08x r5=%08x r6=%08x r7=%08x r11=%08x\n",
              name(pi.error),pi.address,pi.functions,pi.memory_ops,c.r1.u32,uint32_t(c.lr),
              c.r3.u32,c.r4.u32,c.r5.u32,c.r6.u32,c.r7.u32,c.r11.u32);
  CHECK(pi.error==Error::capacity);
  // WIP 023d: the run no longer stops at a platform boundary - the game
  // reaches the main menu (LOGO/LOADING/PAUSE/LEGAL/ATTRACT/MENU paks and
  // the intro music all load, the injected START press drives the sign-in
  // flow) and renders menu frames until the deliberate 900M memory-op
  // diagnostic budget expires mid-draw. All values below are the exact
  // deterministic measurements of that bounded run.
  CHECK(pi.address==0x8214A614u);   // the 10,000-frame diagnostic budget
  CHECK(uint32_t(c.lr)==0x820B7504u); // exact Sleep wrapper frame boundary
  // Exact sub_8209BC98 obtains the observed 16 MiB main pool through exact
  // sub_820B6108 / bounded MmAllocatePhysicalMemoryEx (fixture arena at
  // 0x10000000) and publishes it through the startup hash object. Exact
  // sub_820A9B58 then loads the game's font: the bounded file contracts read
  // the container's fonts\synjUnicode_20.xpr (2,252,812 bytes) into a
  // write-combined physical block at 0x12000000, and the exact XPR texture
  // chain (sub_820C3568/sub_820C3930/sub_820C4488/sub_820C4498) creates the
  // font texture. The slice ends by dispatching renderer vtable slot +12 to
  // exact sub_820A7E80 (with exact sub_820BFB50), which returns normally.
  // Default port policy: DXT5 textures streamed through a 5 MB cache with
  // a scratch swap,
  // rasterized on first bind (CC_TEX_EAGER=1 gives the load-time order),
  // and SOUNDS.PAK without its unused MP3 payloads from the port data
  // overlay (tools/strip_sound_bank.py -> game-data/converted/data/), and
  // the port audio layer playing Xbox ADPCM (tools/convert_audio.py ->
  // game-data/converted/audio/).
  CHECK(pi.functions==320961210u && pi.memory_ops==4101260149u);
  CHECK(c.r1.u32==0x0003ee70u); // pacing-sleep frame at the budget stop
  // The boot-era pool record at 0x75240 (size 16 MiB, base 0x10000000) has
  // been released and cleared by the time the session reaches gameplay.
  CHECK(m.load_be(0x00075240u,4,v)==cc::xbox::MemoryError::ok && v==0u);
  CHECK(m.load_be(0x00075244u,4,v)==cc::xbox::MemoryError::ok && v==0u);
  // The XPR container header read into the physical block, byte-exact from
  // the extracted retail container ("XPR2", data size, header size).
  // Font texture content evidence: the write-combined block at 0x12000000
  // holds the XPR data section (its first nonzero glyph bytes correspond
  // byte-for-byte to fonts\synjUnicode_20.xpr at file offset 0x28834). The
  // main pool has also received its first original writes.
  {
    size_t first_phys=phys_arena.size(), first_pool=main_pool_arena.size();
    for (size_t i=0;i<phys_arena.size();++i) if (phys_arena[i]) { first_phys=i; break; }
    for (size_t i=0;i<main_pool_arena.size();++i) if (main_pool_arena[i]) { first_pool=i; break; }
    cc_log("arena_scan first_phys=%08x first_pool=%08x\n",
           unsigned(first_phys),unsigned(first_pool));
    CHECK(first_phys==0x2828u);
    CHECK(first_pool==4u);
    static constexpr uint8_t glyph_probe[16] = {
      0xab,0xbb,0xee,0xee,0xde,0xee,0xbc,0xcc,0x67,0x77,0x00,0x00,0x00,0x00,0x00,0x00
    };
    for (unsigned i=0;i<16u;++i)
      CHECK(phys_arena[0x2828u+i]==glyph_probe[i]);
  }
}

static void captured_startup_boundary(const char* path) {
  std::FILE* stream=std::fopen(path,"rb");
  CHECK(stream!=nullptr);
  std::fseek(stream,0,SEEK_END);
  const long stream_size=std::ftell(stream);
  std::fseek(stream,0,SEEK_SET);
  CHECK(stream_size>0);
  std::vector<uint8_t> bytes(static_cast<size_t>(stream_size));
  CHECK(std::fread(bytes.data(),1,bytes.size(),stream)==bytes.size());
  std::fclose(stream);
  Fixtures f; CHECK(parse(bytes.data(),bytes.size(),f)==FixtureError::ok); CHECK(f.count>0);
  auto *w=new Workspace; Case c; CHECK(restore(f,0,*w,c)==FixtureError::ok);
  CHECK(c.entry==0x8209CD08);
  uint64_t head=0,vt=0,update=0;
  CHECK(w->memory.load_be(c.initial.r3.u32+24,1,update)==cc::xbox::MemoryError::ok && update==1);
  CHECK(w->memory.load_be(c.initial.r3.u32+12,4,head)==cc::xbox::MemoryError::ok && head);
  CHECK(w->memory.load_be(uint32_t(head),4,vt)==cc::xbox::MemoryError::ok && vt);
  CHECK(w->memory.load_be(uint32_t(vt)+8,4,update)==cc::xbox::MemoryError::ok);
  CHECK(update==0x8209DE50);
  uint64_t owner_stack=0,owner_depth=0;
  const bool have_owner_stack = w->memory.load_be(0x8225e62c,4,owner_stack)==cc::xbox::MemoryError::ok;
  const bool have_owner_depth = have_owner_stack && w->memory.load_be(uint32_t(owner_stack)+72,4,owner_depth)==cc::xbox::MemoryError::ok;
  cc_log("captured_owner_stack mapped=%u ptr=%08x depth=%u\n",unsigned(have_owner_stack&&have_owner_depth),uint32_t(owner_stack),uint32_t(owner_depth));
  // Run the new original walker against the real captured root. The next original
  // virtual target is intentionally not implemented yet, so this must hard-fail
  // at exactly 0x8209DE50 rather than fake a successful update.
  auto ctx=c.initial; ctx.f1.f64=1.0/60.0;
  auto r=invoke(0x8209CC98,ctx,w->memory,sink());
  CHECK(r.error==Error::memory && r.address==0x8225e62c && r.dispatches==1);
  cc_log("captured_startup root=%08x head=%08x vtable=%08x update=%08x boundary=%s@%08x\n",
              c.initial.r3.u32,uint32_t(head),uint32_t(vt),uint32_t(update),name(r.error),r.address);
  delete w;
}
#ifdef CC_XBOX_DRIVER
// Original-Xbox driver: the same boundary chain runs natively from the
// nxdk-checkpoint022 XBE with its inputs on the disc. Results render on
// screen through the nxdk debug console.
static int cc_boundary_main(int argc,char** argv);
int main() {
  XVideoSetMode(640,480,32,REFRESH_DEFAULT);
  cc_log("Castle Crashers X - Checkpoint 022 native boundary run\n");
  static const char* xargv[4] = {
    "default.xbe",
    "D:\\data\\startup.cct",
    "D:\\data\\default.image.bin",
    "D:\\data\\game-data",
  };
  const int rc = cc_boundary_main(4, const_cast<char**>(xargv));
  cc_log("native boundary run complete rc=%d\n", rc);
  for(;;) { Sleep(1000); }
}
static int cc_boundary_main(int argc,char** argv) {
#else
int main(int argc,char** argv) {
#endif
  CHECK(argc==3 || argc==4);
  if (argc==4) {
    cc::tree::set_game_root(argv[3]);
  } else {
    // Default: game-data/extracted next to castle-crashers-port (argv[2] is
    // <root>/castle-crashers-port/reference/default.image.bin). Plain char
    // handling keeps the identical source linkable on the nxdk target.
    char img[512]{};
    std::snprintf(img,sizeof(img),"%s",argv[2]);
    for (int up=0; up<3; ++up) {
      char* cut=nullptr;
      for (char* p=img; *p; ++p) if (*p=='/'||*p=='\\') cut=p;
      CHECK(cut!=nullptr);
      *cut=0;
    }
    char root[560]{};
    std::snprintf(root,sizeof(root),"%s/game-data/extracted",img);
    cc::tree::set_game_root(root);
  }
  CHECK(cc::update014::synthetic_chain_test()==cc::update014::synthetic_chain_mask);
  synthetic_controls();
  map_hit_and_wrapper_controls();
  manager_initializer_controls();
  startup_full_controls(argv[2]);
  renderer_caller_prefix_controls(argv[2]);
  captured_startup_boundary(argv[1]);
  cc_log("PASS update_boundary assertions=%llu full_synthetic_update=ok startup_full=820701D0..return renderer_prefix=82070AC8..before_820A7990 manager_writer=820701D0@82070434 workers=5 lookup_entries=613 originals=8209CC98,8209DE50,82097720,820915F0,820772B0 platform_init_prefix=820A7990..before_820BEFD0 graphics_init_chain=820BEFD0..return gfx_workers=2 resources=3 output_published=1 next_host_graphics_boundary=platform_renderer_init_returned_820A7990_complete next_real_capture_boundary=8225E62C\n",
              (unsigned long long)assertions);
  return 0;
}
