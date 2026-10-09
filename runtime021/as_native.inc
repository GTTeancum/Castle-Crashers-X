// Native ActionScript interpreter (play build, CC_FAST), included at the end
// of runtime021/bodies.inc. The game's scripts are AVM1-style bytecode run
// by the four fetch/dispatch loops below; each loop, the hot instruction
// handlers and the value helpers they use are written natively here, on the
// game's own data structures in guest memory, with the same memory effects
// as the recompiled code (same allocations, reference counts, slot contents
// and calls into the rest of the game). The recompiled bodies stay as
// sub_X_exact: host switches select them (CC_AS_EXACT=1 for everything here,
// CC_EXACT_FNS=sub_X,... per function, CC_AS_GUEST=96,A0,... per opcode),
// and a host run with CC_STATE_HASH compares the guest heaps of the two.
//
// Data layout (survey in TODO.md):
//  - script context S (r3/r4 of a handler): S+0 -> movie whose +76 -> player
//    whose +156 = VM. Pool P = VM + 10372: value stack of slot pointers at
//    P+0, count at P+5024; 1256 value slots of 12 bytes at P+5028
//    {u32 type, u32 payload, u8 in-use}, rover at P+20100.
//  - VM+8248: update-stack count, entries at VM+(n+1998)*4 (current clip on
//    top); VM+10180: function-stack count, entries at VM+(n+2513)*4.
//  - value types: 0x80000000 undefined, 2 bool, 4 int, 8 string (u16 id),
//    16 number (float); objects 1/64/128/1024/4096/8192/... are
//    reference-counted when type & 0x7C6C1 (u16 count at object+24).
//  - instruction record handed to a handler (r5): {+0 u32 op, +4 u16 length,
//    +8 u32 data}; length/data keep their previous values for short ops.
#ifdef CC_FAST
static constexpr uint32_t kAsRef = 0x7C6C1u;
static constexpr uint32_t kAsUndef = 0x80000000u;

