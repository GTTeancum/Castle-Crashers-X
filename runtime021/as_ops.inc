// Native ActionScript instruction handlers (included by as_native.inc).
// Each cc_as_op_XX mirrors the recompiled handler named in its comment:
// same pops, reference counting, slot frees, calls and stores, so the guest
// heap ends up identical. lr values are the original return addresses.
// The handlers take the running loop (CcAsOp) as their instruction: the VM
// it resolved and its host view replace the original's per-use
// [[[S+0]+76]+156] chains (the same VM; CC_ORACLE checks it per op).

// ActionScript Push item decode (exact sub_8207AA50: script r3, out value
// r4, data r5, pos* r6). type = data[pos++]; then, as the original reads
// the bytes b0.. that follow:
//  0 string: copied and interned (sub_82053A00, sub_8209D948 on the VM's
//    string table VM+10316) -> {8, id}; pos += length + 1
//  1 float: bits b0b1b2b3 (big-endian) -> {16, float}; pos += 4
//  2 nothing; 3 undefined {0x80000000, 0}; 4 -> {4, VM+30476}, pos += 1
//  5 bool: {2, b0 == 1}; pos += 1
//  6 double: bytes b3 b2 b1 b0 b7 b6 b5 b4 (big-endian) -> {16, float}
//  7 int: little-endian b0..b3 -> {4, int}; pos += 4
//  8/9 constant-pool index (u8 / LE u16) -> {8, pool[index]} from the
//    active function's pool (VM[(VM[10180] + 2513) * 4] -> +140 -> +0), or
//    the script's own pool ([r3+4] -> +0) when none is active
// VM = [[r3+0]+76]+156 (the loop's). Float values pass through f0 as in
// the original. The position is a host variable here; the guest-callable
// sub_8207AA50 below keeps it in guest memory.
// Constant pool of a Push item or name: the active function's pool, else
// the script's own (u16 string ids).
static CC_AS_INL uint32_t cc_as_pool_tbl(Machine& base, const CcAsLoop& L) {
  const uint32_t act = cc_as_act(base, L);
  return act ? REX_LOAD_U32(REX_LOAD_U32(act + 140u)) : REX_LOAD_U32(REX_LOAD_U32(L.s + 4u));
}
// The decode's rare items out of line: 0 inline string, 6 double.
static __attribute__((noinline)) void cc_as_decode_str(Context& ctx, Machine& base, const CcAsLoop& L, uint32_t out, uint32_t data, uint32_t& pos) {
  CcFrame frame(ctx, base, 208u);
  const uint32_t buf = ctx.r1.u32 + 96u;
  ctx.r3.u64 = buf; ctx.r4.u64 = data + pos; ctx.lr = 0x8207AACCu;
  sub_82053A00(ctx, base);
  pos = pos + REX_LOAD_U32(buf) + 1u;
  ctx.r3.u64 = cc_as_vld(base, L, 10316u); ctx.r4.u64 = buf + 4u; ctx.lr = 0x8207AAF8u;
  sub_8209D948(ctx, base);
  REX_STORE_U16(out + 4u, ctx.r3.u16);
  REX_STORE_U32(out + 0u, 8u);
}
static __attribute__((noinline)) void cc_as_decode_double(Context& ctx, Machine& base, uint32_t out, uint32_t data, uint32_t& pos) {
  auto b = [&](uint32_t k) { return uint32_t(REX_LOAD_U8(data + pos + k)); };
  const uint64_t bits = (uint64_t(b(3)) << 56) | (uint64_t(b(2)) << 48) | (uint64_t(b(1)) << 40) | (uint64_t(b(0)) << 32) |
                        (uint64_t(b(7)) << 24) | (uint64_t(b(6)) << 16) | (uint64_t(b(5)) << 8) | uint64_t(b(4));
  pos += 8u;
  REX_STORE_U32(out + 0u, 16u);
  ctx.fpscr.disableFlushMode();
  ctx.f0.u64 = bits;
  ctx.f13.f64 = double(float(ctx.f0.f64));
  PPCRegister temp{};
  temp.f32 = float(ctx.f13.f64);
  REX_STORE_U32(out + 4u, temp.u32);
}
static CC_HOT_FN void cc_as_decode(Context& ctx, Machine& base, const CcAsLoop& L, uint32_t out, uint32_t data, uint32_t& pos) {
  const uint32_t type = REX_LOAD_U8(data + pos);
  ++pos;
  auto b = [&](uint32_t k) { return uint32_t(REX_LOAD_U8(data + pos + k)); };
  switch (type) {
    case 0: cc_as_decode_str(ctx, base, L, out, data, pos); return;
    case 1: {
      const uint32_t bits = (b(0) << 24) | (b(1) << 16) | (b(2) << 8) | b(3);
      pos += 4u;
      REX_STORE_U32(out + 0u, 16u);
      ctx.fpscr.disableFlushMode();
      PPCRegister temp{};
      temp.u32 = bits;
      ctx.f0.f64 = double(temp.f32);
      temp.f32 = float(ctx.f0.f64);
      REX_STORE_U32(out + 4u, temp.u32);
      return;
    }
    case 3: REX_STORE_U32(out + 0u, 0x80000000u); REX_STORE_U32(out + 4u, 0u); return;
    case 4:
      pos += 1u;
      REX_STORE_U32(out + 0u, 4u);
      REX_STORE_U32(out + 4u, cc_as_vld(base, L, 30476u));
      return;
    case 5: {
      const uint32_t v = b(0);
      REX_STORE_U32(out + 0u, 2u);
      pos += 1u;
      REX_STORE_U8(out + 4u, v == 1u ? 1u : 0u);
      return;
    }
    case 6: cc_as_decode_double(ctx, base, out, data, pos); return;
    case 7: {
      const uint32_t v = (b(3) << 24) | (b(2) << 16) | (b(1) << 8) | b(0);
      pos += 4u;
      REX_STORE_U32(out + 0u, 4u);
      REX_STORE_U32(out + 4u, v);
      return;
    }
    case 8: {
      const uint32_t idx = b(0);
      pos += 1u;
      const uint32_t tbl = cc_as_pool_tbl(base, L);
      REX_STORE_U32(out + 0u, 8u);
      REX_STORE_U16(out + 4u, REX_LOAD_U16(tbl + ((idx << 1) & 0x1FEu)));
      return;
    }
    case 9: {
      const uint32_t idx = (b(1) << 8) | b(0);
      pos += 2u;
      const uint32_t tbl = cc_as_pool_tbl(base, L);
      REX_STORE_U32(out + 0u, 8u);
      REX_STORE_U16(out + 4u, REX_LOAD_U16(tbl + ((idx << 1) & 0x1FFFEu)));
      return;
    }
    default: return;  // 2 and anything above 9: nothing more
  }
}
static CC_HOT_FN void sub_8207AA50(Context& ctx, Machine& base) {
#ifndef CC_XBOX_DRIVER
  static const bool walk_exact = std::getenv("CC_WALK_EXACT") != nullptr;
  if (walk_exact) { sub_8207AA50_exact(ctx, base); return; }
#else
  #ifdef CC_WALK_EXACT_BUILD
  sub_8207AA50_exact(ctx, base); return;  // Xbox bisect build
#endif
  static_cast<void>(&sub_8207AA50_exact);
#endif
  const uint32_t posp = ctx.r6.u32;
  uint32_t pos = REX_LOAD_U32(posp);
  const CcAsLoop L = cc_as_loop_of(base, ctx.r3.u32);
  cc_as_decode(ctx, base, L, ctx.r4.u32, ctx.r5.u32, pos);
  REX_STORE_U32(posp, pos);
}

