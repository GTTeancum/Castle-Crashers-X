DEFINE_REX_FUNC(sub_8212DE60) {
	REX_FUNC_PROLOGUE();
	// lis r11,32752
	ctx.r11.s64 = 2146435072;
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lwz r10,16(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 16);
	// lwz r9,20(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8212de88
	if (!ctx.cr6.eq) goto loc_8212DE88;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8212dea4
	if (!ctx.cr6.eq) goto loc_8212DEA4;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8212DE88:
	// lis r11,-16
	ctx.r11.s64 = -1048576;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8212dea4
	if (!ctx.cr6.eq) goto loc_8212DEA4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8212dea4
	if (!ctx.cr6.eq) goto loc_8212DEA4;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8212DEA4:
	// lhz r11,16(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm r11,r11,0,17,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7FF8;
	// cmplwi cr6,r11,32760
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32760, ctx.xer);
	// bne cr6,0x8212debc
	if (!ctx.cr6.eq) goto loc_8212DEBC;
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8212DEBC:
	// cmplwi cr6,r11,32752
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32752, ctx.xer);
	// bne cr6,0x8212dedc
	if (!ctx.cr6.eq) goto loc_8212DEDC;
	// clrlwi. r11,r10,13
	ctx.r11.u64 = ctx.r10.u32 & 0x7FFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212ded4
	if (!ctx.cr0.eq) goto loc_8212DED4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8212dedc
	if (ctx.cr6.eq) goto loc_8212DEDC;
loc_8212DED4:
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
loc_8212DEDC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
