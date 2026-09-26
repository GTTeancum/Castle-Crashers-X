DEFINE_REX_FUNC(sub_820B6068) {
	REX_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x820b74b0
	sub_820B74B0(ctx, base);
	return;
}
