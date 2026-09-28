DEFINE_REX_FUNC(sub_82107888) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82107890;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x821079d4
	goto loc_821079D4;
loc_821078A0:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r11,0,8,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x821078b4
	if (ctx.cr0.eq) goto loc_821078B4;
	// rlwinm. r11,r11,0,7,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821079e0
	if (ctx.cr0.eq) goto loc_821079E0;
loc_821078B4:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82108e30
	ctx.lr = 0x821078C4;
	sub_82108E30(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x821079e0
	if (!ctx.cr0.eq) goto loc_821079E0;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x821079ac
	if (ctx.cr6.eq) goto loc_821079AC;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// beq cr6,0x82107988
	if (ctx.cr6.eq) goto loc_82107988;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x82107978
	if (ctx.cr6.eq) goto loc_82107978;
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// beq cr6,0x82107950
	if (ctx.cr6.eq) goto loc_82107950;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x82107944
	if (ctx.cr6.eq) goto loc_82107944;
	// cmpwi cr6,r11,11
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 11, ctx.xer);
	// beq cr6,0x82107920
	if (ctx.cr6.eq) goto loc_82107920;
	// cmpwi cr6,r11,12
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 12, ctx.xer);
	// bne cr6,0x821079b8
	if (!ctx.cr6.eq) goto loc_821079B8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82107290
	ctx.lr = 0x8210791C;
	sub_82107290(ctx, base);
	// b 0x821079b4
	goto loc_821079B4;
loc_82107920:
	// lwz r11,20(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821079b8
	if (ctx.cr6.eq) goto loc_821079B8;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,28(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 28);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,24(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// bl 0x821031e0
	ctx.lr = 0x82107940;
	sub_821031E0(ctx, base);
	// b 0x821079b4
	goto loc_821079B4;
loc_82107944:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82103d80
	ctx.lr = 0x8210794C;
	sub_82103D80(ctx, base);
	// b 0x821079b4
	goto loc_821079B4;
loc_82107950:
	// lwz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r11.u32);
	// lwz r11,20(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821079b8
	if (ctx.cr6.eq) goto loc_821079B8;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82106ff0
	ctx.lr = 0x82107974;
	sub_82106FF0(ctx, base);
	// b 0x821079b4
	goto loc_821079B4;
loc_82107978:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82103c48
	ctx.lr = 0x82107980;
	sub_82103C48(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// b 0x821079b4
	goto loc_821079B4;
loc_82107988:
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82105460
	ctx.lr = 0x82107994;
	sub_82105460(ctx, base);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821079b4
	if (ctx.cr6.eq) goto loc_821079B4;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// b 0x821079c0
	goto loc_821079C0;
loc_821079AC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82106368
	ctx.lr = 0x821079B4;
	sub_82106368(ctx, base);
loc_821079B4:
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_821079B8:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x82108e38
	ctx.lr = 0x821079C0;
	sub_82108E38(ctx, base);
loc_821079C0:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge cr6,0x821079d4
	if (!ctx.cr6.lt) goto loc_821079D4;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82100fd8
	ctx.lr = 0x821079D4;
	sub_82100FD8(ctx, base);
loc_821079D4:
	// lwz r11,400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821078a0
	if (!ctx.cr6.eq) goto loc_821078A0;
loc_821079E0:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// addi r28,r31,380
	ctx.r28.s64 = ctx.r31.s64 + 380;
	// ori r29,r11,65534
	ctx.r29.u64 = ctx.r11.u64 | 65534;
loc_821079EC:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82107a4c
	if (ctx.cr6.eq) goto loc_82107A4C;
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm. r10,r10,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82107a20
	if (ctx.cr0.eq) goto loc_82107A20;
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// subf r9,r30,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r30.u64;
	// rlwinm r10,r10,0,19,17
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFDFFF;
	// oris r4,r9,65532
	ctx.r4.u64 = ctx.r9.u64 | 4294705152;
	// stw r10,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r10.u32);
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// bl 0x82108e20
	ctx.lr = 0x82107A20;
	sub_82108E20(ctx, base);
loc_82107A20:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm. r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82107a4c
	if (ctx.cr0.eq) goto loc_82107A4C;
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// subf r9,r30,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r30.u64;
	// rlwinm r10,r10,0,20,18
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFEFFF;
	// oris r4,r9,65016
	ctx.r4.u64 = ctx.r9.u64 | 4260888576;
	// stw r10,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r10.u32);
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// bl 0x82108e20
	ctx.lr = 0x82107A4C;
	sub_82108E20(ctx, base);
loc_82107A4C:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x821079ec
	if (ctx.cr6.lt) goto loc_821079EC;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
