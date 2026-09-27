DEFINE_REX_FUNC(sub_820524D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e0
	ctx.lr = 0x820524E0;
	__savegprlr_14(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// stw r7,372(r1)
	REX_STORE_U32(ctx.r1.u32 + 372, ctx.r7.u32);
	// li r14,0
	ctx.r14.s64 = 0;
	// stw r8,380(r1)
	REX_STORE_U32(ctx.r1.u32 + 380, ctx.r8.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r22,r5
	ctx.r22.u64 = ctx.r5.u64;
	// mr r17,r6
	ctx.r17.u64 = ctx.r6.u64;
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// mr r28,r14
	ctx.r28.u64 = ctx.r14.u64;
	// addi r31,r11,25216
	ctx.r31.s64 = ctx.r11.s64 + 25216;
	// blt cr6,0x82052b98
	if (ctx.cr6.lt) goto loc_82052B98;
	// beq cr6,0x82052908
	if (ctx.cr6.eq) goto loc_82052908;
	// cmplwi cr6,r4,3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 3, ctx.xer);
	// bne cr6,0x82052d68
	if (!ctx.cr6.eq) goto loc_82052D68;
	// addi r11,r29,196
	ctx.r11.s64 = ctx.r29.s64 + 196;
	// lis r21,-32218
	ctx.r21.s64 = -2111438848;
	// sth r11,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r11.u16);
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// lwz r11,-6624(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x82052538;
	sub_82052EA8(ctx, base);
	// addi r9,r29,200
	ctx.r9.s64 = ctx.r29.s64 + 200;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r11,-6624(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -6624);
	// sth r9,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r9.u16);
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// lwz r18,0(r8)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// bl 0x82052ea8
	ctx.lr = 0x82052558;
	sub_82052EA8(ctx, base);
	// lwz r19,0(r3)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r23,1
	ctx.r23.s64 = 1;
	// lis r15,-32218
	ctx.r15.s64 = -2111438848;
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// bne cr6,0x820525d4
	if (!ctx.cr6.eq) goto loc_820525D4;
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// bne cr6,0x820525d4
	if (!ctx.cr6.eq) goto loc_820525D4;
	// li r10,217
	ctx.r10.s64 = 217;
	// lwz r11,-6624(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -6624);
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// sth r10,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r10.u16);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x8205258C;
	sub_82052EA8(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r3,-6628(r15)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r15.u32 + -6628);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820525b8
	if (ctx.cr6.eq) goto loc_820525B8;
	// bl 0x820a39f0
	ctx.lr = 0x820525A4;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820525d0
	if (!ctx.cr6.eq) goto loc_820525D0;
	// mr r18,r23
	ctx.r18.u64 = ctx.r23.u64;
	// b 0x820525d4
	goto loc_820525D4;
loc_820525B8:
	// bl 0x820a39f0
	ctx.lr = 0x820525BC;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820525d0
	if (ctx.cr6.eq) goto loc_820525D0;
	// mr r18,r23
	ctx.r18.u64 = ctx.r23.u64;
	// b 0x820525d4
	goto loc_820525D4;
loc_820525D0:
	// mr r19,r23
	ctx.r19.u64 = ctx.r23.u64;
loc_820525D4:
	// clrlwi r16,r22,24
	ctx.r16.u64 = ctx.r22.u32 & 0xFF;
	// li r28,4
	ctx.r28.s64 = 4;
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// beq cr6,0x820525ec
	if (ctx.cr6.eq) goto loc_820525EC;
	// li r11,16
	ctx.r11.s64 = 16;
loc_820525EC:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// addi r9,r29,5
	ctx.r9.s64 = ctx.r29.s64 + 5;
	// mr r24,r14
	ctx.r24.u64 = ctx.r14.u64;
	// rlwinm r26,r9,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r22,r14
	ctx.r22.u64 = ctx.r14.u64;
	// lwz r27,-6596(r10)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r10.u32 + -6596);
	// mr r30,r14
	ctx.r30.u64 = ctx.r14.u64;
	// mr r20,r14
	ctx.r20.u64 = ctx.r14.u64;
loc_8205260C:
	// clrlwi r25,r11,16
	ctx.r25.u64 = ctx.r11.u32 & 0xFFFF;
	// lwzx r4,r26,r27
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + ctx.r27.u32);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// bl 0x8209d3d8
	ctx.lr = 0x82052620;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,132
	ctx.r5.s64 = ctx.r1.s64 + 132;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwzx r4,r26,r27
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + ctx.r27.u32);
	// bl 0x8209d488
	ctx.lr = 0x82052630;
	sub_8209D488(ctx, base);
	// addi r5,r1,130
	ctx.r5.s64 = ctx.r1.s64 + 130;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// lwzx r4,r26,r27
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + ctx.r27.u32);
	// bl 0x8209d488
	ctx.lr = 0x82052640;
	sub_8209D488(ctx, base);
	// lbz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 132);
	// clrlwi r10,r24,16
	ctx.r10.u64 = ctx.r24.u32 & 0xFFFF;
	// lbz r9,130(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 130);
	// rlwimi r9,r11,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82052664
	if (!ctx.cr6.gt) goto loc_82052664;
	// mr r24,r11
	ctx.r24.u64 = ctx.r11.u64;
	// mr r22,r30
	ctx.r22.u64 = ctx.r30.u64;
