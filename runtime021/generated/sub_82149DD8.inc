DEFINE_REX_FUNC(sub_82149DD8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,6728
	ctx.r11.s64 = ctx.r11.s64 + 6728;
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// bl 0x8214a424
	ctx.lr = 0x82149DF4;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// addi r3,r10,-24184
	ctx.r3.s64 = ctx.r10.s64 + -24184;
	// bl 0x82127fb0
	ctx.lr = 0x82149E00;
	sub_82127FB0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
