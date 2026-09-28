DEFINE_REX_FUNC(sub_820AF600) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820AF608;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x820af6fc
	if (!ctx.cr6.gt) goto loc_820AF6FC;
	// lbz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x820af6c0
	if (!ctx.cr6.eq) goto loc_820AF6C0;
	// lhz r8,164(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 164);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lhz r9,160(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 160);
	// addi r10,r31,168
	ctx.r10.s64 = ctx.r31.s64 + 168;
	// lhz r7,156(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 156);
	// li r11,121
	ctx.r11.s64 = 121;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lhz r6,152(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 152);
	// lhz r5,148(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 148);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lhz r7,144(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 144);
	// lhz r8,140(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 140);
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
loc_820AF67C:
	// lhz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// add r4,r8,r4
	ctx.r4.u64 = ctx.r8.u64 + ctx.r4.u64;
	// bne 0x820af67c
	if (!ctx.cr0.eq) goto loc_820AF67C;
	// addi r10,r31,652
	ctx.r10.s64 = ctx.r31.s64 + 652;
	// li r11,128
	ctx.r11.s64 = 128;
loc_820AF698:
	// lhz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// bne 0x820af698
	if (!ctx.cr0.eq) goto loc_820AF698;
	// rlwinm r11,r4,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFF;
	// subfc r10,r9,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r9.u32;
	ctx.r10.u64 = ctx.r11.u64 - ctx.r9.u64;
	// subfe r11,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stb r9,28(r31)
	REX_STORE_U8(ctx.r31.u32 + 28, ctx.r9.u8);
loc_820AF6C0:
	// addi r4,r31,2832
	ctx.r4.s64 = ctx.r31.s64 + 2832;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ae790
	ctx.lr = 0x820AF6CC;
	sub_820AE790(ctx, base);
	// addi r4,r31,2844
	ctx.r4.s64 = ctx.r31.s64 + 2844;
	// bl 0x820ae790
	ctx.lr = 0x820AF6D4;
	sub_820AE790(ctx, base);
	// bl 0x820af120
	ctx.lr = 0x820AF6D8;
	sub_820AF120(ctx, base);
	// lwz r10,5792(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 5792);
	// lwz r11,5796(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5796);
	// addi r10,r10,10
	ctx.r10.s64 = ctx.r10.s64 + 10;
	// addi r9,r11,10
	ctx.r9.s64 = ctx.r11.s64 + 10;
	// rlwinm r11,r10,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r10,r9,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820af704
	if (ctx.cr6.gt) goto loc_820AF704;
	// b 0x820af700
	goto loc_820AF700;
loc_820AF6FC:
	// addi r10,r30,5
	ctx.r10.s64 = ctx.r30.s64 + 5;
loc_820AF700:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820AF704:
	// addi r9,r30,4
	ctx.r9.s64 = ctx.r30.s64 + 4;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820af730
	if (ctx.cr6.gt) goto loc_820AF730;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820af730
	if (ctx.cr6.eq) goto loc_820AF730;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820af4c0
	ctx.lr = 0x820AF72C;
	sub_820AF4C0(ctx, base);
	// b 0x820af888
	goto loc_820AF888;
loc_820AF730:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// lwz r10,5812(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 5812);
	// lhz r9,5808(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 5808);
	// bne cr6,0x820af7dc
	if (!ctx.cr6.eq) goto loc_820AF7DC;
	// addi r11,r27,2
	ctx.r11.s64 = ctx.r27.s64 + 2;
	// cmpwi cr6,r10,13
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 13, ctx.xer);
	// slw r7,r11,r10
	ctx.r7.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// ble cr6,0x820af7bc
	if (!ctx.cr6.gt) goto loc_820AF7BC;
	// or r5,r7,r9
	ctx.r5.u64 = ctx.r7.u64 | ctx.r9.u64;
	// lwz r8,20(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r6,8(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// clrlwi r3,r5,16
	ctx.r3.u64 = ctx.r5.u32 & 0xFFFF;
	// sth r3,5808(r31)
	REX_STORE_U16(ctx.r31.u32 + 5808, ctx.r3.u16);
	// stbx r3,r8,r6
	REX_STORE_U8(ctx.r8.u32 + ctx.r6.u32, ctx.r3.u8);
	// lbz r10,5808(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 5808);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stbx r10,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u8);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,5812(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5812);
	// subfic r8,r11,16
	ctx.xer.ca = ctx.r11.u32 <= 16;
	ctx.r8.u64 = static_cast<uint64_t>(16) - ctx.r11.u64;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// addi r5,r11,-13
	ctx.r5.s64 = ctx.r11.s64 + -13;
	// srw r4,r4,r7
	ctx.r4.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (ctx.r7.u8 & 0x3F));
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// sth r4,5808(r31)
	REX_STORE_U16(ctx.r31.u32 + 5808, ctx.r4.u16);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r5,5812(r31)
	REX_STORE_U32(ctx.r31.u32 + 5812, ctx.r5.u32);
	// addi r4,r11,13808
	ctx.r4.s64 = ctx.r11.s64 + 13808;
	// stw r6,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r6.u32);
	// addi r5,r4,1152
	ctx.r5.s64 = ctx.r4.s64 + 1152;
	// b 0x820af880
	goto loc_820AF880;
