DEFINE_REX_FUNC(sub_82106368) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f8
	ctx.lr = 0x82106370;
	__savegprlr_20(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r4
	ctx.r22.u64 = ctx.r4.u64;
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// lwz r30,20(r22)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r22.u32 + 20);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82106c60
	if (ctx.cr6.eq) goto loc_82106C60;
	// lis r11,-517
	ctx.r11.s64 = -33882112;
	// lwz r4,24(r22)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r22.u32 + 24);
	// ori r11,r11,65530
	ctx.r11.u64 = ctx.r11.u64 | 65530;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x821063d0
	if (!ctx.cr6.eq) goto loc_821063D0;
	// lwz r3,420(r20)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r20.u32 + 420);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82106c60
	if (ctx.cr6.eq) goto loc_82106C60;
	// lwz r11,396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// rlwinm. r10,r11,0,12,12
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x821063bc
	if (!ctx.cr0.eq) goto loc_821063BC;
	// rlwinm. r11,r11,0,13,13
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82106c60
	if (ctx.cr0.eq) goto loc_82106C60;
loc_821063BC:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r6,40(r22)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r22.u32 + 40);
	// lwz r5,36(r22)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r22.u32 + 36);
	// bl 0x8210ae50
	ctx.lr = 0x821063CC;
	sub_8210AE50(ctx, base);
	// b 0x82106c60
	goto loc_82106C60;
loc_821063D0:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,400(r20)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r20.u32 + 400);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82108f18
	ctx.lr = 0x821063E4;
	sub_82108F18(ctx, base);
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// b 0x821063f8
	goto loc_821063F8;
loc_821063EC:
	// lwz r30,88(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82106c60
	if (ctx.cr6.eq) goto loc_82106C60;
loc_821063F8:
	// lwz r10,24(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x821063ec
	if (!ctx.cr6.eq) goto loc_821063EC;
	// lwz r10,40(r22)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r22.u32 + 40);
	// lwz r11,36(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 36);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// blt cr6,0x82106c60
	if (ctx.cr6.lt) goto loc_82106C60;
	// mr r24,r11
	ctx.r24.u64 = ctx.r11.u64;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// lbz r10,0(r24)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r24.u32 + 0);
	// clrlwi r11,r10,28
	ctx.r11.u64 = ctx.r10.u32 & 0xF;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82106ba4
	if (ctx.cr6.lt) goto loc_82106BA4;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x821069e0
	if (ctx.cr6.eq) goto loc_821069E0;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x821068b4
	if (ctx.cr6.lt) goto loc_821068B4;
	// beq cr6,0x82106864
	if (ctx.cr6.eq) goto loc_82106864;
	// cmplwi cr6,r11,15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 15, ctx.xer);
	// bne cr6,0x82106c60
	if (!ctx.cr6.eq) goto loc_82106C60;
	// lwz r11,32(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82106c60
	if (!ctx.cr6.eq) goto loc_82106C60;
	// rlwinm r11,r10,0,24,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xF0;
	// cmpwi cr6,r11,80
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 80, ctx.xer);
	// bgt cr6,0x821065c8
	if (ctx.cr6.gt) goto loc_821065C8;
	// cmpwi cr6,r11,80
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 80, ctx.xer);
	// beq cr6,0x82106598
	if (ctx.cr6.eq) goto loc_82106598;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82106538
	if (ctx.cr6.eq) goto loc_82106538;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// beq cr6,0x821064f8
	if (ctx.cr6.eq) goto loc_821064F8;
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// beq cr6,0x821064c0
	if (ctx.cr6.eq) goto loc_821064C0;
	// cmpwi cr6,r11,48
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 48, ctx.xer);
	// bne cr6,0x82106c60
	if (!ctx.cr6.eq) goto loc_82106C60;
	// lwz r11,396(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 396);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x821064a4
	if (ctx.cr6.eq) goto loc_821064A4;
	// lwz r11,396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// rlwinm. r11,r11,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82106c60
	if (ctx.cr0.eq) goto loc_82106C60;
loc_821064A4:
	// lwz r11,20(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 20);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x82106c60
	if (!ctx.cr6.eq) goto loc_82106C60;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x82105a18
	ctx.lr = 0x821064BC;
	sub_82105A18(ctx, base);
	// b 0x82106c60
	goto loc_82106C60;
