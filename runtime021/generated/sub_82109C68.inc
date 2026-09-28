DEFINE_REX_FUNC(sub_82109C68) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x82109C70;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r11,72(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 72);
	// cmplwi cr6,r11,52
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 52, ctx.xer);
	// blt cr6,0x82109f38
	if (ctx.cr6.lt) goto loc_82109F38;
	// lwz r30,68(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 68);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r25,20(r30)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r24,24(r30)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x82109f38
	if (!ctx.cr6.eq) goto loc_82109F38;
	// lbz r11,35(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 35);
	// lbz r10,33(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 33);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82109f38
	if (ctx.cr6.gt) goto loc_82109F38;
	// lbz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 36);
	// lbz r10,34(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 34);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82109f38
	if (ctx.cr6.gt) goto loc_82109F38;
	// ld r11,92(r27)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r27.u32 + 92);
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x82109cd8
	if (ctx.cr6.eq) goto loc_82109CD8;
	// ld r10,44(r28)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r28.u32 + 44);
	// cmpld cr6,r11,r10
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r10.u64, ctx.xer);
	// bne cr6,0x82109f38
	if (!ctx.cr6.eq) goto loc_82109F38;
loc_82109CD8:
	// lwz r8,28(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 28);
	// li r26,0
	ctx.r26.s64 = 0;
	// mulli r11,r8,12
	ctx.r11.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(12));
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// addi r29,r11,112
	ctx.r29.s64 = ctx.r11.s64 + 112;
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82109d24
	if (ctx.cr6.eq) goto loc_82109D24;
	// ld r7,44(r28)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r28.u32 + 44);
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
loc_82109D04:
	// ld r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r10.u32 + 0);
	// cmpld cr6,r6,r7
	ctx.cr6.compare<uint64_t>(ctx.r6.u64, ctx.r7.u64, ctx.xer);
	// beq cr6,0x82109f38
	if (ctx.cr6.eq) goto loc_82109F38;
	// lwz r6,0(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,92
	ctx.r10.s64 = ctx.r10.s64 + 92;
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x82109d04
	if (ctx.cr6.lt) goto loc_82109D04;
loc_82109D24:
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x82109f38
	if (!ctx.cr6.lt) goto loc_82109F38;
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// mulli r9,r11,92
	ctx.r9.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(92));
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// add r31,r9,r10
	ctx.r31.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// addi r4,r28,8
	ctx.r4.s64 = ctx.r28.s64 + 8;
	// ld r11,44(r28)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r28.u32 + 44);
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// stdx r11,r9,r10
	REX_STORE_U64(ctx.r9.u32 + ctx.r10.u32, ctx.r11.u64);
	// li r5,36
	ctx.r5.s64 = 36;
	// bl 0x82129a70
	ctx.lr = 0x82109D58;
	sub_82129A70(ctx, base);
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// addi r4,r28,52
	ctx.r4.s64 = ctx.r28.s64 + 52;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x82129a70
	ctx.lr = 0x82109D68;
	sub_82129A70(ctx, base);
	// lbz r10,35(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 35);
	// lbz r11,33(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 33);
	// addi r5,r30,37
	ctx.r5.s64 = ctx.r30.s64 + 37;
	// li r8,15
	ctx.r8.s64 = 15;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r9,r5,15
	ctx.r9.s64 = ctx.r5.s64 + 15;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// li r6,15
	ctx.r6.s64 = 15;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,36(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 36);
	// lbz r11,34(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 34);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// lbz r11,35(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 35);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// lbz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 36);
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// lwz r30,32(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 32);
	// lwz r10,72(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 72);
	// lwz r11,36(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 36);
	// add r7,r11,r29
	ctx.r7.u64 = ctx.r11.u64 + ctx.r29.u64;
	// subf r11,r11,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r11.u64;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r10,r10,-52
	ctx.r10.s64 = ctx.r10.s64 + -52;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// bl 0x82136f70
	ctx.lr = 0x82109DE0;
	sub_82136F70(ctx, base);
	// sth r26,30(r30)
	REX_STORE_U16(ctx.r30.u32 + 30, ctx.r26.u16);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82127e20
	ctx.lr = 0x82109DEC;
	sub_82127E20(ctx, base);
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lis r9,16384
	ctx.r9.s64 = 1073741824;
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// ori r9,r9,32770
	ctx.r9.u64 = ctx.r9.u64 | 32770;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r8,r11,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r11.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// stb r7,8(r10)
	REX_STORE_U8(ctx.r10.u32 + 8, ctx.r7.u8);
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// stw r11,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// stw r30,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r30.u32);
	// stw r8,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// addi r10,r10,-24
	ctx.r10.s64 = ctx.r10.s64 + -24;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// beq cr6,0x82109ec8
	if (ctx.cr6.eq) goto loc_82109EC8;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82109ec4
	if (ctx.cr6.eq) goto loc_82109EC4;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x821080c8
	ctx.lr = 0x82109E78;
	sub_821080C8(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x821089a8
	ctx.lr = 0x82109E9C;
	sub_821089A8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82109eac
	if (!ctx.cr0.lt) goto loc_82109EAC;
	// mr r24,r26
	ctx.r24.u64 = ctx.r26.u64;
	// b 0x82109eb8
	goto loc_82109EB8;
loc_82109EAC:
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
loc_82109EB8:
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82108860
	ctx.lr = 0x82109EC0;
	sub_82108860(ctx, base);
	// b 0x82109ec8
	goto loc_82109EC8;
loc_82109EC4:
	// mr r24,r26
	ctx.r24.u64 = ctx.r26.u64;
loc_82109EC8:
	// addi r30,r31,88
	ctx.r30.s64 = ctx.r31.s64 + 88;
	// stw r26,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r26.u32);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// stw r26,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r26.u32);
	// beq cr6,0x82109f28
	if (ctx.cr6.eq) goto loc_82109F28;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82109f28
	if (ctx.cr6.eq) goto loc_82109F28;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82107c10
	ctx.lr = 0x82109EF0;
	sub_82107C10(ctx, base);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82107f30
	ctx.lr = 0x82109F14;
	sub_82107F30(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82109f20
	if (ctx.cr0.lt) goto loc_82109F20;
	// stw r24,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r24.u32);
loc_82109F20:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82107ed8
	ctx.lr = 0x82109F28;
	sub_82107ED8(ctx, base);
loc_82109F28:
	// lwz r11,32(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 32);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// stw r11,36(r27)
	REX_STORE_U32(ctx.r27.u32 + 36, ctx.r11.u32);
loc_82109F38:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
