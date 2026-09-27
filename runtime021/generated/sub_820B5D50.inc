DEFINE_REX_FUNC(sub_820B5D50) {
	REX_FUNC_PROLOGUE();
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// b 0x8214a304
	__imp__XamShowMarketplaceUI(ctx, base);
	return;
}
