DEFINE_REX_FUNC(sub_82124CE0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82124CE8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82124d14
	if (ctx.cr0.eq) goto loc_82124D14;
loc_82124D04:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x821210b0
	ctx.lr = 0x82124D10;
	sub_821210B0(ctx, base);
	// b 0x82124d68
	goto loc_82124D68;
loc_82124D14:
	// lbz r11,13(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 13);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x82124e44
	if (ctx.cr6.eq) goto loc_82124E44;
	// subf r11,r4,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r4.u64;
	// ld r10,816(r4)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r4.u32 + 816);
	// li r9,24
	ctx.r9.s64 = 24;
	// addi r8,r11,-48
	ctx.r8.s64 = ctx.r11.s64 + -48;
	// lbz r11,12(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 12);
	// divw r9,r8,r9
	ctx.r9.u64 = uint32_t((ctx.r9.s32 && !(ctx.r8.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r8.s32 / ctx.r9.s32 : 0);
	// rlwinm. r8,r11,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// bne 0x82124d74
	if (!ctx.cr0.eq) goto loc_82124D74;
	// addi r3,r31,60
	ctx.r3.s64 = ctx.r31.s64 + 60;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x82125690
	ctx.lr = 0x82124D54;
	sub_82125690(ctx, base);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82124d68
	if (!ctx.cr6.eq) goto loc_82124D68;
loc_82124D60:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82124880
	ctx.lr = 0x82124D68;
	sub_82124880(ctx, base);
loc_82124D68:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82124D6C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82124D74:
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82124d94
	if (!ctx.cr0.eq) goto loc_82124D94;
	// ld r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 72);
	// li r9,1
	ctx.r9.s64 = 1;
	// rldicr r9,r9,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmpld cr6,r11,r9
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r9.u64, ctx.xer);
	// bge cr6,0x82124d04
	if (!ctx.cr6.lt) goto loc_82124D04;
loc_82124D94:
	// addi r30,r31,48
	ctx.r30.s64 = ctx.r31.s64 + 48;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82125690
	ctx.lr = 0x82124DA4;
	sub_82125690(ctx, base);
	// lbz r11,13(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 13);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82124dc0
	if (!ctx.cr6.eq) goto loc_82124DC0;
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// oris r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 536870912;
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// b 0x82124dd4
	goto loc_82124DD4;
loc_82124DC0:
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x82124dd4
	if (!ctx.cr6.eq) goto loc_82124DD4;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
loc_82124DD4:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82124d68
	if (!ctx.cr6.eq) goto loc_82124D68;
	// lbz r11,12(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 12);
	// lhz r7,80(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 80);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82124e00
	if (ctx.cr0.eq) goto loc_82124E00;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x82124e04
	goto loc_82124E04;
loc_82124E00:
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
loc_82124E04:
	// lhz r10,10(r28)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r28.u32 + 10);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82124d68
	if (!ctx.cr6.eq) goto loc_82124D68;
	// lwz r6,100(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x82124e2c
	if (!ctx.cr6.eq) goto loc_82124E2C;
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82124d60
	if (!ctx.cr6.gt) goto loc_82124D60;
loc_82124E2C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r5,96(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821242c8
	ctx.lr = 0x82124E3C;
	sub_821242C8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82124d60
	if (!ctx.cr0.eq) goto loc_82124D60;
loc_82124E44:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4109
	ctx.r3.u64 = ctx.r3.u64 | 4109;
	// b 0x82124d6c
	goto loc_82124D6C;
}
