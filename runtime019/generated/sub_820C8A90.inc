DEFINE_REX_FUNC(sub_820C8A90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x820c8aec
	if (ctx.cr6.eq) goto loc_820C8AEC;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f0,6336(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 6336);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bgt cr6,0x820c8ac0
	if (ctx.cr6.gt) goto loc_820C8AC0;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,6328(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6328);
	ctx.f0.f64 = double(temp.f32);
	// b 0x820c8b04
	goto loc_820C8B04;
loc_820C8AC0:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,6324(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6324);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// lfs f0,6320(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6320);
	ctx.f0.f64 = double(temp.f32);
	// lfd f2,6312(r10)
	ctx.f2.u64 = REX_LOAD_U64(ctx.r10.u32 + 6312);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x8212ac88
	ctx.lr = 0x820C8AE4;
	sub_8212AC88(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// b 0x820c8b30
	goto loc_820C8B30;
loc_820C8AEC:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f0,6304(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 6304);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bgt cr6,0x820c8b0c
	if (ctx.cr6.gt) goto loc_820C8B0C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,6296(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6296);
	ctx.f0.f64 = double(temp.f32);
loc_820C8B04:
	// fmuls f1,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// b 0x820c8b30
	goto loc_820C8B30;
loc_820C8B0C:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f2,6288(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f2.u64 = REX_LOAD_U64(ctx.r11.u32 + 6288);
	// bl 0x8212ac88
	ctx.lr = 0x820C8B18;
	sub_8212AC88(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,6284(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6284);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,6324(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6324);
	ctx.f13.f64 = double(temp.f32);
	// fmsubs f1,f12,f0,f13
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f13.f64)));
loc_820C8B30:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
