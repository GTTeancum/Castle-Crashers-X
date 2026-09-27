DEFINE_REX_FUNC(sub_820867E8) {
	REX_FUNC_PROLOGUE();
	// sth r4,100(r3)
	REX_STORE_U16(ctx.r3.u32 + 100, ctx.r4.u16);
	// blr 
	return;
}
