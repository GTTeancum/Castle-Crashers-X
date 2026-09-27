DEFINE_REX_FUNC(sub_82127EA8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x82127EB0;
	__savegprlr_23(ctx, base);
	// addi r31,r1,-176
	ctx.r31.s64 = ctx.r1.s64 + -176;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// bl 0x8212a090
	ctx.lr = 0x82127EC0;
	sub_8212A090(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r24,-32215
	ctx.r24.s64 = -2111242240;
	// lis r25,-32215
	ctx.r25.s64 = -2111242240;
	// lwz r30,3244(r24)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r24.u32 + 3244);
	// lwz r28,3248(r25)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r25.u32 + 3248);
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x82127f6c
	if (ctx.cr6.lt) goto loc_82127F6C;
	// subf r26,r28,r30
	ctx.r26.u64 = ctx.r30.u64 - ctx.r28.u64;
	// addi r27,r26,4
	ctx.r27.s64 = ctx.r26.s64 + 4;
	// cmplwi cr6,r27,4
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 4, ctx.xer);
	// blt cr6,0x82127f6c
	if (ctx.cr6.lt) goto loc_82127F6C;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8212e0d0
	ctx.lr = 0x82127EF4;
	sub_8212E0D0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplw cr6,r29,r27
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r27.u32, ctx.xer);
	// bge cr6,0x82127f58
	if (!ctx.cr6.lt) goto loc_82127F58;
	// cmplwi cr6,r29,2048
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 2048, ctx.xer);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// blt cr6,0x82127f10
	if (ctx.cr6.lt) goto loc_82127F10;
	// li r11,2048
	ctx.r11.s64 = 2048;
loc_82127F10:
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// cmplw cr6,r4,r29
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x82127f2c
	if (ctx.cr6.lt) goto loc_82127F2C;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8212dfe0
	ctx.lr = 0x82127F24;
	sub_8212DFE0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82127f48
	if (!ctx.cr0.eq) goto loc_82127F48;
loc_82127F2C:
	// addi r4,r29,16
	ctx.r4.s64 = ctx.r29.s64 + 16;
	// cmplw cr6,r4,r29
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x82127f6c
	if (ctx.cr6.lt) goto loc_82127F6C;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8212dfe0
	ctx.lr = 0x82127F40;
	sub_8212DFE0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82127f6c
	if (ctx.cr0.eq) goto loc_82127F6C;
loc_82127F48:
	// srawi r11,r26,2
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r26.s32 >> 2;
	// stw r3,3248(r25)
	REX_STORE_U32(ctx.r25.u32 + 3248, ctx.r3.u32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r11,r3
	ctx.r30.u64 = ctx.r11.u64 + ctx.r3.u64;
loc_82127F58:
	// addi r11,r30,4
	ctx.r11.s64 = ctx.r30.s64 + 4;
	// stw r23,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r23.u32);
	// stw r23,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r23.u32);
	// stw r11,3244(r24)
	REX_STORE_U32(ctx.r24.u32 + 3244, ctx.r11.u32);
	// b 0x82127f74
	goto loc_82127F74;
loc_82127F6C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
loc_82127F74:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,176
	ctx.r12.s64 = ctx.r31.s64 + 176;
	// bl 0x82127f8c
	ctx.lr = 0x82127F80;
	sub_82127F8C(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// addi r1,r31,176
	ctx.r1.s64 = ctx.r31.s64 + 176;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
