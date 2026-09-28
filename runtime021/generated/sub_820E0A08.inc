DEFINE_REX_FUNC(sub_820E0A08) {
	REX_FUNC_PROLOGUE();
	// li r11,28
	ctx.r11.s64 = 28;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}
