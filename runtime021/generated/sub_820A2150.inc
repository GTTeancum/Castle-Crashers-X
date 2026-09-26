DEFINE_REX_FUNC(sub_820A2150) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820A2158;
	__savegprlr_24(ctx, base);
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x8212a858
	ctx.lr = 0x820A2160;
	__savefpr_28(ctx, base);
	// stwu r1,-576(r1)
	ea = -576 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// lwz r31,-6628(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lbz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820a219c
	if (!ctx.cr6.eq) goto loc_820A219C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r10,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r10.u32);
	// stw r11,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
	// addi r1,r1,576
	ctx.r1.s64 = ctx.r1.s64 + 576;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x8212a8a4
	ctx.lr = 0x820A2198;
	__restfpr_28(ctx, base);
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
loc_820A219C:
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x820b6d48
	ctx.lr = 0x820A21A4;
	sub_820B6D48(ctx, base);
	// ld r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// std r11,1408(r31)
	REX_STORE_U64(ctx.r31.u32 + 1408, ctx.r11.u64);
	// bl 0x8212b180
	ctx.lr = 0x820A21B4;
	sub_8212B180(ctx, base);
	// ld r3,1400(r31)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r31.u32 + 1400);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x8212b180
	ctx.lr = 0x820A21C0;
	sub_8212B180(ctx, base);
	// ld r3,1392(r31)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r31.u32 + 1392);
	// fsub f31,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f31.f64 - ctx.f1.f64;
	// bl 0x8212b180
	ctx.lr = 0x820A21CC;
	sub_8212B180(ctx, base);
	// fdiv f0,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64 / ctx.f1.f64;
	// lfs f13,1416(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 1416);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// fadds f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f11,1416(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 1416, temp.u32);
	// bl 0x820b6d48
	ctx.lr = 0x820A21E8;
	sub_820B6D48(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// ld r9,120(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// lfs f0,10004(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 10004);
	ctx.f0.f64 = double(temp.f32);
	// std r9,1400(r31)
	REX_STORE_U64(ctx.r31.u32 + 1400, ctx.r9.u64);
	// lfs f29,1416(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 1416);
	ctx.f29.f64 = double(temp.f32);
	// fcmpu cr6,f29,f0
	ctx.cr6.compare(ctx.f29.f64, ctx.f0.f64);
	// bge cr6,0x820a220c
	if (!ctx.cr6.lt) goto loc_820A220C;
	// li r25,0
	ctx.r25.s64 = 0;
	// b 0x820a2ae4
	goto loc_820A2AE4;
loc_820A220C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f31,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// stfs f31,1416(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 1416, temp.u32);
	// bl 0x8214a204
	ctx.lr = 0x820A222C;
	__imp__XNotifyGetNext(ctx, base);
	// lis r28,-32215
	ctx.r28.s64 = -2111242240;
	// li r26,1
	ctx.r26.s64 = 1;
	// li r25,0
	ctx.r25.s64 = 0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820a2318
	if (ctx.cr6.eq) goto loc_820A2318;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,512
	ctx.r10.s64 = 33554432;
	// lis r9,21
	ctx.r9.s64 = 1376256;
	// lis r8,512
	ctx.r8.s64 = 33554432;
	// ori r30,r10,1
	ctx.r30.u64 = ctx.r10.u64 | 1;
	// lfs f30,18248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18248);
	ctx.f30.f64 = double(temp.f32);
	// ori r27,r9,4336
	ctx.r27.u64 = ctx.r9.u64 | 4336;
	// ori r29,r8,2
	ctx.r29.u64 = ctx.r8.u64 | 2;
loc_820A2260:
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bgt cr6,0x820a22b8
	if (ctx.cr6.gt) goto loc_820A22B8;
	// beq cr6,0x820a22a4
	if (ctx.cr6.eq) goto loc_820A22A4;
	// cmplwi cr6,r11,9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 9, ctx.xer);
	// beq cr6,0x820a228c
	if (ctx.cr6.eq) goto loc_820A228C;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bne cr6,0x820a22fc
	if (!ctx.cr6.eq) goto loc_820A22FC;
	// stfs f30,2712(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r28.u32 + 2712, temp.u32);
	// stb r26,9(r31)
	REX_STORE_U8(ctx.r31.u32 + 9, ctx.r26.u8);
	// b 0x820a22fc
	goto loc_820A22FC;
loc_820A228C:
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stb r8,29(r31)
	REX_STORE_U8(ctx.r31.u32 + 29, ctx.r8.u8);
	// b 0x820a22fc
	goto loc_820A22FC;
loc_820A22A4:
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// beq cr6,0x820a22d4
	if (ctx.cr6.eq) goto loc_820A22D4;
loc_820A22B0:
	// stb r25,1378(r31)
	REX_STORE_U8(ctx.r31.u32 + 1378, ctx.r25.u8);
	// b 0x820a22fc
	goto loc_820A22FC;
loc_820A22B8:
	// subf. r11,r29,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r29.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820a22dc
	if (ctx.cr0.eq) goto loc_820A22DC;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x820a22fc
	if (!ctx.cr6.eq) goto loc_820A22FC;
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a22b0
	if (ctx.cr6.eq) goto loc_820A22B0;
loc_820A22D4:
	// stb r26,1378(r31)
	REX_STORE_U8(ctx.r31.u32 + 1378, ctx.r26.u8);
	// b 0x820a22fc
	goto loc_820A22FC;
loc_820A22DC:
	// addi r4,r31,188
	ctx.r4.s64 = ctx.r31.s64 + 188;
	// lwz r3,112(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x820fc418
	ctx.lr = 0x820A22E8;
	sub_820FC418(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820a22fc
	if (!ctx.cr6.eq) goto loc_820A22FC;
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stb r26,180(r31)
	REX_STORE_U8(ctx.r31.u32 + 180, ctx.r26.u8);
	// stw r11,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
loc_820A22FC:
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214a204
	ctx.lr = 0x820A2310;
	__imp__XNotifyGetNext(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820a2260
	if (!ctx.cr6.eq) goto loc_820A2260;
loc_820A2318:
	// lfs f0,2712(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 2712);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x820a233c
	if (!ctx.cr6.gt) goto loc_820A233C;
	// fsubs f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f29.f64));
	// stfs f0,2712(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 2712, temp.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x820a233c
	if (ctx.cr6.gt) goto loc_820A233C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a1e50
	ctx.lr = 0x820A233C;
	sub_820A1E50(ctx, base);
loc_820A233C:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a2ab8
	if (ctx.cr6.eq) goto loc_820A2AB8;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lis r27,-32234
	ctx.r27.s64 = -2112487424;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820a26a4
	if (!ctx.cr6.eq) goto loc_820A26A4;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stb r26,1372(r31)
	REX_STORE_U8(ctx.r31.u32 + 1372, ctx.r26.u8);
	// stb r26,1373(r31)
	REX_STORE_U8(ctx.r31.u32 + 1373, ctx.r26.u8);
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// stb r11,-28146(r27)
	REX_STORE_U8(ctx.r27.u32 + -28146, ctx.r11.u8);
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
loc_820A2370:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a39f0
	ctx.lr = 0x820A237C;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a239c
	if (ctx.cr6.eq) goto loc_820A239C;
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// slw r10,r26,r30
	ctx.r10.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r26.u32 << (ctx.r30.u8 & 0x3F));
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x820a23ac
	if (!ctx.cr6.eq) goto loc_820A23AC;
loc_820A239C:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x820a2370
	if (ctx.cr6.lt) goto loc_820A2370;
	// b 0x820a23b4
	goto loc_820A23B4;
loc_820A23AC:
	// stw r30,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
loc_820A23B4:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A23C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820a246c
	if (!ctx.cr6.eq) goto loc_820A246C;
	// lbz r11,1377(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1377);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a246c
	if (ctx.cr6.eq) goto loc_820A246C;
	// clrlwi r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a246c
	if (ctx.cr6.eq) goto loc_820A246C;
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// lwz r4,24(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// lwz r3,112(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// bl 0x82051b60
	ctx.lr = 0x820A2404;
	sub_82051B60(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r7,24(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lwz r4,112(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lwz r10,132(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// slw r5,r26,r4
	ctx.r5.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r26.u32 << (ctx.r4.u8 & 0x3F));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r30,6(r7)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r7.u32 + 6);
	// lhz r7,4(r7)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r7.u32 + 4);
	// lwz r8,120(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// subf r6,r30,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r30.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820A2448;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stb r25,1352(r31)
	REX_STORE_U8(ctx.r31.u32 + 1352, ctx.r25.u8);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x820a246c
	if (!ctx.cr6.lt) goto loc_820A246C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,3560
	ctx.r3.s64 = ctx.r11.s64 + 3560;
	// bl 0x8208c5d8
	ctx.lr = 0x820A2464;
	sub_8208C5D8(ctx, base);
	// stw r26,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r26.u32);
	// b 0x820a2ae8
	goto loc_820A2AE8;
loc_820A246C:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A2480;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x820a24a4
	if (!ctx.cr6.eq) goto loc_820A24A4;
	// lbz r11,1184(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1184);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a24a4
	if (ctx.cr6.eq) goto loc_820A24A4;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// b 0x820a24d8
	goto loc_820A24D8;
loc_820A24A4:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A24B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 6, ctx.xer);
	// bne cr6,0x820a24e0
	if (!ctx.cr6.eq) goto loc_820A24E0;
	// lbz r11,1184(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1184);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a24e0
	if (!ctx.cr6.eq) goto loc_820A24E0;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
loc_820A24D8:
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A24E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820A24E0:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A24F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// beq cr6,0x820a2518
	if (ctx.cr6.eq) goto loc_820A2518;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A2510;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 6, ctx.xer);
	// bne cr6,0x820a2674
	if (!ctx.cr6.eq) goto loc_820A2674;
loc_820A2518:
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
loc_820A251C:
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// slw r10,r26,r29
	ctx.r10.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r26.u32 << (ctx.r29.u8 & 0x3F));
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a263c
	if (ctx.cr6.eq) goto loc_820A263C;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a39f0
	ctx.lr = 0x820A253C;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a257c
	if (ctx.cr6.eq) goto loc_820A257C;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A2560;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820a257c
	if (!ctx.cr6.eq) goto loc_820A257C;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// b 0x820a2634
	goto loc_820A2634;
loc_820A257C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a39f0
	ctx.lr = 0x820A2588;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a263c
	if (!ctx.cr6.eq) goto loc_820A263C;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A25AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a263c
	if (ctx.cr6.eq) goto loc_820A263C;
loc_820A25B4:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A25CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820A25DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r3,r29
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r29.u32, ctx.xer);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// beq cr6,0x820a2608
	if (ctx.cr6.eq) goto loc_820A2608;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A25FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x820a25b4
	if (ctx.cr6.lt) goto loc_820A25B4;
	// b 0x820a263c
	goto loc_820A263C;
