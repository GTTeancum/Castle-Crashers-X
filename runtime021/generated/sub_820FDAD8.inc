DEFINE_REX_FUNC(sub_820FDAD8) {
	REX_FUNC_PROLOGUE();
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addic. r11,r4,92
	ctx.xer.ca = ctx.r4.u32 > 4294967203;
	ctx.r11.s64 = ctx.r4.s64 + 92;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r3,-1
	ctx.r3.s64 = -1;
	// beqlr 
	if (ctx.cr0.eq) return;
	// addi r10,r10,248
	ctx.r10.s64 = ctx.r10.s64 + 248;
loc_820FDAEC:
	// lwz r9,304(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 304);
	// rlwinm. r9,r9,0,4,4
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fdafc
	if (ctx.cr0.eq) goto loc_820FDAFC;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_820FDAFC:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x820fdaec
	if (!ctx.cr0.eq) goto loc_820FDAEC;
	// blr 
	return;
}
