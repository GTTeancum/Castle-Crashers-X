DEFINE_REX_FUNC(sub_82096828) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82096830;
	__savegprlr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lbz r9,-22601(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// lwz r29,-6612(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + -6612);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82096868
	if (!ctx.cr6.eq) goto loc_82096868;
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
	ctx.lr = 0x82096868;
	sub_820A71E8(ctx, base);
loc_82096868:
	// bl 0x820b5eb8
	ctx.lr = 0x8209686C;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// li r4,5388
	ctx.r4.s64 = 5388;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82096884;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820968dc
	if (ctx.cr6.eq) goto loc_820968DC;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82129fa0
	ctx.lr = 0x8209689C;
	sub_82129FA0(ctx, base);
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,2048
	ctx.r3.s64 = ctx.r31.s64 + 2048;
	// bl 0x82129fa0
	ctx.lr = 0x820968AC;
	sub_82129FA0(ctx, base);
	// li r5,3072
	ctx.r5.s64 = 3072;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,2304
	ctx.r3.s64 = ctx.r31.s64 + 2304;
	// bl 0x82129fa0
	ctx.lr = 0x820968BC;
	sub_82129FA0(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r30,5376(r31)
	REX_STORE_U32(ctx.r31.u32 + 5376, ctx.r30.u32);
	// stb r30,5380(r31)
	REX_STORE_U8(ctx.r31.u32 + 5380, ctx.r30.u8);
	// lfs f0,9536(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,5384(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 5384, temp.u32);
	// b 0x820968e4
	goto loc_820968E4;
loc_820968DC:
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_820968E4:
	// li r5,11
	ctx.r5.s64 = 11;
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r30,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r30.u8);
	// addi r3,r1,113
	ctx.r3.s64 = ctx.r1.s64 + 113;
	// bl 0x82129fa0
	ctx.lr = 0x820968FC;
	sub_82129FA0(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r9,r11,-32560
	ctx.r9.s64 = ctx.r11.s64 + -32560;
	// stb r10,114(r1)
	REX_STORE_U8(ctx.r1.u32 + 114, ctx.r10.u8);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r9,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// bl 0x820d8580
	ctx.lr = 0x82096918;
	sub_820D8580(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x82096930
	if (!ctx.cr6.lt) goto loc_82096930;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,1216
	ctx.r3.s64 = ctx.r11.s64 + 1216;
	// bl 0x8208c5d8
	ctx.lr = 0x82096930;
	sub_8208C5D8(ctx, base);
loc_82096930:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r30,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r30.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r30,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r30.u32);
	// stb r11,0(r29)
	REX_STORE_U8(ctx.r29.u32 + 0, ctx.r11.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
