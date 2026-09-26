DEFINE_REX_FUNC(sub_82059600) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f4
	ctx.lr = 0x82059608;
	__savegprlr_19(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8212a854
	ctx.lr = 0x82059610;
	__savefpr_27(ctx, base);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// li r20,1
	ctx.r20.s64 = 1;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// sth r20,16(r25)
	REX_STORE_U16(ctx.r25.u32 + 16, ctx.r20.u16);
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
loc_82059630:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lwz r4,-6596(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -6596);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820a0c38
	ctx.lr = 0x82059640;
	sub_820A0C38(ctx, base);
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// clrlwi r31,r11,16
	ctx.r31.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r31,4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 4, ctx.xer);
	// blt cr6,0x82059630
	if (ctx.cr6.lt) goto loc_82059630;
	// lwz r11,-6596(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6596);
	// lis r26,-32215
	ctx.r26.s64 = -2111242240;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// addi r21,r10,-1768
	ctx.r21.s64 = ctx.r10.s64 + -1768;
	// lwz r7,12(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lbz r6,-22601(r26)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// lfs f0,18248(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18248);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// std r7,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f30,f11,f0
	ctx.f30.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// bne cr6,0x820596a0
	if (!ctx.cr6.eq) goto loc_820596A0;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820596A0;
	sub_820A71E8(ctx, base);
loc_820596A0:
	// bl 0x820b5eb8
	ctx.lr = 0x820596A4;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r24,r11,29632
	ctx.r24.s64 = ctx.r11.s64 + 29632;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r10,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820596BC;
	sub_8209BDD8(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f28,10000(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10000);
	ctx.f28.f64 = double(temp.f32);
	// li r22,6
	ctx.r22.s64 = 6;
	// lfd f31,9992(r8)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r8.u32 + 9992);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r23,r11,9448
	ctx.r23.s64 = ctx.r11.s64 + 9448;
	// addi r30,r10,9516
	ctx.r30.s64 = ctx.r10.s64 + 9516;
	// beq cr6,0x820597a0
	if (ctx.cr6.eq) goto loc_820597A0;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r22,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r22.u32);
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82059700:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x82059700
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82059700;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r28,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r28.u8);
	// lwz r29,4(r27)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205972C;
	sub_82066F80(ctx, base);
	// addi r11,r1,100
	ctx.r11.s64 = ctx.r1.s64 + 100;
	// stw r29,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// stw r28,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r28.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stw r23,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r23.u32);
loc_82059740:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82059740
	if (!ctx.cr6.eq) goto loc_82059740;
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
	ctx.lr = 0x82059770;
	sub_82129A70(ctx, base);
	// lwz r9,176(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r10,r1,180
	ctx.r10.s64 = ctx.r1.s64 + 180;
	// fmul f0,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f30.f64 * ctx.f31.f64;
	// li r5,2012
	ctx.r5.s64 = 2012;
	// fmr f2,f28
	ctx.f2.f64 = ctx.f28.f64;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r28,r9,r10
	REX_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r28.u8);
	// frsp f1,f0
	ctx.f1.f64 = double(float(ctx.f0.f64));
	// bl 0x82067c40
	ctx.lr = 0x82059798;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x820597a4
	goto loc_820597A4;
loc_820597A0:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
loc_820597A4:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lfs f29,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f29.f64 = double(temp.f32);
	// fmr f2,f29
	ctx.f2.f64 = ctx.f29.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x82065f78
	ctx.lr = 0x820597BC;
	sub_82065F78(ctx, base);
	// lbz r10,-22601(r26)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820597dc
	if (!ctx.cr6.eq) goto loc_820597DC;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820597DC;
	sub_820A71E8(ctx, base);
loc_820597DC:
	// bl 0x820b5eb8
	ctx.lr = 0x820597E0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820597F0;
	sub_8209BDD8(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// lfs f27,9988(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9988);
	ctx.f27.f64 = double(temp.f32);
	// beq cr6,0x820598b8
	if (ctx.cr6.eq) goto loc_820598B8;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r22,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r22.u32);
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82059818:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x82059818
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82059818;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r28,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r28.u8);
	// lwz r30,4(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82059844;
	sub_82066F80(ctx, base);
	// addi r11,r1,100
	ctx.r11.s64 = ctx.r1.s64 + 100;
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stw r28,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r28.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stw r23,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r23.u32);
loc_82059858:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82059858
	if (!ctx.cr6.eq) goto loc_82059858;
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
	ctx.lr = 0x82059888;
	sub_82129A70(ctx, base);
	// lwz r9,176(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r10,r1,180
	ctx.r10.s64 = ctx.r1.s64 + 180;
	// fmul f0,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f30.f64 * ctx.f31.f64;
	// li r5,2013
	ctx.r5.s64 = 2013;
	// fmr f2,f27
	ctx.f2.f64 = ctx.f27.f64;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r28,r9,r10
	REX_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r28.u8);
	// frsp f1,f0
	ctx.f1.f64 = double(float(ctx.f0.f64));
	// bl 0x82067c40
	ctx.lr = 0x820598B0;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x820598bc
	goto loc_820598BC;
