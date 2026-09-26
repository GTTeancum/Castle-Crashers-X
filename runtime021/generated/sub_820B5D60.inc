DEFINE_REX_FUNC(sub_820B5D60) {
	REX_FUNC_PROLOGUE();
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// li r8,-1
	ctx.r8.s64 = -1;
	// b 0x820b7350
	sub_820B7350(ctx, base);
	return;
}
