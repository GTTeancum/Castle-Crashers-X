// Native variable and member handlers and helpers (included by as_ops.inc).

// Game heap as the AS code fetches it: unless the flag at 0x8228A7B7 is set,
// sub_820A71E8(0x8222F918, 0x02000000, 0, 32) sets the heaps up first; the
// heap is the table at 0x822673C0 indexed by sub_820B5EB8.
static CC_HOT_FN inline uint32_t cc_as_game_heap(Context& ctx, Machine& base, uint32_t lr_init, uint32_t lr_idx) {
  if (REX_LOAD_U8(0x8228A7B7u) == 0u) {
    ctx.r3.u64 = 0x8222F918u; ctx.r4.u64 = 0x02000000u; ctx.r5.u64 = 0u; ctx.r6.u64 = 32u;
    ctx.lr = lr_init;
    sub_820A71E8(ctx, base);
  }
  ctx.lr = lr_idx;
  sub_820B5EB8(ctx, base);
  return REX_LOAD_U32(0x822673C0u + ctx.r3.u32 * 4u);
}

// Var assignment (exact sub_8208BF38: object r3 (unused), Var r4, value r5;
// returns 1, or 0 for an unknown type). The object the Var holds (+0, type
// at +4 counted) is released like a popped value (slot 4 at the last
// reference, then sub_82066EA8(object, 0)) and +0 cleared. No value:
// undefined. By the value's type: undefined -> undefined; bool 2 -> {2,
// ToBoolean byte}; int 4 -> {4, ToInt sub_82082BB0}; string 8 and 32 -> {8,
// u16 ToString id sub_82082890}; number 16 -> {16, ToNumber sub_82082700 as
// float}; objects 1, 64, 128, 512, 1024, 16384, 32768 -> type 1 with +0 the
// value's object (counted, 4096 or 8192 payload, else 0) and
// sub_82066EA8(+0, 1), even for 0; anything else -> undefined, returns 0.
static CC_HOT_FN inline uint32_t cc_as_var_assign(Context& ctx, Machine& base, uint32_t var, uint32_t v) {
  if (REX_LOAD_U32(var + 0u) != 0u && (REX_LOAD_U32(var + 4u) & kAsRef) != 0u)
    cc_as_unref_obj(ctx, base, var + 0u, 0x8208BF9Cu, 0x8208BFA8u);
  REX_STORE_U32(var + 0u, 0u);
  if (v == 0u) {
    REX_STORE_U32(var + 4u, kAsUndef);
    return 1u;
  }
  switch (REX_LOAD_U32(v + 0u)) {
    case kAsUndef:
      REX_STORE_U32(var + 4u, kAsUndef);
      return 1u;
    case 2u:
      REX_STORE_U32(var + 4u, 2u);
      REX_STORE_U8(var + 8u, uint8_t(cc_as_tobool(ctx, base, v)));
      return 1u;
    case 4u:
      REX_STORE_U32(var + 4u, 4u);
      ctx.r3.u64 = v; ctx.lr = 0x8208C020u;
      sub_82082BB0(ctx, base);
      REX_STORE_U32(var + 8u, ctx.r3.u32);
      return 1u;
    case 8u: case 32u:
      REX_STORE_U32(var + 4u, 8u);
      ctx.r3.u64 = v; ctx.lr = 0x8208C05Cu;
      sub_82082890(ctx, base);
      REX_STORE_U16(var + 8u, ctx.r3.u16);
      return 1u;
    case 16u: {
      REX_STORE_U32(var + 4u, 16u);
      ctx.r3.u64 = v; ctx.lr = 0x8208C044u;
      sub_82082700(ctx, base);
      ctx.fpscr.disableFlushMode();
      PPCRegister temp{};
      temp.f32 = float(ctx.f1.f64);
      REX_STORE_U32(var + 8u, temp.u32);
      return 1u;
    }
    case 1u: case 64u: case 128u: case 512u: case 1024u: case 16384u: case 32768u: {
      REX_STORE_U32(var + 4u, 1u);
      const uint32_t obj = cc_as_obj_of(base, v);
      REX_STORE_U32(var + 0u, obj);
      ctx.r3.u64 = obj; ctx.r4.u64 = 1u; ctx.lr = 0x8208C0F0u;
      sub_82066EA8(ctx, base);
      return 1u;
    }
    default:
      REX_STORE_U32(var + 4u, kAsUndef);
      return 0u;
  }
}
static CC_HOT_FN void sub_8208BF38(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8208BF38);
  CC_FPROF_SCOPE(sub_8208BF38_native);
  ctx.r3.u64 = cc_as_var_assign(ctx, base, ctx.r4.u32, ctx.r5.u32);
}

