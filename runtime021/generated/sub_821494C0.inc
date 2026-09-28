DEFINE_REX_FUNC(sub_821494C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x821494C8;
	__savegprlr_25(ctx, base);
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f30.u64);
	// stfd f31,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// lfs f13,2308(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 2308);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r8,2056
	ctx.r4.s64 = ctx.r8.s64 + 2056;
	// stfs f13,2312(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 2312, temp.u32);
	// fmr f0,f2
	ctx.f0.f64 = ctx.f2.f64;
	// lfs f13,2568(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 2568);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r8,2316
	ctx.r3.s64 = ctx.r8.s64 + 2316;
	// stfs f13,2572(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 2572, temp.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// ble cr6,0x821495f0
	if (!ctx.cr6.gt) goto loc_821495F0;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lis r31,-32255
	ctx.r31.s64 = -2113863680;
	// lwz r27,92(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lis r30,-32255
	ctx.r30.s64 = -2113863680;
	// lis r29,-32255
	ctx.r29.s64 = -2113863680;
	// lis r28,-32255
	ctx.r28.s64 = -2113863680;
	// lis r25,-32255
	ctx.r25.s64 = -2113863680;
	// lfs f9,14356(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14356);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,6736(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 6736);
	ctx.f8.f64 = double(temp.f32);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// lfs f10,6740(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 6740);
	ctx.f10.f64 = double(temp.f32);
	// subf r26,r8,r9
	ctx.r26.u64 = ctx.r9.u64 - ctx.r8.u64;
	// lfs f11,6744(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 6744);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,6748(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 6748);
	ctx.f12.f64 = double(temp.f32);
	// lfs f7,-27832(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -27832);
	ctx.f7.f64 = double(temp.f32);
loc_82149534:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// ble cr6,0x82149548
	if (!ctx.cr6.gt) goto loc_82149548;
	// fnmsubs f13,f0,f12,f11
	ctx.f13.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f12.f64, -ctx.f11.f64)));
	// fmadds f13,f13,f0,f10
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f10.f64)));
	// b 0x8214954c
	goto loc_8214954C;
loc_82149548:
	// fmuls f13,f0,f8
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f8.f64));
loc_8214954C:
	// fmuls f13,f13,f9
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// addic. r5,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// fadds f0,f0,f2
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f2.f64));
	// fctiwz f6,f13
	ctx.f6.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f6,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f6.u64);
	// lwz r11,-92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -92);
	// extsw r31,r11
	ctx.r31.s64 = ctx.r11.s32;
	// std r31,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.r31.u64);
	// lfd f6,-88(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// fcfid f6,f6
	ctx.f6.f64 = double(ctx.f6.s64);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// frsp f6,f6
	ctx.f6.f64 = double(float(ctx.f6.f64));
	// add r31,r11,r10
	ctx.r31.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r30,r11,r4
	ctx.r30.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lfsx f5,r11,r10
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f5.f64 = double(temp.f32);
	// lfsx f3,r11,r4
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r4.u32);
	ctx.f3.f64 = double(temp.f32);
	// add r29,r11,r3
	ctx.r29.u64 = ctx.r11.u64 + ctx.r3.u64;
	// add r28,r11,r27
	ctx.r28.u64 = ctx.r11.u64 + ctx.r27.u64;
	// lfs f31,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// fsubs f31,f31,f5
	ctx.f31.f64 = double(float(ctx.f31.f64 - ctx.f5.f64));
	// fsubs f30,f30,f3
	ctx.f30.f64 = double(float(ctx.f30.f64 - ctx.f3.f64));
	// fsubs f13,f13,f6
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f6.f64));
	// fmadds f6,f31,f13,f5
	ctx.f6.f64 = double(float(std::fma(ctx.f31.f64, ctx.f13.f64, ctx.f5.f64)));
	// fmadds f5,f30,f13,f3
	ctx.f5.f64 = double(float(std::fma(ctx.f30.f64, ctx.f13.f64, ctx.f3.f64)));
	// fsubs f5,f5,f6
	ctx.f5.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fmadds f6,f5,f4,f6
	ctx.f6.f64 = double(float(std::fma(ctx.f5.f64, ctx.f4.f64, ctx.f6.f64)));
	// stfsx f6,r26,r8
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r26.u32 + ctx.r8.u32, temp.u32);
	// lfsx f6,r11,r3
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// lfsx f3,r11,r27
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	ctx.f3.f64 = double(temp.f32);
	// lfs f31,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// fsubs f31,f31,f3
	ctx.f31.f64 = double(float(ctx.f31.f64 - ctx.f3.f64));
	// fsubs f5,f5,f6
	ctx.f5.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fmadds f3,f31,f13,f3
	ctx.f3.f64 = double(float(std::fma(ctx.f31.f64, ctx.f13.f64, ctx.f3.f64)));
	// fmadds f13,f5,f13,f6
	ctx.f13.f64 = double(float(std::fma(ctx.f5.f64, ctx.f13.f64, ctx.f6.f64)));
	// fsubs f13,f13,f3
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f3.f64));
	// fmadds f13,f13,f4,f3
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f4.f64, ctx.f3.f64)));
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x82149534
	if (!ctx.cr0.eq) goto loc_82149534;
loc_821495F0:
	// cmpw cr6,r7,r6
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x8214961c
	if (!ctx.cr6.lt) goto loc_8214961C;
	// rlwinm r11,r7,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r7,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r7.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_82149604:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bne 0x82149604
	if (!ctx.cr0.eq) goto loc_82149604;
loc_8214961C:
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
