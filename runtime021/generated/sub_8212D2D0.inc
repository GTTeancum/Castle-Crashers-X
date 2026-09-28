DEFINE_REX_FUNC(sub_8212D2D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e0
	ctx.lr = 0x8212D2D8;
	__savegprlr_14(ctx, base);
	// stwu r1,-2336(r1)
	ea = -2336 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// stw r28,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// mr r15,r4
	ctx.r15.u64 = ctx.r4.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// stw r31,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// mr r25,r28
	ctx.r25.u64 = ctx.r28.u64;
	// mr r14,r28
	ctx.r14.u64 = ctx.r28.u64;
	// mr r23,r28
	ctx.r23.u64 = ctx.r28.u64;
	// mr r17,r28
	ctx.r17.u64 = ctx.r28.u64;
	// mr r19,r28
	ctx.r19.u64 = ctx.r28.u64;
	// bne cr6,0x8212d340
	if (!ctx.cr6.eq) goto loc_8212D340;
loc_8212D314:
	// bl 0x821294e0
	ctx.lr = 0x8212D318;
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
	ctx.lr = 0x8212D338;
	sub_8212C298(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8212de14
	goto loc_8212DE14;
loc_8212D340:
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8212d314
	if (ctx.cr6.eq) goto loc_8212D314;
	// bl 0x8212bf08
	ctx.lr = 0x8212D34C;
	sub_8212BF08(ctx, base);
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// cmplw cr6,r20,r11
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8212dde0
	if (ctx.cr6.eq) goto loc_8212DDE0;
	// bl 0x8212bf08
	ctx.lr = 0x8212D35C;
	sub_8212BF08(ctx, base);
	// addi r11,r3,64
	ctx.r11.s64 = ctx.r3.s64 + 64;
	// cmplw cr6,r20,r11
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8212dde0
	if (ctx.cr6.eq) goto loc_8212DDE0;
	// lhz r29,0(r15)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r15.u32 + 0);
	// mr r22,r28
	ctx.r22.u64 = ctx.r28.u64;
	// mr r26,r28
	ctx.r26.u64 = ctx.r28.u64;
	// stw r28,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// mr. r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r22,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r22.u32);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// beq 0x8212ddd8
	if (ctx.cr0.eq) goto loc_8212DDD8;
	// lis r10,-32234
	ctx.r10.s64 = -2112487424;
	// lwz r16,100(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r27,100(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// addi r18,r10,-32536
	ctx.r18.s64 = ctx.r10.s64 + -32536;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r10,r9,-17904
	ctx.r10.s64 = ctx.r9.s64 + -17904;
	// addi r21,r11,32376
	ctx.r21.s64 = ctx.r11.s64 + 32376;
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
loc_8212D3AC:
	// addi r15,r15,2
	ctx.r15.s64 = ctx.r15.s64 + 2;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// blt cr6,0x8212ddd8
	if (ctx.cr6.lt) goto loc_8212DDD8;
	// cmplwi cr6,r8,32
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 32, ctx.xer);
	// blt cr6,0x8212d3d8
	if (ctx.cr6.lt) goto loc_8212D3D8;
	// cmplwi cr6,r8,120
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 120, ctx.xer);
	// bgt cr6,0x8212d3d8
	if (ctx.cr6.gt) goto loc_8212D3D8;
	// add r11,r8,r10
	ctx.r11.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lbz r11,-32(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + -32);
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// b 0x8212d3dc
	goto loc_8212D3DC;
