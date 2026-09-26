DEFINE_REX_FUNC(sub_8209A628) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x8209A630;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r6,8192
	ctx.r6.s64 = 536870912;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r6,r6,4
	ctx.r6.u64 = ctx.r6.u64 | 4;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lis r3,16
	ctx.r3.s64 = 1048576;
	// bl 0x820b6108
	ctx.lr = 0x8209A64C;
	sub_820B6108(ctx, base);
	// lis r10,-12
	ctx.r10.s64 = -786432;
	// lis r26,12
	ctx.r26.s64 = 786432;
	// subf r31,r3,r10
	ctx.r31.u64 = ctx.r10.u64 - ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r3,r26
	ctx.r11.u64 = ctx.r3.u64 + ctx.r26.u64;
	// lis r27,10
	ctx.r27.s64 = 655360;
	// lis r28,8
	ctx.r28.s64 = 524288;
	// lis r29,6
	ctx.r29.s64 = 393216;
	// lis r30,4
	ctx.r30.s64 = 262144;
	// lis r10,2
	ctx.r10.s64 = 131072;
loc_8209A674:
	// subf r9,r26,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r26.u64;
	// lbzx r25,r11,r10
	ctx.r25.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// subf r8,r27,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r27.u64;
	// lbz r24,0(r11)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// subf r7,r28,r11
	ctx.r7.u64 = ctx.r11.u64 - ctx.r28.u64;
	// subf r6,r29,r11
	ctx.r6.u64 = ctx.r11.u64 - ctx.r29.u64;
	// subf r23,r30,r11
	ctx.r23.u64 = ctx.r11.u64 - ctx.r30.u64;
	// lbz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// subf r22,r10,r11
	ctx.r22.u64 = ctx.r11.u64 - ctx.r10.u64;
	// lbz r8,0(r8)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// add r5,r31,r11
	ctx.r5.u64 = ctx.r31.u64 + ctx.r11.u64;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// lbz r7,0(r7)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// lbz r21,0(r6)
	ctx.r21.u64 = REX_LOAD_U8(ctx.r6.u32 + 0);
	// lbz r23,0(r23)
	ctx.r23.u64 = REX_LOAD_U8(ctx.r23.u32 + 0);
	// li r6,8
	ctx.r6.s64 = 8;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r22,0(r22)
	ctx.r22.u64 = REX_LOAD_U8(ctx.r22.u32 + 0);
	// extsb r8,r7
	ctx.r8.s64 = ctx.r7.s8;
	// extsb r7,r23
	ctx.r7.s64 = ctx.r23.s8;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsb r8,r21
	ctx.r8.s64 = ctx.r21.s8;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsb r8,r24
	ctx.r8.s64 = ctx.r24.s8;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// extsb r7,r22
	ctx.r7.s64 = ctx.r22.s8;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// extsb r7,r25
	ctx.r7.s64 = ctx.r25.s8;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r4,r9,r4
	ctx.r4.u64 = ctx.r9.u64 + ctx.r4.u64;
loc_8209A6F4:
	// dcbf r5,r3
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// add r5,r5,r10
	ctx.r5.u64 = ctx.r5.u64 + ctx.r10.u64;
	// bne 0x8209a6f4
	if (!ctx.cr0.eq) goto loc_8209A6F4;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// add r9,r31,r11
	ctx.r9.u64 = ctx.r31.u64 + ctx.r11.u64;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8209a674
	if (ctx.cr6.lt) goto loc_8209A674;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// std r4,26296(r11)
	REX_STORE_U64(ctx.r11.u32 + 26296, ctx.r4.u64);
	// bl 0x820b6190
	ctx.lr = 0x8209A720;
	sub_820B6190(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