#ifndef CC_XBOX_DRIVER
// Host switch lookup: CC_AS_EXACT=1 selects every recompiled body in this
// file; CC_EXACT_FNS lists single functions (substring match on the name).
static CC_HOT_FN bool cc_as_exact_fn(const char* name) {
  if (std::getenv("CC_AS_EXACT")) return true;
  const char* l = std::getenv("CC_EXACT_FNS");
  return l && std::strstr(l, name) != nullptr;
}
#define CC_AS_SWITCH(name) do { \
    static const bool cc_as_ex = cc_as_exact_fn(#name); \
    if (cc_as_ex) { name##_exact(ctx, base); return; } } while (0)
#else
#define CC_AS_SWITCH(name) static_cast<void>(&name##_exact)
#endif

#define CC_AS_INL inline __attribute__((always_inline))

// Host A/B switches of the lean op path (host environment; Xbox build
// defines of the same name with _BUILD): CC_AS_NOHOST keeps every VM-block
// and code access on the guest path, CC_AS_RC_CALL sends reference counts
// through sub_82066EA8 as before. CC_ORACLE=1 also checks the loop state
// (stored VM, host view, opcode table) on every instruction.
#ifndef CC_XBOX_DRIVER
static const bool g_as_nohost = std::getenv("CC_AS_NOHOST") != nullptr;
static const bool g_as_rc_call = std::getenv("CC_AS_RC_CALL") != nullptr;
static const bool g_as_oracle = std::getenv("CC_ORACLE") != nullptr;
#else
#ifdef CC_AS_NOHOST_BUILD
static constexpr bool g_as_nohost = true;
#else
static constexpr bool g_as_nohost = false;
#endif
#ifdef CC_AS_RC_CALL_BUILD
static constexpr bool g_as_rc_call = true;
#else
static constexpr bool g_as_rc_call = false;
#endif
static constexpr bool g_as_oracle = false;
#endif
// Direct calls of the native clip GetMember (from GetVariable and the
// GetMember handlers) unless the host selects its recompiled body.
#ifndef CC_XBOX_DRIVER
static const bool g_as_gm_direct = !cc_as_exact_fn("sub_8208B438");
#else
static constexpr bool g_as_gm_direct = true;
#endif

// VM of a script context: [[[S+0]+76]+156].
static CC_HOT_FN inline uint32_t cc_as_vm(Machine& base, uint32_t s) {
  return REX_LOAD_U32(REX_LOAD_U32(REX_LOAD_U32(s + 0u) + 76u) + 156u);
}

// Host address of the guest bytes [a, a + n) (n at most 64 KiB) when the
// play build's page table maps all of them with one host offset, else null.
// Every direct host access of the interpreter goes through this helper, so a
// change of the memory model only has to change it.
static CC_HOT_FN inline uint8_t* cc_as_host(uint32_t a, uint32_t n) {
  if (g_as_nohost) return nullptr;
#ifdef CC_FLAT_WINDOW
  // Flat guest window: the pool, stacks and code blocks the interpreter
  // reads each lie in one committed region.
  static_cast<void>(n);
  return ::cc_win::ptr(a);
#else
  uint8_t* const p = g_page_host[a >> 16];
  if (uintptr_t(p) <= 1u) return nullptr;
  const uint32_t e = a + (n - 1u);
  if (e < a) return nullptr;
  if ((e >> 16) != (a >> 16) && g_page_host[e >> 16] != p + 0x10000u) return nullptr;
  return p + (a & 0xFFFFu);
#endif
}
static CC_AS_INL uint32_t cc_as_hld(const uint8_t* p) {
  uint32_t x;
  __builtin_memcpy(&x, p, 4);
  return __builtin_bswap32(x);
}
static CC_AS_INL uint32_t cc_as_hld16(const uint8_t* p) {
  uint16_t x;
  __builtin_memcpy(&x, p, 2);
  return __builtin_bswap16(x);
}
static CC_AS_INL void cc_as_hst(uint8_t* p, uint32_t v) {
  const uint32_t x = __builtin_bswap32(v);
  __builtin_memcpy(p, &x, 4);
}

// The interpreter's hot VM state is one block of the VM: update stack
// (count +8248, entries +(n+1998)*4), function stack (count +10180,
// entries +(n+2513)*4), string table pointer +10316, the value pool P at
// +10372 (value stack of slot pointers at P+0, count P+5024, 1256 slots of
// 12 bytes at P+5028, rover P+20100) and the word at +30476 read by the
// Push decode. A loop resolves its VM once and, when the page table maps
// the whole block with one host offset, a host view of it; the accessors
// below then read and write the same big-endian bytes directly. Offsets
// outside the block (a corrupt count) take the guest path, as without a
// view, so every access lands where the original's does.
static constexpr uint32_t kAsVmBlock = 30480u;
static constexpr uint32_t kAsPool = 10372u;

// Loop state (one per running loop, nested calls run their own): the
// script context, record and return slots, stop byte, the record fields
// as the original keeps them, the VM and its host view, and the opcode
// being run (native handlers take the loop as their instruction).
struct CcAsLoop {
  uint32_t s, rec, r6, done;
  uint32_t len = 0, data = 0;    // record fields as the original keeps them
  uint32_t r6_clear = 0;         // OnEnterFrame-style loops clear r6+4/+8 per op
  uint32_t vm = 0;               // VM of s, resolved when the loop starts
  uint8_t* hv = nullptr;         // host view of the VM block, or null
  uint32_t op = 0;
  uint32_t guest_ran = 0;        // the last instruction ran its guest handler
};
using CcAsOp = CcAsLoop;
#ifndef CC_XBOX_DRIVER
// Host census of the host views (CC_AS_VIEWSTAT=1): loops and code fetch
// views with and without a host pointer, printed at exit.
static const bool g_as_viewstat = std::getenv("CC_AS_VIEWSTAT") != nullptr;
static uint64_t g_as_views[4];  // VM view null / set, code view null / set
namespace {
struct CcAsViewReport {
  ~CcAsViewReport() {
    if (g_as_viewstat)
      std::fprintf(stderr, "ASVIEW vm_null=%llu vm_host=%llu code_null=%llu code_host=%llu\n", (unsigned long long)g_as_views[0],
                   (unsigned long long)g_as_views[1], (unsigned long long)g_as_views[2], (unsigned long long)g_as_views[3]);
  }
} g_as_view_report;
}  // namespace
#endif
static CC_AS_INL void cc_as_loop_vm(Machine& base, CcAsLoop& L) {
  L.vm = cc_as_vm(base, L.s);
  L.hv = cc_as_host(L.vm, kAsVmBlock);
#ifndef CC_XBOX_DRIVER
  if (g_as_viewstat) ++g_as_views[L.hv != nullptr ? 1 : 0];
#endif
}
// Loop state for a helper called from guest code (no loop running).
static CC_AS_INL CcAsLoop cc_as_loop_of(Machine& base, uint32_t s) {
  CcAsLoop L{s, 0u, 0u, 0u};
  cc_as_loop_vm(base, L);
  return L;
}
// The guest path of the accessors below is out of line: with a view (every
// loop of the shipped scripts has one) it only runs for a corrupt count.
static __attribute__((noinline, cold)) uint32_t cc_as_vld_guest(Machine& base, uint32_t a) { return REX_LOAD_U32(a); }
static __attribute__((noinline, cold)) void cc_as_vst_guest(Machine& base, uint32_t a, uint32_t v) { REX_STORE_U32(a, v); }
static CC_AS_INL uint32_t cc_as_vld(Machine& base, const CcAsLoop& L, uint32_t off) {
  if (__builtin_expect(L.hv != nullptr && off < kAsVmBlock - 3u, 1)) return cc_as_hld(L.hv + off);
  return cc_as_vld_guest(base, L.vm + off);
}
static CC_AS_INL void cc_as_vst(Machine& base, const CcAsLoop& L, uint32_t off, uint32_t v) {
  if (__builtin_expect(L.hv != nullptr && off < kAsVmBlock - 3u, 1)) { cc_as_hst(L.hv + off, v); return; }
  cc_as_vst_guest(base, L.vm + off, v);
}
static CC_AS_INL uint32_t cc_as_pool(const CcAsLoop& L) { return L.vm + kAsPool; }
// Active function (top of the VM's function stack; 0 at top level).
static CC_AS_INL uint32_t cc_as_act(Machine& base, const CcAsLoop& L) {
  return cc_as_vld(base, L, (cc_as_vld(base, L, 10180u) + 2513u) * 4u);
}
// Clip on top of the VM's update stack.
static CC_HOT_FN inline uint32_t cc_as_top_clip(Machine& base, uint32_t vm) {
  return REX_LOAD_U32(vm + (REX_LOAD_U32(vm + 8248u) + 1998u) * 4u);
}
static CC_AS_INL uint32_t cc_as_top_clip(Machine& base, const CcAsLoop& L) {
  return cc_as_vld(base, L, (cc_as_vld(base, L, 8248u) + 1998u) * 4u);
}
// Value stack pop as every handler does it: count decremented and stored,
// then the slot pointer read.
static CC_AS_INL uint32_t cc_as_pop(Machine& base, const CcAsLoop& L) {
  const uint32_t n = cc_as_vld(base, L, kAsPool + 5024u) - 1u;
  cc_as_vst(base, L, kAsPool + 5024u, n);
  return cc_as_vld(base, L, kAsPool + n * 4u);
}
// Push: the slot stored at the count, then the count re-read and raised.
static CC_AS_INL void cc_as_push(Machine& base, const CcAsLoop& L, uint32_t slot) {
  cc_as_vst(base, L, kAsPool + cc_as_vld(base, L, kAsPool + 5024u) * 4u, slot);
  cc_as_vst(base, L, kAsPool + 5024u, cc_as_vld(base, L, kAsPool + 5024u) + 1u);
}
// Slot on top of the value stack (after a pop: the popped one).
static CC_AS_INL uint32_t cc_as_top_slot(Machine& base, const CcAsLoop& L) {
  return cc_as_vld(base, L, kAsPool + cc_as_vld(base, L, kAsPool + 5024u) * 4u);
}
// Value-pool allocation (sub_82082488(P) inline): the first free slot from
// the rover on (wrapping), marked used and made the rover; 0 when all 1256
// are in use. Without a host view, with a rover out of range, or under
// CC_ORACLE (which checks the native allocator against the recompiled one)
// it is the call.
static CC_HOT_FN __attribute__((noinline)) uint32_t cc_as_alloc_call(Context& ctx, Machine& base, uint32_t pool, uint32_t lr) {
  ctx.r3.u64 = pool; ctx.lr = lr;
  sub_82082488(ctx, base);
  return ctx.r3.u32;
}
static CC_AS_INL uint32_t cc_as_alloc(Context& ctx, Machine& base, const CcAsLoop& L, uint32_t lr) {
  if (L.hv != nullptr && !g_as_oracle) {
    uint8_t* const p = L.hv + kAsPool;
    const uint32_t start = cc_as_hld(p + 20100u);
    if (start < 1256u) {
      uint32_t i = start;
      while (p[i * 12u + 5036u] != 0u) {
        i = i + 1u < 1256u ? i + 1u : 0u;
        if (i == start) return 0u;
      }
      p[i * 12u + 5036u] = 1u;
      cc_as_hst(p + 20100u, i);
      return L.vm + kAsPool + 5028u + i * 12u;
    }
  }
  return cc_as_alloc_call(ctx, base, L.vm + kAsPool, lr);
}
// Slot returned to the pool: in-use byte and payload cleared.
static CC_AS_INL void cc_as_free(Machine& base, uint32_t slot) {
  REX_STORE_U8(slot + 8u, 0u);
  REX_STORE_U32(slot + 4u, 0u);
}
// Reference count step sub_82066EA8(object, up) without the call: when the
// object's slot-40 method is a constant leaf (li r3,K; cc_leaf_info reads
// it from the image once per method), K decides the inline +1 / -1 on the
// u16 at +24 as the callee does; other methods go through the call.
static CC_HOT_FN __attribute__((noinline)) void cc_as_rc(Context& ctx, Machine& base, uint32_t obj, uint32_t up, uint32_t lr) {
  if (!g_as_rc_call) {
    const CcLeaf& e = cc_leaf_info(base, REX_LOAD_U32(REX_LOAD_U32(obj) + 40u));
    if (e.kind == 2u) {
      if ((uint32_t(e.imm) & kAsRef) != 0u) {
        const uint32_t v = REX_LOAD_U16(obj + 24u);
        REX_STORE_U16(obj + 24u, uint16_t(up ? v + 1u : v + 0xFFFFu));
      }
      return;
    }
  }
  ctx.r3.u64 = obj;
  ctx.r4.u64 = up;
  ctx.lr = lr;
  sub_82066EA8(ctx, base);
}
// Reference released for a value leaving the stack (the handlers' common
// sequence after a pop): a reference-counted object with a nonzero count
// first gets its slot-4 method when this is the last reference, then
// sub_82066EA8(object, 0) decrements the count.
// Slot-4 method of an object losing its last reference (out of line: rare).
static __attribute__((noinline)) void cc_as_last_ref(Context& ctx, Machine& base, uint32_t obj, uint32_t lr) {
  cc_vcall(ctx, base, obj, 4u, lr);
}
static CC_HOT_FN __attribute__((noinline)) void cc_as_unref_obj(Context& ctx, Machine& base, uint32_t holder, uint32_t lr_a, uint32_t lr_b) {
  // holder: address of the object pointer (slot + 4, or Var + 0)
  const uint32_t obj = REX_LOAD_U32(holder);
  const uint32_t rc = REX_LOAD_U16(obj + 24u);
  if (rc == 0u) return;
  if (rc == 1u) cc_as_last_ref(ctx, base, obj, lr_a);
  cc_as_rc(ctx, base, REX_LOAD_U32(holder), 0u, lr_b);
}
static CC_AS_INL void cc_as_unref(Context& ctx, Machine& base, uint32_t slot, uint32_t lr_a, uint32_t lr_b) {
  if ((REX_LOAD_U32(slot) & kAsRef) == 0u) return;
  cc_as_unref_obj(ctx, base, slot + 4u, lr_a, lr_b);
}
// Reference taken for a value pushed on the stack: sub_82066EA8(object, 1)
// for a reference-counted object whose count is nonzero.
static CC_HOT_FN __attribute__((noinline)) void cc_as_ref_obj(Context& ctx, Machine& base, uint32_t obj, uint32_t lr) {
  if (REX_LOAD_U16(obj + 24u) == 0u) return;
  cc_as_rc(ctx, base, obj, 1u, lr);
}
static CC_AS_INL void cc_as_ref(Context& ctx, Machine& base, uint32_t slot, uint32_t lr) {
  if ((REX_LOAD_U32(slot) & kAsRef) == 0u) return;
  cc_as_ref_obj(ctx, base, REX_LOAD_U32(slot + 4u), lr);
}
// Object pointer of a value as the handlers test it: reference-counted
// types, 4096 and 8192 give the payload; anything else 0.
static CC_HOT_FN inline uint32_t cc_as_obj_of(Machine& base, uint32_t slot) {
  const uint32_t t = REX_LOAD_U32(slot);
  if ((t & kAsRef) != 0u || t == 4096u || t == 8192u) return REX_LOAD_U32(slot + 4u);
  return 0u;
}

// Native handlers take the loop as the decoded instruction (op, the
// record's possibly stale len/data, the return slot r6 and the stop byte
// done, plus the VM) and return the extra pc delta like the recompiled
// ones. Each is its own function, reached through the opcode table
// g_as_fn (null: the guest handler), so the dispatch loops stay small and
// the hot handlers do not share one huge function with the rare ones.
using CcAsOpFn = uint32_t (*)(Context&, Machine&, const CcAsOp&);
static CcAsOpFn g_as_fn[256];
static void cc_as_fill_ops();  // as_ops.inc

// Guest handler for an opcode (the table at 0x8215A518), called with the
// record already stored at rec.
static __attribute__((noinline)) uint32_t cc_as_guest_op(Context& ctx, Machine& base, uint32_t op, uint32_t s, uint32_t rec,
                               uint32_t r6, uint32_t done, uint32_t lr) {
  ctx.r3.u64 = s; ctx.r4.u64 = s; ctx.r5.u64 = rec; ctx.r6.u64 = r6; ctx.r7.u64 = done;
  ctx.lr = lr;
  switch (op) {
#include "as_guest_switch.inc"
    default: {
      // not in the table: through the address like the original bctrl
      const uint32_t fn = REX_LOAD_U32(0x8215A518u + op * 4u);
      static uint32_t key = 0; static CcGenFn gf = nullptr;
      cc_dispatch_cached(fn, ctx, base, key, gf);
      break;
    }
  }
  return ctx.r3.u32;
}

// The handler table at 0x8215A518 as the loops test it (a zero entry is a
// missing handler): read once when the first loop starts; 0 handler, 1 no
// handler, 2 past the table's 0xA5 entries (the guest word is read each
// time, as the original).
static uint8_t g_as_tbl[256];
// The native opcode table is filled here too; the host takes the opcodes
// listed in CC_AS_GUEST (all of them under CC_AS_EXACT) out of it, so they
// run their guest handlers.
static CC_HOT_FN void cc_as_init_switches(Machine& base) {
  static bool done = false;
  if (__builtin_expect(done, 1)) return;
  done = true;
  for (unsigned op = 0; op < 256u; ++op)
    g_as_tbl[op] = op >= 0xA5u ? 2u : REX_LOAD_U32(0x8215A518u + op * 4u) == 0u ? 1u : 0u;
  cc_as_fill_ops();
#ifndef CC_XBOX_DRIVER
  const bool all = std::getenv("CC_AS_EXACT") != nullptr;
  const char* l = std::getenv("CC_AS_GUEST");
  for (unsigned op = 0; op < 256u; ++op) {
    char hex[8];
    std::snprintf(hex, sizeof(hex), "%02X", op);
    if (all || (l && std::strstr(l, hex) != nullptr)) g_as_fn[op] = nullptr;
  }
#endif
}
static CC_AS_INL bool cc_as_no_handler_entry(Machine& base, uint32_t op) {
  const uint32_t k = g_as_tbl[op];
  if (__builtin_expect(k == 0u, 1)) return false;
  return k == 1u || REX_LOAD_U32(0x8215A518u + op * 4u) == 0u;
}
#ifndef CC_XBOX_DRIVER
// CC_ORACLE=1: the loop's stored VM and host view against a fresh lookup
// from the script context, and the cached handler-table state against the
// table, before and after every native instruction.
static __attribute__((noinline, cold)) void cc_as_oracle_loop(Machine& base, const CcAsLoop& L) {
  const uint32_t vm = cc_as_vm(base, L.s);
  if (vm != L.vm) cc_oracle_mismatch("as_loop_vm", int(L.op), vm, L.vm);
  if (L.hv != nullptr && L.hv != cc_as_host(L.vm, kAsVmBlock)) cc_oracle_mismatch("as_loop_hv", int(L.op), 0u, 1u);
  const bool none = REX_LOAD_U32(0x8215A518u + L.op * 4u) == 0u;
  if (none != cc_as_no_handler_entry(base, L.op)) cc_oracle_mismatch("as_loop_tbl", int(L.op), none, !none);
}
#endif

// Runs one instruction: native handler unless switched off, else the guest
// handler with the record written to rec first (the loop passes the record
// fields it keeps in variables). Returns the handler's extra pc delta.
#ifdef CC_OP_STATS
// Console op census (make OPSTATS=1): cycles per opcode excluding nested
// opcodes (a call's inner instructions count for themselves), reported on
// the debug channel every 300 frames by cc_op_dbg.
static uint64_t g_op_cyc[256];
static uint32_t g_op_cnt[256];
static uint64_t g_op_child[128];
static uint64_t g_call_setup, g_call_teardown;
static uint32_t g_call_n;
static int g_op_sp = 0;
void cc_op_dbg() {
  uint64_t total = 0;
  for (unsigned i = 0; i < 256u; ++i) total += g_op_cyc[i];
  char line[600]; int n = std::snprintf(line, sizeof(line), "OPS total_mcyc=%u calls=%u setup_kcyc=%u teardown_kcyc=%u", unsigned(total / 1000000u),
      g_call_n, unsigned(g_call_setup / 1000u), unsigned(g_call_teardown / 1000u));
  g_call_n = 0; g_call_setup = 0; g_call_teardown = 0;
  for (int k = 0; k < 14; ++k) {
    unsigned best = 256; uint64_t bc = 0;
    for (unsigned i = 0; i < 256u; ++i) if (g_op_cyc[i] > bc) { bc = g_op_cyc[i]; best = i; }
    if (best == 256u) break;
    n += std::snprintf(line + n, sizeof(line) - size_t(n), " %02X:%u%%/%u", best, unsigned(bc * 100u / (total ? total : 1)), g_op_cnt[best]);
    g_op_cyc[best] = 0; g_op_cnt[best] = 0;
  }
  DbgPrint("%s\n", line);
  for (unsigned i = 0; i < 256u; ++i) { g_op_cyc[i] = 0; g_op_cnt[i] = 0; }
}
#endif
static uint32_t cc_as_step_body(Context& ctx, Machine& base, CcAsLoop& L, uint32_t op, uint32_t lr);
#ifndef CC_XBOX_DRIVER
// Host behaviour trace (CC_AS_VALHASH=<n>): a running hash over every
// instruction the native loops run (the opcode, the value-stack depth and
// the value on top: its type, and its payload for undefined, bool, int,
// string id and number; object payloads are addresses and left out),
// printed every n frames as VALHASH lines. Two runs that place heap
// objects differently (the activation slab) compare by it.
static const uint32_t g_as_valhash_every = [] {
  const char* e = std::getenv("CC_AS_VALHASH");
  return e ? uint32_t(std::strtoul(e, nullptr, 10)) : 0u;
}();
static __attribute__((noinline, cold)) void cc_as_valhash_step(Machine& base, const CcAsLoop& L, uint32_t op) {
  static uint64_t h = 1469598103934665603ull, ops = 0;
  static uint32_t bucket = 0;
  const uint32_t b = g_frame_delay_calls / g_as_valhash_every;
  if (b != bucket) {
    std::fprintf(stderr, "VALHASH frame=%u ops=%llu hash=%016llx\n", b * g_as_valhash_every, (unsigned long long)ops, (unsigned long long)h);
    bucket = b;
  }
  ++ops;
  const uint32_t n = cc_as_vld(base, L, kAsPool + 5024u);
  uint64_t x = uint64_t(op) | (uint64_t(n & 0xFFFFu) << 8);
  if (n - 1u < 1256u) {
    const uint32_t slot = cc_as_vld(base, L, kAsPool + (n - 1u) * 4u);
    const uint32_t t = REX_LOAD_U32(slot);
    x ^= uint64_t(t) << 24;
    if (t == kAsUndef || t == 2u || t == 4u || t == 16u) x ^= uint64_t(REX_LOAD_U32(slot + 4u)) * 0x9E3779B97F4A7C15ull;
    else if (t == 8u) x ^= uint64_t(REX_LOAD_U16(slot + 4u)) * 0x9E3779B97F4A7C15ull;
  }
  for (int k = 0; k < 8; ++k) { h ^= (x >> (8 * k)) & 0xFFu; h *= 1099511628211ull; }
}
#endif
// Guest handler run from a loop: the record fields written to rec first
// (out of line: the shipped scripts' hot opcodes are all native).
static __attribute__((noinline)) uint32_t cc_as_step_guest(Context& ctx, Machine& base, CcAsLoop& L, uint32_t op, uint32_t lr) {
  L.guest_ran = 1u;
  REX_STORE_U32(L.rec + 0u, op);
  REX_STORE_U16(L.rec + 4u, uint16_t(L.len));
  REX_STORE_U32(L.rec + 8u, L.data);
  if (L.r6_clear) { REX_STORE_U32(L.r6 + 4u, 0u); REX_STORE_U8(L.r6 + 8u, 0u); }
  return cc_as_guest_op(ctx, base, op, L.s, L.rec, L.r6, L.done, lr);
}
static CC_HOT_FN inline uint32_t cc_as_step(Context& ctx, Machine& base, CcAsLoop& L, uint32_t op, uint32_t lr) {
#ifdef CC_XBOX_DRIVER
  ++g_fc[0];
#endif
#ifdef CC_OP_STATS
  const uint64_t t0 = __builtin_ia32_rdtsc();
  const int me = g_op_sp < 127 ? g_op_sp++ : 127;
  g_op_child[me] = 0;
  const uint32_t r = cc_as_step_body(ctx, base, L, op, lr);
  const uint64_t dt = __builtin_ia32_rdtsc() - t0;
  if (me == g_op_sp - 1) --g_op_sp;
  g_op_cyc[op] += dt - (g_op_child[me] < dt ? g_op_child[me] : dt);
  ++g_op_cnt[op];
  if (me > 0) g_op_child[me - 1] += dt;
  return r;
#else
  return cc_as_step_body(ctx, base, L, op, lr);
#endif
}
static CC_HOT_FN inline __attribute__((always_inline)) uint32_t cc_as_step_body(Context& ctx, Machine& base, CcAsLoop& L, uint32_t op, uint32_t lr) {
  L.op = op;
  L.guest_ran = 0u;
#ifndef CC_XBOX_DRIVER
  if (g_as_oracle) cc_as_oracle_loop(base, L);
#endif
  const CcAsOpFn fn = g_as_fn[op];
  uint32_t r;
  if (__builtin_expect(fn != nullptr, 1)) {
    r = fn(ctx, base, L);
#ifndef CC_XBOX_DRIVER
    if (g_as_oracle) cc_as_oracle_loop(base, L);
#endif
  } else {
    r = cc_as_step_guest(ctx, base, L, op, lr);
  }
#ifndef CC_XBOX_DRIVER
  if (g_as_valhash_every) cc_as_valhash_step(base, L, op);
#endif
  return r;
}
// Instruction fetch: op byte, and for op >= 0x80 the little-endian u16
// length; a nonzero length moves the data pointer to the bytes after it.
// Returns the instruction size. The code bytes come through the loop's
// host view of the code when pc is inside it (hn: the pc limit below which
// the op and length bytes are in the view), else the guest path.
static CC_AS_INL uint32_t cc_as_fetch(Machine& base, CcAsLoop& L, uint32_t code, const uint8_t* hc, uint32_t hn,
                                      uint32_t pc, uint32_t& op) {
  uint32_t le;
  if (pc < hn) {
    op = hc[pc];
    if (op < 0x80u) return 1u;
    le = hc[pc + 1u] | (uint32_t(hc[pc + 2u]) << 8);
  } else {
    op = REX_LOAD_U8(code + pc);
    if (op < 0x80u) return 1u;
    le = REX_LOAD_U8(code + pc + 1u) | (REX_LOAD_U8(code + pc + 2u) << 8);
  }
  L.len = le;
  if (le == 0u) return 3u;
  L.data = code + pc + 3u;
  return le + 3u;
}
// Host view of the code for the fetch: 64 KiB from code when mapped with
// one offset, else the rest of code's page; null (hn 0) when unmapped.
static CC_AS_INL const uint8_t* cc_as_code_view(uint32_t code, uint32_t& hn) {
  uint32_t n = 0x10000u;
  const uint8_t* h = cc_as_host(code, n);
  if (h == nullptr) {
    n = 0x10000u - (code & 0xFFFFu);
    h = cc_as_host(code, n);
  }
  hn = h != nullptr && n >= 3u ? n - 2u : 0u;
#ifndef CC_XBOX_DRIVER
  if (g_as_viewstat) ++g_as_views[h != nullptr ? 3 : 2];
#endif
  return h;
}
// Stop byte test (the loops read it after every instruction).
static CC_AS_INL bool cc_as_stopped(Machine& base, uint32_t done, const uint8_t* hd) {
  return (hd != nullptr ? uint32_t(*hd) : uint32_t(REX_LOAD_U8(done))) != 0u;
}
// Missing handler (never seen in the shipped scripts): the original's
// error report through the current clip's name (slots 52, 72, 24), the
// format string fmt and sub_820798D8/sub_8208C5D8.
static __attribute__((noinline, cold)) void cc_as_no_handler(Context& ctx, Machine& base, uint32_t s, uint32_t clip, uint32_t fmt,
                             uint32_t a5, uint32_t a6, uint32_t a7) {
  uint32_t name;
  if ((cc_vcall(ctx, base, clip, 52u, 0x8207BBE8u) & 0xFFu) != 0u) {
    const uint32_t names = REX_LOAD_U32(cc_as_vm(base, s) + 10316u);
    const uint32_t id = cc_vcall(ctx, base, clip, 72u, 0x8207BC18u) & 0xFFFFu;
    name = id ? REX_LOAD_U32(REX_LOAD_U32(names + 28u) + id * 4u) : names + 12u;
  } else {
    name = 0x8203E1ECu;  // empty-name string (r23 = 0x82040000 - 7700)
  }
  const uint32_t id = cc_vcall(ctx, base, clip, 24u, 0x8207BC54u) & 0xFFFFu;
  ctx.r3.u64 = fmt; ctx.r4.u64 = id; ctx.r5.u64 = name; ctx.r6.u64 = a5; ctx.r7.u64 = a6; ctx.r8.u64 = a7;
  ctx.lr = 0x8207BC68u;
  sub_820798D8(ctx, base);
  ctx.lr = 0x8207BC6Cu;
  sub_8208C5D8(ctx, base);
}

// ---------------------------------------------------------------------------
// The four fetch/dispatch loops.

// After a loop stopped by its stop byte: sub_8207A0D0(S) and the pool reset
// sub_82079B48(P).
static __attribute__((noinline)) void cc_as_stop_reset(Context& ctx, Machine& base, uint32_t s, uint32_t lr_a, uint32_t lr_b) {
  ctx.r3.u64 = s; ctx.lr = lr_a;
  sub_8207A0D0(ctx, base);
  ctx.r3.u64 = cc_as_vm(base, s) + kAsPool; ctx.lr = lr_b;
  sub_82079B48(ctx, base);
}

// Frame-script loop shared by OnEnterFrame, OnLoad and the end-of-frame
// actions: ops from pc 0 until op 0 (returns false) or the stop byte
// (returns true). A missing handler is reported with format fmt and, by
// kind, (pc after the op, 0) for OnEnterFrame, (pc, 0) for OnLoad and
// (action index, pc) for the end-of-frame actions.
enum CcAsFrameKind { kAsEnterFrame, kAsLoad, kAsEndOfFrame };
static CC_HOT_FN bool cc_as_frame_loop(Context& ctx, Machine& base, CcAsLoop& L, uint32_t code, uint32_t clip, uint32_t fmt,
                                       CcAsFrameKind kind, uint32_t index, uint32_t lr) {
  uint32_t hn;
  const uint8_t* const hc = cc_as_code_view(code, hn);
  const uint8_t* const hd = cc_as_host(L.done, 1u);
  uint32_t pc = 0;
  for (;;) {
    uint32_t op;
    const uint32_t size = cc_as_fetch(base, L, code, hc, hn, pc, op);
    if (op == 0u) return false;
    if (cc_as_no_handler_entry(base, op))
      cc_as_no_handler(ctx, base, L.s, clip, fmt, kind == kAsEnterFrame ? pc + size : kind == kAsLoad ? pc : index,
                       kind == kAsEndOfFrame ? pc : 0u, 0u);
    pc = cc_as_step(ctx, base, L, op, lr) + size + pc;
    if (cc_as_stopped(base, L.done, hd)) return true;
  }
}

// OnEnterFrame (exact sub_8207BAE8: S r3). Code at S+20 (none: return);
// S+4 takes S+12; ops run from pc 0 until op 0 or the stop byte (frame
// +96); record at frame+104, return slot frame+120 (+4/+8 cleared per op).
// Stopped: sub_8207A0D0 + pool reset; otherwise S+12 takes S+4 if S+12 is
// empty and S+4 is set. S+4 is cleared.
static CC_HOT_FN void sub_8207BAE8(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8207BAE8);
  CC_FPROF_SCOPE(sub_8207BAE8_native);
  cc_as_init_switches(base);
  const uint32_t s = ctx.r3.u32;
  const uint32_t code = REX_LOAD_U32(s + 20u);
  if (code == 0u) return;
  CcFrame frame(ctx, base, 224u);
  const uint32_t r1 = ctx.r1.u32;
  CcAsLoop L{s, r1 + 104u, r1 + 120u, r1 + 96u};
  L.r6_clear = 1u;
  cc_as_loop_vm(base, L);
  const uint32_t clip = cc_as_top_clip(base, L);
  REX_STORE_U32(s + 4u, REX_LOAD_U32(s + 12u));
  REX_STORE_U8(r1 + 96u, 0u);
  // r25 = 0x82040000 - 7548
  if (cc_as_frame_loop(ctx, base, L, code, clip, 0x8203E284u, kAsEnterFrame, 0u, 0x8207BC94u)) {
    cc_as_stop_reset(ctx, base, s, 0x8207BCB8u, 0x8207BCCCu);
    REX_STORE_U32(s + 4u, 0u);
    return;
  }
  const uint32_t v4 = REX_LOAD_U32(s + 4u);
  if (v4 != 0u && REX_LOAD_U32(s + 12u) == 0u) REX_STORE_U32(s + 12u, v4);
  REX_STORE_U32(s + 4u, 0u);
}

// OnLoad (exact sub_8207B8B8: S r3). Code at S+16 (none: return); S+4
// takes S+8; same loop and exits as OnEnterFrame (format string -7608),
// with S+8 as the slot that takes S+4.
static CC_HOT_FN void sub_8207B8B8(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8207B8B8);
  CC_FPROF_SCOPE(sub_8207B8B8_native);
  cc_as_init_switches(base);
  const uint32_t s = ctx.r3.u32;
  if (REX_LOAD_U32(s + 16u) == 0u) return;
  CcFrame frame(ctx, base, 224u);
  const uint32_t r1 = ctx.r1.u32;
  CcAsLoop L{s, r1 + 104u, r1 + 120u, r1 + 96u};
  L.r6_clear = 1u;
  cc_as_loop_vm(base, L);
  const uint32_t clip = cc_as_top_clip(base, L);
  cc_vcall(ctx, base, clip, 52u, 0x8207B92Cu);
  REX_STORE_U32(s + 4u, REX_LOAD_U32(s + 8u));
  REX_STORE_U8(r1 + 96u, 0u);
  const uint32_t code = REX_LOAD_U32(s + 16u);
  // r24 = 0x82040000 - 7608
  if (cc_as_frame_loop(ctx, base, L, code, clip, 0x8203E248u, kAsLoad, 0u, 0x8207BA74u)) {
    cc_as_stop_reset(ctx, base, s, 0x8207BAA0u, 0x8207BAB4u);
    REX_STORE_U32(s + 4u, 0u);
    return;
  }
  const uint32_t v4 = REX_LOAD_U32(s + 4u);
  if (v4 != 0u && REX_LOAD_U32(s + 8u) == 0u) REX_STORE_U32(s + 8u, v4);
  REX_STORE_U32(s + 4u, 0u);
}

