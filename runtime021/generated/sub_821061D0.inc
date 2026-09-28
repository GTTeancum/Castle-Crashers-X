DEFINE_REX_FUNC(sub_821061D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x821061D8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,196(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82106258
	if (ctx.cr6.eq) goto loc_82106258;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,24584
	ctx.r11.s64 = ctx.r11.s64 + 24584;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82106238
	if (ctx.cr6.eq) goto loc_82106238;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,21224
	ctx.r11.s64 = ctx.r11.s64 + 21224;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82106218
	if (!ctx.cr6.eq) goto loc_82106218;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r9,r11,0,11,11
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8210623c
	if (ctx.cr0.eq) goto loc_8210623C;
loc_82106218:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,19928
	ctx.r11.s64 = ctx.r11.s64 + 19928;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82106238
	if (ctx.cr6.eq) goto loc_82106238;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,7552
	ctx.r11.s64 = ctx.r11.s64 + 7552;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8210624c
	if (!ctx.cr6.eq) goto loc_8210624C;
loc_82106238:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
loc_8210623C:
	// ori r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 256;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// b 0x8210635c
	goto loc_8210635C;
loc_8210624C:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,170
	ctx.r3.u64 = ctx.r3.u64 | 170;
	// b 0x8210635c
	goto loc_8210635C;
loc_82106258:
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210634c
	if (ctx.cr6.eq) goto loc_8210634C;
	// addi r29,r31,48
	ctx.r29.s64 = ctx.r31.s64 + 48;
	// addi r30,r31,108
	ctx.r30.s64 = ctx.r31.s64 + 108;
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82129a70
	ctx.lr = 0x82106280;
	sub_82129A70(ctx, base);
	// li r5,60
	ctx.r5.s64 = 60;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82129fa0
	ctx.lr = 0x82106290;
	sub_82129FA0(ctx, base);
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm. r10,r10,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x821062b4
	if (ctx.cr0.eq) goto loc_821062B4;
	// lwz r10,720(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// ori r10,r10,128
	ctx.r10.u64 = ctx.r10.u64 | 128;
	// stw r10,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r10.u32);
	// lwz r4,24(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// b 0x821062c4
	goto loc_821062C4;
loc_821062B4:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// li r4,254
	ctx.r4.s64 = 254;
	// rlwinm r11,r11,0,25,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
loc_821062C4:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x821062ec
	if (ctx.cr6.eq) goto loc_821062EC;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x821062ec
	if (ctx.cr6.eq) goto loc_821062EC;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8210634c
	if (!ctx.cr6.eq) goto loc_8210634C;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r11,r11,0,20,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210634c
	if (ctx.cr0.eq) goto loc_8210634C;
loc_821062EC:
	// std r28,200(r31)
	REX_STORE_U64(ctx.r31.u32 + 200, ctx.r28.u64);
	// addi r30,r31,200
	ctx.r30.s64 = ctx.r31.s64 + 200;
	// std r28,208(r31)
	REX_STORE_U64(ctx.r31.u32 + 208, ctx.r28.u64);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// std r28,216(r31)
	REX_STORE_U64(ctx.r31.u32 + 216, ctx.r28.u64);
	// stw r28,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r28.u32);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x821391b8
	ctx.lr = 0x82106310;
	sub_821391B8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210633c
	if (ctx.cr0.eq) goto loc_8210633C;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x8210633c
	if (ctx.cr6.eq) goto loc_8210633C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82136e38
	ctx.lr = 0x82106328;
	sub_82136E38(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8210635c
	if (ctx.cr0.lt) goto loc_8210635C;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x8210635c
	goto loc_8210635C;
loc_8210633C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,7552
	ctx.r11.s64 = ctx.r11.s64 + 7552;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// b 0x82106358
	goto loc_82106358;
loc_8210634C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82101d80
	ctx.lr = 0x82106358;
	sub_82101D80(ctx, base);
loc_82106358:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_8210635C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
