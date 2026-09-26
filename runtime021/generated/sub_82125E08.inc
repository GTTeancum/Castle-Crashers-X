DEFINE_REX_FUNC(sub_82125E08) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r5,6
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 6, ctx.xer);
	// bge cr6,0x82125e18
	if (!ctx.cr6.lt) goto loc_82125E18;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82125E18:
	// stw r4,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}
