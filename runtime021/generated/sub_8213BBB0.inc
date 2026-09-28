DEFINE_REX_FUNC(sub_8213BBB0) {
	REX_FUNC_PROLOGUE();
	// lwz r3,192(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 192);
	// blr 
	return;
}
