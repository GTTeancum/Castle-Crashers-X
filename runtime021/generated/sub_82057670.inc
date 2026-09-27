DEFINE_REX_FUNC(sub_82057670) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x82057678;
	__savegprlr_22(ctx, base);
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32215
	ctx.r27.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r23,r11,-1768
	ctx.r23.s64 = ctx.r11.s64 + -1768;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820576b4
	if (!ctx.cr6.eq) goto loc_820576B4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820576B4;
	sub_820A71E8(ctx, base);
loc_820576B4:
	// bl 0x820b5eb8
	ctx.lr = 0x820576B8;
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
	ctx.lr = 0x820576D0;
	sub_8209BDD8(ctx, base);
	// li r24,0
	ctx.r24.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820576ec
	if (ctx.cr6.eq) goto loc_820576EC;
	// li r4,582
	ctx.r4.s64 = 582;
	// bl 0x82067778
	ctx.lr = 0x820576E4;
	sub_82067778(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x820576f0
	goto loc_820576F0;
loc_820576EC:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_820576F0:
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
	ctx.lr = 0x82057708;
	sub_82065F78(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lbz r8,-22601(r27)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f31,404(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r28.u32 + 404, temp.u32);
	// li r30,4
	ctx.r30.s64 = 4;
	// li r9,10
	ctx.r9.s64 = 10;
	// sth r11,398(r28)
	REX_STORE_U16(ctx.r28.u32 + 398, ctx.r11.u16);
	// sth r11,400(r28)
	REX_STORE_U16(ctx.r28.u32 + 400, ctx.r11.u16);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lfs f0,9952(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9952);
	ctx.f0.f64 = double(temp.f32);
	// stb r11,392(r28)
	REX_STORE_U8(ctx.r28.u32 + 392, ctx.r11.u8);
	// stfs f0,408(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 408, temp.u32);
	// sth r30,394(r28)
	REX_STORE_U16(ctx.r28.u32 + 394, ctx.r30.u16);
	// sth r9,396(r28)
	REX_STORE_U16(ctx.r28.u32 + 396, ctx.r9.u16);
	// bne cr6,0x82057758
	if (!ctx.cr6.eq) goto loc_82057758;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82057758;
	sub_820A71E8(ctx, base);
loc_82057758:
	// bl 0x820b5eb8
	ctx.lr = 0x8205775C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205776C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82057790
	if (ctx.cr6.eq) goto loc_82057790;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,583
	ctx.r6.s64 = 583;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067020
	ctx.lr = 0x82057788;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82057794
	goto loc_82057794;
loc_82057790:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82057794:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820577A4;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820577c4
	if (!ctx.cr6.eq) goto loc_820577C4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820577C4;
	sub_820A71E8(ctx, base);
loc_820577C4:
	// bl 0x820b5eb8
	ctx.lr = 0x820577C8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820577D8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820577fc
	if (ctx.cr6.eq) goto loc_820577FC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,464
	ctx.r6.s64 = 464;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067020
	ctx.lr = 0x820577F4;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82057800
	goto loc_82057800;
loc_820577FC:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82057800:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82057810;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82057830
	if (!ctx.cr6.eq) goto loc_82057830;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82057830;
	sub_820A71E8(ctx, base);
loc_82057830:
	// bl 0x820b5eb8
	ctx.lr = 0x82057834;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82057844;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82057868
	if (ctx.cr6.eq) goto loc_82057868;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,468
	ctx.r6.s64 = 468;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067020
	ctx.lr = 0x82057860;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205786c
	goto loc_8205786C;
loc_82057868:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_8205786C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205787C;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205789c
	if (!ctx.cr6.eq) goto loc_8205789C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205789C;
	sub_820A71E8(ctx, base);
loc_8205789C:
	// bl 0x820b5eb8
	ctx.lr = 0x820578A0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820578B0;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820578d4
	if (ctx.cr6.eq) goto loc_820578D4;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,584
	ctx.r6.s64 = 584;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067020
	ctx.lr = 0x820578CC;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x820578d8
	goto loc_820578D8;
loc_820578D4:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_820578D8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820578E8;
	sub_82065F78(ctx, base);
	// li r31,9
	ctx.r31.s64 = 9;
loc_820578EC:
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205790c
	if (!ctx.cr6.eq) goto loc_8205790C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205790C;
	sub_820A71E8(ctx, base);
loc_8205790C:
	// bl 0x820b5eb8
	ctx.lr = 0x82057910;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82057920;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82057948
	if (ctx.cr6.eq) goto loc_82057948;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,590
	ctx.r6.s64 = 590;
	// addi r5,r11,-31968
	ctx.r5.s64 = ctx.r11.s64 + -31968;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067020
	ctx.lr = 0x82057940;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205794c
	goto loc_8205794C;
loc_82057948:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_8205794C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205795C;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205797c
	if (!ctx.cr6.eq) goto loc_8205797C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205797C;
	sub_820A71E8(ctx, base);
loc_8205797C:
	// bl 0x820b5eb8
	ctx.lr = 0x82057980;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82057990;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820579b4
	if (ctx.cr6.eq) goto loc_820579B4;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,533
	ctx.r6.s64 = 533;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067020
	ctx.lr = 0x820579AC;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x820579b8
	goto loc_820579B8;
loc_820579B4:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_820579B8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820579C8;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820579e8
	if (!ctx.cr6.eq) goto loc_820579E8;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820579E8;
	sub_820A71E8(ctx, base);
loc_820579E8:
	// bl 0x820b5eb8
	ctx.lr = 0x820579EC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820579FC;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82057a20
	if (ctx.cr6.eq) goto loc_82057A20;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,533
	ctx.r6.s64 = 533;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067020
	ctx.lr = 0x82057A18;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82057a24
	goto loc_82057A24;
loc_82057A20:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82057A24:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82057A34;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82057a54
	if (!ctx.cr6.eq) goto loc_82057A54;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82057A54;
	sub_820A71E8(ctx, base);
loc_82057A54:
	// bl 0x820b5eb8
	ctx.lr = 0x82057A58;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82057A68;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82057a8c
	if (ctx.cr6.eq) goto loc_82057A8C;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,533
	ctx.r6.s64 = 533;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067020
	ctx.lr = 0x82057A84;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82057a90
	goto loc_82057A90;
loc_82057A8C:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82057A90:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82057AA0;
	sub_82065F78(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x820578ec
	if (!ctx.cr0.eq) goto loc_820578EC;
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82057ac8
	if (!ctx.cr6.eq) goto loc_82057AC8;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82057AC8;
	sub_820A71E8(ctx, base);
loc_82057AC8:
	// bl 0x820b5eb8
	ctx.lr = 0x82057ACC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82057ADC;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82057bac
	if (ctx.cr6.eq) goto loc_82057BAC;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// addi r9,r11,9472
	ctx.r9.s64 = ctx.r11.s64 + 9472;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
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
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stbx r24,r11,r8
	REX_STORE_U8(ctx.r11.u32 + ctx.r8.u32, ctx.r24.u8);
	// lwz r30,4(r26)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82057B2C;
	sub_82066F80(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// addi r11,r1,84
	ctx.r11.s64 = ctx.r1.s64 + 84;
	// stw r24,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r24.u32);
	// addi r9,r10,9448
	ctx.r9.s64 = ctx.r10.s64 + 9448;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
loc_82057B48:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82057b48
	if (!ctx.cr6.eq) goto loc_82057B48;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// bl 0x82129a70
	ctx.lr = 0x82057B78;
	sub_82129A70(ctx, base);
	// lwz r7,160(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// addi r10,r1,164
	ctx.r10.s64 = ctx.r1.s64 + 164;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// li r5,2004
	ctx.r5.s64 = 2004;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stbx r24,r7,r10
	REX_STORE_U8(ctx.r7.u32 + ctx.r10.u32, ctx.r24.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,9912(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9912);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,18296(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 18296);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82067c40
	ctx.lr = 0x82057BA4;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x82057bb0
	goto loc_82057BB0;
loc_82057BAC:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82057BB0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82057BC0;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82057be0
	if (!ctx.cr6.eq) goto loc_82057BE0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82057BE0;
	sub_820A71E8(ctx, base);
loc_82057BE0:
	// bl 0x820b5eb8
	ctx.lr = 0x82057BE4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82057BF4;
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
	// beq cr6,0x82057c3c
	if (ctx.cr6.eq) goto loc_82057C3C;
	// lwz r22,4(r26)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82057C18;
	sub_82066F80(ctx, base);
	// li r11,17
	ctx.r11.s64 = 17;
	// stw r22,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r22.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x82057C30;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82057c40
	goto loc_82057C40;
loc_82057C3C:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82057C40:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82057C50;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lbz r7,-22601(r27)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// li r9,26
	ctx.r9.s64 = 26;
	// addi r8,r10,-32520
	ctx.r8.s64 = ctx.r10.s64 + -32520;
	// stw r26,356(r28)
	REX_STORE_U32(ctx.r28.u32 + 356, ctx.r26.u32);
	// sth r9,390(r28)
	REX_STORE_U16(ctx.r28.u32 + 390, ctx.r9.u16);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r8,364(r28)
	REX_STORE_U32(ctx.r28.u32 + 364, ctx.r8.u32);
	// bne cr6,0x82057c88
	if (!ctx.cr6.eq) goto loc_82057C88;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82057C88;
	sub_820A71E8(ctx, base);
loc_82057C88:
	// bl 0x820b5eb8
	ctx.lr = 0x82057C8C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82057C9C;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82057cd0
	if (ctx.cr6.eq) goto loc_82057CD0;
	// lwz r22,4(r26)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82057CB0;
	sub_82066F80(ctx, base);
	// stw r22,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r22.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r24,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r24.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// bl 0x82067e00
	ctx.lr = 0x82057CC4;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82057cd4
	goto loc_82057CD4;
loc_82057CD0:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82057CD4:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82057CE4;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82057d04
	if (!ctx.cr6.eq) goto loc_82057D04;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82057D04;
	sub_820A71E8(ctx, base);
loc_82057D04:
	// bl 0x820b5eb8
	ctx.lr = 0x82057D08;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82057D18;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82057d50
	if (ctx.cr6.eq) goto loc_82057D50;
	// lwz r27,4(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82057D2C;
	sub_82066F80(ctx, base);
	// li r11,19
	ctx.r11.s64 = 19;
	// stw r27,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r27.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x82057D44;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x82057d54
	goto loc_82057D54;
loc_82057D50:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82057D54:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82057D64;
	sub_82065F78(ctx, base);
	// li r11,255
	ctx.r11.s64 = 255;
	// sth r11,16(r28)
	REX_STORE_U16(ctx.r28.u32 + 16, ctx.r11.u16);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