loc_821064C0:
	// lwz r11,396(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 396);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x821064d8
	if (ctx.cr6.eq) goto loc_821064D8;
	// lwz r11,396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// rlwinm. r11,r11,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82106c60
	if (ctx.cr0.eq) goto loc_82106C60;
loc_821064D8:
	// lwz r11,20(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 20);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x821064ec
	if (ctx.cr6.eq) goto loc_821064EC;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x82106c60
	if (!ctx.cr6.eq) goto loc_82106C60;
loc_821064EC:
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x821037d0
	ctx.lr = 0x821064F4;
	sub_821037D0(ctx, base);
	// b 0x82106c60
	goto loc_82106C60;
loc_821064F8:
	// lwz r11,720(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 720);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82106c60
	if (ctx.cr0.eq) goto loc_82106C60;
	// lwz r11,20(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 20);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x82106c60
	if (!ctx.cr6.eq) goto loc_82106C60;
	// lwz r11,28(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 28);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82106c60
	if (!ctx.cr6.eq) goto loc_82106C60;
	// lwz r11,396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// rlwinm. r11,r11,0,5,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82106c60
	if (!ctx.cr0.eq) goto loc_82106C60;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x82104d68
	ctx.lr = 0x82106534;
	sub_82104D68(ctx, base);
	// b 0x82106c60
	goto loc_82106C60;
loc_82106538:
	// lwz r11,396(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 396);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82106c60
	if (!ctx.cr6.eq) goto loc_82106C60;
	// lwz r11,20(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 20);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82106c60
	if (!ctx.cr6.eq) goto loc_82106C60;
	// lwz r11,28(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 28);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82106c60
	if (!ctx.cr6.eq) goto loc_82106C60;
	// lwz r3,12(r20)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r20.u32 + 12);
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,20(r20)
	REX_STORE_U32(ctx.r20.u32 + 20, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r10,24(r20)
	REX_STORE_U32(ctx.r20.u32 + 24, ctx.r10.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210658C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x82104c20
	ctx.lr = 0x82106594;
	sub_82104C20(ctx, base);
	// b 0x82106c60
	goto loc_82106C60;
loc_82106598:
	// lwz r11,396(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 396);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x821065b0
	if (ctx.cr6.eq) goto loc_821065B0;
	// lwz r11,396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// rlwinm. r11,r11,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82106c60
	if (ctx.cr0.eq) goto loc_82106C60;
loc_821065B0:
	// lwz r11,20(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 20);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82106c60
	if (!ctx.cr6.eq) goto loc_82106C60;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x821012a0
	ctx.lr = 0x821065C4;
	sub_821012A0(ctx, base);
	// b 0x82106c60
	goto loc_82106C60;
loc_821065C8:
	// cmpwi cr6,r11,96
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 96, ctx.xer);
	// beq cr6,0x821067e0
	if (ctx.cr6.eq) goto loc_821067E0;
	// cmpwi cr6,r11,112
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 112, ctx.xer);
	// beq cr6,0x82106770
	if (ctx.cr6.eq) goto loc_82106770;
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// bne cr6,0x82106c60
	if (!ctx.cr6.eq) goto loc_82106C60;
	// cmplwi cr6,r8,2
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 2, ctx.xer);
	// blt cr6,0x82106c60
	if (ctx.cr6.lt) goto loc_82106C60;
	// lbz r26,0(r29)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// cmplwi cr6,r26,4
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 4, ctx.xer);
	// bge cr6,0x82106c60
	if (!ctx.cr6.lt) goto loc_82106C60;
	// addi r11,r26,95
	ctx.r11.s64 = ctx.r26.s64 + 95;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r20
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82106c60
	if (ctx.cr6.eq) goto loc_82106C60;
	// lwz r11,84(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 84);
	// li r27,0
	ctx.r27.s64 = 0;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// b 0x82106624
	goto loc_82106624;
loc_8210661C:
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
loc_82106624:
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8210661c
	if (!ctx.cr0.eq) goto loc_8210661C;
	// addi r30,r1,128
	ctx.r30.s64 = ctx.r1.s64 + 128;
	// li r21,1
	ctx.r21.s64 = 1;
