// Script function calls: the clip classes' CharToFunc (included by
// as_ops_more.inc). CallFunction (0x3D) and CallMethod (0x52) reach it as
// the clip's slot 20; the custom-function path runs natively into the
// native CallCustomFunction loop, everything else stays recompiled.

// The clip classes' gotoAndStop (slot 164, exact sub_82088C60) and
// gotoAndPlay (slot 172, exact sub_82088C98) on clip r3, frame r4: frame 0
// does nothing; the frame is clamped to the frame count u16 +148;
// gotoAndStop sets bit 1 of +140; gotoAndPlay sets bit 2 when the frame is
// the current one (+146) and clears bit 1; then the timeline seek
// sub_82087F70 (a tail call: lr stays the caller's). Volatile registers as
// the originals leave them.
static CC_HOT_FN void cc_as_clip_goto_slot(Context& ctx, Machine& base, bool play) {
  const uint32_t clip = ctx.r3.u32;
  ctx.r11.u64 = ctx.r4.u32 & 0xFFFFu;
  if (ctx.r11.u32 == 0u) return;
  ctx.r10.u64 = REX_LOAD_U16(clip + 148u);
  ctx.r9.u64 = ctx.r10.u64;
  if (ctx.r11.u32 > ctx.r9.u32) ctx.r4.u64 = ctx.r10.u64;
  if (play) {
    ctx.r11.u64 = REX_LOAD_U16(clip + 146u);
    ctx.r10.u64 = ctx.r4.u32 & 0xFFFFu;
    if (ctx.r10.u32 == ctx.r11.u32) {
      ctx.r11.u64 = REX_LOAD_U8(clip + 140u);
      ctx.r10.u64 = ctx.r11.u64 | 4u;
      REX_STORE_U8(clip + 140u, ctx.r10.u8);
    }
    ctx.r11.u64 = REX_LOAD_U8(clip + 140u);
    ctx.r10.u64 = ctx.r11.u64 & 0xFDu;
  } else {
    ctx.r11.u64 = REX_LOAD_U8(clip + 140u);
    ctx.r10.u64 = ctx.r11.u64 | 2u;
  }
  REX_STORE_U8(clip + 140u, ctx.r10.u8);
  sub_82087F70(ctx, base);
}
// Timeline builtins of the clip CharToFunc below (ids 30 gotoAndPlay, 31
// gotoAndStop, 35 nextFrame, 37 prevFrame; same arguments), run as the
// recompiled body runs them between its update-stack push and pop: the
// frame argument (the first argument's value) is an int or number
// (sub_82082BB0) or else a label (sub_82082890, then slot 120; for
// gotoAndStop undefined is frame 1), handed to slot 172 / 164 (the clip
// classes' are run inline above); nextFrame / prevFrame set bit 1 of +140
// and seek +146 + 1 (when within +148) / +146 - 1 (when not 0). Volatile
// registers are set as the recompiled code leaves them, since a later
// variadic call can spill them into stack words that reach the heap.
// Switches: CC_SEEK_EXACT=1 (host) / make SEEKEXACT=1 (Xbox) or the
// CharToFunc switches run the recompiled body.
static CC_HOT_FN void cc_as_clip_timeline(Context& ctx, Machine& base, uint32_t k) {
  const uint32_t clip = ctx.r3.u32, vm = ctx.r4.u32, args = ctx.r7.u32;
  ctx.r12.u64 = ctx.lr;
  ctx.lr = 0x82088CF8u;  // the register-save call
  CcFrame frame(ctx, base, 320u);
  {  // update-stack push and the jump into the builtin switch
    ctx.r11.u64 = uint64_t(REX_LOAD_U32(vm + 8248u)) + 1u;
    ctx.r9.u64 = ctx.r11.u64 + 1998u;
    REX_STORE_U32(vm + 8248u, ctx.r11.u32);
    ctx.r8.u64 = ctx.r9.u32 << 2;
    REX_STORE_U32(ctx.r8.u32 + vm, clip);
    ctx.r10.u64 = k;
    ctx.r11.u64 = k - 24u;
    ctx.r12.u64 = 0xFFFFFFFF82088E14ull;
    ctx.r0.u64 = REX_LOAD_U32(0x82088E14u + ctx.r11.u32 * 4u);
    ctx.ctr.u64 = ctx.r0.u64;
  }
  auto slot_call = [&](uint32_t slot, uint32_t lr) {
    const uint32_t vt = REX_LOAD_U32(clip + 0u);
    ctx.r11.u64 = vt;
    ctx.r3.u64 = clip;
    const uint32_t fn = REX_LOAD_U32(vt + slot);
    ctx.r10.u64 = fn;
    ctx.ctr.u64 = fn;
    ctx.lr = lr;
    if (fn == 0x82088C60u) cc_as_clip_goto_slot(ctx, base, false);
    else if (fn == 0x82088C98u) cc_as_clip_goto_slot(ctx, base, true);
    else REX_CALL_INDIRECT_FUNC(fn);
  };
  if (k == 30u || k == 31u) {
    const uint32_t a0 = REX_LOAD_U32(args + 0u);
    ctx.r3.u64 = a0;
    if (k == 31u) ctx.r10.u64 = 0xFFFFFFFF80000000ull;
    const uint32_t type = REX_LOAD_U32(a0 + 0u);
    ctx.r11.u64 = type;
    if (k == 31u && type == kAsUndef) {
      ctx.r4.u64 = 1u;
    } else if (type == 4u || type == 16u) {
      ctx.lr = k == 30u ? 0x82088F9Cu : 0x8208900Cu;
      sub_82082BB0(ctx, base);
      ctx.r4.u64 = ctx.r3.u32 & 0xFFFFu;
    } else {
      ctx.lr = k == 30u ? 0x82088F78u : 0x82088FE8u;
      sub_82082890(ctx, base);
      const uint32_t vt = REX_LOAD_U32(clip + 0u);
      ctx.r11.u64 = vt;
      ctx.r4.u64 = ctx.r3.u64;
      ctx.r3.u64 = clip;
      const uint32_t fn = REX_LOAD_U32(vt + 120u);
      ctx.r10.u64 = fn;
      ctx.ctr.u64 = fn;
      ctx.lr = k == 30u ? 0x82088F90u : 0x82089000u;
      REX_CALL_INDIRECT_FUNC(fn);
      ctx.r4.u64 = ctx.r3.u64;
    }
    if (k == 30u) slot_call(172u, 0x82088FB4u);
    else slot_call(164u, 0x82089024u);
  } else {  // 35 nextFrame, 37 prevFrame
    ctx.r11.u64 = REX_LOAD_U16(clip + 146u);
    bool go;
    if (k == 35u) {
      ctx.r10.u64 = REX_LOAD_U16(clip + 148u);
      ctx.r9.u64 = ctx.r11.u64 + 1u;
      ctx.r4.u64 = ctx.r9.u32 & 0xFFFFu;
      go = ctx.r4.u32 <= ctx.r10.u32;
    } else {
      ctx.r10.u64 = ctx.r11.u64 + 0xFFFFu;
      ctx.r4.u64 = ctx.r10.u32 & 0xFFFFu;
      go = ctx.r4.u32 != 0u;
    }
    if (go) {
      ctx.r11.u64 = REX_LOAD_U8(clip + 140u);
      ctx.r3.u64 = clip;
      ctx.r10.u64 = ctx.r11.u64 | 2u;
      REX_STORE_U8(clip + 140u, ctx.r10.u8);
      ctx.lr = k == 35u ? 0x820890C4u : 0x820890F4u;
      sub_82087F70(ctx, base);
    }
  }
  // update-stack pop
  ctx.r11.u64 = uint64_t(REX_LOAD_U32(vm + 8248u)) + 1998u;
  ctx.r10.u64 = ctx.r11.u32 << 2;
  REX_STORE_U32(ctx.r10.u32 + vm, 0u);
  ctx.r11.u64 = REX_LOAD_U32(vm + 8248u);
  ctx.r9.u64 = ctx.r11.u64 - 1u;
  REX_STORE_U32(vm + 8248u, ctx.r9.u32);
}
// Clip CharToFunc (exact sub_82088CF0: clip r3, VM r4, name id r5, argc r6,
// args r7, result slot r8, stop byte r9; frame 320). Ids 24..66 are the
// clip's built-in methods (gotoAndPlay, getDepth, ...): the recompiled body
// runs those whole. Otherwise the clip is pushed on the VM's update stack
// (count +8248, entry +(n+1998)*4); ids 129..174, 177..186 and 227..228 go
// to the native-function dispatcher sub_82071280(VM, id, argc, args,
// result), and when that returns 0 in its low byte, as for every other id,
// the clip's custom function runs: sub_8207B150(clip+160, id, argc, args,
// result, stop byte). Then the update-stack entry is cleared and popped.
// Host switches: CC_AS_EXACT / CC_EXACT_FNS=sub_82088CF0; Xbox build
// define CC_AS_CALL_EXACT_BUILD.
static CC_HOT_FN void sub_82088CF0(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_82088CF0);
#ifdef CC_AS_CALL_EXACT_BUILD
  if (true) { sub_82088CF0_exact(ctx, base); return; }  // Xbox bisect build
