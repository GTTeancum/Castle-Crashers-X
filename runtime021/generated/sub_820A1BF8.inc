DEFINE_REX_FUNC(sub_820A1BF8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820A1C00;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r31,-6628(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// bl 0x820d7e90
	ctx.lr = 0x820A1C18;
	sub_820D7E90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x820a1c34
	if (ctx.cr6.eq) goto loc_820A1C34;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,3412
	ctx.r3.s64 = ctx.r11.s64 + 3412;
	// bl 0x8208c5d8
	ctx.lr = 0x820A1C30;
	sub_8208C5D8(ctx, base);
	// b 0x820a1d00
	goto loc_820A1D00;
loc_820A1C34:
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x820b6ca0
	ctx.lr = 0x820A1C3C;
	sub_820B6CA0(ctx, base);
	// stw r3,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a1cf4
	if (ctx.cr6.eq) goto loc_820A1CF4;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x820a1cf4
	if (ctx.cr6.eq) goto loc_820A1CF4;
	// bl 0x820fbf50
	ctx.lr = 0x820A1C54;
	sub_820FBF50(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a1c7c
	if (ctx.cr6.eq) goto loc_820A1C7C;
	// bl 0x820d7ea0
	ctx.lr = 0x820A1C60;
	sub_820D7EA0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_820A1C7C:
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r5,r31,12
	ctx.r5.s64 = ctx.r31.s64 + 12;
	// stw r29,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82104fd0
	ctx.lr = 0x820A1C94;
	sub_82104FD0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x820a1cbc
	if (!ctx.cr6.lt) goto loc_820A1CBC;
	// bl 0x820fbf60
	ctx.lr = 0x820A1CA0;
	sub_820FBF60(ctx, base);
	// bl 0x820d7ea0
	ctx.lr = 0x820A1CA4;
	sub_820D7EA0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r29,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r29.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_820A1CBC:
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a1cd0
	if (ctx.cr6.eq) goto loc_820A1CD0;
	// bl 0x820a7400
	ctx.lr = 0x820A1CCC;
	sub_820A7400(ctx, base);
	// stw r29,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
loc_820A1CD0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a1e50
	ctx.lr = 0x820A1CD8;
	sub_820A1E50(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r29,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stb r11,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r11.u8);
	// stw r29,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_820A1CF4:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,3456
	ctx.r3.s64 = ctx.r11.s64 + 3456;
	// bl 0x8208c5d8
	ctx.lr = 0x820A1D00;
	sub_8208C5D8(ctx, base);
loc_820A1D00:
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r9,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
