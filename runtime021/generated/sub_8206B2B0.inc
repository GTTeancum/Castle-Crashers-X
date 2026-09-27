DEFINE_REX_FUNC(sub_8206B2B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x8206B2B8;
	__savegprlr_23(ctx, base);
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32215
	ctx.r27.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r24,r11,-1768
	ctx.r24.s64 = ctx.r11.s64 + -1768;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206b2f4
	if (!ctx.cr6.eq) goto loc_8206B2F4;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206B2F4;
	sub_820A71E8(ctx, base);
loc_8206B2F4:
	// bl 0x820b5eb8
	ctx.lr = 0x8206B2F8;
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
	ctx.lr = 0x8206B310;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206b328
	if (ctx.cr6.eq) goto loc_8206B328;
	// li r4,582
	ctx.r4.s64 = 582;
	// bl 0x82067778
	ctx.lr = 0x8206B320;
	sub_82067778(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206b32c
	goto loc_8206B32C;
loc_8206B328:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206B32C:
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
	ctx.lr = 0x8206B344;
	sub_82065F78(ctx, base);
	// lbz r10,-22601(r27)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8206b364
	if (!ctx.cr6.eq) goto loc_8206B364;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206B364;
	sub_820A71E8(ctx, base);
loc_8206B364:
	// bl 0x820b5eb8
	ctx.lr = 0x8206B368;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206B378;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206b3a0
	if (ctx.cr6.eq) goto loc_8206B3A0;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,593
	ctx.r6.s64 = 593;
	// addi r5,r11,-10160
	ctx.r5.s64 = ctx.r11.s64 + -10160;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067020
	ctx.lr = 0x8206B398;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206b3a4
	goto loc_8206B3A4;
loc_8206B3A0:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206B3A4:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206B3B4;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206b3d4
	if (!ctx.cr6.eq) goto loc_8206B3D4;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206B3D4;
	sub_820A71E8(ctx, base);
loc_8206B3D4:
	// bl 0x820b5eb8
	ctx.lr = 0x8206B3D8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206B3E8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206b410
	if (ctx.cr6.eq) goto loc_8206B410;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,589
	ctx.r6.s64 = 589;
	// addi r5,r11,-32456
	ctx.r5.s64 = ctx.r11.s64 + -32456;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067020
	ctx.lr = 0x8206B408;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206b414
	goto loc_8206B414;
loc_8206B410:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206B414:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206B424;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206b444
	if (!ctx.cr6.eq) goto loc_8206B444;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206B444;
	sub_820A71E8(ctx, base);
loc_8206B444:
	// bl 0x820b5eb8
	ctx.lr = 0x8206B448;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206B458;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206b480
	if (ctx.cr6.eq) goto loc_8206B480;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,465
	ctx.r6.s64 = 465;
	// addi r5,r11,27120
	ctx.r5.s64 = ctx.r11.s64 + 27120;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82067020
	ctx.lr = 0x8206B478;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206b484
	goto loc_8206B484;
loc_8206B480:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206B484:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206B494;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206b4b4
	if (!ctx.cr6.eq) goto loc_8206B4B4;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206B4B4;
	sub_820A71E8(ctx, base);
loc_8206B4B4:
	// bl 0x820b5eb8
	ctx.lr = 0x8206B4B8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206B4C8;
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
	// beq cr6,0x8206b510
	if (ctx.cr6.eq) goto loc_8206B510;
	// lwz r23,4(r26)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8206B4EC;
	sub_82066F80(ctx, base);
	// li r11,17
	ctx.r11.s64 = 17;
	// stw r23,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r23.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x8206B504;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8206b514
	goto loc_8206B514;
loc_8206B510:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206B514:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206B524;
	sub_82065F78(ctx, base);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lbz r7,-22601(r27)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// li r9,25
	ctx.r9.s64 = 25;
	// addi r8,r10,-17448
	ctx.r8.s64 = ctx.r10.s64 + -17448;
	// stw r26,356(r28)
	REX_STORE_U32(ctx.r28.u32 + 356, ctx.r26.u32);
	// sth r9,390(r28)
	REX_STORE_U16(ctx.r28.u32 + 390, ctx.r9.u16);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r8,364(r28)
	REX_STORE_U32(ctx.r28.u32 + 364, ctx.r8.u32);
	// bne cr6,0x8206b55c
	if (!ctx.cr6.eq) goto loc_8206B55C;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206B55C;
	sub_820A71E8(ctx, base);
loc_8206B55C:
	// bl 0x820b5eb8
	ctx.lr = 0x8206B560;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206B570;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8206b5a8
	if (ctx.cr6.eq) goto loc_8206B5A8;
	// lwz r27,4(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8206B584;
	sub_82066F80(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r27,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r27.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x8206B59C;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8206b5ac
	goto loc_8206B5AC;
loc_8206B5A8:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206B5AC:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206B5BC;
	sub_82065F78(ctx, base);
	// li r11,255
	ctx.r11.s64 = 255;
	// sth r11,16(r28)
	REX_STORE_U16(ctx.r28.u32 + 16, ctx.r11.u16);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
