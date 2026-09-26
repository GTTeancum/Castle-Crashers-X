DEFINE_REX_FUNC(sub_8212C6F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e0
	ctx.lr = 0x8212C6F8;
	__savegprlr_14(ctx, base);
	// stwu r1,-1328(r1)
	ea = -1328 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,0
	ctx.r27.s64 = 0;
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// stw r27,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r27.u32);
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// stw r27,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// stw r27,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// mr r25,r27
	ctx.r25.u64 = ctx.r27.u64;
	// stw r27,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// mr r16,r27
	ctx.r16.u64 = ctx.r27.u64;
	// bne cr6,0x8212c758
	if (!ctx.cr6.eq) goto loc_8212C758;
loc_8212C72C:
	// bl 0x821294e0
	ctx.lr = 0x8212C730;
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
	ctx.lr = 0x8212C750;
	sub_8212C298(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8212d25c
	goto loc_8212D25C;
loc_8212C758:
	// lwz r11,12(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212c824
	if (!ctx.cr0.eq) goto loc_8212C824;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8212e910
	ctx.lr = 0x8212C76C;
	sub_8212E910(ctx, base);
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// addi r30,r11,2976
	ctx.r30.s64 = ctx.r11.s64 + 2976;
	// addi r29,r10,32392
	ctx.r29.s64 = ctx.r10.s64 + 32392;
	// beq cr6,0x8212c7bc
	if (ctx.cr6.eq) goto loc_8212C7BC;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8212e910
	ctx.lr = 0x8212C78C;
	sub_8212E910(ctx, base);
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x8212c7bc
	if (ctx.cr6.eq) goto loc_8212C7BC;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8212e910
	ctx.lr = 0x8212C79C;
	sub_8212E910(ctx, base);
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// rlwinm r31,r11,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8212e910
	ctx.lr = 0x8212C7AC;
	sub_8212E910(ctx, base);
	// lwzx r11,r31,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// rlwinm r10,r3,6,21,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x8212c7c0
	goto loc_8212C7C0;
loc_8212C7BC:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8212C7C0:
	// lbz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 40);
	// rlwinm. r11,r11,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212c72c
	if (!ctx.cr0.eq) goto loc_8212C72C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8212e910
	ctx.lr = 0x8212C7D4;
	sub_8212E910(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8212c814
	if (ctx.cr6.eq) goto loc_8212C814;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8212e910
	ctx.lr = 0x8212C7E4;
	sub_8212E910(ctx, base);
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x8212c814
	if (ctx.cr6.eq) goto loc_8212C814;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8212e910
	ctx.lr = 0x8212C7F4;
	sub_8212E910(ctx, base);
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// rlwinm r31,r11,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8212e910
	ctx.lr = 0x8212C804;
	sub_8212E910(ctx, base);
	// lwzx r11,r31,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// rlwinm r10,r3,6,21,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x8212c818
	goto loc_8212C818;
loc_8212C814:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8212C818:
	// lbz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 40);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212c72c
	if (!ctx.cr0.eq) goto loc_8212C72C;
loc_8212C824:
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x8212c72c
	if (ctx.cr6.eq) goto loc_8212C72C;
	// bl 0x8212bf08
	ctx.lr = 0x8212C830;
	sub_8212BF08(ctx, base);
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// cmplw cr6,r23,r11
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8212d228
	if (ctx.cr6.eq) goto loc_8212D228;
	// bl 0x8212bf08
	ctx.lr = 0x8212C840;
	sub_8212BF08(ctx, base);
	// addi r11,r3,64
	ctx.r11.s64 = ctx.r3.s64 + 64;
	// cmplw cr6,r23,r11
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8212d228
	if (ctx.cr6.eq) goto loc_8212D228;
	// lbz r29,0(r18)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r18.u32 + 0);
	// mr r24,r27
	ctx.r24.u64 = ctx.r27.u64;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// stw r27,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// extsb. r8,r29
	ctx.r8.s64 = ctx.r29.s8;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r24,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// mr r15,r27
	ctx.r15.u64 = ctx.r27.u64;
	// beq 0x8212d220
	if (ctx.cr0.eq) goto loc_8212D220;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r20,112(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lis r10,-32234
	ctx.r10.s64 = -2112487424;
	// lwz r28,112(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r14,-32255
	ctx.r14.s64 = -2113863680;
	// lis r19,-32255
	ctx.r19.s64 = -2113863680;
	// addi r22,r11,32376
	ctx.r22.s64 = ctx.r11.s64 + 32376;
	// addi r21,r10,-32536
	ctx.r21.s64 = ctx.r10.s64 + -32536;
	// addi r17,r9,-17904
	ctx.r17.s64 = ctx.r9.s64 + -17904;
loc_8212C898:
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// blt cr6,0x8212d220
	if (ctx.cr6.lt) goto loc_8212D220;
	// cmpwi cr6,r8,32
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 32, ctx.xer);
	// blt cr6,0x8212c8c4
	if (ctx.cr6.lt) goto loc_8212C8C4;
	// cmpwi cr6,r8,120
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 120, ctx.xer);
	// bgt cr6,0x8212c8c4
	if (ctx.cr6.gt) goto loc_8212C8C4;
	// add r11,r8,r17
	ctx.r11.u64 = ctx.r8.u64 + ctx.r17.u64;
	// lbz r11,-32(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + -32);
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// b 0x8212c8c8
	goto loc_8212C8C8;
loc_8212C8C4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8212C8C8:
	// lwz r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbzx r11,r11,r17
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r17.u32);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// srawi r11,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 4;
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x8212d20c
	if (ctx.cr6.gt) goto loc_8212D20C;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-17696
	ctx.r12.s64 = ctx.r12.s64 + -17696;
	// rlwinm r0,r11,1,0,30
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U16(ctx.r12.u32 + ctx.r0.u32);
	// lis r12,-32237
	ctx.r12.s64 = -2112684032;
	// addi r12,r12,-14056
	ctx.r12.s64 = ctx.r12.s64 + -14056;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8212CAE4;
	case 1:
		goto loc_8212C918;
	case 2:
		goto loc_8212C938;
	case 3:
		goto loc_8212C988;
	case 4:
		goto loc_8212C9D4;
	case 5:
		goto loc_8212C9DC;
	case 6:
		goto loc_8212CA14;
	case 7:
		goto loc_8212CB34;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8212C918:
	// li r27,0
	ctx.r27.s64 = 0;
	// li r25,-1
	ctx.r25.s64 = -1;
	// mr r20,r27
	ctx.r20.u64 = ctx.r27.u64;
	// stw r27,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// stw r27,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// mr r16,r27
	ctx.r16.u64 = ctx.r27.u64;
	// stw r27,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212C938:
	// cmpwi cr6,r8,32
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 32, ctx.xer);
	// beq cr6,0x8212c980
	if (ctx.cr6.eq) goto loc_8212C980;
	// cmpwi cr6,r8,35
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 35, ctx.xer);
	// beq cr6,0x8212c978
	if (ctx.cr6.eq) goto loc_8212C978;
	// cmpwi cr6,r8,43
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 43, ctx.xer);
	// beq cr6,0x8212c970
	if (ctx.cr6.eq) goto loc_8212C970;
	// cmpwi cr6,r8,45
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 45, ctx.xer);
	// beq cr6,0x8212c968
	if (ctx.cr6.eq) goto loc_8212C968;
	// cmpwi cr6,r8,48
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 48, ctx.xer);
	// bne cr6,0x8212d20c
	if (!ctx.cr6.eq) goto loc_8212D20C;
	// ori r27,r27,8
	ctx.r27.u64 = ctx.r27.u64 | 8;
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212C968:
	// ori r27,r27,4
	ctx.r27.u64 = ctx.r27.u64 | 4;
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212C970:
	// ori r27,r27,1
	ctx.r27.u64 = ctx.r27.u64 | 1;
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212C978:
	// ori r27,r27,128
	ctx.r27.u64 = ctx.r27.u64 | 128;
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212C980:
	// ori r27,r27,2
	ctx.r27.u64 = ctx.r27.u64 | 2;
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212C988:
	// cmpwi cr6,r8,42
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 42, ctx.xer);
	// bne cr6,0x8212c9bc
	if (!ctx.cr6.eq) goto loc_8212C9BC;
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// bge cr6,0x8212d20c
	if (!ctx.cr6.lt) goto loc_8212D20C;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// ori r27,r27,4
	ctx.r27.u64 = ctx.r27.u64 | 4;
	// neg r11,r11
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// b 0x8212c9cc
	goto loc_8212C9CC;
