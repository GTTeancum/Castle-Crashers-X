DEFINE_REX_FUNC(sub_8213E508) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8213e518
	if (ctx.cr6.eq) goto loc_8213E518;
	// li r11,6172
	ctx.r11.s64 = 6172;
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
loc_8213E518:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
