DEFINE_REX_FUNC(sub_820E8CF8) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820eab98
	sub_820EAB98(ctx, base);
	return;
}
