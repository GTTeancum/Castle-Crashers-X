DEFINE_REX_FUNC(sub_820C8B40) {
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
	// beq cr6,0x820c8b9c
	if (ctx.cr6.eq) goto loc_820C8B9C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f0,6392(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 6392);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bge cr6,0x820c8b70
	if (!ctx.cr6.lt) goto loc_820C8B70;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,6384(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6384);
	ctx.f0.f64 = double(temp.f32);
	// b 0x820c8bb4
	goto loc_820C8BB4;
loc_820C8B70:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,6380(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6380);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// lfs f0,6376(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6376);
	ctx.f0.f64 = double(temp.f32);
	// lfd f2,6368(r10)
	ctx.f2.u64 = REX_LOAD_U64(ctx.r10.u32 + 6368);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x8212ac88
	ctx.lr = 0x820C8B94;
	sub_8212AC88(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// b 0x820c8be0
	goto loc_820C8BE0;
loc_820C8B9C:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f0,6360(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 6360);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bge cr6,0x820c8bbc
	if (!ctx.cr6.lt) goto loc_820C8BBC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,9716(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9716);
	ctx.f0.f64 = double(temp.f32);
loc_820C8BB4:
	// fmuls f1,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// b 0x820c8be0
	goto loc_820C8BE0;
loc_820C8BBC:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f2,6352(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f2.u64 = REX_LOAD_U64(ctx.r11.u32 + 6352);
	// bl 0x8212ac88
	ctx.lr = 0x820C8BC8;
	sub_8212AC88(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,6344(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,6380(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6380);
	ctx.f13.f64 = double(temp.f32);
	// fmsubs f1,f12,f0,f13
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f13.f64)));
loc_820C8BE0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
