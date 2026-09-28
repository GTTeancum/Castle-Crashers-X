DEFINE_REX_FUNC(sub_820BCD48) {
	REX_FUNC_PROLOGUE();
	// lwz r3,10700(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 10700);
	// blr 
	return;
}