loc_8212D3D8:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_8212D3DC:
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lbzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// srawi r11,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 4;
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x8212ddb8
	if (ctx.cr6.gt) goto loc_8212DDB8;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-17568
	ctx.r12.s64 = ctx.r12.s64 + -17568;
	// rlwinm r0,r11,1,0,30
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U16(ctx.r12.u32 + ctx.r0.u32);
	// lis r12,-32237
	ctx.r12.s64 = -2112684032;
	// addi r12,r12,-11228
	ctx.r12.s64 = ctx.r12.s64 + -11228;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8212D5D8;
	case 1:
		goto loc_8212D424;
	case 2:
		goto loc_8212D444;
	case 3:
		goto loc_8212D494;
	case 4:
		goto loc_8212D4D0;
	case 5:
		goto loc_8212D4D8;
	case 6:
		goto loc_8212D510;
	case 7:
		goto loc_8212D5F4;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8212D424:
	// mr r16,r28
	ctx.r16.u64 = ctx.r28.u64;
	// stw r28,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// mr r14,r28
	ctx.r14.u64 = ctx.r28.u64;
	// mr r17,r28
	ctx.r17.u64 = ctx.r28.u64;
	// mr r25,r28
	ctx.r25.u64 = ctx.r28.u64;
	// li r23,-1
	ctx.r23.s64 = -1;
	// mr r19,r28
	ctx.r19.u64 = ctx.r28.u64;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D444:
	// cmpwi cr6,r8,32
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 32, ctx.xer);
	// beq cr6,0x8212d48c
	if (ctx.cr6.eq) goto loc_8212D48C;
	// cmpwi cr6,r8,35
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 35, ctx.xer);
	// beq cr6,0x8212d484
	if (ctx.cr6.eq) goto loc_8212D484;
	// cmpwi cr6,r8,43
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 43, ctx.xer);
	// beq cr6,0x8212d47c
	if (ctx.cr6.eq) goto loc_8212D47C;
	// cmpwi cr6,r8,45
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 45, ctx.xer);
	// beq cr6,0x8212d474
	if (ctx.cr6.eq) goto loc_8212D474;
	// cmpwi cr6,r8,48
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 48, ctx.xer);
	// bne cr6,0x8212ddb8
	if (!ctx.cr6.eq) goto loc_8212DDB8;
	// ori r25,r25,8
	ctx.r25.u64 = ctx.r25.u64 | 8;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D474:
	// ori r25,r25,4
	ctx.r25.u64 = ctx.r25.u64 | 4;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D47C:
	// ori r25,r25,1
	ctx.r25.u64 = ctx.r25.u64 | 1;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D484:
	// ori r25,r25,128
	ctx.r25.u64 = ctx.r25.u64 | 128;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D48C:
	// ori r25,r25,2
	ctx.r25.u64 = ctx.r25.u64 | 2;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D494:
	// cmplwi cr6,r8,42
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 42, ctx.xer);
	// bne cr6,0x8212d4c0
	if (!ctx.cr6.eq) goto loc_8212D4C0;
	// addi r11,r24,7
	ctx.r11.s64 = ctx.r24.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r24,r11,8
	ctx.r24.s64 = ctx.r11.s64 + 8;
	// lwz r14,4(r11)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r14,0
	ctx.cr6.compare<int32_t>(ctx.r14.s32, 0, ctx.xer);
	// bge cr6,0x8212ddb8
	if (!ctx.cr6.lt) goto loc_8212DDB8;
	// ori r25,r25,4
	ctx.r25.u64 = ctx.r25.u64 | 4;
	// neg r14,r14
	ctx.r14.s64 = static_cast<int64_t>(-ctx.r14.u64);
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D4C0:
	// mulli r11,r14,10
	ctx.r11.s64 = static_cast<int64_t>(ctx.r14.u64 * static_cast<uint64_t>(10));
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r14,r11,-48
	ctx.r14.s64 = ctx.r11.s64 + -48;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D4D0:
	// mr r23,r28
	ctx.r23.u64 = ctx.r28.u64;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D4D8:
	// cmplwi cr6,r8,42
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 42, ctx.xer);
	// bne cr6,0x8212d500
	if (!ctx.cr6.eq) goto loc_8212D500;
	// addi r11,r24,7
	ctx.r11.s64 = ctx.r24.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r24,r11,8
	ctx.r24.s64 = ctx.r11.s64 + 8;
	// lwz r23,4(r11)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// bge cr6,0x8212ddb8
	if (!ctx.cr6.lt) goto loc_8212DDB8;
	// li r23,-1
	ctx.r23.s64 = -1;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D500:
	// mulli r11,r23,10
	ctx.r11.s64 = static_cast<int64_t>(ctx.r23.u64 * static_cast<uint64_t>(10));
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r23,r11,-48
	ctx.r23.s64 = ctx.r11.s64 + -48;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D510:
	// cmpwi cr6,r8,73
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 73, ctx.xer);
	// beq cr6,0x8212d560
	if (ctx.cr6.eq) goto loc_8212D560;
	// cmpwi cr6,r8,104
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 104, ctx.xer);
	// beq cr6,0x8212d558
	if (ctx.cr6.eq) goto loc_8212D558;
	// cmpwi cr6,r8,108
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 108, ctx.xer);
	// beq cr6,0x8212d538
	if (ctx.cr6.eq) goto loc_8212D538;
	// cmpwi cr6,r8,119
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 119, ctx.xer);
	// bne cr6,0x8212ddb8
	if (!ctx.cr6.eq) goto loc_8212DDB8;
	// ori r25,r25,2048
	ctx.r25.u64 = ctx.r25.u64 | 2048;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D538:
	// lhz r11,0(r15)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r15.u32 + 0);
	// cmplwi cr6,r11,108
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 108, ctx.xer);
	// bne cr6,0x8212d550
	if (!ctx.cr6.eq) goto loc_8212D550;
	// addi r15,r15,2
	ctx.r15.s64 = ctx.r15.s64 + 2;
	// ori r25,r25,4096
	ctx.r25.u64 = ctx.r25.u64 | 4096;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D550:
	// ori r25,r25,16
	ctx.r25.u64 = ctx.r25.u64 | 16;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D558:
	// ori r25,r25,32
	ctx.r25.u64 = ctx.r25.u64 | 32;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D560:
	// lhz r11,0(r15)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r15.u32 + 0);
	// cmplwi cr6,r11,54
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 54, ctx.xer);
	// bne cr6,0x8212d584
	if (!ctx.cr6.eq) goto loc_8212D584;
	// lhz r10,2(r15)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r15.u32 + 2);
	// cmplwi cr6,r10,52
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 52, ctx.xer);
	// bne cr6,0x8212d584
	if (!ctx.cr6.eq) goto loc_8212D584;
	// addi r15,r15,4
	ctx.r15.s64 = ctx.r15.s64 + 4;
	// ori r25,r25,32768
	ctx.r25.u64 = ctx.r25.u64 | 32768;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D584:
	// cmplwi cr6,r11,51
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 51, ctx.xer);
	// bne cr6,0x8212d5a4
	if (!ctx.cr6.eq) goto loc_8212D5A4;
	// lhz r10,2(r15)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r15.u32 + 2);
	// cmplwi cr6,r10,50
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 50, ctx.xer);
	// bne cr6,0x8212d5a4
	if (!ctx.cr6.eq) goto loc_8212D5A4;
	// addi r15,r15,4
	ctx.r15.s64 = ctx.r15.s64 + 4;
	// rlwinm r25,r25,0,17,15
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0xFFFFFFFFFFFF7FFF;
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D5A4:
	// cmplwi cr6,r11,100
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 100, ctx.xer);
	// beq cr6,0x8212ddb8
	if (ctx.cr6.eq) goto loc_8212DDB8;
	// cmplwi cr6,r11,105
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 105, ctx.xer);
	// beq cr6,0x8212ddb8
	if (ctx.cr6.eq) goto loc_8212DDB8;
	// cmplwi cr6,r11,111
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 111, ctx.xer);
	// beq cr6,0x8212ddb8
	if (ctx.cr6.eq) goto loc_8212DDB8;
	// cmplwi cr6,r11,117
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 117, ctx.xer);
	// beq cr6,0x8212ddb8
	if (ctx.cr6.eq) goto loc_8212DDB8;
	// cmplwi cr6,r11,120
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 120, ctx.xer);
	// beq cr6,0x8212ddb8
	if (ctx.cr6.eq) goto loc_8212DDB8;
	// cmplwi cr6,r11,88
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 88, ctx.xer);
	// beq cr6,0x8212ddb8
	if (ctx.cr6.eq) goto loc_8212DDB8;
	// stw r28,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r28.u32);
