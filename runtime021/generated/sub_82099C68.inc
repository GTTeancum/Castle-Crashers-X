DEFINE_REX_FUNC(sub_82099C68) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82099c78
	if (!ctx.cr6.eq) goto loc_82099C78;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82099C78:
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lbz r10,29(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 29);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82099ca4
	if (ctx.cr6.eq) goto loc_82099CA4;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lbz r10,29(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 29);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_82099C9C:
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
	// blr 
	return;
loc_82099CA4:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r9,29(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 29);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82099ce0
	if (!ctx.cr6.eq) goto loc_82099CE0;
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r9,29(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 29);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82099cd8
	if (!ctx.cr6.eq) goto loc_82099CD8;
loc_82099CC4:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lbz r9,29(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 29);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82099cc4
	if (ctx.cr6.eq) goto loc_82099CC4;
loc_82099CD8:
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
loc_82099CE0:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lbz r10,29(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 29);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82099d18
	if (!ctx.cr6.eq) goto loc_82099D18;
loc_82099CF0:
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82099d18
	if (!ctx.cr6.eq) goto loc_82099D18;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lbz r10,29(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 29);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82099cf0
	if (ctx.cr6.eq) goto loc_82099CF0;
loc_82099D18:
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lbz r9,29(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 29);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82099c9c
	if (!ctx.cr6.eq) goto loc_82099C9C;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}
