DEFINE_REX_FUNC(sub_82118338) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82118340;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r28,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r28.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r28,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lbz r3,2(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// bl 0x82120778
	ctx.lr = 0x82118364;
	sub_82120778(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x821184d8
	if (!ctx.cr6.eq) goto loc_821184D8;
	// lwz r11,156(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 156);
	// lwz r10,276(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 276);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x821184d8
	if (!ctx.cr6.lt) goto loc_821184D8;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r5,44(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r4,40(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// bl 0x82120960
	ctx.lr = 0x8211838C;
	sub_82120960(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x821184d8
	if (ctx.cr0.eq) goto loc_821184D8;
	// lwz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r11,9(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 9);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x821184d8
	if (!ctx.cr6.eq) goto loc_821184D8;
	// lhz r11,3(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 3);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x821184d8
	if (ctx.cr6.lt) goto loc_821184D8;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,1607
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1607, ctx.xer);
	// bgt cr6,0x821184d8
	if (ctx.cr6.gt) goto loc_821184D8;
	// lhz r9,5(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 5);
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// bgt cr6,0x821184d8
	if (ctx.cr6.gt) goto loc_821184D8;
	// lhz r11,7(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 7);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x821184d8
	if (ctx.cr6.lt) goto loc_821184D8;
	// clrlwi r8,r11,16
	ctx.r8.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r8,60000
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 60000, ctx.xer);
	// bgt cr6,0x821184d8
	if (ctx.cr6.gt) goto loc_821184D8;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x821184d8
	if (ctx.cr6.gt) goto loc_821184D8;
	// lwz r11,21(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 21);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x821184d8
	if (ctx.cr0.eq) goto loc_821184D8;
	// lwz r10,68(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 68);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x821184d8
	if (ctx.cr6.gt) goto loc_821184D8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821209a0
	ctx.lr = 0x82118418;
	sub_821209A0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x821184d8
	if (ctx.cr0.eq) goto loc_821184D8;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,21(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 21);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x821184d8
	if (ctx.cr6.gt) goto loc_821184D8;
	// addi r30,r29,164
	ctx.r30.s64 = ctx.r29.s64 + 164;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a434
	ctx.lr = 0x82118440;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,280(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 280);
	// addi r11,r29,280
	ctx.r11.s64 = ctx.r29.s64 + 280;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82118454
	if (!ctx.cr6.eq) goto loc_82118454;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
loc_82118454:
	// lwz r8,20(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lhz r7,18(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 18);
	// beq cr6,0x82118498
	if (ctx.cr6.eq) goto loc_82118498;
loc_82118464:
	// lwz r6,12(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lhz r9,10(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// cmplw cr6,r8,r6
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x82118484
	if (!ctx.cr6.eq) goto loc_82118484;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// cmplw cr6,r6,r9
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x821184d0
	if (ctx.cr6.eq) goto loc_821184D0;
loc_82118484:
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82118498
	if (ctx.cr6.eq) goto loc_82118498;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82118464
	if (!ctx.cr0.eq) goto loc_82118464;
loc_82118498:
	// lwz r9,276(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 276);
	// addi r10,r31,8
	ctx.r10.s64 = ctx.r31.s64 + 8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,276(r29)
	REX_STORE_U32(ctx.r29.u32 + 276, ctx.r9.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bl 0x8214a444
	ctx.lr = 0x821184C8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x821184dc
	goto loc_821184DC;
loc_821184D0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a444
	ctx.lr = 0x821184D8;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_821184D8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_821184DC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