loc_8212D5D8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r19,1
	ctx.r19.s64 = 1;
	// bl 0x8212d268
	ctx.lr = 0x8212D5EC;
	sub_8212D268(ctx, base);
	// lwz r22,80(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8212ddb8
	goto loc_8212DDB8;
loc_8212D5F4:
	// addi r11,r8,-65
	ctx.r11.s64 = ctx.r8.s64 + -65;
	// cmplwi cr6,r11,55
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 55, ctx.xer);
	// bgt cr6,0x8212db18
	if (ctx.cr6.gt) goto loc_8212DB18;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-17680
	ctx.r12.s64 = ctx.r12.s64 + -17680;
	// rlwinm r0,r11,1,0,30
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U16(ctx.r12.u32 + ctx.r0.u32);
	// lis r12,-32237
	ctx.r12.s64 = -2112684032;
	// addi r12,r12,-10712
	ctx.r12.s64 = ctx.r12.s64 + -10712;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8212D834;
	case 1:
		goto loc_8212DB18;
	case 2:
		goto loc_8212D628;
	case 3:
		goto loc_8212DB18;
	case 4:
		goto loc_8212D834;
	case 5:
		goto loc_8212DB18;
	case 6:
		goto loc_8212D834;
	case 7:
		goto loc_8212DB18;
	case 8:
		goto loc_8212DB18;
	case 9:
		goto loc_8212DB18;
	case 10:
		goto loc_8212DB18;
	case 11:
		goto loc_8212DB18;
	case 12:
		goto loc_8212DB18;
	case 13:
		goto loc_8212DB18;
	case 14:
		goto loc_8212DB18;
	case 15:
		goto loc_8212DB18;
	case 16:
		goto loc_8212DB18;
	case 17:
		goto loc_8212DB18;
	case 18:
		goto loc_8212D720;
	case 19:
		goto loc_8212DB18;
	case 20:
		goto loc_8212DB18;
	case 21:
		goto loc_8212DB18;
	case 22:
		goto loc_8212DB18;
	case 23:
		goto loc_8212D978;
	case 24:
		goto loc_8212DB18;
	case 25:
		goto loc_8212D6A0;
	case 26:
		goto loc_8212DB18;
	case 27:
		goto loc_8212DB18;
	case 28:
		goto loc_8212DB18;
	case 29:
		goto loc_8212DB18;
	case 30:
		goto loc_8212DB18;
	case 31:
		goto loc_8212DB18;
	case 32:
		goto loc_8212D840;
	case 33:
		goto loc_8212DB18;
	case 34:
		goto loc_8212D638;
	case 35:
		goto loc_8212D968;
	case 36:
		goto loc_8212D840;
	case 37:
		goto loc_8212D840;
	case 38:
		goto loc_8212D840;
	case 39:
		goto loc_8212DB18;
	case 40:
		goto loc_8212D968;
	case 41:
		goto loc_8212DB18;
	case 42:
		goto loc_8212DB18;
	case 43:
		goto loc_8212DB18;
	case 44:
		goto loc_8212DB18;
	case 45:
		goto loc_8212D7F8;
	case 46:
		goto loc_8212D9AC;
	case 47:
		goto loc_8212D974;
	case 48:
		goto loc_8212DB18;
	case 49:
		goto loc_8212DB18;
	case 50:
		goto loc_8212D730;
	case 51:
		goto loc_8212DB18;
	case 52:
		goto loc_8212D96C;
	case 53:
		goto loc_8212DB18;
	case 54:
		goto loc_8212DB18;
	case 55:
		goto loc_8212D980;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8212D628:
	// andi. r11,r25,2096
	ctx.r11.u64 = ctx.r25.u64 & 2096;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212d638
	if (!ctx.cr0.eq) goto loc_8212D638;
	// ori r25,r25,32
	ctx.r25.u64 = ctx.r25.u64 | 32;
