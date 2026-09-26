#include "generated/__savegprlr_29.inc"
#include "generated/__restgprlr_29.inc"
#include "generated/sub_8208C5D8.inc"
#include "generated/sub_8209CC98.inc"

// ReXGlue's generated PPC trap intrinsic is a non-returning failure path. The
// bounded host runtime reports it as context failure; it never converts a trap
// into success.
static void ppc_trap([[maybe_unused]] Context& ctx, Machine& base, uint32_t code) {
  base.fail(Error::context, code);
}

#include "generated/sub_82097720.inc"
#include "generated/__savegprlr_22.inc"
#include "generated/__restgprlr_22.inc"

#define HARD_BOUNDARY(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { \
    base.fail(Error::unsupported, addr); \
  }
HARD_BOUNDARY(sub_820B0F18, 0x820B0F18u)
HARD_BOUNDARY(sub_82084D18, 0x82084D18u)
HARD_BOUNDARY(sub_82084DB8, 0x82084DB8u)
HARD_BOUNDARY(sub_820A71E8, 0x820A71E8u)
HARD_BOUNDARY(sub_82086010, 0x82086010u)
HARD_BOUNDARY(sub_82084C78, 0x82084C78u)
HARD_BOUNDARY(sub_8207B630, 0x8207B630u)
HARD_BOUNDARY(sub_8207B8B8, 0x8207B8B8u)
HARD_BOUNDARY(sub_8207BAE8, 0x8207BAE8u)
HARD_BOUNDARY(sub_82084EE0, 0x82084EE0u)
HARD_BOUNDARY(sub_82098100, 0x82098100u)
HARD_BOUNDARY(sub_82099730, 0x82099730u)
HARD_BOUNDARY(sub_82099C68, 0x82099C68u)
HARD_BOUNDARY(sub_82099B48, 0x82099B48u)
HARD_BOUNDARY(sub_82099BE8, 0x82099BE8u)
HARD_BOUNDARY(sub_82051868, 0x82051868u)
HARD_BOUNDARY(sub_820518E0, 0x820518E0u)
HARD_BOUNDARY(sub_82053380, 0x82053380u)
HARD_BOUNDARY(sub_82084AC8, 0x82084AC8u)
HARD_BOUNDARY(sub_82127468, 0x82127468u)
HARD_BOUNDARY(sub_82074A58, 0x82074A58u)
HARD_BOUNDARY(sub_82074B00, 0x82074B00u)
HARD_BOUNDARY(sub_82078668, 0x82078668u)
HARD_BOUNDARY(sub_820516F8, 0x820516F8u)
HARD_BOUNDARY(sub_82127588, 0x82127588u)
HARD_BOUNDARY(sub_8209A170, 0x8209A170u)
HARD_BOUNDARY(sub_82053888, 0x82053888u)
HARD_BOUNDARY(sub_82053648, 0x82053648u)
HARD_BOUNDARY(sub_8208B8D0, 0x8208B8D0u)
HARD_BOUNDARY(sub_82086D30, 0x82086D30u)
HARD_BOUNDARY(sub_82066EA8, 0x82066EA8u)
HARD_BOUNDARY(sub_8207A1E0, 0x8207A1E0u)
#undef HARD_BOUNDARY

#include "generated/sub_820B5EB8.inc"
#include "generated/sub_8209BDD8.inc"
#include "generated/sub_8209BF18.inc"
#include "generated/__savegprlr_26.inc"
#include "generated/__restgprlr_26.inc"
#include "generated/sub_82099A80.inc"
#include "generated/sub_82099968.inc"
#include "generated/sub_820986F0.inc"
#include "generated/sub_82097AC8.inc"
#include "generated/sub_82075098.inc"
#include "generated/sub_820744C8.inc"
#include "generated/sub_82099680.inc"
#include "generated/sub_82097650.inc"
#include "generated/sub_820701D0_manager_slice.inc"

// Xbox 360's performance/timebase frequency is 49.875 MHz. Keep the platform
// shim paired with a scaled monotonic timebase so generated mftb code observes
// guest-rate ticks rather than the host CPU TSC frequency.
static void __imp__KeQueryPerformanceFrequency(Context& ctx, [[maybe_unused]] Machine& base) {
  ctx.r3.u64 = Machine::timebase_hz;
}
#define REX_QUERY_TIMEBASE() base.query_timebase()
#include "generated/sub_820B6D10.inc"
#include "generated/sub_820B6D48.inc"
#undef REX_QUERY_TIMEBASE

#include "generated/sub_82082390.inc"
#include "generated/sub_8208BE40.inc"
#include "generated/sub_8208AB98.inc"
#include "generated/sub_820936B0.inc"
#include "generated/sub_82094530.inc"
#include "generated/sub_82094420.inc"
#include "generated/sub_820772B0.inc"
#include "generated/sub_820A1AC0.inc"
#include "generated/sub_82088A08.inc"
#include "generated/sub_8208A228.inc"
#include "generated/sub_8208AE78.inc"
#include "generated/sub_820915F0.inc"
#include "generated/sub_8209DE50.inc"


// Checkpoint 016 startup-prefix closure. Exact bodies are copied byte-for-byte
// from the sealed ReXGlue translation units; the two host shims below are
// intentionally narrow platform/CRT boundaries and are not counted as exact bodies.
#include "generated/__savegprlr_23.inc"
#include "generated/__restgprlr_23.inc"
#include "generated/sub_82053A00.inc"

static void sub_82127778(Context& ctx, Machine& base) {
  // The only accepted checkpoint-016 call shape is sprintf-like "%i" used by
  // sub_8209CA70 to create its monotonically numbered startup label.
  if (ctx.r4.u32 != 0x8203DF98u ||
      base.load(ctx.r4.u32 + 0,1) != uint8_t('%') ||
      base.load(ctx.r4.u32 + 1,1) != uint8_t('i') ||
      base.load(ctx.r4.u32 + 2,1) != 0)
    base.fail(Error::unsupported, 0x82127778u);
  char rev[16]{};
  unsigned used=0;
  const int32_t sv=ctx.r5.s32;
  uint32_t mag = sv < 0 ? uint32_t(-int64_t(sv)) : uint32_t(sv);
  do { rev[used++]=char('0'+(mag%10)); mag/=10; } while(mag && used<sizeof(rev));
  uint32_t out=ctx.r3.u32;
  unsigned written=0;
  if (sv < 0) { base.store(out++,1,uint8_t('-')); ++written; }
  while (used) { base.store(out++,1,uint8_t(rev[--used])); ++written; }
  base.store(out,1,0);
  ctx.r3.u64=written;
}

#include "generated/sub_8209CA70.inc"
#include "generated/sub_820783E8.inc"
#include "generated/sub_8209C7A8.inc"
#include "generated/sub_8209C588.inc"
#include "generated/sub_82073ED0.inc"
#include "generated/sub_820745D8.inc"
#include "generated/sub_82053118.inc"
#include "generated/sub_82052EA8.inc"
#include "generated/sub_82075410.inc"

static void __imp__RtlInitializeCriticalSection(Context& ctx, Machine& base) {
  // Startup-prefix proof is single-threaded. The Xbox import receives a
  // 28-byte object here; initialize the owned bytes deterministically. Enter/
  // leave semantics are deliberately outside this checkpoint.
  const uint32_t p=ctx.r3.u32;
  if (p > 0xffffffe4u) base.fail(Error::context,p);
  for (unsigned i=0;i<28;++i) base.store(p+i,1,0);
  ctx.r3.u64=0;
}

#include "generated/sub_82095C20.inc"
#include "generated/sub_8209C340.inc"
#include "generated/sub_8209CED0.inc"
#include "generated/sub_82084BE8.inc"
#include "generated/sub_82079A00.inc"
#include "generated/sub_8207A0D0.inc"
#include "generated/sub_82079F38.inc"
#include "generated/sub_820867B8.inc"
#include "generated/sub_82086BA8.inc"
#include "generated/sub_820869B0.inc"
#include "generated/sub_82094C30.inc"
#include "generated/sub_82129FA0.inc"
#include "generated/sub_8208CFA0.inc"