// ProcessEndOfFrameAction (exact sub_8207B630: S r3). Frame f = current
// clip's u16 +144 (0 -> 1); the action list for f is looked up in the map
// at S+64 (none: return) and S+4 takes the map S+24 entry for f. Each
// action record (list {u32 n, entries of 8 bytes, code at +4}) runs until
// op 0; a stop byte ends everything with sub_8207A0D0 + pool reset. Then,
// if S+4 is set and the S+24 lookup had found nothing, sub_820936B0(S+24,
// f, S+4) stores it; S+4 is cleared.
static CC_HOT_FN void sub_8207B630(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8207B630);
  CC_FPROF_SCOPE(sub_8207B630_native);
  cc_as_init_switches(base);
  const uint32_t s = ctx.r3.u32;
  const uint32_t clip = cc_as_top_clip(base, cc_as_vm(base, s));
  uint32_t f = REX_LOAD_U16(clip + 144u);
  if (f == 0u) f = 1u;
  const uint32_t list = cc_asmap_find(base, s + 64u, f);
  if (list == 0u) return;
  CcFrame frame(ctx, base, 288u);
  const uint32_t r1 = ctx.r1.u32;
  const uint32_t found = cc_asmap_find(base, s + 24u, f);
  REX_STORE_U32(s + 4u, found);
  const uint32_t n = REX_LOAD_U32(list + 0u);
  for (uint32_t i = 0; i < n; ++i) {
    const uint32_t code = REX_LOAD_U32(REX_LOAD_U32(list + 4u) + i * 8u + 4u);
    REX_STORE_U8(r1 + 96u, 0u);
    CcAsLoop L{s, r1 + 104u, r1 + 120u, r1 + 96u};
    L.r6_clear = 1u;
    cc_as_loop_vm(base, L);
    // r22 = 0x82040000 - 7688
    if (cc_as_frame_loop(ctx, base, L, code, clip, 0x8203E1F8u, kAsEndOfFrame, i, 0x8207B82Cu)) {
      cc_as_stop_reset(ctx, base, s, 0x8207B870u, 0x8207B884u);
      break;
    }
  }
  if (REX_LOAD_U32(s + 4u) != 0u && found == 0u) {
    ctx.r3.u64 = s + 24u; ctx.r4.u64 = f; ctx.r5.u64 = REX_LOAD_U32(s + 4u);
    ctx.lr = 0x8207B8A8u;
    sub_820936B0(ctx, base);
  }
  REX_STORE_U32(s + 4u, 0u);
}

