DEFINE_REX_FUNC(sub_82082F18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82082F20;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// cmplwi cr6,r11,14
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 14, ctx.xer);
	// bgt cr6,0x8208341c
	if (ctx.cr6.gt) goto loc_8208341C;
	// lis r12,-32248
	ctx.r12.s64 = -2113404928;
	// addi r12,r12,12128
	ctx.r12.s64 = ctx.r12.s64 + 12128;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82082F9C;
	case 1:
		goto loc_8208341C;
	case 2:
		goto loc_82083084;
	case 3:
		goto loc_8208341C;
	case 4:
		goto loc_8208341C;
	case 5:
		goto loc_8208341C;
	case 6:
		goto loc_820832AC;
	case 7:
		goto loc_8208341C;
	case 8:
		goto loc_8208341C;
	case 9:
		goto loc_8208341C;
	case 10:
		goto loc_8208341C;
	case 11:
		goto loc_8208341C;
	case 12:
		goto loc_8208341C;
	case 13:
		goto loc_8208341C;
	case 14:
		goto loc_82083180;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82082F9C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bne cr6,0x82083054
	if (!ctx.cr6.eq) goto loc_82083054;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r31,10316(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 10316);
	// bl 0x82082890
	ctx.lr = 0x82082FB4;
	sub_82082890(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82082fc8
	if (!ctx.cr6.eq) goto loc_82082FC8;
	// addi r4,r31,12
	ctx.r4.s64 = ctx.r31.s64 + 12;
	// b 0x82082fd4
	goto loc_82082FD4;
loc_82082FC8:
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_82082FD4:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82053a00
	ctx.lr = 0x82082FDC;
	sub_82053A00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82082670
	ctx.lr = 0x82082FE4;
	sub_82082670(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82082ffc
	if (ctx.cr6.eq) goto loc_82082FFC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r11,-7088
	ctx.r4.s64 = ctx.r11.s64 + -7088;
	// b 0x82083004
	goto loc_82083004;
loc_82082FFC:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r11,-7096
	ctx.r4.s64 = ctx.r11.s64 + -7096;
loc_82083004:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-7068
	ctx.r3.s64 = ctx.r11.s64 + -7068;
	// bl 0x820798d8
	ctx.lr = 0x82083010;
	sub_820798D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82053a00
	ctx.lr = 0x8208301C;
	sub_82053A00(ctx, base);
	// addi r10,r1,180
	ctx.r10.s64 = ctx.r1.s64 + 180;
	// addi r11,r1,100
	ctx.r11.s64 = ctx.r1.s64 + 100;
loc_82083024:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82083024
	if (!ctx.cr6.eq) goto loc_82083024;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82083038:
	// lbz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stb r9,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x82083038
	if (!ctx.cr6.eq) goto loc_82083038;
	// b 0x820833f4
	goto loc_820833F4;
loc_82083054:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82083058:
	// bl 0x82082bb0
	ctx.lr = 0x8208305C;
	sub_82082BB0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82082bb0
	ctx.lr = 0x82083068;
	sub_82082BB0(ctx, base);
	// add r11,r30,r3
	ctx.r11.u64 = ctx.r30.u64 + ctx.r3.u64;
loc_8208306C:
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r11,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82083084:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bne cr6,0x82083120
	if (!ctx.cr6.eq) goto loc_82083120;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r31,10316(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 10316);
	// bl 0x82082890
	ctx.lr = 0x8208309C;
	sub_82082890(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820830b0
	if (!ctx.cr6.eq) goto loc_820830B0;
	// addi r4,r31,12
	ctx.r4.s64 = ctx.r31.s64 + 12;
	// b 0x820830bc
	goto loc_820830BC;
loc_820830B0:
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_820830BC:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82053a00
	ctx.lr = 0x820830C4;
	sub_82053A00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82082bb0
	ctx.lr = 0x820830CC;
	sub_82082BB0(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-7076
	ctx.r3.s64 = ctx.r11.s64 + -7076;
	// bl 0x820798d8
	ctx.lr = 0x820830DC;
	sub_820798D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82053a00
	ctx.lr = 0x820830E8;
	sub_82053A00(ctx, base);
	// addi r10,r1,180
	ctx.r10.s64 = ctx.r1.s64 + 180;
	// addi r11,r1,100
	ctx.r11.s64 = ctx.r1.s64 + 100;
loc_820830F0:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x820830f0
	if (!ctx.cr6.eq) goto loc_820830F0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82083104:
	// lbz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stb r9,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x82083104
	if (!ctx.cr6.eq) goto loc_82083104;
	// b 0x820833f4
	goto loc_820833F4;
loc_82083120:
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bne cr6,0x82083058
	if (!ctx.cr6.eq) goto loc_82083058;
	// bl 0x82082700
	ctx.lr = 0x82083130;
	sub_82082700(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x82082700
	ctx.lr = 0x8208313C;
	sub_82082700(ctx, base);
	// fadds f0,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f1.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fcmpu cr6,f10,f0
	ctx.cr6.compare(ctx.f10.f64, ctx.f0.f64);
	// beq cr6,0x8208306c
	if (ctx.cr6.eq) goto loc_8208306C;
	// li r11,16
	ctx.r11.s64 = 16;
	// stfs f0,4(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-48(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82083180:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bne cr6,0x82083220
	if (!ctx.cr6.eq) goto loc_82083220;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r31,10316(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 10316);
	// bl 0x82082890
	ctx.lr = 0x82083198;
	sub_82082890(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820831ac
	if (!ctx.cr6.eq) goto loc_820831AC;
	// addi r4,r31,12
	ctx.r4.s64 = ctx.r31.s64 + 12;
	// b 0x820831b8
	goto loc_820831B8;
loc_820831AC:
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_820831B8:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82053a00
	ctx.lr = 0x820831C0;
	sub_82053A00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82082700
	ctx.lr = 0x820831C8;
	sub_82082700(ctx, base);
	// stfd f1,24(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 24);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-7064
	ctx.r3.s64 = ctx.r11.s64 + -7064;
	// bl 0x820798d8
	ctx.lr = 0x820831DC;
	sub_820798D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82053a00
	ctx.lr = 0x820831E8;
	sub_82053A00(ctx, base);
	// addi r10,r1,180
	ctx.r10.s64 = ctx.r1.s64 + 180;
	// addi r11,r1,100
	ctx.r11.s64 = ctx.r1.s64 + 100;
loc_820831F0:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x820831f0
	if (!ctx.cr6.eq) goto loc_820831F0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82083204:
	// lbz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stb r9,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x82083204
	if (!ctx.cr6.eq) goto loc_82083204;
	// b 0x820833f4
	goto loc_820833F4;
loc_82083220:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bne cr6,0x82083280
	if (!ctx.cr6.eq) goto loc_82083280;
	// bl 0x82082700
	ctx.lr = 0x82083230;
	sub_82082700(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x82082700
	ctx.lr = 0x8208323C;
	sub_82082700(ctx, base);
	// fadds f0,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f1.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fcmpu cr6,f10,f0
	ctx.cr6.compare(ctx.f10.f64, ctx.f0.f64);
	// beq cr6,0x8208306c
	if (ctx.cr6.eq) goto loc_8208306C;
	// li r11,16
	ctx.r11.s64 = 16;
	// stfs f0,4(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-48(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82083280:
	// bl 0x82082700
	ctx.lr = 0x82083284;
	sub_82082700(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x82082700
	ctx.lr = 0x82083290;
	sub_82082700(ctx, base);
	// li r11,16
	ctx.r11.s64 = 16;
	// fadds f0,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f1.f64));
	// stfs f0,4(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-48(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820832AC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// stb r10,100(r1)
	REX_STORE_U8(ctx.r1.u32 + 100, ctx.r10.u8);
	// bne cr6,0x82083310
	if (!ctx.cr6.eq) goto loc_82083310;
	// bl 0x82082670
	ctx.lr = 0x820832CC;
	sub_82082670(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820832f4
	if (ctx.cr6.eq) goto loc_820832F4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r11,-7088
	ctx.r4.s64 = ctx.r11.s64 + -7088;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-7068
	ctx.r3.s64 = ctx.r11.s64 + -7068;
	// bl 0x820798d8
	ctx.lr = 0x820832EC;
	sub_820798D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82083384
	goto loc_82083384;
loc_820832F4:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r11,-7096
	ctx.r4.s64 = ctx.r11.s64 + -7096;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-7068
	ctx.r3.s64 = ctx.r11.s64 + -7068;
	// bl 0x820798d8
	ctx.lr = 0x82083308;
	sub_820798D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82083384
	goto loc_82083384;
loc_82083310:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x82083334
	if (!ctx.cr6.eq) goto loc_82083334;
	// bl 0x82082bb0
	ctx.lr = 0x8208331C;
	sub_82082BB0(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-7076
	ctx.r3.s64 = ctx.r11.s64 + -7076;
	// bl 0x820798d8
	ctx.lr = 0x8208332C;
	sub_820798D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82083384
	goto loc_82083384;
loc_82083334:
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bne cr6,0x8208335c
	if (!ctx.cr6.eq) goto loc_8208335C;
	// bl 0x82082700
	ctx.lr = 0x82083340;
	sub_82082700(ctx, base);
	// stfd f1,24(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 24);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-7064
	ctx.r3.s64 = ctx.r11.s64 + -7064;
	// bl 0x820798d8
	ctx.lr = 0x82083354;
	sub_820798D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82083384
	goto loc_82083384;
loc_8208335C:
	// lwz r31,10316(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 10316);
	// bl 0x82082890
	ctx.lr = 0x82083364;
	sub_82082890(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82083378
	if (!ctx.cr6.eq) goto loc_82083378;
	// addi r4,r31,12
	ctx.r4.s64 = ctx.r31.s64 + 12;
	// b 0x82083384
	goto loc_82083384;
loc_82083378:
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_82083384:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82053a00
	ctx.lr = 0x8208338C;
	sub_82053A00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r31,10316(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 10316);
	// bl 0x82082890
	ctx.lr = 0x82083398;
	sub_82082890(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820833ac
	if (!ctx.cr6.eq) goto loc_820833AC;
	// addi r4,r31,12
	ctx.r4.s64 = ctx.r31.s64 + 12;
	// b 0x820833b8
	goto loc_820833B8;
loc_820833AC:
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_820833B8:
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82053a00
	ctx.lr = 0x820833C0;
	sub_82053A00(ctx, base);
	// addi r10,r1,180
	ctx.r10.s64 = ctx.r1.s64 + 180;
	// addi r11,r1,100
	ctx.r11.s64 = ctx.r1.s64 + 100;
loc_820833C8:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x820833c8
	if (!ctx.cr6.eq) goto loc_820833C8;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_820833DC:
	// lbz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stb r9,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x820833dc
	if (!ctx.cr6.eq) goto loc_820833DC;
loc_820833F4:
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// lwz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// lwz r3,10316(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 10316);
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// bl 0x8209d948
	ctx.lr = 0x82083410;
	sub_8209D948(ctx, base);
	// li r8,8
	ctx.r8.s64 = 8;
	// sth r3,4(r28)
	REX_STORE_U16(ctx.r28.u32 + 4, ctx.r3.u16);
	// stw r8,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r8.u32);
loc_8208341C:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