// Inline name decode (exact sub_8207A908: S r3, data r4, pos* r5; returns
// the u16 name id). type = data[pos++]:
//  0 inline string: copied (sub_82053A00 into a frame buffer) and interned
//    in the VM's string table (sub_8209D948(VM+10316)); pos += length + 1
//  8 / 9: constant-pool index (u8 / LE u16): the active function's pool
//    (VM[(VM[10180] + 2513) * 4] -> +140 -> +0), else the script's own
//    ([S+4] -> +0); pos += 1 / 2
//  anything else: 0.
static __attribute__((noinline)) uint32_t cc_as_name_str(Context& ctx, Machine& base, const CcAsLoop& L, uint32_t data, uint32_t& pos) {
  CcFrame frame(ctx, base, 176u);
  const uint32_t buf = ctx.r1.u32 + 80u;
  ctx.r3.u64 = buf; ctx.r4.u64 = data + pos; ctx.lr = 0x8207AA08u;
  sub_82053A00(ctx, base);
  pos = pos + REX_LOAD_U32(buf) + 1u;
  ctx.r3.u64 = cc_as_vld(base, L, 10316u); ctx.r4.u64 = buf + 4u; ctx.lr = 0x8207AA34u;
  sub_8209D948(ctx, base);
  return ctx.r3.u32 & 0xFFFFu;
}
static CC_AS_INL uint32_t cc_as_name(Context& ctx, Machine& base, const CcAsLoop& L, uint32_t data, uint32_t& pos) {
  const uint32_t t = REX_LOAD_U8(data + pos);
  ++pos;
  uint32_t idx2;
  if (t == 8u) {
    idx2 = (REX_LOAD_U8(data + pos) << 1) & 0x1FEu;
    pos += 1u;
  } else if (t == 9u) {
    idx2 = ((REX_LOAD_U8(data + pos) | (REX_LOAD_U8(data + pos + 1u) << 8)) << 1) & 0x1FFFEu;
    pos += 2u;
  } else if (t == 0u) {
    return cc_as_name_str(ctx, base, L, data, pos);
  } else {
    return 0u;
  }
  return REX_LOAD_U16(cc_as_pool_tbl(base, L) + idx2);
}
static CC_HOT_FN void sub_8207A908(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8207A908);
  CC_FPROF_SCOPE(sub_8207A908_native);
  const uint32_t posp = ctx.r5.u32;
  uint32_t pos = REX_LOAD_U32(posp);
  const CcAsLoop L = cc_as_loop_of(base, ctx.r3.u32);
  const uint32_t id = cc_as_name(ctx, base, L, ctx.r4.u32, pos);
  REX_STORE_U32(posp, pos);
  ctx.r3.u64 = id;
}

