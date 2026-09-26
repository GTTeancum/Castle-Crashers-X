DEFINE_REX_FUNC(sub_820E0D00) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820e15e8
	sub_820E15E8(ctx, base);
	return;
}
