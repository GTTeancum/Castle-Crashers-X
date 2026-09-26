DEFINE_REX_FUNC(sub_820E1FD0) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820e1fe4
	if (ctx.cr6.eq) goto loc_820E1FE4;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// b 0x820e1fe8
	goto loc_820E1FE8;
loc_820E1FE4:
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_820E1FE8:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x820e1ff8
	if (ctx.cr6.eq) goto loc_820E1FF8;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x820e1ffc
	goto loc_820E1FFC;
loc_820E1FF8:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_820E1FFC:
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820e2010
	if (ctx.cr6.eq) goto loc_820E2010;
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// subf r3,r10,r11
	ctx.r3.u64 = ctx.r11.u64 - ctx.r10.u64;
	// blr 
	return;
loc_820E2010:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