// Deterministic console-region/platform shims used only by the startup locale
// constructor. They validate the observed call shapes rather than pretending to
// implement the wider Xbox APIs.
static void __imp__ExGetXConfigSetting(Context& ctx, Machine& base) {
  if (ctx.r3.u32 != 3u || ctx.r6.u32 != 4u)
    base.fail(Error::unsupported, 0x8214A554u);
  if (ctx.r5.u32 > 0xfffffffbu || ctx.r7.u32 > 0xfffffffdU)
    base.fail(Error::context, 0x8214A554u);
  if (ctx.r4.u32 == 9u) {
    base.store(ctx.r5.u32,4,0);
    base.store(ctx.r7.u32,2,4);
    ctx.r3.s64 = -1; // startup region fallback path
    return;
  }
  if (ctx.r4.u32 == 10u) {
    // This value is not consumed before the checkpoint-018 graphics boundary;
    // expose a deterministic zero-valued platform setting and the observed size.
    base.store(ctx.r5.u32,4,0);
    base.store(ctx.r7.u32,2,4);
    ctx.r3.s64 = 0;
    return;
  }
  base.fail(Error::unsupported, 0x8214A554u);
}
static void __imp__XGetGameRegion(Context& ctx, [[maybe_unused]] Machine& base) {
  // 0x101 is the original NTSC-U/US region code used by this deterministic fixture.
  ctx.r3.u64 = 0x101u;
}
static void __imp__XNotifyPositionUI(Context& ctx, Machine& base) {
  if (ctx.r3.u32 != 1u) base.fail(Error::unsupported, 0x8214A1F4u);
  ctx.r3.u64 = 0;
}

#include "generated/sub_820B6998.inc"
#include "generated/sub_8209F9F0.inc"
#include "generated/sub_8209D3D8.inc"
#include "generated/sub_8209D538.inc"
#include "generated/sub_82050170.inc"
#include "generated/sub_82050000.inc"
#include "generated/sub_8209D2D0.inc"
#include "generated/sub_8209F7E8.inc"

// Checkpoint 017 thread/platform boundary. The five startup workers are created
// suspended by the original code, assigned priority/affinity, then resumed.
// The host proof records that lifecycle as bounded scheduler state but does not
// execute the worker entry: sub_820B0E80 is an intentional infinite work loop.
static void __imp__ExCreateThread(Context& ctx, Machine& base) {
  const uint32_t out_handle=ctx.r3.u32;
  if (ctx.r6.u32 != 0x820B79B8u)
    base.fail(Error::unsupported, 0x8214A5E4u);
  if (ctx.r7.u32 == 0x820B0E80u) {
    if (ctx.r4.u32 != 0u || ctx.r5.u32 != 0u || ctx.r8.u32 >= 5u || ctx.r9.u32 != 1u ||
        base.thread_count != ctx.r8.u32 || base.thread_count >= 5u)
      base.fail(Error::unsupported, 0x8214A5E4u);
    auto &t=base.threads[base.thread_count];
    t.allocated=true; t.suspended=true; t.runnable=false;
    t.handle=0xF1000001u+base.thread_count; t.object=0xF2000001u+base.thread_count;
    t.startup_thunk=ctx.r6.u32; t.start_routine=ctx.r7.u32; t.parameter=ctx.r8.u32;
    t.priority=0; t.affinity=0x3fu; ++base.thread_count;
    base.store(out_handle,4,t.handle); ctx.r3.s64=0; return;
  }
  if (ctx.r7.u32 == 0x820D7578u) {
    static constexpr uint32_t records[2]={0x02002D5Cu,0x02002DACu};
    if (base.thread_count>=2u || ctx.r4.u32!=0x10000u || ctx.r9.u32!=0u ||
        ctx.r8.u32!=records[base.thread_count] || ctx.r5.u32!=ctx.r8.u32+52u)
      base.fail(Error::unsupported,0x8214A5E4u);
    auto &t=base.threads[base.thread_count];
    t.allocated=true; t.suspended=false; t.runnable=true;
    t.handle=0xF1000001u+base.thread_count; t.object=0xF2000001u+base.thread_count;
    t.startup_thunk=ctx.r6.u32; t.start_routine=ctx.r7.u32; t.parameter=ctx.r8.u32;
    t.priority=0; t.affinity=0x3fu; ++base.thread_count;
    base.store(out_handle,4,t.handle); ctx.r3.s64=0; return;
  }
  base.fail(Error::unsupported,0x8214A5E4u);
}
static void __imp__ObReferenceObjectByHandle(Context& ctx, Machine& base) {
  auto *t=base.by_handle(ctx.r3.u32);
  if (!t || ctx.r4.u32 != 0x0001001Bu || ctx.r5.u32 > 0xfffffffbu)
    base.fail(Error::unsupported, 0x8214A474u);
  base.store(ctx.r5.u32,4,t->object);
  ctx.r3.s64=0;
}
static void __imp__KeSetBasePriorityThread(Context& ctx, Machine& base) {
  auto *t=base.by_object(ctx.r3.u32);
  const bool startup=t && t->start_routine==0x820B0E80u && ctx.r4.s32==-1;
  const bool graphics=t && t->start_routine==0x820D7578u && ctx.r4.s32==17;
  if (!startup && !graphics) base.fail(Error::unsupported, 0x8214A464u);
  const int32_t old=t->priority; t->priority=ctx.r4.s32; ctx.r3.s64=old;
}
static void __imp__ObDereferenceObject(Context& ctx, Machine& base) {
  if (!base.by_object(ctx.r3.u32))
    base.fail(Error::unsupported, 0x8214A454u);
  ctx.r3.u64=0;
}
static void __imp__KeSetAffinityThread(Context& ctx, Machine& base) {
  auto *t=base.by_object(ctx.r3.u32);
  const uint32_t expected=t ? (1u << (t->parameter+1u)) : 0u;
  if (!t || ctx.r4.u32 != expected || ctx.r5.u32 > 0xfffffffbu)
    base.fail(Error::unsupported, 0x8214A484u);
  base.store(ctx.r5.u32,4,t->affinity);
  t->affinity=ctx.r4.u32;
  ctx.r3.s64=0;
}
static void __imp__NtResumeThread(Context& ctx, Machine& base) {
  auto *t=base.by_handle(ctx.r3.u32);
  if (!t || !t->suspended || ctx.r4.u32 > 0xfffffffbu)
    base.fail(Error::unsupported, 0x8214A4C4u);
  base.store(ctx.r4.u32,4,1u);
  t->suspended=false;
  t->runnable=true;
  ctx.r3.s64=0;
}

// Failure-only error translation path for the exact wrappers. Successful
// checkpoint-017 calls never enter it; a platform failure remains fail-closed.
static void sub_820B7290([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x820B7290u);
}

#include "generated/sub_820B7350.inc"
#include "generated/sub_820B73C0.inc"
#include "generated/sub_820B5D60.inc"
#include "generated/sub_820B5D70.inc"
#include "generated/sub_820B5E08.inc"
#include "generated/sub_820B6028.inc"
#include "generated/sub_8209D688.inc"
#include "generated/sub_820701D0_startup_full.inc"

// Checkpoint 017 caller-prefix closure. The original caller reaches this code
// only after the complete sub_820701D0 startup initializer. Unused branches in
// sub_8209A728 remain hard boundaries; the observed r3=0 path does not enter them.
#include "generated/__savegprlr_18.inc"
#include "generated/__restgprlr_18.inc"

#define HARD_BOUNDARY_017(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { \
    base.fail(Error::unsupported, addr); \
  }
static void __imp__RtlEnterCriticalSection(Context& ctx, Machine& base) {
  if (base.tile_allocator && ctx.r3.u32 == base.tile_allocator) {
    if (base.tile_cs_locked) base.fail(Error::unsupported,0x8214A434u);
    base.tile_cs_locked=true; ctx.r3.u64=0; return;
  }
  const uint32_t hsio_slot=uint32_t(base.load(0x82000594u,4));
  if (!hsio_slot || ctx.r3.u32!=hsio_slot || base.hsio_cs_locked || base.critical_region_depth!=1u)
    base.fail(Error::unsupported,0x8214A434u);
  base.hsio_cs_locked=true; ctx.r3.u64=0;
}
static void __imp__RtlLeaveCriticalSection(Context& ctx, Machine& base) {
  if (base.tile_allocator && ctx.r3.u32 == base.tile_allocator) {
    if (!base.tile_cs_locked) base.fail(Error::unsupported,0x8214A444u);
    base.tile_cs_locked=false; ctx.r3.u64=0; return;
  }
  const uint32_t hsio_slot=uint32_t(base.load(0x82000594u,4));
  if (!hsio_slot || ctx.r3.u32!=hsio_slot || !base.hsio_cs_locked || base.critical_region_depth!=1u)
    base.fail(Error::unsupported,0x8214A444u);
  base.hsio_cs_locked=false; ctx.r3.u64=0;
}
HARD_BOUNDARY_017(sub_821287B0, 0x821287B0u)
HARD_BOUNDARY_017(sub_82128A60, 0x82128A60u)
HARD_BOUNDARY_017(sub_820B00D8, 0x820B00D8u)
HARD_BOUNDARY_017(sub_820B0330, 0x820B0330u)
HARD_BOUNDARY_017(sub_820B0D80, 0x820B0D80u)
HARD_BOUNDARY_017(sub_820B6498, 0x820B6498u)
HARD_BOUNDARY_017(sub_820B02B0, 0x820B02B0u)
HARD_BOUNDARY_017(sub_820A7400, 0x820A7400u)
HARD_BOUNDARY_017(sub_820B0750, 0x820B0750u)
#undef HARD_BOUNDARY_017

