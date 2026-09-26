DEFINE_REX_FUNC(sub_820CF728) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820CF730;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r25,276(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// mr r27,r9
	ctx.r27.u64 = ctx.r9.u64;
	// mr r26,r10
	ctx.r26.u64 = ctx.r10.u64;
	// stw r29,21680(r31)
	REX_STORE_U32(ctx.r31.u32 + 21680, ctx.r29.u32);
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// stw r28,21684(r31)
	REX_STORE_U32(ctx.r31.u32 + 21684, ctx.r28.u32);
	// rlwinm. r11,r4,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r27,21688(r31)
	REX_STORE_U32(ctx.r31.u32 + 21688, ctx.r27.u32);
	// stw r30,21692(r31)
	REX_STORE_U32(ctx.r31.u32 + 21692, ctx.r30.u32);
	// stw r26,21696(r31)
	REX_STORE_U32(ctx.r31.u32 + 21696, ctx.r26.u32);
	// stw r25,21700(r31)
	REX_STORE_U32(ctx.r31.u32 + 21700, ctx.r25.u32);
	// beq 0x820cf77c
	if (ctx.cr0.eq) goto loc_820CF77C;
	// addi r3,r31,21704
	ctx.r3.s64 = ctx.r31.s64 + 21704;
	// bl 0x8214a864
	ctx.lr = 0x820CF77C;
	__imp__VdQueryVideoMode(ctx, base);
loc_820CF77C:
	// lwz r11,21536(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21536);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cf84c
	if (ctx.cr0.eq) goto loc_820CF84C;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// bne cr6,0x820cf7c4
	if (!ctx.cr6.eq) goto loc_820CF7C4;
	// lbz r11,10941(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10941);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820cf7c4
	if (!ctx.cr0.eq) goto loc_820CF7C4;
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cf038
	ctx.lr = 0x820CF7BC;
	sub_820CF038(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x820cf814
	goto loc_820CF814;
loc_820CF7C4:
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x82129fa0
	ctx.lr = 0x820CF7D4;
	sub_82129FA0(ctx, base);
	// cntlzw r11,r24
	ctx.r11.u64 = ctx.r24.u32 == 0 ? 32 : __builtin_clz(ctx.r24.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r10,r11,1
	ctx.r10.u64 = ctx.r11.u64 ^ 1;
	// lwz r11,1676(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 1676);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cf810
	if (ctx.cr6.eq) goto loc_820CF810;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,92
	ctx.r3.s64 = 92;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CF810;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CF810:
	// lwz r30,104(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_820CF814:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r4,48(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820cf830
	if (!ctx.cr6.gt) goto loc_820CF830;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7228
	ctx.lr = 0x820CF82C;
	sub_820C7228(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_820CF830:
	// lis r11,-32243
	ctx.r11.s64 = -2113077248;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// addi r6,r11,-12120
	ctx.r6.s64 = ctx.r11.s64 + -12120;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c6be8
	ctx.lr = 0x820CF848;
	sub_820C6BE8(ctx, base);
	// stw r3,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
loc_820CF84C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
