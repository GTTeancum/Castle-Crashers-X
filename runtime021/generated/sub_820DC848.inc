DEFINE_REX_FUNC(sub_820DC848) {
	REX_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// b 0x82136670
	sub_82136670(ctx, base);
	return;
}
