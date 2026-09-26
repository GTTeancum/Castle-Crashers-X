DEFINE_REX_FUNC(sub_820E2820) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r11,r3,8
	ctx.r11.s64 = ctx.r3.s64 + 8;
	// bne cr6,0x820e2830
	if (!ctx.cr6.eq) goto loc_820E2830;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820E2830:
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}