// ToBoolean (exact sub_82082670: value r3): bool -> its byte; number ->
// != 0.0; int, 512, 1024, 16384, 0x40000 -> payload != 0; else false.
static CC_HOT_FN inline uint32_t cc_as_tobool(Context& ctx, Machine& base, uint32_t v) {
  const uint32_t t = REX_LOAD_U32(v);
  switch (t) {
    case 2u: return REX_LOAD_U8(v + 4u);
    case 16u: {
      ctx.fpscr.disableFlushMode();
      PPCRegister x{};
      x.u32 = REX_LOAD_U32(v + 4u);
      PPCRegister z{};
      z.u32 = REX_LOAD_U32(0x82040000u + 9536u);
      return double(x.f32) != double(z.f32) ? 1u : 0u;
    }
    case 4u: case 512u: case 1024u: case 16384u: case 0x40000u:
      return REX_LOAD_U32(v + 4u) != 0u ? 1u : 0u;
    default: return 0u;
  }
}
static CC_HOT_FN void sub_82082670(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_82082670);
  CC_FPROF_SCOPE(sub_82082670_native);
  ctx.r3.u64 = cc_as_tobool(ctx, base, ctx.r3.u32);
}

// Push (exact sub_820814A0, op 0x96): for each item of the record's data
// (length rec.len): a pool slot (sub_82082488), decoded into (Push item
// decode), its object's reference count raised inline when the object
// (count nonzero) reports a counted type through slot 40, then pushed.
static CC_HOT_FN uint32_t cc_as_op_96(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_96);
  if (o.len == 0u) return 0u;
  uint32_t pos = 0;
  do {
    const uint32_t slot = cc_as_alloc(ctx, base, o, 0x820814E0u);
    cc_as_decode(ctx, base, o, slot, o.data, pos);
    if ((REX_LOAD_U32(slot) & kAsRef) != 0u) {
      const uint32_t obj = REX_LOAD_U32(slot + 4u);
      if (REX_LOAD_U16(obj + 24u) != 0u) {
        const uint32_t t = cc_vcall(ctx, base, obj, 40u, 0x82081544u);
        if ((t & kAsRef) != 0u) REX_STORE_U16(obj + 24u, uint16_t(REX_LOAD_U16(obj + 24u) + 1u));
      }
    }
    cc_as_push(base, o, slot);
  } while (int32_t(pos) < int32_t(o.len));
  return 0u;
}