loc_82052664:
	// addi r11,r20,1
	ctx.r11.s64 = ctx.r20.s64 + 1;
	// addi r10,r25,2
	ctx.r10.s64 = ctx.r25.s64 + 2;
	// clrlwi r30,r11,16
	ctx.r30.u64 = ctx.r11.u32 & 0xFFFF;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r20,r30
	ctx.r20.u64 = ctx.r30.u64;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x8205260c
	if (ctx.cr6.lt) goto loc_8205260C;
	// clrlwi r11,r24,16
	ctx.r11.u64 = ctx.r24.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820526b8
	if (!ctx.cr6.eq) goto loc_820526B8;
	// li r10,212
	ctx.r10.s64 = 212;
	// lwz r11,-6624(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -6624);
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// sth r10,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r10.u16);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x820526A4;
	sub_82052EA8(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r22,r9,16
	ctx.r22.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplwi cr6,r22,3
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 3, ctx.xer);
	// ble cr6,0x820526b8
	if (!ctx.cr6.gt) goto loc_820526B8;
	// mr r22,r14
	ctx.r22.u64 = ctx.r14.u64;
loc_820526B8:
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x820526d0
	if (ctx.cr6.eq) goto loc_820526D0;
	// lwz r11,-6628(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + -6628);
	// lwz r11,1188(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1188);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// b 0x820526d4
	goto loc_820526D4;
loc_820526D0:
	// li r7,-1
	ctx.r7.s64 = -1;
