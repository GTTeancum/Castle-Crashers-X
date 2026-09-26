DEFINE_REX_FUNC(sub_820C2E60) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r3,44
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 44, ctx.xer);
	// bgt cr6,0x820c2eb8
	if (ctx.cr6.gt) goto loc_820C2EB8;
	// beq cr6,0x820c2eb0
	if (ctx.cr6.eq) goto loc_820C2EB0;
	// cmplwi cr6,r3,11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 11, ctx.xer);
	// blt cr6,0x820c2ee0
	if (ctx.cr6.lt) goto loc_820C2EE0;
	// cmplwi cr6,r3,12
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 12, ctx.xer);
	// ble cr6,0x820c2e9c
	if (!ctx.cr6.gt) goto loc_820C2E9C;
	// cmplwi cr6,r3,17
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 17, ctx.xer);
	// ble cr6,0x820c2ee0
	if (!ctx.cr6.gt) goto loc_820C2EE0;
	// cmplwi cr6,r3,20
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 20, ctx.xer);
	// ble cr6,0x820c2ee8
	if (!ctx.cr6.gt) goto loc_820C2EE8;
	// cmplwi cr6,r3,39
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 39, ctx.xer);
	// beq cr6,0x820c2eb0
	if (ctx.cr6.eq) goto loc_820C2EB0;
	// cmplwi cr6,r3,40
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 40, ctx.xer);
	// bne cr6,0x820c2ee0
	if (!ctx.cr6.eq) goto loc_820C2EE0;
loc_820C2E9C:
	// li r11,2
	ctx.r11.s64 = 2;
loc_820C2EA0:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r10,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// blr 
	return;
loc_820C2EB0:
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x820c2ea0
	goto loc_820C2EA0;
loc_820C2EB8:
	// cmplwi cr6,r3,49
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 49, ctx.xer);
	// beq cr6,0x820c2ee8
	if (ctx.cr6.eq) goto loc_820C2EE8;
	// cmplwi cr6,r3,50
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 50, ctx.xer);
	// ble cr6,0x820c2ee0
	if (!ctx.cr6.gt) goto loc_820C2EE0;
	// cmplwi cr6,r3,53
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 53, ctx.xer);
	// ble cr6,0x820c2ee8
	if (!ctx.cr6.gt) goto loc_820C2EE8;
	// cmplwi cr6,r3,57
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 57, ctx.xer);
	// ble cr6,0x820c2ee0
	if (!ctx.cr6.gt) goto loc_820C2EE0;
	// cmplwi cr6,r3,61
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 61, ctx.xer);
	// ble cr6,0x820c2ee8
	if (!ctx.cr6.gt) goto loc_820C2EE8;
loc_820C2EE0:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820c2eec
	goto loc_820C2EEC;
loc_820C2EE8:
	// li r11,4
	ctx.r11.s64 = 4;
loc_820C2EEC:
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}