// SetVariable on an object (exact sub_8208C2A0: object r3, name id r4,
// value r5). The object's member map at +4 (sub_82082390): a found Var takes
// the value (Var assignment, whose result is r3). Otherwise a new 12-byte
// Var {0, undefined} from the game heap (sub_8209BDD8; none: 0) takes the
// value and sub_820936B0(object+4, id, Var) adds it (r3 its result).
static CC_HOT_FN inline void cc_as_set_member(Context& ctx, Machine& base, uint32_t obj, uint32_t id, uint32_t v) {
  const uint32_t var = cc_asmap_find(base, obj + 4u, id & 0xFFFFu);
  if (var != 0u) {
    ctx.r3.u64 = cc_as_var_assign(ctx, base, var, v);
    return;
  }
  ctx.r3.u64 = cc_as_game_heap(ctx, base, 0x8208C30Cu, 0x8208C310u);
  ctx.r4.u64 = 12u; ctx.lr = 0x8208C328u;
  sub_8209BDD8(ctx, base);
  const uint32_t nv = ctx.r3.u32;
  if (nv != 0u) {
    REX_STORE_U32(nv + 0u, 0u);
    REX_STORE_U32(nv + 4u, kAsUndef);
  }
  cc_as_var_assign(ctx, base, nv, v);
  ctx.r3.u64 = obj + 4u; ctx.r4.u64 = id; ctx.r5.u64 = nv; ctx.lr = 0x8208C36Cu;
  sub_820936B0(ctx, base);
}
static CC_HOT_FN void sub_8208C2A0(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8208C2A0);
  CC_FPROF_SCOPE(sub_8208C2A0_native);
  cc_as_set_member(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32);
}

