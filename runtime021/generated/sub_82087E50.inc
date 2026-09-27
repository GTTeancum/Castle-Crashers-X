DEFINE_REX_FUNC(sub_82087E50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82087E58;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r3,244(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82087ef4
	if (!ctx.cr6.eq) goto loc_82087EF4;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lbz r10,-22601(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82087e9c
	if (!ctx.cr6.eq) goto loc_82087E9C;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r3,r11,-1768
	ctx.r3.s64 = ctx.r11.s64 + -1768;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82087E9C;
	sub_820A71E8(ctx, base);
loc_82087E9C:
	// bl 0x820b5eb8
	ctx.lr = 0x82087EA0;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// li r4,20
	ctx.r4.s64 = 20;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82087EB8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82087ee8
	if (ctx.cr6.eq) goto loc_82087EE8;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r9,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// stb r11,16(r3)
	REX_STORE_U8(ctx.r3.u32 + 16, ctx.r11.u8);
	// stw r10,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r10.u32);
	// b 0x82087f08
	goto loc_82087F08;
loc_82087EE8:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r10.u32);
	// b 0x82087f08
	goto loc_82087F08;
loc_82087EF4:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8208bae0
	ctx.lr = 0x82087EFC;
	sub_8208BAE0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82087f28
	if (!ctx.cr6.eq) goto loc_82087F28;
loc_82087F08:
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// lwz r3,244(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bne cr6,0x82087f24
	if (!ctx.cr6.eq) goto loc_82087F24;
	// lhz r5,146(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 146);
loc_82087F24:
	// bl 0x8208b948
	ctx.lr = 0x82087F28;
	sub_8208B948(ctx, base);
loc_82087F28:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
