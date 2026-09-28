DEFINE_REX_FUNC(sub_8214A028) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r10,2820
	ctx.r3.s64 = ctx.r10.s64 + 2820;
	// addi r11,r11,-7008
	ctx.r11.s64 = ctx.r11.s64 + -7008;
	// stw r11,2820(r10)
	REX_STORE_U32(ctx.r10.u32 + 2820, ctx.r11.u32);
	// b 0x82079970
	sub_82079970(ctx, base);
	return;
}
