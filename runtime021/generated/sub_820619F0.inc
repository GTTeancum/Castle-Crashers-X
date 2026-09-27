DEFINE_REX_FUNC(sub_820619F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820619F8;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r29,-32215
	ctx.r29.s64 = -2111242240;
	// addi r9,r11,9436
	ctx.r9.s64 = ctx.r11.s64 + 9436;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r4,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// li r26,0
	ctx.r26.s64 = 0;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// addi r8,r10,18640
	ctx.r8.s64 = ctx.r10.s64 + 18640;
	// lwz r5,10316(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 10316);
	// li r7,4
	ctx.r7.s64 = 4;
	// lbz r6,-22601(r29)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// li r4,1
	ctx.r4.s64 = 1;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// stw r5,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// stw r26,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r26.u32);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// stw r26,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r26.u32);
	// addi r24,r11,-1768
	ctx.r24.s64 = ctx.r11.s64 + -1768;
	// sth r7,16(r31)
	REX_STORE_U16(ctx.r31.u32 + 16, ctx.r7.u16);
	// sth r26,18(r31)
	REX_STORE_U16(ctx.r31.u32 + 18, ctx.r26.u16);
	// stb r4,20(r31)
	REX_STORE_U8(ctx.r31.u32 + 20, ctx.r4.u8);
	// stb r26,33(r31)
	REX_STORE_U8(ctx.r31.u32 + 33, ctx.r26.u8);
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// bne cr6,0x82061a78
	if (!ctx.cr6.eq) goto loc_82061A78;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82061A78;
	sub_820A71E8(ctx, base);
loc_82061A78:
	// bl 0x820b5eb8
	ctx.lr = 0x82061A7C;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r25,r11,29632
	ctx.r25.s64 = ctx.r11.s64 + 29632;
	// li r4,17880
	ctx.r4.s64 = 17880;
	// lwzx r3,r10,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82061A94;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82061acc
	if (ctx.cr6.eq) goto loc_82061ACC;
	// li r11,41
	ctx.r11.s64 = 41;
	// addi r27,r3,4
	ctx.r27.s64 = ctx.r3.s64 + 4;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r30,40
	ctx.r30.s64 = 40;
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
loc_82061AB0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82066680
	ctx.lr = 0x82061AB8;
	sub_82066680(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r28,r28,436
	ctx.r28.s64 = ctx.r28.s64 + 436;
	// bge 0x82061ab0
	if (!ctx.cr0.lt) goto loc_82061AB0;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// b 0x82061ad0
	goto loc_82061AD0;
loc_82061ACC:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_82061AD0:
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053ac0
	ctx.lr = 0x82061ADC;
	sub_82053AC0(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6976
	ctx.r4.s64 = ctx.r11.s64 + 6976;
	// bl 0x82061fc8
	ctx.lr = 0x82061AEC;
	sub_82061FC8(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6540
	ctx.r4.s64 = ctx.r11.s64 + 6540;
	// bl 0x820623c0
	ctx.lr = 0x82061AFC;
	sub_820623C0(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,7412
	ctx.r4.s64 = ctx.r11.s64 + 7412;
	// bl 0x82062a50
	ctx.lr = 0x82061B0C;
	sub_82062A50(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,7848
	ctx.r4.s64 = ctx.r11.s64 + 7848;
	// bl 0x82062e80
	ctx.lr = 0x82061B1C;
	sub_82062E80(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,8284
	ctx.r4.s64 = ctx.r11.s64 + 8284;
	// bl 0x820631b0
	ctx.lr = 0x82061B2C;
	sub_820631B0(ctx, base);
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// lwz r10,56(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r30,r10,10028
	ctx.r30.s64 = ctx.r10.s64 + 10028;
	// bne cr6,0x82061b54
	if (!ctx.cr6.eq) goto loc_82061B54;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82061B54;
	sub_820A71E8(ctx, base);
loc_82061B54:
	// bl 0x820b5eb8
	ctx.lr = 0x82061B58;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82061B68;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82061b8c
	if (ctx.cr6.eq) goto loc_82061B8C;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,381
	ctx.r6.s64 = 381;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82067020
	ctx.lr = 0x82061B84;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82061b90
	goto loc_82061B90;
loc_82061B8C:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
loc_82061B90:
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
	ctx.lr = 0x82061BA8;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stw r31,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r31.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r9,r10,20880
	ctx.r9.s64 = ctx.r10.s64 + 20880;
	// stw r9,384(r30)
	REX_STORE_U32(ctx.r30.u32 + 384, ctx.r9.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// addi r4,r11,10464
	ctx.r4.s64 = ctx.r11.s64 + 10464;
	// bl 0x8206abd0
	ctx.lr = 0x82061BC8;
	sub_8206ABD0(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,10900
	ctx.r4.s64 = ctx.r11.s64 + 10900;
	// bl 0x8206b000
	ctx.lr = 0x82061BD8;
	sub_8206B000(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,11336
	ctx.r4.s64 = ctx.r11.s64 + 11336;
	// bl 0x8206b2b0
	ctx.lr = 0x82061BE8;
	sub_8206B2B0(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,11772
	ctx.r4.s64 = ctx.r11.s64 + 11772;
	// bl 0x82055810
	ctx.lr = 0x82061BF8;
	sub_82055810(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,12208
	ctx.r4.s64 = ctx.r11.s64 + 12208;
	// bl 0x82055c20
	ctx.lr = 0x82061C08;
	sub_82055C20(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,12644
	ctx.r4.s64 = ctx.r11.s64 + 12644;
	// bl 0x82056030
	ctx.lr = 0x82061C18;
	sub_82056030(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,13080
	ctx.r4.s64 = ctx.r11.s64 + 13080;
	// bl 0x820563a0
	ctx.lr = 0x82061C28;
	sub_820563A0(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,13516
	ctx.r4.s64 = ctx.r11.s64 + 13516;
	// bl 0x82056718
	ctx.lr = 0x82061C38;
	sub_82056718(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,13952
	ctx.r4.s64 = ctx.r11.s64 + 13952;
	// bl 0x82056cb8
	ctx.lr = 0x82061C48;
	sub_82056CB8(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,14388
	ctx.r4.s64 = ctx.r11.s64 + 14388;
	// bl 0x82057028
	ctx.lr = 0x82061C58;
	sub_82057028(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,14824
	ctx.r4.s64 = ctx.r11.s64 + 14824;
	// bl 0x82057398
	ctx.lr = 0x82061C68;
	sub_82057398(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,15260
	ctx.r4.s64 = ctx.r11.s64 + 15260;
	// bl 0x8206d728
	ctx.lr = 0x82061C78;
	sub_8206D728(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,15696
	ctx.r4.s64 = ctx.r11.s64 + 15696;
	// bl 0x82057670
	ctx.lr = 0x82061C88;
	sub_82057670(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,16132
	ctx.r4.s64 = ctx.r11.s64 + 16132;
	// bl 0x8206d728
	ctx.lr = 0x82061C98;
	sub_8206D728(ctx, base);
	// lbz r8,-22601(r29)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// lwz r10,56(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r30,r10,16568
	ctx.r30.s64 = ctx.r10.s64 + 16568;
	// bne cr6,0x82061cc0
	if (!ctx.cr6.eq) goto loc_82061CC0;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82061CC0;
	sub_820A71E8(ctx, base);
loc_82061CC0:
	// bl 0x820b5eb8
	ctx.lr = 0x82061CC4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82061CD4;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82061cec
	if (ctx.cr6.eq) goto loc_82061CEC;
	// li r4,381
	ctx.r4.s64 = 381;
	// bl 0x82067778
	ctx.lr = 0x82061CE4;
	sub_82067778(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82061cf0
	goto loc_82061CF0;
loc_82061CEC:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
loc_82061CF0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82061D00;
	sub_82065F78(ctx, base);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r31,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r31.u32);
	// li r11,255
	ctx.r11.s64 = 255;
	// addi r9,r10,-9280
	ctx.r9.s64 = ctx.r10.s64 + -9280;
	// sth r11,16(r30)
	REX_STORE_U16(ctx.r30.u32 + 16, ctx.r11.u16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,384(r30)
	REX_STORE_U32(ctx.r30.u32 + 384, ctx.r9.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// addi r4,r11,17004
	ctx.r4.s64 = ctx.r11.s64 + 17004;
	// bl 0x820684c0
	ctx.lr = 0x82061D28;
	sub_820684C0(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,17440
	ctx.r4.s64 = ctx.r11.s64 + 17440;
	// bl 0x82068d60
	ctx.lr = 0x82061D38;
	sub_82068D60(ctx, base);
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// lis r7,1
	ctx.r7.s64 = 65536;
	// ori r6,r7,59648
	ctx.r6.u64 = ctx.r7.u64 | 59648;
	// lwz r11,-6596(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -6596);
	// lwzx r3,r11,r6
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r6.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82061d94
	if (ctx.cr6.eq) goto loc_82061D94;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,102
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 102, ctx.xer);
	// beq cr6,0x82061d90
	if (ctx.cr6.eq) goto loc_82061D90;
	// li r11,102
	ctx.r11.s64 = 102;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stb r26,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r26.u8);
	// stw r26,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r26.u32);
	// stw r26,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r26.u32);
	// stw r26,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r26.u32);
	// stw r26,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r26.u32);
	// stb r26,40(r3)
	REX_STORE_U8(ctx.r3.u32 + 40, ctx.r26.u8);
	// stw r26,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r26.u32);
	// stw r26,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r26.u32);
	// stw r26,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r26.u32);
	// stw r26,56(r3)
	REX_STORE_U32(ctx.r3.u32 + 56, ctx.r26.u32);
loc_82061D90:
	// bl 0x82050a50
	ctx.lr = 0x82061D94;
	sub_82050A50(ctx, base);
loc_82061D94:
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x82061DA0;
	sub_82053BC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
