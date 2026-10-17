// SPDX-License-Identifier: MIT
// Game program identity for dashboards: the XBE certificate's title ID and
// title name, and a title image section ($$XTIMAGE) made from the 360 game's
// own icon (TitleIcon.png in the user's package, 64x64, enlarged to 128x128,
// DXT1 in an XPR0 resource). The same XPR0 is written as TitleImage.xbx for
// the game's saved-game folder (E:\UDATA\<title id>\).
using System.Buffers.Binary;
using System.Text;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace CastleCrashersXInstaller.Conversion;

public static class XbeTitle
{
    public const uint TitleId = 0x584108B7;  // the 360 game's title ID
    public const string TitleName = "Castle Crashers";

    // 32-bit BGRA pixels of a PNG scaled to size x size (high-quality).
    static byte[] LoadPng(string path, int size)
    {
        var dec = new PngBitmapDecoder(new Uri(Path.GetFullPath(path)), BitmapCreateOptions.PreservePixelFormat, BitmapCacheOption.OnLoad);
        BitmapSource src = new FormatConvertedBitmap(dec.Frames[0], PixelFormats.Bgra32, null, 0);
        var scaled = new TransformedBitmap(src, new ScaleTransform((double)size / src.PixelWidth, (double)size / src.PixelHeight));
        RenderOptions.SetBitmapScalingMode(scaled, BitmapScalingMode.HighQuality);
        var px = new byte[size * size * 4];
        new FormatConvertedBitmap(scaled, PixelFormats.Bgra32, null, 0).CopyPixels(px, size * 4, 0);
        return px;
    }

    static ushort To565(int r, int g, int b) => (ushort)(((r * 31 + 127) / 255) << 11 | ((g * 63 + 127) / 255) << 5 | ((b * 31 + 127) / 255));
    static (int r, int g, int b) From565(ushort c) => (((c >> 11) & 31) * 255 / 31, ((c >> 5) & 63) * 255 / 63, (c & 31) * 255 / 31);

    // DXT1: per 4x4 block the two colours spanning the block's range
    // (opaque pixels), four-colour mode; pixels with alpha < 128 use the
    // three-colour mode's transparent index.
    static byte[] Dxt1(byte[] bgra, int size)
    {
        var output = new byte[size * size / 2];
        int o = 0;
        for (int by = 0; by < size; by += 4)
            for (int bx = 0; bx < size; bx += 4)
            {
                var pix = new (int r, int g, int b, int a)[16];
                for (int i = 0; i < 16; ++i)
                {
                    int p = ((by + i / 4) * size + bx + i % 4) * 4;
                    pix[i] = (bgra[p + 2], bgra[p + 1], bgra[p], bgra[p + 3]);
                }
                bool anyClear = pix.Any(q => q.a < 128);
                var opaque = pix.Where(q => q.a >= 128).ToArray();
                ushort c0 = 0, c1 = 0;
                if (opaque.Length > 0)
                {
                    // Endpoints: the extremes along the axis of largest spread.
                    int ch(int k, (int r, int g, int b, int a) q) => k == 0 ? q.r : k == 1 ? q.g : q.b;
                    int axis = Enumerable.Range(0, 3).OrderByDescending(k => opaque.Max(q => ch(k, q)) - opaque.Min(q => ch(k, q))).First();
                    var lo = opaque.MinBy(q => ch(axis, q));
                    var hi = opaque.MaxBy(q => ch(axis, q));
                    c0 = To565(hi.r, hi.g, hi.b);
                    c1 = To565(lo.r, lo.g, lo.b);
                }
                bool threeColour = anyClear;
                if (threeColour ? c0 > c1 : c0 < c1) (c0, c1) = (c1, c0);
                if (!threeColour && c0 == c1) { if (c1 > 0) c1--; else c0++; }
                var e0 = From565(c0); var e1 = From565(c1);
                var pal = threeColour
                    ? new[] { e0, e1, ((e0.r + e1.r) / 2, (e0.g + e1.g) / 2, (e0.b + e1.b) / 2), (0, 0, 0) }
                    : new[] { e0, e1, ((2 * e0.r + e1.r) / 3, (2 * e0.g + e1.g) / 3, (2 * e0.b + e1.b) / 3),
                                      ((e0.r + 2 * e1.r) / 3, (e0.g + 2 * e1.g) / 3, (e0.b + 2 * e1.b) / 3) };
                uint bits = 0;
                for (int i = 0; i < 16; ++i)
                {
                    int best = 0;
                    if (threeColour && pix[i].a < 128) best = 3;
                    else
                    {
                        int bestD = int.MaxValue;
                        for (int k = 0; k < (threeColour ? 3 : 4); ++k)
                        {
                            int dr = pal[k].Item1 - pix[i].r, dg = pal[k].Item2 - pix[i].g, db = pal[k].Item3 - pix[i].b;
                            int d = dr * dr + dg * dg + db * db;
                            if (d < bestD) { bestD = d; best = k; }
                        }
                    }
                    bits |= (uint)best << (2 * i);
                }
                BinaryPrimitives.WriteUInt16LittleEndian(output.AsSpan(o), c0);
                BinaryPrimitives.WriteUInt16LittleEndian(output.AsSpan(o + 2), c1);
                BinaryPrimitives.WriteUInt32LittleEndian(output.AsSpan(o + 4), bits);
                o += 8;
            }
        return output;
    }

