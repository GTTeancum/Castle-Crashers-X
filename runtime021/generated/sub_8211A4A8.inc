DEFINE_REX_FUNC(sub_8211A4A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8211A4B0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r28,r31,40
	ctx.r28.s64 = ctx.r31.s64 + 40;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a434
	ctx.lr = 0x8211A4CC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addis r11,r30,-8192
	ctx.r11.s64 = ctx.r30.s64 + -536870912;
	// cmplwi cr6,r11,9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 9, ctx.xer);
	// bgt cr6,0x8211a578
	if (ctx.cr6.gt) goto loc_8211A578;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-20440
	ctx.r12.s64 = ctx.r12.s64 + -20440;
	// lbzx r0,r12,r11
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r11.u32);
	// lis r12,-32238
	ctx.r12.s64 = -2112749568;
	// addi r12,r12,-23296
	ctx.r12.s64 = ctx.r12.s64 + -23296;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// nop 
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8211A500;
	case 1:
		goto loc_8211A510;
	case 2:
		goto loc_8211A518;
	case 3:
		goto loc_8211A528;
	case 4:
		goto loc_8211A540;
	case 5:
		goto loc_8211A548;
	case 6:
		goto loc_8211A550;
	case 7:
		goto loc_8211A558;
	case 8:
		goto loc_8211A560;
	case 9:
		goto loc_8211A568;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8211A500:
	// ld r11,784(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 784);
loc_8211A504:
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// b 0x8211a580
	goto loc_8211A580;
loc_8211A510:
	// lwz r11,672(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 672);
	// b 0x8211a504
	goto loc_8211A504;
loc_8211A518:
	// lwz r11,1156(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1156);
	// lwz r10,1152(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1152);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8211a504
	goto loc_8211A504;
loc_8211A528:
	// ld r11,1176(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 1176);
	// ld r10,1168(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 1168);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_8211A534:
	// li r30,0
	ctx.r30.s64 = 0;
	// std r11,0(r29)
	REX_STORE_U64(ctx.r29.u32 + 0, ctx.r11.u64);
	// b 0x8211a580
	goto loc_8211A580;
loc_8211A540:
	// lwz r11,1156(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1156);
	// b 0x8211a504
	goto loc_8211A504;
loc_8211A548:
	// ld r11,1176(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 1176);
	// b 0x8211a534
	goto loc_8211A534;
loc_8211A550:
	// lwz r11,1160(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1160);
	// b 0x8211a504
	goto loc_8211A504;
loc_8211A558:
	// ld r11,1184(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 1184);
	// b 0x8211a534
	goto loc_8211A534;
loc_8211A560:
	// lwz r11,1164(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1164);
	// b 0x8211a504
	goto loc_8211A504;
loc_8211A568:
	// lhz r11,1042(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1042);
	// lhz r10,1038(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 1038);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// b 0x8211a504
	goto loc_8211A504;
loc_8211A578:
	// lis r30,-32646
	ctx.r30.s64 = -2139488256;
	// ori r30,r30,4105
	ctx.r30.u64 = ctx.r30.u64 | 4105;
loc_8211A580:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a444
	ctx.lr = 0x8211A588;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