loc_820598B8:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
loc_820598BC:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f29.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x82065f78
	ctx.lr = 0x820598CC;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820598ec
	if (!ctx.cr6.eq) goto loc_820598EC;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820598EC;
	sub_820A71E8(ctx, base);
loc_820598EC:
	// bl 0x820b5eb8
	ctx.lr = 0x820598F0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82059900;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82059918
	if (ctx.cr6.eq) goto loc_82059918;
	// li r4,606
	ctx.r4.s64 = 606;
	// bl 0x82067778
	ctx.lr = 0x82059910;
	sub_82067778(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205991c
	goto loc_8205991C;
loc_82059918:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
loc_8205991C:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f29.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205992C;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205994c
	if (!ctx.cr6.eq) goto loc_8205994C;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205994C;
	sub_820A71E8(ctx, base);
loc_8205994C:
	// bl 0x820b5eb8
	ctx.lr = 0x82059950;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82059960;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82059988
	if (ctx.cr6.eq) goto loc_82059988;
	// lis r11,-32247
	ctx.r11.s64 = -2113339392;
	// li r7,20
	ctx.r7.s64 = 20;
	// li r6,394
	ctx.r6.s64 = 394;
	// addi r5,r11,-14888
	ctx.r5.s64 = ctx.r11.s64 + -14888;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x82059980;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205998c
	goto loc_8205998C;
loc_82059988:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
loc_8205998C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// fmr f2,f28
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f28.f64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lfs f0,9984(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9984);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f31,f30,f0
	ctx.f31.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820599A8;
	sub_82065F78(ctx, base);
	// lbz r10,-22601(r26)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820599c8
	if (!ctx.cr6.eq) goto loc_820599C8;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820599C8;
	sub_820A71E8(ctx, base);
loc_820599C8:
	// bl 0x820b5eb8
	ctx.lr = 0x820599CC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820599DC;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82059a04
	if (ctx.cr6.eq) goto loc_82059A04;
	// lis r11,-32247
	ctx.r11.s64 = -2113339392;
	// li r7,20
	ctx.r7.s64 = 20;
	// li r6,395
	ctx.r6.s64 = 395;
	// addi r5,r11,-14888
	ctx.r5.s64 = ctx.r11.s64 + -14888;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x820599FC;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82059a08
	goto loc_82059A08;
loc_82059A04:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
loc_82059A08:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// fmr f2,f27
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f27.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82059A18;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82059a38
	if (!ctx.cr6.eq) goto loc_82059A38;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82059A38;
	sub_820A71E8(ctx, base);
loc_82059A38:
	// bl 0x820b5eb8
	ctx.lr = 0x82059A3C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,112
	ctx.r4.s64 = 112;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82059A4C;
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
	// addi r30,r11,18856
	ctx.r30.s64 = ctx.r11.s64 + 18856;
	// beq cr6,0x82059ad0
	if (ctx.cr6.eq) goto loc_82059AD0;
	// bl 0x82066f80
	ctx.lr = 0x82059A6C;
	sub_82066F80(ctx, base);
	// stw r27,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r27.u32);
	// sth r28,100(r31)
	REX_STORE_U16(ctx.r31.u32 + 100, ctx.r28.u16);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// li r4,595
	ctx.r4.s64 = 595;
	// sth r28,102(r31)
	REX_STORE_U16(ctx.r31.u32 + 102, ctx.r28.u16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// sth r20,104(r31)
	REX_STORE_U16(ctx.r31.u32 + 104, ctx.r20.u16);
	// stb r20,106(r31)
	REX_STORE_U8(ctx.r31.u32 + 106, ctx.r20.u8);
	// stw r28,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r28.u32);
	// bl 0x82067230
	ctx.lr = 0x82059A98;
	sub_82067230(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82059AAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82059abc
	if (!ctx.cr6.eq) goto loc_82059ABC;
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
loc_82059ABC:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// sth r28,44(r31)
	REX_STORE_U16(ctx.r31.u32 + 44, ctx.r28.u16);
	// addi r10,r11,-11560
	ctx.r10.s64 = ctx.r11.s64 + -11560;
	// stw r10,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r10.u32);
	// b 0x82059ad4
	goto loc_82059AD4;
loc_82059AD0:
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
loc_82059AD4:
	// li r4,396
	ctx.r4.s64 = 396;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x82059AE0;
	sub_820679E8(ctx, base);
	// li r4,397
	ctx.r4.s64 = 397;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x82059AEC;
	sub_820679E8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lfs f2,9980(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9980);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82065f78
	ctx.lr = 0x82059B04;
	sub_82065F78(ctx, base);
	// lbz r10,-22601(r26)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82059b24
	if (!ctx.cr6.eq) goto loc_82059B24;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82059B24;
	sub_820A71E8(ctx, base);
loc_82059B24:
	// bl 0x820b5eb8
	ctx.lr = 0x82059B28;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,112
	ctx.r4.s64 = 112;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82059B38;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82059bac
	if (ctx.cr6.eq) goto loc_82059BAC;
	// bl 0x82066f80
	ctx.lr = 0x82059B48;
	sub_82066F80(ctx, base);
	// stw r27,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r27.u32);
	// sth r28,100(r31)
	REX_STORE_U16(ctx.r31.u32 + 100, ctx.r28.u16);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// li r4,399
	ctx.r4.s64 = 399;
	// sth r28,102(r31)
	REX_STORE_U16(ctx.r31.u32 + 102, ctx.r28.u16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// sth r20,104(r31)
	REX_STORE_U16(ctx.r31.u32 + 104, ctx.r20.u16);
	// stb r20,106(r31)
	REX_STORE_U8(ctx.r31.u32 + 106, ctx.r20.u8);
	// stw r28,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r28.u32);
	// bl 0x82067230
	ctx.lr = 0x82059B74;
	sub_82067230(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82059B88;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82059b98
	if (!ctx.cr6.eq) goto loc_82059B98;
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
loc_82059B98:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// sth r28,44(r31)
	REX_STORE_U16(ctx.r31.u32 + 44, ctx.r28.u16);
	// addi r10,r11,-13944
	ctx.r10.s64 = ctx.r11.s64 + -13944;
	// stw r10,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r10.u32);
	// b 0x82059bb0
	goto loc_82059BB0;
loc_82059BAC:
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
loc_82059BB0:
	// li r4,396
	ctx.r4.s64 = 396;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x82059BBC;
	sub_820679E8(ctx, base);
	// li r4,397
	ctx.r4.s64 = 397;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820679e8
	ctx.lr = 0x82059BC8;
	sub_820679E8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lfs f2,9976(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9976);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82065f78
	ctx.lr = 0x82059BE0;
	sub_82065F78(ctx, base);
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82059BF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x82059c0c
	if (!ctx.cr6.eq) goto loc_82059C0C;
	// lis r11,85
	ctx.r11.s64 = 5570560;
	// stb r20,21(r31)
	REX_STORE_U8(ctx.r31.u32 + 21, ctx.r20.u8);
	// ori r10,r11,21845
	ctx.r10.u64 = ctx.r11.u64 | 21845;
	// stw r10,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
loc_82059C0C:
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lbz r9,-22601(r26)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// stw r27,356(r25)
	REX_STORE_U32(ctx.r25.u32 + 356, ctx.r27.u32);
	// addi r8,r10,-15072
	ctx.r8.s64 = ctx.r10.s64 + -15072;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,384(r25)
	REX_STORE_U32(ctx.r25.u32 + 384, ctx.r8.u32);
	// bne cr6,0x82059c3c
	if (!ctx.cr6.eq) goto loc_82059C3C;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82059C3C;
	sub_820A71E8(ctx, base);
loc_82059C3C:
	// bl 0x820b5eb8
	ctx.lr = 0x82059C40;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82059C50;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r30,r11,9460
	ctx.r30.s64 = ctx.r11.s64 + 9460;
	// beq cr6,0x82059c90
	if (ctx.cr6.eq) goto loc_82059C90;
	// lwz r19,4(r27)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82059C6C;
	sub_82066F80(ctx, base);
	// li r11,17
	ctx.r11.s64 = 17;
	// stw r19,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r19.u32);
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x82059C84;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// b 0x82059c94
	goto loc_82059C94;
loc_82059C90:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
loc_82059C94:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f29.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x82065f78
	ctx.lr = 0x82059CA4;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lbz r7,-22601(r26)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r8,r10,-13584
	ctx.r8.s64 = ctx.r10.s64 + -13584;
	// stw r27,356(r25)
	REX_STORE_U32(ctx.r25.u32 + 356, ctx.r27.u32);
	// sth r9,390(r25)
	REX_STORE_U16(ctx.r25.u32 + 390, ctx.r9.u16);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r8,364(r25)
	REX_STORE_U32(ctx.r25.u32 + 364, ctx.r8.u32);
	// bne cr6,0x82059cdc
	if (!ctx.cr6.eq) goto loc_82059CDC;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82059CDC;
	sub_820A71E8(ctx, base);
loc_82059CDC:
	// bl 0x820b5eb8
	ctx.lr = 0x82059CE0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82059CF0;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82059d24
	if (ctx.cr6.eq) goto loc_82059D24;
	// lwz r19,4(r27)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82059D04;
	sub_82066F80(ctx, base);
	// stw r19,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r19.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r28.u32);
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// bl 0x82067e00
	ctx.lr = 0x82059D18;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// b 0x82059d28
	goto loc_82059D28;
loc_82059D24:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
loc_82059D28:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f29.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x82065f78
	ctx.lr = 0x82059D38;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lbz r9,-22601(r26)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// addi r8,r10,-13808
	ctx.r8.s64 = ctx.r10.s64 + -13808;
	// stw r27,356(r25)
	REX_STORE_U32(ctx.r25.u32 + 356, ctx.r27.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,368(r25)
	REX_STORE_U32(ctx.r25.u32 + 368, ctx.r8.u32);
	// bne cr6,0x82059d68
	if (!ctx.cr6.eq) goto loc_82059D68;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82059D68;
	sub_820A71E8(ctx, base);
loc_82059D68:
	// bl 0x820b5eb8
	ctx.lr = 0x82059D6C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82059D7C;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82059db4
	if (ctx.cr6.eq) goto loc_82059DB4;
	// lwz r19,4(r27)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82059D90;
	sub_82066F80(ctx, base);
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r19,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r19.u32);
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x82059DA8;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// b 0x82059db8
	goto loc_82059DB8;
loc_82059DB4:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
loc_82059DB8:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f29.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x82065f78
	ctx.lr = 0x82059DC8;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82059de8
	if (!ctx.cr6.eq) goto loc_82059DE8;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82059DE8;
	sub_820A71E8(ctx, base);
loc_82059DE8:
	// bl 0x820b5eb8
	ctx.lr = 0x82059DEC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82059DFC;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82059ebc
	if (ctx.cr6.eq) goto loc_82059EBC;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r22,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r22.u32);
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// addi r11,r11,9484
	ctx.r11.s64 = ctx.r11.s64 + 9484;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82059E20:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x82059e20
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82059E20;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r28,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r28.u8);
	// lwz r30,4(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82059E4C;
	sub_82066F80(ctx, base);
	// addi r11,r1,100
	ctx.r11.s64 = ctx.r1.s64 + 100;
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stw r28,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r28.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stw r23,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r23.u32);
loc_82059E60:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82059e60
	if (!ctx.cr6.eq) goto loc_82059E60;
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
	ctx.lr = 0x82059E90;
	sub_82129A70(ctx, base);
	// lwz r9,176(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r10,r1,180
	ctx.r10.s64 = ctx.r1.s64 + 180;
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f29.f64;
	// li r5,2001
	ctx.r5.s64 = 2001;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r28,r9,r10
	REX_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r28.u8);
	// bl 0x82067c40
	ctx.lr = 0x82059EB4;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x82059ec0
	goto loc_82059EC0;
loc_82059EBC:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
loc_82059EC0:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f29.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x82065f78
	ctx.lr = 0x82059ED0;
	sub_82065F78(ctx, base);
	// stb r20,14(r25)
	REX_STORE_U8(ctx.r25.u32 + 14, ctx.r20.u8);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8212a8a0
	ctx.lr = 0x82059EE0;
	__restfpr_27(ctx, base);
	// b 0x82129944
	__restgprlr_19(ctx, base);
	return;
}
