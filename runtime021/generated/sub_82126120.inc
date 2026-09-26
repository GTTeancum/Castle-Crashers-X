DEFINE_REX_FUNC(sub_82126120) {
	REX_FUNC_PROLOGUE();
	// addi r11,r7,-2
	ctx.r11.s64 = ctx.r7.s64 + -2;
	// cmplwi cr6,r4,16383
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 16383, ctx.xer);
	// ble cr6,0x82126134
	if (!ctx.cr6.gt) goto loc_82126134;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// b 0x82126150
	goto loc_82126150;
loc_82126134:
	// cmplwi cr6,r4,127
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 127, ctx.xer);
	// ble cr6,0x82126144
	if (!ctx.cr6.gt) goto loc_82126144;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// b 0x82126150
	goto loc_82126150;
loc_82126144:
	// cmplwi cr6,r4,15
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 15, ctx.xer);
	// ble cr6,0x82126150
	if (!ctx.cr6.gt) goto loc_82126150;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82126150:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x8212615c
	if (ctx.cr6.eq) goto loc_8212615C;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
loc_8212615C:
	// cmpwi cr6,r3,128
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 128, ctx.xer);
	// beq cr6,0x82126168
	if (ctx.cr6.eq) goto loc_82126168;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82126168:
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82126178
	if (!ctx.cr0.eq) goto loc_82126178;
	// cmplwi cr6,r11,510
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 510, ctx.xer);
	// ble cr6,0x82126184
	if (!ctx.cr6.gt) goto loc_82126184;
loc_82126178:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x82126184
	if (!ctx.cr6.eq) goto loc_82126184;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82126184:
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// ble cr6,0x82126190
	if (!ctx.cr6.gt) goto loc_82126190;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82126190:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}