// GetVariable (exact sub_8207AF80: S r3, name id r4, out value r5; returns 1
// when found). Ids 102..108 (jump table on id - 102): 102 the current clip's
// slot-156 object, 103 the player ([S+0]+76), 107 / 108 the player's +280 /
// +284 object, each as a typed reference (sub_8206F918(out, object)); 106 is
// {2, true}. Any other id (104 and 105 too): the active function's locals
// (sub_82079BE0) and members (sub_8208C140), then the current clip's slot 12
// (r4 id, r5 out); not found: out = {undefined, 0}, returns 0.
static CC_HOT_FN inline uint32_t cc_as_get_variable(Context& ctx, Machine& base, uint32_t s, uint32_t id, uint32_t out) {
  switch ((id & 0xFFFFu) - 102u) {
    case 0u: {
      const uint32_t r = cc_vcall(ctx, base, cc_as_top_clip(base, cc_as_vm(base, s)), 156u, 0x8207B064u);
      ctx.r3.u64 = out; ctx.r4.u64 = r; ctx.lr = 0x8207B070u;
      sub_8206F918(ctx, base);
      return 1u;
    }
    case 1u:
      ctx.r3.u64 = out; ctx.r4.u64 = REX_LOAD_U32(REX_LOAD_U32(s + 0u) + 76u); ctx.lr = 0x8207B02Cu;
      sub_8206F918(ctx, base);
      return 1u;
    case 4u:
      REX_STORE_U32(out + 0u, 2u);
      REX_STORE_U8(out + 4u, 1u);
      return 1u;
    case 5u:
      ctx.r3.u64 = out; ctx.r4.u64 = REX_LOAD_U32(REX_LOAD_U32(REX_LOAD_U32(s + 0u) + 76u) + 280u);
      ctx.lr = 0x8207B010u;
      sub_8206F918(ctx, base);
      return 1u;
    case 6u:
      ctx.r3.u64 = out; ctx.r4.u64 = REX_LOAD_U32(REX_LOAD_U32(REX_LOAD_U32(s + 0u) + 76u) + 284u);
      ctx.lr = 0x8207AFF0u;
      sub_8206F918(ctx, base);
      return 1u;
    default:
      break;
  }
  {
    const uint32_t vm = cc_as_vm(base, s);
    const uint32_t act = REX_LOAD_U32(vm + (REX_LOAD_U32(vm + 10180u) + 2513u) * 4u);
    if (act != 0u) {
      ctx.r3.u64 = act; ctx.r4.u64 = id; ctx.r5.u64 = out; ctx.lr = 0x8207B0CCu;
      sub_82079BE0(ctx, base);
      if ((ctx.r3.u32 & 0xFFu) != 0u) return 1u;
      ctx.r3.u64 = act; ctx.r4.u64 = id; ctx.r5.u64 = out; ctx.lr = 0x8207B0E8u;
      sub_8208C140(ctx, base);
      if ((ctx.r3.u32 & 0xFFu) != 0u) return 1u;
    }
  }
  const uint32_t clip = cc_as_top_clip(base, cc_as_vm(base, s));
  ctx.r4.u64 = id; ctx.r5.u64 = out;
  if ((cc_vcall(ctx, base, clip, 12u, 0x8207B128u) & 0xFFu) != 0u) return 1u;
  REX_STORE_U32(out + 4u, 0u);
  REX_STORE_U32(out + 0u, kAsUndef);
  return 0u;
}
static CC_HOT_FN void sub_8207AF80(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8207AF80);
  CC_FPROF_SCOPE(sub_8207AF80_native);
  ctx.r3.u64 = cc_as_get_variable(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32);
}

// Function member release after a call (exact sub_82079A00: function r3).
// Member map at +4 {u32 n, entries* at +8 (8 bytes, Var* at +4)}; n read
// once, the entry array re-read per entry. Each Var's object (+0), if any,
// gets its slot 4 when its count is 1; then the object (re-read) has its
// u16 count +24 decremented inline when its slot-40 type is counted; the Var
// is freed to the game heap (sub_8209BF18). Then the entry array is freed
// and +8 cleared (when set); +4 and +12 cleared.
static CC_HOT_FN void sub_82079A00(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_82079A00);
  CC_FPROF_SCOPE(sub_82079A00_native);
  const uint32_t fn = ctx.r3.u32;
  const uint32_t n = REX_LOAD_U32(fn + 4u);
  if (int32_t(n) > 0) {
    for (uint32_t i = 0; i < n; ++i) {
      const uint32_t var = REX_LOAD_U32(REX_LOAD_U32(fn + 8u) + i * 8u + 4u);
      const uint32_t o = REX_LOAD_U32(var + 0u);
      if (o != 0u) {
        if (REX_LOAD_U16(o + 24u) == 1u) cc_vcall(ctx, base, o, 4u, 0x82079A7Cu);
        const uint32_t o2 = REX_LOAD_U32(var + 0u);
        if ((cc_vcall(ctx, base, o2, 40u, 0x82079A94u) & kAsRef) != 0u)
          REX_STORE_U16(o2 + 24u, uint16_t(REX_LOAD_U16(o2 + 24u) + 0xFFFFu));
      }
      ctx.r3.u64 = cc_as_game_heap(ctx, base, 0x82079AD4u, 0x82079AD8u);
      ctx.r4.u64 = var; ctx.lr = 0x82079AE8u;
      sub_8209BF18(ctx, base);
    }
  }
  const uint32_t e = REX_LOAD_U32(fn + 8u);
  if (e != 0u) {
    ctx.r3.u64 = cc_as_game_heap(ctx, base, 0x82079B20u, 0x82079B24u);
    ctx.r4.u64 = e; ctx.lr = 0x82079B34u;
    sub_8209BF18(ctx, base);
    REX_STORE_U32(fn + 8u, 0u);
  }
  REX_STORE_U32(fn + 4u, 0u);
  REX_STORE_U32(fn + 12u, 0u);
}

