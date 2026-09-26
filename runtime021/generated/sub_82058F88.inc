DEFINE_REX_FUNC(sub_82058F88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x82058F90;
	__savegprlr_22(ctx, base);
	// stfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f30.u64);
	// stfd f31,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r23,1
	ctx.r23.s64 = 1;
	// lis r28,-32215
	ctx.r28.s64 = -2111242240;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r10,-6596(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -6596);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// sth r23,16(r30)
	REX_STORE_U16(ctx.r30.u32 + 16, ctx.r23.u16);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r24,r11,-1768
	ctx.r24.s64 = ctx.r11.s64 + -1768;
	// lbz r8,-22601(r28)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r28.u32 + -22601);
	// lfs f0,18248(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18248);
	ctx.f0.f64 = double(temp.f32);
	// lwz r7,12(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// subfic r6,r7,848
	ctx.xer.ca = ctx.r7.u32 <= 848;
	ctx.r6.u64 = static_cast<uint64_t>(848) - ctx.r7.u64;
	// clrldi r5,r6,32
	ctx.r5.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// std r5,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f30,f11,f0
	ctx.f30.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// bne cr6,0x82059008
	if (!ctx.cr6.eq) goto loc_82059008;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82059008;
	sub_820A71E8(ctx, base);
loc_82059008:
	// bl 0x820b5eb8
	ctx.lr = 0x8205900C;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r25,r11,29632
	ctx.r25.s64 = ctx.r11.s64 + 29632;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r10,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82059024;
	sub_8209BDD8(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r26,r11,9448
	ctx.r26.s64 = ctx.r11.s64 + 9448;
	// lfs f31,9536(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// beq cr6,0x82059098
	if (ctx.cr6.eq) goto loc_82059098;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,9492
	ctx.r4.s64 = ctx.r11.s64 + 9492;
	// bl 0x82053a00
	ctx.lr = 0x82059050;
	sub_82053A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r22,4(r29)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205905C;
	sub_82066F80(ctx, base);
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r22,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r22.u32);
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// stw r26,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// stw r27,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r27.u32);
	// bl 0x82053a00
	ctx.lr = 0x82059078;
	sub_82053A00(ctx, base);
	// li r5,2015
	ctx.r5.s64 = 2015;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fneg f1,f30
	ctx.f1.u64 = ctx.f30.u64 ^ 0x8000000000000000;
	// bl 0x82067c40
	ctx.lr = 0x82059090;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x820590a0
	goto loc_820590A0;
loc_82059098:
	// li r27,0
	ctx.r27.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
loc_820590A0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820590B0;
	sub_82065F78(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lbz r7,-22601(r28)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r28.u32 + -22601);
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r8,r10,20768
	ctx.r8.s64 = ctx.r10.s64 + 20768;
	// stw r29,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r29.u32);
	// sth r9,390(r30)
	REX_STORE_U16(ctx.r30.u32 + 390, ctx.r9.u16);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r8,364(r30)
	REX_STORE_U32(ctx.r30.u32 + 364, ctx.r8.u32);
	// bne cr6,0x820590e8
	if (!ctx.cr6.eq) goto loc_820590E8;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820590E8;
	sub_820A71E8(ctx, base);
loc_820590E8:
	// bl 0x820b5eb8
	ctx.lr = 0x820590EC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820590FC;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82059140
	if (ctx.cr6.eq) goto loc_82059140;
	// lwz r22,4(r29)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x82059110;
	sub_82066F80(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r22,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r22.u32);
	// stw r27,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,9460
	ctx.r10.s64 = ctx.r11.s64 + 9460;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82067e00
	ctx.lr = 0x8205912C;
	sub_82067E00(ctx, base);
	// lis r9,-21846
	ctx.r9.s64 = -1431699456;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// ori r8,r9,43775
	ctx.r8.u64 = ctx.r9.u64 | 43775;
	// stw r8,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// b 0x82059144
	goto loc_82059144;
loc_82059140:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
loc_82059144:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82059154;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82059174
	if (!ctx.cr6.eq) goto loc_82059174;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82059174;
	sub_820A71E8(ctx, base);
loc_82059174:
	// bl 0x820b5eb8
	ctx.lr = 0x82059178;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82059188;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820591e8
	if (ctx.cr6.eq) goto loc_820591E8;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r4,r11,9484
	ctx.r4.s64 = ctx.r11.s64 + 9484;
	// bl 0x82053a00
	ctx.lr = 0x820591A4;
	sub_82053A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r29,4(r29)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x820591B0;
	sub_82066F80(ctx, base);
	// addi r4,r1,180
	ctx.r4.s64 = ctx.r1.s64 + 180;
	// stw r29,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r26,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// stw r27,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r27.u32);
	// bl 0x82053a00
	ctx.lr = 0x820591C8;
	sub_82053A00(ctx, base);
	// li r5,2001
	ctx.r5.s64 = 2001;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82067c40
	ctx.lr = 0x820591E0;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x820591ec
	goto loc_820591EC;
loc_820591E8:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
loc_820591EC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820591FC;
	sub_82065F78(ctx, base);
	// stb r23,14(r30)
	REX_STORE_U8(ctx.r30.u32 + 14, ctx.r23.u8);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
