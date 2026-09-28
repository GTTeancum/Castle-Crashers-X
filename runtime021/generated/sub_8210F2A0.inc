DEFINE_REX_FUNC(sub_8210F2A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8210F2A8;
	__savegprlr_28(ctx, base);
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
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// lwz r11,820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// stw r9,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r9.u32);
	// rlwimi r11,r10,26,5,5
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x4000000) | (ctx.r11.u64 & 0xFFFFFFFFFBFFFFFF);
	// stw r8,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r8.u32);
	// rlwimi r11,r10,26,2,2
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x20000000) | (ctx.r11.u64 & 0xFFFFFFFFDFFFFFFF);
	// stw r11,820(r31)
	REX_STORE_U32(ctx.r31.u32 + 820, ctx.r11.u32);
	// bl 0x821163b0
	ctx.lr = 0x8210F2DC;
	sub_821163B0(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x8210f314
	if (!ctx.cr0.eq) goto loc_8210F314;
	// lwz r30,712(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 712);
	// addi r29,r31,712
	ctx.r29.s64 = ctx.r31.s64 + 712;
	// b 0x8210f304
	goto loc_8210F304;
loc_8210F2F0:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r30,-4
	ctx.r4.s64 = ctx.r30.s64 + -4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210d208
	ctx.lr = 0x8210F300;
	sub_8210D208(ctx, base);
	// lwz r30,0(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_8210F304:
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8210f314
	if (ctx.cr6.eq) goto loc_8210F314;
	// cmplwi r30,0
	ctx.cr0.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne 0x8210f2f0
	if (!ctx.cr0.eq) goto loc_8210F2F0;
loc_8210F314:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