// String "length" member (GetMember on a string with name id 1): the
// value's ToString id (sub_82082890) looked up in the VM's string table
// (VM+10316: id 0 -> table+12, else [table+28][id]; the table pointer read
// before the call); the value becomes {4, strlen}.
static CC_HOT_FN inline void cc_as_strlen_value(Context& ctx, Machine& base, uint32_t s, uint32_t v, uint32_t lr) {
  const uint32_t names = REX_LOAD_U32(cc_as_vm(base, s) + 10316u);
  ctx.r3.u64 = v; ctx.lr = lr;
  sub_82082890(ctx, base);
  const uint32_t id = ctx.r3.u32 & 0xFFFFu;
  const uint32_t str = id ? REX_LOAD_U32(REX_LOAD_U32(names + 28u) + id * 4u) : names + 12u;
  uint32_t e = str;
  while (REX_LOAD_U8(e) != 0u) ++e;
  REX_STORE_U32(v + 0u, 4u);
  REX_STORE_U32(v + 4u, e - str);
}

// GetVariable (exact sub_8207CE60, op 0x1C): pops the name (released); its
// slot takes the variable's value (GetVariable with the name's ToString id)
// and is referenced and pushed.
static CC_HOT_FN uint32_t cc_as_op_1C(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_1C);
  const uint32_t slot = cc_as_pop_release(ctx, base, o.s, 0x8207CED8u, 0x8207CEE4u);
  ctx.r3.u64 = slot; ctx.lr = 0x8207CEF8u;
  sub_82082890(ctx, base);
  cc_as_get_variable(ctx, base, o.s, ctx.r3.u32, slot);
  const uint32_t p = cc_as_pool(base, o.s);
  cc_as_ref(ctx, base, slot, 0x8207CF48u);
  cc_as_push(base, p, slot);
  return 0u;
}

// SetVariable (exact sub_8207CF70, op 0x1D): pops the value and the name
// (both released); unless the name is undefined, sub_8207AE58(S, ToString
// id of the name, value). Both slots freed.
static CC_HOT_FN uint32_t cc_as_op_1D(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_1D);
  const uint32_t val = cc_as_pop_release(ctx, base, o.s, 0x8207CFE8u, 0x8207CFF4u);
  const uint32_t name = cc_as_pop_release(ctx, base, o.s, 0x8207D068u, 0x8207D074u);
  if (REX_LOAD_U32(name) != kAsUndef) {
    ctx.r3.u64 = name; ctx.lr = 0x8207D098u;
    sub_82082890(ctx, base);
    ctx.r4.u64 = ctx.r3.u32; ctx.r5.u64 = val; ctx.r3.u64 = o.s; ctx.lr = 0x8207D0A8u;
    sub_8207AE58(ctx, base);
  }
  cc_as_free(base, val);
  cc_as_free(base, name);
  return 0u;
}

