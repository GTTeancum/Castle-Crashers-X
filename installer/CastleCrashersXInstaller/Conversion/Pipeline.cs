// SPDX-License-Identifier: MIT
// The whole conversion, in order: unpack the Xbox LIVE package, check it is
// the version the installer's texture list was made from, unpack the game
// code image, lay out the game files, strip the sound bank, rebuild the
// texture pack, convert the audio, add the game program. Output layout (the
// Xbox game reads D:\data next to default.xbe):
//   <out>\default.xbe
//   <out>\data\default.image.bin
//   <out>\data\game-data\{art,bsps,Fonts,game,levels,shaders}\...
//   <out>\data\game-data\audio\sfx.xab, audio\music\*.xad
//   <out>\data\game-data\texbake.pak
using System.Security.Cryptography;

namespace CastleCrashersXInstaller.Conversion;

public sealed class Pipeline
{
    const uint CastleCrashersTitleId = 0x584108B7;
    readonly string _payload;
    readonly Action<string> _log;
    readonly Action<double, string> _progress;

    // Share of the progress bar per step (by typical running time).
    static readonly (string name, double weight)[] Steps = [
        ("Reading the Xbox LIVE package", 6), ("Checking the game version", 2), ("Unpacking the game code", 2),
        ("Copying game files", 3), ("Preparing the sound bank", 1), ("Building textures", 30),
        ("Converting sound effects", 16), ("Converting music", 38), ("Adding the game program", 2),
    ];
    int _step;

    // payload: the installer's Payload folder (default: next to the exe).
    public Pipeline(Action<string> log, Action<double, string> progress, string? payload = null)
    {
        _log = log; _progress = progress;
        _payload = payload ?? Path.Combine(AppContext.BaseDirectory, "Payload");
    }

    void Report(double fraction)
    {
        double done = 0, total = Steps.Sum(s => s.weight);
        for (int i = 0; i < _step; ++i) done += Steps[i].weight;
        done += Steps[_step].weight * Math.Clamp(fraction, 0, 1);
        _progress(done / total, Steps[_step].name);
    }

    void Begin(int step) { _step = step; _log("— " + Steps[step].name); Report(0); }

    string PayloadFile(string rel)
    {
        var p = Path.Combine(_payload, rel);
        if (!File.Exists(p)) throw new FileNotFoundException($"The installer is incomplete: {rel} is missing next to it.");
        return p;
    }

    public async Task Run(string package, string outDir, CancellationToken ct)
    {
        var ffmpeg = PayloadFile(@"ffmpeg\ffmpeg.exe");
        var tool = PayloadFile(@"texbake\ccx-texbake.exe");
        var list = PayloadFile("textures.txr");
        var hashes = PayloadFile("gamefiles.sha256");
        var xbe = PayloadFile("default.xbe");

        // Scratch files go in the output folder (removed at the end), not the
        // system temp folder.
        var work = Path.Combine(outDir, ".ccx-work");
        var extracted = Path.Combine(work, "extracted");
        var data = Path.Combine(outDir, "data");
        var gameData = Path.Combine(data, "game-data");
        try
        {
            // 1. The package.
            Begin(0);
            using (var stfs = new Stfs(package))
            {
                if (stfs.TitleId != CastleCrashersTitleId)
                    throw new InvalidDataException($"This package is \"{stfs.Title}\" (title {stfs.TitleId:X8}), not Castle Crashers.");
                var entries = stfs.Entries();
                long total = entries.Where(e => !e.Directory).Sum(e => e.Size), done = 0;
                foreach (var e in entries)
                {
                    ct.ThrowIfCancellationRequested();
                    var dest = Path.GetFullPath(Path.Combine(extracted, e.Path));
                    if (!dest.StartsWith(Path.GetFullPath(extracted), StringComparison.OrdinalIgnoreCase))
                        throw new InvalidDataException("The package tries to write outside its folder.");
                    if (e.Directory) { Directory.CreateDirectory(dest); continue; }
                    Directory.CreateDirectory(Path.GetDirectoryName(dest)!);
                    await File.WriteAllBytesAsync(dest, stfs.ReadFile(e), ct);
                    done += e.Size;
                    _log($"unpacked {e.Path}");
                    Report((double)done / total);
                }
                stfs.VerifyTree();
            }

            // 2. Version check: the texture list points into these files.
            Begin(1);
            var lines = File.ReadAllLines(hashes).Where(l => l.Length > 66).ToList();
            for (int i = 0; i < lines.Count; ++i)
            {
                var want = lines[i][..64];
                var rel = lines[i][66..].Trim();
                var path = Path.Combine(extracted, rel);
                if (!File.Exists(path)) throw new InvalidDataException($"The package has no {rel}; it is not the supported Castle Crashers version.");
                var got = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(path))).ToLowerInvariant();
                if (got != want) throw new InvalidDataException($"{rel} differs from the supported Castle Crashers version (title update or different release).");
                Report((i + 1.0) / lines.Count);
            }
            _log($"checked {lines.Count} game files against the supported version");

