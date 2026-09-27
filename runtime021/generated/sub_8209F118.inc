DEFINE_REX_FUNC(sub_8209F118) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8209F120;
	__savegprlr_27(ctx, base);
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f30.u64);
	// stfd f31,-56(r1)
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r4,r4,16
	ctx.r4.u64 = ctx.r4.u32 & 0xFFFF;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// fmr f31,f2
	ctx.f31.f64 = ctx.f2.f64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// cmplwi cr6,r4,512
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 512, ctx.xer);
	// blt cr6,0x8209f168
	if (ctx.cr6.lt) goto loc_8209F168;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,1944
	ctx.r3.s64 = ctx.r11.s64 + 1944;
	// bl 0x8208c5d8
	ctx.lr = 0x8209F154;
	sub_8208C5D8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8209F168:
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r11,r28
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8209f198
	if (!ctx.cr6.eq) goto loc_8209F198;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,1988
	ctx.r3.s64 = ctx.r11.s64 + 1988;
loc_8209F180:
	// bl 0x8208c5d8
	ctx.lr = 0x8209F184;
	sub_8208C5D8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8209F198:
	// li r31,0
	ctx.r31.s64 = 0;
	// li r5,88
	ctx.r5.s64 = 88;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r31,272(r1)
	REX_STORE_U8(ctx.r1.u32 + 272, ctx.r31.u8);
	// addi r3,r1,276
	ctx.r3.s64 = ctx.r1.s64 + 276;
	// bl 0x82129fa0
	ctx.lr = 0x8209F1B0;
	sub_82129FA0(ctx, base);
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8209e740
	ctx.lr = 0x8209F1BC;
	sub_8209E740(ctx, base);
	// lwz r11,152(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 152);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8209f1d4
	if (ctx.cr6.eq) goto loc_8209F1D4;
	// lwz r11,160(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 160);
	// lbz r3,40(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 40);
	// b 0x8209f1dc
	goto loc_8209F1DC;
loc_8209F1D4:
	// lwz r11,156(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 156);
	// lbz r3,29(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 29);
