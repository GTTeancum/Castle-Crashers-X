DEFINE_REX_FUNC(sub_820A4F88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f8
	ctx.lr = 0x820A4F90;
	__savegprlr_20(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// lbz r11,1185(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a4fc8
	if (!ctx.cr6.eq) goto loc_820A4FC8;
	// li r22,0
	ctx.r22.s64 = 0;
loc_820A4FB4:
	// stw r22,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r22.u32);
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// stw r22,4(r21)
	REX_STORE_U32(ctx.r21.u32 + 4, ctx.r22.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
loc_820A4FC8:
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A4FDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// li r22,0
	ctx.r22.s64 = 0;
	// bne cr6,0x820a4fb4
	if (!ctx.cr6.eq) goto loc_820A4FB4;
	// lis r23,-32218
	ctx.r23.s64 = -2111438848;
	// ld r7,0(r25)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r25.u32 + 0);
	// lwz r26,112(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// addi r11,r28,1200
	ctx.r11.s64 = ctx.r28.s64 + 1200;
	// mr r31,r22
	ctx.r31.u64 = ctx.r22.u64;
	// li r8,4
	ctx.r8.s64 = 4;
	// lwz r9,-6652(r23)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r23.u32 + -6652);
loc_820A5004:
	// ld r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// cmpld cr6,r7,r10
	ctx.cr6.compare<uint64_t>(ctx.r7.u64, ctx.r10.u64, ctx.xer);
	// bne cr6,0x820a5038
	if (!ctx.cr6.eq) goto loc_820A5038;
	// lbz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + 4);
	// addi r26,r11,-8
	ctx.r26.s64 = ctx.r11.s64 + -8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820a5028
	if (!ctx.cr6.eq) goto loc_820A5028;
	// mr r31,r22
	ctx.r31.u64 = ctx.r22.u64;
	// b 0x820a5038
	goto loc_820A5038;
loc_820A5028:
	// lbz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 12);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r6,r9
	ctx.r31.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
loc_820A5038:
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// bne 0x820a5004
	if (!ctx.cr0.eq) goto loc_820A5004;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820a520c
	if (ctx.cr6.eq) goto loc_820A520C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lbz r4,20(r26)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r26.u32 + 20);
	// addi r3,r11,5672
	ctx.r3.s64 = ctx.r11.s64 + 5672;
	// bl 0x8208c5d8
	ctx.lr = 0x820A505C;
	sub_8208C5D8(ctx, base);
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
	// lwz r3,12(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,52(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 52);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820A5074;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r27,1
	ctx.r27.s64 = 1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a5104
	if (ctx.cr6.eq) goto loc_820A5104;
loc_820A5080:
	// lwz r3,12(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A5098;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// lwz r9,0(r20)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820A50AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,0(r24)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r6,68(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820A50C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820a50e4
	if (ctx.cr6.eq) goto loc_820A50E4;
	// lbz r11,20(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 20);
	// lwz r10,24(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 24);
	// slw r9,r27,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r11.u8 & 0x3F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,24(r26)
	REX_STORE_U32(ctx.r26.u32 + 24, ctx.r8.u32);
loc_820A50E4:
	// lwz r3,12(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 12);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A50FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x820a5080
	if (ctx.cr6.lt) goto loc_820A5080;
loc_820A5104:
	// lwz r11,-6652(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + -6652);
	// lbz r10,32(r25)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r25.u32 + 32);
	// lbz r9,102(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 102);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// lbz r7,24(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 24);
	// extsb r11,r9
	ctx.r11.s64 = ctx.r9.s8;
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// subf r10,r8,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r8.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r5,r11,5
	ctx.r5.s64 = ctx.r11.s64 + 5;
	// extsb r11,r5
	ctx.r11.s64 = ctx.r5.s8;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bge cr6,0x820a4fb4
	if (!ctx.cr6.lt) goto loc_820A4FB4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x820a5160
	if (!ctx.cr6.lt) goto loc_820A5160;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,5712
	ctx.r3.s64 = ctx.r11.s64 + 5712;
	// bl 0x8208c5d8
	ctx.lr = 0x820A514C;
	sub_8208C5D8(ctx, base);
	// stw r27,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r27.u32);
	// stw r22,4(r21)
	REX_STORE_U32(ctx.r21.u32 + 4, ctx.r22.u32);
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
loc_820A5160:
	// lis r10,-32234
	ctx.r10.s64 = -2112487424;
	// lbz r6,-28146(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + -28146);
loc_820A5168:
	// add r10,r11,r25
	ctx.r10.u64 = ctx.r11.u64 + ctx.r25.u64;
	// lbz r9,102(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 102);
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// lbz r8,26(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 26);
	// lbz r7,20(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 20);
	// bge cr6,0x820a51e8
	if (!ctx.cr6.lt) goto loc_820A51E8;
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x820a51e8
	if (!ctx.cr6.lt) goto loc_820A51E8;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lbz r10,101(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 101);
	// rlwinm r5,r9,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r4,r10,18
	ctx.r4.s64 = ctx.r10.s64 + 18;
	// rlwinm r3,r4,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r5,r25
	ctx.r10.u64 = REX_LOAD_U16(ctx.r5.u32 + ctx.r25.u32);
	// sthx r10,r3,r31
	REX_STORE_U16(ctx.r3.u32 + ctx.r31.u32, ctx.r10.u16);
	// lbz r10,101(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 101);
	// add r9,r10,r31
	ctx.r9.u64 = ctx.r10.u64 + ctx.r31.u64;
	// stb r7,68(r9)
	REX_STORE_U8(ctx.r9.u32 + 68, ctx.r7.u8);
	// lbz r10,101(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 101);
	// add r7,r10,r31
	ctx.r7.u64 = ctx.r10.u64 + ctx.r31.u64;
	// stb r8,84(r7)
	REX_STORE_U8(ctx.r7.u32 + 84, ctx.r8.u8);
	// lbz r10,102(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 102);
	// lbz r9,101(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 101);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// clrlwi r3,r5,24
	ctx.r3.u64 = ctx.r5.u32 & 0xFF;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// stb r3,101(r31)
	REX_STORE_U8(ctx.r31.u32 + 101, ctx.r3.u8);
	// cmplwi cr6,r3,16
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 16, ctx.xer);
	// stb r4,102(r31)
	REX_STORE_U8(ctx.r31.u32 + 102, ctx.r4.u8);
	// blt cr6,0x820a51e8
	if (ctx.cr6.lt) goto loc_820A51E8;
	// stb r22,101(r31)
	REX_STORE_U8(ctx.r31.u32 + 101, ctx.r22.u8);
loc_820A51E8:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// blt cr6,0x820a5168
	if (ctx.cr6.lt) goto loc_820A5168;
	// stw r22,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r22.u32);
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// stw r22,4(r21)
	REX_STORE_U32(ctx.r21.u32 + 4, ctx.r22.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
loc_820A520C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,5768
	ctx.r3.s64 = ctx.r11.s64 + 5768;
	// bl 0x8208c5d8
	ctx.lr = 0x820A5218;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r22,4(r21)
	REX_STORE_U32(ctx.r21.u32 + 4, ctx.r22.u32);
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// stw r10,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
}
