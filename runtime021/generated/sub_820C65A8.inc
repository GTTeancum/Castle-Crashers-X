DEFINE_REX_FUNC(sub_820C65A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x820C65B0;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// lbz r11,10941(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 10941);
	// lwz r25,14900(r26)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r26.u32 + 14900);
	// lwz r24,14896(r26)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r26.u32 + 14896);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820c664c
	if (ctx.cr0.eq) goto loc_820C664C;
	// lwz r11,21532(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 21532);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820c6784
	if (ctx.cr6.eq) goto loc_820C6784;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820c6784
	if (ctx.cr6.eq) goto loc_820C6784;
	// lis r21,8192
	ctx.r21.s64 = 536870912;
	// lis r22,16384
	ctx.r22.s64 = 1073741824;
	// lis r23,16640
	ctx.r23.s64 = 1090519040;
loc_820C65F4:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r21
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r21.u32, ctx.xer);
	// clrlwi r5,r10,8
	ctx.r5.u64 = ctx.r10.u32 & 0xFFFFFF;
	// subf r4,r22,r11
	ctx.r4.u64 = ctx.r11.u64 - ctx.r22.u64;
	// blt cr6,0x820c6610
	if (ctx.cr6.lt) goto loc_820C6610;
	// subf r4,r23,r11
	ctx.r4.u64 = ctx.r11.u64 - ctx.r23.u64;
loc_820C6610:
	// lwz r3,21532(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 21532);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820C6628;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,21532(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 21532);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820C663C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// bne 0x820c65f4
	if (!ctx.cr0.eq) goto loc_820C65F4;
	// b 0x820c6784
	goto loc_820C6784;
loc_820C664C:
	// lwz r29,10952(r26)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r26.u32 + 10952);
	// mulli r5,r31,3
	ctx.r5.s64 = static_cast<int64_t>(ctx.r31.u64 * static_cast<uint64_t>(3));
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x820c5ee8
	ctx.lr = 0x820C6660;
	sub_820C5EE8(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820c672c
	if (ctx.cr6.eq) goto loc_820C672C;
	// mr r27,r31
	ctx.r27.u64 = ctx.r31.u64;
	// lis r21,8192
	ctx.r21.s64 = 536870912;
	// lis r22,16384
	ctx.r22.s64 = 1073741824;
	// lis r23,16640
	ctx.r23.s64 = 1090519040;
loc_820C6678:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r3,21532(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 21532);
	// lwz r31,4(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// clrlwi r28,r11,8
	ctx.r28.u64 = ctx.r11.u32 & 0xFFFFFF;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820c66b8
	if (ctx.cr6.eq) goto loc_820C66B8;
	// cmplw cr6,r31,r21
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r21.u32, ctx.xer);
	// subf r4,r22,r31
	ctx.r4.u64 = ctx.r31.u64 - ctx.r22.u64;
	// blt cr6,0x820c66a0
	if (ctx.cr6.lt) goto loc_820C66A0;
	// subf r4,r23,r31
	ctx.r4.u64 = ctx.r31.u64 - ctx.r23.u64;
loc_820C66A0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820C66B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820C66B8:
	// lwz r11,23356(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 23356);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820c66e8
	if (ctx.cr6.eq) goto loc_820C66E8;
	// cmplw cr6,r31,r21
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r21.u32, ctx.xer);
	// subf r4,r22,r31
	ctx.r4.u64 = ctx.r31.u64 - ctx.r22.u64;
	// blt cr6,0x820c66d4
	if (ctx.cr6.lt) goto loc_820C66D4;
	// subf r4,r23,r31
	ctx.r4.u64 = ctx.r31.u64 - ctx.r23.u64;
loc_820C66D4:
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820C66E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820C66E8:
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// and r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 & ctx.r25.u64;
	// lis r9,-16383
	ctx.r9.s64 = -1073676288;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// and r11,r8,r25
	ctx.r11.u64 = ctx.r8.u64 & ctx.r25.u64;
	// ori r9,r9,16128
	ctx.r9.u64 = ctx.r9.u64 | 16128;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwx r9,r10,r24
	REX_STORE_U32(ctx.r10.u32 + ctx.r24.u32, ctx.r9.u32);
	// stwx r31,r7,r24
	REX_STORE_U32(ctx.r7.u32 + ctx.r24.u32, ctx.r31.u32);
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// and r29,r11,r25
	ctx.r29.u64 = ctx.r11.u64 & ctx.r25.u64;
	// stwx r28,r8,r24
	REX_STORE_U32(ctx.r8.u32 + ctx.r24.u32, ctx.r28.u32);
	// bne 0x820c6678
	if (!ctx.cr0.eq) goto loc_820C6678;
loc_820C672C:
	// stw r29,10952(r26)
	REX_STORE_U32(ctx.r26.u32 + 10952, ctx.r29.u32);
	// sync 
	// lis r11,32712
	ctx.r11.s64 = 2143813632;
	// stw r29,1812(r11)
	REX_MM_STORE_U32(ctx.r11.u32 + 1812, ctx.r29.u32);
	// eieio 
	// sync 
	// lwz r3,21532(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 21532);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820c6760
	if (ctx.cr6.eq) goto loc_820C6760;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_MM_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820C6760;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820C6760:
	// lwz r11,23356(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 23356);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820c6784
	if (ctx.cr6.eq) goto loc_820C6784;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820C6784;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820C6784:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