loc_8212C9BC:
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// mulli r11,r11,10
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(10));
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r11,r11,-48
	ctx.r11.s64 = ctx.r11.s64 + -48;
loc_8212C9CC:
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212C9D4:
	// li r25,0
	ctx.r25.s64 = 0;
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212C9DC:
	// cmpwi cr6,r8,42
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 42, ctx.xer);
	// bne cr6,0x8212ca04
	if (!ctx.cr6.eq) goto loc_8212CA04;
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r25,4(r11)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bge cr6,0x8212d20c
	if (!ctx.cr6.lt) goto loc_8212D20C;
	// li r25,-1
	ctx.r25.s64 = -1;
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212CA04:
	// mulli r11,r25,10
	ctx.r11.s64 = static_cast<int64_t>(ctx.r25.u64 * static_cast<uint64_t>(10));
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r25,r11,-48
	ctx.r25.s64 = ctx.r11.s64 + -48;
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212CA14:
	// cmpwi cr6,r8,73
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 73, ctx.xer);
	// beq cr6,0x8212ca64
	if (ctx.cr6.eq) goto loc_8212CA64;
	// cmpwi cr6,r8,104
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 104, ctx.xer);
	// beq cr6,0x8212ca5c
	if (ctx.cr6.eq) goto loc_8212CA5C;
	// cmpwi cr6,r8,108
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 108, ctx.xer);
	// beq cr6,0x8212ca3c
	if (ctx.cr6.eq) goto loc_8212CA3C;
	// cmpwi cr6,r8,119
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 119, ctx.xer);
	// bne cr6,0x8212d20c
	if (!ctx.cr6.eq) goto loc_8212D20C;
	// ori r27,r27,2048
	ctx.r27.u64 = ctx.r27.u64 | 2048;
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212CA3C:
	// lbz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 0);
	// cmplwi cr6,r11,108
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 108, ctx.xer);
	// bne cr6,0x8212ca54
	if (!ctx.cr6.eq) goto loc_8212CA54;
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// ori r27,r27,4096
	ctx.r27.u64 = ctx.r27.u64 | 4096;
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212CA54:
	// ori r27,r27,16
	ctx.r27.u64 = ctx.r27.u64 | 16;
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212CA5C:
	// ori r27,r27,32
	ctx.r27.u64 = ctx.r27.u64 | 32;
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212CA64:
	// lbz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 0);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,54
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 54, ctx.xer);
	// bne cr6,0x8212ca8c
	if (!ctx.cr6.eq) goto loc_8212CA8C;
	// lbz r10,1(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 1);
	// cmplwi cr6,r10,52
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 52, ctx.xer);
	// bne cr6,0x8212ca8c
	if (!ctx.cr6.eq) goto loc_8212CA8C;
	// addi r18,r18,2
	ctx.r18.s64 = ctx.r18.s64 + 2;
	// ori r27,r27,32768
	ctx.r27.u64 = ctx.r27.u64 | 32768;
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212CA8C:
	// cmpwi cr6,r11,51
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 51, ctx.xer);
	// bne cr6,0x8212caac
	if (!ctx.cr6.eq) goto loc_8212CAAC;
	// lbz r10,1(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 1);
	// cmplwi cr6,r10,50
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 50, ctx.xer);
	// bne cr6,0x8212caac
	if (!ctx.cr6.eq) goto loc_8212CAAC;
	// addi r18,r18,2
	ctx.r18.s64 = ctx.r18.s64 + 2;
	// rlwinm r27,r27,0,17,15
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xFFFFFFFFFFFF7FFF;
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212CAAC:
	// cmpwi cr6,r11,100
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 100, ctx.xer);
	// beq cr6,0x8212d20c
	if (ctx.cr6.eq) goto loc_8212D20C;
	// cmpwi cr6,r11,105
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 105, ctx.xer);
	// beq cr6,0x8212d20c
	if (ctx.cr6.eq) goto loc_8212D20C;
	// cmpwi cr6,r11,111
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 111, ctx.xer);
	// beq cr6,0x8212d20c
	if (ctx.cr6.eq) goto loc_8212D20C;
	// cmpwi cr6,r11,117
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 117, ctx.xer);
	// beq cr6,0x8212d20c
	if (ctx.cr6.eq) goto loc_8212D20C;
	// cmpwi cr6,r11,120
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 120, ctx.xer);
	// beq cr6,0x8212d20c
	if (ctx.cr6.eq) goto loc_8212D20C;
	// cmpwi cr6,r11,88
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 88, ctx.xer);
	// beq cr6,0x8212d20c
	if (ctx.cr6.eq) goto loc_8212D20C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
