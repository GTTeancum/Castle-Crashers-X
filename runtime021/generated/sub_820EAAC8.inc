DEFINE_REX_FUNC(sub_820EAAC8) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// b 0x820e71d0
	sub_820E71D0(ctx, base);
	return;
}
