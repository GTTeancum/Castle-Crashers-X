// SPDX-License-Identifier: MIT
// Read-only STFS (Xbox LIVE package) reader: the C# form of
// castle-crashers-port\tools\extract_stfs.py. Single-hash-table, read-only
// LIVE/PIRS/CON packages only; every data block is checked against its
// SHA-1 hash entry, and the hash tables up to the header descriptor.
using System.Security.Cryptography;
using System.Text;

namespace CastleCrashersXInstaller.Conversion;

public sealed class StfsEntry
{
    public required string Path { get; init; }
    public required bool Directory { get; init; }
    public required int StartBlock { get; init; }
    public required int ValidBlocks { get; init; }
    public required int AllocatedBlocks { get; init; }
    public required long Size { get; init; }
}

public sealed class Stfs : IDisposable
{
    const int Block = 4096;
    const int End = 0xFFFFFF;
    readonly FileStream _file;
    readonly long _length;
    readonly long _base;
    public int TotalBlocks { get; }
    public uint TitleId { get; }
    public string Title { get; }

    public Stfs(string path)
    {
        _file = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.Read, 1 << 16);
        _length = _file.Length;
        if (_length < 0x971A) throw new InvalidDataException("This file is too small to be an Xbox LIVE package.");
        var magic = Encoding.ASCII.GetString(Read(0, 4));
        if (magic != "LIVE" && magic != "PIRS" && magic != "CON ")
            throw new InvalidDataException("This file is not an Xbox LIVE package (no LIVE/PIRS/CON header).");
        var headerSize = U32(0x340);
        _base = (headerSize + Block - 1) & ~(long)(Block - 1);
        if (headerSize < 0x971A || _base > _length) throw new InvalidDataException("The package header length is invalid.");
        if (U32(0x3A9) != 0) throw new InvalidDataException("SVOD packages are not supported.");
        if (Read(0x379, 1)[0] != 0x24 || (Read(0x37B, 1)[0] & 1) == 0)
            throw new InvalidDataException("Only read-only, single-copy STFS packages are supported.");
        TotalBlocks = (int)U32(0x395);
        if (TotalBlocks < 1 || TotalBlocks > 170 * 170 * 170) throw new InvalidDataException("The package block count is out of range.");
        TitleId = U32(0x360);
        Title = Encoding.BigEndianUnicode.GetString(Read(0x411, 256)).Split('\0')[0];
    }

    public void Dispose() => _file.Dispose();

    byte[] Read(long offset, int size)
    {
        if (offset < 0 || size < 0 || offset + size > _length)
            throw new InvalidDataException($"The package is cut short (read at 0x{offset:X}).");
        var b = new byte[size];
        _file.Position = offset;
        _file.ReadExactly(b);
        return b;
    }

    uint U32(long offset) { var b = Read(offset, 4); return (uint)(b[0] << 24 | b[1] << 16 | b[2] << 8 | b[3]); }

    long DataOffset(int block)
    {
        if (block < 0 || block >= TotalBlocks) throw new InvalidDataException($"Invalid data block {block}.");
        long physical = block;
        long span = 170;
        for (int i = 0; i < 3; ++i)
        {
            physical += (block + span) / span;
            if (block < span) break;
            span *= 170;
        }
        return _base + physical * Block;
    }

    long HashTableOffset(int block, int level)
    {
        long n = level switch
        {
            0 => block < 170 ? 0 : (block / 170) * 171 + (block / 28900) + 1 + (block >= 28900 ? 1 : 0),
            1 => block < 28900 ? 171 : (block / 28900) * 29071 + 1,
            2 => 29071,
            _ => throw new InvalidDataException("Invalid hash level."),
        };
        return _base + n * Block;
    }

    // One data block, checked against its hash entry; returns the next block.
    byte[] ReadBlock(int number, out int next)
    {
        var raw = Read(DataOffset(number), Block);
        var entry = Read(HashTableOffset(number, 0) + (number % 170) * 24, 24);
        var digest = SHA1.HashData(raw);
        if (!digest.AsSpan().SequenceEqual(entry.AsSpan(0, 20)))
            throw new InvalidDataException($"The package is damaged (SHA-1 mismatch at data block {number}).");
        next = entry[21] << 16 | entry[22] << 8 | entry[23];
        return raw;
    }

    List<(int block, byte[] data)> Chain(int start, int count)
    {
        if (count > TotalBlocks) throw new InvalidDataException("A file chain is longer than the package.");
        var seen = new HashSet<int>();
        var result = new List<(int, byte[])>(count);
        int current = start;
        for (int i = 0; i < count; ++i)
        {
            if (!seen.Add(current)) throw new InvalidDataException($"The package's block chain loops at block {current}.");
            var raw = ReadBlock(current, out var next);
            result.Add((current, raw));
            current = next;
        }
        if (count > 0 && current != End) throw new InvalidDataException("A file chain does not end where it should.");
        return result;
    }

    public List<StfsEntry> Entries()
    {
        var hdr = Read(0x37C, 5);
        int count = hdr[0] | hdr[1] << 8;
        int first = hdr[2] | hdr[3] << 8 | hdr[4] << 16;
        var raw = new List<(int index, string name, bool dir, int valid, int alloc, int start, int parent, long size)>();
        int page = 0;
        foreach (var (_, data) in Chain(first, count))
        {
            for (int slot = 0; slot < 64; ++slot)
            {
                int o = slot * 64;
                if (data[o] == 0) continue;
                int n = data[o + 40] & 63;
                if (n < 1 || n > 40) throw new InvalidDataException("A file name in the package is invalid.");
                var name = Encoding.UTF8.GetString(data, o, n);
                if (name is "." or ".." || name.IndexOfAny(['/', '\\', ':', '\0']) >= 0)
                    throw new InvalidDataException($"Unsafe file name in the package: {name}");
                raw.Add((page * 64 + slot, name, (data[o + 40] & 0x80) != 0,
                    data[o + 41] | data[o + 42] << 8 | data[o + 43] << 16,
                    data[o + 44] | data[o + 45] << 8 | data[o + 46] << 16,
                    data[o + 47] | data[o + 48] << 8 | data[o + 49] << 16,
                    data[o + 50] << 8 | data[o + 51],
                    (long)((uint)(data[o + 52] << 24 | data[o + 53] << 16 | data[o + 54] << 8 | data[o + 55]))));
            }
            ++page;
        }
        var lookup = raw.ToDictionary(e => e.index);
        string Resolve(int index, HashSet<int> ancestors)
        {
            var e = lookup[index];
            if (!ancestors.Add(index)) throw new InvalidDataException("The package's folders form a loop.");
            if (e.parent == 65535) return e.name;
            if (!lookup.TryGetValue(e.parent, out var p) || !p.dir) throw new InvalidDataException("A folder is missing in the package.");
            return Resolve(e.parent, ancestors) + "/" + e.name;
        }
        var used = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        var list = new List<StfsEntry>();
        foreach (var e in raw)
        {
            var path = Resolve(e.index, new HashSet<int>());
            if (!used.Add(path)) throw new InvalidDataException($"Duplicate path in the package: {path}");
            list.Add(new StfsEntry { Path = path, Directory = e.dir, StartBlock = e.start, ValidBlocks = e.valid, AllocatedBlocks = e.alloc, Size = e.size });
        }
        return list;
    }

    // A file's bytes (every block hash-checked).
    public byte[] ReadFile(StfsEntry e)
    {
        int n = (int)((e.Size + Block - 1) / Block);
        if (e.AllocatedBlocks != n || e.ValidBlocks != n)
            throw new InvalidDataException($"The package's allocation for {e.Path} does not match its length.");
        var data = new byte[e.Size];
        int at = 0;
        foreach (var (_, b) in Chain(e.StartBlock, n))
        {
            int take = (int)Math.Min(Block, e.Size - at);
            Buffer.BlockCopy(b, 0, data, at, take);
            at += take;
        }
        return data;
    }

    // The hash tables above the data blocks, up to the header's descriptor.
    public void VerifyTree()
    {
        if (TotalBlocks > 170)
            for (int b = 0; b < TotalBlocks; b += 170)
            {
                var table = Read(HashTableOffset(b, 0), Block);
                var parent = HashTableOffset(b, 1) + ((b / 170) % 170) * 24;
                if (!SHA1.HashData(table).AsSpan().SequenceEqual(Read(parent, 20)))
                    throw new InvalidDataException($"The package is damaged (level-0 hash table at block {b}).");
            }
        if (TotalBlocks > 28900)
            for (int b = 0; b < TotalBlocks; b += 28900)
            {
                var table = Read(HashTableOffset(b, 1), Block);
                var parent = HashTableOffset(b, 2) + (b / 28900) * 24;
                if (!SHA1.HashData(table).AsSpan().SequenceEqual(Read(parent, 20)))
                    throw new InvalidDataException($"The package is damaged (level-1 hash table at block {b}).");
            }
        int rootLevel = TotalBlocks > 28900 ? 2 : TotalBlocks > 170 ? 1 : 0;
        var root = Read(HashTableOffset(0, rootLevel), Block);
        if (!SHA1.HashData(root).AsSpan().SequenceEqual(Read(0x381, 20)))
            throw new InvalidDataException("The package is damaged (root hash table).");
    }
}
