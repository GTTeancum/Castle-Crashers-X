// SPDX-License-Identifier: MIT
// Installer conversion checks without the window: each step's output against
// the files the console was tested with, and a full install ("install <out>").
using System.Diagnostics;
using System.Security.Cryptography;
using CastleCrashersXInstaller.Conversion;
var repo = @"D:\Programming\GitHub\Castle-Crashers-X";
var tmp = Path.Combine(repo, "game-data", "installer-check"); Directory.CreateDirectory(tmp);  // git-ignored
string H(string p) => Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(p)));
var sw = Stopwatch.StartNew();
var what = args.Length > 0 ? args[0] : "all";
if (what == "install") {
  var outDir = args[1];
  var last = "";
  var p = new Pipeline(l => Console.WriteLine(l.StartsWith("—") || l.StartsWith("textures") || l.StartsWith("wrote") || l.StartsWith("checked") ? "[" + sw.Elapsed.ToString(@"mm\:ss") + "] " + l : ""),
                       (f, st) => { var t = $"{st} {f * 100:F0}%"; if (t != last && (int)(f * 100) % 10 == 0) { last = t; } },
                       Path.Combine(repo, @"installer\CastleCrashersXInstaller\Payload"));
  await p.Run(Path.Combine(repo, "Castle Crashers"), outDir, CancellationToken.None);
  Console.WriteLine($"install done in {sw.Elapsed}");
  return;
}
if (what is "all" or "stfs") {
  using var s = new Stfs(Path.Combine(repo, "Castle Crashers"));
  int n = 0, bad = 0;
  foreach (var e in s.Entries()) { if (e.Directory) continue; var d = s.ReadFile(e); n++;
    var refp = Path.Combine(repo, "game-data", "extracted", e.Path);
    if (!File.Exists(refp) || !SHA256.HashData(d).AsSpan().SequenceEqual(SHA256.HashData(File.ReadAllBytes(refp)))) { bad++; Console.WriteLine("DIFF " + e.Path); } }
  s.VerifyTree();
  Console.WriteLine($"stfs: {n} files, {bad} differ, title {s.TitleId:X8} '{s.Title}', {sw.Elapsed.TotalSeconds:F1}s"); sw.Restart();
}
if (what is "all" or "sound") {
  var o = Path.Combine(tmp, "sounds.pak");
  SoundBank.Strip(Path.Combine(repo, @"game-data\extracted\game\sounds.pak"), o);
  Console.WriteLine($"sounds.pak: same as converted = {H(o) == H(Path.Combine(repo, @"game-data\converted\data\game\sounds.pak"))}, size {new FileInfo(o).Length} vs {new FileInfo(Path.Combine(repo, @"game-data\converted\data\game\sounds.pak")).Length}, {sw.Elapsed.TotalSeconds:F1}s"); sw.Restart();
}
var ff = Environment.GetEnvironmentVariable("FF") ?? Path.Combine(repo, "installer", "third_party", "ffmpeg", "ffmpeg.exe");
if (what is "all" or "sfx") {
  var o = Path.Combine(tmp, "sfx.xab");
  await Audio.Sfx(ff, Path.Combine(repo, @"game-data\extracted\sounds"), o, _ => {}, (_, _) => {}, CancellationToken.None);
  Console.WriteLine($"sfx.xab: same = {H(o) == H(Path.Combine(repo, @"game-data\converted\audio\sfx.xab"))}, {sw.Elapsed.TotalSeconds:F1}s"); sw.Restart();
}
if (what is "all" or "music") {
  var o = Path.Combine(tmp, "music");
  await Audio.Music(ff, Path.Combine(repo, @"game-data\extracted\music"), o, _ => {}, (_, _) => {}, CancellationToken.None);
  int same = 0, n = 0;
  foreach (var f in Directory.GetFiles(o)) { n++; if (H(f) == H(Path.Combine(repo, @"game-data\converted\audio\music", Path.GetFileName(f)))) same++; }
  Console.WriteLine($"music: {same}/{n} same, {sw.Elapsed.TotalSeconds:F1}s");
}
