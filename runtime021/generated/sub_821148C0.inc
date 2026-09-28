DEFINE_REX_FUNC(sub_821148C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x821148C8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r30,12(r29)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// cmpwi cr6,r11,-2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -2, ctx.xer);
	// bne cr6,0x82114a64
	if (!ctx.cr6.eq) goto loc_82114A64;
	// lwz r6,32(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// blt cr6,0x82114a7c
	if (ctx.cr6.lt) goto loc_82114A7C;
	// lwz r10,168(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 168);
	// lwz r11,28(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// rlwinm. r10,r10,0,2,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82114910
	if (ctx.cr0.eq) goto loc_82114910;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 11, ctx.xer);
	// beq cr6,0x82114928
	if (ctx.cr6.eq) goto loc_82114928;
	// b 0x82114a7c
	goto loc_82114A7C;
loc_82114910:
	// lwz r10,152(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82114928
	if (!ctx.cr6.eq) goto loc_82114928;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5, ctx.xer);
	// bne cr6,0x82114a7c
	if (!ctx.cr6.eq) goto loc_82114A7C;
loc_82114928:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r10,r10,-5
	ctx.r10.s64 = ctx.r10.s64 + -5;
	// cmplwi cr6,r10,10
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 10, ctx.xer);
	// bgt cr6,0x82114a7c
	if (ctx.cr6.gt) goto loc_82114A7C;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-20696
	ctx.r12.s64 = ctx.r12.s64 + -20696;
	// lbzx r0,r12,r10
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r10.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32239
	ctx.r12.s64 = -2112815104;
	// addi r12,r12,18784
	ctx.r12.s64 = ctx.r12.s64 + 18784;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	switch (ctx.r10.u32) {
	case 0:
		goto loc_82114960;
	case 1:
		goto loc_82114974;
	case 2:
		goto loc_82114988;
	case 3:
		goto loc_8211499C;
	case 4:
		goto loc_821149C8;
	case 5:
		goto loc_821149DC;
	case 6:
		goto loc_821149FC;
	case 7:
		goto loc_82114A10;
	case 8:
		goto loc_82114A24;
	case 9:
		goto loc_82114A34;
	case 10:
		goto loc_82114A48;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82114960:
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82113cd8
	ctx.lr = 0x82114970;
	sub_82113CD8(ctx, base);
	// b 0x82114a58
	goto loc_82114A58;
loc_82114974:
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210ec50
	ctx.lr = 0x82114984;
	sub_8210EC50(ctx, base);
	// b 0x82114a58
	goto loc_82114A58;
loc_82114988:
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210ee60
	ctx.lr = 0x82114998;
	sub_8210EE60(ctx, base);
	// b 0x82114a58
	goto loc_82114A58;
loc_8211499C:
	// cmplwi cr6,r6,9
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 9, ctx.xer);
	// bge cr6,0x821149b0
	if (!ctx.cr6.lt) goto loc_821149B0;
loc_821149A4:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4106
	ctx.r3.u64 = ctx.r3.u64 | 4106;
	// b 0x82114a58
	goto loc_82114A58;
loc_821149B0:
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// lwz r4,1(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 1);
	// lwz r5,5(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 5);
	// lwz r6,60(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// bl 0x82116ad0
	ctx.lr = 0x821149C4;
	sub_82116AD0(ctx, base);
	// b 0x82114a58
	goto loc_82114A58;
loc_821149C8:
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210cdb0
	ctx.lr = 0x821149D8;
	sub_8210CDB0(ctx, base);
	// b 0x82114a58
	goto loc_82114A58;
loc_821149DC:
	// cmplwi cr6,r6,9
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 9, ctx.xer);
	// blt cr6,0x821149a4
	if (ctx.cr6.lt) goto loc_821149A4;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r4,1(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 1);
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// lwz r6,5(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 5);
	// bl 0x82116ee8
	ctx.lr = 0x821149F8;
	sub_82116EE8(ctx, base);
	// b 0x82114a58
	goto loc_82114A58;
loc_821149FC:
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82111848
	ctx.lr = 0x82114A0C;
	sub_82111848(ctx, base);
	// b 0x82114a58
	goto loc_82114A58;
loc_82114A10:
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210f0b8
	ctx.lr = 0x82114A20;
	sub_8210F0B8(ctx, base);
	// b 0x82114a58
	goto loc_82114A58;
loc_82114A24:
	// cmplwi cr6,r6,5
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 5, ctx.xer);
	// blt cr6,0x821149a4
	if (ctx.cr6.lt) goto loc_821149A4;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82114a58
	goto loc_82114A58;
loc_82114A34:
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210f1b0
	ctx.lr = 0x82114A44;
	sub_8210F1B0(ctx, base);
	// b 0x82114a58
	goto loc_82114A58;
loc_82114A48:
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82111a58
	ctx.lr = 0x82114A58;
	sub_82111A58(ctx, base);
loc_82114A58:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82114b94
	if (!ctx.cr6.eq) goto loc_82114B94;
	// b 0x82114ba8
	goto loc_82114BA8;
