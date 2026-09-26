DEFINE_REX_FUNC(sub_820E15E8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r8,r11,-31848
	ctx.r8.s64 = ctx.r11.s64 + -31848;
	// addi r7,r10,-31880
	ctx.r7.s64 = ctx.r10.s64 + -31880;
	// addi r6,r9,-32372
	ctx.r6.s64 = ctx.r9.s64 + -32372;
	// stw r8,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r7,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r6,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// blr 
	return;
}
