DEFINE_REX_FUNC(sub_820EAF78) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x820eab48
	sub_820EAB48(ctx, base);
	return;
}
