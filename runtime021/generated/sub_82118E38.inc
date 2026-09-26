DEFINE_REX_FUNC(sub_82118E38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x82118E40;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,4096
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4096, ctx.xer);
	// bgt cr6,0x821190d8
	if (ctx.cr6.gt) goto loc_821190D8;
	// beq cr6,0x821190cc
	if (ctx.cr6.eq) goto loc_821190CC;
	// addi r11,r4,-1
	ctx.r11.s64 = ctx.r4.s64 + -1;
	// cmplwi cr6,r11,27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 27, ctx.xer);
	// bgt cr6,0x82119110
	if (ctx.cr6.gt) goto loc_82119110;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-20504
	ctx.r12.s64 = ctx.r12.s64 + -20504;
	// lbzx r0,r12,r11
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r11.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32238
	ctx.r12.s64 = -2112749568;
	// addi r12,r12,-29048
	ctx.r12.s64 = ctx.r12.s64 + -29048;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82118E88;
	case 1:
		goto loc_82118EA8;
	case 2:
		goto loc_82118EC4;
	case 3:
		goto loc_82118ED0;
	case 4:
		goto loc_82118EDC;
	case 5:
		goto loc_82118EE8;
	case 6:
		goto loc_82118EF4;
	case 7:
		goto loc_82118F00;
	case 8:
		goto loc_82118F0C;
	case 9:
		goto loc_82118F18;
	case 10:
		goto loc_82118F24;
	case 11:
		goto loc_82118F30;
	case 12:
		goto loc_82118F3C;
	case 13:
		goto loc_82118F48;
	case 14:
		goto loc_82118F54;
	case 15:
		goto loc_82118F60;
	case 16:
		goto loc_82118F6C;
	case 17:
		goto loc_82118F78;
	case 18:
		goto loc_82118F84;
	case 19:
		goto loc_82118F90;
	case 20:
		goto loc_82118F9C;
	case 21:
		goto loc_82119038;
	case 22:
		goto loc_82119044;
	case 23:
		goto loc_82119050;
	case 24:
		goto loc_8211905C;
	case 25:
		goto loc_82119068;
	case 26:
		goto loc_821190B4;
	case 27:
		goto loc_821190C0;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82118E88:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r10,116(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r11,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// bge cr6,0x82119170
	if (!ctx.cr6.lt) goto loc_82119170;
loc_82118EA0:
	// stw r11,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// b 0x82119170
	goto loc_82119170;
loc_82118EA8:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r10,116(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// ble cr6,0x82119170
	if (!ctx.cr6.gt) goto loc_82119170;
	// b 0x82118ea0
	goto loc_82118EA0;
loc_82118EC4:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118ED0:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118EDC:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118EE8:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118EF4:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118F00:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118F0C:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118F18:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// sth r11,148(r31)
	REX_STORE_U16(ctx.r31.u32 + 148, ctx.r11.u16);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118F24:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// sth r11,150(r31)
	REX_STORE_U16(ctx.r31.u32 + 150, ctx.r11.u16);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118F30:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// sth r11,152(r31)
	REX_STORE_U16(ctx.r31.u32 + 152, ctx.r11.u16);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118F3C:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// sth r11,154(r31)
	REX_STORE_U16(ctx.r31.u32 + 154, ctx.r11.u16);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118F48:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118F54:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118F60:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118F6C:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118F78:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118F84:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118F90:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82118F9C:
	// addi r28,r31,236
	ctx.r28.s64 = ctx.r31.s64 + 236;
	// lwz r29,0(r5)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a434
	ctx.lr = 0x82118FB0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r27,r31,164
	ctx.r27.s64 = ctx.r31.s64 + 164;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8214a434
	ctx.lr = 0x82118FBC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,276(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 276);
	// stw r29,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r29.u32);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// ble cr6,0x82119024
	if (!ctx.cr6.gt) goto loc_82119024;
	// addi r26,r31,280
	ctx.r26.s64 = ctx.r31.s64 + 280;
loc_82118FD0:
	// lwz r11,4(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x82118fe4
	if (!ctx.cr6.eq) goto loc_82118FE4;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82119004
	goto loc_82119004;
loc_82118FE4:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
loc_82119004:
	// addi r3,r11,-8
	ctx.r3.s64 = ctx.r11.s64 + -8;
	// bl 0x821180d8
	ctx.lr = 0x8211900C;
	sub_821180D8(ctx, base);
	// lwz r11,276(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 276);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,276(r31)
	REX_STORE_U32(ctx.r31.u32 + 276, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bgt cr6,0x82118fd0
	if (ctx.cr6.gt) goto loc_82118FD0;
loc_82119024:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8214a444
	ctx.lr = 0x8211902C;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8211902C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a444
	ctx.lr = 0x82119034;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x82119170
	goto loc_82119170;
loc_82119038:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82119044:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82119050:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_8211905C:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82119068:
	// addi r28,r31,164
	ctx.r28.s64 = ctx.r31.s64 + 164;
	// lwz r29,0(r5)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a434
	ctx.lr = 0x8211907C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// cntlzw r10,r29
	ctx.r10.u64 = ctx.r29.u32 == 0 ? 32 : __builtin_clz(ctx.r29.u32);
	// lwz r11,440(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 440);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// rlwinm r9,r11,5,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0x1;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x8211902c
	if (ctx.cr6.eq) goto loc_8211902C;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x821190a8
	if (ctx.cr6.eq) goto loc_821190A8;
	// oris r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 134217728;
	// b 0x821190ac
	goto loc_821190AC;
loc_821190A8:
	// rlwinm r11,r11,0,5,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFF7FFFFFF;
loc_821190AC:
	// stw r11,440(r31)
	REX_STORE_U32(ctx.r31.u32 + 440, ctx.r11.u32);
	// b 0x8211902c
	goto loc_8211902C;
loc_821190B4:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_821190C0:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_821190CC:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_821190D8:
	// cmpwi cr6,r4,4097
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4097, ctx.xer);
	// beq cr6,0x82119164
	if (ctx.cr6.eq) goto loc_82119164;
	// cmpwi cr6,r4,4099
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4099, ctx.xer);
	// beq cr6,0x82119158
	if (ctx.cr6.eq) goto loc_82119158;
	// cmpwi cr6,r4,4100
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4100, ctx.xer);
	// beq cr6,0x8211914c
	if (ctx.cr6.eq) goto loc_8211914C;
	// cmpwi cr6,r4,4101
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4101, ctx.xer);
	// beq cr6,0x82119140
	if (ctx.cr6.eq) goto loc_82119140;
	// cmpwi cr6,r4,4102
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4102, ctx.xer);
	// beq cr6,0x82119134
	if (ctx.cr6.eq) goto loc_82119134;
	// cmpwi cr6,r4,4103
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4103, ctx.xer);
	// beq cr6,0x82119128
	if (ctx.cr6.eq) goto loc_82119128;
	// cmpwi cr6,r4,4104
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4104, ctx.xer);
	// beq cr6,0x8211911c
	if (ctx.cr6.eq) goto loc_8211911C;
loc_82119110:
	// lis r30,-32646
	ctx.r30.s64 = -2139488256;
	// ori r30,r30,4105
	ctx.r30.u64 = ctx.r30.u64 | 4105;
	// b 0x82119170
	goto loc_82119170;
loc_8211911C:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82119128:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82119134:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// sth r11,100(r31)
	REX_STORE_U16(ctx.r31.u32 + 100, ctx.r11.u16);
	// b 0x8211916c
	goto loc_8211916C;
loc_82119140:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// sth r11,98(r31)
	REX_STORE_U16(ctx.r31.u32 + 98, ctx.r11.u16);
	// b 0x8211916c
	goto loc_8211916C;
loc_8211914C:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// sth r11,96(r31)
	REX_STORE_U16(ctx.r31.u32 + 96, ctx.r11.u16);
	// b 0x8211916c
	goto loc_8211916C;
loc_82119158:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// b 0x8211916c
	goto loc_8211916C;
loc_82119164:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r11.u32);
loc_8211916C:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82119170:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
