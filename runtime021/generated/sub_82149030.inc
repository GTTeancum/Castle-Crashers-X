DEFINE_REX_FUNC(sub_82149030) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f13,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,6676(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6676);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8214906c
	if (!ctx.cr6.lt) goto loc_8214906C;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,6708(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6708);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,6704(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6704);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fadds f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x82149094
	if (!ctx.cr6.lt) goto loc_82149094;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
	// b 0x82149094
	goto loc_82149094;
loc_8214906C:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,6700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6700);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82149088
	if (!ctx.cr6.lt) goto loc_82149088;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,6696(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6696);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82149090
	goto loc_82149090;
loc_82149088:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,6692(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6692);
	ctx.f0.f64 = double(temp.f32);
loc_82149090:
	// fmuls f0,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
loc_82149094:
	// fcmpu cr6,f1,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// bge cr6,0x8214918c
	if (!ctx.cr6.lt) goto loc_8214918C;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lbz r11,18(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 18);
	// extsb. r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f9,9540(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9540);
	ctx.f9.f64 = double(temp.f32);
	// bgt 0x821490d8
	if (ctx.cr0.gt) goto loc_821490D8;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// fadds f12,f1,f9
	ctx.f12.f64 = double(float(ctx.f1.f64 + ctx.f9.f64));
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f11,-27980(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27980);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f11,f13,f11
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// lfs f10,-27944(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -27944);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f8,f12,f10,f11
	ctx.f8.f64 = double(float(std::fma(ctx.f12.f64, ctx.f10.f64, ctx.f11.f64)));
	// fcmpu cr6,f8,f0
	ctx.cr6.compare(ctx.f8.f64, ctx.f0.f64);
	// bgt cr6,0x821490d8
	if (ctx.cr6.gt) goto loc_821490D8;
	// fmadds f0,f12,f10,f11
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f10.f64, ctx.f11.f64)));
loc_821490D8:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f12,-27960(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27960);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fcmpu cr6,f1,f12
	ctx.cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// bgt cr6,0x82149144
	if (ctx.cr6.gt) goto loc_82149144;
	// fcmpu cr6,f1,f9
	ctx.cr6.compare(ctx.f1.f64, ctx.f9.f64);
	// bge cr6,0x82149120
	if (!ctx.cr6.lt) goto loc_82149120;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// fadds f12,f1,f9
	ctx.f12.f64 = double(float(ctx.f1.f64 + ctx.f9.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f11,9984(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9984);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// lfs f11,14684(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14684);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f12,f11,f13
	ctx.f10.f64 = double(float(std::fma(ctx.f12.f64, ctx.f11.f64, ctx.f13.f64)));
	// fcmpu cr6,f10,f0
	ctx.cr6.compare(ctx.f10.f64, ctx.f0.f64);
	// bgt cr6,0x821491bc
	if (ctx.cr6.gt) goto loc_821491BC;
	// fmadds f0,f12,f11,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f11.f64, ctx.f13.f64)));
	// b 0x821491bc
	goto loc_821491BC;
loc_82149120:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f12,-5388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5388);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f13,9672(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9672);
	ctx.f13.f64 = double(temp.f32);
loc_82149134:
	// fmadds f13,f1,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(std::fma(ctx.f1.f64, ctx.f13.f64, ctx.f12.f64)));
loc_82149138:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x821491bc
	if (ctx.cr6.gt) goto loc_821491BC;
	// b 0x821491b8
	goto loc_821491B8;
loc_82149144:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f12,9588(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9588);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fcmpu cr6,f1,f12
	ctx.cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// bgt cr6,0x82149170
	if (ctx.cr6.gt) goto loc_82149170;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f12,-27840(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27840);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f13,9784(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9784);
	ctx.f13.f64 = double(temp.f32);
	// b 0x82149134
	goto loc_82149134;
loc_82149170:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f12,-11332(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11332);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// lfs f12,9688(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9688);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f13,f12,f11
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f12.f64, ctx.f11.f64)));
	// b 0x82149138
	goto loc_82149138;
loc_8214918C:
	// lbz r11,19(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 19);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821491bc
	if (!ctx.cr6.eq) goto loc_821491BC;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,14356(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14356);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// lfs f12,14680(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14680);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f13,f12,f11
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f12.f64, ctx.f11.f64)));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x821491bc
	if (ctx.cr6.lt) goto loc_821491BC;
loc_821491B8:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
loc_821491BC:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f13,6688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6688);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x821491d0
	if (!ctx.cr6.gt) goto loc_821491D0;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_821491D0:
	// lbz r11,18(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 18);
	// extsb. r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt 0x821491e4
	if (ctx.cr0.gt) goto loc_821491E4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,18(r4)
	REX_STORE_U8(ctx.r4.u32 + 18, ctx.r11.u8);
loc_821491E4:
	// stfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// blr 
	return;
}
