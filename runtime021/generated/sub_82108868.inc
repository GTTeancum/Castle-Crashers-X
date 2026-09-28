DEFINE_REX_FUNC(sub_82108868) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82108870;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82108884
	if (!ctx.cr6.eq) goto loc_82108884;
	// lwz r4,4(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r5,0(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
loc_82108884:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8210899c
	if (ctx.cr6.eq) goto loc_8210899C;
	// addi r31,r4,16
	ctx.r31.s64 = ctx.r4.s64 + 16;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
loc_82108894:
	// lwz r8,-16(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + -16);
	// addi r11,r7,-4
	ctx.r11.s64 = ctx.r7.s64 + -4;
	// addi r10,r31,4
	ctx.r10.s64 = ctx.r31.s64 + 4;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// addi r11,r6,4
	ctx.r11.s64 = ctx.r6.s64 + 4;
	// stw r8,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbz r8,-8(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + -8);
	// stb r8,4(r6)
	REX_STORE_U8(ctx.r6.u32 + 4, ctx.r8.u8);
	// lbz r8,-8(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + -8);
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// beq cr6,0x82108980
	if (ctx.cr6.eq) goto loc_82108980;
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// beq cr6,0x8210896c
	if (ctx.cr6.eq) goto loc_8210896C;
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// beq cr6,0x8210896c
	if (ctx.cr6.eq) goto loc_8210896C;
	// cmpwi cr6,r8,4
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 4, ctx.xer);
	// beq cr6,0x8210891c
	if (ctx.cr6.eq) goto loc_8210891C;
	// cmpwi cr6,r8,5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 5, ctx.xer);
	// beq cr6,0x82108980
	if (ctx.cr6.eq) goto loc_82108980;
	// cmpwi cr6,r8,6
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 6, ctx.xer);
	// bne cr6,0x8210896c
	if (!ctx.cr6.eq) goto loc_8210896C;
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r30,r11,2
	ctx.r30.s64 = ctx.r11.s64 + 2;
	// addi r29,r9,-2
	ctx.r29.s64 = ctx.r9.s64 + -2;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// sth r8,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r8.u16);
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x82129a70
	ctx.lr = 0x8210890C;
	sub_82129A70(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// add r6,r11,r30
	ctx.r6.u64 = ctx.r11.u64 + ctx.r30.u64;
	// subf r7,r11,r29
	ctx.r7.u64 = ctx.r29.u64 - ctx.r11.u64;
	// b 0x82108990
	goto loc_82108990;
loc_8210891C:
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r30,r11,2
	ctx.r30.s64 = ctx.r11.s64 + 2;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// lwz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r29,r9,-2
	ctx.r29.s64 = ctx.r9.s64 + -2;
	// rlwinm r11,r8,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r3,r3,65001
	ctx.r3.u64 = ctx.r3.u64 | 65001;
	// bl 0x82136e98
	ctx.lr = 0x82108958;
	sub_82136E98(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// sth r11,0(r27)
	REX_STORE_U16(ctx.r27.u32 + 0, ctx.r11.u16);
	// add r6,r11,r30
	ctx.r6.u64 = ctx.r11.u64 + ctx.r30.u64;
	// subf r7,r11,r29
	ctx.r7.u64 = ctx.r29.u64 - ctx.r11.u64;
	// b 0x82108990
	goto loc_82108990;
loc_8210896C:
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// addi r7,r9,-8
	ctx.r7.s64 = ctx.r9.s64 + -8;
	// addi r6,r11,8
	ctx.r6.s64 = ctx.r11.s64 + 8;
	// std r10,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r10.u64);
	// b 0x82108990
	goto loc_82108990;
loc_82108980:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// addi r7,r9,-4
	ctx.r7.s64 = ctx.r9.s64 + -4;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82108990:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// bne 0x82108894
	if (!ctx.cr0.eq) goto loc_82108894;
loc_8210899C:
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
