DEFINE_REX_FUNC(sub_821420A0) {
	REX_FUNC_PROLOGUE();
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r9,2912
	ctx.r8.s64 = ctx.r9.s64 + 2912;
	// lis r10,15258
	ctx.r10.s64 = 999948288;
	// ori r10,r10,51712
	ctx.r10.u64 = ctx.r10.u64 | 51712;
	// std r11,0(r8)
	REX_STORE_U64(ctx.r8.u32 + 0, ctx.r11.u64);
	// std r11,8(r8)
	REX_STORE_U64(ctx.r8.u32 + 8, ctx.r11.u64);
	// std r11,16(r8)
	REX_STORE_U64(ctx.r8.u32 + 16, ctx.r11.u64);
	// std r11,24(r8)
	REX_STORE_U64(ctx.r8.u32 + 24, ctx.r11.u64);
	// std r11,32(r8)
	REX_STORE_U64(ctx.r8.u32 + 32, ctx.r11.u64);
	// std r10,2912(r9)
	REX_STORE_U64(ctx.r9.u32 + 2912, ctx.r10.u64);
	// b 0x82141f88
	sub_82141F88(ctx, base);
	return;
}
