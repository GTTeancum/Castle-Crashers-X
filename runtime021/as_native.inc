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
static bool cc_as_exact_fn(const char* name) {
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

// VM of a script context: [[[S+0]+76]+156].
static inline uint32_t cc_as_vm(Machine& base, uint32_t s) {
  return REX_LOAD_U32(REX_LOAD_U32(REX_LOAD_U32(s + 0u) + 76u) + 156u);
}
static inline uint32_t cc_as_pool(Machine& base, uint32_t s) { return cc_as_vm(base, s) + 10372u; }
// Clip on top of the VM's update stack.
static inline uint32_t cc_as_top_clip(Machine& base, uint32_t vm) {
  return REX_LOAD_U32(vm + (REX_LOAD_U32(vm + 8248u) + 1998u) * 4u);
}
// Value stack pop as every handler does it: count decremented and stored,
// then the slot pointer read.
static inline uint32_t cc_as_pop(Machine& base, uint32_t p) {
  const uint32_t n = REX_LOAD_U32(p + 5024u) - 1u;
  REX_STORE_U32(p + 5024u, n);
  return REX_LOAD_U32(p + n * 4u);
}
static inline void cc_as_push(Machine& base, uint32_t p, uint32_t slot) {
  REX_STORE_U32(p + REX_LOAD_U32(p + 5024u) * 4u, slot);
  REX_STORE_U32(p + 5024u, REX_LOAD_U32(p + 5024u) + 1u);
}
// Slot returned to the pool: in-use byte and payload cleared.
static inline void cc_as_free(Machine& base, uint32_t slot) {
  REX_STORE_U8(slot + 8u, 0u);
  REX_STORE_U32(slot + 4u, 0u);
}
// Reference released for a value leaving the stack (the handlers' common
// sequence after a pop): a reference-counted object with a nonzero count
// first gets its slot-4 method when this is the last reference, then
// sub_82066EA8(object, 0) decrements the count.
static inline void cc_as_unref_obj(Context& ctx, Machine& base, uint32_t holder, uint32_t lr_a, uint32_t lr_b) {
  // holder: address of the object pointer (slot + 4, or Var + 0)
  const uint32_t obj = REX_LOAD_U32(holder);
  const uint32_t rc = REX_LOAD_U16(obj + 24u);
  if (rc == 0u) return;
  if (rc == 1u) cc_vcall(ctx, base, obj, 4u, lr_a);
  ctx.r3.u64 = REX_LOAD_U32(holder);
  ctx.r4.u64 = 0u;
  ctx.lr = lr_b;
  sub_82066EA8(ctx, base);
}
static inline void cc_as_unref(Context& ctx, Machine& base, uint32_t slot, uint32_t lr_a, uint32_t lr_b) {
  if ((REX_LOAD_U32(slot) & kAsRef) == 0u) return;
  cc_as_unref_obj(ctx, base, slot + 4u, lr_a, lr_b);
}
// Reference taken for a value pushed on the stack: sub_82066EA8(object, 1)
// for a reference-counted object whose count is nonzero.
static inline void cc_as_ref(Context& ctx, Machine& base, uint32_t slot, uint32_t lr) {
  if ((REX_LOAD_U32(slot) & kAsRef) == 0u) return;
  const uint32_t obj = REX_LOAD_U32(slot + 4u);
  if (REX_LOAD_U16(obj + 24u) == 0u) return;
  ctx.r3.u64 = obj;
  ctx.r4.u64 = 1u;
  ctx.lr = lr;
  sub_82066EA8(ctx, base);
}
// Object pointer of a value as the handlers test it: reference-counted
// types, 4096 and 8192 give the payload; anything else 0.
static inline uint32_t cc_as_obj_of(Machine& base, uint32_t slot) {
  const uint32_t t = REX_LOAD_U32(slot);
  if ((t & kAsRef) != 0u || t == 4096u || t == 8192u) return REX_LOAD_U32(slot + 4u);
  return 0u;
}

// One decoded instruction for a native handler. data/len are the record's
// (possibly stale) values; r6 and done are the loop's extra arguments (the
// return-value slot and the stop byte).
struct CcAsOp {
  uint32_t s, op, len, data, r6, done;
};

// Native handlers return the extra pc delta like the recompiled ones.
static uint32_t cc_as_native_op(Context& ctx, Machine& base, const CcAsOp& o, bool& handled);

// Guest handler for an opcode (the table at 0x8215A518), called with the
// record already stored at rec.
static uint32_t cc_as_guest_op(Context& ctx, Machine& base, uint32_t op, uint32_t s, uint32_t rec,
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

// Per-opcode choice: true runs the guest handler (host CC_AS_GUEST list or
// CC_AS_EXACT; opcodes without a native handler fall back by themselves).
static bool g_as_guest[256];
static void cc_as_init_switches() {
  static bool done = false;
  if (done) return;
  done = true;
#ifndef CC_XBOX_DRIVER
  const bool all = std::getenv("CC_AS_EXACT") != nullptr;
  const char* l = std::getenv("CC_AS_GUEST");
  for (unsigned op = 0; op < 256u; ++op) {
    char hex[8];
    std::snprintf(hex, sizeof(hex), "%02X", op);
    g_as_guest[op] = all || (l && std::strstr(l, hex) != nullptr);
  }
#endif
}

// Runs one instruction: native handler unless switched off, else the guest
// handler with the record written to rec first (the loop passes the record
// fields it keeps in variables). Returns the handler's extra pc delta.
struct CcAsLoop {
  uint32_t s, rec, r6, done;
  uint32_t len = 0, data = 0;    // record fields as the original keeps them
  uint32_t r6_clear = 0;         // OnEnterFrame-style loops clear r6+4/+8 per op
};
static inline uint32_t cc_as_step(Context& ctx, Machine& base, CcAsLoop& L, uint32_t op, uint32_t lr) {
  if (!g_as_guest[op]) {
    const CcAsOp o{L.s, op, L.len, L.data, L.r6, L.done};
    bool handled = false;
    const uint32_t r = cc_as_native_op(ctx, base, o, handled);
    if (handled) return r;
  }
  REX_STORE_U32(L.rec + 0u, op);
  REX_STORE_U16(L.rec + 4u, uint16_t(L.len));
  REX_STORE_U32(L.rec + 8u, L.data);
  if (L.r6_clear) { REX_STORE_U32(L.r6 + 4u, 0u); REX_STORE_U8(L.r6 + 8u, 0u); }
  return cc_as_guest_op(ctx, base, op, L.s, L.rec, L.r6, L.done, lr);
}
// Instruction fetch: op byte, and for op >= 0x80 the little-endian u16
// length; a nonzero length moves the data pointer to the bytes after it.
// Returns the instruction size.
static inline uint32_t cc_as_fetch(Machine& base, CcAsLoop& L, uint32_t code, uint32_t pc, uint32_t& op) {
  op = REX_LOAD_U8(code + pc);
  if (op < 0x80u) return 1u;
  const uint32_t le = REX_LOAD_U8(code + pc + 1u) | (REX_LOAD_U8(code + pc + 2u) << 8);
  L.len = le;
  if (le == 0u) return 3u;
  L.data = code + pc + 3u;
  return le + 3u;
}
// Missing handler (never seen in the shipped scripts): the original's
// error report through the current clip's name (slots 52, 72, 24), the
// format string fmt and sub_820798D8/sub_8208C5D8.
static void cc_as_no_handler(Context& ctx, Machine& base, uint32_t s, uint32_t clip, uint32_t fmt,
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
static inline void cc_as_stop_reset(Context& ctx, Machine& base, uint32_t s, uint32_t lr_a, uint32_t lr_b) {
  ctx.r3.u64 = s; ctx.lr = lr_a;
  sub_8207A0D0(ctx, base);
  ctx.r3.u64 = cc_as_pool(base, s); ctx.lr = lr_b;
  sub_82079B48(ctx, base);
}

// OnEnterFrame (exact sub_8207BAE8: S r3). Code at S+20 (none: return);
// S+4 takes S+12; ops run from pc 0 until op 0 or the stop byte (frame
// +96); record at frame+104, return slot frame+120 (+4/+8 cleared per op).
// Stopped: sub_8207A0D0 + pool reset; otherwise S+12 takes S+4 if S+12 is
// empty and S+4 is set. S+4 is cleared.
static void sub_8207BAE8(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8207BAE8);
  CC_FPROF_SCOPE(sub_8207BAE8_native);
  cc_as_init_switches();
  const uint32_t s = ctx.r3.u32;
  const uint32_t code = REX_LOAD_U32(s + 20u);
  if (code == 0u) return;
  CcFrame frame(ctx, base, 224u);
  const uint32_t r1 = ctx.r1.u32;
  const uint32_t vm = cc_as_vm(base, s);
  const uint32_t clip = cc_as_top_clip(base, vm);
  REX_STORE_U32(s + 4u, REX_LOAD_U32(s + 12u));
  REX_STORE_U8(r1 + 96u, 0u);
  CcAsLoop L{s, r1 + 104u, r1 + 120u, r1 + 96u};
  L.r6_clear = 1u;
  uint32_t pc = 0;
  bool stopped = false;
  for (;;) {
    uint32_t op;
    const uint32_t size = cc_as_fetch(base, L, code, pc, op);
    if (op == 0u) break;
    if (REX_LOAD_U32(0x8215A518u + op * 4u) == 0u)
      cc_as_no_handler(ctx, base, s, clip, 0x8203E284u, pc + size, 0u, 0u);  // r25 = 0x82040000 - 7548
    pc = cc_as_step(ctx, base, L, op, 0x8207BC94u) + size + pc;
    if (REX_LOAD_U8(L.done) != 0u) { stopped = true; break; }
  }
  if (stopped) {
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
static void sub_8207B8B8(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8207B8B8);
  CC_FPROF_SCOPE(sub_8207B8B8_native);
  cc_as_init_switches();
  const uint32_t s = ctx.r3.u32;
  if (REX_LOAD_U32(s + 16u) == 0u) return;
  CcFrame frame(ctx, base, 224u);
  const uint32_t r1 = ctx.r1.u32;
  const uint32_t clip = cc_as_top_clip(base, cc_as_vm(base, s));
  cc_vcall(ctx, base, clip, 52u, 0x8207B92Cu);
  REX_STORE_U32(s + 4u, REX_LOAD_U32(s + 8u));
  REX_STORE_U8(r1 + 96u, 0u);
  const uint32_t code = REX_LOAD_U32(s + 16u);
  CcAsLoop L{s, r1 + 104u, r1 + 120u, r1 + 96u};
  L.r6_clear = 1u;
  uint32_t pc = 0;
  bool stopped = false;
  for (;;) {
    uint32_t op;
    const uint32_t size = cc_as_fetch(base, L, code, pc, op);
    if (op == 0u) break;
    if (REX_LOAD_U32(0x8215A518u + op * 4u) == 0u)
      cc_as_no_handler(ctx, base, s, clip, 0x8203E248u, pc, 0u, 0u);  // r24 = 0x82040000 - 7608
    pc = cc_as_step(ctx, base, L, op, 0x8207BA74u) + size + pc;
    if (REX_LOAD_U8(L.done) != 0u) { stopped = true; break; }
  }
  if (stopped) {
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
static void sub_8207B630(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8207B630);
  CC_FPROF_SCOPE(sub_8207B630_native);
  cc_as_init_switches();
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
    uint32_t pc = 0;
    for (;;) {
      uint32_t op;
      const uint32_t size = cc_as_fetch(base, L, code, pc, op);
      if (op == 0u) break;
      if (REX_LOAD_U32(0x8215A518u + op * 4u) == 0u)
        cc_as_no_handler(ctx, base, s, clip, 0x8203E1F8u, i, pc, 0u);  // r22 = 0x82040000 - 7688
      pc = cc_as_step(ctx, base, L, op, 0x8207B82Cu) + size + pc;
      if (REX_LOAD_U8(L.done) != 0u) {
        cc_as_stop_reset(ctx, base, s, 0x8207B870u, 0x8207B884u);
        goto finish;
      }
    }
  }
finish:
  if (REX_LOAD_U32(s + 4u) != 0u && found == 0u) {
    ctx.r3.u64 = s + 24u; ctx.r4.u64 = f; ctx.r5.u64 = REX_LOAD_U32(s + 4u);
    ctx.lr = 0x8207B8A8u;
    sub_820936B0(ctx, base);
  }
  REX_STORE_U32(s + 4u, 0u);
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
// cleared, and both stacks popped.
static void sub_8207B150(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8207B150);
  CC_FPROF_SCOPE(sub_8207B150_native);
  cc_as_init_switches();
  const uint32_t s = ctx.r3.u32, id = ctx.r4.u32, argc = ctx.r5.u32, argv = ctx.r6.u32;
  const uint32_t ret = ctx.r7.u32, done = ctx.r8.u32;
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
      const uint32_t names = REX_LOAD_U32(cc_as_vm(base, s) + 10316u);
      const uint32_t k = id & 0xFFFFu;
      ctx.r3.u64 = 0x8203E178u;  // 0x82040000 - 7816
      ctx.r4.u64 = k ? REX_LOAD_U32(REX_LOAD_U32(names + 28u) + k * 4u) : names + 12u;
      ctx.lr = 0x8207B230u;
      sub_820798D8(ctx, base);
      ctx.lr = 0x8207B234u;
      sub_8208C5D8(ctx, base);
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
    ctx.r3.u64 = fn; ctx.r5.u64 = REX_LOAD_U32(argv + k * 4u); ctx.r4.u64 = REX_LOAD_U32(fn + 48u + k * 8u);
    ctx.lr = 0x8207B30Cu;
    sub_8208BF38(ctx, base);
  }
  const uint32_t code = REX_LOAD_U32(fn + 36u);
  if (code == 0u) return;
  uint32_t pc = 0;
  while (REX_LOAD_U8(code + pc) == 0u) ++pc;
  {
    const uint32_t vm = cc_as_vm(base, s);
    const uint32_t n = REX_LOAD_U32(vm + 10180u) + 1u;
    REX_STORE_U32(vm + 10180u, n);
    REX_STORE_U32(vm + (n + 2513u) * 4u, fn);
  }
  {
    const uint32_t vm = cc_as_vm(base, s);
    const uint32_t c = REX_LOAD_U32(fn + 40u);
    const uint32_t n = REX_LOAD_U32(vm + 8248u) + 1u;
    REX_STORE_U32(vm + 8248u, n);
    REX_STORE_U32(vm + (n + 1998u) * 4u, c);
  }
  REX_STORE_U32(r1 + 128u, 0u);
  REX_STORE_U16(r1 + 132u, 0u);
  REX_STORE_U32(r1 + 136u, 0u);
  CcAsLoop L{s, r1 + 128u, ret, done};
  while (int32_t(pc) < int32_t(int16_t(REX_LOAD_U16(fn + 30u)))) {
    if (REX_LOAD_U8(done) != 0u) break;
    uint32_t op;
    const uint32_t size = cc_as_fetch(base, L, code, pc, op);
    if (op == 0u) break;
    if (REX_LOAD_U32(0x8215A518u + op * 4u) == 0u) {
      REX_STORE_U32(L.rec + 0u, op);
      const uint32_t names = REX_LOAD_U32(cc_as_vm(base, s) + 10316u);
      const uint32_t k = id & 0xFFFFu;
      ctx.r3.u64 = 0x8203E1B4u;  // 0x82040000 - 7756
      ctx.r4.u64 = k ? REX_LOAD_U32(REX_LOAD_U32(names + 28u) + k * 4u) : names + 12u;
      ctx.r5.u64 = pc;
      ctx.lr = 0x8207B470u;
      sub_820798D8(ctx, base);
      ctx.lr = 0x8207B474u;
      sub_8208C5D8(ctx, base);
    }
    const bool native = !g_as_guest[op];
    const uint32_t r = cc_as_step(ctx, base, L, op, 0x8207B49Cu);
    // the original re-reads the record's op after the handler
    const uint32_t op_after = native ? op : REX_LOAD_U32(L.rec + 0u);
    pc = r + size + pc;
    if (op_after == 62u) break;
  }
  ctx.r3.u64 = fn; ctx.lr = 0x8207B4C8u;
  sub_82079A00(ctx, base);
  for (uint32_t i = 0; i < 12u; ++i) {
    const uint32_t var = REX_LOAD_U32(fn + 48u + i * 8u);
    if (var == 0u || REX_LOAD_U32(var + 0u) == 0u) continue;
    if ((REX_LOAD_U32(var + 4u) & kAsRef) != 0u)
      cc_as_unref_obj(ctx, base, var + 0u, 0x8207B530u, 0x8207B53Cu);
    REX_STORE_U32(REX_LOAD_U32(fn + 48u + i * 8u) + 0u, 0u);
  }
  {
    const uint32_t vm = cc_as_vm(base, s);
    REX_STORE_U32(vm + (REX_LOAD_U32(vm + 8248u) + 1998u) * 4u, 0u);
    REX_STORE_U32(vm + 8248u, REX_LOAD_U32(vm + 8248u) - 1u);
  }
  {
    const uint32_t vm = cc_as_vm(base, s);
    REX_STORE_U32(vm + 10180u, REX_LOAD_U32(vm + 10180u) - 1u);
    ctx.r3.u64 = vm;
  }
}

// ---------------------------------------------------------------------------
// Native instruction handlers. Each takes the decoded instruction and
// returns the extra pc delta; the comments give the recompiled handler.

#include "as_ops.inc"
#include "as_render.inc"

#endif  // CC_FAST
