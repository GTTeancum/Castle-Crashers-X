DEFINE_REX_FUNC(sub_82106120) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 10, ctx.xer);
	// beq cr6,0x821061b4
	if (ctx.cr6.eq) goto loc_821061B4;
	// cmplwi cr6,r4,17
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 17, ctx.xer);
	// beq cr6,0x821061a4
	if (ctx.cr6.eq) goto loc_821061A4;
	// lis r11,512
	ctx.r11.s64 = 33554432;
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8210617c
	if (ctx.cr6.eq) goto loc_8210617C;
	// lis r11,1024
	ctx.r11.s64 = 67108864;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8210619c
	if (!ctx.cr6.gt) goto loc_8210619C;
	// lis r11,1024
	ctx.r11.s64 = 67108864;
	// ori r11,r11,3
	ctx.r11.u64 = ctx.r11.u64 | 3;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8210619c
	if (ctx.cr6.gt) goto loc_8210619C;
	// bl 0x820ffb38
	ctx.lr = 0x82106178;
	sub_820FFB38(ctx, base);
	// b 0x821061bc
	goto loc_821061BC;
loc_8210617C:
	// stw r5,428(r31)
	REX_STORE_U32(ctx.r31.u32 + 428, ctx.r5.u32);
	// addi r4,r31,432
	ctx.r4.s64 = ctx.r31.s64 + 432;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x820fc418
	ctx.lr = 0x8210618C;
	sub_820FC418(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210619c
	if (ctx.cr0.eq) goto loc_8210619C;
	// li r11,254
	ctx.r11.s64 = 254;
	// stw r11,428(r31)
	REX_STORE_U32(ctx.r31.u32 + 428, ctx.r11.u32);
loc_8210619C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x821061bc
	goto loc_821061BC;
loc_821061A4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82100240
	ctx.lr = 0x821061B0;
	sub_82100240(ctx, base);
	// b 0x821061bc
	goto loc_821061BC;
loc_821061B4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82105f28
	ctx.lr = 0x821061BC;
	sub_82105F28(ctx, base);
loc_821061BC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
