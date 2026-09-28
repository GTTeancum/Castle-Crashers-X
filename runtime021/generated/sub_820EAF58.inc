DEFINE_REX_FUNC(sub_820EAF58) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820eaa88
	sub_820EAA88(ctx, base);
	return;
}
