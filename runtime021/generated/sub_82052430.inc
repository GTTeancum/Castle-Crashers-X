DEFINE_REX_FUNC(sub_82052430) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82052438;
	__savegprlr_28(ctx, base);
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// bge cr6,0x820524d0
	if (!ctx.cr6.lt) goto loc_820524D0;
	// rlwinm r11,r3,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// add r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r10,r10,25216
	ctx.r10.s64 = ctx.r10.s64 + 25216;
	// rlwinm r11,r9,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// lis r9,8192
	ctx.r9.s64 = 536870912;
	// lis r8,8192
	ctx.r8.s64 = 536870912;
	// lis r28,8192
	ctx.r28.s64 = 536870912;
	// clrlwi r3,r6,16
	ctx.r3.u64 = ctx.r6.u32 & 0xFFFF;
	// extsw r31,r7
	ctx.r31.s64 = ctx.r7.s32;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// ori r6,r9,19
	ctx.r6.u64 = ctx.r9.u64 | 19;
	// ori r7,r8,23
	ctx.r7.u64 = ctx.r8.u64 | 23;
	// clrldi r4,r4,32
	ctx.r4.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// clrldi r5,r5,32
	ctx.r5.u64 = ctx.r5.u64 & 0xFFFFFFFF;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r29,9
	ctx.r29.s64 = 9;
	// li r30,0
	ctx.r30.s64 = 0;
	// ori r8,r28,28
	ctx.r8.u64 = ctx.r28.u64 | 28;
loc_82052494:
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
	// stw r29,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r29.u32);
	// stb r30,48(r11)
	REX_STORE_U8(ctx.r11.u32 + 48, ctx.r30.u8);
	// stw r3,56(r11)
	REX_STORE_U32(ctx.r11.u32 + 56, ctx.r3.u32);
	// stw r8,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r8.u32);
	// stb r9,72(r11)
	REX_STORE_U8(ctx.r11.u32 + 72, ctx.r9.u8);
	// std r31,80(r11)
	REX_STORE_U64(ctx.r11.u32 + 80, ctx.r31.u64);
	// addi r11,r11,96
	ctx.r11.s64 = ctx.r11.s64 + 96;
	// bne 0x82052494
	if (!ctx.cr0.eq) goto loc_82052494;
loc_820524D0:
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
