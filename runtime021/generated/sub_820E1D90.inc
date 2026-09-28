DEFINE_REX_FUNC(sub_820E1D90) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-12
	ctx.r3.s64 = ctx.r3.s64 + -12;
	// b 0x820e25a0
	sub_820E25A0(ctx, base);
	return;
}