loc_8212D638:
	// addi r11,r24,7
	ctx.r11.s64 = ctx.r24.s64 + 7;
	// li r26,1
	ctx.r26.s64 = 1;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// rlwinm. r10,r25,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r24,r11,8
	ctx.r24.s64 = ctx.r11.s64 + 8;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r19,r26
	ctx.r19.u64 = ctx.r26.u64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r11,84(r1)
	REX_STORE_U16(ctx.r1.u32 + 84, ctx.r11.u16);
	// beq 0x8212d694
	if (ctx.cr0.eq) goto loc_8212D694;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stb r28,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r28.u8);
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// stb r10,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r10.u8);
	// addi r4,r1,86
	ctx.r4.s64 = ctx.r1.s64 + 86;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r5,172(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// bl 0x82132f50
	ctx.lr = 0x8212D684;
	sub_82132F50(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8212d698
	if (!ctx.cr0.lt) goto loc_8212D698;
	// stw r26,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r26.u32);
	// b 0x8212d698
	goto loc_8212D698;
loc_8212D694:
	// sth r11,128(r1)
	REX_STORE_U16(ctx.r1.u32 + 128, ctx.r11.u16);
loc_8212D698:
	// addi r27,r1,128
	ctx.r27.s64 = ctx.r1.s64 + 128;
	// b 0x8212db18
	goto loc_8212DB18;
loc_8212D6A0:
	// addi r11,r24,7
	ctx.r11.s64 = ctx.r24.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r24,r11,8
	ctx.r24.s64 = ctx.r11.s64 + 8;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8212d6f0
	if (ctx.cr6.eq) goto loc_8212D6F0;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8212d6f0
	if (ctx.cr6.eq) goto loc_8212D6F0;
	// rlwinm. r9,r25,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// mr r27,r10
	ctx.r27.u64 = ctx.r10.u64;
	// beq 0x8212d6e4
	if (ctx.cr0.eq) goto loc_8212D6E4;
	// lha r11,0(r11)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r11.u32 + 0));
	// li r19,1
	ctx.r19.s64 = 1;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addze r26,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r26.s64 = temp.s64;
	// b 0x8212db18
	goto loc_8212DB18;
loc_8212D6E4:
	// lha r26,0(r11)
	ctx.r26.s64 = int16_t(REX_LOAD_U16(ctx.r11.u32 + 0));
	// mr r19,r28
	ctx.r19.u64 = ctx.r28.u64;
	// b 0x8212db18
	goto loc_8212DB18;
loc_8212D6F0:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r27,-17916(r10)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r10.u32 + -17916);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
loc_8212D700:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8212d700
	if (!ctx.cr6.eq) goto loc_8212D700;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
loc_8212D714:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r26,r11,0
	ctx.r26.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// b 0x8212db18
	goto loc_8212DB18;
loc_8212D720:
	// andi. r11,r25,2096
	ctx.r11.u64 = ctx.r25.u64 & 2096;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212d730
	if (!ctx.cr0.eq) goto loc_8212D730;
	// ori r25,r25,32
	ctx.r25.u64 = ctx.r25.u64 | 32;
loc_8212D730:
	// cmpwi cr6,r23,-1
	ctx.cr6.compare<int32_t>(ctx.r23.s32, -1, ctx.xer);
	// bne cr6,0x8212d744
	if (!ctx.cr6.eq) goto loc_8212D744;
	// lis r30,32767
	ctx.r30.s64 = 2147418112;
	// ori r30,r30,65535
	ctx.r30.u64 = ctx.r30.u64 | 65535;
	// b 0x8212d748
	goto loc_8212D748;
loc_8212D744:
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
loc_8212D748:
	// addi r11,r24,7
	ctx.r11.s64 = ctx.r24.s64 + 7;
	// rlwinm. r10,r25,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r24,r11,8
	ctx.r24.s64 = ctx.r11.s64 + 8;
	// lwz r27,4(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq 0x8212d7b8
	if (ctx.cr0.eq) goto loc_8212D7B8;
	// bne cr6,0x8212d770
	if (!ctx.cr6.eq) goto loc_8212D770;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r27,-17916(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + -17916);
loc_8212D770:
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// mr r26,r28
	ctx.r26.u64 = ctx.r28.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// ble cr6,0x8212db18
	if (!ctx.cr6.gt) goto loc_8212DB18;
loc_8212D780:
	// lbz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8212db18
	if (ctx.cr0.eq) goto loc_8212DB18;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// bl 0x82132b08
	ctx.lr = 0x8212D798;
	sub_82132B08(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8212d7a4
	if (ctx.cr0.eq) goto loc_8212D7A4;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
loc_8212D7A4:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpw cr6,r26,r30
	ctx.cr6.compare<int32_t>(ctx.r26.s32, ctx.r30.s32, ctx.xer);
	// blt cr6,0x8212d780
	if (ctx.cr6.lt) goto loc_8212D780;
	// b 0x8212db18
	goto loc_8212DB18;
loc_8212D7B8:
	// bne cr6,0x8212d7c4
	if (!ctx.cr6.eq) goto loc_8212D7C4;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r27,-17912(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + -17912);
loc_8212D7C4:
	// li r19,1
	ctx.r19.s64 = 1;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// b 0x8212d7e4
	goto loc_8212D7E4;
loc_8212D7D0:
	// lhz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r30,r30,-1
	ctx.r30.s64 = ctx.r30.s64 + -1;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8212d7ec
	if (ctx.cr0.eq) goto loc_8212D7EC;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
loc_8212D7E4:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x8212d7d0
	if (!ctx.cr6.eq) goto loc_8212D7D0;
loc_8212D7EC:
	// subf r11,r27,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r27.u64;
	// srawi r26,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r26.s64 = ctx.r11.s32 >> 1;
	// b 0x8212db18
	goto loc_8212DB18;
loc_8212D7F8:
	// addi r11,r24,7
	ctx.r11.s64 = ctx.r24.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r24,r11,8
	ctx.r24.s64 = ctx.r11.s64 + 8;
	// lwz r31,4(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x821329b8
	ctx.lr = 0x8212D80C;
	sub_821329B8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8212d314
	if (ctx.cr0.eq) goto loc_8212D314;
	// rlwinm. r11,r25,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212d824
	if (ctx.cr0.eq) goto loc_8212D824;
	// sth r22,0(r31)
	REX_STORE_U16(ctx.r31.u32 + 0, ctx.r22.u16);
	// b 0x8212d828
	goto loc_8212D828;
loc_8212D824:
	// stw r22,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r22.u32);
loc_8212D828:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// b 0x8212dd9c
	goto loc_8212DD9C;
loc_8212D834:
	// addi r11,r8,32
	ctx.r11.s64 = ctx.r8.s64 + 32;
	// li r16,1
	ctx.r16.s64 = 1;
	// clrlwi r29,r11,16
	ctx.r29.u64 = ctx.r11.u32 & 0xFFFF;
loc_8212D840:
	// ori r25,r25,64
	ctx.r25.u64 = ctx.r25.u64 | 64;
	// addi r27,r1,128
	ctx.r27.s64 = ctx.r1.s64 + 128;
	// li r30,512
	ctx.r30.s64 = 512;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// bge cr6,0x8212d85c
	if (!ctx.cr6.lt) goto loc_8212D85C;
	// li r23,6
	ctx.r23.s64 = 6;
	// b 0x8212d8b0
	goto loc_8212D8B0;
loc_8212D85C:
	// bne cr6,0x8212d874
	if (!ctx.cr6.eq) goto loc_8212D874;
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// cmplwi cr6,r11,103
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 103, ctx.xer);
	// bne cr6,0x8212d8b0
	if (!ctx.cr6.eq) goto loc_8212D8B0;
	// li r23,1
	ctx.r23.s64 = 1;
	// b 0x8212d8b0
	goto loc_8212D8B0;
loc_8212D874:
	// cmpwi cr6,r23,512
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 512, ctx.xer);
	// ble cr6,0x8212d880
	if (!ctx.cr6.gt) goto loc_8212D880;
	// li r23,512
	ctx.r23.s64 = 512;
