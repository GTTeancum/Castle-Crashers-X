DEFINE_REX_FUNC(sub_82084100) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
	// lfs f12,9536(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9536);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r3,12
	ctx.r9.s64 = ctx.r3.s64 + 12;
	// stfs f12,4(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f12,8(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f12,12(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lhz r31,28(r4)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r4.u32 + 28);
	// lfs f0,9596(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9596);
	ctx.f0.f64 = double(temp.f32);
	// lhz r8,34(r4)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r4.u32 + 34);
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// lfs f13,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// extsh r8,r31
	ctx.r8.s64 = ctx.r31.s16;
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// std r8,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// std r7,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f9,f11
	ctx.f9.f64 = double(ctx.f11.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fmadds f4,f6,f13,f5
	ctx.f4.f64 = double(float(std::fma(ctx.f6.f64, ctx.f13.f64, ctx.f5.f64)));
	// stfs f4,0(r3)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lhz r8,36(r4)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r4.u32 + 36);
	// lfs f3,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// lhz r7,30(r4)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r4.u32 + 30);
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// std r7,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f2,-16(r1)
	ctx.f2.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f2
	ctx.f13.f64 = double(ctx.f2.s64);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// std r8,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f1,-16(r1)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// fcfid f10,f1
	ctx.f10.f64 = double(ctx.f1.s64);
	// fmuls f9,f11,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fmadds f7,f9,f3,f8
	ctx.f7.f64 = double(float(std::fma(ctx.f9.f64, ctx.f3.f64, ctx.f8.f64)));
	// stfs f7,4(r3)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lhz r7,38(r4)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r4.u32 + 38);
	// lfs f6,8(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// lhz r8,32(r4)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r4.u32 + 32);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// std r8,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f5,-16(r1)
	ctx.f5.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f3,f5
	ctx.f3.f64 = double(ctx.f5.s64);
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// std r7,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f4,-16(r1)
	ctx.f4.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// fcfid f1,f4
	ctx.f1.f64 = double(ctx.f4.s64);
	// fmuls f13,f2,f0
	ctx.f13.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// frsp f11,f1
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// fmadds f10,f13,f6,f11
	ctx.f10.f64 = double(float(std::fma(ctx.f13.f64, ctx.f6.f64, ctx.f11.f64)));
	// stfs f10,8(r3)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lhz r7,40(r4)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r4.u32 + 40);
	// lfs f9,12(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f9.f64 = double(temp.f32);
	// lhz r8,42(r4)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r4.u32 + 42);
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// extsh r8,r7
	ctx.r8.s64 = ctx.r7.s16;
	// extsh r7,r4
	ctx.r7.s64 = ctx.r4.s16;
	// std r8,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f8,-16(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// std r7,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f7,-16(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f6,f8
	ctx.f6.f64 = double(ctx.f8.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fcfid f4,f7
	ctx.f4.f64 = double(ctx.f7.s64);
	// fmuls f3,f5,f0
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// lfs f0,9544(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 9544);
	ctx.f0.f64 = double(temp.f32);
	// frsp f2,f4
	ctx.f2.f64 = double(float(ctx.f4.f64));
	// fmadds f1,f3,f9,f2
	ctx.f1.f64 = double(float(std::fma(ctx.f3.f64, ctx.f9.f64, ctx.f2.f64)));
	// stfs f1,12(r3)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lfs f13,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x8208424c
	if (ctx.cr6.lt) goto loc_8208424C;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_8208424C:
	// stfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82084260
	if (ctx.cr6.lt) goto loc_82084260;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_82084260:
	// stfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfs f13,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82084274
	if (ctx.cr6.lt) goto loc_82084274;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_82084274:
	// stfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82084288
	if (!ctx.cr6.lt) goto loc_82084288;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_82084288:
	// stfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bgt cr6,0x8208429c
	if (ctx.cr6.gt) goto loc_8208429C;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8208429C:
	// stfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bgt cr6,0x820842b0
	if (ctx.cr6.gt) goto loc_820842B0;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_820842B0:
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfs f0,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bgt cr6,0x820842c4
	if (ctx.cr6.gt) goto loc_820842C4;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_820842C4:
	// stfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f0,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x820842e0
	if (!ctx.cr6.gt) goto loc_820842E0;
	// stfs f0,0(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_820842E0:
	// stfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}
