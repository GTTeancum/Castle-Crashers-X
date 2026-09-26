DEFINE_REX_FUNC(sub_8211DC88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8211DC90;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,4096
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4096, ctx.xer);
	// bgt cr6,0x8211df20
	if (ctx.cr6.gt) goto loc_8211DF20;
	// beq cr6,0x8211df0c
	if (ctx.cr6.eq) goto loc_8211DF0C;
	// addi r11,r5,-1
	ctx.r11.s64 = ctx.r5.s64 + -1;
	// cmplwi cr6,r11,27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 27, ctx.xer);
	// bgt cr6,0x8211df48
	if (ctx.cr6.gt) goto loc_8211DF48;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-20392
	ctx.r12.s64 = ctx.r12.s64 + -20392;
	// lbzx r0,r12,r11
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r11.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32238
	ctx.r12.s64 = -2112749568;
	// addi r12,r12,-8996
	ctx.r12.s64 = ctx.r12.s64 + -8996;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8211DCDC;
	case 1:
		goto loc_8211DCF0;
	case 2:
		goto loc_8211DF48;
	case 3:
		goto loc_8211DD04;
	case 4:
		goto loc_8211DD68;
	case 5:
		goto loc_8211DD7C;
	case 6:
		goto loc_8211DF48;
	case 7:
		goto loc_8211DF48;
	case 8:
		goto loc_8211DD90;
	case 9:
		goto loc_8211DF48;
	case 10:
		goto loc_8211DF48;
	case 11:
		goto loc_8211DF48;
	case 12:
		goto loc_8211DF48;
	case 13:
		goto loc_8211DD9C;
	case 14:
		goto loc_8211DF48;
	case 15:
		goto loc_8211DF48;
	case 16:
		goto loc_8211DF48;
	case 17:
		goto loc_8211DDA8;
	case 18:
		goto loc_8211DE00;
	case 19:
		goto loc_8211DE58;
	case 20:
		goto loc_8211DF48;
	case 21:
		goto loc_8211DE64;
	case 22:
		goto loc_8211DE70;
	case 23:
		goto loc_8211DE7C;
	case 24:
		goto loc_8211DE88;
	case 25:
		goto loc_8211DE94;
	case 26:
		goto loc_8211DEF4;
	case 27:
		goto loc_8211DF00;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8211DCDC:
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// lwz r4,0(r6)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// bl 0x82124e50
	ctx.lr = 0x8211DCEC;
	sub_82124E50(ctx, base);
	// b 0x8211df90
	goto loc_8211DF90;
loc_8211DCF0:
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// lwz r4,0(r6)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// bl 0x82124e68
	ctx.lr = 0x8211DD00;
	sub_82124E68(ctx, base);
	// b 0x8211df90
	goto loc_8211DF90;
loc_8211DD04:
	// lwz r27,0(r6)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8211dd1c
	if (!ctx.cr6.eq) goto loc_8211DD1C;
	// stw r27,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r27.u32);
	// b 0x8211df90
	goto loc_8211DF90;
