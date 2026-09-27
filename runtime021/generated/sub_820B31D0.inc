DEFINE_REX_FUNC(sub_820B31D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f0
	ctx.lr = 0x820B31D8;
	__savegprlr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r18,r5
	ctx.r18.u64 = ctx.r5.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r18,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r18.u32);
	// ld r4,12(r11)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r11.u32 + 12);
	// std r4,152(r31)
	REX_STORE_U64(ctx.r31.u32 + 152, ctx.r4.u64);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820B320C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r3.u32);
	// lfs f0,12(r18)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f13,0(r18)
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f0,9536(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// li r25,0
	ctx.r25.s64 = 0;
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x820b3238
	if (ctx.cr6.lt) goto loc_820B3238;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_820B3238:
	// lbz r10,537(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 537);
	// addi r20,r31,524
	ctx.r20.s64 = ctx.r31.s64 + 524;
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// addi r19,r31,532
	ctx.r19.s64 = ctx.r31.s64 + 532;
	// stw r25,520(r31)
	REX_STORE_U32(ctx.r31.u32 + 520, ctx.r25.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r25,524(r31)
	REX_STORE_U32(ctx.r31.u32 + 524, ctx.r25.u32);
	// stw r25,528(r31)
	REX_STORE_U32(ctx.r31.u32 + 528, ctx.r25.u32);
	// stw r25,532(r31)
	REX_STORE_U32(ctx.r31.u32 + 532, ctx.r25.u32);
	// stw r25,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r25.u32);
	// stw r25,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r25.u32);
	// beq cr6,0x820b32e0
	if (ctx.cr6.eq) goto loc_820B32E0;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b3710
	ctx.lr = 0x820B3274;
	sub_820B3710(ctx, base);
	// stw r3,528(r31)
	REX_STORE_U32(ctx.r31.u32 + 528, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820b3704
	if (ctx.cr6.eq) goto loc_820B3704;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b3ae8
	ctx.lr = 0x820B328C;
	sub_820B3AE8(ctx, base);
	// stw r3,520(r31)
	REX_STORE_U32(ctx.r31.u32 + 520, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820b3704
	if (ctx.cr6.eq) goto loc_820B3704;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x820a7390
	ctx.lr = 0x820B32A0;
	sub_820A7390(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820b3704
	if (ctx.cr6.eq) goto loc_820B3704;
	// stw r25,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r25.u32);
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// lwz r10,528(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 528);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r9,0(r19)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// lwz r8,520(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// lwz r7,0(r20)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// stw r7,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// bl 0x820b4dc8
	ctx.lr = 0x820B32E0;
	sub_820B4DC8(ctx, base);
loc_820B32E0:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r25,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r25.u32);
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// stw r25,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r25.u32);
loc_820B32F0:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// subfic r7,r11,24
	ctx.xer.ca = ctx.r11.u32 <= 24;
	ctx.r7.u64 = static_cast<uint64_t>(24) - ctx.r11.u64;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// lbz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// stw r9,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// slw r5,r6,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r7.u8 & 0x3F));
	// or r8,r5,r8
	ctx.r8.u64 = ctx.r5.u64 | ctx.r8.u64;
	// blt cr6,0x820b32f0
	if (ctx.cr6.lt) goto loc_820B32F0;
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// rlwinm r8,r8,4,28,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xF;
	// stw r10,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// stw r8,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r8.u32);
	// bge cr6,0x820b335c
	if (!ctx.cr6.lt) goto loc_820B335C;
loc_820B3338:
	// lbz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// subfic r7,r11,24
	ctx.xer.ca = ctx.r11.u32 <= 24;
	ctx.r7.u64 = static_cast<uint64_t>(24) - ctx.r11.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// slw r6,r8,r7
	ctx.r6.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r7.u8 & 0x3F));
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r9,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// or r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 | ctx.r10.u64;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// blt cr6,0x820b3338
	if (ctx.cr6.lt) goto loc_820B3338;
loc_820B335C:
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// stw r25,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r25.u32);
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r25,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r25.u32);
	// rlwinm r8,r10,4,28,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xF;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r9,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r8.u32);
	// mr r26,r25
	ctx.r26.u64 = ctx.r25.u64;
	// stw r25,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r25.u32);
	// mr r27,r25
	ctx.r27.u64 = ctx.r25.u64;
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// li r24,1
	ctx.r24.s64 = 1;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// bl 0x820b3e08
	ctx.lr = 0x820B33A0;
	sub_820B3E08(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lis r23,-32215
	ctx.r23.s64 = -2111242240;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// addi r22,r11,29632
	ctx.r22.s64 = ctx.r11.s64 + 29632;
	// addi r21,r10,-1768
	ctx.r21.s64 = ctx.r10.s64 + -1768;
	// beq cr6,0x820b3624
	if (ctx.cr6.eq) goto loc_820B3624;
loc_820B33BC:
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x820b347c
	if (ctx.cr6.lt) goto loc_820B347C;
	// beq cr6,0x820b3420
	if (ctx.cr6.eq) goto loc_820B3420;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x820b3614
	if (!ctx.cr6.lt) goto loc_820B3614;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x820b33f0
	if (ctx.cr6.eq) goto loc_820B33F0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b42c0
	ctx.lr = 0x820B33EC;
	sub_820B42C0(ctx, base);
	// mr r24,r25
	ctx.r24.u64 = ctx.r25.u64;
loc_820B33F0:
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r29,r10,r29
	ctx.r29.u64 = ctx.r10.u64 + ctx.r29.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b4498
	ctx.lr = 0x820B341C;
	sub_820B4498(ctx, base);
	// b 0x820b3614
	goto loc_820B3614;
loc_820B3420:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x820b343c
	if (ctx.cr6.eq) goto loc_820B343C;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b42c0
	ctx.lr = 0x820B3438;
	sub_820B42C0(ctx, base);
	// mr r24,r25
	ctx.r24.u64 = ctx.r25.u64;
loc_820B343C:
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// lwz r8,124(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwz r7,128(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r11,132(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// add r5,r8,r29
	ctx.r5.u64 = ctx.r8.u64 + ctx.r29.u64;
	// add r30,r7,r4
	ctx.r30.u64 = ctx.r7.u64 + ctx.r4.u64;
	// add r29,r11,r5
	ctx.r29.u64 = ctx.r11.u64 + ctx.r5.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b4920
	ctx.lr = 0x820B3478;
	sub_820B4920(ctx, base);
	// b 0x820b3614
	goto loc_820B3614;
loc_820B347C:
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820b351c
	if (ctx.cr6.eq) goto loc_820B351C;
	// lwz r10,104(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// lwz r9,108(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r7,112(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// lwz r6,116(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// lbz r8,-22601(r23)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r23.u32 + -22601);
	// stw r10,528(r31)
	REX_STORE_U32(ctx.r31.u32 + 528, ctx.r10.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stw r9,0(r19)
	REX_STORE_U32(ctx.r19.u32 + 0, ctx.r9.u32);
	// stw r7,520(r31)
	REX_STORE_U32(ctx.r31.u32 + 520, ctx.r7.u32);
	// stw r6,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r6.u32);
	// bne cr6,0x820b34cc
	if (!ctx.cr6.eq) goto loc_820B34CC;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820B34CC;
	sub_820A71E8(ctx, base);
loc_820B34CC:
	// bl 0x820b5eb8
	ctx.lr = 0x820B34D0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,20
	ctx.r4.s64 = 20;
	// lwzx r3,r11,r22
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r22.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820B34E0;
	sub_8209BDD8(ctx, base);
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,16(r9)
	REX_STORE_U32(ctx.r9.u32 + 16, ctx.r10.u32);
	// lwz r8,104(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lwz r7,108(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// stw r7,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r7.u32);
	// lwz r6,112(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// stw r6,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r6.u32);
	// lwz r5,116(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// stw r5,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r5.u32);
	// stw r9,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r9.u32);
	// bl 0x820b4dc8
	ctx.lr = 0x820B351C;
	sub_820B4DC8(ctx, base);
loc_820B351C:
	// lwz r8,80(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// rlwinm r11,r8,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820b3560
	if (ctx.cr6.eq) goto loc_820B3560;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820b355c
	if (ctx.cr6.eq) goto loc_820B355C;
	// lwz r10,528(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 528);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820b3554
	if (ctx.cr6.eq) goto loc_820B3554;
	// mulli r11,r11,180
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(180));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r27,r11,-180
	ctx.r27.s64 = ctx.r11.s64 + -180;
	// b 0x820b3560
	goto loc_820B3560;
loc_820B3554:
	// addi r27,r31,148
	ctx.r27.s64 = ctx.r31.s64 + 148;
	// b 0x820b3560
	goto loc_820B3560;
loc_820B355C:
	// mr r27,r25
	ctx.r27.u64 = ctx.r25.u64;
loc_820B3560:
	// rlwinm r11,r8,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820b35a0
	if (ctx.cr6.eq) goto loc_820B35A0;
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820b359c
	if (ctx.cr6.eq) goto loc_820B359C;
	// lwz r10,528(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 528);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820b3594
	if (ctx.cr6.eq) goto loc_820B3594;
	// mulli r11,r11,180
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(180));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r28,r11,-180
	ctx.r28.s64 = ctx.r11.s64 + -180;
	// b 0x820b35a0
	goto loc_820B35A0;
loc_820B3594:
	// addi r28,r31,148
	ctx.r28.s64 = ctx.r31.s64 + 148;
	// b 0x820b35a0
	goto loc_820B35A0;
loc_820B359C:
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
loc_820B35A0:
	// rlwinm r11,r8,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820b35d8
	if (ctx.cr6.eq) goto loc_820B35D8;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820b35d4
	if (ctx.cr6.eq) goto loc_820B35D4;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,520(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r26,r11,-192
	ctx.r26.s64 = ctx.r11.s64 + -192;
	// b 0x820b35d8
	goto loc_820B35D8;
loc_820B35D4:
	// mr r26,r25
	ctx.r26.u64 = ctx.r25.u64;
loc_820B35D8:
	// clrlwi r11,r8,31
	ctx.r11.u64 = ctx.r8.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820b3614
	if (ctx.cr6.eq) goto loc_820B3614;
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820b35f8
	if (!ctx.cr6.eq) goto loc_820B35F8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b46a8
	ctx.lr = 0x820B35F8;
	sub_820B46A8(ctx, base);
loc_820B35F8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,88(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r4,84(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x820b42c0
	ctx.lr = 0x820B3608;
	sub_820B42C0(ctx, base);
	// mr r24,r25
	ctx.r24.u64 = ctx.r25.u64;
	// lwz r30,84(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r29,88(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
loc_820B3614:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b3e08
	ctx.lr = 0x820B361C;
	sub_820B3E08(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820b33bc
	if (!ctx.cr6.eq) goto loc_820B33BC;
loc_820B3624:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b46a8
	ctx.lr = 0x820B362C;
	sub_820B46A8(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820b3704
	if (ctx.cr6.eq) goto loc_820B3704;
loc_820B3638:
	// lwz r30,28(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r5,4(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x820b54e8
	ctx.lr = 0x820B3654;
	sub_820B54E8(ctx, base);
	// lbz r10,-22601(r23)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r23.u32 + -22601);
	// lwz r29,0(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820b3678
	if (!ctx.cr6.eq) goto loc_820B3678;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820B3678;
	sub_820A71E8(ctx, base);
loc_820B3678:
	// bl 0x820b5eb8
	ctx.lr = 0x820B367C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r11,r22
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r22.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820B368C;
	sub_8209BF18(ctx, base);
	// lbz r10,-22601(r23)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r23.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r29,8(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// bne cr6,0x820b36b0
	if (!ctx.cr6.eq) goto loc_820B36B0;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820B36B0;
	sub_820A71E8(ctx, base);
loc_820B36B0:
	// bl 0x820b5eb8
	ctx.lr = 0x820B36B4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r11,r22
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r22.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820B36C4;
	sub_8209BF18(ctx, base);
	// lbz r10,-22601(r23)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r23.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820b36e4
	if (!ctx.cr6.eq) goto loc_820B36E4;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820B36E4;
	sub_820A71E8(ctx, base);
loc_820B36E4:
	// bl 0x820b5eb8
	ctx.lr = 0x820B36E8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r11,r22
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r22.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820B36F8;
	sub_8209BF18(ctx, base);
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820b3638
	if (!ctx.cr6.eq) goto loc_820B3638;
loc_820B3704:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
}
