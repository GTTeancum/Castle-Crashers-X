DEFINE_REX_FUNC(sub_82111A58) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82111A60;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// cmplwi cr6,r27,13
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 13, ctx.xer);
	// blt cr6,0x82111b28
	if (ctx.cr6.lt) goto loc_82111B28;
	// lwz r5,5(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 5);
	// addi r11,r27,-13
	ctx.r11.s64 = ctx.r27.s64 + -13;
	// lwz r8,1(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 1);
	// lwz r6,9(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 9);
	// cmplwi cr6,r5,1000
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1000, ctx.xer);
	// bgt cr6,0x82111b28
	if (ctx.cr6.gt) goto loc_82111B28;
	// cmplwi cr6,r6,1000
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1000, ctx.xer);
	// bgt cr6,0x82111b28
	if (ctx.cr6.gt) goto loc_82111B28;
	// mulli r9,r6,13
	ctx.r9.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(13));
	// mulli r10,r5,5
	ctx.r10.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(5));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82111b28
	if (!ctx.cr6.eq) goto loc_82111B28;
	// lwz r11,168(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 168);
	// rlwinm. r11,r11,0,11,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82111b0c
	if (ctx.cr0.eq) goto loc_82111B0C;
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82111b28
	if (ctx.cr6.lt) goto loc_82111B28;
	// addi r7,r28,13
	ctx.r7.s64 = ctx.r28.s64 + 13;
	// addi r3,r30,8
	ctx.r3.s64 = ctx.r30.s64 + 8;
	// bl 0x82115aa0
	ctx.lr = 0x82111AD4;
	sub_82115AA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82111b30
	if (ctx.cr0.lt) goto loc_82111B30;
	// lwz r11,168(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 168);
	// rlwinm r11,r11,0,12,10
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// stw r11,168(r29)
	REX_STORE_U32(ctx.r29.u32 + 168, ctx.r11.u32);
	// lwz r11,708(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 708);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,708(r30)
	REX_STORE_U32(ctx.r30.u32 + 708, ctx.r11.u32);
	// bne 0x82111c44
	if (!ctx.cr0.eq) goto loc_82111C44;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210f488
	ctx.lr = 0x82111B00;
	sub_8210F488(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82111b30
	if (!ctx.cr0.eq) goto loc_82111B30;
	// b 0x82111c44
	goto loc_82111C44;
loc_82111B0C:
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r10,24(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82111b38
	if (!ctx.cr6.eq) goto loc_82111B38;
	// lwz r11,144(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 144);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82111c44
	if (ctx.cr6.eq) goto loc_82111C44;
loc_82111B28:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4106
	ctx.r3.u64 = ctx.r3.u64 | 4106;
loc_82111B30:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82111B38:
	// lwz r9,24(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// lwz r11,60(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 60);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82111b28
	if (ctx.cr6.eq) goto loc_82111B28;
	// lwz r11,168(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 168);
	// lwz r10,64(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 64);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82111b28
	if (ctx.cr6.lt) goto loc_82111B28;
	// lwz r11,144(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 144);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82111b28
	if (!ctx.cr6.eq) goto loc_82111B28;
	// lwz r11,712(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 712);
	// addi r10,r30,712
	ctx.r10.s64 = ctx.r30.s64 + 712;
	// b 0x82111b84
	goto loc_82111B84;
loc_82111B70:
	// lwz r8,56(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// addi r31,r11,-4
	ctx.r31.s64 = ctx.r11.s64 + -4;
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82111b98
	if (ctx.cr6.eq) goto loc_82111B98;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82111B84:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82111b94
	if (ctx.cr6.eq) goto loc_82111B94;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82111b70
	if (!ctx.cr0.eq) goto loc_82111B70;
loc_82111B94:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82111B98:
	// lwz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82111bf4
	if (ctx.cr0.eq) goto loc_82111BF4;
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lis r12,-1024
	ctx.r12.s64 = -67108864;
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r11,r10,26,30,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x3;
	// ori r12,r12,0
	ctx.r12.u64 = ctx.r12.u64 | 0;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// rldicr r12,r12,6,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 6) & 0xFFFFFFFFFFFFFFFF;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// and r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 & ctx.r12.u64;
	// sld r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r10.u8 & 0x7F));
	// ldx r11,r11,r29
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + ctx.r29.u32);
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// bne cr6,0x82111bf4
	if (!ctx.cr6.eq) goto loc_82111BF4;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210d078
	ctx.lr = 0x82111BEC;
	sub_8210D078(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82111b30
	if (!ctx.cr0.eq) goto loc_82111B30;
loc_82111BF4:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210e730
	ctx.lr = 0x82111C00;
	sub_8210E730(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,-1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -1, ctx.xer);
	// bne cr6,0x82111b98
	if (!ctx.cr6.eq) goto loc_82111B98;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,15
	ctx.r3.s64 = 15;
	// bl 0x8210e7d8
	ctx.lr = 0x82111C1C;
	sub_8210E7D8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82111c30
	if (!ctx.cr0.eq) goto loc_82111C30;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x82111b30
	goto loc_82111B30;
loc_82111C30:
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// bl 0x82129a70
	ctx.lr = 0x82111C40;
	sub_82129A70(ctx, base);
	// stw r31,144(r29)
	REX_STORE_U32(ctx.r29.u32 + 144, ctx.r31.u32);
loc_82111C44:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82111b30
	goto loc_82111B30;
}
