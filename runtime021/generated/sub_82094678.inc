DEFINE_REX_FUNC(sub_82094678) {
	REX_FUNC_PROLOGUE();
	// stb r4,102(r3)
	REX_STORE_U8(ctx.r3.u32 + 102, ctx.r4.u8);
	// blr 
	return;
}
