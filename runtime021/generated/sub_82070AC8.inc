DEFINE_REX_FUNC(sub_82070AC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x82070AD0;
	__savegprlr_24(ctx, base);
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x820701d0
	ctx.lr = 0x82070AE0;
	sub_820701D0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r3,r11,26304
	ctx.r3.s64 = ctx.r11.s64 + 26304;
	// bl 0x8214a424
	ctx.lr = 0x82070AEC;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r9,-32234
	ctx.r9.s64 = -2112487424;
	// lis r8,-32234
	ctx.r8.s64 = -2112487424;
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r11,r11,29584
	ctx.r11.s64 = ctx.r11.s64 + 29584;
	// addi r10,r10,29696
	ctx.r10.s64 = ctx.r10.s64 + 29696;
	// stw r11,-28292(r9)
	REX_STORE_U32(ctx.r9.u32 + -28292, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,-28288(r8)
	REX_STORE_U32(ctx.r8.u32 + -28288, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8209a728
	ctx.lr = 0x82070B18;
	sub_8209A728(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// li r27,1
	ctx.r27.s64 = 1;
	// lwz r3,-6652(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + -6652);
	// stb r27,4(r3)
	REX_STORE_U8(ctx.r3.u32 + 4, ctx.r27.u8);
	// bl 0x8209b458
	ctx.lr = 0x82070B2C;
	sub_8209B458(ctx, base);
	// lis r29,-32215
	ctx.r29.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r26,r11,-1768
	ctx.r26.s64 = ctx.r11.s64 + -1768;
	// lbz r6,-22601(r29)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x82070b58
	if (!ctx.cr6.eq) goto loc_82070B58;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82070B58;
	sub_820A71E8(ctx, base);
loc_82070B58:
	// bl 0x820b5eb8
	ctx.lr = 0x82070B5C;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r25,r11,29632
	ctx.r25.s64 = ctx.r11.s64 + 29632;
	// li r4,30216
	ctx.r4.s64 = 30216;
	// lwzx r3,r10,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82070B74;
	sub_8209BDD8(ctx, base);
	// li r24,0
	ctx.r24.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82070b8c
	if (ctx.cr6.eq) goto loc_82070B8C;
	// bl 0x820a7668
	ctx.lr = 0x82070B84;
	sub_820A7668(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82070b90
	goto loc_82070B90;
loc_82070B8C:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82070B90:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r31,r11,-6616
	ctx.r31.s64 = ctx.r11.s64 + -6616;
	// stw r4,-6616(r11)
	REX_STORE_U32(ctx.r11.u32 + -6616, ctx.r4.u32);
	// bl 0x820a7990
	ctx.lr = 0x82070BA4;
	sub_820A7990(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,4096
	ctx.r6.s64 = 4096;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,256
	ctx.r4.s64 = 16777216;
	// lwz r11,-6656(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6656);
	// lwz r3,136(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// bl 0x8209bc98
	ctx.lr = 0x82070BC4;
	sub_8209BC98(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r4,r10,-9040
	ctx.r4.s64 = ctx.r10.s64 + -9040;
	// bl 0x82053a00
	ctx.lr = 0x82070BD4;
	sub_82053A00(ctx, base);
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r11,-6604(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6604);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r3,r11,212
	ctx.r3.s64 = ctx.r11.s64 + 212;
	// bl 0x820a9b58
	ctx.lr = 0x82070BEC;
	sub_820A9B58(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f31,9536(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r7,12(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82070C0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r6,-32218
	ctx.r6.s64 = -2111438848;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r8,-32221
	ctx.r8.s64 = -2111635456;
	// lwz r3,-6604(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6604);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r27,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,-6596(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + -6596);
	// li r6,140
	ctx.r6.s64 = 140;
	// lfs f2,9540(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 9540);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// lbz r7,9(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 9);
	// subfic r5,r7,0
	ctx.xer.ca = ctx.r7.u32 <= 0;
	ctx.r5.u64 = static_cast<uint64_t>(0) - ctx.r7.u64;
	// subfe r11,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r5.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r11,0,25,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x78;
	// rlwinm r11,r11,0,28,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// lwz r8,-26316(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + -26316);
	// addi r5,r11,51
	ctx.r5.s64 = ctx.r11.s64 + 51;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x8209d028
	ctx.lr = 0x82070C60;
	sub_8209D028(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82070C78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r4,-6612(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + -6612);
	// bl 0x82096828
	ctx.lr = 0x82070C8C;
	sub_82096828(ctx, base);
	// lis r28,-32218
	ctx.r28.s64 = -2111438848;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r3,-6624(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -6624);
	// bl 0x820756e0
	ctx.lr = 0x82070C9C;
	sub_820756E0(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r6,r7,-9056
	ctx.r6.s64 = ctx.r7.s64 + -9056;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820b5f50
	ctx.lr = 0x82070CB4;
	sub_820B5F50(ctx, base);
	// lis r6,-32218
	ctx.r6.s64 = -2111438848;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r5,r5,2088
	ctx.r5.s64 = ctx.r5.s64 + 2088;
	// stw r3,-6620(r6)
	REX_STORE_U32(ctx.r6.u32 + -6620, ctx.r3.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820b5d60
	ctx.lr = 0x82070CDC;
	sub_820B5D60(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x820b5d70
	ctx.lr = 0x82070CE8;
	sub_820B5D70(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820b6028
	ctx.lr = 0x82070CF0;
	sub_820B6028(ctx, base);
	// lis r4,-32218
	ctx.r4.s64 = -2111438848;
	// lbz r3,-22601(r29)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lwz r30,-6636(r4)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r4.u32 + -6636);
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r26,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r26.u32);
	// bne cr6,0x82070d20
	if (!ctx.cr6.eq) goto loc_82070D20;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82070D20;
	sub_820A71E8(ctx, base);
loc_82070D20:
	// bl 0x820b5eb8
	ctx.lr = 0x82070D24;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,12
	ctx.r4.s64 = 12;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82070D34;
	sub_8209BDD8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82070d50
	if (ctx.cr6.eq) goto loc_82070D50;
	// stb r24,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r24.u8);
	// stw r24,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r24.u32);
	// stb r24,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r24.u8);
	// b 0x82070d54
	goto loc_82070D54;
loc_82070D50:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_82070D54:
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// stw r31,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stb r27,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r27.u8);
	// stb r27,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r27.u8);
	// lwz r4,-6628(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + -6628);
	// bl 0x820a1bf8
	ctx.lr = 0x82070D74;
	sub_820A1BF8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6624(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -6624);
	// bl 0x820757c8
	ctx.lr = 0x82070D80;
	sub_820757C8(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f31,9724(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9724);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x820b6d10
	ctx.lr = 0x82070D90;
	sub_820B6D10(ctx, base);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x820b6d48
	ctx.lr = 0x82070D98;
	sub_820B6D48(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// ld r27,96(r1)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lis r29,-32215
	ctx.r29.s64 = -2111242240;
	// addi r30,r11,18268
	ctx.r30.s64 = ctx.r11.s64 + 18268;
	// lfs f30,9732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9732);
	ctx.f30.f64 = double(temp.f32);
loc_82070DB0:
	// lwz r9,-6624(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + -6624);
	// lwz r10,52(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 52);
	// lwz r11,56(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 56);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82070dcc
	if (!ctx.cr6.gt) goto loc_82070DCC;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82070DCC:
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82070de0
	if (ctx.cr6.gt) goto loc_82070DE0;
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82070de4
	if (!ctx.cr6.lt) goto loc_82070DE4;
loc_82070DE0:
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82070DE4:
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// rlwinm r10,r7,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFF;
	// clrlwi r8,r7,30
	ctx.r8.u64 = ctx.r7.u32 & 0x3;
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82070dfc
	if (ctx.cr6.lt) goto loc_82070DFC;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82070DFC:
	// lwz r11,48(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 48);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82070e0c
	if (ctx.cr6.gt) goto loc_82070E0C;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
loc_82070E0C:
	// lwz r11,44(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 44);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwzx r7,r8,r9
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// cmpwi cr6,r7,7
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 7, ctx.xer);
	// beq cr6,0x82070f0c
	if (ctx.cr6.eq) goto loc_82070F0C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x820b6d48
	ctx.lr = 0x82070E30;
	sub_820B6D48(ctx, base);
	// lwz r3,-6624(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -6624);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// ld r31,96(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x82075c88
	ctx.lr = 0x82070E40;
	sub_82075C88(ctx, base);
	// lbz r11,-22661(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22661);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82070ee0
	if (!ctx.cr6.eq) goto loc_82070EE0;
	// lwz r3,-6624(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -6624);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x820759a8
	ctx.lr = 0x82070E58;
	sub_820759A8(ctx, base);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x820b6d48
	ctx.lr = 0x82070E60;
	sub_820B6D48(ctx, base);
	// ld r3,104(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// bl 0x8212b180
	ctx.lr = 0x82070E68;
	sub_8212B180(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x8212b180
	ctx.lr = 0x82070E74;
	sub_8212B180(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fsub f31,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f31.f64 - ctx.f1.f64;
	// bl 0x8212b180
	ctx.lr = 0x82070E80;
	sub_8212B180(ctx, base);
	// fdiv f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64 / ctx.f1.f64;
	// lfs f0,-4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// frsp f31,f13
	ctx.f31.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bge cr6,0x82070eb0
	if (!ctx.cr6.lt) goto loc_82070EB0;
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// fmuls f13,f0,f30
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f12.u64);
	// lwz r3,116(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bge cr6,0x82070eb4
	if (!ctx.cr6.lt) goto loc_82070EB4;
loc_82070EB0:
	// li r3,2
	ctx.r3.s64 = 2;
loc_82070EB4:
	// bl 0x820b6068
	ctx.lr = 0x82070EB8;
	sub_820B6068(ctx, base);
	// lfs f0,-4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bgt cr6,0x82070ecc
	if (ctx.cr6.gt) goto loc_82070ECC;
	// fmr f31,f0
	ctx.f31.f64 = ctx.f0.f64;
	// b 0x82070db0
	goto loc_82070DB0;
loc_82070ECC:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// blt cr6,0x82070db0
	if (ctx.cr6.lt) goto loc_82070DB0;
	// fmr f31,f0
	ctx.f31.f64 = ctx.f0.f64;
	// b 0x82070db0
	goto loc_82070DB0;
loc_82070EE0:
	// lwz r31,-6624(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + -6624);
	// lbz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82070f08
	if (ctx.cr6.eq) goto loc_82070F08;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82070F04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r24,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r24.u8);
loc_82070F08:
	// bl 0x82070908
	ctx.lr = 0x82070F0C;
	sub_82070908(ctx, base);
loc_82070F0C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
