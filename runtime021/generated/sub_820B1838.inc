DEFINE_REX_FUNC(sub_820B1838) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820B1840;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r9,16383
	ctx.r9.s64 = 1073676288;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,255
	ctx.r10.s64 = 255;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r7,r9,65535
	ctx.r7.u64 = ctx.r9.u64 | 65535;
	// stw r4,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r4.u32);
	// stw r5,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r5.u32);
	// rlwinm r28,r6,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r5,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r5.u32);
	// cmplw cr6,r6,r7
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, ctx.xer);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// stw r6,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r6.u32);
	// stw r8,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r8.u32);
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r6,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r6.u32);
	// stb r11,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r11.u8);
	// stb r11,13(r31)
	REX_STORE_U8(ctx.r31.u32 + 13, ctx.r11.u8);
	// stb r11,14(r31)
	REX_STORE_U8(ctx.r31.u32 + 14, ctx.r11.u8);
	// stb r10,15(r31)
	REX_STORE_U8(ctx.r31.u32 + 15, ctx.r10.u8);
	// stb r11,4(r31)
	REX_STORE_U8(ctx.r31.u32 + 4, ctx.r11.u8);
	// stb r11,5(r31)
	REX_STORE_U8(ctx.r31.u32 + 5, ctx.r11.u8);
	// stb r11,6(r31)
	REX_STORE_U8(ctx.r31.u32 + 6, ctx.r11.u8);
	// stb r10,7(r31)
	REX_STORE_U8(ctx.r31.u32 + 7, ctx.r10.u8);
	// ble cr6,0x820b18ac
	if (!ctx.cr6.gt) goto loc_820B18AC;
	// li r28,-1
	ctx.r28.s64 = -1;
loc_820B18AC:
	// lis r29,-32215
	ctx.r29.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r27,r11,-1768
	ctx.r27.s64 = ctx.r11.s64 + -1768;
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b18d8
	if (!ctx.cr6.eq) goto loc_820B18D8;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820B18D8;
	sub_820A71E8(ctx, base);
loc_820B18D8:
	// bl 0x820b5eb8
	ctx.lr = 0x820B18DC;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r11,29632
	ctx.r30.s64 = ctx.r11.s64 + 29632;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwzx r3,r10,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820B18F4;
	sub_8209BDD8(ctx, base);
	// lwz r9,60(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82129fa0
	ctx.lr = 0x820B1908;
	sub_82129FA0(ctx, base);
	// lwz r6,60(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lbz r7,-22601(r29)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r8,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r8.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r6,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r6.u32);
	// bne cr6,0x820b1938
	if (!ctx.cr6.eq) goto loc_820B1938;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820B1938;
	sub_820A71E8(ctx, base);
loc_820B1938:
	// bl 0x820b5eb8
	ctx.lr = 0x820B193C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r4,12
	ctx.r4.s64 = 786432;
	// ori r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 32768;
	// lwzx r3,r11,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820B1950;
	sub_8209BDD8(ctx, base);
	// stw r3,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
	// stw r3,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
