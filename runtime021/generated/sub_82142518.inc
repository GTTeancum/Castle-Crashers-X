DEFINE_REX_FUNC(sub_82142518) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,24192(r10)
	REX_STORE_U32(ctx.r10.u32 + 24192, ctx.r11.u32);
	// blr 
	return;
}
