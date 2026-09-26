DEFINE_REX_FUNC(sub_82115238) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// stw r10,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// lhz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 32);
	// sth r11,4(r4)
	REX_STORE_U16(ctx.r4.u32 + 4, ctx.r11.u16);
	// blr 
	return;
}
