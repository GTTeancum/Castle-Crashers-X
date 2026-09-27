DEFINE_REX_FUNC(sub_820623C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x820623C8;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32215
	ctx.r29.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r26,r11,-1768
	ctx.r26.s64 = ctx.r11.s64 + -1768;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82062404
	if (!ctx.cr6.eq) goto loc_82062404;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062404;
	sub_820A71E8(ctx, base);
loc_82062404:
	// bl 0x820b5eb8
	ctx.lr = 0x82062408;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r27,r11,29632
	ctx.r27.s64 = ctx.r11.s64 + 29632;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r10,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82062420;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82062494
	if (ctx.cr6.eq) goto loc_82062494;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,9672
	ctx.r4.s64 = ctx.r11.s64 + 9672;
	// bl 0x82053a00
	ctx.lr = 0x8206243C;
	sub_82053A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r25,4(r28)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82062448;
	sub_82066F80(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r25,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r25.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,9448
	ctx.r8.s64 = ctx.r10.s64 + 9448;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// stw r9,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r9.u32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// bl 0x82053a00
	ctx.lr = 0x8206246C;
	sub_82053A00(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r5,2000
	ctx.r5.s64 = 2000;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,9944(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9944);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,9916(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 9916);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82067c40
	ctx.lr = 0x8206248C;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x82062498
	goto loc_82062498;
loc_82062494:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82062498:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f31,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820624B0;
	sub_82065F78(ctx, base);
	// lbz r10,-22601(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820624d0
	if (!ctx.cr6.eq) goto loc_820624D0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820624D0;
	sub_820A71E8(ctx, base);
loc_820624D0:
	// bl 0x820b5eb8
	ctx.lr = 0x820624D4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820624E4;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206250c
	if (ctx.cr6.eq) goto loc_8206250C;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,386
	ctx.r6.s64 = 386;
	// addi r5,r11,13896
	ctx.r5.s64 = ctx.r11.s64 + 13896;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82067020
	ctx.lr = 0x82062504;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82062510
	goto loc_82062510;
loc_8206250C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82062510:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82062520;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82062540
	if (!ctx.cr6.eq) goto loc_82062540;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062540;
	sub_820A71E8(ctx, base);
loc_82062540:
	// bl 0x820b5eb8
	ctx.lr = 0x82062544;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82062554;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206257c
	if (ctx.cr6.eq) goto loc_8206257C;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,387
	ctx.r6.s64 = 387;
	// addi r5,r11,16456
	ctx.r5.s64 = ctx.r11.s64 + 16456;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82067020
	ctx.lr = 0x82062574;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82062580
	goto loc_82062580;
loc_8206257C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82062580:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82062590;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820625b0
	if (!ctx.cr6.eq) goto loc_820625B0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820625B0;
	sub_820A71E8(ctx, base);
loc_820625B0:
	// bl 0x820b5eb8
	ctx.lr = 0x820625B4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820625C4;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820625ec
	if (ctx.cr6.eq) goto loc_820625EC;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,388
	ctx.r6.s64 = 388;
	// addi r5,r11,16640
	ctx.r5.s64 = ctx.r11.s64 + 16640;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82067020
	ctx.lr = 0x820625E4;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x820625f0
	goto loc_820625F0;
loc_820625EC:
	// li r4,0
	ctx.r4.s64 = 0;
loc_820625F0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82062600;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82062620
	if (!ctx.cr6.eq) goto loc_82062620;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062620;
	sub_820A71E8(ctx, base);
loc_82062620:
	// bl 0x820b5eb8
	ctx.lr = 0x82062624;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82062634;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206265c
	if (ctx.cr6.eq) goto loc_8206265C;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,597
	ctx.r6.s64 = 597;
	// addi r5,r11,-11296
	ctx.r5.s64 = ctx.r11.s64 + -11296;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82067020
	ctx.lr = 0x82062654;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82062660
	goto loc_82062660;
loc_8206265C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82062660:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82062670;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82062690
	if (!ctx.cr6.eq) goto loc_82062690;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062690;
	sub_820A71E8(ctx, base);
loc_82062690:
	// bl 0x820b5eb8
	ctx.lr = 0x82062694;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820626A4;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820626cc
	if (ctx.cr6.eq) goto loc_820626CC;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,598
	ctx.r6.s64 = 598;
	// addi r5,r11,20888
	ctx.r5.s64 = ctx.r11.s64 + 20888;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82067020
	ctx.lr = 0x820626C4;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x820626d0
	goto loc_820626D0;
loc_820626CC:
	// li r4,0
	ctx.r4.s64 = 0;
loc_820626D0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820626E0;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82062700
	if (!ctx.cr6.eq) goto loc_82062700;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062700;
	sub_820A71E8(ctx, base);
loc_82062700:
	// bl 0x820b5eb8
	ctx.lr = 0x82062704;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82062714;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206273c
	if (ctx.cr6.eq) goto loc_8206273C;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,599
	ctx.r6.s64 = 599;
	// addi r5,r11,-23992
	ctx.r5.s64 = ctx.r11.s64 + -23992;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82067020
	ctx.lr = 0x82062734;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82062740
	goto loc_82062740;
loc_8206273C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82062740:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82062750;
	sub_82065F78(ctx, base);
	// lis r31,-32215
	ctx.r31.s64 = -2111242240;
	// lbz r11,2704(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 2704);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82062768
	if (ctx.cr6.eq) goto loc_82062768;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820627a0
	goto loc_820627A0;
loc_82062768:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820b6818
	ctx.lr = 0x82062774;
	sub_820B6818(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8206279c
	if (!ctx.cr6.eq) goto loc_8206279C;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206279c
	if (ctx.cr6.eq) goto loc_8206279C;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r10,2704(r31)
	REX_STORE_U8(ctx.r31.u32 + 2704, ctx.r10.u8);
	// b 0x820627a0
	goto loc_820627A0;
loc_8206279C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_820627A0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// beq cr6,0x82062808
	if (ctx.cr6.eq) goto loc_82062808;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820627cc
	if (!ctx.cr6.eq) goto loc_820627CC;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820627CC;
	sub_820A71E8(ctx, base);
loc_820627CC:
	// bl 0x820b5eb8
	ctx.lr = 0x820627D0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820627E0;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82062860
	if (ctx.cr6.eq) goto loc_82062860;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,601
	ctx.r6.s64 = 601;
	// addi r5,r11,20488
	ctx.r5.s64 = ctx.r11.s64 + 20488;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82067020
	ctx.lr = 0x82062800;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82062864
	goto loc_82062864;
loc_82062808:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82062824
	if (!ctx.cr6.eq) goto loc_82062824;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062824;
	sub_820A71E8(ctx, base);
loc_82062824:
	// bl 0x820b5eb8
	ctx.lr = 0x82062828;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82062838;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82062860
	if (ctx.cr6.eq) goto loc_82062860;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,600
	ctx.r6.s64 = 600;
	// addi r5,r11,21016
	ctx.r5.s64 = ctx.r11.s64 + 21016;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82067020
	ctx.lr = 0x82062858;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82062864
	goto loc_82062864;
loc_82062860:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82062864:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82062874;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82062894
	if (!ctx.cr6.eq) goto loc_82062894;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062894;
	sub_820A71E8(ctx, base);
loc_82062894:
	// bl 0x820b5eb8
	ctx.lr = 0x82062898;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820628A8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820628d0
	if (ctx.cr6.eq) goto loc_820628D0;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,602
	ctx.r6.s64 = 602;
	// addi r5,r11,20680
	ctx.r5.s64 = ctx.r11.s64 + 20680;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82067020
	ctx.lr = 0x820628C8;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x820628d4
	goto loc_820628D4;
loc_820628D0:
	// li r4,0
	ctx.r4.s64 = 0;
loc_820628D4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820628E4;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lbz r9,-22601(r29)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// addi r8,r10,10640
	ctx.r8.s64 = ctx.r10.s64 + 10640;
	// stw r28,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r28.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,384(r30)
	REX_STORE_U32(ctx.r30.u32 + 384, ctx.r8.u32);
	// bne cr6,0x82062914
	if (!ctx.cr6.eq) goto loc_82062914;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062914;
	sub_820A71E8(ctx, base);
loc_82062914:
	// bl 0x820b5eb8
	ctx.lr = 0x82062918;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82062928;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82062970
	if (ctx.cr6.eq) goto loc_82062970;
	// lwz r29,4(r28)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8206293C;
	sub_82066F80(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r29,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// li r10,17
	ctx.r10.s64 = 17;
	// addi r9,r11,9460
	ctx.r9.s64 = ctx.r11.s64 + 9460;
	// stw r10,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// bl 0x82067e00
	ctx.lr = 0x8206295C;
	sub_82067E00(ctx, base);
	// lis r8,-21846
	ctx.r8.s64 = -1431699456;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// ori r7,r8,43775
	ctx.r7.u64 = ctx.r8.u64 | 43775;
	// stw r7,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r7.u32);
	// b 0x82062974
	goto loc_82062974;
loc_82062970:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82062974:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82062984;
	sub_82065F78(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
