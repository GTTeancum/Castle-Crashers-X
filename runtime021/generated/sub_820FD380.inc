DEFINE_REX_FUNC(sub_820FD380) {
	REX_FUNC_PROLOGUE();
	// lwz r10,248(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// addi r11,r3,248
	ctx.r11.s64 = ctx.r3.s64 + 248;
	// b 0x820fd3a0
	goto loc_820FD3A0;
loc_820FD38C:
	// ld r8,-76(r10)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r10.u32 + -76);
	// addi r9,r10,-92
	ctx.r9.s64 = ctx.r10.s64 + -92;
	// cmpld cr6,r8,r4
	ctx.cr6.compare<uint64_t>(ctx.r8.u64, ctx.r4.u64, ctx.xer);
	// beq cr6,0x820fd3b4
	if (ctx.cr6.eq) goto loc_820FD3B4;
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
loc_820FD3A0:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820fd3c0
	if (ctx.cr6.eq) goto loc_820FD3C0;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x820fd38c
	if (!ctx.cr0.eq) goto loc_820FD38C;
	// b 0x820fd3c0
	goto loc_820FD3C0;
loc_820FD3B4:
	// lwz r11,396(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 396);
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820fd3c4
	if (!ctx.cr0.eq) goto loc_820FD3C4;
loc_820FD3C0:
	// li r9,0
	ctx.r9.s64 = 0;
loc_820FD3C4:
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// blr 
	return;
}
