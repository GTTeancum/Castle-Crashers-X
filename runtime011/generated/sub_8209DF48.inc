DEFINE_REX_FUNC(sub_8209DF48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8209DF50;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lbz r11,24(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209dfe0
	if (ctx.cr6.eq) goto loc_8209DFE0;
	// lwz r31,96(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 96);
	// lis r29,-32218
	ctx.r29.s64 = -2111438848;
	// lwz r11,10316(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// lbz r10,10345(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 10345);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,26332(r29)
	REX_STORE_U32(ctx.r29.u32 + 26332, ctx.r11.u32);
	// beq cr6,0x8209dfcc
	if (ctx.cr6.eq) goto loc_8209DFCC;
	// lwz r11,8248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8248);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,72(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r11,1998
	ctx.r9.s64 = ctx.r11.s64 + 1998;
	// stw r11,8248(r31)
	REX_STORE_U32(ctx.r31.u32 + 8248, ctx.r11.u32);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r10.u32);
	// bl 0x82091248
	ctx.lr = 0x8209DFAC;
	sub_82091248(ctx, base);
	// lwz r11,8248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8248);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r11,1998
	ctx.r6.s64 = ctx.r11.s64 + 1998;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r7,r5,r31
	REX_STORE_U32(ctx.r5.u32 + ctx.r31.u32, ctx.r7.u32);
	// lwz r11,8248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8248);
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// stw r4,8248(r31)
	REX_STORE_U32(ctx.r31.u32 + 8248, ctx.r4.u32);
loc_8209DFCC:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8209cd08
	ctx.lr = 0x8209DFD8;
	sub_8209CD08(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,26332(r29)
	REX_STORE_U32(ctx.r29.u32 + 26332, ctx.r11.u32);
loc_8209DFE0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
