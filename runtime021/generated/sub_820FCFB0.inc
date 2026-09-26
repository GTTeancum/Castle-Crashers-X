DEFINE_REX_FUNC(sub_820FCFB0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820FCFB8;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820fd068
	if (ctx.cr6.eq) goto loc_820FD068;
	// cmplwi cr6,r31,1020
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1020, ctx.xer);
	// ble cr6,0x820fcfe4
	if (!ctx.cr6.gt) goto loc_820FCFE4;
loc_820FCFD8:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,4336
	ctx.r30.u64 = ctx.r30.u64 | 4336;
	// b 0x820fd0e8
	goto loc_820FD0E8;
loc_820FCFE4:
	// li r11,13
	ctx.r11.s64 = 13;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x820d7fb8
	ctx.lr = 0x820FCFFC;
	sub_820D7FB8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820fd020
	if (ctx.cr0.eq) goto loc_820FD020;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bgt cr6,0x820fd014
	if (ctx.cr6.gt) goto loc_820FD014;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x820fd0e8
	goto loc_820FD0E8;
loc_820FD014:
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r30,r11,32775
	ctx.r30.u64 = ctx.r11.u64 | 2147942400;
	// b 0x820fd0e8
	goto loc_820FD0E8;
loc_820FD020:
	// lbz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// rotlwi r11,r11,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820fcfd8
	if (ctx.cr6.gt) goto loc_820FCFD8;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82108f48
	ctx.lr = 0x820FD040;
	sub_82108F48(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x820fd054
	if (!ctx.cr0.eq) goto loc_820FD054;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x820fd0b0
	goto loc_820FD0B0;
loc_820FD054:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82129a70
	ctx.lr = 0x820FD064;
	sub_82129A70(ctx, base);
	// b 0x820fd06c
	goto loc_820FD06C;
loc_820FD068:
	// li r29,0
	ctx.r29.s64 = 0;
loc_820FD06C:
	// lwz r11,720(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 720);
	// rlwinm. r11,r11,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820fd0c8
	if (ctx.cr0.eq) goto loc_820FD0C8;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r28,48
	ctx.r3.s64 = ctx.r28.s64 + 48;
	// bl 0x820d7f18
	ctx.lr = 0x820FD090;
	sub_820D7F18(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820fd0c8
	if (ctx.cr0.eq) goto loc_820FD0C8;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bgt cr6,0x820fd0a8
	if (ctx.cr6.gt) goto loc_820FD0A8;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x820fd0b0
	goto loc_820FD0B0;
loc_820FD0A8:
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r30,r11,32775
	ctx.r30.u64 = ctx.r11.u64 | 2147942400;
loc_820FD0B0:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820fd0e8
	if (ctx.cr6.eq) goto loc_820FD0E8;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82108f60
	ctx.lr = 0x820FD0C4;
	sub_82108F60(ctx, base);
	// b 0x820fd0e8
	goto loc_820FD0E8;
loc_820FD0C8:
	// lwz r4,516(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 516);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820fd0dc
	if (ctx.cr6.eq) goto loc_820FD0DC;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82108f60
	ctx.lr = 0x820FD0DC;
	sub_82108F60(ctx, base);
loc_820FD0DC:
	// stw r29,516(r28)
	REX_STORE_U32(ctx.r28.u32 + 516, ctx.r29.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r31,520(r28)
	REX_STORE_U32(ctx.r28.u32 + 520, ctx.r31.u32);
loc_820FD0E8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
