DEFINE_REX_FUNC(sub_82053AC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// addi r4,r11,872
	ctx.r4.s64 = ctx.r11.s64 + 872;
	// bl 0x82054170
	ctx.lr = 0x82053AE0;
	sub_82054170(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,436
	ctx.r4.s64 = ctx.r11.s64 + 436;
	// bl 0x82054528
	ctx.lr = 0x82053AF0;
	sub_82054528(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,1308
	ctx.r4.s64 = ctx.r11.s64 + 1308;
	// bl 0x82054858
	ctx.lr = 0x82053B00;
	sub_82054858(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,1744
	ctx.r4.s64 = ctx.r11.s64 + 1744;
	// bl 0x820585a8
	ctx.lr = 0x82053B10;
	sub_820585A8(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,2180
	ctx.r4.s64 = ctx.r11.s64 + 2180;
	// bl 0x820589f0
	ctx.lr = 0x82053B20;
	sub_820589F0(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,2616
	ctx.r4.s64 = ctx.r11.s64 + 2616;
	// bl 0x82058f88
	ctx.lr = 0x82053B30;
	sub_82058F88(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,3052
	ctx.r4.s64 = ctx.r11.s64 + 3052;
	// bl 0x82059210
	ctx.lr = 0x82053B40;
	sub_82059210(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,3488
	ctx.r4.s64 = ctx.r11.s64 + 3488;
	// bl 0x82059600
	ctx.lr = 0x82053B50;
	sub_82059600(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,3924
	ctx.r4.s64 = ctx.r11.s64 + 3924;
	// bl 0x82059ee8
	ctx.lr = 0x82053B60;
	sub_82059EE8(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,4360
	ctx.r4.s64 = ctx.r11.s64 + 4360;
	// bl 0x8205d5a8
	ctx.lr = 0x82053B70;
	sub_8205D5A8(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,4796
	ctx.r4.s64 = ctx.r11.s64 + 4796;
	// bl 0x8205d8e0
	ctx.lr = 0x82053B80;
	sub_8205D8E0(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,5232
	ctx.r4.s64 = ctx.r11.s64 + 5232;
	// bl 0x8205e7e0
	ctx.lr = 0x82053B90;
	sub_8205E7E0(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,5668
	ctx.r4.s64 = ctx.r11.s64 + 5668;
	// bl 0x8205f6e0
	ctx.lr = 0x82053BA0;
	sub_8205F6E0(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6104
	ctx.r4.s64 = ctx.r11.s64 + 6104;
	// bl 0x820552b8
	ctx.lr = 0x82053BB0;
	sub_820552B8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
