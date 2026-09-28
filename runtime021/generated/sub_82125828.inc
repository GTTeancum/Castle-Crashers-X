DEFINE_REX_FUNC(sub_82125828) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82125830;
	__savegprlr_29(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// stw r9,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r9.u32);
	// mr r31,r9
	ctx.r31.u64 = ctx.r9.u64;
	// stw r9,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r9.u32);
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// stw r9,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// li r29,24
	ctx.r29.s64 = 24;
loc_82125858:
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8212588c
	if (ctx.cr6.eq) goto loc_8212588C;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82125878
	if (!ctx.cr6.eq) goto loc_82125878;
	// stw r11,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// b 0x82125884
	goto loc_82125884;
loc_82125878:
	// subf r10,r30,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r30.u64;
	// divw r10,r10,r29
	ctx.r10.u64 = uint32_t((ctx.r29.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r29.s32 == -1)) ? ctx.r10.s32 / ctx.r29.s32 : 0);
	// stb r10,20(r30)
	REX_STORE_U8(ctx.r30.u32 + 20, ctx.r10.u8);
loc_82125884:
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// b 0x821258e8
	goto loc_821258E8;
loc_8212588C:
	// lbz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 16);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// rlwinm. r10,r10,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x821258c4
	if (ctx.cr0.eq) goto loc_821258C4;
	// lwz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821258b0
	if (!ctx.cr6.eq) goto loc_821258B0;
	// stw r11,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// b 0x821258bc
	goto loc_821258BC;
loc_821258B0:
	// subf r10,r31,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r31.u64;
	// divw r10,r10,r29
	ctx.r10.u64 = uint32_t((ctx.r29.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r29.s32 == -1)) ? ctx.r10.s32 / ctx.r29.s32 : 0);
	// stb r10,20(r31)
	REX_STORE_U8(ctx.r31.u32 + 20, ctx.r10.u8);
loc_821258BC:
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// b 0x821258e8
	goto loc_821258E8;
loc_821258C4:
	// lwz r10,0(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821258d8
	if (!ctx.cr6.eq) goto loc_821258D8;
	// stw r11,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// b 0x821258e4
	goto loc_821258E4;
loc_821258D8:
	// subf r10,r5,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r5.u64;
	// divw r10,r10,r29
	ctx.r10.u64 = uint32_t((ctx.r29.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r29.s32 == -1)) ? ctx.r10.s32 / ctx.r29.s32 : 0);
	// stb r10,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r10.u8);
loc_821258E4:
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
loc_821258E8:
	// lbz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 20);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82125904
	if (ctx.cr0.eq) goto loc_82125904;
	// mulli r10,r10,24
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(24));
	// stb r9,20(r11)
	REX_STORE_U8(ctx.r11.u32 + 20, ctx.r9.u8);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x82125858
	goto loc_82125858;
loc_82125904:
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
