DEFINE_REX_FUNC(sub_820A49E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820A49E8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a4a48
	if (ctx.cr6.eq) goto loc_820A4A48;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// stw r31,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r31.u32);
	// lbz r10,-22601(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820a4a2c
	if (!ctx.cr6.eq) goto loc_820A4A2C;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r3,r11,-1768
	ctx.r3.s64 = ctx.r11.s64 + -1768;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820A4A2C;
	sub_820A71E8(ctx, base);
loc_820A4A2C:
	// bl 0x820b5eb8
	ctx.lr = 0x820A4A30;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820A4A48;
	sub_8209BF18(ctx, base);
loc_820A4A48:
	// lis r10,-32234
	ctx.r10.s64 = -2112487424;
	// stb r31,28(r30)
	REX_STORE_U8(ctx.r30.u32 + 28, ctx.r31.u8);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r31,1184(r30)
	REX_STORE_U8(ctx.r30.u32 + 1184, ctx.r31.u8);
	// stb r31,1185(r30)
	REX_STORE_U8(ctx.r30.u32 + 1185, ctx.r31.u8);
	// li r29,4
	ctx.r29.s64 = 4;
	// stb r31,1374(r30)
	REX_STORE_U8(ctx.r30.u32 + 1374, ctx.r31.u8);
	// lis r28,-32218
	ctx.r28.s64 = -2111438848;
	// stb r31,1375(r30)
	REX_STORE_U8(ctx.r30.u32 + 1375, ctx.r31.u8);
	// stb r31,1376(r30)
	REX_STORE_U8(ctx.r30.u32 + 1376, ctx.r31.u8);
	// stw r31,120(r30)
	REX_STORE_U32(ctx.r30.u32 + 120, ctx.r31.u32);
	// stb r31,1377(r30)
	REX_STORE_U8(ctx.r30.u32 + 1377, ctx.r31.u8);
	// stb r11,1372(r30)
	REX_STORE_U8(ctx.r30.u32 + 1372, ctx.r11.u8);
	// stb r11,1373(r30)
	REX_STORE_U8(ctx.r30.u32 + 1373, ctx.r11.u8);
	// li r30,188
	ctx.r30.s64 = 188;
	// stb r11,-28146(r10)
	REX_STORE_U8(ctx.r10.u32 + -28146, ctx.r11.u8);
loc_820A4A88:
	// addi r10,r30,4
	ctx.r10.s64 = ctx.r30.s64 + 4;
	// lwz r11,-6624(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -6624);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r10,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x820A4AA0;
	sub_82052EA8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// sth r30,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r30.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-6624(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// stw r31,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r31.u32);
	// bl 0x82052ea8
	ctx.lr = 0x820A4ABC;
	sub_82052EA8(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stw r31,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// bne 0x820a4a88
	if (!ctx.cr0.eq) goto loc_820A4A88;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
