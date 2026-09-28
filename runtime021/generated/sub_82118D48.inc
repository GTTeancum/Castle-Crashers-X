DEFINE_REX_FUNC(sub_82118D48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82118D50;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r11,r31,304
	ctx.r11.s64 = ctx.r31.s64 + 304;
	// lwz r10,436(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 436);
	// lhz r8,18(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 18);
	// lwz r7,20(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// rldimi r7,r8,32,16
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFF00000000) | (ctx.r7.u64 & 0xFFFF0000FFFFFFFF);
	// clrlwi r9,r7,30
	ctx.r9.u64 = ctx.r7.u32 & 0x3;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// addi r6,r9,2
	ctx.r6.s64 = ctx.r9.s64 + 2;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// b 0x82118da4
	goto loc_82118DA4;
loc_82118D88:
	// ld r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// cmpld cr6,r7,r9
	ctx.cr6.compare<uint64_t>(ctx.r7.u64, ctx.r9.u64, ctx.xer);
	// beq cr6,0x82118db4
	if (ctx.cr6.eq) goto loc_82118DB4;
	// rldicl r8,r8,62,2
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 62) & 0x3FFFFFFFFFFFFFFF;
	// clrlwi r7,r8,30
	ctx.r7.u64 = ctx.r8.u32 & 0x3;
	// addi r7,r7,2
	ctx.r7.s64 = ctx.r7.s64 + 2;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
loc_82118DA4:
	// lwzx r11,r7,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82118d88
	if (!ctx.cr6.eq) goto loc_82118D88;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82118DB4:
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82118dc8
	if (ctx.cr6.eq) goto loc_82118DC8;
	// addic. r30,r11,-136
	ctx.xer.ca = ctx.r11.u32 > 135;
	ctx.r30.s64 = ctx.r11.s64 + -136;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82118dd4
	if (!ctx.cr0.eq) goto loc_82118DD4;
loc_82118DC8:
	// lwz r11,440(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 440);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82118e30
	if (ctx.cr0.eq) goto loc_82118E30;
loc_82118DD4:
	// lwz r11,432(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 432);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82118e04
	if (!ctx.cr6.eq) goto loc_82118E04;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,1264
	ctx.r3.s64 = 1264;
	// bl 0x821210e8
	ctx.lr = 0x82118DEC;
	sub_821210E8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82118e30
	if (ctx.cr0.lt) goto loc_82118E30;
	// lwz r3,432(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 432);
	// bl 0x821180d8
	ctx.lr = 0x82118DFC;
	sub_821180D8(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,432(r31)
	REX_STORE_U32(ctx.r31.u32 + 432, ctx.r11.u32);
loc_82118E04:
	// lwz r4,436(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 436);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82118e1c
	if (ctx.cr6.eq) goto loc_82118E1C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8211fa68
	ctx.lr = 0x82118E18;
	sub_8211FA68(ctx, base);
	// b 0x82118e24
	goto loc_82118E24;
loc_82118E1C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82118338
	ctx.lr = 0x82118E24;
	sub_82118338(ctx, base);
loc_82118E24:
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82118e30
	if (ctx.cr0.eq) goto loc_82118E30;
	// stw r29,436(r31)
	REX_STORE_U32(ctx.r31.u32 + 436, ctx.r29.u32);
loc_82118E30:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
