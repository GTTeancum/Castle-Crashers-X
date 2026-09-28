DEFINE_REX_FUNC(sub_820E8200) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x820e8078
	sub_820E8078(ctx, base);
	return;
}
