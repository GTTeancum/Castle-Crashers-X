DEFINE_REX_FUNC(sub_820879A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820879A8;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,0(r5)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// and r10,r11,r12
	ctx.r10.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82087ac0
	if (ctx.cr6.eq) goto loc_82087AC0;
	// lis r12,7
	ctx.r12.s64 = 458752;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r10,r11,r12
	ctx.r10.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820879ec
	if (ctx.cr6.eq) goto loc_820879EC;
	// lwz r31,4(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x82087a14
	goto loc_82087A14;
loc_820879EC:
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82087a10
	if (ctx.cr6.eq) goto loc_82087A10;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// beq cr6,0x82087a08
	if (ctx.cr6.eq) goto loc_82087A08;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// bne cr6,0x82087a10
	if (!ctx.cr6.eq) goto loc_82087A10;
loc_82087A08:
	// lwz r31,4(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x82087a14
	goto loc_82087A14;
loc_82087A10:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82087A14:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r29,28(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// lwz r28,28(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82087A30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82087A40;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82087a60
	if (ctx.cr6.eq) goto loc_82087A60;
loc_82087A4C:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x82087a88
	if (ctx.cr6.eq) goto loc_82087A88;
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82087a4c
	if (!ctx.cr6.eq) goto loc_82087A4C;
loc_82087A60:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82087A64:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82087a90
	if (!ctx.cr6.eq) goto loc_82087A90;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-6584
	ctx.r3.s64 = ctx.r11.s64 + -6584;
	// bl 0x820798d8
	ctx.lr = 0x82087A7C;
	sub_820798D8(ctx, base);
	// bl 0x8208c5d8
	ctx.lr = 0x82087A80;
	sub_8208C5D8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82087A88:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82087a64
	goto loc_82087A64;
loc_82087A90:
	// stw r28,28(r30)
	REX_STORE_U32(ctx.r30.u32 + 28, ctx.r28.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r29,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r29.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82087AAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,140(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 140);
	// ori r8,r9,32
	ctx.r8.u64 = ctx.r9.u64 | 32;
	// stb r8,140(r3)
	REX_STORE_U8(ctx.r3.u32 + 140, ctx.r8.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82087AC0:
	// bl 0x82082bb0
	ctx.lr = 0x82087AC4;
	sub_82082BB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820878e0
	ctx.lr = 0x82087AD0;
	sub_820878E0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
