DEFINE_REX_FUNC(sub_8211AD88) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r10,1042(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 1042);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// lwz r10,568(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 568);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8211adb4
	if (!ctx.cr6.eq) goto loc_8211ADB4;
	// lwz r10,564(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 564);
	// cmplwi cr6,r10,1184
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1184, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
loc_8211ADB4:
	// lhz r10,1032(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 1032);
	// lhz r9,1046(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 1046);
	// subf r9,r9,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r9.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// cmpwi cr6,r9,256
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 256, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// lhz r8,1050(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 1050);
	// lhz r7,1056(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 1056);
	// subf r10,r8,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r8.u64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// cmpwi cr6,r9,255
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 255, ctx.xer);
	// bne cr6,0x8211adf8
	if (!ctx.cr6.eq) goto loc_8211ADF8;
	// lhz r11,980(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 980);
	// rlwinm. r11,r11,0,0,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF8000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
loc_8211ADF8:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}
