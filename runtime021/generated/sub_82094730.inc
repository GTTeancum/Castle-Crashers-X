DEFINE_REX_FUNC(sub_82094730) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r11,150(r3)
	REX_STORE_U16(ctx.r3.u32 + 150, ctx.r11.u16);
	// blr 
	return;
}
