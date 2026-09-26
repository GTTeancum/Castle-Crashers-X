DEFINE_REX_FUNC(sub_8209B258) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8209B260;
	__savegprlr_28(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r29,r4,16
	ctx.r29.u64 = ctx.r4.u32 & 0xFFFF;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// cmplwi cr6,r29,65535
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 65535, ctx.xer);
	// beq cr6,0x8209b310
	if (ctx.cr6.eq) goto loc_8209B310;
	// clrlwi r31,r3,16
	ctx.r31.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8209b2a4
	if (!ctx.cr6.eq) goto loc_8209B2A4;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// mulli r10,r29,140
	ctx.r10.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(140));
	// addi r9,r11,-22008
	ctx.r9.s64 = ctx.r11.s64 + -22008;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lwzx r8,r10,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// stw r8,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r8.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8209B2A4:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r30,r11,26304
	ctx.r30.s64 = ctx.r11.s64 + 26304;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a434
	ctx.lr = 0x8209B2B4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// add r9,r31,r11
	ctx.r9.u64 = ctx.r31.u64 + ctx.r11.u64;
	// addi r11,r10,-22008
	ctx.r11.s64 = ctx.r10.s64 + -22008;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,8
	ctx.r7.s64 = ctx.r11.s64 + 8;
	// mulli r10,r29,140
	ctx.r10.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(140));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// li r5,80
	ctx.r5.s64 = 80;
	// lwzx r11,r8,r7
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r31,r11,12
	ctx.r31.s64 = ctx.r11.s64 + 12;
	// addi r4,r31,40
	ctx.r4.s64 = ctx.r31.s64 + 40;
	// bl 0x82129a70
	ctx.lr = 0x8209B2EC;
	sub_82129A70(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r3,r6,-408
	ctx.r3.s64 = ctx.r6.s64 + -408;
	// bl 0x8208c5d8
	ctx.lr = 0x8209B2F8;
	sub_8208C5D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b0a38
	ctx.lr = 0x8209B300;
	sub_820B0A38(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x8209b31c
	if (!ctx.cr6.lt) goto loc_8209B31C;
loc_8209B308:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8209B30C:
	// bl 0x8214a444
	ctx.lr = 0x8209B310;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8209B310:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8209B31C:
	// lwz r29,140(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x820b0ba8
	ctx.lr = 0x8209B330;
	sub_820B0BA8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8209b308
	if (ctx.cr6.lt) goto loc_8209B308;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b0d80
	ctx.lr = 0x8209B340;
	sub_820B0D80(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// blt cr6,0x8209b30c
	if (ctx.cr6.lt) goto loc_8209B30C;
	// bl 0x8214a444
	ctx.lr = 0x8209B350;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,0(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// bl 0x8209a628
	ctx.lr = 0x8209B35C;
	sub_8209A628(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