            // 3. Game code image.
            Begin(2);
            Directory.CreateDirectory(data);
            var image = Xex.UnpackImage(await File.ReadAllBytesAsync(Path.Combine(extracted, "default.xex"), ct));
            var imageBin = Path.Combine(data, "default.image.bin");
            await File.WriteAllBytesAsync(imageBin, image, ct);
            _log($"wrote data\\default.image.bin ({image.Length:N0} bytes)");

            // 4. Game files the Xbox build reads (the 360 audio is converted
            // below instead).
            Begin(3);
            var copies = new (string from, string to)[] { ("art", "art"), ("bsps", "bsps"), ("fonts", "Fonts"), ("game", "game"), ("levels", "levels"), ("shaders", "shaders") };
            var all = copies.SelectMany(c => Directory.GetFiles(Path.Combine(extracted, c.from), "*", SearchOption.AllDirectories).Select(f => (c, f))).ToList();
            for (int i = 0; i < all.Count; ++i)
            {
                ct.ThrowIfCancellationRequested();
                var (c, f) = all[i];
                var rel = Path.GetRelativePath(Path.Combine(extracted, c.from), f);
                if (c.from == "game" && rel.Equals("sounds.pak", StringComparison.OrdinalIgnoreCase)) continue;  // step 5
                var dest = Path.Combine(gameData, c.to, rel);
                Directory.CreateDirectory(Path.GetDirectoryName(dest)!);
                File.Copy(f, dest, true);
                _log($"copied {c.to}\\{rel}");
                Report((i + 1.0) / all.Count);
            }

            // 5. Sound bank without its unused MP3 data.
            Begin(4);
            int removed = SoundBank.Strip(Path.Combine(extracted, "game", "sounds.pak"), Path.Combine(gameData, "game", "sounds.pak"));
            _log($"wrote game\\sounds.pak ({removed / 1e6:F1} MB of unused sound data removed)");

            // 6. Textures.
            Begin(5);
            await Textures.Build(tool, list, extracted, imageBin, Path.Combine(work, "textures"), Path.Combine(gameData, "texbake.pak"),
                _log, (n, t) => Report((double)n / t), ct);
            _log("wrote texbake.pak");

            // 7, 8. Audio.
            Begin(6);
            var audio = Path.Combine(gameData, "audio");
            Directory.CreateDirectory(audio);
            await Audio.Sfx(ffmpeg, Path.Combine(extracted, "sounds"), Path.Combine(audio, "sfx.xab"), _log, (n, t) => Report((double)n / t), ct);
            _log("wrote audio\\sfx.xab");
            Begin(7);
            await Audio.Music(ffmpeg, Path.Combine(extracted, "music"), Path.Combine(audio, "music"), _log, (n, t) => Report((double)n / t), ct);

            // 9. The game program.
            Begin(8);
            var outXbe = Path.Combine(outDir, "default.xbe");
            File.Copy(xbe, outXbe, true);
            // Dashboard identity: title "Castle Crashers", title ID 584108B7
            // (the 360 game's), and the 360 icon as the title image; the
            // same image goes next to the game data for its saved-game folder.
            var titleImage = XbeTitle.TitleImageXpr(Path.Combine(extracted, "TitleIcon.png"));
            XbeTitle.Patch(outXbe, titleImage);
            await File.WriteAllBytesAsync(Path.Combine(data, "TitleImage.xbx"), titleImage, ct);
            _log($"wrote default.xbe (\"{XbeTitle.TitleName}\", title ID {XbeTitle.TitleId:X8}, 360 icon as the title image)");
            _step = Steps.Length - 1;
            Report(1);
        }
        finally
        {
            try { if (Directory.Exists(work)) Directory.Delete(work, true); } catch { /* temp files only */ }
        }
    }
}
