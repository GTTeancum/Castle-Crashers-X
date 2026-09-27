DEFINE_REX_FUNC(sub_82080E08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82080E10;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,156(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// addi r31,r11,10372
	ctx.r31.s64 = ctx.r11.s64 + 10372;
	// lwz r11,15396(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 15396);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,5024(r31)
	REX_STORE_U32(ctx.r31.u32 + 5024, ctx.r11.u32);
	// lwzx r30,r9,r31
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// and r7,r8,r12
	ctx.r7.u64 = ctx.r8.u64 & ctx.r12.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x82080e8c
	if (ctx.cr6.eq) goto loc_82080E8C;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lhz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82080e8c
	if (ctx.cr6.eq) goto loc_82080E8C;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82080e80
	if (!ctx.cr6.eq) goto loc_82080E80;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82080E80;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82080E80:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x82066ea8
	ctx.lr = 0x82080E8C;
	sub_82066EA8(ctx, base);
loc_82080E8C:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r10,5024(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,76(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwzx r30,r9,r31
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// lwz r11,156(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 156);
	// addi r31,r11,10372
	ctx.r31.s64 = ctx.r11.s64 + 10372;
	// lwz r11,15396(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 15396);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,5024(r31)
	REX_STORE_U32(ctx.r31.u32 + 5024, ctx.r11.u32);
	// lwzx r29,r7,r31
	ctx.r29.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r31.u32);
	// lwz r6,0(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// and r5,r6,r12
	ctx.r5.u64 = ctx.r6.u64 & ctx.r12.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x82080f0c
	if (ctx.cr6.eq) goto loc_82080F0C;
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lhz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82080f0c
	if (ctx.cr6.eq) goto loc_82080F0C;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82080f00
	if (!ctx.cr6.eq) goto loc_82080F00;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82080F00;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82080F00:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x82066ea8
	ctx.lr = 0x82080F0C;
	sub_82066EA8(ctx, base);
loc_82080F0C:
	// lwz r9,5024(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r29,0
	ctx.r29.s64 = 0;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// lwzx r31,r8,r31
	ctx.r31.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	// beq cr6,0x82080f50
	if (ctx.cr6.eq) goto loc_82080F50;
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x82080f50
	if (ctx.cr6.eq) goto loc_82080F50;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x82080f50
	if (!ctx.cr6.eq) goto loc_82080F50;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82082cd0
	ctx.lr = 0x82080F4C;
	sub_82082CD0(ctx, base);
	// b 0x82080f54
	goto loc_82080F54;
loc_82080F50:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_82080F54:
	// li r11,2
	ctx.r11.s64 = 2;
	// stb r3,4(r31)
	REX_STORE_U8(ctx.r31.u32 + 4, ctx.r3.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r11,156(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 156);
	// addi r11,r11,10372
	ctx.r11.s64 = ctx.r11.s64 + 10372;
	// lwz r8,5024(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 5024);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r31,r7,r11
	REX_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r31.u32);
	// lwz r10,5024(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 5024);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r6,5024(r11)
	REX_STORE_U32(ctx.r11.u32 + 5024, ctx.r6.u32);
	// stb r29,8(r30)
	REX_STORE_U8(ctx.r30.u32 + 8, ctx.r29.u8);
	// stw r29,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
