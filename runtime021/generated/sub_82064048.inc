DEFINE_REX_FUNC(sub_82064048) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82064050;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,15
	ctx.r5.s64 = 15;
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// bl 0x82053c70
	ctx.lr = 0x8206407C;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820640f8
	if (ctx.cr6.eq) goto loc_820640F8;
	// li r4,24
	ctx.r4.s64 = 24;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x82064094;
	sub_82053BC8(ctx, base);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r4,r11,18344
	ctx.r4.s64 = ctx.r11.s64 + 18344;
	// lwz r9,276(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 276);
	// lhz r31,8(r10)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// lwz r30,56(r9)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + 56);
	// bl 0x8209d948
	ctx.lr = 0x820640B4;
	sub_8209D948(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r7,100(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 100);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820640CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x820640D4;
	sub_82085078(ctx, base);
	// lis r6,-32221
	ctx.r6.s64 = -2111635456;
	// rotlwi r5,r31,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r31.u32, 2);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r6,808
	ctx.r4.s64 = ctx.r6.s64 + 808;
	// lwz r9,164(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// lwzx r10,r5,r4
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r4.u32);
	// clrlwi r4,r10,16
	ctx.r4.u64 = ctx.r10.u32 & 0xFFFF;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820640F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820640F8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
