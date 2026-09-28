DEFINE_REX_FUNC(sub_82069578) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82069580;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r11,48(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// lhz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bge cr6,0x820696a0
	if (!ctx.cr6.lt) goto loc_820696A0;
	// lhz r11,10(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// extsh r31,r11
	ctx.r31.s64 = ctx.r11.s16;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,-6628(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// bl 0x820a39f0
	ctx.lr = 0x820695C0;
	sub_820A39F0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820695f8
	if (ctx.cr6.eq) goto loc_820695F8;
	// lwz r3,-6628(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// bl 0x820a3eb8
	ctx.lr = 0x820695D4;
	sub_820A3EB8(ctx, base);
	// cmplw cr6,r29,r3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x820696a0
	if (!ctx.cr6.lt) goto loc_820696A0;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lwz r4,-6628(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820a4038
	ctx.lr = 0x820695F0;
	sub_820A4038(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820695F8:
	// lhz r11,14(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820696a0
	if (ctx.cr6.eq) goto loc_820696A0;
	// lwz r4,-6628(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// li r9,1
	ctx.r9.s64 = 1;
	// slw r11,r9,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r31.u8 & 0x3F));
	// lwz r10,36(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 36);
	// and r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82069654
	if (ctx.cr6.eq) goto loc_82069654;
	// lwz r8,104(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 104);
	// and r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 & ctx.r11.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82069654
	if (ctx.cr6.eq) goto loc_82069654;
	// lwz r8,108(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 108);
	// and r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 & ctx.r11.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82069654
	if (ctx.cr6.eq) goto loc_82069654;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820a31a0
	ctx.lr = 0x8206964C;
	sub_820A31A0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82069654:
	// slw r11,r9,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r31.u8 & 0x3F));
	// and r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 & ctx.r10.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82069698
	if (ctx.cr6.eq) goto loc_82069698;
	// lwz r10,108(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 108);
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82069688
	if (ctx.cr6.eq) goto loc_82069688;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820b5d30
	ctx.lr = 0x82069680;
	sub_820B5D30(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82069688:
	// lis r4,64
	ctx.r4.s64 = 4194304;
	// bl 0x820b5d30
	ctx.lr = 0x82069690;
	sub_820B5D30(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82069698:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x820b5d30
	ctx.lr = 0x820696A0;
	sub_820B5D30(ctx, base);
loc_820696A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
