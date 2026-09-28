DEFINE_REX_FUNC(sub_8212F6A0) {
	REX_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8212f558
	sub_8212F558(ctx, base);
	return;
}
