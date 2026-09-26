DEFINE_REX_FUNC(sub_821260B0) {
	REX_FUNC_PROLOGUE();
	// li r11,2
	ctx.r11.s64 = 2;
	// cmplwi cr6,r5,16383
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 16383, ctx.xer);
	// ble cr6,0x821260c4
	if (!ctx.cr6.gt) goto loc_821260C4;
	// li r11,6
	ctx.r11.s64 = 6;
	// b 0x821260e0
	goto loc_821260E0;
loc_821260C4:
	// cmplwi cr6,r5,127
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 127, ctx.xer);
	// ble cr6,0x821260d4
	if (!ctx.cr6.gt) goto loc_821260D4;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x821260e0
	goto loc_821260E0;
loc_821260D4:
	// cmplwi cr6,r5,15
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 15, ctx.xer);
	// ble cr6,0x821260e0
	if (!ctx.cr6.gt) goto loc_821260E0;
	// li r11,3
	ctx.r11.s64 = 3;
loc_821260E0:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x821260ec
	if (ctx.cr6.eq) goto loc_821260EC;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
loc_821260EC:
	// clrlwi. r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x821260fc
	if (!ctx.cr0.eq) goto loc_821260FC;
	// cmplwi cr6,r4,510
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 510, ctx.xer);
	// ble cr6,0x82126108
	if (!ctx.cr6.gt) goto loc_82126108;
loc_821260FC:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x82126108
	if (!ctx.cr6.eq) goto loc_82126108;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82126108:
	// cmpwi cr6,r3,128
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 128, ctx.xer);
	// beq cr6,0x82126114
	if (ctx.cr6.eq) goto loc_82126114;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82126114:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}