// SetProperty (exact sub_8207D2A0, op 0x23): pops the value, the property
// index and the target (all released); the target clip sub_8207B598(S,
// ToString id of the target) gets its slot 116 with r4 = ToInt(index) + 78,
// r5 = the value. The three slots freed.
static CC_HOT_FN uint32_t cc_as_op_23(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_23);
  const uint32_t val = cc_as_pop_release(ctx, base, o.s, 0x8207D318u, 0x8207D324u);
  const uint32_t idx = cc_as_pop_release(ctx, base, o.s, 0x8207D398u, 0x8207D3A4u);
  const uint32_t tgt = cc_as_pop_release(ctx, base, o.s, 0x8207D418u, 0x8207D424u);
  ctx.r3.u64 = tgt; ctx.lr = 0x8207D438u;
  sub_82082890(ctx, base);
  ctx.r4.u64 = ctx.r3.u32; ctx.r3.u64 = o.s; ctx.lr = 0x8207D444u;
  sub_8207B598(ctx, base);
  const uint32_t clip = ctx.r3.u32;
  ctx.r3.u64 = idx; ctx.lr = 0x8207D450u;
  sub_82082BB0(ctx, base);
  ctx.r4.s64 = ctx.r3.s64 + 78; ctx.r5.u64 = val;
  cc_vcall(ctx, base, clip, 116u, 0x8207D46Cu);
  cc_as_free(base, val);
  cc_as_free(base, idx);
  cc_as_free(base, tgt);
  return 0u;
}

// DefineLocal (exact sub_8207DEB8, op 0x3C): pops the value and the name
// (both released); with an active function (VM function stack) the
// variable is set through sub_8208C2A0(function, ToString id, value), else
// through the current clip's slot 16 (r4 id, r5 value). Both slots freed.
static CC_HOT_FN uint32_t cc_as_op_3C(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_3C);
  const uint32_t val = cc_as_pop_release(ctx, base, o.s, 0x8207DF30u, 0x8207DF3Cu);
  const uint32_t name = cc_as_pop_release(ctx, base, o.s, 0x8207DFB0u, 0x8207DFBCu);
  ctx.r3.u64 = name; ctx.lr = 0x8207DFD0u;
  sub_82082890(ctx, base);
  const uint32_t id = ctx.r3.u32;
  const uint32_t vm = cc_as_vm(base, o.s);
  const uint32_t act = REX_LOAD_U32(vm + (REX_LOAD_U32(vm + 10180u) + 2513u) * 4u);
  if (act != 0u) {
    cc_as_set_member(ctx, base, act, id, val);
  } else {
    ctx.r4.u64 = id; ctx.r5.u64 = val;
    cc_vcall(ctx, base, cc_as_top_clip(base, vm), 16u, 0x8207E028u);
  }
  cc_as_free(base, val);
  cc_as_free(base, name);
  return 0u;
}

// DefineLocal without a value (exact sub_8207EB68, op 0x41): pops the name
// (released); a frame temporary {undefined, 0, 0} at frame+80; with an
// active function the variable is created through sub_8208C2A0(function,
// ToString id, temp) unless the function's member map (+4) already has the
// id, else through the current clip's slot 16 (r4 id, r5 temp). The name
// slot freed.
static CC_HOT_FN uint32_t cc_as_op_41(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_41);
  CcFrame frame(ctx, base, 144u);
  const uint32_t tmp = ctx.r1.u32 + 80u;
  const uint32_t name = cc_as_pop_release(ctx, base, o.s, 0x8207EBE0u, 0x8207EBECu);
  ctx.r3.u64 = name; ctx.lr = 0x8207EC00u;
  sub_82082890(ctx, base);
  const uint32_t id = ctx.r3.u32;
  REX_STORE_U32(tmp + 0u, kAsUndef);
  REX_STORE_U8(tmp + 8u, 0u);
  REX_STORE_U32(tmp + 4u, 0u);
  const uint32_t vm = cc_as_vm(base, o.s);
  const uint32_t act = REX_LOAD_U32(vm + (REX_LOAD_U32(vm + 10180u) + 2513u) * 4u);
  if (act != 0u) {
    if (cc_asmap_find(base, act + 4u, id & 0xFFFFu) == 0u) cc_as_set_member(ctx, base, act, id, tmp);
  } else {
    ctx.r4.u64 = id; ctx.r5.u64 = tmp;
    cc_vcall(ctx, base, cc_as_top_clip(base, vm), 16u, 0x8207ECA8u);
  }
  cc_as_free(base, name);
  return 0u;
}

