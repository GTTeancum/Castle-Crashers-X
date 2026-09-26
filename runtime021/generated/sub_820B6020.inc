DEFINE_REX_FUNC(sub_820B6020) {
	REX_FUNC_PROLOGUE();
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x820b7448
	sub_820B7448(ctx, base);
	return;
}
