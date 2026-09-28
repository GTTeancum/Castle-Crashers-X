DEFINE_REX_FUNC(sub_82108E38) {
	REX_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r4,-740
	ctx.r3.s64 = ctx.r4.s64 + -740;
	// b 0x82113430
	sub_82113430(ctx, base);
	return;
}
