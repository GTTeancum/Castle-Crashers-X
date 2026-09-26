DEFINE_REX_FUNC(sub_820E15E0) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820eaaa8
	sub_820EAAA8(ctx, base);
	return;
}
