DEFINE_REX_FUNC(sub_8211A158) {
	REX_FUNC_PROLOGUE();
	// lwz r9,1016(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 1016);
	// addi r11,r3,1016
	ctx.r11.s64 = ctx.r3.s64 + 1016;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8211a1d8
	if (ctx.cr6.eq) goto loc_8211A1D8;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x8211a180
	if (ctx.cr6.eq) goto loc_8211A180;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_8211A180:
	// lhz r10,824(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 824);
	// lhz r11,872(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 872);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// extsh. r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8211a1d0
	if (!ctx.cr0.gt) goto loc_8211A1D0;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8211a1c8
	if (ctx.cr6.lt) goto loc_8211A1C8;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x8211a1b8
	if (!ctx.cr6.lt) goto loc_8211A1B8;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// srawi r11,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 3;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// b 0x8211a1c4
	goto loc_8211A1C4;
loc_8211A1B8:
	// addi r11,r11,-72
	ctx.r11.s64 = ctx.r11.s64 + -72;
	// srawi r11,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 5;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
loc_8211A1C4:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
loc_8211A1C8:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x8211a1d4
	goto loc_8211A1D4;
loc_8211A1D0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8211A1D4:
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
loc_8211A1D8:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}
