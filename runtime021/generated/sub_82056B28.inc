DEFINE_REX_FUNC(sub_82056B28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82056B30;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r6,1
	ctx.r6.s64 = 1;
	// lhz r5,52(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// bl 0x82053c70
	ctx.lr = 0x82056B5C;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82056cac
	if (ctx.cr6.eq) goto loc_82056CAC;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// lhz r29,10(r11)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// lwz r3,-6628(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// sth r29,30(r31)
	REX_STORE_U16(ctx.r31.u32 + 30, ctx.r29.u16);
	// bl 0x820a3900
	ctx.lr = 0x82056B80;
	sub_820A3900(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r4,-6628(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x82056bc0
	if (ctx.cr6.eq) goto loc_82056BC0;
	// bl 0x820a37b8
	ctx.lr = 0x82056B94;
	sub_820A37B8(ctx, base);
	// li r11,7
	ctx.r11.s64 = 7;
	// li r5,15
	ctx.r5.s64 = 15;
	// sth r11,44(r31)
	REX_STORE_U16(ctx.r31.u32 + 44, ctx.r11.u16);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82054d38
	ctx.lr = 0x82056BAC;
	sub_82054D38(ctx, base);
	// lwz r11,-6628(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r11)
	REX_STORE_U32(ctx.r11.u32 + 140, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82056BC0:
	// addi r30,r31,12
	ctx.r30.s64 = ctx.r31.s64 + 12;
	// extsh r5,r29
	ctx.r5.s64 = ctx.r29.s16;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// bl 0x820a2c90
	ctx.lr = 0x82056BD0;
	sub_820A2C90(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82056c9c
	if (!ctx.cr6.eq) goto loc_82056C9C;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,105
	ctx.r6.s64 = 105;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-6596(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// bl 0x820a1138
	ctx.lr = 0x82056BFC;
	sub_820A1138(ctx, base);
	// li r4,39
	ctx.r4.s64 = 39;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x82056C08;
	sub_82053BC8(ctx, base);
	// lhz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82056c38
	if (ctx.cr6.lt) goto loc_82056C38;
	// beq cr6,0x82056c30
	if (ctx.cr6.eq) goto loc_82056C30;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x82056c28
	if (ctx.cr6.eq) goto loc_82056C28;
	// li r4,582
	ctx.r4.s64 = 582;
	// b 0x82056c3c
	goto loc_82056C3C;
loc_82056C28:
	// li r4,390
	ctx.r4.s64 = 390;
	// b 0x82056c3c
	goto loc_82056C3C;
loc_82056C30:
	// li r4,389
	ctx.r4.s64 = 389;
	// b 0x82056c3c
	goto loc_82056C3C;
loc_82056C38:
	// li r4,382
	ctx.r4.s64 = 382;
loc_82056C3C:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x82056C4C;
	sub_82067230(ctx, base);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r11,300(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 300);
	// lwz r9,56(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82056c78
	if (ctx.cr6.eq) goto loc_82056C78;
	// rotlwi r3,r9,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,236(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 236);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82056C78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82056C78:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82056C94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82056C9C:
	// li r5,15
	ctx.r5.s64 = 15;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82054d38
	ctx.lr = 0x82056CAC;
	sub_82054D38(ctx, base);
loc_82056CAC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