#include "generated/sub_8209A728.inc"
#include "generated/sub_8209B458.inc"
#include "generated/sub_820A7668.inc"

// Adapter used by the diagnostic caller slice. The body it invokes is the exact
// original startup initializer already provenance-checked above.
static void sub_820701D0(Context& ctx, Machine& base) {
  sub_820701D0_startup_full(ctx, base);
}
#include "generated/sub_82070AC8_renderer_prefix.inc"

// PlatformRenderer::Init entry. The shim returns one deterministic standard
// 640x480/60-Hz mode descriptor; the exact original code consumes it and builds
// its presentation parameters. The prefix then stops immediately before the
// first graphics-device helper (sub_820BEFD0).
static void __imp__XGetVideoMode(Context& ctx, Machine& base) {
  const uint32_t p=ctx.r3.u32;
  if (p > 0xffffffd0u) base.fail(Error::context,0x8214A214u);
  for (unsigned i=0;i<48;++i) base.store(p+i,1,0);
  base.store(p+0,4,640u);
  base.store(p+4,4,480u);
  base.store(p+20,4,0x42700000u); // 60.0f
  base.store(p+24,4,1u);          // deterministic non-PAL standard token
  ctx.r3.u64=0;
}
#include "generated/sub_820A7990_platform_prefix.inc"
#include "generated/sub_820A7990_platform_post_graphics.inc"



// Checkpoint 019: graphics/runtime platform boundary. Game-side device/ring setup
// remains exact generated code; only loader/kernel/runtime contracts are modeled.
static void sub_82136670(Context& ctx, Machine& base) {
  ctx.r3.u64=base.graphics_allocate(ctx.r3.u32,ctx.r4.u32);
}
static void sub_82136708(Context& ctx, Machine& base) {
  // Fresh-object ring setup frees four null physical allocations. Non-null free
  // behavior is not observed before this checkpoint boundary.
  if (ctx.r3.u32 != 0u || ctx.r4.u32 != 0xB1800000u)
    base.fail(Error::unsupported,0x82136708u);
  ctx.r3.u64=0;
}
static void __imp__KeGetCurrentProcessType(Context& ctx, [[maybe_unused]] Machine& base) {
  ctx.r3.u64=1u; // normal title process, not the process-type-2 system path
}
static void __imp__VdInitializeEngines(Context& ctx, Machine& base) {
  if (base.graphics_engines_initialized || ctx.r3.u32!=0x1DDD0000u ||
      ctx.r4.u32!=0x820CB900u || ctx.r5.u32!=0u ||
      ctx.r6.u32!=0x82005820u || ctx.r7.u32!=0x82005CA0u)
    base.fail(Error::unsupported,0x8214A8A4u);
  base.graphics_engines_initialized=true; ctx.r3.u64=0;
}
static void __imp__ExRegisterTitleTerminateNotification(Context& ctx, Machine& base) {
  const uint32_t want = base.terminate_notifications==0 ? 0x821508E0u : 0x821508F0u;
  if (!base.graphics_engines_initialized || base.terminate_notifications>=2u ||
      ctx.r3.u32!=want || ctx.r4.u32!=1u)
    base.fail(Error::unsupported,0x8214A844u);
  ++base.terminate_notifications; ctx.r3.u64=0;
}
static void __imp__VdSetGraphicsInterruptCallback(Context& ctx, Machine& base) {
  if (!base.graphics_engines_initialized || base.terminate_notifications!=2u ||
      ctx.r3.u32!=0x820C60E0u || ctx.r4.u32<0x02000000u || ctx.r4.u32>=0x02240000u)
    base.fail(Error::unsupported,0x8214A894u);
  base.graphics_interrupt_installed=true; ctx.r3.u64=0;
}
static void __imp__VdSetSystemCommandBufferGpuIdentifierAddress(Context& ctx, Machine& base) {
  if (!base.system_identifier_cleared) {
    if (ctx.r3.u32!=0u) base.fail(Error::unsupported,0x8214A7F4u);
    base.system_identifier_cleared=true; ctx.r3.u64=0; return;
  }
  if (!base.ring_writeback_enabled || base.system_identifier_set ||
      !base.ring_descriptor || ctx.r3.u32!=base.ring_descriptor+8u)
    base.fail(Error::unsupported,0x8214A7F4u);
  base.system_identifier_set=true; ctx.r3.u64=0;
}
static void __imp__MmGetPhysicalAddress(Context& ctx, Machine& base) {
  if (base.graphics_alloc_index!=6u || !base.ring_virtual || ctx.r3.u32!=base.ring_virtual)
    base.fail(Error::unsupported,0x8214A7E4u);
  // The bounded fixture maps its graphics arena in low guest memory, so the
  // physical token is the low 29-bit address used by this original path.
  base.ring_physical=ctx.r3.u32 & 0x1FFFFFFFu;
  ctx.r3.u64=base.ring_physical;
}
static void __imp__VdInitializeRingBuffer(Context& ctx, Machine& base) {
  if (!base.graphics_engines_initialized || !base.ring_physical ||
      ctx.r3.u32!=base.ring_physical || ctx.r4.u32!=12u)
    base.fail(Error::unsupported,0x8214A7D4u);
  base.ring_initialized=true; ctx.r3.u64=0;
}
static void __imp__VdEnableRingBufferRPtrWriteBack(Context& ctx, Machine& base) {
  if (!base.ring_initialized || !base.ring_descriptor)
    base.fail(Error::unsupported,0x8214A7C4u);
  uint32_t q=base.ring_descriptor+60u;
  uint64_t t=__builtin_rotateleft64(uint64_t(q) | (uint64_t(q)<<32),12) & 0xFFFu;
  t=(t+512u) & 0xffffffffu;
  t=__builtin_rotateleft64(uint64_t(uint32_t(t)) | (uint64_t(uint32_t(t))<<32),0) & 0x1000u;
  const uint32_t want=uint32_t(t)+(q & 0x1FFFFFFFu);
  if (ctx.r3.u32!=want) base.fail(Error::unsupported,0x8214A7C4u);
  base.ring_writeback_enabled=true; ctx.r3.u64=0;
}

#define HARD_BOUNDARY_019(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, addr); }
HARD_BOUNDARY_019(sub_820C74D0,0x820C74D0u)
HARD_BOUNDARY_019(sub_820CC318,0x820CC318u)
HARD_BOUNDARY_019(sub_820BECA0,0x820BECA0u)
#include "generated/sub_820C7458.inc"
HARD_BOUNDARY_019(sub_820C7A98,0x820C7A98u)
#undef HARD_BOUNDARY_019

