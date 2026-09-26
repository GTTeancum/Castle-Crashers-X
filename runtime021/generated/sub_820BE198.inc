DEFINE_REX_FUNC(sub_820BE198) {
	REX_FUNC_PROLOGUE();
	// stw r4,11856(r3)
	REX_STORE_U32(ctx.r3.u32 + 11856, ctx.r4.u32);
	// addi r4,r3,12676
	ctx.r4.s64 = ctx.r3.s64 + 12676;
	// b 0x820bd978
	sub_820BD978(ctx, base);
	return;
}
