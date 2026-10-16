// SPDX-License-Identifier: MIT
// The 360 audio (XMA2) to Xbox ADPCM: the C# form of tools\convert_audio.py.
//   sfx.xab           the game:\sounds effects, mono, 22,050 Hz (or the
//                     source rate when lower), looked up by name
//   music\<name>.xad  one file per music track, 44,100 Hz stereo, streamed
// ffmpeg (hidden) decodes XMA2 to PCM; the ADPCM encoder is XAdpcm.
using System.Buffers.Binary;
using System.Text;

namespace CastleCrashersXInstaller.Conversion;

public static class Audio
{
    const int SfxMaxRate = 22050;

    // Sample rate from the file's RIFF header: the game's files carry an
    // 'XMA2' chunk (XMA2WAVEFORMAT, big-endian, sample rate at +12; all 464
    // agree with ffprobe), others a 'fmt ' chunk (nSamplesPerSec at +4).
    public static int SourceRate(string path)
    {
        var d = File.ReadAllBytes(path);
        if (d.Length < 12 || Encoding.ASCII.GetString(d, 0, 4) != "RIFF")
            throw new InvalidDataException($"{Path.GetFileName(path)} is not a RIFF audio file.");
        int p = 12;
        while (p + 8 <= d.Length)
        {
            var id = Encoding.ASCII.GetString(d, p, 4);
            int len = BinaryPrimitives.ReadInt32LittleEndian(d.AsSpan(p + 4));
            if (id == "XMA2") return BinaryPrimitives.ReadInt32BigEndian(d.AsSpan(p + 8 + 12));
            if (id == "fmt ") return BinaryPrimitives.ReadInt32LittleEndian(d.AsSpan(p + 12));
            p += 8 + len + (len & 1);
        }
        throw new InvalidDataException($"{Path.GetFileName(path)} has no format chunk.");
    }

    static async Task<short[]> DecodePcm(string ffmpeg, string src, int channels, int rate, CancellationToken ct)
    {
        var bytes = await Hidden.RunBytes(ffmpeg, ["-v", "error", "-nostdin", "-i", src, "-ac", channels.ToString(),
            "-ar", rate.ToString(), "-f", "s16le", "pipe:1"], ct);
        var pcm = new short[bytes.Length / 2];
        Buffer.BlockCopy(bytes, 0, pcm, 0, pcm.Length * 2);
        return pcm;
    }

    public static async Task Sfx(string ffmpeg, string soundsDir, string outFile, Action<string> log, Action<int, int> progress, CancellationToken ct)
    {
        var files = Directory.GetFiles(soundsDir, "*.xma").OrderBy(f => f, StringComparer.Ordinal).ToArray();
        var entries = new (string name, int rate, int samples, byte[] data)[files.Length];
        int done = 0;
        await Parallel.ForEachAsync(Enumerable.Range(0, files.Length),
            new ParallelOptions { MaxDegreeOfParallelism = Environment.ProcessorCount, CancellationToken = ct },
            async (i, token) =>
            {
                var name = Path.GetFileNameWithoutExtension(files[i]).ToLowerInvariant();
                if (name.Length >= 32) throw new InvalidDataException($"Sound name too long: {name}");
                int rate = Math.Min(SourceRate(files[i]), SfxMaxRate);
                var pcm = await DecodePcm(ffmpeg, files[i], 1, rate, token);
                entries[i] = (name, rate, pcm.Length, XAdpcm.EncodePcm(pcm, 1));
                int n = Interlocked.Increment(ref done);
                log($"sound effect {name}.xma");
                progress(n, files.Length);
            });
        Array.Sort(entries, (a, b) => string.CompareOrdinal(a.name, b.name));
        using var f = new FileStream(outFile, FileMode.Create);
        using var w = new BinaryWriter(f);
        w.Write(Encoding.ASCII.GetBytes("XAB2"));
        w.Write(entries.Length);
        uint off = (uint)(8 + 52 * entries.Length);
        foreach (var e in entries)
        {
            var nm = new byte[32];
            Encoding.ASCII.GetBytes(e.name, nm);
            w.Write(nm);
            w.Write(e.rate); w.Write(1); w.Write(e.samples); w.Write(off); w.Write(e.data.Length);
            off += (uint)e.data.Length;
        }
        foreach (var e in entries) w.Write(e.data);
    }

    public static async Task Music(string ffmpeg, string musicDir, string outDir, Action<string> log, Action<int, int> progress, CancellationToken ct)
    {
        Directory.CreateDirectory(outDir);
        var files = Directory.GetFiles(musicDir, "*.xma").OrderBy(f => f, StringComparer.Ordinal).ToArray();
        int done = 0;
        await Parallel.ForEachAsync(files,
            new ParallelOptions { MaxDegreeOfParallelism = Environment.ProcessorCount, CancellationToken = ct },
            async (src, token) =>
            {
                var name = Path.GetFileNameWithoutExtension(src);
                var pcm = await DecodePcm(ffmpeg, src, 2, 44100, token);
                var data = XAdpcm.EncodePcm(pcm, 2);
                using (var f = new FileStream(Path.Combine(outDir, name + ".xad"), FileMode.Create))
                using (var w = new BinaryWriter(f))
                {
                    w.Write(Encoding.ASCII.GetBytes("XAD1"));
                    w.Write(44100); w.Write(2); w.Write(pcm.Length / 2);
                    w.Write(data);
                }
                int n = Interlocked.Increment(ref done);
                log($"music {name}.xma");
                progress(n, files.Length);
            });
    }
}
