DEFINE_REX_FUNC(sub_8212EC40) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// stw r3,23308(r11)
	REX_STORE_U32(ctx.r11.u32 + 23308, ctx.r3.u32);
	// blr 
	return;
}
