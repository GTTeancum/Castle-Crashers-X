// SPDX-License-Identifier: MIT
//
// Unpacks an AES-encrypted, normal-LZX XEX2 (Xbox 360 executable) to its mapped
// PowerPC image. C# equivalent of castle-crashers-port/tools/unpack_xex.py:
// AES-CBC decrypt, walk and SHA-1 verify the compressed block hash chain,
// collect the LZX frames, then LZX-decode them into the image.
// No RSA signature or per-page descriptor checks (same as the Python tool).

using System;
using System.Collections.Generic;
using System.IO;
using System.Security.Cryptography;

namespace CastleCrashersXInstaller.Conversion;

public static class Xex
{
    // Public Xenia retail XEX key, not an account credential or per-user secret.
    private static readonly byte[] RetailKey = Convert.FromHexString("20b185a59d28fdc340583fbb0896bf91");

    private const int LzxFrameSize = 32768;

    /// <summary>Decrypt and decompress a retail XEX2 into its PE image (starts with "MZ").</summary>
    /// <exception cref="InvalidDataException">The file is malformed or uses an unsupported format.</exception>
    public static byte[] UnpackImage(byte[] xex)
    {
        ArgumentNullException.ThrowIfNull(xex);

        if (Read(xex, 0, 4).AsSpan().SequenceEqual("XEX2"u8) == false)
            throw Fail("Expected XEX2 magic");

        uint count = Be32(xex, 20);
        if (count > 4096) throw Fail("Unreasonable optional header count");

        // Optional headers: (id, value) pairs; later duplicates win, as in the Python dict.
        var opts = new Dictionary<uint, uint>();
        for (int i = 0; i < count; i++)
            opts[Be32(xex, 24 + i * 8)] = Be32(xex, 28 + i * 8);

        int security = ToOffset(Be32(xex, 16));
        if (!opts.TryGetValue(0x3FF, out uint fmtValue)) throw Fail("No file-format optional header");
        int fmt = ToOffset(fmtValue);

        uint imageSizeU = Be32(xex, security + 4);
        if (imageSizeU < 1 || imageSizeU > 256u * 1024 * 1024) throw Fail("Image outside probe safety limit");
        int imageSize = (int)imageSizeU;

        int encryption = Be16(xex, fmt + 4), compression = Be16(xex, fmt + 6);
        if (encryption != 1 || compression != 2)
            throw Fail($"Only AES + normal LZX is supported (encryption={encryption}, compression={compression})");

        // Session key = retail key decrypting the 16-byte key in the security info.
        byte[] key = Decrypt(RetailKey, Read(xex, security + 0x150, 16));
        int dataOffset = ToOffset(Be32(xex, 8));
        byte[] plain = Decrypt(key, Read(xex, dataOffset, xex.Length - dataOffset));

        // Walk the hash chain: each block starts with the next block's length + SHA-1,
        // followed by (u16 size, LZX frame) records terminated by a zero size.
        int maxFrames = (imageSize + LzxFrameSize - 1) / LzxFrameSize;
        uint length = Be32(xex, fmt + 12);
        byte[] digest = Read(xex, fmt + 16, 20);
        var chunks = new List<(int Offset, int Length)>();
        long totalCompressed = 0;
        int pos = 0, blocks = 0;
        while (length != 0)
        {
            if (length < 26 || pos + (long)length > plain.Length) throw Fail("Compressed block out of bounds");
            var block = new ReadOnlySpan<byte>(plain, pos, (int)length);
            if (!SHA1.HashData(block).AsSpan().SequenceEqual(digest))
                throw Fail($"Compressed block SHA1 mismatch at {blocks}");

            uint nextLength = Be32(plain, pos);
            byte[] nextDigest = block.Slice(4, 20).ToArray();
            int q = 24;
            while (true)
            {
                if (q + 2 > block.Length) throw Fail("LZX frame header truncated");
                int n = (block[q] << 8) | block[q + 1];
                q += 2;
                if (n == 0) break;
                if (q + n > block.Length) throw Fail("LZX frame truncated");
                chunks.Add((pos + q, n));
                totalCompressed += n;
                q += n;
                if (chunks.Count > maxFrames) throw Fail("Too many LZX frames");
            }
            pos += (int)length;
            length = nextLength;
            digest = nextDigest;
            blocks++;
        }

        uint window = Be32(xex, fmt + 8);
        if (window < 32768 || window > 2097152 || (window & (window - 1)) != 0)
            throw Fail($"Unsupported LZX window {window}");
        if (chunks.Count != maxFrames || chunks.Count > 65535)
            throw Fail("Unexpected LZX frame/image-size relationship");

        // The frames form one continuous LZX stream (one 32 KB output frame each,
        // no reset interval), exactly as the Python tool's synthetic CAB folder.
        var stream = new byte[totalCompressed];
        int w = 0;
        foreach (var (offset, len) in chunks)
        {
            Buffer.BlockCopy(plain, offset, stream, w, len);
            w += len;
        }

        int windowBits = System.Numerics.BitOperations.Log2(window);
        byte[] image = new LzxDecoder(windowBits).Decompress(stream, imageSize);

        if (image.Length != imageSize || image[0] != (byte)'M' || image[1] != (byte)'Z')
            throw Fail("Decoded image length or PE signature is unexpected");
        return image;
    }

    private static byte[] Decrypt(byte[] key, byte[] data)
    {
        if (data.Length % 16 != 0) throw Fail("AES input is not block aligned");
        using var aes = Aes.Create();
        aes.Key = key;
        return aes.DecryptCbc(data, new byte[16], PaddingMode.None);
    }

    private static byte[] Read(byte[] b, long offset, long count)
    {
        if (offset < 0 || count < 0 || offset + count > b.Length) throw Fail("XEX header read out of bounds");
        return b.AsSpan((int)offset, (int)count).ToArray();
    }

    private static uint Be32(byte[] b, long offset)
    {
        var s = Read(b, offset, 4);
        return (uint)(s[0] << 24 | s[1] << 16 | s[2] << 8 | s[3]);
    }

    private static int Be16(byte[] b, long offset)
    {
        var s = Read(b, offset, 2);
        return s[0] << 8 | s[1];
    }

    private static int ToOffset(uint value)
    {
        if (value > int.MaxValue) throw Fail("XEX header read out of bounds");
        return (int)value;
    }

    private static InvalidDataException Fail(string message) => new($"XEX: {message}");
}