// Pop with release as the handlers do it: returns the slot (re-read from
// the stack after the release).
static CC_AS_INL uint32_t cc_as_pop_release(Context& ctx, Machine& base, const CcAsOp& o, uint32_t lr_a, uint32_t lr_b) {
  const uint32_t v = cc_as_pop(base, o);
  cc_as_unref(ctx, base, v, lr_a, lr_b);
  return cc_as_top_slot(base, o);
}

// Pop (exact sub_8207CDA0, ops 0x17 and 0x9E): the top value's reference
// released and its slot freed.
static CC_HOT_FN uint32_t cc_as_op_17(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_17);
  cc_as_free(base, cc_as_pop_release(ctx, base, o, 0x8207CE1Cu, 0x8207CE28u));
  return 0u;
}

// Jump (exact sub_82081598, op 0x99): the signed LE u16 at data.
static CC_HOT_FN inline uint32_t cc_as_branch(Machine& base, uint32_t data) {
  return uint32_t(int32_t(int16_t(uint16_t(REX_LOAD_U8(data) | (REX_LOAD_U8(data + 1u) << 8)))));
}
static uint32_t cc_as_op_99(Context&, Machine& base, const CcAsOp& o) { return cc_as_branch(base, o.data); }

// If (exact sub_82081920, op 0x9D): pop, release, ToBoolean; true takes
// the branch offset at data. The slot is freed.
static CC_HOT_FN uint32_t cc_as_op_9D(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_9D);
  const uint32_t slot = cc_as_pop_release(ctx, base, o, 0x82081998u, 0x820819A4u);
  const uint32_t r = (cc_as_tobool(ctx, base, slot) & 0xFFu) != 0u ? cc_as_branch(base, o.data) : 0u;
  cc_as_free(base, slot);
  return r;
}

// Return (exact sub_8207E308, op 0x3E): pop, release, the slot's 12 bytes
// copied to the return slot (r6), the slot freed.
static CC_HOT_FN uint32_t cc_as_op_3E(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_3E);
  const uint32_t slot = cc_as_pop_release(ctx, base, o, 0x8207E380u, 0x8207E38Cu);
  REX_STORE_U32(o.r6 + 0u, REX_LOAD_U32(slot + 0u));
  REX_STORE_U32(o.r6 + 4u, REX_LOAD_U32(slot + 4u));
  REX_STORE_U32(o.r6 + 8u, REX_LOAD_U32(slot + 8u));
  cc_as_free(base, slot);
  return 0u;
}

// GetVariable (as_ops_var.inc).
static uint32_t cc_as_get_variable(Context& ctx, Machine& base, const CcAsLoop& L, uint32_t id, uint32_t out);

// Variable read into a new slot, referenced and pushed (the tail shared by
// A0 and A1): sub_82082488, GetVariable sub_8207AF80(S, id, slot).
static CC_AS_INL void cc_as_push_var(Context& ctx, Machine& base, const CcAsOp& o, uint32_t id, uint32_t lr_alloc,
                                     uint32_t lr_ref) {
  const uint32_t slot = cc_as_alloc(ctx, base, o, lr_alloc);
  cc_as_get_variable(ctx, base, o, id, slot);
  cc_as_ref(ctx, base, slot, lr_ref);
  cc_as_push(base, o, slot);
}

