DEFINE_REX_FUNC(sub_820B1618) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,12(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// lfs f0,8(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// std r5,32(r1)
	REX_STORE_U64(ctx.r1.u32 + 32, ctx.r5.u64);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// lbz r7,32(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 32);
	// std r8,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// std r7,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// lfd f12,-16(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fmadds f7,f0,f8,f9
	ctx.f7.f64 = double(float(std::fma(ctx.f0.f64, ctx.f8.f64, ctx.f9.f64)));
	// fctiwz f6,f7
	ctx.f6.s64 = std::isnan(ctx.f7.f64) ? int64_t(0x80000000U) : (ctx.f7.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f6.u64);
	// lwz r11,-12(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x820b166c
	if (!ctx.cr6.gt) goto loc_820B166C;
	// li r11,255
	ctx.r11.s64 = 255;
	// b 0x820b1678
	goto loc_820B1678;
loc_820B166C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x820b1678
	if (!ctx.cr6.lt) goto loc_820B1678;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820B1678:
	// lwz r9,20(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// lfs f0,16(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// lbz r5,33(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 33);
	// extsw r6,r9
	ctx.r6.s64 = ctx.r9.s32;
	// stb r11,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// std r6,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// std r5,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f12,-16(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fmadds f7,f0,f8,f9
	ctx.f7.f64 = double(float(std::fma(ctx.f0.f64, ctx.f8.f64, ctx.f9.f64)));
	// fctiwz f6,f7
	ctx.f6.s64 = std::isnan(ctx.f7.f64) ? int64_t(0x80000000U) : (ctx.f7.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f6.u64);
	// lwz r11,-12(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x820b16cc
	if (!ctx.cr6.gt) goto loc_820B16CC;
	// li r11,255
	ctx.r11.s64 = 255;
	// b 0x820b16d8
	goto loc_820B16D8;
loc_820B16CC:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x820b16d8
	if (!ctx.cr6.lt) goto loc_820B16D8;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820B16D8:
	// lwz r9,28(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 28);
	// lfs f0,24(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// lbz r5,34(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 34);
	// extsw r6,r9
	ctx.r6.s64 = ctx.r9.s32;
	// stb r11,1(r3)
	REX_STORE_U8(ctx.r3.u32 + 1, ctx.r11.u8);
	// std r6,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// std r5,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r5.u64);
	// lfd f12,-8(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fmadds f7,f0,f8,f9
	ctx.f7.f64 = double(float(std::fma(ctx.f0.f64, ctx.f8.f64, ctx.f9.f64)));
	// fctiwz f6,f7
	ctx.f6.s64 = std::isnan(ctx.f7.f64) ? int64_t(0x80000000U) : (ctx.f7.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.f6.u64);
	// lwz r11,-4(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -4);
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x820b172c
	if (!ctx.cr6.gt) goto loc_820B172C;
	// li r11,255
	ctx.r11.s64 = 255;
	// b 0x820b1738
	goto loc_820B1738;
loc_820B172C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x820b1738
	if (!ctx.cr6.lt) goto loc_820B1738;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820B1738:
	// lbz r5,35(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 35);
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stb r11,2(r3)
	REX_STORE_U8(ctx.r3.u32 + 2, ctx.r11.u8);
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// std r5,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r5.u64);
	// std r7,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f9,f11
	ctx.f9.f64 = double(ctx.f11.s64);
	// lfd f13,-8(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmadds f7,f10,f0,f8
	ctx.f7.f64 = double(float(std::fma(ctx.f10.f64, ctx.f0.f64, ctx.f8.f64)));
	// fctiwz f6,f7
	ctx.f6.s64 = std::isnan(ctx.f7.f64) ? int64_t(0x80000000U) : (ctx.f7.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.f6.u64);
	// lwz r11,-4(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -4);
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x820b1790
	if (!ctx.cr6.gt) goto loc_820B1790;
	// li r11,255
	ctx.r11.s64 = 255;
	// stb r11,3(r3)
	REX_STORE_U8(ctx.r3.u32 + 3, ctx.r11.u8);
	// blr 
	return;
loc_820B1790:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x820b179c
	if (!ctx.cr6.lt) goto loc_820B179C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820B179C:
	// stb r11,3(r3)
	REX_STORE_U8(ctx.r3.u32 + 3, ctx.r11.u8);
	// blr 
	return;
}
