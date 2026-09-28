DEFINE_REX_FUNC(sub_820C0DA0) {
	REX_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x820c08b8
	sub_820C08B8(ctx, base);
	return;
}
