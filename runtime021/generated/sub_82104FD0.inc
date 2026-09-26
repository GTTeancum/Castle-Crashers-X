DEFINE_REX_FUNC(sub_82104FD0) {
	REX_FUNC_PROLOGUE();
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82104b10
	sub_82104B10(ctx, base);
	return;
}
