DEFINE_REX_FUNC(sub_820E8D30) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820e32d0
	sub_820E32D0(ctx, base);
	return;
}