loc_82114A64:
	// lwz r10,168(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 168);
	// rlwinm. r9,r10,0,2,2
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82114a7c
	if (!ctx.cr0.eq) goto loc_82114A7C;
	// lwz r9,152(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82114a88
	if (!ctx.cr6.eq) goto loc_82114A88;
loc_82114A7C:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4106
	ctx.r3.u64 = ctx.r3.u64 | 4106;
	// b 0x82114b94
	goto loc_82114B94;
loc_82114A88:
	// lwz r9,144(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82114b8c
	if (ctx.cr6.eq) goto loc_82114B8C;
	// rlwinm. r10,r10,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82114b8c
	if (!ctx.cr0.eq) goto loc_82114B8C;
	// lwz r9,36(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// clrlwi r8,r11,8
	ctx.r8.u64 = ctx.r11.u32 & 0xFFFFFF;
	// lwz r10,24(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// rlwinm. r9,r9,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82114af8
	if (ctx.cr0.eq) goto loc_82114AF8;
	// lis r9,255
	ctx.r9.s64 = 16711680;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ori r9,r9,65534
	ctx.r9.u64 = ctx.r9.u64 | 65534;
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// bne cr6,0x82114ac8
	if (!ctx.cr6.eq) goto loc_82114AC8;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
loc_82114AC8:
	// subfic r8,r10,127
	ctx.xer.ca = ctx.r10.u32 <= 127;
	ctx.r8.u64 = static_cast<uint64_t>(127) - ctx.r10.u64;
	// subfic r7,r10,-1
	ctx.xer.ca = ctx.r10.u32 <= 4294967295;
	ctx.r7.u64 = static_cast<uint64_t>(-1) - ctx.r10.u64;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// rlwinm r8,r8,18,0,13
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 18) & 0xFFFC0000;
	// rlwinm r7,r7,25,0,6
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0xFE000000;
	// ori r6,r6,65534
	ctx.r6.u64 = ctx.r6.u64 | 65534;
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// subf r9,r9,r6
	ctx.r9.u64 = ctx.r6.u64 - ctx.r9.u64;
	// rlwinm r11,r11,18,14,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 18) & 0x20000;
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
	// b 0x82114b18
	goto loc_82114B18;
loc_82114AF8:
	// lwz r9,60(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// rlwinm r11,r11,19,14,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 19) & 0x3F800;
	// lwz r7,172(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// or r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 | ctx.r8.u64;
	// rlwinm r9,r9,25,0,6
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0xFE000000;
	// rlwinm r8,r7,18,0,13
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 18) & 0xFFFC0000;
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
	// or r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 | ctx.r11.u64;
loc_82114B18:
	// lwz r8,136(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r9,48
	ctx.r9.s64 = 48;
	// lwz r7,132(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r9,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r9.u32);
	// addi r9,r31,740
	ctx.r9.s64 = ctx.r31.s64 + 740;
	// stw r6,744(r31)
	REX_STORE_U32(ctx.r31.u32 + 744, ctx.r6.u32);
	// stw r8,748(r31)
	REX_STORE_U32(ctx.r31.u32 + 748, ctx.r8.u32);
	// stw r7,752(r31)
	REX_STORE_U32(ctx.r31.u32 + 752, ctx.r7.u32);
	// lwz r8,60(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// stw r8,756(r31)
	REX_STORE_U32(ctx.r31.u32 + 756, ctx.r8.u32);
	// lwz r8,72(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 72);
	// stw r11,764(r31)
	REX_STORE_U32(ctx.r31.u32 + 764, ctx.r11.u32);
	// stw r8,760(r31)
	REX_STORE_U32(ctx.r31.u32 + 760, ctx.r8.u32);
	// lwz r11,20(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// stw r11,768(r31)
	REX_STORE_U32(ctx.r31.u32 + 768, ctx.r11.u32);
	// stw r10,772(r31)
	REX_STORE_U32(ctx.r31.u32 + 772, ctx.r10.u32);
	// lwz r11,28(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// stw r11,776(r31)
	REX_STORE_U32(ctx.r31.u32 + 776, ctx.r11.u32);
	// lwz r11,32(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// stw r11,780(r31)
	REX_STORE_U32(ctx.r31.u32 + 780, ctx.r11.u32);
	// lwz r11,36(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// stw r11,784(r31)
	REX_STORE_U32(ctx.r31.u32 + 784, ctx.r11.u32);
	// stw r9,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// lwz r11,820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r29,808(r31)
	REX_STORE_U32(ctx.r31.u32 + 808, ctx.r29.u32);
	// stw r11,820(r31)
	REX_STORE_U32(ctx.r31.u32 + 820, ctx.r11.u32);
	// b 0x82114bb0
	goto loc_82114BB0;
loc_82114B8C:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4098
	ctx.r3.u64 = ctx.r3.u64 | 4098;
loc_82114B94:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821138a0
	ctx.lr = 0x82114BA8;
	sub_821138A0(ctx, base);
loc_82114BA8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821151c8
	ctx.lr = 0x82114BB0;
	sub_821151C8(ctx, base);
loc_82114BB0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