// GetMember (exact sub_8207F4D8, op 0x4E): pops the name and the object
// (both released); the object's slot takes the result. Object or name
// undefined: undefined. By the object's type: 1, 64, 1024 -> the object's
// slot 12 (r4 ToString id of the name, r5 the slot), not found ->
// undefined; 0x40000 -> the same call only for name id 100; 128 ->
// sub_8207A3F0(object, name, slot); string 8 with name id 1 -> {4, string
// length}; others keep the popped value. The slot is referenced and pushed,
// the name slot freed.
static CC_HOT_FN uint32_t cc_as_op_4E(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_4E);
  const uint32_t name = cc_as_pop_release(ctx, base, o.s, 0x8207F550u, 0x8207F55Cu);
  const uint32_t obj = cc_as_pop_release(ctx, base, o.s, 0x8207F5D0u, 0x8207F5DCu);
  const uint32_t t = REX_LOAD_U32(obj);
  bool undef = t == kAsUndef || REX_LOAD_U32(name) == kAsUndef;
  if (!undef) {
    const int32_t st = int32_t(t);
    bool call = false;
    uint32_t target = 0;
    if (st == 1 || st == 64 || st == 1024) {
      target = REX_LOAD_U32(obj + 4u);  // all counted types
      ctx.r3.u64 = name; ctx.lr = 0x8207F7D0u;
      sub_82082890(ctx, base);
      ctx.r4.u64 = ctx.r3.u32;
      call = true;
    } else if (st == 0x40000) {
      target = REX_LOAD_U32(obj + 4u);  // counted
      ctx.r3.u64 = name; ctx.lr = 0x8207F78Cu;
      sub_82082890(ctx, base);
      if ((ctx.r3.u32 & 0xFFFFu) == 100u) {
        ctx.r4.u64 = 100u;
        call = true;
      }
    } else if (st == 128) {
      ctx.r3.u64 = REX_LOAD_U32(obj + 4u); ctx.r4.u64 = name; ctx.r5.u64 = obj; ctx.lr = 0x8207F6E4u;  // counted
      sub_8207A3F0(ctx, base);
    } else if (st == 8) {
      ctx.r3.u64 = name; ctx.lr = 0x8207F650u;
      sub_82082890(ctx, base);
      if ((ctx.r3.u32 & 0xFFFFu) == 1u) cc_as_strlen_value(ctx, base, o.s, obj, 0x8207F674u);
    }
    if (call) {
      ctx.r5.u64 = obj;
      undef = (cc_vcall(ctx, base, target, 12u, 0x8207F7ECu) & 0xFFu) == 0u;
    }
  }
  if (undef) {
    REX_STORE_U32(obj + 0u, kAsUndef);
    REX_STORE_U32(obj + 4u, 0u);
  }
  const uint32_t p = cc_as_pool(base, o.s);
  cc_as_ref(ctx, base, obj, 0x8207F840u);
  cc_as_push(base, p, obj);
  cc_as_free(base, name);
  return 0u;
}

