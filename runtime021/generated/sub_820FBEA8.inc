DEFINE_REX_FUNC(sub_820FBEA8) {
	REX_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x820fbdf8
	sub_820FBDF8(ctx, base);
	return;
}
