DEFINE_REX_FUNC(sub_82122DB8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e8
	ctx.lr = 0x82122DC0;
	__savegprlr_16(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// not r11,r9
	ctx.r11.u64 = ~ctx.r9.u64;
	// addi r10,r31,48
	ctx.r10.s64 = ctx.r31.s64 + 48;
	// rlwinm r11,r11,17,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0x2;
	// mr r18,r8
	ctx.r18.u64 = ctx.r8.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r8,r31,56
	ctx.r8.s64 = ctx.r31.s64 + 56;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// addi r10,r31,64
	ctx.r10.s64 = ctx.r31.s64 + 64;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// mr r20,r5
	ctx.r20.u64 = ctx.r5.u64;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// mr r22,r6
	ctx.r22.u64 = ctx.r6.u64;
	// mr r19,r7
	ctx.r19.u64 = ctx.r7.u64;
	// li r16,0
	ctx.r16.s64 = 0;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r25,0
	ctx.r25.s64 = 0;
	// clrlwi r23,r9,27
	ctx.r23.u64 = ctx.r9.u32 & 0x1F;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82122ecc
	if (ctx.cr6.eq) goto loc_82122ECC;
	// addi r21,r1,80
	ctx.r21.s64 = ctx.r1.s64 + 80;
	// mr r17,r11
	ctx.r17.u64 = ctx.r11.u64;
loc_82122E20:
	// lwz r26,0(r21)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x82122ec0
	if (ctx.cr6.eq) goto loc_82122EC0;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82122ec0
	if (ctx.cr0.eq) goto loc_82122EC0;
	// mulli r11,r29,56
	ctx.r11.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(56));
	// add r28,r11,r22
	ctx.r28.u64 = ctx.r11.u64 + ctx.r22.u64;
loc_82122E44:
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lwz r4,36(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 36);
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r30,r27,-4
	ctx.r30.s64 = ctx.r27.s64 + -4;
	// bl 0x821227d0
	ctx.lr = 0x82122E5C;
	sub_821227D0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82122ea8
	if (ctx.cr0.eq) goto loc_82122EA8;
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// bne cr6,0x82122ea4
	if (!ctx.cr6.eq) goto loc_82122EA4;
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82122e88
	if (!ctx.cr6.lt) goto loc_82122E88;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82126e20
	ctx.lr = 0x82122E84;
	sub_82126E20(ctx, base);
	// b 0x82122e90
	goto loc_82122E90;
loc_82122E88:
	// lis r16,-32646
	ctx.r16.s64 = -2139488256;
	// ori r16,r16,4097
	ctx.r16.u64 = ctx.r16.u64 | 4097;
loc_82122E90:
	// lwz r11,60(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r28,r28,56
	ctx.r28.s64 = ctx.r28.s64 + 56;
	// add r25,r11,r25
	ctx.r25.u64 = ctx.r11.u64 + ctx.r25.u64;
	// b 0x82122ea8
	goto loc_82122EA8;
loc_82122EA4:
	// addi r20,r20,-1
	ctx.r20.s64 = ctx.r20.s64 + -1;
loc_82122EA8:
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x82122ec0
	if (ctx.cr6.eq) goto loc_82122EC0;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82122e44
	if (!ctx.cr0.eq) goto loc_82122E44;
loc_82122EC0:
	// addic. r17,r17,-1
	ctx.xer.ca = ctx.r17.u32 > 0;
	ctx.r17.s64 = ctx.r17.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// addi r21,r21,4
	ctx.r21.s64 = ctx.r21.s64 + 4;
	// bne 0x82122e20
	if (!ctx.cr0.eq) goto loc_82122E20;
loc_82122ECC:
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x82122edc
	if (ctx.cr6.eq) goto loc_82122EDC;
	// lis r16,-32646
	ctx.r16.s64 = -2139488256;
	// ori r16,r16,4105
	ctx.r16.u64 = ctx.r16.u64 | 4105;
loc_82122EDC:
	// stw r29,0(r19)
	REX_STORE_U32(ctx.r19.u32 + 0, ctx.r29.u32);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x82122eec
	if (ctx.cr6.eq) goto loc_82122EEC;
	// stw r25,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r25.u32);
loc_82122EEC:
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82129938
	__restgprlr_16(ctx, base);
	return;
}
