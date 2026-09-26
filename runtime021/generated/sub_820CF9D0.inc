DEFINE_REX_FUNC(sub_820CF9D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r10,16720(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16720);
	// rlwinm. r11,r10,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cfb60
	if (ctx.cr0.eq) goto loc_820CFB60;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1676(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1676);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfa14
	if (ctx.cr6.eq) goto loc_820CFA14;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// b 0x820cfa18
	goto loc_820CFA18;
loc_820CFA14:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_820CFA18:
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CFA24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,16724(r31)
	REX_STORE_U32(ctx.r31.u32 + 16724, ctx.r3.u32);
loc_820CFA28:
	// stw r30,16720(r31)
	REX_STORE_U32(ctx.r31.u32 + 16720, ctx.r30.u32);
loc_820CFA2C:
	// lwz r11,21584(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21584);
	// lwz r10,21580(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21580);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// mftb r11
	ctx.r11.u64 = REX_QUERY_TIMEBASE();
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// cmpdi cr6,r10,0
	ctx.cr6.compare<int64_t>(ctx.r10.s64, 0, ctx.xer);
	// beq cr6,0x820cfa60
	if (ctx.cr6.eq) goto loc_820CFA60;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// stw r11,21576(r31)
	REX_STORE_U32(ctx.r31.u32 + 21576, ctx.r11.u32);
loc_820CFA60:
	// ld r8,21600(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 21600);
	// ld r10,21608(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 21608);
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r7,84(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r11,21648(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21648);
	// stw r8,21616(r31)
	REX_STORE_U32(ctx.r31.u32 + 21616, ctx.r8.u32);
	// std r30,21600(r31)
	REX_STORE_U64(ctx.r31.u32 + 21600, ctx.r30.u64);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r9,21584(r31)
	REX_STORE_U32(ctx.r31.u32 + 21584, ctx.r9.u32);
	// stw r7,21580(r31)
	REX_STORE_U32(ctx.r31.u32 + 21580, ctx.r7.u32);
	// stw r10,21620(r31)
	REX_STORE_U32(ctx.r31.u32 + 21620, ctx.r10.u32);
	// std r30,21608(r31)
	REX_STORE_U64(ctx.r31.u32 + 21608, ctx.r30.u64);
	// bne cr6,0x820cfbcc
	if (!ctx.cr6.eq) goto loc_820CFBCC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ce088
	ctx.lr = 0x820CFA9C;
	sub_820CE088(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cfbc4
	if (ctx.cr0.eq) goto loc_820CFBC4;
	// li r5,240
	ctx.r5.s64 = 240;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82129fa0
	ctx.lr = 0x820CFAB4;
	sub_82129FA0(ctx, base);
	// li r11,19
	ctx.r11.s64 = 19;
	// li r9,8
	ctx.r9.s64 = 8;
	// lbz r10,10942(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 10942);
	// stw r11,312(r1)
	REX_STORE_U32(ctx.r1.u32 + 312, ctx.r11.u32);
	// li r8,13
	ctx.r8.s64 = 13;
	// stw r11,316(r1)
	REX_STORE_U32(ctx.r1.u32 + 316, ctx.r11.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r9.u32);
	// li r9,37
	ctx.r9.s64 = 37;
	// stw r8,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r8.u32);
	// li r8,6
	ctx.r8.s64 = 6;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// li r11,25
	ctx.r11.s64 = 25;
	// stw r9,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r9.u32);
	// li r9,26
	ctx.r9.s64 = 26;
	// stw r8,320(r1)
	REX_STORE_U32(ctx.r1.u32 + 320, ctx.r8.u32);
	// li r8,200
	ctx.r8.s64 = 200;
	// stw r11,324(r1)
	REX_STORE_U32(ctx.r1.u32 + 324, ctx.r11.u32);
	// li r11,30
	ctx.r11.s64 = 30;
	// stw r30,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r9,328(r1)
	REX_STORE_U32(ctx.r1.u32 + 328, ctx.r9.u32);
	// stw r8,212(r1)
	REX_STORE_U32(ctx.r1.u32 + 212, ctx.r8.u32);
	// stw r11,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r11.u32);
	// bne 0x820cfb24
	if (!ctx.cr0.eq) goto loc_820CFB24;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c91c0
	ctx.lr = 0x820CFB24;
	sub_820C91C0(ctx, base);
loc_820CFB24:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c9348
	ctx.lr = 0x820CFB34;
	sub_820C9348(ctx, base);
	// lwz r11,21644(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21644);
	// stw r30,21652(r31)
	REX_STORE_U32(ctx.r31.u32 + 21652, ctx.r30.u32);
	// stw r30,21656(r31)
	REX_STORE_U32(ctx.r31.u32 + 21656, ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820cfb54
	if (!ctx.cr6.eq) goto loc_820CFB54;
	// lwz r11,21636(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21636);
	// addi r11,r11,1920
	ctx.r11.s64 = ctx.r11.s64 + 1920;
	// stw r11,21644(r31)
	REX_STORE_U32(ctx.r31.u32 + 21644, ctx.r11.u32);
loc_820CFB54:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,21648(r31)
	REX_STORE_U32(ctx.r31.u32 + 21648, ctx.r11.u32);
	// b 0x820cfc24
	goto loc_820CFC24;
loc_820CFB60:
	// rlwinm. r11,r10,0,23,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cfa2c
	if (ctx.cr0.eq) goto loc_820CFA2C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1676(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1676);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfb84
	if (ctx.cr6.eq) goto loc_820CFB84;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// b 0x820cfb88
	goto loc_820CFB88;
loc_820CFB84:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_820CFB88:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r4,r10,20,4,11
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0xFF00000;
	// addi r3,r9,14456
	ctx.r3.s64 = ctx.r9.s64 + 14456;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CFBA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,16724(r31)
	REX_STORE_U32(ctx.r31.u32 + 16724, ctx.r3.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820cfa28
	if (ctx.cr0.lt) goto loc_820CFA28;
	// lwz r11,16720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16720);
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwimi r11,r10,10,23,23
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 10) & 0x100) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFEFF);
	// rlwimi r11,r10,10,21,21
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 10) & 0x400) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFBFF);
	// stw r11,16720(r31)
	REX_STORE_U32(ctx.r31.u32 + 16720, ctx.r11.u32);
	// b 0x820cfa2c
	goto loc_820CFA2C;
