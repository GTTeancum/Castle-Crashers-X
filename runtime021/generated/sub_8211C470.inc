DEFINE_REX_FUNC(sub_8211C470) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8211C478;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,-20356
	ctx.r11.s64 = ctx.r11.s64 + -20356;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r4,536(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 536);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8211c4a8
	if (ctx.cr6.eq) goto loc_8211C4A8;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82108f60
	ctx.lr = 0x8211C4A4;
	sub_82108F60(ctx, base);
	// stw r30,536(r31)
	REX_STORE_U32(ctx.r31.u32 + 536, ctx.r30.u32);
loc_8211C4A8:
	// addi r3,r31,472
	ctx.r3.s64 = ctx.r31.s64 + 472;
	// bl 0x82121c30
	ctx.lr = 0x8211C4B0;
	sub_82121C30(ctx, base);
	// lwz r4,592(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 592);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8211c4c8
	if (ctx.cr6.eq) goto loc_8211C4C8;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82108f60
	ctx.lr = 0x8211C4C4;
	sub_82108F60(ctx, base);
	// stw r30,592(r31)
	REX_STORE_U32(ctx.r31.u32 + 592, ctx.r30.u32);
loc_8211C4C8:
	// addi r3,r31,572
	ctx.r3.s64 = ctx.r31.s64 + 572;
	// bl 0x82122020
	ctx.lr = 0x8211C4D0;
	sub_82122020(ctx, base);
	// addi r30,r31,176
	ctx.r30.s64 = ctx.r31.s64 + 176;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82122268
	ctx.lr = 0x8211C4DC;
	sub_82122268(ctx, base);
	// addi r29,r31,236
	ctx.r29.s64 = ctx.r31.s64 + 236;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82122268
	ctx.lr = 0x8211C4E8;
	sub_82122268(ctx, base);
	// addi r28,r31,296
	ctx.r28.s64 = ctx.r31.s64 + 296;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82122268
	ctx.lr = 0x8211C4F4;
	sub_82122268(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// bl 0x821180d8
	ctx.lr = 0x8211C4FC;
	sub_821180D8(ctx, base);
	// addi r11,r31,356
	ctx.r11.s64 = ctx.r31.s64 + 356;
	// addi r3,r11,8
	ctx.r3.s64 = ctx.r11.s64 + 8;
	// bl 0x8208c5d8
	ctx.lr = 0x8211C508;
	sub_8208C5D8(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r28,8
	ctx.r3.s64 = ctx.r28.s64 + 8;
	// addi r28,r11,-20668
	ctx.r28.s64 = ctx.r11.s64 + -20668;
	// stw r28,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r28.u32);
	// bl 0x8208c5d8
	ctx.lr = 0x8211C51C;
	sub_8208C5D8(ctx, base);
	// stw r28,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r28.u32);
	// addi r3,r29,8
	ctx.r3.s64 = ctx.r29.s64 + 8;
	// bl 0x8208c5d8
	ctx.lr = 0x8211C528;
	sub_8208C5D8(ctx, base);
	// stw r28,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r28.u32);
	// addi r3,r30,8
	ctx.r3.s64 = ctx.r30.s64 + 8;
	// bl 0x8208c5d8
	ctx.lr = 0x8211C534;
	sub_8208C5D8(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r28,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r28.u32);
	// addi r11,r11,-20476
	ctx.r11.s64 = ctx.r11.s64 + -20476;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
