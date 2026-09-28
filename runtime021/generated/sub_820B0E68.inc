DEFINE_REX_FUNC(sub_820B0E68) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,-28288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -28288);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}
