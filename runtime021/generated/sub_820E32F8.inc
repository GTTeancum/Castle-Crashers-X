DEFINE_REX_FUNC(sub_820E32F8) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820e33d0
	sub_820E33D0(ctx, base);
	return;
}
