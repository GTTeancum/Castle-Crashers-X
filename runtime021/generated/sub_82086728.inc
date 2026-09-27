DEFINE_REX_FUNC(sub_82086728) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lbz r10,86(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 86);
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stb r9,86(r3)
	REX_STORE_U8(ctx.r3.u32 + 86, ctx.r9.u8);
	// lfs f0,9576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9576);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f0,72(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// blr 
	return;
}
