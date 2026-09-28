DEFINE_REX_FUNC(sub_8210CF10) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8210CF18;
	__savegprlr_27(ctx, base);
	// lwz r9,12(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r7,16(r4)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// li r8,48
	ctx.r8.s64 = 48;
	// li r6,3
	ctx.r6.s64 = 3;
	// clrlwi r30,r7,8
	ctx.r30.u64 = ctx.r7.u32 & 0xFFFFFF;
	// rlwinm r7,r7,19,14,20
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 19) & 0x3F800;
	// lwz r27,60(r9)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r9.u32 + 60);
	// addi r10,r11,740
	ctx.r10.s64 = ctx.r11.s64 + 740;
	// stw r8,740(r11)
	REX_STORE_U32(ctx.r11.u32 + 740, ctx.r8.u32);
	// or r7,r7,r30
	ctx.r7.u64 = ctx.r7.u64 | ctx.r30.u64;
	// lwz r31,136(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// rlwinm r8,r27,25,0,6
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 25) & 0xFE000000;
	// lwz r29,132(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r28,172(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stw r6,744(r11)
	REX_STORE_U32(ctx.r11.u32 + 744, ctx.r6.u32);
	// rlwinm r6,r28,18,0,13
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 18) & 0xFFFC0000;
	// stw r31,748(r11)
	REX_STORE_U32(ctx.r11.u32 + 748, ctx.r31.u32);
	// stw r29,752(r11)
	REX_STORE_U32(ctx.r11.u32 + 752, ctx.r29.u32);
	// or r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 | ctx.r8.u64;
	// lwz r7,60(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 60);
	// stw r7,756(r11)
	REX_STORE_U32(ctx.r11.u32 + 756, ctx.r7.u32);
	// lwz r9,72(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 72);
	// stw r8,764(r11)
	REX_STORE_U32(ctx.r11.u32 + 764, ctx.r8.u32);
	// stw r9,760(r11)
	REX_STORE_U32(ctx.r11.u32 + 760, ctx.r9.u32);
	// lwz r9,20(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// stw r9,768(r11)
	REX_STORE_U32(ctx.r11.u32 + 768, ctx.r9.u32);
	// lwz r9,24(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// stw r9,772(r11)
	REX_STORE_U32(ctx.r11.u32 + 772, ctx.r9.u32);
	// lwz r9,28(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 28);
	// stw r9,776(r11)
	REX_STORE_U32(ctx.r11.u32 + 776, ctx.r9.u32);
	// lwz r9,32(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 32);
	// stw r9,780(r11)
	REX_STORE_U32(ctx.r11.u32 + 780, ctx.r9.u32);
	// lwz r9,36(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 36);
	// stw r9,784(r11)
	REX_STORE_U32(ctx.r11.u32 + 784, ctx.r9.u32);
	// stw r10,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// lwz r10,820(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 820);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r4,808(r11)
	REX_STORE_U32(ctx.r11.u32 + 808, ctx.r4.u32);
	// stw r10,820(r11)
	REX_STORE_U32(ctx.r11.u32 + 820, ctx.r10.u32);
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
