DEFINE_REX_FUNC(sub_8212A270) {
	REX_FUNC_PROLOGUE();
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8212a100
	sub_8212A100(ctx, base);
	return;
}
