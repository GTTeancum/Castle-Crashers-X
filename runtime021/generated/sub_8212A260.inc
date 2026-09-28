DEFINE_REX_FUNC(sub_8212A260) {
	REX_FUNC_PROLOGUE();
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8212a100
	sub_8212A100(ctx, base);
	return;
}
