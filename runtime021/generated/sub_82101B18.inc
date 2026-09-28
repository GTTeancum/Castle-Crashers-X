DEFINE_REX_FUNC(sub_82101B18) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x82101B20;
	__savegprlr_25(ctx, base);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x82101b38
	if (!ctx.cr6.lt) goto loc_82101B38;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// b 0x82101d6c
	goto loc_82101D6C;
loc_82101B38:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bne cr6,0x82101b50
	if (!ctx.cr6.eq) goto loc_82101B50;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,1235
	ctx.r30.u64 = ctx.r30.u64 | 1235;
	// b 0x82101d6c
	goto loc_82101D6C;
loc_82101B50:
	// li r25,0
	ctx.r25.s64 = 0;
	// addi r27,r1,160
	ctx.r27.s64 = ctx.r1.s64 + 160;
	// mr r26,r25
	ctx.r26.u64 = ctx.r25.u64;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// addi r28,r31,380
	ctx.r28.s64 = ctx.r31.s64 + 380;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
loc_82101B68:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82101bac
	if (ctx.cr6.eq) goto loc_82101BAC;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ffe78
	ctx.lr = 0x82101B84;
	sub_820FFE78(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
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
	// b 0x82101bbc
	goto loc_82101BBC;
loc_82101BAC:
	// li r5,42
	ctx.r5.s64 = 42;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82129fa0
	ctx.lr = 0x82101BBC;
	sub_82129FA0(ctx, base);
loc_82101BBC:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// addi r27,r27,42
	ctx.r27.s64 = ctx.r27.s64 + 42;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x82101b68
	if (ctx.cr6.lt) goto loc_82101B68;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82101be4
	if (!ctx.cr6.eq) goto loc_82101BE4;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82101be8
	goto loc_82101BE8;
loc_82101BE4:
	// bl 0x820fbf88
	ctx.lr = 0x82101BE8;
	sub_820FBF88(ctx, base);
loc_82101BE8:
	// lwz r11,420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// rlwinm r9,r3,2,24,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFC;
	// stb r9,328(r1)
	REX_STORE_U8(ctx.r1.u32 + 328, ctx.r9.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82101c04
	if (ctx.cr6.eq) goto loc_82101C04;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// b 0x82101c08
	goto loc_82101C08;
loc_82101C04:
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
loc_82101C08:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stb r10,328(r1)
	REX_STORE_U8(ctx.r1.u32 + 328, ctx.r10.u8);
	// beq cr6,0x82101c2c
	if (ctx.cr6.eq) goto loc_82101C2C;
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// rlwinm r11,r11,2,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x1;
	// b 0x82101c30
	goto loc_82101C30;
loc_82101C2C:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_82101C30:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82101c40
	if (ctx.cr6.eq) goto loc_82101C40;
	// ori r11,r10,16
	ctx.r11.u64 = ctx.r10.u64 | 16;
	// stb r11,328(r1)
	REX_STORE_U8(ctx.r1.u32 + 328, ctx.r11.u8);
loc_82101C40:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82138990
	ctx.lr = 0x82101C58;
	sub_82138990(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82101c7c
	if (ctx.cr0.eq) goto loc_82101C7C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82136e38
	ctx.lr = 0x82101C68;
	sub_82136E38(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82101d6c
	if (ctx.cr0.lt) goto loc_82101D6C;
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// ori r30,r30,16389
	ctx.r30.u64 = ctx.r30.u64 | 16389;
	// b 0x82101d6c
	goto loc_82101D6C;
loc_82101C7C:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// li r30,1000
	ctx.r30.s64 = 1000;
	// stw r25,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r25.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// oris r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 16777216;
	// sth r30,96(r1)
	REX_STORE_U16(ctx.r1.u32 + 96, ctx.r30.u16);
	// addi r4,r31,48
	ctx.r4.s64 = ctx.r31.s64 + 48;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// addi r3,r31,56
	ctx.r3.s64 = ctx.r31.s64 + 56;
	// bl 0x820d7eb8
	ctx.lr = 0x82101CA4;
	sub_820D7EB8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82101cc8
	if (ctx.cr0.eq) goto loc_82101CC8;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bgt cr6,0x82101cbc
	if (ctx.cr6.gt) goto loc_82101CBC;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82101d6c
	goto loc_82101D6C;
loc_82101CBC:
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r30,r11,32775
	ctx.r30.u64 = ctx.r11.u64 | 2147942400;
	// b 0x82101d6c
	goto loc_82101D6C;
loc_82101CC8:
	// sth r30,88(r1)
	REX_STORE_U16(ctx.r1.u32 + 88, ctx.r30.u16);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fcbe8
	ctx.lr = 0x82101CD8;
	sub_820FCBE8(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r6,5
	ctx.r6.s64 = 5;
	// addi r29,r31,400
	ctx.r29.s64 = ctx.r31.s64 + 400;
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// stw r25,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r25.u32);
	// sth r6,82(r1)
	REX_STORE_U16(ctx.r1.u32 + 82, ctx.r6.u16);
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// sth r10,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,169
	ctx.r6.s64 = 169;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,92
	ctx.r3.s64 = ctx.r1.s64 + 92;
	// bl 0x82108db0
	ctx.lr = 0x82101D14;
	sub_82108DB0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fcce0
	ctx.lr = 0x82101D24;
	sub_820FCCE0(ctx, base);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82101d6c
	if (ctx.cr6.lt) goto loc_82101D6C;
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
	ctx.lr = 0x82101D48;
	sub_82108ED8(ctx, base);
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82101d78
	if (ctx.cr0.eq) goto loc_82101D78;
	// rlwinm r11,r11,0,23,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bl 0x821015d0
	ctx.lr = 0x82101D64;
	sub_821015D0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82101d78
	if (!ctx.cr0.lt) goto loc_82101D78;
loc_82101D6C:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82100fd8
	ctx.lr = 0x82101D78;
	sub_82100FD8(ctx, base);
loc_82101D78:
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
