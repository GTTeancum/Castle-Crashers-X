DEFINE_REX_FUNC(sub_820FE5F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x820FE600;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r22,0
	ctx.r22.s64 = 0;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// mr r27,r22
	ctx.r27.u64 = ctx.r22.u64;
	// mr r28,r22
	ctx.r28.u64 = ctx.r22.u64;
	// mr r31,r22
	ctx.r31.u64 = ctx.r22.u64;
loc_820FE628:
	// li r11,1
	ctx.r11.s64 = 1;
	// slw r29,r11,r31
	ctx.r29.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// and. r11,r29,r26
	ctx.r11.u64 = ctx.r29.u64 & ctx.r26.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820fe640
	if (!ctx.cr0.eq) goto loc_820FE640;
	// std r22,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r22.u64);
	// b 0x820fe68c
	goto loc_820FE68C;
loc_820FE640:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5a00
	ctx.lr = 0x820FE648;
	sub_820B5A00(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x820fe660
	if (ctx.cr6.eq) goto loc_820FE660;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x820fe6b0
	if (!ctx.cr6.eq) goto loc_820FE6B0;
	// or r28,r29,r28
	ctx.r28.u64 = ctx.r29.u64 | ctx.r28.u64;
	// b 0x820fe674
	goto loc_820FE674;
loc_820FE660:
	// lwz r11,28(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 28);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x820fe6bc
	if (ctx.cr6.eq) goto loc_820FE6BC;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x820fe6bc
	if (ctx.cr6.eq) goto loc_820FE6BC;
loc_820FE674:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5ce0
	ctx.lr = 0x820FE680;
	sub_820B5CE0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x820fe6b0
	if (!ctx.cr0.eq) goto loc_820FE6B0;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_820FE68C:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// cmplwi cr6,r31,4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 4, ctx.xer);
	// blt cr6,0x820fe628
	if (ctx.cr6.lt) goto loc_820FE628;
	// stw r27,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r27.u32);
	// stw r28,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r28.u32);
loc_820FE6A4:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_820FE6B0:
	// lis r22,-32761
	ctx.r22.s64 = -2147024896;
	// ori r22,r22,1245
	ctx.r22.u64 = ctx.r22.u64 | 1245;
	// b 0x820fe6a4
	goto loc_820FE6A4;
loc_820FE6BC:
	// lis r22,-32747
	ctx.r22.s64 = -2146107392;
	// ori r22,r22,21001
	ctx.r22.u64 = ctx.r22.u64 | 21001;
	// b 0x820fe6a4
	goto loc_820FE6A4;
}
