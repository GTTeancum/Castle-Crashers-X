DEFINE_REX_FUNC(sub_820CDB90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820CDB98;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1484(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1484);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820cdd60
	if (ctx.cr6.eq) goto loc_820CDD60;
	// rotlwi r31,r10,0
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cdd60
	if (ctx.cr6.eq) goto loc_820CDD60;
	// ld r11,10880(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 10880);
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x820cdd60
	if (ctx.cr6.eq) goto loc_820CDD60;
	// cmplwi cr6,r3,224
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 224, ctx.xer);
	// bgt cr6,0x820cdc78
	if (ctx.cr6.gt) goto loc_820CDC78;
	// beq cr6,0x820cdd28
	if (ctx.cr6.eq) goto loc_820CDD28;
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x820cdc64
	if (ctx.cr6.lt) goto loc_820CDC64;
	// beq cr6,0x820cdc64
	if (ctx.cr6.eq) goto loc_820CDC64;
	// cmplwi cr6,r3,16
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 16, ctx.xer);
	// beq cr6,0x820cdc38
	if (ctx.cr6.eq) goto loc_820CDC38;
	// cmplwi cr6,r3,17
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 17, ctx.xer);
	// beq cr6,0x820cdc04
	if (ctx.cr6.eq) goto loc_820CDC04;
	// cmplwi cr6,r3,34
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 34, ctx.xer);
	// bne cr6,0x820cdd60
	if (!ctx.cr6.eq) goto loc_820CDD60;
	// stw r4,23356(r31)
	REX_STORE_U32(ctx.r31.u32 + 23356, ctx.r4.u32);
	// b 0x820cdd60
	goto loc_820CDD60;
loc_820CDC04:
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r4,6
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 6, ctx.xer);
	// slw r8,r10,r4
	ctx.r8.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r4.u8 & 0x3F));
	// lwz r11,6152(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 6152);
	// or r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 | ctx.r11.u64;
	// stw r11,6152(r9)
	REX_STORE_U32(ctx.r9.u32 + 6152, ctx.r11.u32);
	// bne cr6,0x820cdd60
	if (!ctx.cr6.eq) goto loc_820CDD60;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,21632(r31)
	REX_STORE_U32(ctx.r31.u32 + 21632, ctx.r10.u32);
	// stw r11,21624(r31)
	REX_STORE_U32(ctx.r31.u32 + 21624, ctx.r11.u32);
	// stw r11,21628(r31)
	REX_STORE_U32(ctx.r31.u32 + 21628, ctx.r11.u32);
	// b 0x820cdd60
	goto loc_820CDD60;
loc_820CDC38:
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// li r11,1
	ctx.r11.s64 = 1;
	// cmplwi cr6,r4,6
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 6, ctx.xer);
	// slw r9,r11,r4
	ctx.r9.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r4.u8 & 0x3F));
	// lwz r11,6152(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 6152);
	// andc r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ~ctx.r9.u64;
	// stw r11,6152(r10)
	REX_STORE_U32(ctx.r10.u32 + 6152, ctx.r11.u32);
	// bne cr6,0x820cdd60
	if (!ctx.cr6.eq) goto loc_820CDD60;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,21632(r31)
	REX_STORE_U32(ctx.r31.u32 + 21632, ctx.r11.u32);
	// b 0x820cdd60
	goto loc_820CDD60;
loc_820CDC64:
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,21632(r31)
	REX_STORE_U32(ctx.r31.u32 + 21632, ctx.r11.u32);
	// stw r11,6152(r10)
	REX_STORE_U32(ctx.r10.u32 + 6152, ctx.r11.u32);
	// b 0x820cdd60
	goto loc_820CDD60;
loc_820CDC78:
	// cmplwi cr6,r3,225
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 225, ctx.xer);
	// beq cr6,0x820cdd28
	if (ctx.cr6.eq) goto loc_820CDD28;
	// cmplwi cr6,r3,226
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 226, ctx.xer);
	// beq cr6,0x820cdd28
	if (ctx.cr6.eq) goto loc_820CDD28;
	// cmplwi cr6,r3,227
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 227, ctx.xer);
	// beq cr6,0x820cdd1c
	if (ctx.cr6.eq) goto loc_820CDD1C;
	// cmplwi cr6,r3,255
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 255, ctx.xer);
	// bne cr6,0x820cdd60
	if (!ctx.cr6.eq) goto loc_820CDD60;
	// lis r28,-32221
	ctx.r28.s64 = -2111635456;
	// lwz r11,6152(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 6152);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cdcd8
	if (ctx.cr0.eq) goto loc_820CDCD8;
	// lwz r11,21576(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21576);
	// lfs f13,21592(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 21592);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r3,2
	ctx.r3.s64 = 131072;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// lfs f0,9732(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9732);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x82136738
	ctx.lr = 0x820CDCD8;
	sub_82136738(ctx, base);
loc_820CDCD8:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// li r29,17
	ctx.r29.s64 = 17;
	// addi r11,r11,2304
	ctx.r11.s64 = ctx.r11.s64 + 2304;
	// addi r30,r11,8
	ctx.r30.s64 = ctx.r11.s64 + 8;
loc_820CDCE8:
	// lwz r11,-8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -8);
	// lwz r10,6152(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 6152);
	// and. r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cdd0c
	if (ctx.cr0.eq) goto loc_820CDD0C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x820cd6a8
	ctx.lr = 0x820CDD04;
	sub_820CD6A8(ctx, base);
	// lwz r3,-4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -4);
	// bl 0x82136738
	ctx.lr = 0x820CDD0C;
	sub_82136738(ctx, base);
loc_820CDD0C:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,12
	ctx.r30.s64 = ctx.r30.s64 + 12;
	// bne 0x820cdce8
	if (!ctx.cr0.eq) goto loc_820CDCE8;
	// b 0x820cdd60
	goto loc_820CDD60;
loc_820CDD1C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cc888
	ctx.lr = 0x820CDD24;
	sub_820CC888(ctx, base);
	// b 0x820cdd60
	goto loc_820CDD60;
loc_820CDD28:
	// lwz r11,21532(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21532);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cdd60
	if (ctx.cr6.eq) goto loc_820CDD60;
	// bl 0x82136728
	ctx.lr = 0x820CDD38;
	sub_82136728(ctx, base);
	// lwz r11,10888(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10888);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x820cdd60
	if (!ctx.cr6.eq) goto loc_820CDD60;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820cdd5c
	if (!ctx.cr6.gt) goto loc_820CDD5C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7228
	ctx.lr = 0x820CDD5C;
	sub_820C7228(ctx, base);
loc_820CDD5C:
	// stw r3,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
loc_820CDD60:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
