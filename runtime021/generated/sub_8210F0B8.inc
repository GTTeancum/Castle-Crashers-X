DEFINE_REX_FUNC(sub_8210F0B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r6,5
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 5, ctx.xer);
	// blt cr6,0x8210f194
	if (ctx.cr6.lt) goto loc_8210F194;
	// lwz r9,1(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 1);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8210f194
	if (ctx.cr6.eq) goto loc_8210F194;
	// lwz r11,60(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 60);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8210f194
	if (ctx.cr6.eq) goto loc_8210F194;
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8210f194
	if (ctx.cr6.eq) goto loc_8210F194;
	// lwz r10,712(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 712);
	// addi r11,r3,712
	ctx.r11.s64 = ctx.r3.s64 + 712;
	// b 0x8210f110
	goto loc_8210F110;
loc_8210F0FC:
	// lwz r8,56(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 56);
	// addi r5,r10,-4
	ctx.r5.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8210f124
	if (ctx.cr6.eq) goto loc_8210F124;
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
loc_8210F110:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8210f120
	if (ctx.cr6.eq) goto loc_8210F120;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8210f0fc
	if (!ctx.cr0.eq) goto loc_8210F0FC;
loc_8210F120:
	// li r5,0
	ctx.r5.s64 = 0;
loc_8210F124:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8210f170
	if (ctx.cr6.eq) goto loc_8210F170;
	// lwz r11,168(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 168);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210f18c
	if (ctx.cr0.eq) goto loc_8210F18C;
	// lis r12,-1024
	ctx.r12.s64 = -67108864;
	// lwz r11,60(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 60);
	// li r9,1
	ctx.r9.s64 = 1;
	// ori r12,r12,0
	ctx.r12.u64 = ctx.r12.u64 | 0;
	// rlwinm r10,r11,26,30,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0x3;
	// rldicr r12,r12,6,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 6) & 0xFFFFFFFFFFFFFFFF;
	// addi r8,r10,16
	ctx.r8.s64 = ctx.r10.s64 + 16;
	// and r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 & ctx.r12.u64;
	// sld r11,r9,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r11.u8 & 0x7F));
	// rlwinm r9,r8,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// ldx r9,r9,r4
	ctx.r9.u64 = REX_LOAD_U64(ctx.r9.u32 + ctx.r4.u32);
	// and r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 & ctx.r11.u64;
	// cmpldi cr6,r9,0
	ctx.cr6.compare<uint64_t>(ctx.r9.u64, 0, ctx.xer);
	// beq cr6,0x8210f178
	if (ctx.cr6.eq) goto loc_8210F178;
loc_8210F170:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8210f19c
	goto loc_8210F19C;
loc_8210F178:
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// ldx r9,r10,r4
	ctx.r9.u64 = REX_LOAD_U64(ctx.r10.u32 + ctx.r4.u32);
	// or r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 | ctx.r9.u64;
	// stdx r11,r10,r4
	REX_STORE_U64(ctx.r10.u32 + ctx.r4.u32, ctx.r11.u64);
loc_8210F18C:
	// bl 0x8210d078
	ctx.lr = 0x8210F190;
	sub_8210D078(ctx, base);
	// b 0x8210f19c
	goto loc_8210F19C;
loc_8210F194:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4106
	ctx.r3.u64 = ctx.r3.u64 | 4106;
loc_8210F19C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
