DEFINE_REX_FUNC(sub_8211FD38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8211FD40;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r29,r11,30236
	ctx.r29.s64 = ctx.r11.s64 + 30236;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// addi r3,r29,8
	ctx.r3.s64 = ctx.r29.s64 + 8;
	// bl 0x8214a434
	ctx.lr = 0x8211FD5C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// cmpwi cr6,r30,4096
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4096, ctx.xer);
	// bgt cr6,0x8211ffec
	if (ctx.cr6.gt) goto loc_8211FFEC;
	// beq cr6,0x8211ffd8
	if (ctx.cr6.eq) goto loc_8211FFD8;
	// addi r11,r30,-1
	ctx.r11.s64 = ctx.r30.s64 + -1;
	// cmplwi cr6,r11,27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 27, ctx.xer);
	// bgt cr6,0x8212001c
	if (ctx.cr6.gt) goto loc_8212001C;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-20336
	ctx.r12.s64 = ctx.r12.s64 + -20336;
	// lbzx r0,r12,r11
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r11.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32238
	ctx.r12.s64 = -2112749568;
	// addi r12,r12,-612
	ctx.r12.s64 = ctx.r12.s64 + -612;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8211FD9C;
	case 1:
		goto loc_8211FDC4;
	case 2:
		goto loc_8211FDE8;
	case 3:
		goto loc_8211FDFC;
	case 4:
		goto loc_8211FE0C;
	case 5:
		goto loc_8211FE20;
	case 6:
		goto loc_8211FE34;
	case 7:
		goto loc_8211FE48;
	case 8:
		goto loc_8211FE5C;
	case 9:
		goto loc_8211FE70;
	case 10:
		goto loc_8211FE84;
	case 11:
		goto loc_8211FE98;
	case 12:
		goto loc_8211FEAC;
	case 13:
		goto loc_8211FEC0;
	case 14:
		goto loc_8211FED4;
	case 15:
		goto loc_8211FEE8;
	case 16:
		goto loc_8211FEFC;
	case 17:
		goto loc_8211FF10;
	case 18:
		goto loc_8211FF24;
	case 19:
		goto loc_8211FF38;
	case 20:
		goto loc_8211FF4C;
	case 21:
		goto loc_8211FF60;
	case 22:
		goto loc_8211FF74;
	case 23:
		goto loc_8211FF88;
	case 24:
		goto loc_8211FF9C;
	case 25:
		goto loc_8212001C;
	case 26:
		goto loc_8211FFB0;
	case 27:
		goto loc_8211FFC4;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8211FD9C:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r9,76(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// stw r10,68(r11)
	REX_STORE_U32(ctx.r11.u32 + 68, ctx.r10.u32);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x821200a0
	if (!ctx.cr6.lt) goto loc_821200A0;
loc_8211FDBC:
	// stw r10,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r10.u32);
	// b 0x821200a0
	goto loc_821200A0;
loc_8211FDC4:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r9,76(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// stw r10,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x821200a0
	if (!ctx.cr6.gt) goto loc_821200A0;
	// b 0x8211fdbc
	goto loc_8211FDBC;
loc_8211FDE8:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,76(r10)
	REX_STORE_U32(ctx.r10.u32 + 76, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FDFC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// stw r11,30112(r10)
	REX_STORE_U32(ctx.r10.u32 + 30112, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FE0C:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,80(r10)
	REX_STORE_U32(ctx.r10.u32 + 80, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FE20:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,84(r10)
	REX_STORE_U32(ctx.r10.u32 + 84, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FE34:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,96(r10)
	REX_STORE_U32(ctx.r10.u32 + 96, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FE48:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,100(r10)
	REX_STORE_U32(ctx.r10.u32 + 100, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FE5C:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FE70:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r9,r11,30112
	ctx.r9.s64 = ctx.r11.s64 + 30112;
	// sth r10,108(r9)
	REX_STORE_U16(ctx.r9.u32 + 108, ctx.r10.u16);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FE84:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r9,r11,30112
	ctx.r9.s64 = ctx.r11.s64 + 30112;
	// sth r10,110(r9)
	REX_STORE_U16(ctx.r9.u32 + 110, ctx.r10.u16);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FE98:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r9,r11,30112
	ctx.r9.s64 = ctx.r11.s64 + 30112;
	// sth r10,112(r9)
	REX_STORE_U16(ctx.r9.u32 + 112, ctx.r10.u16);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FEAC:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r9,r11,30112
	ctx.r9.s64 = ctx.r11.s64 + 30112;
	// sth r10,114(r9)
	REX_STORE_U16(ctx.r9.u32 + 114, ctx.r10.u16);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FEC0:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FED4:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,104(r10)
	REX_STORE_U32(ctx.r10.u32 + 104, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FEE8:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FEFC:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FF10:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FF24:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FF38:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,32(r10)
	REX_STORE_U32(ctx.r10.u32 + 32, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FF4C:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,116(r10)
	REX_STORE_U32(ctx.r10.u32 + 116, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FF60:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,20(r10)
	REX_STORE_U32(ctx.r10.u32 + 20, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FF74:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,36(r10)
	REX_STORE_U32(ctx.r10.u32 + 36, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FF88:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,40(r10)
	REX_STORE_U32(ctx.r10.u32 + 40, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FF9C:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,44(r10)
	REX_STORE_U32(ctx.r10.u32 + 44, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FFB0:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,52(r10)
	REX_STORE_U32(ctx.r10.u32 + 52, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FFC4:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,64(r10)
	REX_STORE_U32(ctx.r10.u32 + 64, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FFD8:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,88(r10)
	REX_STORE_U32(ctx.r10.u32 + 88, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8211FFEC:
	// cmpwi cr6,r30,4099
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4099, ctx.xer);
	// beq cr6,0x8212008c
	if (ctx.cr6.eq) goto loc_8212008C;
	// cmpwi cr6,r30,4100
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4100, ctx.xer);
	// beq cr6,0x82120078
	if (ctx.cr6.eq) goto loc_82120078;
	// cmpwi cr6,r30,4101
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4101, ctx.xer);
	// beq cr6,0x82120064
	if (ctx.cr6.eq) goto loc_82120064;
	// cmpwi cr6,r30,4102
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4102, ctx.xer);
	// beq cr6,0x82120050
	if (ctx.cr6.eq) goto loc_82120050;
	// cmpwi cr6,r30,4103
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4103, ctx.xer);
	// beq cr6,0x8212003c
	if (ctx.cr6.eq) goto loc_8212003C;
	// cmpwi cr6,r30,4104
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4104, ctx.xer);
	// beq cr6,0x82120028
	if (ctx.cr6.eq) goto loc_82120028;
loc_8212001C:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4105
	ctx.r31.u64 = ctx.r31.u64 | 4105;
	// b 0x821200a0
	goto loc_821200A0;
loc_82120028:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,120(r10)
	REX_STORE_U32(ctx.r10.u32 + 120, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_8212003C:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,92(r10)
	REX_STORE_U32(ctx.r10.u32 + 92, ctx.r11.u32);
	// b 0x8212009c
	goto loc_8212009C;
loc_82120050:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r9,r11,30112
	ctx.r9.s64 = ctx.r11.s64 + 30112;
	// sth r10,60(r9)
	REX_STORE_U16(ctx.r9.u32 + 60, ctx.r10.u16);
	// b 0x8212009c
	goto loc_8212009C;
loc_82120064:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r9,r11,30112
	ctx.r9.s64 = ctx.r11.s64 + 30112;
	// sth r10,58(r9)
	REX_STORE_U16(ctx.r9.u32 + 58, ctx.r10.u16);
	// b 0x8212009c
	goto loc_8212009C;
loc_82120078:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r9,r11,30112
	ctx.r9.s64 = ctx.r11.s64 + 30112;
	// sth r10,56(r9)
	REX_STORE_U16(ctx.r9.u32 + 56, ctx.r10.u16);
	// b 0x8212009c
	goto loc_8212009C;
loc_8212008C:
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,30112
	ctx.r10.s64 = ctx.r10.s64 + 30112;
	// stw r11,48(r10)
	REX_STORE_U32(ctx.r10.u32 + 48, ctx.r11.u32);
loc_8212009C:
	// li r31,0
	ctx.r31.s64 = 0;
loc_821200A0:
	// addi r3,r29,8
	ctx.r3.s64 = ctx.r29.s64 + 8;
	// bl 0x8214a444
	ctx.lr = 0x821200A8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
