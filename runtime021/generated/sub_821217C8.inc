DEFINE_REX_FUNC(sub_821217C8) {
	REX_FUNC_PROLOGUE();
	// lwz r3,28(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// b 0x82120ae0
	sub_82120AE0(ctx, base);
	return;
}
