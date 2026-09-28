DEFINE_REX_FUNC(sub_8211E990) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8211E998;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// lbz r11,13(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 13);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x8211e9f0
	if (ctx.cr6.eq) goto loc_8211E9F0;
	// lbz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211e9e0
	if (ctx.cr0.eq) goto loc_8211E9E0;
	// lwz r11,636(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 636);
	// cmplwi cr6,r11,512
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 512, ctx.xer);
	// bge cr6,0x8211ea28
	if (!ctx.cr6.lt) goto loc_8211EA28;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r3,r31,624
	ctx.r3.s64 = ctx.r31.s64 + 624;
	// stw r11,636(r31)
	REX_STORE_U32(ctx.r31.u32 + 636, ctx.r11.u32);
	// b 0x8211ea38
	goto loc_8211EA38;
loc_8211E9E0:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821210b0
	ctx.lr = 0x8211E9EC;
	sub_821210B0(ctx, base);
	// b 0x8211ea44
	goto loc_8211EA44;
loc_8211E9F0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lhz r5,8(r30)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82125de8
	ctx.lr = 0x8211EA00;
	sub_82125DE8(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,652(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 652);
	// lwz r10,1(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 1);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8211ea4c
	if (ctx.cr6.eq) goto loc_8211EA4C;
	// lhz r9,1040(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 1040);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// rotlwi r10,r9,5
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 5);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8211ea34
	if (ctx.cr6.lt) goto loc_8211EA34;
loc_8211EA28:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4109
	ctx.r3.u64 = ctx.r3.u64 | 4109;
	// b 0x8211ea74
	goto loc_8211EA74;
loc_8211EA34:
	// addi r3,r31,640
	ctx.r3.s64 = ctx.r31.s64 + 640;
loc_8211EA38:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82125690
	ctx.lr = 0x8211EA44;
	sub_82125690(ctx, base);
loc_8211EA44:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8211ea74
	goto loc_8211EA74;
loc_8211EA4C:
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r4,4(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211b2a0
	ctx.lr = 0x8211EA64;
	sub_8211B2A0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8211ea74
	if (ctx.cr0.lt) goto loc_8211EA74;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211cc70
	ctx.lr = 0x8211EA74;
	sub_8211CC70(ctx, base);
loc_8211EA74:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
