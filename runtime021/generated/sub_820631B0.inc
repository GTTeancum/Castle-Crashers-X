DEFINE_REX_FUNC(sub_820631B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x820631B8;
	__savegprlr_21(ctx, base);
	// stfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f30.u64);
	// stfd f31,-104(r1)
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32215
	ctx.r26.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// addi r23,r11,-1768
	ctx.r23.s64 = ctx.r11.s64 + -1768;
	// li r22,1
	ctx.r22.s64 = 1;
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// sth r22,16(r28)
	REX_STORE_U16(ctx.r28.u32 + 16, ctx.r22.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82063200
	if (!ctx.cr6.eq) goto loc_82063200;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82063200;
	sub_820A71E8(ctx, base);
loc_82063200:
	// bl 0x820b5eb8
	ctx.lr = 0x82063204;
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
	ctx.lr = 0x8206321C;
	sub_8209BDD8(ctx, base);
	// li r24,0
	ctx.r24.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82063244
	if (ctx.cr6.eq) goto loc_82063244;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x8206323C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82063248
	goto loc_82063248;
loc_82063244:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82063248:
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
	ctx.lr = 0x82063260;
	sub_82065F78(ctx, base);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r11,-6596(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6596);
	// lfs f0,18248(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18248);
	ctx.f0.f64 = double(temp.f32);
	// lwz r6,12(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r7,16(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r7,576
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 576, ctx.xer);
	// std r6,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// fmuls f30,f11,f0
	ctx.f30.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// bne cr6,0x8206330c
	if (!ctx.cr6.eq) goto loc_8206330C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820632b4
	if (!ctx.cr6.eq) goto loc_820632B4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820632B4;
	sub_820A71E8(ctx, base);
loc_820632B4:
	// bl 0x820b5eb8
	ctx.lr = 0x820632B8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820632C8;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82063380
	if (ctx.cr6.eq) goto loc_82063380;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18324
	ctx.r4.s64 = ctx.r11.s64 + 18324;
	// bl 0x82053a00
	ctx.lr = 0x820632E4;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,2014
	ctx.r6.s64 = 2014;
	// lwz r4,4(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,9860(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9860);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82067bc0
	ctx.lr = 0x82063304;
	sub_82067BC0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82063384
	goto loc_82063384;
loc_8206330C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82063328
	if (!ctx.cr6.eq) goto loc_82063328;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82063328;
	sub_820A71E8(ctx, base);
loc_82063328:
	// bl 0x820b5eb8
	ctx.lr = 0x8206332C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206333C;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82063380
	if (ctx.cr6.eq) goto loc_82063380;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18324
	ctx.r4.s64 = ctx.r11.s64 + 18324;
	// bl 0x82053a00
	ctx.lr = 0x82063358;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,2014
	ctx.r6.s64 = 2014;
	// lwz r4,4(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,9948(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9948);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82067bc0
	ctx.lr = 0x82063378;
	sub_82067BC0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82063384
	goto loc_82063384;
loc_82063380:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82063384:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82063394;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820633b4
	if (!ctx.cr6.eq) goto loc_820633B4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820633B4;
	sub_820A71E8(ctx, base);
loc_820633B4:
	// bl 0x820b5eb8
	ctx.lr = 0x820633B8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820633C8;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r30,r11,9448
	ctx.r30.s64 = ctx.r11.s64 + 9448;
	// beq cr6,0x82063430
	if (ctx.cr6.eq) goto loc_82063430;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,9484
	ctx.r4.s64 = ctx.r11.s64 + 9484;
	// bl 0x82053a00
	ctx.lr = 0x820633EC;
	sub_82053A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r29,4(r27)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x820633F8;
	sub_82066F80(ctx, base);
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// stw r29,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r24,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r24.u32);
	// bl 0x82053a00
	ctx.lr = 0x82063410;
	sub_82053A00(ctx, base);
	// li r5,2001
	ctx.r5.s64 = 2001;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82067c40
	ctx.lr = 0x82063428;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x82063434
	goto loc_82063434;
loc_82063430:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82063434:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82063444;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82063464
	if (!ctx.cr6.eq) goto loc_82063464;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82063464;
	sub_820A71E8(ctx, base);
loc_82063464:
	// bl 0x820b5eb8
	ctx.lr = 0x82063468;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82063478;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820634e4
	if (ctx.cr6.eq) goto loc_820634E4;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r4,r11,18332
	ctx.r4.s64 = ctx.r11.s64 + 18332;
	// bl 0x82053a00
	ctx.lr = 0x82063494;
	sub_82053A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r29,4(r27)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x820634A0;
	sub_82066F80(ctx, base);
	// addi r4,r1,180
	ctx.r4.s64 = ctx.r1.s64 + 180;
	// stw r29,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r24,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r24.u32);
	// bl 0x82053a00
	ctx.lr = 0x820634B8;
	sub_82053A00(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,2016
	ctx.r5.s64 = 2016;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,9904(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9904);
	ctx.f0.f64 = double(temp.f32);
	// lfs f2,9944(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9944);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f1,f30,f0
	ctx.f1.f64 = double(float(ctx.f30.f64 - ctx.f0.f64));
	// bl 0x82067c40
	ctx.lr = 0x820634DC;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x820634e8
	goto loc_820634E8;
loc_820634E4:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_820634E8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820634F8;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lbz r9,-22601(r26)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// addi r8,r10,16856
	ctx.r8.s64 = ctx.r10.s64 + 16856;
	// stw r27,356(r28)
	REX_STORE_U32(ctx.r28.u32 + 356, ctx.r27.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,384(r28)
	REX_STORE_U32(ctx.r28.u32 + 384, ctx.r8.u32);
	// bne cr6,0x82063528
	if (!ctx.cr6.eq) goto loc_82063528;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82063528;
	sub_820A71E8(ctx, base);
loc_82063528:
	// bl 0x820b5eb8
	ctx.lr = 0x8206352C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206353C;
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
	// beq cr6,0x82063584
	if (ctx.cr6.eq) goto loc_82063584;
	// lwz r21,4(r27)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82063560;
	sub_82066F80(ctx, base);
	// li r11,14
	ctx.r11.s64 = 14;
	// stw r21,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r21.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x82063578;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82063588
	goto loc_82063588;
loc_82063584:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82063588:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82063598;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lbz r5,-22601(r26)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// addi r8,r10,19328
	ctx.r8.s64 = ctx.r10.s64 + 19328;
	// stw r27,356(r28)
	REX_STORE_U32(ctx.r28.u32 + 356, ctx.r27.u32);
	// addi r7,r9,20768
	ctx.r7.s64 = ctx.r9.s64 + 20768;
	// li r6,15
	ctx.r6.s64 = 15;
	// stw r8,372(r28)
	REX_STORE_U32(ctx.r28.u32 + 372, ctx.r8.u32);
	// stw r7,364(r28)
	REX_STORE_U32(ctx.r28.u32 + 364, ctx.r7.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// sth r6,390(r28)
	REX_STORE_U16(ctx.r28.u32 + 390, ctx.r6.u16);
	// bne cr6,0x820635d8
	if (!ctx.cr6.eq) goto loc_820635D8;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820635D8;
	sub_820A71E8(ctx, base);
loc_820635D8:
	// bl 0x820b5eb8
	ctx.lr = 0x820635DC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820635EC;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82063620
	if (ctx.cr6.eq) goto loc_82063620;
	// lwz r27,4(r27)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82063600;
	sub_82066F80(ctx, base);
	// stw r27,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r24,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r24.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// bl 0x82067e00
	ctx.lr = 0x82063614;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82063624
	goto loc_82063624;
loc_82063620:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82063624:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82063634;
	sub_82065F78(ctx, base);
	// stb r22,14(r28)
	REX_STORE_U8(ctx.r28.u32 + 14, ctx.r22.u8);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
