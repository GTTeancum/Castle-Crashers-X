DEFINE_REX_FUNC(sub_82104C20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82104C28;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82104c7c
	if (ctx.cr6.eq) goto loc_82104C7C;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r10,r10,19928
	ctx.r10.s64 = ctx.r10.s64 + 19928;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82104c5c
	if (ctx.cr6.eq) goto loc_82104C5C;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r10,r10,7552
	ctx.r10.s64 = ctx.r10.s64 + 7552;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82104c70
	if (!ctx.cr6.eq) goto loc_82104C70;
loc_82104C5C:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// li r3,0
	ctx.r3.s64 = 0;
	// ori r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 64;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// b 0x82104d5c
	goto loc_82104D5C;
loc_82104C70:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,170
	ctx.r3.u64 = ctx.r3.u64 | 170;
	// b 0x82104d5c
	goto loc_82104D5C;
loc_82104C7C:
	// li r8,0
	ctx.r8.s64 = 0;
	// ld r5,40(r31)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82138c30
	ctx.lr = 0x82104C98;
	sub_82138C30(ctx, base);
	// cmplwi cr6,r3,122
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 122, ctx.xer);
	// beq cr6,0x82104cb4
	if (ctx.cr6.eq) goto loc_82104CB4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82136e38
	ctx.lr = 0x82104CA8;
	sub_82136E38(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82104d5c
	if (ctx.cr0.lt) goto loc_82104D5C;
	// b 0x82104cc0
	goto loc_82104CC0;
loc_82104CB4:
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82104ccc
	if (!ctx.cr6.eq) goto loc_82104CCC;
loc_82104CC0:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// b 0x82104d5c
	goto loc_82104D5C;
loc_82104CCC:
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82108f48
	ctx.lr = 0x82104CD4;
	sub_82108F48(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r3.u32);
	// bne 0x82104cec
	if (!ctx.cr0.eq) goto loc_82104CEC;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x82104d5c
	goto loc_82104D5C;
loc_82104CEC:
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r31,200
	ctx.r30.s64 = ctx.r31.s64 + 200;
	// std r29,200(r31)
	REX_STORE_U64(ctx.r31.u32 + 200, ctx.r29.u64);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// std r29,208(r31)
	REX_STORE_U64(ctx.r31.u32 + 208, ctx.r29.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r29,216(r31)
	REX_STORE_U64(ctx.r31.u32 + 216, ctx.r29.u64);
	// stw r29,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r29.u32);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// lwz r7,184(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// ld r5,40(r31)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82138c30
	ctx.lr = 0x82104D20;
	sub_82138C30(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82104d4c
	if (ctx.cr0.eq) goto loc_82104D4C;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x82104d4c
	if (ctx.cr6.eq) goto loc_82104D4C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82136e38
	ctx.lr = 0x82104D38;
	sub_82136E38(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82104d5c
	if (ctx.cr0.lt) goto loc_82104D5C;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x82104d5c
	goto loc_82104D5C;
loc_82104D4C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r11,r11,14584
	ctx.r11.s64 = ctx.r11.s64 + 14584;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
loc_82104D5C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
