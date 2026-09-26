DEFINE_REX_FUNC(sub_82066680) {
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
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,-2
	ctx.r7.s64 = -2;
	// addi r10,r31,20
	ctx.r10.s64 = ctx.r31.s64 + 20;
	// sth r11,4(r31)
	REX_STORE_U16(ctx.r31.u32 + 4, ctx.r11.u16);
	// li r9,64
	ctx.r9.s64 = 64;
	// sth r11,6(r31)
	REX_STORE_U16(ctx.r31.u32 + 6, ctx.r11.u16);
	// sth r11,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r11.u16);
	// stb r11,14(r31)
	REX_STORE_U8(ctx.r31.u32 + 14, ctx.r11.u8);
	// sth r11,16(r31)
	REX_STORE_U16(ctx.r31.u32 + 16, ctx.r11.u16);
	// stw r11,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r11.u32);
	// stw r11,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r11.u32);
	// stw r11,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r11.u32);
	// stw r11,372(r31)
	REX_STORE_U32(ctx.r31.u32 + 372, ctx.r11.u32);
	// stw r11,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r11.u32);
	// stw r11,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r11.u32);
	// stw r11,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r11.u32);
	// stb r11,392(r31)
	REX_STORE_U8(ctx.r31.u32 + 392, ctx.r11.u8);
	// sth r8,10(r31)
	REX_STORE_U16(ctx.r31.u32 + 10, ctx.r8.u16);
	// sth r7,12(r31)
	REX_STORE_U16(ctx.r31.u32 + 12, ctx.r7.u16);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820666EC:
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x820666ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820666EC;
	// addi r10,r31,276
	ctx.r10.s64 = ctx.r31.s64 + 276;
	// li r9,16
	ctx.r9.s64 = 16;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82066704:
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82066704
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82066704;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stb r11,340(r31)
	REX_STORE_U8(ctx.r31.u32 + 340, ctx.r11.u8);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r8,18736
	ctx.r6.s64 = ctx.r8.s64 + 18736;
	// lfs f13,9700(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9700);
	ctx.f13.f64 = double(temp.f32);
	// stb r7,424(r31)
	REX_STORE_U8(ctx.r31.u32 + 424, ctx.r7.u8);
	// lfs f0,9536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// stw r6,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// stfs f13,412(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 412, temp.u32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// stfs f0,416(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 416, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f0,428(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 428, temp.u32);
	// addi r4,r5,18652
	ctx.r4.s64 = ctx.r5.s64 + 18652;
	// stfs f0,432(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 432, temp.u32);
	// bl 0x82053a00
	ctx.lr = 0x82066758;
	sub_82053A00(ctx, base);
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6612(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -6612);
	// bl 0x82096b48
	ctx.lr = 0x82066770;
	sub_82096B48(ctx, base);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r4,r4,18672
	ctx.r4.s64 = ctx.r4.s64 + 18672;
	// bl 0x82053a00
	ctx.lr = 0x82066780;
	sub_82053A00(ctx, base);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,-6612(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -6612);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82096b48
	ctx.lr = 0x82066794;
	sub_82096B48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
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
