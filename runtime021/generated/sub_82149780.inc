DEFINE_REX_FUNC(sub_82149780) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// fcmpu cr6,f2,f3
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f2.f64, ctx.f3.f64);
	// bgt cr6,0x8214981c
	if (ctx.cr6.gt) goto loc_8214981C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r3,-32234
	ctx.r3.s64 = -2112487424;
	// lfs f12,4852(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4852);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,6752(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6752);
	ctx.f13.f64 = double(temp.f32);
loc_821497A4:
	// fmadds f11,f2,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(std::fma(ctx.f2.f64, ctx.f13.f64, ctx.f12.f64)));
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// fmr f0,f4
	ctx.f0.f64 = ctx.f4.f64;
	// fctiwz f11,f11
	ctx.f11.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f11,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f11.u64);
	// lwz r4,-28(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -28);
	// ble cr6,0x821497f8
	if (!ctx.cr6.gt) goto loc_821497F8;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// subf r5,r8,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r8.u64;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
loc_821497CC:
	// lwzx r31,r5,r11
	ctx.r31.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lwz r30,-28456(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + -28456);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// mullw r31,r31,r4
	ctx.r31.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r4.s32);
	// addis r31,r31,128
	ctx.r31.s64 = ctx.r31.s64 + 8388608;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// rlwinm r31,r31,10,22,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 10) & 0x3FC;
	// lfsx f10,r31,r30
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f0,f10,f11,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f10.f64, ctx.f11.f64, ctx.f0.f64)));
	// bne 0x821497cc
	if (!ctx.cr0.eq) goto loc_821497CC;
loc_821497F8:
	// lfs f11,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x82149810
	if (!ctx.cr6.gt) goto loc_82149810;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stfs f0,0(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f2,0(r11)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_82149810:
	// fadds f2,f1,f2
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fcmpu cr6,f2,f3
	ctx.cr6.compare(ctx.f2.f64, ctx.f3.f64);
	// ble cr6,0x821497a4
	if (!ctx.cr6.gt) goto loc_821497A4;
loc_8214981C:
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}
