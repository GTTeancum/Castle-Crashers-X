DEFINE_REX_FUNC(sub_820D7708) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820D7710;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,23980(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 23980);
	// rlwinm. r11,r11,0,23,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820d7878
	if (!ctx.cr0.eq) goto loc_820D7878;
	// lis r4,-19072
	ctx.r4.s64 = -1249902592;
	// li r3,200
	ctx.r3.s64 = 200;
	// bl 0x82136670
	ctx.lr = 0x820D7730;
	sub_82136670(ctx, base);
	// stw r3,11804(r30)
	REX_STORE_U32(ctx.r30.u32 + 11804, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x820d7744
	if (!ctx.cr0.eq) goto loc_820D7744;
loc_820D773C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820d787c
	goto loc_820D787C;
loc_820D7744:
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r11,23980(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 23980);
	// lis r24,256
	ctx.r24.s64 = 16777216;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// stw r27,11012(r30)
	REX_STORE_U32(ctx.r30.u32 + 11012, ctx.r27.u32);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
loc_820D775C:
	// slw r8,r24,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r10.u8 & 0x3F));
	// and. r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x820d776c
	if (ctx.cr0.eq) goto loc_820D776C;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_820D776C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r10,6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 6, ctx.xer);
	// blt cr6,0x820d775c
	if (ctx.cr6.lt) goto loc_820D775C;
	// lwz r10,14896(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 14896);
	// lis r8,-16384
	ctx.r8.s64 = -1073741824;
	// lwz r7,14900(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 14900);
	// rlwinm. r11,r11,0,5,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r8,11028(r30)
	REX_STORE_U32(ctx.r30.u32 + 11028, ctx.r8.u32);
	// li r26,-1
	ctx.r26.s64 = -1;
	// stw r9,10984(r30)
	REX_STORE_U32(ctx.r30.u32 + 10984, ctx.r9.u32);
	// stw r27,10988(r30)
	REX_STORE_U32(ctx.r30.u32 + 10988, ctx.r27.u32);
	// stw r10,10948(r30)
	REX_STORE_U32(ctx.r30.u32 + 10948, ctx.r10.u32);
	// stw r7,10956(r30)
	REX_STORE_U32(ctx.r30.u32 + 10956, ctx.r7.u32);
	// beq 0x820d77ac
	if (ctx.cr0.eq) goto loc_820D77AC;
	// li r26,2
	ctx.r26.s64 = 2;
	// stw r26,11320(r30)
	REX_STORE_U32(ctx.r30.u32 + 11320, ctx.r26.u32);
loc_820D77AC:
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// lis r28,32512
	ctx.r28.s64 = 2130706432;
	// addi r31,r30,11364
	ctx.r31.s64 = ctx.r30.s64 + 11364;
	// lis r25,-32256
	ctx.r25.s64 = -2113929216;
loc_820D77BC:
	// lwz r11,23980(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 23980);
	// slw r10,r24,r29
	ctx.r10.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r29.u8 & 0x3F));
	// and. r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d785c
	if (ctx.cr0.eq) goto loc_820D785C;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bge cr6,0x820d77dc
	if (!ctx.cr6.lt) goto loc_820D77DC;
	// mr r26,r29
	ctx.r26.u64 = ctx.r29.u64;
	// stw r29,11320(r30)
	REX_STORE_U32(ctx.r30.u32 + 11320, ctx.r29.u32);
loc_820D77DC:
	// addis r11,r28,16640
	ctx.r11.s64 = ctx.r28.s64 + 1090519040;
	// stw r29,-36(r31)
	REX_STORE_U32(ctx.r31.u32 + -36, ctx.r29.u32);
	// addi r10,r30,10944
	ctx.r10.s64 = ctx.r30.s64 + 10944;
	// stw r28,-12(r31)
	REX_STORE_U32(ctx.r31.u32 + -12, ctx.r28.u32);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// stw r10,-40(r31)
	REX_STORE_U32(ctx.r31.u32 + -40, ctx.r10.u32);
	// addi r6,r31,-40
	ctx.r6.s64 = ctx.r31.s64 + -40;
	// stw r11,-16(r31)
	REX_STORE_U32(ctx.r31.u32 + -16, ctx.r11.u32);
	// lis r11,-32243
	ctx.r11.s64 = -2113077248;
	// stb r27,-8(r31)
	REX_STORE_U8(ctx.r31.u32 + -8, ctx.r27.u8);
	// addi r8,r31,12
	ctx.r8.s64 = ctx.r31.s64 + 12;
	// stw r27,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r27.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r31,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r31.u32);
	// addi r5,r11,30072
	ctx.r5.s64 = ctx.r11.s64 + 30072;
	// stw r31,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r31.u32);
	// lis r4,1
	ctx.r4.s64 = 65536;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820b5d60
	ctx.lr = 0x820D7828;
	sub_820B5D60(ctx, base);
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x820d773c
	if (ctx.cr0.eq) goto loc_820D773C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,1684(r25)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r25.u32 + 1684);
	// bl 0x8214a474
	ctx.lr = 0x820D7840;
	__imp__ObReferenceObjectByHandle(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820d785c
	if (ctx.cr0.lt) goto loc_820D785C;
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8214a464
	ctx.lr = 0x820D7854;
	__imp__KeSetBasePriorityThread(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8214a454
	ctx.lr = 0x820D785C;
	__imp__ObDereferenceObject(ctx, base);
loc_820D785C:
	// lis r11,32512
	ctx.r11.s64 = 2130706432;
	// addi r28,r28,128
	ctx.r28.s64 = ctx.r28.s64 + 128;
	// ori r11,r11,768
	ctx.r11.u64 = ctx.r11.u64 | 768;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r31,r31,80
	ctx.r31.s64 = ctx.r31.s64 + 80;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820d77bc
	if (ctx.cr6.lt) goto loc_820D77BC;
loc_820D7878:
	// li r3,1
	ctx.r3.s64 = 1;
loc_820D787C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
