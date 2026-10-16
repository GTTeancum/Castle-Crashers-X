// SPDX-License-Identifier: MIT
// sounds.pak without the unused MP3 payloads: the C# form of
// tools\strip_sound_bank.py. sounds.pak is a stored ZIP whose member
// SOUNDS.COK6.BREC is a 'COK6' cooked image (128-byte header) around an
// uncompressed SWF with 342 DefineSound tags (9.8 MB of MP3 data the game
// never plays; it plays game:\sounds\<name>.xma instead). Every tag and every
// DefineSound header is kept; only the sound data is emptied.
using System.Buffers.Binary;
using System.IO.Compression;

namespace CastleCrashersXInstaller.Conversion;

public static class SoundBank
{
    const string Bank = "SOUNDS.COK6.BREC";
    const int CookHeader = 128;

    static byte[] StripSwf(byte[] swf, out int removed)
    {
        int nbits = swf[8] >> 3;
        int p = 8 + (5 + 4 * nbits + 7) / 8 + 4;
        var output = new MemoryStream();
        output.Write(swf, 0, p);
        removed = 0;
        Span<byte> head = stackalloc byte[6];
        while (p < swf.Length)
        {
            int h = BinaryPrimitives.ReadUInt16LittleEndian(swf.AsSpan(p));
            int code = h >> 6, length = h & 63;
            int hp = p;
            p += 2;
            if (length == 63)
            {
                length = (int)BinaryPrimitives.ReadUInt32LittleEndian(swf.AsSpan(p));
                p += 4;
            }
            if (code == 14)
            {
                // SoundId u16, flags u8, SoundSampleCount u32, then the MP3
                // data (SeekSamples s16 + frames): keep the first 9 bytes.
                BinaryPrimitives.WriteUInt16LittleEndian(head, (ushort)((code << 6) | 63));
                BinaryPrimitives.WriteUInt32LittleEndian(head[2..], 9u);
                output.Write(head);
                output.Write(swf, p, 9);
                removed += length - 9;
            }
            else
            {
                output.Write(swf, hp, p + length - hp);
            }
            p += length;
            if (code == 0)
            {
                output.Write(swf, p, swf.Length - p);  // cooked bytes after the End tag
                break;
            }
        }
        var result = output.ToArray();
        uint fileLength = BinaryPrimitives.ReadUInt32LittleEndian(swf.AsSpan(4));
        BinaryPrimitives.WriteUInt32LittleEndian(result.AsSpan(4), (uint)(fileLength - removed));
        return result;
    }

    // Writes the stripped pak; returns the number of MP3 bytes removed.
    public static int Strip(string sourcePak, string destPak)
    {
        using var src = ZipFile.OpenRead(sourcePak);
        var bankEntry = src.GetEntry(Bank) ?? throw new InvalidDataException($"sounds.pak has no {Bank}.");
        byte[] bank;
        using (var s = bankEntry.Open()) { bank = new byte[bankEntry.Length]; s.ReadExactly(bank); }
        if (BinaryPrimitives.ReadUInt32BigEndian(bank.AsSpan(16)) != bank.Length - 136)
            throw new InvalidDataException("sounds.pak's sound bank is not the expected retail version.");
        var swf = StripSwf(bank[CookHeader..], out int removed);
        var newBank = new byte[CookHeader + swf.Length];
        Buffer.BlockCopy(bank, 0, newBank, 0, CookHeader);
        Buffer.BlockCopy(swf, 0, newBank, CookHeader, swf.Length);
        BinaryPrimitives.WriteUInt32BigEndian(newBank.AsSpan(16), (uint)(newBank.Length - 136));
        Directory.CreateDirectory(Path.GetDirectoryName(destPak)!);
        using (var outFile = new FileStream(destPak, FileMode.Create))
        using (var zip = new ZipArchive(outFile, ZipArchiveMode.Create))
            foreach (var e in src.Entries)
            {
                var n = zip.CreateEntry(e.FullName, CompressionLevel.NoCompression);
                n.LastWriteTime = e.LastWriteTime;
                n.ExternalAttributes = e.ExternalAttributes;
                using var w = n.Open();
                if (e.FullName == Bank) w.Write(newBank);
                else { using var r = e.Open(); r.CopyTo(w); }
            }
        CopyMadeBy(sourcePak, destPak);
        return removed;
    }

    // The central directory's "version made by" of each entry as in the
    // original (it records a Unix host; .NET writes 0), so the pak matches
    // the one the port was tested with byte for byte.
    static void CopyMadeBy(string sourcePak, string destPak)
    {
        var a = File.ReadAllBytes(sourcePak);
        var b = File.ReadAllBytes(destPak);
        static List<int> Central(byte[] d)
        {
            var l = new List<int>();
            for (int i = 0; i + 4 <= d.Length; ++i)
                if (d[i] == 0x50 && d[i + 1] == 0x4B && d[i + 2] == 0x01 && d[i + 3] == 0x02) l.Add(i);
            return l;
        }
        var ca = Central(a);
        var cb = Central(b);
        if (ca.Count != cb.Count) return;
        for (int k = 0; k < ca.Count; ++k) { b[cb[k] + 4] = a[ca[k] + 4]; b[cb[k] + 5] = a[ca[k] + 5]; }
        File.WriteAllBytes(destPak, b);
    }
}
