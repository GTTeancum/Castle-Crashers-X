# SPDX-License-Identifier: MIT
"""Copy a local folder to the console, file by file (xbcp's recursive copy
does not descend into folders given a wildcard).

usage: xbox_push_folder.py <local folder> <console folder, e.g. xE:\\CastleCrashersX-Test\\data>
"""
import os
import subprocess
import sys
import time

XBCP = r"C:\XDK\Xbox\Bin\xbcp.exe"


def main(argv):
    root, target = argv[0], argv[1].rstrip("\\")
    t = time.time()
    n, bad = 0, []
    for dp, _, fs in os.walk(root):
        rel = os.path.relpath(dp, root)
        dest = target if rel == "." else target + "\\" + rel
        for f in fs:
            r = subprocess.run([XBCP, "/y", "/t", "/f", "/q", f, dest], cwd=dp, capture_output=True, text=True, input="A\n")
            n += 1
            if r.returncode != 0:
                bad.append((rel, f, (r.stdout + r.stderr).strip()))
    print("%d files copied to %s, %d failed, %d s" % (n, target, len(bad), time.time() - t))
    for b in bad[:10]:
        print("FAILED", b)
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
