DEFINE_REX_FUNC(sub_82135070) {
	REX_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82135080
	if (!ctx.cr6.eq) goto loc_82135080;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82135080:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}
