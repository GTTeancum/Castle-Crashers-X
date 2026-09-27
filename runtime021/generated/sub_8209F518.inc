DEFINE_REX_FUNC(sub_8209F518) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x8209F520;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// cmplwi cr6,r5,64
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 64, ctx.xer);
	// blt cr6,0x8209f56c
	if (ctx.cr6.lt) goto loc_8209F56C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2212
	ctx.r3.s64 = ctx.r11.s64 + 2212;
	// bl 0x8208c5d8
	ctx.lr = 0x8209F54C;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r9.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_8209F56C:
	// addi r11,r5,512
	ctx.r11.s64 = ctx.r5.s64 + 512;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r28,r10,r29
	ctx.r28.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8209f5b0
	if (!ctx.cr6.eq) goto loc_8209F5B0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r3,r11,2256
	ctx.r3.s64 = ctx.r11.s64 + 2256;
	// bl 0x8208c5d8
	ctx.lr = 0x8209F590;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r9.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_8209F5B0:
	// lwz r11,5376(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 5376);
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209f5d0
	if (ctx.cr6.eq) goto loc_8209F5D0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x820d8370
	ctx.lr = 0x8209F5CC;
	sub_820D8370(ctx, base);
	// stw r31,5376(r29)
	REX_STORE_U32(ctx.r29.u32 + 5376, ctx.r31.u32);
loc_8209F5D0:
	// li r5,88
	ctx.r5.s64 = 88;
	// stb r31,208(r1)
	REX_STORE_U8(ctx.r1.u32 + 208, ctx.r31.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,212
	ctx.r3.s64 = ctx.r1.s64 + 212;
	// bl 0x82129fa0
	ctx.lr = 0x8209F5E4;
	sub_82129FA0(ctx, base);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8209e740
	ctx.lr = 0x8209F5F0;
	sub_8209E740(ctx, base);
	// li r26,1
	ctx.r26.s64 = 1;
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stw r31,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r31.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stb r26,136(r1)
	REX_STORE_U8(ctx.r1.u32 + 136, ctx.r26.u8);
	// stw r11,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r11.u32);
	// stw r10,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
	// lwz r9,152(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 152);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8209f624
	if (ctx.cr6.eq) goto loc_8209F624;
	// lwz r11,160(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 160);
	// lbz r3,40(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 40);
	// b 0x8209f62c
	goto loc_8209F62C;
loc_8209F624:
	// lwz r11,156(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 156);
	// lbz r3,29(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 29);
loc_8209F62C:
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x820d8648
	ctx.lr = 0x8209F638;
	sub_820D8648(ctx, base);
	// addi r11,r1,136
	ctx.r11.s64 = ctx.r1.s64 + 136;
	// stw r31,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r31.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r11,280(r1)
	REX_STORE_U32(ctx.r1.u32 + 280, ctx.r11.u32);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x820d8588
	ctx.lr = 0x8209F650;
	sub_820D8588(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x8209f66c
	if (!ctx.cr6.lt) goto loc_8209F66C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2304
	ctx.r3.s64 = ctx.r11.s64 + 2304;
	// bl 0x8208c5d8
	ctx.lr = 0x8209F668;
	sub_8208C5D8(ctx, base);
	// b 0x8209f784
	goto loc_8209F784;
loc_8209F66C:
	// lwz r8,160(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 160);
	// addi r11,r1,164
	ctx.r11.s64 = ctx.r1.s64 + 164;
	// stw r31,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r31.u32);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// li r10,7
	ctx.r10.s64 = 7;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8209F684:
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8209f684
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8209F684;
	// lwz r11,148(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 148);
	// clrlwi r10,r27,24
	ctx.r10.u64 = ctx.r27.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// lwz r9,68(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 68);
	// stw r9,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r9.u32);
	// beq cr6,0x8209f6c8
	if (ctx.cr6.eq) goto loc_8209F6C8;
	// stw r31,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r31.u32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r11.u32);
	// lwz r11,32(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 32);
	// addi r10,r11,127
	ctx.r10.s64 = ctx.r11.s64 + 127;
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// b 0x8209f6dc
	goto loc_8209F6DC;
loc_8209F6C8:
	// lbz r11,3(r8)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r8.u32 + 3);
	// stw r11,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r11.u32);
	// lwz r10,4(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r10,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// lwz r9,8(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
loc_8209F6DC:
	// stw r9,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r3,128(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// bl 0x820d82c8
	ctx.lr = 0x8209F6F0;
	sub_820D82C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x8209f708
	if (!ctx.cr6.lt) goto loc_8209F708;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2392
	ctx.r3.s64 = ctx.r11.s64 + 2392;
	// bl 0x8208c5d8
	ctx.lr = 0x8209F708;
	sub_8208C5D8(ctx, base);
loc_8209F708:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,128(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// bl 0x820d8328
	ctx.lr = 0x8209F714;
	sub_820D8328(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x8209f72c
	if (!ctx.cr6.lt) goto loc_8209F72C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2436
	ctx.r3.s64 = ctx.r11.s64 + 2436;
	// bl 0x8208c5d8
	ctx.lr = 0x8209F72C;
	sub_8208C5D8(ctx, base);
loc_8209F72C:
	// lbz r11,5380(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 5380);
	// stfs f31,5384(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r29.u32 + 5384, temp.u32);
	// lwz r3,128(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209f74c
	if (ctx.cr6.eq) goto loc_8209F74C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f1,9536(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8209f750
	goto loc_8209F750;
loc_8209F74C:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
loc_8209F750:
	// bl 0x820d8430
	ctx.lr = 0x8209F754;
	sub_820D8430(ctx, base);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r10,r29,2304
	ctx.r10.s64 = ctx.r29.s64 + 2304;
loc_8209F75C:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8209f79c
	if (ctx.cr6.eq) goto loc_8209F79C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// blt cr6,0x8209f75c
	if (ctx.cr6.lt) goto loc_8209F75C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2472
	ctx.r3.s64 = ctx.r11.s64 + 2472;
	// bl 0x8208c5d8
	ctx.lr = 0x8209F784;
	sub_8208C5D8(ctx, base);
loc_8209F784:
	// stw r26,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r26.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r31.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_8209F79C:
	// addi r10,r11,192
	ctx.r10.s64 = ctx.r11.s64 + 192;
	// lwz r7,128(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r31,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r31.u32);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r31,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r31.u32);
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r11,r6,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r11,r10,r29
	ctx.r11.u64 = ctx.r10.u64 + ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,5376(r29)
	REX_STORE_U32(ctx.r29.u32 + 5376, ctx.r11.u32);
	// stwx r7,r10,r29
	REX_STORE_U32(ctx.r10.u32 + ctx.r29.u32, ctx.r7.u32);
	// stw r28,2308(r4)
	REX_STORE_U32(ctx.r4.u32 + 2308, ctx.r28.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
