DEFINE_REX_FUNC(sub_82094038) {
	REX_FUNC_PROLOGUE();
	// lwz r3,132(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 132);
	// blr 
	return;
}
