DEFINE_REX_FUNC(sub_821200B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x821200C0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r28,r11,30236
	ctx.r28.s64 = ctx.r11.s64 + 30236;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r3,r28,8
	ctx.r3.s64 = ctx.r28.s64 + 8;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// bl 0x8214a434
	ctx.lr = 0x821200E0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// cmpwi cr6,r31,4096
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 4096, ctx.xer);
	// bgt cr6,0x8212042c
	if (ctx.cr6.gt) goto loc_8212042C;
	// beq cr6,0x82120410
	if (ctx.cr6.eq) goto loc_82120410;
	// addi r11,r31,-1
	ctx.r11.s64 = ctx.r31.s64 + -1;
	// cmplwi cr6,r11,27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 27, ctx.xer);
	// bgt cr6,0x82120480
	if (ctx.cr6.gt) goto loc_82120480;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-20304
	ctx.r12.s64 = ctx.r12.s64 + -20304;
	// lbzx r0,r12,r11
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r11.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32238
	ctx.r12.s64 = -2112749568;
	// addi r12,r12,288
	ctx.r12.s64 = ctx.r12.s64 + 288;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82120120;
	case 1:
		goto loc_8212013C;
	case 2:
		goto loc_82120158;
	case 3:
		goto loc_82120174;
	case 4:
		goto loc_8212018C;
	case 5:
		goto loc_821201A8;
	case 6:
		goto loc_821201C4;
	case 7:
		goto loc_821201E0;
	case 8:
		goto loc_821201FC;
	case 9:
		goto loc_82120218;
	case 10:
		goto loc_82120234;
	case 11:
		goto loc_82120250;
	case 12:
		goto loc_8212026C;
	case 13:
		goto loc_82120288;
	case 14:
		goto loc_821202A4;
	case 15:
		goto loc_821202C0;
	case 16:
		goto loc_821202DC;
	case 17:
		goto loc_821202F8;
	case 18:
		goto loc_82120314;
	case 19:
		goto loc_82120330;
	case 20:
		goto loc_8212034C;
	case 21:
		goto loc_82120368;
	case 22:
		goto loc_82120384;
	case 23:
		goto loc_821203A0;
	case 24:
		goto loc_821203BC;
	case 25:
		goto loc_82120480;
	case 26:
		goto loc_821203D8;
	case 27:
		goto loc_821203F4;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82120120:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,68(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// b 0x82120514
	goto loc_82120514;
loc_8212013C:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// b 0x82120514
	goto loc_82120514;
loc_82120158:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// b 0x82120514
	goto loc_82120514;
loc_82120174:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r11,30112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 30112);
	// b 0x82120514
	goto loc_82120514;
loc_8212018C:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// b 0x82120514
	goto loc_82120514;
loc_821201A8:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// b 0x82120514
	goto loc_82120514;
loc_821201C4:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,96(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// b 0x82120514
	goto loc_82120514;
loc_821201E0:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// b 0x82120514
	goto loc_82120514;
loc_821201FC:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// b 0x82120514
	goto loc_82120514;
loc_82120218:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lhz r11,108(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 108);
	// b 0x82120514
	goto loc_82120514;
loc_82120234:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lhz r11,110(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 110);
	// b 0x82120514
	goto loc_82120514;
loc_82120250:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lhz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 112);
	// b 0x82120514
	goto loc_82120514;
loc_8212026C:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lhz r11,114(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 114);
	// b 0x82120514
	goto loc_82120514;
loc_82120288:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// b 0x82120514
	goto loc_82120514;
loc_821202A4:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// b 0x82120514
	goto loc_82120514;
loc_821202C0:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// b 0x82120514
	goto loc_82120514;
loc_821202DC:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// b 0x82120514
	goto loc_82120514;
loc_821202F8:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82120514
	goto loc_82120514;
loc_82120314:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82120514
	goto loc_82120514;
loc_82120330:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// b 0x82120514
	goto loc_82120514;
loc_8212034C:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// b 0x82120514
	goto loc_82120514;
loc_82120368:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// b 0x82120514
	goto loc_82120514;
loc_82120384:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// b 0x82120514
	goto loc_82120514;
loc_821203A0:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// b 0x82120514
	goto loc_82120514;
loc_821203BC:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// b 0x82120514
	goto loc_82120514;
loc_821203D8:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// b 0x82120514
	goto loc_82120514;
loc_821203F4:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// b 0x82120514
	goto loc_82120514;
loc_82120410:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// b 0x82120514
	goto loc_82120514;
loc_8212042C:
	// cmpwi cr6,r31,4099
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 4099, ctx.xer);
	// beq cr6,0x821204fc
	if (ctx.cr6.eq) goto loc_821204FC;
	// cmpwi cr6,r31,4100
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 4100, ctx.xer);
	// beq cr6,0x821204e0
	if (ctx.cr6.eq) goto loc_821204E0;
	// cmpwi cr6,r31,4101
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 4101, ctx.xer);
	// beq cr6,0x821204c4
	if (ctx.cr6.eq) goto loc_821204C4;
	// cmpwi cr6,r31,4102
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 4102, ctx.xer);
	// beq cr6,0x821204a8
	if (ctx.cr6.eq) goto loc_821204A8;
	// cmpwi cr6,r31,4103
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 4103, ctx.xer);
	// beq cr6,0x8212048c
	if (ctx.cr6.eq) goto loc_8212048C;
	// cmpwi cr6,r31,4104
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 4104, ctx.xer);
	// bne cr6,0x82120480
	if (!ctx.cr6.eq) goto loc_82120480;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120478
	if (ctx.cr6.lt) goto loc_82120478;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_82120478:
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_82120480:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4105
	ctx.r31.u64 = ctx.r31.u64 | 4105;
	// b 0x82120530
	goto loc_82120530;
loc_8212048C:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,92(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// b 0x82120514
	goto loc_82120514;
loc_821204A8:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lhz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 60);
	// b 0x82120514
	goto loc_82120514;
loc_821204C4:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lhz r11,58(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 58);
	// b 0x82120514
	goto loc_82120514;
loc_821204E0:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lhz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 56);
	// b 0x82120514
	goto loc_82120514;
loc_821204FC:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82120520
	if (ctx.cr6.lt) goto loc_82120520;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r11,r11,30112
	ctx.r11.s64 = ctx.r11.s64 + 30112;
	// lwz r11,48(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
loc_82120514:
	// li r31,0
	ctx.r31.s64 = 0;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x82120528
	goto loc_82120528;
loc_82120520:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4097
	ctx.r31.u64 = ctx.r31.u64 | 4097;
loc_82120528:
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_82120530:
	// addi r3,r28,8
	ctx.r3.s64 = ctx.r28.s64 + 8;
	// bl 0x8214a444
	ctx.lr = 0x82120538;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
