DEFINE_REX_FUNC(sub_8208A7A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x8208A7A8;
	__savegprlr_21(ctx, base);
	// stfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f30.u64);
	// stfd f31,-104(r1)
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r23,0
	ctx.r23.s64 = 0;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r22,r23
	ctx.r22.u64 = ctx.r23.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208A7DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r24,r27
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x8208a7e8
	if (!ctx.cr6.eq) goto loc_8208A7E8;
	// mr r24,r23
	ctx.r24.u64 = ctx.r23.u64;
loc_8208A7E8:
	// lwz r11,152(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 152);
	// mr r25,r23
	ctx.r25.u64 = ctx.r23.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8208a814
	if (ctx.cr6.eq) goto loc_8208A814;
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// clrlwi r5,r11,16
	ctx.r5.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r9,32(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8208A814;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8208A814:
	// lwz r29,104(r27)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r27.u32 + 104);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8208a8a0
	if (ctx.cr6.eq) goto loc_8208A8A0;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,1525
	ctx.r8.s64 = 99942400;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// ori r21,r8,57599
	ctx.r21.u64 = ctx.r8.u64 | 57599;
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
loc_8208A844:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208A858;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8208a910
	if (ctx.cr6.eq) goto loc_8208A910;
	// lbz r11,140(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 140);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8208a894
	if (ctx.cr6.eq) goto loc_8208A894;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,180(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 180);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208A888;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8208a910
	if (!ctx.cr6.eq) goto loc_8208A910;
loc_8208A894:
	// cmplw cr6,r24,r29
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8208ab88
	if (!ctx.cr6.eq) goto loc_8208AB88;
	// li r23,2
	ctx.r23.s64 = 2;
loc_8208A8A0:
	// lwz r11,152(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 152);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8208a8c4
	if (ctx.cr6.eq) goto loc_8208A8C4;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208A8C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8208A8C4:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x8208a8fc
	if (ctx.cr6.eq) goto loc_8208A8FC;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
loc_8208A8D0:
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
	ctx.lr = 0x8208A8F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8208a8d0
	if (!ctx.cr0.eq) goto loc_8208A8D0;
loc_8208A8FC:
	// or r3,r22,r23
	ctx.r3.u64 = ctx.r22.u64 | ctx.r23.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
loc_8208A910:
	// lbz r11,86(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 86);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8208ab88
	if (ctx.cr6.eq) goto loc_8208AB88;
	// lwz r11,8248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8248);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r11,1998
	ctx.r10.s64 = ctx.r11.s64 + 1998;
	// stw r11,8248(r31)
	REX_STORE_U32(ctx.r31.u32 + 8248, ctx.r11.u32);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r27,r9,r31
	REX_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r27.u32);
	// lbz r8,86(r29)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r29.u32 + 86);
	// rlwinm r7,r8,0,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8208a9c0
	if (ctx.cr6.eq) goto loc_8208A9C0;
	// lwz r11,2760(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 2760);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8208a99c
	if (!ctx.cr6.eq) goto loc_8208A99C;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stfs f30,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// stfs f30,4(r30)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
	// stfs f31,8(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// mr r8,r23
	ctx.r8.u64 = ctx.r23.u64;
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
loc_8208A99C:
	// lbz r11,86(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 86);
	// addi r4,r29,36
	ctx.r4.s64 = ctx.r29.s64 + 36;
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8208a9b4
	if (!ctx.cr6.eq) goto loc_8208A9B4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
loc_8208A9B4:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82086090
	ctx.lr = 0x8208A9C0;
	sub_82086090(ctx, base);
loc_8208A9C0:
	// lwz r11,76(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208aa28
	if (ctx.cr6.eq) goto loc_8208AA28;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820836e0
	ctx.lr = 0x8208A9D4;
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
	ctx.lr = 0x8208A9F8;
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
loc_8208AA28:
	// lwz r10,32(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8208aa70
	if (ctx.cr6.eq) goto loc_8208AA70;
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
	ctx.lr = 0x8208AA68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// b 0x8208ab08
	goto loc_8208AB08;
loc_8208AA70:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x8208ab08
	if (ctx.cr6.eq) goto loc_8208AB08;
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
	// ble cr6,0x8208aae0
	if (!ctx.cr6.gt) goto loc_8208AAE0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208AAAC;
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
	ctx.lr = 0x8208AAC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,10312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10312);
	// addi r7,r11,2546
	ctx.r7.s64 = ctx.r11.s64 + 2546;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,10312(r31)
	REX_STORE_U32(ctx.r31.u32 + 10312, ctx.r11.u32);
	// stwx r21,r6,r31
	REX_STORE_U32(ctx.r6.u32 + ctx.r31.u32, ctx.r21.u32);
	// b 0x8208ab08
	goto loc_8208AB08;
loc_8208AAE0:
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208AAEC;
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
	ctx.lr = 0x8208AB08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8208AB08:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
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
	ctx.lr = 0x8208AB28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,76(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 76);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8208ab40
	if (ctx.cr6.eq) goto loc_8208AB40;
	// lwz r11,10048(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10048);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,10048(r31)
	REX_STORE_U32(ctx.r31.u32 + 10048, ctx.r11.u32);
loc_8208AB40:
	// lbz r11,86(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 86);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8208ab5c
	if (ctx.cr6.eq) goto loc_8208AB5C;
	// lwz r11,9532(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 9532);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,9532(r31)
	REX_STORE_U32(ctx.r31.u32 + 9532, ctx.r11.u32);
loc_8208AB5C:
	// lwz r11,8248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8248);
	// or r22,r3,r22
	ctx.r22.u64 = ctx.r3.u64 | ctx.r22.u64;
	// addi r11,r11,1998
	ctx.r11.s64 = ctx.r11.s64 + 1998;
	// rlwinm r10,r22,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 0) & 0x2;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stwx r23,r9,r31
	REX_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r23.u32);
	// lwz r11,8248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8248);
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// stw r8,8248(r31)
	REX_STORE_U32(ctx.r31.u32 + 8248, ctx.r8.u32);
	// bne cr6,0x8208a8a0
	if (!ctx.cr6.eq) goto loc_8208A8A0;
loc_8208AB88:
	// lwz r29,88(r29)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r29.u32 + 88);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8208a844
	if (!ctx.cr6.eq) goto loc_8208A844;
	// b 0x8208a8a0
	goto loc_8208A8A0;
}
