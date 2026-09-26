// SPDX-License-Identifier: MIT (adapter; includes are unchanged user-game code)
#include "../runtime008/bridge.h"
#include <climits>
#include <array>
#include <chrono>
#include <cmath>
#include <csetjmp>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
namespace cc::tree {
// WIP 021 bounded shader-file platform contract: host directory holding the
// files extracted from the retail container (set by the test harness; the
// contract fails closed when unset).
static std::string g_game_root;
void set_game_root(const char* p) noexcept { g_game_root = p ? p : ""; }
// WIP 021 persistent kernel-fixture state. Unlike per-invoke Machine state,
// these model kernel-side facts that survive between diagnostic invocations
// exactly as they would across calls on hardware: TLS slot values, critical
// sections created by exact code, and the virtual-memory cursor backing the
// exact CRT heap's reservations.
static uint32_t g_tls_slots[64]{};
static std::vector<uint32_t> g_registered_cs;
static std::vector<bool> g_registered_cs_locked;
[[maybe_unused]] static uint32_t g_valloc_cursor = 0x04000000u;
// The physical graphics allocator is one durable kernel-side allocator: its
// sequence position and cursor survive between diagnostic invocations exactly
// as physical allocations do on hardware.
static uint32_t g_graphics_alloc_index = 0;
static uint32_t g_graphics_alloc_cursor = 0x02000000u;
#include "../runtime007/float_scope.inc"
struct Machine {
  struct ThreadSlot {
    bool allocated{};
    bool suspended{};
    bool runnable{};
    uint32_t handle{};
    uint32_t object{};
    uint32_t startup_thunk{};
    uint32_t start_routine{};
    uint32_t parameter{};
    int32_t priority{};
    uint32_t affinity{0x3fu};
  };
  AddressSpace &memory;
  Sink sink;
  Result result{};
  std::array<ThreadSlot,8> threads{};
  uint32_t thread_count{};
  // Checkpoint 020's graphics allocator is a deliberately tiny platform/runtime
  // contract. It accepts only the fifteen allocation shapes reached by the sealed
  // 640x480 device-init path; all other sizes/flags fail closed.


