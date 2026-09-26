DEFINE_REX_FUNC(sub_820FD240) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x820FD248;
	__savegprlr_22(ctx, base);
	// addi r11,r4,13
	ctx.r11.s64 = ctx.r4.s64 + 13;
	// ld r9,232(r3)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r3.u32 + 232);
	// addi r8,r4,66
	ctx.r8.s64 = ctx.r4.s64 + 66;
	// ld r23,240(r3)
	ctx.r23.u64 = REX_LOAD_U64(ctx.r3.u32 + 240);
	// rlwinm r30,r11,3,0,28
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r24,328(r3)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r3.u32 + 328);
	// addi r11,r4,17
	ctx.r11.s64 = ctx.r4.s64 + 17;
	// lwz r25,332(r3)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r3.u32 + 332);
	// addi r7,r4,21
	ctx.r7.s64 = ctx.r4.s64 + 21;
	// ld r26,248(r3)
	ctx.r26.u64 = REX_LOAD_U64(ctx.r3.u32 + 248);
	// rlwinm r31,r11,3,0,28
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// ld r27,256(r3)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r3.u32 + 256);
	// addi r11,r4,70
	ctx.r11.s64 = ctx.r4.s64 + 70;
	// lwz r28,336(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 336);
	// ldx r10,r30,r3
	ctx.r10.u64 = REX_LOAD_U64(ctx.r30.u32 + ctx.r3.u32);
	// addi r22,r4,25
	ctx.r22.s64 = ctx.r4.s64 + 25;
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r29,340(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 340);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r9,r4,74
	ctx.r9.s64 = ctx.r4.s64 + 74;
	// std r10,232(r3)
	REX_STORE_U64(ctx.r3.u32 + 232, ctx.r10.u64);
	// addi r10,r4,78
	ctx.r10.s64 = ctx.r4.s64 + 78;
	// ldx r4,r31,r3
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + ctx.r3.u32);
	// add r8,r23,r4
	ctx.r8.u64 = ctx.r23.u64 + ctx.r4.u64;
	// std r8,240(r3)
	REX_STORE_U64(ctx.r3.u32 + 240, ctx.r8.u64);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r5,r3
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	// add r11,r24,r4
	ctx.r11.u64 = ctx.r24.u64 + ctx.r4.u64;
	// stw r11,328(r3)
	REX_STORE_U32(ctx.r3.u32 + 328, ctx.r11.u32);
	// rlwinm r7,r7,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r6,r3
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r3.u32);
	// add r11,r25,r4
	ctx.r11.u64 = ctx.r25.u64 + ctx.r4.u64;
	// stw r11,332(r3)
	REX_STORE_U32(ctx.r3.u32 + 332, ctx.r11.u32);
	// rlwinm r8,r22,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 3) & 0xFFFFFFF8;
	// ldx r4,r7,r3
	ctx.r4.u64 = REX_LOAD_U64(ctx.r7.u32 + ctx.r3.u32);
	// add r11,r4,r26
	ctx.r11.u64 = ctx.r4.u64 + ctx.r26.u64;
	// std r11,248(r3)
	REX_STORE_U64(ctx.r3.u32 + 248, ctx.r11.u64);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// ldx r4,r8,r3
	ctx.r4.u64 = REX_LOAD_U64(ctx.r8.u32 + ctx.r3.u32);
	// add r11,r27,r4
	ctx.r11.u64 = ctx.r27.u64 + ctx.r4.u64;
	// std r11,256(r3)
	REX_STORE_U64(ctx.r3.u32 + 256, ctx.r11.u64);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r3
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// add r11,r28,r4
	ctx.r11.u64 = ctx.r28.u64 + ctx.r4.u64;
	// stw r11,336(r3)
	REX_STORE_U32(ctx.r3.u32 + 336, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwzx r4,r10,r3
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// add r4,r29,r4
	ctx.r4.u64 = ctx.r29.u64 + ctx.r4.u64;
	// stw r4,340(r3)
	REX_STORE_U32(ctx.r3.u32 + 340, ctx.r4.u32);
	// stdx r11,r30,r3
	REX_STORE_U64(ctx.r30.u32 + ctx.r3.u32, ctx.r11.u64);
	// stdx r11,r31,r3
	REX_STORE_U64(ctx.r31.u32 + ctx.r3.u32, ctx.r11.u64);
	// stwx r11,r5,r3
	REX_STORE_U32(ctx.r5.u32 + ctx.r3.u32, ctx.r11.u32);
	// stwx r11,r6,r3
	REX_STORE_U32(ctx.r6.u32 + ctx.r3.u32, ctx.r11.u32);
	// stdx r11,r7,r3
	REX_STORE_U64(ctx.r7.u32 + ctx.r3.u32, ctx.r11.u64);
	// stdx r11,r8,r3
	REX_STORE_U64(ctx.r8.u32 + ctx.r3.u32, ctx.r11.u64);
	// stwx r11,r9,r3
	REX_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r11.u32);
	// stwx r11,r10,r3
	REX_STORE_U32(ctx.r10.u32 + ctx.r3.u32, ctx.r11.u32);
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
