DEFINE_REX_FUNC(sub_821015D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x821015D8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82101610
	if (ctx.cr6.eq) goto loc_82101610;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r10,r10,4936
	ctx.r10.s64 = ctx.r10.s64 + 4936;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82101608
	if (ctx.cr6.eq) goto loc_82101608;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// ori r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 512;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
loc_82101608:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82101728
	goto loc_82101728;
loc_82101610:
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82101718
	if (ctx.cr6.eq) goto loc_82101718;
	// lwz r9,720(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// addi r10,r31,380
	ctx.r10.s64 = ctx.r31.s64 + 380;
	// rlwinm r4,r9,21,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 21) & 0x1;
loc_82101630:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82101650
	if (!ctx.cr6.eq) goto loc_82101650;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82101630
	if (ctx.cr6.lt) goto loc_82101630;
	// b 0x82101668
	goto loc_82101668;
loc_82101650:
	// addi r11,r11,95
	ctx.r11.s64 = ctx.r11.s64 + 95;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// lwz r11,396(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm r11,r11,4,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0x1;
	// or r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 | ctx.r4.u64;
loc_82101668:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fcaa8
	ctx.lr = 0x82101670;
	sub_820FCAA8(ctx, base);
	// lbz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 168);
	// lbz r10,172(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 172);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821016a4
	if (!ctx.cr6.eq) goto loc_821016A4;
	// lbz r10,173(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 173);
	// lbz r9,169(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 169);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821016a4
	if (!ctx.cr6.eq) goto loc_821016A4;
	// lwz r10,176(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82101718
	if (ctx.cr6.eq) goto loc_82101718;
loc_821016A4:
	// lbz r10,169(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 169);
	// addi r30,r31,200
	ctx.r30.s64 = ctx.r31.s64 + 200;
	// stw r4,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r4.u32);
	// stb r11,172(r31)
	REX_STORE_U8(ctx.r31.u32 + 172, ctx.r11.u8);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// stb r10,173(r31)
	REX_STORE_U8(ctx.r31.u32 + 173, ctx.r10.u8);
	// std r29,200(r31)
	REX_STORE_U64(ctx.r31.u32 + 200, ctx.r29.u64);
	// std r29,208(r31)
	REX_STORE_U64(ctx.r31.u32 + 208, ctx.r29.u64);
	// std r29,216(r31)
	REX_STORE_U64(ctx.r31.u32 + 216, ctx.r29.u64);
	// stw r29,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r29.u32);
	// lbz r6,169(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 169);
	// lbz r5,168(r31)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r31.u32 + 168);
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82138828
	ctx.lr = 0x821016DC;
	sub_82138828(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82101708
	if (ctx.cr0.eq) goto loc_82101708;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x82101708
	if (ctx.cr6.eq) goto loc_82101708;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82136e38
	ctx.lr = 0x821016F4;
	sub_82136E38(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82101728
	if (ctx.cr0.lt) goto loc_82101728;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x82101728
	goto loc_82101728;
loc_82101708:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,19928
	ctx.r11.s64 = ctx.r11.s64 + 19928;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// b 0x82101724
	goto loc_82101724;
loc_82101718:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82104dd8
	ctx.lr = 0x82101724;
	sub_82104DD8(ctx, base);
loc_82101724:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_82101728:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
