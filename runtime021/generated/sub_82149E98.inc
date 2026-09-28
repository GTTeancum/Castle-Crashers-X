DEFINE_REX_FUNC(sub_82149E98) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lwz r11,-12408(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12408);
	// stw r11,23128(r10)
	REX_STORE_U32(ctx.r10.u32 + 23128, ctx.r11.u32);
	// blr 
	return;
}
