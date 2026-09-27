DEFINE_REX_FUNC(sub_820867F0) {
	REX_FUNC_PROLOGUE();
	// lhz r3,146(r3)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r3.u32 + 146);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}
