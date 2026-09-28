DEFINE_REX_FUNC(sub_8212A598) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8212A5A0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32235
	ctx.r30.s64 = -2112552960;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r29,-32235
	ctx.r29.s64 = -2112552960;
	// lwz r11,31236(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 31236);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8212a614
	if (ctx.cr6.eq) goto loc_8212A614;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8212a5f4
	if (!ctx.cr6.eq) goto loc_8212A5F4;
	// lwz r3,31240(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 31240);
	// bl 0x8214acc4
	ctx.lr = 0x8212A5CC;
	__imp__KeTlsGetValue(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8212a5f4
	if (ctx.cr0.eq) goto loc_8212A5F4;
	// lwz r3,31240(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 31240);
	// lwz r31,31236(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 31236);
	// bl 0x8214acc4
	ctx.lr = 0x8212A5E0;
	__imp__KeTlsGetValue(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8212A5F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8212A5F4:
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r3,31236(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 31236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,23252(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 23252);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8212A60C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8212a4e8
	ctx.lr = 0x8212A614;
	sub_8212A4E8(ctx, base);
loc_8212A614:
	// lwz r3,31240(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 31240);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8212a628
	if (ctx.cr6.eq) goto loc_8212A628;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214acd4
	ctx.lr = 0x8212A628;
	__imp__KeTlsSetValue(ctx, base);
loc_8212A628:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
