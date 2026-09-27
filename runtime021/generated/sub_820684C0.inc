DEFINE_REX_FUNC(sub_820684C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x820684C8;
	__savegprlr_22(ctx, base);
	// stfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f29.u64);
	// stfd f30,-104(r1)
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f30.u64);
	// stfd f31,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32215
	ctx.r26.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r23,r11,-1768
	ctx.r23.s64 = ctx.r11.s64 + -1768;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206850c
	if (!ctx.cr6.eq) goto loc_8206850C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206850C;
	sub_820A71E8(ctx, base);
loc_8206850C:
	// bl 0x820b5eb8
	ctx.lr = 0x82068510;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r24,r11,29632
	ctx.r24.s64 = ctx.r11.s64 + 29632;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r10,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068528;
	sub_8209BDD8(ctx, base);
	// li r25,0
	ctx.r25.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82068544
	if (ctx.cr6.eq) goto loc_82068544;
	// li r4,582
	ctx.r4.s64 = 582;
	// bl 0x82067778
	ctx.lr = 0x8206853C;
	sub_82067778(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82068548
	goto loc_82068548;
loc_82068544:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82068548:
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
	ctx.lr = 0x82068560;
	sub_82065F78(ctx, base);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r11,-6596(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6596);
	// lfs f29,9920(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9920);
	ctx.f29.f64 = double(temp.f32);
	// lbz r8,9(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 9);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82068584
	if (!ctx.cr6.eq) goto loc_82068584;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f29,9916(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9916);
	ctx.f29.f64 = double(temp.f32);
loc_82068584:
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820685a4
	if (!ctx.cr6.eq) goto loc_820685A4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820685A4;
	sub_820A71E8(ctx, base);
loc_820685A4:
	// bl 0x820b5eb8
	ctx.lr = 0x820685A8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820685B8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820685e0
	if (ctx.cr6.eq) goto loc_820685E0;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r7,21
	ctx.r7.s64 = 21;
	// li r6,478
	ctx.r6.s64 = 478;
	// addi r5,r11,-27272
	ctx.r5.s64 = ctx.r11.s64 + -27272;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x820685D8;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x820685e4
	goto loc_820685E4;
loc_820685E0:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_820685E4:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820685F4;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82068614
	if (!ctx.cr6.eq) goto loc_82068614;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82068614;
	sub_820A71E8(ctx, base);
loc_82068614:
	// bl 0x820b5eb8
	ctx.lr = 0x82068618;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068628;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82068650
	if (ctx.cr6.eq) goto loc_82068650;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r7,21
	ctx.r7.s64 = 21;
	// li r6,478
	ctx.r6.s64 = 478;
	// addi r5,r11,-27272
	ctx.r5.s64 = ctx.r11.s64 + -27272;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x82068648;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82068654
	goto loc_82068654;
loc_82068650:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82068654:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82068664;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82068684
	if (!ctx.cr6.eq) goto loc_82068684;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82068684;
	sub_820A71E8(ctx, base);
loc_82068684:
	// bl 0x820b5eb8
	ctx.lr = 0x82068688;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068698;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820686c0
	if (ctx.cr6.eq) goto loc_820686C0;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r7,21
	ctx.r7.s64 = 21;
	// li r6,478
	ctx.r6.s64 = 478;
	// addi r5,r11,-27272
	ctx.r5.s64 = ctx.r11.s64 + -27272;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x820686B8;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x820686c4
	goto loc_820686C4;
loc_820686C0:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_820686C4:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820686D4;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820686f4
	if (!ctx.cr6.eq) goto loc_820686F4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820686F4;
	sub_820A71E8(ctx, base);
loc_820686F4:
	// bl 0x820b5eb8
	ctx.lr = 0x820686F8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068708;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82068730
	if (ctx.cr6.eq) goto loc_82068730;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r7,21
	ctx.r7.s64 = 21;
	// li r6,478
	ctx.r6.s64 = 478;
	// addi r5,r11,-27272
	ctx.r5.s64 = ctx.r11.s64 + -27272;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x82068728;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82068734
	goto loc_82068734;
loc_82068730:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82068734:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82068744;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82068764
	if (!ctx.cr6.eq) goto loc_82068764;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82068764;
	sub_820A71E8(ctx, base);
loc_82068764:
	// bl 0x820b5eb8
	ctx.lr = 0x82068768;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068778;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r29,r11,9448
	ctx.r29.s64 = ctx.r11.s64 + 9448;
	// addi r30,r10,-10192
	ctx.r30.s64 = ctx.r10.s64 + -10192;
	// beq cr6,0x820687e8
	if (ctx.cr6.eq) goto loc_820687E8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82053a00
	ctx.lr = 0x820687A0;
	sub_82053A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r22,4(r27)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x820687AC;
	sub_82066F80(ctx, base);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r22,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r22.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// stw r25,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r25.u32);
	// bl 0x82053a00
	ctx.lr = 0x820687C4;
	sub_82053A00(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r5,2005
	ctx.r5.s64 = 2005;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,9912(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9912);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82067c40
	ctx.lr = 0x820687E0;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x820687ec
	goto loc_820687EC;
loc_820687E8:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_820687EC:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820687FC;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206881c
	if (!ctx.cr6.eq) goto loc_8206881C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206881C;
	sub_820A71E8(ctx, base);
loc_8206881C:
	// bl 0x820b5eb8
	ctx.lr = 0x82068820;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068830;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82068890
	if (ctx.cr6.eq) goto loc_82068890;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82053a00
	ctx.lr = 0x82068848;
	sub_82053A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r22,4(r27)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82068854;
	sub_82066F80(ctx, base);
	// addi r4,r1,164
	ctx.r4.s64 = ctx.r1.s64 + 164;
	// stw r22,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r22.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// stw r25,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r25.u32);
	// bl 0x82053a00
	ctx.lr = 0x8206886C;
	sub_82053A00(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r5,2006
	ctx.r5.s64 = 2006;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,9908(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9908);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82067c40
	ctx.lr = 0x82068888;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x82068894
	goto loc_82068894;
loc_82068890:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82068894:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820688A4;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820688c4
	if (!ctx.cr6.eq) goto loc_820688C4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820688C4;
	sub_820A71E8(ctx, base);
loc_820688C4:
	// bl 0x820b5eb8
	ctx.lr = 0x820688C8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820688D8;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82068938
	if (ctx.cr6.eq) goto loc_82068938;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82053a00
	ctx.lr = 0x820688F0;
	sub_82053A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r22,4(r27)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x820688FC;
	sub_82066F80(ctx, base);
	// addi r4,r1,164
	ctx.r4.s64 = ctx.r1.s64 + 164;
	// stw r22,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r22.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// stw r25,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r25.u32);
	// bl 0x82053a00
	ctx.lr = 0x82068914;
	sub_82053A00(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r5,2007
	ctx.r5.s64 = 2007;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,9904(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9904);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82067c40
	ctx.lr = 0x82068930;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x8206893c
	goto loc_8206893C;
loc_82068938:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_8206893C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206894C;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206896c
	if (!ctx.cr6.eq) goto loc_8206896C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206896C;
	sub_820A71E8(ctx, base);
loc_8206896C:
	// bl 0x820b5eb8
	ctx.lr = 0x82068970;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068980;
	sub_8209BDD8(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// lfs f30,9900(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9900);
	ctx.f30.f64 = double(temp.f32);
	// beq cr6,0x820689e4
	if (ctx.cr6.eq) goto loc_820689E4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82053a00
	ctx.lr = 0x820689A0;
	sub_82053A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r30,4(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x820689AC;
	sub_82066F80(ctx, base);
	// addi r4,r1,164
	ctx.r4.s64 = ctx.r1.s64 + 164;
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// stw r25,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r25.u32);
	// bl 0x82053a00
	ctx.lr = 0x820689C4;
	sub_82053A00(ctx, base);
	// li r5,2008
	ctx.r5.s64 = 2008;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f30.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x82067c40
	ctx.lr = 0x820689DC;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x820689e8
	goto loc_820689E8;
loc_820689E4:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_820689E8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820689F8;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82068a18
	if (!ctx.cr6.eq) goto loc_82068A18;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82068A18;
	sub_820A71E8(ctx, base);
loc_82068A18:
	// bl 0x820b5eb8
	ctx.lr = 0x82068A1C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068A2C;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82068a94
	if (ctx.cr6.eq) goto loc_82068A94;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r4,r11,-10180
	ctx.r4.s64 = ctx.r11.s64 + -10180;
	// bl 0x82053a00
	ctx.lr = 0x82068A48;
	sub_82053A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r30,4(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82068A54;
	sub_82066F80(ctx, base);
	// addi r4,r1,164
	ctx.r4.s64 = ctx.r1.s64 + 164;
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// stw r25,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r25.u32);
	// bl 0x82053a00
	ctx.lr = 0x82068A6C;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,2017
	ctx.r5.s64 = 2017;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f30.f64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,9896(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9896);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f29,f0
	ctx.f1.f64 = double(float(ctx.f29.f64 + ctx.f0.f64));
	// bl 0x82067c40
	ctx.lr = 0x82068A8C;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x82068a98
	goto loc_82068A98;
loc_82068A94:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82068A98:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82068AA8;
	sub_82065F78(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r4,20(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lbz r5,-22601(r26)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lfs f0,9872(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9872);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stfs f0,8(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// lwz r3,24(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// lfs f13,18236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18236);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,8(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lwz r11,28(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 28);
	// lfs f12,9892(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9892);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,8(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// lwz r10,32(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 32);
	// lfs f11,9888(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9888);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,8(r10)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r9,36(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 36);
	// lfs f10,9884(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 9884);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,8(r9)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// bne cr6,0x82068b18
	if (!ctx.cr6.eq) goto loc_82068B18;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82068B18;
	sub_820A71E8(ctx, base);
loc_82068B18:
	// bl 0x820b5eb8
	ctx.lr = 0x82068B1C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068B2C;
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
	// beq cr6,0x82068b74
	if (ctx.cr6.eq) goto loc_82068B74;
	// lwz r22,4(r27)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82068B50;
	sub_82066F80(ctx, base);
	// li r11,18
	ctx.r11.s64 = 18;
	// stw r22,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r22.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x82068B68;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82068b78
	goto loc_82068B78;
loc_82068B74:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82068B78:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82068B88;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82068ba8
	if (!ctx.cr6.eq) goto loc_82068BA8;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82068BA8;
	sub_820A71E8(ctx, base);
loc_82068BA8:
	// bl 0x820b5eb8
	ctx.lr = 0x82068BAC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068BBC;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82068bf4
	if (ctx.cr6.eq) goto loc_82068BF4;
	// lwz r22,4(r27)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82068BD0;
	sub_82066F80(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r22,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r22.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x82068BE8;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82068bf8
	goto loc_82068BF8;
loc_82068BF4:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82068BF8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82068C08;
	sub_82065F78(ctx, base);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lbz r5,-22601(r26)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// addi r8,r10,-26968
	ctx.r8.s64 = ctx.r10.s64 + -26968;
	// stw r27,356(r28)
	REX_STORE_U32(ctx.r28.u32 + 356, ctx.r27.u32);
	// addi r7,r9,-23136
	ctx.r7.s64 = ctx.r9.s64 + -23136;
	// li r6,26
	ctx.r6.s64 = 26;
	// stw r8,368(r28)
	REX_STORE_U32(ctx.r28.u32 + 368, ctx.r8.u32);
	// stw r7,364(r28)
	REX_STORE_U32(ctx.r28.u32 + 364, ctx.r7.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// sth r6,390(r28)
	REX_STORE_U16(ctx.r28.u32 + 390, ctx.r6.u16);
	// bne cr6,0x82068c48
	if (!ctx.cr6.eq) goto loc_82068C48;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82068C48;
	sub_820A71E8(ctx, base);
loc_82068C48:
	// bl 0x820b5eb8
	ctx.lr = 0x82068C4C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068C5C;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82068c94
	if (ctx.cr6.eq) goto loc_82068C94;
	// lwz r22,4(r27)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82068C70;
	sub_82066F80(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r22,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r22.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x82068C88;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82068c98
	goto loc_82068C98;
loc_82068C94:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82068C98:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82068CA8;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82068cc8
	if (!ctx.cr6.eq) goto loc_82068CC8;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82068CC8;
	sub_820A71E8(ctx, base);
loc_82068CC8:
	// bl 0x820b5eb8
	ctx.lr = 0x82068CCC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068CDC;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82068d14
	if (ctx.cr6.eq) goto loc_82068D14;
	// lwz r26,4(r27)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82068CF0;
	sub_82066F80(ctx, base);
	// li r11,20
	ctx.r11.s64 = 20;
	// stw r26,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r26.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x82068D08;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82068d18
	goto loc_82068D18;
loc_82068D14:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82068D18:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82068D28;
	sub_82065F78(ctx, base);
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r27,356(r28)
	REX_STORE_U32(ctx.r28.u32 + 356, ctx.r27.u32);
	// addi r9,r11,-22008
	ctx.r9.s64 = ctx.r11.s64 + -22008;
	// addi r8,r10,-26776
	ctx.r8.s64 = ctx.r10.s64 + -26776;
	// li r7,15
	ctx.r7.s64 = 15;
	// stw r9,372(r28)
	REX_STORE_U32(ctx.r28.u32 + 372, ctx.r9.u32);
	// stw r8,384(r28)
	REX_STORE_U32(ctx.r28.u32 + 384, ctx.r8.u32);
	// sth r7,16(r28)
	REX_STORE_U16(ctx.r28.u32 + 16, ctx.r7.u16);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f30,-104(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
