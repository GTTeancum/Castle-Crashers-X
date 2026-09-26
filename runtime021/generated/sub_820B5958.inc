DEFINE_REX_FUNC(sub_820B5958) {
	REX_FUNC_PROLOGUE();
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x820b58d0
	sub_820B58D0(ctx, base);
	return;
}