loc_820A2608:
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A2610;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// ble cr6,0x820a262c
	if (!ctx.cr6.gt) goto loc_820A262C;
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// b 0x820a2634
	goto loc_820A2634;
loc_820A262C:
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// li r4,0
	ctx.r4.s64 = 0;
loc_820A2634:
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A263C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820A263C:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// blt cr6,0x820a251c
	if (ctx.cr6.lt) goto loc_820A251C;
	// lbz r11,1377(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1377);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a2674
	if (!ctx.cr6.eq) goto loc_820A2674;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A266C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a49e0
	ctx.lr = 0x820A2674;
	sub_820A49E0(ctx, base);
loc_820A2674:
	// lbz r11,1377(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1377);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a26a4
	if (ctx.cr6.eq) goto loc_820A26A4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a3eb8
	ctx.lr = 0x820A2688;
	sub_820A3EB8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820a26a4
	if (!ctx.cr6.eq) goto loc_820A26A4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,3636
	ctx.r3.s64 = ctx.r11.s64 + 3636;
	// bl 0x8208c5d8
	ctx.lr = 0x820A269C;
	sub_8208C5D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a49e0
	ctx.lr = 0x820A26A4;
	sub_820A49E0(ctx, base);
loc_820A26A4:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lfs f30,9548(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9548);
	ctx.f30.f64 = double(temp.f32);
	// beq cr6,0x820a2700
	if (ctx.cr6.eq) goto loc_820A2700;
	// lbz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a2700
	if (ctx.cr6.eq) goto loc_820A2700;
	// lbz r11,1376(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1376);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a2700
	if (ctx.cr6.eq) goto loc_820A2700;
	// lbz r11,1185(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a2700
	if (ctx.cr6.eq) goto loc_820A2700;
	// lfs f0,1364(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 1364);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f28,f0
	ctx.f13.f64 = double(float(ctx.f28.f64 + ctx.f0.f64));
	// stfs f13,1364(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 1364, temp.u32);
	// fcmpu cr6,f13,f30
	ctx.cr6.compare(ctx.f13.f64, ctx.f30.f64);
	// ble cr6,0x820a2700
	if (!ctx.cr6.gt) goto loc_820A2700;
	// stfs f31,1364(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 1364, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x820a5390
	ctx.lr = 0x820A2700;
	sub_820A5390(ctx, base);
