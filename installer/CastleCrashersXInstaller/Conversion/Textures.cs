// SPDX-License-Identifier: MIT
// The texture pack (texbake.pak) rebuilt from the shipped texture list
// (Payload\textures.txr, "TXR2", made by tools\texrecipe_locate.py): the list
// says where each texture's shape bytes sit in the user's own game files and
// holds the drawing job; the texture tool (Payload\texbake\ccx-texbake.exe,
// the port's PC build in its CC_TEX_REPLAY mode) runs only the game's
// rasterizer over those jobs. The list is split over several hidden tool
// processes; their packs are merged into one "TXB1" pack whose index is
// sorted by key (the console's binary search) and whose pixels are laid out
// in list order (the order the console first reads them).
using System.Buffers.Binary;
using System.Diagnostics;
using System.Text.RegularExpressions;

namespace CastleCrashersXInstaller.Conversion;

public static partial class Textures
{
    sealed record Row(uint Key0, uint Full, uint Len, uint W, uint H, byte[] Raw);

    // TXR2: u32 file count, (u16 len + name) per file, u32 count, then per
    // texture 7 u32, u8 patch count, 2 bytes per patch, 596-byte job.
    static (List<string> files, List<Row> rows) ReadList(string path)
    {
        var d = File.ReadAllBytes(path);
        if (d.Length < 12 || d[0] != 'T' || d[1] != 'X' || d[2] != 'R' || d[3] != '2')
            throw new InvalidDataException("The texture list is damaged (not TXR2).");
        int p = 4;
        int nf = BinaryPrimitives.ReadInt32LittleEndian(d.AsSpan(p)); p += 4;
        var files = new List<string>();
        for (int i = 0; i < nf; ++i)
        {
            int n = BinaryPrimitives.ReadUInt16LittleEndian(d.AsSpan(p)); p += 2;
            files.Add(System.Text.Encoding.UTF8.GetString(d, p, n)); p += n;
        }
        int count = BinaryPrimitives.ReadInt32LittleEndian(d.AsSpan(p)); p += 4;
        var rows = new List<Row>(count);
        for (int i = 0; i < count; ++i)
        {
            int start = p;
            uint U(int k) => BinaryPrimitives.ReadUInt32LittleEndian(d.AsSpan(start + 4 * k));
            int np = d[start + 28];
            int size = 28 + 1 + 2 * np + 596;
            rows.Add(new Row(U(0), U(1), U(2), U(3), U(4), d[start..(start + size)]));
            p += size;
        }
        return (files, rows);
    }

    static void WriteList(string path, List<string> files, IEnumerable<Row> rows)
    {
        using var f = new FileStream(path, FileMode.Create);
        using var w = new BinaryWriter(f);
        w.Write("TXR2"u8.ToArray());
        w.Write(files.Count);
        foreach (var n in files)
        {
            var b = System.Text.Encoding.UTF8.GetBytes(n);
            w.Write((ushort)b.Length); w.Write(b);
        }
        var list = rows.ToList();
        w.Write(list.Count);
        foreach (var r in list) w.Write(r.Raw);
    }

    [GeneratedRegex(@"TEXREPLAY progress (\d+)/(\d+) bad=(\d+)")]
    private static partial Regex ProgressLine();
    [GeneratedRegex(@"TEXREPLAY done (\d+) textures, (\d+) bad")]
    private static partial Regex DoneLine();

