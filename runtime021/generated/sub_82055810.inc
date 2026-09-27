DEFINE_REX_FUNC(sub_82055810) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x82055818;
	__savegprlr_23(ctx, base);
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32215
	ctx.r27.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r24,r11,-1768
	ctx.r24.s64 = ctx.r11.s64 + -1768;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82055854
	if (!ctx.cr6.eq) goto loc_82055854;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82055854;
	sub_820A71E8(ctx, base);
loc_82055854:
	// bl 0x820b5eb8
	ctx.lr = 0x82055858;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r25,r11,29632
	ctx.r25.s64 = ctx.r11.s64 + 29632;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r10,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82055870;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82055888
	if (ctx.cr6.eq) goto loc_82055888;
	// li r4,382
	ctx.r4.s64 = 382;
	// bl 0x82067778
	ctx.lr = 0x82055880;
	sub_82067778(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205588c
	goto loc_8205588C;
loc_82055888:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8205588C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lfs f31,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820558A4;
	sub_82065F78(ctx, base);
	// lbz r10,-22601(r27)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820558c4
	if (!ctx.cr6.eq) goto loc_820558C4;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820558C4;
	sub_820A71E8(ctx, base);
loc_820558C4:
	// bl 0x820b5eb8
	ctx.lr = 0x820558C8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,112
	ctx.r4.s64 = 112;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820558D8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820558fc
	if (ctx.cr6.eq) goto loc_820558FC;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r6,469
	ctx.r6.s64 = 469;
	// addi r5,r11,-17144
	ctx.r5.s64 = ctx.r11.s64 + -17144;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067828
	ctx.lr = 0x820558F4;
	sub_82067828(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82055900
	goto loc_82055900;
loc_820558FC:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82055900:
	// li r4,533
	ctx.r4.s64 = 533;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x8205590C;
	sub_820679E8(ctx, base);
	// li r4,534
	ctx.r4.s64 = 534;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x82055918;
	sub_820679E8(ctx, base);
	// li r4,535
	ctx.r4.s64 = 535;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x82055924;
	sub_820679E8(ctx, base);
	// li r4,536
	ctx.r4.s64 = 536;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x82055930;
	sub_820679E8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82055944;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82055964
	if (!ctx.cr6.eq) goto loc_82055964;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82055964;
	sub_820A71E8(ctx, base);
loc_82055964:
	// bl 0x820b5eb8
	ctx.lr = 0x82055968;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,112
	ctx.r4.s64 = 112;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82055978;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205599c
	if (ctx.cr6.eq) goto loc_8205599C;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r6,468
	ctx.r6.s64 = 468;
	// addi r5,r11,-17288
	ctx.r5.s64 = ctx.r11.s64 + -17288;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067828
	ctx.lr = 0x82055994;
	sub_82067828(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x820559a0
	goto loc_820559A0;
loc_8205599C:
	// li r31,0
	ctx.r31.s64 = 0;
loc_820559A0:
	// li r4,535
	ctx.r4.s64 = 535;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x820559AC;
	sub_820679E8(ctx, base);
	// li r4,536
	ctx.r4.s64 = 536;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x820559B8;
	sub_820679E8(ctx, base);
	// li r4,537
	ctx.r4.s64 = 537;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x820559C4;
	sub_820679E8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820559D8;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820559f8
	if (!ctx.cr6.eq) goto loc_820559F8;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820559F8;
	sub_820A71E8(ctx, base);
loc_820559F8:
	// bl 0x820b5eb8
	ctx.lr = 0x820559FC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,112
	ctx.r4.s64 = 112;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82055A0C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82055a30
	if (ctx.cr6.eq) goto loc_82055A30;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r6,470
	ctx.r6.s64 = 470;
	// addi r5,r11,-17008
	ctx.r5.s64 = ctx.r11.s64 + -17008;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067828
	ctx.lr = 0x82055A28;
	sub_82067828(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82055a34
	goto loc_82055A34;
loc_82055A30:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82055A34:
	// li r5,18
	ctx.r5.s64 = 18;
	// li r4,470
	ctx.r4.s64 = 470;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x82055A44;
	sub_82067230(ctx, base);
	// li r4,448
	ctx.r4.s64 = 448;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x82055A50;
	sub_820679E8(ctx, base);
	// li r4,447
	ctx.r4.s64 = 447;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x82055A5C;
	sub_820679E8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82055A70;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82055a90
	if (!ctx.cr6.eq) goto loc_82055A90;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82055A90;
	sub_820A71E8(ctx, base);
loc_82055A90:
	// bl 0x820b5eb8
	ctx.lr = 0x82055A94;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82055AA4;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82055acc
	if (ctx.cr6.eq) goto loc_82055ACC;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,465
	ctx.r6.s64 = 465;
	// addi r5,r11,27432
	ctx.r5.s64 = ctx.r11.s64 + 27432;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067020
	ctx.lr = 0x82055AC4;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82055ad0
	goto loc_82055AD0;
loc_82055ACC:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82055AD0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82055AE0;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82055b00
	if (!ctx.cr6.eq) goto loc_82055B00;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82055B00;
	sub_820A71E8(ctx, base);
loc_82055B00:
	// bl 0x820b5eb8
	ctx.lr = 0x82055B04;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82055B14;
	sub_8209BDD8(ctx, base);
	// lis r10,-21846
	ctx.r10.s64 = -1431699456;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// ori r30,r10,43775
	ctx.r30.u64 = ctx.r10.u64 | 43775;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r29,r11,9460
	ctx.r29.s64 = ctx.r11.s64 + 9460;
	// beq cr6,0x82055b5c
	if (ctx.cr6.eq) goto loc_82055B5C;
	// lwz r23,4(r26)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82055B38;
	sub_82066F80(ctx, base);
	// li r11,17
	ctx.r11.s64 = 17;
	// stw r23,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r23.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x82055B50;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82055b60
	goto loc_82055B60;
loc_82055B5C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82055B60:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82055B70;
	sub_82065F78(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lbz r7,-22601(r27)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// li r9,26
	ctx.r9.s64 = 26;
	// addi r8,r10,20768
	ctx.r8.s64 = ctx.r10.s64 + 20768;
	// stw r26,356(r28)
	REX_STORE_U32(ctx.r28.u32 + 356, ctx.r26.u32);
	// sth r9,390(r28)
	REX_STORE_U16(ctx.r28.u32 + 390, ctx.r9.u16);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r8,364(r28)
	REX_STORE_U32(ctx.r28.u32 + 364, ctx.r8.u32);
	// bne cr6,0x82055ba8
	if (!ctx.cr6.eq) goto loc_82055BA8;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82055BA8;
	sub_820A71E8(ctx, base);
loc_82055BA8:
	// bl 0x820b5eb8
	ctx.lr = 0x82055BAC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82055BBC;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82055bf4
	if (ctx.cr6.eq) goto loc_82055BF4;
	// lwz r27,4(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82055BD0;
	sub_82066F80(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r27,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r27.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x82055BE8;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82055bf8
	goto loc_82055BF8;
loc_82055BF4:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82055BF8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82055C08;
	sub_82065F78(ctx, base);
	// li r11,255
	ctx.r11.s64 = 255;
	// sth r11,16(r28)
	REX_STORE_U16(ctx.r28.u32 + 16, ctx.r11.u16);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