// SetMember (exact sub_8207F870, op 0x4F): pops the value, the name and the
// object (all released); nothing when the object or the name is undefined.
// Target = the object value's object: when its slot-40 type is 128 (an
// array), ToInt(name) below its u16 +32 length stores through
// sub_8207A358(target, index, value), out of range is an error report
// (format 0x8203E37C, sub_820798D8 + sub_8208C5D8); otherwise the object
// value's object (nonzero) gets its slot 16 (r4 ToString id of the name, r5
// value). The three slots freed.
static CC_HOT_FN uint32_t cc_as_op_4F(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_4F);
  const uint32_t val = cc_as_pop_release(ctx, base, o.s, 0x8207F8E8u, 0x8207F8F4u);
  const uint32_t name = cc_as_pop_release(ctx, base, o.s, 0x8207F968u, 0x8207F974u);
  const uint32_t obj = cc_as_pop_release(ctx, base, o.s, 0x8207F9E8u, 0x8207F9F4u);
  if (REX_LOAD_U32(obj) != kAsUndef && REX_LOAD_U32(name) != kAsUndef) {
    const uint32_t target = cc_as_obj_of(base, obj);
    if (cc_vcall(ctx, base, target, 40u, 0x8207FA78u) == 128u) {
      ctx.r3.u64 = name; ctx.lr = 0x8207FA88u;
      sub_82082BB0(ctx, base);
      const uint32_t idx = ctx.r3.u32;
      if (idx < REX_LOAD_U16(target + 32u)) {
        ctx.r3.u64 = target; ctx.r4.u64 = idx; ctx.r5.u64 = val; ctx.lr = 0x8207FAA4u;
        sub_8207A358(ctx, base);
      } else {
        ctx.r3.u64 = 0x8203E37Cu; ctx.r4.u64 = idx; ctx.lr = 0x8207FAB4u;  // 0x82040000 - 7300
        sub_820798D8(ctx, base);
        ctx.lr = 0x8207FAB8u;
        sub_8208C5D8(ctx, base);
      }
    } else {
      ctx.r3.u64 = name; ctx.lr = 0x8207FAC0u;
      sub_82082890(ctx, base);
      const uint32_t id = ctx.r3.u32;
      const uint32_t m = cc_as_obj_of(base, obj);
      if (m != 0u) {
        ctx.r4.u64 = id; ctx.r5.u64 = val;
        cc_vcall(ctx, base, m, 16u, 0x8207FB18u);
      }
    }
  }
  cc_as_free(base, val);
  cc_as_free(base, name);
  cc_as_free(base, obj);
  return 0u;
}

// ConstantPool (exact sub_820813F8, op 0x88): only when S+4 is empty: an
// 8-byte pool header {u32 0, u16 0} from the game heap (sub_8209BDD8; none:
// 0) is stored at S+4 and filled by sub_82083900(header, VM, data).
static CC_HOT_FN uint32_t cc_as_op_88(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_88);
  if (REX_LOAD_U32(o.s + 4u) != 0u) return 0u;
  ctx.r3.u64 = cc_as_game_heap(ctx, base, 0x82081444u, 0x82081448u);
  ctx.r4.u64 = 8u; ctx.lr = 0x82081460u;
  sub_8209BDD8(ctx, base);
  const uint32_t hdr = ctx.r3.u32;
  if (hdr != 0u) {
    REX_STORE_U32(hdr + 0u, 0u);
    REX_STORE_U16(hdr + 4u, 0u);
  }
  REX_STORE_U32(o.s + 4u, hdr);
  ctx.r3.u64 = hdr; ctx.r4.u64 = cc_as_vm(base, o.s); ctx.r5.u64 = o.data; ctx.lr = 0x82081494u;
  sub_82083900(ctx, base);
  return 0u;
}

