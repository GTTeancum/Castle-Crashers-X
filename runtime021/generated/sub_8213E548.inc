DEFINE_REX_FUNC(sub_8213E548) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8213e560
	if (ctx.cr6.eq) goto loc_8213E560;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,0(r4)
	REX_STORE_U8(ctx.r4.u32 + 0, ctx.r11.u8);
	// sth r10,2(r4)
	REX_STORE_U16(ctx.r4.u32 + 2, ctx.r10.u16);
loc_8213E560:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
