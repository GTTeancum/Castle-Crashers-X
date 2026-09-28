DEFINE_REX_FUNC(sub_82069F40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e0
	ctx.lr = 0x82069F48;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r18,0
	ctx.r18.s64 = 0;
	// addi r4,r11,-10168
	ctx.r4.s64 = ctx.r11.s64 + -10168;
	// mr r17,r18
	ctx.r17.u64 = ctx.r18.u64;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// mr r14,r18
	ctx.r14.u64 = ctx.r18.u64;
	// bl 0x8209d948
	ctx.lr = 0x82069F6C;
	sub_8209D948(ctx, base);
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// addi r4,r9,-10156
	ctx.r4.s64 = ctx.r9.s64 + -10156;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x8209d948
	ctx.lr = 0x82069F84;
	sub_8209D948(ctx, base);
	// lwz r8,8(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// addi r4,r7,-10144
	ctx.r4.s64 = ctx.r7.s64 + -10144;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x8209d948
	ctx.lr = 0x82069F9C;
	sub_8209D948(ctx, base);
	// lwz r6,48(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// mr r29,r18
	ctx.r29.u64 = ctx.r18.u64;
	// lis r24,-32218
	ctx.r24.s64 = -2111438848;
	// li r19,1
	ctx.r19.s64 = 1;
	// lwz r5,292(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 292);
	// li r16,40
	ctx.r16.s64 = 40;
	// lwz r15,56(r5)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r5.u32 + 56);
loc_82069FBC:
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// lwz r10,48(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// addi r9,r11,69
	ctx.r9.s64 = ctx.r11.s64 + 69;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r10
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwz r31,56(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r5,100(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 100);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82069FE8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// bl 0x82085078
	ctx.lr = 0x82069FF0;
	sub_82085078(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8206A008;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// bl 0x82085078
	ctx.lr = 0x8206A010;
	sub_82085078(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8206A028;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// bl 0x82085078
	ctx.lr = 0x8206A030;
	sub_82085078(ctx, base);
	// addi r25,r29,1
	ctx.r25.s64 = ctx.r29.s64 + 1;
	// lhz r8,16(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 16);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// clrlwi r11,r25,16
	ctx.r11.u64 = ctx.r25.u32 & 0xFFFF;
	// lwz r10,48(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// cmplw cr6,r29,r8
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r8.u32, ctx.xer);
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// bge cr6,0x8206a310
	if (!ctx.cr6.lt) goto loc_8206A310;
	// rlwinm r28,r9,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwzx r8,r28,r10
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r10.u32);
	// stb r18,21(r8)
	REX_STORE_U8(ctx.r8.u32 + 21, ctx.r18.u8);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r6,236(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 236);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8206A074;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r5,0(r27)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r11,236(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 236);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8206A08C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-6628(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8206a0ec
	if (!ctx.cr6.eq) goto loc_8206A0EC;
	// lwz r9,120(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mr r10,r18
	ctx.r10.u64 = ctx.r18.u64;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8206a0b8
	if (ctx.cr6.eq) goto loc_8206A0B8;
	// mr r10,r19
	ctx.r10.u64 = ctx.r19.u64;
loc_8206A0B8:
	// rlwinm r8,r9,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8206a0c8
	if (ctx.cr6.eq) goto loc_8206A0C8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_8206A0C8:
	// rlwinm r8,r9,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8206a0d8
	if (ctx.cr6.eq) goto loc_8206A0D8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_8206A0D8:
	// rlwinm r9,r9,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206a114
	if (ctx.cr6.eq) goto loc_8206A114;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// b 0x8206a114
	goto loc_8206A114;
loc_8206A0EC:
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206a110
	if (ctx.cr6.eq) goto loc_8206A110;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206A10C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-6628(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
loc_8206A110:
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_8206A114:
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8206a288
	if (!ctx.cr6.lt) goto loc_8206A288;
	// clrlwi r10,r14,16
	ctx.r10.u64 = ctx.r14.u32 & 0xFFFF;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// bl 0x820a3b88
	ctx.lr = 0x8206A134;
	sub_820A3B88(ctx, base);
	// lwz r9,48(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// clrlwi r31,r3,24
	ctx.r31.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,-6628(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// lwzx r14,r28,r9
	ctx.r14.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r9.u32);
	// bl 0x820a3cc8
	ctx.lr = 0x8206A14C;
	sub_820A3CC8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82067518
	ctx.lr = 0x8206A15C;
	sub_82067518(ctx, base);
	// lwz r6,48(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r7,r8,-27272
	ctx.r7.s64 = ctx.r8.s64 + -27272;
	// lwzx r5,r28,r6
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r6.u32);
	// stw r30,24(r5)
	REX_STORE_U32(ctx.r5.u32 + 24, ctx.r30.u32);
	// stw r7,28(r5)
	REX_STORE_U32(ctx.r5.u32 + 28, ctx.r7.u32);
	// bne cr6,0x8206a198
	if (!ctx.cr6.eq) goto loc_8206A198;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206A194;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8206a1c4
	goto loc_8206A1C4;
loc_8206A198:
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// bne cr6,0x8206a1c4
	if (!ctx.cr6.eq) goto loc_8206A1C4;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206A1B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r17,16
	ctx.r11.u64 = ctx.r17.u32 & 0xFFFF;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r17,r9,16
	ctx.r17.u64 = ctx.r9.u32 & 0xFFFF;
loc_8206A1C4:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,-6628(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// bl 0x820a3c28
	ctx.lr = 0x8206A1D0;
	sub_820A3C28(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206a23c
	if (!ctx.cr6.eq) goto loc_8206A23C;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,-6628(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// bl 0x820a3d60
	ctx.lr = 0x8206A1E8;
	sub_820A3D60(ctx, base);
	// addi r11,r3,-60
	ctx.r11.s64 = ctx.r3.s64 + -60;
	// divwu r31,r11,r16
	ctx.r31.u64 = uint32_t(ctx.r16.u32 ? ctx.r11.u32 / ctx.r16.u32 : 0);
	// cmpwi cr6,r31,5
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 5, ctx.xer);
	// ble cr6,0x8206a200
	if (!ctx.cr6.gt) goto loc_8206A200;
	// li r31,5
	ctx.r31.s64 = 5;
	// b 0x8206a20c
	goto loc_8206A20C;
loc_8206A200:
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
	// bge cr6,0x8206a20c
	if (!ctx.cr6.lt) goto loc_8206A20C;
	// mr r31,r19
	ctx.r31.u64 = ctx.r19.u64;
loc_8206A20C:
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r10,236(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 236);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206A224;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// clrlwi r4,r31,16
	ctx.r4.u64 = ctx.r31.u32 & 0xFFFF;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r8,164(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 164);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8206A23C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8206A23C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,-6628(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// bl 0x820a3ae8
	ctx.lr = 0x8206A248;
	sub_820A3AE8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// beq cr6,0x8206a274
	if (ctx.cr6.eq) goto loc_8206A274;
	// li r4,2
	ctx.r4.s64 = 2;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206A26C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r14,80(r1)
	ctx.r14.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// b 0x8206a360
	goto loc_8206A360;
loc_8206A274:
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206A280;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r14,80(r1)
	ctx.r14.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// b 0x8206a360
	goto loc_8206A360;
loc_8206A288:
	// lhz r11,14(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 14);
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lwzx r3,r28,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// bne cr6,0x8206a2bc
	if (!ctx.cr6.eq) goto loc_8206A2BC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82067230
	ctx.lr = 0x8206A2A8;
	sub_82067230(ctx, base);
	// lwz r10,48(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lwzx r9,r28,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r10.u32);
	// stw r30,24(r9)
	REX_STORE_U32(ctx.r9.u32 + 24, ctx.r30.u32);
	// stw r18,28(r9)
	REX_STORE_U32(ctx.r9.u32 + 28, ctx.r18.u32);
	// b 0x8206a2dc
	goto loc_8206A2DC;
loc_8206A2BC:
	// li r4,478
	ctx.r4.s64 = 478;
	// bl 0x82067230
	ctx.lr = 0x8206A2C4;
	sub_82067230(ctx, base);
	// lwz r8,48(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r10,-27272
	ctx.r9.s64 = ctx.r10.s64 + -27272;
	// lwzx r7,r28,r8
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r8.u32);
	// stw r30,24(r7)
	REX_STORE_U32(ctx.r7.u32 + 24, ctx.r30.u32);
	// stw r9,28(r7)
	REX_STORE_U32(ctx.r7.u32 + 28, ctx.r9.u32);
loc_8206A2DC:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206A2F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r23)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// lwz r8,164(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 164);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8206A30C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8206a360
	goto loc_8206A360;
loc_8206A310:
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r7,r8,r10
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// stb r19,21(r7)
	REX_STORE_U8(ctx.r7.u32 + 21, ctx.r19.u8);
	// lwz r6,48(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lwzx r3,r8,r6
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// bl 0x82067230
	ctx.lr = 0x8206A330;
	sub_82067230(ctx, base);
	// lwz r5,0(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r11,164(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 164);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8206A348;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,236(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 236);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8206A360;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8206A360:
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// cmplwi cr6,r25,4
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 4, ctx.xer);
	// blt cr6,0x82069fbc
	if (ctx.cr6.lt) goto loc_82069FBC;
	// lwz r11,-6628(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// lwz r10,140(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8206a4b8
	if (!ctx.cr6.eq) goto loc_8206A4B8;
	// clrlwi r9,r14,16
	ctx.r9.u64 = ctx.r14.u32 & 0xFFFF;
	// clrlwi r11,r17,16
	ctx.r11.u64 = ctx.r17.u32 & 0xFFFF;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8206a4b8
	if (!ctx.cr6.eq) goto loc_8206A4B8;
	// lwz r10,-6628(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
	// lwz r10,120(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 120);
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8206a3a8
	if (ctx.cr6.eq) goto loc_8206A3A8;
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
loc_8206A3A8:
	// rlwinm r8,r10,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8206a3b8
	if (ctx.cr6.eq) goto loc_8206A3B8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_8206A3B8:
	// rlwinm r8,r10,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8206a3c8
	if (ctx.cr6.eq) goto loc_8206A3C8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_8206A3C8:
	// rlwinm r10,r10,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206a3d8
	if (ctx.cr6.eq) goto loc_8206A3D8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_8206A3D8:
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8206a4b8
	if (!ctx.cr6.gt) goto loc_8206A4B8;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// addi r31,r11,604
	ctx.r31.s64 = ctx.r11.s64 + 604;
	// lwz r11,604(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 604);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r11,120
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 120, ctx.xer);
	// ble cr6,0x8206a458
	if (!ctx.cr6.gt) goto loc_8206A458;
	// lwz r10,0(r15)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r15.u32 + 0);
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// lwz r9,164(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 164);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8206A41C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8206a44c
	if (ctx.cr6.lt) goto loc_8206A44C;
	// beq cr6,0x8206a440
	if (ctx.cr6.eq) goto loc_8206A440;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x8206a454
	if (!ctx.cr6.eq) goto loc_8206A454;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8206aad0
	ctx.lr = 0x8206A43C;
	sub_8206AAD0(ctx, base);
	// b 0x8206a454
	goto loc_8206A454;
loc_8206A440:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8206ab50
	ctx.lr = 0x8206A448;
	sub_8206AB50(ctx, base);
	// b 0x8206a454
	goto loc_8206A454;
loc_8206A44C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8206aad0
	ctx.lr = 0x8206A454;
	sub_8206AAD0(ctx, base);
loc_8206A454:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_8206A458:
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// ble cr6,0x8206a478
	if (!ctx.cr6.gt) goto loc_8206A478;
	// lwz r11,0(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + 0);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// b 0x8206a4dc
	goto loc_8206A4DC;
loc_8206A478:
	// cmplwi cr6,r11,60
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 60, ctx.xer);
	// ble cr6,0x8206a498
	if (!ctx.cr6.gt) goto loc_8206A498;
	// lwz r11,0(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// b 0x8206a4dc
	goto loc_8206A4DC;
loc_8206A498:
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// ble cr6,0x8206a4e0
	if (!ctx.cr6.gt) goto loc_8206A4E0;
	// lwz r11,0(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// b 0x8206a4dc
	goto loc_8206A4DC;
loc_8206A4B8:
	// lwz r9,0(r15)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r15.u32 + 0);
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r31,r10,604
	ctx.r31.s64 = ctx.r10.s64 + 604;
	// lwz r8,164(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 164);
	// stw r11,604(r10)
	REX_STORE_U32(ctx.r10.u32 + 604, ctx.r11.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8206A4DC:
	// bctrl 
	ctx.lr = 0x8206A4E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8206A4E0:
	// lwz r3,-6628(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// bl 0x820a3900
	ctx.lr = 0x8206A4E8;
	sub_820A3900(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x8206a508
	if (ctx.cr6.eq) goto loc_8206A508;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8206a508
	if (ctx.cr6.eq) goto loc_8206A508;
	// li r10,3
	ctx.r10.s64 = 3;
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
	// sth r10,44(r30)
	REX_STORE_U16(ctx.r30.u32 + 44, ctx.r10.u16);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8206A508:
	// clrlwi r11,r14,16
	ctx.r11.u64 = ctx.r14.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206a588
	if (!ctx.cr6.eq) goto loc_8206A588;
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lwz r11,608(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 608);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,608(r9)
	REX_STORE_U32(ctx.r9.u32 + 608, ctx.r11.u32);
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// ble cr6,0x8206a594
	if (!ctx.cr6.gt) goto loc_8206A594;
	// lwz r8,0(r15)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r15.u32 + 0);
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
	// mr r10,r18
	ctx.r10.u64 = ctx.r18.u64;
	// stw r11,608(r9)
	REX_STORE_U32(ctx.r9.u32 + 608, ctx.r11.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// lwz r7,164(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 164);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8206A554;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-6628(r24)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// bl 0x820a37b8
	ctx.lr = 0x8206A560;
	sub_820A37B8(ctx, base);
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,15
	ctx.r5.s64 = 15;
	// sth r6,44(r30)
	REX_STORE_U16(ctx.r30.u32 + 44, ctx.r6.u16);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82054d38
	ctx.lr = 0x8206A578;
	sub_82054D38(ctx, base);
	// lwz r11,-6628(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// stw r18,140(r11)
	REX_STORE_U32(ctx.r11.u32 + 140, ctx.r18.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
loc_8206A588:
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
	// stw r11,608(r10)
	REX_STORE_U32(ctx.r10.u32 + 608, ctx.r11.u32);
loc_8206A594:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
}
