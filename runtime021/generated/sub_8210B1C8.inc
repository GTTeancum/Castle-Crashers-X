DEFINE_REX_FUNC(sub_8210B1C8) {
	REX_FUNC_PROLOGUE();
	// lwz r3,80(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// blr 
	return;
}
