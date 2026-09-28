DEFINE_REX_FUNC(sub_8211B690) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8211B698;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// bl 0x82136f58
	ctx.lr = 0x8211B6A8;
	sub_82136F58(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// subf r4,r29,r30
	ctx.r4.u64 = ctx.r30.u64 - ctx.r29.u64;
	// bl 0x82124e98
	ctx.lr = 0x8211B6BC;
	sub_82124E98(ctx, base);
	// stw r30,468(r31)
	REX_STORE_U32(ctx.r31.u32 + 468, ctx.r30.u32);
	// stw r30,464(r31)
	REX_STORE_U32(ctx.r31.u32 + 464, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,1028(r31)
	REX_STORE_U32(ctx.r31.u32 + 1028, ctx.r30.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211ae00
	ctx.lr = 0x8211B6D8;
	sub_8211AE00(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8211b6f0
	if (ctx.cr0.eq) goto loc_8211B6F0;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r31,356
	ctx.r3.s64 = ctx.r31.s64 + 356;
	// bl 0x82122270
	ctx.lr = 0x8211B6F0;
	sub_82122270(ctx, base);
loc_8211B6F0:
	// li r10,1
	ctx.r10.s64 = 1;
	// lbz r11,1144(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1144);
	// lwz r9,1148(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// li r8,250
	ctx.r8.s64 = 250;
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// andi. r11,r11,250
	ctx.r11.u64 = ctx.r11.u64 & 250;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// oris r10,r9,1024
	ctx.r10.u64 = ctx.r9.u64 | 67108864;
	// stb r8,1145(r31)
	REX_STORE_U8(ctx.r31.u32 + 1145, ctx.r8.u8);
	// stb r11,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r11.u8);
	// addi r3,r31,176
	ctx.r3.s64 = ctx.r31.s64 + 176;
	// stw r10,1148(r31)
	REX_STORE_U32(ctx.r31.u32 + 1148, ctx.r10.u32);
	// bl 0x82122310
	ctx.lr = 0x8211B720;
	sub_82122310(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
