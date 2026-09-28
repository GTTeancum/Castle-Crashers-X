DEFINE_REX_FUNC(sub_8210D270) {
	REX_FUNC_PROLOGUE();
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
}
