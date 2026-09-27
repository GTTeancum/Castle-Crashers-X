DEFINE_REX_FUNC(sub_820E8208) {
	REX_FUNC_PROLOGUE();
	// lbz r11,172(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 172);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,0(r4)
	REX_STORE_U8(ctx.r4.u32 + 0, ctx.r11.u8);
	// blr 
	return;
}
