DEFINE_REX_FUNC(sub_820A86B0) {
	REX_FUNC_PROLOGUE();
	// lbz r11,28715(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,28720(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28720);
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// lwz r10,28724(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 28724);
	// stw r10,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}
