DEFINE_REX_FUNC(sub_820A7668) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r7,r10,18248
	ctx.r7.s64 = ctx.r10.s64 + 18248;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r11,0
	ctx.r11.s64 = 0;
	// lfs f13,18248(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 18248);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r6,8264
	ctx.r5.s64 = ctx.r6.s64 + 8264;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r5,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lfs f0,9540(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,24(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stw r11,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stw r11,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// lfs f12,-1988(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -1988);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,28728(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 28728, temp.u32);
	// stb r11,28712(r3)
	REX_STORE_U8(ctx.r3.u32 + 28712, ctx.r11.u8);
	// stb r11,28713(r3)
	REX_STORE_U8(ctx.r3.u32 + 28713, ctx.r11.u8);
	// lfs f11,-1860(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -1860);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,28732(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 28732, temp.u32);
	// stb r11,28714(r3)
	REX_STORE_U8(ctx.r3.u32 + 28714, ctx.r11.u8);
	// stb r11,28715(r3)
	REX_STORE_U8(ctx.r3.u32 + 28715, ctx.r11.u8);
	// stw r11,28716(r3)
	REX_STORE_U32(ctx.r3.u32 + 28716, ctx.r11.u32);
	// stfs f0,29176(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 29176, temp.u32);
	// stfs f13,29184(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 29184, temp.u32);
	// stw r9,29128(r3)
	REX_STORE_U32(ctx.r3.u32 + 29128, ctx.r9.u32);
	// stw r11,29132(r3)
	REX_STORE_U32(ctx.r3.u32 + 29132, ctx.r11.u32);
	// stw r10,29136(r3)
	REX_STORE_U32(ctx.r3.u32 + 29136, ctx.r10.u32);
	// stw r10,29160(r3)
	REX_STORE_U32(ctx.r3.u32 + 29160, ctx.r10.u32);
	// stw r10,29140(r3)
	REX_STORE_U32(ctx.r3.u32 + 29140, ctx.r10.u32);
	// stw r11,29144(r3)
	REX_STORE_U32(ctx.r3.u32 + 29144, ctx.r11.u32);
	// stw r11,29148(r3)
	REX_STORE_U32(ctx.r3.u32 + 29148, ctx.r11.u32);
	// stw r11,29152(r3)
	REX_STORE_U32(ctx.r3.u32 + 29152, ctx.r11.u32);
	// stw r11,29156(r3)
	REX_STORE_U32(ctx.r3.u32 + 29156, ctx.r11.u32);
	// stw r10,29164(r3)
	REX_STORE_U32(ctx.r3.u32 + 29164, ctx.r10.u32);
	// stw r10,29168(r3)
	REX_STORE_U32(ctx.r3.u32 + 29168, ctx.r10.u32);
	// stw r10,29172(r3)
	REX_STORE_U32(ctx.r3.u32 + 29172, ctx.r10.u32);
	// stb r11,29180(r3)
	REX_STORE_U8(ctx.r3.u32 + 29180, ctx.r11.u8);
	// stb r11,29188(r3)
	REX_STORE_U8(ctx.r3.u32 + 29188, ctx.r11.u8);
	// stfs f0,29240(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 29240, temp.u32);
	// stfs f13,29248(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 29248, temp.u32);
	// stw r9,29192(r3)
	REX_STORE_U32(ctx.r3.u32 + 29192, ctx.r9.u32);
	// stfs f0,29304(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 29304, temp.u32);
	// stw r11,29196(r3)
	REX_STORE_U32(ctx.r3.u32 + 29196, ctx.r11.u32);
	// stfs f13,29312(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 29312, temp.u32);
	// stw r10,29200(r3)
	REX_STORE_U32(ctx.r3.u32 + 29200, ctx.r10.u32);
	// stfs f0,29368(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 29368, temp.u32);
	// stw r10,29224(r3)
	REX_STORE_U32(ctx.r3.u32 + 29224, ctx.r10.u32);
	// stfs f13,29376(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 29376, temp.u32);
	// stw r10,29204(r3)
	REX_STORE_U32(ctx.r3.u32 + 29204, ctx.r10.u32);
	// stw r11,29208(r3)
	REX_STORE_U32(ctx.r3.u32 + 29208, ctx.r11.u32);
	// stw r11,29212(r3)
	REX_STORE_U32(ctx.r3.u32 + 29212, ctx.r11.u32);
	// stw r11,29216(r3)
	REX_STORE_U32(ctx.r3.u32 + 29216, ctx.r11.u32);
	// stw r11,29220(r3)
	REX_STORE_U32(ctx.r3.u32 + 29220, ctx.r11.u32);
	// stw r10,29228(r3)
	REX_STORE_U32(ctx.r3.u32 + 29228, ctx.r10.u32);
	// stw r10,29232(r3)
	REX_STORE_U32(ctx.r3.u32 + 29232, ctx.r10.u32);
	// stw r10,29236(r3)
	REX_STORE_U32(ctx.r3.u32 + 29236, ctx.r10.u32);
	// stb r11,29244(r3)
	REX_STORE_U8(ctx.r3.u32 + 29244, ctx.r11.u8);
	// stb r11,29252(r3)
	REX_STORE_U8(ctx.r3.u32 + 29252, ctx.r11.u8);
	// stw r9,29256(r3)
	REX_STORE_U32(ctx.r3.u32 + 29256, ctx.r9.u32);
	// stw r11,29260(r3)
	REX_STORE_U32(ctx.r3.u32 + 29260, ctx.r11.u32);
	// stw r10,29264(r3)
	REX_STORE_U32(ctx.r3.u32 + 29264, ctx.r10.u32);
	// stw r10,29288(r3)
	REX_STORE_U32(ctx.r3.u32 + 29288, ctx.r10.u32);
	// stw r10,29268(r3)
	REX_STORE_U32(ctx.r3.u32 + 29268, ctx.r10.u32);
	// stw r11,29272(r3)
	REX_STORE_U32(ctx.r3.u32 + 29272, ctx.r11.u32);
	// stw r11,29276(r3)
	REX_STORE_U32(ctx.r3.u32 + 29276, ctx.r11.u32);
	// stw r11,29280(r3)
	REX_STORE_U32(ctx.r3.u32 + 29280, ctx.r11.u32);
	// stw r11,29284(r3)
	REX_STORE_U32(ctx.r3.u32 + 29284, ctx.r11.u32);
	// stw r10,29292(r3)
	REX_STORE_U32(ctx.r3.u32 + 29292, ctx.r10.u32);
	// stw r10,29296(r3)
	REX_STORE_U32(ctx.r3.u32 + 29296, ctx.r10.u32);
	// stw r10,29300(r3)
	REX_STORE_U32(ctx.r3.u32 + 29300, ctx.r10.u32);
	// stb r11,29308(r3)
	REX_STORE_U8(ctx.r3.u32 + 29308, ctx.r11.u8);
	// stb r11,29316(r3)
	REX_STORE_U8(ctx.r3.u32 + 29316, ctx.r11.u8);
	// stw r9,29320(r3)
	REX_STORE_U32(ctx.r3.u32 + 29320, ctx.r9.u32);
	// stw r11,29324(r3)
	REX_STORE_U32(ctx.r3.u32 + 29324, ctx.r11.u32);
	// stw r10,29328(r3)
	REX_STORE_U32(ctx.r3.u32 + 29328, ctx.r10.u32);
	// stw r10,29352(r3)
	REX_STORE_U32(ctx.r3.u32 + 29352, ctx.r10.u32);
	// stw r10,29332(r3)
	REX_STORE_U32(ctx.r3.u32 + 29332, ctx.r10.u32);
	// stw r11,29336(r3)
	REX_STORE_U32(ctx.r3.u32 + 29336, ctx.r11.u32);
	// stfs f0,29432(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 29432, temp.u32);
	// stw r11,29340(r3)
	REX_STORE_U32(ctx.r3.u32 + 29340, ctx.r11.u32);
	// stfs f13,29440(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 29440, temp.u32);
	// stw r11,29344(r3)
	REX_STORE_U32(ctx.r3.u32 + 29344, ctx.r11.u32);
	// stfs f0,29496(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 29496, temp.u32);
	// stw r11,29348(r3)
	REX_STORE_U32(ctx.r3.u32 + 29348, ctx.r11.u32);
	// stfs f13,29504(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 29504, temp.u32);
	// stw r10,29356(r3)
	REX_STORE_U32(ctx.r3.u32 + 29356, ctx.r10.u32);
	// stfs f0,29560(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 29560, temp.u32);
	// stw r10,29360(r3)
	REX_STORE_U32(ctx.r3.u32 + 29360, ctx.r10.u32);
	// stfs f13,29568(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 29568, temp.u32);
	// stw r10,29364(r3)
	REX_STORE_U32(ctx.r3.u32 + 29364, ctx.r10.u32);
	// stfs f0,29624(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 29624, temp.u32);
	// stb r11,29372(r3)
	REX_STORE_U8(ctx.r3.u32 + 29372, ctx.r11.u8);
	// stfs f13,29632(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 29632, temp.u32);
	// stb r11,29380(r3)
	REX_STORE_U8(ctx.r3.u32 + 29380, ctx.r11.u8);
	// stfs f0,29688(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 29688, temp.u32);
	// stw r9,29384(r3)
	REX_STORE_U32(ctx.r3.u32 + 29384, ctx.r9.u32);
	// stfs f13,29696(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 29696, temp.u32);
	// stw r11,29388(r3)
	REX_STORE_U32(ctx.r3.u32 + 29388, ctx.r11.u32);
	// stfs f0,29752(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 29752, temp.u32);
	// stw r10,29392(r3)
	REX_STORE_U32(ctx.r3.u32 + 29392, ctx.r10.u32);
	// stfs f13,29760(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 29760, temp.u32);
	// stw r10,29416(r3)
	REX_STORE_U32(ctx.r3.u32 + 29416, ctx.r10.u32);
	// stw r10,29396(r3)
	REX_STORE_U32(ctx.r3.u32 + 29396, ctx.r10.u32);
	// stw r11,29400(r3)
	REX_STORE_U32(ctx.r3.u32 + 29400, ctx.r11.u32);
	// stw r11,29404(r3)
	REX_STORE_U32(ctx.r3.u32 + 29404, ctx.r11.u32);
	// stw r11,29408(r3)
	REX_STORE_U32(ctx.r3.u32 + 29408, ctx.r11.u32);
	// stw r11,29412(r3)
	REX_STORE_U32(ctx.r3.u32 + 29412, ctx.r11.u32);
	// stw r10,29420(r3)
	REX_STORE_U32(ctx.r3.u32 + 29420, ctx.r10.u32);
	// stw r10,29424(r3)
	REX_STORE_U32(ctx.r3.u32 + 29424, ctx.r10.u32);
	// stw r10,29428(r3)
	REX_STORE_U32(ctx.r3.u32 + 29428, ctx.r10.u32);
	// stb r11,29436(r3)
	REX_STORE_U8(ctx.r3.u32 + 29436, ctx.r11.u8);
	// stb r11,29444(r3)
	REX_STORE_U8(ctx.r3.u32 + 29444, ctx.r11.u8);
	// stw r9,29448(r3)
	REX_STORE_U32(ctx.r3.u32 + 29448, ctx.r9.u32);
	// stw r11,29452(r3)
	REX_STORE_U32(ctx.r3.u32 + 29452, ctx.r11.u32);
	// stw r10,29456(r3)
	REX_STORE_U32(ctx.r3.u32 + 29456, ctx.r10.u32);
	// stw r10,29480(r3)
	REX_STORE_U32(ctx.r3.u32 + 29480, ctx.r10.u32);
	// stw r10,29460(r3)
	REX_STORE_U32(ctx.r3.u32 + 29460, ctx.r10.u32);
	// stw r11,29464(r3)
	REX_STORE_U32(ctx.r3.u32 + 29464, ctx.r11.u32);
	// stw r11,29468(r3)
	REX_STORE_U32(ctx.r3.u32 + 29468, ctx.r11.u32);
	// stw r11,29472(r3)
	REX_STORE_U32(ctx.r3.u32 + 29472, ctx.r11.u32);
	// stw r11,29476(r3)
	REX_STORE_U32(ctx.r3.u32 + 29476, ctx.r11.u32);
	// stw r10,29484(r3)
	REX_STORE_U32(ctx.r3.u32 + 29484, ctx.r10.u32);
	// stw r10,29488(r3)
	REX_STORE_U32(ctx.r3.u32 + 29488, ctx.r10.u32);
	// stw r10,29492(r3)
	REX_STORE_U32(ctx.r3.u32 + 29492, ctx.r10.u32);
	// stb r11,29500(r3)
	REX_STORE_U8(ctx.r3.u32 + 29500, ctx.r11.u8);
	// stb r11,29508(r3)
	REX_STORE_U8(ctx.r3.u32 + 29508, ctx.r11.u8);
	// stw r9,29512(r3)
	REX_STORE_U32(ctx.r3.u32 + 29512, ctx.r9.u32);
	// stw r11,29516(r3)
	REX_STORE_U32(ctx.r3.u32 + 29516, ctx.r11.u32);
	// stw r10,29520(r3)
	REX_STORE_U32(ctx.r3.u32 + 29520, ctx.r10.u32);
	// stw r10,29544(r3)
	REX_STORE_U32(ctx.r3.u32 + 29544, ctx.r10.u32);
	// stw r10,29524(r3)
	REX_STORE_U32(ctx.r3.u32 + 29524, ctx.r10.u32);
	// stw r11,29528(r3)
	REX_STORE_U32(ctx.r3.u32 + 29528, ctx.r11.u32);
	// stw r11,29532(r3)
	REX_STORE_U32(ctx.r3.u32 + 29532, ctx.r11.u32);
	// stw r11,29536(r3)
	REX_STORE_U32(ctx.r3.u32 + 29536, ctx.r11.u32);
	// stw r11,29540(r3)
	REX_STORE_U32(ctx.r3.u32 + 29540, ctx.r11.u32);
	// stw r10,29548(r3)
	REX_STORE_U32(ctx.r3.u32 + 29548, ctx.r10.u32);
	// stw r10,29552(r3)
	REX_STORE_U32(ctx.r3.u32 + 29552, ctx.r10.u32);
	// stw r10,29556(r3)
	REX_STORE_U32(ctx.r3.u32 + 29556, ctx.r10.u32);
	// stb r11,29564(r3)
	REX_STORE_U8(ctx.r3.u32 + 29564, ctx.r11.u8);
	// stb r11,29572(r3)
	REX_STORE_U8(ctx.r3.u32 + 29572, ctx.r11.u8);
	// stw r9,29576(r3)
	REX_STORE_U32(ctx.r3.u32 + 29576, ctx.r9.u32);
	// stw r11,29580(r3)
	REX_STORE_U32(ctx.r3.u32 + 29580, ctx.r11.u32);
	// stw r10,29584(r3)
	REX_STORE_U32(ctx.r3.u32 + 29584, ctx.r10.u32);
	// stw r10,29608(r3)
	REX_STORE_U32(ctx.r3.u32 + 29608, ctx.r10.u32);
	// stw r10,29588(r3)
	REX_STORE_U32(ctx.r3.u32 + 29588, ctx.r10.u32);
	// stw r11,29592(r3)
	REX_STORE_U32(ctx.r3.u32 + 29592, ctx.r11.u32);
	// stw r11,29596(r3)
	REX_STORE_U32(ctx.r3.u32 + 29596, ctx.r11.u32);
	// stw r11,29600(r3)
	REX_STORE_U32(ctx.r3.u32 + 29600, ctx.r11.u32);
	// stw r11,29604(r3)
	REX_STORE_U32(ctx.r3.u32 + 29604, ctx.r11.u32);
	// stw r10,29612(r3)
	REX_STORE_U32(ctx.r3.u32 + 29612, ctx.r10.u32);
	// stw r10,29616(r3)
	REX_STORE_U32(ctx.r3.u32 + 29616, ctx.r10.u32);
	// stw r10,29620(r3)
	REX_STORE_U32(ctx.r3.u32 + 29620, ctx.r10.u32);
	// stb r11,29628(r3)
	REX_STORE_U8(ctx.r3.u32 + 29628, ctx.r11.u8);
	// stb r11,29636(r3)
	REX_STORE_U8(ctx.r3.u32 + 29636, ctx.r11.u8);
	// stw r9,29640(r3)
	REX_STORE_U32(ctx.r3.u32 + 29640, ctx.r9.u32);
	// stw r11,29644(r3)
	REX_STORE_U32(ctx.r3.u32 + 29644, ctx.r11.u32);
	// stw r10,29648(r3)
	REX_STORE_U32(ctx.r3.u32 + 29648, ctx.r10.u32);
	// stw r10,29672(r3)
	REX_STORE_U32(ctx.r3.u32 + 29672, ctx.r10.u32);
	// stw r10,29652(r3)
	REX_STORE_U32(ctx.r3.u32 + 29652, ctx.r10.u32);
	// stfs f0,29816(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 29816, temp.u32);
	// stw r11,29656(r3)
	REX_STORE_U32(ctx.r3.u32 + 29656, ctx.r11.u32);
	// stfs f13,29824(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 29824, temp.u32);
	// stw r11,29660(r3)
	REX_STORE_U32(ctx.r3.u32 + 29660, ctx.r11.u32);
	// stw r11,29664(r3)
	REX_STORE_U32(ctx.r3.u32 + 29664, ctx.r11.u32);
	// stw r11,29668(r3)
	REX_STORE_U32(ctx.r3.u32 + 29668, ctx.r11.u32);
	// stw r10,29676(r3)
	REX_STORE_U32(ctx.r3.u32 + 29676, ctx.r10.u32);
	// stw r10,29680(r3)
	REX_STORE_U32(ctx.r3.u32 + 29680, ctx.r10.u32);
	// stw r10,29684(r3)
	REX_STORE_U32(ctx.r3.u32 + 29684, ctx.r10.u32);
	// stb r11,29692(r3)
	REX_STORE_U8(ctx.r3.u32 + 29692, ctx.r11.u8);
	// stb r11,29700(r3)
	REX_STORE_U8(ctx.r3.u32 + 29700, ctx.r11.u8);
	// stw r9,29704(r3)
	REX_STORE_U32(ctx.r3.u32 + 29704, ctx.r9.u32);
	// stw r11,29708(r3)
	REX_STORE_U32(ctx.r3.u32 + 29708, ctx.r11.u32);
	// stw r10,29712(r3)
	REX_STORE_U32(ctx.r3.u32 + 29712, ctx.r10.u32);
	// stw r10,29736(r3)
	REX_STORE_U32(ctx.r3.u32 + 29736, ctx.r10.u32);
	// stw r10,29716(r3)
	REX_STORE_U32(ctx.r3.u32 + 29716, ctx.r10.u32);
	// stw r11,29720(r3)
	REX_STORE_U32(ctx.r3.u32 + 29720, ctx.r11.u32);
	// stw r11,29724(r3)
	REX_STORE_U32(ctx.r3.u32 + 29724, ctx.r11.u32);
	// stw r11,29728(r3)
	REX_STORE_U32(ctx.r3.u32 + 29728, ctx.r11.u32);
	// stw r11,29732(r3)
	REX_STORE_U32(ctx.r3.u32 + 29732, ctx.r11.u32);
	// stw r10,29740(r3)
	REX_STORE_U32(ctx.r3.u32 + 29740, ctx.r10.u32);
	// stw r10,29744(r3)
	REX_STORE_U32(ctx.r3.u32 + 29744, ctx.r10.u32);
	// stw r10,29748(r3)
	REX_STORE_U32(ctx.r3.u32 + 29748, ctx.r10.u32);
	// stb r11,29756(r3)
	REX_STORE_U8(ctx.r3.u32 + 29756, ctx.r11.u8);
	// stb r11,29764(r3)
	REX_STORE_U8(ctx.r3.u32 + 29764, ctx.r11.u8);
	// stw r9,29768(r3)
	REX_STORE_U32(ctx.r3.u32 + 29768, ctx.r9.u32);
	// stw r11,29772(r3)
	REX_STORE_U32(ctx.r3.u32 + 29772, ctx.r11.u32);
	// stw r10,29776(r3)
	REX_STORE_U32(ctx.r3.u32 + 29776, ctx.r10.u32);
	// stw r10,29800(r3)
	REX_STORE_U32(ctx.r3.u32 + 29800, ctx.r10.u32);
	// stw r10,29780(r3)
	REX_STORE_U32(ctx.r3.u32 + 29780, ctx.r10.u32);
	// stw r11,29784(r3)
	REX_STORE_U32(ctx.r3.u32 + 29784, ctx.r11.u32);
	// stw r11,29788(r3)
	REX_STORE_U32(ctx.r3.u32 + 29788, ctx.r11.u32);
	// stw r11,29792(r3)
	REX_STORE_U32(ctx.r3.u32 + 29792, ctx.r11.u32);
	// stw r11,29796(r3)
	REX_STORE_U32(ctx.r3.u32 + 29796, ctx.r11.u32);
	// stw r10,29804(r3)
	REX_STORE_U32(ctx.r3.u32 + 29804, ctx.r10.u32);
	// stw r10,29808(r3)
	REX_STORE_U32(ctx.r3.u32 + 29808, ctx.r10.u32);
	// stw r10,29812(r3)
	REX_STORE_U32(ctx.r3.u32 + 29812, ctx.r10.u32);
	// stb r11,29820(r3)
	REX_STORE_U8(ctx.r3.u32 + 29820, ctx.r11.u8);
	// stb r11,29828(r3)
	REX_STORE_U8(ctx.r3.u32 + 29828, ctx.r11.u8);
	// blr 
	return;
}
