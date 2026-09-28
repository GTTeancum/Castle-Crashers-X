DEFINE_REX_FUNC(sub_820B59F0) {
	REX_FUNC_PROLOGUE();
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x820b5960
	sub_820B5960(ctx, base);
	return;
}
