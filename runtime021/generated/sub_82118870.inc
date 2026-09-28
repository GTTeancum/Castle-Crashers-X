DEFINE_REX_FUNC(sub_82118870) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82118878;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// addi r29,r30,236
	ctx.r29.s64 = ctx.r30.s64 + 236;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214a434
	ctx.lr = 0x82118890;
	__imp__RtlEnterCriticalSection(ctx, base);
	// cntlzw r11,r31
	ctx.r11.u64 = ctx.r31.u32 == 0 ? 32 : __builtin_clz(ctx.r31.u32);
	// lwz r10,440(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 440);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// rlwinm r11,r11,26,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0x80000000;
	// clrlwi r10,r10,1
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// xoris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 ^ 2147483648;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r11,440(r30)
	REX_STORE_U32(ctx.r30.u32 + 440, ctx.r11.u32);
	// bne cr6,0x82118914
	if (!ctx.cr6.eq) goto loc_82118914;
	// lwz r11,280(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 280);
	// addi r31,r30,280
	ctx.r31.s64 = ctx.r30.s64 + 280;
	// b 0x8211890c
	goto loc_8211890C;
loc_821188C0:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x821188d4
	if (!ctx.cr6.eq) goto loc_821188D4;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x821188f4
	goto loc_821188F4;
loc_821188D4:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
loc_821188F4:
	// addi r3,r11,-8
	ctx.r3.s64 = ctx.r11.s64 + -8;
	// bl 0x821180d8
	ctx.lr = 0x821188FC;
	sub_821180D8(ctx, base);
	// lwz r11,276(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 276);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,276(r30)
	REX_STORE_U32(ctx.r30.u32 + 276, ctx.r11.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_8211890C:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x821188c0
	if (!ctx.cr6.eq) goto loc_821188C0;
loc_82118914:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214a444
	ctx.lr = 0x8211891C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
