DEFINE_REX_FUNC(sub_82083A08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x82083A10;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
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
	// rlwinm r26,r11,0,0,24
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// rlwinm r29,r11,0,25,25
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// bl 0x82095700
	ctx.lr = 0x82083A4C;
	sub_82095700(ctx, base);
	// clrlwi r28,r3,24
	ctx.r28.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82083adc
	if (ctx.cr6.eq) goto loc_82083ADC;
	// clrlwi r25,r28,24
	ctx.r25.u64 = ctx.r28.u32 & 0xFF;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82095788
	ctx.lr = 0x82083A70;
	sub_82095788(ctx, base);
	// extsh r24,r3
	ctx.r24.s64 = ctx.r3.s16;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// sth r24,28(r31)
	REX_STORE_U16(ctx.r31.u32 + 28, ctx.r24.u16);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82095788
	ctx.lr = 0x82083A8C;
	sub_82095788(ctx, base);
	// extsh r29,r3
	ctx.r29.s64 = ctx.r3.s16;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// sth r29,30(r31)
	REX_STORE_U16(ctx.r31.u32 + 30, ctx.r29.u16);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82095788
	ctx.lr = 0x82083AA8;
	sub_82095788(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// sth r11,32(r31)
	REX_STORE_U16(ctx.r31.u32 + 32, ctx.r11.u16);
	// bge cr6,0x82083abc
	if (!ctx.cr6.lt) goto loc_82083ABC;
	// sth r27,28(r31)
	REX_STORE_U16(ctx.r31.u32 + 28, ctx.r27.u16);
loc_82083ABC:
	// extsh r10,r29
	ctx.r10.s64 = ctx.r29.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x82083acc
	if (!ctx.cr6.lt) goto loc_82083ACC;
	// sth r27,30(r31)
	REX_STORE_U16(ctx.r31.u32 + 30, ctx.r27.u16);
loc_82083ACC:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82083adc
	if (!ctx.cr6.lt) goto loc_82083ADC;
	// sth r27,32(r31)
	REX_STORE_U16(ctx.r31.u32 + 32, ctx.r27.u16);
loc_82083ADC:
	// clrlwi r11,r26,24
	ctx.r11.u64 = ctx.r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82083b34
	if (ctx.cr6.eq) goto loc_82083B34;
	// clrlwi r29,r28,24
	ctx.r29.u64 = ctx.r28.u32 & 0xFF;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82095788
	ctx.lr = 0x82083B00;
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
	ctx.lr = 0x82083B18;
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
	ctx.lr = 0x82083B30;
	sub_82095788(ctx, base);
	// sth r3,38(r31)
	REX_STORE_U16(ctx.r31.u32 + 38, ctx.r3.u16);
loc_82083B34:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bge cr6,0x82083b4c
	if (!ctx.cr6.lt) goto loc_82083B4C;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// b 0x82083b50
	goto loc_82083B50;
loc_82083B4C:
	// lwz r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_82083B50:
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82083b64
	if (ctx.cr6.eq) goto loc_82083B64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x820837c0
	ctx.lr = 0x82083B64;
	sub_820837C0(ctx, base);
loc_82083B64:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
