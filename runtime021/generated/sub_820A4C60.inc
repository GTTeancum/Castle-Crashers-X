DEFINE_REX_FUNC(sub_820A4C60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x820A4C68;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// lbz r11,1375(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 1375);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a4df0
	if (ctx.cr6.eq) goto loc_820A4DF0;
	// lbz r11,28(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a4df0
	if (ctx.cr6.eq) goto loc_820A4DF0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A4CA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820a4df0
	if (!ctx.cr6.eq) goto loc_820A4DF0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A4CC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r27,-32218
	ctx.r27.s64 = -2111438848;
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r11,-6652(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -6652);
	// lbz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x820a4ce4
	if (!ctx.cr6.eq) goto loc_820A4CE4;
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// b 0x820a4cf4
	goto loc_820A4CF4;
loc_820A4CE4:
	// lbz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 20);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r9,r11
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
loc_820A4CF4:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A4D08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,25(r29)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r29.u32 + 25);
	// stb r9,28(r3)
	REX_STORE_U8(ctx.r3.u32 + 28, ctx.r9.u8);
	// lwz r8,12(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x820a4d38
	if (ctx.cr6.eq) goto loc_820A4D38;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r26,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r26.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820A4D38:
	// lwz r11,-6652(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -6652);
	// lbz r10,24(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 24);
	// lbz r9,102(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 102);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// extsb r10,r9
	ctx.r10.s64 = ctx.r9.s8;
	// lbz r7,24(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 24);
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// subf r11,r8,r6
	ctx.r11.u64 = ctx.r6.u64 - ctx.r8.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r5,r11,5
	ctx.r5.s64 = ctx.r11.s64 + 5;
	// extsb r31,r5
	ctx.r31.s64 = ctx.r5.s8;
	// cmpwi cr6,r31,6
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 6, ctx.xer);
	// bge cr6,0x820a4df4
	if (!ctx.cr6.lt) goto loc_820A4DF4;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge cr6,0x820a4dac
	if (!ctx.cr6.lt) goto loc_820A4DAC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,5420
	ctx.r3.s64 = ctx.r11.s64 + 5420;
	// bl 0x8208c5d8
	ctx.lr = 0x820A4D80;
	sub_8208C5D8(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820a37b8
	ctx.lr = 0x820A4D8C;
	sub_820A37B8(ctx, base);
	// li r10,11
	ctx.r10.s64 = 11;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r26,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r26.u32);
	// stw r10,140(r25)
	REX_STORE_U32(ctx.r25.u32 + 140, ctx.r10.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r9,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820A4DAC:
	// add r11,r31,r29
	ctx.r11.u64 = ctx.r31.u64 + ctx.r29.u64;
	// rlwinm r10,r31,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lbz r6,18(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// lbz r5,12(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 12);
	// lhzx r4,r10,r29
	ctx.r4.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r29.u32);
	// bl 0x8209b9d0
	ctx.lr = 0x820A4DCC;
	sub_8209B9D0(ctx, base);
	// addi r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 1;
	// extsb r31,r9
	ctx.r31.s64 = ctx.r9.s8;
	// cmpwi cr6,r31,6
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 6, ctx.xer);
	// blt cr6,0x820a4dac
	if (ctx.cr6.lt) goto loc_820A4DAC;
	// stw r26,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r26.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r26,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r26.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820A4DF0:
	// li r26,0
	ctx.r26.s64 = 0;
loc_820A4DF4:
	// stw r26,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r26.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r26,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r26.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
