DEFINE_REX_FUNC(sub_8206EDC0) {
	REX_FUNC_PROLOGUE();
	// li r11,2
	ctx.r11.s64 = 2;
	// li r4,15
	ctx.r4.s64 = 15;
	// sth r11,60(r3)
	REX_STORE_U16(ctx.r3.u32 + 60, ctx.r11.u16);
	// b 0x82053bc8
	sub_82053BC8(ctx, base);
	return;
}
