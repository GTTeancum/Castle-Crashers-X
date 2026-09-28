DEFINE_REX_FUNC(sub_8211A240) {
	REX_FUNC_PROLOGUE();
	// addi r11,r3,1016
	ctx.r11.s64 = ctx.r3.s64 + 1016;
	// lhz r3,872(r3)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r3.u32 + 872);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x8211a268
	if (ctx.cr6.eq) goto loc_8211A268;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_8211A268:
	// lhz r11,824(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 824);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r10,32768
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32768, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}
