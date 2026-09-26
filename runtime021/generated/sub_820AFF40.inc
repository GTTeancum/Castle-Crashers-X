DEFINE_REX_FUNC(sub_820AFF40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820AFF48;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,0
	ctx.r27.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// ori r27,r27,65535
	ctx.r27.u64 = ctx.r27.u64 | 65535;
	// li r24,0
	ctx.r24.s64 = 0;
	// bl 0x820b61a0
	ctx.lr = 0x820AFF6C;
	sub_820B61A0(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x820aff80
	if (!ctx.cr6.eq) goto loc_820AFF80;
loc_820AFF74:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
loc_820AFF80:
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x820b61a0
	ctx.lr = 0x820AFF94;
	sub_820B61A0(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,65535
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 65535, ctx.xer);
	// bge cr6,0x820affa4
	if (!ctx.cr6.lt) goto loc_820AFFA4;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
loc_820AFFA4:
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// li r3,1028
	ctx.r3.s64 = 1028;
	// lwz r10,-28292(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -28292);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820AFFB8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820aff74
	if (ctx.cr6.eq) goto loc_820AFF74;
	// li r28,4
	ctx.r28.s64 = 4;
	// cmplwi cr6,r27,4
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 4, ctx.xer);
	// ble cr6,0x820b00b8
	if (!ctx.cr6.gt) goto loc_820B00B8;
loc_820AFFD0:
	// addi r11,r28,1024
	ctx.r11.s64 = ctx.r28.s64 + 1024;
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// bgt cr6,0x820affe4
	if (ctx.cr6.gt) goto loc_820AFFE4;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
loc_820AFFE4:
	// subf r29,r28,r26
	ctx.r29.u64 = ctx.r26.u64 - ctx.r28.u64;
	// li r31,1028
	ctx.r31.s64 = 1028;
	// subf r11,r29,r26
	ctx.r11.u64 = ctx.r26.u64 - ctx.r29.u64;
	// cmplwi cr6,r11,1028
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1028, ctx.xer);
	// bgt cr6,0x820afffc
	if (ctx.cr6.gt) goto loc_820AFFFC;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
loc_820AFFFC:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x820b61a0
	ctx.lr = 0x820B0010;
	sub_820B61A0(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x820b00b8
	if (ctx.cr6.eq) goto loc_820B00B8;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x820b6310
	ctx.lr = 0x820B0030;
	sub_820B6310(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820b00ac
	if (ctx.cr6.eq) goto loc_820B00AC;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x820b00ac
	if (!ctx.cr6.eq) goto loc_820B00AC;
	// addic. r11,r31,-3
	ctx.xer.ca = ctx.r31.u32 > 2;
	ctx.r11.s64 = ctx.r31.s64 + -3;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x820b00a0
	if (!ctx.cr0.gt) goto loc_820B00A0;
loc_820B004C:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lbzx r10,r11,r30
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r30.u32);
	// cmplwi cr6,r10,80
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 80, ctx.xer);
	// bne cr6,0x820b008c
	if (!ctx.cr6.eq) goto loc_820B008C;
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lbz r9,1(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// cmplwi cr6,r9,75
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 75, ctx.xer);
	// bne cr6,0x820b008c
	if (!ctx.cr6.eq) goto loc_820B008C;
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lbz r9,2(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// cmplwi cr6,r9,5
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 5, ctx.xer);
	// bne cr6,0x820b008c
	if (!ctx.cr6.eq) goto loc_820B008C;
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lbz r9,3(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// cmplwi cr6,r9,6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 6, ctx.xer);
	// beq cr6,0x820b0098
	if (ctx.cr6.eq) goto loc_820B0098;
loc_820B008C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x820b004c
	if (ctx.cr6.gt) goto loc_820B004C;
	// b 0x820b00a0
	goto loc_820B00A0;
loc_820B0098:
	// add. r24,r11,r29
	ctx.r24.u64 = ctx.r11.u64 + ctx.r29.u64;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// bne 0x820b00b8
	if (!ctx.cr0.eq) goto loc_820B00B8;
loc_820B00A0:
	// cmplw cr6,r28,r27
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r27.u32, ctx.xer);
	// blt cr6,0x820affd0
	if (ctx.cr6.lt) goto loc_820AFFD0;
	// b 0x820b00b8
	goto loc_820B00B8;
loc_820B00AC:
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,-22661(r11)
	REX_STORE_U8(ctx.r11.u32 + -22661, ctx.r10.u8);
loc_820B00B8:
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,-28288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -28288);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820B00CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