// GetVariable with an inline name (exact sub_82081C08, op 0xA0): name from
// data (inline name decode), value pushed. Returns 1.
static CC_HOT_FN uint32_t cc_as_op_A0(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_A0);
  uint32_t pos = 0;
  const uint32_t id = cc_as_name(ctx, base, o, o.data, pos);
  cc_as_push_var(ctx, base, o, id, 0x82081C5Cu, 0x82081CA0u);
  return 1u;
}

// Push one item then GetVariable inline (exact sub_82081CD8, op 0xA1): a
// decoded item pushed (referenced), then a name from the same data and its
// variable's value pushed. Returns 1.
static CC_HOT_FN uint32_t cc_as_op_A1(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_A1);
  uint32_t pos = 0;
  const uint32_t slot = cc_as_alloc(ctx, base, o, 0x82081D10u);
  cc_as_decode(ctx, base, o, slot, o.data, pos);
  cc_as_ref(ctx, base, slot, 0x82081D60u);
  cc_as_push(base, o, slot);
  const uint32_t id = cc_as_name(ctx, base, o, o.data, pos);
  cc_as_push_var(ctx, base, o, id, 0x82081DACu, 0x82081DF0u);
  return 1u;
}

// SetVariable on an object (as_ops_var.inc).
static inline void cc_as_set_member(Context& ctx, Machine& base, uint32_t obj, uint32_t id, uint32_t v);

// SetVariable inline (exact sub_820822D8, op 0xA4): name, then an item
// decoded into a frame temporary {type, payload, in-use} at frame+88; with
// an active function (VM function stack) the variable is set through
// sub_8208C2A0(function, id, temp), else through the current clip's slot
// 16 (r4 id, r5 temp). Returns 1.
static CC_HOT_FN uint32_t cc_as_op_A4(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_A4);
  CcFrame frame(ctx, base, 144u);
  const uint32_t tmp = ctx.r1.u32 + 88u;
  uint32_t pos = 0;
  const uint32_t id = cc_as_name(ctx, base, o, o.data, pos);
  REX_STORE_U32(tmp + 4u, 0u);
  REX_STORE_U8(tmp + 8u, 0u);
  cc_as_decode(ctx, base, o, tmp, o.data, pos);
  const uint32_t act = cc_as_act(base, o);
  if (act != 0u) {
    cc_as_set_member(ctx, base, act, id, tmp);
  } else {
    const uint32_t clip = cc_as_top_clip(base, o);
    ctx.r4.u64 = id; ctx.r5.u64 = tmp;
    cc_vcall(ctx, base, clip, 16u, 0x82082380u);
  }
  return 1u;
}

