DEFINE_REX_FUNC(sub_82069768) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e0
	ctx.lr = 0x82069770;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r17,0
	ctx.r17.s64 = 0;
	// sth r17,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r17.u16);
	// mr r14,r17
	ctx.r14.u64 = ctx.r17.u64;
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lwz r18,300(r11)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r11.u32 + 300);
	// lwz r10,56(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 56);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820697b0
	if (ctx.cr6.eq) goto loc_820697B0;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,236(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 236);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820697B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820697B0:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x82067230
	ctx.lr = 0x820697C0;
	sub_82067230(ctx, base);
	// lwz r10,48(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r11,-10168
	ctx.r4.s64 = ctx.r11.s64 + -10168;
	// lhz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// extsh r16,r8
	ctx.r16.s64 = ctx.r8.s16;
	// bl 0x8209d948
	ctx.lr = 0x820697E0;
	sub_8209D948(ctx, base);
	// lwz r7,8(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// addi r4,r6,-10156
	ctx.r4.s64 = ctx.r6.s64 + -10156;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x8209d948
	ctx.lr = 0x820697F8;
	sub_8209D948(ctx, base);
	// lwz r5,48(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// addi r4,r10,-10144
	ctx.r4.s64 = ctx.r10.s64 + -10144;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,292(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 292);
	// lwz r19,56(r9)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r9.u32 + 56);
	// bl 0x8209d948
	ctx.lr = 0x8206981C;
	sub_8209D948(ctx, base);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// mr r29,r17
	ctx.r29.u64 = ctx.r17.u64;
	// li r15,1
	ctx.r15.s64 = 1;
	// lis r24,-32218
	ctx.r24.s64 = -2111438848;
