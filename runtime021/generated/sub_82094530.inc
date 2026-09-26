DEFINE_REX_FUNC(sub_82094530) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x82094538;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r3,r28,108
	ctx.r3.s64 = ctx.r28.s64 + 108;
	// lhz r4,144(r28)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r28.u32 + 144);
	// bl 0x82082390
	ctx.lr = 0x82094550;
	sub_82082390(ctx, base);
	// stw r3,128(r28)
	REX_STORE_U32(ctx.r28.u32 + 128, ctx.r3.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820b6d10
	ctx.lr = 0x8209455C;
	sub_820B6D10(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820b6d48
	ctx.lr = 0x82094564;
	sub_820B6D48(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820b6d48
	ctx.lr = 0x8209456C;
	sub_820B6D48(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r25,0
	ctx.r25.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// ble cr6,0x820945b0
	if (!ctx.cr6.gt) goto loc_820945B0;
loc_82094580:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8208ab98
	ctx.lr = 0x82094590;
	sub_8208AB98(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x82094640
	if (ctx.cr6.eq) goto loc_82094640;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82094650
	if (ctx.cr6.eq) goto loc_82094650;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82094580
	if (ctx.cr6.lt) goto loc_82094580;
loc_820945B0:
	// lis r11,305
	ctx.r11.s64 = 19988480;
	// ld r26,80(r1)
	ctx.r26.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// mr r27,r25
	ctx.r27.u64 = ctx.r25.u64;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// ori r29,r11,11520
	ctx.r29.u64 = ctx.r11.u64 | 11520;
loc_820945C4:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8208ab98
	ctx.lr = 0x820945D4;
	sub_8208AB98(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x82094640
	if (ctx.cr6.eq) goto loc_82094640;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82094650
	if (ctx.cr6.eq) goto loc_82094650;
	// cmpwi cr6,r3,66
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 66, ctx.xer);
	// beq cr6,0x82094660
	if (ctx.cr6.eq) goto loc_82094660;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// bl 0x820b6d48
	ctx.lr = 0x820945F8;
	sub_820B6D48(ctx, base);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// subf r10,r26,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r26.u64;
	// cmpld cr6,r10,r29
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, ctx.r29.u64, ctx.xer);
	// ble cr6,0x8209460c
	if (!ctx.cr6.gt) goto loc_8209460C;
	// li r27,1
	ctx.r27.s64 = 1;
loc_8209460C:
	// clrlwi r11,r27,24
	ctx.r11.u64 = ctx.r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820945c4
	if (ctx.cr6.eq) goto loc_820945C4;
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r3,1
	ctx.r3.s64 = 1;
	// add r9,r11,r31
	ctx.r9.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// lwz r11,2816(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 2816);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2816(r10)
	REX_STORE_U32(ctx.r10.u32 + 2816, ctx.r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_82094640:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r25,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r25.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_82094650:
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r25,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r25.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_82094660:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
