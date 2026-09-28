DEFINE_REX_FUNC(sub_820D99B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820D99B8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,268(r13)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r13.u32 + 268);
	// lis r31,-32221
	ctx.r31.s64 = -2111635456;
	// lwz r10,256(r13)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r13.u32 + 256);
	// addi r9,r11,83
	ctx.r9.s64 = ctx.r11.s64 + 83;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,22960(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22960);
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// addi r28,r9,22928
	ctx.r28.s64 = ctx.r9.s64 + 22928;
	// stwx r10,r8,r11
	REX_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r10.u32);
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r27,r10,22908
	ctx.r27.s64 = ctx.r10.s64 + 22908;
	// addi r29,r11,22944
	ctx.r29.s64 = ctx.r11.s64 + 22944;
loc_820D99F0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x8214a994
	ctx.lr = 0x820D9A08;
	__imp__KeWaitForSingleObject(ctx, base);
	// lwz r3,22960(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 22960);
	// lwz r11,300(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 300);
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r10,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d9a44
	if (ctx.cr6.eq) goto loc_820D9A44;
	// lwz r11,304(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 304);
	// addic. r5,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r5.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq 0x820d9a54
	if (ctx.cr0.eq) goto loc_820D9A54;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8214abe4
	ctx.lr = 0x820D9A40;
	__imp__KeReleaseSemaphore(ctx, base);
	// b 0x820d9a54
	goto loc_820D9A54;
loc_820D9A44:
	// bl 0x820d9248
	ctx.lr = 0x820D9A48;
	sub_820D9248(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,22960(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 22960);
	// bl 0x820d9330
	ctx.lr = 0x820D9A54;
	sub_820D9330(ctx, base);
loc_820D9A54:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8214a9a4
	ctx.lr = 0x820D9A64;
	__imp__KeSetEvent(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820d99f0
	if (ctx.cr6.eq) goto loc_820D99F0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
