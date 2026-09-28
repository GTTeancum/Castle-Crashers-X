DEFINE_REX_FUNC(sub_8213F990) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x8213F998;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// lwz r10,72(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// lhz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r27,r11,31,21,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FF;
	// rlwinm r30,r11,20,12,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 20) & 0xFFFFF;
	// bne cr6,0x8213fa24
	if (!ctx.cr6.eq) goto loc_8213FA24;
	// lwz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8213fa04
	if (ctx.cr6.eq) goto loc_8213FA04;
	// bl 0x82136f58
	ctx.lr = 0x8213F9D8;
	sub_82136F58(ctx, base);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// clrldi r10,r3,32
	ctx.r10.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// addi r11,r11,24128
	ctx.r11.s64 = ctx.r11.s64 + 24128;
	// ld r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// cmpldi cr6,r9,0
	ctx.cr6.compare<uint64_t>(ctx.r9.u64, 0, ctx.xer);
	// bne cr6,0x8213f9fc
	if (!ctx.cr6.eq) goto loc_8213F9FC;
	// li r9,20
	ctx.r9.s64 = 20;
	// std r10,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r10.u64);
	// std r9,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r9.u64);
loc_8213F9FC:
	// std r10,24(r31)
	REX_STORE_U64(ctx.r31.u32 + 24, ctx.r10.u64);
	// b 0x8213fa10
	goto loc_8213FA10;
loc_8213FA04:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8213f040
	ctx.lr = 0x8213FA0C;
	sub_8213F040(ctx, base);
	// std r3,24(r31)
	REX_STORE_U64(ctx.r31.u32 + 24, ctx.r3.u64);
loc_8213FA10:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r30,308(r31)
	REX_STORE_U8(ctx.r31.u32 + 308, ctx.r30.u8);
	// sth r27,32(r31)
	REX_STORE_U16(ctx.r31.u32 + 32, ctx.r27.u16);
	// std r25,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r25.u64);
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
loc_8213FA24:
	// lbz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 308);
	// clrlwi r29,r30,24
	ctx.r29.u64 = ctx.r30.u32 & 0xFF;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8213fa40
	if (ctx.cr6.eq) goto loc_8213FA40;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8213f3d0
	ctx.lr = 0x8213FA3C;
	sub_8213F3D0(ctx, base);
	// stb r30,308(r31)
	REX_STORE_U8(ctx.r31.u32 + 308, ctx.r30.u8);
loc_8213FA40:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8213f108
	ctx.lr = 0x8213FA50;
	sub_8213F108(ctx, base);
	// lwz r11,304(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r11.u32);
	// blt cr6,0x8213fa90
	if (ctx.cr6.lt) goto loc_8213FA90;
	// beq cr6,0x8213fb10
	if (ctx.cr6.eq) goto loc_8213FB10;
	// cmplwi cr6,r3,3
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 3, ctx.xer);
	// bge cr6,0x8213fb48
	if (!ctx.cr6.lt) goto loc_8213FB48;
	// lwz r11,360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 360);
	// lwz r10,356(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8213fb44
	if (!ctx.cr6.lt) goto loc_8213FB44;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8213f300
	ctx.lr = 0x8213FA88;
	sub_8213F300(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8213f108
	ctx.lr = 0x8213FA90;
	sub_8213F108(ctx, base);
loc_8213FA90:
	// lwz r30,364(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// addi r29,r31,364
	ctx.r29.s64 = ctx.r31.s64 + 364;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8213fb44
	if (ctx.cr6.eq) goto loc_8213FB44;
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8213fab0
	if (!ctx.cr6.eq) goto loc_8213FAB0;
	// stw r25,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r25.u32);
loc_8213FAB0:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r25,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r25.u32);
	// std r10,24(r11)
	REX_STORE_U64(ctx.r11.u32 + 24, ctx.r10.u64);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x82129a70
	ctx.lr = 0x8213FADC;
	sub_82129A70(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r24,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r24.u32);
	// bl 0x8213f230
	ctx.lr = 0x8213FAF0;
	sub_8213F230(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge 0x8213fb48
	if (!ctx.cr0.lt) goto loc_8213FB48;
	// stw r25,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r25.u32);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8213fb30
	if (ctx.cr6.eq) goto loc_8213FB30;
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// b 0x8213fb34
	goto loc_8213FB34;
loc_8213FB10:
	// lbz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 308);
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8213fb48
	if (!ctx.cr6.eq) goto loc_8213FB48;
	// lwz r11,312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r11.u32);
	// b 0x8213fb48
	goto loc_8213FB48;
loc_8213FB30:
	// stw r30,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
loc_8213FB34:
	// stw r30,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r30.u32);
	// lwz r11,304(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r11.u32);
loc_8213FB44:
	// li r28,1
	ctx.r28.s64 = 1;
loc_8213FB48:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
