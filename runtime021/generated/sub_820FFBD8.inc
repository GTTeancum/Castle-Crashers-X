DEFINE_REX_FUNC(sub_820FFBD8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820FFBE0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// lwz r11,20(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bge cr6,0x820ffc0c
	if (!ctx.cr6.lt) goto loc_820FFC0C;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,1609
	ctx.r29.u64 = ctx.r29.u64 | 1609;
	// b 0x820ffca4
	goto loc_820FFCA4;
loc_820FFC0C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820febb0
	ctx.lr = 0x820FFC14;
	sub_820FEBB0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x820ffc28
	if (!ctx.cr0.eq) goto loc_820FFC28;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,117
	ctx.r29.u64 = ctx.r29.u64 | 117;
	// b 0x820ffca4
	goto loc_820FFCA4;
loc_820FFC28:
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// ld r4,16(r8)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r8.u32 + 16);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8210bd90
	ctx.lr = 0x820FFC38;
	sub_8210BD90(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x820ffc4c
	if (!ctx.cr0.eq) goto loc_820FFC4C;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// b 0x820ffc70
	goto loc_820FFC70;
loc_820FFC4C:
	// lwz r11,524(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 524);
	// addi r30,r29,524
	ctx.r30.s64 = ctx.r29.s64 + 524;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820ffc84
	if (!ctx.cr6.eq) goto loc_820FFC84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,32(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// bl 0x8210bc60
	ctx.lr = 0x820FFC68;
	sub_8210BC60(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge 0x820ffc84
	if (!ctx.cr0.lt) goto loc_820FFC84;
loc_820FFC70:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820ffca4
	if (ctx.cr6.eq) goto loc_820FFCA4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210be88
	ctx.lr = 0x820FFC80;
	sub_8210BE88(ctx, base);
	// b 0x820ffca4
	goto loc_820FFCA4;
loc_820FFC84:
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
loc_820FFCA4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
