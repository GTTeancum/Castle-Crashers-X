DEFINE_REX_FUNC(sub_82079A00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x82079A08;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// addi r26,r27,4
	ctx.r26.s64 = ctx.r27.s64 + 4;
	// li r21,0
	ctx.r21.s64 = 0;
	// lwz r11,4(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lis r24,-32215
	ctx.r24.s64 = -2111242240;
	// addi r25,r9,29632
	ctx.r25.s64 = ctx.r9.s64 + 29632;
	// addi r22,r10,-1768
	ctx.r22.s64 = ctx.r10.s64 + -1768;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82079af4
	if (!ctx.cr6.gt) goto loc_82079AF4;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r29,r21
	ctx.r29.u64 = ctx.r21.u64;
	// ori r23,r11,65535
	ctx.r23.u64 = ctx.r11.u64 | 65535;
loc_82079A48:
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82079ab4
	if (ctx.cr6.eq) goto loc_82079AB4;
	// lhz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82079a7c
	if (!ctx.cr6.eq) goto loc_82079A7C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82079A7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82079A7C:
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82079A94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r9,r3,r12
	ctx.r9.u64 = ctx.r3.u64 & ctx.r12.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82079ab4
	if (ctx.cr6.eq) goto loc_82079AB4;
	// lhz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 24);
	// add r10,r11,r23
	ctx.r10.u64 = ctx.r11.u64 + ctx.r23.u64;
	// sth r10,24(r31)
	REX_STORE_U16(ctx.r31.u32 + 24, ctx.r10.u16);
loc_82079AB4:
	// lbz r11,-22601(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82079ad4
	if (!ctx.cr6.eq) goto loc_82079AD4;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82079AD4;
	sub_820A71E8(ctx, base);
loc_82079AD4:
	// bl 0x820b5eb8
	ctx.lr = 0x82079AD8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bf18
	ctx.lr = 0x82079AE8;
	sub_8209BF18(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// bne 0x82079a48
	if (!ctx.cr0.eq) goto loc_82079A48;
loc_82079AF4:
	// lwz r31,4(r26)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82079b38
	if (ctx.cr6.eq) goto loc_82079B38;
	// lbz r11,-22601(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82079b20
	if (!ctx.cr6.eq) goto loc_82079B20;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82079B20;
	sub_820A71E8(ctx, base);
loc_82079B20:
	// bl 0x820b5eb8
	ctx.lr = 0x82079B24;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bf18
	ctx.lr = 0x82079B34;
	sub_8209BF18(ctx, base);
	// stw r21,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r21.u32);
loc_82079B38:
	// stw r21,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r21.u32);
	// stw r21,8(r26)
	REX_STORE_U32(ctx.r26.u32 + 8, ctx.r21.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
