# SPDX-License-Identifier: MIT
"""Count one-frame drawing glitches on a static screen of the console.

usage: xbox_glitch_check.py <xbe> <out dir> [--delay S] [--shots N]

Pushes the XBE (a test build that parks on a static screen, e.g. make
SCRIPT=book), launches it, waits `delay` seconds, then takes `shots`
paused screenshots (tools/xbox_console.py shot; each is a random frame of
the running game). A frame counts as a glitch when it differs from the
per-pixel median of all shots by much more than the typical frame does
(small animations stay below the threshold). Glitch frames are saved as
glitch_NNN.png next to median.png; the summary goes to summary.txt and the
console's debug output to log.txt.
"""
import os
import sys
import threading
import time

import numpy as np
from PIL import Image

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import xbox_console as xc  # noqa: E402


def main(argv):
    delay, shots = 115.0, 300
    args, i = [], 0
    while i < len(argv):
        if argv[i] == "--delay": delay = float(argv[i + 1]); i += 2
        elif argv[i] == "--shots": shots = int(argv[i + 1]); i += 2
        else: args.append(argv[i]); i += 1
    xbe, out = args
    os.makedirs(out, exist_ok=True)
    xc.XBOX = xc.xbox_name()
    xc.tool("xbcp", "/y", "/q", xbe, xc.GAME_DIR + r"\default.xbe")
    total = delay + shots * 1.5 + 60
    t = threading.Thread(target=xc.listen, args=(total, os.path.join(out, "log.txt"), xc.GAME_DIR + r"\default.xbe"), daemon=True)
    t.start()
    time.sleep(delay)
    frames = []
    for k in range(shots):
        p = os.path.join(out, "shot.png")
        try:
            xc.shot(p)
        except Exception as e:
            print("shot failed:", e)
            continue
        frames.append(np.asarray(Image.open(p).convert("L"), dtype=np.int16))
    med = np.median(np.stack(frames), axis=0).astype(np.int16)
    Image.fromarray(med.astype(np.uint8)).save(os.path.join(out, "median.png"))
    diffs = [float(np.abs(f - med).mean()) for f in frames]
    typical = float(np.median(diffs))
    thresh = max(3.0, typical * 4)
    glitches = [k for k, d in enumerate(diffs) if d > thresh]
    for k in glitches:
        Image.fromarray(frames[k].astype(np.uint8)).save(os.path.join(out, "glitch_%03d.png" % k))
    line = "%s: %d shots, %d glitch frames (typical diff %.2f, threshold %.2f, glitch diffs %s)" % (
        os.path.basename(xbe), len(frames), len(glitches), typical, thresh,
        ", ".join("%.1f" % diffs[k] for k in glitches[:20]))
    print(line)
    with open(os.path.join(out, "summary.txt"), "w") as f:
        f.write(line + "\n")
    t.join()


if __name__ == "__main__":
    main(sys.argv[1:])