// Checkpoint 020: exact late device-finalization path. The game-side EDRAM
// routine is byte-exact generated code. Only the kernel/platform exports are
// modeled here, and only for the observed sub_820CC100 call shape. Xenia's
// Xbox 360 kernel model reports VdRetrainEDRAMWorker/VdRetrainEDRAM as zero
// and VdIsHSIOTrainingSucceeded as one; unexpected ordering/arguments fail.
static void __imp__KeEnterCriticalRegion(Context& ctx, Machine& base) {
  if (base.critical_region_depth!=0u || base.hsio_cs_locked || base.edram_retrain_calls!=0u)
    base.fail(Error::unsupported,0x8214A924u);
  base.critical_region_depth=1u; ctx.r3.u64=0;
}
static void __imp__KeLeaveCriticalRegion(Context& ctx, Machine& base) {
  const bool checkpoint020_complete =
      !base.edram_suffix021_shape && base.edram_worker_calls==1u &&
      base.edram_retrain_calls==1u;
  const bool suffix021_complete =
      base.edram_suffix021_shape && base.edram_worker_calls==0u &&
      base.edram_retrain_calls==1u;
  if (base.critical_region_depth!=1u || base.hsio_cs_locked ||
      (!checkpoint020_complete && !suffix021_complete))
    base.fail(Error::unsupported,0x8214A8F4u);
  base.critical_region_depth=0u; ctx.r3.u64=0;
}
static void __imp__VdRetrainEDRAMWorker(Context& ctx, Machine& base) {
  if (ctx.r3.u32!=0u || base.critical_region_depth!=1u || !base.hsio_cs_locked ||
      base.edram_worker_calls!=0u || base.edram_retrain_calls!=0u ||
      base.edram_suffix021_shape)
    base.fail(Error::unsupported,0x8214A914u);
  ++base.edram_worker_calls; ctx.r3.u64=0u;
}
static void __imp__VdRetrainEDRAM(Context& ctx, Machine& base) {
  const uint32_t sp=ctx.r1.u32;
  const bool checkpoint020_shape =
      ctx.r3.u32==1u && ctx.r4.u32==sp+80u && ctx.r5.u32==4096u &&
      ctx.r6.u32==sp+84u && ctx.r7.u32==sp+96u && ctx.r8.u32==2048u &&
      base.edram_worker_calls==1u && !base.edram_suffix021_shape;
  // WIP 021: bind the later PlatformRenderer::Init suffix invocation separately
  // rather than broadening the sealed Checkpoint 020 contract. This exact call
  // skips VdRetrainEDRAMWorker because sub_820C0DA8 passes r5=0 to sub_820D19E8.
  const bool suffix021_shape =
      sp==0x0003E210u && uint32_t(ctx.lr)==0x820D1A48u &&
      ctx.r3.u32==0u && ctx.r4.u32==0x0003E260u && ctx.r5.u32==4096u &&
      ctx.r6.u32==0x0003E264u && ctx.r7.u32==0x0003E270u && ctx.r8.u32==2048u &&
      ctx.r9.u32==0x02012320u && ctx.r10.u32==0x0201231Cu &&
      ctx.r11.u32==0u && ctx.r12.u32==0x820C1318u &&
      base.edram_worker_calls==0u && !base.edram_suffix021_shape;
  if (base.critical_region_depth!=1u || !base.hsio_cs_locked ||
      base.edram_retrain_calls!=0u || (!checkpoint020_shape && !suffix021_shape) ||
      uint32_t(base.load(ctx.r4.u32,4))!=0u || uint32_t(base.load(ctx.r6.u32,4))!=0u)
    base.fail(Error::unsupported,0x8214A904u);
  // The Xbox 360 kernel model returns zero and leaves the caller-owned output
  // words/workspace untouched. Zero selects the exact original success branch.
  base.edram_suffix021_shape=suffix021_shape;
  ++base.edram_retrain_calls; ctx.r3.u64=0u;
}
#include "generated/sub_820D19E8.inc"
#include "generated/sub_820BDE48.inc"
static void __imp__VdIsHSIOTrainingSucceeded(Context& ctx, Machine& base) {
  if (base.critical_region_depth!=0u || base.hsio_cs_locked ||
      base.edram_worker_calls!=1u || base.edram_retrain_calls!=1u ||
      base.hsio_status_calls!=0u)
    base.fail(Error::unsupported,0x8214A8B4u);
  ++base.hsio_status_calls; ctx.r3.u64=1u;
}
#include "generated/sub_820D1C08.inc"


// Checkpoint 019: deterministic VdQueryVideoMode contract for the exact
// 640x480/60 host platform fixture already consumed by PlatformRenderer::Init.
// The X_VIDEO_MODE layout is 48 bytes; only fields consumed on this path are
// populated. Unknown mode shapes remain fail-closed.
static void __imp__VdQueryVideoMode(Context& ctx, Machine& base) {
  const bool contiguous = !base.video_mode_queried && ctx.r3.u32 == 0x0003e5a0u;
  bool resumed = false;
  if (!contiguous && !base.video_mode_queried && base.video_flags_queried && base.system_command_buffer_queried &&
      base.vd_swap_called && base.display_mode_set && base.display_info_queried &&
      ctx.r1.u32==0x0003dec0u && ctx.lr==0x820D129Cu &&
      ctx.r3.u32==ctx.r1.u32+112u && ctx.r3.u32==0x0003df30u &&
      ctx.r28.u32==0x02000080u && ctx.r31.u32==0u &&
      ctx.r29.u32==0x028001e0u && ctx.r27.u32==0u &&
      ctx.r26.u32==0x050002d0u && ctx.r20.u32==0x028001e0u &&
      ctx.r15.u32==0x0003e084u && ctx.r14.u32==0x0003e0acu) {
    const uint32_t dev=ctx.r28.u32;
    resumed = uint32_t(base.load(dev+21544u,4))==1280u &&
              uint32_t(base.load(dev+21548u,4))==720u &&
              uint32_t(base.load(dev+21552u,4))==1280u;
  }
  // Exact later refresh performed by sub_820CF728. This is a second video-mode
  // query, so it is keyed to the complete observed suffix state rather than the
  // one-shot initialization form above.
  bool cf728_refresh = false;
  if (!contiguous && !resumed && base.video_mode_queried && base.video_flags_queried &&
      base.system_command_buffer_queried && base.vd_swap_called && base.display_mode_set &&
      base.display_info_queried && base.scaler_command_buffer_initialized &&
      ctx.r1.u32==0x0003e9e0u && ctx.lr==0x820CF77Cu &&
      ctx.r3.u32==0x02005548u && ctx.r31.u32==0x02000080u &&
      ctx.r24.u32==0u && ctx.r30.u32==0x02211000u &&
      ctx.r29.u32==0x28280106u && ctx.r28.u32==640u &&
      ctx.r27.u32==480u && ctx.r26.u32==0x0200361cu && ctx.r25.u32==0x02003b1cu) {
    const uint32_t dev=ctx.r31.u32;
    cf728_refresh = uint32_t(base.load(dev+21544u,4))==1280u &&
                    uint32_t(base.load(dev+21548u,4))==720u &&
                    uint32_t(base.load(dev+21552u,4))==1280u &&
                    uint32_t(base.load(dev+48u,4))==0x020122dcu;
  }
  if (!contiguous && !resumed && !cf728_refresh)
    base.fail(Error::unsupported,0x8214A7A4u);
  for (uint32_t i=0;i<48u;i+=4u) base.store(ctx.r3.u32+i,4,0u);
  base.store(ctx.r3.u32+0u,4,640u);
  base.store(ctx.r3.u32+4u,4,480u);
  base.store(ctx.r3.u32+20u,4,0x42700000u); // 60.0f
  if (resumed || cf728_refresh) base.store(ctx.r3.u32+28u,4,0x0000004au);
  base.video_mode_queried=true;
}


static void __imp__VdGetCurrentDisplayGamma(Context& ctx, Machine& base) {
  if (base.display_gamma_queried || ctx.r3.u32>0xfffffffbu || ctx.r4.u32>0xfffffffbu)
    base.fail(Error::unsupported,0x8214A814u);
  // Xbox contract: type 1 = sRGB. Power is ignored by this type, but the
  // deterministic platform fixture reports Xenia's documented default.
  base.store(ctx.r3.u32,4,1u);
  base.store(ctx.r4.u32,4,0x400e38e4u);
  base.display_gamma_queried=true;
  ctx.r3.u64=0u;
}

static void __imp__VdQueryVideoFlags(Context& ctx, Machine& base) {
  // The API query itself is valid independently of XGetVideoMode. Most earlier
  // device-init use runs in one Machine invocation and therefore carries the
  // video_mode_queried marker. WIP 021 resumes the still-live original caller
  // through a fresh host Machine while preserving guest memory, so accept only
  // that one exact resumed call shape as the equivalent durable state.
  if (base.video_flags_queried)
    base.fail(Error::unsupported,0x8214A8C4u);
  const bool contiguous = base.video_mode_queried;
  bool resumed = false;
  if (!contiguous && ctx.r1.u32==0x0003DF70u && ctx.lr==0x820CFD30u &&
      ctx.r26.u32==0x02000080u && ctx.r31.u32==0x0200361Cu &&
      ctx.r4.u32==640u && ctx.r5.u32==480u) {
    const uint32_t dev=ctx.r26.u32;
    resumed = uint32_t(base.load(dev+21544u,4))==1280u &&
              uint32_t(base.load(dev+21548u,4))==720u &&
              uint32_t(base.load(dev+21552u,4))==1280u;
  }
  if (!contiguous && !resumed)
    base.fail(Error::unsupported,0x8214A8C4u);
  base.video_flags_queried=true;
  // Exact observed path consumes only bit 0; the trusted standard-mode fixture
  // reports no special flag.
  ctx.r3.u64=0u;
}
static void __imp__VdCallGraphicsNotificationRoutines(Context& ctx, Machine& base) {
  const uint32_t p=ctx.r4.u32;
  if (base.graphics_notification_sent || ctx.r3.u32!=1u || p>0xffffffc0u)
    base.fail(Error::unsupported,0x8214A8D4u);
  const uint16_t w=uint16_t(base.load(p+0u,2)), h=uint16_t(base.load(p+2u,2));
  const uint16_t dw=uint16_t(base.load(p+4u,2)), dh=uint16_t(base.load(p+6u,2));
  if (w!=640u || h!=480u || dw!=640u || dh!=480u)
    base.fail(Error::unsupported,0x8214A8D4u);
  base.graphics_notification_sent=true;
  ctx.r3.u64=0u;
}