loc_8212D880:
	// cmpwi cr6,r23,163
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 163, ctx.xer);
	// ble cr6,0x8212d8b0
	if (!ctx.cr6.gt) goto loc_8212D8B0;
	// addi r31,r23,349
	ctx.r31.s64 = ctx.r23.s64 + 349;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82128f70
	ctx.lr = 0x8212D894;
	sub_82128F70(ctx, base);
	// stw r3,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8212d8ac
	if (ctx.cr0.eq) goto loc_8212D8AC;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// b 0x8212d8b0
	goto loc_8212D8B0;
loc_8212D8AC:
	// li r23,163
	ctx.r23.s64 = 163;
loc_8212D8B0:
	// addi r11,r24,7
	ctx.r11.s64 = ctx.r24.s64 + 7;
	// lwz r10,24(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 24);
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// mr r8,r16
	ctx.r8.u64 = ctx.r16.u64;
	// addi r24,r11,8
	ctx.r24.s64 = ctx.r11.s64 + 8;
	// mr r7,r23
	ctx.r7.u64 = ctx.r23.u64;
	// extsb r6,r29
	ctx.r6.s64 = ctx.r29.s8;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8212D8EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm. r31,r25,0,24,24
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8212d910
	if (ctx.cr0.eq) goto loc_8212D910;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// bne cr6,0x8212d910
	if (!ctx.cr6.eq) goto loc_8212D910;
	// lwz r11,36(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 36);
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8212D910;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8212D910:
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// cmplwi cr6,r11,103
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 103, ctx.xer);
	// bne cr6,0x8212d938
	if (!ctx.cr6.eq) goto loc_8212D938;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne cr6,0x8212d938
	if (!ctx.cr6.eq) goto loc_8212D938;
	// lwz r11,32(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 32);
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8212D938;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8212D938:
	// lbz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 0);
	// cmplwi cr6,r11,45
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 45, ctx.xer);
	// bne cr6,0x8212d94c
	if (!ctx.cr6.eq) goto loc_8212D94C;
	// ori r25,r25,256
	ctx.r25.u64 = ctx.r25.u64 | 256;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_8212D94C:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8212D950:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8212d950
	if (!ctx.cr6.eq) goto loc_8212D950;
	// subf r11,r27,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r27.u64;
	// b 0x8212d714
	goto loc_8212D714;
