DEFINE_REX_FUNC(sub_8205E7E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f0
	ctx.lr = 0x8205E7E8;
	__savegprlr_18(ctx, base);
	// addi r12,r1,-120
	ctx.r12.s64 = ctx.r1.s64 + -120;
	// bl 0x8212a854
	ctx.lr = 0x8205E7F0;
	__savefpr_27(ctx, base);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// addi r26,r11,-22601
	ctx.r26.s64 = ctx.r11.s64 + -22601;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// lbz r11,-22601(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// addi r18,r10,-1768
	ctx.r18.s64 = ctx.r10.s64 + -1768;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205e82c
	if (!ctx.cr6.eq) goto loc_8205E82C;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205E82C;
	sub_820A71E8(ctx, base);
loc_8205E82C:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E830;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r21,r11,29632
	ctx.r21.s64 = ctx.r11.s64 + 29632;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r10,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205E848;
	sub_8209BDD8(ctx, base);
	// li r22,0
	ctx.r22.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205e864
	if (ctx.cr6.eq) goto loc_8205E864;
	// li r4,390
	ctx.r4.s64 = 390;
	// bl 0x82067778
	ctx.lr = 0x8205E85C;
	sub_82067778(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205e868
	goto loc_8205E868;
loc_8205E864:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205E868:
	// lis r25,-32218
	ctx.r25.s64 = -2111438848;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r23,r11,18236
	ctx.r23.s64 = ctx.r11.s64 + 18236;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r11,-6596(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6596);
	// lfs f2,9652(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9652);
	ctx.f2.f64 = double(temp.f32);
	// lfs f27,12(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 12);
	ctx.f27.f64 = double(temp.f32);
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// std r8,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f27
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f27.f64));
	// bl 0x82065f78
	ctx.lr = 0x8205E8A4;
	sub_82065F78(ctx, base);
	// lbz r7,0(r26)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8205e8c4
	if (!ctx.cr6.eq) goto loc_8205E8C4;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205E8C4;
	sub_820A71E8(ctx, base);
loc_8205E8C4:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E8C8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205E8D8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205e8fc
	if (ctx.cr6.eq) goto loc_8205E8FC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,506
	ctx.r6.s64 = 506;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205E8F4;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205e900
	goto loc_8205E900;
loc_8205E8FC:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205E900:
	// lwz r11,-6596(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6596);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r7,16(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// std r8,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r7,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fmuls f2,f10,f27
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f27.f64));
	// fmuls f1,f9,f27
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f27.f64));
	// bl 0x82065f78
	ctx.lr = 0x8205E93C;
	sub_82065F78(ctx, base);
	// lbz r6,0(r26)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x8205e95c
	if (!ctx.cr6.eq) goto loc_8205E95C;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205E95C;
	sub_820A71E8(ctx, base);
loc_8205E95C:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E960;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205E970;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205e994
	if (ctx.cr6.eq) goto loc_8205E994;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205E98C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205e998
	goto loc_8205E998;
loc_8205E994:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205E998:
	// lwz r11,-6596(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6596);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r6,16(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lfs f0,9868(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9868);
	ctx.f0.f64 = double(temp.f32);
	// lwz r7,12(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// std r6,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r7,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f11
	ctx.f9.f64 = double(ctx.f11.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f8,f27
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f27.f64));
	// fmadds f2,f10,f27,f0
	ctx.f2.f64 = double(float(std::fma(ctx.f10.f64, ctx.f27.f64, ctx.f0.f64)));
	// bl 0x82065f78
	ctx.lr = 0x8205E9DC;
	sub_82065F78(ctx, base);
	// lbz r5,0(r26)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x8205e9f8
	if (!ctx.cr6.eq) goto loc_8205E9F8;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205E9F8;
	sub_820A71E8(ctx, base);
loc_8205E9F8:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E9FC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205EA0C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205ea30
	if (ctx.cr6.eq) goto loc_8205EA30;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,533
	ctx.r6.s64 = 533;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205EA28;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205ea34
	goto loc_8205EA34;
loc_8205EA30:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205EA34:
	// sth r22,44(r4)
	REX_STORE_U16(ctx.r4.u32 + 44, ctx.r22.u16);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,-6596(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6596);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f28,-320(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + -320);
	ctx.f28.f64 = double(temp.f32);
	// stfs f28,36(r4)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r4.u32 + 36, temp.u32);
	// lfs f29,9940(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9940);
	ctx.f29.f64 = double(temp.f32);
	// lfs f31,9536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// lwz r8,16(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r8,576
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 576, ctx.xer);
	// bne cr6,0x8205ea68
	if (!ctx.cr6.eq) goto loc_8205EA68;
	// fmr f0,f29
	ctx.f0.f64 = ctx.f29.f64;
	// b 0x8205ea6c
	goto loc_8205EA6C;
