DEFINE_REX_FUNC(sub_82139310) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,1092(r11)
	REX_STORE_U32(ctx.r11.u32 + 1092, ctx.r10.u32);
	// blr 
	return;
}
