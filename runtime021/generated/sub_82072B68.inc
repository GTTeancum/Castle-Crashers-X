DEFINE_REX_FUNC(sub_82072B68) {
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
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r31,832
	ctx.r3.s64 = ctx.r31.s64 + 832;
	// addi r10,r11,-8200
	ctx.r10.s64 = ctx.r11.s64 + -8200;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82073cf8
	ctx.lr = 0x82072B90;
	sub_82073CF8(ctx, base);
	// addi r3,r31,796
	ctx.r3.s64 = ctx.r31.s64 + 796;
	// bl 0x82073cf8
	ctx.lr = 0x82072B98;
	sub_82073CF8(ctx, base);
	// addi r3,r31,760
	ctx.r3.s64 = ctx.r31.s64 + 760;
	// bl 0x82073cf8
	ctx.lr = 0x82072BA0;
	sub_82073CF8(ctx, base);
	// addi r3,r31,724
	ctx.r3.s64 = ctx.r31.s64 + 724;
	// bl 0x82073cf8
	ctx.lr = 0x82072BA8;
	sub_82073CF8(ctx, base);
	// addi r3,r31,688
	ctx.r3.s64 = ctx.r31.s64 + 688;
	// bl 0x82073cf8
	ctx.lr = 0x82072BB0;
	sub_82073CF8(ctx, base);
	// addi r3,r31,652
	ctx.r3.s64 = ctx.r31.s64 + 652;
	// bl 0x82073cf8
	ctx.lr = 0x82072BB8;
	sub_82073CF8(ctx, base);
	// addi r3,r31,616
	ctx.r3.s64 = ctx.r31.s64 + 616;
	// bl 0x82073cf8
	ctx.lr = 0x82072BC0;
	sub_82073CF8(ctx, base);
	// addi r3,r31,580
	ctx.r3.s64 = ctx.r31.s64 + 580;
	// bl 0x82073cf8
	ctx.lr = 0x82072BC8;
	sub_82073CF8(ctx, base);
	// addi r3,r31,544
	ctx.r3.s64 = ctx.r31.s64 + 544;
	// bl 0x82073cf8
	ctx.lr = 0x82072BD0;
	sub_82073CF8(ctx, base);
	// addi r3,r31,508
	ctx.r3.s64 = ctx.r31.s64 + 508;
	// bl 0x82073cf8
	ctx.lr = 0x82072BD8;
	sub_82073CF8(ctx, base);
	// addi r3,r31,472
	ctx.r3.s64 = ctx.r31.s64 + 472;
	// bl 0x82073cf8
	ctx.lr = 0x82072BE0;
	sub_82073CF8(ctx, base);
	// addi r3,r31,436
	ctx.r3.s64 = ctx.r31.s64 + 436;
	// bl 0x82073cf8
	ctx.lr = 0x82072BE8;
	sub_82073CF8(ctx, base);
	// addi r3,r31,400
	ctx.r3.s64 = ctx.r31.s64 + 400;
	// bl 0x82073cf8
	ctx.lr = 0x82072BF0;
	sub_82073CF8(ctx, base);
	// addi r3,r31,364
	ctx.r3.s64 = ctx.r31.s64 + 364;
	// bl 0x82073cf8
	ctx.lr = 0x82072BF8;
	sub_82073CF8(ctx, base);
	// addi r3,r31,328
	ctx.r3.s64 = ctx.r31.s64 + 328;
	// bl 0x82073cf8
	ctx.lr = 0x82072C00;
	sub_82073CF8(ctx, base);
	// addi r3,r31,292
	ctx.r3.s64 = ctx.r31.s64 + 292;
	// bl 0x82073cf8
	ctx.lr = 0x82072C08;
	sub_82073CF8(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = ctx.r31.s64 + 256;
	// bl 0x82073cf8
	ctx.lr = 0x82072C10;
	sub_82073CF8(ctx, base);
	// addi r3,r31,220
	ctx.r3.s64 = ctx.r31.s64 + 220;
	// bl 0x82073cf8
	ctx.lr = 0x82072C18;
	sub_82073CF8(ctx, base);
	// addi r3,r31,184
	ctx.r3.s64 = ctx.r31.s64 + 184;
	// bl 0x82073cf8
	ctx.lr = 0x82072C20;
	sub_82073CF8(ctx, base);
	// addi r3,r31,148
	ctx.r3.s64 = ctx.r31.s64 + 148;
	// bl 0x82073cf8
	ctx.lr = 0x82072C28;
	sub_82073CF8(ctx, base);
	// addi r3,r31,112
	ctx.r3.s64 = ctx.r31.s64 + 112;
	// bl 0x82073cf8
	ctx.lr = 0x82072C30;
	sub_82073CF8(ctx, base);
	// addi r3,r31,76
	ctx.r3.s64 = ctx.r31.s64 + 76;
	// bl 0x82073cf8
	ctx.lr = 0x82072C38;
	sub_82073CF8(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// addi r8,r9,-8204
	ctx.r8.s64 = ctx.r9.s64 + -8204;
	// stw r8,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r8.u32);
	// stw r8,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r8.u32);
	// bl 0x82099680
	ctx.lr = 0x82072C50;
	sub_82099680(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// bl 0x82073cf8
	ctx.lr = 0x82072C58;
	sub_82073CF8(ctx, base);
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
