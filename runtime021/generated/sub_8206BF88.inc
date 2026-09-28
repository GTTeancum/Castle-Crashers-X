DEFINE_REX_FUNC(sub_8206BF88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8206BF90;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r11,48(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// lhz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 16);
	// rlwinm r9,r10,28,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x1;
	// rlwinm r8,r10,30,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// rlwinm r7,r10,29,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	// clrlwi r6,r10,31
	ctx.r6.u64 = ctx.r10.u32 & 0x1;
	// rlwinm r5,r10,31,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	// bl 0x82053ef0
	ctx.lr = 0x8206BFC4;
	sub_82053EF0(ctx, base);
	// lwz r3,48(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8206BFDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r29,-32218
	ctx.r29.s64 = -2111438848;
	// lwz r11,-6628(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -6628);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206bff8
	if (ctx.cr6.eq) goto loc_8206BFF8;
	// lhz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// b 0x8206bffc
	goto loc_8206BFFC;
loc_8206BFF8:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8206BFFC:
	// lhz r10,52(r28)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r28.u32 + 52);
	// lis r27,-32218
	ctx.r27.s64 = -2111438848;
	// cmplwi cr6,r10,17
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 17, ctx.xer);
	// bne cr6,0x8206c014
	if (!ctx.cr6.eq) goto loc_8206C014;
	// li r4,3
	ctx.r4.s64 = 3;
	// b 0x8206c048
	goto loc_8206C048;
loc_8206C014:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206c044
	if (!ctx.cr6.eq) goto loc_8206C044;
	// li r10,222
	ctx.r10.s64 = 222;
	// lwz r11,-6624(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -6624);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r10,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x8206C034;
	sub_82052EA8(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x8206c048
	if (!ctx.cr6.eq) goto loc_8206C048;
loc_8206C044:
	// li r4,1
	ctx.r4.s64 = 1;
loc_8206C048:
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// lwz r3,76(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,164(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 164);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8206C060;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,-6628(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -6628);
	// lbz r11,29(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 29);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206c11c
	if (!ctx.cr6.eq) goto loc_8206C11C;
	// lhz r11,52(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 52);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8206c11c
	if (ctx.cr6.eq) goto loc_8206C11C;
	// lbz r11,180(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 180);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c11c
	if (ctx.cr6.eq) goto loc_8206C11C;
	// lwz r30,184(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 184);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x820a39f0
	ctx.lr = 0x8206C094;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206c0d0
	if (!ctx.cr6.eq) goto loc_8206C0D0;
	// li r31,0
	ctx.r31.s64 = 0;
loc_8206C0A4:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,-6628(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -6628);
	// bl 0x820a39f0
	ctx.lr = 0x8206C0B0;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c0c4
	if (ctx.cr6.eq) goto loc_8206C0C4;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// li r31,4
	ctx.r31.s64 = 4;
loc_8206C0C4:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r31,4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 4, ctx.xer);
	// blt cr6,0x8206c0a4
	if (ctx.cr6.lt) goto loc_8206C0A4;
loc_8206C0D0:
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,-6624(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -6624);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82077310
	ctx.lr = 0x8206C0E4;
	sub_82077310(ctx, base);
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r8,r11,-11336
	ctx.r8.s64 = ctx.r11.s64 + -11336;
	// addi r7,r10,-11464
	ctx.r7.s64 = ctx.r10.s64 + -11464;
	// li r6,15
	ctx.r6.s64 = 15;
	// li r5,539
	ctx.r5.s64 = 539;
	// li r4,538
	ctx.r4.s64 = 538;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82054c38
	ctx.lr = 0x8206C108;
	sub_82054C38(ctx, base);
	// lwz r11,56(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 56);
	// clrlwi r9,r30,16
	ctx.r9.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r3,-6628(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -6628);
	// sth r9,1320(r11)
	REX_STORE_U16(ctx.r11.u32 + 1320, ctx.r9.u16);
	// sth r9,1318(r11)
	REX_STORE_U16(ctx.r11.u32 + 1318, ctx.r9.u16);
loc_8206C11C:
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8206c144
	if (ctx.cr6.eq) goto loc_8206C144;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c144
	if (ctx.cr6.eq) goto loc_8206C144;
	// lbz r11,1185(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x8206c148
	if (!ctx.cr6.eq) goto loc_8206C148;
loc_8206C144:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8206C148:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c1c0
	if (ctx.cr6.eq) goto loc_8206C1C0;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c184
	if (ctx.cr6.eq) goto loc_8206C184;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206C174;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r3,-6628(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -6628);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x8206c188
	if (!ctx.cr6.eq) goto loc_8206C188;
loc_8206C184:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8206C188:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c1c0
	if (ctx.cr6.eq) goto loc_8206C1C0;
	// bl 0x820a3eb8
	ctx.lr = 0x8206C198;
	sub_820A3EB8(ctx, base);
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lwz r11,-22660(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -22660);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x8206c1c0
	if (ctx.cr6.eq) goto loc_8206C1C0;
	// lhz r11,52(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 52);
	// cmplwi cr6,r11,18
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 18, ctx.xer);
	// bne cr6,0x8206c1c0
	if (!ctx.cr6.eq) goto loc_8206C1C0;
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82053bc8
	ctx.lr = 0x8206C1C0;
	sub_82053BC8(ctx, base);
loc_8206C1C0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
