DEFINE_REX_FUNC(sub_820BC468) {
	REX_FUNC_PROLOGUE();
	// stw r4,11884(r3)
	REX_STORE_U32(ctx.r3.u32 + 11884, ctx.r4.u32);
	// blr 
	return;
}
