DEFINE_REX_FUNC(sub_82107A68) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82107A70;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82107aac
	if (ctx.cr6.eq) goto loc_82107AAC;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214a204
	ctx.lr = 0x82107A94;
	__imp__XNotifyGetNext(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82107aac
	if (ctx.cr0.eq) goto loc_82107AAC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82106120
	ctx.lr = 0x82107AAC;
	sub_82106120(ctx, base);
loc_82107AAC:
	// lwz r3,428(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// bge cr6,0x82107b04
	if (!ctx.cr6.lt) goto loc_82107B04;
	// bl 0x820b5a00
	ctx.lr = 0x82107ABC;
	sub_820B5A00(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x82107b04
	if (!ctx.cr6.eq) goto loc_82107B04;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82107ae0
	if (ctx.cr6.eq) goto loc_82107AE0;
	// ld r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 48);
	// ld r10,452(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 452);
	// cmpld cr6,r11,r10
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r10.u64, ctx.xer);
	// beq cr6,0x82107afc
	if (ctx.cr6.eq) goto loc_82107AFC;
loc_82107AE0:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r5,r31,432
	ctx.r5.s64 = ctx.r31.s64 + 432;
	// lwz r4,428(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 428);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82107AFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82107AFC:
	// li r11,254
	ctx.r11.s64 = 254;
	// stw r11,428(r31)
	REX_STORE_U32(ctx.r31.u32 + 428, ctx.r11.u32);
loc_82107B04:
	// lwz r30,196(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82107b58
	if (ctx.cr6.eq) goto loc_82107B58;
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// addi r3,r31,200
	ctx.r3.s64 = ctx.r31.s64 + 200;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x82107b58
	if (ctx.cr6.eq) goto loc_82107B58;
	// bl 0x82136e38
	ctx.lr = 0x82107B24;
	sub_82136E38(ctx, base);
	// rlwinm. r11,r3,0,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFF0000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82107b40
	if (!ctx.cr0.eq) goto loc_82107B40;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x82107b40
	if (!ctx.cr6.gt) goto loc_82107B40;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r4,r11,32775
	ctx.r4.u64 = ctx.r11.u64 | 2147942400;
	// b 0x82107b44
	goto loc_82107B44;
loc_82107B40:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_82107B44:
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
	// bctrl 
	ctx.lr = 0x82107B58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82107B58:
	// lwz r30,412(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// addi r29,r31,412
	ctx.r29.s64 = ctx.r31.s64 + 412;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82107b94
	if (ctx.cr6.eq) goto loc_82107B94;
	// cmplwi r30,0
	ctx.cr0.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq 0x82107b94
	if (ctx.cr0.eq) goto loc_82107B94;
loc_82107B70:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r3,r30,-12
	ctx.r3.s64 = ctx.r30.s64 + -12;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82107b88
	if (ctx.cr6.eq) goto loc_82107B88;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_82107B88:
	// bl 0x8210a030
	ctx.lr = 0x82107B8C;
	sub_8210A030(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82107b70
	if (!ctx.cr6.eq) goto loc_82107B70;
loc_82107B94:
	// lwz r3,420(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82107bac
	if (ctx.cr6.eq) goto loc_82107BAC;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm r4,r11,9,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 9) & 0x1;
	// bl 0x8210a890
	ctx.lr = 0x82107BAC;
	sub_8210A890(ctx, base);
loc_82107BAC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82100c60
	ctx.lr = 0x82107BB4;
	sub_82100C60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82107888
	ctx.lr = 0x82107BBC;
	sub_82107888(ctx, base);
	// lwz r3,408(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82107be4
	if (ctx.cr6.eq) goto loc_82107BE4;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8210c538
	ctx.lr = 0x82107BD4;
	sub_8210C538(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge 0x82107be4
	if (!ctx.cr0.lt) goto loc_82107BE4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82100fd8
	ctx.lr = 0x82107BE4;
	sub_82100FD8(ctx, base);
loc_82107BE4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82105878
	ctx.lr = 0x82107BEC;
	sub_82105878(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
