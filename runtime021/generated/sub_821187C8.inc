DEFINE_REX_FUNC(sub_821187C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x821187D0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r11,r11,-20460
	ctx.r11.s64 = ctx.r11.s64 + -20460;
	// addi r10,r10,-20468
	ctx.r10.s64 = ctx.r10.s64 + -20468;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r29,r31,340
	ctx.r29.s64 = ctx.r31.s64 + 340;
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x821187FC;
	sub_8208C5D8(ctx, base);
	// lwz r3,388(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 388);
	// bl 0x821180d8
	ctx.lr = 0x82118804;
	sub_821180D8(ctx, base);
	// lwz r3,436(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 436);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8211881c
	if (ctx.cr6.eq) goto loc_8211881C;
	// bl 0x821180d8
	ctx.lr = 0x82118814;
	sub_821180D8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,436(r31)
	REX_STORE_U32(ctx.r31.u32 + 436, ctx.r11.u32);
loc_8211881C:
	// lwz r3,432(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 432);
	// bl 0x821180d8
	ctx.lr = 0x82118824;
	sub_821180D8(ctx, base);
	// addi r30,r31,392
	ctx.r30.s64 = ctx.r31.s64 + 392;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x82118830;
	sub_8208C5D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211fbb0
	ctx.lr = 0x82118838;
	sub_8211FBB0(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x8210c788
	ctx.lr = 0x82118840;
	sub_8210C788(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x82118848;
	sub_8208C5D8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x82118850;
	sub_8208C5D8(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r11,r11,-20668
	ctx.r11.s64 = ctx.r11.s64 + -20668;
	// addi r10,r10,-20476
	ctx.r10.s64 = ctx.r10.s64 + -20476;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
