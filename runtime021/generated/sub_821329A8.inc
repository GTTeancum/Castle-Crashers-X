DEFINE_REX_FUNC(sub_821329A8) {
	REX_FUNC_PROLOGUE();
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x821328b8
	sub_821328B8(ctx, base);
	return;
}
