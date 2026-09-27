DEFINE_REX_FUNC(sub_82067AF0) {
	REX_FUNC_PROLOGUE();
	// lhz r9,102(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 102);
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// beq cr6,0x82067b44
	if (ctx.cr6.eq) goto loc_82067B44;
	// cmpwi cr6,r4,3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 3, ctx.xer);
	// bne cr6,0x82067b88
	if (!ctx.cr6.eq) goto loc_82067B88;
	// lhz r10,100(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 100);
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x82067b3c
	if (!ctx.cr6.eq) goto loc_82067B3C;
	// lbz r11,106(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 106);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82067b30
	if (!ctx.cr6.eq) goto loc_82067B30;
	// clrlwi r11,r5,24
	ctx.r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82067b88
	if (ctx.cr6.eq) goto loc_82067B88;
loc_82067B30:
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r11,102(r3)
	REX_STORE_U16(ctx.r3.u32 + 102, ctx.r11.u16);
	// b 0x82067b88
	goto loc_82067B88;
loc_82067B3C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x82067b84
	goto loc_82067B84;
loc_82067B44:
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82067b7c
	if (!ctx.cr6.eq) goto loc_82067B7C;
	// lbz r11,106(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 106);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82067b68
	if (!ctx.cr6.eq) goto loc_82067B68;
	// clrlwi r11,r5,24
	ctx.r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82067b88
	if (ctx.cr6.eq) goto loc_82067B88;
loc_82067B68:
	// lhz r11,100(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 100);
	// addis r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,102(r3)
	REX_STORE_U16(ctx.r3.u32 + 102, ctx.r10.u16);
	// b 0x82067b88
	goto loc_82067B88;
loc_82067B7C:
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82067B84:
	// sth r11,102(r3)
	REX_STORE_U16(ctx.r3.u32 + 102, ctx.r11.u16);
loc_82067B88:
	// lhz r11,102(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 102);
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,108(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,24(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}