loc_8212CAE4:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// clrlwi r3,r29,24
	ctx.r3.u64 = ctx.r29.u32 & 0xFF;
	// li r16,0
	ctx.r16.s64 = 0;
	// bl 0x82132b08
	ctx.lr = 0x8212CAF4;
	sub_82132B08(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8212cb1c
	if (ctx.cr0.eq) goto loc_8212CB1C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8212c5c0
	ctx.lr = 0x8212CB0C;
	sub_8212C5C0(ctx, base);
	// lbz r29,0(r18)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r18.u32 + 0);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// cmplwi r29,0
	ctx.cr0.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq 0x8212c72c
	if (ctx.cr0.eq) goto loc_8212C72C;
loc_8212CB1C:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8212c5c0
	ctx.lr = 0x8212CB2C;
	sub_8212C5C0(ctx, base);
	// lwz r24,80(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8212d20c
	goto loc_8212D20C;
loc_8212CB34:
	// addi r11,r8,-65
	ctx.r11.s64 = ctx.r8.s64 + -65;
	// cmplwi cr6,r11,55
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 55, ctx.xer);
	// bgt cr6,0x8212d038
	if (ctx.cr6.gt) goto loc_8212D038;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-17808
	ctx.r12.s64 = ctx.r12.s64 + -17808;
	// rlwinm r0,r11,1,0,30
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U16(ctx.r12.u32 + ctx.r0.u32);
	// lis r12,-32237
	ctx.r12.s64 = -2112684032;
	// addi r12,r12,-13464
	ctx.r12.s64 = ctx.r12.s64 + -13464;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8212CD44;
	case 1:
		goto loc_8212D038;
	case 2:
		goto loc_8212CB68;
	case 3:
		goto loc_8212D038;
	case 4:
		goto loc_8212CD44;
	case 5:
		goto loc_8212D038;
	case 6:
		goto loc_8212CD44;
	case 7:
		goto loc_8212D038;
	case 8:
		goto loc_8212D038;
	case 9:
		goto loc_8212D038;
	case 10:
		goto loc_8212D038;
	case 11:
		goto loc_8212D038;
	case 12:
		goto loc_8212D038;
	case 13:
		goto loc_8212D038;
	case 14:
		goto loc_8212D038;
	case 15:
		goto loc_8212D038;
	case 16:
		goto loc_8212D038;
	case 17:
		goto loc_8212D038;
	case 18:
		goto loc_8212CC50;
	case 19:
		goto loc_8212D038;
	case 20:
		goto loc_8212D038;
	case 21:
		goto loc_8212D038;
	case 22:
		goto loc_8212D038;
	case 23:
		goto loc_8212CE84;
	case 24:
		goto loc_8212D038;
	case 25:
		goto loc_8212CBD4;
	case 26:
		goto loc_8212D038;
	case 27:
		goto loc_8212D038;
	case 28:
		goto loc_8212D038;
	case 29:
		goto loc_8212D038;
	case 30:
		goto loc_8212D038;
	case 31:
		goto loc_8212D038;
	case 32:
		goto loc_8212CD50;
	case 33:
		goto loc_8212D038;
	case 34:
		goto loc_8212CB78;
	case 35:
		goto loc_8212CE74;
	case 36:
		goto loc_8212CD50;
	case 37:
		goto loc_8212CD50;
	case 38:
		goto loc_8212CD50;
	case 39:
		goto loc_8212D038;
	case 40:
		goto loc_8212CE74;
	case 41:
		goto loc_8212D038;
	case 42:
		goto loc_8212D038;
	case 43:
		goto loc_8212D038;
	case 44:
		goto loc_8212D038;
	case 45:
		goto loc_8212CD08;
	case 46:
		goto loc_8212CEBC;
	case 47:
		goto loc_8212CE80;
	case 48:
		goto loc_8212D038;
	case 49:
		goto loc_8212D038;
	case 50:
		goto loc_8212CC60;
	case 51:
		goto loc_8212D038;
	case 52:
		goto loc_8212CE78;
	case 53:
		goto loc_8212D038;
	case 54:
		goto loc_8212D038;
	case 55:
		goto loc_8212CE8C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8212CB68:
	// andi. r11,r27,2096
	ctx.r11.u64 = ctx.r27.u64 & 2096;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212cb78
	if (!ctx.cr0.eq) goto loc_8212CB78;
	// ori r27,r27,2048
	ctx.r27.u64 = ctx.r27.u64 | 2048;
