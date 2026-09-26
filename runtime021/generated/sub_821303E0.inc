DEFINE_REX_FUNC(sub_821303E0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// addi r11,r11,816
	ctx.r11.s64 = ctx.r11.s64 + 816;
	// stw r11,23716(r10)
	REX_STORE_U32(ctx.r10.u32 + 23716, ctx.r11.u32);
	// blr 
	return;
}
