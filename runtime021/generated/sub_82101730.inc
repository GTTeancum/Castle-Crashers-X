DEFINE_REX_FUNC(sub_82101730) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x82101738;
	__savegprlr_22(ctx, base);
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r24,0
	ctx.r24.s64 = 0;
	// li r22,4
	ctx.r22.s64 = 4;
	// mr r23,r24
	ctx.r23.u64 = ctx.r24.u64;
	// stw r24,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r24.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r22,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r22.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r23,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r23.u32);
	// bge cr6,0x82101768
	if (!ctx.cr6.lt) goto loc_82101768;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// b 0x82101b08
	goto loc_82101B08;
loc_82101768:
	// addi r25,r31,380
	ctx.r25.s64 = ctx.r31.s64 + 380;
	// mr r26,r24
	ctx.r26.u64 = ctx.r24.u64;
	// mr r30,r24
	ctx.r30.u64 = ctx.r24.u64;
	// addi r27,r1,224
	ctx.r27.s64 = ctx.r1.s64 + 224;
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
loc_82101780:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821017c4
	if (ctx.cr6.eq) goto loc_821017C4;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ffe78
	ctx.lr = 0x8210179C;
	sub_820FFE78(ctx, base);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// stwx r30,r29,r11
	REX_STORE_U32(ctx.r29.u32 + ctx.r11.u32, ctx.r30.u32);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r11,396(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm r11,r11,3,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x1;
	// stwx r11,r29,r10
	REX_STORE_U32(ctx.r29.u32 + ctx.r10.u32, ctx.r11.u32);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// b 0x821017d4
	goto loc_821017D4;
loc_821017C4:
	// li r5,42
	ctx.r5.s64 = 42;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82129fa0
	ctx.lr = 0x821017D4;
	sub_82129FA0(ctx, base);
loc_821017D4:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// addi r27,r27,42
	ctx.r27.s64 = ctx.r27.s64 + 42;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x82101780
	if (ctx.cr6.lt) goto loc_82101780;
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101838
	if (ctx.cr6.eq) goto loc_82101838;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82138990
	ctx.lr = 0x82101808;
	sub_82138990(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210182c
	if (ctx.cr0.eq) goto loc_8210182C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82136e38
	ctx.lr = 0x82101818;
	sub_82136E38(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82101b08
	if (ctx.cr0.lt) goto loc_82101B08;
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// ori r30,r30,16389
	ctx.r30.u64 = ctx.r30.u64 | 16389;
	// b 0x82101b08
	goto loc_82101B08;
loc_8210182C:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// oris r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 16777216;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
loc_82101838:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82101a2c
	if (ctx.cr6.eq) goto loc_82101A2C;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82101854
	if (!ctx.cr6.eq) goto loc_82101854;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82101858
	goto loc_82101858;
loc_82101854:
	// bl 0x820fbf88
	ctx.lr = 0x82101858;
	sub_820FBF88(ctx, base);
loc_82101858:
	// lwz r11,420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// rlwinm r9,r3,2,24,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFC;
	// stb r9,392(r1)
	REX_STORE_U8(ctx.r1.u32 + 392, ctx.r9.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82101874
	if (ctx.cr6.eq) goto loc_82101874;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// b 0x82101878
	goto loc_82101878;
loc_82101874:
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
loc_82101878:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stb r10,392(r1)
	REX_STORE_U8(ctx.r1.u32 + 392, ctx.r10.u8);
	// beq cr6,0x8210189c
	if (ctx.cr6.eq) goto loc_8210189C;
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// rlwinm r11,r11,2,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x1;
	// b 0x821018a0
	goto loc_821018A0;
loc_8210189C:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_821018A0:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821018b0
	if (ctx.cr6.eq) goto loc_821018B0;
	// ori r11,r10,16
	ctx.r11.u64 = ctx.r10.u64 | 16;
	// stb r11,392(r1)
	REX_STORE_U8(ctx.r1.u32 + 392, ctx.r11.u8);
loc_821018B0:
	// li r11,1000
	ctx.r11.s64 = 1000;
	// stw r24,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r24.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r11,116(r1)
	REX_STORE_U16(ctx.r1.u32 + 116, ctx.r11.u16);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// addi r7,r1,108
	ctx.r7.s64 = ctx.r1.s64 + 108;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ff170
	ctx.lr = 0x821018E0;
	sub_820FF170(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82101af0
	if (ctx.cr0.lt) goto loc_82101AF0;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fcbe8
	ctx.lr = 0x821018F4;
	sub_820FCBE8(ctx, base);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lbz r6,169(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 169);
	// addi r29,r31,400
	ctx.r29.s64 = ctx.r31.s64 + 400;
	// lbz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 168);
	// li r30,5
	ctx.r30.s64 = 5;
	// lwz r23,100(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r8,104(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// stw r24,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r24.u32);
	// mr r7,r23
	ctx.r7.u64 = ctx.r23.u64;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// li r5,169
	ctx.r5.s64 = 169;
	// sth r22,96(r1)
	REX_STORE_U16(ctx.r1.u32 + 96, ctx.r22.u16);
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// sth r30,98(r1)
	REX_STORE_U16(ctx.r1.u32 + 98, ctx.r30.u16);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// bl 0x82108d50
	ctx.lr = 0x82101940;
	sub_82108D50(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fcce0
	ctx.lr = 0x82101950;
	sub_820FCCE0(ctx, base);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82101af4
	if (ctx.cr6.lt) goto loc_82101AF4;
	// li r8,4
	ctx.r8.s64 = 4;
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r7,r31,548
	ctx.r7.s64 = ctx.r31.s64 + 548;
	// li r6,20
	ctx.r6.s64 = 20;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82108ed8
	ctx.lr = 0x82101974;
	sub_82108ED8(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x821019b4
	if (!ctx.cr6.eq) goto loc_821019B4;
	// addi r29,r31,408
	ctx.r29.s64 = ctx.r31.s64 + 408;
	// li r6,1199
	ctx.r6.s64 = 1199;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// li r5,1001
	ctx.r5.s64 = 1001;
	// addi r4,r31,92
	ctx.r4.s64 = ctx.r31.s64 + 92;
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// bl 0x8210c5b0
	ctx.lr = 0x8210199C;
	sub_8210C5B0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82101af4
	if (ctx.cr0.lt) goto loc_82101AF4;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwz r5,108(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x8210c058
	ctx.lr = 0x821019B4;
	sub_8210C058(ctx, base);
loc_821019B4:
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82108f60
	ctx.lr = 0x821019C0;
	sub_82108F60(ctx, base);
	// li r7,5
	ctx.r7.s64 = 5;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,520(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// lwz r4,516(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 516);
	// bl 0x820d7f18
	ctx.lr = 0x821019D8;
	sub_820D7F18(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x821019fc
	if (ctx.cr0.eq) goto loc_821019FC;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bgt cr6,0x821019f0
	if (ctx.cr6.gt) goto loc_821019F0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82101b08
	goto loc_82101B08;
loc_821019F0:
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r30,r11,32775
	ctx.r30.u64 = ctx.r11.u64 | 2147942400;
	// b 0x82101b08
	goto loc_82101B08;
loc_821019FC:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// oris r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 33554432;
	// rlwinm. r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// beq 0x82101ae8
	if (ctx.cr0.eq) goto loc_82101AE8;
	// rlwinm r11,r11,0,23,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bl 0x821015d0
	ctx.lr = 0x82101A20;
	sub_821015D0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82101b08
	if (ctx.cr0.lt) goto loc_82101B08;
	// b 0x82101ae8
	goto loc_82101AE8;
loc_82101A2C:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82101a50
	if (ctx.cr0.eq) goto loc_82101A50;
	// rlwinm r11,r11,0,23,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bl 0x821015d0
	ctx.lr = 0x82101A48;
	sub_821015D0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82101af4
	if (ctx.cr0.lt) goto loc_82101AF4;
loc_82101A50:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r11,3
	ctx.r11.s64 = 3;
	// lwz r4,20(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r24,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r24.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82101A7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
loc_82101A84:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82101adc
	if (ctx.cr6.eq) goto loc_82101ADC;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// bl 0x820d7fa8
	ctx.lr = 0x82101A98;
	sub_820D7FA8(ctx, base);
	// li r5,255
	ctx.r5.s64 = 255;
	// addi r3,r31,256
	ctx.r3.s64 = ctx.r31.s64 + 256;
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82109378
	ctx.lr = 0x82101AA8;
	sub_82109378(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// oris r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 134217728;
	// stw r10,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r10.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82101ADC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82101ADC:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// bne 0x82101a84
	if (!ctx.cr0.eq) goto loc_82101A84;
loc_82101AE8:
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_82101AF0:
	// lwz r23,100(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
loc_82101AF4:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x82101b08
	if (ctx.cr6.eq) goto loc_82101B08;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82108f60
	ctx.lr = 0x82101B08;
	sub_82108F60(ctx, base);
loc_82101B08:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82100fd8
	ctx.lr = 0x82101B14;
	sub_82100FD8(ctx, base);
	// b 0x82101ae8
	goto loc_82101AE8;
}
