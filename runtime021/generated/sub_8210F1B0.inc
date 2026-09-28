DEFINE_REX_FUNC(sub_8210F1B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8210F1B8;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// bge cr6,0x8210f1d8
	if (!ctx.cr6.lt) goto loc_8210F1D8;
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4106
	ctx.r3.u64 = ctx.r3.u64 | 4106;
	// b 0x8210f294
	goto loc_8210F294;
loc_8210F1D8:
	// lwz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// li r28,0
	ctx.r28.s64 = 0;
	// rlwinm. r10,r11,0,6,6
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8210f290
	if (!ctx.cr0.eq) goto loc_8210F290;
	// rlwinm. r10,r11,0,8,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8210f290
	if (!ctx.cr0.eq) goto loc_8210F290;
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8210f290
	if (!ctx.cr0.eq) goto loc_8210F290;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r28,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r28.u32);
	// li r10,14
	ctx.r10.s64 = 14;
	// stw r28,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// addi r11,r11,-20751
	ctx.r11.s64 = ctx.r11.s64 + -20751;
	// lwz r3,68(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// li r29,1
	ctx.r29.s64 = 1;
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lis r8,-32646
	ctx.r8.s64 = -2139488256;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lis r4,32767
	ctx.r4.s64 = 2147418112;
	// li r9,1155
	ctx.r9.s64 = 1155;
	// ori r8,r8,4113
	ctx.r8.u64 = ctx.r8.u64 | 4113;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// ori r4,r4,65534
	ctx.r4.u64 = ctx.r4.u64 | 65534;
	// bl 0x82115188
	ctx.lr = 0x8210F244;
	sub_82115188(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8210f294
	if (!ctx.cr0.eq) goto loc_8210F294;
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8210f26c
	if (!ctx.cr6.eq) goto loc_8210F26C;
	// lwz r10,96(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 96);
	// addi r11,r30,8
	ctx.r11.s64 = ctx.r30.s64 + 8;
	// rlwimi r10,r29,30,1,2
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 30) & 0x60000000) | (ctx.r10.u64 & 0xFFFFFFFF9FFFFFFF);
	// stw r10,96(r30)
	REX_STORE_U32(ctx.r30.u32 + 96, ctx.r10.u32);
loc_8210F26C:
	// lwz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// lis r10,-32646
	ctx.r10.s64 = -2139488256;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// ori r10,r10,4113
	ctx.r10.u64 = ctx.r10.u64 | 4113;
	// oris r11,r11,2176
	ctx.r11.u64 = ctx.r11.u64 | 142606336;
	// stw r10,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// bl 0x8210da60
	ctx.lr = 0x8210F290;
	sub_8210DA60(ctx, base);
loc_8210F290:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_8210F294:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
