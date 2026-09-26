DEFINE_REX_FUNC(sub_820A47E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x820A47F0;
	__savegprlr_21(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// mr r23,r27
	ctx.r23.u64 = ctx.r27.u64;
	// lwz r11,1188(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 1188);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x820a49d8
	if (!ctx.cr6.gt) goto loc_820A49D8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r25,r26,1200
	ctx.r25.s64 = ctx.r26.s64 + 1200;
	// li r24,1
	ctx.r24.s64 = 1;
	// lis r21,-32218
	ctx.r21.s64 = -2111438848;
	// addi r22,r11,5244
	ctx.r22.s64 = ctx.r11.s64 + 5244;
loc_820A4820:
	// lbz r11,-7(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -7);
	// addi r29,r25,-8
	ctx.r29.s64 = ctx.r25.s64 + -8;
	// mr r28,r24
	ctx.r28.u64 = ctx.r24.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a49c4
	if (!ctx.cr6.eq) goto loc_820A49C4;
	// lwz r3,12(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A484C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a48fc
	if (ctx.cr6.eq) goto loc_820A48FC;
loc_820A4854:
	// lwz r3,12(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A486C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820A4880;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// ld r7,0(r25)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r25.u32 + 0);
	// cmpld cr6,r3,r7
	ctx.cr6.compare<uint64_t>(ctx.r3.u64, ctx.r7.u64, ctx.xer);
	// beq cr6,0x820a48f8
	if (ctx.cr6.eq) goto loc_820A48F8;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A48A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820a48d4
	if (!ctx.cr6.eq) goto loc_820A48D4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A48BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,20(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 20);
	// lwz r8,24(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// slw r7,r24,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r9.u8 & 0x3F));
	// and r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 & ctx.r8.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x820a48f8
	if (ctx.cr6.eq) goto loc_820A48F8;
loc_820A48D4:
	// lwz r3,12(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A48EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x820a4854
	if (ctx.cr6.lt) goto loc_820A4854;
	// b 0x820a48fc
	goto loc_820A48FC;
loc_820A48F8:
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
loc_820A48FC:
	// clrlwi r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a49c4
	if (ctx.cr6.eq) goto loc_820A49C4;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// lbz r4,20(r29)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r29.u32 + 20);
	// bl 0x8208c5d8
	ctx.lr = 0x820A4914;
	sub_8208C5D8(ctx, base);
	// lwz r8,-6652(r21)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r21.u32 + -6652);
	// lbz r11,4(r8)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a492c
	if (!ctx.cr6.eq) goto loc_820A492C;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// b 0x820a493c
	goto loc_820A493C;
loc_820A492C:
	// lbz r11,20(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 20);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r8
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
loc_820A493C:
	// lbz r10,102(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 102);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// bge cr6,0x820a4998
	if (!ctx.cr6.lt) goto loc_820A4998;
	// lbz r10,101(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 101);
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r27,r9,r11
	REX_STORE_U16(ctx.r9.u32 + ctx.r11.u32, ctx.r27.u16);
	// lbz r10,101(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 101);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stb r27,68(r7)
	REX_STORE_U8(ctx.r7.u32 + 68, ctx.r27.u8);
	// lbz r10,101(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 101);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stb r27,84(r6)
	REX_STORE_U8(ctx.r6.u32 + 84, ctx.r27.u8);
	// lbz r9,102(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 102);
	// lbz r10,101(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 101);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// clrlwi r3,r5,24
	ctx.r3.u64 = ctx.r5.u32 & 0xFF;
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// stb r3,101(r11)
	REX_STORE_U8(ctx.r11.u32 + 101, ctx.r3.u8);
	// cmplwi cr6,r3,16
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 16, ctx.xer);
	// stb r4,102(r11)
	REX_STORE_U8(ctx.r11.u32 + 102, ctx.r4.u8);
	// blt cr6,0x820a4998
	if (ctx.cr6.lt) goto loc_820A4998;
	// stb r27,101(r11)
	REX_STORE_U8(ctx.r11.u32 + 101, ctx.r27.u8);
loc_820A4998:
	// lbz r11,4(r8)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a49ac
	if (!ctx.cr6.eq) goto loc_820A49AC;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// b 0x820a49bc
	goto loc_820A49BC;
loc_820A49AC:
	// lbz r11,20(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 20);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r8
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
loc_820A49BC:
	// stb r27,35(r11)
	REX_STORE_U8(ctx.r11.u32 + 35, ctx.r27.u8);
	// stb r24,1(r29)
	REX_STORE_U8(ctx.r29.u32 + 1, ctx.r24.u8);
loc_820A49C4:
	// lwz r11,1188(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 1188);
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// addi r25,r25,40
	ctx.r25.s64 = ctx.r25.s64 + 40;
	// cmplw cr6,r23,r11
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820a4820
	if (ctx.cr6.lt) goto loc_820A4820;
loc_820A49D8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
