DEFINE_REX_FUNC(sub_8211E770) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8211E778;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r3,r31,40
	ctx.r3.s64 = ctx.r31.s64 + 40;
	// bl 0x8214a434
	ctx.lr = 0x8211E78C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,1148(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwinm r10,r10,0,5,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFF7FFFFFF;
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// stw r10,1148(r31)
	REX_STORE_U32(ctx.r31.u32 + 1148, ctx.r10.u32);
	// lwz r30,1024(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 1024);
	// stw r11,1024(r31)
	REX_STORE_U32(ctx.r31.u32 + 1024, ctx.r11.u32);
	// beq cr6,0x8211e7e0
	if (ctx.cr6.eq) goto loc_8211E7E0;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge cr6,0x8211e7ec
	if (!ctx.cr6.lt) goto loc_8211E7EC;
	// lwz r10,132(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8211e7ec
	if (ctx.cr6.eq) goto loc_8211E7EC;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r29,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
	// stb r11,1145(r31)
	REX_STORE_U8(ctx.r31.u32 + 1145, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// stb r11,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r11.u8);
	// bl 0x8211a3b8
	ctx.lr = 0x8211E7E0;
	sub_8211A3B8(ctx, base);
loc_8211E7E0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821180d8
	ctx.lr = 0x8211E7E8;
	sub_821180D8(ctx, base);
	// b 0x8211e854
	goto loc_8211E854;
loc_8211E7EC:
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// lbz r3,2(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// bl 0x82120778
	ctx.lr = 0x8211E7F8;
	sub_82120778(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// ble cr6,0x8211e848
	if (!ctx.cr6.gt) goto loc_8211E848;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// beq cr6,0x8211e7e0
	if (ctx.cr6.eq) goto loc_8211E7E0;
	// cmpwi cr6,r3,5
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 5, ctx.xer);
	// beq cr6,0x8211e838
	if (ctx.cr6.eq) goto loc_8211E838;
	// cmpwi cr6,r3,6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 6, ctx.xer);
	// beq cr6,0x8211e7e0
	if (ctx.cr6.eq) goto loc_8211E7E0;
	// cmpwi cr6,r3,7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 7, ctx.xer);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x8211e830
	if (ctx.cr6.eq) goto loc_8211E830;
	// bl 0x8211ba60
	ctx.lr = 0x8211E82C;
	sub_8211BA60(ctx, base);
	// b 0x8211e854
	goto loc_8211E854;
loc_8211E830:
	// bl 0x8211bb58
	ctx.lr = 0x8211E834;
	sub_8211BB58(ctx, base);
	// b 0x8211e854
	goto loc_8211E854;
loc_8211E838:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211a0f0
	ctx.lr = 0x8211E844;
	sub_8211A0F0(ctx, base);
	// b 0x8211e854
	goto loc_8211E854;
loc_8211E848:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211ba00
	ctx.lr = 0x8211E854;
	sub_8211BA00(ctx, base);
loc_8211E854:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211c7f8
	ctx.lr = 0x8211E85C;
	sub_8211C7F8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821180d8
	ctx.lr = 0x8211E864;
	sub_821180D8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
