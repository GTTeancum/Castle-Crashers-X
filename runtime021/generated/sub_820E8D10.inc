DEFINE_REX_FUNC(sub_820E8D10) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x820e8280
	sub_820E8280(ctx, base);
	return;
}