loc_8205EA68:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_8205EA6C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lfs f30,9936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9936);
	ctx.f30.f64 = double(temp.f32);
	// lfs f1,9744(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9744);
	ctx.f1.f64 = double(temp.f32);
	// fadds f2,f0,f30
	ctx.f2.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// bl 0x82065f78
	ctx.lr = 0x8205EA88;
	sub_82065F78(ctx, base);
	// lbz r9,0(r26)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8205eaa8
	if (!ctx.cr6.eq) goto loc_8205EAA8;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205EAA8;
	sub_820A71E8(ctx, base);
loc_8205EAA8:
	// bl 0x820b5eb8
	ctx.lr = 0x8205EAAC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205EABC;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205eae0
	if (ctx.cr6.eq) goto loc_8205EAE0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,507
	ctx.r6.s64 = 507;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205EAD8;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205eae4
	goto loc_8205EAE4;
loc_8205EAE0:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205EAE4:
	// lwz r11,-6596(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6596);
	// li r20,1
	ctx.r20.s64 = 1;
	// stfs f28,36(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r4.u32 + 36, temp.u32);
	// sth r20,44(r4)
	REX_STORE_U16(ctx.r4.u32 + 44, ctx.r20.u16);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,576
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 576, ctx.xer);
	// bne cr6,0x8205eb08
	if (!ctx.cr6.eq) goto loc_8205EB08;
	// fmr f0,f29
	ctx.f0.f64 = ctx.f29.f64;
	// b 0x8205eb0c
	goto loc_8205EB0C;
loc_8205EB08:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_8205EB0C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// fadds f2,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lfs f1,9892(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9892);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82065f78
	ctx.lr = 0x8205EB20;
	sub_82065F78(ctx, base);
	// lwz r11,-6596(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6596);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lbz r7,0(r26)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// li r19,10
	ctx.r19.s64 = 10;
	// li r8,5
	ctx.r8.s64 = 5;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// lwz r6,16(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lfs f0,9932(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9932);
	ctx.f0.f64 = double(temp.f32);
	// stfs f31,404(r27)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r27.u32 + 404, temp.u32);
	// sth r8,394(r27)
	REX_STORE_U16(ctx.r27.u32 + 394, ctx.r8.u16);
	// rlwinm r5,r6,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// sth r19,396(r27)
	REX_STORE_U16(ctx.r27.u32 + 396, ctx.r19.u16);
	// sth r20,398(r27)
	REX_STORE_U16(ctx.r27.u32 + 398, ctx.r20.u16);
	// std r5,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// sth r20,400(r27)
	REX_STORE_U16(ctx.r27.u32 + 400, ctx.r20.u16);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stb r20,392(r27)
	REX_STORE_U8(ctx.r27.u32 + 392, ctx.r20.u8);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f0.f64));
	// stfs f10,408(r27)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r27.u32 + 408, temp.u32);
	// bne cr6,0x8205eb8c
	if (!ctx.cr6.eq) goto loc_8205EB8C;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205EB8C;
	sub_820A71E8(ctx, base);
loc_8205EB8C:
	// bl 0x820b5eb8
	ctx.lr = 0x8205EB90;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205EBA0;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205ebc4
	if (ctx.cr6.eq) goto loc_8205EBC4;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,488
	ctx.r6.s64 = 488;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205EBBC;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205ebc8
	goto loc_8205EBC8;
loc_8205EBC4:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205EBC8:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205EBD8;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205ebf8
	if (!ctx.cr6.eq) goto loc_8205EBF8;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205EBF8;
	sub_820A71E8(ctx, base);
loc_8205EBF8:
	// bl 0x820b5eb8
	ctx.lr = 0x8205EBFC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205EC0C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205ec30
	if (ctx.cr6.eq) goto loc_8205EC30;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,590
	ctx.r6.s64 = 590;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205EC28;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205ec34
	goto loc_8205EC34;
loc_8205EC30:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205EC34:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205EC44;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205ec64
	if (!ctx.cr6.eq) goto loc_8205EC64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205EC64;
	sub_820A71E8(ctx, base);
