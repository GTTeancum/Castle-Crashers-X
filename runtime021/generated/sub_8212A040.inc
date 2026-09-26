DEFINE_REX_FUNC(sub_8212A040) {
	REX_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8214a954
	__imp__KeBugCheck(ctx, base);
	return;
}
