DEFINE_REX_FUNC(sub_82079F38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x82079F40;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// addi r29,r27,44
	ctx.r29.s64 = ctx.r27.s64 + 44;
	// lwz r11,44(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 44);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82079fcc
	if (ctx.cr6.eq) goto loc_82079FCC;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// ori r26,r11,65535
	ctx.r26.u64 = ctx.r11.u64 | 65535;
loc_82079F6C:
	// lwz r11,48(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 48);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lwz r31,4(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82079F8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r7,40(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 40);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82079FA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r6,r3,r12
	ctx.r6.u64 = ctx.r3.u64 & ctx.r12.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x82079fc0
	if (ctx.cr6.eq) goto loc_82079FC0;
	// lhz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 24);
	// add r10,r11,r26
	ctx.r10.u64 = ctx.r11.u64 + ctx.r26.u64;
	// sth r10,24(r31)
	REX_STORE_U16(ctx.r31.u32 + 24, ctx.r10.u16);
loc_82079FC0:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// bne 0x82079f6c
	if (!ctx.cr0.eq) goto loc_82079F6C;
loc_82079FCC:
	// lwz r31,4(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lis r24,-32215
	ctx.r24.s64 = -2111242240;
	// addi r26,r10,29632
	ctx.r26.s64 = ctx.r10.s64 + 29632;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r23,r11,-1768
	ctx.r23.s64 = ctx.r11.s64 + -1768;
	// beq cr6,0x8207a024
	if (ctx.cr6.eq) goto loc_8207A024;
	// lbz r11,-22601(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207a00c
	if (!ctx.cr6.eq) goto loc_8207A00C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8207A00C;
	sub_820A71E8(ctx, base);
loc_8207A00C:
	// bl 0x820b5eb8
	ctx.lr = 0x8207A010;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8207A020;
	sub_8209BF18(ctx, base);
	// stw r25,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r25.u32);
loc_8207A024:
	// stw r25,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r25.u32);
	// addi r28,r27,64
	ctx.r28.s64 = ctx.r27.s64 + 64;
	// stw r25,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r25.u32);
	// lwz r11,64(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r25,16(r27)
	REX_STORE_U32(ctx.r27.u32 + 16, ctx.r25.u32);
	// stw r25,20(r27)
	REX_STORE_U32(ctx.r27.u32 + 20, ctx.r25.u32);
	// beq cr6,0x8207a074
	if (ctx.cr6.eq) goto loc_8207A074;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_8207A04C:
	// lwz r11,68(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 68);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8207a068
	if (ctx.cr6.eq) goto loc_8207A068;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82086d30
	ctx.lr = 0x8207A068;
	sub_82086D30(ctx, base);
loc_8207A068:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// bne 0x8207a04c
	if (!ctx.cr0.eq) goto loc_8207A04C;
loc_8207A074:
	// lwz r31,4(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8207a0b8
	if (ctx.cr6.eq) goto loc_8207A0B8;
	// lbz r11,-22601(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207a0a0
	if (!ctx.cr6.eq) goto loc_8207A0A0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8207A0A0;
	sub_820A71E8(ctx, base);
loc_8207A0A0:
	// bl 0x820b5eb8
	ctx.lr = 0x8207A0A4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8207A0B4;
	sub_8209BF18(ctx, base);
	// stw r25,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r25.u32);
loc_8207A0B8:
	// stw r25,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r25.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r25,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r25.u32);
	// bl 0x8207a0d0
	ctx.lr = 0x8207A0C8;
	sub_8207A0D0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
