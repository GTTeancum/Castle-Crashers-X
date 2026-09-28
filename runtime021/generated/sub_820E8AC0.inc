DEFINE_REX_FUNC(sub_820E8AC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x820E8AC8;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// addi r30,r29,296
	ctx.r30.s64 = ctx.r29.s64 + 296;
	// mr r26,r25
	ctx.r26.u64 = ctx.r25.u64;
	// bl 0x8214abc4
	ctx.lr = 0x820E8AE4;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,300(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 300);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r13
	ctx.r31.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e8b04
	if (ctx.cr6.eq) goto loc_820E8B04;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820e8b14
	if (ctx.cr6.eq) goto loc_820E8B14;
loc_820E8B04:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820E8B0C;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// stb r28,12(r30)
	REX_STORE_U8(ctx.r30.u32 + 12, ctx.r28.u8);
	// stw r31,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r31.u32);
loc_820E8B14:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820dafe8
	ctx.lr = 0x820E8B28;
	sub_820DAFE8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x820e8b50
	if (!ctx.cr6.eq) goto loc_820E8B50;
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820dae88
	ctx.lr = 0x820E8B3C;
	sub_820DAE88(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// blt cr6,0x820e8bc0
	if (ctx.cr6.lt) goto loc_820E8BC0;
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820daf20
	ctx.lr = 0x820E8B50;
	sub_820DAF20(ctx, base);
loc_820E8B50:
	// lbz r11,56(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e8bac
	if (ctx.cr6.eq) goto loc_820E8BAC;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
loc_820E8B60:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x820dace0
	ctx.lr = 0x820E8B70;
	sub_820DACE0(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// blt cr6,0x820e8bac
	if (ctx.cr6.lt) goto loc_820E8BAC;
	// rlwinm r11,r31,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 1;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// rlwinm r7,r10,7,16,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFF80;
	// clrlwi r31,r9,24
	ctx.r31.u64 = ctx.r9.u32 & 0xFF;
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// sth r7,4(r11)
	REX_STORE_U16(ctx.r11.u32 + 4, ctx.r7.u16);
	// lbz r6,56(r29)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r29.u32 + 56);
	// cmplw cr6,r31,r6
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x820e8b60
	if (ctx.cr6.lt) goto loc_820E8B60;
loc_820E8BAC:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x820e8bc0
	if (!ctx.cr6.eq) goto loc_820E8BC0;
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820db138
	ctx.lr = 0x820E8BBC;
	sub_820DB138(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
loc_820E8BC0:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e8c04
	if (ctx.cr6.eq) goto loc_820E8C04;
	// lwz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820e8c04
	if (!ctx.cr6.eq) goto loc_820E8C04;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// bne 0x820e8c04
	if (!ctx.cr0.eq) goto loc_820E8C04;
	// lbz r31,12(r30)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r30.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r25,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r25.u32);
	// stb r25,12(r30)
	REX_STORE_U8(ctx.r30.u32 + 12, ctx.r25.u8);
	// bl 0x8214a794
	ctx.lr = 0x820E8BFC;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820E8C04;
	__imp__KfLowerIrql(ctx, base);
loc_820E8C04:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
