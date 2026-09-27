DEFINE_REX_FUNC(sub_82086DE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82086DF0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r11,92(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 92);
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// lwz r30,104(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 104);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82086e7c
	if (ctx.cr6.eq) goto loc_82086E7C;
	// addi r27,r31,104
	ctx.r27.s64 = ctx.r31.s64 + 104;
loc_82086E14:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82086E28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r8,44(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 44);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82086E3C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82086e60
	if (ctx.cr6.eq) goto loc_82086E60;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,148(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 148);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82086E60;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82086E60:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82084db8
	ctx.lr = 0x82086E70;
	sub_82084DB8(ctx, base);
	// lwz r30,88(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82086e14
	if (!ctx.cr6.eq) goto loc_82086E14;
loc_82086E7C:
	// addi r4,r31,160
	ctx.r4.s64 = ctx.r31.s64 + 160;
	// addi r3,r28,160
	ctx.r3.s64 = ctx.r28.s64 + 160;
	// bl 0x8207bd00
	ctx.lr = 0x82086E88;
	sub_8207BD00(ctx, base);
	// lwz r11,244(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 244);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,1
	ctx.r29.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82086ee8
	if (ctx.cr6.eq) goto loc_82086EE8;
	// lwz r11,244(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82086edc
	if (!ctx.cr6.eq) goto loc_82086EDC;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x820a7390
	ctx.lr = 0x82086EB0;
	sub_820A7390(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82086ed4
	if (ctx.cr6.eq) goto loc_82086ED4;
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r30,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// stw r30,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stw r29,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r29.u32);
	// stb r30,16(r3)
	REX_STORE_U8(ctx.r3.u32 + 16, ctx.r30.u8);
	// b 0x82086ed8
	goto loc_82086ED8;
loc_82086ED4:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82086ED8:
	// stw r11,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r11.u32);
loc_82086EDC:
	// lwz r4,244(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 244);
	// lwz r3,244(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// bl 0x8208bbb0
	ctx.lr = 0x82086EE8;
	sub_8208BBB0(ctx, base);
loc_82086EE8:
	// addi r4,r28,108
	ctx.r4.s64 = ctx.r28.s64 + 108;
	// addi r3,r31,108
	ctx.r3.s64 = ctx.r31.s64 + 108;
	// bl 0x8208bcf8
	ctx.lr = 0x82086EF4;
	sub_8208BCF8(ctx, base);
	// lbz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 140);
	// li r12,177
	ctx.r12.s64 = 177;
	// lwz r10,128(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 128);
	// lbz r8,86(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 86);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// and r9,r11,r12
	ctx.r9.u64 = ctx.r11.u64 & ctx.r12.u64;
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// ori r5,r8,16
	ctx.r5.u64 = ctx.r8.u64 | 16;
	// ori r6,r9,4
	ctx.r6.u64 = ctx.r9.u64 | 4;
	// stw r10,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r10.u32);
	// stb r6,140(r31)
	REX_STORE_U8(ctx.r31.u32 + 140, ctx.r6.u8);
	// rlwimi r6,r29,0,31,23
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xFFFFFFFFFFFFFF01) | (ctx.r6.u64 & 0xFE);
	// lwz r4,96(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 96);
	// stw r4,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r4.u32);
	// sth r30,82(r31)
	REX_STORE_U16(ctx.r31.u32 + 82, ctx.r30.u16);
	// stw r30,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// sth r30,146(r31)
	REX_STORE_U16(ctx.r31.u32 + 146, ctx.r30.u16);
	// sth r30,144(r31)
	REX_STORE_U16(ctx.r31.u32 + 144, ctx.r30.u16);
	// lhz r11,148(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 148);
	// sth r11,148(r31)
	REX_STORE_U16(ctx.r31.u32 + 148, ctx.r11.u16);
	// stb r6,140(r31)
	REX_STORE_U8(ctx.r31.u32 + 140, ctx.r6.u8);
	// stb r5,86(r31)
	REX_STORE_U8(ctx.r31.u32 + 86, ctx.r5.u8);
	// lhz r4,100(r28)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r28.u32 + 100);
	// lwz r10,76(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82086F5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,156(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 156);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r9,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r9.u32);
	// bl 0x82083550
	ctx.lr = 0x82086F70;
	sub_82083550(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