loc_8212D968:
	// ori r25,r25,64
	ctx.r25.u64 = ctx.r25.u64 | 64;
loc_8212D96C:
	// li r8,10
	ctx.r8.s64 = 10;
	// b 0x8212d9bc
	goto loc_8212D9BC;
loc_8212D974:
	// li r23,8
	ctx.r23.s64 = 8;
loc_8212D978:
	// li r31,7
	ctx.r31.s64 = 7;
	// b 0x8212d984
	goto loc_8212D984;
loc_8212D980:
	// li r31,39
	ctx.r31.s64 = 39;
loc_8212D984:
	// stw r31,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// rlwinm. r11,r25,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r8,16
	ctx.r8.s64 = 16;
	// beq 0x8212d9bc
	if (ctx.cr0.eq) goto loc_8212D9BC;
	// addi r11,r31,81
	ctx.r11.s64 = ctx.r31.s64 + 81;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r17,2
	ctx.r17.s64 = 2;
	// sth r11,90(r1)
	REX_STORE_U16(ctx.r1.u32 + 90, ctx.r11.u16);
	// sth r10,88(r1)
	REX_STORE_U16(ctx.r1.u32 + 88, ctx.r10.u16);
	// b 0x8212d9bc
	goto loc_8212D9BC;
loc_8212D9AC:
	// rlwinm. r11,r25,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r8,8
	ctx.r8.s64 = 8;
	// beq 0x8212d9bc
	if (ctx.cr0.eq) goto loc_8212D9BC;
	// ori r25,r25,512
	ctx.r25.u64 = ctx.r25.u64 | 512;
loc_8212D9BC:
	// rlwinm. r11,r25,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212d9cc
	if (!ctx.cr0.eq) goto loc_8212D9CC;
	// rlwinm. r11,r25,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212d9e0
	if (ctx.cr0.eq) goto loc_8212D9E0;
loc_8212D9CC:
	// addi r11,r24,7
	ctx.r11.s64 = ctx.r24.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r24,r11,8
	ctx.r24.s64 = ctx.r11.s64 + 8;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// b 0x8212da30
	goto loc_8212DA30;
loc_8212D9E0:
	// rlwinm. r11,r25,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212da10
	if (ctx.cr0.eq) goto loc_8212DA10;
	// rlwinm. r11,r25,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r24,7
	ctx.r11.s64 = ctx.r24.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r24,r11,8
	ctx.r24.s64 = ctx.r11.s64 + 8;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// beq 0x8212da08
	if (ctx.cr0.eq) goto loc_8212DA08;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// b 0x8212da30
	goto loc_8212DA30;
loc_8212DA08:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x8212da30
	goto loc_8212DA30;
loc_8212DA10:
	// rlwinm. r11,r25,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r24,7
	ctx.r11.s64 = ctx.r24.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r24,r11,8
	ctx.r24.s64 = ctx.r11.s64 + 8;
	// beq 0x8212da2c
	if (ctx.cr0.eq) goto loc_8212DA2C;
	// lwa r11,4(r11)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r11.u32 + 4));
	// b 0x8212da30
	goto loc_8212DA30;
loc_8212DA2C:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_8212DA30:
	// rlwinm. r10,r25,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8212da48
	if (ctx.cr0.eq) goto loc_8212DA48;
	// cmpdi cr6,r11,0
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 0, ctx.xer);
	// bge cr6,0x8212da48
	if (!ctx.cr6.lt) goto loc_8212DA48;
	// neg r11,r11
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// ori r25,r25,256
	ctx.r25.u64 = ctx.r25.u64 | 256;
loc_8212DA48:
	// rlwinm. r10,r25,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8212da5c
	if (!ctx.cr0.eq) goto loc_8212DA5C;
	// rlwinm. r10,r25,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8212da5c
	if (!ctx.cr0.eq) goto loc_8212DA5C;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
loc_8212DA5C:
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// bge cr6,0x8212da6c
	if (!ctx.cr6.lt) goto loc_8212DA6C;
	// li r23,1
	ctx.r23.s64 = 1;
	// b 0x8212da7c
	goto loc_8212DA7C;
loc_8212DA6C:
	// rlwinm r25,r25,0,29,27
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// cmpwi cr6,r23,512
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 512, ctx.xer);
	// ble cr6,0x8212da7c
	if (!ctx.cr6.gt) goto loc_8212DA7C;
	// li r23,512
	ctx.r23.s64 = 512;
loc_8212DA7C:
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// bne cr6,0x8212da88
	if (!ctx.cr6.eq) goto loc_8212DA88;
	// mr r17,r28
	ctx.r17.u64 = ctx.r28.u64;
loc_8212DA88:
	// addi r9,r1,639
	ctx.r9.s64 = ctx.r1.s64 + 639;
loc_8212DA8C:
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// addi r23,r23,-1
	ctx.r23.s64 = ctx.r23.s64 + -1;
	// bgt cr6,0x8212daa0
	if (ctx.cr6.gt) goto loc_8212DAA0;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x8212dae0
	if (ctx.cr6.eq) goto loc_8212DAE0;
loc_8212DAA0:
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
	// ble cr6,0x8212dad0
	if (!ctx.cr6.gt) goto loc_8212DAD0;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
loc_8212DAD0:
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// stb r10,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// b 0x8212da8c
	goto loc_8212DA8C;