loc_8209F1DC:
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x820d8648
	ctx.lr = 0x8209F1E8;
	sub_820D8648(ctx, base);
	// addi r11,r1,208
	ctx.r11.s64 = ctx.r1.s64 + 208;
	// addi r10,r1,152
	ctx.r10.s64 = ctx.r1.s64 + 152;
	// stw r31,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r31.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stw r11,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r11.u32);
	// li r29,1
	ctx.r29.s64 = 1;
	// stw r10,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r10.u32);
	// stw r9,344(r1)
	REX_STORE_U32(ctx.r1.u32 + 344, ctx.r9.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stb r29,160(r1)
	REX_STORE_U8(ctx.r1.u32 + 160, ctx.r29.u8);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// stw r31,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r31.u32);
	// bl 0x820d8588
	ctx.lr = 0x8209F21C;
	sub_820D8588(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x8209f234
	if (!ctx.cr6.lt) goto loc_8209F234;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2040
	ctx.r3.s64 = ctx.r11.s64 + 2040;
	// b 0x8209f180
	goto loc_8209F180;
loc_8209F234:
	// lwz r8,160(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 160);
	// addi r11,r1,180
	ctx.r11.s64 = ctx.r1.s64 + 180;
	// stw r31,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r31.u32);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// li r10,7
	ctx.r10.s64 = 7;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8209F24C:
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8209f24c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8209F24C;
	// lwz r11,148(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 148);
	// clrlwi r10,r27,24
	ctx.r10.u64 = ctx.r27.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r11.u32);
	// lwz r9,68(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 68);
	// stw r9,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r9.u32);
	// beq cr6,0x8209f290
	if (ctx.cr6.eq) goto loc_8209F290;
	// stw r31,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r31.u32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r11.u32);
	// lwz r11,32(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 32);
	// addi r10,r11,127
	ctx.r10.s64 = ctx.r11.s64 + 127;
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// b 0x8209f2a4
	goto loc_8209F2A4;
loc_8209F290:
	// lbz r11,3(r8)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r8.u32 + 3);
	// stw r11,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r11.u32);
	// lwz r10,4(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r10,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r10.u32);
	// lwz r9,8(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
loc_8209F2A4:
	// stw r9,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r9.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lwz r3,128(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// bl 0x820d82c8
	ctx.lr = 0x8209F2B8;
	sub_820D82C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x8209f2d0
	if (!ctx.cr6.lt) goto loc_8209F2D0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2124
	ctx.r3.s64 = ctx.r11.s64 + 2124;
	// bl 0x8208c5d8
	ctx.lr = 0x8209F2D0;
	sub_8208C5D8(ctx, base);
loc_8209F2D0:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,128(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// bl 0x820d8328
	ctx.lr = 0x8209F2DC;
	sub_820D8328(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x8209f2f4
	if (!ctx.cr6.lt) goto loc_8209F2F4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2176
	ctx.r3.s64 = ctx.r11.s64 + 2176;
	// bl 0x8208c5d8
	ctx.lr = 0x8209F2F4;
	sub_8208C5D8(ctx, base);
loc_8209F2F4:
	// lwz r3,128(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x820d8430
	ctx.lr = 0x8209F300;
	sub_820D8430(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// beq cr6,0x8209f384
	if (ctx.cr6.eq) goto loc_8209F384;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stb r31,224(r1)
	REX_STORE_U8(ctx.r1.u32 + 224, ctx.r31.u8);
	// lfs f0,9540(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8209f330
	if (!ctx.cr6.lt) goto loc_8209F330;
	// stfs f13,228(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// b 0x8209f334
	goto loc_8209F334;
loc_8209F330:
	// stfs f0,228(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
loc_8209F334:
	// fadds f13,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// stb r29,232(r1)
	REX_STORE_U8(ctx.r1.u32 + 232, ctx.r29.u8);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8209f34c
	if (!ctx.cr6.lt) goto loc_8209F34C;
	// stfs f13,236(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// b 0x8209f350
	goto loc_8209F350;
loc_8209F34C:
	// stfs f0,236(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
loc_8209F350:
	// li r11,2
	ctx.r11.s64 = 2;
	// stb r31,136(r1)
	REX_STORE_U8(ctx.r1.u32 + 136, ctx.r31.u8);
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// stb r29,144(r1)
	REX_STORE_U8(ctx.r1.u32 + 144, ctx.r29.u8);
	// addi r9,r1,168
	ctx.r9.s64 = ctx.r1.s64 + 168;
	// stb r11,168(r1)
	REX_STORE_U8(ctx.r1.u32 + 168, ctx.r11.u8);
	// addi r8,r1,136
	ctx.r8.s64 = ctx.r1.s64 + 136;
	// stw r10,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// stw r9,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stw r8,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r8.u32);
	// lwz r3,128(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// bl 0x820d81b8
	ctx.lr = 0x8209F384;
	sub_820D81B8(ctx, base);
loc_8209F384:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r10,r28,2304
	ctx.r10.s64 = ctx.r28.s64 + 2304;
loc_8209F38C:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8209f3bc
	if (ctx.cr6.eq) goto loc_8209F3BC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// blt cr6,0x8209f38c
	if (ctx.cr6.lt) goto loc_8209F38C;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8209F3BC:
	// addi r10,r11,192
	ctx.r10.s64 = ctx.r11.s64 + 192;
	// lwz r7,128(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + ctx.r28.u64;
	// extsh r3,r11
	ctx.r3.s64 = ctx.r11.s16;
	// stwx r7,r4,r28
	REX_STORE_U32(ctx.r4.u32 + ctx.r28.u32, ctx.r7.u32);
	// stw r30,2308(r10)
	REX_STORE_U32(ctx.r10.u32 + 2308, ctx.r30.u32);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
