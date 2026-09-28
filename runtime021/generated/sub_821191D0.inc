DEFINE_REX_FUNC(sub_821191D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x821191D8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r28,r31,236
	ctx.r28.s64 = ctx.r31.s64 + 236;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a434
	ctx.lr = 0x821191EC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r29,r31,164
	ctx.r29.s64 = ctx.r31.s64 + 164;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214a434
	ctx.lr = 0x821191F8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lwz r11,440(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 440);
	// oris r11,r11,24576
	ctx.r11.u64 = ctx.r11.u64 | 1610612736;
	// rlwinm. r10,r11,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,440(r31)
	REX_STORE_U32(ctx.r31.u32 + 440, ctx.r11.u32);
	// beq 0x8211922c
	if (ctx.cr0.eq) goto loc_8211922C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214a444
	ctx.lr = 0x8211921C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82118268
	ctx.lr = 0x82119224;
	sub_82118268(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214a434
	ctx.lr = 0x8211922C;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8211922C:
	// lwz r11,328(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82119260
	if (ctx.cr6.eq) goto loc_82119260;
	// addi r30,r31,304
	ctx.r30.s64 = ctx.r31.s64 + 304;
loc_8211923C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82118550
	ctx.lr = 0x82119244;
	sub_82118550(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-136
	ctx.r4.s64 = ctx.r11.s64 + -136;
	// bl 0x82118928
	ctx.lr = 0x82119254;
	sub_82118928(ctx, base);
	// lwz r11,328(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8211923c
	if (!ctx.cr6.eq) goto loc_8211923C;
loc_82119260:
	// lwz r3,272(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 272);
	// bl 0x820fc740
	ctx.lr = 0x82119268;
	sub_820FC740(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// addi r30,r31,292
	ctx.r30.s64 = ctx.r31.s64 + 292;
	// stw r11,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r11.u32);
	// lwz r11,292(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// b 0x821192bc
	goto loc_821192BC;
loc_8211927C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82119290
	if (!ctx.cr6.eq) goto loc_82119290;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x821192b0
	goto loc_821192B0;
loc_82119290:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
loc_821192B0:
	// addi r3,r11,-8
	ctx.r3.s64 = ctx.r11.s64 + -8;
	// bl 0x821180d8
	ctx.lr = 0x821192B8;
	sub_821180D8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_821192BC:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8211927c
	if (!ctx.cr6.eq) goto loc_8211927C;
	// lwz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// addi r30,r31,280
	ctx.r30.s64 = ctx.r31.s64 + 280;
	// b 0x8211931c
	goto loc_8211931C;
loc_821192D0:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x821192e4
	if (!ctx.cr6.eq) goto loc_821192E4;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82119304
	goto loc_82119304;
loc_821192E4:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
loc_82119304:
	// addi r3,r11,-8
	ctx.r3.s64 = ctx.r11.s64 + -8;
	// bl 0x821180d8
	ctx.lr = 0x8211930C;
	sub_821180D8(ctx, base);
	// lwz r11,276(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 276);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,276(r31)
	REX_STORE_U32(ctx.r31.u32 + 276, ctx.r11.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_8211931C:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x821192d0
	if (!ctx.cr6.eq) goto loc_821192D0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82121220
	ctx.lr = 0x8211932C;
	sub_82121220(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214a444
	ctx.lr = 0x82119334;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
loc_82119338:
	// lwz r11,436(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 436);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82119350
	if (!ctx.cr6.eq) goto loc_82119350;
	// lwz r11,380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 380);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8211937c
	if (ctx.cr6.eq) goto loc_8211937C;
loc_82119350:
	// cmplwi cr6,r30,1000
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1000, ctx.xer);
	// bge cr6,0x8211937c
	if (!ctx.cr6.lt) goto loc_8211937C;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a444
	ctx.lr = 0x82119360;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x8210c7e8
	ctx.lr = 0x8211936C;
	sub_8210C7E8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a434
	ctx.lr = 0x82119374;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// b 0x82119338
	goto loc_82119338;
loc_8211937C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a444
	ctx.lr = 0x82119384;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821180d8
	ctx.lr = 0x8211938C;
	sub_821180D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
