DEFINE_REX_FUNC(sub_82075C88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x82075C90;
	__savegprlr_21(ctx, base);
	// stfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f30.u64);
	// stfd f31,-104(r1)
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f11,9540(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,10008(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 10008);
	ctx.f13.f64 = double(temp.f32);
	// lwz r28,-6624(r9)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r9.u32 + -6624);
	// lfs f30,9536(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9536);
	ctx.f30.f64 = double(temp.f32);
	// fdivs f0,f11,f31
	ctx.f0.f64 = double(float(ctx.f11.f64 / ctx.f31.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x82075ce0
	if (ctx.cr6.gt) goto loc_82075CE0;
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x82075ce0
	if (!ctx.cr6.lt) goto loc_82075CE0;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// stfs f30,-22608(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + -22608, temp.u32);
	// b 0x82075cf8
	goto loc_82075CF8;
loc_82075CE0:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// ble cr6,0x82075cf4
	if (!ctx.cr6.gt) goto loc_82075CF4;
	// stfs f13,-22608(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + -22608, temp.u32);
	// b 0x82075cf8
	goto loc_82075CF8;
loc_82075CF4:
	// stfs f0,-22608(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + -22608, temp.u32);
loc_82075CF8:
	// li r22,0
	ctx.r22.s64 = 0;
	// addi r23,r28,40
	ctx.r23.s64 = ctx.r28.s64 + 40;
	// stb r22,60(r28)
	REX_STORE_U8(ctx.r28.u32 + 60, ctx.r22.u8);
	// lwz r11,52(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 52);
	// lwz r10,56(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 56);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82075d1c
	if (!ctx.cr6.gt) goto loc_82075D1C;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82075D1C:
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82075d30
	if (ctx.cr6.gt) goto loc_82075D30;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82075d34
	if (!ctx.cr6.lt) goto loc_82075D34;
loc_82075D30:
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82075D34:
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// rlwinm r11,r8,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// clrlwi r9,r8,30
	ctx.r9.u64 = ctx.r8.u32 & 0x3;
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82075d4c
	if (ctx.cr6.lt) goto loc_82075D4C;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82075D4C:
	// lwz r10,8(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + 8);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82075d5c
	if (ctx.cr6.gt) goto loc_82075D5C;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
loc_82075D5C:
	// lwz r10,4(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + 4);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,20(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,16(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fadds f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f31.f64));
	// fmr f13,f30
	ctx.f13.f64 = ctx.f30.f64;
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// lwzx r6,r8,r10
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwzx r21,r6,r7
	ctx.r21.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// stfs f12,20(r28)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r28.u32 + 20, temp.u32);
	// stb r22,29(r28)
	REX_STORE_U8(ctx.r28.u32 + 29, ctx.r22.u8);
	// ble cr6,0x82075d94
	if (!ctx.cr6.gt) goto loc_82075D94;
	// fdivs f13,f11,f0
	ctx.f13.f64 = double(float(ctx.f11.f64 / ctx.f0.f64));
loc_82075D94:
	// li r24,1
	ctx.r24.s64 = 1;
	// fcmpu cr6,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x82075da4
	if (ctx.cr6.lt) goto loc_82075DA4;
	// stb r24,29(r28)
	REX_STORE_U8(ctx.r28.u32 + 29, ctx.r24.u8);
loc_82075DA4:
	// lbz r11,29(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 29);
	// lis r25,-32218
	ctx.r25.s64 = -2111438848;
	// lis r27,-32218
	ctx.r27.s64 = -2111438848;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82075e1c
	if (ctx.cr6.eq) goto loc_82075E1C;
	// lbz r11,1772(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 1772);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82075dcc
	if (ctx.cr6.eq) goto loc_82075DCC;
	// lwz r3,-6652(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -6652);
	// bl 0x8209b5d0
	ctx.lr = 0x82075DCC;
	sub_8209B5D0(ctx, base);
loc_82075DCC:
	// lwz r31,-6628(r25)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r25.u32 + -6628);
	// lbz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82075e20
	if (ctx.cr6.eq) goto loc_82075E20;
	// lbz r11,1376(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1376);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82075e20
	if (ctx.cr6.eq) goto loc_82075E20;
	// lbz r11,1185(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82075e20
	if (ctx.cr6.eq) goto loc_82075E20;
	// lbz r11,1374(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1374);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// stb r10,1374(r31)
	REX_STORE_U8(ctx.r31.u32 + 1374, ctx.r10.u8);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// blt cr6,0x82075e20
	if (ctx.cr6.lt) goto loc_82075E20;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820a4ad8
	ctx.lr = 0x82075E18;
	sub_820A4AD8(ctx, base);
	// stb r22,1374(r31)
	REX_STORE_U8(ctx.r31.u32 + 1374, ctx.r22.u8);
loc_82075E1C:
	// lwz r31,-6628(r25)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r25.u32 + -6628);
loc_82075E20:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820a2150
	ctx.lr = 0x82075E30;
	sub_820A2150(ctx, base);
	// lbz r11,29(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 29);
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82075f6c
	if (ctx.cr6.eq) goto loc_82075F6C;
	// lbz r11,1772(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 1772);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82075f6c
	if (ctx.cr6.eq) goto loc_82075F6C;
	// lwz r3,-6652(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -6652);
	// li r29,-1
	ctx.r29.s64 = -1;
	// lbz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82075ec0
	if (ctx.cr6.eq) goto loc_82075EC0;
	// addi r31,r3,8
	ctx.r31.s64 = ctx.r3.s64 + 8;
	// li r30,4
	ctx.r30.s64 = 4;
loc_82075E68:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82075eb0
	if (ctx.cr6.eq) goto loc_82075EB0;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82075E88;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82075eb0
	if (ctx.cr6.eq) goto loc_82075EB0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// clrlwi r10,r29,16
	ctx.r10.u64 = ctx.r29.u32 & 0xFFFF;
	// lbz r11,102(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 102);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82075eb0
	if (!ctx.cr6.lt) goto loc_82075EB0;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_82075EB0:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x82075e68
	if (!ctx.cr0.eq) goto loc_82075E68;
	// lwz r3,-6652(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -6652);
loc_82075EC0:
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82075f6c
	if (ctx.cr6.eq) goto loc_82075F6C;
	// lbz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4);
	// li r29,-1
	ctx.r29.s64 = -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82075f4c
	if (ctx.cr6.eq) goto loc_82075F4C;
	// addi r31,r3,8
	ctx.r31.s64 = ctx.r3.s64 + 8;
	// li r30,4
	ctx.r30.s64 = 4;
loc_82075EE4:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82075f3c
	if (ctx.cr6.eq) goto loc_82075F3C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82075F04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82075f3c
	if (ctx.cr6.eq) goto loc_82075F3C;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82075f3c
	if (ctx.cr6.eq) goto loc_82075F3C;
	// lbz r11,102(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 102);
	// clrlwi r10,r29,16
	ctx.r10.u64 = ctx.r29.u32 & 0xFFFF;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82075f3c
	if (!ctx.cr6.lt) goto loc_82075F3C;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_82075F3C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x82075ee4
	if (!ctx.cr0.eq) goto loc_82075EE4;
	// lwz r3,-6652(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -6652);
loc_82075F4C:
	// lwz r11,-6628(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6628);
	// clrlwi r10,r29,16
	ctx.r10.u64 = ctx.r29.u32 & 0xFFFF;
	// lbz r9,1373(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1373);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82075f6c
	if (ctx.cr6.lt) goto loc_82075F6C;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8209b648
	ctx.lr = 0x82075F68;
	sub_8209B648(ctx, base);
	// mr r26,r24
	ctx.r26.u64 = ctx.r24.u64;
loc_82075F6C:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r3,-6596(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// bl 0x8209ff98
	ctx.lr = 0x82075F7C;
	sub_8209FF98(ctx, base);
	// lbz r10,29(r28)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r28.u32 + 29);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82075f94
	if (ctx.cr6.eq) goto loc_82075F94;
	// lwz r3,1756(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 1756);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82078f38
	ctx.lr = 0x82075F94;
	sub_82078F38(ctx, base);
loc_82075F94:
	// lbz r11,76(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82075fa8
	if (ctx.cr6.eq) goto loc_82075FA8;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820776d8
	ctx.lr = 0x82075FA8;
	sub_820776D8(ctx, base);
loc_82075FA8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82076f08
	ctx.lr = 0x82075FB4;
	sub_82076F08(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r3,-6612(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6612);
	// bl 0x82096950
	ctx.lr = 0x82075FC4;
	sub_82096950(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82099fa0
	ctx.lr = 0x82075FCC;
	sub_82099FA0(ctx, base);
	// lwz r3,4(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,64(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82075FE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,1764(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 1764);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x82076138
	if (!ctx.cr6.eq) goto loc_82076138;
	// lbz r11,29(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 29);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076138
	if (ctx.cr6.eq) goto loc_82076138;
	// cmpwi cr6,r21,4
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 4, ctx.xer);
	// beq cr6,0x82076174
	if (ctx.cr6.eq) goto loc_82076174;
	// lwz r3,1656(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 1656);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82076024
	if (ctx.cr6.eq) goto loc_82076024;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82076024;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82076024:
	// lwz r10,-6628(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + -6628);
	// lwz r11,20(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82076050
	if (ctx.cr6.eq) goto loc_82076050;
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076050
	if (ctx.cr6.eq) goto loc_82076050;
	// lbz r11,1185(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// bne cr6,0x82076054
	if (!ctx.cr6.eq) goto loc_82076054;
loc_82076050:
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
loc_82076054:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820760ac
	if (ctx.cr6.eq) goto loc_820760AC;
	// lwz r11,288(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 288);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820760ac
	if (ctx.cr6.eq) goto loc_820760AC;
	// clrlwi r11,r26,24
	ctx.r11.u64 = ctx.r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076094
	if (ctx.cr6.eq) goto loc_82076094;
	// stb r24,1773(r28)
	REX_STORE_U8(ctx.r28.u32 + 1773, ctx.r24.u8);
	// lwz r11,288(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 288);
	// lwz r11,96(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820760ac
	if (ctx.cr6.eq) goto loc_820760AC;
	// stb r22,10333(r11)
	REX_STORE_U8(ctx.r11.u32 + 10333, ctx.r22.u8);
	// b 0x820760ac
	goto loc_820760AC;
loc_82076094:
	// stb r22,1773(r28)
	REX_STORE_U8(ctx.r28.u32 + 1773, ctx.r22.u8);
	// lwz r11,288(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 288);
	// lwz r11,96(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820760ac
	if (ctx.cr6.eq) goto loc_820760AC;
	// stb r24,10333(r11)
	REX_STORE_U8(ctx.r11.u32 + 10333, ctx.r24.u8);
loc_820760AC:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r11,-6608(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6608);
	// lwz r9,24(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820760e4
	if (ctx.cr6.eq) goto loc_820760E4;
	// addi r3,r11,8
	ctx.r3.s64 = ctx.r11.s64 + 8;
	// bl 0x82078280
	ctx.lr = 0x820760C8;
	sub_82078280(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820760E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,-6628(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + -6628);
loc_820760E4:
	// lwz r11,20(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8207610c
	if (ctx.cr6.eq) goto loc_8207610C;
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207610c
	if (ctx.cr6.eq) goto loc_8207610C;
	// lbz r11,1185(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// bne cr6,0x82076110
	if (!ctx.cr6.eq) goto loc_82076110;
loc_8207610C:
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
loc_82076110:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076138
	if (ctx.cr6.eq) goto loc_82076138;
	// lwz r11,288(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 288);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82076138
	if (ctx.cr6.eq) goto loc_82076138;
	// lwz r11,96(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076138
	if (ctx.cr6.eq) goto loc_82076138;
	// stb r24,10333(r11)
	REX_STORE_U8(ctx.r11.u32 + 10333, ctx.r24.u8);
loc_82076138:
	// cmplwi cr6,r21,6
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 6, ctx.xer);
	// bgt cr6,0x820762b0
	if (ctx.cr6.gt) goto loc_820762B0;
loc_82076140:
	// lis r12,-32249
	ctx.r12.s64 = -2113470464;
	// addi r12,r12,24920
	ctx.r12.s64 = ctx.r12.s64 + 24920;
	// rlwinm r0,r21,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r21.u32) {
	case 0:
		goto loc_82076190;
	case 1:
		goto loc_820761C4;
	case 2:
		goto loc_820761F8;
	case 3:
		goto loc_82076254;
	case 4:
		goto loc_82076220;
	case 5:
		goto loc_82076264;
	case 6:
		goto loc_820762A4;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82076174:
	// lwz r3,212(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 212);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207618C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82076140
	goto loc_82076140;
loc_82076190:
	// lbz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820761b4
	if (!ctx.cr6.eq) goto loc_820761B4;
	// stb r24,8(r28)
	REX_STORE_U8(ctx.r28.u32 + 8, ctx.r24.u8);
	// lwz r3,4(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820761B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820761B4:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x820762d0
	ctx.lr = 0x820761C0;
	sub_820762D0(ctx, base);
	// b 0x820762b0
	goto loc_820762B0;
loc_820761C4:
	// lbz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820761e8
	if (!ctx.cr6.eq) goto loc_820761E8;
	// stb r24,8(r28)
	REX_STORE_U8(ctx.r28.u32 + 8, ctx.r24.u8);
	// lwz r3,4(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820761E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820761E8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82076758
	ctx.lr = 0x820761F4;
	sub_82076758(ctx, base);
	// b 0x820762b0
	goto loc_820762B0;
loc_820761F8:
	// lbz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820762b0
	if (ctx.cr6.eq) goto loc_820762B0;
	// lwz r3,4(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82076218;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r22,8(r28)
	REX_STORE_U8(ctx.r28.u32 + 8, ctx.r22.u8);
	// b 0x820762b0
	goto loc_820762B0;
loc_82076220:
	// lbz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82076244
	if (!ctx.cr6.eq) goto loc_82076244;
	// stb r24,8(r28)
	REX_STORE_U8(ctx.r28.u32 + 8, ctx.r24.u8);
	// lwz r3,4(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82076244;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82076244:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82076ad8
	ctx.lr = 0x82076250;
	sub_82076AD8(ctx, base);
	// b 0x820762b0
	goto loc_820762B0;
loc_82076254:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82076ce0
	ctx.lr = 0x82076260;
	sub_82076CE0(ctx, base);
	// b 0x820762b0
	goto loc_820762B0;
loc_82076264:
	// lwz r11,56(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 56);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x8207628c
	if (!ctx.cr6.gt) goto loc_8207628C;
	// lwz r11,16(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207628c
	if (ctx.cr6.eq) goto loc_8207628C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r23)
	REX_STORE_U32(ctx.r23.u32 + 16, ctx.r11.u32);
	// bne 0x8207628c
	if (!ctx.cr0.eq) goto loc_8207628C;
	// stw r22,12(r23)
	REX_STORE_U32(ctx.r23.u32 + 12, ctx.r22.u32);
loc_8207628C:
	// li r11,6
	ctx.r11.s64 = 6;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x820782f0
	ctx.lr = 0x820762A0;
	sub_820782F0(ctx, base);
	// b 0x820762b0
	goto loc_820762B0;
loc_820762A4:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82076dc8
	ctx.lr = 0x820762B0;
	sub_82076DC8(ctx, base);
loc_820762B0:
	// lbz r11,29(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 29);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820762c0
	if (ctx.cr6.eq) goto loc_820762C0;
	// stfs f30,20(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r28.u32 + 20, temp.u32);
loc_820762C0:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
