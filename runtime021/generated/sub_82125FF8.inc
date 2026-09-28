DEFINE_REX_FUNC(sub_82125FF8) {
	REX_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lbz r8,74(r4)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r4.u32 + 74);
	// lbz r10,75(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 75);
	// lhz r11,72(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 72);
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// stw r5,76(r4)
	REX_STORE_U32(ctx.r4.u32 + 76, ctx.r5.u32);
	// rlwinm. r8,r11,0,0,16
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF8000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stb r9,74(r4)
	REX_STORE_U8(ctx.r4.u32 + 74, ctx.r9.u8);
	// stb r10,75(r4)
	REX_STORE_U8(ctx.r4.u32 + 75, ctx.r10.u8);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// ori r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 32768;
	// lwz r3,20(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// sth r11,72(r4)
	REX_STORE_U16(ctx.r4.u32 + 72, ctx.r11.u16);
	// b 0x821235b0
	sub_821235B0(ctx, base);
	return;
}
