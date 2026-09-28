DEFINE_REX_FUNC(sub_8210B348) {
	REX_FUNC_PROLOGUE();
	// ld r3,16(r3)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// blr 
	return;
}
