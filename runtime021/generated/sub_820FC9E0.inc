DEFINE_REX_FUNC(sub_820FC9E0) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,228
	ctx.r3.s64 = ctx.r3.s64 + 228;
	// b 0x821087b0
	sub_821087B0(ctx, base);
	return;
}