loc_8205EC64:
	// bl 0x820b5eb8
	ctx.lr = 0x8205EC68;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205EC78;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205ec9c
	if (ctx.cr6.eq) goto loc_8205EC9C;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,612
	ctx.r6.s64 = 612;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205EC94;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205eca0
	goto loc_8205ECA0;
loc_8205EC9C:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205ECA0:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205ECB0;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205ecd0
	if (!ctx.cr6.eq) goto loc_8205ECD0;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205ECD0;
	sub_820A71E8(ctx, base);
loc_8205ECD0:
	// bl 0x820b5eb8
	ctx.lr = 0x8205ECD4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205ECE4;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205ed08
	if (ctx.cr6.eq) goto loc_8205ED08;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,611
	ctx.r6.s64 = 611;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205ED00;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205ed0c
	goto loc_8205ED0C;
loc_8205ED08:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205ED0C:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205ED1C;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205ed3c
	if (!ctx.cr6.eq) goto loc_8205ED3C;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205ED3C;
	sub_820A71E8(ctx, base);
loc_8205ED3C:
	// bl 0x820b5eb8
	ctx.lr = 0x8205ED40;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205ED50;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205ed74
	if (ctx.cr6.eq) goto loc_8205ED74;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,390
	ctx.r6.s64 = 390;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205ED6C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205ed78
	goto loc_8205ED78;
loc_8205ED74:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205ED78:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205ED88;
	sub_82065F78(ctx, base);
	// li r30,9
	ctx.r30.s64 = 9;
loc_8205ED8C:
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205edac
	if (!ctx.cr6.eq) goto loc_8205EDAC;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205EDAC;
	sub_820A71E8(ctx, base);
loc_8205EDAC:
	// bl 0x820b5eb8
	ctx.lr = 0x8205EDB0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205EDC0;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205ede4
	if (ctx.cr6.eq) goto loc_8205EDE4;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205EDDC;
	sub_82067020(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8205ede8
	goto loc_8205EDE8;
loc_8205EDE4:
	// mr r31,r22
	ctx.r31.u64 = ctx.r22.u64;
loc_8205EDE8:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205EDFC;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// sth r22,44(r31)
	REX_STORE_U16(ctx.r31.u32 + 44, ctx.r22.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205ee20
	if (!ctx.cr6.eq) goto loc_8205EE20;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205EE20;
	sub_820A71E8(ctx, base);
loc_8205EE20:
	// bl 0x820b5eb8
	ctx.lr = 0x8205EE24;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205EE34;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205ee5c
	if (ctx.cr6.eq) goto loc_8205EE5C;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,6376
	ctx.r5.s64 = ctx.r11.s64 + 6376;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205EE54;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205ee60
	goto loc_8205EE60;
loc_8205EE5C:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205EE60:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205EE70;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205ee90
	if (!ctx.cr6.eq) goto loc_8205EE90;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205EE90;
	sub_820A71E8(ctx, base);
loc_8205EE90:
	// bl 0x820b5eb8
	ctx.lr = 0x8205EE94;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205EEA4;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205eec8
	if (ctx.cr6.eq) goto loc_8205EEC8;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205EEC0;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205eecc
	goto loc_8205EECC;
loc_8205EEC8:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205EECC:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205EEDC;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205eefc
	if (!ctx.cr6.eq) goto loc_8205EEFC;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205EEFC;
	sub_820A71E8(ctx, base);
loc_8205EEFC:
	// bl 0x820b5eb8
	ctx.lr = 0x8205EF00;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205EF10;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205ef34
	if (ctx.cr6.eq) goto loc_8205EF34;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205EF2C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205ef38
	goto loc_8205EF38;
loc_8205EF34:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205EF38:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205EF48;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205ef68
	if (!ctx.cr6.eq) goto loc_8205EF68;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205EF68;
	sub_820A71E8(ctx, base);
loc_8205EF68:
	// bl 0x820b5eb8
	ctx.lr = 0x8205EF6C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205EF7C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205efa0
	if (ctx.cr6.eq) goto loc_8205EFA0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205EF98;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205efa4
	goto loc_8205EFA4;
loc_8205EFA0:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205EFA4:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205EFB4;
	sub_82065F78(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8205ed8c
	if (!ctx.cr0.eq) goto loc_8205ED8C;
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205efdc
	if (!ctx.cr6.eq) goto loc_8205EFDC;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205EFDC;
	sub_820A71E8(ctx, base);
loc_8205EFDC:
	// bl 0x820b5eb8
	ctx.lr = 0x8205EFE0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205EFF0;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205f014
	if (ctx.cr6.eq) goto loc_8205F014;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,338
	ctx.r6.s64 = 338;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205F00C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205f018
	goto loc_8205F018;
loc_8205F014:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205F018:
	// lwz r11,-6596(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6596);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f30,0(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lfs f29,9928(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9928);
	ctx.f29.f64 = double(temp.f32);
	// std r8,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmsubs f1,f12,f27,f29
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f27.f64, -ctx.f29.f64)));
	// bl 0x82065f78
	ctx.lr = 0x8205F04C;
	sub_82065F78(ctx, base);
	// lbz r7,0(r26)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8205f06c
	if (!ctx.cr6.eq) goto loc_8205F06C;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205F06C;
	sub_820A71E8(ctx, base);
