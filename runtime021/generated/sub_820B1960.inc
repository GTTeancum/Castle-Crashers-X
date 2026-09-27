DEFINE_REX_FUNC(sub_820B1960) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820B1968;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32215
	ctx.r30.s64 = -2111242240;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r9,r10,9480
	ctx.r9.s64 = ctx.r10.s64 + 9480;
	// lbz r8,-22601(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + -22601);
	// addi r27,r11,-1768
	ctx.r27.s64 = ctx.r11.s64 + -1768;
	// lwz r28,44(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x820b19ac
	if (!ctx.cr6.eq) goto loc_820B19AC;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820B19AC;
	sub_820A71E8(ctx, base);
loc_820B19AC:
	// bl 0x820b5eb8
	ctx.lr = 0x820B19B0;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r11,29632
	ctx.r29.s64 = ctx.r11.s64 + 29632;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwzx r3,r10,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820B19C8;
	sub_8209BF18(ctx, base);
	// lbz r9,-22601(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + -22601);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r31,48(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// bne cr6,0x820b19ec
	if (!ctx.cr6.eq) goto loc_820B19EC;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820B19EC;
	sub_820A71E8(ctx, base);
loc_820B19EC:
	// bl 0x820b5eb8
	ctx.lr = 0x820B19F0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820B1A00;
	sub_8209BF18(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