  bool graphics_engines_initialized{};
  uint32_t terminate_notifications{};
  bool graphics_interrupt_installed{};
  bool system_identifier_cleared{};
  bool ring_initialized{};
  bool ring_writeback_enabled{};
  bool system_identifier_set{};
  bool video_mode_queried{};
  bool video_flags_queried{};
  uint32_t graphics_last_alloc_size{};
  uint32_t graphics_last_alloc_flags{};
  uint32_t tile_allocator{};
  bool tile_cs_locked{};
  bool hsio_cs_locked{};
  uint32_t critical_region_depth{};
  uint32_t edram_worker_calls{};
  uint32_t edram_retrain_calls{};
  bool edram_suffix021_shape{};
  uint32_t hsio_status_calls{};
  uint32_t tile_next{};
  bool graphics_notification_sent{};
  bool display_gamma_queried{};
  bool system_command_buffer_queried{};
  bool vd_swap_called{};
  bool display_mode_set{};
  bool display_info_queried{};
  bool scaler_command_buffer_initialized{};
  bool persist_display_called{};
  bool persist_display_freed{};
  uint32_t persist_display_allocation{};
  // WIP 021 shader-file fixture: exactly one file open at a time, read-only,
  // backed by the extracted container bytes. All other shapes fail closed.
  bool file_open{};
  uint32_t file_handle{};
  uint32_t file_pos{};
  std::vector<uint8_t> file_bytes;
  uint32_t ring_virtual{};
  uint32_t ring_physical{};
  uint32_t ring_descriptor{};
  uint32_t graphics_allocate(uint32_t size, uint32_t flags) {
    static constexpr uint32_t sizes[] = {24192u, 4800u, 32768u, 2097152u, 96u, 32u,
                                         672u, 512u, 200u, 8192u, 52u, 0x12C000u, 48u, 804u, 48u};
    static constexpr uint32_t flagv[] = {0x24800000u, 0xB5800000u, 0xB5800000u,
                                         0x87800000u, 0xA5800000u, 0x95800000u,
                                         0xB5800000u, 0x64800000u, 0xB5800000u, 0xB5800000u, 0x64800000u, 0xBC800000u, 0x64800000u, 0x64800000u, 0x64800000u};
    graphics_last_alloc_size=size; graphics_last_alloc_flags=flags;
    if (g_graphics_alloc_index >= 15u) {
      // WIP 021 shader-creation phase: after the fifteen sealed device-init
      // shapes, exact sub_820C0440/sub_820C0330/sub_820C01C0 allocate shader
      // and declaration objects (flag 0x24800000) and their physical
      // microcode blocks (flag 0xB5800000), with small sizes derived from the
      // container's shader files. Only those shapes are accepted.
      if ((flags != 0x24800000u && flags != 0xB5800000u) ||
          size < 16u || size > 65536u)
        fail(Error::unsupported, 0x82136670u);
      const uint32_t p=(g_graphics_alloc_cursor + 15u) & ~15u;
      if (p > 0xffffffffu-size || memory.check(p,size,3) != cc::xbox::MemoryError::ok)
        fail(Error::memory,p);
      g_graphics_alloc_cursor=p+size;
      ++g_graphics_alloc_index;
      return p;
    }
    if (size != sizes[g_graphics_alloc_index] ||
        flags != flagv[g_graphics_alloc_index])
      fail(Error::unsupported, 0x82136670u);
    uint32_t p=(g_graphics_alloc_cursor + 15u) & ~15u;
    if (p > 0xffffffffu-size || memory.check(p,size,3) != cc::xbox::MemoryError::ok)
      fail(Error::memory,p);
    if (g_graphics_alloc_index == 2u) ring_virtual=p;
    if (g_graphics_alloc_index == 4u) ring_descriptor=p;
    if (g_graphics_alloc_index == 13u) tile_allocator=p;
    g_graphics_alloc_cursor=p+size;
    ++g_graphics_alloc_index;
    return p;
  }
  ThreadSlot* by_handle(uint32_t handle) noexcept {
    for (auto &t: threads) if (t.allocated && t.handle==handle) return &t;
    return nullptr;
  }
  ThreadSlot* by_object(uint32_t object) noexcept {
    for (auto &t: threads) if (t.allocated && t.object==object) return &t;
    return nullptr;
  }
  std::jmp_buf escape{};
  uint32_t budget = 200000, depth = 0;
  uint32_t cp_rb_wptr = 0, cp_rb_wptr_writes = 0;
  const char* last_function = "<none>";
  std::array<const char*,32> recent_functions{};
  std::array<uint32_t,32> recent_r1{};
  uint32_t recent_pos{};
  std::chrono::steady_clock::time_point timebase_epoch = std::chrono::steady_clock::now();
  static constexpr uint64_t timebase_hz = 49875000ull;
  uint64_t query_timebase() const noexcept {
    using namespace std::chrono;
    const uint64_t ns = uint64_t(duration_cast<nanoseconds>(steady_clock::now()-timebase_epoch).count());
    return (ns/1000000000ull)*timebase_hz + ((ns%1000000000ull)*timebase_hz)/1000000000ull;
  }
  const Context* last_ctx{};
  void prologue(const char *name, const Context& ctx) {
    last_function = name;
    last_ctx = &ctx;
    recent_functions[recent_pos & 31u] = name;
    recent_r1[recent_pos & 31u] = ctx.r1.u32;
    ++recent_pos;
    if (!std::strcmp(name,"sub_8209CD08") || !std::strcmp(name,"sub_8209CC98")) validate_widget_list(ctx.r3.u32);
    if (!std::strcmp(name,"sub_8209DE50")) validate_widget_update(ctx.r3.u32);
    if (!std::strcmp(name,"sub_8209DF48")) validate_widget_owner(ctx.r3.u32);
    if (!std::strcmp(name,"sub_82091248")) validate_owner(ctx.r3.u32);
    if (++result.functions > 250000)
      fail(Error::capacity);
    if (!std::strcmp(name, "sub_8208A7A0"))
      ++result.tree_visits;
  }
  void tick(uint32_t a) {
    if (++result.memory_ops > budget)
      fail(Error::capacity, a);
  }
  [[noreturn]] void fail(Error e, uint32_t a = 0) {
    result.error = e;
    result.address = a;
    std::fprintf(stderr,"TRACE020 fail error=%u address=%08x last=%s funcs=%u memops=%u",unsigned(e),a,last_function,result.functions,result.memory_ops);
    if (last_ctx)
      std::fprintf(stderr," r1=%08x r3=%08x r4=%08x r5=%08x r6=%08x r11=%08x lr=%08x",
                   last_ctx->r1.u32,last_ctx->r3.u32,last_ctx->r4.u32,last_ctx->r5.u32,
                   last_ctx->r6.u32,last_ctx->r11.u32,uint32_t(last_ctx->lr));
    std::fprintf(stderr," recent=");
    for (unsigned k=0;k<32;++k) { const char* n=recent_functions[(recent_pos+k)&31u]; if(n) std::fprintf(stderr,"%s%s@%08x",k?",":"",n,recent_r1[(recent_pos+k)&31u]); }
    std::fprintf(stderr,"\n");
    std::longjmp(escape, 1);
  }
  // The original widget list uses +12 for its head and +20 for siblings.
  // Visibility gates are honored before following fields that the original would
  // never touch. No absent input pages are synthesized by this preflight.
  void validate_widget_list(uint32_t object) {
    if (object > 0xffffffe7u) fail(Error::context,object);
    if (!load(object+24,1)) return;
    uint32_t slow=uint32_t(load(object+12,4)),fast=slow;
    auto next=[&](uint32_t node)->uint32_t {
      if (!node) return 0;
      if (node>0xffffffebu) fail(Error::context,node);
      return uint32_t(load(node+20,4));
    };
    for(unsigned i=0;fast;++i) {
      if(i>=4096) fail(Error::capacity,object);
      slow=next(slow);fast=next(next(fast));
      if(fast && fast==slow) fail(Error::cycle,fast);
    }
  }
  void validate_widget_update(uint32_t object) {
    if(object>0xffffff9fu) fail(Error::context,object);
    if(!load(object+24,1)) return;
    const uint32_t owner=uint32_t(load(object+96,4));
    if(owner>0xffffd7b7u) fail(Error::context,owner);
  }
  void validate_widget_owner(uint32_t object) {
    if(object>0xffffff9fu) fail(Error::context,object);
    if(!load(object+24,1)) return;
    uint32_t owner=uint32_t(load(object+96,4));
    if(owner>0xffffd796u) fail(Error::context,owner);
    if(load(owner+10345,1)) {
      // Original owner stack occupies [7992,8248); its next push must fit.
      int32_t index=int32_t(uint32_t(load(owner+8248,4)));
      if(index < -1 || index >= 63) fail(Error::context,owner+8248);
    }
  }
  void validate_list(uint32_t object) {
    if (object > 0xffffff97u)
      fail(Error::context, object);
    uint32_t slow = uint32_t(load(object + 104, 4)), fast = slow;
    auto next = [&](uint32_t node) -> uint32_t {
      if (!node)
        return 0;
      if (node > 0xffffffa7u)
        fail(Error::context, node);
      return uint32_t(load(node + 88, 4));
    };
    for (unsigned i = 0; fast; ++i) {
      if (i >= 4096)
        fail(Error::capacity, object);
      slow = next(slow);
      fast = next(next(fast));
      if (fast && fast == slow)
        fail(Error::cycle, fast);
    }
  }
  void validate_owner(uint32_t owner) {
    if (owner > 0xffffd7b7u) fail(Error::context, owner);
    const uint32_t object = uint32_t(load(owner + 72, 4));
    if (object > 0xffffff97u) fail(Error::context, object);
    const uint32_t vt = uint32_t(load(object, 4));
    if (vt > 0xffffff9bu) fail(Error::context, vt);
    const uint32_t getter = uint32_t(load(vt + 100, 4));
    // Original sub_82086810 returns object + 104. Reject unknown contracts.
    if (getter != 0x82086810u) fail(Error::dispatch, getter);
    validate_list(object);
  }
  uint64_t load(uint32_t a, unsigned n) {
    tick(a);
    uint64_t v = 0;
    if (memory.load_be(a, n, v) != cc::xbox::MemoryError::ok)
      fail(Error::memory, a);
    return v;
  }
  void store(uint32_t a, unsigned n, uint64_t v) {
    tick(a);
    if (memory.store_be(a, n, v) != cc::xbox::MemoryError::ok)
      fail(Error::memory, a);
  }
};
// Minimal diagnostic-harness compatibility for the ReXGlue scalar/vector
// helpers reached by the exact recovered bodies. This is not a general SIMD
// runtime: implement only the lane semantics actually emitted by the sealed
// corpus and keep generated game bodies byte-exact. Nearest-even is established
// by FloatScope; nonfinite/out-of-range scalar converts use the intrinsic
// indefinite value.
struct ScalarDouble {
  double value;
};
static ScalarDouble simde_mm_load_sd(const double *p) { return {*p}; }
static int64_t convert(double x, bool nearest) {
  if (!std::isfinite(x))
    return INT64_MIN;
  double n = nearest ? std::nearbyint(x) : std::trunc(x);
  if (n < -0x1p63 || n >= 0x1p63)
    return INT64_MIN;
  return static_cast<int64_t>(n);
}
static int64_t simde_mm_cvtsd_si64(ScalarDouble d) {
  return convert(d.value, true);
}
static int64_t simde_mm_cvttsd_si64(ScalarDouble d) {
  return convert(d.value, false);
}
static int32_t simde_mm_cvttsd_si32(ScalarDouble d) {
  if (!std::isfinite(d.value) || d.value < double(INT_MIN) || d.value >= 2147483648.0)
    return INT_MIN;
  return static_cast<int32_t>(std::trunc(d.value));
}
using PPCVRegister = cc::quad::VRegister;
struct SimdI021 { uint8_t u8[16]; };
struct SimdF021 { float f32[4]; };
using simde__m128i = SimdI021;
using simde__m128 = SimdF021;
static simde__m128i simde_mm_load_si128(const simde__m128i* p) { simde__m128i v{}; std::memcpy(&v,p,16); return v; }
static void simde_mm_store_si128(simde__m128i* p, simde__m128i v) { std::memcpy(p,&v,16); }
static simde__m128 simde_mm_load_ps(const float* p) { simde__m128 v{}; std::memcpy(v.f32,p,16); return v; }
static void simde_mm_store_ps(float* p, simde__m128 v) { std::memcpy(p,v.f32,16); }
static simde__m128 simde_mm_permute_ps(simde__m128 a, int imm) {
  simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=a.f32[(imm>>(i*2))&3]; return r;
}
static simde__m128 simde_mm_blend_ps(simde__m128 a, simde__m128 b, int mask) {
  simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=(mask&(1<<i))?b.f32[i]:a.f32[i]; return r;
}
static simde__m128 simde_mm_add_ps(simde__m128 a, simde__m128 b) { simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=a.f32[i]+b.f32[i]; return r; }
static simde__m128 simde_mm_sub_ps(simde__m128 a, simde__m128 b) { simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=a.f32[i]-b.f32[i]; return r; }
static simde__m128 simde_mm_mul_ps(simde__m128 a, simde__m128 b) { simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=a.f32[i]*b.f32[i]; return r; }
static simde__m128 simde_mm_div_ps(simde__m128 a, simde__m128 b) { simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=a.f32[i]/b.f32[i]; return r; }
static simde__m128 simde_mm_set1_ps(float v) { simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=v; return r; }
static simde__m128 simde_mm_max_ps(simde__m128 a, simde__m128 b) {
  simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=(std::isnan(a.f32[i])||std::isnan(b.f32[i]))?b.f32[i]:(a.f32[i]>b.f32[i]?a.f32[i]:b.f32[i]); return r;
}
static simde__m128 simde_mm_min_ps(simde__m128 a, simde__m128 b) {
  simde__m128 r{}; for(int i=0;i<4;++i) r.f32[i]=(std::isnan(a.f32[i])||std::isnan(b.f32[i]))?b.f32[i]:(a.f32[i]<b.f32[i]?a.f32[i]:b.f32[i]); return r;
}
static simde__m128i simde_mm_set1_epi32(int v) { simde__m128i r{}; for(int i=0;i<4;++i) std::memcpy(r.u8+i*4,&v,4); return r; }
static simde__m128i simde_mm_and_si128(simde__m128i a, simde__m128i b) { simde__m128i r{}; for(int i=0;i<16;++i) r.u8[i]=uint8_t(a.u8[i]&b.u8[i]); return r; }
static simde__m128i simde_mm_andnot_si128(simde__m128i a, simde__m128i b) { simde__m128i r{}; for(int i=0;i<16;++i) r.u8[i]=uint8_t((~a.u8[i])&b.u8[i]); return r; }
static simde__m128i simde_mm_or_si128(simde__m128i a, simde__m128i b) { simde__m128i r{}; for(int i=0;i<16;++i) r.u8[i]=uint8_t(a.u8[i]|b.u8[i]); return r; }
static simde__m128i simde_mm_add_epi32(simde__m128i a, simde__m128i b) {
  simde__m128i r{}; uint32_t av[4]{},bv[4]{},rv[4]{}; std::memcpy(av,a.u8,16); std::memcpy(bv,b.u8,16);
  for(int i=0;i<4;++i) rv[i]=av[i]+bv[i]; std::memcpy(r.u8,rv,16); return r;
}
static simde__m128i simde_mm_slli_epi32(simde__m128i a, int n) {
  simde__m128i r{}; uint32_t av[4]{},rv[4]{}; std::memcpy(av,a.u8,16);
  for(int i=0;i<4;++i) rv[i]=(n>=32)?0u:(av[i]<<n); std::memcpy(r.u8,rv,16); return r;
}
static simde__m128i simde_mm_sllv_epi32(simde__m128i a, simde__m128i b) {
  simde__m128i r{}; uint32_t av[4]{},bv[4]{},rv[4]{}; std::memcpy(av,a.u8,16); std::memcpy(bv,b.u8,16);
  for(int i=0;i<4;++i) rv[i]=(bv[i]>=32u)?0u:(av[i]<<bv[i]); std::memcpy(r.u8,rv,16); return r;
}
static simde__m128 simde_mm_castsi128_ps(simde__m128i a) { simde__m128 r{}; std::memcpy(r.f32,a.u8,16); return r; }
static simde__m128i simde_mm_cvttps_epi32(simde__m128 a) {
  simde__m128i r{}; int32_t out[4]{};
  for(int i=0;i<4;++i) { const float x=a.f32[i]; if(!std::isfinite(x)||x < -2147483648.0f || x >= 2147483648.0f) out[i]=INT32_MIN; else out[i]=static_cast<int32_t>(std::trunc(x)); }
  std::memcpy(r.u8,out,16); return r;
}
static simde__m128i simde_mm_shuffle_epi32(simde__m128i a, int imm) {
  simde__m128i r{}; uint32_t lanes[4]{}; std::memcpy(lanes,a.u8,16); uint32_t out[4]{};
  for(int i=0;i<4;++i) out[i]=lanes[(imm>>(i*2))&3]; std::memcpy(r.u8,out,16); return r;
}
static simde__m128i simde_mm_xor_si128(simde__m128i a, simde__m128i b) { simde__m128i r{}; for(int i=0;i<16;++i) r.u8[i]=a.u8[i]^b.u8[i]; return r; }
static simde__m128 simde_mm_xor_ps(simde__m128 a, simde__m128 b) { simde__m128 r{}; uint32_t av[4]{},bv[4]{},rv[4]{}; std::memcpy(av,a.f32,16); std::memcpy(bv,b.f32,16); for(int i=0;i<4;++i) rv[i]=av[i]^bv[i]; std::memcpy(r.f32,rv,16); return r; }
static simde__m128 simde_mm_cmpeq_ps(simde__m128 a, simde__m128 b) { simde__m128 r{}; uint32_t bits[4]{}; for(int i=0;i<4;++i) bits[i]=(!std::isnan(a.f32[i])&&!std::isnan(b.f32[i])&&a.f32[i]==b.f32[i])?0xffffffffu:0u; std::memcpy(r.f32,bits,16); return r; }
static simde__m128 simde_mm_cmpgt_ps(simde__m128 a, simde__m128 b) { simde__m128 r{}; uint32_t bits[4]{}; for(int i=0;i<4;++i) bits[i]=(!std::isnan(a.f32[i])&&!std::isnan(b.f32[i])&&a.f32[i]>b.f32[i])?0xffffffffu:0u; std::memcpy(r.f32,bits,16); return r; }
static constexpr int SIMDE_MM_FROUND_TO_NEAREST_INT=0x00;
static constexpr int SIMDE_MM_FROUND_TO_NEG_INF=0x01;
static constexpr int SIMDE_MM_FROUND_TO_ZERO=0x03;
static constexpr int SIMDE_MM_FROUND_NO_EXC=0x08;
static simde__m128 simde_mm_round_ps(simde__m128 a, int mode) {
  simde__m128 r{}; const int m=mode&0x07;
  for(int i=0;i<4;++i) { if(m==SIMDE_MM_FROUND_TO_NEG_INF) r.f32[i]=std::floor(a.f32[i]); else if(m==SIMDE_MM_FROUND_TO_ZERO) r.f32[i]=std::trunc(a.f32[i]); else r.f32[i]=std::nearbyint(a.f32[i]); }
  return r;
}
// PPC lvsl control table in ReXGlue host byte order. lvsl with shift sh must
// yield the big-endian control vector whose lane j equals sh+j; host lane i
// mirrors big-endian lane 15-i, so row sh holds [sh+15, sh+14, ..., sh]. The
// pairing with simde_mm_perm_epi8_ below reproduces exact vperm unaligned
// loads: be-lane j selects concat(vA,vB)[c_be[j] & 0x1F].
static constexpr uint8_t VectorShiftTableL[256] = {
  0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,
  0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,
  0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,
  0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,
  0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,
  0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,
  0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,
  0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,
  0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,
  0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,
  0x19,0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,
  0x1A,0x19,0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0B,
  0x1B,0x1A,0x19,0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,
  0x1C,0x1B,0x1A,0x19,0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,
  0x1D,0x1C,0x1B,0x1A,0x19,0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F,0x0E,
  0x1E,0x1D,0x1C,0x1B,0x1A,0x19,0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0F
};
namespace rex::ppc {
// PPC vperm in the host mirrored-lane representation: host lane i is
// big-endian lane 15-i, so the be-space select translates to
// d_host[i] = (c&0x10) ? b_host[31-c] : a_host[15-c] with c = c_host[i]&0x1F.
static simde__m128i simde_mm_perm_epi8_(simde__m128i a, simde__m128i b, simde__m128i c) {
  simde__m128i d{};
  for (int i=0;i<16;++i) {
    const uint8_t sel = uint8_t(c.u8[i] & 0x1F);
    d.u8[i] = sel < 16 ? a.u8[15 - sel] : b.u8[31 - sel];
  }
  return d;
}
static simde__m128i simde_mm_vctsxs(simde__m128 a) {
  simde__m128i r{}; int32_t out[4]{};
  for(int i=0;i<4;++i) {
    const float x=a.f32[i];
    if (std::isnan(x)) out[i]=0;
    else if (x>=float(INT32_MAX)) out[i]=INT32_MAX;
    else if (x<=float(INT32_MIN)) out[i]=INT32_MIN;
    else out[i]=static_cast<int32_t>(std::trunc(x));
  }
  std::memcpy(r.u8,out,16); return r;
}
}
static simde__m128i simde_mm_shuffle_epi8(simde__m128i a, simde__m128i m) { simde__m128i r{}; for(int i=0;i<16;++i) r.u8[i]=(m.u8[i]&0x80u)?0u:a.u8[m.u8[i]&15u]; return r; }
static simde__m128i simde_mm_alignr_epi8(simde__m128i a, simde__m128i b, int n) { simde__m128i r{}; uint8_t c[32]; std::memcpy(c,b.u8,16); std::memcpy(c+16,a.u8,16); for(int i=0;i<16;++i) r.u8[i]=(n+i<32)?c[n+i]:0u; return r; }
static constexpr uint8_t VectorMaskL[256] = {
  0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,
  0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,
  0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,
  0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,
  0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,
  0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,0x0B,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,0x0C,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,0x0D,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0E,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F
};
static uint8_t* raw_addr021(Machine& base,uint32_t a) { auto* p=base.memory.contiguous(a,16,3); if(!p) base.fail(Error::memory,a); return p; }
#define REX_RAW_ADDR(a) raw_addr021(base,uint32_t(a))
using PPCRegister = Register;
#define DEFINE_REX_FUNC(name)                                                  \
  static void name([[maybe_unused]] Context &ctx,                              \
                   [[maybe_unused]] Machine &base)
#define REX_FUNC_PROLOGUE() base.prologue(__func__,ctx)
#define REX_LOAD_U8(a) uint8_t(base.load(uint32_t(a), 1))
#define REX_LOAD_U16(a) uint16_t(base.load(uint32_t(a), 2))
#define REX_LOAD_U32(a) uint32_t(base.load(uint32_t(a), 4))
#define REX_LOAD_U64(a) base.load(uint32_t(a), 8)
#define REX_STORE_U8(a, v) base.store(uint32_t(a), 1, v)
#define REX_STORE_U16(a, v) base.store(uint32_t(a), 2, v)
#define REX_STORE_U32(a, v) base.store(uint32_t(a), 4, v)
#define REX_STORE_U64(a, v) base.store(uint32_t(a), 8, v)
static void dispatch(uint32_t, Context &, Machine &);
#define REX_CALL_INDIRECT_FUNC(a) dispatch(uint32_t(a), ctx, base)
#include "decls.inc"
#define sub_8208C5D8 sub_8208C5D8_unsupported008
#include "../runtime008/bodies.inc"
#undef sub_8208C5D8
#include "../runtime010/bodies.inc"
#include "../runtime011/bodies.inc"
#include "bodies.inc"
static bool submit(void *ptr, const Draw &d) {
  auto &m = *static_cast<Machine *>(ptr);
  if (!m.sink.submit || !m.sink.submit(m.sink.user, d))
    return false;
  ++m.result.submits;
  return true;
}
static void dispatch_impl(uint32_t address, Context &ctx, Machine &base) {
  if (++base.result.dispatches > 20000)
    base.fail(Error::capacity, address);
  if (address == 0x82091248)
    base.validate_owner(ctx.r3.u32);
  if (address == 0x8208a7a0)
    base.validate_list(ctx.r3.u32);
  switch (address) {
#include "../runtime008/dispatch.inc"
#include "../runtime010/dispatch.inc"
#include "../runtime011/dispatch.inc"
#include "dispatch.inc"
  case 0x8214a534: {
    // NtCreateFile ??? bounded shader-file platform contract. Accept only the
    // observed synchronous read-only open (access 0x80100080, OBJ root -3,
    // OBJ_CASE_INSENSITIVE, FILE_OPEN, options 0x60) of "game:\shaders\<name>"
    // backed by the extracted retail-container files.
    const uint32_t handle_out=ctx.r3.u32, oa=ctx.r5.u32, iosb=ctx.r6.u32;
    if (base.file_open || ctx.r4.u32!=0x80100080u || ctx.r7.u32!=0u ||
        ctx.r8.u32!=0u || ctx.r9.u32!=0u || ctx.r10.u32!=1u ||
        uint32_t(base.load(ctx.r1.u32+84,4))!=0x60u ||
        uint32_t(base.load(oa+0,4))!=0xFFFFFFFDu ||
        uint32_t(base.load(oa+8,4))!=0x40u) {
      std::fprintf(stderr,"NTCREATE reject open=%d r4=%08x r7=%08x r8=%08x r9=%08x r10=%08x s84=%08x oa0=%08x oa8=%08x\n",
        int(base.file_open),ctx.r4.u32,ctx.r7.u32,ctx.r8.u32,ctx.r9.u32,ctx.r10.u32,
        uint32_t(base.load(ctx.r1.u32+84,4)),uint32_t(base.load(oa+0,4)),uint32_t(base.load(oa+8,4)));
      base.fail(Error::unsupported, address);
    }
    const uint32_t str=uint32_t(base.load(oa+4,4));
    const uint32_t len=uint32_t(base.load(str+0,2));
    const uint32_t buf=uint32_t(base.load(str+4,4));
    char fname[80]{};
    static constexpr char prefix[]="game:\\shaders\\";
    constexpr uint32_t plen=uint32_t(sizeof(prefix))-1u;
    if (len<=plen || len>=plen+64u)
      base.fail(Error::unsupported, address);
    for (uint32_t i=0;i<plen;++i)
      if (uint8_t(base.load(buf+i,1))!=uint8_t(prefix[i]))
        base.fail(Error::unsupported, address);
    for (uint32_t i=plen;i<len;++i) {
      const char chv=char(base.load(buf+i,1));
      if (!((chv>='A'&&chv<='Z')||(chv>='a'&&chv<='z')||(chv>='0'&&chv<='9')||chv=='.'))
        base.fail(Error::unsupported, address);
      fname[i-plen]=chv;
    }
    if (g_game_root.empty())
      base.fail(Error::unsupported, address);
    const std::string host=g_game_root+"/shaders/"+fname;
    std::FILE* f=std::fopen(host.c_str(),"rb");
    if (!f) {
      // The sealed shader-name table requests SobelEdge.xpu (the container
      // ships SobelEdgePS.xpu) and VertexColorFillPS.xpu (absent from the
      // container entirely, per the sealed container manifest). The retail
      // game observes STATUS_OBJECT_NAME_NOT_FOUND for exactly these two and
      // continues. Any other miss is an environment problem and fails closed.
      if (std::strcmp(fname,"SobelEdge.xpu")!=0 &&
          std::strcmp(fname,"VertexColorFillPS.xpu")!=0) {
        std::fprintf(stderr,"NTCREATE miss name='%s' root='%s'\n",fname,g_game_root.c_str());
        base.fail(Error::unsupported, address);
      }
      ctx.r3.u64=0xC0000034u;
      return;
    }
    std::fseek(f,0,SEEK_END);
    const long sz=std::ftell(f);
    std::fseek(f,0,SEEK_SET);
    if (sz<=0 || sz>65536) { std::fclose(f); base.fail(Error::unsupported, address); }
    base.file_bytes.assign(size_t(sz),0);
    const bool ok=std::fread(base.file_bytes.data(),1,size_t(sz),f)==size_t(sz);
    std::fclose(f);
    if (!ok) base.fail(Error::unsupported, address);
    base.file_open=true;
    base.file_pos=0;
    base.file_handle=0x0F11E001u;
    base.store(handle_out,4,base.file_handle);
    base.store(iosb+0,4,0u);
    base.store(iosb+4,4,1u); // FILE_OPENED
    ctx.r3.u64=0;
    return;
  }
  case 0x8214a624: {
    // NtQueryInformationFile ??? bounded to FileNetworkOpenInformation (class
    // 34, 56 bytes) on the single open shader-file fixture handle.
    const uint32_t iosb=ctx.r4.u32, buf=ctx.r5.u32;
    if (!base.file_open || ctx.r3.u32!=base.file_handle ||
        ctx.r6.u32!=56u || ctx.r7.u32!=34u)
      base.fail(Error::unsupported, address);
    for (unsigned i=0;i<4;++i) base.store(buf+i*8u,8,0u); // four timestamps
    base.store(buf+32u,8,uint64_t(base.file_bytes.size())); // AllocationSize
    base.store(buf+40u,8,uint64_t(base.file_bytes.size())); // EndOfFile
    base.store(buf+48u,4,0x80u); // FILE_ATTRIBUTE_NORMAL
    base.store(buf+52u,4,0u);
    base.store(iosb+0,4,0u);
    base.store(iosb+4,4,56u);
    ctx.r3.u64=0;
    return;
  }
  case 0x8214a664: {
    // NtReadFile ??? bounded synchronous read of the single open shader-file
    // fixture from the current position (no event/APC/byte-offset observed).
    const uint32_t iosb=ctx.r7.u32, buf=ctx.r8.u32, len=ctx.r9.u32;
    if (!base.file_open || ctx.r3.u32!=base.file_handle || ctx.r4.u32!=0u ||
        ctx.r5.u32!=0u || ctx.r6.u32!=0u || ctx.r10.u32!=0u ||
        base.file_pos>base.file_bytes.size())
      base.fail(Error::unsupported, address);
    const uint32_t avail=uint32_t(base.file_bytes.size()-base.file_pos);
    const uint32_t take=len<avail?len:avail;
    for (uint32_t i=0;i<take;++i)
      base.store(buf+i,1,base.file_bytes[base.file_pos+i]);
    base.file_pos+=take;
    base.store(iosb+0,4,take?0u:0xC0000011u); // STATUS_END_OF_FILE when empty
    base.store(iosb+4,4,take);
    ctx.r3.u64=take?0u:0xC0000011u;
    return;
  }
  case 0x8214a584: {
    // NtClose ??? bounded to the single open shader-file fixture handle.
    if (!base.file_open || ctx.r3.u32!=base.file_handle)
      base.fail(Error::unsupported, address);
    base.file_open=false;
    base.file_handle=0;
    base.file_pos=0;
    base.file_bytes.clear();
    ctx.r3.u64=0;
    return;
  }
  case 0x820a89f8: {
    const uint32_t obj = ctx.r3.u32, desc = ctx.r4.u32;
    if (obj > 0xffff89efu || desc > 0xffffffafu)
      base.fail(Error::context, address);
    const uint32_t ix = uint32_t(base.load(obj + 30208, 4));
    if (ix >= 8)
      base.fail(Error::context, address);
    const uint32_t shader =
        uint32_t(base.load(uint32_t(base.load(obj + 30176 + ix * 4, 4)), 4));
    if (shader != 0 && shader != 5)
      base.fail(Error::context, address);
    uint32_t words[20];
    for (unsigned i = 0; i < 20; ++i)
      words[i] = uint32_t(base.load(desc + i * 4, 4));
    if (!words[4] || !words[5] || words[4] > 4096 || words[5] > 4096 ||
        (words[6] != 1 && words[6] != 5))
      base.fail(Error::texture, desc);
    if (!base.sink.bind || !base.sink.bind(base.sink.user, desc, words))
      base.fail(Error::texture, desc);
    ++base.result.bind_calls;
    return;
  }
  case 0x820a9308: {
    ++base.result.quad_calls;
    unsigned emitted = 0;
    const auto e =
        cc::quad::invoke(address, ctx, base.memory, {&base, submit}, &emitted);
    if (e != cc::quad::Error::ok) {
      base.result.quad_error = uint32_t(e);
      base.fail(Error::quad, address);
    }
    return;
  }
  default:
    base.fail(Error::dispatch, address);
  }
}
static void dispatch(uint32_t a, Context &c, Machine &m) {
  if (++m.depth > 64)
    m.fail(Error::capacity, a);
  if (m.depth > m.result.deepest_dispatch)
    m.result.deepest_dispatch = m.depth;
  dispatch_impl(a, c, m);
  --m.depth;
}
// setjmp lives in a separate function; modified Machine/Context storage belongs
// to the caller, not to this setjmp frame. Generated callees are scalar/trivial
// and create no nontrivial automatic objects across a longjmp. FloatScope is
// outside this frame and always restores host FP controls normally.
static void execute(uint32_t entry, Context &ctx, Machine &m) {
  if (setjmp(m.escape))
    return;
  if (entry == 0x8208a7a0)
    m.validate_list(ctx.r3.u32);
  if (entry == 0x82091248)
    m.validate_owner(ctx.r3.u32);
  if(entry==0x8209ce40 || entry==0x8209ce48) {
    if(ctx.r3.u32>0xffffffe7u) m.fail(Error::context,ctx.r3.u32);
  }
  switch (entry) {
  case 0x820701d0: sub_820701D0_startup_full(ctx,m); break;
  case 0x820b7880: sub_820B7880(ctx,m); break;
  case 0x82070ac8: sub_82070AC8_renderer_prefix(ctx,m); break;
  case 0x820a7990: sub_820A7990_platform_prefix(ctx,m); break;
  case 0x820a7b34: sub_820A7990_platform_post_graphics(ctx,m); break;
  case 0x820befd0: sub_820BEFD0(ctx,m); break;
  case 0x820c2c98: sub_820C2C98(ctx,m); break;
  case 0x820c13b8: sub_820C13B8(ctx,m); break;
  case 0x82070434: sub_820701D0_manager_slice(ctx,m); break;
  case 0x8209cc98: sub_8209CC98(ctx,m); break;
  case 0x8209de50: sub_8209DE50(ctx,m); break;
  case 0x82097720: sub_82097720(ctx,m); break;
  case 0x820915f0: sub_820915F0(ctx,m); break;
  case 0x820a1ac0: sub_820A1AC0(ctx,m); break;
  case 0x8209ce40: sub_8209CE40(ctx,m); break;
  case 0x8209ce48: sub_8209CE48(ctx,m); break;
  case 0x8209cd08: sub_8209CD08(ctx,m); break;
  case 0x8209df48: sub_8209DF48(ctx,m); break;
  case 0x8208a7a0:
    sub_8208A7A0(ctx, m);
    break;
  case 0x82091248:
    sub_82091248(ctx, m);
    break;
  case 0x820a8ff8:
    sub_820A8FF8(ctx, m);
    break;
  default:
    m.fail(Error::entry, entry);
  }
}
Result invoke(uint32_t entry, Context &ctx, AddressSpace &memory, Sink sink,
              uint32_t budget) noexcept {
  Result error;
  if (entry != 0x820c13b8 && entry != 0x820c2c98 && entry != 0x820befd0 && entry != 0x820a7b34 && entry != 0x820a7990 && entry != 0x82070ac8 && entry != 0x820701d0 && entry != 0x820b7880 && entry != 0x82070434 && entry != 0x8208a7a0 && entry != 0x820a8ff8 && entry != 0x82091248 && entry != 0x8209cd08 && entry != 0x8209cc98 && entry != 0x8209de50 && entry != 0x82097720 && entry != 0x820915f0 && entry != 0x8209df48 && entry != 0x820a1ac0 && entry != 0x8209ce40 && entry != 0x8209ce48) {
    error.error = Error::entry;
    return error;
  }
  if (!sink.submit || !sink.bind || ctx.r1.u64 < 16384 ||
      ctx.r1.u64 > 0xffffff7f || budget < 1 || budget > 20000000) {
    error.error = Error::context;
    return error;
  }
  if (memory.check(ctx.r1.u32 - 512, 640, 3) != cc::xbox::MemoryError::ok) {
    error.error = Error::memory;
    return error;
  }
  Machine m(memory, sink);
  m.budget = budget;
  FloatScope fp;
  execute(entry, ctx, m);
  return m.result;
}
const char *name(Error e) noexcept {
  switch (e) {
#define E(x)                                                                   \
  case Error::x:                                                               \
    return #x;
    E(ok)
    E(entry)
    E(context) E(memory) E(dispatch) E(texture) E(quad) E(sink) E(capacity)
        E(unsupported) E(cycle)
#undef E
  }
  return "unknown";
}
} // namespace cc::tree