loc_8212CB78:
	// andi. r11,r27,2064
	ctx.r11.u64 = ctx.r27.u64 & 2064;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// beq 0x8212cbb8
	if (ctx.cr0.eq) goto loc_8212CBB8;
	// li r5,512
	ctx.r5.s64 = 512;
	// lhz r6,6(r11)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x82132b00
	ctx.lr = 0x8212CBA4;
	sub_82132B00(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8212cbc8
	if (ctx.cr0.eq) goto loc_8212CBC8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// b 0x8212cbc8
	goto loc_8212CBC8;
loc_8212CBB8:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stb r11,144(r1)
	REX_STORE_U8(ctx.r1.u32 + 144, ctx.r11.u8);
loc_8212CBC8:
	// lwz r7,84(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r28,r1,144
	ctx.r28.s64 = ctx.r1.s64 + 144;
	// b 0x8212d038
	goto loc_8212D038;
loc_8212CBD4:
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8212cc24
	if (ctx.cr6.eq) goto loc_8212CC24;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8212cc24
	if (ctx.cr6.eq) goto loc_8212CC24;
	// rlwinm. r9,r27,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// beq 0x8212cc18
	if (ctx.cr0.eq) goto loc_8212CC18;
	// lha r11,0(r11)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r11.u32 + 0));
	// li r16,1
	ctx.r16.s64 = 1;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addze r7,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r7.s64 = temp.s64;
	// b 0x8212d034
	goto loc_8212D034;
loc_8212CC18:
	// lha r7,0(r11)
	ctx.r7.s64 = int16_t(REX_LOAD_U16(ctx.r11.u32 + 0));
	// li r16,0
	ctx.r16.s64 = 0;
	// b 0x8212d034
	goto loc_8212D034;
loc_8212CC24:
	// lwz r28,-17916(r19)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r19.u32 + -17916);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
loc_8212CC30:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8212cc30
	if (!ctx.cr6.eq) goto loc_8212CC30;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
loc_8212CC44:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r7,r11,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// b 0x8212d034
	goto loc_8212D034;
loc_8212CC50:
	// andi. r11,r27,2096
	ctx.r11.u64 = ctx.r27.u64 & 2096;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212cc60
	if (!ctx.cr0.eq) goto loc_8212CC60;
	// ori r27,r27,2048
	ctx.r27.u64 = ctx.r27.u64 | 2048;
loc_8212CC60:
	// cmpwi cr6,r25,-1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, -1, ctx.xer);
	// bne cr6,0x8212cc74
	if (!ctx.cr6.eq) goto loc_8212CC74;
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// b 0x8212cc78
	goto loc_8212CC78;
loc_8212CC74:
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
loc_8212CC78:
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// andi. r9,r27,2064
	ctx.r9.u64 = ctx.r27.u64 & 2064;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r28,4(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq 0x8212ccd4
	if (ctx.cr0.eq) goto loc_8212CCD4;
	// bne cr6,0x8212cca0
	if (!ctx.cr6.eq) goto loc_8212CCA0;
	// lwz r28,-17912(r14)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r14.u32 + -17912);
loc_8212CCA0:
	// li r16,1
	ctx.r16.s64 = 1;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x8212ccc0
	goto loc_8212CCC0;
loc_8212CCAC:
	// lhz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x8212ccc8
	if (ctx.cr0.eq) goto loc_8212CCC8;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
loc_8212CCC0:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8212ccac
	if (!ctx.cr6.eq) goto loc_8212CCAC;
loc_8212CCC8:
	// subf r11,r28,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r28.u64;
	// srawi r7,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 1;
	// b 0x8212d034
	goto loc_8212D034;
loc_8212CCD4:
	// bne cr6,0x8212ccdc
	if (!ctx.cr6.eq) goto loc_8212CCDC;
	// lwz r28,-17916(r19)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r19.u32 + -17916);
loc_8212CCDC:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x8212ccf8
	goto loc_8212CCF8;
loc_8212CCE4:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8212cd00
	if (ctx.cr6.eq) goto loc_8212CD00;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_8212CCF8:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8212cce4
	if (!ctx.cr6.eq) goto loc_8212CCE4;
loc_8212CD00:
	// subf r7,r28,r11
	ctx.r7.u64 = ctx.r11.u64 - ctx.r28.u64;
	// b 0x8212d034
	goto loc_8212D034;
loc_8212CD08:
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r31,4(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x821329b8
	ctx.lr = 0x8212CD1C;
	sub_821329B8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8212c72c
	if (ctx.cr0.eq) goto loc_8212C72C;
	// rlwinm. r11,r27,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212cd34
	if (ctx.cr0.eq) goto loc_8212CD34;
	// sth r24,0(r31)
	REX_STORE_U16(ctx.r31.u32 + 0, ctx.r24.u16);
	// b 0x8212cd38
	goto loc_8212CD38;
loc_8212CD34:
	// stw r24,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r24.u32);
loc_8212CD38:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// b 0x8212d1f8
	goto loc_8212D1F8;
loc_8212CD44:
	// addi r11,r8,32
	ctx.r11.s64 = ctx.r8.s64 + 32;
	// li r20,1
	ctx.r20.s64 = 1;
	// extsb r29,r11
	ctx.r29.s64 = ctx.r11.s8;
loc_8212CD50:
	// ori r27,r27,64
	ctx.r27.u64 = ctx.r27.u64 | 64;
	// addi r28,r1,144
	ctx.r28.s64 = ctx.r1.s64 + 144;
	// li r30,512
	ctx.r30.s64 = 512;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bge cr6,0x8212cd6c
	if (!ctx.cr6.lt) goto loc_8212CD6C;
	// li r25,6
	ctx.r25.s64 = 6;
	// b 0x8212cdbc
	goto loc_8212CDBC;
loc_8212CD6C:
	// bne cr6,0x8212cd84
	if (!ctx.cr6.eq) goto loc_8212CD84;
	// extsb r11,r29
	ctx.r11.s64 = ctx.r29.s8;
	// cmpwi cr6,r11,103
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 103, ctx.xer);
	// bne cr6,0x8212cdbc
	if (!ctx.cr6.eq) goto loc_8212CDBC;
	// li r25,1
	ctx.r25.s64 = 1;
	// b 0x8212cdbc
	goto loc_8212CDBC;
loc_8212CD84:
	// cmpwi cr6,r25,512
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 512, ctx.xer);
	// ble cr6,0x8212cd90
	if (!ctx.cr6.gt) goto loc_8212CD90;
	// li r25,512
	ctx.r25.s64 = 512;
loc_8212CD90:
	// cmpwi cr6,r25,163
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 163, ctx.xer);
	// ble cr6,0x8212cdbc
	if (!ctx.cr6.gt) goto loc_8212CDBC;
	// addi r31,r25,349
	ctx.r31.s64 = ctx.r25.s64 + 349;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82128f70
	ctx.lr = 0x8212CDA4;
	sub_82128F70(ctx, base);
	// mr. r15,r3
	ctx.r15.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// beq 0x8212cdb8
	if (ctx.cr0.eq) goto loc_8212CDB8;
	// mr r28,r15
	ctx.r28.u64 = ctx.r15.u64;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// b 0x8212cdbc
	goto loc_8212CDBC;
