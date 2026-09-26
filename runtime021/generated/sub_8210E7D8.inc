DEFINE_REX_FUNC(sub_8210E7D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8210E7E0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r30,5
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 5, ctx.xer);
	// beq cr6,0x8210e810
	if (ctx.cr6.eq) goto loc_8210E810;
	// cmpwi cr6,r30,15
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 15, ctx.xer);
	// beq cr6,0x8210e808
	if (ctx.cr6.eq) goto loc_8210E808;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8210e840
	goto loc_8210E840;
loc_8210E808:
	// li r3,262
	ctx.r3.s64 = 262;
	// b 0x8210e814
	goto loc_8210E814;
loc_8210E810:
	// li r3,259
	ctx.r3.s64 = 259;
loc_8210E814:
	// addi r4,r31,16
	ctx.r4.s64 = ctx.r31.s64 + 16;
	// bl 0x82108f48
	ctx.lr = 0x8210E81C;
	sub_82108F48(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210e840
	if (ctx.cr0.eq) goto loc_8210E840;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r29,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r31,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r31.u32);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stb r30,16(r3)
	REX_STORE_U8(ctx.r3.u32 + 16, ctx.r30.u8);
loc_8210E840:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
