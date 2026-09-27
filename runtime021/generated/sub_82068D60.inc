DEFINE_REX_FUNC(sub_82068D60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x82068D68;
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
	// bne cr6,0x82068dac
	if (!ctx.cr6.eq) goto loc_82068DAC;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82068DAC;
	sub_820A71E8(ctx, base);
loc_82068DAC:
	// bl 0x820b5eb8
	ctx.lr = 0x82068DB0;
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
	ctx.lr = 0x82068DC8;
	sub_8209BDD8(ctx, base);
	// li r25,0
	ctx.r25.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82068de4
	if (ctx.cr6.eq) goto loc_82068DE4;
	// li r4,582
	ctx.r4.s64 = 582;
	// bl 0x82067778
	ctx.lr = 0x82068DDC;
	sub_82067778(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82068de8
	goto loc_82068DE8;
loc_82068DE4:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82068DE8:
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
	ctx.lr = 0x82068E00;
	sub_82065F78(ctx, base);
	// lbz r10,-22601(r26)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82068e20
	if (!ctx.cr6.eq) goto loc_82068E20;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82068E20;
	sub_820A71E8(ctx, base);
loc_82068E20:
	// bl 0x820b5eb8
	ctx.lr = 0x82068E24;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068E34;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82068e5c
	if (ctx.cr6.eq) goto loc_82068E5C;
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
	ctx.lr = 0x82068E54;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82068e60
	goto loc_82068E60;
loc_82068E5C:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82068E60:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82068E70;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82068e90
	if (!ctx.cr6.eq) goto loc_82068E90;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82068E90;
	sub_820A71E8(ctx, base);
loc_82068E90:
	// bl 0x820b5eb8
	ctx.lr = 0x82068E94;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068EA4;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82068ecc
	if (ctx.cr6.eq) goto loc_82068ECC;
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
	ctx.lr = 0x82068EC4;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82068ed0
	goto loc_82068ED0;
loc_82068ECC:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82068ED0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82068EE0;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82068f00
	if (!ctx.cr6.eq) goto loc_82068F00;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82068F00;
	sub_820A71E8(ctx, base);
loc_82068F00:
	// bl 0x820b5eb8
	ctx.lr = 0x82068F04;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068F14;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82068f3c
	if (ctx.cr6.eq) goto loc_82068F3C;
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
	ctx.lr = 0x82068F34;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82068f40
	goto loc_82068F40;
loc_82068F3C:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82068F40:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82068F50;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82068f70
	if (!ctx.cr6.eq) goto loc_82068F70;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82068F70;
	sub_820A71E8(ctx, base);
loc_82068F70:
	// bl 0x820b5eb8
	ctx.lr = 0x82068F74;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82068F84;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82068fac
	if (ctx.cr6.eq) goto loc_82068FAC;
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
	ctx.lr = 0x82068FA4;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82068fb0
	goto loc_82068FB0;
loc_82068FAC:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82068FB0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82068FC0;
	sub_82065F78(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f30,9920(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9920);
	ctx.f30.f64 = double(temp.f32);
	// lwz r11,-6596(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// lbz r9,9(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 9);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82068fe4
	if (!ctx.cr6.eq) goto loc_82068FE4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f30,9916(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9916);
	ctx.f30.f64 = double(temp.f32);
loc_82068FE4:
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82069004
	if (!ctx.cr6.eq) goto loc_82069004;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82069004;
	sub_820A71E8(ctx, base);
loc_82069004:
	// bl 0x820b5eb8
	ctx.lr = 0x82069008;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82069018;
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
	// beq cr6,0x82069088
	if (ctx.cr6.eq) goto loc_82069088;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82053a00
	ctx.lr = 0x82069040;
	sub_82053A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r22,4(r27)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8206904C;
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
	ctx.lr = 0x82069064;
	sub_82053A00(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r5,2005
	ctx.r5.s64 = 2005;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,9912(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9912);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82067c40
	ctx.lr = 0x82069080;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x8206908c
	goto loc_8206908C;
loc_82069088:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_8206908C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206909C;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820690bc
	if (!ctx.cr6.eq) goto loc_820690BC;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820690BC;
	sub_820A71E8(ctx, base);
loc_820690BC:
	// bl 0x820b5eb8
	ctx.lr = 0x820690C0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820690D0;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82069130
	if (ctx.cr6.eq) goto loc_82069130;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82053a00
	ctx.lr = 0x820690E8;
	sub_82053A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r22,4(r27)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x820690F4;
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
	ctx.lr = 0x8206910C;
	sub_82053A00(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r5,2006
	ctx.r5.s64 = 2006;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,9908(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9908);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82067c40
	ctx.lr = 0x82069128;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x82069134
	goto loc_82069134;
loc_82069130:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82069134:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82069144;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82069164
	if (!ctx.cr6.eq) goto loc_82069164;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82069164;
	sub_820A71E8(ctx, base);
loc_82069164:
	// bl 0x820b5eb8
	ctx.lr = 0x82069168;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82069178;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820691d8
	if (ctx.cr6.eq) goto loc_820691D8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82053a00
	ctx.lr = 0x82069190;
	sub_82053A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r22,4(r27)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8206919C;
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
	ctx.lr = 0x820691B4;
	sub_82053A00(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r5,2007
	ctx.r5.s64 = 2007;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,9904(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9904);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82067c40
	ctx.lr = 0x820691D0;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x820691dc
	goto loc_820691DC;
loc_820691D8:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_820691DC:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820691EC;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206920c
	if (!ctx.cr6.eq) goto loc_8206920C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206920C;
	sub_820A71E8(ctx, base);
loc_8206920C:
	// bl 0x820b5eb8
	ctx.lr = 0x82069210;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82069220;
	sub_8209BDD8(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// lfs f29,9900(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9900);
	ctx.f29.f64 = double(temp.f32);
	// beq cr6,0x82069284
	if (ctx.cr6.eq) goto loc_82069284;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82053a00
	ctx.lr = 0x82069240;
	sub_82053A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r30,4(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8206924C;
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
	ctx.lr = 0x82069264;
	sub_82053A00(ctx, base);
	// li r5,2008
	ctx.r5.s64 = 2008;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f29.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x82067c40
	ctx.lr = 0x8206927C;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x82069288
	goto loc_82069288;
loc_82069284:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82069288:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82069298;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820692b8
	if (!ctx.cr6.eq) goto loc_820692B8;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820692B8;
	sub_820A71E8(ctx, base);
loc_820692B8:
	// bl 0x820b5eb8
	ctx.lr = 0x820692BC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820692CC;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82069334
	if (ctx.cr6.eq) goto loc_82069334;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r4,r11,-10180
	ctx.r4.s64 = ctx.r11.s64 + -10180;
	// bl 0x82053a00
	ctx.lr = 0x820692E8;
	sub_82053A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r30,4(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x820692F4;
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
	ctx.lr = 0x8206930C;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,2017
	ctx.r5.s64 = 2017;
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f29.f64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,9896(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9896);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f30,f0
	ctx.f1.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// bl 0x82067c40
	ctx.lr = 0x8206932C;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x82069338
	goto loc_82069338;
loc_82069334:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82069338:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82069348;
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
	// bne cr6,0x820693b8
	if (!ctx.cr6.eq) goto loc_820693B8;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820693B8;
	sub_820A71E8(ctx, base);
loc_820693B8:
	// bl 0x820b5eb8
	ctx.lr = 0x820693BC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820693CC;
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
	// beq cr6,0x82069414
	if (ctx.cr6.eq) goto loc_82069414;
	// lwz r22,4(r27)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x820693F0;
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
	ctx.lr = 0x82069408;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82069418
	goto loc_82069418;
loc_82069414:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82069418:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82069428;
	sub_82065F78(ctx, base);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lbz r7,-22601(r26)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// li r9,26
	ctx.r9.s64 = 26;
	// addi r8,r10,-23136
	ctx.r8.s64 = ctx.r10.s64 + -23136;
	// stw r27,356(r28)
	REX_STORE_U32(ctx.r28.u32 + 356, ctx.r27.u32);
	// sth r9,390(r28)
	REX_STORE_U16(ctx.r28.u32 + 390, ctx.r9.u16);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r8,364(r28)
	REX_STORE_U32(ctx.r28.u32 + 364, ctx.r8.u32);
	// bne cr6,0x82069460
	if (!ctx.cr6.eq) goto loc_82069460;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82069460;
	sub_820A71E8(ctx, base);
loc_82069460:
	// bl 0x820b5eb8
	ctx.lr = 0x82069464;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82069474;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820694ac
	if (ctx.cr6.eq) goto loc_820694AC;
	// lwz r22,4(r27)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82069488;
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
	ctx.lr = 0x820694A0;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x820694b0
	goto loc_820694B0;
loc_820694AC:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_820694B0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820694C0;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820694e0
	if (!ctx.cr6.eq) goto loc_820694E0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820694E0;
	sub_820A71E8(ctx, base);
loc_820694E0:
	// bl 0x820b5eb8
	ctx.lr = 0x820694E4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820694F4;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8206952c
	if (ctx.cr6.eq) goto loc_8206952C;
	// lwz r26,4(r27)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82069508;
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
	ctx.lr = 0x82069520;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82069530
	goto loc_82069530;
loc_8206952C:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82069530:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82069540;
	sub_82065F78(ctx, base);
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r27,356(r28)
	REX_STORE_U32(ctx.r28.u32 + 356, ctx.r27.u32);
	// addi r9,r11,-22008
	ctx.r9.s64 = ctx.r11.s64 + -22008;
	// addi r8,r10,-24768
	ctx.r8.s64 = ctx.r10.s64 + -24768;
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
