DEFINE_REX_FUNC(sub_82126288) {
	REX_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,11
	ctx.r3.s64 = 11;
	// b 0x82108f60
	sub_82108F60(ctx, base);
	return;
}
