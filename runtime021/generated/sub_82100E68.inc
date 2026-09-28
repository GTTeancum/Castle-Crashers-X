DEFINE_REX_FUNC(sub_82100E68) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x82100E70;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// lwz r11,420(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 420);
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82100ea4
	if (ctx.cr6.eq) goto loc_82100EA4;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,183
	ctx.r31.u64 = ctx.r31.u64 | 183;
	// b 0x82100f18
	goto loc_82100F18;
loc_82100EA4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210b0e8
	ctx.lr = 0x82100EAC;
	sub_8210B0E8(ctx, base);
	// mr. r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x82100ec0
	if (!ctx.cr0.eq) goto loc_82100EC0;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x82100f00
	goto loc_82100F00;
loc_82100EC0:
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8210a7a0
	ctx.lr = 0x82100ED8;
	sub_8210A7A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82100f00
	if (ctx.cr0.lt) goto loc_82100F00;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821005e8
	ctx.lr = 0x82100EE8;
	sub_821005E8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82100f00
	if (ctx.cr0.lt) goto loc_82100F00;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820ffb38
	ctx.lr = 0x82100EF8;
	sub_820FFB38(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge 0x82100f14
	if (!ctx.cr0.lt) goto loc_82100F14;
loc_82100F00:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82100f18
	if (ctx.cr6.eq) goto loc_82100F18;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8210b140
	ctx.lr = 0x82100F10;
	sub_8210B140(ctx, base);
	// b 0x82100f18
	goto loc_82100F18;
loc_82100F14:
	// stw r26,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r26.u32);
loc_82100F18:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
