DEFINE_REX_FUNC(sub_82126FE0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r11,75(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 75);
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82127018
	if (ctx.cr0.eq) goto loc_82127018;
	// bl 0x82126d40
	ctx.lr = 0x82127004;
	sub_82126D40(ctx, base);
	// lbz r11,75(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 75);
	// andi. r11,r11,239
	ctx.r11.u64 = ctx.r11.u64 & 239;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
loc_8212700C:
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,75(r31)
	REX_STORE_U8(ctx.r31.u32 + 75, ctx.r11.u8);
	// b 0x821270cc
	goto loc_821270CC;
loc_82127018:
	// rlwinm. r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8212704c
	if (ctx.cr0.eq) goto loc_8212704C;
	// lhz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 72);
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm. r11,r11,0,17,17
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82127034
	if (!ctx.cr0.eq) goto loc_82127034;
	// lwz r6,76(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
loc_82127034:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82126c48
	ctx.lr = 0x82127040;
	sub_82126C48(ctx, base);
	// lbz r11,75(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 75);
	// clrlwi r11,r11,25
	ctx.r11.u64 = ctx.r11.u32 & 0x7F;
	// b 0x8212700c
	goto loc_8212700C;
loc_8212704C:
	// rlwinm. r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82127080
	if (ctx.cr0.eq) goto loc_82127080;
	// lhz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 72);
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm. r11,r11,0,18,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82127068
	if (!ctx.cr0.eq) goto loc_82127068;
	// lwz r6,76(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
loc_82127068:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82126c48
	ctx.lr = 0x82127074;
	sub_82126C48(ctx, base);
	// lbz r11,75(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 75);
	// andi. r11,r11,191
	ctx.r11.u64 = ctx.r11.u64 & 191;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// b 0x8212700c
	goto loc_8212700C;
loc_82127080:
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lhz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 72);
	// beq 0x821270b4
	if (ctx.cr0.eq) goto loc_821270B4;
	// rlwinm. r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r6,0
	ctx.r6.s64 = 0;
	// bne 0x8212709c
	if (!ctx.cr0.eq) goto loc_8212709C;
	// lwz r6,76(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
loc_8212709C:
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82126c48
	ctx.lr = 0x821270A8;
	sub_82126C48(ctx, base);
	// lbz r11,75(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 75);
	// andi. r11,r11,223
	ctx.r11.u64 = ctx.r11.u64 & 223;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// b 0x8212700c
	goto loc_8212700C;
loc_821270B4:
	// clrlwi r11,r11,17
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFF;
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// sth r11,72(r31)
	REX_STORE_U16(ctx.r31.u32 + 72, ctx.r11.u16);
	// bl 0x82122b78
	ctx.lr = 0x821270C8;
	sub_82122B78(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_821270CC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
