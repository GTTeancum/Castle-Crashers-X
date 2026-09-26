DEFINE_REX_FUNC(sub_8212A280) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212ec40
	ctx.lr = 0x8212A294;
	sub_8212EC40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821303f8
	ctx.lr = 0x8212A29C;
	sub_821303F8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212c288
	ctx.lr = 0x8212A2A4;
	sub_8212C288(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212c3e0
	ctx.lr = 0x8212A2AC;
	sub_8212C3E0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8208c5d8
	ctx.lr = 0x8212A2B4;
	sub_8208C5D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821303e0
	ctx.lr = 0x8212A2BC;
	sub_821303E0(ctx, base);
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// addi r11,r11,-23968
	ctx.r11.s64 = ctx.r11.s64 + -23968;
	// stw r11,31232(r10)
	REX_STORE_U32(ctx.r10.u32 + 31232, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
