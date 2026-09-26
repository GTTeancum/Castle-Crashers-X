DEFINE_REX_FUNC(sub_8211AE00) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r9,464(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 464);
	// lwz r10,84(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// subf r9,r9,r4
	ctx.r9.u64 = ctx.r4.u64 - ctx.r9.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8211ae44
	if (ctx.cr6.eq) goto loc_8211AE44;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8211ae30
	if (ctx.cr6.lt) goto loc_8211AE30;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8211ae40
	goto loc_8211AE40;
loc_8211AE30:
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8211ae40
	if (!ctx.cr6.lt) goto loc_8211AE40;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_8211AE40:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8211AE44:
	// lwz r9,468(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 468);
	// lwz r10,88(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// subf r9,r9,r4
	ctx.r9.u64 = ctx.r4.u64 - ctx.r9.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8211ae7c
	if (ctx.cr6.eq) goto loc_8211AE7C;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8211ae68
	if (ctx.cr6.lt) goto loc_8211AE68;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8211ae78
	goto loc_8211AE78;
loc_8211AE68:
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8211ae78
	if (!ctx.cr6.lt) goto loc_8211AE78;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_8211AE78:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8211AE7C:
	// lhz r7,1050(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 1050);
	// lhz r9,1032(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 1032);
	// lwz r10,1028(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 1028);
	// subf r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	// lhz r6,1056(r11)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r11.u32 + 1056);
	// subf r10,r10,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r10.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// cmpw cr6,r9,r6
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x8211aed0
	if (ctx.cr6.lt) goto loc_8211AED0;
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8211aed0
	if (ctx.cr6.eq) goto loc_8211AED0;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8211aebc
	if (ctx.cr6.lt) goto loc_8211AEBC;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8211aecc
	goto loc_8211AECC;
loc_8211AEBC:
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8211aecc
	if (!ctx.cr6.lt) goto loc_8211AECC;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
loc_8211AECC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8211AED0:
	// stw r8,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}
