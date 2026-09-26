DEFINE_REX_FUNC(sub_8209B030) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r10,-7080
	ctx.r10.s64 = ctx.r10.s64 + -7080;
loc_8209B03C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// beq cr6,0x8209b060
	if (ctx.cr6.eq) goto loc_8209B060;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8209b03c
	if (ctx.cr6.eq) goto loc_8209B03C;
loc_8209B060:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8209b074
	if (!ctx.cr6.eq) goto loc_8209B074;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lbz r3,-22602(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + -22602);
	// blr 
	return;
loc_8209B074:
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r11,r11,-16888
	ctx.r11.s64 = ctx.r11.s64 + -16888;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
loc_8209B088:
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_8209B090:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r5,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r5.u64;
	// beq cr6,0x8209b0b4
	if (ctx.cr6.eq) goto loc_8209B0B4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8209b090
	if (ctx.cr6.eq) goto loc_8209B090;
loc_8209B0B4:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8209b0d8
	if (ctx.cr6.eq) goto loc_8209B0D8;
	// addi r7,r7,68
	ctx.r7.s64 = ctx.r7.s64 + 68;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r8,r8,68
	ctx.r8.s64 = ctx.r8.s64 + 68;
	// cmplwi cr6,r7,17408
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 17408, ctx.xer);
	// blt cr6,0x8209b088
	if (ctx.cr6.lt) goto loc_8209B088;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8209B0D8:
	// clrlwi r3,r6,16
	ctx.r3.u64 = ctx.r6.u32 & 0xFFFF;
	// blr 
	return;
}
