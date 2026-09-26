DEFINE_REX_FUNC(sub_8205F6E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298ec
	ctx.lr = 0x8205F6E8;
	__savegprlr_17(ctx, base);
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x8212a854
	ctx.lr = 0x8205F6F0;
	__savefpr_27(ctx, base);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// addi r25,r11,-22601
	ctx.r25.s64 = ctx.r11.s64 + -22601;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lbz r11,-22601(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// addi r17,r10,-1768
	ctx.r17.s64 = ctx.r10.s64 + -1768;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205f72c
	if (!ctx.cr6.eq) goto loc_8205F72C;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205F72C;
	sub_820A71E8(ctx, base);
loc_8205F72C:
	// bl 0x820b5eb8
	ctx.lr = 0x8205F730;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r20,r11,29632
	ctx.r20.s64 = ctx.r11.s64 + 29632;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r10,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205F748;
	sub_8209BDD8(ctx, base);
	// li r21,0
	ctx.r21.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205f764
	if (ctx.cr6.eq) goto loc_8205F764;
	// li r4,389
	ctx.r4.s64 = 389;
	// bl 0x82067778
	ctx.lr = 0x8205F75C;
	sub_82067778(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205f768
	goto loc_8205F768;
loc_8205F764:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_8205F768:
	// lis r26,-32218
	ctx.r26.s64 = -2111438848;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r22,r11,18236
	ctx.r22.s64 = ctx.r11.s64 + 18236;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// lfs f2,9652(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9652);
	ctx.f2.f64 = double(temp.f32);
	// lfs f27,12(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 12);
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
	ctx.lr = 0x8205F7A4;
	sub_82065F78(ctx, base);
	// lbz r7,0(r25)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8205f7c4
	if (!ctx.cr6.eq) goto loc_8205F7C4;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205F7C4;
	sub_820A71E8(ctx, base);
loc_8205F7C4:
	// bl 0x820b5eb8
	ctx.lr = 0x8205F7C8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205F7D8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205f7fc
	if (ctx.cr6.eq) goto loc_8205F7FC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,506
	ctx.r6.s64 = 506;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205F7F4;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205f800
	goto loc_8205F800;
loc_8205F7FC:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_8205F800:
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
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
	ctx.lr = 0x8205F83C;
	sub_82065F78(ctx, base);
	// lbz r6,0(r25)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x8205f85c
	if (!ctx.cr6.eq) goto loc_8205F85C;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205F85C;
	sub_820A71E8(ctx, base);
loc_8205F85C:
	// bl 0x820b5eb8
	ctx.lr = 0x8205F860;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205F870;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205f894
	if (ctx.cr6.eq) goto loc_8205F894;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205F88C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205f898
	goto loc_8205F898;
loc_8205F894:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_8205F898:
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
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
	ctx.lr = 0x8205F8DC;
	sub_82065F78(ctx, base);
	// lbz r5,0(r25)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x8205f8f8
	if (!ctx.cr6.eq) goto loc_8205F8F8;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205F8F8;
	sub_820A71E8(ctx, base);
loc_8205F8F8:
	// bl 0x820b5eb8
	ctx.lr = 0x8205F8FC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205F90C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205f930
	if (ctx.cr6.eq) goto loc_8205F930;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,533
	ctx.r6.s64 = 533;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205F928;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205f934
	goto loc_8205F934;
loc_8205F930:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_8205F934:
	// sth r21,44(r4)
	REX_STORE_U16(ctx.r4.u32 + 44, ctx.r21.u16);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f28,-320(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -320);
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
	// bne cr6,0x8205f968
	if (!ctx.cr6.eq) goto loc_8205F968;
	// fmr f0,f29
	ctx.f0.f64 = ctx.f29.f64;
	// b 0x8205f96c
	goto loc_8205F96C;
loc_8205F968:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_8205F96C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
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
	ctx.lr = 0x8205F988;
	sub_82065F78(ctx, base);
	// lbz r9,0(r25)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8205f9a8
	if (!ctx.cr6.eq) goto loc_8205F9A8;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205F9A8;
	sub_820A71E8(ctx, base);
loc_8205F9A8:
	// bl 0x820b5eb8
	ctx.lr = 0x8205F9AC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205F9BC;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205f9e0
	if (ctx.cr6.eq) goto loc_8205F9E0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,507
	ctx.r6.s64 = 507;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205F9D8;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205f9e4
	goto loc_8205F9E4;
loc_8205F9E0:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_8205F9E4:
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// li r19,1
	ctx.r19.s64 = 1;
	// stfs f28,36(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r4.u32 + 36, temp.u32);
	// sth r19,44(r4)
	REX_STORE_U16(ctx.r4.u32 + 44, ctx.r19.u16);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,576
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 576, ctx.xer);
	// bne cr6,0x8205fa08
	if (!ctx.cr6.eq) goto loc_8205FA08;
	// fmr f0,f29
	ctx.f0.f64 = ctx.f29.f64;
	// b 0x8205fa0c
	goto loc_8205FA0C;
loc_8205FA08:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_8205FA0C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// fadds f2,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lfs f1,9892(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9892);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82065f78
	ctx.lr = 0x8205FA20;
	sub_82065F78(ctx, base);
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lbz r8,0(r25)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// li r23,4
	ctx.r23.s64 = 4;
	// li r18,10
	ctx.r18.s64 = 10;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r7,16(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lfs f0,9932(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9932);
	ctx.f0.f64 = double(temp.f32);
	// stfs f31,404(r29)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r29.u32 + 404, temp.u32);
	// sth r23,394(r29)
	REX_STORE_U16(ctx.r29.u32 + 394, ctx.r23.u16);
	// rlwinm r6,r7,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// sth r18,396(r29)
	REX_STORE_U16(ctx.r29.u32 + 396, ctx.r18.u16);
	// sth r19,398(r29)
	REX_STORE_U16(ctx.r29.u32 + 398, ctx.r19.u16);
	// std r6,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// sth r19,400(r29)
	REX_STORE_U16(ctx.r29.u32 + 400, ctx.r19.u16);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stb r19,392(r29)
	REX_STORE_U8(ctx.r29.u32 + 392, ctx.r19.u8);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f0.f64));
	// stfs f10,408(r29)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r29.u32 + 408, temp.u32);
	// bne cr6,0x8205fa8c
	if (!ctx.cr6.eq) goto loc_8205FA8C;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205FA8C;
	sub_820A71E8(ctx, base);
loc_8205FA8C:
	// bl 0x820b5eb8
	ctx.lr = 0x8205FA90;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205FAA0;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205fac4
	if (ctx.cr6.eq) goto loc_8205FAC4;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,488
	ctx.r6.s64 = 488;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205FABC;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205fac8
	goto loc_8205FAC8;
loc_8205FAC4:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_8205FAC8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205FAD8;
	sub_82065F78(ctx, base);
	// lbz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205faf8
	if (!ctx.cr6.eq) goto loc_8205FAF8;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205FAF8;
	sub_820A71E8(ctx, base);
loc_8205FAF8:
	// bl 0x820b5eb8
	ctx.lr = 0x8205FAFC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205FB0C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205fb30
	if (ctx.cr6.eq) goto loc_8205FB30;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,590
	ctx.r6.s64 = 590;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205FB28;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205fb34
	goto loc_8205FB34;
loc_8205FB30:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_8205FB34:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205FB44;
	sub_82065F78(ctx, base);
	// lbz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205fb64
	if (!ctx.cr6.eq) goto loc_8205FB64;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205FB64;
	sub_820A71E8(ctx, base);
loc_8205FB64:
	// bl 0x820b5eb8
	ctx.lr = 0x8205FB68;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205FB78;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205fb9c
	if (ctx.cr6.eq) goto loc_8205FB9C;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,612
	ctx.r6.s64 = 612;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205FB94;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205fba0
	goto loc_8205FBA0;
loc_8205FB9C:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_8205FBA0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205FBB0;
	sub_82065F78(ctx, base);
	// lbz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205fbd0
	if (!ctx.cr6.eq) goto loc_8205FBD0;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205FBD0;
	sub_820A71E8(ctx, base);
loc_8205FBD0:
	// bl 0x820b5eb8
	ctx.lr = 0x8205FBD4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205FBE4;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205fc08
	if (ctx.cr6.eq) goto loc_8205FC08;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,611
	ctx.r6.s64 = 611;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205FC00;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205fc0c
	goto loc_8205FC0C;
loc_8205FC08:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_8205FC0C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205FC1C;
	sub_82065F78(ctx, base);
	// li r30,9
	ctx.r30.s64 = 9;
loc_8205FC20:
	// lbz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205fc40
	if (!ctx.cr6.eq) goto loc_8205FC40;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205FC40;
	sub_820A71E8(ctx, base);
loc_8205FC40:
	// bl 0x820b5eb8
	ctx.lr = 0x8205FC44;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205FC54;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205fc78
	if (ctx.cr6.eq) goto loc_8205FC78;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205FC70;
	sub_82067020(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8205fc7c
	goto loc_8205FC7C;
loc_8205FC78:
	// mr r31,r21
	ctx.r31.u64 = ctx.r21.u64;
loc_8205FC7C:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205FC90;
	sub_82065F78(ctx, base);
	// lbz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// sth r21,44(r31)
	REX_STORE_U16(ctx.r31.u32 + 44, ctx.r21.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205fcb4
	if (!ctx.cr6.eq) goto loc_8205FCB4;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205FCB4;
	sub_820A71E8(ctx, base);
loc_8205FCB4:
	// bl 0x820b5eb8
	ctx.lr = 0x8205FCB8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205FCC8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205fcf0
	if (ctx.cr6.eq) goto loc_8205FCF0;
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
	ctx.lr = 0x8205FCE8;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205fcf4
	goto loc_8205FCF4;
loc_8205FCF0:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_8205FCF4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205FD04;
	sub_82065F78(ctx, base);
	// lbz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205fd24
	if (!ctx.cr6.eq) goto loc_8205FD24;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205FD24;
	sub_820A71E8(ctx, base);
loc_8205FD24:
	// bl 0x820b5eb8
	ctx.lr = 0x8205FD28;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205FD38;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205fd5c
	if (ctx.cr6.eq) goto loc_8205FD5C;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205FD54;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205fd60
	goto loc_8205FD60;
loc_8205FD5C:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_8205FD60:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205FD70;
	sub_82065F78(ctx, base);
	// lbz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205fd90
	if (!ctx.cr6.eq) goto loc_8205FD90;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205FD90;
	sub_820A71E8(ctx, base);
loc_8205FD90:
	// bl 0x820b5eb8
	ctx.lr = 0x8205FD94;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205FDA4;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205fdc8
	if (ctx.cr6.eq) goto loc_8205FDC8;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205FDC0;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205fdcc
	goto loc_8205FDCC;
loc_8205FDC8:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_8205FDCC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205FDDC;
	sub_82065F78(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8205fc20
	if (!ctx.cr0.eq) goto loc_8205FC20;
	// lbz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205fe04
	if (!ctx.cr6.eq) goto loc_8205FE04;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205FE04;
	sub_820A71E8(ctx, base);
loc_8205FE04:
	// bl 0x820b5eb8
	ctx.lr = 0x8205FE08;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205FE18;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205fe3c
	if (ctx.cr6.eq) goto loc_8205FE3C;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,338
	ctx.r6.s64 = 338;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205FE34;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205fe40
	goto loc_8205FE40;
loc_8205FE3C:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_8205FE40:
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f30,0(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
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
	ctx.lr = 0x8205FE74;
	sub_82065F78(ctx, base);
	// lbz r7,0(r25)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8205fe94
	if (!ctx.cr6.eq) goto loc_8205FE94;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205FE94;
	sub_820A71E8(ctx, base);
loc_8205FE94:
	// bl 0x820b5eb8
	ctx.lr = 0x8205FE98;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205FEA8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205fecc
	if (ctx.cr6.eq) goto loc_8205FECC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,494
	ctx.r6.s64 = 494;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82067020
	ctx.lr = 0x8205FEC4;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205fed0
	goto loc_8205FED0;
loc_8205FECC:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_8205FED0:
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
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
	ctx.lr = 0x8205FEF8;
	sub_82065F78(ctx, base);
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// li r27,48
	ctx.r27.s64 = 48;
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r9,576
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 576, ctx.xer);
	// beq cr6,0x8205ff10
	if (ctx.cr6.eq) goto loc_8205FF10;
	// mr r27,r21
	ctx.r27.u64 = ctx.r21.u64;
loc_8205FF10:
	// lbz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205ff30
	if (!ctx.cr6.eq) goto loc_8205FF30;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205FF30;
	sub_820A71E8(ctx, base);
loc_8205FF30:
	// bl 0x820b5eb8
	ctx.lr = 0x8205FF34;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205FF44;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r28,r11,9448
	ctx.r28.s64 = ctx.r11.s64 + 9448;
	// beq cr6,0x82060040
	if (ctx.cr6.eq) goto loc_82060040;
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// li r30,48
	ctx.r30.s64 = 48;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,576
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 576, ctx.xer);
	// beq cr6,0x8205ff70
	if (ctx.cr6.eq) goto loc_8205FF70;
	// mr r30,r21
	ctx.r30.u64 = ctx.r21.u64;
loc_8205FF70:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r23,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r23.u32);
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// addi r9,r11,9472
	ctx.r9.s64 = ctx.r11.s64 + 9472;
	// addi r8,r1,100
	ctx.r8.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r7,9472(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 9472);
	// lbz r6,1(r9)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbz r5,2(r9)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + 2);
	// lbz r4,3(r9)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r9.u32 + 3);
	// stb r7,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r7.u8);
	// stb r6,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r6.u8);
	// stb r5,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, ctx.r5.u8);
	// stb r4,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, ctx.r4.u8);
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// stbx r21,r11,r8
	REX_STORE_U8(ctx.r11.u32 + ctx.r8.u32, ctx.r21.u8);
	// lwz r26,4(r24)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205FFB8;
	sub_82066F80(ctx, base);
	// addi r11,r1,100
	ctx.r11.s64 = ctx.r1.s64 + 100;
	// stw r26,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r26.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// stw r21,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r21.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8205FFCC:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8205ffcc
	if (!ctx.cr6.eq) goto loc_8205FFCC;
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
	ctx.lr = 0x8205FFFC;
	sub_82129A70(ctx, base);
	// extsw r10,r30
	ctx.r10.s64 = ctx.r30.s32;
	// lwz r8,176(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r9,r1,180
	ctx.r9.s64 = ctx.r1.s64 + 180;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,64(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// stbx r21,r8,r9
	REX_STORE_U8(ctx.r8.u32 + ctx.r9.u32, ctx.r21.u8);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// li r5,2003
	ctx.r5.s64 = 2003;
	// lfs f1,60(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 60);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fadds f2,f11,f0
	ctx.f2.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// bl 0x82067c40
	ctx.lr = 0x82060038;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x82060044
	goto loc_82060044;
loc_82060040:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_82060044:
	// extsw r11,r27
	ctx.r11.s64 = ctx.r27.s32;
	// lfs f0,64(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lfs f1,60(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 60);
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
	ctx.lr = 0x8206006C;
	sub_82065F78(ctx, base);
	// lbz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8206008c
	if (!ctx.cr6.eq) goto loc_8206008C;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206008C;
	sub_820A71E8(ctx, base);
loc_8206008C:
	// bl 0x820b5eb8
	ctx.lr = 0x82060090;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820600A0;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82060160
	if (ctx.cr6.eq) goto loc_82060160;
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
loc_820600C4:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x820600c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820600C4;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r21,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r21.u8);
	// lwz r30,4(r24)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x820600F0;
	sub_82066F80(ctx, base);
	// addi r11,r1,100
	ctx.r11.s64 = ctx.r1.s64 + 100;
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stw r21,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r21.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_82060104:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82060104
	if (!ctx.cr6.eq) goto loc_82060104;
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
	ctx.lr = 0x82060134;
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
	// stbx r21,r9,r10
	REX_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r21.u8);
	// bl 0x82067c40
	ctx.lr = 0x82060158;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x82060164
	goto loc_82060164;
loc_82060160:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_82060164:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82060174;
	sub_82065F78(ctx, base);
	// lbz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82060194
	if (!ctx.cr6.eq) goto loc_82060194;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82060194;
	sub_820A71E8(ctx, base);
loc_82060194:
	// bl 0x820b5eb8
	ctx.lr = 0x82060198;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820601A8;
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
	// addi r28,r11,9460
	ctx.r28.s64 = ctx.r11.s64 + 9460;
	// beq cr6,0x820601f0
	if (ctx.cr6.eq) goto loc_820601F0;
	// lwz r27,4(r24)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x820601CC;
	sub_82066F80(ctx, base);
	// li r11,13
	ctx.r11.s64 = 13;
	// stw r27,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r27.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x820601E4;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x820601f4
	goto loc_820601F4;
loc_820601F0:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_820601F4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82060204;
	sub_82065F78(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lbz r9,0(r25)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// addi r8,r10,20768
	ctx.r8.s64 = ctx.r10.s64 + 20768;
	// sth r18,390(r29)
	REX_STORE_U16(ctx.r29.u32 + 390, ctx.r18.u16);
	// stw r24,356(r29)
	REX_STORE_U32(ctx.r29.u32 + 356, ctx.r24.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,364(r29)
	REX_STORE_U32(ctx.r29.u32 + 364, ctx.r8.u32);
	// bne cr6,0x82060238
	if (!ctx.cr6.eq) goto loc_82060238;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82060238;
	sub_820A71E8(ctx, base);
loc_82060238:
	// bl 0x820b5eb8
	ctx.lr = 0x8206023C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206024C;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82060284
	if (ctx.cr6.eq) goto loc_82060284;
	// lwz r27,4(r24)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82060260;
	sub_82066F80(ctx, base);
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r27,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r27.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x82060278;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82060288
	goto loc_82060288;
loc_82060284:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_82060288:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82060298;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lbz r9,0(r25)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// addi r8,r10,5400
	ctx.r8.s64 = ctx.r10.s64 + 5400;
	// stw r24,356(r29)
	REX_STORE_U32(ctx.r29.u32 + 356, ctx.r24.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,372(r29)
	REX_STORE_U32(ctx.r29.u32 + 372, ctx.r8.u32);
	// bne cr6,0x820602c8
	if (!ctx.cr6.eq) goto loc_820602C8;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820602C8;
	sub_820A71E8(ctx, base);
loc_820602C8:
	// bl 0x820b5eb8
	ctx.lr = 0x820602CC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820602DC;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82060310
	if (ctx.cr6.eq) goto loc_82060310;
	// lwz r27,4(r24)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x820602F0;
	sub_82066F80(ctx, base);
	// stw r27,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r19,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r19.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// bl 0x82067e00
	ctx.lr = 0x82060304;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82060314
	goto loc_82060314;
loc_82060310:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_82060314:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82060324;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lbz r9,0(r25)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// addi r8,r10,5216
	ctx.r8.s64 = ctx.r10.s64 + 5216;
	// stw r24,356(r29)
	REX_STORE_U32(ctx.r29.u32 + 356, ctx.r24.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,368(r29)
	REX_STORE_U32(ctx.r29.u32 + 368, ctx.r8.u32);
	// bne cr6,0x82060354
	if (!ctx.cr6.eq) goto loc_82060354;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82060354;
	sub_820A71E8(ctx, base);
loc_82060354:
	// bl 0x820b5eb8
	ctx.lr = 0x82060358;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82060368;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820603a0
	if (ctx.cr6.eq) goto loc_820603A0;
	// lwz r27,4(r24)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8206037C;
	sub_82066F80(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r27,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r27.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x82060394;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x820603a4
	goto loc_820603A4;
loc_820603A0:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_820603A4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820603B4;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lbz r9,0(r25)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// addi r8,r10,5592
	ctx.r8.s64 = ctx.r10.s64 + 5592;
	// stw r24,356(r29)
	REX_STORE_U32(ctx.r29.u32 + 356, ctx.r24.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,380(r29)
	REX_STORE_U32(ctx.r29.u32 + 380, ctx.r8.u32);
	// bne cr6,0x820603e4
	if (!ctx.cr6.eq) goto loc_820603E4;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820603E4;
	sub_820A71E8(ctx, base);
loc_820603E4:
	// bl 0x820b5eb8
	ctx.lr = 0x820603E8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820603F8;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82060430
	if (ctx.cr6.eq) goto loc_82060430;
	// lwz r27,4(r24)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8206040C;
	sub_82066F80(ctx, base);
	// li r11,11
	ctx.r11.s64 = 11;
	// stw r27,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r27.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x82060424;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82060434
	goto loc_82060434;
loc_82060430:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_82060434:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82060444;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lbz r9,0(r25)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// addi r8,r10,5984
	ctx.r8.s64 = ctx.r10.s64 + 5984;
	// stw r24,356(r29)
	REX_STORE_U32(ctx.r29.u32 + 356, ctx.r24.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,376(r29)
	REX_STORE_U32(ctx.r29.u32 + 376, ctx.r8.u32);
	// bne cr6,0x82060474
	if (!ctx.cr6.eq) goto loc_82060474;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82060474;
	sub_820A71E8(ctx, base);
loc_82060474:
	// bl 0x820b5eb8
	ctx.lr = 0x82060478;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r20
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r20.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82060488;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820604bc
	if (ctx.cr6.eq) goto loc_820604BC;
	// lwz r27,4(r24)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8206049C;
	sub_82066F80(ctx, base);
	// stw r27,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r18,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r18.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// bl 0x82067e00
	ctx.lr = 0x820604B0;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x820604c0
	goto loc_820604C0;
loc_820604BC:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_820604C0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820604D0;
	sub_82065F78(ctx, base);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r10,21
	ctx.r10.s64 = 21;
	// stw r24,356(r29)
	REX_STORE_U32(ctx.r29.u32 + 356, ctx.r24.u32);
	// addi r9,r11,1976
	ctx.r9.s64 = ctx.r11.s64 + 1976;
	// stb r19,14(r29)
	REX_STORE_U8(ctx.r29.u32 + 14, ctx.r19.u8);
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// sth r10,16(r29)
	REX_STORE_U16(ctx.r29.u32 + 16, ctx.r10.u16);
	// stw r9,384(r29)
	REX_STORE_U32(ctx.r29.u32 + 384, ctx.r9.u32);
	// stb r11,-61(r25)
	REX_STORE_U8(ctx.r25.u32 + -61, ctx.r11.u8);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x8212a8a0
	ctx.lr = 0x82060500;
	__restfpr_27(ctx, base);
	// b 0x8212993c
	__restgprlr_17(ctx, base);
	return;
}
