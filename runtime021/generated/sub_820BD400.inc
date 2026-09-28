DEFINE_REX_FUNC(sub_820BD400) {
	REX_FUNC_PROLOGUE();
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r3,11924(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 11924);
	// blr 
	return;
}