// Var assignment (as_ops_var.inc).
static uint32_t cc_as_var_assign(Context& ctx, Machine& base, uint32_t var, uint32_t v);

// Activation slab (host CC_AS_SLAB=1, Xbox build define CC_AS_SLAB_BUILD;
// off by default: locals then live outside the game heap, so the heap's
// contents and later placements differ from the original and state hashes
// no longer compare). The locals DefineLocal (3C, 41) and the inline
// SetVariable (A4) create in the innermost active function's member map
// take their Var, and an empty map its 16-entry array, from a 16 KiB block
// of the physical arena (checked to lie outside the game heap), handed out
// last-in first-out: CallCustomFunction rewinds it to its entry mark after
// the function's members are released. The heap free sub_8209BF18 returns
// at once for pointers outside the heap, so the releases (sub_82079A00, a
// regrow past 16 entries, Delete) need no change. A full slab falls back
// to the heap. This removes about four game-heap operations per local.
#ifndef CC_XBOX_DRIVER
static const bool g_as_slab_on = std::getenv("CC_AS_SLAB") != nullptr;
static uint32_t g_as_slab_peak = 0, g_as_slab_full = 0;
#elif defined(CC_AS_SLAB_BUILD)
static constexpr bool g_as_slab_on = true;
#else
static constexpr bool g_as_slab_on = false;
#endif
static constexpr uint32_t kAsSlabBytes = 0x4000u;
static uint32_t g_as_slab = 0u, g_as_slab_top = 0u;  // slab 0: not yet, 0xFFFFFFFF: unusable
// First use (from CallCustomFunction): the block and its heap check.
static __attribute__((noinline, cold)) void cc_as_slab_init(Context& ctx, Machine& base) {
  const uint32_t hint = g_phys_zone_hint;
  g_phys_zone_hint = 0u;
  const uint32_t a = cc_phys_alloc(base, kAsSlabBytes, 16u);
  g_phys_zone_hint = hint;
  const uint32_t heap = REX_LOAD_U32(0x822673C0u + REX_LOAD_U8(ctx.r13.u32 + 268u) * 4u);
  const uint32_t lo = REX_LOAD_U32(heap + 8u), hi = REX_LOAD_U32(heap + 12u);
  const bool outside = a != 0u && (a + kAsSlabBytes <= lo || a >= hi);
  g_as_slab = outside ? a : 0xFFFFFFFFu;
  g_as_slab_top = a;
#ifndef CC_XBOX_DRIVER
  std::fprintf(stderr, "ASSLAB block=%08x heap=%08x..%08x %s\n", a, lo, hi, outside ? "used" : "unusable");
  static struct Report { ~Report() { std::fprintf(stderr, "ASSLAB peak=%u full=%u\n", g_as_slab_peak, g_as_slab_full); } } report;
#endif
}
// n bytes (16-byte steps) from the slab, or 0 when it is full or unusable.
static CC_AS_INL uint32_t cc_as_slab_alloc(uint32_t n) {
  const uint32_t step = (n + 15u) & ~15u;
  if (g_as_slab + 1u <= 1u || g_as_slab_top - g_as_slab + step > kAsSlabBytes) {
#ifndef CC_XBOX_DRIVER
    ++g_as_slab_full;
#endif
    return 0u;
  }
  const uint32_t p = g_as_slab_top;
  g_as_slab_top = p + step;
#ifndef CC_XBOX_DRIVER
  if (g_as_slab_top - g_as_slab > g_as_slab_peak) g_as_slab_peak = g_as_slab_top - g_as_slab;
#endif
  return p;
}
// Error report of CallCustomFunction: format fmt with the function's name
// (id 0 -> the string table's +12, else [table+28][id]) and, when set_r5,
// r5 (otherwise r5 stays as the last call left it, as in the original).
static __attribute__((noinline, cold)) void cc_as_call_error(Context& ctx, Machine& base, uint32_t s, uint32_t id, uint32_t fmt,
                                                             bool set_r5, uint32_t r5, uint32_t lr_a, uint32_t lr_b) {
  const uint32_t names = REX_LOAD_U32(cc_as_vm(base, s) + 10316u);
  const uint32_t k = id & 0xFFFFu;
  ctx.r3.u64 = fmt;
  ctx.r4.u64 = k ? REX_LOAD_U32(REX_LOAD_U32(names + 28u) + k * 4u) : names + 12u;
  if (set_r5) ctx.r5.u64 = r5;
  ctx.lr = lr_a;
  sub_820798D8(ctx, base);
  ctx.lr = lr_b;
  sub_8208C5D8(ctx, base);
}

