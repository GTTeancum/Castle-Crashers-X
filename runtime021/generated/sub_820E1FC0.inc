DEFINE_REX_FUNC(sub_820E1FC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,100(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
