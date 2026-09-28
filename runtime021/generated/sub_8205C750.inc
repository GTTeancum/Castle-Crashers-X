DEFINE_REX_FUNC(sub_8205C750) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x8205C758;
	__savegprlr_24(ctx, base);
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lis r26,-32218
	ctx.r26.s64 = -2111438848;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r31,1
	ctx.r31.s64 = 1;
	// lwz r10,48(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// lwz r11,-6612(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6612);
	// lfs f31,9700(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9700);
	ctx.f31.f64 = double(temp.f32);
	// lfd f30,9960(r8)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r8.u32 + 9960);
	// lhz r25,10(r10)
	ctx.r25.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// sth r25,12(r10)
	REX_STORE_U16(ctx.r10.u32 + 12, ctx.r25.u16);
	// sth r25,10(r10)
	REX_STORE_U16(ctx.r10.u32 + 10, ctx.r25.u16);
	// lfs f0,108(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// lwz r7,48(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// lwz r6,276(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 276);
	// fadd f12,f13,f30
	ctx.f12.f64 = ctx.f13.f64 + ctx.f30.f64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r27,r11,13272
	ctx.r27.s64 = ctx.r11.s64 + 13272;
	// fctiwz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r28,84(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r30,56(r6)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r6.u32 + 56);
loc_8205C7C0:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82127778
	ctx.lr = 0x8205C7D0;
	sub_82127778(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,8(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// bl 0x8209d948
	ctx.lr = 0x8205C7DC;
	sub_8209D948(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205C7F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82085078
	ctx.lr = 0x8205C7FC;
	sub_82085078(ctx, base);
	// cmpw cr6,r28,r31
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r31.s32, ctx.xer);
	// li r4,2
	ctx.r4.s64 = 2;
	// bge cr6,0x8205c80c
	if (!ctx.cr6.lt) goto loc_8205C80C;
	// li r4,1
	ctx.r4.s64 = 1;
loc_8205C80C:
	// bl 0x82087f70
	ctx.lr = 0x8205C810;
	sub_82087F70(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,10
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 10, ctx.xer);
	// ble cr6,0x8205c7c0
	if (!ctx.cr6.gt) goto loc_8205C7C0;
	// lwz r11,-6612(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6612);
	// li r31,1
	ctx.r31.s64 = 1;
	// lwz r10,48(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// lfs f0,104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// lwz r9,280(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 280);
	// lwz r30,56(r9)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + 56);
	// fadd f12,f13,f30
	ctx.f12.f64 = ctx.f13.f64 + ctx.f30.f64;
	// fctiwz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r28,84(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_8205C848:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82127778
	ctx.lr = 0x8205C858;
	sub_82127778(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,8(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// bl 0x8209d948
	ctx.lr = 0x8205C864;
	sub_8209D948(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205C87C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82085078
	ctx.lr = 0x8205C884;
	sub_82085078(ctx, base);
	// cmpw cr6,r28,r31
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r31.s32, ctx.xer);
	// li r4,2
	ctx.r4.s64 = 2;
	// bge cr6,0x8205c894
	if (!ctx.cr6.lt) goto loc_8205C894;
	// li r4,1
	ctx.r4.s64 = 1;
loc_8205C894:
	// bl 0x82087f70
	ctx.lr = 0x8205C898;
	sub_82087F70(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,10
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 10, ctx.xer);
	// ble cr6,0x8205c848
	if (!ctx.cr6.gt) goto loc_8205C848;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r10,48(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// extsh r9,r25
	ctx.r9.s64 = ctx.r25.s16;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-6624(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6624);
	// lwz r28,32(r10)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// lwz r7,1756(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 1756);
	// lwzx r31,r8,r7
	ctx.r31.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8205c954
	if (ctx.cr6.eq) goto loc_8205C954;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r30,r31,8
	ctx.r30.s64 = ctx.r31.s64 + 8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8205c8f4
	if (ctx.cr6.eq) goto loc_8205C8F4;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205C8F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8205c8f8
	goto loc_8205C8F8;
loc_8205C8F4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8205C8F8:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205c940
	if (!ctx.cr6.eq) goto loc_8205C940;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r10,-6652(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -6652);
	// lbz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8205c920
	if (!ctx.cr6.eq) goto loc_8205C920;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8205c930
	goto loc_8205C930;
loc_8205C920:
	// lwz r11,876(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 876);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_8205C930:
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,876(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 876);
	// bl 0x82072eb0
	ctx.lr = 0x8205C940;
	sub_82072EB0(ctx, base);
loc_8205C940:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8205c954
	if (ctx.cr6.eq) goto loc_8205C954;
	// lbz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 16);
	// b 0x8205c958
	goto loc_8205C958;
loc_8205C954:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8205C958:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// sth r9,102(r28)
	REX_STORE_U16(ctx.r28.u32 + 102, ctx.r9.u16);
	// lwz r8,48(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// lwz r11,-6596(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6596);
	// lwz r7,36(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 36);
	// lbz r6,8(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 8);
	// sth r6,102(r7)
	REX_STORE_U16(ctx.r7.u32 + 102, ctx.r6.u16);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
