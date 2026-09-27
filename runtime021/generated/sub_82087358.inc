DEFINE_REX_FUNC(sub_82087358) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x82087360;
	__savegprlr_25(ctx, base);
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f30.u64);
	// stfd f31,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-1232(r1)
	ea = -1232 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lfs f30,18236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18236);
	ctx.f30.f64 = double(temp.f32);
	// mr r26,r28
	ctx.r26.u64 = ctx.r28.u64;
	// lfs f31,9536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// stfs f30,0(r30)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// stb r28,12(r30)
	REX_STORE_U8(ctx.r30.u32 + 12, ctx.r28.u8);
	// stfs f30,4(r30)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// stb r28,13(r30)
	REX_STORE_U8(ctx.r30.u32 + 13, ctx.r28.u8);
	// lwz r8,152(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 152);
	// stfs f31,8(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// stfs f30,16(r30)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r30.u32 + 16, temp.u32);
	// stb r28,14(r30)
	REX_STORE_U8(ctx.r30.u32 + 14, ctx.r28.u8);
	// stfs f30,20(r30)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r30.u32 + 20, temp.u32);
	// stfs f31,24(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 24, temp.u32);
	// stfs f31,28(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 28, temp.u32);
	// stfs f31,32(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 32, temp.u32);
	// stfs f31,36(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 36, temp.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820873D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82087518
	if (ctx.cr6.eq) goto loc_82087518;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// addi r27,r1,128
	ctx.r27.s64 = ctx.r1.s64 + 128;
	// lis r29,-32215
	ctx.r29.s64 = -2111242240;
	// addi r31,r11,2720
	ctx.r31.s64 = ctx.r11.s64 + 2720;
loc_820873E8:
	// lbz r11,86(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 86);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82087470
	if (ctx.cr6.eq) goto loc_82087470;
	// lwz r11,2760(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 2760);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8208744c
	if (!ctx.cr6.eq) goto loc_8208744C;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stfs f30,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// stfs f30,4(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// stfs f31,8(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// stfs f30,16(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// stfs f30,20(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stw r11,2760(r29)
	REX_STORE_U32(ctx.r29.u32 + 2760, ctx.r11.u32);
	// stfs f31,24(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// stb r10,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r10.u8);
	// stfs f31,28(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// stb r9,13(r31)
	REX_STORE_U8(ctx.r31.u32 + 13, ctx.r9.u8);
	// stfs f31,32(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// stb r8,14(r31)
	REX_STORE_U8(ctx.r31.u32 + 14, ctx.r8.u8);
	// stfs f31,36(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
loc_8208744C:
	// lbz r11,86(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 86);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// addi r11,r3,36
	ctx.r11.s64 = ctx.r3.s64 + 36;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82087464
	if (!ctx.cr6.eq) goto loc_82087464;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_82087464:
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
loc_82087470:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,152(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82087480;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820873e8
	if (!ctx.cr6.eq) goto loc_820873E8;
	// addic. r31,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r31.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82087518
	if (ctx.cr0.lt) goto loc_82087518;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// add r29,r10,r11
	ctx.r29.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_8208749C:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r5,0(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82085ad8
	ctx.lr = 0x820874AC;
	sub_82085AD8(ctx, base);
	// lbz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 12);
	// lbz r10,13(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 13);
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lbz r9,14(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 14);
	// lfs f13,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// lfs f11,16(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// addi r29,r29,-4
	ctx.r29.s64 = ctx.r29.s64 + -4;
	// lfs f10,20(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// stb r11,12(r30)
	REX_STORE_U8(ctx.r30.u32 + 12, ctx.r11.u8);
	// lfs f9,24(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f9.f64 = double(temp.f32);
	// stb r10,13(r30)
	REX_STORE_U8(ctx.r30.u32 + 13, ctx.r10.u8);
	// lfs f8,28(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// stb r9,14(r30)
	REX_STORE_U8(ctx.r30.u32 + 14, ctx.r9.u8);
	// lfs f7,32(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,36(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// stfs f12,8(r30)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// stfs f11,16(r30)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r30.u32 + 16, temp.u32);
	// stfs f10,20(r30)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r30.u32 + 20, temp.u32);
	// stfs f9,24(r30)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r30.u32 + 24, temp.u32);
	// stfs f8,28(r30)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r30.u32 + 28, temp.u32);
	// stfs f7,32(r30)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r30.u32 + 32, temp.u32);
	// stfs f6,36(r30)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r30.u32 + 36, temp.u32);
	// bge 0x8208749c
	if (!ctx.cr0.lt) goto loc_8208749C;
loc_82087518:
	// lbz r11,86(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 86);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8208759c
	if (ctx.cr6.eq) goto loc_8208759C;
	// addi r5,r25,36
	ctx.r5.s64 = ctx.r25.s64 + 36;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82085ad8
	ctx.lr = 0x82087538;
	sub_82085AD8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lbz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 12);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lbz r9,13(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 13);
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lbz r8,14(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 14);
	// lfs f12,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f9.f64 = double(temp.f32);
	// stb r10,12(r30)
	REX_STORE_U8(ctx.r30.u32 + 12, ctx.r10.u8);
	// lfs f8,28(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// stb r9,13(r30)
	REX_STORE_U8(ctx.r30.u32 + 13, ctx.r9.u8);
	// lfs f7,32(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32);
	ctx.f7.f64 = double(temp.f32);
	// stb r8,14(r30)
	REX_STORE_U8(ctx.r30.u32 + 14, ctx.r8.u8);
	// lfs f6,36(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// stfs f12,8(r30)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// stfs f11,16(r30)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r30.u32 + 16, temp.u32);
	// stfs f10,20(r30)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r30.u32 + 20, temp.u32);
	// stfs f9,24(r30)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r30.u32 + 24, temp.u32);
	// stfs f8,28(r30)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r30.u32 + 28, temp.u32);
	// stfs f7,32(r30)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r30.u32 + 32, temp.u32);
	// stfs f6,36(r30)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r30.u32 + 36, temp.u32);
loc_8208759C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,1232
	ctx.r1.s64 = ctx.r1.s64 + 1232;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
