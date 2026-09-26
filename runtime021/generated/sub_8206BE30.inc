DEFINE_REX_FUNC(sub_8206BE30) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8206BE38;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r8,r10,9436
	ctx.r8.s64 = ctx.r10.s64 + 9436;
	// lbz r3,-22601(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r7,r9,-10136
	ctx.r7.s64 = ctx.r9.s64 + -10136;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r4,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,10316(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 10316);
	// stw r4,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r27,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// stw r27,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r27.u32);
	// sth r6,16(r31)
	REX_STORE_U16(ctx.r31.u32 + 16, ctx.r6.u16);
	// sth r27,18(r31)
	REX_STORE_U16(ctx.r31.u32 + 18, ctx.r27.u16);
	// stb r5,20(r31)
	REX_STORE_U8(ctx.r31.u32 + 20, ctx.r5.u8);
	// stb r27,33(r31)
	REX_STORE_U8(ctx.r31.u32 + 33, ctx.r27.u8);
	// stw r7,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// bne cr6,0x8206beb0
	if (!ctx.cr6.eq) goto loc_8206BEB0;
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
	ctx.lr = 0x8206BEB0;
	sub_820A71E8(ctx, base);
loc_8206BEB0:
	// bl 0x820b5eb8
	ctx.lr = 0x8206BEB4;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// li r4,8288
	ctx.r4.s64 = 8288;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206BECC;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206bf04
	if (ctx.cr6.eq) goto loc_8206BF04;
	// li r11,19
	ctx.r11.s64 = 19;
	// addi r28,r3,4
	ctx.r28.s64 = ctx.r3.s64 + 4;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r30,18
	ctx.r30.s64 = 18;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
loc_8206BEE8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82066680
	ctx.lr = 0x8206BEF0;
	sub_82066680(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,436
	ctx.r29.s64 = ctx.r29.s64 + 436;
	// bge 0x8206bee8
	if (!ctx.cr0.lt) goto loc_8206BEE8;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x8206bf08
	goto loc_8206BF08;
loc_8206BF04:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8206BF08:
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053ac0
	ctx.lr = 0x8206BF14;
	sub_82053AC0(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6540
	ctx.r4.s64 = ctx.r11.s64 + 6540;
	// bl 0x8206c510
	ctx.lr = 0x8206BF24;
	sub_8206C510(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6976
	ctx.r4.s64 = ctx.r11.s64 + 6976;
	// bl 0x820552b8
	ctx.lr = 0x8206BF34;
	sub_820552B8(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,7412
	ctx.r4.s64 = ctx.r11.s64 + 7412;
	// bl 0x8206ca60
	ctx.lr = 0x8206BF44;
	sub_8206CA60(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,7848
	ctx.r4.s64 = ctx.r11.s64 + 7848;
	// bl 0x8206cc40
	ctx.lr = 0x8206BF54;
	sub_8206CC40(ctx, base);
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x8206BF60;
	sub_82053BC8(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,-22656(r9)
	REX_STORE_U32(ctx.r9.u32 + -22656, ctx.r11.u32);
	// stw r10,-22660(r8)
	REX_STORE_U32(ctx.r8.u32 + -22660, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
