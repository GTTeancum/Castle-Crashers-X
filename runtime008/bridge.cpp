// SPDX-License-Identifier: MIT (adapter; includes are unchanged user-game code)
#include "bridge.h"
#include <climits>
#include <cmath>
#include <csetjmp>
#include <cstring>
namespace cc::tree {
#include "../runtime007/float_scope.inc"
struct Machine {
  AddressSpace &memory;
  Sink sink;
  Result result{};
  std::jmp_buf escape;
  uint32_t budget = 200000, depth = 0;
  void prologue(const char *name) {
    if (++result.functions > 50000)
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
    std::longjmp(escape, 1);
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
#define REX_FUNC_PROLOGUE() base.prologue(__func__)
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
#include "bodies.inc"
#include "../runtime010/bodies.inc"
static bool submit(void *ptr, const Draw &d) {
  auto &m = *static_cast<Machine *>(ptr);
  if (!m.sink.submit || !m.sink.submit(m.sink.user, d))
    return false;
  ++m.result.submits;
  return true;
}
static void dispatch_impl(uint32_t address, Context &ctx, Machine &base) {
  if (++base.result.dispatches > 10000)
    base.fail(Error::capacity, address);
  if (address == 0x82091248)
    base.validate_owner(ctx.r3.u32);
  if (address == 0x8208a7a0)
    base.validate_list(ctx.r3.u32);
  switch (address) {
#include "dispatch.inc"
#include "../runtime010/dispatch.inc"
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
  switch (entry) {
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
  if (entry != 0x8208a7a0 && entry != 0x820a8ff8 && entry != 0x82091248) {
    error.error = Error::entry;
    return error;
  }
  if (!sink.submit || !sink.bind || ctx.r1.u64 < 16384 ||
      ctx.r1.u64 > 0xffffff7f || budget < 1 || budget > 2000000) {
    error.error = Error::context;
    return error;
  }
  if (memory.check(ctx.r1.u32 - 512, 640, 3) != cc::xbox::MemoryError::ok) {
    error.error = Error::memory;
    return error;
  }
  Machine m{memory, sink, {}, {}};
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
