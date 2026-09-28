DEFINE_REX_FUNC(sub_82105878) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82105880;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r10,r29,524
	ctx.r10.s64 = ctx.r29.s64 + 524;
	// lwz r11,524(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 524);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82105a10
	if (ctx.cr6.eq) goto loc_82105A10;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82105a10
	if (ctx.cr0.eq) goto loc_82105A10;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r31,r11,-4
	ctx.r31.s64 = ctx.r11.s64 + -4;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// beq cr6,0x821058bc
	if (ctx.cr6.eq) goto loc_821058BC;
	// mr r28,r9
	ctx.r28.u64 = ctx.r9.u64;
loc_821058BC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210bcd8
	ctx.lr = 0x821058C4;
	sub_8210BCD8(ctx, base);
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// ori r11,r11,997
	ctx.r11.u64 = ctx.r11.u64 | 997;
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82105a10
	if (ctx.cr6.eq) goto loc_82105A10;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bl 0x8210be88
	ctx.lr = 0x82105900;
	sub_8210BE88(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82105918
	if (ctx.cr6.eq) goto loc_82105918;
	// addi r3,r28,-4
	ctx.r3.s64 = ctx.r28.s64 + -4;
	// lwz r4,32(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// bl 0x8210bc60
	ctx.lr = 0x82105914;
	sub_8210BC60(ctx, base);
	// b 0x82105a10
	goto loc_82105A10;
loc_82105918:
	// lwz r11,20(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x82105990
	if (!ctx.cr6.eq) goto loc_82105990;
	// lwz r11,196(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 196);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82105a10
	if (!ctx.cr6.eq) goto loc_82105A10;
	// std r30,200(r29)
	REX_STORE_U64(ctx.r29.u32 + 200, ctx.r30.u64);
	// addi r31,r29,200
	ctx.r31.s64 = ctx.r29.s64 + 200;
	// std r30,208(r29)
	REX_STORE_U64(ctx.r29.u32 + 208, ctx.r30.u64);
	// std r30,216(r29)
	REX_STORE_U64(ctx.r29.u32 + 216, ctx.r30.u64);
	// stw r30,224(r29)
	REX_STORE_U32(ctx.r29.u32 + 224, ctx.r30.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,32(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// bl 0x82138da0
	ctx.lr = 0x82105950;
	sub_82138DA0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82105984
	if (ctx.cr0.eq) goto loc_82105984;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x82105984
	if (ctx.cr6.eq) goto loc_82105984;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82136e38
	ctx.lr = 0x82105968;
	sub_82136E38(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt 0x82105978
	if (ctx.cr0.lt) goto loc_82105978;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// ori r4,r4,16389
	ctx.r4.u64 = ctx.r4.u64 | 16389;
loc_82105978:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821052e8
	ctx.lr = 0x82105980;
	sub_821052E8(ctx, base);
	// b 0x82105a10
	goto loc_82105A10;
loc_82105984:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,21224
	ctx.r11.s64 = ctx.r11.s64 + 21224;
	// b 0x82105a0c
	goto loc_82105A0C;
loc_82105990:
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// bne cr6,0x82105a10
	if (!ctx.cr6.eq) goto loc_82105A10;
	// lwz r11,196(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 196);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82105a10
	if (!ctx.cr6.eq) goto loc_82105A10;
	// lwz r11,720(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 720);
	// addi r31,r29,200
	ctx.r31.s64 = ctx.r29.s64 + 200;
	// oris r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 524288;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r11,720(r29)
	REX_STORE_U32(ctx.r29.u32 + 720, ctx.r11.u32);
	// std r30,200(r29)
	REX_STORE_U64(ctx.r29.u32 + 200, ctx.r30.u64);
	// std r30,208(r29)
	REX_STORE_U64(ctx.r29.u32 + 208, ctx.r30.u64);
	// std r30,216(r29)
	REX_STORE_U64(ctx.r29.u32 + 216, ctx.r30.u64);
	// stw r30,224(r29)
	REX_STORE_U32(ctx.r29.u32 + 224, ctx.r30.u32);
	// lwz r3,32(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// bl 0x821388e0
	ctx.lr = 0x821059D0;
	sub_821388E0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82105a04
	if (ctx.cr0.eq) goto loc_82105A04;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x82105a04
	if (ctx.cr6.eq) goto loc_82105A04;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82136e38
	ctx.lr = 0x821059E8;
	sub_82136E38(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt 0x821059f8
	if (ctx.cr0.lt) goto loc_821059F8;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// ori r4,r4,16389
	ctx.r4.u64 = ctx.r4.u64 | 16389;
loc_821059F8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82101348
	ctx.lr = 0x82105A00;
	sub_82101348(ctx, base);
	// b 0x82105a10
	goto loc_82105A10;
loc_82105A04:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,4936
	ctx.r11.s64 = ctx.r11.s64 + 4936;
loc_82105A0C:
	// stw r11,196(r29)
	REX_STORE_U32(ctx.r29.u32 + 196, ctx.r11.u32);
loc_82105A10:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
