DEFINE_REX_FUNC(sub_82115178) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-200
	ctx.r3.s64 = ctx.r3.s64 + -200;
	// b 0x82119718
	sub_82119718(ctx, base);
	return;
}
