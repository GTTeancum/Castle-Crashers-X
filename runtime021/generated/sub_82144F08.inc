DEFINE_REX_FUNC(sub_82144F08) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r10,74
	ctx.r10.s64 = 74;
	// addi r11,r11,-5384
	ctx.r11.s64 = ctx.r11.s64 + -5384;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}
