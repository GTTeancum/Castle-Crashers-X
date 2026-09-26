DEFINE_REX_FUNC(sub_821210B0) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lhz r10,836(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 836);
	// addis r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi. r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// sth r10,836(r11)
	REX_STORE_U16(ctx.r11.u32 + 836, ctx.r10.u16);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// b 0x8211bd50
	sub_8211BD50(ctx, base);
	return;
}
