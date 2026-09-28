DEFINE_REX_FUNC(sub_820CC7A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r5,56
	ctx.r5.s64 = 56;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,21752
	ctx.r3.s64 = ctx.r31.s64 + 21752;
	// bl 0x82129fa0
	ctx.lr = 0x820CC7C8;
	sub_82129FA0(ctx, base);
	// li r5,1536
	ctx.r5.s64 = 1536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,21808
	ctx.r3.s64 = ctx.r31.s64 + 21808;
	// bl 0x82129fa0
	ctx.lr = 0x820CC7D8;
	sub_82129FA0(ctx, base);
	// lis r11,10280
	ctx.r11.s64 = 673710080;
	// ori r30,r11,262
	ctx.r30.u64 = ctx.r11.u64 | 262;
	// lwz r11,21680(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21680);
	// cmpw cr6,r11,r30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r30.s32, ctx.xer);
	// beq cr6,0x820cc808
	if (ctx.cr6.eq) goto loc_820CC808;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cc748
	ctx.lr = 0x820CC7F4;
	sub_820CC748(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c0a98
	ctx.lr = 0x820CC800;
	sub_820C0A98(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7228
	ctx.lr = 0x820CC808;
	sub_820C7228(ctx, base);
loc_820CC808:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
