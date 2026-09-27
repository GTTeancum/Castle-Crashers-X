DEFINE_REX_FUNC(sub_82094858) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82094860;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// lhz r11,98(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 98);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82094888
	if (ctx.cr6.eq) goto loc_82094888;
loc_8209487C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82094888:
	// lwz r3,140(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820948a0
	if (ctx.cr6.eq) goto loc_820948A0;
	// bl 0x820a7400
	ctx.lr = 0x8209489C;
	sub_820A7400(ctx, base);
	// stw r28,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r28.u32);
loc_820948A0:
	// lwz r3,144(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 144);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820948b4
	if (ctx.cr6.eq) goto loc_820948B4;
	// bl 0x820a7400
	ctx.lr = 0x820948B0;
	sub_820A7400(ctx, base);
	// stw r28,144(r30)
	REX_STORE_U32(ctx.r30.u32 + 144, ctx.r28.u32);
loc_820948B4:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8209487c
	if (ctx.cr6.eq) goto loc_8209487C;
	// lhz r11,98(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 98);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209493c
	if (ctx.cr6.eq) goto loc_8209493C;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-6640(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6640);
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// lwzx r6,r9,r8
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r6,r5
	ctx.r31.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82127e20
	ctx.lr = 0x820948F4;
	sub_82127E20(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// sth r11,100(r30)
	REX_STORE_U16(ctx.r30.u32 + 100, ctx.r11.u16);
	// beq cr6,0x82094a8c
	if (ctx.cr6.eq) goto loc_82094A8C;
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// rlwinm r3,r11,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x82094920
	if (!ctx.cr6.gt) goto loc_82094920;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82094920:
	// bl 0x820a7390
	ctx.lr = 0x82094924;
	sub_820A7390(ctx, base);
	// stw r3,144(r30)
	REX_STORE_U32(ctx.r30.u32 + 144, ctx.r3.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82127bc8
	ctx.lr = 0x82094930;
	sub_82127BC8(ctx, base);
	// lhz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r30.u32 + 100);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8209493C:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82094940:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82094940
	if (!ctx.cr6.eq) goto loc_82094940;
	// subf r11,r29,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r29.u64;
	// clrlwi r10,r31,24
	ctx.r10.u64 = ctx.r31.u32 & 0xFF;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// clrlwi r11,r8,16
	ctx.r11.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// sth r11,100(r30)
	REX_STORE_U16(ctx.r30.u32 + 100, ctx.r11.u16);
	// beq cr6,0x82094a54
	if (ctx.cr6.eq) goto loc_82094A54;
	// clrlwi r8,r11,16
	ctx.r8.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82094a8c
	if (ctx.cr6.eq) goto loc_82094A8C;
	// lhz r8,100(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 100);
loc_82094988:
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// lbzx r7,r11,r29
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r29.u32);
	// beq cr6,0x820949a8
	if (ctx.cr6.eq) goto loc_820949A8;
	// cmplwi cr6,r7,62
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 62, ctx.xer);
	// bne cr6,0x820949bc
	if (!ctx.cr6.eq) goto loc_820949BC;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// b 0x820949bc
	goto loc_820949BC;
loc_820949A8:
	// cmplwi cr6,r7,60
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 60, ctx.xer);
	// bne cr6,0x820949b8
	if (!ctx.cr6.eq) goto loc_820949B8;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x820949bc
	goto loc_820949BC;
loc_820949B8:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_820949BC:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82094988
	if (ctx.cr6.lt) goto loc_82094988;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82094a8c
	if (ctx.cr6.eq) goto loc_82094A8C;
	// addi r3,r9,1
	ctx.r3.s64 = ctx.r9.s64 + 1;
	// bl 0x820a7390
	ctx.lr = 0x820949D8;
	sub_820A7390(ctx, base);
	// lhz r11,100(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 100);
	// stw r3,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r3.u32);
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82094a40
	if (ctx.cr6.eq) goto loc_82094A40;
loc_820949F4:
	// clrlwi r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lbzx r11,r10,r29
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r29.u32);
	// beq cr6,0x82094a14
	if (ctx.cr6.eq) goto loc_82094A14;
	// cmplwi cr6,r11,62
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 62, ctx.xer);
	// bne cr6,0x82094a30
	if (!ctx.cr6.eq) goto loc_82094A30;
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// b 0x82094a30
	goto loc_82094A30;
loc_82094A14:
	// cmplwi cr6,r11,60
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 60, ctx.xer);
	// bne cr6,0x82094a24
	if (!ctx.cr6.eq) goto loc_82094A24;
	// li r8,1
	ctx.r8.s64 = 1;
	// b 0x82094a30
	goto loc_82094A30;
loc_82094A24:
	// lwz r7,140(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// stbx r11,r7,r9
	REX_STORE_U8(ctx.r7.u32 + ctx.r9.u32, ctx.r11.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_82094A30:
	// lhz r11,100(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 100);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820949f4
	if (ctx.cr6.lt) goto loc_820949F4;
loc_82094A40:
	// lwz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// stbx r28,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r28.u8);
	// lhz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r30.u32 + 100);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82094A54:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82094a8c
	if (ctx.cr6.eq) goto loc_82094A8C;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x820a7390
	ctx.lr = 0x82094A68;
	sub_820A7390(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// stw r10,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r10.u32);
loc_82094A74:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne cr6,0x82094a74
	if (!ctx.cr6.eq) goto loc_82094A74;
loc_82094A8C:
	// lhz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r30.u32 + 100);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
