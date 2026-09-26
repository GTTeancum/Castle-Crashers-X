DEFINE_REX_FUNC(sub_82111D58) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82111D60;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lis r9,32767
	ctx.r9.s64 = 2147418112;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ori r9,r9,65534
	ctx.r9.u64 = ctx.r9.u64 | 65534;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r10,12(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82111e60
	if (!ctx.cr6.eq) goto loc_82111E60;
	// lwz r11,40(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 40);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x82111e58
	if (ctx.cr6.eq) goto loc_82111E58;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// beq cr6,0x82111e34
	if (ctx.cr6.eq) goto loc_82111E34;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x82111e10
	if (ctx.cr6.eq) goto loc_82111E10;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// ble cr6,0x82111e58
	if (!ctx.cr6.gt) goto loc_82111E58;
	// cmpwi cr6,r11,14
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 14, ctx.xer);
	// beq cr6,0x82111df0
	if (ctx.cr6.eq) goto loc_82111DF0;
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x82111f70
	if (ctx.cr6.lt) goto loc_82111F70;
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// rlwinm. r9,r11,0,1,1
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82111f70
	if (ctx.cr0.eq) goto loc_82111F70;
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82111f70
	if (ctx.cr0.eq) goto loc_82111F70;
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r10,60(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82111f70
	if (!ctx.cr6.eq) goto loc_82111F70;
	// bl 0x8210f488
	ctx.lr = 0x82111DEC;
	sub_8210F488(ctx, base);
	// b 0x82111e04
	goto loc_82111E04;
loc_82111DF0:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,48(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821138a0
	ctx.lr = 0x82111E04;
	sub_821138A0(ctx, base);
loc_82111E04:
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x82111f88
	if (!ctx.cr0.eq) goto loc_82111F88;
	// b 0x82111f70
	goto loc_82111F70;
loc_82111E10:
	// lwz r28,48(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// lwz r6,32(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82116d78
	ctx.lr = 0x82111E28;
	sub_82116D78(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x82111f74
	if (!ctx.cr0.eq) goto loc_82111F74;
	// b 0x82111f70
	goto loc_82111F70;
loc_82111E34:
	// lwz r28,48(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// lwz r6,32(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82116ba8
	ctx.lr = 0x82111E4C;
	sub_82116BA8(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x82111f70
	if (ctx.cr0.eq) goto loc_82111F70;
	// b 0x82111f74
	goto loc_82111F74;
loc_82111E58:
	// lwz r28,48(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// b 0x82111f70
	goto loc_82111F70;
loc_82111E60:
	// lwz r8,56(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// clrlwi r7,r11,8
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFFFF;
	// lwz r9,24(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// clrlwi. r8,r8,31
	ctx.r8.u64 = ctx.r8.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x82111ebc
	if (ctx.cr0.eq) goto loc_82111EBC;
	// lis r8,255
	ctx.r8.s64 = 16711680;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ori r8,r8,65534
	ctx.r8.u64 = ctx.r8.u64 | 65534;
	// subf r8,r7,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r7.u64;
	// bne cr6,0x82111e8c
	if (!ctx.cr6.eq) goto loc_82111E8C;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
loc_82111E8C:
	// subfic r7,r9,127
	ctx.xer.ca = ctx.r9.u32 <= 127;
	ctx.r7.u64 = static_cast<uint64_t>(127) - ctx.r9.u64;
	// subfic r6,r9,-1
	ctx.xer.ca = ctx.r9.u32 <= 4294967295;
	ctx.r6.u64 = static_cast<uint64_t>(-1) - ctx.r9.u64;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// rlwinm r7,r7,18,0,13
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 18) & 0xFFFC0000;
	// rlwinm r6,r6,25,0,6
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 25) & 0xFE000000;
	// ori r5,r5,65534
	ctx.r5.u64 = ctx.r5.u64 | 65534;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// subf r8,r8,r5
	ctx.r8.u64 = ctx.r5.u64 - ctx.r8.u64;
	// rlwinm r11,r11,18,14,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 18) & 0x20000;
	// or r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 | ctx.r8.u64;
	// or r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 | ctx.r11.u64;
	// b 0x82111edc
	goto loc_82111EDC;
loc_82111EBC:
	// lwz r8,172(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// rlwinm r11,r11,19,14,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 19) & 0x3F800;
	// lwz r6,60(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// or r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 | ctx.r7.u64;
	// rlwinm r8,r8,25,0,6
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0xFE000000;
	// rlwinm r7,r6,18,6,13
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 18) & 0x3FC0000;
	// or r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 | ctx.r11.u64;
	// or r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 | ctx.r11.u64;
loc_82111EDC:
	// lwz r8,136(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r7,68
	ctx.r7.s64 = 68;
	// lwz r6,132(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// li r5,6
	ctx.r5.s64 = 6;
	// stw r7,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r7.u32);
	// addi r3,r31,784
	ctx.r3.s64 = ctx.r31.s64 + 784;
	// stw r5,744(r31)
	REX_STORE_U32(ctx.r31.u32 + 744, ctx.r5.u32);
	// addi r4,r30,36
	ctx.r4.s64 = ctx.r30.s64 + 36;
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r8,748(r31)
	REX_STORE_U32(ctx.r31.u32 + 748, ctx.r8.u32);
	// addi r29,r31,740
	ctx.r29.s64 = ctx.r31.s64 + 740;
	// stw r6,752(r31)
	REX_STORE_U32(ctx.r31.u32 + 752, ctx.r6.u32);
	// lwz r8,60(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// stw r8,756(r31)
	REX_STORE_U32(ctx.r31.u32 + 756, ctx.r8.u32);
	// lwz r10,72(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 72);
	// stw r11,764(r31)
	REX_STORE_U32(ctx.r31.u32 + 764, ctx.r11.u32);
	// stw r10,760(r31)
	REX_STORE_U32(ctx.r31.u32 + 760, ctx.r10.u32);
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// stw r11,768(r31)
	REX_STORE_U32(ctx.r31.u32 + 768, ctx.r11.u32);
	// stw r9,772(r31)
	REX_STORE_U32(ctx.r31.u32 + 772, ctx.r9.u32);
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// stw r11,776(r31)
	REX_STORE_U32(ctx.r31.u32 + 776, ctx.r11.u32);
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// stw r11,780(r31)
	REX_STORE_U32(ctx.r31.u32 + 780, ctx.r11.u32);
	// bl 0x82129a70
	ctx.lr = 0x82111F40;
	sub_82129A70(ctx, base);
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// stw r11,796(r31)
	REX_STORE_U32(ctx.r31.u32 + 796, ctx.r11.u32);
	// lwz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// stw r11,800(r31)
	REX_STORE_U32(ctx.r31.u32 + 800, ctx.r11.u32);
	// lwz r11,56(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// stw r11,804(r31)
	REX_STORE_U32(ctx.r31.u32 + 804, ctx.r11.u32);
	// stw r29,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r29.u32);
	// lwz r11,820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r30,808(r31)
	REX_STORE_U32(ctx.r31.u32 + 808, ctx.r30.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r11,820(r31)
	REX_STORE_U32(ctx.r31.u32 + 820, ctx.r11.u32);
loc_82111F70:
	// li r29,0
	ctx.r29.s64 = 0;
loc_82111F74:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82111f88
	if (ctx.cr6.eq) goto loc_82111F88;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x82115c28
	ctx.lr = 0x82111F88;
	sub_82115C28(ctx, base);
loc_82111F88:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82111fa0
	if (ctx.cr6.eq) goto loc_82111FA0;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82111fa0
	if (ctx.cr6.eq) goto loc_82111FA0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821151c8
	ctx.lr = 0x82111FA0;
	sub_821151C8(ctx, base);
loc_82111FA0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
