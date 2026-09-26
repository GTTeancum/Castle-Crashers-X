DEFINE_REX_FUNC(sub_820A1940) {
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
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lbz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a1978
	if (!ctx.cr6.eq) goto loc_820A1978;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne cr6,0x820a1a00
	if (!ctx.cr6.eq) goto loc_820A1A00;
loc_820A1978:
	// cmplwi cr6,r31,3
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 3, ctx.xer);
	// bgt cr6,0x820a19ec
	if (ctx.cr6.gt) goto loc_820A19EC;
	// lis r12,-32246
	ctx.r12.s64 = -2113273856;
	// addi r12,r12,6552
	ctx.r12.s64 = ctx.r12.s64 + 6552;
	// rlwinm r0,r31,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r31.u32) {
	case 0:
		goto loc_820A19A8;
	case 1:
		goto loc_820A19B0;
	case 2:
		goto loc_820A19B8;
	case 3:
		goto loc_820A19C4;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820A19A8:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x820a19cc
	goto loc_820A19CC;
loc_820A19B0:
	// li r11,16384
	ctx.r11.s64 = 16384;
	// b 0x820a19cc
	goto loc_820A19CC;
loc_820A19B8:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 32768;
	// b 0x820a19cc
	goto loc_820A19CC;
loc_820A19C4:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,61440
	ctx.r11.u64 = ctx.r11.u64 | 61440;
loc_820A19CC:
	// sth r11,114(r1)
	REX_STORE_U16(ctx.r1.u32 + 114, ctx.r11.u16);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// sth r11,112(r1)
	REX_STORE_U16(ctx.r1.u32 + 112, ctx.r11.u16);
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x820b6b90
	ctx.lr = 0x820A19E0;
	sub_820B6B90(ctx, base);
	// stfs f31,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 20, temp.u32);
	// stw r31,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r31.u32);
	// b 0x820a1a00
	goto loc_820A1A00;
loc_820A19EC:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r11,3072
	ctx.r3.s64 = ctx.r11.s64 + 3072;
	// bl 0x820798d8
	ctx.lr = 0x820A19FC;
	sub_820798D8(ctx, base);
	// bl 0x8208c5d8
	ctx.lr = 0x820A1A00;
	sub_8208C5D8(ctx, base);
loc_820A1A00:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
