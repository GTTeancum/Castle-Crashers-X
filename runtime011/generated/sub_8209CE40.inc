DEFINE_REX_FUNC(sub_8209CE40) {
	REX_FUNC_PROLOGUE();
	// stb r4,24(r3)
	REX_STORE_U8(ctx.r3.u32 + 24, ctx.r4.u8);
	// blr 
	return;
}