loc_82106634:
	// stw r31,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r31.u32);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82106654;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,1(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 1);
	// slw r10,r21,r3
	ctx.r10.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r3.u8 & 0x3F));
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplwi cr6,r26,255
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 255, ctx.xer);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r9,r11,1
	ctx.r9.u64 = ctx.r11.u64 ^ 1;
	// bne cr6,0x8210667c
	if (!ctx.cr6.eq) goto loc_8210667C;
	// li r11,15
	ctx.r11.s64 = 15;
	// b 0x82106684
	goto loc_82106684;
loc_8210667C:
	// slw r11,r21,r26
	ctx.r11.u64 = ctx.r26.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r26.u8 & 0x3F));
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
loc_82106684:
	// rlwinm r10,r11,4,24,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xF0;
	// lbz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 392);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// and r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ctx.r11.u64;
	// rlwinm r8,r8,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// xori r8,r8,1
	ctx.r8.u64 = ctx.r8.u64 ^ 1;
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// beq cr6,0x8210673c
	if (ctx.cr6.eq) goto loc_8210673C;
	// addi r10,r26,4
	ctx.r10.s64 = ctx.r26.s64 + 4;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// slw r10,r21,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r10.u8 & 0x3F));
	// beq cr6,0x821066c8
	if (ctx.cr6.eq) goto loc_821066C8;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// b 0x821066cc
	goto loc_821066CC;
loc_821066C8:
	// andc r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ~ctx.r10.u64;
loc_821066CC:
	// stb r11,392(r31)
	REX_STORE_U8(ctx.r31.u32 + 392, ctx.r11.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8210672c
	if (ctx.cr6.eq) goto loc_8210672C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_821066DC:
	// addi r10,r11,95
	ctx.r10.s64 = ctx.r11.s64 + 95;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r20
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r20.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82106718
	if (ctx.cr6.eq) goto loc_82106718;
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bne cr6,0x82106700
	if (!ctx.cr6.eq) goto loc_82106700;
	// li r10,15
	ctx.r10.s64 = 15;
	// b 0x82106708
	goto loc_82106708;
loc_82106700:
	// slw r10,r21,r11
	ctx.r10.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r11.u8 & 0x3F));
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
loc_82106708:
	// lbz r8,392(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 392);
	// rlwinm r10,r10,4,20,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFF0;
	// and. r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 & ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82106728
	if (ctx.cr0.eq) goto loc_82106728;
loc_82106718:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x821066dc
	if (ctx.cr6.lt) goto loc_821066DC;
	// b 0x8210672c
	goto loc_8210672C;
loc_82106728:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8210672C:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// mr r27,r21
	ctx.r27.u64 = ctx.r21.u64;
	// rlwimi r11,r9,16,15,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0x10000) | (ctx.r11.u64 & 0xFFFFFFFFFFFEFFFF);
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
loc_8210673C:
	// lwz r31,88(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82106634
	if (!ctx.cr6.eq) goto loc_82106634;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x82106c60
	if (ctx.cr6.eq) goto loc_82106C60;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x820fec30
	ctx.lr = 0x8210676C;
	sub_820FEC30(ctx, base);
	// b 0x82106c60
	goto loc_82106C60;
loc_82106770:
	// lwz r11,20(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 20);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bge cr6,0x82106c60
	if (!ctx.cr6.lt) goto loc_82106C60;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x82106790
	if (!ctx.cr6.eq) goto loc_82106790;
	// lwz r11,720(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 720);
	// rlwinm. r11,r11,0,11,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82106c60
	if (!ctx.cr0.eq) goto loc_82106C60;
loc_82106790:
	// lwz r11,396(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 396);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x821067a8
	if (ctx.cr6.eq) goto loc_821067A8;
	// lwz r11,396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// rlwinm. r11,r11,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82106c60
	if (ctx.cr0.eq) goto loc_82106C60;
