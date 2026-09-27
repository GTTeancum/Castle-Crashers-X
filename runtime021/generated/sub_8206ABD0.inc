DEFINE_REX_FUNC(sub_8206ABD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x8206ABD8;
	__savegprlr_22(ctx, base);
	// stfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f30.u64);
	// stfd f31,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32218
	ctx.r31.s64 = -2111438848;
	// lis r26,-32215
	ctx.r26.s64 = -2111242240;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r11,-6596(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -6596);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lbz r8,-22601(r26)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// addi r23,r10,-1768
	ctx.r23.s64 = ctx.r10.s64 + -1768;
	// lfs f0,18248(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18248);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r6,12(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// std r6,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f30,f11,f0
	ctx.f30.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// bne cr6,0x8206ac40
	if (!ctx.cr6.eq) goto loc_8206AC40;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206AC40;
	sub_820A71E8(ctx, base);
loc_8206AC40:
	// bl 0x820b5eb8
	ctx.lr = 0x8206AC44;
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
	ctx.lr = 0x8206AC5C;
	sub_8209BDD8(ctx, base);
	// li r24,0
	ctx.r24.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206ac84
	if (ctx.cr6.eq) goto loc_8206AC84;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x8206AC7C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206ac88
	goto loc_8206AC88;
loc_8206AC84:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_8206AC88:
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
	ctx.lr = 0x8206ACA0;
	sub_82065F78(ctx, base);
	// lbz r10,-22601(r26)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8206acc0
	if (!ctx.cr6.eq) goto loc_8206ACC0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206ACC0;
	sub_820A71E8(ctx, base);
loc_8206ACC0:
	// bl 0x820b5eb8
	ctx.lr = 0x8206ACC4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206ACD4;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206acf8
	if (ctx.cr6.eq) goto loc_8206ACF8;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x8206ACF0;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206acfc
	goto loc_8206ACFC;
loc_8206ACF8:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_8206ACFC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206AD0C;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206ad2c
	if (!ctx.cr6.eq) goto loc_8206AD2C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206AD2C;
	sub_820A71E8(ctx, base);
loc_8206AD2C:
	// bl 0x820b5eb8
	ctx.lr = 0x8206AD30;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206AD40;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206ad64
	if (ctx.cr6.eq) goto loc_8206AD64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x8206AD5C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206ad68
	goto loc_8206AD68;
loc_8206AD64:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_8206AD68:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206AD78;
	sub_82065F78(ctx, base);
	// lwz r11,-6596(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -6596);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,576
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 576, ctx.xer);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// bne cr6,0x8206ae00
	if (!ctx.cr6.eq) goto loc_8206AE00;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206ada8
	if (!ctx.cr6.eq) goto loc_8206ADA8;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206ADA8;
	sub_820A71E8(ctx, base);
loc_8206ADA8:
	// bl 0x820b5eb8
	ctx.lr = 0x8206ADAC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206ADBC;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8206ae70
	if (ctx.cr6.eq) goto loc_8206AE70;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18312
	ctx.r4.s64 = ctx.r11.s64 + 18312;
	// bl 0x82053a00
	ctx.lr = 0x8206ADD8;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,2002
	ctx.r6.s64 = 2002;
	// lwz r4,4(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,9924(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9924);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82067bc0
	ctx.lr = 0x8206ADF8;
	sub_82067BC0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206ae74
	goto loc_8206AE74;
loc_8206AE00:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206ae1c
	if (!ctx.cr6.eq) goto loc_8206AE1C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206AE1C;
	sub_820A71E8(ctx, base);
loc_8206AE1C:
	// bl 0x820b5eb8
	ctx.lr = 0x8206AE20;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206AE30;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8206ae70
	if (ctx.cr6.eq) goto loc_8206AE70;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18312
	ctx.r4.s64 = ctx.r11.s64 + 18312;
	// bl 0x82053a00
	ctx.lr = 0x8206AE4C;
	sub_82053A00(ctx, base);
	// li r6,2002
	ctx.r6.s64 = 2002;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r4,4(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x82067bc0
	ctx.lr = 0x8206AE68;
	sub_82067BC0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206ae74
	goto loc_8206AE74;
loc_8206AE70:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_8206AE74:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206AE84;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206aea4
	if (!ctx.cr6.eq) goto loc_8206AEA4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206AEA4;
	sub_820A71E8(ctx, base);
loc_8206AEA4:
	// bl 0x820b5eb8
	ctx.lr = 0x8206AEA8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206AEB8;
	sub_8209BDD8(ctx, base);
	// lis r10,-21846
	ctx.r10.s64 = -1431699456;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// ori r29,r10,43775
	ctx.r29.u64 = ctx.r10.u64 | 43775;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r28,r11,9460
	ctx.r28.s64 = ctx.r11.s64 + 9460;
	// beq cr6,0x8206af00
	if (ctx.cr6.eq) goto loc_8206AF00;
	// lwz r22,4(r27)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8206AEDC;
	sub_82066F80(ctx, base);
	// li r11,17
	ctx.r11.s64 = 17;
	// stw r22,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r22.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x8206AEF4;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// b 0x8206af04
	goto loc_8206AF04;
loc_8206AF00:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_8206AF04:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206AF14;
	sub_82065F78(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lbz r7,-22601(r26)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// li r9,15
	ctx.r9.s64 = 15;
	// addi r8,r10,20768
	ctx.r8.s64 = ctx.r10.s64 + 20768;
	// stw r27,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r27.u32);
	// sth r9,390(r30)
	REX_STORE_U16(ctx.r30.u32 + 390, ctx.r9.u16);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r8,364(r30)
	REX_STORE_U32(ctx.r30.u32 + 364, ctx.r8.u32);
	// bne cr6,0x8206af4c
	if (!ctx.cr6.eq) goto loc_8206AF4C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206AF4C;
	sub_820A71E8(ctx, base);
loc_8206AF4C:
	// bl 0x820b5eb8
	ctx.lr = 0x8206AF50;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206AF60;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8206af94
	if (ctx.cr6.eq) goto loc_8206AF94;
	// lwz r26,4(r27)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8206AF74;
	sub_82066F80(ctx, base);
	// stw r26,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r26.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r24,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r24.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// bl 0x82067e00
	ctx.lr = 0x8206AF88;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// b 0x8206af98
	goto loc_8206AF98;
loc_8206AF94:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_8206AF98:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206AFA8;
	sub_82065F78(ctx, base);
	// lhz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r27,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r27.u32);
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// addi r6,r10,-18992
	ctx.r6.s64 = ctx.r10.s64 + -18992;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r8,255
	ctx.r8.s64 = 255;
	// stw r6,384(r30)
	REX_STORE_U32(ctx.r30.u32 + 384, ctx.r6.u32);
	// lis r5,30583
	ctx.r5.s64 = 2004287488;
	// sth r8,16(r30)
	REX_STORE_U16(ctx.r30.u32 + 16, ctx.r8.u16);
	// lis r4,-1
	ctx.r4.s64 = -65536;
	// ori r3,r5,30719
	ctx.r3.u64 = ctx.r5.u64 | 30719;
	// ori r11,r4,255
	ctx.r11.u64 = ctx.r4.u64 | 255;
	// lwzx r10,r7,r30
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r30.u32);
	// stw r3,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r3.u32);
	// sth r24,8(r30)
	REX_STORE_U16(ctx.r30.u32 + 8, ctx.r24.u16);
	// lwz r9,20(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// stw r11,16(r9)
	REX_STORE_U32(ctx.r9.u32 + 16, ctx.r11.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
