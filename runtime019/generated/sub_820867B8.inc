DEFINE_REX_FUNC(sub_820867B8) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r11,100(r3)
	REX_STORE_U16(ctx.r3.u32 + 100, ctx.r11.u16);
	// blr 
	return;
}
