DEFINE_REX_FUNC(sub_82120BE0) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r5,5
	ctx.r10.s64 = ctx.r5.s64 + 5;
	// li r9,4
	ctx.r9.s64 = 4;
	// li r3,7
	ctx.r3.s64 = 7;
	// stw r4,3(r11)
	REX_STORE_U32(ctx.r11.u32 + 3, ctx.r4.u32);
	// stb r9,2(r11)
	REX_STORE_U8(ctx.r11.u32 + 2, ctx.r9.u8);
	// sth r10,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r10.u16);
	// blr 
	return;
}
