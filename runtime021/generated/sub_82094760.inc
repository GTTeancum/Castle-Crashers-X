DEFINE_REX_FUNC(sub_82094760) {
	REX_FUNC_PROLOGUE();
	// sth r4,150(r3)
	REX_STORE_U16(ctx.r3.u32 + 150, ctx.r4.u16);
	// blr 
	return;
}
