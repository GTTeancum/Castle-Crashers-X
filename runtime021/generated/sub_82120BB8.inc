DEFINE_REX_FUNC(sub_82120BB8) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r3,11
	ctx.r3.s64 = 11;
	// stw r4,3(r11)
	REX_STORE_U32(ctx.r11.u32 + 3, ctx.r4.u32);
	// stw r5,7(r11)
	REX_STORE_U32(ctx.r11.u32 + 7, ctx.r5.u32);
	// sth r10,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r10.u16);
	// stb r9,2(r11)
	REX_STORE_U8(ctx.r11.u32 + 2, ctx.r9.u8);
	// blr 
	return;
}