loc_820A2700:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A2714;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820a2ab8
	if (ctx.cr6.eq) goto loc_820A2AB8;
	// lbz r11,1185(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a2ab8
	if (ctx.cr6.eq) goto loc_820A2AB8;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A2740;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// cmpwi cr6,r29,6
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 6, ctx.xer);
	// lfs f28,9656(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9656);
	ctx.f28.f64 = double(temp.f32);
	// addi r28,r11,9424
	ctx.r28.s64 = ctx.r11.s64 + 9424;
	// beq cr6,0x820a2768
	if (ctx.cr6.eq) goto loc_820A2768;
	// cmpwi cr6,r29,3
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 3, ctx.xer);
	// bne cr6,0x820a2804
	if (!ctx.cr6.eq) goto loc_820A2804;
loc_820A2768:
	// lwz r11,-6624(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6624);
	// lbz r10,1772(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1772);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a2804
	if (ctx.cr6.eq) goto loc_820A2804;
	// lbz r11,1773(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1773);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a278c
	if (ctx.cr6.eq) goto loc_820A278C;
	// stfs f31,1356(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 1356, temp.u32);
	// b 0x820a2804
	goto loc_820A2804;
loc_820A278C:
	// lfs f0,1356(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 1356);
	ctx.f0.f64 = double(temp.f32);
	// cmpwi cr6,r29,6
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 6, ctx.xer);
	// fadds f13,f29,f0
	ctx.f13.f64 = double(float(ctx.f29.f64 + ctx.f0.f64));
	// stfs f13,1356(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 1356, temp.u32);
	// bne cr6,0x820a27a8
	if (!ctx.cr6.eq) goto loc_820A27A8;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
	// b 0x820a27ac
	goto loc_820A27AC;