// CallCustomFunction (exact sub_8207B150: S r3, name id r4, argc r5, argv
// r6 (slot pointers), return slot r7, stop byte r8). The function object is
// the S+44 map entry for the id, else the value of the variable of that
// name (an object, 4096 or 8192); none: error report, return. Its locals
// (u16 +32 Vars at +48, 8 bytes apart) are released and set undefined,
// the arguments stored into the first argc of them (sub_8208BF38), and the
// code (+36, leading zero bytes skipped, length s16 +30) runs with the
// function pushed on the VM's function stack and its clip (+40) on the
// update stack, until op 0, Return (62), the end, or the stop byte. Then
// sub_82079A00(function), the twelve Var slots' objects released and
// cleared, and both stacks popped. The body loop reads the length, the
// stop byte and the code bytes through host views when they are mapped
// (the length is still re-read before every instruction, as the original).
static CC_HOT_FN void sub_8207B150(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8207B150);
  CC_FPROF_SCOPE(sub_8207B150_native);
#ifdef CC_XBOX_DRIVER
  ++g_fc[1];
#endif
  cc_as_init_switches(base);
  const uint32_t s = ctx.r3.u32, id = ctx.r4.u32, argc = ctx.r5.u32, argv = ctx.r6.u32;
  const uint32_t ret = ctx.r7.u32, done = ctx.r8.u32;
