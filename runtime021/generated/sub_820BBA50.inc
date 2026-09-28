DEFINE_REX_FUNC(sub_820BBA50) {
	REX_FUNC_PROLOGUE();
	// lhz r11,11848(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 11848);
	// clrlwi r3,r11,27
	ctx.r3.u64 = ctx.r11.u32 & 0x1F;
	// blr 
	return;
}
