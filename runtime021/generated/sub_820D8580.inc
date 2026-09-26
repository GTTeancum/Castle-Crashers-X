DEFINE_REX_FUNC(sub_820D8580) {
	REX_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x820d84a8
	sub_820D84A8(ctx, base);
	return;
}
