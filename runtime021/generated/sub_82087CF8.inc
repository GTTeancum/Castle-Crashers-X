DEFINE_REX_FUNC(sub_82087CF8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82087D00;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82079a00
	ctx.lr = 0x82087D0C;
	sub_82079A00(ctx, base);
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82087d30
	if (ctx.cr6.eq) goto loc_82087D30;
	// stw r30,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,76(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// bl 0x82066ea8
	ctx.lr = 0x82087D2C;
	sub_82066EA8(ctx, base);
	// stw r30,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
loc_82087D30:
	// addi r3,r31,104
	ctx.r3.s64 = ctx.r31.s64 + 104;
	// bl 0x82084be8
	ctx.lr = 0x82087D38;
	sub_82084BE8(ctx, base);
	// addi r29,r31,108
	ctx.r29.s64 = ctx.r31.s64 + 108;
	// lwz r28,112(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82087d90
	if (ctx.cr6.eq) goto loc_82087D90;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lbz r10,-22601(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82087d70
	if (!ctx.cr6.eq) goto loc_82087D70;
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
	ctx.lr = 0x82087D70;
	sub_820A71E8(ctx, base);
loc_82087D70:
	// bl 0x820b5eb8
	ctx.lr = 0x82087D74;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bf18
	ctx.lr = 0x82087D8C;
	sub_8209BF18(ctx, base);
	// stw r30,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r30.u32);
loc_82087D90:
	// stw r30,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r30.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r30,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// addi r3,r31,160
	ctx.r3.s64 = ctx.r31.s64 + 160;
	// lbz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 140);
	// clrlwi r9,r10,27
	ctx.r9.u64 = ctx.r10.u32 & 0x1F;
	// rlwinm r9,r9,0,31,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF9;
	// stw r30,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r30.u32);
	// stw r30,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r30.u32);
	// ori r8,r9,2
	ctx.r8.u64 = ctx.r9.u64 | 2;
	// sth r11,142(r31)
	REX_STORE_U16(ctx.r31.u32 + 142, ctx.r11.u16);
	// sth r11,144(r31)
	REX_STORE_U16(ctx.r31.u32 + 144, ctx.r11.u16);
	// sth r11,146(r31)
	REX_STORE_U16(ctx.r31.u32 + 146, ctx.r11.u16);
	// sth r11,148(r31)
	REX_STORE_U16(ctx.r31.u32 + 148, ctx.r11.u16);
	// stw r30,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// stb r8,140(r31)
	REX_STORE_U8(ctx.r31.u32 + 140, ctx.r8.u8);
	// bl 0x82079f38
	ctx.lr = 0x82087DD4;
	sub_82079F38(ctx, base);
	// lwz r3,244(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82087dfc
	if (ctx.cr6.eq) goto loc_82087DFC;
	// bl 0x8208b8d0
	ctx.lr = 0x82087DE4;
	sub_8208B8D0(ctx, base);
	// lwz r3,244(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82087df8
	if (ctx.cr6.eq) goto loc_82087DF8;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82086d30
	ctx.lr = 0x82087DF8;
	sub_82086D30(ctx, base);
loc_82087DF8:
	// stw r30,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r30.u32);
loc_82087DFC:
	// lbz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 140);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82087e44
	if (ctx.cr6.eq) goto loc_82087E44;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// lwz r11,156(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// rlwinm r9,r9,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r9,140(r31)
	REX_STORE_U8(ctx.r31.u32 + 140, ctx.r9.u8);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,20(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 20);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82087E38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,96(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r5,156(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 156);
	// stw r5,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r5.u32);
loc_82087E44:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
