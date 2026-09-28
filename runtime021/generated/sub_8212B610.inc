DEFINE_REX_FUNC(sub_8212B610) {
	REX_FUNC_PROLOGUE();
	// li r5,2624
	ctx.r5.s64 = 2624;
	// b 0x8212a760
	sub_8212A760(ctx, base);
	return;
}
