DEFINE_REX_FUNC(sub_8212A090) {
	REX_FUNC_PROLOGUE();
	// li r3,8
	ctx.r3.s64 = 8;
	// b 0x8212f458
	sub_8212F458(ctx, base);
	return;
}
