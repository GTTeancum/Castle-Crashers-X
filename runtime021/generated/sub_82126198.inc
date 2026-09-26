DEFINE_REX_FUNC(sub_82126198) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x821261A0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// addi r9,r10,-20088
	ctx.r9.s64 = ctx.r10.s64 + -20088;
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// addi r10,r31,12
	ctx.r10.s64 = ctx.r31.s64 + 12;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// stw r10,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// stw r10,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// stw r4,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r4.u32);
	// std r5,24(r31)
	REX_STORE_U64(ctx.r31.u32 + 24, ctx.r5.u64);
	// bl 0x82136f58
	ctx.lr = 0x821261E8;
	sub_82136F58(ctx, base);
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// addi r3,r31,36
	ctx.r3.s64 = ctx.r31.s64 + 36;
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82129a70
	ctx.lr = 0x821261FC;
	sub_82129A70(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwinm. r10,r30,0,25,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x60;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r27,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stw r29,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r29.u32);
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stb r11,75(r31)
	REX_STORE_U8(ctx.r31.u32 + 75, ctx.r11.u8);
	// stb r11,74(r31)
	REX_STORE_U8(ctx.r31.u32 + 74, ctx.r11.u8);
	// sth r11,72(r31)
	REX_STORE_U16(ctx.r31.u32 + 72, ctx.r11.u16);
	// bne 0x8212622c
	if (!ctx.cr0.eq) goto loc_8212622C;
	// li r11,2048
	ctx.r11.s64 = 2048;
	// sth r11,72(r31)
	REX_STORE_U16(ctx.r31.u32 + 72, ctx.r11.u16);
loc_8212622C:
	// rlwinm. r11,r30,0,23,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212623c
	if (ctx.cr0.eq) goto loc_8212623C;
	// li r11,128
	ctx.r11.s64 = 128;
	// stb r11,74(r31)
	REX_STORE_U8(ctx.r31.u32 + 74, ctx.r11.u8);
loc_8212623C:
	// rlwinm. r11,r30,0,22,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82126250
	if (ctx.cr0.eq) goto loc_82126250;
	// lbz r11,74(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 74);
	// ori r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 64;
	// stb r11,74(r31)
	REX_STORE_U8(ctx.r31.u32 + 74, ctx.r11.u8);
loc_82126250:
	// rlwinm. r11,r30,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82126264
	if (ctx.cr0.eq) goto loc_82126264;
	// lbz r11,74(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 74);
	// ori r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 32;
	// stb r11,74(r31)
	REX_STORE_U8(ctx.r31.u32 + 74, ctx.r11.u8);
loc_82126264:
	// rlwinm. r11,r30,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82126278
	if (ctx.cr0.eq) goto loc_82126278;
	// lbz r11,74(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 74);
	// ori r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 16;
	// stb r11,74(r31)
	REX_STORE_U8(ctx.r31.u32 + 74, ctx.r11.u8);
loc_82126278:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
