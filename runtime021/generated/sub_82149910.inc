DEFINE_REX_FUNC(sub_82149910) {
	REX_FUNC_PROLOGUE();
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// lfd f4,6768(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f4.u64 = REX_LOAD_U64(ctx.r12.u32 + 6768);
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// lfd f5,6776(r12)
	ctx.f5.u64 = REX_LOAD_U64(ctx.r12.u32 + 6776);
	// fcmpu cr0,f1,f4
	ctx.cr0.compare(ctx.f1.f64, ctx.f4.f64);
	// beq- 0x82149950
	if (ctx.cr0.eq) goto loc_82149950;
	// fabs f6,f1
	ctx.f6.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// fcmpu cr0,f6,f5
	ctx.cr0.compare(ctx.f6.f64, ctx.f5.f64);
	// bge- 0x82149950
	if (!ctx.cr0.lt) goto loc_82149950;
	// fcmpu cr0,f1,f4
	ctx.cr0.compare(ctx.f1.f64, ctx.f4.f64);
	// blt 0x82149948
	if (ctx.cr0.lt) goto loc_82149948;
	// fadd f4,f1,f5
	ctx.f4.f64 = ctx.f1.f64 + ctx.f5.f64;
	// fsub f1,f4,f5
	ctx.f1.f64 = ctx.f4.f64 - ctx.f5.f64;
	// b 0x82149950
	goto loc_82149950;
loc_82149948:
	// fsub f4,f1,f5
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f1.f64 - ctx.f5.f64;
	// fadd f1,f4,f5
	ctx.f1.f64 = ctx.f4.f64 + ctx.f5.f64;
loc_82149950:
	// blr 
	return;
}
