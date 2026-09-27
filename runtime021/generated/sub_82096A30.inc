DEFINE_REX_FUNC(sub_82096A30) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82096A38;
	__savegprlr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-1248
	ctx.r3.s64 = ctx.r10.s64 + -1248;
	// lwz r30,-6612(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -6612);
	// bl 0x8208c5d8
	ctx.lr = 0x82096A58;
	sub_8208C5D8(ctx, base);
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// addi r28,r30,76
	ctx.r28.s64 = ctx.r30.s64 + 76;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82097720
	ctx.lr = 0x82096A6C;
	sub_82097720(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// stw r10,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
loc_82096A84:
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82096a98
	if (ctx.cr6.eq) goto loc_82096A98;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x82096a9c
	if (ctx.cr6.eq) goto loc_82096A9C;
loc_82096A98:
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82096A9C:
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82096ae4
	if (ctx.cr6.eq) goto loc_82096AE4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82096ab0
	if (!ctx.cr6.eq) goto loc_82096AB0;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82096AB0:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82096ac0
	if (!ctx.cr6.eq) goto loc_82096AC0;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82096AC0:
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lhz r5,16(r10)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r10.u32 + 16);
	// lwz r4,4(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8209eff0
	ctx.lr = 0x82096AD0;
	sub_8209EFF0(ctx, base);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x82074a58
	ctx.lr = 0x82096AD8;
	sub_82074A58(ctx, base);
	// lwz r10,124(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// b 0x82096a84
	goto loc_82096A84;
loc_82096AE4:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x82075098
	ctx.lr = 0x82096AF4;
	sub_82075098(ctx, base);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r10,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r10.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// stw r9,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r9.u32);
	// lwz r8,4(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r8,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r8.u32);
	// bl 0x82097840
	ctx.lr = 0x82096B20;
	sub_82097840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r7,-1192
	ctx.r3.s64 = ctx.r7.s64 + -1192;
	// bl 0x8208c5d8
	ctx.lr = 0x82096B30;
	sub_8208C5D8(ctx, base);
	// stw r30,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r30,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r30.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
