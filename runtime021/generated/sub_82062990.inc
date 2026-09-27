DEFINE_REX_FUNC(sub_82062990) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82062998;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lis r31,-32215
	ctx.r31.s64 = -2111242240;
	// lwz r10,48(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// lbz r9,2704(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 2704);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r30,44(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// beq cr6,0x820629c0
	if (ctx.cr6.eq) goto loc_820629C0;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820629f8
	goto loc_820629F8;
loc_820629C0:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820b6818
	ctx.lr = 0x820629CC;
	sub_820B6818(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820629f4
	if (!ctx.cr6.eq) goto loc_820629F4;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820629f4
	if (ctx.cr6.eq) goto loc_820629F4;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r10,2704(r31)
	REX_STORE_U8(ctx.r31.u32 + 2704, ctx.r10.u8);
	// b 0x820629f8
	goto loc_820629F8;
loc_820629F4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_820629F8:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// beq cr6,0x82062a2c
	if (ctx.cr6.eq) goto loc_82062A2C;
	// li r4,601
	ctx.r4.s64 = 601;
	// bl 0x82067230
	ctx.lr = 0x82062A14;
	sub_82067230(ctx, base);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// stw r29,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r29.u32);
	// addi r10,r11,20488
	ctx.r10.s64 = ctx.r11.s64 + 20488;
	// stw r10,28(r30)
	REX_STORE_U32(ctx.r30.u32 + 28, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82062A2C:
	// li r4,600
	ctx.r4.s64 = 600;
	// bl 0x82067230
	ctx.lr = 0x82062A34;
	sub_82067230(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r29,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r29.u32);
	// addi r10,r11,21016
	ctx.r10.s64 = ctx.r11.s64 + 21016;
	// stw r10,28(r30)
	REX_STORE_U32(ctx.r30.u32 + 28, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
