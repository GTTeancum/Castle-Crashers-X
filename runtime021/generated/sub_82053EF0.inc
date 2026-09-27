DEFINE_REX_FUNC(sub_82053EF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82053EF8;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r5,24
	ctx.r11.u64 = ctx.r5.u32 & 0xFF;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82053fa8
	if (ctx.cr6.eq) goto loc_82053FA8;
	// lis r31,-32215
	ctx.r31.s64 = -2111242240;
	// lbz r11,2704(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 2704);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82053f30
	if (ctx.cr6.eq) goto loc_82053F30;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82053f68
	goto loc_82053F68;
loc_82053F30:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820b6818
	ctx.lr = 0x82053F3C;
	sub_820B6818(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82053f64
	if (!ctx.cr6.eq) goto loc_82053F64;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82053f64
	if (ctx.cr6.eq) goto loc_82053F64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r10,2704(r31)
	REX_STORE_U8(ctx.r31.u32 + 2704, ctx.r10.u8);
	// b 0x82053f68
	goto loc_82053F68;
loc_82053F64:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82053F68:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82053fa8
	if (!ctx.cr6.eq) goto loc_82053FA8;
	// lwz r11,56(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,15
	ctx.r9.s64 = 15;
	// addi r8,r10,20784
	ctx.r8.s64 = ctx.r10.s64 + 20784;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r30,1228(r11)
	REX_STORE_U32(ctx.r11.u32 + 1228, ctx.r30.u32);
	// stw r8,1236(r11)
	REX_STORE_U32(ctx.r11.u32 + 1236, ctx.r8.u32);
	// sth r9,1262(r11)
	REX_STORE_U16(ctx.r11.u32 + 1262, ctx.r9.u16);
	// bl 0x82053bc8
	ctx.lr = 0x82053F9C;
	sub_82053BC8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82053FA8:
	// lis r31,-32218
	ctx.r31.s64 = -2111438848;
	// lwz r11,-6628(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
	// lbz r10,9(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 9);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82054164
	if (!ctx.cr6.eq) goto loc_82054164;
	// lwz r10,116(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// clrlwi r7,r10,31
	ctx.r7.u64 = ctx.r10.u32 & 0x1;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82053fdc
	if (ctx.cr6.eq) goto loc_82053FDC;
	// li r9,1
	ctx.r9.s64 = 1;
loc_82053FDC:
	// lwz r7,104(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// clrlwi r5,r7,31
	ctx.r5.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82053ff0
	if (ctx.cr6.eq) goto loc_82053FF0;
	// li r8,1
	ctx.r8.s64 = 1;
loc_82053FF0:
	// lwz r11,108(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// clrlwi r5,r11,31
	ctx.r5.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82054004
	if (ctx.cr6.eq) goto loc_82054004;
	// li r6,1
	ctx.r6.s64 = 1;
loc_82054004:
	// rlwinm r5,r10,0,30,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82054014
	if (ctx.cr6.eq) goto loc_82054014;
	// li r9,1
	ctx.r9.s64 = 1;
loc_82054014:
	// rlwinm r5,r7,0,30,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82054024
	if (ctx.cr6.eq) goto loc_82054024;
	// li r8,1
	ctx.r8.s64 = 1;
loc_82054024:
	// rlwinm r5,r11,0,30,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82054034
	if (ctx.cr6.eq) goto loc_82054034;
	// li r6,1
	ctx.r6.s64 = 1;
loc_82054034:
	// rlwinm r5,r10,0,29,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82054044
	if (ctx.cr6.eq) goto loc_82054044;
	// li r9,1
	ctx.r9.s64 = 1;
loc_82054044:
	// rlwinm r5,r7,0,29,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82054054
	if (ctx.cr6.eq) goto loc_82054054;
	// li r8,1
	ctx.r8.s64 = 1;
loc_82054054:
	// rlwinm r5,r11,0,29,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82054064
	if (ctx.cr6.eq) goto loc_82054064;
	// li r6,1
	ctx.r6.s64 = 1;
loc_82054064:
	// rlwinm r10,r10,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82054074
	if (ctx.cr6.eq) goto loc_82054074;
	// li r9,1
	ctx.r9.s64 = 1;
loc_82054074:
	// rlwinm r10,r7,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82054084
	if (ctx.cr6.eq) goto loc_82054084;
	// li r8,1
	ctx.r8.s64 = 1;
loc_82054084:
	// rlwinm r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82054094
	if (ctx.cr6.eq) goto loc_82054094;
	// li r6,1
	ctx.r6.s64 = 1;
loc_82054094:
	// clrlwi r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820540d4
	if (ctx.cr6.eq) goto loc_820540D4;
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820540d4
	if (ctx.cr6.eq) goto loc_820540D4;
	// li r5,15
	ctx.r5.s64 = 15;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82054d38
	ctx.lr = 0x820540BC;
	sub_82054D38(ctx, base);
	// lwz r11,-6628(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_820540D4:
	// clrlwi r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82054108
	if (ctx.cr6.eq) goto loc_82054108;
	// clrlwi r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82054108
	if (!ctx.cr6.eq) goto loc_82054108;
	// li r5,15
	ctx.r5.s64 = 15;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82054d38
	ctx.lr = 0x820540FC;
	sub_82054D38(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82054108:
	// clrlwi r11,r27,24
	ctx.r11.u64 = ctx.r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82054164
	if (ctx.cr6.eq) goto loc_82054164;
	// clrlwi r11,r6,24
	ctx.r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82054164
	if (!ctx.cr6.eq) goto loc_82054164;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82054134;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x82054148
	if (ctx.cr6.eq) goto loc_82054148;
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// li r10,-2
	ctx.r10.s64 = -2;
	// sth r10,10(r11)
	REX_STORE_U16(ctx.r11.u32 + 10, ctx.r10.u16);
loc_82054148:
	// li r5,15
	ctx.r5.s64 = 15;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82054d38
	ctx.lr = 0x82054158;
	sub_82054D38(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82054164:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