loc_820CFBC4:
	// stw r30,21648(r31)
	REX_STORE_U32(ctx.r31.u32 + 21648, ctx.r30.u32);
	// b 0x820cfc24
	goto loc_820CFC24;
loc_820CFBCC:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x820cfc24
	if (!ctx.cr6.eq) goto loc_820CFC24;
	// lbz r11,10942(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10942);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820cfbec
	if (!ctx.cr0.eq) goto loc_820CFBEC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c91c0
	ctx.lr = 0x820CFBEC;
	sub_820C91C0(ctx, base);
loc_820CFBEC:
	// lwz r11,21656(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21656);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x820cfbfc
	if (ctx.cr6.eq) goto loc_820CFBFC;
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
loc_820CFBFC:
	// lwz r11,21652(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21652);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820cfc24
	if (ctx.cr6.eq) goto loc_820CFC24;
	// lwz r10,21640(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21640);
	// rlwinm r11,r30,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 4) & 0xFFFFFFF0;
	// li r5,0
	ctx.r5.s64 = 0;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c9968
	ctx.lr = 0x820CFC20;
	sub_820C9968(ctx, base);
	// stw r30,21656(r31)
	REX_STORE_U32(ctx.r31.u32 + 21656, ctx.r30.u32);
loc_820CFC24:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cf858
	ctx.lr = 0x820CFC2C;
	sub_820CF858(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1488(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1488);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfc58
	if (ctx.cr6.eq) goto loc_820CFC58;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfc58
	if (ctx.cr6.eq) goto loc_820CFC58;
	// li r3,0
	ctx.r3.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CFC58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CFC58:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
