DEFINE_REX_FUNC(sub_821321D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x821321D8;
	__savegprlr_26(ctx, base);
	// addi r31,r1,-160
	ctx.r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r29,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r29.u32);
	// li r26,0
	ctx.r26.s64 = 0;
	// cmpwi cr6,r29,11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 11, ctx.xer);
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
	// stw r28,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
	// stw r27,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r27.u32);
	// bgt cr6,0x821322ac
	if (ctx.cr6.gt) goto loc_821322AC;
	// beq cr6,0x82132228
	if (ctx.cr6.eq) goto loc_82132228;
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// beq cr6,0x82132240
	if (ctx.cr6.eq) goto loc_82132240;
	// cmpwi cr6,r29,4
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 4, ctx.xer);
	// beq cr6,0x82132228
	if (ctx.cr6.eq) goto loc_82132228;
	// cmpwi cr6,r29,6
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 6, ctx.xer);
	// beq cr6,0x821322ec
	if (ctx.cr6.eq) goto loc_821322EC;
	// cmpwi cr6,r29,8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 8, ctx.xer);
	// bne cr6,0x821322c4
	if (!ctx.cr6.eq) goto loc_821322C4;
loc_82132228:
	// bl 0x8212a3b8
	ctx.lr = 0x8213222C;
	sub_8212A3B8(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// stw r27,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r27.u32);
	// bne 0x82132250
	if (!ctx.cr0.eq) goto loc_82132250;
loc_82132238:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82132468
	goto loc_82132468;
loc_82132240:
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r30,r11,23732
	ctx.r30.s64 = ctx.r11.s64 + 23732;
	// lwz r11,23732(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 23732);
	// b 0x82132324
	goto loc_82132324;
loc_82132250:
	// lwz r10,92(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 92);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lis r9,-32234
	ctx.r9.s64 = -2112487424;
	// lwz r8,-32364(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32364);
loc_82132260:
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpw cr6,r9,r29
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x82132280
	if (ctx.cr6.eq) goto loc_82132280;
	// mulli r9,r8,12
	ctx.r9.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(12));
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82132260
	if (ctx.cr6.lt) goto loc_82132260;
loc_82132280:
	// mulli r9,r8,12
	ctx.r9.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(12));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8213229c
	if (!ctx.cr6.lt) goto loc_8213229C;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpw cr6,r10,r29
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x821322a0
	if (ctx.cr6.eq) goto loc_821322A0;
loc_8213229C:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_821322A0:
	// addi r30,r11,8
	ctx.r30.s64 = ctx.r11.s64 + 8;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x8213232c
	goto loc_8213232C;
loc_821322AC:
	// cmpwi cr6,r29,15
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 15, ctx.xer);
	// beq cr6,0x82132314
	if (ctx.cr6.eq) goto loc_82132314;
	// cmpwi cr6,r29,21
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 21, ctx.xer);
	// beq cr6,0x82132300
	if (ctx.cr6.eq) goto loc_82132300;
	// cmpwi cr6,r29,22
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 22, ctx.xer);
	// beq cr6,0x821322ec
	if (ctx.cr6.eq) goto loc_821322EC;
