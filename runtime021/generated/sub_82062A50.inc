DEFINE_REX_FUNC(sub_82062A50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x82062A58;
	__savegprlr_21(ctx, base);
	// stfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f30.u64);
	// stfd f31,-104(r1)
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32218
	ctx.r31.s64 = -2111438848;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r24,17
	ctx.r24.s64 = 17;
	// lis r26,-32215
	ctx.r26.s64 = -2111242240;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r10,-6596(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + -6596);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// sth r24,16(r30)
	REX_STORE_U16(ctx.r30.u32 + 16, ctx.r24.u16);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r22,r11,-1768
	ctx.r22.s64 = ctx.r11.s64 + -1768;
	// lbz r8,-22601(r26)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// lfs f0,18248(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18248);
	ctx.f0.f64 = double(temp.f32);
	// lwz r6,12(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
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
	// bne cr6,0x82062ac8
	if (!ctx.cr6.eq) goto loc_82062AC8;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062AC8;
	sub_820A71E8(ctx, base);
loc_82062AC8:
	// bl 0x820b5eb8
	ctx.lr = 0x82062ACC;
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
	ctx.lr = 0x82062AE4;
	sub_8209BDD8(ctx, base);
	// li r23,0
	ctx.r23.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82062b0c
	if (ctx.cr6.eq) goto loc_82062B0C;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x82062B04;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82062b10
	goto loc_82062B10;
loc_82062B0C:
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
loc_82062B10:
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
	ctx.lr = 0x82062B28;
	sub_82065F78(ctx, base);
	// lbz r10,-22601(r26)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82062b48
	if (!ctx.cr6.eq) goto loc_82062B48;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062B48;
	sub_820A71E8(ctx, base);
loc_82062B48:
	// bl 0x820b5eb8
	ctx.lr = 0x82062B4C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82062B5C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82062b80
	if (ctx.cr6.eq) goto loc_82062B80;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x82062B78;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82062b84
	goto loc_82062B84;
loc_82062B80:
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
loc_82062B84:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82062B94;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82062bb4
	if (!ctx.cr6.eq) goto loc_82062BB4;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062BB4;
	sub_820A71E8(ctx, base);
loc_82062BB4:
	// bl 0x820b5eb8
	ctx.lr = 0x82062BB8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82062BC8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82062bec
	if (ctx.cr6.eq) goto loc_82062BEC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x82062BE4;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82062bf0
	goto loc_82062BF0;
loc_82062BEC:
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
loc_82062BF0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82062C00;
	sub_82065F78(ctx, base);
	// lwz r11,-6596(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -6596);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,576
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 576, ctx.xer);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// bne cr6,0x82062c88
	if (!ctx.cr6.eq) goto loc_82062C88;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82062c30
	if (!ctx.cr6.eq) goto loc_82062C30;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062C30;
	sub_820A71E8(ctx, base);
loc_82062C30:
	// bl 0x820b5eb8
	ctx.lr = 0x82062C34;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82062C44;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82062cf8
	if (ctx.cr6.eq) goto loc_82062CF8;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18312
	ctx.r4.s64 = ctx.r11.s64 + 18312;
	// bl 0x82053a00
	ctx.lr = 0x82062C60;
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
	ctx.lr = 0x82062C80;
	sub_82067BC0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82062cfc
	goto loc_82062CFC;
loc_82062C88:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82062ca4
	if (!ctx.cr6.eq) goto loc_82062CA4;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062CA4;
	sub_820A71E8(ctx, base);
loc_82062CA4:
	// bl 0x820b5eb8
	ctx.lr = 0x82062CA8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82062CB8;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82062cf8
	if (ctx.cr6.eq) goto loc_82062CF8;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18312
	ctx.r4.s64 = ctx.r11.s64 + 18312;
	// bl 0x82053a00
	ctx.lr = 0x82062CD4;
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
	ctx.lr = 0x82062CF0;
	sub_82067BC0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82062cfc
	goto loc_82062CFC;
loc_82062CF8:
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
loc_82062CFC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82062D0C;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82062d2c
	if (!ctx.cr6.eq) goto loc_82062D2C;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062D2C;
	sub_820A71E8(ctx, base);
loc_82062D2C:
	// bl 0x820b5eb8
	ctx.lr = 0x82062D30;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82062D40;
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
	// beq cr6,0x82062d84
	if (ctx.cr6.eq) goto loc_82062D84;
	// lwz r21,4(r27)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82062D64;
	sub_82066F80(ctx, base);
	// stw r21,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r21.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r24,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r24.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// bl 0x82067e00
	ctx.lr = 0x82062D78;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// b 0x82062d88
	goto loc_82062D88;
loc_82062D84:
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
loc_82062D88:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82062D98;
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
	// bne cr6,0x82062dd0
	if (!ctx.cr6.eq) goto loc_82062DD0;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062DD0;
	sub_820A71E8(ctx, base);
loc_82062DD0:
	// bl 0x820b5eb8
	ctx.lr = 0x82062DD4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82062DE4;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82062e18
	if (ctx.cr6.eq) goto loc_82062E18;
	// lwz r26,4(r27)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82062DF8;
	sub_82066F80(ctx, base);
	// stw r26,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r26.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r23,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r23.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// bl 0x82067e00
	ctx.lr = 0x82062E0C;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// b 0x82062e1c
	goto loc_82062E1C;
loc_82062E18:
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
loc_82062E1C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82062E2C;
	sub_82065F78(ctx, base);
	// lhz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stw r27,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r27.u32);
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// addi r8,r10,14168
	ctx.r8.s64 = ctx.r10.s64 + 14168;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r6,30583
	ctx.r6.s64 = 2004287488;
	// stw r8,384(r30)
	REX_STORE_U32(ctx.r30.u32 + 384, ctx.r8.u32);
	// lis r5,-1
	ctx.r5.s64 = -65536;
	// ori r4,r6,30719
	ctx.r4.u64 = ctx.r6.u64 | 30719;
	// ori r3,r5,255
	ctx.r3.u64 = ctx.r5.u64 | 255;
	// lwzx r11,r7,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r30.u32);
	// stw r4,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r4.u32);
	// sth r23,8(r30)
	REX_STORE_U16(ctx.r30.u32 + 8, ctx.r23.u16);
	// lwz r10,20(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// stw r3,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r3.u32);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
