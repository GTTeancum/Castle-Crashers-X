DEFINE_REX_FUNC(sub_820E0660) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r9,r11,-31984
	ctx.r9.s64 = ctx.r11.s64 + -31984;
	// addi r8,r10,-32012
	ctx.r8.s64 = ctx.r10.s64 + -32012;
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// stw r8,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r7,16(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// addi r11,r11,52
	ctx.r11.s64 = ctx.r11.s64 + 52;
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// addi r8,r5,-32376
	ctx.r8.s64 = ctx.r5.s64 + -32376;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// addi r9,r6,-32056
	ctx.r9.s64 = ctx.r6.s64 + -32056;
	// addi r6,r4,-32372
	ctx.r6.s64 = ctx.r4.s64 + -32372;
	// lwz r10,4(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,-52(r5)
	REX_STORE_U32(ctx.r5.u32 + -52, ctx.r9.u32);
	// stw r8,208(r3)
	REX_STORE_U32(ctx.r3.u32 + 208, ctx.r8.u32);
	// stw r6,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// blr 
	return;
}
