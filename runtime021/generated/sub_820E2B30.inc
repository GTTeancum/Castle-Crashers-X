DEFINE_REX_FUNC(sub_820E2B30) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r3,22960(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 22960);
	// b 0x820d9b28
	sub_820D9B28(ctx, base);
	return;
}
