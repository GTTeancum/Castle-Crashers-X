DEFINE_REX_FUNC(sub_82094728) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 164, temp.u32);
	// blr 
	return;
}
