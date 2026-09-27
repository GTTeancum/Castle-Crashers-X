DEFINE_REX_FUNC(sub_82075400) {
	REX_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x82070f68
	sub_82070F68(ctx, base);
	return;
}
