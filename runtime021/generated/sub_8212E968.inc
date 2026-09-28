DEFINE_REX_FUNC(sub_8212E968) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8212E970;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x821347d8
	ctx.lr = 0x8212E97C;
	sub_821347D8(ctx, base);
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// addi r29,r11,2976
	ctx.r29.s64 = ctx.r11.s64 + 2976;
	// beq cr6,0x8212e9f4
	if (ctx.cr6.eq) goto loc_8212E9F4;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
	// bne cr6,0x8212e9a4
	if (!ctx.cr6.eq) goto loc_8212E9A4;
	// lbz r10,132(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 132);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8212e9b8
	if (!ctx.cr0.eq) goto loc_8212E9B8;
loc_8212E9A4:
	// cmpwi cr6,r31,2
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 2, ctx.xer);
	// bne cr6,0x8212e9d4
	if (!ctx.cr6.eq) goto loc_8212E9D4;
	// lbz r11,68(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 68);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212e9d4
	if (ctx.cr0.eq) goto loc_8212E9D4;
loc_8212E9B8:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x821347d8
	ctx.lr = 0x8212E9C0;
	sub_821347D8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821347d8
	ctx.lr = 0x8212E9CC;
	sub_821347D8(ctx, base);
	// cmpw cr6,r3,r30
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r30.s32, ctx.xer);
	// beq cr6,0x8212e9f4
	if (ctx.cr6.eq) goto loc_8212E9F4;
loc_8212E9D4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821347d8
	ctx.lr = 0x8212E9DC;
	sub_821347D8(ctx, base);
	// bl 0x820b6498
	ctx.lr = 0x8212E9E0;
	sub_820B6498(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8212e9f4
	if (!ctx.cr0.eq) goto loc_8212E9F4;
	// bl 0x820b6780
	ctx.lr = 0x8212E9EC;
	sub_820B6780(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x8212e9f8
	goto loc_8212E9F8;
loc_8212E9F4:
	// li r30,0
	ctx.r30.s64 = 0;
loc_8212E9F8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82134740
	ctx.lr = 0x8212EA00;
	sub_82134740(ctx, base);
	// srawi r11,r31,5
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r31.s32 >> 5;
	// rlwinm r10,r31,6,21,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 6) & 0x7C0;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwzx r11,r11,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stb r9,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, ctx.r9.u8);
	// beq cr6,0x8212ea34
	if (ctx.cr6.eq) goto loc_8212EA34;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82129550
	ctx.lr = 0x8212EA2C;
	sub_82129550(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8212ea38
	goto loc_8212EA38;
loc_8212EA34:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8212EA38:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
