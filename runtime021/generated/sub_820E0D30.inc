DEFINE_REX_FUNC(sub_820E0D30) {
	REX_FUNC_PROLOGUE();
	// stb r4,26(r3)
	REX_STORE_U8(ctx.r3.u32 + 26, ctx.r4.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