#endif
  CC_FPROF_SCOPE(sub_82088CF0_native);
  const uint32_t k = ctx.r5.u32 & 0xFFFFu;
#ifdef CC_SPIKE_REPORT
  CcAsFnScope spike_scope(k | 0x10000u);
#endif
  if (k - 24u <= 42u) {
    if ((k == 31u || k == 30u || k == 35u || k == 37u) && !g_seek_exact) cc_as_clip_timeline(ctx, base, k);
    else sub_82088CF0_exact(ctx, base);
    return;
  }
  const uint64_t clip = ctx.r3.u64, vm64 = ctx.r4.u64, id = ctx.r5.u64, argc = ctx.r6.u64, args = ctx.r7.u64;
  const uint64_t res = ctx.r8.u64, done = ctx.r9.u64;
  const uint32_t vm = uint32_t(vm64);
  CcFrame frame(ctx, base, 320u);
  {
    const uint32_t n = REX_LOAD_U32(vm + 8248u) + 1u;
    REX_STORE_U32(vm + 8248u, n);
    REX_STORE_U32(vm + (n + 1998u) * 4u, uint32_t(clip));
  }
  bool custom = true;
  if ((k > 128u && k < 175u) || (k > 176u && k < 187u) || (k > 226u && k < 229u)) {
    ctx.r3.u64 = vm64; ctx.r4.u64 = id; ctx.r5.u64 = argc; ctx.r6.u64 = args; ctx.r7.u64 = res;
    ctx.lr = 0x82088DA4u;
    sub_82071280(ctx, base);
    custom = (ctx.r3.u32 & 0xFFu) == 0u;
  }
  if (custom) {
    ctx.r3.s64 = int64_t(clip) + 160; ctx.r4.u64 = id; ctx.r5.u64 = argc; ctx.r6.u64 = args; ctx.r7.u64 = res;
    ctx.r8.u64 = done; ctx.lr = 0x82088DCCu;
    sub_8207B150(ctx, base);
  }
  REX_STORE_U32(vm + (REX_LOAD_U32(vm + 8248u) + 1998u) * 4u, 0u);
  REX_STORE_U32(vm + 8248u, REX_LOAD_U32(vm + 8248u) - 1u);
}