loc_821322C4:
	// bl 0x821294e0
	ctx.lr = 0x821322C8;
	sub_821294E0(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212c298
	ctx.lr = 0x821322E8;
	sub_8212C298(ctx, base);
	// b 0x82132238
	goto loc_82132238;
loc_821322EC:
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r11,r11,23732
	ctx.r11.s64 = ctx.r11.s64 + 23732;
	// addi r30,r11,8
	ctx.r30.s64 = ctx.r11.s64 + 8;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82132324
	goto loc_82132324;
loc_82132300:
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r11,r11,23732
	ctx.r11.s64 = ctx.r11.s64 + 23732;
	// addi r30,r11,4
	ctx.r30.s64 = ctx.r11.s64 + 4;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82132324
	goto loc_82132324;
loc_82132314:
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r11,r11,23732
	ctx.r11.s64 = ctx.r11.s64 + 23732;
	// addi r30,r11,12
	ctx.r30.s64 = ctx.r11.s64 + 12;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
loc_82132324:
	// li r28,1
	ctx.r28.s64 = 1;
	// stw r28,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
loc_8213232C:
	// stw r11,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x82132464
	if (ctx.cr6.eq) goto loc_82132464;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82132348
	if (!ctx.cr6.eq) goto loc_82132348;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x8212a260
	ctx.lr = 0x82132348;
	sub_8212A260(ctx, base);
loc_82132348:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x82132358
	if (ctx.cr6.eq) goto loc_82132358;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212f458
	ctx.lr = 0x82132358;
	sub_8212F458(ctx, base);
loc_82132358:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// cmpwi cr6,r29,8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 8, ctx.xer);
	// beq cr6,0x82132378
	if (ctx.cr6.eq) goto loc_82132378;
	// cmpwi cr6,r29,11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 11, ctx.xer);
	// beq cr6,0x82132378
	if (ctx.cr6.eq) goto loc_82132378;
	// cmpwi cr6,r29,4
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 4, ctx.xer);
	// bne cr6,0x8213239c
	if (!ctx.cr6.eq) goto loc_8213239C;
loc_82132378:
	// lwz r11,96(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 96);
	// cmpwi cr6,r29,8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 8, ctx.xer);
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// stw r26,96(r27)
	REX_STORE_U32(ctx.r27.u32 + 96, ctx.r26.u32);
	// bne cr6,0x821323ec
	if (!ctx.cr6.eq) goto loc_821323EC;
	// lwz r11,100(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 100);
	// li r10,140
	ctx.r10.s64 = 140;
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// stw r10,100(r27)
	REX_STORE_U32(ctx.r27.u32 + 100, ctx.r10.u32);
loc_8213239C:
	// cmpwi cr6,r29,8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 8, ctx.xer);
	// bne cr6,0x821323ec
	if (!ctx.cr6.eq) goto loc_821323EC;
	// lis r8,-32234
	ctx.r8.s64 = -2112487424;
	// lis r7,-32234
	ctx.r7.s64 = -2112487424;
	// lwz r10,-32376(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + -32376);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
loc_821323B8:
	// lwz r9,-32372(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + -32372);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x821323f0
	if (!ctx.cr6.lt) goto loc_821323F0;
	// lwz r9,92(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 92);
	// mulli r10,r11,12
	ctx.r10.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(12));
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r26,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r26.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// lwz r10,-32376(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + -32376);
	// b 0x821323b8
	goto loc_821323B8;
loc_821323EC:
	// stw r26,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r26.u32);
loc_821323F0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	ctx.r12.s64 = ctx.r31.s64 + 160;
	// bl 0x82132490
	ctx.lr = 0x821323FC;
	sub_82132490(ctx, base);
	// lwz r30,180(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// bne cr6,0x82132424
	if (!ctx.cr6.eq) goto loc_82132424;
	// lwz r29,88(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// li r3,8
	ctx.r3.s64 = 8;
	// lwz r4,100(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82132420;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82132434
	goto loc_82132434;
loc_82132424:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82132430;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r29,88(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
loc_82132434:
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// beq cr6,0x8213244c
	if (ctx.cr6.eq) goto loc_8213244C;
	// cmpwi cr6,r30,11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 11, ctx.xer);
	// beq cr6,0x8213244c
	if (ctx.cr6.eq) goto loc_8213244C;
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// bne cr6,0x82132464
	if (!ctx.cr6.eq) goto loc_82132464;
loc_8213244C:
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// stw r11,96(r29)
	REX_STORE_U32(ctx.r29.u32 + 96, ctx.r11.u32);
	// bne cr6,0x82132464
	if (!ctx.cr6.eq) goto loc_82132464;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// stw r11,100(r29)
	REX_STORE_U32(ctx.r29.u32 + 100, ctx.r11.u32);
loc_82132464:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82132468:
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
