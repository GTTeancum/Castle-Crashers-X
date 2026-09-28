DEFINE_REX_FUNC(sub_82123858) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x82123860;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// li r4,312
	ctx.r4.s64 = 312;
	// li r3,9
	ctx.r3.s64 = 9;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
	// mr r27,r10
	ctx.r27.u64 = ctx.r10.u64;
	// bl 0x82108f48
	ctx.lr = 0x82123890;
	sub_82108F48(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x821238a4
	if (!ctx.cr0.eq) goto loc_821238A4;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x82123924
	goto loc_82123924;
loc_821238A4:
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x821236d0
	ctx.lr = 0x821238BC;
	sub_821236D0(ctx, base);
	// lwz r8,560(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 560);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r11,560(r31)
	REX_STORE_U32(ctx.r31.u32 + 560, ctx.r11.u32);
	// bne cr6,0x82123918
	if (!ctx.cr6.eq) goto loc_82123918;
	// ld r11,552(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 552);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// lwz r10,260(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 260);
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// clrldi r4,r11,5
	ctx.r4.u64 = ctx.r11.u64 & 0x7FFFFFFFFFFFFFF;
	// std r6,552(r31)
	REX_STORE_U64(ctx.r31.u32 + 552, ctx.r6.u64);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// bl 0x82126b08
	ctx.lr = 0x82123904;
	sub_82126B08(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge 0x82123918
	if (!ctx.cr0.lt) goto loc_82123918;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821180d8
	ctx.lr = 0x82123914;
	sub_821180D8(ctx, base);
	// b 0x82123924
	goto loc_82123924;
loc_82123918:
	// lwz r11,268(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 268);
	// li r31,0
	ctx.r31.s64 = 0;
	// stw r28,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
loc_82123924:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
