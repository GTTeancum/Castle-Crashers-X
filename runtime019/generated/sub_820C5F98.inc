DEFINE_REX_FUNC(sub_820C5F98) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820C5FA0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r3,21532(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 21532);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820c5fd0
	if (ctx.cr6.eq) goto loc_820C5FD0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820C5FD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820C5FD0:
	// lwz r11,23356(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 23356);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820c5ff4
	if (ctx.cr6.eq) goto loc_820C5FF4;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820C5FF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820C5FF4:
	// lwz r31,10952(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 10952);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r27,14900(r30)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r30.u32 + 14900);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r26,14896(r30)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r30.u32 + 14896);
	// bl 0x820c5ee8
	ctx.lr = 0x820C6010;
	sub_820C5EE8(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820c603c
	if (ctx.cr6.eq) goto loc_820C603C;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_820C601C:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r9,r31,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 1;
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// and r31,r8,r27
	ctx.r31.u64 = ctx.r8.u64 & ctx.r27.u64;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stwx r10,r9,r26
	REX_STORE_U32(ctx.r9.u32 + ctx.r26.u32, ctx.r10.u32);
	// bne 0x820c601c
	if (!ctx.cr0.eq) goto loc_820C601C;
loc_820C603C:
	// lwz r3,21532(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 21532);
	// stw r31,10952(r30)
	REX_STORE_U32(ctx.r30.u32 + 10952, ctx.r31.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820c605c
	if (ctx.cr6.eq) goto loc_820C605C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820C605C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820C605C:
	// lwz r11,23356(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 23356);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820c6080
	if (ctx.cr6.eq) goto loc_820C6080;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820C6080;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820C6080:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
