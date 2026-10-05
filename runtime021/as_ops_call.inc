// Script function calls: the clip classes' CharToFunc (included by
// as_ops_more.inc). CallFunction (0x3D) and CallMethod (0x52) reach it as
// the clip's slot 20; the custom-function path runs natively into the
// native CallCustomFunction loop, everything else stays recompiled.

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
  if (k - 24u <= 42u) { sub_82088CF0_exact(ctx, base); return; }
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
