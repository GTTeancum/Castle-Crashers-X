DEFINE_REX_FUNC(sub_82125FB0) {
	REX_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lhz r11,72(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 72);
	// lbz r10,75(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 75);
	// lbz r9,74(r4)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r4.u32 + 74);
	// ori r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 4096;
	// ori r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 | 32;
	// andi. r9,r9,223
	ctx.r9.u64 = ctx.r9.u64 & 223;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// sth r11,72(r4)
	REX_STORE_U16(ctx.r4.u32 + 72, ctx.r11.u16);
	// rlwinm. r11,r11,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r10,75(r4)
	REX_STORE_U8(ctx.r4.u32 + 75, ctx.r10.u8);
	// stb r9,74(r4)
	REX_STORE_U8(ctx.r4.u32 + 74, ctx.r9.u8);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lhz r11,72(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 72);
	// lwz r3,20(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// ori r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 32768;
	// sth r11,72(r4)
	REX_STORE_U16(ctx.r4.u32 + 72, ctx.r11.u16);
	// b 0x821235b0
	sub_821235B0(ctx, base);
	return;
}
