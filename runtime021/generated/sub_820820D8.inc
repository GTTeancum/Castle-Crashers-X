DEFINE_REX_FUNC(sub_820820D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820820E0;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lis r12,7
	ctx.r12.s64 = 458752;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
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
	// beq cr6,0x82082160
	if (ctx.cr6.eq) goto loc_82082160;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lhz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82082160
	if (ctx.cr6.eq) goto loc_82082160;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82082154
	if (!ctx.cr6.eq) goto loc_82082154;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82082154;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82082154:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x82066ea8
	ctx.lr = 0x82082160;
	sub_82066EA8(ctx, base);
loc_82082160:
	// lwz r11,5024(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// li r26,0
	ctx.r26.s64 = 0;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r28,r10,r31
	ctx.r28.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmpw cr6,r9,r30
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r30.s32, ctx.xer);
	// beq cr6,0x820822c4
	if (ctx.cr6.eq) goto loc_820822C4;
	// stw r26,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r31,8(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r26,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// stb r26,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r26.u8);
	// bl 0x8207aa50
	ctx.lr = 0x820821A4;
	sub_8207AA50(ctx, base);
	// stw r26,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r26.u32);
	// stb r26,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r26.u8);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207aa50
	ctx.lr = 0x820821C0;
	sub_8207AA50(ctx, base);
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmpw cr6,r11,r30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r30.s32, ctx.xer);
	// beq cr6,0x820822c4
	if (ctx.cr6.eq) goto loc_820822C4;
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r10,r11,r12
	ctx.r10.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820821f0
	if (ctx.cr6.eq) goto loc_820821F0;
	// lwz r31,4(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// b 0x82082214
	goto loc_82082214;
loc_820821F0:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x82082210
	if (ctx.cr6.eq) goto loc_82082210;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// beq cr6,0x82082208
	if (ctx.cr6.eq) goto loc_82082208;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// bne cr6,0x82082210
	if (!ctx.cr6.eq) goto loc_82082210;
loc_82082208:
	// lwz r31,4(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// b 0x82082214
	goto loc_82082214;
loc_82082210:
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
loc_82082214:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82082228;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,128
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 128, ctx.xer);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bne cr6,0x82082268
	if (!ctx.cr6.eq) goto loc_82082268;
	// bl 0x82082bb0
	ctx.lr = 0x82082238;
	sub_82082BB0(ctx, base);
	// lhz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x820822c4
	if (!ctx.cr6.lt) goto loc_820822C4;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a358
	ctx.lr = 0x82082254;
	sub_8207A358(ctx, base);
	// stw r26,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r26.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r26,8(r28)
	REX_STORE_U8(ctx.r28.u32 + 8, ctx.r26.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_82082268:
	// bl 0x82082890
	ctx.lr = 0x8208226C;
	sub_82082890(ctx, base);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r10,r11,r12
	ctx.r10.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820822a0
	if (!ctx.cr6.eq) goto loc_820822A0;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820822c4
	if (ctx.cr6.eq) goto loc_820822C4;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// beq cr6,0x820822a0
	if (ctx.cr6.eq) goto loc_820822A0;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// bne cr6,0x820822c4
	if (!ctx.cr6.eq) goto loc_820822C4;
loc_820822A0:
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820822c4
	if (ctx.cr6.eq) goto loc_820822C4;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820822C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820822C4:
	// stw r26,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r26.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r26,8(r28)
	REX_STORE_U8(ctx.r28.u32 + 8, ctx.r26.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
