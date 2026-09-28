DEFINE_REX_FUNC(sub_820DCDF8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820DCE00;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mftb r10
	ctx.r10.u64 = REX_QUERY_TIMEBASE();
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r28,r1,80
	ctx.r28.s64 = ctx.r1.s64 + 80;
	// addi r31,r11,22972
	ctx.r31.s64 = ctx.r11.s64 + 22972;
	// li r30,0
	ctx.r30.s64 = 0;
	// sradi r26,r10,32
	ctx.xer.ca = (ctx.r10.s64 < 0) & ((ctx.r10.u64 & 0xFFFFFFFF) != 0);
	ctx.r26.s64 = ctx.r10.s64 >> 32;
	// mr r27,r10
	ctx.r27.u64 = ctx.r10.u64;
	// lwz r11,22972(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 22972);
	// std r30,0(r28)
	REX_STORE_U64(ctx.r28.u32 + 0, ctx.r30.u64);
	// lis r3,22593
	ctx.r3.s64 = 1480654848;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r5,40
	ctx.r5.s64 = 40;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r8,12(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// ori r3,r3,30052
	ctx.r3.u64 = ctx.r3.u64 | 30052;
	// lwz r7,16(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r6,20(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r29,24(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// std r30,8(r28)
	REX_STORE_U64(ctx.r28.u32 + 8, ctx.r30.u64);
	// std r30,16(r28)
	REX_STORE_U64(ctx.r28.u32 + 16, ctx.r30.u64);
	// std r30,24(r28)
	REX_STORE_U64(ctx.r28.u32 + 24, ctx.r30.u64);
	// std r30,32(r28)
	REX_STORE_U64(ctx.r28.u32 + 32, ctx.r30.u64);
	// stw r26,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// stw r27,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r9,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// stw r8,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// stw r7,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// stw r6,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// stw r29,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// bl 0x821367a0
	ctx.lr = 0x820DCE88;
	sub_821367A0(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_820DCE8C:
	// lwzx r9,r11,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// addi r8,r31,28
	ctx.r8.s64 = ctx.r31.s64 + 28;
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stwx r30,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r30.u32);
	// stwx r9,r11,r8
	REX_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpwi cr6,r11,28
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 28, ctx.xer);
	// blt cr6,0x820dce8c
	if (ctx.cr6.lt) goto loc_820DCE8C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
