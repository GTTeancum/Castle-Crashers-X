DEFINE_REX_FUNC(sub_8209CED0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r10,-22601(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8209cf0c
	if (!ctx.cr6.eq) goto loc_8209CF0C;
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
	ctx.lr = 0x8209CF0C;
	sub_820A71E8(ctx, base);
loc_8209CF0C:
	// bl 0x820b5eb8
	ctx.lr = 0x8209CF10;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// li r4,852
	ctx.r4.s64 = 852;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8209CF28;
	sub_8209BDD8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209d00c
	if (ctx.cr6.eq) goto loc_8209D00C;
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r8,4
	ctx.r8.s64 = 4;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// stb r9,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, ctx.r9.u8);
	// sth r10,6(r11)
	REX_STORE_U16(ctx.r11.u32 + 6, ctx.r10.u16);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// sth r10,8(r11)
	REX_STORE_U16(ctx.r11.u32 + 8, ctx.r10.u16);
	// sth r10,10(r11)
	REX_STORE_U16(ctx.r11.u32 + 10, ctx.r10.u16);
	// sth r10,12(r11)
	REX_STORE_U16(ctx.r11.u32 + 12, ctx.r10.u16);
	// stw r9,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r9.u32);
	// stw r9,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r9.u32);
	// stw r9,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r9.u32);
	// stw r9,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r9.u32);
	// stb r9,132(r11)
	REX_STORE_U8(ctx.r11.u32 + 132, ctx.r9.u8);
	// stb r9,216(r11)
	REX_STORE_U8(ctx.r11.u32 + 216, ctx.r9.u8);
	// sth r10,218(r11)
	REX_STORE_U16(ctx.r11.u32 + 218, ctx.r10.u16);
	// sth r10,220(r11)
	REX_STORE_U16(ctx.r11.u32 + 220, ctx.r10.u16);
	// sth r10,222(r11)
	REX_STORE_U16(ctx.r11.u32 + 222, ctx.r10.u16);
	// sth r10,224(r11)
	REX_STORE_U16(ctx.r11.u32 + 224, ctx.r10.u16);
	// stw r9,324(r11)
	REX_STORE_U32(ctx.r11.u32 + 324, ctx.r9.u32);
	// stw r9,328(r11)
	REX_STORE_U32(ctx.r11.u32 + 328, ctx.r9.u32);
	// stw r9,332(r11)
	REX_STORE_U32(ctx.r11.u32 + 332, ctx.r9.u32);
	// stw r9,340(r11)
	REX_STORE_U32(ctx.r11.u32 + 340, ctx.r9.u32);
	// stb r9,344(r11)
	REX_STORE_U8(ctx.r11.u32 + 344, ctx.r9.u8);
	// stb r9,428(r11)
	REX_STORE_U8(ctx.r11.u32 + 428, ctx.r9.u8);
	// sth r10,430(r11)
	REX_STORE_U16(ctx.r11.u32 + 430, ctx.r10.u16);
	// sth r10,432(r11)
	REX_STORE_U16(ctx.r11.u32 + 432, ctx.r10.u16);
	// sth r10,434(r11)
	REX_STORE_U16(ctx.r11.u32 + 434, ctx.r10.u16);
	// sth r10,436(r11)
	REX_STORE_U16(ctx.r11.u32 + 436, ctx.r10.u16);
	// stw r9,536(r11)
	REX_STORE_U32(ctx.r11.u32 + 536, ctx.r9.u32);
	// stw r9,540(r11)
	REX_STORE_U32(ctx.r11.u32 + 540, ctx.r9.u32);
	// stw r9,544(r11)
	REX_STORE_U32(ctx.r11.u32 + 544, ctx.r9.u32);
	// stw r9,552(r11)
	REX_STORE_U32(ctx.r11.u32 + 552, ctx.r9.u32);
	// stb r9,556(r11)
	REX_STORE_U8(ctx.r11.u32 + 556, ctx.r9.u8);
	// stb r9,640(r11)
	REX_STORE_U8(ctx.r11.u32 + 640, ctx.r9.u8);
	// sth r10,642(r11)
	REX_STORE_U16(ctx.r11.u32 + 642, ctx.r10.u16);
	// sth r10,644(r11)
	REX_STORE_U16(ctx.r11.u32 + 644, ctx.r10.u16);
	// sth r10,646(r11)
	REX_STORE_U16(ctx.r11.u32 + 646, ctx.r10.u16);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// sth r7,648(r11)
	REX_STORE_U16(ctx.r11.u32 + 648, ctx.r7.u16);
	// stw r9,748(r11)
	REX_STORE_U32(ctx.r11.u32 + 748, ctx.r9.u32);
	// stw r9,752(r11)
	REX_STORE_U32(ctx.r11.u32 + 752, ctx.r9.u32);
	// stw r9,756(r11)
	REX_STORE_U32(ctx.r11.u32 + 756, ctx.r9.u32);
	// stw r9,764(r11)
	REX_STORE_U32(ctx.r11.u32 + 764, ctx.r9.u32);
	// stb r9,768(r11)
	REX_STORE_U8(ctx.r11.u32 + 768, ctx.r9.u8);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8209D00C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
