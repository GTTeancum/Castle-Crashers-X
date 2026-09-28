DEFINE_REX_FUNC(sub_820DCEB8) {
	REX_FUNC_PROLOGUE();
	// li r11,6
	ctx.r11.s64 = 6;
	// li r10,3750
	ctx.r10.s64 = 3750;
	// stb r11,0(r4)
	REX_STORE_U8(ctx.r4.u32 + 0, ctx.r11.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r10,2(r4)
	REX_STORE_U16(ctx.r4.u32 + 2, ctx.r10.u16);
	// blr 
	return;
}
