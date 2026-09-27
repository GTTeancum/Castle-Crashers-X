DEFINE_REX_FUNC(sub_82094D28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x82094D30;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82079a00
	ctx.lr = 0x82094D3C;
	sub_82079A00(ctx, base);
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r30,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// beq cr6,0x82094d64
	if (ctx.cr6.eq) goto loc_82094D64;
	// stw r30,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,76(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// bl 0x82066ea8
	ctx.lr = 0x82094D60;
	sub_82066EA8(ctx, base);
	// stw r30,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
loc_82094D64:
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lbz r8,86(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 86);
	// lwz r29,140(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r7,1
	ctx.r7.s64 = 1;
	// clrlwi r6,r8,28
	ctx.r6.u64 = ctx.r8.u32 & 0xF;
	// sth r30,82(r31)
	REX_STORE_U16(ctx.r31.u32 + 82, ctx.r30.u16);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// sth r7,84(r31)
	REX_STORE_U16(ctx.r31.u32 + 84, ctx.r7.u16);
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// stb r6,86(r31)
	REX_STORE_U8(ctx.r31.u32 + 86, ctx.r6.u8);
	// lfs f0,9540(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// stw r30,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// stfs f0,164(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 164, temp.u32);
	// lis r27,-32215
	ctx.r27.s64 = -2111242240;
	// stw r30,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r30,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r30.u32);
	// addi r28,r11,29632
	ctx.r28.s64 = ctx.r11.s64 + 29632;
	// sth r30,98(r31)
	REX_STORE_U16(ctx.r31.u32 + 98, ctx.r30.u16);
	// addi r26,r10,-1768
	ctx.r26.s64 = ctx.r10.s64 + -1768;
	// stb r30,120(r31)
	REX_STORE_U8(ctx.r31.u32 + 120, ctx.r30.u8);
	// sth r30,160(r31)
	REX_STORE_U16(ctx.r31.u32 + 160, ctx.r30.u16);
	// beq cr6,0x82094df8
	if (ctx.cr6.eq) goto loc_82094DF8;
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82094de0
	if (!ctx.cr6.eq) goto loc_82094DE0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82094DE0;
	sub_820A71E8(ctx, base);
loc_82094DE0:
	// bl 0x820b5eb8
	ctx.lr = 0x82094DE4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r11,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// bl 0x8209bf18
	ctx.lr = 0x82094DF4;
	sub_8209BF18(ctx, base);
	// stw r30,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r30.u32);
loc_82094DF8:
	// lwz r29,144(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82094e3c
	if (ctx.cr6.eq) goto loc_82094E3C;
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82094e24
	if (!ctx.cr6.eq) goto loc_82094E24;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82094E24;
	sub_820A71E8(ctx, base);
loc_82094E24:
	// bl 0x820b5eb8
	ctx.lr = 0x82094E28;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r11,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// bl 0x8209bf18
	ctx.lr = 0x82094E38;
	sub_8209BF18(ctx, base);
	// stw r30,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r30.u32);
loc_82094E3C:
	// lwz r29,152(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82094e80
	if (ctx.cr6.eq) goto loc_82094E80;
	// lbz r11,-22601(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82094e68
	if (!ctx.cr6.eq) goto loc_82094E68;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82094E68;
	sub_820A71E8(ctx, base);
loc_82094E68:
	// bl 0x820b5eb8
	ctx.lr = 0x82094E6C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r11,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// bl 0x8209bf18
	ctx.lr = 0x82094E7C;
	sub_8209BF18(ctx, base);
	// stw r30,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
loc_82094E80:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
