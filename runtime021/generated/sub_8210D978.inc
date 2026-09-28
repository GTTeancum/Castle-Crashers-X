DEFINE_REX_FUNC(sub_8210D978) {
	REX_FUNC_PROLOGUE();
	// lwz r11,168(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 168);
	// rlwinm. r11,r11,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210d9a4
	if (ctx.cr0.eq) goto loc_8210D9A4;
	// lbz r11,56(r6)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + 56);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8210d9a4
	if (!ctx.cr0.gt) goto loc_8210D9A4;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// ble cr6,0x8210d9a4
	if (!ctx.cr6.gt) goto loc_8210D9A4;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8210d9a4
	if (ctx.cr6.gt) goto loc_8210D9A4;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8210D9A4:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// blr 
	return;
}
