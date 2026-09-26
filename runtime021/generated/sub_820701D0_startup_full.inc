DEFINE_REX_FUNC(sub_820701D0_startup_full) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x820701D8;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// addi r25,r11,-22592
	ctx.r25.s64 = ctx.r11.s64 + -22592;
	// addi r23,r10,-1768
	ctx.r23.s64 = ctx.r10.s64 + -1768;
	// lbz r11,-9(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -9);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207020c
	if (!ctx.cr6.eq) goto loc_8207020C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8207020C;
	sub_820A71E8(ctx, base);
loc_8207020C:
	// bl 0x820b5eb8
	ctx.lr = 0x82070210;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r24,r11,29632
	ctx.r24.s64 = ctx.r11.s64 + 29632;
	// li r4,28
	ctx.r4.s64 = 28;
	// lwzx r3,r10,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82070228;
	sub_8209BDD8(ctx, base);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82070244
	if (ctx.cr6.eq) goto loc_82070244;
	// bl 0x8209c588
	ctx.lr = 0x82070238;
	sub_8209C588(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// stw r3,-6608(r11)
	REX_STORE_U32(ctx.r11.u32 + -6608, ctx.r3.u32);
	// b 0x82070250
	goto loc_82070250;
loc_82070244:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r11,-6608(r10)
	REX_STORE_U32(ctx.r10.u32 + -6608, ctx.r11.u32);
loc_82070250:
	// lbz r11,-9(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -9);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82070270
	if (!ctx.cr6.eq) goto loc_82070270;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82070270;
	sub_820A71E8(ctx, base);
loc_82070270:
	// bl 0x820b5eb8
	ctx.lr = 0x82070274;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,28
	ctx.r4.s64 = 28;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82070284;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// beq cr6,0x820702bc
	if (ctx.cr6.eq) goto loc_820702BC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stb r28,4(r3)
	REX_STORE_U8(ctx.r3.u32 + 4, ctx.r28.u8);
	// stb r28,24(r3)
	REX_STORE_U8(ctx.r3.u32 + 24, ctx.r28.u8);
	// addi r9,r11,-364
	ctx.r9.s64 = ctx.r11.s64 + -364;
	// stw r3,-6652(r10)
	REX_STORE_U32(ctx.r10.u32 + -6652, ctx.r3.u32);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r28,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r28.u32);
	// stw r28,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r28.u32);
	// stw r28,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r28.u32);
	// stw r28,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r28.u32);
	// b 0x820702c4
	goto loc_820702C4;
loc_820702BC:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r11,-6652(r10)
	REX_STORE_U32(ctx.r10.u32 + -6652, ctx.r11.u32);
loc_820702C4:
	// lbz r11,-9(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -9);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820702e4
	if (!ctx.cr6.eq) goto loc_820702E4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820702E4;
	sub_820A71E8(ctx, base);
