DEFINE_REX_FUNC(sub_820E81E8) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x820e7fe8
	sub_820E7FE8(ctx, base);
	return;
}
