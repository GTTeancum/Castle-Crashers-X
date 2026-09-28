DEFINE_REX_FUNC(sub_820BCB78) {
	REX_FUNC_PROLOGUE();
	// lwz r3,12040(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12040);
	// blr 
	return;
}