// sub_820D62F8 contains PPC atomic/global-lock operations absent from the
// reduced host Context. Model only its exact fresh 6,144-tile allocator
// behavior reached by the sealed presentation path; unexpected requests fail.
static void sub_820D62F8(Context& ctx, Machine& base) {
  const uint32_t request=ctx.r3.u32, out=ctx.r4.u32;
  if (!base.video_mode_queried || request!=240u || out>0xfffffffbu)
    base.fail(Error::unsupported,0x820D62F8u);
  if (!base.tile_allocator) {
    const uint32_t p=base.graphics_allocate(804u,0x64800000u);
    base.tile_allocator=p;
    for (uint32_t i=0;i<804u;++i) base.store(p+i,1,0u);
    base.store(p+28u,4,6144u);
    base.store(p+800u,4,0x55555555u);
    base.store(0x8223191cu,4,p);
  }
  if (base.tile_next>6144u-request) base.fail(Error::unsupported,0x820D62F8u);
  const uint32_t start=base.tile_next;
  for (uint32_t i=0;i<request;++i) {
    const uint32_t tile=start+i, a=base.tile_allocator+32u+(tile/32u)*4u;
    uint32_t w=uint32_t(base.load(a,4));
    w |= 0x80000000u >> (tile%32u);
    base.store(a,4,w);
  }
  base.tile_next+=request;
  base.store(base.tile_allocator+28u,4,6144u-base.tile_next);
  base.store(out,4,start);
  ctx.r3.u64=1u;
}

#define HARD_RESOURCE_BOUNDARY_019(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, addr); }
HARD_RESOURCE_BOUNDARY_019(sub_820D62A8,0x820D62A8u)
HARD_RESOURCE_BOUNDARY_019(sub_82136390,0x82136390u)
HARD_RESOURCE_BOUNDARY_019(sub_820C90E0,0x820C90E0u)
HARD_RESOURCE_BOUNDARY_019(sub_820BDD78,0x820BDD78u)
#undef HARD_RESOURCE_BOUNDARY_019

static void __imp__KiApcNormalRoutineNop(Context& ctx, Machine& base) {
  if (ctx.r4.u32!=19u || ctx.r3.u32>0xffffffb3u)
    base.fail(Error::unsupported,0x8214A7B4u);
  static constexpr uint32_t fixed[] = {
    0xC0114800u,1023u,0u,0u
  };
  for (unsigned i=0;i<4;++i)
    if (uint32_t(base.load(ctx.r3.u32+i*4,4))!=fixed[i])
      base.fail(Error::unsupported,0x8214A7B4u);
  // Words 4..11 are copied verbatim by original code from sealed image
  // 0x8200176C; validate the copy instead of inventing their meaning.
  for (unsigned i=0;i<8;++i) {
    uint32_t a=uint32_t(base.load(0x8200176Cu+i*4,4));
    uint32_t b=uint32_t(base.load(ctx.r3.u32+(4u+i)*4,4));
    if (a!=b) base.fail(Error::unsupported,0x8214A7B4u);
  }
  if (uint32_t(base.load(ctx.r3.u32+48,4))!=0x00010800u ||
      uint32_t(base.load(ctx.r3.u32+52,4))!=7u)
    base.fail(Error::unsupported,0x8214A7B4u);
  for (unsigned i=14;i<19;++i)
    if (base.load(ctx.r3.u32+i*4,4)!=0) base.fail(Error::unsupported,0x8214A7B4u);
  // Xbox kernel export 479 is named KiApcNormalRoutineNop in the generated
  // import table. The bounded contract is therefore no observable mutation.
}

#include "generated/sub_82136728.inc"
#include "generated/sub_820BEF28.inc"
#include "generated/sub_820BEF80.inc"
#include "generated/sub_820CC088.inc"
#include "generated/sub_820CBFF0.inc"
#include "generated/sub_820C5EE8.inc"
#include "generated/sub_820C5F98.inc"
#include "generated/sub_820C73F0.inc"
#include "generated/sub_820C7548.inc"
#include "generated/sub_820BEAC8.inc"
#include "generated/sub_820D7708.inc"
#include "generated/__savegprlr_17.inc"
#include "generated/__restgprlr_17.inc"
#include "generated/sub_820BF5E0.inc"
#include "generated/sub_820BF8D0.inc"
#include "generated/sub_820BF930.inc"
#include "generated/sub_820D7920.inc"

#include "generated/__savegprlr_14.inc"
#include "generated/__restgprlr_14.inc"
#include "generated/__savegprlr_16.inc"
#include "generated/__restgprlr_16.inc"
#include "generated/sub_820C2EF8.inc"
#include "generated/sub_820C2F80.inc"
#include "generated/sub_820C2E60.inc"
#include "generated/sub_820C30A0.inc"
#include "generated/sub_820C2DF0.inc"
#include "generated/sub_820C3EF8.inc"
#include "generated/sub_820C4210.inc"
#include "generated/sub_820C44A0.inc"
#include "generated/sub_820C45C0.inc"
#include "generated/__savefpr_26.inc"
#include "generated/__restfpr_26.inc"
#include "generated/sub_820BB3B8.inc"
#include "generated/sub_820BD978.inc"
#include "generated/sub_820BDF40.inc"
#include "generated/sub_820BE1A8.inc"
#include "generated/sub_820BE248.inc"
#include "generated/sub_820BE2D8.inc"
#include "generated/sub_820BE620.inc"
#include "generated/sub_820CFD98.inc"
#include "generated/sub_820CFC70.inc"
#include "generated/sub_820CFE10.inc"
#include "generated/sub_820D1938.inc"
#include "generated/sub_820D19B8.inc"
#include "generated/__savefpr_28.inc"
#include "generated/__restfpr_28.inc"
#include "generated/sub_8212AA90.inc"
#include "generated/sub_82130550.inc"
#include "generated/sub_8212DEE8.inc"
#include "generated/sub_8212DE48.inc"
#include "generated/sub_8212B1A8.inc"
#include "generated/sub_8212DE20.inc"
#include "generated/sub_8212AB00.inc"
#include "generated/sub_8212AC88.inc"
#include "generated/sub_820C8A90.inc"
#include "generated/sub_820C8B40.inc"
#include "generated/sub_820C8BF0.inc"
#include "generated/sub_820C8D78.inc"
#include "generated/sub_820C9090.inc"
#include "generated/sub_820BDCA8.inc"
#include "generated/sub_820CBBF0.inc"
#include "generated/sub_820CC100.inc"
#include "generated/sub_820BEFD0.inc"

