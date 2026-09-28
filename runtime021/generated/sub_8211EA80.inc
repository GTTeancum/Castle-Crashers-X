DEFINE_REX_FUNC(sub_8211EA80) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x8211EA88;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r11,-1
	ctx.r11.s64 = -1;
	// addi r29,r31,1000
	ctx.r29.s64 = ctx.r31.s64 + 1000;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r10,1000(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1000);
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplw cr6,r10,r29
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8211eb08
	if (ctx.cr6.eq) goto loc_8211EB08;
	// extsh r30,r23
	ctx.r30.s64 = ctx.r23.s16;
loc_8211EAC0:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8211ead0
	if (!ctx.cr6.eq) goto loc_8211EAD0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8211EAD0:
	// lhz r10,324(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 324);
	// addi r4,r11,-8
	ctx.r4.s64 = ctx.r11.s64 + -8;
	// subf r11,r30,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r30.u64;
	// extsh. r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x8211eb08
	if (!ctx.cr0.lt) goto loc_8211EB08;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211b488
	ctx.lr = 0x8211EAF8;
	sub_8211B488(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r26,1
	ctx.r26.s64 = 1;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8211eac0
	if (!ctx.cr6.eq) goto loc_8211EAC0;
loc_8211EB08:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8211ece0
	if (ctx.cr6.eq) goto loc_8211ECE0;
	// lhz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r27.u32 + 0);
	// lhz r10,1048(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 1048);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r10,32768
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32768, ctx.xer);
	// bge cr6,0x8211eb3c
	if (!ctx.cr6.lt) goto loc_8211EB3C;
	// sth r11,1048(r31)
	REX_STORE_U16(ctx.r31.u32 + 1048, ctx.r11.u16);
	// li r24,1
	ctx.r24.s64 = 1;
	// b 0x8211eb40
	goto loc_8211EB40;
loc_8211EB3C:
	// li r24,0
	ctx.r24.s64 = 0;
loc_8211EB40:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8211ebf0
	if (!ctx.cr6.eq) goto loc_8211EBF0;
	// li r28,0
	ctx.r28.s64 = 0;
loc_8211EB50:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x8211eb84
	if (ctx.cr6.eq) goto loc_8211EB84;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// addi r3,r31,942
	ctx.r3.s64 = ctx.r31.s64 + 942;
	// bl 0x82123ee8
	ctx.lr = 0x8211EB64;
	sub_82123EE8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8211eb84
	if (ctx.cr0.eq) goto loc_8211EB84;
	// lwz r11,1164(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1164);
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,1164(r31)
	REX_STORE_U32(ctx.r31.u32 + 1164, ctx.r11.u32);
	// bl 0x82125390
	ctx.lr = 0x8211EB80;
	sub_82125390(ctx, base);
loc_8211EB80:
	// li r26,1
	ctx.r26.s64 = 1;
loc_8211EB84:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// addi r30,r28,-8
	ctx.r30.s64 = ctx.r28.s64 + -8;
	// bne cr6,0x8211eb94
	if (!ctx.cr6.eq) goto loc_8211EB94;
	// li r30,0
	ctx.r30.s64 = 0;
loc_8211EB94:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8211ec74
	if (ctx.cr6.eq) goto loc_8211EC74;
	// lhz r11,332(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 332);
	// lhz r10,2(r27)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r27.u32 + 2);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8211ec74
	if (!ctx.cr6.eq) goto loc_8211EC74;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8211ebc0
	if (ctx.cr6.eq) goto loc_8211EBC0;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
loc_8211EBC0:
	// lwz r11,4(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lbz r10,8(r27)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r27.u32 + 8);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// and. r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211ec40
	if (ctx.cr0.eq) goto loc_8211EC40;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211b488
	ctx.lr = 0x8211EBEC;
	sub_8211B488(ctx, base);
	// b 0x8211ec5c
	goto loc_8211EC5C;
