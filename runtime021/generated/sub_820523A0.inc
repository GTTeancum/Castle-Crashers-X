DEFINE_REX_FUNC(sub_820523A0) {
	REX_FUNC_PROLOGUE();
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// bge cr6,0x82052424
	if (!ctx.cr6.lt) goto loc_82052424;
	// rlwinm r11,r3,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// add r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r10,r10,24248
	ctx.r10.s64 = ctx.r10.s64 + 24248;
	// rlwinm r11,r9,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// lis r8,8192
	ctx.r8.s64 = 536870912;
	// li r9,2
	ctx.r9.s64 = 2;
	// lis r7,8192
	ctx.r7.s64 = 536870912;
	// lis r31,8192
	ctx.r31.s64 = 536870912;
	// extsw r3,r6
	ctx.r3.s64 = ctx.r6.s32;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// ori r6,r8,19
	ctx.r6.u64 = ctx.r8.u64 | 19;
	// clrldi r4,r4,32
	ctx.r4.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// clrldi r5,r5,32
	ctx.r5.u64 = ctx.r5.u64 & 0xFFFFFFFF;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// ori r7,r7,23
	ctx.r7.u64 = ctx.r7.u64 | 23;
	// ori r8,r31,28
	ctx.r8.u64 = ctx.r31.u64 | 28;
loc_820523F4:
	// std r4,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r4.u64);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// std r5,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r5.u64);
	// stw r6,-8(r11)
	REX_STORE_U32(ctx.r11.u32 + -8, ctx.r6.u32);
	// stb r9,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// stw r7,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// stb r9,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r9.u8);
	// stw r8,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r8.u32);
	// stb r9,48(r11)
	REX_STORE_U8(ctx.r11.u32 + 48, ctx.r9.u8);
	// std r3,56(r11)
	REX_STORE_U64(ctx.r11.u32 + 56, ctx.r3.u64);
	// addi r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 + 72;
	// bne 0x820523f4
	if (!ctx.cr0.eq) goto loc_820523F4;
loc_82052424:
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}
