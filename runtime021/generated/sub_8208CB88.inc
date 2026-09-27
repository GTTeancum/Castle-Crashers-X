DEFINE_REX_FUNC(sub_8208CB88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8208CB90;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,5461
	ctx.r11.s64 = 357892096;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// ori r10,r11,21845
	ctx.r10.u64 = ctx.r11.u64 | 21845;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8208cbc8
	if (ctx.cr6.gt) goto loc_8208CBC8;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,-5
	ctx.r10.s64 = -5;
	// add r9,r29,r11
	ctx.r9.u64 = ctx.r29.u64 + ctx.r11.u64;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// addi r30,r11,4
	ctx.r30.s64 = ctx.r11.s64 + 4;
	// ble cr6,0x8208cbcc
	if (!ctx.cr6.gt) goto loc_8208CBCC;
loc_8208CBC8:
	// li r30,-1
	ctx.r30.s64 = -1;
loc_8208CBCC:
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lbz r10,-22601(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8208cbf4
	if (!ctx.cr6.eq) goto loc_8208CBF4;
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
	ctx.lr = 0x8208CBF4;
	sub_820A71E8(ctx, base);
loc_8208CBF4:
	// bl 0x820b5eb8
	ctx.lr = 0x8208CBF8;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8208CC10;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r8,0
	ctx.r8.s64 = 0;
	// beq cr6,0x8208cc4c
	if (ctx.cr6.eq) goto loc_8208CC4C;
	// addic. r11,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r11.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r29,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
	// blt 0x8208cc44
	if (ctx.cr0.lt) goto loc_8208CC44;
	// addi r10,r9,8
	ctx.r10.s64 = ctx.r9.s64 + 8;
loc_8208CC30:
	// stw r8,-4(r10)
	REX_STORE_U32(ctx.r10.u32 + -4, ctx.r8.u32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r8,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// bge 0x8208cc30
	if (!ctx.cr0.lt) goto loc_8208CC30;
loc_8208CC44:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// b 0x8208cc50
	goto loc_8208CC50;
loc_8208CC4C:
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_8208CC50:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// beq cr6,0x8208cc94
	if (ctx.cr6.eq) goto loc_8208CC94;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// lis r7,-32768
	ctx.r7.s64 = -2147483648;
loc_8208CC6C:
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stb r6,8(r9)
	REX_STORE_U8(ctx.r9.u32 + 8, ctx.r6.u8);
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// stw r7,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// bne 0x8208cc6c
	if (!ctx.cr0.eq) goto loc_8208CC6C;
loc_8208CC94:
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// sth r11,32(r31)
	REX_STORE_U16(ctx.r31.u32 + 32, ctx.r11.u16);
	// sth r11,34(r31)
	REX_STORE_U16(ctx.r31.u32 + 34, ctx.r11.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