#ifdef CC_OP_STATS
  uint64_t cc_t0 = __builtin_ia32_rdtsc();
  ++g_call_n;
#endif
  CcFrame frame(ctx, base, 272u);
  const uint32_t r1 = ctx.r1.u32;
  uint32_t fn = cc_asmap_find(base, s + 44u, id & 0xFFFFu);
  if (fn == 0u) {
    REX_STORE_U32(r1 + 148u, 0u);
    REX_STORE_U8(r1 + 152u, 0u);
    ctx.r3.u64 = s; ctx.r4.u64 = id; ctx.r5.u64 = r1 + 144u; ctx.lr = 0x8207B1B4u;
    sub_8207AF80(ctx, base);
    const uint32_t t = REX_LOAD_U32(r1 + 144u);
    if (t != kAsUndef) fn = cc_as_obj_of(base, r1 + 144u);
    if (fn == 0u) {
      cc_as_call_error(ctx, base, s, id, 0x8203E178u, false, 0u, 0x8207B230u, 0x8207B234u);  // 0x82040000 - 7816
      return;
    }
  }
  for (uint32_t i = 0; int32_t(i) < int32_t(REX_LOAD_U16(fn + 32u)); ++i) {
    const uint32_t var = REX_LOAD_U32(fn + 48u + i * 8u);
    if (REX_LOAD_U32(var + 0u) != 0u && (REX_LOAD_U32(var + 4u) & kAsRef) != 0u)
      cc_as_unref_obj(ctx, base, var + 0u, 0x8207B2C0u, 0x8207B2CCu);
    REX_STORE_U32(var + 0u, 0u);
    REX_STORE_U32(var + 4u, kAsUndef);
  }
  for (uint32_t k = 0; int32_t(k) < int32_t(argc); ++k) {
    const uint32_t v = REX_LOAD_U32(argv + k * 4u);
    ctx.r3.u64 = cc_as_var_assign(ctx, base, REX_LOAD_U32(fn + 48u + k * 8u), v);  // sub_8208BF38(fn, Var, arg)
  }
  const uint32_t code = REX_LOAD_U32(fn + 36u);
  if (code == 0u) return;
  uint32_t pc = 0;
  while (REX_LOAD_U8(code + pc) == 0u) ++pc;
  CcAsLoop L{s, r1 + 128u, ret, done};
  cc_as_loop_vm(base, L);
  {
    const uint32_t n = cc_as_vld(base, L, 10180u) + 1u;
    cc_as_vst(base, L, 10180u, n);
    cc_as_vst(base, L, (n + 2513u) * 4u, fn);
  }
  {
    const uint32_t c = REX_LOAD_U32(fn + 40u);
    const uint32_t n = cc_as_vld(base, L, 8248u) + 1u;
    cc_as_vst(base, L, 8248u, n);
    cc_as_vst(base, L, (n + 1998u) * 4u, c);
  }
  REX_STORE_U32(r1 + 128u, 0u);
  REX_STORE_U16(r1 + 132u, 0u);
  REX_STORE_U32(r1 + 136u, 0u);
  uint32_t slab_mark = 0u;
  if (g_as_slab_on) {
    if (g_as_slab == 0u) cc_as_slab_init(ctx, base);
    slab_mark = g_as_slab_top;
  }
