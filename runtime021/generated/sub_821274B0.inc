DEFINE_REX_FUNC(sub_821274B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x821274B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x821274d8
	if (!ctx.cr6.eq) goto loc_821274D8;
loc_821274D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82127508
	goto loc_82127508;
loc_821274D8:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82127510
	if (!ctx.cr6.eq) goto loc_82127510;
	// bl 0x821294e0
	ctx.lr = 0x821274E4;
	sub_821294E0(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212c298
	ctx.lr = 0x82127504;
	sub_8212C298(ctx, base);
loc_82127504:
	// li r3,22
	ctx.r3.s64 = 22;
loc_82127508:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82127510:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82127530
	if (ctx.cr6.eq) goto loc_82127530;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x82127530
	if (ctx.cr6.lt) goto loc_82127530;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82129a70
	ctx.lr = 0x8212752C;
	sub_82129A70(ctx, base);
	// b 0x821274d0
	goto loc_821274D0;
loc_82127530:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82129fa0
	ctx.lr = 0x8212753C;
	sub_82129FA0(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82127570
	if (!ctx.cr6.eq) goto loc_82127570;
	// bl 0x821294e0
	ctx.lr = 0x82127548;
	sub_821294E0(ctx, base);
	// li r31,22
	ctx.r31.s64 = 22;
loc_8212754C:
	// stw r31,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212c298
	ctx.lr = 0x82127568;
	sub_8212C298(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x82127508
	goto loc_82127508;
loc_82127570:
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x82127504
	if (!ctx.cr6.lt) goto loc_82127504;
	// bl 0x821294e0
	ctx.lr = 0x8212757C;
	sub_821294E0(ctx, base);
	// li r31,34
	ctx.r31.s64 = 34;
	// b 0x8212754c
	goto loc_8212754C;
}