loc_8205F06C:
	// bl 0x820b5eb8
	ctx.lr = 0x8205F070;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205F080;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205f0a4
	if (ctx.cr6.eq) goto loc_8205F0A4;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,494
	ctx.r6.s64 = 494;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205F09C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205f0a8
	goto loc_8205F0A8;
loc_8205F0A4:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205F0A8:
	// lwz r11,-6596(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6596);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f30.f64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmadds f1,f12,f27,f29
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f27.f64, ctx.f29.f64)));
	// bl 0x82065f78
	ctx.lr = 0x8205F0D0;
	sub_82065F78(ctx, base);
	// lwz r11,-6596(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6596);
	// li r28,48
	ctx.r28.s64 = 48;
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r9,576
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 576, ctx.xer);
	// beq cr6,0x8205f0e8
	if (ctx.cr6.eq) goto loc_8205F0E8;
	// mr r28,r22
	ctx.r28.u64 = ctx.r22.u64;
loc_8205F0E8:
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205f108
	if (!ctx.cr6.eq) goto loc_8205F108;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205F108;
	sub_820A71E8(ctx, base);
loc_8205F108:
	// bl 0x820b5eb8
	ctx.lr = 0x8205F10C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205F11C;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r29,r11,9448
	ctx.r29.s64 = ctx.r11.s64 + 9448;
	// beq cr6,0x8205f21c
	if (ctx.cr6.eq) goto loc_8205F21C;
	// lwz r11,-6596(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6596);
	// li r30,48
	ctx.r30.s64 = 48;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,576
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 576, ctx.xer);
	// beq cr6,0x8205f148
	if (ctx.cr6.eq) goto loc_8205F148;
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
loc_8205F148:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// addi r9,r11,9472
	ctx.r9.s64 = ctx.r11.s64 + 9472;
	// li r8,4
	ctx.r8.s64 = 4;
	// addi r7,r1,100
	ctx.r7.s64 = ctx.r1.s64 + 100;
	// lbz r6,9472(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 9472);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// lbz r5,1(r9)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbz r4,2(r9)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r9.u32 + 2);
	// lbz r11,3(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 3);
	// stb r6,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r6.u8);
	// stb r5,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r5.u8);
	// stb r4,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, ctx.r4.u8);
	// stb r11,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, ctx.r11.u8);
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// stbx r22,r10,r7
	REX_STORE_U8(ctx.r10.u32 + ctx.r7.u32, ctx.r22.u8);
	// lwz r25,4(r24)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205F194;
	sub_82066F80(ctx, base);
	// addi r11,r1,100
	ctx.r11.s64 = ctx.r1.s64 + 100;
	// stw r25,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r25.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// stw r22,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r22.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8205F1A8:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8205f1a8
	if (!ctx.cr6.eq) goto loc_8205F1A8;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r1,180
	ctx.r3.s64 = ctx.r1.s64 + 180;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// stw r11,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r11.u32);
	// bl 0x82129a70
	ctx.lr = 0x8205F1D8;
	sub_82129A70(ctx, base);
	// extsw r10,r30
	ctx.r10.s64 = ctx.r30.s32;
	// lwz r8,176(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r9,r1,180
	ctx.r9.s64 = ctx.r1.s64 + 180;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfs f0,64(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// li r5,2003
	ctx.r5.s64 = 2003;
	// lfs f1,60(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 60);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r22,r8,r9
	REX_STORE_U8(ctx.r8.u32 + ctx.r9.u32, ctx.r22.u8);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fadds f2,f11,f0
	ctx.f2.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// bl 0x82067c40
	ctx.lr = 0x8205F214;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x8205f220
	goto loc_8205F220;
loc_8205F21C:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205F220:
	// extsw r11,r28
	ctx.r11.s64 = ctx.r28.s32;
	// lfs f0,64(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lfs f1,60(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 60);
	ctx.f1.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fadds f2,f11,f0
	ctx.f2.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// bl 0x82065f78
	ctx.lr = 0x8205F248;
	sub_82065F78(ctx, base);
	// lbz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8205f268
	if (!ctx.cr6.eq) goto loc_8205F268;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205F268;
	sub_820A71E8(ctx, base);
loc_8205F268:
	// bl 0x820b5eb8
	ctx.lr = 0x8205F26C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205F27C;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8205f33c
	if (ctx.cr6.eq) goto loc_8205F33C;
	// li r9,6
	ctx.r9.s64 = 6;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// addi r11,r11,9484
	ctx.r11.s64 = ctx.r11.s64 + 9484;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8205F2A0:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8205f2a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8205F2A0;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r22,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r22.u8);
	// lwz r30,4(r24)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205F2CC;
	sub_82066F80(ctx, base);
	// addi r11,r1,100
	ctx.r11.s64 = ctx.r1.s64 + 100;
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// stw r22,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r22.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8205F2E0:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8205f2e0
	if (!ctx.cr6.eq) goto loc_8205F2E0;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r1,180
	ctx.r3.s64 = ctx.r1.s64 + 180;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// stw r11,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r11.u32);
	// bl 0x82129a70
	ctx.lr = 0x8205F310;
	sub_82129A70(ctx, base);
	// lwz r9,176(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r10,r1,180
	ctx.r10.s64 = ctx.r1.s64 + 180;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// li r5,2001
	ctx.r5.s64 = 2001;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r22,r9,r10
	REX_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r22.u8);
	// bl 0x82067c40
	ctx.lr = 0x8205F334;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x8205f340
	goto loc_8205F340;