loc_820702E4:
	// bl 0x820b5eb8
	ctx.lr = 0x820702E8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,1780
	ctx.r4.s64 = 1780;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820702F8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82070310
	if (ctx.cr6.eq) goto loc_82070310;
	// bl 0x82075410
	ctx.lr = 0x82070304;
	sub_82075410(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// stw r3,-6624(r11)
	REX_STORE_U32(ctx.r11.u32 + -6624, ctx.r3.u32);
	// b 0x8207031c
	goto loc_8207031C;
loc_82070310:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r11,-6624(r10)
	REX_STORE_U32(ctx.r10.u32 + -6624, ctx.r11.u32);
loc_8207031C:
	// lbz r11,-9(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -9);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207033c
	if (!ctx.cr6.eq) goto loc_8207033C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8207033C;
	sub_820A71E8(ctx, base);
loc_8207033C:
	// bl 0x820b5eb8
	ctx.lr = 0x82070340;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82070350;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820703b0
	if (ctx.cr6.eq) goto loc_820703B0;
	// lis r11,18
	ctx.r11.s64 = 1179648;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// ori r3,r11,54919
	ctx.r3.u64 = ctx.r11.u64 | 54919;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r8,32767
	ctx.r8.s64 = 2147418112;
	// addi r7,r10,-15552
	ctx.r7.s64 = ctx.r10.s64 + -15552;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r9,-15480
	ctx.r5.s64 = ctx.r9.s64 + -15480;
	// stw r7,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r7.u32);
	// ori r4,r8,65535
	ctx.r4.u64 = ctx.r8.u64 | 65535;
	// stw r6,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// rotlwi r11,r7,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r5,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// stw r4,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8207039C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r11,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r11.u32);
	// stw r31,-6644(r10)
	REX_STORE_U32(ctx.r10.u32 + -6644, ctx.r31.u32);
	// b 0x820703bc
	goto loc_820703BC;
loc_820703B0:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r11,-6644(r10)
	REX_STORE_U32(ctx.r10.u32 + -6644, ctx.r11.u32);
loc_820703BC:
	// lbz r11,-9(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -9);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820703dc
	if (!ctx.cr6.eq) goto loc_820703DC;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820703DC;
	sub_820A71E8(ctx, base);
loc_820703DC:
	// bl 0x820b5eb8
	ctx.lr = 0x820703E0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,14656
	ctx.r4.s64 = 14656;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820703F0;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82070408
	if (ctx.cr6.eq) goto loc_82070408;
	// bl 0x82095c20
	ctx.lr = 0x820703FC;
	sub_82095C20(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// stw r3,-6656(r11)
	REX_STORE_U32(ctx.r11.u32 + -6656, ctx.r3.u32);
	// b 0x82070414
	goto loc_82070414;
loc_82070408:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r11,-6656(r10)
	REX_STORE_U32(ctx.r10.u32 + -6656, ctx.r11.u32);
loc_82070414:
	// lbz r11,-9(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -9);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82070434
	if (!ctx.cr6.eq) goto loc_82070434;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82070434;
	sub_820A71E8(ctx, base);
loc_82070434:
	// bl 0x820b5eb8
	ctx.lr = 0x82070438;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,140
	ctx.r4.s64 = 140;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82070448;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820704b8
	if (ctx.cr6.eq) goto loc_820704B8;
	// stb r28,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// addi r30,r31,76
	ctx.r30.s64 = ctx.r31.s64 + 76;
	// stb r28,1(r31)
	REX_STORE_U8(ctx.r31.u32 + 1, ctx.r28.u8);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82097650
	ctx.lr = 0x82070468;
	sub_82097650(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r28,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r28.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r28,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r28.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// lfs f0,18080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18080);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 100, temp.u32);
	// stfs f0,104(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 104, temp.u32);
	// stfs f0,108(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
	// stw r28,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r28.u32);
	// stw r28,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r28.u32);
	// stw r28,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r28.u32);
	// stw r28,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r28.u32);
	// stw r28,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// bl 0x82097720
	ctx.lr = 0x820704A8;
	sub_82097720(ctx, base);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// stw r3,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// stw r31,-6612(r10)
	REX_STORE_U32(ctx.r10.u32 + -6612, ctx.r31.u32);
	// b 0x820704c4
	goto loc_820704C4;
loc_820704B8:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r11,-6612(r10)
	REX_STORE_U32(ctx.r10.u32 + -6612, ctx.r11.u32);
loc_820704C4:
	// lbz r11,-9(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -9);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820704e4
	if (!ctx.cr6.eq) goto loc_820704E4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820704E4;
	sub_820A71E8(ctx, base);
loc_820704E4:
	// bl 0x820b5eb8
	ctx.lr = 0x820704E8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,20
	ctx.r4.s64 = 20;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820704F8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82070518
	if (ctx.cr6.eq) goto loc_82070518;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// stb r28,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r28.u8);
	// stw r28,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r28.u32);
	// stw r28,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r28.u32);
	// stw r3,-6636(r11)
	REX_STORE_U32(ctx.r11.u32 + -6636, ctx.r3.u32);
	// b 0x82070524
	goto loc_82070524;
loc_82070518:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r11,-6636(r10)
	REX_STORE_U32(ctx.r10.u32 + -6636, ctx.r11.u32);
loc_82070524:
	// lbz r11,-9(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -9);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82070544
	if (!ctx.cr6.eq) goto loc_82070544;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82070544;
	sub_820A71E8(ctx, base);
loc_82070544:
	// bl 0x820b5eb8
	ctx.lr = 0x82070548;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82070558;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82070570
	if (ctx.cr6.eq) goto loc_82070570;
	// bl 0x8209ced0
	ctx.lr = 0x82070564;
	sub_8209CED0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// stw r3,-6604(r11)
	REX_STORE_U32(ctx.r11.u32 + -6604, ctx.r3.u32);
	// b 0x8207057c
	goto loc_8207057C;
loc_82070570:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r11,-6604(r10)
	REX_STORE_U32(ctx.r10.u32 + -6604, ctx.r11.u32);
loc_8207057C:
	// lbz r11,-9(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -9);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207059c
	if (!ctx.cr6.eq) goto loc_8207059C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8207059C;
	sub_820A71E8(ctx, base);
loc_8207059C:
	// bl 0x820b5eb8
	ctx.lr = 0x820705A0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,1424
	ctx.r4.s64 = 1424;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820705B0;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820705c8
	if (ctx.cr6.eq) goto loc_820705C8;
	// bl 0x820a1ac0
	ctx.lr = 0x820705BC;
	sub_820A1AC0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// stw r3,-6628(r11)
	REX_STORE_U32(ctx.r11.u32 + -6628, ctx.r3.u32);
	// b 0x820705d4
	goto loc_820705D4;
loc_820705C8:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r11,-6628(r10)
	REX_STORE_U32(ctx.r10.u32 + -6628, ctx.r11.u32);
loc_820705D4:
	// lbz r11,-9(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -9);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820705f4
	if (!ctx.cr6.eq) goto loc_820705F4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820705F4;
	sub_820A71E8(ctx, base);
loc_820705F4:
	// bl 0x820b5eb8
	ctx.lr = 0x820705F8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// ori r4,r4,46992
	ctx.r4.u64 = ctx.r4.u64 | 46992;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8207060C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82070624
	if (ctx.cr6.eq) goto loc_82070624;
	// bl 0x8208cfa0
	ctx.lr = 0x82070618;
	sub_8208CFA0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// stw r3,-6648(r11)
	REX_STORE_U32(ctx.r11.u32 + -6648, ctx.r3.u32);
	// b 0x82070630
	goto loc_82070630;
loc_82070624:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r11,-6648(r10)
	REX_STORE_U32(ctx.r10.u32 + -6648, ctx.r11.u32);
loc_82070630:
	// lbz r11,-9(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -9);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82070650
	if (!ctx.cr6.eq) goto loc_82070650;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82070650;
	sub_820A71E8(ctx, base);
loc_82070650:
	// bl 0x820b5eb8
	ctx.lr = 0x82070654;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// ori r4,r4,59652
	ctx.r4.u64 = ctx.r4.u64 | 59652;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82070668;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82070684
	if (ctx.cr6.eq) goto loc_82070684;
	// bl 0x8209f7e8
	ctx.lr = 0x82070674;
	sub_8209F7E8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r26,r11,-6596
	ctx.r26.s64 = ctx.r11.s64 + -6596;
	// stw r3,-6596(r11)
	REX_STORE_U32(ctx.r11.u32 + -6596, ctx.r3.u32);
	// b 0x82070694
	goto loc_82070694;
loc_82070684:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// addi r26,r10,-6596
	ctx.r26.s64 = ctx.r10.s64 + -6596;
	// stw r11,-6596(r10)
	REX_STORE_U32(ctx.r10.u32 + -6596, ctx.r11.u32);
loc_82070694:
	// lbz r11,-9(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -9);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820706b4
	if (!ctx.cr6.eq) goto loc_820706B4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820706B4;
	sub_820A71E8(ctx, base);
loc_820706B4:
	// bl 0x820b5eb8
	ctx.lr = 0x820706B8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,20
	ctx.r4.s64 = 20;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820706C8;
	sub_8209BDD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82070780
	if (ctx.cr6.eq) goto loc_82070780;
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// stw r11,-22672(r9)
	REX_STORE_U32(ctx.r9.u32 + -22672, ctx.r11.u32);
	// addi r3,r7,-22712
	ctx.r3.s64 = ctx.r7.s64 + -22712;
	// stw r10,-22684(r8)
	REX_STORE_U32(ctx.r8.u32 + -22684, ctx.r10.u32);
	// bl 0x8214a424
	ctx.lr = 0x820706F8;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// stw r28,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r28.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// stw r28,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r28.u32);
	// addi r11,r5,-22680
	ctx.r11.s64 = ctx.r5.s64 + -22680;
	// stw r28,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r28.u32);
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// stw r28,12(r29)
	REX_STORE_U32(ctx.r29.u32 + 12, ctx.r28.u32);
	// addi r27,r11,-1
	ctx.r27.s64 = ctx.r11.s64 + -1;
	// stw r28,16(r29)
	REX_STORE_U32(ctx.r29.u32 + 16, ctx.r28.u32);
loc_82070720:
	// addi r30,r6,1
	ctx.r30.s64 = ctx.r6.s64 + 1;
	// lis r11,-32245
	ctx.r11.s64 = -2113208320;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r5,r11,3712
	ctx.r5.s64 = ctx.r11.s64 + 3712;
	// stbx r28,r27,r30
	REX_STORE_U8(ctx.r27.u32 + ctx.r30.u32, ctx.r28.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820b5d60
	ctx.lr = 0x82070744;
	sub_820B5D60(ctx, base);
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x820b5d70
	ctx.lr = 0x82070750;
	sub_820B5D70(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x820b5e08
	ctx.lr = 0x8207075C;
	sub_820B5E08(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x820b6028
	ctx.lr = 0x82070764;
	sub_820B6028(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r30,5
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 5, ctx.xer);
	// blt cr6,0x82070720
	if (ctx.cr6.lt) goto loc_82070720;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// stw r29,-6600(r11)
	REX_STORE_U32(ctx.r11.u32 + -6600, ctx.r29.u32);
	// b 0x82070788
	goto loc_82070788;
loc_82070780:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// stw r11,-6600(r10)
	REX_STORE_U32(ctx.r10.u32 + -6600, ctx.r11.u32);
loc_82070788:
	// lbz r11,-9(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -9);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820707a8
	if (!ctx.cr6.eq) goto loc_820707A8;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820707A8;
	sub_820A71E8(ctx, base);
loc_820707A8:
	// bl 0x820b5eb8
	ctx.lr = 0x820707AC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820707BC;
	sub_8209BDD8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r31,r11,-6640
	ctx.r31.s64 = ctx.r11.s64 + -6640;
	// beq cr6,0x820707e0
	if (ctx.cr6.eq) goto loc_820707E0;
	// stw r28,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r28.u32);
	// stw r28,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r28.u32);
	// stw r28,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r28.u32);
	// stw r28,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r28.u32);
	// b 0x820707e4
	goto loc_820707E4;
loc_820707E0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_820707E4:
	// stw r3,-6640(r11)
	REX_STORE_U32(ctx.r11.u32 + -6640, ctx.r3.u32);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r7,613
	ctx.r7.s64 = 613;
	// addi r5,r11,-26312
	ctx.r5.s64 = ctx.r11.s64 + -26312;
	// li r6,613
	ctx.r6.s64 = 613;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x8209d688
	ctx.lr = 0x82070800;
	sub_8209D688(ctx, base);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8207081c
	if (!ctx.cr6.lt) goto loc_8207081C;
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
loc_8207081C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