loc_820A27A8:
	// fmr f0,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f28.f64;
loc_820A27AC:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x820a27c0
	if (ctx.cr6.gt) goto loc_820A27C0;
	// lbz r11,1378(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1378);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a2804
	if (!ctx.cr6.eq) goto loc_820A2804;
loc_820A27C0:
	// stfs f31,1356(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 1356, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x820a37b8
	ctx.lr = 0x820A27D0;
	sub_820A37B8(ctx, base);
	// stb r25,1185(r31)
	REX_STORE_U8(ctx.r31.u32 + 1185, ctx.r25.u8);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82053a00
	ctx.lr = 0x820A27E0;
	sub_82053A00(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r3,-6624(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6624);
	// bl 0x82077a98
	ctx.lr = 0x820A27EC;
	sub_82077A98(ctx, base);
	// lbz r11,1378(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1378);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,10
	ctx.r11.s64 = 10;
	// beq cr6,0x820a2800
	if (ctx.cr6.eq) goto loc_820A2800;
	// li r11,11
	ctx.r11.s64 = 11;
loc_820A2800:
	// stw r11,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
loc_820A2804:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a3f38
	ctx.lr = 0x820A280C;
	sub_820A3F38(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// bgt cr6,0x820a284c
	if (ctx.cr6.gt) goto loc_820A284C;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x820a37b8
	ctx.lr = 0x820A2820;
	sub_820A37B8(ctx, base);
	// stb r25,1185(r31)
	REX_STORE_U8(ctx.r31.u32 + 1185, ctx.r25.u8);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82053a00
	ctx.lr = 0x820A2830;
	sub_82053A00(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r3,-6624(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6624);
	// bl 0x82077a98
	ctx.lr = 0x820A283C;
	sub_82077A98(ctx, base);
	// cmpwi cr6,r29,7
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 7, ctx.xer);
	// beq cr6,0x820a284c
	if (ctx.cr6.eq) goto loc_820A284C;
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
loc_820A284C:
	// lbz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a2970
	if (!ctx.cr6.eq) goto loc_820A2970;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A2874;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a28d4
	if (ctx.cr6.eq) goto loc_820A28D4;
loc_820A287C:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A2894;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820A28A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r7,21(r3)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r3.u32 + 21);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820a28b4
	if (ctx.cr6.eq) goto loc_820A28B4;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
loc_820A28B4:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A28CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x820a287c
	if (ctx.cr6.lt) goto loc_820A287C;
loc_820A28D4:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820a2930
	if (!ctx.cr6.eq) goto loc_820A2930;
	// lwz r10,120(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a28fc
	if (ctx.cr6.eq) goto loc_820A28FC;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_820A28FC:
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a290c
	if (ctx.cr6.eq) goto loc_820A290C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_820A290C:
	// rlwinm r9,r10,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a291c
	if (ctx.cr6.eq) goto loc_820A291C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_820A291C:
	// rlwinm r10,r10,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a2954
	if (ctx.cr6.eq) goto loc_820A2954;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x820a2954
	goto loc_820A2954;
loc_820A2930:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a2950
	if (ctx.cr6.eq) goto loc_820A2950;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,52(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 52);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820A2950;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820A2950:
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_820A2954:
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820a2ab8
	if (!ctx.cr6.eq) goto loc_820A2AB8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,3664
	ctx.r3.s64 = ctx.r11.s64 + 3664;
	// bl 0x8208c5d8
	ctx.lr = 0x820A2968;
	sub_8208C5D8(ctx, base);
	// stb r26,28(r31)
	REX_STORE_U8(ctx.r31.u32 + 28, ctx.r26.u8);
	// b 0x820a2ab8
	goto loc_820A2AB8;
loc_820A2970:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a47e8
	ctx.lr = 0x820A2978;
	sub_820A47E8(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A2990;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a29f0
	if (ctx.cr6.eq) goto loc_820A29F0;
loc_820A2998:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A29B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820A29C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,32(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x820a29d0
	if (!ctx.cr6.gt) goto loc_820A29D0;
	// fmr f31,f0
	ctx.f31.f64 = ctx.f0.f64;
loc_820A29D0:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A29E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x820a2998
	if (ctx.cr6.lt) goto loc_820A2998;
loc_820A29F0:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,9632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9632);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f31,f28,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f31.f64, ctx.f28.f64, ctx.f0.f64)));
	// fctidz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.f13.u64);
	// lbz r10,127(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 127);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// stb r10,1372(r31)
	REX_STORE_U8(ctx.r31.u32 + 1372, ctx.r10.u8);
	// bge cr6,0x820a2a18
	if (!ctx.cr6.lt) goto loc_820A2A18;
	// stb r26,1372(r31)
	REX_STORE_U8(ctx.r31.u32 + 1372, ctx.r26.u8);
