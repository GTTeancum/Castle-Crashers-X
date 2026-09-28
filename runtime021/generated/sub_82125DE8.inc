DEFINE_REX_FUNC(sub_82125DE8) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r5,9
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 9, ctx.xer);
	// bge cr6,0x82125df8
	if (!ctx.cr6.lt) goto loc_82125DF8;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82125DF8:
	// stw r4,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}
