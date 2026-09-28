DEFINE_REX_FUNC(sub_82084EE0) {
	REX_FUNC_PROLOGUE();
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
loc_82084EF0:
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// stw r5,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82085060
	if (ctx.cr6.eq) goto loc_82085060;
loc_82084F08:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82084f34
	if (ctx.cr6.eq) goto loc_82084F34;
loc_82084F1C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82084f34
	if (ctx.cr6.eq) goto loc_82084F34;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// cmplw cr6,r6,r4
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x82084f1c
	if (ctx.cr6.lt) goto loc_82084F1C;
loc_82084F34:
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82084f5c
	if (ctx.cr6.eq) goto loc_82084F5C;
loc_82084F44:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82084f5c
	if (ctx.cr6.eq) goto loc_82084F5C;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// lwz r8,88(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 88);
	// cmplw cr6,r7,r4
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x82084f44
	if (ctx.cr6.lt) goto loc_82084F44;
loc_82084F5C:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82084fe8
	if (ctx.cr6.eq) goto loc_82084FE8;
loc_82084F64:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82085004
	if (ctx.cr6.eq) goto loc_82085004;
	// lwz r8,28(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// lwz r30,28(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// cmpw cr6,r8,r30
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r30.s32, ctx.xer);
	// bgt cr6,0x82084fb8
	if (ctx.cr6.gt) goto loc_82084FB8;
	// lwz r8,88(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 88);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82084fa0
	if (ctx.cr6.eq) goto loc_82084FA0;
	// stw r10,88(r9)
	REX_STORE_U32(ctx.r9.u32 + 88, ctx.r10.u32);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stw r5,88(r10)
	REX_STORE_U32(ctx.r10.u32 + 88, ctx.r5.u32);
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// b 0x82084fe0
	goto loc_82084FE0;
loc_82084FA0:
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stw r5,88(r10)
	REX_STORE_U32(ctx.r10.u32 + 88, ctx.r5.u32);
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// b 0x82084fe0
	goto loc_82084FE0;
loc_82084FB8:
	// lwz r8,88(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82084fcc
	if (ctx.cr6.eq) goto loc_82084FCC;
	// stw r11,88(r9)
	REX_STORE_U32(ctx.r9.u32 + 88, ctx.r11.u32);
	// b 0x82084fd0
	goto loc_82084FD0;
loc_82084FCC:
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_82084FD0:
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// stw r5,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r5.u32);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_82084FE0:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x82084f64
	if (!ctx.cr6.eq) goto loc_82084F64;
loc_82084FE8:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82085054
	if (ctx.cr6.eq) goto loc_82085054;
loc_82084FF0:
	// lwz r10,88(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8208503c
	if (ctx.cr6.eq) goto loc_8208503C;
	// stw r11,88(r9)
	REX_STORE_U32(ctx.r9.u32 + 88, ctx.r11.u32);
	// b 0x82085040
	goto loc_82085040;
loc_82085004:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82085054
	if (ctx.cr6.eq) goto loc_82085054;
loc_8208500C:
	// lwz r8,88(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 88);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82085020
	if (ctx.cr6.eq) goto loc_82085020;
	// stw r10,88(r9)
	REX_STORE_U32(ctx.r9.u32 + 88, ctx.r10.u32);
	// b 0x82085024
	goto loc_82085024;
loc_82085020:
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_82085024:
	// stw r5,88(r10)
	REX_STORE_U32(ctx.r10.u32 + 88, ctx.r5.u32);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// bne 0x8208500c
	if (!ctx.cr0.eq) goto loc_8208500C;
	// b 0x82085054
	goto loc_82085054;
loc_8208503C:
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_82085040:
	// stw r5,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r5.u32);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// bne 0x82084ff0
	if (!ctx.cr0.eq) goto loc_82084FF0;
loc_82085054:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82084f08
	if (!ctx.cr6.eq) goto loc_82084F08;
loc_82085060:
	// rlwinm r4,r4,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// bgt cr6,0x82084ef0
	if (ctx.cr6.gt) goto loc_82084EF0;
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}
