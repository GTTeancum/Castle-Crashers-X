DEFINE_REX_FUNC(sub_82102940) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82102948;
	__savegprlr_27(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,0
	ctx.r27.s64 = 0;
	// li r11,4
	ctx.r11.s64 = 4;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r27,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// bl 0x821015d0
	ctx.lr = 0x82102970;
	sub_821015D0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82102a50
	if (ctx.cr0.lt) goto loc_82102A50;
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x821029bc
	if (ctx.cr6.lt) goto loc_821029BC;
	// beq cr6,0x821029b0
	if (ctx.cr6.eq) goto loc_821029B0;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x821029a8
	if (!ctx.cr6.eq) goto loc_821029A8;
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x821029a8
	if (ctx.cr6.eq) goto loc_821029A8;
	// lwz r11,720(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 720);
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x821029b0
	if (!ctx.cr0.eq) goto loc_821029B0;
loc_821029A8:
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x821029b4
	goto loc_821029B4;
loc_821029B0:
	// li r4,0
	ctx.r4.s64 = 0;
loc_821029B4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820fcde0
	ctx.lr = 0x821029BC;
	sub_820FCDE0(ctx, base);
loc_821029BC:
	// lwz r11,400(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 400);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82102a4c
	if (ctx.cr6.eq) goto loc_82102A4C;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820ff170
	ctx.lr = 0x821029EC;
	sub_820FF170(ctx, base);
	// lwz r29,80(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82102a10
	if (ctx.cr0.lt) goto loc_82102A10;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r3,400(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 400);
	// bl 0x82108e48
	ctx.lr = 0x82102A08;
	sub_82108E48(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge 0x82102a28
	if (!ctx.cr0.lt) goto loc_82102A28;
loc_82102A10:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82102a50
	if (ctx.cr6.eq) goto loc_82102A50;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82108f60
	ctx.lr = 0x82102A24;
	sub_82108F60(ctx, base);
	// b 0x82102a50
	goto loc_82102A50;
loc_82102A28:
	// lwz r3,408(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 408);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82102a40
	if (ctx.cr6.eq) goto loc_82102A40;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x8210c058
	ctx.lr = 0x82102A40;
	sub_8210C058(ctx, base);
loc_82102A40:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82108f60
	ctx.lr = 0x82102A4C;
	sub_82108F60(ctx, base);
loc_82102A4C:
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
loc_82102A50:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
