DEFINE_REX_FUNC(sub_82132B00) {
	REX_FUNC_PROLOGUE();
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x821329e0
	sub_821329E0(ctx, base);
	return;
}
