DEFINE_REX_FUNC(sub_82136F58) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1796(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1796);
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// blr 
	return;
}
