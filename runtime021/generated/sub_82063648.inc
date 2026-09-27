DEFINE_REX_FUNC(sub_82063648) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82063650;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,15
	ctx.r5.s64 = 15;
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// bl 0x82053c70
	ctx.lr = 0x8206367C;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82063724
	if (ctx.cr6.eq) goto loc_82063724;
	// li r4,17
	ctx.r4.s64 = 17;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x82063694;
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
	ctx.lr = 0x820636B4;
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
	ctx.lr = 0x820636CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x820636D4;
	sub_82085078(ctx, base);
	// li r6,211
	ctx.r6.s64 = 211;
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// sth r6,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r6.u16);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-6624(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x820636F4;
	sub_82052EA8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// stw r4,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// rotlwi r10,r31,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r31.u32, 2);
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r8,r11,796
	ctx.r8.s64 = ctx.r11.s64 + 796;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwzx r7,r10,r8
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// clrlwi r4,r7,16
	ctx.r4.u64 = ctx.r7.u32 & 0xFFFF;
	// lwz r6,164(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 164);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82063724;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82063724:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