loc_8212CDB8:
	// li r25,163
	ctx.r25.s64 = 163;
loc_8212CDBC:
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// lwz r10,24(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 24);
	// extsb r31,r29
	ctx.r31.s64 = ctx.r29.s8;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8212CDFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm. r30,r27,0,24,24
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8212ce20
	if (ctx.cr0.eq) goto loc_8212CE20;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne cr6,0x8212ce20
	if (!ctx.cr6.eq) goto loc_8212CE20;
	// lwz r11,36(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 36);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8212CE20;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8212CE20:
	// cmpwi cr6,r31,103
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 103, ctx.xer);
	// bne cr6,0x8212ce44
	if (!ctx.cr6.eq) goto loc_8212CE44;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x8212ce44
	if (!ctx.cr6.eq) goto loc_8212CE44;
	// lwz r11,32(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8212CE44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8212CE44:
	// lbz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,45
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 45, ctx.xer);
	// bne cr6,0x8212ce58
	if (!ctx.cr6.eq) goto loc_8212CE58;
	// ori r27,r27,256
	ctx.r27.u64 = ctx.r27.u64 | 256;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_8212CE58:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_8212CE5C:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8212ce5c
	if (!ctx.cr6.eq) goto loc_8212CE5C;
	// subf r11,r28,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r28.u64;
	// b 0x8212cc44
	goto loc_8212CC44;
