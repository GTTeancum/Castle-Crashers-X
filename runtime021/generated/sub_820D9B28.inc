DEFINE_REX_FUNC(sub_820D9B28) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820D9B30;
	__savegprlr_28(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// bl 0x82053a98
	ctx.lr = 0x820D9B44;
	sub_82053A98(ctx, base);
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r30,r11,6728
	ctx.r30.s64 = ctx.r11.s64 + 6728;
	// addi r3,r30,4
	ctx.r3.s64 = ctx.r30.s64 + 4;
	// bl 0x8214a434
	ctx.lr = 0x820D9B54;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,256(r13)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r13.u32 + 256);
	// lwz r10,304(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r11.u32);
	// beq cr6,0x820d9bdc
	if (ctx.cr6.eq) goto loc_820D9BDC;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,22944
	ctx.r3.s64 = ctx.r11.s64 + 22944;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8214a9a4
	ctx.lr = 0x820D9B7C;
	__imp__KeSetEvent(ctx, base);
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// stw r28,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// addi r8,r10,22928
	ctx.r8.s64 = ctx.r10.s64 + 22928;
	// addi r7,r9,22892
	ctx.r7.s64 = ctx.r9.s64 + 22892;
	// li r5,44
	ctx.r5.s64 = 44;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x82129fa0
	ctx.lr = 0x820D9BA8;
	sub_82129FA0(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,3
	ctx.r6.s64 = 3;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8214ac14
	ctx.lr = 0x820D9BCC;
	__imp__KeWaitForMultipleObjects(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x820d9bf0
	if (!ctx.cr6.eq) goto loc_820D9BF0;
	// li r29,1
	ctx.r29.s64 = 1;
	// b 0x820d9bf0
	goto loc_820D9BF0;
loc_820D9BDC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d9248
	ctx.lr = 0x820D9BE4;
	sub_820D9248(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d9330
	ctx.lr = 0x820D9BF0;
	sub_820D9330(ctx, base);
loc_820D9BF0:
	// clrlwi r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d9c24
	if (!ctx.cr6.eq) goto loc_820D9C24;
	// lwz r3,64(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D9C10;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820d9c24
	if (ctx.cr6.lt) goto loc_820D9C24;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820dcdc0
	ctx.lr = 0x820D9C24;
	sub_820DCDC0(ctx, base);
loc_820D9C24:
	// stw r28,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r28.u32);
	// bl 0x820dcdf8
	ctx.lr = 0x820D9C2C;
	sub_820DCDF8(ctx, base);
	// addi r3,r30,4
	ctx.r3.s64 = ctx.r30.s64 + 4;
	// bl 0x8214a444
	ctx.lr = 0x820D9C34;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
