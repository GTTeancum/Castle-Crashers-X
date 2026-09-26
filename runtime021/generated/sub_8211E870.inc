DEFINE_REX_FUNC(sub_8211E870) {
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
	// addi r3,r31,40
	ctx.r3.s64 = ctx.r31.s64 + 40;
	// bl 0x8214a434
	ctx.lr = 0x8211E890;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,1148(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// lwz r11,1064(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1064);
	// rlwinm r10,r10,0,4,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFCFFFFFFF;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// stw r10,1148(r31)
	REX_STORE_U32(ctx.r31.u32 + 1148, ctx.r10.u32);
	// ble cr6,0x8211e928
	if (!ctx.cr6.gt) goto loc_8211E928;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// ble cr6,0x8211e8f8
	if (!ctx.cr6.gt) goto loc_8211E8F8;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// beq cr6,0x8211e8dc
	if (ctx.cr6.eq) goto loc_8211E8DC;
	// lwz r11,1092(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1092);
	// rlwinm. r11,r11,0,3,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211e964
	if (ctx.cr0.eq) goto loc_8211E964;
	// addi r5,r31,1136
	ctx.r5.s64 = ctx.r31.s64 + 1136;
	// lwz r3,1136(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1136);
	// addi r4,r31,1060
	ctx.r4.s64 = ctx.r31.s64 + 1060;
	// bl 0x821229d0
	ctx.lr = 0x8211E8D4;
	sub_821229D0(ctx, base);
	// lwz r3,1136(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1136);
	// b 0x8211e8e8
	goto loc_8211E8E8;
loc_8211E8DC:
	// lwz r3,1136(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1136);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8211e964
	if (ctx.cr6.eq) goto loc_8211E964;
loc_8211E8E8:
	// bl 0x821180d8
	ctx.lr = 0x8211E8EC;
	sub_821180D8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,1136(r31)
	REX_STORE_U32(ctx.r31.u32 + 1136, ctx.r11.u32);
	// b 0x8211e964
	goto loc_8211E964;
loc_8211E8F8:
	// addi r30,r31,1136
	ctx.r30.s64 = ctx.r31.s64 + 1136;
	// lwz r3,1136(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1136);
	// addi r4,r31,1060
	ctx.r4.s64 = ctx.r31.s64 + 1060;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x821229d0
	ctx.lr = 0x8211E90C;
	sub_821229D0(ctx, base);
	// lwz r11,1064(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1064);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x8211e954
	if (!ctx.cr6.eq) goto loc_8211E954;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8211c068
	ctx.lr = 0x8211E924;
	sub_8211C068(ctx, base);
	// b 0x8211e954
	goto loc_8211E954;
loc_8211E928:
	// addi r30,r31,1136
	ctx.r30.s64 = ctx.r31.s64 + 1136;
	// lwz r3,1136(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1136);
	// addi r4,r31,1060
	ctx.r4.s64 = ctx.r31.s64 + 1060;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x82124c40
	ctx.lr = 0x8211E93C;
	sub_82124C40(ctx, base);
	// lwz r11,1064(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1064);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8211e954
	if (!ctx.cr6.eq) goto loc_8211E954;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8211dab8
	ctx.lr = 0x8211E954;
	sub_8211DAB8(ctx, base);
loc_8211E954:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x821180d8
	ctx.lr = 0x8211E95C;
	sub_821180D8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_8211E964:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211c7f8
	ctx.lr = 0x8211E96C;
	sub_8211C7F8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821180d8
	ctx.lr = 0x8211E974;
	sub_821180D8(ctx, base);
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
}
