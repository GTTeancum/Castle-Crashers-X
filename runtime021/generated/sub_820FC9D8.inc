DEFINE_REX_FUNC(sub_820FC9D8) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,240
	ctx.r3.s64 = ctx.r3.s64 + 240;
	// b 0x82107e28
	sub_82107E28(ctx, base);
	return;
}
