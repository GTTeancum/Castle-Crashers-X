DEFINE_REX_FUNC(sub_82055740) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82055748;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r30,1
	ctx.r30.s64 = 1;
	// lis r29,-32218
	ctx.r29.s64 = -2111438848;
	// lwz r11,-22668(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -22668);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6596(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + -6596);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820557b4
	if (!ctx.cr6.eq) goto loc_820557B4;
	// lwz r31,-6624(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + -6624);
	// addi r11,r31,84
	ctx.r11.s64 = ctx.r31.s64 + 84;
	// addi r11,r31,80
	ctx.r11.s64 = ctx.r31.s64 + 80;
	// lwz r6,84(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r5,80(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x820a0e98
	ctx.lr = 0x8205578C;
	sub_820A0E98(ctx, base);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r9,84(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r7,r11,r31
	ctx.r7.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stb r30,88(r7)
	REX_STORE_U8(ctx.r7.u32 + 88, ctx.r30.u8);
	// stb r30,76(r31)
	REX_STORE_U8(ctx.r31.u32 + 76, ctx.r30.u8);
	// b 0x820557d4
	goto loc_820557D4;
loc_820557B4:
	// lwz r11,48(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// lhz r9,10(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// bl 0x820a0988
	ctx.lr = 0x820557C4;
	sub_820A0988(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r8,5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 5, ctx.xer);
	// bne cr6,0x820557d4
	if (!ctx.cr6.eq) goto loc_820557D4;
	// li r30,0
	ctx.r30.s64 = 0;
loc_820557D4:
	// clrlwi r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82055808
	if (ctx.cr6.eq) goto loc_82055808;
	// lwz r11,48(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// li r6,97
	ctx.r6.s64 = 97;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6624(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -6624);
	// lhz r10,10(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// extsh r5,r10
	ctx.r5.s64 = ctx.r10.s16;
	// bl 0x82077310
	ctx.lr = 0x820557FC;
	sub_82077310(ctx, base);
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82053bc8
	ctx.lr = 0x82055808;
	sub_82053BC8(ctx, base);
loc_82055808:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
