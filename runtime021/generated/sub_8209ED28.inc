DEFINE_REX_FUNC(sub_8209ED28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x8209ED30;
	__savegprlr_25(ctx, base);
	// stwu r1,-704(r1)
	ea = -704 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// lwz r4,-6628(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8209ed64
	if (ctx.cr6.eq) goto loc_8209ED64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f1,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820a2150
	ctx.lr = 0x8209ED64;
	sub_820A2150(ctx, base);
loc_8209ED64:
	// cmplwi cr6,r31,64
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 64, ctx.xer);
	// blt cr6,0x8209ed94
	if (ctx.cr6.lt) goto loc_8209ED94;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,1612
	ctx.r3.s64 = ctx.r11.s64 + 1612;
	// bl 0x8208c5d8
	ctx.lr = 0x8209ED78;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r9,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r9.u32);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_8209ED94:
	// addi r11,r31,512
	ctx.r11.s64 = ctx.r31.s64 + 512;
	// rlwinm r25,r11,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r25,r26
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + ctx.r26.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8209edd4
	if (ctx.cr6.eq) goto loc_8209EDD4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r11,1664
	ctx.r3.s64 = ctx.r11.s64 + 1664;
	// bl 0x8208c5d8
	ctx.lr = 0x8209EDB8;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r9,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r9.u32);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_8209EDD4:
	// lbz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 4);
	// addi r11,r30,4
	ctx.r11.s64 = ctx.r30.s64 + 4;
	// cmplwi cr6,r10,47
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 47, ctx.xer);
	// beq cr6,0x8209edf4
	if (ctx.cr6.eq) goto loc_8209EDF4;
loc_8209EDE4:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,47
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 47, ctx.xer);
	// bne cr6,0x8209ede4
	if (!ctx.cr6.eq) goto loc_8209EDE4;
loc_8209EDF4:
	// addi r28,r11,1
	ctx.r28.s64 = ctx.r11.s64 + 1;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r11,1740
	ctx.r4.s64 = ctx.r11.s64 + 1740;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82127778
	ctx.lr = 0x8209EE0C;
	sub_82127778(ctx, base);
	// lbz r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 128);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// cmplwi cr6,r10,46
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 46, ctx.xer);
	// beq cr6,0x8209ee2c
	if (ctx.cr6.eq) goto loc_8209EE2C;
loc_8209EE1C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,46
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 46, ctx.xer);
	// bne cr6,0x8209ee1c
	if (!ctx.cr6.eq) goto loc_8209EE1C;
loc_8209EE2C:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r10,1444
	ctx.r30.s64 = ctx.r10.s64 + 1444;
	// stb r29,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r29.u8);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8209EE44:
	// lbz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8209ee44
	if (!ctx.cr6.eq) goto loc_8209EE44;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_8209EE58:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne cr6,0x8209ee58
	if (!ctx.cr6.eq) goto loc_8209EE58;
	// li r3,168
	ctx.r3.s64 = 168;
	// bl 0x820a7390
	ctx.lr = 0x8209EE78;
	sub_820A7390(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209ee8c
	if (ctx.cr6.eq) goto loc_8209EE8C;
	// bl 0x8209e270
	ctx.lr = 0x8209EE84;
	sub_8209E270(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8209ee90
	goto loc_8209EE90;
loc_8209EE8C:
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
loc_8209EE90:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209e448
	ctx.lr = 0x8209EEA0;
	sub_8209E448(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x8209ef6c
	if (!ctx.cr6.lt) goto loc_8209EF6C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r11,1756
	ctx.r4.s64 = ctx.r11.s64 + 1756;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82127778
	ctx.lr = 0x8209EEBC;
	sub_82127778(ctx, base);
	// lbz r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 128);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// cmplwi cr6,r10,46
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 46, ctx.xer);
	// beq cr6,0x8209eedc
	if (ctx.cr6.eq) goto loc_8209EEDC;
loc_8209EECC:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,46
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 46, ctx.xer);
	// bne cr6,0x8209eecc
	if (!ctx.cr6.eq) goto loc_8209EECC;
loc_8209EEDC:
	// stb r29,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r29.u8);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
loc_8209EEE8:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8209eee8
	if (!ctx.cr6.eq) goto loc_8209EEE8;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_8209EEFC:
	// lbz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stb r9,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x8209eefc
	if (!ctx.cr6.eq) goto loc_8209EEFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209e448
	ctx.lr = 0x8209EF24;
	sub_8209E448(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x8209ef6c
	if (!ctx.cr6.lt) goto loc_8209EF6C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r3,r11,1776
	ctx.r3.s64 = ctx.r11.s64 + 1776;
	// bl 0x8208c5d8
	ctx.lr = 0x8209EF40;
	sub_8208C5D8(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8209ef54
	if (ctx.cr6.eq) goto loc_8209EF54;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209ecb0
	ctx.lr = 0x8209EF54;
	sub_8209ECB0(ctx, base);
loc_8209EF54:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r29,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r29.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_8209EF6C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209e6c8
	ctx.lr = 0x8209EF74;
	sub_8209E6C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x8209efbc
	if (!ctx.cr6.lt) goto loc_8209EFBC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r3,r11,1808
	ctx.r3.s64 = ctx.r11.s64 + 1808;
	// bl 0x8208c5d8
	ctx.lr = 0x8209EF90;
	sub_8208C5D8(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8209ef54
	if (ctx.cr6.eq) goto loc_8209EF54;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209ecb0
	ctx.lr = 0x8209EFA4;
	sub_8209ECB0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r29,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r29.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_8209EFBC:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8209efd4
	if (ctx.cr6.eq) goto loc_8209EFD4;
	// bl 0x820b6498
	ctx.lr = 0x8209EFCC;
	sub_820B6498(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8209EFD4:
	// stwx r31,r25,r26
	REX_STORE_U32(ctx.r25.u32 + ctx.r26.u32, ctx.r31.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r29,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r29.u32);
	// stw r29,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r29.u32);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
