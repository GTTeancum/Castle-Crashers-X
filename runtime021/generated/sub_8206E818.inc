DEFINE_REX_FUNC(sub_8206E818) {
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206e84c
	if (ctx.cr6.eq) goto loc_8206E84C;
	// lhz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// b 0x8206e850
	goto loc_8206E850;
loc_8206E84C:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_8206E850:
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x8206ea58
	if (ctx.cr6.gt) goto loc_8206EA58;
	// lis r12,-32249
	ctx.r12.s64 = -2113470464;
	// addi r12,r12,-6032
	ctx.r12.s64 = ctx.r12.s64 + -6032;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8206E880;
	case 1:
		goto loc_8206E8E4;
	case 2:
		goto loc_8206E9A4;
	case 3:
		goto loc_8206E93C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8206E880:
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// stb r31,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r31.u8);
	// addi r4,r10,-10012
	ctx.r4.s64 = ctx.r10.s64 + -10012;
	// stw r31,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r31.u32);
	// stb r31,144(r1)
	REX_STORE_U8(ctx.r1.u32 + 144, ctx.r31.u8);
	// lwz r3,10316(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 10316);
	// bl 0x8209d948
	ctx.lr = 0x8206E8A8;
	sub_8209D948(ctx, base);
	// lwz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r8,8
	ctx.r8.s64 = 8;
	// sth r3,92(r1)
	REX_STORE_U16(ctx.r1.u32 + 92, ctx.r3.u16);
	// stb r31,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r31.u8);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// stw r8,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// addi r7,r1,136
	ctx.r7.s64 = ctx.r1.s64 + 136;
	// lwz r3,76(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r11,8248(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8248);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r11,1998
	ctx.r10.s64 = ctx.r11.s64 + 1998;
	// stw r11,8248(r9)
	REX_STORE_U32(ctx.r9.u32 + 8248, ctx.r11.u32);
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r11,r9
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, ctx.r3.u32);
	// b 0x8206ea04
	goto loc_8206EA04;
loc_8206E8E4:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-9996
	ctx.r4.s64 = ctx.r10.s64 + -9996;
	// lwz r3,10316(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 10316);
	// bl 0x8209d948
	ctx.lr = 0x8206E8F8;
	sub_8209D948(ctx, base);
	// lwz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,76(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,120(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 120);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8206E914;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,4(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,76(r6)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + 76);
	// lwz r5,0(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,164(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 164);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8206E930;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lwz r3,-6624(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -6624);
	// b 0x8206ea50
	goto loc_8206EA50;
loc_8206E93C:
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r31,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// stb r31,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r31.u8);
	// addi r4,r10,-9988
	ctx.r4.s64 = ctx.r10.s64 + -9988;
	// stw r31,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r31.u32);
	// stb r31,160(r1)
	REX_STORE_U8(ctx.r1.u32 + 160, ctx.r31.u8);
	// lwz r3,10316(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 10316);
	// bl 0x8209d948
	ctx.lr = 0x8206E964;
	sub_8209D948(ctx, base);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r9,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// stb r31,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r31.u8);
	// addi r7,r1,152
	ctx.r7.s64 = ctx.r1.s64 + 152;
	// sth r3,108(r1)
	REX_STORE_U16(ctx.r1.u32 + 108, ctx.r3.u16);
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// lwz r10,76(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 76);
	// lwz r11,8248(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8248);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r11,1998
	ctx.r9.s64 = ctx.r11.s64 + 1998;
	// stw r11,8248(r3)
	REX_STORE_U32(ctx.r3.u32 + 8248, ctx.r11.u32);
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r11,r3
	REX_STORE_U32(ctx.r11.u32 + ctx.r3.u32, ctx.r10.u32);
	// b 0x8206ea08
	goto loc_8206EA08;
loc_8206E9A4:
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r31,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r31.u32);
	// stb r31,128(r1)
	REX_STORE_U8(ctx.r1.u32 + 128, ctx.r31.u8);
	// addi r4,r10,-9968
	ctx.r4.s64 = ctx.r10.s64 + -9968;
	// stw r31,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r31.u32);
	// stb r31,176(r1)
	REX_STORE_U8(ctx.r1.u32 + 176, ctx.r31.u8);
	// lwz r3,10316(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 10316);
	// bl 0x8209d948
	ctx.lr = 0x8206E9CC;
	sub_8209D948(ctx, base);
	// li r9,8
	ctx.r9.s64 = 8;
	// sth r3,124(r1)
	REX_STORE_U16(ctx.r1.u32 + 124, ctx.r3.u16);
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// stw r9,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r9.u32);
	// addi r7,r1,168
	ctx.r7.s64 = ctx.r1.s64 + 168;
	// stb r31,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r31.u8);
	// lwz r10,76(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 76);
	// lwz r11,8248(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8248);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r11,1998
	ctx.r9.s64 = ctx.r11.s64 + 1998;
	// stw r11,8248(r3)
	REX_STORE_U32(ctx.r3.u32 + 8248, ctx.r11.u32);
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r11,r3
	REX_STORE_U32(ctx.r11.u32 + ctx.r3.u32, ctx.r10.u32);
loc_8206EA04:
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
loc_8206EA08:
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,224
	ctx.r4.s64 = 224;
	// lwz r11,76(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// addi r3,r11,160
	ctx.r3.s64 = ctx.r11.s64 + 160;
	// bl 0x8207b150
	ctx.lr = 0x8206EA28;
	sub_8207B150(ctx, base);
	// lwz r8,4(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lwz r11,8248(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 8248);
	// lwz r3,-6624(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + -6624);
	// addi r7,r11,1998
	ctx.r7.s64 = ctx.r11.s64 + 1998;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r31,r6,r8
	REX_STORE_U32(ctx.r6.u32 + ctx.r8.u32, ctx.r31.u32);
	// lwz r11,8248(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 8248);
	// addi r5,r11,-1
	ctx.r5.s64 = ctx.r11.s64 + -1;
	// stw r5,8248(r8)
	REX_STORE_U32(ctx.r8.u32 + 8248, ctx.r5.u32);
loc_8206EA50:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8206dd58
	ctx.lr = 0x8206EA58;
	sub_8206DD58(ctx, base);
loc_8206EA58:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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
