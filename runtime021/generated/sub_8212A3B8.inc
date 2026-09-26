DEFINE_REX_FUNC(sub_8212A3B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8212A3C0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x820b6780
	ctx.lr = 0x8212A3C8;
	sub_820B6780(ctx, base);
	// lis r30,-32235
	ctx.r30.s64 = -2112552960;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r31,31236(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 31236);
	// bl 0x8212a2e8
	ctx.lr = 0x8212A3D8;
	sub_8212A2E8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8212A3E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8212a484
	if (!ctx.cr0.eq) goto loc_8212A484;
	// lis r29,-32221
	ctx.r29.s64 = -2111635456;
	// lwz r3,31236(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 31236);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,23252(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 23252);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8212A408;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8212a490
	if (ctx.cr0.eq) goto loc_8212A490;
	// li r4,196
	ctx.r4.s64 = 196;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8212e218
	ctx.lr = 0x8212A41C;
	sub_8212E218(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// lwz r3,31236(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 31236);
	// lwz r11,23252(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 23252);
	// beq 0x8212a474
	if (ctx.cr0.eq) goto loc_8212A474;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8212A438;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8212a468
	if (ctx.cr0.eq) goto loc_8212A468;
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,-32496
	ctx.r11.s64 = ctx.r11.s64 + -32496;
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// bl 0x82136728
	ctx.lr = 0x8212A458;
	sub_82136728(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// b 0x8212a490
	goto loc_8212A490;
loc_8212A468:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82129880
	ctx.lr = 0x8212A470;
	sub_82129880(ctx, base);
	// b 0x8212a48c
	goto loc_8212A48C;
loc_8212A474:
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8212A480;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8212a490
	goto loc_8212A490;
loc_8212A484:
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// bne cr6,0x8212a490
	if (!ctx.cr6.eq) goto loc_8212A490;
loc_8212A48C:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8212A490:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820b73c8
	ctx.lr = 0x8212A498;
	sub_820B73C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
