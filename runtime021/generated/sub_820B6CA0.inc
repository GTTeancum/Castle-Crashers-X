DEFINE_REX_FUNC(sub_820B6CA0) {
	REX_FUNC_PROLOGUE();
	// li r4,3
	ctx.r4.s64 = 3;
	// b 0x8214a3b4
	__imp__XamNotifyCreateListener(ctx, base);
	return;
}