loc_821067A8:
	// lis r4,-32761
	ctx.r4.s64 = -2147024896;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// ori r4,r4,1226
	ctx.r4.u64 = ctx.r4.u64 | 1226;
	// bl 0x821002a8
	ctx.lr = 0x821067B8;
	sub_821002A8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82106c60
	if (ctx.cr0.lt) goto loc_82106C60;
	// lwz r11,720(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 720);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// oris r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 1048576;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// stw r11,720(r20)
	REX_STORE_U32(ctx.r20.u32 + 720, ctx.r11.u32);
	// bl 0x82100718
	ctx.lr = 0x821067DC;
	sub_82100718(ctx, base);
	// b 0x82106c60
	goto loc_82106C60;
loc_821067E0:
	// lwz r11,20(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 20);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x82106c60
	if (ctx.cr6.eq) goto loc_82106C60;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bge cr6,0x82106c60
	if (!ctx.cr6.lt) goto loc_82106C60;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x82106808
	if (!ctx.cr6.eq) goto loc_82106808;
	// lwz r11,720(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 720);
	// rlwinm. r11,r11,0,11,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82106c60
	if (!ctx.cr0.eq) goto loc_82106C60;
loc_82106808:
	// lwz r11,720(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 720);
	// rlwinm. r10,r11,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82106c60
	if (!ctx.cr0.eq) goto loc_82106C60;
	// lwz r10,28(r20)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r20.u32 + 28);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x82106828
	if (!ctx.cr6.eq) goto loc_82106828;
	// rlwinm. r11,r11,0,20,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82106c60
	if (ctx.cr0.eq) goto loc_82106C60;
loc_82106828:
	// cmplwi cr6,r8,24
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 24, ctx.xer);
	// blt cr6,0x82106c60
	if (ctx.cr6.lt) goto loc_82106C60;
	// ld r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// addi r3,r20,116
	ctx.r3.s64 = ctx.r20.s64 + 116;
	// addi r4,r30,44
	ctx.r4.s64 = ctx.r30.s64 + 44;
	// li r5,36
	ctx.r5.s64 = 36;
	// std r11,108(r20)
	REX_STORE_U64(ctx.r20.u32 + 108, ctx.r11.u64);
	// bl 0x82129a70
	ctx.lr = 0x82106848;
	sub_82129A70(ctx, base);
	// addi r3,r20,152
	ctx.r3.s64 = ctx.r20.s64 + 152;
	// addi r4,r29,8
	ctx.r4.s64 = ctx.r29.s64 + 8;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x82129a70
	ctx.lr = 0x82106858;
	sub_82129A70(ctx, base);
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x821061d0
	ctx.lr = 0x82106860;
	sub_821061D0(ctx, base);
	// b 0x82106c60
	goto loc_82106C60;
loc_82106864:
	// lwz r11,32(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82106c60
	if (!ctx.cr6.eq) goto loc_82106C60;
	// lwz r11,396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// rlwinm. r10,r11,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82106c60
	if (ctx.cr0.eq) goto loc_82106C60;
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82106c60
	if (ctx.cr0.eq) goto loc_82106C60;
	// lwz r3,424(r20)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r20.u32 + 424);
	// stw r8,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// ld r4,16(r30)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r30.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82106c60
	if (ctx.cr6.eq) goto loc_82106C60;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821068B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82106c60
	goto loc_82106C60;
loc_821068B4:
	// cmplwi cr6,r8,5
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 5, ctx.xer);
	// ble cr6,0x82106c60
	if (!ctx.cr6.gt) goto loc_82106C60;
	// lbz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 4);
	// addi r26,r8,-5
	ctx.r26.s64 = ctx.r8.s64 + -5;
	// lwz r27,0(r29)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r25,r29,5
	ctx.r25.s64 = ctx.r29.s64 + 5;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bge cr6,0x82106c60
	if (!ctx.cr6.lt) goto loc_82106C60;
	// lwz r11,248(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 248);
	// addi r28,r20,248
	ctx.r28.s64 = ctx.r20.s64 + 248;
	// b 0x82106914
	goto loc_82106914;
loc_821068E0:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r31,r30,-92
	ctx.r31.s64 = ctx.r30.s64 + -92;
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x82106910
	if (!ctx.cr6.eq) goto loc_82106910;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82106904;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 4);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8210692c
	if (ctx.cr6.eq) goto loc_8210692C;
