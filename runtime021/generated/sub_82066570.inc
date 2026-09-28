DEFINE_REX_FUNC(sub_82066570) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r10,368(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 368);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r9,3
	ctx.r9.s64 = 3;
	// lwz r3,356(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 356);
	// stw r9,344(r11)
	REX_STORE_U32(ctx.r11.u32 + 344, ctx.r9.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}