#ifdef CC_OP_STATS
  g_call_setup += __builtin_ia32_rdtsc() - cc_t0;
#endif
  uint32_t hn;
  const uint8_t* const hc = cc_as_code_view(code, hn);
  const uint8_t* const hd = cc_as_host(done, 1u);
  const uint8_t* const hl = cc_as_host(fn + 30u, 2u);
  for (;;) {
    const uint32_t len = hl != nullptr ? cc_as_hld16(hl) : uint32_t(REX_LOAD_U16(fn + 30u));
    if (int32_t(pc) >= int32_t(int16_t(uint16_t(len)))) break;
    if (cc_as_stopped(base, done, hd)) break;
    uint32_t op;
    const uint32_t size = cc_as_fetch(base, L, code, hc, hn, pc, op);
    if (op == 0u) break;
    if (cc_as_no_handler_entry(base, op)) {
      REX_STORE_U32(L.rec + 0u, op);
      cc_as_call_error(ctx, base, s, id, 0x8203E1B4u, true, pc, 0x8207B470u, 0x8207B474u);  // 0x82040000 - 7756
    }
    const uint32_t r = cc_as_step(ctx, base, L, op, 0x8207B49Cu);
    // the original re-reads the record's op after the handler
    const uint32_t op_after = L.guest_ran ? REX_LOAD_U32(L.rec + 0u) : op;
    pc = r + size + pc;
    if (op_after == 62u) break;
  }
