DEFINE_REX_FUNC(sub_820EB2C0) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x820eb170
	sub_820EB170(ctx, base);
	return;
}
