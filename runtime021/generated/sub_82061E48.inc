DEFINE_REX_FUNC(sub_82061E48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82061E50;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
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
	ctx.lr = 0x82061E84;
	sub_82053EF0(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
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
	ctx.lr = 0x82061E9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,-6628(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// lwz r10,140(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82061ed0
	if (ctx.cr6.eq) goto loc_82061ED0;
	// sth r10,44(r31)
	REX_STORE_U16(ctx.r31.u32 + 44, ctx.r10.u16);
	// li r5,15
	ctx.r5.s64 = 15;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82054d38
	ctx.lr = 0x82061EC8;
	sub_82054D38(ctx, base);
	// lwz r11,-6628(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// stw r29,140(r11)
	REX_STORE_U32(ctx.r11.u32 + 140, ctx.r29.u32);
loc_82061ED0:
	// lbz r10,29(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 29);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82061fb8
	if (!ctx.cr6.eq) goto loc_82061FB8;
	// lbz r10,180(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 180);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82061fb8
	if (ctx.cr6.eq) goto loc_82061FB8;
	// lhz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// beq cr6,0x82061fb8
	if (ctx.cr6.eq) goto loc_82061FB8;
	// lwz r11,184(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,15
	ctx.r5.s64 = 15;
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053c70
	ctx.lr = 0x82061F1C;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82061f8c
	if (ctx.cr6.eq) goto loc_82061F8C;
	// lwz r3,-6628(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// bl 0x820a3900
	ctx.lr = 0x82061F30;
	sub_820A3900(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82061f64
	if (ctx.cr6.eq) goto loc_82061F64;
	// lbz r11,33(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 33);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82061fb8
	if (!ctx.cr6.eq) goto loc_82061FB8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6628(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// bl 0x820a37b8
	ctx.lr = 0x82061F50;
	sub_820A37B8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,33(r31)
	REX_STORE_U8(ctx.r31.u32 + 33, ctx.r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82061F64:
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x820b5d30
	ctx.lr = 0x82061F70;
	sub_820B5D30(ctx, base);
	// li r4,23
	ctx.r4.s64 = 23;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x82061F7C;
	sub_82053BC8(ctx, base);
	// stb r29,33(r31)
	REX_STORE_U8(ctx.r31.u32 + 33, ctx.r29.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82061F8C:
	// lhz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x82061fb8
	if (ctx.cr6.eq) goto loc_82061FB8;
	// lwz r11,-6628(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// li r6,8
	ctx.r6.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r29,180(r11)
	REX_STORE_U8(ctx.r11.u32 + 180, ctx.r29.u8);
	// lwz r3,-6624(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -6624);
	// lwz r5,184(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// bl 0x82077310
	ctx.lr = 0x82061FB8;
	sub_82077310(ctx, base);
loc_82061FB8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
