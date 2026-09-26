DEFINE_REX_FUNC(sub_820C5EE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820C5EF0;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// add r10,r31,r5
	ctx.r10.u64 = ctx.r31.u64 + ctx.r5.u64;
	// lwz r11,14900(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 14900);
	// lwz r9,10896(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 10896);
	// and r30,r10,r11
	ctx.r30.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// lwz r11,60(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 60);
	// bge cr6,0x820c5f2c
	if (!ctx.cr6.lt) goto loc_820C5F2C;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x820c5f88
	if (!ctx.cr6.lt) goto loc_820C5F88;
loc_820C5F20:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// ble cr6,0x820c5f34
	if (!ctx.cr6.gt) goto loc_820C5F34;
	// b 0x820c5f88
	goto loc_820C5F88;
loc_820C5F2C:
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x820c5f20
	if (!ctx.cr6.lt) goto loc_820C5F20;
loc_820C5F34:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820be8f8
	ctx.lr = 0x820C5F44;
	sub_820BE8F8(ctx, base);
loc_820C5F44:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820be9f0
	ctx.lr = 0x820C5F4C;
	sub_820BE9F0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820c5f80
	if (ctx.cr0.eq) goto loc_820C5F80;
	// lwz r11,10896(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 10896);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// bge cr6,0x820c5f70
	if (!ctx.cr6.lt) goto loc_820C5F70;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x820c5f80
	if (!ctx.cr6.lt) goto loc_820C5F80;
	// b 0x820c5f78
	goto loc_820C5F78;
loc_820C5F70:
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820c5f44
	if (ctx.cr6.lt) goto loc_820C5F44;
loc_820C5F78:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// ble cr6,0x820c5f44
	if (!ctx.cr6.gt) goto loc_820C5F44;
loc_820C5F80:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820be928
	ctx.lr = 0x820C5F88;
	sub_820BE928(ctx, base);
loc_820C5F88:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