loc_820A2A18:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// lbz r29,1372(r31)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r31.u32 + 1372);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A2A34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a2a94
	if (ctx.cr6.eq) goto loc_820A2A94;
loc_820A2A3C:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A2A54;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820A2A64;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 28);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// ble cr6,0x820a2a74
	if (!ctx.cr6.gt) goto loc_820A2A74;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_820A2A74:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A2A8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x820a2a3c
	if (ctx.cr6.lt) goto loc_820A2A3C;
loc_820A2A94:
	// clrlwi r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x820a2aa8
	if (!ctx.cr6.lt) goto loc_820A2AA8;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// b 0x820a2ab4
	goto loc_820A2AB4;
loc_820A2AA8:
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// ble cr6,0x820a2ab4
	if (!ctx.cr6.gt) goto loc_820A2AB4;
	// li r11,8
	ctx.r11.s64 = 8;
loc_820A2AB4:
	// stb r11,-28146(r27)
	REX_STORE_U8(ctx.r27.u32 + -28146, ctx.r11.u8);
loc_820A2AB8:
	// lwz r3,176(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a2ae4
	if (ctx.cr6.eq) goto loc_820A2AE4;
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x820a2ad8
	if (!ctx.cr6.eq) goto loc_820A2AD8;
	// bl 0x820a6cd8
	ctx.lr = 0x820A2AD4;
	sub_820A6CD8(ctx, base);
	// b 0x820a2ae4
	goto loc_820A2AE4;
loc_820A2AD8:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x820a2ae4
	if (!ctx.cr6.eq) goto loc_820A2AE4;
	// bl 0x820a70b0
	ctx.lr = 0x820A2AE4;
	sub_820A70B0(ctx, base);
loc_820A2AE4:
	// stw r25,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r25.u32);
loc_820A2AE8:
	// stw r25,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r25.u32);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r1,r1,576
	ctx.r1.s64 = ctx.r1.s64 + 576;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x8212a8a4
	ctx.lr = 0x820A2AFC;
	__restfpr_28(ctx, base);
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
