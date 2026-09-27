DEFINE_REX_FUNC(sub_8207A5D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8207A5E0;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r5,16
	ctx.r11.u64 = ctx.r5.u32 & 0xFFFF;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x8207a6e0
	if (ctx.cr6.eq) goto loc_8207A6E0;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x8207a698
	if (ctx.cr6.eq) goto loc_8207A698;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x8207a734
	if (!ctx.cr6.eq) goto loc_8207A734;
	// cmpwi cr6,r6,2
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2, ctx.xer);
	// bne cr6,0x8207a650
	if (!ctx.cr6.eq) goto loc_8207A650;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207a650
	if (ctx.cr6.eq) goto loc_8207A650;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x8207a650
	if (ctx.cr6.eq) goto loc_8207A650;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x8207A63C;
	sub_82082BB0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82082bb0
	ctx.lr = 0x8207A648;
	sub_82082BB0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8207a660
	goto loc_8207A660;
loc_8207A650:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r31,-1
	ctx.r31.s64 = -1;
	// bl 0x82082bb0
	ctx.lr = 0x8207A65C;
	sub_82082BB0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_8207A660:
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8207a4c0
	ctx.lr = 0x8207A678;
	sub_8207A4C0(ctx, base);
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// lwz r3,10316(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 10316);
	// bl 0x8209d948
	ctx.lr = 0x8207A684;
	sub_8209D948(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// sth r3,4(r27)
	REX_STORE_U16(ctx.r27.u32 + 4, ctx.r3.u16);
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8207A698:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x8207A6A0;
	sub_82082BB0(ctx, base);
	// lhz r11,28(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 28);
	// lwz r10,10316(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 10316);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207a6b8
	if (!ctx.cr6.eq) goto loc_8207A6B8;
	// addi r11,r10,12
	ctx.r11.s64 = ctx.r10.s64 + 12;
	// b 0x8207a6c4
	goto loc_8207A6C4;
loc_8207A6B8:
	// lwz r10,28(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_8207A6C4:
	// lbzx r11,r11,r3
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r3.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// stw r9,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8207A6E0:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x8207A6E8;
	sub_82082BB0(ctx, base);
	// lhz r10,28(r28)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r28.u32 + 28);
	// lwz r11,10316(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 10316);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8207a700
	if (!ctx.cr6.eq) goto loc_8207A700;
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// b 0x8207a70c
	goto loc_8207A70C;
loc_8207A700:
	// lwz r9,28(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r9
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
loc_8207A70C:
	// lbzx r10,r10,r3
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r3.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r9,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r9.u8);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// stb r10,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// bl 0x8209d948
	ctx.lr = 0x8207A728;
	sub_8209D948(ctx, base);
	// li r8,8
	ctx.r8.s64 = 8;
	// sth r3,4(r27)
	REX_STORE_U16(ctx.r27.u32 + 4, ctx.r3.u16);
	// stw r8,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r8.u32);
loc_8207A734:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
