DEFINE_REX_FUNC(sub_820C9950) {
	REX_FUNC_PROLOGUE();
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820c9960
	if (!ctx.cr6.eq) goto loc_820C9960;
	// blr 
	return;
loc_820C9960:
	// b 0x820c7360
	sub_820C7360(ctx, base);
	return;
}
