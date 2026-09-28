DEFINE_REX_FUNC(sub_82145A30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// fmuls f11,f0,f1
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f1.f64));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lfs f5,-4820(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4820);
	ctx.f5.f64 = double(temp.f32);
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
	// lfs f6,9540(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9540);
	ctx.f6.f64 = double(temp.f32);
	// lfs f12,-27980(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -27980);
	ctx.f12.f64 = double(temp.f32);
	// fmr f13,f6
	ctx.f13.f64 = ctx.f6.f64;
	// lfs f3,-4824(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -4824);
	ctx.f3.f64 = double(temp.f32);
	// lfs f4,9700(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 9700);
	ctx.f4.f64 = double(temp.f32);
	// fadds f0,f11,f5
	ctx.f0.f64 = double(float(ctx.f11.f64 + ctx.f5.f64));
	// b 0x82145a78
	goto loc_82145A78;
loc_82145A70:
	// fmuls f0,f0,f4
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f4.f64));
	// fmuls f13,f13,f3
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f3.f64));
loc_82145A78:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// blt cr6,0x82145a70
	if (ctx.cr6.lt) goto loc_82145A70;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// addic. r11,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r11.s64 = ctx.r4.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r6,4
	ctx.r10.s64 = ctx.r6.s64 + 4;
	// lfs f9,-4828(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -4828);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-4832(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -4832);
	ctx.f8.f64 = double(temp.f32);
	// fnmsubs f10,f0,f9,f8
	ctx.f10.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f9.f64, -ctx.f8.f64)));
	// lfs f7,-4836(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -4836);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f0,f10,f0,f7
	ctx.f0.f64 = double(float(std::fma(ctx.f10.f64, ctx.f0.f64, ctx.f7.f64)));
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,0(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// blelr 
	if (!ctx.cr0.gt) return;
loc_82145AB4:
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// fmuls f10,f0,f1
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f1.f64));
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// fcmpu cr6,f10,f11
	ctx.cr6.compare(ctx.f10.f64, ctx.f11.f64);
	// beq cr6,0x82145af8
	if (ctx.cr6.eq) goto loc_82145AF8;
	// fadds f0,f10,f5
	ctx.f0.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// fmr f13,f6
	ctx.f13.f64 = ctx.f6.f64;
	// b 0x82145ae0
	goto loc_82145AE0;
loc_82145AD8:
	// fmuls f0,f0,f4
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f4.f64));
	// fmuls f13,f13,f3
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f3.f64));
loc_82145AE0:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// blt cr6,0x82145ad8
	if (ctx.cr6.lt) goto loc_82145AD8;
	// fnmsubs f11,f0,f9,f8
	ctx.f11.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f9.f64, -ctx.f8.f64)));
	// fmadds f0,f11,f0,f7
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f7.f64)));
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// b 0x82145afc
	goto loc_82145AFC;
loc_82145AF8:
	// lfs f0,-4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
loc_82145AFC:
	// stfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fmr f11,f10
	ctx.f11.f64 = ctx.f10.f64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x82145ab4
	if (ctx.cr6.gt) goto loc_82145AB4;
	// blr 
	return;
}
