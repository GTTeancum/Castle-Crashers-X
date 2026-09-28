DEFINE_REX_FUNC(sub_821005E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x821005F0;
	__savegprlr_27(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r11,420(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 420);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82100610
	if (ctx.cr6.eq) goto loc_82100610;
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// rlwinm r11,r11,2,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x1;
	// b 0x82100614
	goto loc_82100614;
loc_82100610:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82100614:
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r29,r1,80
	ctx.r29.s64 = ctx.r1.s64 + 80;
	// xori r27,r11,1
	ctx.r27.u64 = ctx.r11.u64 ^ 1;
	// addi r31,r28,380
	ctx.r31.s64 = ctx.r28.s64 + 380;
loc_8210062C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82100668
	if (ctx.cr6.eq) goto loc_82100668;
	// lwz r11,396(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm. r11,r11,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82100668
	if (!ctx.cr0.eq) goto loc_82100668;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820ffe78
	ctx.lr = 0x82100654;
	sub_820FFE78(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwimi r10,r27,24,7,7
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 24) & 0x1000000) | (ctx.r10.u64 & 0xFFFFFFFFFEFFFFFF);
	// stw r10,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r10.u32);
	// b 0x82100678
	goto loc_82100678;
loc_82100668:
	// li r5,42
	ctx.r5.s64 = 42;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82129fa0
	ctx.lr = 0x82100678;
	sub_82129FA0(ctx, base);
loc_82100678:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r29,r29,42
	ctx.r29.s64 = ctx.r29.s64 + 42;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x8210062c
	if (ctx.cr6.lt) goto loc_8210062C;
	// lwz r11,400(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 400);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210070c
	if (ctx.cr6.eq) goto loc_8210070C;
	// lwz r11,28(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 28);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x821006ac
	if (!ctx.cr6.eq) goto loc_821006AC;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x821006b0
	goto loc_821006B0;
loc_821006AC:
	// bl 0x820fbf88
	ctx.lr = 0x821006B0;
	sub_820FBF88(ctx, base);
loc_821006B0:
	// lwz r11,420(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 420);
	// rlwinm r10,r3,2,24,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFC;
	// stb r10,248(r1)
	REX_STORE_U8(ctx.r1.u32 + 248, ctx.r10.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821006cc
	if (ctx.cr6.eq) goto loc_821006CC;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// b 0x821006d0
	goto loc_821006D0;
loc_821006CC:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821006D0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stb r11,248(r1)
	REX_STORE_U8(ctx.r1.u32 + 248, ctx.r11.u8);
	// beq cr6,0x821006f0
	if (ctx.cr6.eq) goto loc_821006F0;
	// ori r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 16;
	// stb r11,248(r1)
	REX_STORE_U8(ctx.r1.u32 + 248, ctx.r11.u8);
loc_821006F0:
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,400(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 400);
	// li r5,169
	ctx.r5.s64 = 169;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82108e58
	ctx.lr = 0x82100704;
	sub_82108E58(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82100710
	if (ctx.cr0.lt) goto loc_82100710;
loc_8210070C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82100710:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