// Checkpoint 020 exact GPU-state setter fanout and adjacent helpers.
#include "generated/sub_820BB6A8.inc"
#include "generated/sub_820BB6D8.inc"
#include "generated/sub_820BB708.inc"
#include "generated/sub_820BB740.inc"
#include "generated/sub_820BB7D0.inc"
#include "generated/sub_820BB860.inc"
#include "generated/sub_820BB8F0.inc"
#include "generated/sub_820BB980.inc"
#include "generated/sub_820BB9F0.inc"
#include "generated/sub_820BBA60.inc"
#include "generated/sub_820BBAD0.inc"
#include "generated/sub_820BBB68.inc"
#include "generated/sub_820BBBC8.inc"
#include "generated/sub_820BBBF8.inc"
#include "generated/sub_820BBCF8.inc"
#include "generated/sub_820BBD30.inc"
#include "generated/sub_820BBDA0.inc"
#include "generated/sub_820BBDD0.inc"
#include "generated/sub_820BBE10.inc"
#include "generated/sub_820BBE40.inc"
#include "generated/sub_820BBE78.inc"
#include "generated/sub_820BBEB8.inc"
#include "generated/sub_820BBEF0.inc"
#include "generated/sub_820BBF20.inc"
#include "generated/sub_820BBF58.inc"
#include "generated/sub_820BBF90.inc"
#include "generated/sub_820BBFC0.inc"
#include "generated/sub_820BBFF0.inc"
#include "generated/sub_820BC028.inc"
#include "generated/sub_820BC060.inc"
#include "generated/sub_820BC090.inc"
#include "generated/sub_820BC0B0.inc"
#include "generated/sub_820BC0D0.inc"
#include "generated/sub_820BC0F0.inc"
#include "generated/sub_820BC110.inc"
#include "generated/sub_820BC130.inc"
#include "generated/sub_820BC150.inc"
#include "generated/sub_820BC1A8.inc"
#include "generated/sub_820BC270.inc"
#include "generated/sub_820BC318.inc"
#include "generated/sub_820BC348.inc"
#include "generated/sub_820BC368.inc"
#include "generated/sub_820BC3A8.inc"
#include "generated/sub_820BC3E8.inc"
#include "generated/sub_820BC428.inc"
#include "generated/sub_820BC468.inc"
#include "generated/sub_820BC478.inc"
#include "generated/sub_820BC4D0.inc"
#include "generated/sub_820BC520.inc"
#include "generated/sub_820BC570.inc"
#include "generated/sub_820BC590.inc"
#include "generated/sub_820BC5B8.inc"
#include "generated/sub_820BC5E0.inc"
#include "generated/sub_820BC608.inc"
#include "generated/sub_820BC630.inc"
#include "generated/sub_820BC658.inc"
#include "generated/sub_820BC680.inc"
#include "generated/sub_820BC6A0.inc"
#include "generated/sub_820BC6C0.inc"
#include "generated/sub_820BC6E8.inc"
#include "generated/sub_820BC710.inc"
#include "generated/sub_820BC738.inc"
#include "generated/sub_820BC760.inc"
#include "generated/sub_820BC788.inc"
#include "generated/sub_820BC7B0.inc"
#include "generated/sub_820BC8D0.inc"
#include "generated/sub_820BC920.inc"
#include "generated/sub_820BC9B8.inc"
#include "generated/sub_820BCA50.inc"
#include "generated/sub_820BCAE8.inc"
#include "generated/sub_820BCB80.inc"
#include "generated/sub_820BCBB8.inc"
#include "generated/sub_820BCBF0.inc"
#include "generated/sub_820BCC28.inc"
#include "generated/sub_820BCC60.inc"
#include "generated/sub_820BCC90.inc"
#include "generated/sub_820BCCB8.inc"
#include "generated/sub_820BCCE8.inc"
#include "generated/sub_820BCD20.inc"
#include "generated/sub_820BCD50.inc"
#include "generated/sub_820BCD80.inc"
#include "generated/sub_820BCDA8.inc"
#include "generated/sub_820BCDD8.inc"
#include "generated/sub_820BCE08.inc"
#include "generated/sub_820BCE70.inc"
#include "generated/sub_820BCEA0.inc"
#include "generated/sub_820BCED0.inc"
#include "generated/sub_820BCF00.inc"
#include "generated/sub_820BCF20.inc"
#include "generated/sub_820BCF30.inc"
#include "generated/sub_820BCF50.inc"
#include "generated/sub_820BD050.inc"
#include "generated/sub_820BD0F8.inc"
#include "generated/sub_820BD1F8.inc"
#include "generated/sub_820BD298.inc"
#include "generated/sub_820BD2F0.inc"
#include "generated/sub_820BD398.inc"
#include "generated/sub_820BD410.inc"
#include "generated/sub_820BD4B8.inc"
#include "generated/sub_820BD558.inc"
#include "generated/sub_820BD5D8.inc"
#include "generated/sub_820BD658.inc"
#include "generated/sub_820BD6C8.inc"
#include "generated/sub_820BD718.inc"
#include "generated/sub_820BD768.inc"
#include "generated/sub_820BD7B8.inc"
#include "generated/sub_820BD810.inc"
#include "generated/sub_820BD868.inc"
#include "generated/sub_820BD8C0.inc"
#include "generated/sub_820BD918.inc"
#include "generated/sub_820BE198.inc"
#include "generated/sub_820CB988.inc"
#include "generated/sub_820C46F8.inc"
#include "generated/sub_820C9150.inc"
#include "generated/sub_820C0530.inc"
#include "generated/sub_820C0248.inc"
#include "generated/sub_820BF0A8.inc"
#include "generated/sub_820BF7B8.inc"

// Checkpoint 020 reduced-host implementation of exact sub_820C6088 semantics.
// The generated body uses PPC ldarx/stdcx plus MSR/global-lock helpers that the
// reduced Context intentionally does not model. On this single-threaded host
// fixture its observable contract is an atomic 64-bit exchange with
// 0x00000000FFFFFFFF, returning the old low/high words through r4/r5.
static void sub_820C6088(Context& ctx, Machine& base) {
  base.prologue(__func__,ctx);
  const uint32_t src=ctx.r3.u32, lo=ctx.r4.u32, hi=ctx.r5.u32;
  if (src>0xfffffff7u || lo>0xfffffffbu || hi>0xfffffffbu)
    base.fail(Error::context,0x820C6088u);
  const uint64_t old=base.load(src,8);
  base.store(src,8,0x00000000FFFFFFFFull);
  base.store(lo,4,uint32_t(old));
  base.store(hi,4,uint32_t(old>>32));
  ctx.r9.u64=old;
  ctx.r10.u64=old;
  ctx.r11.u64=uint32_t(old>>32);
}

// Compile-time fail-closed imports used only by deeper branches of this exact
// command-buffer family. A branch reaching one must establish its observed
// platform/CRT contract before execution can proceed.
static void __imp__KeDelayExecutionThread([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A614u); }
static void __imp__KfReleaseSpinLock([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A744u); }
static void __imp__KfAcquireSpinLock([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A754u); }
static void __imp___vsnprintf([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A834u); }
static void __imp__DbgPrint([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A5A4u); }
static void __imp__sprintf([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A804u); }

static uint32_t checkpoint020_mm_load_u32(Machine& base, uint32_t a) {
  if (a>=0x7F000000u && a<0x80000000u) base.fail(Error::unsupported,a);
  return uint32_t(base.load(a,4));
}
static void checkpoint020_mm_store_u32(Machine& base, uint32_t a, uint32_t v) {
  if (a>=0x7F000000u && a<0x80000000u) {
    // Observed CP_RB_WPTR write: Xenos MMIO base 0x7FC80000 + register 0x714.
    // The current ring has 8192 dwords, so reject any unobserved/out-of-ring value.
    if (a!=0x7FC80714u || v>=8192u) base.fail(Error::unsupported,a);
    base.cp_rb_wptr=v; ++base.cp_rb_wptr_writes; return;
  }
  base.store(a,4,v);
}
#define REX_MM_LOAD_U32(a) checkpoint020_mm_load_u32(base,uint32_t(a))
#define REX_MM_STORE_U32(a,v) checkpoint020_mm_store_u32(base,uint32_t(a),uint32_t(v))
#define REX_QUERY_TIMEBASE() base.query_timebase()
// Checkpoint 020 exact command-buffer / flush family from sub_820C7228.
#include "generated/__restgprlr_19.inc"
#include "generated/__savegprlr_19.inc"
#include "generated/sub_820B6068.inc"
#include "generated/sub_820B74B0.inc"
#include "generated/sub_820BE8F8.inc"
#include "generated/sub_820BE928.inc"
#include "generated/sub_820BE9F0.inc"
#include "generated/sub_820C5E50.inc"
#include "generated/sub_820C6178.inc"
#include "generated/sub_820C6218.inc"
#include "generated/sub_820C6290.inc"
#include "generated/sub_820C64C0.inc"
#include "generated/sub_820C65A8.inc"
#include "generated/sub_820C6790.inc"
#include "generated/sub_820C6950.inc"
#include "generated/sub_820C6A40.inc"
#include "generated/sub_820C6B18.inc"
#include "generated/sub_820C6E68.inc"
#include "generated/sub_820C6F68.inc"
#include "generated/sub_820C70A0.inc"
#include "generated/sub_820C7228.inc"
#include "generated/sub_820C7988.inc"
#include "generated/sub_820C7B48.inc"
#include "generated/sub_820C7BF8.inc"
#include "generated/sub_820CB088.inc"
#include "generated/sub_820CB108.inc"
#include "generated/sub_820CB370.inc"
#include "generated/sub_820CB468.inc"
#include "generated/sub_820CB7F8.inc"
#include "generated/sub_820CCB40.inc"
#include "generated/sub_820D6470.inc"
#include "generated/sub_82128830.inc"

#undef REX_QUERY_TIMEBASE // checkpoint020-c7228
#undef REX_MM_STORE_U32
#undef REX_MM_LOAD_U32

// Checkpoint 020 late device finalization exact bodies.
#include "generated/sub_820CDD68.inc"

// Checkpoint 021 focused PlatformRenderer::Init suffix probe. Specialized
// adjacent helpers remain fail-closed until the observed sub_820C1F58 branch
// proves they are needed.
static void sub_8212A8B8([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8212A8B8u); }
static void sub_820C48C8([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C48C8u); }
#include "generated/sub_820C4AF8.inc"
#include "generated/sub_820C19C8.inc"
#include "generated/sub_820C1CB8.inc"
#include "generated/sub_820D4298.inc"
#include "generated/sub_820C1F58.inc"
#include "generated/sub_820D3FE8.inc"
#include "generated/sub_820D4630.inc"
#include "generated/sub_820C24C0.inc"
#include "generated/sub_820C2B70.inc"
#include "generated/sub_820C2C98.inc"

