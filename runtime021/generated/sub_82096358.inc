DEFINE_REX_FUNC(sub_82096358) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x82096360;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// addi r26,r28,14572
	ctx.r26.s64 = ctx.r28.s64 + 14572;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8214a434
	ctx.lr = 0x82096378;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,136(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 136);
	// bl 0x8209c0d0
	ctx.lr = 0x82096380;
	sub_8209C0D0(ctx, base);
	// cmplw cr6,r3,r25
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r25.u32, ctx.xer);
	// blt cr6,0x8209639c
	if (ctx.cr6.lt) goto loc_8209639C;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8214a444
	ctx.lr = 0x82096390;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_82096390:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_8209639C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-1504
	ctx.r3.s64 = ctx.r11.s64 + -1504;
	// bl 0x8208c5d8
	ctx.lr = 0x820963A8;
	sub_8208C5D8(ctx, base);
	// li r27,0
	ctx.r27.s64 = 0;
loc_820963AC:
	// lwz r11,136(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 136);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82096404
	if (ctx.cr6.eq) goto loc_82096404;
loc_820963C0:
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820963d8
	if (ctx.cr6.eq) goto loc_820963D8;
	// cmplwi cr6,r11,53
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 53, ctx.xer);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// ble cr6,0x820963dc
	if (!ctx.cr6.gt) goto loc_820963DC;
loc_820963D8:
	// li r11,1
	ctx.r11.s64 = 1;
loc_820963DC:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820963f8
	if (ctx.cr6.eq) goto loc_820963F8;
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x820963f8
	if (!ctx.cr6.gt) goto loc_820963F8;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_820963F8:
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820963c0
	if (!ctx.cr6.eq) goto loc_820963C0;
loc_82096404:
	// cmplw cr6,r9,r25
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r25.u32, ctx.xer);
	// bge cr6,0x820964a8
	if (!ctx.cr6.lt) goto loc_820964A8;
	// addi r29,r28,14600
	ctx.r29.s64 = ctx.r28.s64 + 14600;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214a434
	ctx.lr = 0x82096418;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r31,140(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 140);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8209646c
	if (ctx.cr6.eq) goto loc_8209646C;
loc_82096428:
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// lhz r9,112(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 112);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82096460
	if (ctx.cr6.eq) goto loc_82096460;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82096450;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82096460
	if (ctx.cr6.eq) goto loc_82096460;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
loc_82096460:
	// lwz r31,52(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82096428
	if (!ctx.cr6.eq) goto loc_82096428;
loc_8209646C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214a444
	ctx.lr = 0x82096474;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820964a8
	if (ctx.cr6.eq) goto loc_820964A8;
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82096494
	if (!ctx.cr6.gt) goto loc_82096494;
	// lwz r4,24(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// lwz r3,136(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 136);
	// bl 0x8209bf18
	ctx.lr = 0x82096494;
	sub_8209BF18(ctx, base);
loc_82096494:
	// stw r27,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r27.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820966a0
	ctx.lr = 0x820964A4;
	sub_820966A0(ctx, base);
	// b 0x820963ac
	goto loc_820963AC;
loc_820964A8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8214a444
	ctx.lr = 0x820964B0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r11,136(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 136);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82096508
	if (ctx.cr6.eq) goto loc_82096508;
loc_820964C4:
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820964dc
	if (ctx.cr6.eq) goto loc_820964DC;
	// cmplwi cr6,r11,53
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 53, ctx.xer);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// ble cr6,0x820964e0
	if (!ctx.cr6.gt) goto loc_820964E0;
loc_820964DC:
	// li r11,1
	ctx.r11.s64 = 1;
loc_820964E0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820964fc
	if (ctx.cr6.eq) goto loc_820964FC;
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x820964fc
	if (!ctx.cr6.gt) goto loc_820964FC;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_820964FC:
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820964c4
	if (!ctx.cr6.eq) goto loc_820964C4;
loc_82096508:
	// cmplw cr6,r9,r25
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r25.u32, ctx.xer);
	// bge cr6,0x82096390
	if (!ctx.cr6.lt) goto loc_82096390;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r11,-1452
	ctx.r3.s64 = ctx.r11.s64 + -1452;
	// bl 0x8208c5d8
	ctx.lr = 0x82096520;
	sub_8208C5D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