loc_8212CE74:
	// ori r27,r27,64
	ctx.r27.u64 = ctx.r27.u64 | 64;
loc_8212CE78:
	// li r8,10
	ctx.r8.s64 = 10;
	// b 0x8212cecc
	goto loc_8212CECC;
loc_8212CE80:
	// li r25,8
	ctx.r25.s64 = 8;
loc_8212CE84:
	// li r11,7
	ctx.r11.s64 = 7;
	// b 0x8212ce90
	goto loc_8212CE90;
loc_8212CE8C:
	// li r11,39
	ctx.r11.s64 = 39;
loc_8212CE90:
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// rlwinm. r10,r27,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// li r8,16
	ctx.r8.s64 = 16;
	// beq 0x8212cecc
	if (ctx.cr0.eq) goto loc_8212CECC;
	// addi r11,r11,81
	ctx.r11.s64 = ctx.r11.s64 + 81;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,2
	ctx.r9.s64 = 2;
	// stb r11,89(r1)
	REX_STORE_U8(ctx.r1.u32 + 89, ctx.r11.u8);
	// stb r10,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r10.u8);
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// b 0x8212cecc
	goto loc_8212CECC;
loc_8212CEBC:
	// rlwinm. r11,r27,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r8,8
	ctx.r8.s64 = 8;
	// beq 0x8212cecc
	if (ctx.cr0.eq) goto loc_8212CECC;
	// ori r27,r27,512
	ctx.r27.u64 = ctx.r27.u64 | 512;
loc_8212CECC:
	// rlwinm. r11,r27,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212cedc
	if (!ctx.cr0.eq) goto loc_8212CEDC;
	// rlwinm. r11,r27,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212cef0
	if (ctx.cr0.eq) goto loc_8212CEF0;
loc_8212CEDC:
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// b 0x8212cf40
	goto loc_8212CF40;
loc_8212CEF0:
	// rlwinm. r11,r27,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212cf20
	if (ctx.cr0.eq) goto loc_8212CF20;
	// rlwinm. r11,r27,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// beq 0x8212cf18
	if (ctx.cr0.eq) goto loc_8212CF18;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// b 0x8212cf40
	goto loc_8212CF40;
loc_8212CF18:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x8212cf40
	goto loc_8212CF40;
loc_8212CF20:
	// rlwinm. r11,r27,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// beq 0x8212cf3c
	if (ctx.cr0.eq) goto loc_8212CF3C;
	// lwa r11,4(r11)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r11.u32 + 4));
	// b 0x8212cf40
	goto loc_8212CF40;
loc_8212CF3C:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_8212CF40:
	// rlwinm. r10,r27,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8212cf58
	if (ctx.cr0.eq) goto loc_8212CF58;
	// cmpdi cr6,r11,0
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 0, ctx.xer);
	// bge cr6,0x8212cf58
	if (!ctx.cr6.lt) goto loc_8212CF58;
	// neg r11,r11
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// ori r27,r27,256
	ctx.r27.u64 = ctx.r27.u64 | 256;
