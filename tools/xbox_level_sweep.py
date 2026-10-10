# SPDX-License-Identifier: MIT
"""Four-player stress run of every level on the development console.

Needs a build made with `make FOURP=1 LEVEL=file` (nxdk-checkpoint022): it
reads the level number from D:\\level.txt beside the XBE at boot. For each
level the sweep writes that file, launches the game, records its debug
output, takes a screenshot during the fight and one at the end, and writes
one summary line:

  - FAIL lines (memory stops, including "game heap block past the backed
    heap"), exceptions, textures drawn live (TEXBAKE miss),
  - whether the game was still running at the end (PERF lines in the last
    30 s),
  - the game heap and main pool high-water marks (HWM lines),
  - FPS over the fight (the last `fight` seconds).

Usage: xbox_level_sweep.py <xbe> <out dir> [levels, e.g. 1-33 or 4,7,25; default all 58]
       [--seconds N] [--fight N]
The XBE is pushed as the game's default.xbe; the out dir gets L<n>.txt
(debug log), L<n>_fight.png, L<n>_end.png and summary.txt.
"""
import os
import re
import subprocess
import sys
import tempfile
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import xbox_console as xc  # noqa: E402


def parse_levels(text):
    out = []
    for part in text.split(","):
        if "-" in part:
            a, b = part.split("-")
            out += range(int(a), int(b) + 1)
        else:
            out.append(int(part))
    return out


def summarize(level, logs, fight):
    lines = []
    for p in logs:
        if os.path.exists(p):
            lines += open(p, encoding="utf-8", errors="replace").read().splitlines()
    fails = [l.split("string=", 1)[-1] for l in lines if "FAIL" in l]
    misses = [l for l in lines if "TEXBAKE miss" in l]
    excepts = [l for l in lines if re.search(r"\bexception\b", l, re.I) and "string=" not in l]
    perf = []
    for l in lines:
        m = re.search(r"PERF t=(\d+) fps=(\d+)", l)
        if m:
            perf.append((int(m.group(1)) / 1000.0, int(m.group(2)), l[:8]))
    heap = pool = 0
    heap_cap = pool_cap = 0
    for l in lines:
        m = re.search(r"HWM t=\d+s heap=(\d+)K/(\d+)K pool=(\d+)K/(\d+)K", l)
        if m:
            heap, heap_cap, pool, pool_cap = (int(g) for g in m.groups())
    # Still running: a PERF line within 30 s of the last log line's clock.
    def clock(s):
        try:
            h, m_, sec = (int(x) for x in s.split(":"))
            return h * 3600 + m_ * 60 + sec
        except ValueError:
            return None
    stamps = [clock(l[:8]) for l in lines if clock(l[:8]) is not None]
    # (Clock times modulo a day: a run may cross midnight.)
    alive = bool(perf) and stamps and clock(perf[-1][2]) is not None and (stamps[-1] - clock(perf[-1][2])) % 86400 <= 30
    tail = [p for p in perf if p[0] >= perf[-1][0] - fight] if perf else []
    avg = sum(p[1] for p in tail) / len(tail) if tail else 0.0
    low = min((p[1] for p in tail), default=0)
    under = sum(1 for p in tail if p[1] < 28)
    verdict = "FAIL" if fails or excepts else ("HUNG" if not alive else "ok")
    s = "L%-2d %-4s fps avg %.1f min %d (%d of %d s under 28)  heap %dK/%dK  pool %dK/%dK  live-drawn textures %d" % (
        level, verdict, avg, low, under, len(tail), heap, heap_cap, pool, pool_cap, len(misses))
    for f in fails[:3]:
        s += "\n     " + f
    for e in excepts[:3]:
        s += "\n     " + e
    return s


def main(argv):
    seconds, fight = 500.0, 240.0
    args = []
    i = 0
    while i < len(argv):
        if argv[i] == "--seconds":
            seconds = float(argv[i + 1]); i += 2
        elif argv[i] == "--fight":
            fight = float(argv[i + 1]); i += 2
        else:
            args.append(argv[i]); i += 1
    if len(args) < 2:
        raise SystemExit(__doc__)
    xbe, out = args[0], args[1]
    # Default: every level the game ships (levels/level<n>.pak; 39 and 52 do
    # not exist).
    levels = parse_levels(args[2]) if len(args) > 2 else [n for n in range(1, 61) if n not in (39, 52)]
    os.makedirs(out, exist_ok=True)
    xc.XBOX = xc.xbox_name()
    xc.tool("xbcp", "/y", "/q", xbe, xc.GAME_DIR + r"\default.xbe")
    summary = open(os.path.join(out, "summary.txt"), "a", encoding="utf-8", newline="\n")
    summary.write("# %s sweep of %s, %d s per level\n" % (time.strftime("%Y-%m-%d %H:%M"), xbe, seconds))
    summary.flush()
    for lvl in levels:
        # Back to the dashboard first, so the running game has no file open.
        xc.tool("xbreboot", check=False)
        time.sleep(20)
        tmp = os.path.join(tempfile.mkdtemp(dir=out), "level.txt")
        with open(tmp, "w", newline="\n") as f:
            f.write("%d\n" % lvl)
        xc.tool("xbcp", "/y", "/q", tmp, xc.GAME_DIR + r"\level.txt")
        a = os.path.join(out, "L%d.txt" % lvl)
        b = os.path.join(out, "L%d_end.txt" % lvl)
        first = seconds - 150.0
        xc.listen(first, a, launch=xc.GAME_DIR + r"\default.xbe")
        for name in ("fight", "end"):
            try:
                xc.shot(os.path.join(out, "L%d_%s.png" % (lvl, name)))
            except Exception as e:  # a hung console may not answer
                print("L%d %s screenshot failed: %s" % (lvl, name, e))
            if name == "fight":
                xc.listen(150.0, b)
        line = summarize(lvl, [a, b], fight)
        print(line, flush=True)
        summary.write(line + "\n")
        summary.flush()
    summary.close()


if __name__ == "__main__":
    main(sys.argv[1:])
