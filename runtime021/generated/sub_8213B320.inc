DEFINE_REX_FUNC(sub_8213B320) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x8213B328;
	__savegprlr_23(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r23,r25
	ctx.r23.u64 = ctx.r25.u64;
	// mr r26,r25
	ctx.r26.u64 = ctx.r25.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 68);
	// lwz r24,64(r29)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r29.u32 + 64);
	// bl 0x8213f718
	ctx.lr = 0x8213B348;
	sub_8213F718(ctx, base);
	// addi r28,r29,44
	ctx.r28.s64 = ctx.r29.s64 + 44;
	// lwz r31,44(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 44);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8213b360
	if (!ctx.cr6.eq) goto loc_8213B360;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// b 0x8213b378
	goto loc_8213B378;
loc_8213B360:
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8213b378
	if (ctx.cr6.eq) goto loc_8213B378;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,259
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 259, ctx.xer);
	// bne cr6,0x8213b394
	if (!ctx.cr6.eq) goto loc_8213B394;
loc_8213B378:
	// lwz r11,64(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8213b394
	if (!ctx.cr6.eq) goto loc_8213B394;
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r3,60(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 60);
	// stw r11,64(r29)
	REX_STORE_U32(ctx.r29.u32 + 64, ctx.r11.u32);
	// bl 0x820d83c8
	ctx.lr = 0x8213B394;
	sub_820D83C8(ctx, base);
loc_8213B394:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8213b478
	if (ctx.cr6.eq) goto loc_8213B478;
loc_8213B39C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,259
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 259, ctx.xer);
	// beq cr6,0x8213b478
	if (ctx.cr6.eq) goto loc_8213B478;
	// lwz r11,20(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8213b478
	if (!ctx.cr6.lt) goto loc_8213B478;
	// addi r27,r29,52
	ctx.r27.s64 = ctx.r29.s64 + 52;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8213ec70
	ctx.lr = 0x8213B3C0;
	sub_8213EC70(ctx, base);
	// lwz r11,20(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8213b478
	if (!ctx.cr6.lt) goto loc_8213B478;
	// li r11,259
	ctx.r11.s64 = 259;
	// li r5,88
	ctx.r5.s64 = 88;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82136c88
	ctx.lr = 0x8213B3E4;
	sub_82136C88(ctx, base);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,60(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 60);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r31,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r31.u32);
	// bl 0x820d8268
	ctx.lr = 0x8213B408;
	sub_820D8268(ctx, base);
	// mr. r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// blt 0x8213b470
	if (ctx.cr0.lt) goto loc_8213B470;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8213b438
	if (ctx.cr6.eq) goto loc_8213B438;
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8213b42c
	if (!ctx.cr6.eq) goto loc_8213B42C;
	// stw r25,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r25.u32);
loc_8213B42C:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// stw r25,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r25.u32);
loc_8213B438:
	// stw r25,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// lwz r11,4(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8213b450
	if (ctx.cr6.eq) goto loc_8213B450;
	// stw r31,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// b 0x8213b454
	goto loc_8213B454;
loc_8213B450:
	// stw r31,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r31.u32);
loc_8213B454:
	// stw r31,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r31.u32);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// lwz r31,0(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8213b478
	if (ctx.cr6.eq) goto loc_8213B478;
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// b 0x8213b39c
	goto loc_8213B39C;
loc_8213B470:
	// mr r23,r25
	ctx.r23.u64 = ctx.r25.u64;
	// stw r25,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r25.u32);
loc_8213B478:
	// lwz r11,64(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 64);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8213b4ac
	if (!ctx.cr6.eq) goto loc_8213B4AC;
	// cmpwi cr6,r24,1
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 1, ctx.xer);
	// bne cr6,0x8213b4ac
	if (!ctx.cr6.eq) goto loc_8213B4AC;
	// addi r3,r29,52
	ctx.r3.s64 = ctx.r29.s64 + 52;
	// bl 0x8213ec70
	ctx.lr = 0x8213B494;
	sub_8213EC70(ctx, base);
	// cmplwi cr6,r3,2
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 2, ctx.xer);
	// blt cr6,0x8213b4ac
	if (ctx.cr6.lt) goto loc_8213B4AC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,60(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 60);
	// bl 0x820d8328
	ctx.lr = 0x8213B4A8;
	sub_820D8328(ctx, base);
	// stw r25,64(r29)
	REX_STORE_U32(ctx.r29.u32 + 64, ctx.r25.u32);
loc_8213B4AC:
	// lwz r4,52(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 52);
	// addi r31,r29,52
	ctx.r31.s64 = ctx.r29.s64 + 52;
	// b 0x8213b4fc
	goto loc_8213B4FC;
loc_8213B4B8:
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r11,259
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 259, ctx.xer);
	// beq cr6,0x8213b504
	if (ctx.cr6.eq) goto loc_8213B504;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8213b4f0
	if (ctx.cr6.eq) goto loc_8213B4F0;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8213b4e4
	if (!ctx.cr6.eq) goto loc_8213B4E4;
	// stw r25,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
loc_8213B4E4:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r25,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r25.u32);
loc_8213B4F0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8213b0c0
	ctx.lr = 0x8213B4F8;
	sub_8213B0C0(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_8213B4FC:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8213b4b8
	if (!ctx.cr6.eq) goto loc_8213B4B8;
loc_8213B504:
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
