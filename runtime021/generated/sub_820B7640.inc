DEFINE_REX_FUNC(sub_820B7640) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r3,1544(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 1544);
	// blr 
	return;
}
