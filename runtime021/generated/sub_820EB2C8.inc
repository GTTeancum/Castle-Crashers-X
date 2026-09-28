DEFINE_REX_FUNC(sub_820EB2C8) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x820eb078
	sub_820EB078(ctx, base);
	return;
}
