DEFINE_REX_FUNC(sub_8210CDB0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r6,9
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 9, ctx.xer);
	// blt cr6,0x8210ce0c
	if (ctx.cr6.lt) goto loc_8210CE0C;
	// lwz r11,144(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 144);
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// lwz r7,1(r5)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r5.u32 + 1);
	// lwz r8,5(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 5);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210cdf4
	if (ctx.cr6.eq) goto loc_8210CDF4;
	// addi r10,r11,16
	ctx.r10.s64 = ctx.r11.s64 + 16;
	// lwz r4,21(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 21);
	// lwz r5,25(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 25);
	// addi r6,r10,13
	ctx.r6.s64 = ctx.r10.s64 + 13;
	// bl 0x82115878
	ctx.lr = 0x8210CDF0;
	sub_82115878(ctx, base);
	// b 0x8210ce14
	goto loc_8210CE14;
loc_8210CDF4:
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// bl 0x82116e20
	ctx.lr = 0x8210CE04;
	sub_82116E20(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8210ce14
	if (ctx.cr0.eq) goto loc_8210CE14;
loc_8210CE0C:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4106
	ctx.r3.u64 = ctx.r3.u64 | 4106;
loc_8210CE14:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
