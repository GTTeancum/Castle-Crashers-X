DEFINE_REX_FUNC(sub_82127CF0) {
	REX_FUNC_PROLOGUE();
	// b 0x82127d04
	goto loc_82127D04;
loc_82127CF4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82127d14
	if (ctx.cr6.eq) goto loc_82127D14;
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// addi r4,r4,2
	ctx.r4.s64 = ctx.r4.s64 + 2;
loc_82127D04:
	// lhz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r4.u32 + 0);
	// lhz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 0);
	// subf. r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82127cf4
	if (ctx.cr0.eq) goto loc_82127CF4;
loc_82127D14:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82127d24
	if (!ctx.cr6.lt) goto loc_82127D24;
	// li r11,-1
	ctx.r11.s64 = -1;
	// b 0x82127d2c
	goto loc_82127D2C;
loc_82127D24:
	// ble cr6,0x82127d2c
	if (!ctx.cr6.gt) goto loc_82127D2C;
	// li r11,1
	ctx.r11.s64 = 1;
loc_82127D2C:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}