loc_8206982C:
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
	ctx.lr = 0x82069858;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// bl 0x82085078
	ctx.lr = 0x82069860;
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
	ctx.lr = 0x82069878;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// bl 0x82085078
	ctx.lr = 0x82069880;
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
	ctx.lr = 0x82069898;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// bl 0x82085078
	ctx.lr = 0x820698A0;
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
	// bge cr6,0x82069c38
	if (!ctx.cr6.lt) goto loc_82069C38;
	// rlwinm r28,r9,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwzx r8,r28,r10
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r10.u32);
	// stb r17,21(r8)
	REX_STORE_U8(ctx.r8.u32 + 21, ctx.r17.u8);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r6,236(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 236);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820698E4;
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
	ctx.lr = 0x820698FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-6628(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8206995c
	if (!ctx.cr6.eq) goto loc_8206995C;
	// lwz r9,120(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mr r10,r17
	ctx.r10.u64 = ctx.r17.u64;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82069928
	if (ctx.cr6.eq) goto loc_82069928;
	// mr r10,r15
	ctx.r10.u64 = ctx.r15.u64;
loc_82069928:
	// rlwinm r8,r9,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82069938
	if (ctx.cr6.eq) goto loc_82069938;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_82069938:
	// rlwinm r8,r9,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82069948
	if (ctx.cr6.eq) goto loc_82069948;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_82069948:
	// rlwinm r9,r9,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82069984
	if (ctx.cr6.eq) goto loc_82069984;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// b 0x82069984
	goto loc_82069984;
loc_8206995C:
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82069980
	if (ctx.cr6.eq) goto loc_82069980;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206997C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-6628(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
loc_82069980:
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_82069984:
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82069b64
	if (!ctx.cr6.lt) goto loc_82069B64;
	// clrlwi r10,r14,16
	ctx.r10.u64 = ctx.r14.u32 & 0xFFFF;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// sth r11,82(r1)
	REX_STORE_U16(ctx.r1.u32 + 82, ctx.r11.u16);
	// bl 0x820a3b88
	ctx.lr = 0x820699A4;
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
	ctx.lr = 0x820699BC;
	sub_820A3CC8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82067518
	ctx.lr = 0x820699CC;
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
	// bne cr6,0x82069a08
	if (!ctx.cr6.eq) goto loc_82069A08;
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
	ctx.lr = 0x82069A04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82069a34
	goto loc_82069A34;
loc_82069A08:
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// bne cr6,0x82069a34
	if (!ctx.cr6.eq) goto loc_82069A34;
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
	ctx.lr = 0x82069A28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// sth r8,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r8.u16);
loc_82069A34:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,-6628(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// bl 0x820a3c28
	ctx.lr = 0x82069A40;
	sub_820A3C28(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82069ab0
	if (!ctx.cr6.eq) goto loc_82069AB0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,-6628(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// bl 0x820a3d60
	ctx.lr = 0x82069A58;
	sub_820A3D60(ctx, base);
	// addi r11,r3,-60
	ctx.r11.s64 = ctx.r3.s64 + -60;
	// li r10,40
	ctx.r10.s64 = 40;
	// divwu r31,r11,r10
	ctx.r31.u64 = uint32_t(ctx.r10.u32 ? ctx.r11.u32 / ctx.r10.u32 : 0);
	// cmpwi cr6,r31,5
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 5, ctx.xer);
	// ble cr6,0x82069a74
	if (!ctx.cr6.gt) goto loc_82069A74;
	// li r31,5
	ctx.r31.s64 = 5;
	// b 0x82069a80
	goto loc_82069A80;
loc_82069A74:
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
	// bge cr6,0x82069a80
	if (!ctx.cr6.lt) goto loc_82069A80;
	// mr r31,r15
	ctx.r31.u64 = ctx.r15.u64;
loc_82069A80:
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
	ctx.lr = 0x82069A98;
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
	ctx.lr = 0x82069AB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82069AB0:
	// extsh r4,r16
	ctx.r4.s64 = ctx.r16.s16;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x82069b18
	if (!ctx.cr6.gt) goto loc_82069B18;
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// bge cr6,0x82069b18
	if (!ctx.cr6.lt) goto loc_82069B18;
	// lwz r3,-6628(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// bl 0x820a3c28
	ctx.lr = 0x82069ACC;
	sub_820A3C28(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82069b18
	if (!ctx.cr6.eq) goto loc_82069B18;
	// lhz r11,14(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 14);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82069b18
	if (ctx.cr6.eq) goto loc_82069B18;
	// lwz r11,56(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82069b08
	if (ctx.cr6.eq) goto loc_82069B08;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,236(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 236);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82069B08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82069B08:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,445
	ctx.r4.s64 = 445;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x82067230
	ctx.lr = 0x82069B18;
	sub_82067230(ctx, base);
loc_82069B18:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,-6628(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// bl 0x820a3ae8
	ctx.lr = 0x82069B24;
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
	// beq cr6,0x82069b50
	if (ctx.cr6.eq) goto loc_82069B50;
	// li r4,2
	ctx.r4.s64 = 2;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82069B48;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r14,82(r1)
	ctx.r14.u64 = REX_LOAD_U16(ctx.r1.u32 + 82);
	// b 0x82069c70
	goto loc_82069C70;
loc_82069B50:
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82069B5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r14,82(r1)
	ctx.r14.u64 = REX_LOAD_U16(ctx.r1.u32 + 82);
	// b 0x82069c70
	goto loc_82069C70;
loc_82069B64:
	// extsh r11,r16
	ctx.r11.s64 = ctx.r16.s16;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82069bb0
	if (!ctx.cr6.eq) goto loc_82069BB0;
	// lhz r11,14(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 14);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82069bb0
	if (ctx.cr6.eq) goto loc_82069BB0;
	// lwz r11,56(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82069ba0
	if (ctx.cr6.eq) goto loc_82069BA0;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,236(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 236);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82069BA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82069BA0:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,591
	ctx.r4.s64 = 591;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x82067230
	ctx.lr = 0x82069BB0;
	sub_82067230(ctx, base);
loc_82069BB0:
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
	// bne cr6,0x82069be4
	if (!ctx.cr6.eq) goto loc_82069BE4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82067230
	ctx.lr = 0x82069BD0;
	sub_82067230(ctx, base);
	// lwz r10,48(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lwzx r9,r28,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r10.u32);
	// stw r30,24(r9)
	REX_STORE_U32(ctx.r9.u32 + 24, ctx.r30.u32);
	// stw r17,28(r9)
	REX_STORE_U32(ctx.r9.u32 + 28, ctx.r17.u32);
	// b 0x82069c04
	goto loc_82069C04;
loc_82069BE4:
	// li r4,478
	ctx.r4.s64 = 478;
	// bl 0x82067230
	ctx.lr = 0x82069BEC;
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
loc_82069C04:
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
	ctx.lr = 0x82069C1C;
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
	ctx.lr = 0x82069C34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82069c70
	goto loc_82069C70;
loc_82069C38:
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r7,r8,r10
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// stb r15,21(r7)
	REX_STORE_U8(ctx.r7.u32 + 21, ctx.r15.u8);
	// lwz r6,48(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lwzx r3,r8,r6
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// bl 0x82067230
	ctx.lr = 0x82069C58;
	sub_82067230(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,236(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 236);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82069C70;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82069C70:
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// cmplwi cr6,r25,4
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 4, ctx.xer);
	// blt cr6,0x8206982c
	if (ctx.cr6.lt) goto loc_8206982C;
	// lwz r3,-6628(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// bl 0x820a3900
	ctx.lr = 0x82069C84;
	sub_820A3900(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82069e38
	if (!ctx.cr6.eq) goto loc_82069E38;
	// lwz r11,-6628(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// lwz r10,140(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82069cc8
	if (ctx.cr6.eq) goto loc_82069CC8;
	// lwz r9,0(r19)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
	// addi r31,r10,596
	ctx.r31.s64 = ctx.r10.s64 + 596;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// lwz r8,164(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 164);
	// stw r11,596(r10)
	REX_STORE_U32(ctx.r10.u32 + 596, ctx.r11.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82069CC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82069ea8
	goto loc_82069EA8;
loc_82069CC8:
	// lhz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// clrlwi r9,r14,16
	ctx.r9.u64 = ctx.r14.u32 & 0xFFFF;
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82069e0c
	if (!ctx.cr6.eq) goto loc_82069E0C;
	// lwz r10,120(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82069cf0
	if (ctx.cr6.eq) goto loc_82069CF0;
	// mr r11,r15
	ctx.r11.u64 = ctx.r15.u64;
loc_82069CF0:
	// rlwinm r8,r10,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82069d00
	if (ctx.cr6.eq) goto loc_82069D00;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82069D00:
	// rlwinm r8,r10,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82069d10
	if (ctx.cr6.eq) goto loc_82069D10;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82069D10:
	// rlwinm r10,r10,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82069d20
	if (ctx.cr6.eq) goto loc_82069D20;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82069D20:
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82069e0c
	if (!ctx.cr6.gt) goto loc_82069E0C;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// addi r31,r11,596
	ctx.r31.s64 = ctx.r11.s64 + 596;
	// lwz r11,596(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 596);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r11,120
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 120, ctx.xer);
	// ble cr6,0x82069da0
	if (!ctx.cr6.gt) goto loc_82069DA0;
	// lhz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82069d74
	if (ctx.cr6.lt) goto loc_82069D74;
	// beq cr6,0x82069d68
	if (ctx.cr6.eq) goto loc_82069D68;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x82069d7c
	if (!ctx.cr6.eq) goto loc_82069D7C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8206aad0
	ctx.lr = 0x82069D64;
	sub_8206AAD0(ctx, base);
	// b 0x82069d7c
	goto loc_82069D7C;
loc_82069D68:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8206ab50
	ctx.lr = 0x82069D70;
	sub_8206AB50(ctx, base);
	// b 0x82069d7c
	goto loc_82069D7C;
loc_82069D74:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8206aad0
	ctx.lr = 0x82069D7C;
	sub_8206AAD0(ctx, base);
loc_82069D7C:
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82069D94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x82069ea8
	goto loc_82069EA8;
loc_82069DA0:
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// ble cr6,0x82069dc4
	if (!ctx.cr6.gt) goto loc_82069DC4;
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82069DC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82069ea8
	goto loc_82069EA8;
loc_82069DC4:
	// cmplwi cr6,r11,60
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 60, ctx.xer);
	// ble cr6,0x82069de8
	if (!ctx.cr6.gt) goto loc_82069DE8;
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82069DE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82069ea8
	goto loc_82069EA8;
loc_82069DE8:
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// ble cr6,0x82069ea8
	if (!ctx.cr6.gt) goto loc_82069EA8;
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82069E08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82069ea8
	goto loc_82069EA8;
loc_82069E0C:
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82069E24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
	// addi r31,r10,596
	ctx.r31.s64 = ctx.r10.s64 + 596;
	// stw r11,596(r10)
	REX_STORE_U32(ctx.r10.u32 + 596, ctx.r11.u32);
	// b 0x82069ea8
	goto loc_82069EA8;
loc_82069E38:
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82069E50;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
	// lwz r3,-6628(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// addi r31,r10,596
	ctx.r31.s64 = ctx.r10.s64 + 596;
	// stw r11,596(r10)
	REX_STORE_U32(ctx.r10.u32 + 596, ctx.r11.u32);
	// bl 0x820a3900
	ctx.lr = 0x82069E68;
	sub_820A3900(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82069ea8
	if (!ctx.cr6.eq) goto loc_82069EA8;
	// lwz r10,0(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// lwz r9,164(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 164);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82069E90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r8,2
	ctx.r8.s64 = 2;
	// li r5,24
	ctx.r5.s64 = 24;
	// sth r8,44(r30)
	REX_STORE_U16(ctx.r30.u32 + 44, ctx.r8.u16);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82054d38
	ctx.lr = 0x82069EA8;
	sub_82054D38(ctx, base);
loc_82069EA8:
	// clrlwi r11,r14,16
	ctx.r11.u64 = ctx.r14.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82069f28
	if (!ctx.cr6.eq) goto loc_82069F28;
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lwz r11,600(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 600);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,600(r9)
	REX_STORE_U32(ctx.r9.u32 + 600, ctx.r11.u32);
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// ble cr6,0x82069f34
	if (!ctx.cr6.gt) goto loc_82069F34;
	// lwz r8,0(r19)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
	// mr r10,r17
	ctx.r10.u64 = ctx.r17.u64;
	// stw r11,600(r9)
	REX_STORE_U32(ctx.r9.u32 + 600, ctx.r11.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// lwz r7,164(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 164);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82069EF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-6628(r24)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// bl 0x820a37b8
	ctx.lr = 0x82069F00;
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
	ctx.lr = 0x82069F18;
	sub_82054D38(ctx, base);
	// lwz r11,-6628(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -6628);
	// stw r17,140(r11)
	REX_STORE_U32(ctx.r11.u32 + 140, ctx.r17.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
loc_82069F28:
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
	// stw r11,600(r10)
	REX_STORE_U32(ctx.r10.u32 + 600, ctx.r11.u32);
loc_82069F34:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
}
