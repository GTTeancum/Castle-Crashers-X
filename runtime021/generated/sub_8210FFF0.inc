DEFINE_REX_FUNC(sub_8210FFF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8210FFF8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r29,r31,104
	ctx.r29.s64 = ctx.r31.s64 + 104;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214a434
	ctx.lr = 0x82110010;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82110038
	if (ctx.cr6.lt) goto loc_82110038;
	// beq cr6,0x82110030
	if (ctx.cr6.eq) goto loc_82110030;
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// ori r31,r31,4105
	ctx.r31.u64 = ctx.r31.u64 | 4105;
	// b 0x82110058
	goto loc_82110058;
loc_82110030:
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82110040
	goto loc_82110040;
loc_82110038:
	// lis r5,-32646
	ctx.r5.s64 = -2139488256;
	// ori r5,r5,4114
	ctx.r5.u64 = ctx.r5.u64 | 4114;
loc_82110040:
	// li r11,2
	ctx.r11.s64 = 2;
	// clrlwi r4,r30,31
	ctx.r4.u64 = ctx.r30.u32 & 0x1;
	// stw r11,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210f320
	ctx.lr = 0x82110054;
	sub_8210F320(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
loc_82110058:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214a444
	ctx.lr = 0x82110060;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
