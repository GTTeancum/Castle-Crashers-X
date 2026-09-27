DEFINE_REX_FUNC(sub_8208C6E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8208C6E8;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82079a00
	ctx.lr = 0x8208C6F4;
	sub_82079A00(ctx, base);
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r27,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r27.u32);
	// beq cr6,0x8208c71c
	if (ctx.cr6.eq) goto loc_8208C71C;
	// stw r27,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r27.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,76(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// bl 0x82066ea8
	ctx.lr = 0x8208C718;
	sub_82066EA8(ctx, base);
	// stw r27,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r27.u32);
loc_8208C71C:
	// lbz r10,86(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 86);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 136);
	// clrlwi r8,r10,28
	ctx.r8.u64 = ctx.r10.u32 & 0xF;
	// sth r27,82(r31)
	REX_STORE_U16(ctx.r31.u32 + 82, ctx.r27.u16);
	// sth r9,84(r31)
	REX_STORE_U16(ctx.r31.u32 + 84, ctx.r9.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stb r8,86(r31)
	REX_STORE_U8(ctx.r31.u32 + 86, ctx.r8.u8);
	// stw r27,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r27.u32);
	// stw r27,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r27.u32);
	// beq cr6,0x8208c784
	if (ctx.cr6.eq) goto loc_8208C784;
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8208c780
	if (!ctx.cr6.gt) goto loc_8208C780;
	// addi r30,r31,104
	ctx.r30.s64 = ctx.r31.s64 + 104;
	// lis r28,-32218
	ctx.r28.s64 = -2111438848;
loc_8208C75C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6612(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + -6612);
	// lhz r5,0(r30)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// bl 0x82096e50
	ctx.lr = 0x8208C76C;
	sub_82096E50(ctx, base);
	// lbz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 136);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8208c75c
	if (ctx.cr6.lt) goto loc_8208C75C;
loc_8208C780:
	// stb r27,136(r31)
	REX_STORE_U8(ctx.r31.u32 + 136, ctx.r27.u8);
loc_8208C784:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
