DEFINE_REX_FUNC(sub_8206FDB8) {
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
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,177
	ctx.r4.s64 = 177;
	// addi r5,r11,-9928
	ctx.r5.s64 = ctx.r11.s64 + -9928;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8209d840
	ctx.lr = 0x8206FDDC;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,178
	ctx.r4.s64 = 178;
	// addi r5,r10,-9904
	ctx.r5.s64 = ctx.r10.s64 + -9904;
	// bl 0x8209d840
	ctx.lr = 0x8206FDEC;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,179
	ctx.r4.s64 = 179;
	// addi r5,r9,-9880
	ctx.r5.s64 = ctx.r9.s64 + -9880;
	// bl 0x8209d840
	ctx.lr = 0x8206FDFC;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,180
	ctx.r4.s64 = 180;
	// addi r5,r8,-9856
	ctx.r5.s64 = ctx.r8.s64 + -9856;
	// bl 0x8209d840
	ctx.lr = 0x8206FE0C;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,181
	ctx.r4.s64 = 181;
	// addi r5,r7,-9840
	ctx.r5.s64 = ctx.r7.s64 + -9840;
	// bl 0x8209d840
	ctx.lr = 0x8206FE1C;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,182
	ctx.r4.s64 = 182;
	// addi r5,r6,-9824
	ctx.r5.s64 = ctx.r6.s64 + -9824;
	// bl 0x8209d840
	ctx.lr = 0x8206FE2C;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,183
	ctx.r4.s64 = 183;
	// addi r5,r5,-9800
	ctx.r5.s64 = ctx.r5.s64 + -9800;
	// bl 0x8209d840
	ctx.lr = 0x8206FE3C;
	sub_8209D840(ctx, base);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// addi r5,r4,-9788
	ctx.r5.s64 = ctx.r4.s64 + -9788;
	// li r4,184
	ctx.r4.s64 = 184;
	// bl 0x8209d840
	ctx.lr = 0x8206FE4C;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,185
	ctx.r4.s64 = 185;
	// addi r5,r11,-9776
	ctx.r5.s64 = ctx.r11.s64 + -9776;
	// bl 0x8209d840
	ctx.lr = 0x8206FE5C;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,186
	ctx.r4.s64 = 186;
	// addi r5,r10,-9764
	ctx.r5.s64 = ctx.r10.s64 + -9764;
	// bl 0x8209d840
	ctx.lr = 0x8206FE6C;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,188
	ctx.r4.s64 = 188;
	// addi r5,r9,-9752
	ctx.r5.s64 = ctx.r9.s64 + -9752;
	// bl 0x8209d840
	ctx.lr = 0x8206FE7C;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,189
	ctx.r4.s64 = 189;
	// addi r5,r8,-9736
	ctx.r5.s64 = ctx.r8.s64 + -9736;
	// bl 0x8209d840
	ctx.lr = 0x8206FE8C;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,190
	ctx.r4.s64 = 190;
	// addi r5,r7,-9720
	ctx.r5.s64 = ctx.r7.s64 + -9720;
	// bl 0x8209d840
	ctx.lr = 0x8206FE9C;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,191
	ctx.r4.s64 = 191;
	// addi r5,r6,-9704
	ctx.r5.s64 = ctx.r6.s64 + -9704;
	// bl 0x8209d840
	ctx.lr = 0x8206FEAC;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,192
	ctx.r4.s64 = 192;
	// addi r5,r5,-9688
	ctx.r5.s64 = ctx.r5.s64 + -9688;
	// bl 0x8209d840
	ctx.lr = 0x8206FEBC;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,193
	ctx.r4.s64 = 193;
	// addi r5,r3,-9672
	ctx.r5.s64 = ctx.r3.s64 + -9672;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209d840
	ctx.lr = 0x8206FED0;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,194
	ctx.r4.s64 = 194;
	// addi r5,r11,-9656
	ctx.r5.s64 = ctx.r11.s64 + -9656;
	// bl 0x8209d840
	ctx.lr = 0x8206FEE0;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,195
	ctx.r4.s64 = 195;
	// addi r5,r10,-9640
	ctx.r5.s64 = ctx.r10.s64 + -9640;
	// bl 0x8209d840
	ctx.lr = 0x8206FEF0;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,196
	ctx.r4.s64 = 196;
	// addi r5,r9,-9624
	ctx.r5.s64 = ctx.r9.s64 + -9624;
	// bl 0x8209d840
	ctx.lr = 0x8206FF00;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,197
	ctx.r4.s64 = 197;
	// addi r5,r8,-9612
	ctx.r5.s64 = ctx.r8.s64 + -9612;
	// bl 0x8209d840
	ctx.lr = 0x8206FF10;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,198
	ctx.r4.s64 = 198;
	// addi r5,r7,-9600
	ctx.r5.s64 = ctx.r7.s64 + -9600;
	// bl 0x8209d840
	ctx.lr = 0x8206FF20;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,199
	ctx.r4.s64 = 199;
	// addi r5,r6,-9588
	ctx.r5.s64 = ctx.r6.s64 + -9588;
	// bl 0x8209d840
	ctx.lr = 0x8206FF30;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,200
	ctx.r4.s64 = 200;
	// addi r5,r5,-9576
	ctx.r5.s64 = ctx.r5.s64 + -9576;
	// bl 0x8209d840
	ctx.lr = 0x8206FF40;
	sub_8209D840(ctx, base);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// addi r5,r4,-9560
	ctx.r5.s64 = ctx.r4.s64 + -9560;
	// li r4,201
	ctx.r4.s64 = 201;
	// bl 0x8209d840
	ctx.lr = 0x8206FF50;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,202
	ctx.r4.s64 = 202;
	// addi r5,r11,-9544
	ctx.r5.s64 = ctx.r11.s64 + -9544;
	// bl 0x8209d840
	ctx.lr = 0x8206FF60;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,203
	ctx.r4.s64 = 203;
	// addi r5,r10,-9528
	ctx.r5.s64 = ctx.r10.s64 + -9528;
	// bl 0x8209d840
	ctx.lr = 0x8206FF70;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,204
	ctx.r4.s64 = 204;
	// addi r5,r9,-9512
	ctx.r5.s64 = ctx.r9.s64 + -9512;
	// bl 0x8209d840
	ctx.lr = 0x8206FF80;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,205
	ctx.r4.s64 = 205;
	// addi r5,r8,-9492
	ctx.r5.s64 = ctx.r8.s64 + -9492;
	// bl 0x8209d840
	ctx.lr = 0x8206FF90;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,206
	ctx.r4.s64 = 206;
	// addi r5,r7,-9472
	ctx.r5.s64 = ctx.r7.s64 + -9472;
	// bl 0x8209d840
	ctx.lr = 0x8206FFA0;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,207
	ctx.r4.s64 = 207;
	// addi r5,r6,-9452
	ctx.r5.s64 = ctx.r6.s64 + -9452;
	// bl 0x8209d840
	ctx.lr = 0x8206FFB0;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,208
	ctx.r4.s64 = 208;
	// addi r5,r5,-9432
	ctx.r5.s64 = ctx.r5.s64 + -9432;
	// bl 0x8209d840
	ctx.lr = 0x8206FFC0;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,209
	ctx.r4.s64 = 209;
	// addi r5,r3,-9420
	ctx.r5.s64 = ctx.r3.s64 + -9420;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209d840
	ctx.lr = 0x8206FFD4;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,210
	ctx.r4.s64 = 210;
	// addi r5,r11,-9400
	ctx.r5.s64 = ctx.r11.s64 + -9400;
	// bl 0x8209d840
	ctx.lr = 0x8206FFE4;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,211
	ctx.r4.s64 = 211;
	// addi r5,r10,-9392
	ctx.r5.s64 = ctx.r10.s64 + -9392;
	// bl 0x8209d840
	ctx.lr = 0x8206FFF4;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,212
	ctx.r4.s64 = 212;
	// addi r5,r9,-9364
	ctx.r5.s64 = ctx.r9.s64 + -9364;
	// bl 0x8209d840
	ctx.lr = 0x82070004;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,213
	ctx.r4.s64 = 213;
	// addi r5,r8,-9348
	ctx.r5.s64 = ctx.r8.s64 + -9348;
	// bl 0x8209d840
	ctx.lr = 0x82070014;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,214
	ctx.r4.s64 = 214;
	// addi r5,r7,-9336
	ctx.r5.s64 = ctx.r7.s64 + -9336;
	// bl 0x8209d840
	ctx.lr = 0x82070024;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,215
	ctx.r4.s64 = 215;
	// addi r5,r6,-9320
	ctx.r5.s64 = ctx.r6.s64 + -9320;
	// bl 0x8209d840
	ctx.lr = 0x82070034;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,216
	ctx.r4.s64 = 216;
	// addi r5,r5,-9312
	ctx.r5.s64 = ctx.r5.s64 + -9312;
	// bl 0x8209d840
	ctx.lr = 0x82070044;
	sub_8209D840(ctx, base);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// addi r5,r4,-9304
	ctx.r5.s64 = ctx.r4.s64 + -9304;
	// li r4,217
	ctx.r4.s64 = 217;
	// bl 0x8209d840
	ctx.lr = 0x82070054;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,219
	ctx.r4.s64 = 219;
	// addi r5,r11,-9292
	ctx.r5.s64 = ctx.r11.s64 + -9292;
	// bl 0x8209d840
	ctx.lr = 0x82070064;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,218
	ctx.r4.s64 = 218;
	// addi r5,r10,-9280
	ctx.r5.s64 = ctx.r10.s64 + -9280;
	// bl 0x8209d840
	ctx.lr = 0x82070074;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,220
	ctx.r4.s64 = 220;
	// addi r5,r9,-9268
	ctx.r5.s64 = ctx.r9.s64 + -9268;
	// bl 0x8209d840
	ctx.lr = 0x82070084;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,221
	ctx.r4.s64 = 221;
	// addi r5,r8,-9252
	ctx.r5.s64 = ctx.r8.s64 + -9252;
	// bl 0x8209d840
	ctx.lr = 0x82070094;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,222
	ctx.r4.s64 = 222;
	// addi r5,r7,-9232
	ctx.r5.s64 = ctx.r7.s64 + -9232;
	// bl 0x8209d840
	ctx.lr = 0x820700A4;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,223
	ctx.r4.s64 = 223;
	// addi r5,r6,-9224
	ctx.r5.s64 = ctx.r6.s64 + -9224;
	// bl 0x8209d840
	ctx.lr = 0x820700B4;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,224
	ctx.r4.s64 = 224;
	// addi r5,r5,-9208
	ctx.r5.s64 = ctx.r5.s64 + -9208;
	// bl 0x8209d840
	ctx.lr = 0x820700C4;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,225
	ctx.r4.s64 = 225;
	// addi r5,r3,-9192
	ctx.r5.s64 = ctx.r3.s64 + -9192;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209d840
	ctx.lr = 0x820700D8;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,227
	ctx.r4.s64 = 227;
	// addi r5,r11,-9184
	ctx.r5.s64 = ctx.r11.s64 + -9184;
	// bl 0x8209d840
	ctx.lr = 0x820700E8;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,228
	ctx.r4.s64 = 228;
	// addi r5,r10,-9176
	ctx.r5.s64 = ctx.r10.s64 + -9176;
	// bl 0x8209d840
	ctx.lr = 0x820700F8;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,230
	ctx.r4.s64 = 230;
	// addi r5,r9,-9156
	ctx.r5.s64 = ctx.r9.s64 + -9156;
	// bl 0x8209d840
	ctx.lr = 0x82070108;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,231
	ctx.r4.s64 = 231;
	// addi r5,r8,-9148
	ctx.r5.s64 = ctx.r8.s64 + -9148;
	// bl 0x8209d840
	ctx.lr = 0x82070118;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,233
	ctx.r4.s64 = 233;
	// addi r5,r7,-9140
	ctx.r5.s64 = ctx.r7.s64 + -9140;
	// bl 0x8209d840
	ctx.lr = 0x82070128;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,234
	ctx.r4.s64 = 234;
	// addi r5,r6,-9128
	ctx.r5.s64 = ctx.r6.s64 + -9128;
	// bl 0x8209d840
	ctx.lr = 0x82070138;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,232
	ctx.r4.s64 = 232;
	// addi r5,r5,-9116
	ctx.r5.s64 = ctx.r5.s64 + -9116;
	// bl 0x8209d840
	ctx.lr = 0x82070148;
	sub_8209D840(ctx, base);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// addi r5,r4,-9100
	ctx.r5.s64 = ctx.r4.s64 + -9100;
	// li r4,235
	ctx.r4.s64 = 235;
	// bl 0x8209d840
	ctx.lr = 0x82070158;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,236
	ctx.r4.s64 = 236;
	// addi r5,r11,-9096
	ctx.r5.s64 = ctx.r11.s64 + -9096;
	// bl 0x8209d840
	ctx.lr = 0x82070168;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,237
	ctx.r4.s64 = 237;
	// addi r5,r10,-9088
	ctx.r5.s64 = ctx.r10.s64 + -9088;
	// bl 0x8209d840
	ctx.lr = 0x82070178;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,238
	ctx.r4.s64 = 238;
	// addi r5,r9,-9080
	ctx.r5.s64 = ctx.r9.s64 + -9080;
	// bl 0x8209d840
	ctx.lr = 0x82070188;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,239
	ctx.r4.s64 = 239;
	// addi r5,r8,-9072
	ctx.r5.s64 = ctx.r8.s64 + -9072;
	// bl 0x8209d840
	ctx.lr = 0x82070198;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,240
	ctx.r4.s64 = 240;
	// addi r5,r7,-9068
	ctx.r5.s64 = ctx.r7.s64 + -9068;
	// bl 0x8209d840
	ctx.lr = 0x820701A8;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,241
	ctx.r4.s64 = 241;
	// addi r5,r6,-9064
	ctx.r5.s64 = ctx.r6.s64 + -9064;
	// bl 0x8209d840
	ctx.lr = 0x820701B8;
	sub_8209D840(ctx, base);
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
