DEFINE_REX_FUNC(sub_82104DD8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,720(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r11,r10,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82104f70
	if (ctx.cr0.eq) goto loc_82104F70;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r10,r10,0,26,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// stw r10,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r10.u32);
	// beq cr6,0x82104f5c
	if (ctx.cr6.eq) goto loc_82104F5C;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x82104f18
	if (ctx.cr6.eq) goto loc_82104F18;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// addi r11,r31,524
	ctx.r11.s64 = ctx.r31.s64 + 524;
	// beq cr6,0x82104ecc
	if (ctx.cr6.eq) goto loc_82104ECC;
	// lwz r9,524(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82104f70
	if (!ctx.cr6.eq) goto loc_82104F70;
	// oris r10,r10,8
	ctx.r10.u64 = ctx.r10.u64 | 524288;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r10.u32);
	// addi r30,r31,200
	ctx.r30.s64 = ctx.r31.s64 + 200;
	// std r11,200(r31)
	REX_STORE_U64(ctx.r31.u32 + 200, ctx.r11.u64);
	// std r11,208(r31)
	REX_STORE_U64(ctx.r31.u32 + 208, ctx.r11.u64);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// std r11,216(r31)
	REX_STORE_U64(ctx.r31.u32 + 216, ctx.r11.u64);
	// stw r11,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r11.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x821388e0
	ctx.lr = 0x82104E5C;
	sub_821388E0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82104ebc
	if (ctx.cr0.eq) goto loc_82104EBC;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x82104ebc
	if (ctx.cr6.eq) goto loc_82104EBC;
loc_82104E6C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82136e38
	ctx.lr = 0x82104E74;
	sub_82136E38(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82104e84
	if (ctx.cr0.lt) goto loc_82104E84;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
loc_82104E84:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x82104ea4
	if (ctx.cr6.eq) goto loc_82104EA4;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82105c40
	ctx.lr = 0x82104EA4;
	sub_82105C40(ctx, base);
loc_82104EA4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
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
loc_82104EBC:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,4936
	ctx.r11.s64 = ctx.r11.s64 + 4936;
loc_82104EC4:
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// b 0x82104ea4
	goto loc_82104EA4;
loc_82104ECC:
	// lwz r10,524(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82104f70
	if (!ctx.cr6.eq) goto loc_82104F70;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r30,r31,200
	ctx.r30.s64 = ctx.r31.s64 + 200;
	// std r11,200(r31)
	REX_STORE_U64(ctx.r31.u32 + 200, ctx.r11.u64);
	// std r11,208(r31)
	REX_STORE_U64(ctx.r31.u32 + 208, ctx.r11.u64);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// std r11,216(r31)
	REX_STORE_U64(ctx.r31.u32 + 216, ctx.r11.u64);
	// stw r11,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r11.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82138da0
	ctx.lr = 0x82104EFC;
	sub_82138DA0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82104f0c
	if (ctx.cr0.eq) goto loc_82104F0C;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x82104e6c
	if (!ctx.cr6.eq) goto loc_82104E6C;
loc_82104F0C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,21224
	ctx.r11.s64 = ctx.r11.s64 + 21224;
	// b 0x82104ec4
	goto loc_82104EC4;
loc_82104F18:
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r30,r31,200
	ctx.r30.s64 = ctx.r31.s64 + 200;
	// std r11,200(r31)
	REX_STORE_U64(ctx.r31.u32 + 200, ctx.r11.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r11,208(r31)
	REX_STORE_U64(ctx.r31.u32 + 208, ctx.r11.u64);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// std r11,216(r31)
	REX_STORE_U64(ctx.r31.u32 + 216, ctx.r11.u64);
	// stw r11,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r11.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82138d08
	ctx.lr = 0x82104F40;
	sub_82138D08(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82104f50
	if (ctx.cr0.eq) goto loc_82104F50;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x82104e6c
	if (!ctx.cr6.eq) goto loc_82104E6C;
loc_82104F50:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,24584
	ctx.r11.s64 = ctx.r11.s64 + 24584;
	// b 0x82104ec4
	goto loc_82104EC4;
loc_82104F5C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82104c20
	ctx.lr = 0x82104F64;
	sub_82104C20(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82104e84
	if (!ctx.cr0.eq) goto loc_82104E84;
	// b 0x82104ea4
	goto loc_82104EA4;
loc_82104F70:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r11,0,23,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82104fb0
	if (ctx.cr0.eq) goto loc_82104FB0;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r11,r11,0,24,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFEFF;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bne cr6,0x82104f9c
	if (!ctx.cr6.eq) goto loc_82104F9C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,1232
	ctx.r3.u64 = ctx.r3.u64 | 1232;
	// b 0x82104e84
	goto loc_82104E84;
loc_82104F9C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821061d0
	ctx.lr = 0x82104FA4;
	sub_821061D0(ctx, base);
loc_82104FA4:
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82104e84
	if (ctx.cr0.lt) goto loc_82104E84;
	// b 0x82104ea4
	goto loc_82104EA4;
loc_82104FB0:
	// rlwinm. r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82104ea4
	if (ctx.cr0.eq) goto loc_82104EA4;
	// rlwinm r11,r11,0,23,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bl 0x821015d0
	ctx.lr = 0x82104FC8;
	sub_821015D0(ctx, base);
	// b 0x82104fa4
	goto loc_82104FA4;
}
