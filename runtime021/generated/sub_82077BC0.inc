DEFINE_REX_FUNC(sub_82077BC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82077BC8;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// bl 0x82077fd8
	ctx.lr = 0x82077BDC;
	sub_82077FD8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82077c04
	if (ctx.cr6.lt) goto loc_82077C04;
	// mulli r11,r3,76
	ctx.r11.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(76));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r10,r11,208
	ctx.r10.s64 = ctx.r11.s64 + 208;
	// lhz r10,208(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 208);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,208(r11)
	REX_STORE_U16(ctx.r11.u32 + 208, ctx.r10.u16);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82077C04:
	// addi r30,r31,40
	ctx.r30.s64 = ctx.r31.s64 + 40;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82078280
	ctx.lr = 0x82077C10;
	sub_82078280(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x82077c40
	if (ctx.cr6.eq) goto loc_82077C40;
	// stw r28,1668(r31)
	REX_STORE_U32(ctx.r31.u32 + 1668, ctx.r28.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82078280
	ctx.lr = 0x82077C28;
	sub_82078280(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// bl 0x820757c8
	ctx.lr = 0x82077C40;
	sub_820757C8(ctx, base);
loc_82077C40:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-8185
	ctx.r4.s64 = ctx.r11.s64 + -8185;
	// bl 0x82053a00
	ctx.lr = 0x82077C50;
	sub_82053A00(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82077fd8
	ctx.lr = 0x82077C5C;
	sub_82077FD8(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// mulli r11,r27,76
	ctx.r11.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(76));
	// add r30,r11,r31
	ctx.r30.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r4,r29,4
	ctx.r4.s64 = ctx.r29.s64 + 4;
	// addi r28,r30,140
	ctx.r28.s64 = ctx.r30.s64 + 140;
	// addi r3,r28,4
	ctx.r3.s64 = ctx.r28.s64 + 4;
	// sth r10,208(r30)
	REX_STORE_U16(ctx.r30.u32 + 208, ctx.r10.u16);
	// lwz r5,0(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x82129a70
	ctx.lr = 0x82077C84;
	sub_82129A70(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// add r9,r11,r28
	ctx.r9.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r11,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,4(r9)
	REX_STORE_U8(ctx.r9.u32 + 4, ctx.r10.u8);
	// stw r10,136(r30)
	REX_STORE_U32(ctx.r30.u32 + 136, ctx.r10.u32);
	// lhz r8,1664(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 1664);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82077cd8
	if (!ctx.cr6.eq) goto loc_82077CD8;
	// lwz r11,1776(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1776);
	// sth r27,1664(r31)
	REX_STORE_U16(ctx.r31.u32 + 1664, ctx.r27.u16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82077cd8
	if (!ctx.cr6.eq) goto loc_82077CD8;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// stb r10,1772(r31)
	REX_STORE_U8(ctx.r31.u32 + 1772, ctx.r10.u8);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,1776(r31)
	REX_STORE_U32(ctx.r31.u32 + 1776, ctx.r9.u32);
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82077cd8
	if (ctx.cr6.eq) goto loc_82077CD8;
	// stb r10,1375(r11)
	REX_STORE_U8(ctx.r11.u32 + 1375, ctx.r10.u8);
loc_82077CD8:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
