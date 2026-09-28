DEFINE_REX_FUNC(sub_82105460) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x82105468;
	__savegprlr_26(ctx, base);
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r11,20(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// lwz r29,24(r28)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x821056e8
	if (!ctx.cr6.eq) goto loc_821056E8;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// oris r11,r11,128
	ctx.r11.u64 = ctx.r11.u64 | 8388608;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bl 0x82108e60
	ctx.lr = 0x821054A0;
	sub_82108E60(ctx, base);
	// addi r27,r31,380
	ctx.r27.s64 = ctx.r31.s64 + 380;
	// li r26,0
	ctx.r26.s64 = 0;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
loc_821054B0:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821054e8
	if (ctx.cr6.eq) goto loc_821054E8;
	// lwz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r10,100(r11)
	REX_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// bl 0x820d7fa8
	ctx.lr = 0x821054D4;
	sub_820D7FA8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r31,424
	ctx.r3.s64 = ctx.r31.s64 + 424;
	// bl 0x82109038
	ctx.lr = 0x821054E0;
	sub_82109038(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82105870
	if (ctx.cr0.lt) goto loc_82105870;
loc_821054E8:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// blt cr6,0x821054b0
	if (ctx.cr6.lt) goto loc_821054B0;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821055c4
	if (ctx.cr0.eq) goto loc_821055C4;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r11,3
	ctx.r11.s64 = 3;
	// lwz r4,20(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r26,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r26.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82105530;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82105530:
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// li r29,4
	ctx.r29.s64 = 4;
loc_82105538:
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82105550
	if (ctx.cr6.eq) goto loc_82105550;
	// li r5,255
	ctx.r5.s64 = 255;
	// addi r3,r31,256
	ctx.r3.s64 = ctx.r31.s64 + 256;
	// bl 0x82109378
	ctx.lr = 0x82105550;
	sub_82109378(ctx, base);
loc_82105550:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// bne 0x82105538
	if (!ctx.cr0.eq) goto loc_82105538;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821005e8
	ctx.lr = 0x82105564;
	sub_821005E8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82105870
	if (ctx.cr0.lt) goto loc_82105870;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// li r29,4
	ctx.r29.s64 = 4;
loc_82105574:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821055b0
	if (ctx.cr6.eq) goto loc_821055B0;
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// oris r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 134217728;
	// stw r10,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r10.u32);
	// lwz r11,180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// stw r11,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821055B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821055B0:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// bne 0x82105574
	if (!ctx.cr0.eq) goto loc_82105574;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// b 0x82105870
	goto loc_82105870;
loc_821055C4:
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r5,32(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,28(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 28);
	// bl 0x821031e0
	ctx.lr = 0x821055D8;
	sub_821031E0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82105870
	if (ctx.cr0.lt) goto loc_82105870;
	// li r11,31
	ctx.r11.s64 = 31;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// bl 0x82108e70
	ctx.lr = 0x821055F8;
	sub_82108E70(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82105870
	if (ctx.cr0.lt) goto loc_82105870;
	// stw r26,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r26.u32);
	// li r11,3
	ctx.r11.s64 = 3;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,20(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210562C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821056d0
	if (ctx.cr6.eq) goto loc_821056D0;
	// addi r30,r1,304
	ctx.r30.s64 = ctx.r1.s64 + 304;
loc_82105640:
	// li r11,169
	ctx.r11.s64 = 169;
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// bl 0x82108e80
	ctx.lr = 0x8210565C;
	sub_82108E80(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82105870
	if (ctx.cr0.lt) goto loc_82105870;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,169
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 169, ctx.xer);
	// bne cr6,0x821056dc
	if (!ctx.cr6.eq) goto loc_821056DC;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// li r11,4
	ctx.r11.s64 = 4;
loc_8210567C:
	// ld r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,42
	ctx.r10.s64 = ctx.r10.s64 + 42;
	// std r8,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.r8.u64);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// bne 0x8210567c
	if (!ctx.cr0.eq) goto loc_8210567C;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82102a60
	ctx.lr = 0x821056B4;
	sub_82102A60(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82105870
	if (ctx.cr0.lt) goto loc_82105870;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82105640
	if (ctx.cr6.lt) goto loc_82105640;
loc_821056D0:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82105530
	if (!ctx.cr6.eq) goto loc_82105530;
loc_821056DC:
	// lis r3,-32747
	ctx.r3.s64 = -2146107392;
	// ori r3,r3,10
	ctx.r3.u64 = ctx.r3.u64 | 10;
	// b 0x82105870
	goto loc_82105870;
loc_821056E8:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82105750
	if (!ctx.cr6.eq) goto loc_82105750;
	// lwz r11,16(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 16);
	// li r26,0
	ctx.r26.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8210573c
	if (!ctx.cr6.eq) goto loc_8210573C;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821002a8
	ctx.lr = 0x8210570C;
	sub_821002A8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82105870
	if (ctx.cr0.lt) goto loc_82105870;
	// stw r26,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// bl 0x82108e70
	ctx.lr = 0x82105728;
	sub_82108E70(ctx, base);
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// oris r11,r11,80
	ctx.r11.u64 = ctx.r11.u64 | 5242880;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// stw r10,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
loc_8210573C:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// rlwinm r11,r11,0,9,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFF7FFFFF;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// b 0x82105870
	goto loc_82105870;
loc_82105750:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// rlwinm r11,r11,0,10,8
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFBFFFFF;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bl 0x82108e38
	ctx.lr = 0x82105764;
	sub_82108E38(ctx, base);
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// bl 0x82108e28
	ctx.lr = 0x8210576C;
	sub_82108E28(ctx, base);
	// li r26,0
	ctx.r26.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r26,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r26.u32);
	// addi r11,r31,380
	ctx.r11.s64 = ctx.r31.s64 + 380;
	// std r26,648(r31)
	REX_STORE_U64(ctx.r31.u32 + 648, ctx.r26.u64);
	// li r10,4
	ctx.r10.s64 = 4;
	// std r26,656(r31)
	REX_STORE_U64(ctx.r31.u32 + 656, ctx.r26.u64);
	// stw r26,712(r31)
	REX_STORE_U32(ctx.r31.u32 + 712, ctx.r26.u32);
	// stw r26,716(r31)
	REX_STORE_U32(ctx.r31.u32 + 716, ctx.r26.u32);
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
loc_82105794:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821057bc
	if (ctx.cr6.eq) goto loc_821057BC;
	// lwz r8,396(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 396);
	// rlwinm r8,r8,0,19,17
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFDFFF;
	// stw r8,396(r9)
	REX_STORE_U32(ctx.r9.u32 + 396, ctx.r8.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,396(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 396);
	// rlwinm r8,r8,0,20,18
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFEFFF;
	// stw r8,396(r9)
	REX_STORE_U32(ctx.r9.u32 + 396, ctx.r8.u32);
loc_821057BC:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bne 0x82105794
	if (!ctx.cr0.eq) goto loc_82105794;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x821057e4
	if (ctx.cr6.eq) goto loc_821057E4;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x821057e4
	if (ctx.cr6.eq) goto loc_821057E4;
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// b 0x82105858
	goto loc_82105858;
loc_821057E4:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x821057f8
	if (ctx.cr6.lt) goto loc_821057F8;
	// lis r30,-32747
	ctx.r30.s64 = -2146107392;
	// ori r30,r30,10
	ctx.r30.u64 = ctx.r30.u64 | 10;
	// b 0x82105858
	goto loc_82105858;
loc_821057F8:
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// ori r11,r11,4103
	ctx.r11.u64 = ctx.r11.u64 | 4103;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82105850
	if (ctx.cr6.eq) goto loc_82105850;
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// ori r11,r11,4104
	ctx.r11.u64 = ctx.r11.u64 | 4104;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x82105824
	if (!ctx.cr6.eq) goto loc_82105824;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,4320
	ctx.r30.u64 = ctx.r30.u64 | 4320;
	// b 0x82105858
	goto loc_82105858;
loc_82105824:
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// ori r11,r11,4116
	ctx.r11.u64 = ctx.r11.u64 | 4116;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82105850
	if (ctx.cr6.eq) goto loc_82105850;
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// ori r11,r11,4119
	ctx.r11.u64 = ctx.r11.u64 | 4119;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x82105850
	if (!ctx.cr6.eq) goto loc_82105850;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,1617
	ctx.r30.u64 = ctx.r30.u64 | 1617;
	// b 0x82105858
	goto loc_82105858;
loc_82105850:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,1232
	ctx.r30.u64 = ctx.r30.u64 | 1232;
loc_82105858:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82105118
	ctx.lr = 0x82105864;
	sub_82105118(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82105870
	if (ctx.cr0.lt) goto loc_82105870;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82105870:
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