    public static async Task Build(string tool, string listPath, string gameRoot, string imageBin, string workDir, string outPack,
                                   Action<string> log, Action<int, int> progress, CancellationToken ct)
    {
        var (files, rows) = ReadList(listPath);
        foreach (var f in files)
            if (!File.Exists(Path.Combine(gameRoot, f)))
                throw new FileNotFoundException($"The game file {f} needed for the textures is missing.");
        int parts = Math.Clamp(Environment.ProcessorCount, 1, 16);
        Directory.CreateDirectory(workDir);
        var partDone = new int[parts];
        int total = rows.Count;
        var tasks = new List<Task>();
        var partPaths = new string[parts];
        for (int k = 0; k < parts; ++k)
        {
            int part = k;
            var chunk = rows.Where((_, i) => i % parts == part).ToList();
            var list = Path.Combine(workDir, $"part{part}.txr");
            partPaths[part] = Path.Combine(workDir, $"part{part}.pak");
            WriteList(list, files, chunk);
            var psi = Hidden.Start(tool, [Path.Combine(workDir, "none.cct"), imageBin, gameRoot]);
            psi.Environment["CC_TEX_REPLAY"] = list;
            psi.Environment["CC_TEX_REPLAY_ROOT"] = gameRoot;
            psi.Environment["CC_TEX_BAKE"] = partPaths[part];
            tasks.Add(Task.Run(async () =>
            {
                using var p = Process.Start(psi) ?? throw new InvalidOperationException("Could not start the texture tool.");
                using var reg = ct.Register(() => { try { p.Kill(true); } catch { } });
                var outTask = p.StandardOutput.ReadToEndAsync(ct);
                string? line, last = null;
                bool finished = false;
                int bad = -1;
                while ((line = await p.StandardError.ReadLineAsync(ct)) != null)
                {
                    last = line;
                    var m = ProgressLine().Match(line);
                    if (m.Success)
                    {
                        partDone[part] = int.Parse(m.Groups[1].Value);
                        progress(partDone.Sum(), total);
                        continue;
                    }
                    var dm = DoneLine().Match(line);
                    if (dm.Success) { finished = true; bad = int.Parse(dm.Groups[2].Value); }
                    else if (line.StartsWith("FAIL") || line.StartsWith("TEXREPLAY mismatch") || line.StartsWith("TEXREPLAY skip")) log("texture tool: " + line);
                }
                await p.WaitForExitAsync(ct);
                await outTask;
                if (p.ExitCode != 0 || !finished)
                    throw new InvalidOperationException($"The texture tool stopped (part {part + 1}, exit {p.ExitCode}): {last}");
                if (bad != 0)
                    throw new InvalidDataException($"{bad} textures did not match the list (part {part + 1}); the game files may be a different version.");
                log($"textures: part {part + 1} of {parts} done ({chunk.Count} textures)");
            }, ct));
        }
        await Task.WhenAll(tasks);
        log("textures: merging the parts into texbake.pak");
        Merge(partPaths, rows, outPack);
    }

    // One pack from the parts: index by key0, pixels in list order.
    static void Merge(string[] parts, List<Row> order, string outPack)
    {
        var pixels = new Dictionary<(uint, uint), (string file, long offset, uint w, uint h, uint len)>();
        foreach (var path in parts)
        {
            using var f = new FileStream(path, FileMode.Open, FileAccess.Read);
            using var r = new BinaryReader(f);
            if (r.ReadUInt32() != 0x31425854u) throw new InvalidDataException("A texture part is damaged.");  // "TXB1"
            uint n = r.ReadUInt32();
            for (uint i = 0; i < n; ++i)
            {
                uint key0 = r.ReadUInt32(), full = r.ReadUInt32(), len = r.ReadUInt32(), w = r.ReadUInt32(), h = r.ReadUInt32(), off = r.ReadUInt32();
                pixels[(key0, full)] = (path, off, w, h, len);
            }
        }
        var missing = order.Count(o => !pixels.ContainsKey((o.Key0, o.Full)));
        if (missing != 0) throw new InvalidDataException($"{missing} textures are missing after the texture tool ran.");
        var keys = order.Select(o => (o.Key0, o.Full)).Distinct().ToList();
        uint offset = (uint)(8 + 24 * keys.Count);
        var offsets = new Dictionary<(uint, uint), uint>();
        foreach (var k in keys) { offsets[k] = offset; var e = pixels[k]; offset += e.w * e.h; }
        var index = keys.OrderBy(k => k.Item1).ToList();
        using var outFile = new FileStream(outPack, FileMode.Create);
        using var bw = new BinaryWriter(outFile);
        bw.Write(0x31425854u);
        bw.Write((uint)keys.Count);
        foreach (var k in index)
        {
            var e = pixels[k];
            bw.Write(k.Item1); bw.Write(k.Item2); bw.Write(e.len); bw.Write(e.w); bw.Write(e.h); bw.Write(offsets[k]);
        }
        var open = new Dictionary<string, FileStream>();
        try
        {
            foreach (var k in keys)
            {
                var e = pixels[k];
                if (!open.TryGetValue(e.file, out var src)) open[e.file] = src = new FileStream(e.file, FileMode.Open, FileAccess.Read);
                var buf = new byte[e.w * e.h];
                src.Position = e.offset;
                src.ReadExactly(buf);
                bw.Write(buf);
            }
        }
        finally
        {
            foreach (var s in open.Values) s.Dispose();
        }
    }
}