loc_8205F33C:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205F340:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205F350;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205f370
	if (!ctx.cr6.eq) goto loc_8205F370;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205F370;
	sub_820A71E8(ctx, base);
loc_8205F370:
	// bl 0x820b5eb8
	ctx.lr = 0x8205F374;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205F384;
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
	// beq cr6,0x8205f3cc
	if (ctx.cr6.eq) goto loc_8205F3CC;
	// lwz r28,4(r24)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205F3A8;
	sub_82066F80(ctx, base);
	// li r11,13
	ctx.r11.s64 = 13;
	// stw r28,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r28.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x8205F3C0;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8205f3d0
	goto loc_8205F3D0;
loc_8205F3CC:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205F3D0:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205F3E0;
	sub_82065F78(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lbz r9,0(r26)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// addi r8,r10,20768
	ctx.r8.s64 = ctx.r10.s64 + 20768;
	// sth r19,390(r27)
	REX_STORE_U16(ctx.r27.u32 + 390, ctx.r19.u16);
	// stw r24,356(r27)
	REX_STORE_U32(ctx.r27.u32 + 356, ctx.r24.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,364(r27)
	REX_STORE_U32(ctx.r27.u32 + 364, ctx.r8.u32);
	// bne cr6,0x8205f414
	if (!ctx.cr6.eq) goto loc_8205F414;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205F414;
	sub_820A71E8(ctx, base);
loc_8205F414:
	// bl 0x820b5eb8
	ctx.lr = 0x8205F418;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205F428;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8205f460
	if (ctx.cr6.eq) goto loc_8205F460;
	// lwz r28,4(r24)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205F43C;
	sub_82066F80(ctx, base);
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r28,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r28.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x8205F454;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8205f464
	goto loc_8205F464;
loc_8205F460:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205F464:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205F474;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lbz r9,0(r26)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// addi r8,r10,5400
	ctx.r8.s64 = ctx.r10.s64 + 5400;
	// stw r24,356(r27)
	REX_STORE_U32(ctx.r27.u32 + 356, ctx.r24.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,372(r27)
	REX_STORE_U32(ctx.r27.u32 + 372, ctx.r8.u32);
	// bne cr6,0x8205f4a4
	if (!ctx.cr6.eq) goto loc_8205F4A4;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205F4A4;
	sub_820A71E8(ctx, base);
loc_8205F4A4:
	// bl 0x820b5eb8
	ctx.lr = 0x8205F4A8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205F4B8;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8205f4ec
	if (ctx.cr6.eq) goto loc_8205F4EC;
	// lwz r28,4(r24)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205F4CC;
	sub_82066F80(ctx, base);
	// stw r28,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r20,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r20.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// bl 0x82067e00
	ctx.lr = 0x8205F4E0;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8205f4f0
	goto loc_8205F4F0;
loc_8205F4EC:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205F4F0:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205F500;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lbz r9,0(r26)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// addi r8,r10,5216
	ctx.r8.s64 = ctx.r10.s64 + 5216;
	// stw r24,356(r27)
	REX_STORE_U32(ctx.r27.u32 + 356, ctx.r24.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,368(r27)
	REX_STORE_U32(ctx.r27.u32 + 368, ctx.r8.u32);
	// bne cr6,0x8205f530
	if (!ctx.cr6.eq) goto loc_8205F530;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205F530;
	sub_820A71E8(ctx, base);
loc_8205F530:
	// bl 0x820b5eb8
	ctx.lr = 0x8205F534;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205F544;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8205f57c
	if (ctx.cr6.eq) goto loc_8205F57C;
	// lwz r28,4(r24)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205F558;
	sub_82066F80(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r28,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r28.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x8205F570;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8205f580
	goto loc_8205F580;
loc_8205F57C:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205F580:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205F590;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lbz r9,0(r26)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// addi r8,r10,5592
	ctx.r8.s64 = ctx.r10.s64 + 5592;
	// stw r24,356(r27)
	REX_STORE_U32(ctx.r27.u32 + 356, ctx.r24.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,380(r27)
	REX_STORE_U32(ctx.r27.u32 + 380, ctx.r8.u32);
	// bne cr6,0x8205f5c0
	if (!ctx.cr6.eq) goto loc_8205F5C0;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205F5C0;
	sub_820A71E8(ctx, base);
loc_8205F5C0:
	// bl 0x820b5eb8
	ctx.lr = 0x8205F5C4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205F5D4;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8205f60c
	if (ctx.cr6.eq) goto loc_8205F60C;
	// lwz r28,4(r24)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205F5E8;
	sub_82066F80(ctx, base);
	// li r11,11
	ctx.r11.s64 = 11;
	// stw r28,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r28.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x8205F600;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8205f610
	goto loc_8205F610;
loc_8205F60C:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205F610:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205F620;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lbz r9,0(r26)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// addi r8,r10,5984
	ctx.r8.s64 = ctx.r10.s64 + 5984;
	// stw r24,356(r27)
	REX_STORE_U32(ctx.r27.u32 + 356, ctx.r24.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,376(r27)
	REX_STORE_U32(ctx.r27.u32 + 376, ctx.r8.u32);
	// bne cr6,0x8205f650
	if (!ctx.cr6.eq) goto loc_8205F650;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205F650;
	sub_820A71E8(ctx, base);
loc_8205F650:
	// bl 0x820b5eb8
	ctx.lr = 0x8205F654;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205F664;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8205f698
	if (ctx.cr6.eq) goto loc_8205F698;
	// lwz r28,4(r24)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205F678;
	sub_82066F80(ctx, base);
	// stw r28,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r19,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r19.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// bl 0x82067e00
	ctx.lr = 0x8205F68C;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8205f69c
	goto loc_8205F69C;
loc_8205F698:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205F69C:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205F6AC;
	sub_82065F78(ctx, base);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r10,21
	ctx.r10.s64 = 21;
	// stw r24,356(r27)
	REX_STORE_U32(ctx.r27.u32 + 356, ctx.r24.u32);
	// addi r9,r11,1976
	ctx.r9.s64 = ctx.r11.s64 + 1976;
	// stb r20,14(r27)
	REX_STORE_U8(ctx.r27.u32 + 14, ctx.r20.u8);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// sth r10,16(r27)
	REX_STORE_U16(ctx.r27.u32 + 16, ctx.r10.u16);
	// stw r9,384(r27)
	REX_STORE_U32(ctx.r27.u32 + 384, ctx.r9.u32);
	// stb r11,-61(r26)
	REX_STORE_U8(ctx.r26.u32 + -61, ctx.r11.u8);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// addi r12,r1,-120
	ctx.r12.s64 = ctx.r1.s64 + -120;
	// bl 0x8212a8a0
	ctx.lr = 0x8205F6DC;
	__restfpr_27(ctx, base);
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
}
