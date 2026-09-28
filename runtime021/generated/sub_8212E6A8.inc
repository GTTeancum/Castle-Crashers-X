DEFINE_REX_FUNC(sub_8212E6A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8212E6B0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8212e910
	ctx.lr = 0x8212E6BC;
	sub_8212E910(ctx, base);
	// bl 0x82053a98
	ctx.lr = 0x8212E6C0;
	sub_82053A98(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8212e774
	if (ctx.cr0.eq) goto loc_8212E774;
	// bl 0x8212bf08
	ctx.lr = 0x8212E6CC;
	sub_8212BF08(ctx, base);
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8212e6e0
	if (!ctx.cr6.eq) goto loc_8212E6E0;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8212e6f4
	goto loc_8212E6F4;
loc_8212E6E0:
	// bl 0x8212bf08
	ctx.lr = 0x8212E6E4;
	sub_8212BF08(ctx, base);
	// addi r11,r3,64
	ctx.r11.s64 = ctx.r3.s64 + 64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8212e774
	if (!ctx.cr6.eq) goto loc_8212E774;
	// li r10,1
	ctx.r10.s64 = 1;
loc_8212E6F4:
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// lwz r11,23260(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 23260);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,23260(r9)
	REX_STORE_U32(ctx.r9.u32 + 23260, ctx.r11.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// andi. r11,r11,268
	ctx.r11.u64 = ctx.r11.u64 & 268;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212e774
	if (!ctx.cr0.eq) goto loc_8212E774;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// rlwinm r29,r10,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r11,23300
	ctx.r30.s64 = ctx.r11.s64 + 23300;
	// lwzx r11,r29,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8212e74c
	if (!ctx.cr6.eq) goto loc_8212E74C;
	// li r3,4096
	ctx.r3.s64 = 4096;
	// bl 0x82128f70
	ctx.lr = 0x8212E734;
	sub_82128F70(ctx, base);
	// mr. r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stwx r11,r29,r30
	REX_STORE_U32(ctx.r29.u32 + ctx.r30.u32, ctx.r11.u32);
	// bne 0x8212e74c
	if (!ctx.cr0.eq) goto loc_8212E74C;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r31,20
	ctx.r11.s64 = ctx.r31.s64 + 20;
	// b 0x8212e750
	goto loc_8212E750;
loc_8212E74C:
	// li r10,4096
	ctx.r10.s64 = 4096;
loc_8212E750:
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// ori r11,r11,4354
	ctx.r11.u64 = ctx.r11.u64 | 4354;
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// b 0x8212e778
	goto loc_8212E778;
loc_8212E774:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8212E778:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
