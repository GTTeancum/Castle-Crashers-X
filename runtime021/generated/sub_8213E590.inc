DEFINE_REX_FUNC(sub_8213E590) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8213e5a0
	if (ctx.cr6.eq) goto loc_8213E5A0;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
loc_8213E5A0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
