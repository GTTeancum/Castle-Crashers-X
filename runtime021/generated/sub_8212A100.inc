DEFINE_REX_FUNC(sub_8212A100) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8212A108;
	__savegprlr_28(ctx, base);
	// addi r31,r1,-128
	ctx.r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// stw r28,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r28.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8212f458
	ctx.lr = 0x8212A124;
	sub_8212F458(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,23228(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 23228);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8212a1d8
	if (ctx.cr6.eq) goto loc_8212A1D8;
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// lwz r11,23224(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 23224);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8212a150
	if (!ctx.cr6.eq) goto loc_8212A150;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8214a954
	ctx.lr = 0x8212A150;
	__imp__KeBugCheck(ctx, base);
loc_8212A150:
	// lis r8,-32221
	ctx.r8.s64 = -2111635456;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,23224(r9)
	REX_STORE_U32(ctx.r9.u32 + 23224, ctx.r11.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stb r28,23220(r8)
	REX_STORE_U8(ctx.r8.u32 + 23220, ctx.r28.u8);
	// bne cr6,0x8212a1c4
	if (!ctx.cr6.eq) goto loc_8212A1C4;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// lwz r30,3244(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 3244);
	// lwz r29,3248(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 3248);
	// cmplwi r29,0
	ctx.cr0.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r30,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// beq 0x8212a1b0
	if (ctx.cr0.eq) goto loc_8212A1B0;
loc_8212A184:
	// addi r30,r30,-4
	ctx.r30.s64 = ctx.r30.s64 + -4;
	// stw r30,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x8212a1b0
	if (ctx.cr6.lt) goto loc_8212A1B0;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8212a1a8
	if (ctx.cr6.eq) goto loc_8212A1A8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8212A1A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8212A1A8:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x8212a184
	goto loc_8212A184;
loc_8212A1B0:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// addi r4,r11,116
	ctx.r4.s64 = ctx.r11.s64 + 116;
	// addi r3,r10,108
	ctx.r3.s64 = ctx.r10.s64 + 108;
	// bl 0x8212a0a0
	ctx.lr = 0x8212A1C4;
	sub_8212A0A0(ctx, base);
loc_8212A1C4:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// addi r4,r11,124
	ctx.r4.s64 = ctx.r11.s64 + 124;
	// addi r3,r10,120
	ctx.r3.s64 = ctx.r10.s64 + 120;
	// bl 0x8212a0a0
	ctx.lr = 0x8212A1D8;
	sub_8212A0A0(ctx, base);
loc_8212A1D8:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	ctx.r12.s64 = ctx.r31.s64 + 128;
	// bl 0x8212a220
	ctx.lr = 0x8212A1E4;
	sub_8212A220(ctx, base);
	// lwz r11,164(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8212a1f8
	if (!ctx.cr6.eq) goto loc_8212A1F8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8214a954
	ctx.lr = 0x8212A1F8;
	__imp__KeBugCheck(ctx, base);
loc_8212A1F8:
	// addi r1,r31,128
	ctx.r1.s64 = ctx.r31.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
