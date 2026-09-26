DEFINE_REX_FUNC(sub_821231F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x821231F8;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,60(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// lwz r9,564(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 564);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,564(r11)
	REX_STORE_U32(ctx.r11.u32 + 564, ctx.r10.u32);
	// beq cr6,0x82123230
	if (ctx.cr6.eq) goto loc_82123230;
	// lwz r10,568(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 568);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,568(r11)
	REX_STORE_U32(ctx.r11.u32 + 568, ctx.r10.u32);
loc_82123230:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r5,32(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// addi r3,r31,184
	ctx.r3.s64 = ctx.r31.s64 + 184;
	// bl 0x82122608
	ctx.lr = 0x82123240;
	sub_82122608(ctx, base);
	// addi r3,r31,248
	ctx.r3.s64 = ctx.r31.s64 + 248;
	// lwz r5,32(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// lwz r4,60(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// bl 0x82122608
	ctx.lr = 0x82123250;
	sub_82122608(ctx, base);
	// lwz r11,176(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// lwz r10,180(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r9,240(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// stw r11,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r11.u32);
	// lwz r11,60(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm. r10,r9,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// bne 0x82123284
	if (!ctx.cr0.eq) goto loc_82123284;
	// lwz r11,304(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// rlwinm. r11,r11,0,3,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212328c
	if (ctx.cr0.eq) goto loc_8212328C;
loc_82123284:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82122c20
	ctx.lr = 0x8212328C;
	sub_82122C20(ctx, base);
loc_8212328C:
	// addi r27,r31,48
	ctx.r27.s64 = ctx.r31.s64 + 48;
	// addi r29,r30,4
	ctx.r29.s64 = ctx.r30.s64 + 4;
	// stw r27,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r27.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// stw r29,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// stw r29,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// lwz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821232fc
	if (ctx.cr0.eq) goto loc_821232FC;
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// addi r28,r31,72
	ctx.r28.s64 = ctx.r31.s64 + 72;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x821232e0
	if (!ctx.cr6.eq) goto loc_821232E0;
	// lwz r25,140(r31)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// bl 0x82136f58
	ctx.lr = 0x821232D0;
	sub_82136F58(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r31,80
	ctx.r3.s64 = ctx.r31.s64 + 80;
	// bl 0x82122270
	ctx.lr = 0x821232E0;
	sub_82122270(ctx, base);
loc_821232E0:
	// stw r28,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r28.u32);
	// addi r11,r30,12
	ctx.r11.s64 = ctx.r30.s64 + 12;
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// stw r10,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r10.u32);
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r11,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
loc_821232FC:
	// lwz r29,4(r29)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplw cr6,r29,r27
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x82123310
	if (ctx.cr6.eq) goto loc_82123310;
	// cmplwi r29,0
	ctx.cr0.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne 0x8212332c
	if (!ctx.cr0.eq) goto loc_8212332C;
loc_82123310:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r31,32
	ctx.r5.s64 = ctx.r31.s64 + 32;
	// ld r4,24(r30)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r30.u32 + 24);
	// addi r3,r11,536
	ctx.r3.s64 = ctx.r11.s64 + 536;
	// bl 0x82122840
	ctx.lr = 0x82123328;
	sub_82122840(ctx, base);
	// b 0x821233b0
	goto loc_821233B0;
loc_8212332C:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x821233b0
	if (ctx.cr6.eq) goto loc_821233B0;
	// ld r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 24);
	// rldicl r28,r11,5,59
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u64, 5) & 0x1F;
	// b 0x82123354
	goto loc_82123354;
loc_82123340:
	// lwz r29,4(r29)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplw cr6,r29,r27
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x82123370
	if (ctx.cr6.eq) goto loc_82123370;
	// cmplwi r29,0
	ctx.cr0.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq 0x82123370
	if (ctx.cr0.eq) goto loc_82123370;
loc_82123354:
	// addi r30,r29,-4
	ctx.r30.s64 = ctx.r29.s64 + -4;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82125e68
	ctx.lr = 0x82123364;
	sub_82125E68(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82123340
	if (!ctx.cr0.eq) goto loc_82123340;
	// b 0x821233b0
	goto loc_821233B0;
loc_82123370:
	// lwz r9,16(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r11,r31,32
	ctx.r11.s64 = ctx.r31.s64 + 32;
	// ld r10,24(r30)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r30.u32 + 24);
	// ld r8,40(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// addi r3,r9,536
	ctx.r3.s64 = ctx.r9.s64 + 536;
	// li r9,1
	ctx.r9.s64 = 1;
	// cmpld cr6,r8,r10
	ctx.cr6.compare<uint64_t>(ctx.r8.u64, ctx.r10.u64, ctx.xer);
	// blt cr6,0x82123394
	if (ctx.cr6.lt) goto loc_82123394;
	// li r9,0
	ctx.r9.s64 = 0;
loc_82123394:
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// std r10,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r10.u64);
	// beq cr6,0x821233ac
	if (ctx.cr6.eq) goto loc_821233AC;
	// bl 0x8211aab0
	ctx.lr = 0x821233A8;
	sub_8211AAB0(ctx, base);
	// b 0x821233b0
	goto loc_821233B0;
loc_821233AC:
	// bl 0x82122708
	ctx.lr = 0x821233B0;
	sub_82122708(ctx, base);
loc_821233B0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
