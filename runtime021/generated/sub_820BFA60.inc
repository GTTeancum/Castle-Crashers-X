DEFINE_REX_FUNC(sub_820BFA60) {
	REX_FUNC_PROLOGUE();
	// lwz r3,13780(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 13780);
	// lis r4,-20096
	ctx.r4.s64 = -1317011456;
	// b 0x82136708
	sub_82136708(ctx, base);
	return;
}
