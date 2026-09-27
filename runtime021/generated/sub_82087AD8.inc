DEFINE_REX_FUNC(sub_82087AD8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82087AE0;
	__savegprlr_28(ctx, base);
	// stwu r1,-624(r1)
	ea = -624 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r10,156(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 156);
	// lwz r9,76(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r8,156(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r10,10316(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 10316);
	// bne cr6,0x82087b0c
	if (!ctx.cr6.eq) goto loc_82087B0C;
	// addi r4,r10,12
	ctx.r4.s64 = ctx.r10.s64 + 12;
	// b 0x82087b18
	goto loc_82087B18;
loc_82087B0C:
	// lwz r10,28(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_82087B18:
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x82053a00
	ctx.lr = 0x82087B20;
	sub_82053A00(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r4,r1,244
	ctx.r4.s64 = ctx.r1.s64 + 244;
	// stb r29,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r29.u8);
	// addi r5,r11,-6520
	ctx.r5.s64 = ctx.r11.s64 + -6520;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82075130
	ctx.lr = 0x82087B40;
	sub_82075130(ctx, base);
	// lwz r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// clrlwi r11,r7,16
	ctx.r11.u64 = ctx.r7.u32 & 0xFFFF;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82087bac
	if (!ctx.cr6.gt) goto loc_82087BAC;
loc_82087B60:
	// clrlwi r11,r8,16
	ctx.r11.u64 = ctx.r8.u32 & 0xFFFF;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bge cr6,0x82087b88
	if (!ctx.cr6.lt) goto loc_82087B88;
	// lbzx r5,r10,r6
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r6.u32);
	// cmplwi cr6,r5,47
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 47, ctx.xer);
	// bne cr6,0x82087ba0
	if (!ctx.cr6.eq) goto loc_82087BA0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r11,16
	ctx.r8.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x82087ba0
	goto loc_82087BA0;
loc_82087B88:
	// lbzx r3,r10,r6
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r6.u32);
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r5,r1,320
	ctx.r5.s64 = ctx.r1.s64 + 320;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// stbx r3,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r3.u8);
loc_82087BA0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x82087b60
	if (ctx.cr6.lt) goto loc_82087B60;
loc_82087BAC:
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r8,r1,320
	ctx.r8.s64 = ctx.r1.s64 + 320;
	// addi r11,r1,320
	ctx.r11.s64 = ctx.r1.s64 + 320;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stbx r29,r9,r8
	REX_STORE_U8(ctx.r9.u32 + ctx.r8.u32, ctx.r29.u8);
loc_82087BC0:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82087bc0
	if (!ctx.cr6.eq) goto loc_82087BC0;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// bl 0x82129a70
	ctx.lr = 0x82087BEC;
	sub_82129A70(ctx, base);
	// lwz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// addi r11,r1,84
	ctx.r11.s64 = ctx.r1.s64 + 84;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stbx r29,r8,r9
	REX_STORE_U8(ctx.r8.u32 + ctx.r9.u32, ctx.r29.u8);
loc_82087C00:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82087c00
	if (!ctx.cr6.eq) goto loc_82087C00;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// bl 0x82129a70
	ctx.lr = 0x82087C30;
	sub_82129A70(ctx, base);
	// lwz r9,160(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// addi r10,r1,164
	ctx.r10.s64 = ctx.r1.s64 + 164;
	// addi r4,r1,164
	ctx.r4.s64 = ctx.r1.s64 + 164;
	// stbx r29,r9,r10
	REX_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r29.u8);
	// lwz r8,156(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 156);
	// lwz r7,76(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 76);
	// lwz r31,156(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 156);
	// lwz r6,76(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r5,156(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 156);
	// lwz r3,10316(r5)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + 10316);
	// bl 0x8209d948
	ctx.lr = 0x82087C5C;
	sub_8209D948(ctx, base);
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r11,140(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 140);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82087C74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,4920(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4920);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r31
	ctx.r9.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r30,116(r9)
	REX_STORE_U32(ctx.r9.u32 + 116, ctx.r30.u32);
	// lwz r11,4920(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4920);
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r7,r31
	REX_STORE_U32(ctx.r7.u32 + ctx.r31.u32, ctx.r3.u32);
	// lwz r11,4920(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4920);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r6,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r31
	ctx.r5.u64 = ctx.r11.u64 + ctx.r31.u64;
	// sth r28,124(r5)
	REX_STORE_U16(ctx.r5.u32 + 124, ctx.r28.u16);
	// lwz r11,4920(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4920);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,4920(r31)
	REX_STORE_U32(ctx.r31.u32 + 4920, ctx.r11.u32);
	// cmplwi cr6,r11,400
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 400, ctx.xer);
	// bne cr6,0x82087cd4
	if (!ctx.cr6.eq) goto loc_82087CD4;
	// stw r29,4920(r31)
	REX_STORE_U32(ctx.r31.u32 + 4920, ctx.r29.u32);
loc_82087CD4:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82087CF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,624
	ctx.r1.s64 = ctx.r1.s64 + 624;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