loc_8211DD1C:
	// addi r28,r31,472
	ctx.r28.s64 = ctx.r31.s64 + 472;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r31,532
	ctx.r5.s64 = ctx.r31.s64 + 532;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82121f40
	ctx.lr = 0x8211DD38;
	sub_82121F40(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8211dd60
	if (!ctx.cr0.eq) goto loc_8211DD60;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82121ef0
	ctx.lr = 0x8211DD4C;
	sub_82121EF0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8211dd60
	if (!ctx.cr0.eq) goto loc_8211DD60;
loc_8211DD54:
	// lis r30,-32646
	ctx.r30.s64 = -2139488256;
	// ori r30,r30,4111
	ctx.r30.u64 = ctx.r30.u64 | 4111;
	// b 0x8211df90
	goto loc_8211DF90;
loc_8211DD60:
	// stw r27,140(r3)
	REX_STORE_U32(ctx.r3.u32 + 140, ctx.r27.u32);
	// b 0x8211df90
	goto loc_8211DF90;
loc_8211DD68:
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// lwz r4,0(r6)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// bl 0x82124fe8
	ctx.lr = 0x8211DD78;
	sub_82124FE8(ctx, base);
	// b 0x8211df90
	goto loc_8211DF90;
loc_8211DD7C:
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// lwz r4,0(r6)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// bl 0x82125038
	ctx.lr = 0x8211DD8C;
	sub_82125038(ctx, base);
	// b 0x8211df90
	goto loc_8211DF90;
loc_8211DD90:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// b 0x8211df8c
	goto loc_8211DF8C;
loc_8211DD9C:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// b 0x8211df8c
	goto loc_8211DF8C;
loc_8211DDA8:
	// lwz r27,0(r6)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8211ddc0
	if (!ctx.cr6.eq) goto loc_8211DDC0;
	// stw r27,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r27.u32);
	// b 0x8211df90
	goto loc_8211DF90;
loc_8211DDC0:
	// addi r28,r31,472
	ctx.r28.s64 = ctx.r31.s64 + 472;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r31,532
	ctx.r5.s64 = ctx.r31.s64 + 532;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82121f40
	ctx.lr = 0x8211DDDC;
	sub_82121F40(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8211ddf8
	if (!ctx.cr0.eq) goto loc_8211DDF8;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82121ef0
	ctx.lr = 0x8211DDF0;
	sub_82121EF0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8211dd54
	if (ctx.cr0.eq) goto loc_8211DD54;
loc_8211DDF8:
	// stw r27,144(r3)
	REX_STORE_U32(ctx.r3.u32 + 144, ctx.r27.u32);
	// b 0x8211df90
	goto loc_8211DF90;
loc_8211DE00:
	// lwz r27,0(r6)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8211de18
	if (!ctx.cr6.eq) goto loc_8211DE18;
	// stw r27,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r27.u32);
	// b 0x8211df90
	goto loc_8211DF90;
loc_8211DE18:
	// addi r28,r31,472
	ctx.r28.s64 = ctx.r31.s64 + 472;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r31,532
	ctx.r5.s64 = ctx.r31.s64 + 532;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82121f40
	ctx.lr = 0x8211DE34;
	sub_82121F40(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8211de50
	if (!ctx.cr0.eq) goto loc_8211DE50;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82121ef0
	ctx.lr = 0x8211DE48;
	sub_82121EF0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8211dd54
	if (ctx.cr0.eq) goto loc_8211DD54;
loc_8211DE50:
	// stw r27,148(r3)
	REX_STORE_U32(ctx.r3.u32 + 148, ctx.r27.u32);
	// b 0x8211df90
	goto loc_8211DF90;
loc_8211DE58:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// b 0x8211df8c
	goto loc_8211DF8C;
loc_8211DE64:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// b 0x8211df8c
	goto loc_8211DF8C;
loc_8211DE70:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// b 0x8211df8c
	goto loc_8211DF8C;
loc_8211DE7C:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// b 0x8211df8c
	goto loc_8211DF8C;
loc_8211DE88:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// b 0x8211df8c
	goto loc_8211DF8C;
loc_8211DE94:
	// addi r29,r31,40
	ctx.r29.s64 = ctx.r31.s64 + 40;
	// lwz r28,0(r6)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214a434
	ctx.lr = 0x8211DEA8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// cntlzw r10,r28
	ctx.r10.u64 = ctx.r28.u32 == 0 ? 32 : __builtin_clz(ctx.r28.u32);
	// lwz r11,1148(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// rlwinm r9,r11,13,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 13) & 0x1;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x8211ded4
	if (ctx.cr6.eq) goto loc_8211DED4;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x8211dee0
	if (ctx.cr6.eq) goto loc_8211DEE0;
	// oris r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 524288;
	// stw r11,1148(r31)
	REX_STORE_U32(ctx.r31.u32 + 1148, ctx.r11.u32);
loc_8211DED4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214a444
	ctx.lr = 0x8211DEDC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x8211df90
	goto loc_8211DF90;
loc_8211DEE0:
	// rlwinm r11,r11,0,13,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFF7FFFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,1148(r31)
	REX_STORE_U32(ctx.r31.u32 + 1148, ctx.r11.u32);
	// bl 0x8211c7f8
	ctx.lr = 0x8211DEF0;
	sub_8211C7F8(ctx, base);
	// b 0x8211df90
	goto loc_8211DF90;
loc_8211DEF4:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// b 0x8211df8c
	goto loc_8211DF8C;
loc_8211DF00:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// b 0x8211df8c
	goto loc_8211DF8C;
loc_8211DF0C:
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// lwz r4,0(r6)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// bl 0x82124e80
	ctx.lr = 0x8211DF1C;
	sub_82124E80(ctx, base);
	// b 0x8211df90
	goto loc_8211DF90;
loc_8211DF20:
	// cmpwi cr6,r5,4099
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4099, ctx.xer);
	// beq cr6,0x8211df84
	if (ctx.cr6.eq) goto loc_8211DF84;
	// cmpwi cr6,r5,4100
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4100, ctx.xer);
	// beq cr6,0x8211df78
	if (ctx.cr6.eq) goto loc_8211DF78;
	// cmpwi cr6,r5,4101
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4101, ctx.xer);
	// beq cr6,0x8211df6c
	if (ctx.cr6.eq) goto loc_8211DF6C;
	// cmpwi cr6,r5,4102
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4102, ctx.xer);
	// beq cr6,0x8211df60
	if (ctx.cr6.eq) goto loc_8211DF60;
	// cmpwi cr6,r5,4103
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4103, ctx.xer);
	// beq cr6,0x8211df54
	if (ctx.cr6.eq) goto loc_8211DF54;
loc_8211DF48:
	// lis r30,-32646
	ctx.r30.s64 = -2139488256;
	// ori r30,r30,4105
	ctx.r30.u64 = ctx.r30.u64 | 4105;
	// b 0x8211df90
	goto loc_8211DF90;
loc_8211DF54:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,688(r31)
	REX_STORE_U32(ctx.r31.u32 + 688, ctx.r11.u32);
	// b 0x8211df8c
	goto loc_8211DF8C;
loc_8211DF60:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// sth r11,128(r31)
	REX_STORE_U16(ctx.r31.u32 + 128, ctx.r11.u16);
	// b 0x8211df8c
	goto loc_8211DF8C;
loc_8211DF6C:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// sth r11,126(r31)
	REX_STORE_U16(ctx.r31.u32 + 126, ctx.r11.u16);
	// b 0x8211df8c
	goto loc_8211DF8C;
loc_8211DF78:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// sth r11,124(r31)
	REX_STORE_U16(ctx.r31.u32 + 124, ctx.r11.u16);
	// b 0x8211df8c
	goto loc_8211DF8C;
loc_8211DF84:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
loc_8211DF8C:
	// li r30,0
	ctx.r30.s64 = 0;
loc_8211DF90:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
