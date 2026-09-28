DEFINE_REX_FUNC(sub_820956B0) {
	REX_FUNC_PROLOGUE();
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r11,100
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 100, ctx.xer);
	// beq cr6,0x820956e4
	if (ctx.cr6.eq) goto loc_820956E4;
	// cmpwi cr6,r11,101
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 101, ctx.xer);
	// beq cr6,0x820956cc
	if (ctx.cr6.eq) goto loc_820956CC;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_820956CC:
	// lhz r11,148(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 148);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// sth r11,4(r5)
	REX_STORE_U16(ctx.r5.u32 + 4, ctx.r11.u16);
	// blr 
	return;
loc_820956E4:
	// lhz r11,98(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 98);
	// li r10,4
	ctx.r10.s64 = 4;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}
