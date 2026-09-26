DEFINE_REX_FUNC(sub_820AA488) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820AA490;
	__savegprlr_27(ctx, base);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r29,r5,4
	ctx.r29.s64 = ctx.r5.s64 + 4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r11,8500
	ctx.r4.s64 = ctx.r11.s64 + 8500;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// bl 0x82127778
	ctx.lr = 0x820AA4B4;
	sub_82127778(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820b64e0
	ctx.lr = 0x820AA4D4;
	sub_820B64E0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// bne cr6,0x820aa50c
	if (!ctx.cr6.eq) goto loc_820AA50C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r11,8416
	ctx.r3.s64 = ctx.r11.s64 + 8416;
	// bl 0x8208c5d8
	ctx.lr = 0x820AA4F0;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_820AA50C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820b6ad8
	ctx.lr = 0x820AA518;
	sub_820B6AD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82128f70
	ctx.lr = 0x820AA520;
	sub_82128F70(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820aa550
	if (!ctx.cr6.eq) goto loc_820AA550;
	// bl 0x820b6498
	ctx.lr = 0x820AA534;
	sub_820B6498(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_820AA550:
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x820b6310
	ctx.lr = 0x820AA564;
	sub_820B6310(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820b6498
	ctx.lr = 0x820AA56C;
	sub_820B6498(ctx, base);
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x820aa59c
	if (ctx.cr6.eq) goto loc_820AA59C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820b6190
	ctx.lr = 0x820AA580;
	sub_820B6190(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_820AA59C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r29,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
