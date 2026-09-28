DEFINE_REX_FUNC(sub_8207D918) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8207D920;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,156(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// addi r31,r11,10372
	ctx.r31.s64 = ctx.r11.s64 + 10372;
	// lwz r11,15396(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 15396);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,5024(r31)
	REX_STORE_U32(ctx.r31.u32 + 5024, ctx.r11.u32);
	// lwzx r30,r9,r31
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// and r7,r8,r12
	ctx.r7.u64 = ctx.r8.u64 & ctx.r12.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x8207d99c
	if (ctx.cr6.eq) goto loc_8207D99C;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lhz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207d99c
	if (ctx.cr6.eq) goto loc_8207D99C;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8207d990
	if (!ctx.cr6.eq) goto loc_8207D990;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207D990;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207D990:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x82066ea8
	ctx.lr = 0x8207D99C;
	sub_82066EA8(ctx, base);
loc_8207D99C:
	// lwz r11,5024(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r29,r9,r31
	ctx.r29.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x8207da24
	if (ctx.cr6.eq) goto loc_8207DA24;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82082bb0
	ctx.lr = 0x8207D9C0;
	sub_82082BB0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8207d9dc
	if (!ctx.cr6.eq) goto loc_8207D9DC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-7360
	ctx.r3.s64 = ctx.r11.s64 + -7360;
	// bl 0x8208c5d8
	ctx.lr = 0x8207D9D8;
	sub_8208C5D8(ctx, base);
	// li r31,1
	ctx.r31.s64 = 1;
loc_8207D9DC:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// lwz r30,-6644(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -6644);
	// ble cr6,0x8207da24
	if (!ctx.cr6.gt) goto loc_8207DA24;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8207D9F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// and r8,r10,r3
	ctx.r8.u64 = ctx.r10.u64 & ctx.r3.u64;
	// twllei r31,0
	if (ctx.r31.s32 == 0 || ctx.r31.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r7,r8,r31
	ctx.r7.u64 = uint32_t(ctx.r31.u32 ? ctx.r8.u32 / ctx.r31.u32 : 0);
	// lwz r11,-22592(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -22592);
	// mullw r6,r7,r31
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r31.s32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// subf r10,r6,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r6.u64;
	// stw r11,-22592(r9)
	REX_STORE_U32(ctx.r9.u32 + -22592, ctx.r11.u32);
	// b 0x8207da28
	goto loc_8207DA28;
loc_8207DA24:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8207DA28:
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r10,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,156(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// addi r11,r11,10372
	ctx.r11.s64 = ctx.r11.s64 + 10372;
	// lwz r9,5024(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 5024);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r8,r11
	REX_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r29.u32);
	// lwz r10,5024(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 5024);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r7,5024(r11)
	REX_STORE_U32(ctx.r11.u32 + 5024, ctx.r7.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
