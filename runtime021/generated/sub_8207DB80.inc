DEFINE_REX_FUNC(sub_8207DB80) {
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
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,156(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// addi r3,r11,10372
	ctx.r3.s64 = ctx.r11.s64 + 10372;
	// bl 0x82082488
	ctx.lr = 0x8207DBA0;
	sub_82082488(ctx, base);
	// lwz r9,0(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r5,76(r9)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r9.u32 + 76);
	// lfs f0,9732(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9732);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,156(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 156);
	// lfs f13,10340(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10340);
	ctx.f13.f64 = double(temp.f32);
	// stw r6,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f12,4(r7)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r11,156(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 156);
	// addi r11,r11,10372
	ctx.r11.s64 = ctx.r11.s64 + 10372;
	// lwz r8,5024(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 5024);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r7,r6,r11
	REX_STORE_U32(ctx.r6.u32 + ctx.r11.u32, ctx.r7.u32);
	// lwz r10,5024(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 5024);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// stw r5,5024(r11)
	REX_STORE_U32(ctx.r11.u32 + 5024, ctx.r5.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