loc_82106910:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_82106914:
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82106c60
	if (ctx.cr6.eq) goto loc_82106C60;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// bne 0x821068e0
	if (!ctx.cr0.eq) goto loc_821068E0;
	// b 0x82106c60
	goto loc_82106C60;
loc_8210692C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82106c60
	if (ctx.cr6.eq) goto loc_82106C60;
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82106c60
	if (ctx.cr0.eq) goto loc_82106C60;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r10,r31,280
	ctx.r10.s64 = ctx.r31.s64 + 280;
	// addi r11,r31,136
	ctx.r11.s64 = ctx.r31.s64 + 136;
	// addi r4,r20,380
	ctx.r4.s64 = ctx.r20.s64 + 380;
	// li r21,1
	ctx.r21.s64 = 1;
loc_8210695C:
	// addi r8,r6,4
	ctx.r8.s64 = ctx.r6.s64 + 4;
	// lbz r7,0(r24)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r24.u32 + 0);
	// slw r8,r21,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r8.u8 & 0x3F));
	// and. r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 & ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x821069b0
	if (ctx.cr0.eq) goto loc_821069B0;
	// lwz r8,0(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x821069b0
	if (ctx.cr6.eq) goto loc_821069B0;
	// lwz r7,396(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 396);
	// rlwinm. r7,r7,0,4,4
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x821069b0
	if (ctx.cr0.eq) goto loc_821069B0;
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// clrldi r7,r26,32
	ctx.r7.u64 = ctx.r26.u64 & 0xFFFFFFFF;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// ld r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// std r8,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r8.u64);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
loc_821069B0:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r6,4
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 4, ctx.xer);
	// blt cr6,0x8210695c
	if (ctx.cr6.lt) goto loc_8210695C;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82106c60
	if (ctx.cr6.eq) goto loc_82106C60;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x82106c48
	goto loc_82106C48;
loc_821069E0:
	// lwz r11,720(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 720);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821069f4
	if (ctx.cr0.eq) goto loc_821069F4;
	// lwz r23,396(r20)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r20.u32 + 396);
	// b 0x82106a18
	goto loc_82106A18;
loc_821069F4:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r20,380
	ctx.r11.s64 = ctx.r20.s64 + 380;
loc_821069FC:
	// lwz r23,0(r11)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// bne cr6,0x82106a20
	if (!ctx.cr6.eq) goto loc_82106A20;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// blt cr6,0x821069fc
	if (ctx.cr6.lt) goto loc_821069FC;
loc_82106A18:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x82106c60
	if (ctx.cr6.eq) goto loc_82106C60;
loc_82106A20:
	// cmplwi cr6,r8,5
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 5, ctx.xer);
	// ble cr6,0x82106c60
	if (!ctx.cr6.gt) goto loc_82106C60;
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// li r21,1
	ctx.r21.s64 = 1;
	// addi r24,r29,5
	ctx.r24.s64 = ctx.r29.s64 + 5;
	// addi r25,r8,-5
	ctx.r25.s64 = ctx.r8.s64 + -5;
	// lwz r26,0(r28)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82106b20
	if (ctx.cr6.eq) goto loc_82106B20;
	// lbz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 4);
	// rlwinm. r11,r11,0,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF0;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82106c60
	if (ctx.cr0.eq) goto loc_82106C60;
	// lwz r11,248(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 248);
	// addi r27,r20,248
	ctx.r27.s64 = ctx.r20.s64 + 248;
	// b 0x82106a98
	goto loc_82106A98;
loc_82106A5C:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// addi r31,r29,-92
	ctx.r31.s64 = ctx.r29.s64 + -92;
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x82106a94
	if (!ctx.cr6.eq) goto loc_82106A94;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82106A80;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lbz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r28.u32 + 4);
	// slw r11,r21,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r11.u8 & 0x3F));
	// and. r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82106ab0
	if (!ctx.cr0.eq) goto loc_82106AB0;
loc_82106A94:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
loc_82106A98:
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x82106c60
	if (ctx.cr6.eq) goto loc_82106C60;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// bne 0x82106a5c
	if (!ctx.cr0.eq) goto loc_82106A5C;
	// b 0x82106c60
	goto loc_82106C60;
