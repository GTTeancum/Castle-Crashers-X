DEFINE_REX_FUNC(sub_820D1AE8) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,6423(r10)
	REX_STORE_U8(ctx.r10.u32 + 6423, ctx.r11.u8);
	// blr 
	return;
}
