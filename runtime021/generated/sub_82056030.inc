DEFINE_REX_FUNC(sub_82056030) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x82056038;
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
	// bne cr6,0x82056074
	if (!ctx.cr6.eq) goto loc_82056074;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82056074;
	sub_820A71E8(ctx, base);
loc_82056074:
	// bl 0x820b5eb8
	ctx.lr = 0x82056078;
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
	ctx.lr = 0x82056090;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820560a8
	if (ctx.cr6.eq) goto loc_820560A8;
	// li r4,390
	ctx.r4.s64 = 390;
	// bl 0x82067778
	ctx.lr = 0x820560A0;
	sub_82067778(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x820560ac
	goto loc_820560AC;
loc_820560A8:
	// li r4,0
	ctx.r4.s64 = 0;
loc_820560AC:
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
	ctx.lr = 0x820560C4;
	sub_82065F78(ctx, base);
	// lbz r10,-22601(r27)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820560e4
	if (!ctx.cr6.eq) goto loc_820560E4;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820560E4;
	sub_820A71E8(ctx, base);
loc_820560E4:
	// bl 0x820b5eb8
	ctx.lr = 0x820560E8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,112
	ctx.r4.s64 = 112;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820560F8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205611c
	if (ctx.cr6.eq) goto loc_8205611C;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r6,468
	ctx.r6.s64 = 468;
	// addi r5,r11,-17288
	ctx.r5.s64 = ctx.r11.s64 + -17288;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067828
	ctx.lr = 0x82056114;
	sub_82067828(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82056120
	goto loc_82056120;
loc_8205611C:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82056120:
	// li r4,535
	ctx.r4.s64 = 535;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x8205612C;
	sub_820679E8(ctx, base);
	// li r4,536
	ctx.r4.s64 = 536;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x82056138;
	sub_820679E8(ctx, base);
	// li r4,537
	ctx.r4.s64 = 537;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x82056144;
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
	ctx.lr = 0x82056158;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82056178
	if (!ctx.cr6.eq) goto loc_82056178;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82056178;
	sub_820A71E8(ctx, base);
loc_82056178:
	// bl 0x820b5eb8
	ctx.lr = 0x8205617C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,112
	ctx.r4.s64 = 112;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205618C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820561b0
	if (ctx.cr6.eq) goto loc_820561B0;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r6,470
	ctx.r6.s64 = 470;
	// addi r5,r11,-17008
	ctx.r5.s64 = ctx.r11.s64 + -17008;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067828
	ctx.lr = 0x820561A8;
	sub_82067828(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x820561b4
	goto loc_820561B4;
loc_820561B0:
	// li r31,0
	ctx.r31.s64 = 0;
loc_820561B4:
	// li r5,18
	ctx.r5.s64 = 18;
	// li r4,470
	ctx.r4.s64 = 470;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067230
	ctx.lr = 0x820561C4;
	sub_82067230(ctx, base);
	// li r4,448
	ctx.r4.s64 = 448;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x820561D0;
	sub_820679E8(ctx, base);
	// li r4,447
	ctx.r4.s64 = 447;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x820561DC;
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
	ctx.lr = 0x820561F0;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82056210
	if (!ctx.cr6.eq) goto loc_82056210;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82056210;
	sub_820A71E8(ctx, base);
loc_82056210:
	// bl 0x820b5eb8
	ctx.lr = 0x82056214;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82056224;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205624c
	if (ctx.cr6.eq) goto loc_8205624C;
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
	ctx.lr = 0x82056244;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82056250
	goto loc_82056250;
loc_8205624C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82056250:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82056260;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82056280
	if (!ctx.cr6.eq) goto loc_82056280;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82056280;
	sub_820A71E8(ctx, base);
loc_82056280:
	// bl 0x820b5eb8
	ctx.lr = 0x82056284;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82056294;
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
	// beq cr6,0x820562dc
	if (ctx.cr6.eq) goto loc_820562DC;
	// lwz r23,4(r26)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x820562B8;
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
	ctx.lr = 0x820562D0;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x820562e0
	goto loc_820562E0;
loc_820562DC:
	// li r4,0
	ctx.r4.s64 = 0;
loc_820562E0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820562F0;
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
	// bne cr6,0x82056328
	if (!ctx.cr6.eq) goto loc_82056328;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82056328;
	sub_820A71E8(ctx, base);
loc_82056328:
	// bl 0x820b5eb8
	ctx.lr = 0x8205632C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205633C;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82056374
	if (ctx.cr6.eq) goto loc_82056374;
	// lwz r27,4(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82056350;
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
	ctx.lr = 0x82056368;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82056378
	goto loc_82056378;
loc_82056374:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82056378:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82056388;
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
