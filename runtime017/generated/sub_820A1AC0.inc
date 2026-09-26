DEFINE_REX_FUNC(sub_820A1AC0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r7,r8,7268
	ctx.r7.s64 = ctx.r8.s64 + 7268;
	// lfs f0,9536(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// lfs f13,9548(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9548);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,1356(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 1356, temp.u32);
	// stb r31,8(r30)
	REX_STORE_U8(ctx.r30.u32 + 8, ctx.r31.u8);
	// stfs f13,1364(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 1364, temp.u32);
	// stw r7,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r7.u32);
	// stb r31,9(r30)
	REX_STORE_U8(ctx.r30.u32 + 9, ctx.r31.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r31,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r31.u32);
	// stw r6,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r6.u32);
	// stw r31,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r31.u32);
	// stw r31,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r31.u32);
	// stb r31,28(r30)
	REX_STORE_U8(ctx.r30.u32 + 28, ctx.r31.u8);
	// stb r31,29(r30)
	REX_STORE_U8(ctx.r30.u32 + 29, ctx.r31.u8);
	// stw r31,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r31.u32);
	// stw r31,36(r30)
	REX_STORE_U32(ctx.r30.u32 + 36, ctx.r31.u32);
	// stw r31,104(r30)
	REX_STORE_U32(ctx.r30.u32 + 104, ctx.r31.u32);
	// stw r31,108(r30)
	REX_STORE_U32(ctx.r30.u32 + 108, ctx.r31.u32);
	// stw r31,112(r30)
	REX_STORE_U32(ctx.r30.u32 + 112, ctx.r31.u32);
	// stw r31,116(r30)
	REX_STORE_U32(ctx.r30.u32 + 116, ctx.r31.u32);
	// stw r31,120(r30)
	REX_STORE_U32(ctx.r30.u32 + 120, ctx.r31.u32);
	// stw r31,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r31.u32);
	// stw r31,176(r30)
	REX_STORE_U32(ctx.r30.u32 + 176, ctx.r31.u32);
	// stb r31,180(r30)
	REX_STORE_U8(ctx.r30.u32 + 180, ctx.r31.u8);
	// stb r31,272(r30)
	REX_STORE_U8(ctx.r30.u32 + 272, ctx.r31.u8);
	// stw r31,276(r30)
	REX_STORE_U32(ctx.r30.u32 + 276, ctx.r31.u32);
	// stw r31,280(r30)
	REX_STORE_U32(ctx.r30.u32 + 280, ctx.r31.u32);
	// stb r31,1184(r30)
	REX_STORE_U8(ctx.r30.u32 + 1184, ctx.r31.u8);
	// stb r31,1185(r30)
	REX_STORE_U8(ctx.r30.u32 + 1185, ctx.r31.u8);
	// stb r31,1360(r30)
	REX_STORE_U8(ctx.r30.u32 + 1360, ctx.r31.u8);
	// stb r11,1372(r30)
	REX_STORE_U8(ctx.r30.u32 + 1372, ctx.r11.u8);
	// stb r11,1373(r30)
	REX_STORE_U8(ctx.r30.u32 + 1373, ctx.r11.u8);
	// stb r31,1374(r30)
	REX_STORE_U8(ctx.r30.u32 + 1374, ctx.r31.u8);
	// stb r11,1375(r30)
	REX_STORE_U8(ctx.r30.u32 + 1375, ctx.r11.u8);
	// stb r11,1376(r30)
	REX_STORE_U8(ctx.r30.u32 + 1376, ctx.r11.u8);
	// stb r31,1377(r30)
	REX_STORE_U8(ctx.r30.u32 + 1377, ctx.r31.u8);
	// stb r31,1378(r30)
	REX_STORE_U8(ctx.r30.u32 + 1378, ctx.r31.u8);
	// stw r11,1384(r30)
	REX_STORE_U32(ctx.r30.u32 + 1384, ctx.r11.u32);
	// std r31,1408(r30)
	REX_STORE_U64(ctx.r30.u32 + 1408, ctx.r31.u64);
	// bl 0x820b6d10
	ctx.lr = 0x820A1B94;
	sub_820B6D10(ctx, base);
	// ld r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// std r5,1392(r30)
	REX_STORE_U64(ctx.r30.u32 + 1392, ctx.r5.u64);
	// bl 0x820b6d48
	ctx.lr = 0x820A1BA4;
	sub_820B6D48(ctx, base);
	// ld r3,88(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// std r3,1400(r30)
	REX_STORE_U64(ctx.r30.u32 + 1400, ctx.r3.u64);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f0,9540(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1416(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 1416, temp.u32);
	// std r31,40(r30)
	REX_STORE_U64(ctx.r30.u32 + 40, ctx.r31.u64);
	// std r31,72(r30)
	REX_STORE_U64(ctx.r30.u32 + 72, ctx.r31.u64);
	// std r31,48(r30)
	REX_STORE_U64(ctx.r30.u32 + 48, ctx.r31.u64);
	// std r31,80(r30)
	REX_STORE_U64(ctx.r30.u32 + 80, ctx.r31.u64);
	// std r31,56(r30)
	REX_STORE_U64(ctx.r30.u32 + 56, ctx.r31.u64);
	// std r31,88(r30)
	REX_STORE_U64(ctx.r30.u32 + 88, ctx.r31.u64);
	// std r31,64(r30)
	REX_STORE_U64(ctx.r30.u32 + 64, ctx.r31.u64);
	// std r31,96(r30)
	REX_STORE_U64(ctx.r30.u32 + 96, ctx.r31.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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
