DEFINE_REX_FUNC(sub_820FD330) {
	REX_FUNC_PROLOGUE();
	// lwz r11,180(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 180);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x820fd378
	if (!ctx.cr6.lt) goto loc_820FD378;
	// lwz r10,248(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// addi r11,r3,248
	ctx.r11.s64 = ctx.r3.s64 + 248;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820fd354
	if (!ctx.cr6.eq) goto loc_820FD354;
	// li r10,0
	ctx.r10.s64 = 0;
loc_820FD354:
	// lwz r8,304(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 304);
	// addi r3,r10,-92
	ctx.r3.s64 = ctx.r10.s64 + -92;
	// rlwinm. r8,r8,0,4,4
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x820fd370
	if (ctx.cr0.eq) goto loc_820FD370;
	// cmplw cr6,r9,r4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_820FD370:
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x820fd354
	goto loc_820FD354;
loc_820FD378:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
