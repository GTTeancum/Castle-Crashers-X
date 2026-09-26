DEFINE_REX_FUNC(sub_82091248) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x82091250;
	__savegprlr_24(ctx, base);
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// bl 0x82083658
	ctx.lr = 0x8209126C;
	sub_82083658(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82086090
	ctx.lr = 0x8209127C;
	sub_82086090(ctx, base);
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r27,r25
	ctx.r27.u64 = ctx.r25.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82091298;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r29,0(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8209159c
	if (ctx.cr6.eq) goto loc_8209159C;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,1525
	ctx.r8.s64 = 99942400;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// ori r24,r8,57599
	ctx.r24.u64 = ctx.r8.u64 | 57599;
	// lfs f30,18236(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 18236);
	ctx.f30.f64 = double(temp.f32);
	// lis r26,-32215
	ctx.r26.s64 = -2111242240;
	// lfs f31,9536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// addi r30,r11,2720
	ctx.r30.s64 = ctx.r11.s64 + 2720;
loc_820912C8:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820912DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82091318
	if (ctx.cr6.eq) goto loc_82091318;
	// lbz r11,140(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 140);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82091590
	if (ctx.cr6.eq) goto loc_82091590;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,180(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 180);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8209130C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82091590
	if (ctx.cr6.eq) goto loc_82091590;
loc_82091318:
	// lbz r11,86(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 86);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82091590
	if (ctx.cr6.eq) goto loc_82091590;
	// lwz r11,8248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8248);
	// lwz r10,72(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r11,1998
	ctx.r9.s64 = ctx.r11.s64 + 1998;
	// stw r11,8248(r31)
	REX_STORE_U32(ctx.r31.u32 + 8248, ctx.r11.u32);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r10.u32);
	// lbz r7,86(r29)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r29.u32 + 86);
	// rlwinm r6,r7,0,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x820913cc
	if (ctx.cr6.eq) goto loc_820913CC;
	// lwz r11,2760(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 2760);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820913a8
	if (!ctx.cr6.eq) goto loc_820913A8;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stfs f30,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// stfs f30,4(r30)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// stfs f31,8(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// stfs f30,16(r30)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r30.u32 + 16, temp.u32);
	// stfs f30,20(r30)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r30.u32 + 20, temp.u32);
	// stw r11,2760(r26)
	REX_STORE_U32(ctx.r26.u32 + 2760, ctx.r11.u32);
	// stfs f31,24(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 24, temp.u32);
	// stb r10,12(r30)
	REX_STORE_U8(ctx.r30.u32 + 12, ctx.r10.u8);
	// stfs f31,28(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 28, temp.u32);
	// stb r9,13(r30)
	REX_STORE_U8(ctx.r30.u32 + 13, ctx.r9.u8);
	// stfs f31,32(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 32, temp.u32);
	// stb r8,14(r30)
	REX_STORE_U8(ctx.r30.u32 + 14, ctx.r8.u8);
	// stfs f31,36(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 36, temp.u32);
loc_820913A8:
	// lbz r11,86(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 86);
	// addi r4,r29,36
	ctx.r4.s64 = ctx.r29.s64 + 36;
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820913c0
	if (!ctx.cr6.eq) goto loc_820913C0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
loc_820913C0:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82086090
	ctx.lr = 0x820913CC;
	sub_82086090(ctx, base);
loc_820913CC:
	// lwz r11,76(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82091434
	if (ctx.cr6.eq) goto loc_82091434;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820836e0
	ctx.lr = 0x820913E0;
	sub_820836E0(ctx, base);
	// lwz r11,10048(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10048);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stw r11,10048(r31)
	REX_STORE_U32(ctx.r31.u32 + 10048, ctx.r11.u32);
	// addi r11,r11,595
	ctx.r11.s64 = ctx.r11.s64 + 595;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r11,r31
	ctx.r5.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bl 0x82084100
	ctx.lr = 0x82091404;
	sub_82084100(ctx, base);
	// lwz r11,10048(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10048);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r11,596
	ctx.r10.s64 = ctx.r11.s64 + 596;
	// rlwinm r11,r10,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stwx r9,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r9.u32);
	// lwz r7,4(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r7,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// lwz r6,8(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// stw r6,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r6.u32);
	// lwz r5,12(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// stw r5,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r5.u32);
loc_82091434:
	// lwz r10,32(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8209147c
	if (ctx.cr6.eq) goto loc_8209147C;
	// lwz r11,10312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10312);
	// li r5,11
	ctx.r5.s64 = 11;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,2546
	ctx.r9.s64 = ctx.r11.s64 + 2546;
	// stw r11,10312(r31)
	REX_STORE_U32(ctx.r31.u32 + 10312, ctx.r11.u32);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r6,32(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 32);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82091474;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// b 0x82091514
	goto loc_82091514;
loc_8209147C:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82091514
	if (ctx.cr6.eq) goto loc_82091514;
	// lwz r11,10312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10312);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r10,28(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// addi r9,r11,2546
	ctx.r9.s64 = ctx.r11.s64 + 2546;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r31
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// ble cr6,0x820914ec
	if (!ctx.cr6.gt) goto loc_820914EC;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820914B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r8,32(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820914D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,10312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10312);
	// addi r7,r11,2546
	ctx.r7.s64 = ctx.r11.s64 + 2546;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,10312(r31)
	REX_STORE_U32(ctx.r31.u32 + 10312, ctx.r11.u32);
	// stwx r24,r6,r31
	REX_STORE_U32(ctx.r6.u32 + ctx.r31.u32, ctx.r24.u32);
	// b 0x82091514
	goto loc_82091514;
loc_820914EC:
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820914F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r8,32(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82091514;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82091514:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82091534;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,76(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 76);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8209154c
	if (ctx.cr6.eq) goto loc_8209154C;
	// lwz r11,10048(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10048);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,10048(r31)
	REX_STORE_U32(ctx.r31.u32 + 10048, ctx.r11.u32);
loc_8209154C:
	// lbz r11,86(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 86);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82091568
	if (ctx.cr6.eq) goto loc_82091568;
	// lwz r11,9532(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 9532);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,9532(r31)
	REX_STORE_U32(ctx.r31.u32 + 9532, ctx.r11.u32);
loc_82091568:
	// lwz r11,8248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8248);
	// rlwinm r10,r3,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x2;
	// addi r9,r11,1998
	ctx.r9.s64 = ctx.r11.s64 + 1998;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r25,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r25.u32);
	// lwz r11,8248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8248);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// stw r7,8248(r31)
	REX_STORE_U32(ctx.r31.u32 + 8248, ctx.r7.u32);
	// bne cr6,0x8209159c
	if (!ctx.cr6.eq) goto loc_8209159C;
loc_82091590:
	// lwz r29,88(r29)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r29.u32 + 88);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820912c8
	if (!ctx.cr6.eq) goto loc_820912C8;
loc_8209159C:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x820915d4
	if (ctx.cr6.eq) goto loc_820915D4;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
loc_820915A8:
	// lwz r11,10312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10312);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,10312(r31)
	REX_STORE_U32(ctx.r31.u32 + 10312, ctx.r11.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r9,36(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820915CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x820915a8
	if (!ctx.cr0.eq) goto loc_820915A8;
loc_820915D4:
	// lwz r11,9532(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 9532);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,9532(r31)
	REX_STORE_U32(ctx.r31.u32 + 9532, ctx.r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
