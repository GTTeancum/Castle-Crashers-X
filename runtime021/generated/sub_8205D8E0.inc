DEFINE_REX_FUNC(sub_8205D8E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f0
	ctx.lr = 0x8205D8E8;
	__savegprlr_18(ctx, base);
	// addi r12,r1,-120
	ctx.r12.s64 = ctx.r1.s64 + -120;
	// bl 0x8212a854
	ctx.lr = 0x8205D8F0;
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
	// bne cr6,0x8205d92c
	if (!ctx.cr6.eq) goto loc_8205D92C;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205D92C;
	sub_820A71E8(ctx, base);
loc_8205D92C:
	// bl 0x820b5eb8
	ctx.lr = 0x8205D930;
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
	ctx.lr = 0x8205D948;
	sub_8209BDD8(ctx, base);
	// li r22,0
	ctx.r22.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205d964
	if (ctx.cr6.eq) goto loc_8205D964;
	// li r4,382
	ctx.r4.s64 = 382;
	// bl 0x82067778
	ctx.lr = 0x8205D95C;
	sub_82067778(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205d968
	goto loc_8205D968;
loc_8205D964:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205D968:
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
	ctx.lr = 0x8205D9A4;
	sub_82065F78(ctx, base);
	// lbz r7,0(r26)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8205d9c4
	if (!ctx.cr6.eq) goto loc_8205D9C4;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205D9C4;
	sub_820A71E8(ctx, base);
loc_8205D9C4:
	// bl 0x820b5eb8
	ctx.lr = 0x8205D9C8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205D9D8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205d9fc
	if (ctx.cr6.eq) goto loc_8205D9FC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,506
	ctx.r6.s64 = 506;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205D9F4;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205da00
	goto loc_8205DA00;
loc_8205D9FC:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205DA00:
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
	ctx.lr = 0x8205DA3C;
	sub_82065F78(ctx, base);
	// lbz r6,0(r26)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x8205da5c
	if (!ctx.cr6.eq) goto loc_8205DA5C;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205DA5C;
	sub_820A71E8(ctx, base);
loc_8205DA5C:
	// bl 0x820b5eb8
	ctx.lr = 0x8205DA60;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205DA70;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205da94
	if (ctx.cr6.eq) goto loc_8205DA94;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205DA8C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205da98
	goto loc_8205DA98;
loc_8205DA94:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205DA98:
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
	ctx.lr = 0x8205DADC;
	sub_82065F78(ctx, base);
	// lbz r5,0(r26)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x8205daf8
	if (!ctx.cr6.eq) goto loc_8205DAF8;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205DAF8;
	sub_820A71E8(ctx, base);
loc_8205DAF8:
	// bl 0x820b5eb8
	ctx.lr = 0x8205DAFC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205DB0C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205db30
	if (ctx.cr6.eq) goto loc_8205DB30;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,533
	ctx.r6.s64 = 533;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205DB28;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205db34
	goto loc_8205DB34;
loc_8205DB30:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205DB34:
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
	// bne cr6,0x8205db68
	if (!ctx.cr6.eq) goto loc_8205DB68;
	// fmr f0,f29
	ctx.f0.f64 = ctx.f29.f64;
	// b 0x8205db6c
	goto loc_8205DB6C;
loc_8205DB68:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_8205DB6C:
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
	ctx.lr = 0x8205DB88;
	sub_82065F78(ctx, base);
	// lbz r9,0(r26)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8205dba8
	if (!ctx.cr6.eq) goto loc_8205DBA8;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205DBA8;
	sub_820A71E8(ctx, base);
loc_8205DBA8:
	// bl 0x820b5eb8
	ctx.lr = 0x8205DBAC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205DBBC;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205dbe0
	if (ctx.cr6.eq) goto loc_8205DBE0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,507
	ctx.r6.s64 = 507;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205DBD8;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205dbe4
	goto loc_8205DBE4;
loc_8205DBE0:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205DBE4:
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
	// bne cr6,0x8205dc08
	if (!ctx.cr6.eq) goto loc_8205DC08;
	// fmr f0,f29
	ctx.f0.f64 = ctx.f29.f64;
	// b 0x8205dc0c
	goto loc_8205DC0C;
loc_8205DC08:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_8205DC0C:
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
	ctx.lr = 0x8205DC20;
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
	// bne cr6,0x8205dc8c
	if (!ctx.cr6.eq) goto loc_8205DC8C;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205DC8C;
	sub_820A71E8(ctx, base);
loc_8205DC8C:
	// bl 0x820b5eb8
	ctx.lr = 0x8205DC90;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205DCA0;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205dcc4
	if (ctx.cr6.eq) goto loc_8205DCC4;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,488
	ctx.r6.s64 = 488;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205DCBC;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205dcc8
	goto loc_8205DCC8;
loc_8205DCC4:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205DCC8:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205DCD8;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205dcf8
	if (!ctx.cr6.eq) goto loc_8205DCF8;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205DCF8;
	sub_820A71E8(ctx, base);
loc_8205DCF8:
	// bl 0x820b5eb8
	ctx.lr = 0x8205DCFC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205DD0C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205dd30
	if (ctx.cr6.eq) goto loc_8205DD30;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,590
	ctx.r6.s64 = 590;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205DD28;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205dd34
	goto loc_8205DD34;
loc_8205DD30:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205DD34:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205DD44;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205dd64
	if (!ctx.cr6.eq) goto loc_8205DD64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205DD64;
	sub_820A71E8(ctx, base);
loc_8205DD64:
	// bl 0x820b5eb8
	ctx.lr = 0x8205DD68;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205DD78;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205dd9c
	if (ctx.cr6.eq) goto loc_8205DD9C;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,92
	ctx.r6.s64 = 92;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205DD94;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205dda0
	goto loc_8205DDA0;
loc_8205DD9C:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205DDA0:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205DDB0;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205ddd0
	if (!ctx.cr6.eq) goto loc_8205DDD0;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205DDD0;
	sub_820A71E8(ctx, base);
loc_8205DDD0:
	// bl 0x820b5eb8
	ctx.lr = 0x8205DDD4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205DDE4;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205de08
	if (ctx.cr6.eq) goto loc_8205DE08;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,486
	ctx.r6.s64 = 486;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205DE00;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205de0c
	goto loc_8205DE0C;
loc_8205DE08:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205DE0C:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205DE1C;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205de3c
	if (!ctx.cr6.eq) goto loc_8205DE3C;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205DE3C;
	sub_820A71E8(ctx, base);
loc_8205DE3C:
	// bl 0x820b5eb8
	ctx.lr = 0x8205DE40;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205DE50;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205de74
	if (ctx.cr6.eq) goto loc_8205DE74;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,91
	ctx.r6.s64 = 91;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205DE6C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205de78
	goto loc_8205DE78;
loc_8205DE74:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205DE78:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205DE88;
	sub_82065F78(ctx, base);
	// li r30,9
	ctx.r30.s64 = 9;
loc_8205DE8C:
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205deac
	if (!ctx.cr6.eq) goto loc_8205DEAC;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205DEAC;
	sub_820A71E8(ctx, base);
loc_8205DEAC:
	// bl 0x820b5eb8
	ctx.lr = 0x8205DEB0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205DEC0;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205dee4
	if (ctx.cr6.eq) goto loc_8205DEE4;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205DEDC;
	sub_82067020(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8205dee8
	goto loc_8205DEE8;
loc_8205DEE4:
	// mr r31,r22
	ctx.r31.u64 = ctx.r22.u64;
loc_8205DEE8:
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
	ctx.lr = 0x8205DEFC;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// sth r22,44(r31)
	REX_STORE_U16(ctx.r31.u32 + 44, ctx.r22.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205df20
	if (!ctx.cr6.eq) goto loc_8205DF20;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205DF20;
	sub_820A71E8(ctx, base);
loc_8205DF20:
	// bl 0x820b5eb8
	ctx.lr = 0x8205DF24;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205DF34;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205df5c
	if (ctx.cr6.eq) goto loc_8205DF5C;
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
	ctx.lr = 0x8205DF54;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205df60
	goto loc_8205DF60;
loc_8205DF5C:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205DF60:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205DF70;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205df90
	if (!ctx.cr6.eq) goto loc_8205DF90;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205DF90;
	sub_820A71E8(ctx, base);
loc_8205DF90:
	// bl 0x820b5eb8
	ctx.lr = 0x8205DF94;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205DFA4;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205dfc8
	if (ctx.cr6.eq) goto loc_8205DFC8;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205DFC0;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205dfcc
	goto loc_8205DFCC;
loc_8205DFC8:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205DFCC:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205DFDC;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205dffc
	if (!ctx.cr6.eq) goto loc_8205DFFC;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205DFFC;
	sub_820A71E8(ctx, base);
loc_8205DFFC:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E000;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205E010;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205e034
	if (ctx.cr6.eq) goto loc_8205E034;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205E02C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205e038
	goto loc_8205E038;
loc_8205E034:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205E038:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205E048;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205e068
	if (!ctx.cr6.eq) goto loc_8205E068;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205E068;
	sub_820A71E8(ctx, base);
loc_8205E068:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E06C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205E07C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205e0a0
	if (ctx.cr6.eq) goto loc_8205E0A0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205E098;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205e0a4
	goto loc_8205E0A4;
loc_8205E0A0:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205E0A4:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205E0B4;
	sub_82065F78(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8205de8c
	if (!ctx.cr0.eq) goto loc_8205DE8C;
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205e0dc
	if (!ctx.cr6.eq) goto loc_8205E0DC;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205E0DC;
	sub_820A71E8(ctx, base);
loc_8205E0DC:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E0E0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205E0F0;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205e114
	if (ctx.cr6.eq) goto loc_8205E114;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,338
	ctx.r6.s64 = 338;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205E10C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205e118
	goto loc_8205E118;
loc_8205E114:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205E118:
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
	ctx.lr = 0x8205E14C;
	sub_82065F78(ctx, base);
	// lbz r7,0(r26)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8205e16c
	if (!ctx.cr6.eq) goto loc_8205E16C;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205E16C;
	sub_820A71E8(ctx, base);
loc_8205E16C:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E170;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205E180;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205e1a4
	if (ctx.cr6.eq) goto loc_8205E1A4;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,494
	ctx.r6.s64 = 494;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205E19C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205e1a8
	goto loc_8205E1A8;
loc_8205E1A4:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205E1A8:
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
	ctx.lr = 0x8205E1D0;
	sub_82065F78(ctx, base);
	// lwz r11,-6596(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6596);
	// li r28,48
	ctx.r28.s64 = 48;
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r9,576
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 576, ctx.xer);
	// beq cr6,0x8205e1e8
	if (ctx.cr6.eq) goto loc_8205E1E8;
	// mr r28,r22
	ctx.r28.u64 = ctx.r22.u64;
loc_8205E1E8:
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205e208
	if (!ctx.cr6.eq) goto loc_8205E208;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205E208;
	sub_820A71E8(ctx, base);
loc_8205E208:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E20C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205E21C;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r29,r11,9448
	ctx.r29.s64 = ctx.r11.s64 + 9448;
	// beq cr6,0x8205e31c
	if (ctx.cr6.eq) goto loc_8205E31C;
	// lwz r11,-6596(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6596);
	// li r30,48
	ctx.r30.s64 = 48;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,576
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 576, ctx.xer);
	// beq cr6,0x8205e248
	if (ctx.cr6.eq) goto loc_8205E248;
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
loc_8205E248:
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
	ctx.lr = 0x8205E294;
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
loc_8205E2A8:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8205e2a8
	if (!ctx.cr6.eq) goto loc_8205E2A8;
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
	ctx.lr = 0x8205E2D8;
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
	ctx.lr = 0x8205E314;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x8205e320
	goto loc_8205E320;
loc_8205E31C:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205E320:
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
	ctx.lr = 0x8205E348;
	sub_82065F78(ctx, base);
	// lbz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8205e368
	if (!ctx.cr6.eq) goto loc_8205E368;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205E368;
	sub_820A71E8(ctx, base);
loc_8205E368:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E36C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205E37C;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8205e43c
	if (ctx.cr6.eq) goto loc_8205E43C;
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
loc_8205E3A0:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8205e3a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8205E3A0;
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
	ctx.lr = 0x8205E3CC;
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
loc_8205E3E0:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8205e3e0
	if (!ctx.cr6.eq) goto loc_8205E3E0;
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
	ctx.lr = 0x8205E410;
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
	ctx.lr = 0x8205E434;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x8205e440
	goto loc_8205E440;
loc_8205E43C:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205E440:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205E450;
	sub_82065F78(ctx, base);
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205e470
	if (!ctx.cr6.eq) goto loc_8205E470;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205E470;
	sub_820A71E8(ctx, base);
loc_8205E470:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E474;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205E484;
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
	// beq cr6,0x8205e4cc
	if (ctx.cr6.eq) goto loc_8205E4CC;
	// lwz r28,4(r24)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205E4A8;
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
	ctx.lr = 0x8205E4C0;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8205e4d0
	goto loc_8205E4D0;
loc_8205E4CC:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205E4D0:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205E4E0;
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
	// bne cr6,0x8205e514
	if (!ctx.cr6.eq) goto loc_8205E514;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205E514;
	sub_820A71E8(ctx, base);
loc_8205E514:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E518;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205E528;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8205e560
	if (ctx.cr6.eq) goto loc_8205E560;
	// lwz r28,4(r24)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205E53C;
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
	ctx.lr = 0x8205E554;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8205e564
	goto loc_8205E564;
loc_8205E560:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205E564:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205E574;
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
	// bne cr6,0x8205e5a4
	if (!ctx.cr6.eq) goto loc_8205E5A4;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205E5A4;
	sub_820A71E8(ctx, base);
loc_8205E5A4:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E5A8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205E5B8;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8205e5ec
	if (ctx.cr6.eq) goto loc_8205E5EC;
	// lwz r28,4(r24)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205E5CC;
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
	ctx.lr = 0x8205E5E0;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8205e5f0
	goto loc_8205E5F0;
loc_8205E5EC:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205E5F0:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205E600;
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
	// bne cr6,0x8205e630
	if (!ctx.cr6.eq) goto loc_8205E630;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205E630;
	sub_820A71E8(ctx, base);
loc_8205E630:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E634;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205E644;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8205e67c
	if (ctx.cr6.eq) goto loc_8205E67C;
	// lwz r28,4(r24)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205E658;
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
	ctx.lr = 0x8205E670;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8205e680
	goto loc_8205E680;
loc_8205E67C:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205E680:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205E690;
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
	// bne cr6,0x8205e6c0
	if (!ctx.cr6.eq) goto loc_8205E6C0;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205E6C0;
	sub_820A71E8(ctx, base);
loc_8205E6C0:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E6C4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205E6D4;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8205e70c
	if (ctx.cr6.eq) goto loc_8205E70C;
	// lwz r28,4(r24)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205E6E8;
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
	ctx.lr = 0x8205E700;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8205e710
	goto loc_8205E710;
loc_8205E70C:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205E710:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205E720;
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
	// bne cr6,0x8205e750
	if (!ctx.cr6.eq) goto loc_8205E750;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205E750;
	sub_820A71E8(ctx, base);
loc_8205E750:
	// bl 0x820b5eb8
	ctx.lr = 0x8205E754;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205E764;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8205e798
	if (ctx.cr6.eq) goto loc_8205E798;
	// lwz r28,4(r24)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205E778;
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
	ctx.lr = 0x8205E78C;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8205e79c
	goto loc_8205E79C;
loc_8205E798:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
loc_8205E79C:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205E7AC;
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
	ctx.lr = 0x8205E7DC;
	__restfpr_27(ctx, base);
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
}
