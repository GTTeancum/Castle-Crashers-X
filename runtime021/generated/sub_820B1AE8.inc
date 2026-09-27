DEFINE_REX_FUNC(sub_820B1AE8) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820B1AF0;
	__savegprlr_27(ctx, base);
	// cmpw cr6,r5,r7
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r7.s32, ctx.xer);
	// beq cr6,0x820b1c80
	if (ctx.cr6.eq) goto loc_820B1C80;
	// bge cr6,0x820b1b10
	if (!ctx.cr6.lt) goto loc_820B1B10;
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// b 0x820b1b24
	goto loc_820B1B24;
loc_820B1B10:
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
loc_820B1B24:
	// lwz r5,36(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// srawi r31,r7,5
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1F) != 0);
	ctx.r31.s64 = ctx.r7.s32 >> 5;
	// cmpw cr6,r31,r5
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r5.s32, ctx.xer);
	// blt cr6,0x820b1c80
	if (ctx.cr6.lt) goto loc_820B1C80;
	// lwz r28,40(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// srawi r5,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r5.s64 = ctx.r11.s32 >> 5;
	// cmpw cr6,r5,r28
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r28.s32, ctx.xer);
	// bgt cr6,0x820b1c80
	if (ctx.cr6.gt) goto loc_820B1C80;
	// subf r5,r4,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r4.u64;
	// subf r30,r11,r7
	ctx.r30.u64 = ctx.r7.u64 - ctx.r11.u64;
	// rlwinm r31,r5,8,0,23
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// li r27,0
	ctx.r27.s64 = 0;
	// rotlwi r5,r31,1
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r31.u32, 1);
	// rlwinm r29,r4,8,0,23
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// divw r31,r31,r30
	ctx.r31.u64 = uint32_t((ctx.r30.s32 && !(ctx.r31.s32 == INT32_MIN && ctx.r30.s32 == -1)) ? ctx.r31.s32 / ctx.r30.s32 : 0);
	// andc r5,r30,r5
	ctx.r5.u64 = ctx.r30.u64 & ~ctx.r5.u64;
	// twllei r30,0
	if (ctx.r30.s32 == 0 || ctx.r30.u32 < 0u) ppc_trap(ctx, base, 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// twlgei r5,-1
	if (ctx.r5.s32 == -1 || ctx.r5.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// bge cr6,0x820b1b84
	if (!ctx.cr6.lt) goto loc_820B1B84;
	// mullw r11,r31,r11
	ctx.r11.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r11.s32);
	// subf r29,r11,r29
	ctx.r29.u64 = ctx.r29.u64 - ctx.r11.u64;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_820B1B84:
	// addi r5,r11,31
	ctx.r5.s64 = ctx.r11.s64 + 31;
	// rlwinm r30,r5,0,0,26
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFE0;
	// cmpw cr6,r30,r7
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x820b1c80
	if (ctx.cr6.gt) goto loc_820B1C80;
	// subf r11,r11,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srawi r30,r30,5
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1F) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 5;
	// mullw r11,r11,r31
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r31.s32);
	// add r5,r11,r29
	ctx.r5.u64 = ctx.r11.u64 + ctx.r29.u64;
	// cmpw cr6,r30,r28
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r28.s32, ctx.xer);
	// bge cr6,0x820b1c80
	if (!ctx.cr6.lt) goto loc_820B1C80;
	// lwz r29,48(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// li r28,40
	ctx.r28.s64 = 40;
	// lwz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// subf r29,r29,r11
	ctx.r29.u64 = ctx.r11.u64 - ctx.r29.u64;
	// divw r29,r29,r28
	ctx.r29.u64 = uint32_t((ctx.r28.s32 && !(ctx.r29.s32 == INT32_MIN && ctx.r28.s32 == -1)) ? ctx.r29.s32 / ctx.r28.s32 : 0);
	// cmpwi cr6,r29,20480
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 20480, ctx.xer);
	// bge cr6,0x820b1c80
	if (!ctx.cr6.lt) goto loc_820B1C80;
	// addi r29,r11,40
	ctx.r29.s64 = ctx.r11.s64 + 40;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r29,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r29.u32);
	// beq cr6,0x820b1c80
	if (ctx.cr6.eq) goto loc_820B1C80;
	// stw r10,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// stw r4,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// stw r6,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// stw r31,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r31.u32);
	// stw r8,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// stw r9,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// stw r27,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r27.u32);
	// stw r27,36(r11)
	REX_STORE_U32(ctx.r11.u32 + 36, ctx.r27.u32);
	// stw r7,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// stw r5,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r5.u32);
	// lwz r10,64(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 64);
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x820b1c10
	if (!ctx.cr6.lt) goto loc_820B1C10;
	// stw r30,64(r3)
	REX_STORE_U32(ctx.r3.u32 + 64, ctx.r30.u32);
loc_820B1C10:
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r9,60(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// addi r10,r10,31
	ctx.r10.s64 = ctx.r10.s64 + 31;
	// srawi r10,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 5;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x820b1c2c
	if (ctx.cr6.lt) goto loc_820B1C2C;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
loc_820B1C2C:
	// lwz r9,68(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 68);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x820b1c3c
	if (!ctx.cr6.gt) goto loc_820B1C3C;
	// stw r10,68(r3)
	REX_STORE_U32(ctx.r3.u32 + 68, ctx.r10.u32);
loc_820B1C3C:
	// lwz r5,44(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// rlwinm r6,r30,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r6,r5
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820b1c9c
	if (ctx.cr6.eq) goto loc_820B1C9C;
	// lwz r7,28(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_820B1C5C:
	// lwz r4,28(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// cmpw cr6,r4,r7
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x820b1c84
	if (ctx.cr6.gt) goto loc_820B1C84;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// lwz r10,32(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820b1c5c
	if (!ctx.cr6.eq) goto loc_820B1C5C;
	// stw r11,32(r9)
	REX_STORE_U32(ctx.r9.u32 + 32, ctx.r11.u32);
	// stw r27,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r27.u32);
loc_820B1C80:
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_820B1C84:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820b1c98
	if (ctx.cr6.eq) goto loc_820B1C98;
	// stw r11,32(r9)
	REX_STORE_U32(ctx.r9.u32 + 32, ctx.r11.u32);
	// stw r10,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_820B1C98:
	// stw r8,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r8.u32);
loc_820B1C9C:
	// stwx r11,r6,r5
	REX_STORE_U32(ctx.r6.u32 + ctx.r5.u32, ctx.r11.u32);
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