loc_8211EBF0:
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8211eb50
	if (ctx.cr0.eq) goto loc_8211EB50;
	// lhz r11,324(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 324);
	// clrlwi r10,r23,16
	ctx.r10.u64 = ctx.r23.u32 & 0xFFFF;
	// addi r4,r28,-8
	ctx.r4.s64 = ctx.r28.s64 + -8;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8211eb50
	if (!ctx.cr6.eq) goto loc_8211EB50;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8211ec24
	if (ctx.cr6.eq) goto loc_8211EC24;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
loc_8211EC24:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x8211eb84
	if (ctx.cr6.eq) goto loc_8211EB84;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// lhz r6,0(r27)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r27.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211ce50
	ctx.lr = 0x8211EC3C;
	sub_8211CE50(ctx, base);
	// b 0x8211eb80
	goto loc_8211EB80;
loc_8211EC40:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x8211ec60
	if (ctx.cr6.eq) goto loc_8211EC60;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// lhz r6,0(r27)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r27.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211ce50
	ctx.lr = 0x8211EC5C;
	sub_8211CE50(ctx, base);
loc_8211EC5C:
	// li r26,1
	ctx.r26.s64 = 1;
loc_8211EC60:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8211eccc
	if (ctx.cr6.eq) goto loc_8211ECCC;
	// addi r30,r28,-8
	ctx.r30.s64 = ctx.r28.s64 + -8;
	// b 0x8211eccc
	goto loc_8211ECCC;
loc_8211EC74:
	// lwz r11,4(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lbz r10,8(r27)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r27.u32 + 8);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// and. r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211ec98
	if (ctx.cr0.eq) goto loc_8211EC98;
	// addi r3,r31,942
	ctx.r3.s64 = ctx.r31.s64 + 942;
	// lhz r4,2(r27)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r27.u32 + 2);
	// bl 0x82123fa0
	ctx.lr = 0x8211EC94;
	sub_82123FA0(ctx, base);
	// b 0x8211eccc
	goto loc_8211ECCC;
loc_8211EC98:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x8211eccc
	if (ctx.cr6.eq) goto loc_8211ECCC;
	// addi r3,r31,942
	ctx.r3.s64 = ctx.r31.s64 + 942;
	// lhz r4,2(r27)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r27.u32 + 2);
	// bl 0x82123ee8
	ctx.lr = 0x8211ECAC;
	sub_82123EE8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8211eccc
	if (ctx.cr0.eq) goto loc_8211ECCC;
	// lwz r11,1164(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1164);
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,1164(r31)
	REX_STORE_U32(ctx.r31.u32 + 1164, ctx.r11.u32);
	// bl 0x82125390
	ctx.lr = 0x8211ECC8;
	sub_82125390(ctx, base);
	// li r26,1
	ctx.r26.s64 = 1;
loc_8211ECCC:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82119ec8
	ctx.lr = 0x8211ECD4;
	sub_82119EC8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8211eb94
	if (!ctx.cr0.eq) goto loc_8211EB94;
	// b 0x8211ecfc
	goto loc_8211ECFC;
loc_8211ECE0:
	// lhz r11,1048(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1048);
	// clrlwi r10,r23,16
	ctx.r10.u64 = ctx.r23.u32 & 0xFFFF;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// bge cr6,0x8211ecfc
	if (!ctx.cr6.lt) goto loc_8211ECFC;
	// sth r23,1048(r31)
	REX_STORE_U16(ctx.r31.u32 + 1048, ctx.r23.u16);
loc_8211ECFC:
	// lbz r11,1144(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1144);
	// rlwinm. r11,r11,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8211ed14
	if (!ctx.cr0.eq) goto loc_8211ED14;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211aed8
	ctx.lr = 0x8211ED14;
	sub_8211AED8(ctx, base);
loc_8211ED14:
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x8211ed44
	if (ctx.cr6.eq) goto loc_8211ED44;
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r11,48(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// rlwinm r7,r11,29,3,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// bl 0x82125130
	ctx.lr = 0x8211ED40;
	sub_82125130(ctx, base);
	// stw r25,468(r31)
	REX_STORE_U32(ctx.r31.u32 + 468, ctx.r25.u32);
loc_8211ED44:
	// sth r23,1046(r31)
	REX_STORE_U16(ctx.r31.u32 + 1046, ctx.r23.u16);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
