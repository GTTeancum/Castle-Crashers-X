DEFINE_REX_FUNC(sub_820A8030) {
	REX_FUNC_PROLOGUE();
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x820c13b8
	sub_820C13B8(ctx, base);
	return;
}
