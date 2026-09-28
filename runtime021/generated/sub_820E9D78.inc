DEFINE_REX_FUNC(sub_820E9D78) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x820e9b98
	sub_820E9B98(ctx, base);
	return;
}
