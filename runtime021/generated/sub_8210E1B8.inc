DEFINE_REX_FUNC(sub_8210E1B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x8210E1C0;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r4,7,25,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 7) & 0x7F;
	// rlwinm r10,r4,14,25,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 14) & 0x7F;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8210e1f0
	if (ctx.cr6.eq) goto loc_8210E1F0;
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4111
	ctx.r31.u64 = ctx.r31.u64 | 4111;
	// b 0x8210e284
	goto loc_8210E284;
loc_8210E1F0:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// addi r28,r29,104
	ctx.r28.s64 = ctx.r29.s64 + 104;
	// clrlwi r9,r4,15
	ctx.r9.u64 = ctx.r4.u32 & 0x1FFFF;
	// ori r10,r10,65534
	ctx.r10.u64 = ctx.r10.u64 | 65534;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// subfic r31,r11,127
	ctx.xer.ca = ctx.r11.u32 <= 127;
	ctx.r31.u64 = static_cast<uint64_t>(127) - ctx.r11.u64;
	// subf r30,r9,r10
	ctx.r30.u64 = ctx.r10.u64 - ctx.r9.u64;
	// rlwinm r27,r4,0,14,14
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x20000;
	// bl 0x8214a434
	ctx.lr = 0x8210E214;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmpwi cr6,r31,2
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 2, ctx.xer);
	// bge cr6,0x8210e248
	if (!ctx.cr6.lt) goto loc_8210E248;
	// addi r10,r31,80
	ctx.r10.s64 = ctx.r31.s64 + 80;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r10,r29
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r29.u32);
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8210e248
	if (!ctx.cr6.lt) goto loc_8210E248;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne cr6,0x8210e240
	if (!ctx.cr6.eq) goto loc_8210E240;
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
loc_8210E240:
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x8210e254
	if (!ctx.cr6.eq) goto loc_8210E254;
loc_8210E248:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4111
	ctx.r31.u64 = ctx.r31.u64 | 4111;
	// b 0x8210e27c
	goto loc_8210E27C;
loc_8210E254:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x8210e260
	if (ctx.cr6.eq) goto loc_8210E260;
	// stw r31,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r31.u32);
loc_8210E260:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x8210e26c
	if (ctx.cr6.eq) goto loc_8210E26C;
	// stw r30,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r30.u32);
loc_8210E26C:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8210e278
	if (ctx.cr6.eq) goto loc_8210E278;
	// stw r27,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r27.u32);
loc_8210E278:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8210E27C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a444
	ctx.lr = 0x8210E284;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8210E284:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