loc_820526D4:
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// mr r5,r19
	ctx.r5.u64 = ctx.r19.u64;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82052430
	ctx.lr = 0x820526E8;
	sub_82052430(ctx, base);
	// addi r10,r29,204
	ctx.r10.s64 = ctx.r29.s64 + 204;
	// lwz r11,-6624(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -6624);
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// clrlwi r26,r10,16
	ctx.r26.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// sth r26,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r26.u16);
	// bl 0x82052ea8
	ctx.lr = 0x82052704;
	sub_82052EA8(ctx, base);
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r31,-192
	ctx.r6.s64 = ctx.r31.s64 + -192;
	// lwz r5,0(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// add r4,r29,r11
	ctx.r4.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r11,r31,-192
	ctx.r11.s64 = ctx.r31.s64 + -192;
	// rlwinm r30,r4,4,0,27
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r3,r11,8
	ctx.r3.s64 = ctx.r11.s64 + 8;
	// addi r11,r6,40
	ctx.r11.s64 = ctx.r6.s64 + 40;
	// addi r9,r31,-192
	ctx.r9.s64 = ctx.r31.s64 + -192;
	// addi r8,r31,-192
	ctx.r8.s64 = ctx.r31.s64 + -192;
	// addi r7,r31,-192
	ctx.r7.s64 = ctx.r31.s64 + -192;
	// addi r10,r31,-192
	ctx.r10.s64 = ctx.r31.s64 + -192;
	// stbx r23,r30,r3
	REX_STORE_U8(ctx.r30.u32 + ctx.r3.u32, ctx.r23.u8);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// stwx r5,r30,r11
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r5.u32);
	// lis r6,4096
	ctx.r6.s64 = 268435456;
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// addi r8,r8,24
	ctx.r8.s64 = ctx.r8.s64 + 24;
	// addi r7,r7,32
	ctx.r7.s64 = ctx.r7.s64 + 32;
	// ori r3,r6,32779
	ctx.r3.u64 = ctx.r6.u64 | 32779;
	// stwx r17,r30,r9
	REX_STORE_U32(ctx.r30.u32 + ctx.r9.u32, ctx.r17.u32);
	// ori r11,r4,32778
	ctx.r11.u64 = ctx.r4.u64 | 32778;
	// stwx r3,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r3.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stwx r11,r30,r8
	REX_STORE_U32(ctx.r30.u32 + ctx.r8.u32, ctx.r11.u32);
	// mr r6,r19
	ctx.r6.u64 = ctx.r19.u64;
	// stbx r23,r30,r7
	REX_STORE_U8(ctx.r30.u32 + ctx.r7.u32, ctx.r23.u8);
	// addi r3,r9,9252
	ctx.r3.s64 = ctx.r9.s64 + 9252;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// add r27,r30,r10
	ctx.r27.u64 = ctx.r30.u64 + ctx.r10.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x82052784;
	sub_8208C5D8(ctx, base);
	// sth r26,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r26.u16);
	// lwz r11,-6624(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -6624);
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x82052798;
	sub_82052EA8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r6,r17
	ctx.r6.u64 = ctx.r17.u64;
	// addi r3,r7,9304
	ctx.r3.s64 = ctx.r7.s64 + 9304;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r5,0(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// bl 0x8208c5d8
	ctx.lr = 0x820527B4;
	sub_8208C5D8(ctx, base);
	// rlwinm r11,r29,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r10,r31,-384
	ctx.r10.s64 = ctx.r31.s64 + -384;
	// addi r9,r31,-384
	ctx.r9.s64 = ctx.r31.s64 + -384;
	// addi r8,r31,-384
	ctx.r8.s64 = ctx.r31.s64 + -384;
	// addi r7,r31,-384
	ctx.r7.s64 = ctx.r31.s64 + -384;
	// addi r6,r31,-384
	ctx.r6.s64 = ctx.r31.s64 + -384;
	// addi r5,r31,-384
	ctx.r5.s64 = ctx.r31.s64 + -384;
	// addi r4,r31,-384
	ctx.r4.s64 = ctx.r31.s64 + -384;
	// addi r3,r31,-384
	ctx.r3.s64 = ctx.r31.s64 + -384;
	// addi r26,r31,-384
	ctx.r26.s64 = ctx.r31.s64 + -384;
	// addi r25,r31,-384
	ctx.r25.s64 = ctx.r31.s64 + -384;
	// addi r24,r31,-384
	ctx.r24.s64 = ctx.r31.s64 + -384;
	// rlwinm r11,r11,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// beq cr6,0x82052880
	if (ctx.cr6.eq) goto loc_82052880;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// addi r4,r4,28
	ctx.r4.s64 = ctx.r4.s64 + 28;
	// addi r22,r31,-384
	ctx.r22.s64 = ctx.r31.s64 + -384;
	// addi r6,r6,20
	ctx.r6.s64 = ctx.r6.s64 + 20;
	// stwx r28,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r28.u32);
	// addi r10,r31,96
	ctx.r10.s64 = ctx.r31.s64 + 96;
	// stwx r28,r30,r7
	REX_STORE_U32(ctx.r30.u32 + ctx.r7.u32, ctx.r28.u32);
	// addi r23,r9,8
	ctx.r23.s64 = ctx.r9.s64 + 8;
	// addi r7,r26,36
	ctx.r7.s64 = ctx.r26.s64 + 36;
	// stwx r28,r30,r4
	REX_STORE_U32(ctx.r30.u32 + ctx.r4.u32, ctx.r28.u32);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r9,r31,192
	ctx.r9.s64 = ctx.r31.s64 + 192;
	// addi r26,r25,40
	ctx.r26.s64 = ctx.r25.s64 + 40;
	// stwx r10,r30,r6
	REX_STORE_U32(ctx.r30.u32 + ctx.r6.u32, ctx.r10.u32);
	// li r4,23
	ctx.r4.s64 = 23;
	// addi r25,r24,44
	ctx.r25.s64 = ctx.r24.s64 + 44;
	// addi r8,r8,12
	ctx.r8.s64 = ctx.r8.s64 + 12;
	// stwx r4,r30,r22
	REX_STORE_U32(ctx.r30.u32 + ctx.r22.u32, ctx.r4.u32);
	// addi r5,r5,24
	ctx.r5.s64 = ctx.r5.s64 + 24;
	// addi r3,r3,32
	ctx.r3.s64 = ctx.r3.s64 + 32;
	// add r24,r11,r31
	ctx.r24.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stwx r27,r30,r25
	REX_STORE_U32(ctx.r30.u32 + ctx.r25.u32, ctx.r27.u32);
	// li r21,24
	ctx.r21.s64 = 24;
	// stwx r24,r30,r23
	REX_STORE_U32(ctx.r30.u32 + ctx.r23.u32, ctx.r24.u32);
	// li r4,22
	ctx.r4.s64 = 22;
	// lis r10,-1
	ctx.r10.s64 = -65536;
	// stwx r21,r30,r8
	REX_STORE_U32(ctx.r30.u32 + ctx.r8.u32, ctx.r21.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stwx r4,r30,r5
	REX_STORE_U32(ctx.r30.u32 + ctx.r5.u32, ctx.r4.u32);
	// stwx r11,r30,r3
	REX_STORE_U32(ctx.r30.u32 + ctx.r3.u32, ctx.r11.u32);
	// stwx r10,r30,r7
	REX_STORE_U32(ctx.r30.u32 + ctx.r7.u32, ctx.r10.u32);
	// stwx r9,r30,r26
	REX_STORE_U32(ctx.r30.u32 + ctx.r26.u32, ctx.r9.u32);
	// b 0x82052d68
	goto loc_82052D68;
loc_82052880:
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// addi r10,r10,28
	ctx.r10.s64 = ctx.r10.s64 + 28;
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// addi r24,r24,12
	ctx.r24.s64 = ctx.r24.s64 + 12;
	// addi r23,r31,-384
	ctx.r23.s64 = ctx.r31.s64 + -384;
	// stwx r28,r30,r9
	REX_STORE_U32(ctx.r30.u32 + ctx.r9.u32, ctx.r28.u32);
	// addi r9,r31,96
	ctx.r9.s64 = ctx.r31.s64 + 96;
	// addi r3,r3,20
	ctx.r3.s64 = ctx.r3.s64 + 20;
	// stwx r28,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r28.u32);
	// stwx r28,r30,r26
	REX_STORE_U32(ctx.r30.u32 + ctx.r26.u32, ctx.r28.u32);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r10,r31,192
	ctx.r10.s64 = ctx.r31.s64 + 192;
	// stwx r28,r30,r24
	REX_STORE_U32(ctx.r30.u32 + ctx.r24.u32, ctx.r28.u32);
	// li r26,3
	ctx.r26.s64 = 3;
	// addi r25,r25,8
	ctx.r25.s64 = ctx.r25.s64 + 8;
	// addi r4,r4,24
	ctx.r4.s64 = ctx.r4.s64 + 24;
	// stwx r26,r30,r23
	REX_STORE_U32(ctx.r30.u32 + ctx.r23.u32, ctx.r26.u32);
	// addi r5,r5,32
	ctx.r5.s64 = ctx.r5.s64 + 32;
	// stwx r9,r30,r3
	REX_STORE_U32(ctx.r30.u32 + ctx.r3.u32, ctx.r9.u32);
	// addi r6,r6,36
	ctx.r6.s64 = ctx.r6.s64 + 36;
	// addi r7,r7,40
	ctx.r7.s64 = ctx.r7.s64 + 40;
	// addi r8,r8,44
	ctx.r8.s64 = ctx.r8.s64 + 44;
	// add r24,r11,r31
	ctx.r24.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r26,5
	ctx.r26.s64 = 5;
	// stwx r24,r30,r25
	REX_STORE_U32(ctx.r30.u32 + ctx.r25.u32, ctx.r24.u32);
	// lis r10,-1
	ctx.r10.s64 = -65536;
	// stwx r11,r30,r5
	REX_STORE_U32(ctx.r30.u32 + ctx.r5.u32, ctx.r11.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stwx r26,r30,r4
	REX_STORE_U32(ctx.r30.u32 + ctx.r4.u32, ctx.r26.u32);
	// stwx r10,r30,r6
	REX_STORE_U32(ctx.r30.u32 + ctx.r6.u32, ctx.r10.u32);
	// stwx r9,r30,r7
	REX_STORE_U32(ctx.r30.u32 + ctx.r7.u32, ctx.r9.u32);
	// stwx r27,r30,r8
	REX_STORE_U32(ctx.r30.u32 + ctx.r8.u32, ctx.r27.u32);
	// b 0x82052d68
	goto loc_82052D68;
loc_82052908:
	// addi r11,r29,196
	ctx.r11.s64 = ctx.r29.s64 + 196;
	// lis r26,-32218
	ctx.r26.s64 = -2111438848;
	// sth r11,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r11.u16);
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// lwz r11,-6624(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x82052924;
	sub_82052EA8(ctx, base);
	// addi r9,r29,200
	ctx.r9.s64 = ctx.r29.s64 + 200;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r11,-6624(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6624);
	// sth r9,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r9.u16);
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// lwz r24,0(r8)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// bl 0x82052ea8
	ctx.lr = 0x82052944;
	sub_82052EA8(ctx, base);
	// lwz r25,0(r3)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r23,1
	ctx.r23.s64 = 1;
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// bne cr6,0x82052b54
	if (!ctx.cr6.eq) goto loc_82052B54;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// bne cr6,0x82052b5c
	if (!ctx.cr6.eq) goto loc_82052B5C;
	// li r10,217
	ctx.r10.s64 = 217;
	// lwz r11,-6624(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6624);
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// sth r10,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r10.u16);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x82052978;
	sub_82052EA8(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r3,-6628(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82052b2c
	if (ctx.cr6.eq) goto loc_82052B2C;
	// bl 0x820a39f0
	ctx.lr = 0x82052990;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82052b3c
	if (ctx.cr6.eq) goto loc_82052B3C;
loc_8205299C:
	// mr r25,r23
	ctx.r25.u64 = ctx.r23.u64;
loc_820529A0:
	// li r6,-1
	ctx.r6.s64 = -1;
loc_820529A4:
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820523a0
	ctx.lr = 0x820529B4;
	sub_820523A0(ctx, base);
	// addi r10,r29,204
	ctx.r10.s64 = ctx.r29.s64 + 204;
	// lwz r11,-6624(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6624);
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// clrlwi r21,r10,16
	ctx.r21.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// sth r21,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r21.u16);
	// bl 0x82052ea8
	ctx.lr = 0x820529D0;
	sub_82052EA8(ctx, base);
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r5,0(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r7,r31,-192
	ctx.r7.s64 = ctx.r31.s64 + -192;
	// add r4,r29,r11
	ctx.r4.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r11,r31,-192
	ctx.r11.s64 = ctx.r31.s64 + -192;
	// rlwinm r30,r4,4,0,27
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r3,r11,40
	ctx.r3.s64 = ctx.r11.s64 + 40;
	// addi r9,r31,-192
	ctx.r9.s64 = ctx.r31.s64 + -192;
	// addi r10,r31,-192
	ctx.r10.s64 = ctx.r31.s64 + -192;
	// addi r8,r31,-192
	ctx.r8.s64 = ctx.r31.s64 + -192;
	// addi r11,r7,8
	ctx.r11.s64 = ctx.r7.s64 + 8;
	// addi r4,r10,32
	ctx.r4.s64 = ctx.r10.s64 + 32;
	// stwx r5,r30,r3
	REX_STORE_U32(ctx.r30.u32 + ctx.r3.u32, ctx.r5.u32);
	// addi r7,r9,24
	ctx.r7.s64 = ctx.r9.s64 + 24;
	// addi r6,r31,-192
	ctx.r6.s64 = ctx.r31.s64 + -192;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// stbx r23,r30,r11
	REX_STORE_U8(ctx.r30.u32 + ctx.r11.u32, ctx.r23.u8);
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// stbx r23,r30,r4
	REX_STORE_U8(ctx.r30.u32 + ctx.r4.u32, ctx.r23.u8);
	// ori r5,r10,32779
	ctx.r5.u64 = ctx.r10.u64 | 32779;
	// ori r3,r9,32778
	ctx.r3.u64 = ctx.r9.u64 | 32778;
	// stwx r5,r30,r6
	REX_STORE_U32(ctx.r30.u32 + ctx.r6.u32, ctx.r5.u32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stwx r3,r30,r7
	REX_STORE_U32(ctx.r30.u32 + ctx.r7.u32, ctx.r3.u32);
	// add r27,r30,r6
	ctx.r27.u64 = ctx.r30.u64 + ctx.r6.u64;
	// stwx r17,r30,r8
	REX_STORE_U32(ctx.r30.u32 + ctx.r8.u32, ctx.r17.u32);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// addi r3,r11,9140
	ctx.r3.s64 = ctx.r11.s64 + 9140;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r28,3
	ctx.r28.s64 = 3;
	// bl 0x8208c5d8
	ctx.lr = 0x82052A54;
	sub_8208C5D8(ctx, base);
	// sth r21,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r21.u16);
	// lwz r11,-6624(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6624);
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x82052A68;
	sub_82052EA8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r6,r17
	ctx.r6.u64 = ctx.r17.u64;
	// addi r3,r9,9192
	ctx.r3.s64 = ctx.r9.s64 + 9192;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8208c5d8
	ctx.lr = 0x82052A84;
	sub_8208C5D8(ctx, base);
	// clrlwi r8,r22,24
	ctx.r8.u64 = ctx.r22.u32 & 0xFF;
	// rlwinm r11,r29,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r25,r31,-384
	ctx.r25.s64 = ctx.r31.s64 + -384;
	// addi r26,r31,-384
	ctx.r26.s64 = ctx.r31.s64 + -384;
	// addi r3,r31,-384
	ctx.r3.s64 = ctx.r31.s64 + -384;
	// addi r4,r31,-384
	ctx.r4.s64 = ctx.r31.s64 + -384;
	// addi r10,r31,-968
	ctx.r10.s64 = ctx.r31.s64 + -968;
	// addi r5,r31,-384
	ctx.r5.s64 = ctx.r31.s64 + -384;
	// addi r6,r31,-384
	ctx.r6.s64 = ctx.r31.s64 + -384;
	// addi r7,r31,-384
	ctx.r7.s64 = ctx.r31.s64 + -384;
	// addi r8,r31,-384
	ctx.r8.s64 = ctx.r31.s64 + -384;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r24,r31,-384
	ctx.r24.s64 = ctx.r31.s64 + -384;
	// addi r9,r31,-968
	ctx.r9.s64 = ctx.r31.s64 + -968;
	// addi r25,r25,4
	ctx.r25.s64 = ctx.r25.s64 + 4;
	// addi r26,r26,8
	ctx.r26.s64 = ctx.r26.s64 + 8;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// addi r4,r4,16
	ctx.r4.s64 = ctx.r4.s64 + 16;
	// addi r10,r10,72
	ctx.r10.s64 = ctx.r10.s64 + 72;
	// addi r5,r5,20
	ctx.r5.s64 = ctx.r5.s64 + 20;
	// addi r6,r6,24
	ctx.r6.s64 = ctx.r6.s64 + 24;
	// addi r7,r7,28
	ctx.r7.s64 = ctx.r7.s64 + 28;
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stwx r28,r30,r25
	REX_STORE_U32(ctx.r30.u32 + ctx.r25.u32, ctx.r28.u32);
	// stwx r28,r30,r4
	REX_STORE_U32(ctx.r30.u32 + ctx.r4.u32, ctx.r28.u32);
	// stwx r9,r30,r26
	REX_STORE_U32(ctx.r30.u32 + ctx.r26.u32, ctx.r9.u32);
	// stwx r27,r30,r8
	REX_STORE_U32(ctx.r30.u32 + ctx.r8.u32, ctx.r27.u32);
	// beq cr6,0x82052b6c
	if (ctx.cr6.eq) goto loc_82052B6C;
	// li r4,6
	ctx.r4.s64 = 6;
	// li r25,7
	ctx.r25.s64 = 7;
	// stwx r4,r30,r24
	REX_STORE_U32(ctx.r30.u32 + ctx.r24.u32, ctx.r4.u32);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lis r11,-1
	ctx.r11.s64 = -65536;
	// stwx r25,r30,r3
	REX_STORE_U32(ctx.r30.u32 + ctx.r3.u32, ctx.r25.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r4,r30,r5
	REX_STORE_U32(ctx.r30.u32 + ctx.r5.u32, ctx.r4.u32);
	// stwx r11,r30,r6
	REX_STORE_U32(ctx.r30.u32 + ctx.r6.u32, ctx.r11.u32);
	// stwx r10,r30,r7
	REX_STORE_U32(ctx.r30.u32 + ctx.r7.u32, ctx.r10.u32);
	// b 0x82052d68
	goto loc_82052D68;
loc_82052B2C:
	// bl 0x820a39f0
	ctx.lr = 0x82052B30;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8205299c
	if (ctx.cr6.eq) goto loc_8205299C;
loc_82052B3C:
	// lwz r11,-6628(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// li r23,1
	ctx.r23.s64 = 1;
	// mr r24,r23
	ctx.r24.u64 = ctx.r23.u64;
	// lwz r11,1188(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1188);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// b 0x820529a4
	goto loc_820529A4;
loc_82052B54:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x820529a0
	if (ctx.cr6.eq) goto loc_820529A0;
loc_82052B5C:
	// lwz r11,-6628(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// lwz r11,1188(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1188);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// b 0x820529a4
	goto loc_820529A4;
loc_82052B6C:
	// li r4,25
	ctx.r4.s64 = 25;
	// li r25,16
	ctx.r25.s64 = 16;
	// stwx r4,r30,r24
	REX_STORE_U32(ctx.r30.u32 + ctx.r24.u32, ctx.r4.u32);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lis r11,-1
	ctx.r11.s64 = -65536;
	// stwx r25,r30,r3
	REX_STORE_U32(ctx.r30.u32 + ctx.r3.u32, ctx.r25.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r4,r30,r5
	REX_STORE_U32(ctx.r30.u32 + ctx.r5.u32, ctx.r4.u32);
	// stwx r11,r30,r6
	REX_STORE_U32(ctx.r30.u32 + ctx.r6.u32, ctx.r11.u32);
	// stwx r10,r30,r7
	REX_STORE_U32(ctx.r30.u32 + ctx.r7.u32, ctx.r10.u32);
	// b 0x82052d68
	goto loc_82052D68;
loc_82052B98:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r10,r29,5
	ctx.r10.s64 = ctx.r29.s64 + 5;
	// mr r22,r14
	ctx.r22.u64 = ctx.r14.u64;
	// rlwinm r28,r10,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r27,r14
	ctx.r27.u64 = ctx.r14.u64;
	// lwz r30,-6596(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// mr r24,r14
	ctx.r24.u64 = ctx.r14.u64;
	// mr r21,r14
	ctx.r21.u64 = ctx.r14.u64;
	// mr r25,r14
	ctx.r25.u64 = ctx.r14.u64;
	// li r23,1
	ctx.r23.s64 = 1;
loc_82052BC0:
	// rlwinm r11,r25,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// lwzx r4,r28,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r30.u32);
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// stb r23,128(r1)
	REX_STORE_U8(ctx.r1.u32 + 128, ctx.r23.u8);
	// add r11,r25,r11
	ctx.r11.u64 = ctx.r25.u64 + ctx.r11.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r5,r11,97
	ctx.r5.s64 = ctx.r11.s64 + 97;
	// bl 0x8209d3d8
	ctx.lr = 0x82052BE0;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwzx r4,r28,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r30.u32);
	// bl 0x8209d488
	ctx.lr = 0x82052BF0;
	sub_8209D488(ctx, base);
	// lbz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 128);
	// clrlwi r10,r27,16
	ctx.r10.u64 = ctx.r27.u32 & 0xFFFF;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// clrlwi r26,r8,24
	ctx.r26.u64 = ctx.r8.u32 & 0xFF;
	// cmplw cr6,r26,r10
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82052c8c
	if (ctx.cr6.lt) goto loc_82052C8C;
	// addi r5,r1,129
	ctx.r5.s64 = ctx.r1.s64 + 129;
	// lwzx r4,r28,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r30.u32);
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// stb r14,129(r1)
	REX_STORE_U8(ctx.r1.u32 + 129, ctx.r14.u8);
	// stb r14,128(r1)
	REX_STORE_U8(ctx.r1.u32 + 128, ctx.r14.u8);
	// stb r14,130(r1)
	REX_STORE_U8(ctx.r1.u32 + 130, ctx.r14.u8);
	// stb r14,132(r1)
	REX_STORE_U8(ctx.r1.u32 + 132, ctx.r14.u8);
	// bl 0x8209d488
	ctx.lr = 0x82052C28;
	sub_8209D488(ctx, base);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwzx r4,r28,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r30.u32);
	// bl 0x8209d488
	ctx.lr = 0x82052C38;
	sub_8209D488(ctx, base);
	// addi r5,r1,130
	ctx.r5.s64 = ctx.r1.s64 + 130;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// lwzx r4,r28,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r30.u32);
	// bl 0x8209d488
	ctx.lr = 0x82052C48;
	sub_8209D488(ctx, base);
	// addi r5,r1,132
	ctx.r5.s64 = ctx.r1.s64 + 132;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwzx r4,r28,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r30.u32);
	// bl 0x8209d488
	ctx.lr = 0x82052C58;
	sub_8209D488(ctx, base);
	// lbz r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 128);
	// lbz r9,129(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 129);
	// lbz r8,130(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 130);
	// rlwimi r10,r9,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 132);
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwimi r8,r7,8,0,23
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r8.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r11,r8,8,0,23
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r11.u64 & 0xFFFFFFFF000000FF);
	// cmplw cr6,r11,r24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r24.u32, ctx.xer);
	// ble cr6,0x82052c8c
	if (!ctx.cr6.gt) goto loc_82052C8C;
	// mr r24,r11
	ctx.r24.u64 = ctx.r11.u64;
	// mr r22,r21
	ctx.r22.u64 = ctx.r21.u64;
	// clrlwi r27,r26,24
	ctx.r27.u64 = ctx.r26.u32 & 0xFF;
loc_82052C8C:
	// addi r11,r25,1
	ctx.r11.s64 = ctx.r25.s64 + 1;
	// clrlwi r21,r11,16
	ctx.r21.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r25,r21
	ctx.r25.u64 = ctx.r21.u64;
	// cmplwi cr6,r21,28
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 28, ctx.xer);
	// blt cr6,0x82052bc0
	if (ctx.cr6.lt) goto loc_82052BC0;
	// clrlwi r11,r27,16
	ctx.r11.u64 = ctx.r27.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82052cb0
	if (!ctx.cr6.eq) goto loc_82052CB0;
	// mr r27,r23
	ctx.r27.u64 = ctx.r23.u64;
loc_82052CB0:
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// clrlwi r5,r27,16
	ctx.r5.u64 = ctx.r27.u32 & 0xFFFF;
	// clrlwi r4,r22,16
	ctx.r4.u64 = ctx.r22.u32 & 0xFFFF;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82052318
	ctx.lr = 0x82052CC4;
	sub_82052318(ctx, base);
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r31,-384
	ctx.r3.s64 = ctx.r31.s64 + -384;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// rlwinm r25,r11,4,0,27
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r26,r31,-384
	ctx.r26.s64 = ctx.r31.s64 + -384;
	// addi r30,r31,-384
	ctx.r30.s64 = ctx.r31.s64 + -384;
	// li r28,3
	ctx.r28.s64 = 3;
	// addi r8,r26,4
	ctx.r8.s64 = ctx.r26.s64 + 4;
	// addi r30,r30,12
	ctx.r30.s64 = ctx.r30.s64 + 12;
	// stwx r28,r25,r3
	REX_STORE_U32(ctx.r25.u32 + ctx.r3.u32, ctx.r28.u32);
	// addi r3,r31,-384
	ctx.r3.s64 = ctx.r31.s64 + -384;
	// addi r9,r31,1272
	ctx.r9.s64 = ctx.r31.s64 + 1272;
	// addi r27,r31,-384
	ctx.r27.s64 = ctx.r31.s64 + -384;
	// addi r4,r31,-384
	ctx.r4.s64 = ctx.r31.s64 + -384;
	// stwx r28,r25,r8
	REX_STORE_U32(ctx.r25.u32 + ctx.r8.u32, ctx.r28.u32);
	// addi r5,r31,-384
	ctx.r5.s64 = ctx.r31.s64 + -384;
	// stwx r23,r25,r30
	REX_STORE_U32(ctx.r25.u32 + ctx.r30.u32, ctx.r23.u32);
	// addi r6,r31,-384
	ctx.r6.s64 = ctx.r31.s64 + -384;
	// addi r10,r31,1272
	ctx.r10.s64 = ctx.r31.s64 + 1272;
	// addi r7,r31,-384
	ctx.r7.s64 = ctx.r31.s64 + -384;
	// mulli r11,r29,216
	ctx.r11.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(216));
	// addi r8,r31,1272
	ctx.r8.s64 = ctx.r31.s64 + 1272;
	// addi r9,r9,72
	ctx.r9.s64 = ctx.r9.s64 + 72;
	// li r30,2
	ctx.r30.s64 = 2;
	// addi r27,r27,8
	ctx.r27.s64 = ctx.r27.s64 + 8;
	// addi r4,r4,20
	ctx.r4.s64 = ctx.r4.s64 + 20;
	// stwx r30,r25,r3
	REX_STORE_U32(ctx.r25.u32 + ctx.r3.u32, ctx.r30.u32);
	// addi r5,r5,24
	ctx.r5.s64 = ctx.r5.s64 + 24;
	// addi r6,r6,28
	ctx.r6.s64 = ctx.r6.s64 + 28;
	// addi r10,r10,144
	ctx.r10.s64 = ctx.r10.s64 + 144;
	// addi r7,r7,32
	ctx.r7.s64 = ctx.r7.s64 + 32;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// li r3,21
	ctx.r3.s64 = 21;
	// stwx r8,r25,r27
	REX_STORE_U32(ctx.r25.u32 + ctx.r27.u32, ctx.r8.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stwx r9,r25,r4
	REX_STORE_U32(ctx.r25.u32 + ctx.r4.u32, ctx.r9.u32);
	// stwx r3,r25,r5
	REX_STORE_U32(ctx.r25.u32 + ctx.r5.u32, ctx.r3.u32);
	// stwx r11,r25,r7
	REX_STORE_U32(ctx.r25.u32 + ctx.r7.u32, ctx.r11.u32);
	// stwx r28,r25,r6
	REX_STORE_U32(ctx.r25.u32 + ctx.r6.u32, ctx.r28.u32);
loc_82052D68:
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,380(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 380);
	// lwz r8,372(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
	// addi r10,r31,-384
	ctx.r10.s64 = ctx.r31.s64 + -384;
	// add r7,r29,r11
	ctx.r7.u64 = ctx.r29.u64 + ctx.r11.u64;
	// rlwinm r11,r7,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r28,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r28.u32);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r6,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
}
