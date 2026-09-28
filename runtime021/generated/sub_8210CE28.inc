DEFINE_REX_FUNC(sub_8210CE28) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8210CE30;
	__savegprlr_29(ctx, base);
	// lwz r10,12(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r9,168(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 168);
	// rlwinm. r8,r9,0,2,2
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8210ce50
	if (!ctx.cr0.eq) goto loc_8210CE50;
	// lwz r8,152(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8210ce5c
	if (!ctx.cr6.eq) goto loc_8210CE5C;
loc_8210CE50:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4106
	ctx.r3.u64 = ctx.r3.u64 | 4106;
	// b 0x8210cf0c
	goto loc_8210CF0C;
loc_8210CE5C:
	// lwz r8,144(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8210cf04
	if (ctx.cr6.eq) goto loc_8210CF04;
	// rlwinm. r9,r9,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8210cf04
	if (!ctx.cr0.eq) goto loc_8210CF04;
	// lwz r9,16(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// li r8,40
	ctx.r8.s64 = 40;
	// lwz r7,60(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// li r6,2
	ctx.r6.s64 = 2;
	// clrlwi r3,r9,8
	ctx.r3.u64 = ctx.r9.u32 & 0xFFFFFF;
	// lwz r31,136(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// rlwinm r9,r9,19,14,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 19) & 0x3F800;
	// lwz r30,132(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// lwz r29,172(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// rlwinm r7,r7,25,0,6
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0xFE000000;
	// or r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 | ctx.r3.u64;
	// stw r8,740(r11)
	REX_STORE_U32(ctx.r11.u32 + 740, ctx.r8.u32);
	// rlwinm r8,r29,18,0,13
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 18) & 0xFFFC0000;
	// stw r6,744(r11)
	REX_STORE_U32(ctx.r11.u32 + 744, ctx.r6.u32);
	// or r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 | ctx.r9.u64;
	// stw r31,748(r11)
	REX_STORE_U32(ctx.r11.u32 + 748, ctx.r31.u32);
	// stw r30,752(r11)
	REX_STORE_U32(ctx.r11.u32 + 752, ctx.r30.u32);
	// addi r9,r11,740
	ctx.r9.s64 = ctx.r11.s64 + 740;
	// lwz r6,60(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stw r6,756(r11)
	REX_STORE_U32(ctx.r11.u32 + 756, ctx.r6.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,72(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 72);
	// stw r10,760(r11)
	REX_STORE_U32(ctx.r11.u32 + 760, ctx.r10.u32);
	// stw r8,764(r11)
	REX_STORE_U32(ctx.r11.u32 + 764, ctx.r8.u32);
	// lwz r10,20(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// stw r10,768(r11)
	REX_STORE_U32(ctx.r11.u32 + 768, ctx.r10.u32);
	// lwz r10,24(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// stw r10,772(r11)
	REX_STORE_U32(ctx.r11.u32 + 772, ctx.r10.u32);
	// lwz r10,28(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 28);
	// stw r10,776(r11)
	REX_STORE_U32(ctx.r11.u32 + 776, ctx.r10.u32);
	// stw r9,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// lwz r10,820(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 820);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r4,808(r11)
	REX_STORE_U32(ctx.r11.u32 + 808, ctx.r4.u32);
	// stw r10,820(r11)
	REX_STORE_U32(ctx.r11.u32 + 820, ctx.r10.u32);
	// b 0x8210cf0c
	goto loc_8210CF0C;
loc_8210CF04:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4098
	ctx.r3.u64 = ctx.r3.u64 | 4098;
loc_8210CF0C:
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