// CallFunction (exact sub_8207E048, op 0x3D): pops the name and the
// argument count, then (count not undefined) ToInt(count) arguments into a
// frame array, the count slot set undefined to take the result; the
// current clip's slot 20 runs the call (r4 VM, r5 name id (ToString id
// sub_82082890), r6 argc, r7 args, r8 result slot, r9 stop byte). The
// result is referenced and pushed, the argument and name slots freed.
static CC_HOT_FN uint32_t cc_as_op_3D(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_3D);
  CcFrame frame(ctx, base, 240u);
  const uint32_t args = ctx.r1.u32 + 80u;
  const uint32_t name = cc_as_pop_release(ctx, base, o, 0x8207E0C4u, 0x8207E0D0u);
  const uint32_t res = cc_as_pop_release(ctx, base, o, 0x8207E144u, 0x8207E150u);
  ctx.r3.u64 = name; ctx.lr = 0x8207E15Cu;
  sub_82082890(ctx, base);
  const uint32_t id = ctx.r3.u32;
  uint32_t argc = 0;
  if (REX_LOAD_U32(res) != kAsUndef) {
    ctx.r3.u64 = res; ctx.lr = 0x8207E180u;
    sub_82082BB0(ctx, base);
    argc = ctx.r3.u32;
    for (uint32_t k = 0; int32_t(k) < int32_t(argc); ++k)
      REX_STORE_U32(args + k * 4u, cc_as_pop_release(ctx, base, o, 0x8207E204u, 0x8207E210u));
    REX_STORE_U32(res + 0u, kAsUndef);
    REX_STORE_U32(res + 4u, 0u);
  }
  {
    const uint32_t clip = cc_as_top_clip(base, o);
    ctx.r4.u64 = o.vm; ctx.r5.u64 = id; ctx.r6.u64 = argc; ctx.r7.u64 = args; ctx.r8.u64 = res; ctx.r9.u64 = o.done;
    cc_vcall(ctx, base, clip, 20u, 0x8207E28Cu);
  }
  cc_as_ref(ctx, base, res, 0x8207E2B4u);
  cc_as_push(base, o, res);
  for (uint32_t k = 0; int32_t(k) < int32_t(argc); ++k) cc_as_free(base, REX_LOAD_U32(args + k * 4u));
  cc_as_free(base, name);
  return 0u;
}

