DEFINE_REX_FUNC(sub_8207AA50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8207AA58;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lbzx r10,r10,r5
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r5.u32);
	// cmplwi cr6,r10,9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 9, ctx.xer);
	// bgt cr6,0x8207ae50
	if (ctx.cr6.gt) goto loc_8207AE50;
	// lis r12,-32248
	ctx.r12.s64 = -2113404928;
	// addi r12,r12,-21864
	ctx.r12.s64 = ctx.r12.s64 + -21864;
	// rlwinm r0,r10,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r10.u32) {
	case 0:
		goto loc_8207AAC0;
	case 1:
		goto loc_8207AB38;
	case 2:
		goto loc_8207AE50;
	case 3:
		goto loc_8207AE14;
	case 4:
		goto loc_8207AE2C;
	case 5:
		goto loc_8207AB0C;
	case 6:
		goto loc_8207ABB8;
	case 7:
		goto loc_8207ACA4;
	case 8:
		goto loc_8207AD3C;
	case 9:
		goto loc_8207ADAC;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8207AAC0:
	// add r4,r11,r5
	ctx.r4.u64 = ctx.r11.u64 + ctx.r5.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82053a00
	ctx.lr = 0x8207AACC;
	sub_82053A00(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r8,156(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r3,10316(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 10316);
	// bl 0x8209d948
	ctx.lr = 0x8207AAF8;
	sub_8209D948(ctx, base);
	// li r7,8
	ctx.r7.s64 = 8;
	// sth r3,4(r30)
	REX_STORE_U16(ctx.r30.u32 + 4, ctx.r3.u16);
	// stw r7,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r7.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207AB0C:
	// lbzx r10,r11,r5
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// stb r5,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r5.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207AB38:
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbzx r7,r11,r5
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lbzx r6,r10,r5
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r5.u32);
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// lbzx r3,r11,r5
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// stw r4,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// lbzx r10,r9,r5
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r5.u32);
	// xor r6,r3,r11
	ctx.r6.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// stw r8,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r8.u32);
	// xor r5,r10,r7
	ctx.r5.u64 = ctx.r10.u64 ^ ctx.r7.u64;
	// clrlwi r4,r6,24
	ctx.r4.u64 = ctx.r6.u32 & 0xFF;
	// clrlwi r3,r5,24
	ctx.r3.u64 = ctx.r5.u32 & 0xFF;
	// xor r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 ^ ctx.r11.u64;
	// xor r10,r3,r7
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r7.u64;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// xor r9,r11,r4
	ctx.r9.u64 = ctx.r11.u64 ^ ctx.r4.u64;
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// xor r8,r10,r3
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r3.u64;
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// stb r9,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r9.u8);
	// stb r8,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r8.u8);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207ABB8:
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbzx r7,r11,r5
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lbzx r3,r10,r5
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r5.u32);
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lbzx r4,r11,r5
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lbzx r6,r9,r5
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r5.u32);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lbzx r29,r10,r5
	ctx.r29.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r5.u32);
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lbzx r11,r11,r5
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// xor r29,r29,r6
	ctx.r29.u64 = ctx.r29.u64 ^ ctx.r6.u64;
	// addi r28,r10,1
	ctx.r28.s64 = ctx.r10.s64 + 1;
	// lbzx r9,r9,r5
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r5.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// clrlwi r31,r29,24
	ctx.r31.u64 = ctx.r29.u32 & 0xFF;
	// lbzx r10,r10,r5
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r5.u32);
	// xor r5,r11,r4
	ctx.r5.u64 = ctx.r11.u64 ^ ctx.r4.u64;
	// stw r8,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r8.u32);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// xor r10,r9,r3
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r3.u64;
	// xor r9,r11,r7
	ctx.r9.u64 = ctx.r11.u64 ^ ctx.r7.u64;
	// clrlwi r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	// clrlwi r29,r10,24
	ctx.r29.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r28,r9,24
	ctx.r28.u64 = ctx.r9.u32 & 0xFF;
	// xor r10,r5,r4
	ctx.r10.u64 = ctx.r5.u64 ^ ctx.r4.u64;
	// xor r11,r31,r6
	ctx.r11.u64 = ctx.r31.u64 ^ ctx.r6.u64;
	// xor r8,r28,r7
	ctx.r8.u64 = ctx.r28.u64 ^ ctx.r7.u64;
	// xor r9,r29,r3
	ctx.r9.u64 = ctx.r29.u64 ^ ctx.r3.u64;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// stb r10,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r10.u8);
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// stb r11,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r11.u8);
	// xor r6,r10,r5
	ctx.r6.u64 = ctx.r10.u64 ^ ctx.r5.u64;
	// stb r9,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r9.u8);
	// xor r7,r11,r31
	ctx.r7.u64 = ctx.r11.u64 ^ ctx.r31.u64;
	// stb r8,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r8.u8);
	// xor r5,r9,r29
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r29.u64;
	// stb r6,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r6.u8);
	// xor r4,r8,r28
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r28.u64;
	// stb r7,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r7.u8);
	// stb r5,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r5.u8);
	// stb r4,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r4.u8);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207ACA4:
	// add r10,r11,r5
	ctx.r10.u64 = ctx.r11.u64 + ctx.r5.u64;
	// lbzx r9,r11,r5
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// rotlwi r7,r9,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// lbz r5,1(r10)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// lbz r4,2(r10)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// or r3,r7,r5
	ctx.r3.u64 = ctx.r7.u64 | ctx.r5.u64;
	// lbz r11,3(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// stw r6,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r6.u32);
	// rlwinm r10,r3,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | ctx.r11.u64;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lbz r11,82(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r8,81(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r10,83(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// xor r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// xor r6,r8,r11
	ctx.r6.u64 = ctx.r8.u64 ^ ctx.r11.u64;
	// clrlwi r5,r7,24
	ctx.r5.u64 = ctx.r7.u32 & 0xFF;
	// clrlwi r4,r6,24
	ctx.r4.u64 = ctx.r6.u32 & 0xFF;
	// xor r3,r5,r10
	ctx.r3.u64 = ctx.r5.u64 ^ ctx.r10.u64;
	// xor r10,r4,r11
	ctx.r10.u64 = ctx.r4.u64 ^ ctx.r11.u64;
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// xor r9,r11,r5
	ctx.r9.u64 = ctx.r11.u64 ^ ctx.r5.u64;
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// xor r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r4.u64;
	// stb r10,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r10.u8);
	// stb r9,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r9.u8);
	// stb r8,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r8.u8);
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r5,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r5.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207AD3C:
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// lbzx r10,r11,r5
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// rlwinm r10,r10,1,23,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1FE;
	// lwz r7,76(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 76);
	// li r9,8
	ctx.r9.s64 = 8;
	// lwz r6,156(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 156);
	// lwz r11,10180(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 10180);
	// addi r5,r11,2513
	ctx.r5.s64 = ctx.r11.s64 + 2513;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r4,r6
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207ad90
	if (ctx.cr6.eq) goto loc_8207AD90;
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lhzx r7,r8,r10
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r10.u32);
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// sth r7,4(r30)
	REX_STORE_U16(ctx.r30.u32 + 4, ctx.r7.u16);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207AD90:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lhzx r7,r10,r8
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r8.u32);
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// sth r7,4(r30)
	REX_STORE_U16(ctx.r30.u32 + 4, ctx.r7.u16);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207ADAC:
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// add r9,r11,r5
	ctx.r9.u64 = ctx.r11.u64 + ctx.r5.u64;
	// lbzx r8,r11,r5
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// stw r7,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// lwz r6,76(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// lbz r5,1(r9)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// rotlwi r4,r5,8
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// lwz r3,156(r6)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + 156);
	// or r11,r4,r8
	ctx.r11.u64 = ctx.r4.u64 | ctx.r8.u64;
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// rlwinm r10,r10,1,15,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1FFFE;
	// lwz r11,10180(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10180);
	// addi r9,r11,2513
	ctx.r9.s64 = ctx.r11.s64 + 2513;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,8
	ctx.r9.s64 = 8;
	// lwzx r11,r8,r3
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207ad90
	if (ctx.cr6.eq) goto loc_8207AD90;
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lhzx r7,r8,r10
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r10.u32);
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// sth r7,4(r30)
	REX_STORE_U16(ctx.r30.u32 + 4, ctx.r7.u16);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207AE14:
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// stw r10,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207AE2C:
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lwz r7,76(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r6,156(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 156);
	// lwz r5,30476(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 30476);
	// stw r8,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r8.u32);
	// stw r5,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r5.u32);
loc_8207AE50:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
