DEFINE_REX_FUNC(sub_82083F50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x82083F58;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,6
	ctx.r10.s64 = 6;
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rlwinm r25,r11,0,0,24
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// rlwinm r29,r11,0,25,25
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// bl 0x82095700
	ctx.lr = 0x82083F94;
	sub_82095700(ctx, base);
	// clrlwi r26,r3,24
	ctx.r26.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82084050
	if (ctx.cr6.eq) goto loc_82084050;
	// clrlwi r24,r26,24
	ctx.r24.u64 = ctx.r26.u32 & 0xFF;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82095788
	ctx.lr = 0x82083FB8;
	sub_82095788(ctx, base);
	// extsh r23,r3
	ctx.r23.s64 = ctx.r3.s16;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// sth r23,28(r31)
	REX_STORE_U16(ctx.r31.u32 + 28, ctx.r23.u16);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82095788
	ctx.lr = 0x82083FD4;
	sub_82095788(ctx, base);
	// extsh r29,r3
	ctx.r29.s64 = ctx.r3.s16;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// sth r29,30(r31)
	REX_STORE_U16(ctx.r31.u32 + 30, ctx.r29.u16);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82095788
	ctx.lr = 0x82083FF0;
	sub_82095788(ctx, base);
	// extsh r28,r3
	ctx.r28.s64 = ctx.r3.s16;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// sth r28,32(r31)
	REX_STORE_U16(ctx.r31.u32 + 32, ctx.r28.u16);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82095788
	ctx.lr = 0x8208400C;
	sub_82095788(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// sth r11,40(r31)
	REX_STORE_U16(ctx.r31.u32 + 40, ctx.r11.u16);
	// bge cr6,0x82084020
	if (!ctx.cr6.lt) goto loc_82084020;
	// sth r27,28(r31)
	REX_STORE_U16(ctx.r31.u32 + 28, ctx.r27.u16);
loc_82084020:
	// extsh r10,r29
	ctx.r10.s64 = ctx.r29.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x82084030
	if (!ctx.cr6.lt) goto loc_82084030;
	// sth r27,30(r31)
	REX_STORE_U16(ctx.r31.u32 + 30, ctx.r27.u16);
loc_82084030:
	// extsh r10,r28
	ctx.r10.s64 = ctx.r28.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x82084040
	if (!ctx.cr6.lt) goto loc_82084040;
	// sth r27,32(r31)
	REX_STORE_U16(ctx.r31.u32 + 32, ctx.r27.u16);
loc_82084040:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82084050
	if (!ctx.cr6.lt) goto loc_82084050;
	// sth r27,40(r31)
	REX_STORE_U16(ctx.r31.u32 + 40, ctx.r27.u16);
loc_82084050:
	// clrlwi r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820840c0
	if (ctx.cr6.eq) goto loc_820840C0;
	// clrlwi r29,r26,24
	ctx.r29.u64 = ctx.r26.u32 & 0xFF;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82095788
	ctx.lr = 0x82084074;
	sub_82095788(ctx, base);
	// sth r3,34(r31)
	REX_STORE_U16(ctx.r31.u32 + 34, ctx.r3.u16);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82095788
	ctx.lr = 0x8208408C;
	sub_82095788(ctx, base);
	// sth r3,36(r31)
	REX_STORE_U16(ctx.r31.u32 + 36, ctx.r3.u16);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82095788
	ctx.lr = 0x820840A4;
	sub_82095788(ctx, base);
	// sth r3,38(r31)
	REX_STORE_U16(ctx.r31.u32 + 38, ctx.r3.u16);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82095788
	ctx.lr = 0x820840BC;
	sub_82095788(ctx, base);
	// sth r3,42(r31)
	REX_STORE_U16(ctx.r31.u32 + 42, ctx.r3.u16);
loc_820840C0:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bge cr6,0x820840d8
	if (!ctx.cr6.lt) goto loc_820840D8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// b 0x820840dc
	goto loc_820840DC;
loc_820840D8:
	// lwz r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_820840DC:
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820840f0
	if (ctx.cr6.eq) goto loc_820840F0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x820837c0
	ctx.lr = 0x820840F0;
	sub_820837C0(ctx, base);
loc_820840F0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
