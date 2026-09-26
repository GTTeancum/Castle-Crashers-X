DEFINE_REX_FUNC(sub_82104B10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x82104B18;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r25,-32221
	ctx.r25.s64 = -2111635456;
	// li r24,0
	ctx.r24.s64 = 0;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// stw r24,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// lwz r11,23120(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 23120);
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82104b58
	if (ctx.cr6.eq) goto loc_82104B58;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,183
	ctx.r30.u64 = ctx.r30.u64 | 183;
	// b 0x82104c10
	goto loc_82104C10;
loc_82104B58:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8210c908
	ctx.lr = 0x82104B60;
	sub_8210C908(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82104bf4
	if (ctx.cr0.lt) goto loc_82104BF4;
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x820ff968
	ctx.lr = 0x82104B80;
	sub_820FF968(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82104ba0
	if (ctx.cr0.eq) goto loc_82104BA0;
	// stw r24,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x820b6ca0
	ctx.lr = 0x82104B94;
	sub_820B6CA0(ctx, base);
	// stw r3,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82104bac
	if (!ctx.cr0.eq) goto loc_82104BAC;
loc_82104BA0:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x82104bd4
	goto loc_82104BD4;
loc_82104BAC:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x82104bc0
	if (ctx.cr6.eq) goto loc_82104BC0;
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bne cr6,0x82104bc4
	if (!ctx.cr6.eq) goto loc_82104BC4;
loc_82104BC0:
	// li r4,1
	ctx.r4.s64 = 1;
loc_82104BC4:
	// addi r3,r31,424
	ctx.r3.s64 = ctx.r31.s64 + 424;
	// bl 0x82109190
	ctx.lr = 0x82104BCC;
	sub_82109190(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82104c08
	if (!ctx.cr0.lt) goto loc_82104C08;
loc_82104BD4:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82104bf4
	if (ctx.cr6.eq) goto loc_82104BF4;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bl 0x821028d8
	ctx.lr = 0x82104BF0;
	sub_821028D8(ctx, base);
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
loc_82104BF4:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82104c10
	if (ctx.cr6.eq) goto loc_82104C10;
	// bl 0x8210c788
	ctx.lr = 0x82104C04;
	sub_8210C788(ctx, base);
	// b 0x82104c10
	goto loc_82104C10;
loc_82104C08:
	// mr r30,r24
	ctx.r30.u64 = ctx.r24.u64;
	// stw r31,23120(r25)
	REX_STORE_U32(ctx.r25.u32 + 23120, ctx.r31.u32);
loc_82104C10:
	// stw r31,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r31.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