loc_82106AB0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82106c60
	if (ctx.cr6.eq) goto loc_82106C60;
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// rlwinm. r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82106b30
	if (ctx.cr0.eq) goto loc_82106B30;
	// lwz r10,396(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// rlwinm. r10,r10,0,4,4
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82106c60
	if (ctx.cr0.eq) goto loc_82106C60;
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82106c60
	if (ctx.cr0.eq) goto loc_82106C60;
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// clrldi r9,r25,32
	ctx.r9.u64 = ctx.r25.u64 & 0xFFFFFFFF;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// addi r11,r11,17
	ctx.r11.s64 = ctx.r11.s64 + 17;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r5,1
	ctx.r5.s64 = 1;
	// ldx r10,r11,r30
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + ctx.r30.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stdx r10,r11,r30
	REX_STORE_U64(ctx.r11.u32 + ctx.r30.u32, ctx.r10.u64);
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r11,70
	ctx.r11.s64 = ctx.r11.s64 + 70;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r30
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r10,r11,r30
	REX_STORE_U32(ctx.r11.u32 + ctx.r30.u32, ctx.r10.u32);
	// stw r31,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// b 0x82106c44
	goto loc_82106C44;
loc_82106B20:
	// lbz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 4);
	// cmplwi cr6,r11,240
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 240, ctx.xer);
	// bne cr6,0x82106c60
	if (!ctx.cr6.eq) goto loc_82106C60;
	// li r31,0
	ctx.r31.s64 = 0;
loc_82106B30:
	// lwz r9,100(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r9,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// lwz r10,44(r22)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r22.u32 + 44);
	// clrlwi. r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// lwz r9,24(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// stb r9,108(r1)
	REX_STORE_U8(ctx.r1.u32 + 108, ctx.r9.u8);
	// beq 0x82106b54
	if (ctx.cr0.eq) goto loc_82106B54;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
loc_82106B54:
	// rlwinm. r10,r10,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82106b60
	if (ctx.cr0.eq) goto loc_82106B60;
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
loc_82106B60:
	// lwz r10,32(r22)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r22.u32 + 32);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x82106b70
	if (!ctx.cr6.eq) goto loc_82106B70;
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
loc_82106B70:
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// li r10,5
	ctx.r10.s64 = 5;
	// stb r8,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r8.u8);
	// addi r9,r1,104
	ctx.r9.s64 = ctx.r1.s64 + 104;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x820ff3a8
	ctx.lr = 0x82106BA0;
	sub_820FF3A8(ctx, base);
	// b 0x82106c60
	goto loc_82106C60;
loc_82106BA4:
	// lwz r11,396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82106c60
	if (ctx.cr0.eq) goto loc_82106C60;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r10,r30,280
	ctx.r10.s64 = ctx.r30.s64 + 280;
	// addi r11,r30,136
	ctx.r11.s64 = ctx.r30.s64 + 136;
	// addi r3,r20,380
	ctx.r3.s64 = ctx.r20.s64 + 380;
	// li r21,1
	ctx.r21.s64 = 1;
loc_82106BCC:
	// addi r7,r4,4
	ctx.r7.s64 = ctx.r4.s64 + 4;
	// lbz r6,0(r24)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r24.u32 + 0);
	// slw r7,r21,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r7.u8 & 0x3F));
	// and. r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 & ctx.r6.u64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x82106c20
	if (ctx.cr0.eq) goto loc_82106C20;
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82106c20
	if (ctx.cr6.eq) goto loc_82106C20;
	// lwz r6,396(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 396);
	// rlwinm. r6,r6,0,4,4
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq 0x82106c20
	if (ctx.cr0.eq) goto loc_82106C20;
	// clrldi r6,r8,32
	ctx.r6.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// stw r7,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// ld r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// add r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 + ctx.r7.u64;
	// std r7,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r7.u64);
	// lwz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stw r7,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
loc_82106C20:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r4,4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 4, ctx.xer);
	// blt cr6,0x82106bcc
	if (ctx.cr6.lt) goto loc_82106BCC;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82106c60
	if (ctx.cr6.eq) goto loc_82106C60;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
loc_82106C44:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
loc_82106C48:
	// lwz r3,12(r20)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r20.u32 + 12);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82106C60;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82106C60:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
}
