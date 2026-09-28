DEFINE_REX_FUNC(sub_8214A1A0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// addi r11,r11,-32376
	ctx.r11.s64 = ctx.r11.s64 + -32376;
	// stw r11,6760(r10)
	REX_STORE_U32(ctx.r10.u32 + 6760, ctx.r11.u32);
	// blr 
	return;
}