// WIP 021: exact next PlatformRenderer::Init suffix body and the first
// adjacent command-state chain actually reached from it. Later direct callees
// remain fail-closed until execution proves they are required.
#include "generated/sub_820CDFB0.inc"
#include "generated/sub_820CC568.inc"
#include "generated/sub_820C6BE8.inc"
#include "generated/sub_820C08B8.inc"
static void sub_820C3A30([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C3A30u); }
#include "generated/sub_820C4878.inc"
static void sub_820C49D8([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C49D8u); }
static void sub_820C4F20([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C4F20u); }
#include "generated/sub_820C4FF8.inc"
#include "generated/sub_820BE228.inc"
// WIP 021: exact opening of the presentation/swap path.  All adjacent
// helpers/platform imports not yet proven on the observed path stay fail-closed.
static void sub_820D3B88([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D3B88u); }
static void sub_820D2E58([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D2E58u); }
static void sub_820D3280([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D3280u); }
#include "generated/sub_820D3EF8.inc"

#include "generated/sub_820CDF20.inc"
// WIP 021: exact post-swap display-mode/display-info helper. Platform imports
// remain fail-closed until this exact observed call shape reaches them.
static void __imp__VdSetDisplayMode(Context& ctx, Machine& base) {
  if (!base.vd_swap_called || base.display_mode_set || ctx.r3.u32 != 0x40000000u)
    base.fail(Error::unsupported, 0x8214A884u);
  base.display_mode_set = true;
  ctx.r3.u64 = 0u;
}
// WIP 021: one-shot observed VdGetCurrentDisplayInformation contract. The
// exact post-swap caller provides a stack-local 0x58-byte X_DISPLAY_INFO.
// Trusted kernel-model evidence zeroes the block and reports its current
// 1280x720 mode. Only the three fields consumed by exact sub_820CBF48 are
// populated here; every other call order/pointer remains fail-closed.
static void __imp__VdGetCurrentDisplayInformation(Context& ctx, Machine& base) {
  if (!base.vd_swap_called || !base.display_mode_set || base.display_info_queried ||
      ctx.r1.u32 != 0x0003E9E0u || ctx.r3.u32 != ctx.r1.u32 + 80u ||
      ctx.r3.u32 != 0x0003EA30u)
    base.fail(Error::unsupported, 0x8214A874u);
  const uint32_t p = ctx.r3.u32;
  if (p > 0xFFFFFFA7u)
    base.fail(Error::context, 0x8214A874u);
  for (uint32_t i = 0; i < 0x58u; i += 4u)
    base.store(p + i, 4, 0u);
  // X_DISPLAY_INFO offsets consumed by exact sub_820CBF48.
  base.store(p + 0x48u, 2, 1280u);  // display_width
  base.store(p + 0x4Au, 2, 720u);   // display_height
  base.store(p + 0x56u, 2, 1280u);  // actual_display_width
  base.display_info_queried = true;
  ctx.r3.u64 = 0u;
}
#include "generated/sub_820CBF48.inc"
#include "generated/sub_820C0BC0.inc"
// WIP 021: exact sub_820D1788; adjacent unobserved edges remain fail-closed.
#include "generated/sub_820D0008.inc"
static void sub_820D0238([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D0238u); }
static void sub_820D0720([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D0720u); }
static void sub_820D0898([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D0898u); }
static void sub_820D08F0([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D08F0u); }
#include "generated/sub_820D09F8.inc"
#include "generated/__savefpr_22.inc"
#include "generated/__restfpr_22.inc"
#include "generated/sub_820D0B00.inc"
#include "generated/sub_82129EF8.inc"
#include "generated/sub_820D02C0.inc"
#include "generated/sub_820D0F80.inc"
#include "generated/sub_820D1260.inc"
// WIP 021: exact observed Xbox kernel RtlFillMemoryUlong contract reached by
// exact sub_820D1788. Xbox/Xenia RTL semantics fill Length>>2 ULONGs with the
// supplied guest-endian pattern. This diagnostic shim accepts only the single
// observed aligned stack-local call and rejects every other shape.
static void __imp__RtlFillMemoryUlong(Context& ctx, Machine& base) {
  constexpr uint32_t kDestination = 0x0003E0D0u;
  constexpr uint32_t kLength = 800u;
  constexpr uint32_t kPattern = 0x80000000u;
  if (ctx.r1.u32 != 0x0003E010u || ctx.r3.u32 != kDestination ||
      ctx.r3.u32 != ctx.r1.u32 + 192u || ctx.r4.u32 != kLength ||
      ctx.r5.u32 != kPattern || (ctx.r3.u32 & 3u) || (ctx.r4.u32 & 3u))
    base.fail(Error::unsupported, 0x8214A6C4u);
  if (base.memory.check(kDestination, kLength, cc::xbox::write_access) !=
      cc::xbox::MemoryError::ok)
    base.fail(Error::memory, kDestination);
  for (uint32_t i = 0; i < kLength; i += 4u)
    base.store(kDestination + i, 4, kPattern);
}
// WIP 021: one-shot observed VdInitializeScalerCommandBuffer contract reached
// by exact sub_820D1788. Xenia's Xbox 360 kernel model exposes the same
// 12-argument ABI and, for this import, fills dest_count words at dest_ptr with
// type-2 GPU NOP 0x80000000 and returns dest_count. Model only the exact Castle
// Crashers call shape observed here; every other stack/register/order shape is
// fail-closed.
static void __imp__VdInitializeScalerCommandBuffer(Context& ctx, Machine& base) {
  constexpr uint32_t kStack = 0x0003E010u;
  constexpr uint32_t kVerticalParams = kStack + 156u;
  constexpr uint32_t kHorizontalParams = kStack + 172u;
  constexpr uint32_t kUnknownBlock = kStack + 992u;
  constexpr uint32_t kDestination = kStack + 192u;
  constexpr uint32_t kCount = 200u;
  if (!base.vd_swap_called || !base.display_mode_set || !base.display_info_queried ||
      base.scaler_command_buffer_initialized || ctx.r1.u32 != kStack ||
      ctx.r3.u32 != 0x00000000u || ctx.r4.u32 != 0x028001E0u ||
      ctx.r5.u32 != 0x00000000u || ctx.r6.u32 != 0x050002D0u ||
      ctx.r7.u32 != 0x028001E0u || ctx.r8.u32 != 1u ||
      ctx.r9.u32 != kVerticalParams || ctx.r10.u32 != 1u ||
      base.load(kStack + 84u,4) != kHorizontalParams ||
      base.load(kStack + 92u,4) != kUnknownBlock ||
      base.load(kStack + 100u,4) != kDestination ||
      base.load(kStack + 108u,4) != kCount)
    base.fail(Error::unsupported, 0x8214A8E4u);
  if (base.memory.check(kDestination, kCount * 4u, cc::xbox::write_access) !=
      cc::xbox::MemoryError::ok)
    base.fail(Error::memory, kDestination);
  for (uint32_t i=0; i<kCount; ++i)
    base.store(kDestination + i*4u, 4, 0x80000000u);
  base.scaler_command_buffer_initialized = true;
  ctx.r3.u64 = kCount;
}
#include "generated/sub_820D1788.inc"
#include "generated/sub_820C0A98.inc"
#include "generated/sub_820C8E98.inc"
static void sub_820C8F90([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C8F90u); }
#include "generated/sub_820C0580.inc"
static void sub_820C0B40([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C0B40u); }
static void sub_820CF038([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820CF038u); }
#include "generated/sub_820CF728.inc"
// WIP 021: exact sub_820CF9D0 recovered byte-for-byte. Adjacent direct
// callees remain hard boundaries until the exact observed branch reaches them.
static void sub_820CE088([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820CE088u); }
static void sub_820C91C0([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C91C0u); }
static void sub_820C9348([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C9348u); }
static void sub_820C9968([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C9968u); }
// WIP 021: exact sub_820CF858 and its observed first direct callee
// sub_821368C0 are both recovered byte-for-byte. The observed loader state makes
// sub_821368C0 return zero, so CF858 skips sub_820CD258; keep that later
// conditional callee fail-closed until an exact path actually reaches it.
#include "generated/sub_821368C0.inc"
static void sub_820CD258([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820CD258u); }
#include "generated/sub_820CF858.inc"
#define REX_QUERY_TIMEBASE() base.query_timebase()
#include "generated/sub_820CF9D0.inc"
#undef REX_QUERY_TIMEBASE
// WIP 021: one-shot observed VdGetSystemCommandBuffer contract. The exact
// caller supplies two stack output locations. Trusted Xbox 360 kernel-model
// evidence used by this project reports a 0x94-byte system-command block whose
// first dword is 0xBEEF0000 plus companion dword 0xBEEF0001. Model only this
// exact call shape and fail closed on every other invocation.
static void __imp__VdGetSystemCommandBuffer(Context& ctx, Machine& base) {
  if (base.system_command_buffer_queried || ctx.r1.u32!=0x0003EAA0u ||
      ctx.r3.u32!=ctx.r1.u32+208u || ctx.r4.u32!=ctx.r1.u32+116u)
    base.fail(Error::unsupported,0x8214A784u);
  const uint32_t p0=ctx.r3.u32, p1=ctx.r4.u32;
  if (p0>0xffffff6bu || p1>0xfffffffbu)
    base.fail(Error::context,0x8214A784u);
  for (uint32_t i=0;i<0x94u;i+=4u) base.store(p0+i,4,0u);
  base.store(p0,4,0xBEEF0000u);
  base.store(p1,4,0xBEEF0001u);
  base.system_command_buffer_queried=true;
  ctx.r3.u64=0u;
}
// WIP 021: one-shot observed VdSwap contract. Xenia's Xbox 360 kernel model
// validates the D3D texture-header fetch, front-buffer metadata and 640x480
// dimensions, then writes a 64-dword swap command block. This host fixture has
// no kernel MMU/physical mapper, so only the observed low-memory identity map
// (frontbuffer virtual == deterministic fixture physical) is accepted.
static void __imp__VdSwap(Context& ctx, Machine& base) {
  if (!base.system_command_buffer_queried || base.vd_swap_called ||
      ctx.r1.u32 != 0x0003EAA0u || ctx.r3.u32 != 0x0200F950u ||
      ctx.r4.u32 != 0x0003EB20u || ctx.r5.u32 != 0x0220F148u ||
      ctx.r6.u32 != 0x0003EB70u || ctx.r7.u32 != 0xBEEF0001u ||
      ctx.r8.u32 != 0x0003EB0Cu || ctx.r9.u32 != 0x0003EB10u ||
      ctx.r10.u32 != 0x0003EB08u)
    base.fail(Error::unsupported, 0x8214A774u);

  const uint32_t width_ptr = uint32_t(base.load(ctx.r1.u32 + 84u, 4));
  const uint32_t height_ptr = uint32_t(base.load(ctx.r1.u32 + 92u, 4));
  if (width_ptr != ctx.r1.u32 + 96u || height_ptr != ctx.r1.u32 + 100u)
    base.fail(Error::unsupported, 0x8214A774u);

  uint32_t fetch[6]{};
  for (uint32_t i = 0; i < 6u; ++i)
    fetch[i] = uint32_t(base.load(ctx.r4.u32 + i * 4u, 4));

  const uint32_t frontbuffer = uint32_t(base.load(ctx.r8.u32, 4));
  const uint32_t texture_format = uint32_t(base.load(ctx.r9.u32, 4));
  const uint32_t color_space = uint32_t(base.load(ctx.r10.u32, 4));
  const uint32_t width = uint32_t(base.load(width_ptr, 4));
  const uint32_t height = uint32_t(base.load(height_ptr, 4));
  const uint32_t sys0 = uint32_t(base.load(ctx.r6.u32, 4));
  const uint32_t sys1 = uint32_t(base.load(ctx.r1.u32 + 116u, 4));

  const uint32_t fetch_frontbuffer = ((fetch[1] >> 12) & 0xFFFFFu) << 12;
  const uint32_t fetch_width = (fetch[2] & 0x1FFFu) + 1u;
  const uint32_t fetch_height = ((fetch[2] >> 13) & 0x1FFFu) + 1u;
  if (fetch[0] != 0x85000002u || fetch[1] != 0x02211006u ||
      fetch[2] != 0x003BE27Fu || fetch[3] != 0x00001414u ||
      fetch[4] != 0u || fetch[5] != 0x00000200u ||
      fetch_frontbuffer != 0x02211000u || frontbuffer != fetch_frontbuffer ||
      texture_format != 6u || (fetch[1] & 0x3Fu) != texture_format ||
      color_space != 0u || width != 640u || height != 480u ||
      width != fetch_width || height != fetch_height ||
      sys0 != 0xBEEF0000u || sys1 != 0xBEEF0001u)
    base.fail(Error::unsupported, 0x8214A774u);

  // Final 64-dword block matching the trusted kernel model for this exact
  // observed call. The fixture's deterministic low address is used unchanged
  // as the platform physical address; this is not a general Xbox MMU model.
  const uint32_t buffer = ctx.r3.u32;
  base.store(buffer + 0u * 4u, 4, 0x00054800u);  // type0 FETCH_00_0, 6 dwords
  for (uint32_t i = 0; i < 6u; ++i)
    base.store(buffer + (1u + i) * 4u, 4, fetch[i]);
  base.store(buffer + 7u * 4u, 4, 0xC0036400u);  // type3 XE_SWAP, 4 dwords
  base.store(buffer + 8u * 4u, 4, 0x53574150u);  // 'SWAP'
  base.store(buffer + 9u * 4u, 4, frontbuffer);  // identity only for this fixture
  base.store(buffer + 10u * 4u, 4, width);
  base.store(buffer + 11u * 4u, 4, height);
  for (uint32_t i = 12u; i < 64u; ++i)
    base.store(buffer + i * 4u, 4, 0x80000000u);  // type2 NOP

  base.vd_swap_called = true;
}
static void __imp__VdPersistDisplay(Context& ctx, Machine& base) {
  // Xenia's xboxkrnl model for this Xbox 360 export returns TRUE and writes a
  // 64-byte, 32-byte-aligned no-access allocation through its second argument;
  // the exact Castle Crashers caller immediately passes that token to
  // MmFreePhysicalMemory(1, token). Bind only the single observed call shape.
  if (base.persist_display_called || !base.vd_swap_called ||
      ctx.r1.u32 != 0x0003EAA0u || uint32_t(ctx.lr) != 0x820C12E4u ||
      ctx.r3.u32 != 0x0003EB58u || ctx.r4.u32 != 0x0003EB40u ||
      ctx.r5.u32 != 0u || ctx.r6.u32 != 0x02211000u ||
      ctx.r7.u32 != 0x020122ECu || ctx.r8.u32 != 0x0003EB58u ||
      ctx.r9.u32 != 0xFFFFFFFEu || ctx.r10.u32 != 0x00001E4Eu)
    base.fail(Error::unsupported,0x8214A764u);

  // Exact caller code cleared this 12-byte input block before the import.
  if (base.load(ctx.r3.u32 + 0u, 4) != 0u ||
      base.load(ctx.r3.u32 + 4u, 4) != 0u ||
      base.load(ctx.r3.u32 + 8u, 4) != 0u)
    base.fail(Error::unsupported,0x8214A764u);

  // The platform allocation is deliberately represented as an opaque,
  // deterministic no-access token in the diagnostic fixture. The address is
  // 32-byte aligned and is not mapped as guest-readable/writable memory.
  constexpr uint32_t token = 0x02600000u;
  base.persist_display_called = true;
  base.persist_display_allocation = token;
  base.store(ctx.r4.u32, 4, token);
  ctx.r3.u64 = 1u;
}
static void __imp__MmFreePhysicalMemory(Context& ctx, Machine& base) {
  // Bind only the physical allocation created by the immediately preceding
  // observed VdPersistDisplay call. The trusted xboxkrnl contract requires a
  // 32-byte-aligned address and releases that allocation; this diagnostic
  // fixture represents it as an opaque no-access token rather than mapped
  // guest memory.
  if (!base.persist_display_called || base.persist_display_freed ||
      base.persist_display_allocation != 0x02600000u ||
      ctx.r1.u32 != 0x0003EAA0u || uint32_t(ctx.lr) != 0x820C12F8u ||
      ctx.r3.u32 != 1u || ctx.r4.u32 != base.persist_display_allocation ||
      ctx.r5.u32 != 0u || ctx.r6.u32 != 0x02211000u ||
      ctx.r7.u32 != 0x020122ECu || ctx.r8.u32 != 0x0003EB58u ||
      ctx.r9.u32 != 0xFFFFFFFEu || ctx.r10.u32 != 0x00001E4Eu ||
      (ctx.r4.u32 & 0x1Fu) != 0u ||
      base.memory.check(ctx.r4.u32, 64u, 1u) == cc::xbox::MemoryError::ok)
    base.fail(Error::unsupported,0x8214A504u);

  base.persist_display_freed = true;
  base.persist_display_allocation = 0u;
}

#include "generated/sub_820C0DA8.inc"
#include "generated/sub_820C13B8.inc"
