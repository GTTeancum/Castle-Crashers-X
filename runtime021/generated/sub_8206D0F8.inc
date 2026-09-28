DEFINE_REX_FUNC(sub_8206D0F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8206D100;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32215
	ctx.r31.s64 = -2111242240;
	// lwz r10,48(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// li r30,1
	ctx.r30.s64 = 1;
	// lbz r9,2704(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 2704);
	// lhz r29,10(r10)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206d128
	if (ctx.cr6.eq) goto loc_8206D128;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// b 0x8206d160
	goto loc_8206D160;
loc_8206D128:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820b6818
	ctx.lr = 0x8206D134;
	sub_820B6818(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8206d15c
	if (!ctx.cr6.eq) goto loc_8206D15C;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206d15c
	if (ctx.cr6.eq) goto loc_8206D15C;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stb r10,2704(r31)
	REX_STORE_U8(ctx.r31.u32 + 2704, ctx.r10.u8);
	// b 0x8206d160
	goto loc_8206D160;
loc_8206D15C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8206D160:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// beq cr6,0x8206d1c4
	if (ctx.cr6.eq) goto loc_8206D1C4;
	// extsh r31,r29
	ctx.r31.s64 = ctx.r29.s16;
	// lwz r8,36(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// slw r9,r30,r31
	ctx.r9.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r31.u8 & 0x3F));
	// and r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ctx.r9.u64;
	// lwz r30,-6596(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + -6596);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8206d1f8
	if (ctx.cr6.eq) goto loc_8206D1F8;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5d50
	ctx.lr = 0x8206D1A8;
	sub_820B5D50(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8206d1f8
	if (!ctx.cr6.eq) goto loc_8206D1F8;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r10,r11,59644
	ctx.r10.u64 = ctx.r11.u64 | 59644;
	// stwx r31,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8206D1C4:
	// extsh r3,r29
	ctx.r3.s64 = ctx.r29.s16;
	// lwz r9,36(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// slw r10,r30,r3
	ctx.r10.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r3.u8 & 0x3F));
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8206d1f8
	if (ctx.cr6.eq) goto loc_8206D1F8;
	// lis r11,22593
	ctx.r11.s64 = 1480654848;
	// li r5,1
	ctx.r5.s64 = 1;
	// ori r10,r11,2231
	ctx.r10.u64 = ctx.r11.u64 | 2231;
	// li r6,0
	ctx.r6.s64 = 0;
	// rldimi r5,r10,32,0
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r5.u64 & 0xFFFFFFFF);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x820b5d50
	ctx.lr = 0x8206D1F8;
	sub_820B5D50(ctx, base);
loc_8206D1F8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
