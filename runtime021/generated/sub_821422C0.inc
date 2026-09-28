DEFINE_REX_FUNC(sub_821422C0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r11,92(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 92);
	// stb r11,0(r4)
	REX_STORE_U8(ctx.r4.u32 + 0, ctx.r11.u8);
	// blr 
	return;
}
