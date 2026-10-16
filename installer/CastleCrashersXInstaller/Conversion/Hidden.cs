// SPDX-License-Identifier: MIT
// Helper processes (ffmpeg, the texture tool) started without a window.
using System.Diagnostics;

namespace CastleCrashersXInstaller.Conversion;

public static class Hidden
{
    public static ProcessStartInfo Start(string exe, IEnumerable<string> args, string? workingDir = null)
    {
        var psi = new ProcessStartInfo(exe)
        {
            UseShellExecute = false,
            CreateNoWindow = true,
            WindowStyle = ProcessWindowStyle.Hidden,
            RedirectStandardOutput = true,
            RedirectStandardError = true,
            WorkingDirectory = workingDir ?? Path.GetDirectoryName(exe)!,
        };
        foreach (var a in args) psi.ArgumentList.Add(a);
        return psi;
    }

    // Runs to completion; stdout as bytes, stderr as text. Throws with the
    // tool's error text on a nonzero exit.
    public static async Task<byte[]> RunBytes(string exe, IEnumerable<string> args, CancellationToken ct)
    {
        using var p = Process.Start(Start(exe, args)) ?? throw new InvalidOperationException($"Could not start {exe}.");
        using var reg = ct.Register(() => { try { p.Kill(true); } catch { } });
        var errTask = p.StandardError.ReadToEndAsync();
        var ms = new MemoryStream();
        await p.StandardOutput.BaseStream.CopyToAsync(ms, ct);
        await p.WaitForExitAsync(ct);
        var err = await errTask;
        if (p.ExitCode != 0)
            throw new InvalidOperationException($"{Path.GetFileName(exe)} failed (exit {p.ExitCode}): {err.Trim()}");
        return ms.ToArray();
    }
}