    // XPR0 resource with one 128x128 DXT1 texture (header padded to 2048).
    public static byte[] TitleImageXpr(string png)
    {
        const int size = 128, headerSize = 2048;
        var data = Dxt1(LoadPng(png, size), size);
        var x = new byte[headerSize + data.Length];
        Encoding.ASCII.GetBytes("XPR0").CopyTo(x, 0);
        BinaryPrimitives.WriteUInt32LittleEndian(x.AsSpan(4), (uint)x.Length);
        BinaryPrimitives.WriteUInt32LittleEndian(x.AsSpan(8), headerSize);
        // D3DTexture: Common (1 reference, texture), Data (offset into the
        // data area), Lock, Format (DMA 1, 2D, DXT1, 1 level, log2 sizes),
        // Size (0: power-of-two).
        BinaryPrimitives.WriteUInt32LittleEndian(x.AsSpan(12), 0x00040001u);
        BinaryPrimitives.WriteUInt32LittleEndian(x.AsSpan(16), 0u);
        BinaryPrimitives.WriteUInt32LittleEndian(x.AsSpan(20), 0u);
        BinaryPrimitives.WriteUInt32LittleEndian(x.AsSpan(24), 1u | 2u << 4 | 0x0Cu << 8 | 1u << 16 | 7u << 20 | 7u << 24);
        BinaryPrimitives.WriteUInt32LittleEndian(x.AsSpan(28), 0u);
        BinaryPrimitives.WriteUInt32LittleEndian(x.AsSpan(32), 0xFFFFFFFFu);
        for (int i = 36; i < headerSize; ++i) x[i] = 0xAD;  // padding as the XDK's bundler writes it
        data.CopyTo(x, headerSize);
        return x;
    }

    // Sets title ID and name in the certificate and adds the $$XTIMAGE
    // section (section headers moved to the free end of the header area).
    public static void Patch(string xbePath, byte[] titleImage)
    {
        var d = File.ReadAllBytes(xbePath);
        if (Encoding.ASCII.GetString(d, 0, 4) != "XBEH") throw new InvalidDataException("default.xbe is not an XBE.");
        uint U(int o) => BinaryPrimitives.ReadUInt32LittleEndian(d.AsSpan(o));
        void W(byte[] b, int o, uint v) => BinaryPrimitives.WriteUInt32LittleEndian(b.AsSpan(o), v);
        uint baseAddr = U(0x104), headerSize = U(0x108), imageSize = U(0x10C);
        int cert = (int)(U(0x118) - baseAddr);
        W(d, cert + 8, TitleId);
        Array.Clear(d, cert + 12, 80);
        Encoding.Unicode.GetBytes(TitleName).CopyTo(d, cert + 12);

        int nsec = (int)U(0x11C);
        int secHdr = (int)(U(0x120) - baseAddr);
        for (int i = 0; i < nsec; ++i)
        {
            int nameAt = (int)(U(secHdr + 56 * i + 20) - baseAddr);
            if (Encoding.ASCII.GetString(d, nameAt, 9) == "$$XTIMAGE") throw new InvalidDataException("default.xbe already has a title image.");
        }
        int firstRaw = int.MaxValue;
        uint vaEnd = 0;
        for (int i = 0; i < nsec; ++i)
        {
            firstRaw = Math.Min(firstRaw, (int)U(secHdr + 56 * i + 12));
            vaEnd = Math.Max(vaEnd, U(secHdr + 56 * i + 4) + U(secHdr + 56 * i + 8));
        }
        // New section header table and name at the end of the header area.
        int newHdr = (int)((headerSize + 15) & ~15u);
        int newName = newHdr + 56 * (nsec + 1);
        int newEnd = newName + 16;
        if (newEnd > firstRaw) throw new InvalidDataException("No room in the XBE header for the title image.");
        int rawAt = (d.Length + 0xFFF) & ~0xFFF;
        uint va = (vaEnd + 0xFFF) & ~0xFFFu;
        var o = new byte[rawAt + titleImage.Length];
        d.CopyTo(o, 0);
        Buffer.BlockCopy(d, secHdr, o, newHdr, 56 * nsec);
        int h = newHdr + 56 * nsec;
        W(o, h + 0, 0);                         // flags: not preloaded
        W(o, h + 4, va);
        W(o, h + 8, (uint)titleImage.Length);
        W(o, h + 12, (uint)rawAt);
        W(o, h + 16, (uint)titleImage.Length);
        W(o, h + 20, baseAddr + (uint)newName);
        W(o, h + 24, 0);                        // section reference count
        W(o, h + 28, baseAddr + (uint)newName + 12);  // head shared page reference (2 bytes, in the name pad)
        W(o, h + 32, baseAddr + (uint)newName + 14);  // tail shared page reference
        System.Security.Cryptography.SHA1.HashData(titleImage).CopyTo(o, h + 36);
        Encoding.ASCII.GetBytes("$$XTIMAGE").CopyTo(o, newName);
        W(o, 0x108, (uint)newEnd);
        W(o, 0x11C, (uint)(nsec + 1));
        W(o, 0x120, baseAddr + (uint)newHdr);
        W(o, 0x10C, Math.Max(imageSize, va + (uint)titleImage.Length - baseAddr));
        titleImage.CopyTo(o, rawAt);
        File.WriteAllBytes(xbePath, o);
    }
}
