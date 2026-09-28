DEFINE_REX_FUNC(sub_8211FA68) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8211FA70;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r3,r31,40
	ctx.r3.s64 = ctx.r31.s64 + 40;
	// li r29,0
	ctx.r29.s64 = 0;
	// bl 0x8214a434
	ctx.lr = 0x8211FA88;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8211fb48
	if (ctx.cr6.eq) goto loc_8211FB48;
	// lwz r11,40(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 40);
	// lbz r3,2(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// bl 0x82120778
	ctx.lr = 0x8211FAA0;
	sub_82120778(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8211fb38
	if (ctx.cr6.eq) goto loc_8211FB38;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// beq cr6,0x8211fb28
	if (ctx.cr6.eq) goto loc_8211FB28;
	// cmpwi cr6,r3,4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 4, ctx.xer);
	// beq cr6,0x8211fb18
	if (ctx.cr6.eq) goto loc_8211FB18;
	// cmpwi cr6,r3,5
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 5, ctx.xer);
	// beq cr6,0x8211fb08
	if (ctx.cr6.eq) goto loc_8211FB08;
	// cmpwi cr6,r3,6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 6, ctx.xer);
	// beq cr6,0x8211faf8
	if (ctx.cr6.eq) goto loc_8211FAF8;
	// cmpwi cr6,r3,7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 7, ctx.xer);
	// beq cr6,0x8211fae8
	if (ctx.cr6.eq) goto loc_8211FAE8;
	// cmpwi cr6,r3,128
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 128, ctx.xer);
	// bne cr6,0x8211fb48
	if (!ctx.cr6.eq) goto loc_8211FB48;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211f840
	ctx.lr = 0x8211FAE4;
	sub_8211F840(ctx, base);
	// b 0x8211fb44
	goto loc_8211FB44;
loc_8211FAE8:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211ee88
	ctx.lr = 0x8211FAF4;
	sub_8211EE88(ctx, base);
	// b 0x8211fb44
	goto loc_8211FB44;
loc_8211FAF8:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211ed58
	ctx.lr = 0x8211FB04;
	sub_8211ED58(ctx, base);
	// b 0x8211fb44
	goto loc_8211FB44;
loc_8211FB08:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211d320
	ctx.lr = 0x8211FB14;
	sub_8211D320(ctx, base);
	// b 0x8211fb44
	goto loc_8211FB44;
loc_8211FB18:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211d278
	ctx.lr = 0x8211FB24;
	sub_8211D278(ctx, base);
	// b 0x8211fb44
	goto loc_8211FB44;
loc_8211FB28:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211d1f8
	ctx.lr = 0x8211FB34;
	sub_8211D1F8(ctx, base);
	// b 0x8211fb44
	goto loc_8211FB44;
loc_8211FB38:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211cf88
	ctx.lr = 0x8211FB44;
	sub_8211CF88(ctx, base);
loc_8211FB44:
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_8211FB48:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211c7f8
	ctx.lr = 0x8211FB50;
	sub_8211C7F8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
