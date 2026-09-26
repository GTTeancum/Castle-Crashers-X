DEFINE_REX_FUNC(sub_820A7470) {
	REX_FUNC_PROLOGUE();
	// lwz r11,28716(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28716);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,28716(r3)
	REX_STORE_U32(ctx.r3.u32 + 28716, ctx.r11.u32);
	// blr 
	return;
}
