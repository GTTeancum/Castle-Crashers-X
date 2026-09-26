DEFINE_REX_FUNC(sub_820A74F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f1,18236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18236);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}