// CallMethod (exact sub_8207FE10, op 0x52): pops method name, object and
// argument count; arguments as CallFunction. Object or name undefined: no
// call. A string object (8) calls the string method table sub_8207A5D8 on
// a frame string object {vtable 0x8203E41C, ..., +108 id of the string}
// (after the current clip's slot 140), then sub_82079970 destroys it.
// Objects 64, 128, 512, 1024, 4096, 8192, 0x8000 (counted or 4096/8192
// with a payload) call the object's slot 20 (r4 VM, r5 method id, r6 argc,
// r7 args, r8 result slot, r9 stop byte); afterwards, if the current clip
// answers slot 24 and is gone (count 0) or its slot 140 changed across the
// call, the stop byte is set. Unless stopped, the result is referenced and
// pushed; argument, name and object slots are freed.
// CallMethod on a string (out of line: rare): the frame string object so.
static __attribute__((noinline)) void cc_as_op_52_str(Context& ctx, Machine& base, const CcAsOp& o, uint32_t so, uint32_t obj, uint32_t name,
                                                      uint32_t argc, uint32_t args, uint32_t res) {
  REX_STORE_U32(so + 4u, 0u);
  REX_STORE_U32(so + 8u, 0u);
  REX_STORE_U32(so + 12u, 0u);
  REX_STORE_U32(so + 16u, 1u);
  REX_STORE_U32(so + 0u, 0x8203E41Cu);  // 0x82040000 - 7140
  REX_STORE_U8(so + 20u, 0u);
  REX_STORE_U16(so + 24u, 0u);
  ctx.r3.u64 = obj; ctx.lr = 0x820800F0u;
  sub_82082890(ctx, base);
  REX_STORE_U16(so + 28u, ctx.r3.u16);
  cc_vcall(ctx, base, cc_as_top_clip(base, o), 140u, 0x82080118u);
  ctx.r3.u64 = name; ctx.lr = 0x82080130u;
  sub_82082890(ctx, base);
  ctx.r5.u64 = ctx.r3.u32; ctx.r4.u64 = o.vm; ctx.r3.u64 = so; ctx.r6.u64 = argc; ctx.r7.u64 = args;
  ctx.r8.u64 = res; ctx.r9.u64 = o.done; ctx.lr = 0x8208014Cu;
  sub_8207A5D8(ctx, base);
  REX_STORE_U32(so + 0u, 0x8203E41Cu);
  ctx.r3.u64 = so; ctx.lr = 0x82080158u;
  sub_82079970(ctx, base);
}
static CC_HOT_FN uint32_t cc_as_op_52(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_52);
  CcFrame frame(ctx, base, 272u);
  const uint32_t r1 = ctx.r1.u32;
  const uint32_t args = r1 + 112u;
  const uint32_t name = cc_as_pop_release(ctx, base, o, 0x8207FE8Cu, 0x8207FE98u);
  const uint32_t obj = cc_as_pop_release(ctx, base, o, 0x8207FF0Cu, 0x8207FF18u);
  const uint32_t res = cc_as_pop_release(ctx, base, o, 0x8207FF8Cu, 0x8207FF98u);
  uint32_t argc = 0;
  if (REX_LOAD_U32(res) != kAsUndef) {
    ctx.r3.u64 = res; ctx.lr = 0x8207FFC4u;
    sub_82082BB0(ctx, base);
    argc = ctx.r3.u32;
    for (uint32_t k = 0; int32_t(k) < int32_t(argc); ++k)
      REX_STORE_U32(args + k * 4u, cc_as_pop_release(ctx, base, o, 0x82080040u, 0x8208004Cu));
    REX_STORE_U32(res + 0u, kAsUndef);
    REX_STORE_U32(res + 4u, 0u);
  }
  const uint32_t t = REX_LOAD_U32(obj);
  if (t != kAsUndef && REX_LOAD_U32(name) != kAsUndef) {
    const int32_t st = int32_t(t);
    bool objcall = false;
    if (st == 8) {
      cc_as_op_52_str(ctx, base, o, r1 + 80u, obj, name, argc, args, res);
    } else if (st == 1024 || st == 128 || st == 64 || st == 512 || t == 4096u || t == 8192u || t == 32768u) {
      objcall = (t & kAsRef) != 0u || t == 4096u || t == 8192u;
    }
    if (objcall && REX_LOAD_U32(obj + 4u) != 0u) {
      const uint32_t target = REX_LOAD_U32(obj + 4u);
      const uint32_t before = cc_vcall(ctx, base, cc_as_top_clip(base, o), 140u, 0x820801DCu);
      ctx.r3.u64 = name; ctx.lr = 0x820801F8u;
      sub_82082890(ctx, base);
      ctx.r5.u64 = ctx.r3.u32; ctx.r4.u64 = o.vm; ctx.r6.u64 = argc; ctx.r7.u64 = args; ctx.r8.u64 = res; ctx.r9.u64 = o.done;
      cc_vcall(ctx, base, target, 20u, 0x82080220u);
      const uint32_t clip = cc_as_top_clip(base, o);
      if ((cc_vcall(ctx, base, clip, 24u, 0x82080244u) & 0xFFFFu) != 0u) {
        const uint32_t top = cc_as_top_clip(base, o);
        if (REX_LOAD_U16(top + 24u) == 0u || cc_vcall(ctx, base, top, 140u, 0x820802B0u) != before)
          REX_STORE_U8(o.done, 1u);
      }
    }
  }
  if (REX_LOAD_U8(o.done) == 0u) {
    cc_as_ref(ctx, base, res, 0x8208030Cu);
    cc_as_push(base, o, res);
  }
  for (uint32_t k = 0; int32_t(k) < int32_t(argc); ++k) cc_as_free(base, REX_LOAD_U32(args + k * 4u));
  cc_as_free(base, name);
  cc_as_free(base, obj);
  return 0u;
}

#include "as_ops_more.inc"

// Native opcode table (g_as_fn; opcodes left null run their guest
// handler).
static void cc_as_fill_ops() {
  g_as_fn[0x96u] = cc_as_op_96;
  g_as_fn[0x17u] = cc_as_op_17;
  g_as_fn[0x9Eu] = cc_as_op_17;
  g_as_fn[0x99u] = cc_as_op_99;
  g_as_fn[0x9Du] = cc_as_op_9D;
  g_as_fn[0x3Eu] = cc_as_op_3E;
  g_as_fn[0xA0u] = cc_as_op_A0;
  g_as_fn[0xA1u] = cc_as_op_A1;
  g_as_fn[0xA4u] = cc_as_op_A4;
  g_as_fn[0x3Du] = cc_as_op_3D;
  g_as_fn[0x52u] = cc_as_op_52;
#include "as_ops_more_cases.inc"
}
