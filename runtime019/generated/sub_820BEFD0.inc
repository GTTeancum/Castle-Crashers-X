DEFINE_REX_FUNC(sub_820BEFD0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820BEFD8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// li r3,24064
	ctx.r3.s64 = 24064;
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// bl 0x820bef80
	ctx.lr = 0x820BF000;
	sub_820BEF80(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x820bf014
	if (!ctx.cr0.eq) goto loc_820BF014;
loc_820BF008:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x820bf09c
	goto loc_820BF09C;
loc_820BF014:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cc088
	ctx.lr = 0x820BF01C;
	sub_820CC088(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x820bf034
	if (!ctx.cr0.eq) goto loc_820BF034;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// lwz r3,-4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -4);
	// bl 0x82136708
	ctx.lr = 0x820BF030;
	sub_82136708(ctx, base);
	// b 0x820bf008
	goto loc_820BF008;
loc_820BF034:
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// bne cr6,0x820bf06c
	if (!ctx.cr6.eq) goto loc_820BF06C;
	// lbz r11,10940(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10940);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r11,r11,128
	ctx.r11.u64 = ctx.r11.u64 | 128;
	// stb r11,10940(r31)
	REX_STORE_U8(ctx.r31.u32 + 10940, ctx.r11.u8);
	// bl 0x820c6218
	ctx.lr = 0x820BF050;
	sub_820C6218(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cc318
	ctx.lr = 0x820BF058;
	sub_820CC318(ctx, base);
loc_820BF058:
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x820bf094
	if (!ctx.cr0.eq) goto loc_820BF094;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820beca0
	ctx.lr = 0x820BF068;
	sub_820BECA0(ctx, base);
	// b 0x820bf008
	goto loc_820BF008;
loc_820BF06C:
	// rlwinm. r11,r30,0,23,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820bf080
	if (!ctx.cr0.eq) goto loc_820BF080;
	// rlwinm. r11,r30,0,2,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x3F000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820bf080
	if (!ctx.cr0.eq) goto loc_820BF080;
	// oris r30,r30,3072
	ctx.r30.u64 = ctx.r30.u64 | 201326592;
loc_820BF080:
	// stw r30,23980(r31)
	REX_STORE_U32(ctx.r31.u32 + 23980, ctx.r30.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cc100
	ctx.lr = 0x820BF090;
	sub_820CC100(ctx, base);
	// b 0x820bf058
	goto loc_820BF058;
loc_820BF094:
	// stw r31,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r31.u32);
	// li r3,0
	ctx.r3.s64 = 0;
loc_820BF09C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
