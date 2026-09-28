DEFINE_REX_FUNC(sub_8206AAD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r8,1
	ctx.r8.s64 = 1;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lwz r11,-6612(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6612);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,9880(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9880);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r7,18352
	ctx.r4.s64 = ctx.r7.s64 + 18352;
	// lfs f13,9536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,108(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// stb r8,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r8.u8);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f13,116(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 116, temp.u32);
	// stfs f12,112(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 112, temp.u32);
	// stfs f11,120(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 120, temp.u32);
	// bl 0x82053a00
	ctx.lr = 0x8206AB20;
	sub_82053A00(ctx, base);
	// lis r6,-32218
	ctx.r6.s64 = -2111438848;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,-6624(r6)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + -6624);
	// bl 0x820778d0
	ctx.lr = 0x8206AB30;
	sub_820778D0(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6628(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + -6628);
	// bl 0x820a3540
	ctx.lr = 0x8206AB40;
	sub_820A3540(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
