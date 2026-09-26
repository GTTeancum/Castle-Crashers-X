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
HARD_BOUNDARY(sub_82099A80, 0x82099A80u)
HARD_BOUNDARY(sub_82099968, 0x82099968u)
HARD_BOUNDARY(sub_82097AC8, 0x82097AC8u)
HARD_BOUNDARY(sub_82099680, 0x82099680u)
HARD_BOUNDARY(sub_820B0F18, 0x820B0F18u)
HARD_BOUNDARY(sub_82084BE8, 0x82084BE8u)
HARD_BOUNDARY(sub_82053A00, 0x82053A00u)
HARD_BOUNDARY(sub_82084D18, 0x82084D18u)
HARD_BOUNDARY(sub_82084DB8, 0x82084DB8u)
HARD_BOUNDARY(sub_820A71E8, 0x820A71E8u)
HARD_BOUNDARY(sub_820B5EB8, 0x820B5EB8u)
HARD_BOUNDARY(sub_8209BDD8, 0x8209BDD8u)
HARD_BOUNDARY(sub_8209BF18, 0x8209BF18u)
HARD_BOUNDARY(sub_82086010, 0x82086010u)
HARD_BOUNDARY(sub_82084C78, 0x82084C78u)
HARD_BOUNDARY(sub_8207B630, 0x8207B630u)
HARD_BOUNDARY(sub_8207B8B8, 0x8207B8B8u)
HARD_BOUNDARY(sub_8207BAE8, 0x8207BAE8u)
HARD_BOUNDARY(sub_82084EE0, 0x82084EE0u)
#undef HARD_BOUNDARY

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