loc_8212CF58:
	// rlwinm. r10,r27,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8212cf6c
	if (!ctx.cr0.eq) goto loc_8212CF6C;
	// rlwinm. r10,r27,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8212cf6c
	if (!ctx.cr0.eq) goto loc_8212CF6C;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
loc_8212CF6C:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bge cr6,0x8212cf7c
	if (!ctx.cr6.lt) goto loc_8212CF7C;
	// li r25,1
	ctx.r25.s64 = 1;
	// b 0x8212cf8c
	goto loc_8212CF8C;
loc_8212CF7C:
	// rlwinm r27,r27,0,29,27
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// cmpwi cr6,r25,512
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 512, ctx.xer);
	// ble cr6,0x8212cf8c
	if (!ctx.cr6.gt) goto loc_8212CF8C;
	// li r25,512
	ctx.r25.s64 = 512;
loc_8212CF8C:
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// bne cr6,0x8212cf9c
	if (!ctx.cr6.eq) goto loc_8212CF9C;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
loc_8212CF9C:
	// addi r9,r1,655
	ctx.r9.s64 = ctx.r1.s64 + 655;
loc_8212CFA0:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r25,r25,-1
	ctx.r25.s64 = ctx.r25.s64 + -1;
	// bgt cr6,0x8212cfb4
	if (ctx.cr6.gt) goto loc_8212CFB4;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x8212cff8
	if (ctx.cr6.eq) goto loc_8212CFF8;
loc_8212CFB4:
	// extsw r10,r8
	ctx.r10.s64 = ctx.r8.s32;
	// divdu r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 ? ctx.r11.u64 / ctx.r10.u64 : 0;
	// tdllei r10,0
	if (ctx.r10.s64 == 0ll || ctx.r10.u64 < 0ull) ppc_trap(ctx, base, 0);
	// mulld r7,r7,r10
	ctx.r7.s64 = static_cast<int64_t>(ctx.r7.u64 * ctx.r10.u64);
	// subf r7,r7,r11
	ctx.r7.u64 = ctx.r11.u64 - ctx.r7.u64;
	// divdu r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 ? ctx.r11.u64 / ctx.r10.u64 : 0;
	// tdllei r10,0
	if (ctx.r10.s64 == 0ll || ctx.r10.u64 < 0ull) ppc_trap(ctx, base, 0);
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpwi cr6,r10,57
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 57, ctx.xer);
	// ble cr6,0x8212cfe8
	if (!ctx.cr6.gt) goto loc_8212CFE8;
	// lwz r7,108(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
loc_8212CFE8:
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// stb r10,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// b 0x8212cfa0
	goto loc_8212CFA0;
loc_8212CFF8:
	// addi r11,r1,655
	ctx.r11.s64 = ctx.r1.s64 + 655;
	// rlwinm. r10,r27,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r7,r9,r11
	ctx.r7.u64 = ctx.r11.u64 - ctx.r9.u64;
	// addi r28,r9,1
	ctx.r28.s64 = ctx.r9.s64 + 1;
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// beq 0x8212d038
	if (ctx.cr0.eq) goto loc_8212D038;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x8212d024
	if (ctx.cr6.eq) goto loc_8212D024;
	// lbz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,48
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 48, ctx.xer);
	// beq cr6,0x8212d038
	if (ctx.cr6.eq) goto loc_8212D038;
loc_8212D024:
	// addi r28,r28,-1
	ctx.r28.s64 = ctx.r28.s64 + -1;
	// li r11,48
	ctx.r11.s64 = 48;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stb r11,0(r28)
	REX_STORE_U8(ctx.r28.u32 + 0, ctx.r11.u8);
loc_8212D034:
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
loc_8212D038:
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8212d1f8
	if (!ctx.cr6.eq) goto loc_8212D1F8;
	// rlwinm. r11,r27,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212d088
	if (ctx.cr0.eq) goto loc_8212D088;
	// rlwinm. r11,r27,0,23,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212d05c
	if (ctx.cr0.eq) goto loc_8212D05C;
	// li r11,45
	ctx.r11.s64 = 45;
	// b 0x8212d068
	goto loc_8212D068;
loc_8212D05C:
	// clrlwi. r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212d078
	if (ctx.cr0.eq) goto loc_8212D078;
	// li r11,43
	ctx.r11.s64 = 43;
loc_8212D068:
	// li r30,1
	ctx.r30.s64 = 1;
	// stb r11,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r11.u8);
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// b 0x8212d08c
	goto loc_8212D08C;
loc_8212D078:
	// rlwinm. r11,r27,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212d088
	if (ctx.cr0.eq) goto loc_8212D088;
	// li r11,32
	ctx.r11.s64 = 32;
	// b 0x8212d068
	goto loc_8212D068;
loc_8212D088:
	// lwz r30,92(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
