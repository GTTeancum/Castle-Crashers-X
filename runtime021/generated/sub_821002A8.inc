DEFINE_REX_FUNC(sub_821002A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x821002B0;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// ori r11,r11,4101
	ctx.r11.u64 = ctx.r11.u64 | 4101;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x821002d8
	if (!ctx.cr6.eq) goto loc_821002D8;
	// lis r31,-32747
	ctx.r31.s64 = -2146107392;
	// ori r31,r31,20994
	ctx.r31.u64 = ctx.r31.u64 | 20994;
	// b 0x82100328
	goto loc_82100328;
loc_821002D8:
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// ori r11,r11,4103
	ctx.r11.u64 = ctx.r11.u64 | 4103;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x821002f4
	if (!ctx.cr6.eq) goto loc_821002F4;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,1232
	ctx.r31.u64 = ctx.r31.u64 | 1232;
	// b 0x82100328
	goto loc_82100328;
loc_821002F4:
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// ori r11,r11,4104
	ctx.r11.u64 = ctx.r11.u64 | 4104;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x82100310
	if (!ctx.cr6.eq) goto loc_82100310;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,4320
	ctx.r31.u64 = ctx.r31.u64 | 4320;
	// b 0x82100328
	goto loc_82100328;
loc_82100310:
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// ori r11,r11,4119
	ctx.r11.u64 = ctx.r11.u64 | 4119;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x82100328
	if (!ctx.cr6.eq) goto loc_82100328;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,1617
	ctx.r31.u64 = ctx.r31.u64 | 1617;
loc_82100328:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820fcde0
	ctx.lr = 0x82100334;
	sub_820FCDE0(ctx, base);
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210036c
	if (ctx.cr6.eq) goto loc_8210036C;
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// blt cr6,0x8210036c
	if (ctx.cr6.lt) goto loc_8210036C;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bge cr6,0x8210036c
	if (!ctx.cr6.lt) goto loc_8210036C;
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// li r27,1
	ctx.r27.s64 = 1;
	// addi r11,r11,-3
	ctx.r11.s64 = ctx.r11.s64 + -3;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r26,r11,27,31,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// b 0x82100374
	goto loc_82100374;
loc_8210036C:
	// li r27,0
	ctx.r27.s64 = 0;
	// li r26,0
	ctx.r26.s64 = 0;
loc_82100374:
	// lwz r4,20(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmpwi cr6,r4,7
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 7, ctx.xer);
	// beq cr6,0x821003ac
	if (ctx.cr6.eq) goto loc_821003AC;
	// lwz r3,12(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r31,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r31.u32);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// stw r11,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821003A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x821003b8
	goto loc_821003B8;
loc_821003AC:
	// lwz r11,720(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 720);
	// oris r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 1048576;
	// stw r11,720(r30)
	REX_STORE_U32(ctx.r30.u32 + 720, ctx.r11.u32);
loc_821003B8:
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// addi r28,r30,248
	ctx.r28.s64 = ctx.r30.s64 + 248;
	// b 0x82100504
	goto loc_82100504;
loc_821003C4:
	// lwz r11,304(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 304);
	// addi r31,r29,-92
	ctx.r31.s64 = ctx.r29.s64 + -92;
	// rlwinm. r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82100414
	if (ctx.cr0.eq) goto loc_82100414;
	// rlwinm. r10,r11,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82100500
	if (ctx.cr0.eq) goto loc_82100500;
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82100500
	if (ctx.cr0.eq) goto loc_82100500;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x82100500
	if (ctx.cr6.eq) goto loc_82100500;
	// lwz r3,12(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82100404;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// ori r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 256;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// b 0x82100500
	goto loc_82100500;
loc_82100414:
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82100498
	if (ctx.cr0.eq) goto loc_82100498;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x82100448
	if (ctx.cr6.eq) goto loc_82100448;
	// lwz r3,12(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210043C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// ori r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 256;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
loc_82100448:
	// lwz r3,12(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82100460;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// rlwinm r11,r11,0,5,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFF7FFFFFF;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// lwz r11,180(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 180);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,180(r30)
	REX_STORE_U32(ctx.r30.u32 + 180, ctx.r11.u32);
	// lwz r3,424(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 424);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// ld r4,16(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// beq cr6,0x82100498
	if (ctx.cr6.eq) goto loc_82100498;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82100498;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82100498:
	// lwz r3,396(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// cmplw cr6,r31,r3
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x821004b0
	if (!ctx.cr6.eq) goto loc_821004B0;
	// bl 0x8210bc10
	ctx.lr = 0x821004A8;
	sub_8210BC10(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,396(r30)
	REX_STORE_U32(ctx.r30.u32 + 396, ctx.r11.u32);
loc_821004B0:
	// lwz r3,420(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 420);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82100500
	if (ctx.cr6.eq) goto loc_82100500;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_821004C4:
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// lwz r31,88(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x821004c4
	if (!ctx.cr6.eq) goto loc_821004C4;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8210aa68
	ctx.lr = 0x821004F8;
	sub_8210AA68(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8210052c
	if (ctx.cr0.lt) goto loc_8210052C;
loc_82100500:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
loc_82100504:
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82100518
	if (ctx.cr6.eq) goto loc_82100518;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// bne 0x821003c4
	if (!ctx.cr0.eq) goto loc_821003C4;
loc_82100518:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820ffcb0
	ctx.lr = 0x82100528;
	sub_820FFCB0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8210052C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
