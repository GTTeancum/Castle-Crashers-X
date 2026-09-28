DEFINE_REX_FUNC(sub_821321B8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r3,23740(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 23740);
	// blr 
	return;
}
