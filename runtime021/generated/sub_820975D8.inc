DEFINE_REX_FUNC(sub_820975D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f30.u64);
	// stfd f31,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6612(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6612);
	// lfs f31,9536(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lfs f30,108(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 108);
	ctx.f30.f64 = double(temp.f32);
	// fdivs f0,f30,f1
	ctx.f0.f64 = double(float(ctx.f30.f64 / ctx.f1.f64));
	// stfs f0,120(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 120, temp.u32);
	// stfs f31,108(r4)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r4.u32 + 108, temp.u32);
	// bl 0x82096fc8
	ctx.lr = 0x8209761C;
	sub_82096FC8(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// stfs f30,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
	// stfs f30,116(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 116, temp.u32);
	// stb r9,1(r31)
	REX_STORE_U8(ctx.r31.u32 + 1, ctx.r9.u8);
	// stfs f31,112(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 112, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f30,-32(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
