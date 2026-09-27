DEFINE_REX_FUNC(sub_820B1CA8) {
	REX_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_820B1CC4:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820b1cd4
	if (!ctx.cr6.eq) goto loc_820B1CD4;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// b 0x820b1d44
	goto loc_820B1D44;
loc_820B1CD4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820b1d40
	if (ctx.cr6.eq) goto loc_820B1D40;
	// lwz r8,28(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
loc_820B1CE0:
	// lwz r9,28(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// bgt cr6,0x820b1d5c
	if (ctx.cr6.gt) goto loc_820B1D5C;
	// bne cr6,0x820b1d30
	if (!ctx.cr6.eq) goto loc_820B1D30;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpw cr6,r9,r5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, ctx.xer);
	// bne cr6,0x820b1d10
	if (!ctx.cr6.eq) goto loc_820B1D10;
	// lwz r9,24(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// lwz r5,24(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmpw cr6,r9,r5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, ctx.xer);
	// blt cr6,0x820b1d5c
	if (ctx.cr6.lt) goto loc_820B1D5C;
loc_820B1D10:
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r5,4(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpw cr6,r9,r5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, ctx.xer);
	// bne cr6,0x820b1d30
	if (!ctx.cr6.eq) goto loc_820B1D30;
	// lwz r9,24(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// lwz r5,24(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmpw cr6,r9,r5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, ctx.xer);
	// bgt cr6,0x820b1d5c
	if (ctx.cr6.gt) goto loc_820B1D5C;
loc_820B1D30:
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b1ce0
	if (!ctx.cr6.eq) goto loc_820B1CE0;
loc_820B1D40:
	// stw r10,36(r7)
	REX_STORE_U32(ctx.r7.u32 + 36, ctx.r10.u32);
loc_820B1D44:
	// stw r6,36(r10)
	REX_STORE_U32(ctx.r10.u32 + 36, ctx.r6.u32);
loc_820B1D48:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lwz r10,32(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820b1cc4
	if (!ctx.cr6.eq) goto loc_820B1CC4;
	// blr 
	return;
loc_820B1D5C:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820b1d70
	if (ctx.cr6.eq) goto loc_820B1D70;
	// stw r11,36(r10)
	REX_STORE_U32(ctx.r10.u32 + 36, ctx.r11.u32);
	// stw r10,36(r7)
	REX_STORE_U32(ctx.r7.u32 + 36, ctx.r10.u32);
	// b 0x820b1d48
	goto loc_820B1D48;
loc_820B1D70:
	// stw r3,36(r10)
	REX_STORE_U32(ctx.r10.u32 + 36, ctx.r3.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// b 0x820b1d48
	goto loc_820B1D48;
}
