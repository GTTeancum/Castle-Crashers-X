// SPDX-License-Identifier: MIT
// Compressed texture pack ("TXB2"). The pixels are DXT5 blocks of 16 bytes
// (8 alpha, 8 colour); most repeat the block before them or are fully
// transparent or opaque (6x smaller over the whole pack). Each texture is
// stored as runs of block kinds, decoded on the console in one pass that
// writes every block once in order, straight into write-combined graphics
// memory (runtime021 cc_bake_decode):
//   token byte: kind << 5 | (run - 1), run 1..32 blocks of that kind, then
//   each block's payload in order. Kinds: 0 the previous block again, 1 all
//   zero, 2 opaque alpha (FF FF 00 00 00 00 00 00) + 8 colour bytes, 3 the
//   previous block's alpha + 8 colour bytes, 4 8 alpha bytes + the previous
//   block's colour, 5 16 literal bytes. The block before the first is zero.
// Pack: "TXB2", count, then count index entries {key0, full, len, w, h,
// offset, csize} (u32 each, sorted by key0), then the compressed textures.
using System.Buffers.Binary;

namespace CastleCrashersXInstaller.Conversion;

public static class TexPack
{
    public const uint Txb1 = 0x31425854u, Txb2 = 0x32425854u;
    static readonly byte[] Opaque = [0xFF, 0xFF, 0, 0, 0, 0, 0, 0];

    static int Kind(ReadOnlySpan<byte> b, ReadOnlySpan<byte> prev)
    {
        if (b.SequenceEqual(prev)) return 0;
        if (!b.ContainsAnyExcept((byte)0)) return 1;
        if (b[..8].SequenceEqual(Opaque)) return 2;
        if (b[..8].SequenceEqual(prev[..8])) return 3;
        if (b[8..].SequenceEqual(prev[8..])) return 4;
        return 5;
    }

    public static byte[] Encode(ReadOnlySpan<byte> raw)
    {
        if (raw.Length % 16 != 0) throw new InvalidDataException("A texture is not whole DXT5 blocks.");
        var o = new MemoryStream(raw.Length / 4 + 16);
        Span<byte> prev = stackalloc byte[16];
        prev.Clear();
        int n = raw.Length / 16, i = 0;
        var kinds = new int[n];
        for (int k = 0; k < n; ++k)
        {
            var b = raw.Slice(k * 16, 16);
            kinds[k] = Kind(b, prev);
            b.CopyTo(prev);
        }
        while (i < n)
        {
            int kind = kinds[i], run = 1;
            while (i + run < n && run < 32 && kinds[i + run] == kind) ++run;
            o.WriteByte((byte)(kind << 5 | (run - 1)));
            for (int k = i; k < i + run; ++k)
            {
                var b = raw.Slice(k * 16, 16);
                switch (kind)
                {
                    case 2: case 3: o.Write(b[8..]); break;
                    case 4: o.Write(b[..8]); break;
                    case 5: o.Write(b); break;
                }
            }
            i += run;
        }
        return o.ToArray();
    }

    // The console's decoder, for checks: true when src decodes to exactly dst.Length bytes.
    public static bool Decode(ReadOnlySpan<byte> src, Span<byte> dst)
    {
        if (dst.Length % 16 != 0) return false;
        Span<byte> prev = stackalloc byte[16];
        prev.Clear();
        int s = 0, d = 0;
        while (d < dst.Length)
        {
            if (s >= src.Length) return false;
            int t = src[s++], kind = t >> 5, run = (t & 31) + 1;
            for (int k = 0; k < run; ++k)
            {
                if (d >= dst.Length) return false;
                var b = dst.Slice(d, 16);
                switch (kind)
                {
                    case 0: prev.CopyTo(b); break;
                    case 1: b.Clear(); break;
                    case 2: if (s + 8 > src.Length) return false; Opaque.CopyTo(b); src.Slice(s, 8).CopyTo(b[8..]); s += 8; break;
                    case 3: if (s + 8 > src.Length) return false; prev[..8].CopyTo(b); src.Slice(s, 8).CopyTo(b[8..]); s += 8; break;
                    case 4: if (s + 8 > src.Length) return false; src.Slice(s, 8).CopyTo(b); prev[8..].CopyTo(b[8..]); s += 8; break;
                    case 5: if (s + 16 > src.Length) return false; src.Slice(s, 16).CopyTo(b); s += 16; break;
                    default: return false;
                }
                b.CopyTo(prev);
                d += 16;
            }
        }
        return s == src.Length;
    }

    public sealed record Entry(uint Key0, uint Full, uint Len, uint W, uint H, byte[] Packed);

    // Writes a TXB2 pack: entries in storage order (the order given), index by key0.
    public static void Write(string outPack, IReadOnlyList<Entry> stored)
    {
        uint offset = (uint)(8 + 28 * stored.Count);
        var offsets = new uint[stored.Count];
        for (int k = 0; k < stored.Count; ++k) { offsets[k] = offset; offset = checked(offset + (uint)stored[k].Packed.Length); }
        var index = Enumerable.Range(0, stored.Count).OrderBy(k => stored[k].Key0).ToList();
        using var f = new FileStream(outPack, FileMode.Create);
        using var bw = new BinaryWriter(f);
        bw.Write(Txb2);
        bw.Write((uint)stored.Count);
        foreach (var k in index)
        {
            var e = stored[k];
            bw.Write(e.Key0); bw.Write(e.Full); bw.Write(e.Len); bw.Write(e.W); bw.Write(e.H); bw.Write(offsets[k]); bw.Write((uint)e.Packed.Length);
        }
        foreach (var e in stored) bw.Write(e.Packed);
    }

    // A TXB1 pack rewritten as TXB2 (same entries, same storage order), each
    // texture checked by decoding it again. Returns (raw bytes, packed bytes).
    public static (long raw, long packed) Compress(string inPack, string outPack)
    {
        var d = File.ReadAllBytes(inPack);
        if (BinaryPrimitives.ReadUInt32LittleEndian(d) != Txb1) throw new InvalidDataException("Not a TXB1 texture pack.");
        int n = (int)BinaryPrimitives.ReadUInt32LittleEndian(d.AsSpan(4));
        var rows = new List<(uint key0, uint full, uint len, uint w, uint h, uint off)>();
        for (int i = 0; i < n; ++i)
        {
            var e = d.AsSpan(8 + 24 * i, 24);
            rows.Add((BinaryPrimitives.ReadUInt32LittleEndian(e), BinaryPrimitives.ReadUInt32LittleEndian(e[4..]),
                      BinaryPrimitives.ReadUInt32LittleEndian(e[8..]), BinaryPrimitives.ReadUInt32LittleEndian(e[12..]),
                      BinaryPrimitives.ReadUInt32LittleEndian(e[16..]), BinaryPrimitives.ReadUInt32LittleEndian(e[20..])));
        }
        long raw = 0, packed = 0;
        var stored = new List<Entry>(n);
        foreach (var r in rows.OrderBy(r => r.off))
        {
            var px = d.AsSpan((int)r.off, (int)(r.w * r.h));
            var p = Encode(px);
            var check = new byte[px.Length];
            if (!Decode(p, check) || !px.SequenceEqual(check)) throw new InvalidDataException("Texture compression check failed.");
            stored.Add(new Entry(r.key0, r.full, r.len, r.w, r.h, p));
            raw += px.Length; packed += p.Length;
        }
        Write(outPack, stored);
        return (raw, packed);
    }
}
