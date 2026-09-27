DEFINE_REX_FUNC(sub_820B5D40) {
	REX_FUNC_PROLOGUE();
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8214a2e4
	__imp__XamShowGamerCardUIForXUID(ctx, base);
	return;
}
