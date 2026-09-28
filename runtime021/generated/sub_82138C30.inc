DEFINE_REX_FUNC(sub_82138C30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x82138C38;
	__savegprlr_26(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82138cf0
	if (ctx.cr6.eq) goto loc_82138CF0;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,3592
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3592, ctx.xer);
	// blt cr6,0x82138cf0
	if (ctx.cr6.lt) goto loc_82138CF0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8214ad74
	ctx.lr = 0x82138C6C;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x82138cfc
	if (!ctx.cr0.eq) goto loc_82138CFC;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r10,300
	ctx.r10.s64 = 300;
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r27,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// li r7,32
	ctx.r7.s64 = 32;
	// std r26,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r26.u64);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// ori r4,r4,26
	ctx.r4.u64 = ctx.r4.u64 | 26;
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// stw r31,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r31.u32);
	// bl 0x8214a224
	ctx.lr = 0x82138CB4;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82138cc4
	if (!ctx.cr0.lt) goto loc_82138CC4;
	// li r29,1627
	ctx.r29.s64 = 1627;
	// b 0x82138ce4
	goto loc_82138CE4;
loc_82138CC4:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x82138ce0
	if (!ctx.cr6.eq) goto loc_82138CE0;
	// bl 0x820b72c8
	ctx.lr = 0x82138CD0;
	sub_820B72C8(ctx, base);
	// subfic r11,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r3.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// andi. r29,r11,1627
	ctx.r29.u64 = ctx.r11.u64 & 1627;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// b 0x82138ce4
	goto loc_82138CE4;
loc_82138CE0:
	// li r29,997
	ctx.r29.s64 = 997;
loc_82138CE4:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8214a454
	ctx.lr = 0x82138CEC;
	__imp__ObDereferenceObject(ctx, base);
	// b 0x82138cfc
	goto loc_82138CFC;
loc_82138CF0:
	// li r11,3592
	ctx.r11.s64 = 3592;
	// li r29,122
	ctx.r29.s64 = 122;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_82138CFC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
