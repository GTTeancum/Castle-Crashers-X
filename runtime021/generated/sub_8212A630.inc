DEFINE_REX_FUNC(sub_8212A630) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8212A638;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32221
	ctx.r30.s64 = -2111635456;
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// lis r8,-32235
	ctx.r8.s64 = -2112552960;
	// addi r11,r11,-23840
	ctx.r11.s64 = ctx.r11.s64 + -23840;
	// lis r7,-32221
	ctx.r7.s64 = -2111635456;
	// lis r31,-32221
	ctx.r31.s64 = -2111635456;
	// stw r11,23244(r30)
	REX_STORE_U32(ctx.r30.u32 + 23244, ctx.r11.u32);
	// lis r29,-32221
	ctx.r29.s64 = -2111635456;
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lis r9,-32235
	ctx.r9.s64 = -2112552960;
	// addi r10,r10,-21308
	ctx.r10.s64 = ctx.r10.s64 + -21308;
	// addi r9,r9,-21292
	ctx.r9.s64 = ctx.r9.s64 + -21292;
	// addi r11,r8,-21276
	ctx.r11.s64 = ctx.r8.s64 + -21276;
	// stw r10,23248(r31)
	REX_STORE_U32(ctx.r31.u32 + 23248, ctx.r10.u32);
	// stw r9,23252(r29)
	REX_STORE_U32(ctx.r29.u32 + 23252, ctx.r9.u32);
	// stw r11,23256(r7)
	REX_STORE_U32(ctx.r7.u32 + 23256, ctx.r11.u32);
	// bl 0x8214acb4
	ctx.lr = 0x8212A680;
	__imp__KeTlsAlloc(ctx, base);
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// stw r3,31240(r11)
	REX_STORE_U32(ctx.r11.u32 + 31240, ctx.r3.u32);
	// beq cr6,0x8212a754
	if (ctx.cr6.eq) goto loc_8212A754;
	// lwz r4,23248(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 23248);
	// bl 0x8214acd4
	ctx.lr = 0x8212A698;
	__imp__KeTlsSetValue(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8212a754
	if (ctx.cr0.eq) goto loc_8212A754;
	// bl 0x8212a280
	ctx.lr = 0x8212A6A4;
	sub_8212A280(ctx, base);
	// bl 0x8212f208
	ctx.lr = 0x8212A6A8;
	sub_8212F208(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8212a750
	if (ctx.cr0.eq) goto loc_8212A750;
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// lwz r10,23244(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 23244);
	// addi r3,r11,-23320
	ctx.r3.s64 = ctx.r11.s64 + -23320;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8212A6C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r30,-32235
	ctx.r30.s64 = -2112552960;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// stw r3,31236(r30)
	REX_STORE_U32(ctx.r30.u32 + 31236, ctx.r3.u32);
	// beq cr6,0x8212a750
	if (ctx.cr6.eq) goto loc_8212A750;
	// li r4,196
	ctx.r4.s64 = 196;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8212e218
	ctx.lr = 0x8212A6E0;
	sub_8212E218(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8212a750
	if (ctx.cr0.eq) goto loc_8212A750;
	// lwz r3,31236(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 31236);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,23252(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 23252);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8212A6FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8212a750
	if (ctx.cr0.eq) goto loc_8212A750;
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
	ctx.lr = 0x8212A71C;
	sub_82136728(ctx, base);
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// addi r10,r10,23232
	ctx.r10.s64 = ctx.r10.s64 + 23232;
	// li r9,-1
	ctx.r9.s64 = -1;
	// addi r11,r11,1256
	ctx.r11.s64 = ctx.r11.s64 + 1256;
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// bl 0x820b7810
	ctx.lr = 0x8212A748;
	sub_820B7810(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8212a758
	goto loc_8212A758;
loc_8212A750:
	// bl 0x8212a340
	ctx.lr = 0x8212A754;
	sub_8212A340(ctx, base);
loc_8212A754:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8212A758:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
