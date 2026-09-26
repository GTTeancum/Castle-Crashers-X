DEFINE_REX_FUNC(sub_820C2EF8) {
	REX_FUNC_PROLOGUE();
	// rlwinm r9,r6,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r9,r5
	ctx.r8.u64 = ctx.r5.u64 - ctx.r9.u64;
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// bgt cr6,0x820c2f10
	if (ctx.cr6.gt) goto loc_820C2F10;
	// li r11,1
	ctx.r11.s64 = 1;
loc_820C2F10:
	// subf r7,r9,r4
	ctx.r7.u64 = ctx.r4.u64 - ctx.r9.u64;
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820c2f24
	if (!ctx.cr6.gt) goto loc_820C2F24;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// b 0x820c2f34
	goto loc_820C2F34;
loc_820C2F24:
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// bgt cr6,0x820c2f34
	if (ctx.cr6.gt) goto loc_820C2F34;
	// li r10,1
	ctx.r10.s64 = 1;
loc_820C2F34:
	// subf r11,r9,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r9.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x820c2f70
	if (ctx.cr6.gt) goto loc_820C2F70;
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// bgt cr6,0x820c2f50
	if (ctx.cr6.gt) goto loc_820C2F50;
	// li r11,1
	ctx.r11.s64 = 1;
loc_820C2F50:
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820c2f60
	if (!ctx.cr6.gt) goto loc_820C2F60;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// b 0x820c2f70
	goto loc_820C2F70;
loc_820C2F60:
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// bgt cr6,0x820c2f70
	if (ctx.cr6.gt) goto loc_820C2F70;
	// li r11,1
	ctx.r11.s64 = 1;
loc_820C2F70:
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// subfic r3,r11,32
	ctx.xer.ca = ctx.r11.u32 <= 32;
	ctx.r3.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// blr 
	return;
}
