DEFINE_REX_FUNC(sub_820A2C90) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820A2C98;
	__savegprlr_28(ctx, base);
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// lwz r31,-6628(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820a2ce4
	if (!ctx.cr6.eq) goto loc_820A2CE4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,3700
	ctx.r3.s64 = ctx.r11.s64 + 3700;
	// bl 0x8208c5d8
	ctx.lr = 0x820A2CC8;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r9,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r9.u32);
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820A2CE4:
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a2cf4
	if (ctx.cr6.eq) goto loc_820A2CF4;
	// bl 0x820a7400
	ctx.lr = 0x820A2CF4;
	sub_820A7400(ctx, base);
loc_820A2CF4:
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lbz r10,-22601(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820a2d1c
	if (!ctx.cr6.eq) goto loc_820A2D1C;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r3,r11,-1768
	ctx.r3.s64 = ctx.r11.s64 + -1768;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820A2D1C;
	sub_820A71E8(ctx, base);
loc_820A2D1C:
	// bl 0x820b5eb8
	ctx.lr = 0x820A2D20;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// li r4,32
	ctx.r4.s64 = 32;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820A2D38;
	sub_8209BDD8(ctx, base);
	// stw r3,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// li r6,32
	ctx.r6.s64 = 32;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// bl 0x821274b0
	ctx.lr = 0x820A2D4C;
	sub_821274B0(ctx, base);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// lwz r4,24(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82051b60
	ctx.lr = 0x820A2D68;
	sub_82051B60(ctx, base);
	// lwz r8,24(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// stw r30,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
	// lhz r7,2(r8)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + 2);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x820a2d90
	if (!ctx.cr6.eq) goto loc_820A2D90;
	// li r29,1
	ctx.r29.s64 = 1;
	// li r11,3
	ctx.r11.s64 = 3;
	// slw r10,r29,r30
	ctx.r10.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r29.u32 << (ctx.r30.u8 & 0x3F));
	// stw r10,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r10.u32);
	// b 0x820a2db0
	goto loc_820A2DB0;
loc_820A2D90:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a4328
	ctx.lr = 0x820A2D9C;
	sub_820A4328(ctx, base);
	// li r29,1
	ctx.r29.s64 = 1;
	// li r11,2
	ctx.r11.s64 = 2;
	// slw r10,r29,r30
	ctx.r10.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r29.u32 << (ctx.r30.u8 & 0x3F));
	// or r9,r3,r10
	ctx.r9.u64 = ctx.r3.u64 | ctx.r10.u64;
	// stw r9,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r9.u32);
loc_820A2DB0:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r5,r31,20
	ctx.r5.s64 = ctx.r31.s64 + 20;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,120(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A2DD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r30,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// addi r5,r1,116
	ctx.r5.s64 = ctx.r1.s64 + 116;
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,120(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 120);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820A2DFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r5,120(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// clrlwi r7,r5,31
	ctx.r7.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820a2e14
	if (ctx.cr6.eq) goto loc_820A2E14;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_820A2E14:
	// rlwinm r10,r5,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a2e24
	if (ctx.cr6.eq) goto loc_820A2E24;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_820A2E24:
	// rlwinm r10,r5,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a2e34
	if (ctx.cr6.eq) goto loc_820A2E34;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_820A2E34:
	// rlwinm r10,r5,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a2e44
	if (ctx.cr6.eq) goto loc_820A2E44;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_820A2E44:
	// lwz r9,24(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r9.u32 + 4);
	// lhz r9,6(r9)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r9.u32 + 6);
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplw cr6,r7,r9
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x820a2e60
	if (ctx.cr6.lt) goto loc_820A2E60;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
loc_820A2E60:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// subf r6,r7,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r7.u64;
	// lwz r4,112(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// lwz r10,120(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r8,112(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820A2E90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stb r30,1352(r31)
	REX_STORE_U8(ctx.r31.u32 + 1352, ctx.r30.u8);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x820a2ec0
	if (!ctx.cr6.lt) goto loc_820A2EC0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,3760
	ctx.r3.s64 = ctx.r11.s64 + 3760;
	// bl 0x8208c5d8
	ctx.lr = 0x820A2EAC;
	sub_8208C5D8(ctx, base);
	// stw r29,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r29.u32);
	// stw r30,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r30.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820A2EC0:
	// stw r30,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r30.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r30,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r30.u32);
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
