DEFINE_REX_FUNC(sub_8210CFC8) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8210CFD0;
	__savegprlr_28(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r7,16(r4)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r9,12(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// li r8,40
	ctx.r8.s64 = 40;
	// clrlwi r31,r7,8
	ctx.r31.u64 = ctx.r7.u32 & 0xFFFFFF;
	// rlwinm r7,r7,19,14,20
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 19) & 0x3F800;
	// li r6,4
	ctx.r6.s64 = 4;
	// lwz r3,172(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// or r7,r7,r31
	ctx.r7.u64 = ctx.r7.u64 | ctx.r31.u64;
	// lwz r30,136(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// addi r10,r11,740
	ctx.r10.s64 = ctx.r11.s64 + 740;
	// lwz r29,132(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// rlwinm r3,r3,25,0,6
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 25) & 0xFE000000;
	// lwz r28,60(r9)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r9.u32 + 60);
	// stw r8,740(r11)
	REX_STORE_U32(ctx.r11.u32 + 740, ctx.r8.u32);
	// or r7,r3,r7
	ctx.r7.u64 = ctx.r3.u64 | ctx.r7.u64;
	// rlwinm r8,r28,18,6,13
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 18) & 0x3FC0000;
	// stw r6,744(r11)
	REX_STORE_U32(ctx.r11.u32 + 744, ctx.r6.u32);
	// stw r30,748(r11)
	REX_STORE_U32(ctx.r11.u32 + 748, ctx.r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r29,752(r11)
	REX_STORE_U32(ctx.r11.u32 + 752, ctx.r29.u32);
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// lwz r6,60(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 60);
	// stw r6,756(r11)
	REX_STORE_U32(ctx.r11.u32 + 756, ctx.r6.u32);
	// lwz r7,72(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 72);
	// stw r8,764(r11)
	REX_STORE_U32(ctx.r11.u32 + 764, ctx.r8.u32);
	// stw r7,760(r11)
	REX_STORE_U32(ctx.r11.u32 + 760, ctx.r7.u32);
	// lwz r8,20(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// stw r8,768(r11)
	REX_STORE_U32(ctx.r11.u32 + 768, ctx.r8.u32);
	// lwz r8,24(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// stw r8,772(r11)
	REX_STORE_U32(ctx.r11.u32 + 772, ctx.r8.u32);
	// lwz r8,28(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 28);
	// stw r8,776(r11)
	REX_STORE_U32(ctx.r11.u32 + 776, ctx.r8.u32);
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
	// lwz r11,164(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 164);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,164(r9)
	REX_STORE_U32(ctx.r9.u32 + 164, ctx.r11.u32);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
