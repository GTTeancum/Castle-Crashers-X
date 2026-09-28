DEFINE_REX_FUNC(sub_82132F40) {
	REX_FUNC_PROLOGUE();
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x82132e10
	sub_82132E10(ctx, base);
	return;
}
