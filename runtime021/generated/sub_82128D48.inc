DEFINE_REX_FUNC(sub_82128D48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x82128D50;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
	// beq cr6,0x82128dd4
	if (ctx.cr6.eq) goto loc_82128DD4;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82128ddc
	if (ctx.cr6.eq) goto loc_82128DDC;
loc_82128D80:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82128d8c
	if (ctx.cr6.eq) goto loc_82128D8C;
	// stb r28,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
loc_82128D8C:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82128d98
	if (ctx.cr6.eq) goto loc_82128D98;
	// stw r28,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r28.u32);
loc_82128D98:
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bgt cr6,0x82128da8
	if (ctx.cr6.gt) goto loc_82128DA8;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
loc_82128DA8:
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82128a78
	ctx.lr = 0x82128DB4;
	sub_82128A78(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x82128e08
	if (!ctx.cr6.eq) goto loc_82128E08;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82128dc8
	if (ctx.cr6.eq) goto loc_82128DC8;
	// stb r28,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
loc_82128DC8:
	// bl 0x821294e0
	ctx.lr = 0x82128DCC;
	sub_821294E0(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82128e7c
	goto loc_82128E7C;
loc_82128DD4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82128d80
	if (ctx.cr6.eq) goto loc_82128D80;
loc_82128DDC:
	// bl 0x821294e0
	ctx.lr = 0x82128DE0;
	sub_821294E0(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212c298
	ctx.lr = 0x82128E00;
	sub_8212C298(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x82128e7c
	goto loc_82128E7C;
loc_82128E08:
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82128e6c
	if (ctx.cr6.eq) goto loc_82128E6C;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// ble cr6,0x82128e64
	if (!ctx.cr6.gt) goto loc_82128E64;
	// cmpwi cr6,r29,-1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, -1, ctx.xer);
	// beq cr6,0x82128e5c
	if (ctx.cr6.eq) goto loc_82128E5C;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// stb r28,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// bgt cr6,0x82128e5c
	if (ctx.cr6.gt) goto loc_82128E5C;
	// bl 0x821294e0
	ctx.lr = 0x82128E34;
	sub_821294E0(ctx, base);
	// li r11,34
	ctx.r11.s64 = 34;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212c298
	ctx.lr = 0x82128E54;
	sub_8212C298(ctx, base);
	// li r3,34
	ctx.r3.s64 = 34;
	// b 0x82128e7c
	goto loc_82128E7C;
loc_82128E5C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// li r27,80
	ctx.r27.s64 = 80;
loc_82128E64:
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stb r28,-1(r10)
	REX_STORE_U8(ctx.r10.u32 + -1, ctx.r28.u8);
loc_82128E6C:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82128e78
	if (ctx.cr6.eq) goto loc_82128E78;
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
loc_82128E78:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_82128E7C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