loc_8212D08C:
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// rlwinm. r10,r27,0,28,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xC;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r11,r7,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r7.u64;
	// subf r29,r30,r11
	ctx.r29.u64 = ctx.r11.u64 - ctx.r30.u64;
	// bne 0x8212d0d4
	if (!ctx.cr0.eq) goto loc_8212D0D4;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8212d0d4
	if (!ctx.cr6.gt) goto loc_8212D0D4;
loc_8212D0AC:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// bl 0x8212c5c0
	ctx.lr = 0x8212D0C0;
	sub_8212C5C0(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8212d0d4
	if (ctx.cr6.eq) goto loc_8212D0D4;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt cr6,0x8212d0ac
	if (ctx.cr6.gt) goto loc_8212D0AC;
loc_8212D0D4:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8212c658
	ctx.lr = 0x8212D0E8;
	sub_8212C658(ctx, base);
	// rlwinm. r11,r27,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212d12c
	if (ctx.cr0.eq) goto loc_8212D12C;
	// rlwinm. r11,r27,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212d12c
	if (!ctx.cr0.eq) goto loc_8212D12C;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8212d12c
	if (!ctx.cr6.gt) goto loc_8212D12C;
loc_8212D104:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r3,48
	ctx.r3.s64 = 48;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// bl 0x8212c5c0
	ctx.lr = 0x8212D118;
	sub_8212C5C0(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8212d12c
	if (ctx.cr6.eq) goto loc_8212D12C;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt cr6,0x8212d104
	if (ctx.cr6.gt) goto loc_8212D104;
loc_8212D12C:
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// beq cr6,0x8212d1a0
	if (ctx.cr6.eq) goto loc_8212D1A0;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x8212d1a0
	if (!ctx.cr6.gt) goto loc_8212D1A0;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
loc_8212D148:
	// li r5,6
	ctx.r5.s64 = 6;
	// lhz r6,0(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// bl 0x82132b00
	ctx.lr = 0x8212D164;
	sub_82132B00(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8212d194
	if (!ctx.cr0.eq) goto loc_8212D194;
	// lwz r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x8212d194
	if (ctx.cr6.eq) goto loc_8212D194;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// bl 0x8212c658
	ctx.lr = 0x8212D188;
	sub_8212C658(ctx, base);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne cr6,0x8212d148
	if (!ctx.cr6.eq) goto loc_8212D148;
	// b 0x8212d1b0
	goto loc_8212D1B0;
loc_8212D194:
	// li r24,-1
	ctx.r24.s64 = -1;
	// stw r24,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// b 0x8212d1b4
	goto loc_8212D1B4;
loc_8212D1A0:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8212c658
	ctx.lr = 0x8212D1B0;
	sub_8212C658(ctx, base);
loc_8212D1B0:
	// lwz r24,80(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8212D1B4:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// blt cr6,0x8212d1f8
	if (ctx.cr6.lt) goto loc_8212D1F8;
	// rlwinm. r11,r27,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212d1f8
	if (ctx.cr0.eq) goto loc_8212D1F8;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8212d1f8
	if (!ctx.cr6.gt) goto loc_8212D1F8;
loc_8212D1D0:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// bl 0x8212c5c0
	ctx.lr = 0x8212D1E4;
	sub_8212C5C0(ctx, base);
	// lwz r24,80(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r24,-1
	ctx.cr6.compare<int32_t>(ctx.r24.s32, -1, ctx.xer);
	// beq cr6,0x8212d1f8
	if (ctx.cr6.eq) goto loc_8212D1F8;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt cr6,0x8212d1d0
	if (ctx.cr6.gt) goto loc_8212D1D0;
loc_8212D1F8:
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8212d20c
	if (ctx.cr6.eq) goto loc_8212D20C;
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// bl 0x82129880
	ctx.lr = 0x8212D208;
	sub_82129880(ctx, base);
	// li r15,0
	ctx.r15.s64 = 0;
loc_8212D20C:
	// lbz r29,0(r18)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r18.u32 + 0);
	// extsb. r8,r29
	ctx.r8.s64 = ctx.r29.s8;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8212d220
	if (ctx.cr0.eq) goto loc_8212D220;
	// lwz r7,84(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x8212c898
	goto loc_8212C898;
loc_8212D220:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// b 0x8212d25c
	goto loc_8212D25C;
loc_8212D228:
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// li r4,512
	ctx.r4.s64 = 512;
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// bl 0x821329a8
	ctx.lr = 0x8212D23C;
	sub_821329A8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,-1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -1, ctx.xer);
	// bne cr6,0x8212d250
	if (!ctx.cr6.eq) goto loc_8212D250;
	// li r31,511
	ctx.r31.s64 = 511;
	// stb r27,1167(r1)
	REX_STORE_U8(ctx.r1.u32 + 1167, ctx.r27.u8);
loc_8212D250:
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// bl 0x820b6cd0
	ctx.lr = 0x8212D258;
	sub_820B6CD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8212D25C:
	// addi r1,r1,1328
	ctx.r1.s64 = ctx.r1.s64 + 1328;
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
}
