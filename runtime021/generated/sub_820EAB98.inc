DEFINE_REX_FUNC(sub_820EAB98) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x820e1be0
	sub_820E1BE0(ctx, base);
	return;
}
