DEFINE_REX_FUNC(sub_8209BB30) {
	REX_FUNC_PROLOGUE();
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lbz r9,101(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 101);
	// li r11,5
	ctx.r11.s64 = 5;
loc_8209BB3C:
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8209bb50
	if (!ctx.cr6.eq) goto loc_8209BB50;
	// li r9,15
	ctx.r9.s64 = 15;
	// b 0x8209bb58
	goto loc_8209BB58;
loc_8209BB50:
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
loc_8209BB58:
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r4,r10,18
	ctx.r4.s64 = ctx.r10.s64 + 18;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwinm r4,r4,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r31,r11,-1
	ctx.r31.s64 = ctx.r11.s64 + -1;
	// lhzx r4,r4,r3
	ctx.r4.u64 = REX_LOAD_U16(ctx.r4.u32 + ctx.r3.u32);
	// sthx r4,r8,r5
	REX_STORE_U16(ctx.r8.u32 + ctx.r5.u32, ctx.r4.u16);
	// lbz r8,68(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 68);
	// stbx r8,r11,r6
	REX_STORE_U8(ctx.r11.u32 + ctx.r6.u32, ctx.r8.u8);
	// lbz r4,84(r10)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + 84);
	// stbx r4,r11,r7
	REX_STORE_U8(ctx.r11.u32 + ctx.r7.u32, ctx.r4.u8);
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x8209bb3c
	if (!ctx.cr6.lt) goto loc_8209BB3C;
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}