loc_8212DAE0:
	// addi r11,r1,639
	ctx.r11.s64 = ctx.r1.s64 + 639;
	// rlwinm. r10,r25,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r26,r9,r11
	ctx.r26.u64 = ctx.r11.u64 - ctx.r9.u64;
	// addi r27,r9,1
	ctx.r27.s64 = ctx.r9.s64 + 1;
	// beq 0x8212db18
	if (ctx.cr0.eq) goto loc_8212DB18;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x8212db08
	if (ctx.cr6.eq) goto loc_8212DB08;
	// lbz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 0);
	// cmplwi cr6,r11,48
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 48, ctx.xer);
	// beq cr6,0x8212db18
	if (ctx.cr6.eq) goto loc_8212DB18;
loc_8212DB08:
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// li r11,48
	ctx.r11.s64 = 48;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// stb r11,0(r27)
	REX_STORE_U8(ctx.r27.u32 + 0, ctx.r11.u8);
loc_8212DB18:
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8212dd9c
	if (!ctx.cr6.eq) goto loc_8212DD9C;
	// rlwinm. r11,r25,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212db60
	if (ctx.cr0.eq) goto loc_8212DB60;
	// rlwinm. r11,r25,0,23,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212db3c
	if (ctx.cr0.eq) goto loc_8212DB3C;
	// li r11,45
	ctx.r11.s64 = 45;
	// b 0x8212db58
	goto loc_8212DB58;
loc_8212DB3C:
	// clrlwi. r11,r25,31
	ctx.r11.u64 = ctx.r25.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212db4c
	if (ctx.cr0.eq) goto loc_8212DB4C;
	// li r11,43
	ctx.r11.s64 = 43;
	// b 0x8212db58
	goto loc_8212DB58;
loc_8212DB4C:
	// rlwinm. r11,r25,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212db60
	if (ctx.cr0.eq) goto loc_8212DB60;
	// li r11,32
	ctx.r11.s64 = 32;
loc_8212DB58:
	// li r17,1
	ctx.r17.s64 = 1;
	// sth r11,88(r1)
	REX_STORE_U16(ctx.r1.u32 + 88, ctx.r11.u16);
loc_8212DB60:
	// subf r11,r26,r14
	ctx.r11.u64 = ctx.r14.u64 - ctx.r26.u64;
	// rlwinm. r10,r25,0,28,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0xC;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r28,r17,r11
	ctx.r28.u64 = ctx.r11.u64 - ctx.r17.u64;
	// bne 0x8212dba4
	if (!ctx.cr0.eq) goto loc_8212DBA4;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// ble cr6,0x8212dba4
	if (!ctx.cr6.gt) goto loc_8212DBA4;
loc_8212DB7C:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// bl 0x8212d268
	ctx.lr = 0x8212DB90;
	sub_8212D268(ctx, base);
	// lwz r22,80(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// beq cr6,0x8212dba4
	if (ctx.cr6.eq) goto loc_8212DBA4;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt cr6,0x8212db7c
	if (ctx.cr6.gt) goto loc_8212DB7C;
loc_8212DBA4:
	// lwz r11,12(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 12);
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// addi r31,r1,88
	ctx.r31.s64 = ctx.r1.s64 + 88;
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212dbd0
	if (ctx.cr0.eq) goto loc_8212DBD0;
	// lwz r11,8(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8212dbd0
	if (!ctx.cr6.eq) goto loc_8212DBD0;
	// add r22,r22,r17
	ctx.r22.u64 = ctx.r22.u64 + ctx.r17.u64;
	// stw r22,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r22.u32);
	// b 0x8212dc28
	goto loc_8212DC28;
loc_8212DBD0:
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// ble cr6,0x8212dc28
	if (!ctx.cr6.gt) goto loc_8212DC28;
loc_8212DBD8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lhz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// addi r30,r30,-1
	ctx.r30.s64 = ctx.r30.s64 + -1;
	// bl 0x8212d268
	ctx.lr = 0x8212DBEC;
	sub_8212D268(ctx, base);
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// lwz r22,80(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// bne cr6,0x8212dc20
	if (!ctx.cr6.eq) goto loc_8212DC20;
	// bl 0x821294e0
	ctx.lr = 0x8212DC00;
	sub_821294E0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,42
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 42, ctx.xer);
	// bne cr6,0x8212dc28
	if (!ctx.cr6.eq) goto loc_8212DC28;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// li r3,63
	ctx.r3.s64 = 63;
	// bl 0x8212d268
	ctx.lr = 0x8212DC1C;
	sub_8212D268(ctx, base);
	// lwz r22,80(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8212DC20:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bgt cr6,0x8212dbd8
	if (ctx.cr6.gt) goto loc_8212DBD8;
loc_8212DC28:
	// rlwinm. r11,r25,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212dc6c
	if (ctx.cr0.eq) goto loc_8212DC6C;
	// rlwinm. r11,r25,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212dc6c
	if (!ctx.cr0.eq) goto loc_8212DC6C;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// ble cr6,0x8212dc6c
	if (!ctx.cr6.gt) goto loc_8212DC6C;
