// SPDX-License-Identifier: MIT (adapter; includes are unchanged user-game code)
#include "bridge.h"
#include <climits>
#include <cmath>
#include <csetjmp>
#include <cstring>
namespace cc::caller {
#include "float_scope.inc"
struct Machine {
  AddressSpace &memory;
  Sink sink;
  Result result{};
  std::jmp_buf escape;
  [[noreturn]] void fail(Error e, uint32_t a = 0) {
    result.error = e;
    result.address = a;
    std::longjmp(escape, 1);
  }
  uint64_t load(uint32_t a, unsigned n) {
    uint64_t v = 0;
    if (memory.load_be(a, n, v) != cc::xbox::MemoryError::ok)
      fail(Error::memory, a);
    return v;
  }
  void store(uint32_t a, unsigned n, uint64_t v) {
    if (memory.store_be(a, n, v) != cc::xbox::MemoryError::ok)
      fail(Error::memory, a);
  }
};
// Scalar implementations of only the two SIMDe intrinsics used by these bodies.
// No SIMD/vector-register support is implied. Nearest-even is established by
// FloatScope; nonfinite/out-of-range converts to the intrinsic indefinite
// value.
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
using PPCRegister = Register;
#define DEFINE_REX_FUNC(name)                                                  \
  static void name([[maybe_unused]] Context &ctx,                              \
                   [[maybe_unused]] Machine &base)
#define REX_FUNC_PROLOGUE() ((void)0)
#define REX_LOAD_U8(a) uint8_t(base.load(uint32_t(a), 1))
#define REX_LOAD_U32(a) uint32_t(base.load(uint32_t(a), 4))
#define REX_LOAD_U64(a) base.load(uint32_t(a), 8)
#define REX_STORE_U8(a, v) base.store(uint32_t(a), 1, v)
#define REX_STORE_U32(a, v) base.store(uint32_t(a), 4, v)
#define REX_STORE_U64(a, v) base.store(uint32_t(a), 8, v)
static void dispatch(uint32_t, Context &, Machine &);
#define REX_CALL_INDIRECT_FUNC(a) dispatch(uint32_t(a), ctx, base)
// Declarations make the unchanged body includes independent of include sorting.
static void sub_820A7488(Context&, Machine&);
static void sub_82127AE8(Context&, Machine&);
static void __restgprlr_27(Context&, Machine&);
static void sub_820A9068(Context&, Machine&);
static void sub_820855D8(Context&, Machine&);
static void sub_82127A08(Context&, Machine&);
static void sub_82085110(Context&, Machine&);
static void sub_820A8DD8(Context&, Machine&);
static void __savegprlr_28(Context&, Machine&);
static void __restgprlr_28(Context&, Machine&);
static void sub_820A74E0(Context&, Machine&);
static void __restfpr_19(Context&, Machine&);
static void __savegprlr_27(Context&, Machine&);
static void __restgprlr_25(Context&, Machine&);
static void __savefpr_19(Context&, Machine&);
static void __savegprlr_25(Context&, Machine&);
#include "generated/__restfpr_19.inc"
#include "generated/__restgprlr_25.inc"
#include "generated/__restgprlr_27.inc"
#include "generated/__restgprlr_28.inc"
#include "generated/__savefpr_19.inc"
#include "generated/__savegprlr_25.inc"
#include "generated/__savegprlr_27.inc"
#include "generated/__savegprlr_28.inc"
#include "generated/sub_82085110.inc"
#include "generated/sub_820855D8.inc"
#include "generated/sub_820A7488.inc"
#include "generated/sub_820A74E0.inc"
#include "generated/sub_820A8DD8.inc"
#include "generated/sub_820A9068.inc"
#include "generated/sub_82127A08.inc"
#include "generated/sub_82127AE8.inc"
static bool submit(void *ptr, const Draw &d) {
  auto &m = *static_cast<Machine *>(ptr);
  if (!m.sink.submit || !m.sink.submit(m.sink.user, d))
    return false;
  ++m.result.submits;
  return true;
}
static void dispatch(uint32_t address, Context &ctx, Machine &base) {
  if (++base.result.dispatches > 32)
    base.fail(Error::capacity, address);
  switch (address) {
  case 0x820a7488:
    sub_820A7488(ctx, base);
    return;
  case 0x820a74e0:
    sub_820A74E0(ctx, base);
    return;
  case 0x820a8dd8:
    if (ctx.r8.u32 != 4)
      base.fail(Error::context, address);
    sub_820A8DD8(ctx, base);
    return;
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
// setjmp lives in a separate function; modified Machine/Context storage belongs
// to the caller, not to this setjmp frame. Generated callees are scalar/trivial
// and create no nontrivial automatic objects across a longjmp. FloatScope is
// outside this frame and always restores host FP controls normally.
static void execute(uint32_t entry, Context &ctx, Machine &m) {
  if (setjmp(m.escape))
    return;
  switch (entry) {
  case 0x820a9068:
    sub_820A9068(ctx, m);
    break;
  case 0x820855d8:
    sub_820855D8(ctx, m);
    break;
  default:
    m.fail(Error::entry, entry);
  }
}
Result invoke(uint32_t entry, Context &ctx, AddressSpace &memory,
              Sink sink) noexcept {
  Result error;
  if (entry != 0x820a9068 && entry != 0x820855d8) {
    error.error = Error::entry;
    return error;
  }
  if (!sink.submit || ctx.r1.u64 < 1024 || ctx.r1.u64 > 0xffffff8f ||
      (entry == 0x820a9068 &&
       (!std::isfinite(ctx.f1.f64) || std::fabs(ctx.f1.f64) > 10000))) {
    error.error = Error::context;
    return error;
  }
  // Preflight the entire working stack. All further accesses are checked and
  // unwind via the explicit error result on failure, never on assumed success.
  if (memory.check(ctx.r1.u32 - 1024, 1136, 3) != cc::xbox::MemoryError::ok) {
    error.error = Error::memory;
    return error;
  }
  Machine m{memory, sink, {}, {}};
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
    E(entry) E(context) E(memory) E(dispatch) E(texture) E(quad) E(sink)
        E(capacity)
#undef E
  }
  return "unknown";
}
} // namespace cc::caller