loc_820AF7BC:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r8,r10,3
	ctx.r8.s64 = ctx.r10.s64 + 3;
	// or r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 | ctx.r9.u64;
	// addi r4,r11,13808
	ctx.r4.s64 = ctx.r11.s64 + 13808;
	// stw r8,5812(r31)
	REX_STORE_U32(ctx.r31.u32 + 5812, ctx.r8.u32);
	// sth r6,5808(r31)
	REX_STORE_U16(ctx.r31.u32 + 5808, ctx.r6.u16);
	// addi r5,r4,1152
	ctx.r5.s64 = ctx.r4.s64 + 1152;
	// b 0x820af880
	goto loc_820AF880;
loc_820AF7DC:
	// addi r11,r27,4
	ctx.r11.s64 = ctx.r27.s64 + 4;
	// cmpwi cr6,r10,13
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 13, ctx.xer);
	// slw r7,r11,r10
	ctx.r7.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// ble cr6,0x820af84c
	if (!ctx.cr6.gt) goto loc_820AF84C;
	// or r5,r7,r9
	ctx.r5.u64 = ctx.r7.u64 | ctx.r9.u64;
	// lwz r8,20(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r6,8(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// clrlwi r11,r5,16
	ctx.r11.u64 = ctx.r5.u32 & 0xFFFF;
	// sth r11,5808(r31)
	REX_STORE_U16(ctx.r31.u32 + 5808, ctx.r11.u16);
	// stbx r11,r8,r6
	REX_STORE_U8(ctx.r8.u32 + ctx.r6.u32, ctx.r11.u8);
	// lbz r9,5808(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 5808);
	// lwz r8,8(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stbx r9,r11,r8
	REX_STORE_U8(ctx.r11.u32 + ctx.r8.u32, ctx.r9.u8);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,5812(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5812);
	// subfic r7,r11,16
	ctx.xer.ca = ctx.r11.u32 <= 16;
	ctx.r7.u64 = static_cast<uint64_t>(16) - ctx.r11.u64;
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,-13
	ctx.r11.s64 = ctx.r11.s64 + -13;
	// srw r10,r4,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (ctx.r6.u8 & 0x3F));
	// stw r5,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r5.u32);
	// stw r11,5812(r31)
	REX_STORE_U32(ctx.r31.u32 + 5812, ctx.r11.u32);
	// sth r10,5808(r31)
	REX_STORE_U16(ctx.r31.u32 + 5808, ctx.r10.u16);
	// b 0x820af85c
	goto loc_820AF85C;
loc_820AF84C:
	// addi r8,r10,3
	ctx.r8.s64 = ctx.r10.s64 + 3;
	// or r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 | ctx.r9.u64;
	// stw r8,5812(r31)
	REX_STORE_U32(ctx.r31.u32 + 5812, ctx.r8.u32);
	// sth r6,5808(r31)
	REX_STORE_U16(ctx.r31.u32 + 5808, ctx.r6.u16);
loc_820AF85C:
	// lwz r10,2848(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 2848);
	// addi r6,r3,1
	ctx.r6.s64 = ctx.r3.s64 + 1;
	// lwz r11,2836(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2836);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// bl 0x820af220
	ctx.lr = 0x820AF878;
	sub_820AF220(ctx, base);
	// addi r5,r31,2432
	ctx.r5.s64 = ctx.r31.s64 + 2432;
	// addi r4,r31,140
	ctx.r4.s64 = ctx.r31.s64 + 140;
loc_820AF880:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820af900
	ctx.lr = 0x820AF888;
	sub_820AF900(ctx, base);
loc_820AF888:
	// addi r10,r31,140
	ctx.r10.s64 = ctx.r31.s64 + 140;
	// li r11,286
	ctx.r11.s64 = 286;
loc_820AF890:
	// sth r28,0(r10)
	REX_STORE_U16(ctx.r10.u32 + 0, ctx.r28.u16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x820af890
	if (!ctx.cr0.eq) goto loc_820AF890;
	// addi r10,r31,2432
	ctx.r10.s64 = ctx.r31.s64 + 2432;
	// li r11,30
	ctx.r11.s64 = 30;
loc_820AF8A8:
	// sth r28,0(r10)
	REX_STORE_U16(ctx.r10.u32 + 0, ctx.r28.u16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x820af8a8
	if (!ctx.cr0.eq) goto loc_820AF8A8;
	// addi r10,r31,2676
	ctx.r10.s64 = ctx.r31.s64 + 2676;
	// li r11,19
	ctx.r11.s64 = 19;
loc_820AF8C0:
	// sth r28,0(r10)
	REX_STORE_U16(ctx.r10.u32 + 0, ctx.r28.u16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x820af8c0
	if (!ctx.cr0.eq) goto loc_820AF8C0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r28,5796(r31)
	REX_STORE_U32(ctx.r31.u32 + 5796, ctx.r28.u32);
	// stw r28,5792(r31)
	REX_STORE_U32(ctx.r31.u32 + 5792, ctx.r28.u32);
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// sth r11,1164(r31)
	REX_STORE_U16(ctx.r31.u32 + 1164, ctx.r11.u16);
	// stw r28,5800(r31)
	REX_STORE_U32(ctx.r31.u32 + 5800, ctx.r28.u32);
	// stw r28,5784(r31)
	REX_STORE_U32(ctx.r31.u32 + 5784, ctx.r28.u32);
	// beq cr6,0x820af8f8
	if (ctx.cr6.eq) goto loc_820AF8F8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820afd58
	ctx.lr = 0x820AF8F8;
	sub_820AFD58(ctx, base);
loc_820AF8F8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