loc_8212DC44:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// li r3,48
	ctx.r3.s64 = 48;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// bl 0x8212d268
	ctx.lr = 0x8212DC58;
	sub_8212D268(ctx, base);
	// lwz r22,80(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// beq cr6,0x8212dc6c
	if (ctx.cr6.eq) goto loc_8212DC6C;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt cr6,0x8212dc44
	if (ctx.cr6.gt) goto loc_8212DC44;
loc_8212DC6C:
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// bne cr6,0x8212dcd4
	if (!ctx.cr6.eq) goto loc_8212DCD4;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// ble cr6,0x8212dcd4
	if (!ctx.cr6.gt) goto loc_8212DCD4;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
loc_8212DC84:
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// lwz r5,172(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// bl 0x82132f50
	ctx.lr = 0x8212DCA0;
	sub_82132F50(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble 0x8212dccc
	if (!ctx.cr0.gt) goto loc_8212DCCC;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lhz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r1.u32 + 84);
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// bl 0x8212d268
	ctx.lr = 0x8212DCB8;
	sub_8212D268(ctx, base);
	// add r30,r29,r30
	ctx.r30.u64 = ctx.r29.u64 + ctx.r30.u64;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt cr6,0x8212dc84
	if (ctx.cr6.gt) goto loc_8212DC84;
	// lwz r22,80(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8212dd58
	goto loc_8212DD58;
loc_8212DCCC:
	// li r22,-1
	ctx.r22.s64 = -1;
	// b 0x8212dcf8
	goto loc_8212DCF8;
loc_8212DCD4:
	// lwz r11,12(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 12);
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212dd00
	if (ctx.cr0.eq) goto loc_8212DD00;
	// lwz r11,8(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8212dd00
	if (!ctx.cr6.eq) goto loc_8212DD00;
	// add r22,r26,r22
	ctx.r22.u64 = ctx.r26.u64 + ctx.r22.u64;
loc_8212DCF8:
	// stw r22,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r22.u32);
	// b 0x8212dd58
	goto loc_8212DD58;
loc_8212DD00:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// ble cr6,0x8212dd58
	if (!ctx.cr6.gt) goto loc_8212DD58;
loc_8212DD08:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lhz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// addi r30,r30,-1
	ctx.r30.s64 = ctx.r30.s64 + -1;
	// bl 0x8212d268
	ctx.lr = 0x8212DD1C;
	sub_8212D268(ctx, base);
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// lwz r22,80(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// bne cr6,0x8212dd50
	if (!ctx.cr6.eq) goto loc_8212DD50;
	// bl 0x821294e0
	ctx.lr = 0x8212DD30;
	sub_821294E0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,42
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 42, ctx.xer);
	// bne cr6,0x8212dd9c
	if (!ctx.cr6.eq) goto loc_8212DD9C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// li r3,63
	ctx.r3.s64 = 63;
	// bl 0x8212d268
	ctx.lr = 0x8212DD4C;
	sub_8212D268(ctx, base);
	// lwz r22,80(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8212DD50:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bgt cr6,0x8212dd08
	if (ctx.cr6.gt) goto loc_8212DD08;
loc_8212DD58:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// blt cr6,0x8212dd9c
	if (ctx.cr6.lt) goto loc_8212DD9C;
	// rlwinm. r11,r25,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212dd9c
	if (ctx.cr0.eq) goto loc_8212DD9C;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// ble cr6,0x8212dd9c
	if (!ctx.cr6.gt) goto loc_8212DD9C;
loc_8212DD74:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// bl 0x8212d268
	ctx.lr = 0x8212DD88;
	sub_8212D268(ctx, base);
	// lwz r22,80(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// beq cr6,0x8212dd9c
	if (ctx.cr6.eq) goto loc_8212DD9C;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt cr6,0x8212dd74
	if (ctx.cr6.gt) goto loc_8212DD74;
loc_8212DD9C:
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8212ddb8
	if (ctx.cr6.eq) goto loc_8212DDB8;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82129880
	ctx.lr = 0x8212DDB0;
	sub_82129880(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
loc_8212DDB8:
	// lhz r29,0(r15)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r15.u32 + 0);
	// mr. r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8212ddd8
	if (ctx.cr0.eq) goto loc_8212DDD8;
	// lwz r31,104(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r7,108(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// b 0x8212d3ac
	goto loc_8212D3AC;
loc_8212DDD8:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// b 0x8212de14
	goto loc_8212DE14;
loc_8212DDE0:
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// mr r5,r15
	ctx.r5.u64 = ctx.r15.u64;
	// li r4,512
	ctx.r4.s64 = 512;
	// addi r3,r1,1152
	ctx.r3.s64 = ctx.r1.s64 + 1152;
	// bl 0x82132f40
	ctx.lr = 0x8212DDF4;
	sub_82132F40(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,-1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -1, ctx.xer);
	// bne cr6,0x8212de08
	if (!ctx.cr6.eq) goto loc_8212DE08;
	// li r31,511
	ctx.r31.s64 = 511;
	// sth r28,2174(r1)
	REX_STORE_U16(ctx.r1.u32 + 2174, ctx.r28.u16);
loc_8212DE08:
	// addi r3,r1,1152
	ctx.r3.s64 = ctx.r1.s64 + 1152;
	// bl 0x821370c8
	ctx.lr = 0x8212DE10;
	sub_821370C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8212DE14:
	// addi r1,r1,2336
	ctx.r1.s64 = ctx.r1.s64 + 2336;
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
}
