DEFINE_REX_FUNC(sub_820A8CE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r4,32(r1)
	REX_STORE_U64(ctx.r1.u32 + 32, ctx.r4.u64);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// std r5,40(r1)
	REX_STORE_U64(ctx.r1.u32 + 40, ctx.r5.u64);
	// lwz r9,36(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 36);
	// lwz r8,40(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 40);
	// lwz r11,32(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 32);
	// stw r11,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// lfs f0,18248(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 18248);
	ctx.f0.f64 = double(temp.f32);
	// stw r8,8(r6)
	REX_STORE_U32(ctx.r6.u32 + 8, ctx.r8.u32);
	// stw r9,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
	// lfs f13,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f12,4(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// lfs f10,0(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// lfs f9,8(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,-24(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// fadds f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// stfs f8,-28(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// fadds f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// stfs f7,-32(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lwz r7,-28(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -28);
	// lwz r5,-32(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -32);
	// stw r5,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
	// stw r7,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r7.u32);
	// lfs f6,0(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lwz r4,-24(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// stw r4,8(r6)
	REX_STORE_U32(ctx.r6.u32 + 8, ctx.r4.u32);
	// lfs f4,8(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,-8(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// lwz r11,29124(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 29124);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lfs f5,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// addi r10,r11,1198
	ctx.r10.s64 = ctx.r11.s64 + 1198;
	// lwz r7,-8(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// rlwinm r11,r5,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// add r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r8,28748(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 28748);
	// std r8,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r8.u64);
	// lwzx r4,r10,r3
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// lfd f3,-32(r1)
	ctx.f3.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// std r4,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r4.u64);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// lfd f1,-32(r1)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// frsp f13,f2
	ctx.f13.f64 = double(float(ctx.f2.f64));
	// fcfid f0,f1
	ctx.f0.f64 = double(ctx.f1.s64);
	// stw r7,8(r6)
	REX_STORE_U32(ctx.r6.u32 + 8, ctx.r7.u32);
	// fmuls f11,f6,f13
	ctx.f11.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// stfs f11,-16(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// lwz r3,-16(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -16);
	// stw r3,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r3.u32);
	// fmuls f10,f5,f12
	ctx.f10.f64 = double(float(ctx.f5.f64 * ctx.f12.f64));
	// stfs f10,-12(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// lwz r11,-12(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// stw r11,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}
