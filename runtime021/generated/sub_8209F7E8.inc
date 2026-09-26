DEFINE_REX_FUNC(sub_8209F7E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x8209F7F0;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// addis r22,r30,2
	ctx.r22.s64 = ctx.r30.s64 + 131072;
	// ori r7,r11,59588
	ctx.r7.u64 = ctx.r11.u64 | 59588;
	// ori r6,r10,59620
	ctx.r6.u64 = ctx.r10.u64 | 59620;
	// ori r5,r9,59632
	ctx.r5.u64 = ctx.r9.u64 | 59632;
	// ori r4,r8,59644
	ctx.r4.u64 = ctx.r8.u64 | 59644;
	// addi r22,r22,-5888
	ctx.r22.s64 = ctx.r22.s64 + -5888;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r3,640
	ctx.r3.s64 = 640;
	// li r11,480
	ctx.r11.s64 = 480;
	// stw r31,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r31.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r3,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r3.u32);
	// stb r31,9(r30)
	REX_STORE_U8(ctx.r30.u32 + 9, ctx.r31.u8);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// stw r31,256(r30)
	REX_STORE_U32(ctx.r30.u32 + 256, ctx.r31.u32);
	// stw r31,260(r30)
	REX_STORE_U32(ctx.r30.u32 + 260, ctx.r31.u32);
	// stwx r31,r30,r7
	REX_STORE_U32(ctx.r30.u32 + ctx.r7.u32, ctx.r31.u32);
	// stwx r31,r30,r6
	REX_STORE_U32(ctx.r30.u32 + ctx.r6.u32, ctx.r31.u32);
	// stwx r31,r30,r5
	REX_STORE_U32(ctx.r30.u32 + ctx.r5.u32, ctx.r31.u32);
	// stwx r10,r30,r4
	REX_STORE_U32(ctx.r30.u32 + ctx.r4.u32, ctx.r10.u32);
	// stw r31,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r31.u32);
	// bl 0x8209f9f0
	ctx.lr = 0x8209F864;
	sub_8209F9F0(ctx, base);
	// addis r29,r30,2
	ctx.r29.s64 = ctx.r30.s64 + 131072;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r27,r30,64
	ctx.r27.s64 = ctx.r30.s64 + 64;
	// addi r29,r29,-6000
	ctx.r29.s64 = ctx.r29.s64 + -6000;
	// li r26,4
	ctx.r26.s64 = 4;
	// ori r28,r9,59516
	ctx.r28.u64 = ctx.r9.u64 | 59516;
	// lis r25,-32215
	ctx.r25.s64 = -2111242240;
	// addi r24,r10,29632
	ctx.r24.s64 = ctx.r10.s64 + 29632;
	// addi r23,r11,-1768
	ctx.r23.s64 = ctx.r11.s64 + -1768;
loc_8209F890:
	// lbz r11,-22601(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209f8b0
	if (!ctx.cr6.eq) goto loc_8209F8B0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209F8B0;
	sub_820A71E8(ctx, base);
loc_8209F8B0:
	// bl 0x820b5eb8
	ctx.lr = 0x8209F8B4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8209F8C4;
	sub_8209BDD8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8209f8e4
	if (ctx.cr6.eq) goto loc_8209F8E4;
	// stw r31,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r31.u32);
	// stw r31,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r31.u32);
	// stw r31,12(r4)
	REX_STORE_U32(ctx.r4.u32 + 12, ctx.r31.u32);
	// stb r31,0(r4)
	REX_STORE_U8(ctx.r4.u32 + 0, ctx.r31.u8);
	// b 0x8209f8e8
	goto loc_8209F8E8;
loc_8209F8E4:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
loc_8209F8E8:
	// subf r11,r28,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r4,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// bl 0x8209d2d0
	ctx.lr = 0x8209F8F8;
	sub_8209D2D0(ctx, base);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// stw r31,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r31.u32);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// li r10,12
	ctx.r10.s64 = 12;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8209F90C:
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8209f90c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8209F90C;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addi r27,r27,48
	ctx.r27.s64 = ctx.r27.s64 + 48;
	// bne 0x8209f890
	if (!ctx.cr0.eq) goto loc_8209F890;
	// lbz r11,-22601(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209f948
	if (!ctx.cr6.eq) goto loc_8209F948;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209F948;
	sub_820A71E8(ctx, base);
loc_8209F948:
	// bl 0x820b5eb8
	ctx.lr = 0x8209F94C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,76
	ctx.r4.s64 = 76;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8209F95C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209f9b8
	if (ctx.cr6.eq) goto loc_8209F9B8;
	// li r10,102
	ctx.r10.s64 = 102;
	// stw r31,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r31.u32);
	// stb r31,12(r3)
	REX_STORE_U8(ctx.r3.u32 + 12, ctx.r31.u8);
	// addi r11,r3,60
	ctx.r11.s64 = ctx.r3.s64 + 60;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r31,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// stw r31,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r31.u32);
	// stw r31,64(r3)
	REX_STORE_U32(ctx.r3.u32 + 64, ctx.r31.u32);
	// stw r31,68(r3)
	REX_STORE_U32(ctx.r3.u32 + 68, ctx.r31.u32);
	// stw r31,72(r3)
	REX_STORE_U32(ctx.r3.u32 + 72, ctx.r31.u32);
	// stb r31,40(r3)
	REX_STORE_U8(ctx.r3.u32 + 40, ctx.r31.u8);
	// stw r31,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r31.u32);
	// stw r31,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r31.u32);
	// stw r31,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r31.u32);
	// stw r31,56(r3)
	REX_STORE_U32(ctx.r3.u32 + 56, ctx.r31.u32);
	// stb r31,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r31.u8);
	// stw r31,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r31.u32);
	// stw r31,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r31.u32);
	// stw r31,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r31.u32);
	// stw r31,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// b 0x8209f9bc
	goto loc_8209F9BC;
loc_8209F9B8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8209F9BC:
	// stw r3,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r3.u32);
	// addi r11,r30,36
	ctx.r11.s64 = ctx.r30.s64 + 36;
	// li r10,7
	ctx.r10.s64 = 7;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8209F9CC:
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8209f9cc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8209F9CC;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8214a1f4
	ctx.lr = 0x8209F9E0;
	__imp__XNotifyPositionUI(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
