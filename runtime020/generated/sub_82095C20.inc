DEFINE_REX_FUNC(sub_82095C20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82095C28;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r30,8
	ctx.r11.s64 = ctx.r30.s64 + 8;
	// li r9,31
	ctx.r9.s64 = 31;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
loc_82095C40:
	// sth r10,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r10.u16);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// sth r10,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r10.u16);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bge 0x82095c40
	if (!ctx.cr0.lt) goto loc_82095C40;
	// addi r29,r30,148
	ctx.r29.s64 = ctx.r30.s64 + 148;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r9,255
	ctx.r9.s64 = 255;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r8,r8,-1380
	ctx.r8.s64 = ctx.r8.s64 + -1380;
loc_82095C70:
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r7,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r31,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r31.u32);
	// stw r31,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r31.u32);
	// stw r31,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r31.u32);
	// stw r31,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r31.u32);
	// stw r31,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r31.u32);
	// stw r31,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r31.u32);
	// stw r31,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r31.u32);
	// stw r31,36(r11)
	REX_STORE_U32(ctx.r11.u32 + 36, ctx.r31.u32);
	// stw r31,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r31.u32);
	// sth r10,44(r11)
	REX_STORE_U16(ctx.r11.u32 + 44, ctx.r10.u16);
	// sth r10,46(r11)
	REX_STORE_U16(ctx.r11.u32 + 46, ctx.r10.u16);
	// addi r11,r11,56
	ctx.r11.s64 = ctx.r11.s64 + 56;
	// bge 0x82095c70
	if (!ctx.cr0.lt) goto loc_82095C70;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// stw r31,14484(r30)
	REX_STORE_U32(ctx.r30.u32 + 14484, ctx.r31.u32);
	// stw r31,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r31.u32);
	// stw r31,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r31.u32);
	// stw r31,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r31.u32);
	// lbz r10,-22601(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82095ce8
	if (!ctx.cr6.eq) goto loc_82095CE8;
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
	ctx.lr = 0x82095CE8;
	sub_820A71E8(ctx, base);
loc_82095CE8:
	// bl 0x820b5eb8
	ctx.lr = 0x82095CEC;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// li r4,1696
	ctx.r4.s64 = 1696;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82095D04;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82095d30
	if (ctx.cr6.eq) goto loc_82095D30;
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r31,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r31.u32);
	// stw r31,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r31,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r31.u32);
	// stw r31,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r31.u32);
	// stw r31,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// stw r10,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// b 0x82095d34
	goto loc_82095D34;
loc_82095D30:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_82095D34:
	// stw r11,136(r30)
	REX_STORE_U32(ctx.r30.u32 + 136, ctx.r11.u32);
	// addi r3,r30,14488
	ctx.r3.s64 = ctx.r30.s64 + 14488;
	// bl 0x8214a424
	ctx.lr = 0x82095D40;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// addi r3,r30,14516
	ctx.r3.s64 = ctx.r30.s64 + 14516;
	// bl 0x8214a424
	ctx.lr = 0x82095D48;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// addi r3,r30,14544
	ctx.r3.s64 = ctx.r30.s64 + 14544;
	// bl 0x8214a424
	ctx.lr = 0x82095D50;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// addi r3,r30,14572
	ctx.r3.s64 = ctx.r30.s64 + 14572;
	// bl 0x8214a424
	ctx.lr = 0x82095D58;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// addi r3,r30,14600
	ctx.r3.s64 = ctx.r30.s64 + 14600;
	// bl 0x8214a424
	ctx.lr = 0x82095D60;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// addi r3,r30,14628
	ctx.r3.s64 = ctx.r30.s64 + 14628;
	// bl 0x8214a424
	ctx.lr = 0x82095D68;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// li r9,256
	ctx.r9.s64 = 256;
loc_82095D74:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82095d80
	if (ctx.cr6.eq) goto loc_82095D80;
	// stw r11,52(r10)
	REX_STORE_U32(ctx.r10.u32 + 52, ctx.r11.u32);
loc_82095D80:
	// stw r10,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stw r31,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r31.u32);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r11,r11,56
	ctx.r11.s64 = ctx.r11.s64 + 56;
	// bne 0x82095d74
	if (!ctx.cr0.eq) goto loc_82095D74;
	// stw r29,144(r30)
	REX_STORE_U32(ctx.r30.u32 + 144, ctx.r29.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
