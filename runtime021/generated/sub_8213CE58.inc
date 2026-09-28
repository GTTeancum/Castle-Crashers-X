DEFINE_REX_FUNC(sub_8213CE58) {
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
	// lis r11,-32236
	ctx.r11.s64 = -2112618496;
	// addi r3,r11,-12928
	ctx.r3.s64 = ctx.r11.s64 + -12928;
	// bl 0x821424e8
	ctx.lr = 0x8213CE70;
	sub_821424E8(ctx, base);
	// lis r11,-32236
	ctx.r11.s64 = -2112618496;
	// addi r3,r11,-12728
	ctx.r3.s64 = ctx.r11.s64 + -12728;
	// bl 0x82142500
	ctx.lr = 0x8213CE7C;
	sub_82142500(ctx, base);
	// lis r11,-32236
	ctx.r11.s64 = -2112618496;
	// addi r3,r11,-12904
	ctx.r3.s64 = ctx.r11.s64 + -12904;
	// bl 0x82142518
	ctx.lr = 0x8213CE88;
	sub_82142518(ctx, base);
	// lis r11,-32236
	ctx.r11.s64 = -2112618496;
	// addi r3,r11,-12856
	ctx.r3.s64 = ctx.r11.s64 + -12856;
	// bl 0x82142530
	ctx.lr = 0x8213CE94;
	sub_82142530(ctx, base);
	// lis r11,-32238
	ctx.r11.s64 = -2112749568;
	// addi r3,r11,31464
	ctx.r3.s64 = ctx.r11.s64 + 31464;
	// bl 0x82142548
	ctx.lr = 0x8213CEA0;
	sub_82142548(ctx, base);
	// lis r11,-32238
	ctx.r11.s64 = -2112749568;
	// addi r3,r11,31240
	ctx.r3.s64 = ctx.r11.s64 + 31240;
	// bl 0x82142560
	ctx.lr = 0x8213CEAC;
	sub_82142560(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
