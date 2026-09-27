DEFINE_REX_FUNC(sub_82075408) {
	REX_FUNC_PROLOGUE();
	// lwz r3,1756(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 1756);
	// b 0x820790e8
	sub_820790E8(ctx, base);
	return;
}
