DEFINE_REX_FUNC(sub_820696A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820696B0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r11,48(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// lhz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// mr r30,r10
	ctx.r30.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bge cr6,0x82069760
	if (!ctx.cr6.lt) goto loc_82069760;
	// lhz r11,10(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// lis r31,-32218
	ctx.r31.s64 = -2111438848;
	// extsh r28,r11
	ctx.r28.s64 = ctx.r11.s16;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,-6628(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
	// bl 0x820a39f0
	ctx.lr = 0x820696F0;
	sub_820A39F0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82069760
	if (ctx.cr6.eq) goto loc_82069760;
	// lwz r3,-6628(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
	// bl 0x820a3eb8
	ctx.lr = 0x82069704;
	sub_820A3EB8(ctx, base);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// lwz r3,-6628(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
	// bge cr6,0x8206973c
	if (!ctx.cr6.lt) goto loc_8206973C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x820a3c28
	ctx.lr = 0x82069718;
	sub_820A3C28(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82069760
	if (!ctx.cr6.eq) goto loc_82069760;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r4,-6628(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820a3448
	ctx.lr = 0x82069734;
	sub_820A3448(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8206973C:
	// bl 0x820a3eb8
	ctx.lr = 0x82069740;
	sub_820A3EB8(ctx, base);
	// lhz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 16);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x82069760
	if (!ctx.cr6.gt) goto loc_82069760;
	// lhz r11,14(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 14);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82069760
	if (ctx.cr6.eq) goto loc_82069760;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820b5d38
	ctx.lr = 0x82069760;
	sub_820B5D38(ctx, base);
loc_82069760:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
