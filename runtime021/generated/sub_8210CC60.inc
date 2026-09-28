DEFINE_REX_FUNC(sub_8210CC60) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 10);
	// lhz r10,14(r4)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r4.u32 + 14);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210cc78
	if (!ctx.cr6.eq) goto loc_8210CC78;
	// clrlwi. r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8210ccb8
	if (ctx.cr0.eq) goto loc_8210CCB8;
loc_8210CC78:
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x8210cc8c
	if (!ctx.cr6.eq) goto loc_8210CC8C;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65535, ctx.xer);
	// beq cr6,0x8210ccb8
	if (ctx.cr6.eq) goto loc_8210CCB8;
loc_8210CC8C:
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8210ccb8
	if (ctx.cr6.eq) goto loc_8210CCB8;
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8210ccb8
	if (ctx.cr6.eq) goto loc_8210CCB8;
	// lhz r11,36(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 36);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r3,r11,1
	ctx.r3.u64 = ctx.r11.u64 ^ 1;
	// blr 
	return;
loc_8210CCB8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
