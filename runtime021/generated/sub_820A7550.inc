DEFINE_REX_FUNC(sub_820A7550) {
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
	// lwz r11,28720(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28720);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r10,28724(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 28724);
	// lfs f6,28732(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 28732);
	ctx.f6.f64 = double(temp.f32);
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// lfs f5,28728(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 28728);
	ctx.f5.f64 = double(temp.f32);
	// clrldi r5,r8,32
	ctx.r5.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// clrldi r4,r6,32
	ctx.r4.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// lfs f3,9536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f3.f64 = double(temp.f32);
	// std r5,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r4,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// lwz r11,84(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 84);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f2,f11
	ctx.f2.f64 = double(float(ctx.f11.f64));
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// frsp f4,f12
	ctx.f4.f64 = double(float(ctx.f12.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820A75B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