// GetMember with an inline name (exact sub_82081E18, op 0xA2): the name
// item decoded into a frame temporary at frame+88 (+4/+8 cleared first),
// then the object popped (released); its slot takes the result as in
// GetMember (0x4E) without the 0x40000 case: 1, 64, 1024 -> the object's
// slot 12 (r4 ToString id of the name, r5 the slot), not found ->
// undefined; 128 -> sub_8207A3F0(object, temp, slot); string 8 with name id
// 1 -> {4, string length}; object or name undefined -> undefined. The slot
// is referenced and pushed. Returns 1.
static CC_HOT_FN uint32_t cc_as_op_A2(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_A2);
  CcFrame frame(ctx, base, 160u);
  const uint32_t tmp = ctx.r1.u32 + 88u;
  uint32_t pos = 0;
  REX_STORE_U32(tmp + 4u, 0u);
  REX_STORE_U8(tmp + 8u, 0u);
  cc_as_decode(ctx, base, o.s, tmp, o.data, pos);
  const uint32_t obj = cc_as_pop_release(ctx, base, o.s, 0x82081EB4u, 0x82081EC0u);
  const uint32_t t = REX_LOAD_U32(obj);
  bool undef = t == kAsUndef || REX_LOAD_U32(tmp) == kAsUndef;
  if (!undef) {
    const int32_t st = int32_t(t);
    if (st == 1 || st == 64 || st == 1024) {
      const uint32_t target = REX_LOAD_U32(obj + 4u);  // all counted types
      ctx.r3.u64 = tmp; ctx.lr = 0x82081FD8u;
      sub_82082890(ctx, base);
      ctx.r4.u64 = ctx.r3.u32; ctx.r5.u64 = obj;
      undef = (cc_vcall(ctx, base, target, 12u, 0x82081FF4u) & 0xFFu) == 0u;
    } else if (st == 128) {
      ctx.r3.u64 = REX_LOAD_U32(obj + 4u); ctx.r4.u64 = tmp; ctx.r5.u64 = obj; ctx.lr = 0x82082090u;  // counted
      sub_8207A3F0(ctx, base);
    } else if (st == 8) {
      ctx.r3.u64 = tmp; ctx.lr = 0x82081F0Cu;
      sub_82082890(ctx, base);
      if ((ctx.r3.u32 & 0xFFFFu) == 1u) cc_as_strlen_value(ctx, base, o.s, obj, 0x82081F30u);
    }
  }
  if (undef) {
    REX_STORE_U32(obj + 4u, 0u);
    REX_STORE_U32(obj + 0u, kAsUndef);
  }
  const uint32_t p = cc_as_pool(base, o.s);
  cc_as_ref(ctx, base, obj, 0x82082048u);
  cc_as_push(base, p, obj);
  return 1u;
}

// SetMember with inline name and value (exact sub_820820D8, op 0xA3): pops
// the object (released); unless it is undefined, the name and the value
// items are decoded into frame temporaries at frame+88 and frame+104 (+4/+8
// cleared first) and, the name not being undefined, stored as in SetMember
// (0x4F; an out-of-range array index does nothing). The object slot freed.
// Returns 1.
static CC_HOT_FN uint32_t cc_as_op_A3(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_A3);
  CcFrame frame(ctx, base, 176u);
  const uint32_t key = ctx.r1.u32 + 88u, val = ctx.r1.u32 + 104u;
  const uint32_t obj = cc_as_pop_release(ctx, base, o.s, 0x82082154u, 0x82082160u);
  if (REX_LOAD_U32(obj) != kAsUndef) {
    uint32_t pos = 0;
    REX_STORE_U32(key + 4u, 0u);
    REX_STORE_U8(key + 8u, 0u);
    cc_as_decode(ctx, base, o.s, key, o.data, pos);
    REX_STORE_U32(val + 4u, 0u);
    REX_STORE_U8(val + 8u, 0u);
    cc_as_decode(ctx, base, o.s, val, o.data, pos);
    if (REX_LOAD_U32(key) != kAsUndef) {
      const uint32_t target = cc_as_obj_of(base, obj);
      if (cc_vcall(ctx, base, target, 40u, 0x82082228u) == 128u) {
        ctx.r3.u64 = key; ctx.lr = 0x82082238u;
        sub_82082BB0(ctx, base);
        const uint32_t idx = ctx.r3.u32;
        if (idx < REX_LOAD_U16(target + 32u)) {
          ctx.r3.u64 = target; ctx.r4.u64 = idx; ctx.r5.u64 = val; ctx.lr = 0x82082254u;
          sub_8207A358(ctx, base);
        }
      } else {
        ctx.r3.u64 = key; ctx.lr = 0x8208226Cu;
        sub_82082890(ctx, base);
        const uint32_t id = ctx.r3.u32;
        const uint32_t m = cc_as_obj_of(base, obj);
        if (m != 0u) {
          ctx.r4.u64 = id; ctx.r5.u64 = val;
          cc_vcall(ctx, base, m, 16u, 0x820822C4u);
        }
      }
    }
  }
  cc_as_free(base, obj);
  return 1u;
}
