DEFINE_REX_FUNC(sub_82059EE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x82059EF0;
	__savegprlr_23(ctx, base);
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32215
	ctx.r29.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r25,r11,-1768
	ctx.r25.s64 = ctx.r11.s64 + -1768;
	// li r24,1
	ctx.r24.s64 = 1;
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// sth r24,16(r30)
	REX_STORE_U16(ctx.r30.u32 + 16, ctx.r24.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82059f34
	if (!ctx.cr6.eq) goto loc_82059F34;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82059F34;
	sub_820A71E8(ctx, base);
loc_82059F34:
	// bl 0x820b5eb8
	ctx.lr = 0x82059F38;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r27,r11,29632
	ctx.r27.s64 = ctx.r11.s64 + 29632;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r10,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82059F50;
	sub_8209BDD8(ctx, base);
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82059f6c
	if (ctx.cr6.eq) goto loc_82059F6C;
	// li r4,607
	ctx.r4.s64 = 607;
	// bl 0x82067778
	ctx.lr = 0x82059F64;
	sub_82067778(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82059f70
	goto loc_82059F70;
loc_82059F6C:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
loc_82059F70:
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
	ctx.lr = 0x82059F88;
	sub_82065F78(ctx, base);
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
loc_82059F8C:
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82059fac
	if (!ctx.cr6.eq) goto loc_82059FAC;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82059FAC;
	sub_820A71E8(ctx, base);
loc_82059FAC:
	// bl 0x820b5eb8
	ctx.lr = 0x82059FB0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82059FC0;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82059fe4
	if (ctx.cr6.eq) goto loc_82059FE4;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82067020
	ctx.lr = 0x82059FDC;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82059fe8
	goto loc_82059FE8;
loc_82059FE4:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
loc_82059FE8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82059FF8;
	sub_82065F78(ctx, base);
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// ble cr6,0x82059f8c
	if (!ctx.cr6.gt) goto loc_82059F8C;
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205a02c
	if (!ctx.cr6.eq) goto loc_8205A02C;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205A02C;
	sub_820A71E8(ctx, base);
loc_8205A02C:
	// bl 0x820b5eb8
	ctx.lr = 0x8205A030;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205A040;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8205a064
	if (ctx.cr6.eq) goto loc_8205A064;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82067020
	ctx.lr = 0x8205A05C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8205a068
	goto loc_8205A068;
loc_8205A064:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
loc_8205A068:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205A078;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lbz r5,-22601(r29)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// addi r8,r10,-18704
	ctx.r8.s64 = ctx.r10.s64 + -18704;
	// stw r28,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r28.u32);
	// addi r7,r9,-13584
	ctx.r7.s64 = ctx.r9.s64 + -13584;
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r8,384(r30)
	REX_STORE_U32(ctx.r30.u32 + 384, ctx.r8.u32);
	// stw r7,364(r30)
	REX_STORE_U32(ctx.r30.u32 + 364, ctx.r7.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// sth r6,390(r30)
	REX_STORE_U16(ctx.r30.u32 + 390, ctx.r6.u16);
	// bne cr6,0x8205a0b8
	if (!ctx.cr6.eq) goto loc_8205A0B8;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205A0B8;
	sub_820A71E8(ctx, base);
loc_8205A0B8:
	// bl 0x820b5eb8
	ctx.lr = 0x8205A0BC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205A0CC;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8205a110
	if (ctx.cr6.eq) goto loc_8205A110;
	// lwz r23,4(r28)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205A0E0;
	sub_82066F80(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r23,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r23.u32);
	// stw r26,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r26.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,9460
	ctx.r10.s64 = ctx.r11.s64 + 9460;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82067e00
	ctx.lr = 0x8205A0FC;
	sub_82067E00(ctx, base);
	// lis r9,-21846
	ctx.r9.s64 = -1431699456;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// ori r8,r9,43775
	ctx.r8.u64 = ctx.r9.u64 | 43775;
	// stw r8,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// b 0x8205a114
	goto loc_8205A114;
loc_8205A110:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
loc_8205A114:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205A124;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205a144
	if (!ctx.cr6.eq) goto loc_8205A144;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8205A144;
	sub_820A71E8(ctx, base);
loc_8205A144:
	// bl 0x820b5eb8
	ctx.lr = 0x8205A148;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwzx r3,r11,r27
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8205A158;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8205a220
	if (ctx.cr6.eq) goto loc_8205A220;
	// li r9,6
	ctx.r9.s64 = 6;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// addi r11,r11,9484
	ctx.r11.s64 = ctx.r11.s64 + 9484;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8205A17C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8205a17c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8205A17C;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r26,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r26.u8);
	// lwz r29,4(r28)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8205A1A8;
	sub_82066F80(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r11,r1,84
	ctx.r11.s64 = ctx.r1.s64 + 84;
	// stw r29,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// addi r8,r9,9448
	ctx.r8.s64 = ctx.r9.s64 + 9448;
	// stw r26,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r26.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
loc_8205A1C4:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8205a1c4
	if (!ctx.cr6.eq) goto loc_8205A1C4;
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
	ctx.lr = 0x8205A1F4;
	sub_82129A70(ctx, base);
	// lwz r9,160(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// addi r10,r1,164
	ctx.r10.s64 = ctx.r1.s64 + 164;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// li r5,2001
	ctx.r5.s64 = 2001;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r26,r9,r10
	REX_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r26.u8);
	// bl 0x82067c40
	ctx.lr = 0x8205A218;
	sub_82067C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// b 0x8205a224
	goto loc_8205A224;
loc_8205A220:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
loc_8205A224:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8205A234;
	sub_82065F78(ctx, base);
	// stb r24,14(r30)
	REX_STORE_U8(ctx.r30.u32 + 14, ctx.r24.u8);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
