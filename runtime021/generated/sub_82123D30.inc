DEFINE_REX_FUNC(sub_82123D30) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,64
	ctx.r5.s64 = 64;
	// sth r11,0(r3)
	REX_STORE_U16(ctx.r3.u32 + 0, ctx.r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,2(r3)
	REX_STORE_U16(ctx.r3.u32 + 2, ctx.r11.u16);
	// sth r11,4(r3)
	REX_STORE_U16(ctx.r3.u32 + 4, ctx.r11.u16);
	// addi r3,r3,6
	ctx.r3.s64 = ctx.r3.s64 + 6;
	// b 0x82129fa0
	sub_82129FA0(ctx, base);
	return;
}