#ifdef CC_OP_STATS
  cc_t0 = __builtin_ia32_rdtsc();
#endif
  ctx.r3.u64 = fn; ctx.lr = 0x8207B4C8u;
  sub_82079A00(ctx, base);
  if (g_as_slab_on) g_as_slab_top = slab_mark;  // this call's locals are released
  for (uint32_t i = 0; i < 12u; ++i) {
    const uint32_t var = REX_LOAD_U32(fn + 48u + i * 8u);
    if (var == 0u || REX_LOAD_U32(var + 0u) == 0u) continue;
    if ((REX_LOAD_U32(var + 4u) & kAsRef) != 0u)
      cc_as_unref_obj(ctx, base, var + 0u, 0x8207B530u, 0x8207B53Cu);
    REX_STORE_U32(REX_LOAD_U32(fn + 48u + i * 8u) + 0u, 0u);
  }
  cc_as_vst(base, L, (cc_as_vld(base, L, 8248u) + 1998u) * 4u, 0u);
  cc_as_vst(base, L, 8248u, cc_as_vld(base, L, 8248u) - 1u);
  cc_as_vst(base, L, 10180u, cc_as_vld(base, L, 10180u) - 1u);
  ctx.r3.u64 = L.vm;
#ifdef CC_OP_STATS
  g_call_teardown += __builtin_ia32_rdtsc() - cc_t0;
#endif
}

// ---------------------------------------------------------------------------
// Native instruction handlers. Each takes the decoded instruction and
// returns the extra pc delta; the comments give the recompiled handler.

#include "as_ops.inc"
#include "as_render.inc"

#endif  // CC_FAST
