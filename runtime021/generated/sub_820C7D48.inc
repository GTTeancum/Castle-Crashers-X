DEFINE_REX_FUNC(sub_820C7D48) {
	REX_FUNC_PROLOGUE();
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r11,r10,28
	ctx.r11.u64 = ctx.r10.u32 & 0xF;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x820c7da4
	if (!ctx.cr6.eq) goto loc_820C7DA4;
	// lwz r10,48(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// rlwinm r10,r10,23,30,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x3;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bne cr6,0x820c7d70
	if (!ctx.cr6.eq) goto loc_820C7D70;
	// li r11,18
	ctx.r11.s64 = 18;
	// b 0x820c7dcc
	goto loc_820C7DCC;
loc_820C7D70:
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x820c7d80
	if (!ctx.cr6.eq) goto loc_820C7D80;
	// li r11,17
	ctx.r11.s64 = 17;
	// b 0x820c7dcc
	goto loc_820C7DCC;
loc_820C7D80:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820c7d90
	if (!ctx.cr6.eq) goto loc_820C7D90;
	// li r11,20
	ctx.r11.s64 = 20;
	// b 0x820c7dcc
	goto loc_820C7DCC;
loc_820C7D90:
	// lwz r10,32(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// rlwinm. r10,r10,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820c7dcc
	if (ctx.cr0.eq) goto loc_820C7DCC;
	// li r11,19
	ctx.r11.s64 = 19;
	// b 0x820c7dcc
	goto loc_820C7DCC;
loc_820C7DA4:
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x820c7dcc
	if (!ctx.cr6.eq) goto loc_820C7DCC;
	// rlwinm. r10,r10,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820c7dcc
	if (ctx.cr0.eq) goto loc_820C7DCC;
	// lwz r10,24(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r10,48(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 48);
	// rlwinm r10,r10,0,21,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x600;
	// cmplwi cr6,r10,1024
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1024, ctx.xer);
	// bne cr6,0x820c7dcc
	if (!ctx.cr6.eq) goto loc_820C7DCC;
	// li r11,16
	ctx.r11.s64 = 16;
loc_820C7DCC:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}
