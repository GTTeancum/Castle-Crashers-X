DEFINE_REX_FUNC(sub_820E99E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820E99E8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// lbz r11,264(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 264);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820e9aa0
	if (ctx.cr6.eq) goto loc_820E9AA0;
	// addi r31,r29,296
	ctx.r31.s64 = ctx.r29.s64 + 296;
	// bl 0x8214abc4
	ctx.lr = 0x820E9A0C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,300(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 300);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r13
	ctx.r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e9a2c
	if (ctx.cr6.eq) goto loc_820E9A2C;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820e9a3c
	if (ctx.cr6.eq) goto loc_820E9A3C;
loc_820E9A2C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820E9A34;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// stb r28,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r28.u8);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
loc_820E9A3C:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820dadc0
	ctx.lr = 0x820E9A50;
	sub_820DADC0(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e9a98
	if (ctx.cr6.eq) goto loc_820E9A98;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820e9a98
	if (!ctx.cr6.eq) goto loc_820E9A98;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bne 0x820e9a98
	if (!ctx.cr0.eq) goto loc_820E9A98;
	// lbz r28,12(r31)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r31.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r27,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r27.u8);
	// stw r27,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
	// bl 0x8214a794
	ctx.lr = 0x820E9A90;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820E9A98;
	__imp__KfLowerIrql(ctx, base);
loc_820E9A98:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x820e9b88
	if (ctx.cr6.lt) goto loc_820E9B88;
loc_820E9AA0:
	// addi r30,r29,16
	ctx.r30.s64 = ctx.r29.s64 + 16;
	// bl 0x8214abc4
	ctx.lr = 0x820E9AA8;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r31,r11,22852
	ctx.r31.s64 = ctx.r11.s64 + 22852;
	// mr r29,r13
	ctx.r29.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e9ad0
	if (ctx.cr6.eq) goto loc_820E9AD0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820e9ae4
	if (ctx.cr6.eq) goto loc_820E9AE4;
loc_820E9AD0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820E9AD8;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// stb r28,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r28.u8);
loc_820E9AE4:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lbz r10,156(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 156);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x820e9b08
	if (!ctx.cr6.eq) goto loc_820E9B08;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,3
	ctx.r4.s64 = 3;
	// b 0x820e9b1c
	goto loc_820E9B1C;
loc_820E9B08:
	// rlwinm r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820e9b34
	if (ctx.cr6.eq) goto loc_820E9B34;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,6
	ctx.r4.s64 = 6;
loc_820E9B1C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820E9B30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
loc_820E9B34:
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e9b7c
	if (ctx.cr6.eq) goto loc_820E9B7C;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820e9b7c
	if (!ctx.cr6.eq) goto loc_820E9B7C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bne 0x820e9b7c
	if (!ctx.cr0.eq) goto loc_820E9B7C;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// lbz r30,12(r31)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r31.u32 + 12);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// stb r11,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// bl 0x8214a794
	ctx.lr = 0x820E9B74;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820E9B7C;
	__imp__KfLowerIrql(ctx, base);
loc_820E9B7C:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_820E9B88:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
