DEFINE_REX_FUNC(sub_820C6F68) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820C6F70;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r11,10941(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10941);
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820c6f90
	if (ctx.cr0.eq) goto loc_820C6F90;
	// bl 0x820c6218
	ctx.lr = 0x820C6F88;
	sub_820C6218(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820c7094
	goto loc_820C7094;
loc_820C6F90:
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x820c6fa4
	if (!ctx.cr6.eq) goto loc_820C6FA4;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x820c6fac
	goto loc_820C6FAC;
loc_820C6FA4:
	// addi r11,r4,14
	ctx.r11.s64 = ctx.r4.s64 + 14;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
loc_820C6FAC:
	// lwz r3,13516(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 13516);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820c6fd4
	if (ctx.cr6.eq) goto loc_820C6FD4;
	// lwz r10,172(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 172);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820c6fd4
	if (ctx.cr6.eq) goto loc_820C6FD4;
	// lwz r10,14912(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 14912);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x820c6fd4
	if (ctx.cr6.gt) goto loc_820C6FD4;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820C6FD4:
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,2
	ctx.r4.s64 = 2;
	// bne 0x820c6ff8
	if (!ctx.cr0.eq) goto loc_820C6FF8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c6290
	ctx.lr = 0x820C6FF4;
	sub_820C6290(ctx, base);
	// b 0x820c7014
	goto loc_820C7014;
loc_820C6FF8:
	// lwz r11,152(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 152);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820c7010
	if (ctx.cr6.eq) goto loc_820C7010;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7988
	ctx.lr = 0x820C700C;
	sub_820C7988(ctx, base);
	// b 0x820c7014
	goto loc_820C7014;
loc_820C7010:
	// bl 0x820c7bf8
	ctx.lr = 0x820C7014;
	sub_820C7BF8(ctx, base);
loc_820C7014:
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x820c702c
	if (!ctx.cr6.eq) goto loc_820C702C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c6218
	ctx.lr = 0x820C7028;
	sub_820C6218(ctx, base);
	// b 0x820c7060
	goto loc_820C7060;
loc_820C702C:
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r30,-4
	ctx.r11.s64 = ctx.r30.s64 + -4;
	// stw r30,14928(r31)
	REX_STORE_U32(ctx.r31.u32 + 14928, ctx.r30.u32);
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// stw r29,14916(r31)
	REX_STORE_U32(ctx.r31.u32 + 14916, ctx.r29.u32);
	// addi r10,r10,-14
	ctx.r10.s64 = ctx.r10.s64 + -14;
	// stw r29,14932(r31)
	REX_STORE_U32(ctx.r31.u32 + 14932, ctx.r29.u32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r10,r11,-160
	ctx.r10.s64 = ctx.r11.s64 + -160;
	// stw r11,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stw r10,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r10.u32);
loc_820C7060:
	// lwz r11,23980(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 23980);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820c7090
	if (!ctx.cr0.eq) goto loc_820C7090;
	// lwz r4,14940(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 14940);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820c7090
	if (ctx.cr6.eq) goto loc_820C7090;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c6b18
	ctx.lr = 0x820C708C;
	sub_820C6B18(ctx, base);
	// stw r29,14940(r31)
	REX_STORE_U32(ctx.r31.u32 + 14940, ctx.r29.u32);
loc_820C7090:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_820C7094:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
