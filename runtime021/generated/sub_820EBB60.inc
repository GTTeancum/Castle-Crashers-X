DEFINE_REX_FUNC(sub_820EBB60) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// bgt cr6,0x820ebb70
	if (ctx.cr6.gt) goto loc_820EBB70;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_820EBB70:
	// cmplwi cr6,r3,9973
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 9973, ctx.xer);
	// blt cr6,0x820ebb80
	if (ctx.cr6.lt) goto loc_820EBB80;
	// li r3,9973
	ctx.r3.s64 = 9973;
	// blr 
	return;
loc_820EBB80:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1229
	ctx.r8.s64 = 1229;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r6,r10,-27128
	ctx.r6.s64 = ctx.r10.s64 + -27128;
loc_820EBB94:
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// rlwinm r11,r10,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r5,r6
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x820ebbc8
	if (ctx.cr6.eq) goto loc_820EBBC8;
	// ble cr6,0x820ebbbc
	if (!ctx.cr6.gt) goto loc_820EBBBC;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// b 0x820ebbc0
	goto loc_820EBBC0;
loc_820EBBBC:
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
loc_820EBBC0:
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x820ebb94
	if (!ctx.cr6.eq) goto loc_820EBB94;
loc_820EBBC8:
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r6
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r6.u32);
	// blr 
	return;
}
