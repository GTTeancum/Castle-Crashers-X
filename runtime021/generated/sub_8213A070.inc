DEFINE_REX_FUNC(sub_8213A070) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8213A078;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8213a1d8
	if (ctx.cr6.eq) goto loc_8213A1D8;
	// lwz r11,1264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1264);
	// li r28,0
	ctx.r28.s64 = 0;
	// li r30,-1
	ctx.r30.s64 = -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8213a0d0
	if (ctx.cr6.eq) goto loc_8213A0D0;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8213a0d0
	if (ctx.cr6.eq) goto loc_8213A0D0;
	// lwz r3,1304(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1304);
	// bl 0x82136e60
	ctx.lr = 0x8213A0AC;
	sub_82136E60(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// lwz r3,1264(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1264);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stw r11,1300(r31)
	REX_STORE_U32(ctx.r31.u32 + 1300, ctx.r11.u32);
	// bl 0x820b6020
	ctx.lr = 0x8213A0C0;
	sub_820B6020(ctx, base);
	// stw r28,1300(r31)
	REX_STORE_U32(ctx.r31.u32 + 1300, ctx.r28.u32);
	// lwz r3,1264(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1264);
	// bl 0x820b6498
	ctx.lr = 0x8213A0CC;
	sub_820B6498(ctx, base);
	// stw r30,1264(r31)
	REX_STORE_U32(ctx.r31.u32 + 1264, ctx.r30.u32);
loc_8213A0D0:
	// lwz r3,1304(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1304);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8213a0ec
	if (ctx.cr6.eq) goto loc_8213A0EC;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8213a0ec
	if (ctx.cr6.eq) goto loc_8213A0EC;
	// bl 0x820b6498
	ctx.lr = 0x8213A0E8;
	sub_820B6498(ctx, base);
	// stw r30,1304(r31)
	REX_STORE_U32(ctx.r31.u32 + 1304, ctx.r30.u32);
loc_8213A0EC:
	// lwz r3,1312(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1312);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8213a108
	if (ctx.cr6.eq) goto loc_8213A108;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8213a108
	if (ctx.cr6.eq) goto loc_8213A108;
	// bl 0x820b6498
	ctx.lr = 0x8213A104;
	sub_820B6498(ctx, base);
	// stw r30,1312(r31)
	REX_STORE_U32(ctx.r31.u32 + 1312, ctx.r30.u32);
loc_8213A108:
	// lwz r3,60(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8213a118
	if (ctx.cr6.eq) goto loc_8213A118;
	// bl 0x820d8088
	ctx.lr = 0x8213A118;
	sub_820D8088(ctx, base);
loc_8213A118:
	// lwz r3,64(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8213a12c
	if (ctx.cr6.eq) goto loc_8213A12C;
	// bl 0x820d8088
	ctx.lr = 0x8213A128;
	sub_820D8088(ctx, base);
	// stw r28,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r28.u32);
loc_8213A12C:
	// lwz r3,56(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8213a140
	if (ctx.cr6.eq) goto loc_8213A140;
	// bl 0x820d8088
	ctx.lr = 0x8213A13C;
	sub_820D8088(ctx, base);
	// stw r28,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r28.u32);
loc_8213A140:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8213a174
	if (!ctx.cr6.gt) goto loc_8213A174;
	// addi r30,r31,1096
	ctx.r30.s64 = ctx.r31.s64 + 1096;
loc_8213A154:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8213c850
	ctx.lr = 0x8213A15C;
	sub_8213C850(ctx, base);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8213a154
	if (ctx.cr6.lt) goto loc_8213A154;
loc_8213A174:
	// addi r30,r31,1112
	ctx.r30.s64 = ctx.r31.s64 + 1112;
	// li r29,4
	ctx.r29.s64 = 4;
loc_8213A17C:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8213c850
	ctx.lr = 0x8213A184;
	sub_8213C850(ctx, base);
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// bne 0x8213a17c
	if (!ctx.cr0.eq) goto loc_8213A17C;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8213a1c8
	if (!ctx.cr6.gt) goto loc_8213A1C8;
	// addi r30,r31,1128
	ctx.r30.s64 = ctx.r31.s64 + 1128;
loc_8213A1A8:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8213dce0
	ctx.lr = 0x8213A1B0;
	sub_8213DCE0(ctx, base);
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8213a1a8
	if (ctx.cr6.lt) goto loc_8213A1A8;
loc_8213A1C8:
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r4,r4,32780
	ctx.r4.u64 = ctx.r4.u64 | 32780;
	// bl 0x82136708
	ctx.lr = 0x8213A1D8;
	sub_82136708(ctx, base);
loc_8213A1D8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
