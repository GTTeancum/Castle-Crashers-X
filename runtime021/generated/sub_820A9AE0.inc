DEFINE_REX_FUNC(sub_820A9AE0) {
	REX_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// ble cr6,0x820a9af8
	if (!ctx.cr6.gt) goto loc_820A9AF8;
loc_820A9AEC:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x820a9aec
	if (ctx.cr6.lt) goto loc_820A9AEC;
loc_820A9AF8:
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r5,1
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1, ctx.xer);
	// ble cr6,0x820a9b14
	if (!ctx.cr6.gt) goto loc_820A9B14;
loc_820A9B08:
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r10,r5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x820a9b08
	if (ctx.cr6.lt) goto loc_820A9B08;
loc_820A9B14:
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bge cr6,0x820a9b20
	if (!ctx.cr6.lt) goto loc_820A9B20;
	// li r9,64
	ctx.r9.s64 = 64;
loc_820A9B20:
	// cmpwi cr6,r10,64
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 64, ctx.xer);
	// bge cr6,0x820a9b2c
	if (!ctx.cr6.lt) goto loc_820A9B2C;
	// li r10,64
	ctx.r10.s64 = 64;
loc_820A9B2C:
	// cmpwi cr6,r9,512
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 512, ctx.xer);
	// ble cr6,0x820a9b38
	if (!ctx.cr6.gt) goto loc_820A9B38;
	// li r9,512
	ctx.r9.s64 = 512;
loc_820A9B38:
	// cmpwi cr6,r10,512
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 512, ctx.xer);
	// stw r9,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r9.u32);
	// ble cr6,0x820a9b50
	if (!ctx.cr6.gt) goto loc_820A9B50;
	// li r11,512
	ctx.r11.s64 = 512;
	// stw r11,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// blr 
	return;
loc_820A9B50:
	// stw r10,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}
