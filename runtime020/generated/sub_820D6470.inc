DEFINE_REX_FUNC(sub_820D6470) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,32528
	ctx.r11.s64 = 2131755008;
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820d6488
	if (ctx.cr6.lt) goto loc_820D6488;
	// lis r11,-30976
	ctx.r11.s64 = -2030043136;
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
loc_820D6488:
	// addi r10,r4,127
	ctx.r10.s64 = ctx.r4.s64 + 127;
	// rlwinm r11,r3,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFF80;
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,7
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7F) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 7;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm. r9,r10,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// beq 0x820d64f4
	if (ctx.cr0.eq) goto loc_820D64F4;
loc_820D64AC:
	// dcbf r0,r11
	// li r8,128
	ctx.r8.s64 = 128;
	// dcbf r8,r11
	// li r8,256
	ctx.r8.s64 = 256;
	// dcbf r8,r11
	// li r8,384
	ctx.r8.s64 = 384;
	// dcbf r8,r11
	// li r8,512
	ctx.r8.s64 = 512;
	// dcbf r8,r11
	// li r8,640
	ctx.r8.s64 = 640;
	// dcbf r8,r11
	// li r8,768
	ctx.r8.s64 = 768;
	// dcbf r8,r11
	// li r8,896
	ctx.r8.s64 = 896;
	// dcbf r8,r11
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r11,r11,1024
	ctx.r11.s64 = ctx.r11.s64 + 1024;
	// bne 0x820d64ac
	if (!ctx.cr0.eq) goto loc_820D64AC;
loc_820D64F4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820d650c
	if (ctx.cr6.eq) goto loc_820D650C;
loc_820D64FC:
	// dcbf r0,r11
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// bne 0x820d64fc
	if (!ctx.cr0.eq) goto loc_820D64FC;
loc_820D650C:
	// sync 
	// blr 
	return;
}
