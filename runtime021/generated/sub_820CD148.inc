DEFINE_REX_FUNC(sub_820CD148) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820CD150;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,21660(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21660);
	// lwz r10,16560(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16560);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820cd170
	if (!ctx.cr6.eq) goto loc_820CD170;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820cd19c
	goto loc_820CD19C;
loc_820CD170:
	// bl 0x8214a6e4
	ctx.lr = 0x820CD174;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x820cd198
	if (ctx.cr6.eq) goto loc_820CD198;
	// lwz r11,21648(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21648);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x820cd1a4
	if (ctx.cr6.eq) goto loc_820CD1A4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820cd198
	if (!ctx.cr6.eq) goto loc_820CD198;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,21648(r31)
	REX_STORE_U32(ctx.r31.u32 + 21648, ctx.r11.u32);
loc_820CD198:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820CD19C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_820CD1A4:
	// lwz r10,21656(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21656);
	// lwz r11,21652(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21652);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820cd198
	if (ctx.cr6.eq) goto loc_820CD198;
	// lwz r10,21640(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21640);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x820c9950
	ctx.lr = 0x820CD1C4;
	sub_820C9950(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x820cd198
	if (!ctx.cr0.eq) goto loc_820CD198;
	// lis r29,-32221
	ctx.r29.s64 = -2111635456;
	// li r5,480
	ctx.r5.s64 = 480;
	// addi r30,r29,5148
	ctx.r30.s64 = ctx.r29.s64 + 5148;
	// addi r3,r30,4
	ctx.r3.s64 = ctx.r30.s64 + 4;
	// addi r4,r30,484
	ctx.r4.s64 = ctx.r30.s64 + 484;
	// bl 0x82129a70
	ctx.lr = 0x820CD1E4;
	sub_82129A70(ctx, base);
	// lwz r11,5148(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 5148);
	// lwz r10,21640(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21640);
	// addi r4,r30,484
	ctx.r4.s64 = ctx.r30.s64 + 484;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,-4(r30)
	REX_STORE_U32(ctx.r30.u32 + -4, ctx.r11.u32);
	// lwz r11,21652(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21652);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x820caff0
	ctx.lr = 0x820CD20C;
	sub_820CAFF0(ctx, base);
	// lwz r11,21652(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21652);
	// lwz r10,21644(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21644);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// stw r10,5148(r29)
	REX_STORE_U32(ctx.r29.u32 + 5148, ctx.r10.u32);
	// bne cr6,0x820cd23c
	if (!ctx.cr6.eq) goto loc_820CD23C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x820cd240
	goto loc_820CD240;
loc_820CD23C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_820CD240:
	// lwz r10,16560(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16560);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,21652(r31)
	REX_STORE_U32(ctx.r31.u32 + 21652, ctx.r11.u32);
	// stw r10,21660(r31)
	REX_STORE_U32(ctx.r31.u32 + 21660, ctx.r10.u32);
	// b 0x820cd19c
	goto loc_820CD19C;
}
