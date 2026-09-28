DEFINE_REX_FUNC(sub_820FCD60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820FCD68;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// subfic r11,r5,127
	ctx.xer.ca = ctx.r5.u32 <= 127;
	ctx.r11.u64 = static_cast<uint64_t>(127) - ctx.r5.u64;
	// stw r6,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r6.u32);
	// subfic r10,r5,-1
	ctx.xer.ca = ctx.r5.u32 <= 4294967295;
	ctx.r10.u64 = static_cast<uint64_t>(-1) - ctx.r5.u64;
	// rlwinm r11,r11,18,0,13
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 18) & 0xFFFC0000;
	// rlwinm r10,r10,25,0,6
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0xFE000000;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// or r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 | ctx.r10.u64;
loc_820FCD94:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lwz r3,400(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 400);
	// li r8,4
	ctx.r8.s64 = 4;
	// ori r11,r11,65534
	ctx.r11.u64 = ctx.r11.u64 | 65534;
	// addi r7,r1,172
	ctx.r7.s64 = ctx.r1.s64 + 172;
	// subf r11,r31,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r31.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// or r5,r11,r28
	ctx.r5.u64 = ctx.r11.u64 | ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82108ed8
	ctx.lr = 0x820FCDBC;
	sub_82108ED8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820fcdd4
	if (ctx.cr0.lt) goto loc_820FCDD4;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r31,4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 4, ctx.xer);
	// blt cr6,0x820fcd94
	if (ctx.cr6.lt) goto loc_820FCD94;
	// li r3,0
	ctx.r3.s64 = 0;
loc_820FCDD4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
