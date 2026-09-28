DEFINE_REX_FUNC(sub_820D7888) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820D7890;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// lis r4,-20096
	ctx.r4.s64 = -1317011456;
	// stw r28,10948(r31)
	REX_STORE_U32(ctx.r31.u32 + 10948, ctx.r28.u32);
	// lwz r3,11804(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 11804);
	// bl 0x82136708
	ctx.lr = 0x820D78AC;
	sub_82136708(ctx, base);
	// addi r30,r31,11356
	ctx.r30.s64 = ctx.r31.s64 + 11356;
	// li r29,6
	ctx.r29.s64 = 6;
loc_820D78B4:
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d78d0
	if (ctx.cr6.eq) goto loc_820D78D0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a9a4
	ctx.lr = 0x820D78D0;
	__imp__KeSetEvent(ctx, base);
loc_820D78D0:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,80
	ctx.r30.s64 = ctx.r30.s64 + 80;
	// bne 0x820d78b4
	if (!ctx.cr0.eq) goto loc_820D78B4;
	// addi r30,r31,11372
	ctx.r30.s64 = ctx.r31.s64 + 11372;
	// li r29,6
	ctx.r29.s64 = 6;
loc_820D78E4:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820d7900
	if (ctx.cr6.eq) goto loc_820D7900;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x820b6020
	ctx.lr = 0x820D78F8;
	sub_820B6020(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x820b6498
	ctx.lr = 0x820D7900;
	sub_820B6498(ctx, base);
loc_820D7900:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,80
	ctx.r30.s64 = ctx.r30.s64 + 80;
	// bne 0x820d78e4
	if (!ctx.cr0.eq) goto loc_820D78E4;
	// stw r28,10984(r31)
	REX_STORE_U32(ctx.r31.u32 + 10984, ctx.r28.u32);
	// stw r28,10988(r31)
	REX_STORE_U32(ctx.r31.u32 + 10988, ctx.r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
