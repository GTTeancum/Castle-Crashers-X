DEFINE_REX_FUNC(sub_8207ECC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8207ECC8;
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
	// beq cr6,0x8207ed44
	if (ctx.cr6.eq) goto loc_8207ED44;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lhz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207ed44
	if (ctx.cr6.eq) goto loc_8207ED44;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8207ed38
	if (!ctx.cr6.eq) goto loc_8207ED38;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207ED38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207ED38:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x82066ea8
	ctx.lr = 0x8207ED44;
	sub_82066EA8(ctx, base);
loc_8207ED44:
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
	// beq cr6,0x8207edc4
	if (ctx.cr6.eq) goto loc_8207EDC4;
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lhz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207edc4
	if (ctx.cr6.eq) goto loc_8207EDC4;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8207edb8
	if (!ctx.cr6.eq) goto loc_8207EDB8;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207EDB8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207EDB8:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x82066ea8
	ctx.lr = 0x8207EDC4;
	sub_82066EA8(ctx, base);
loc_8207EDC4:
	// lwz r10,5024(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// lwzx r31,r8,r31
	ctx.r31.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bne cr6,0x8207ee0c
	if (!ctx.cr6.eq) goto loc_8207EE0C;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// bne cr6,0x8207ee00
	if (!ctx.cr6.eq) goto loc_8207EE00;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
loc_8207EE00:
	// stb r11,8(r30)
	REX_STORE_U8(ctx.r30.u32 + 8, ctx.r11.u8);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// b 0x8207ee64
	goto loc_8207EE64;
loc_8207EE0C:
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x8207ee20
	if (!ctx.cr6.eq) goto loc_8207EE20;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// b 0x8207ee5c
	goto loc_8207EE5C;
loc_8207EE20:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,156(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// addi r3,r11,10372
	ctx.r3.s64 = ctx.r11.s64 + 10372;
	// bl 0x82082488
	ctx.lr = 0x8207EE34;
	sub_82082488(ctx, base);
	// lwz r9,0(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r8,76(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r4,156(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + 156);
	// bl 0x82082f18
	ctx.lr = 0x8207EE50;
	sub_82082F18(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,8(r30)
	REX_STORE_U8(ctx.r30.u32 + 8, ctx.r11.u8);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
loc_8207EE5C:
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stb r11,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r11.u8);
loc_8207EE64:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r9,r10,r12
	ctx.r9.u64 = ctx.r10.u64 & ctx.r12.u64;
	// lwz r8,76(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r11,156(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 156);
	// addi r31,r11,10372
	ctx.r31.s64 = ctx.r11.s64 + 10372;
	// beq cr6,0x8207eea4
	if (ctx.cr6.eq) goto loc_8207EEA4;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lhz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207eea4
	if (ctx.cr6.eq) goto loc_8207EEA4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82066ea8
	ctx.lr = 0x8207EEA4;
	sub_82066EA8(ctx, base);
loc_8207EEA4:
	// lwz r11,5024(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r10,r31
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, ctx.r29.u32);
	// lwz r11,5024(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,5024(r31)
	REX_STORE_U32(ctx.r31.u32 + 5024, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
