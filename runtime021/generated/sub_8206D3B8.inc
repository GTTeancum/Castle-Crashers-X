DEFINE_REX_FUNC(sub_8206D3B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// li r6,8
	ctx.r6.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lwz r3,-6624(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -6624);
	// lhz r9,10(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// bl 0x82077310
	ctx.lr = 0x8206D3F0;
	sub_82077310(ctx, base);
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,-6628(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -6628);
	// stb r31,180(r11)
	REX_STORE_U8(ctx.r11.u32 + 180, ctx.r31.u8);
	// bl 0x82053bc8
	ctx.lr = 0x8206D40C;
	sub_82053BC8(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r5,48(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f0,9536(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,428(r5)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r5.u32 + 428, temp.u32);
	// stb r6,424(r5)
	REX_STORE_U8(ctx.r5.u32 + 424, ctx.r6.u8);
	// stb r31,340(r5)
	REX_STORE_U8(ctx.r5.u32 + 340, ctx.r31.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
