DEFINE_REX_FUNC(sub_820FF170) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f4
	ctx.lr = 0x820FF178;
	__savegprlr_19(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r22,r10
	ctx.r22.u64 = ctx.r10.u64;
	// mr r21,r4
	ctx.r21.u64 = ctx.r4.u64;
	// li r3,260
	ctx.r3.s64 = 260;
	// mr r20,r5
	ctx.r20.u64 = ctx.r5.u64;
	// lwz r10,240(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// lwz r11,520(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// mr r19,r7
	ctx.r19.u64 = ctx.r7.u64;
	// rlwinm r27,r10,3,0,28
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r28,236(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 236);
	// mr r23,r8
	ctx.r23.u64 = ctx.r8.u64;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r25,r31,240
	ctx.r25.s64 = ctx.r31.s64 + 240;
	// addi r24,r11,68
	ctx.r24.s64 = ctx.r11.s64 + 68;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82108f48
	ctx.lr = 0x820FF1C8;
	sub_82108F48(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x820ff1dc
	if (!ctx.cr0.eq) goto loc_820FF1DC;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x820ff3a0
	goto loc_820FF3A0;
loc_820FF1DC:
	// lwz r10,720(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// rlwinm. r9,r10,0,2,2
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820ff1f0
	if (ctx.cr0.eq) goto loc_820FF1F0;
	// ori r11,r26,1
	ctx.r11.u64 = ctx.r26.u64 | 1;
loc_820FF1F0:
	// rlwinm. r9,r10,0,3,3
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820ff1fc
	if (ctx.cr0.eq) goto loc_820FF1FC;
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
loc_820FF1FC:
	// rlwinm. r9,r10,0,4,4
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820ff20c
	if (ctx.cr0.eq) goto loc_820FF20C;
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// b 0x820ff218
	goto loc_820FF218;
loc_820FF20C:
	// rlwinm. r9,r10,0,5,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820ff218
	if (ctx.cr0.eq) goto loc_820FF218;
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
loc_820FF218:
	// rlwinm. r10,r10,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820ff224
	if (ctx.cr0.eq) goto loc_820FF224;
	// ori r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 64;
loc_820FF224:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r31,380
	ctx.r9.s64 = ctx.r31.s64 + 380;
loc_820FF22C:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x820ff24c
	if (!ctx.cr6.eq) goto loc_820FF24C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// blt cr6,0x820ff22c
	if (ctx.cr6.lt) goto loc_820FF22C;
	// b 0x820ff268
	goto loc_820FF268;
loc_820FF24C:
	// addi r10,r10,95
	ctx.r10.s64 = ctx.r10.s64 + 95;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// lwz r10,396(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 396);
	// rlwinm. r10,r10,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820ff268
	if (ctx.cr0.eq) goto loc_820FF268;
	// ori r11,r11,128
	ctx.r11.u64 = ctx.r11.u64 | 128;
loc_820FF268:
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// li r11,31
	ctx.r11.s64 = 31;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// li r10,37
	ctx.r10.s64 = 37;
	// ld r9,40(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// addi r26,r31,228
	ctx.r26.s64 = ctx.r31.s64 + 228;
	// std r9,8(r30)
	REX_STORE_U64(ctx.r30.u32 + 8, ctx.r9.u64);
	// stw r22,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r22.u32);
	// lwz r9,228(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// stw r9,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r9.u32);
	// lwz r9,0(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// stw r9,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r9.u32);
	// lwz r9,520(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// sth r9,28(r30)
	REX_STORE_U16(ctx.r30.u32 + 28, ctx.r9.u16);
	// sth r11,30(r30)
	REX_STORE_U16(ctx.r30.u32 + 30, ctx.r11.u16);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// stb r11,32(r30)
	REX_STORE_U8(ctx.r30.u32 + 32, ctx.r11.u8);
	// lbz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 168);
	// stb r11,33(r30)
	REX_STORE_U8(ctx.r30.u32 + 33, ctx.r11.u8);
	// lbz r11,169(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 169);
	// stb r11,34(r30)
	REX_STORE_U8(ctx.r30.u32 + 34, ctx.r11.u8);
	// lbz r11,170(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 170);
	// stb r11,35(r30)
	REX_STORE_U8(ctx.r30.u32 + 35, ctx.r11.u8);
	// lbz r11,171(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 171);
	// stb r11,36(r30)
	REX_STORE_U8(ctx.r30.u32 + 36, ctx.r11.u8);
	// stw r30,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// stw r10,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r10.u32);
	// lwz r3,396(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820ff2f0
	if (ctx.cr6.eq) goto loc_820FF2F0;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// bl 0x8210b2d0
	ctx.lr = 0x820FF2EC;
	sub_8210B2D0(ctx, base);
	// b 0x820ff300
	goto loc_820FF300;
loc_820FF2F0:
	// li r5,15
	ctx.r5.s64 = 15;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x82129fa0
	ctx.lr = 0x820FF300;
	sub_82129FA0(ctx, base);
loc_820FF300:
	// addi r6,r30,37
	ctx.r6.s64 = ctx.r30.s64 + 37;
	// stw r23,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r23.u32);
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r28,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r28.u32);
	// stw r6,16(r29)
	REX_STORE_U32(ctx.r29.u32 + 16, ctx.r6.u32);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// stw r11,12(r29)
	REX_STORE_U32(ctx.r29.u32 + 12, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82108868
	ctx.lr = 0x820FF32C;
	sub_82108868(ctx, base);
	// stw r3,24(r29)
	REX_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
	// stw r27,28(r29)
	REX_STORE_U32(ctx.r29.u32 + 28, ctx.r27.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82107ee0
	ctx.lr = 0x820FF34C;
	sub_82107EE0(ctx, base);
	// lwz r5,520(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// lwz r4,516(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 516);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x82129a70
	ctx.lr = 0x820FF35C;
	sub_82129A70(ctx, base);
	// lwz r11,520(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// li r5,31
	ctx.r5.s64 = 31;
	// addi r3,r31,256
	ctx.r3.s64 = ctx.r31.s64 + 256;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x821094a8
	ctx.lr = 0x820FF370;
	sub_821094A8(ctx, base);
	// stw r30,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r30.u32);
	// stw r24,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r24.u32);
	// li r11,2
	ctx.r11.s64 = 2;
	// cmplwi cr6,r28,1147
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 1147, ctx.xer);
	// bgt cr6,0x820ff398
	if (ctx.cr6.gt) goto loc_820FF398;
	// subfic r10,r28,1147
	ctx.xer.ca = ctx.r28.u32 <= 1147;
	ctx.r10.u64 = static_cast<uint64_t>(1147) - ctx.r28.u64;
	// li r11,3
	ctx.r11.s64 = 3;
	// cmplw cr6,r10,r27
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r27.u32, ctx.xer);
	// blt cr6,0x820ff398
	if (ctx.cr6.lt) goto loc_820FF398;
	// li r11,4
	ctx.r11.s64 = 4;
loc_820FF398:
	// stw r11,0(r19)
	REX_STORE_U32(ctx.r19.u32 + 0, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
loc_820FF3A0:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129944
	__restgprlr_19(ctx, base);
	return;
}
