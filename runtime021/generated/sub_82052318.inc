DEFINE_REX_FUNC(sub_82052318) {
	REX_FUNC_PROLOGUE();
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// bge cr6,0x82052394
	if (!ctx.cr6.lt) goto loc_82052394;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// mulli r11,r3,216
	ctx.r11.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(216));
	// addi r10,r10,26488
	ctx.r10.s64 = ctx.r10.s64 + 26488;
	// clrldi r7,r6,32
	ctx.r7.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// addi r9,r10,8
	ctx.r9.s64 = ctx.r10.s64 + 8;
	// lis r6,8192
	ctx.r6.s64 = 536870912;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// li r10,3
	ctx.r10.s64 = 3;
	// ori r8,r9,24
	ctx.r8.u64 = ctx.r9.u64 | 24;
	// ori r9,r6,21
	ctx.r9.u64 = ctx.r6.u64 | 21;
	// li r30,10
	ctx.r30.s64 = 10;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// li r6,2
	ctx.r6.s64 = 2;
loc_82052364:
	// stw r4,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r5,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r5.u32);
	// stw r30,-8(r11)
	REX_STORE_U32(ctx.r11.u32 + -8, ctx.r30.u32);
	// stb r31,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r31.u8);
	// stw r8,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r8.u32);
	// stb r3,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r3.u8);
	// stw r9,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r9.u32);
	// stb r6,48(r11)
	REX_STORE_U8(ctx.r11.u32 + 48, ctx.r6.u8);
	// std r7,56(r11)
	REX_STORE_U64(ctx.r11.u32 + 56, ctx.r7.u64);
	// addi r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 + 72;
	// bne 0x82052364
	if (!ctx.cr0.eq) goto loc_82052364;
loc_82052394:
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}
