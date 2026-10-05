# SPDX-License-Identifier: MIT
"""Drive the Xbox development console over the debug monitor (XBDM).

The console is the one the XDK tools target (HKCU\\Software\\Microsoft\\
XboxSDK\\XboxName, or --xbox). Commands:

  push <local xbe>         copy a build to the console as the game's default.xbe
                           (the previous one is kept as default.prev.xbe)
  run [seconds] [log]      launch the game and record its debug output (and
                           other notifications) for <seconds> to <log>
  listen <seconds> <log>   record notifications without launching anything
  shot <file.png>          capture the console's scanout framebuffer
  profile <delay> <secs> <out>  sample the running game's threads (Eip, Esp,
                           top of stack) every 5 ms after <delay> seconds
  reboot                   warm reboot to the default title
  cmd <text>               send one XBDM command and print the reply

File copies, launches and captures use the XDK command-line tools in
C:\\XDK\\Xbox\\Bin; notifications use an XBDM 'notify' channel on port 731.
"""
import os
import socket
import subprocess
import sys
import time
import winreg

XDK_BIN = r"C:\XDK\Xbox\Bin"
GAME_DIR = r"xE:\CastleCrashersX-Test"


def xbox_name():
    try:
        with winreg.OpenKey(winreg.HKEY_CURRENT_USER, r"Software\Microsoft\XboxSDK") as k:
            return winreg.QueryValueEx(k, "XboxName")[0]
    except OSError:
        return "10.0.0.231"


def tool(name, *args, check=True):
    cmd = [os.path.join(XDK_BIN, name + ".exe"), "/x", XBOX] + list(args)
    r = subprocess.run(cmd, capture_output=True, text=True)
    if check and r.returncode != 0:
        sys.stderr.write(r.stdout + r.stderr)
        raise SystemExit("%s failed (%d)" % (name, r.returncode))
    return r


class Xbdm:
    def __init__(self, host, timeout=10.0):
        self.s = socket.create_connection((host, 731), timeout=timeout)
        self.buf = b""
        banner = self.line()
        if not banner.startswith("201"):
            raise RuntimeError("unexpected banner: " + banner)

    def line(self):
        while b"\r\n" not in self.buf:
            d = self.s.recv(4096)
            if not d:
                raise EOFError("connection closed")
            self.buf += d
        l, self.buf = self.buf.split(b"\r\n", 1)
        return l.decode("latin-1")

    def cmd(self, text):
        self.s.sendall(text.encode("latin-1") + b"\r\n")
        first = self.line()
        lines = [first]
        if first.startswith("202"):  # multi-line response, ends with "."
            while True:
                l = self.line()
                if l == ".":
                    break
                lines.append(l)
        return lines


def listen(seconds, log_path, launch=None):
    """Record notifications (debug strings, exceptions, title starts) for
    `seconds`; with launch, reboot into that XBE once the channel is open."""
    end = time.time() + seconds
    out = open(log_path, "w", encoding="utf-8", newline="\n") if log_path else sys.stdout
    launched = False
    while time.time() < end:
        try:
            x = Xbdm(XBOX, timeout=5.0)
            reply = x.cmd("notify")
            out.write("# %s notify: %s\n" % (time.strftime("%H:%M:%S"), reply[0]))
            out.flush()
            if launch and not launched:
                launched = True
                tool("xbreboot", launch)
                out.write("# %s launched %s\n" % (time.strftime("%H:%M:%S"), launch))
                out.flush()
            x.s.settimeout(1.0)
            while time.time() < end:
                try:
                    l = x.line()
                except socket.timeout:
                    continue
                out.write("%s %s\n" % (time.strftime("%H:%M:%S"), l))
                out.flush()
        except (OSError, EOFError, RuntimeError) as e:
            # the channel drops across a reboot; reconnect
            out.write("# %s channel: %s\n" % (time.strftime("%H:%M:%S"), e))
            out.flush()
            time.sleep(1.0)
    if log_path:
        out.close()


def getmem(x, addr, length):
    data = bytearray()
    for l in x.cmd("getmem addr=0x%08X length=0x%X" % (addr, length))[1:]:
        data += bytes.fromhex(l.replace("??", "00"))
    return bytes(data)


def shot(path, width=640, height=480):
    """Screenshot from the scanout buffer: the GPU's display start
    (PCRTC_START, 0xFD600800) gives the framebuffer's physical address;
    pbkit's 32-bit X8R8G8B8 framebuffer is read through the 0x80000000
    physical mapping. (xbcapture only finds framebuffers of XDK D3D titles.)"""
    from PIL import Image
    x = Xbdm(XBOX)
    phys = int.from_bytes(getmem(x, 0xFD600800, 4), "little") & 0x0FFFFFFF
    raw = bytearray()
    total = width * height * 4
    base = 0x80000000 | phys
    while len(raw) < total:
        n = min(0x10000, total - len(raw))
        raw += getmem(x, base + len(raw), n)
    Image.frombytes("RGB", (width, height), bytes(raw), "raw", "BGRX").save(path)


def profile(delay, seconds, out_path, period=0.02, stack_words=192):
    """Sampling profiler: after `delay` seconds, every `period` the console
    is stopped, each game thread's Eip/Esp read (getcontext) and the top
    `stack_words` dwords of its stack copied (return-address candidates for
    a caller view), then resumed. Samples are written one per line:
    'thread eip esp w0 w1 ...' (hex)."""
    time.sleep(delay)
    x = Xbdm(XBOX)
    end = time.time() + seconds
    n = 0
    with open(out_path, "w", encoding="utf-8", newline="\n") as out:
        while time.time() < end:
            threads = x.cmd("threads")[1:]
            x.cmd("stop")
            rows = []
            for t in threads:
                ctx = {}
                for l in x.cmd("getcontext thread=%s control int" % t)[1:]:
                    k, _, v = l.partition("=")
                    ctx[k] = v
                eip = int(ctx.get("Eip", "0"), 16)
                esp = int(ctx.get("Esp", "0"), 16)
                words = b""
                if esp and stack_words:
                    try:
                        words = getmem(x, esp, stack_words * 4)
                    except Exception:
                        words = b""
                ws = [int.from_bytes(words[i:i + 4], "little") for i in range(0, len(words) - 3, 4)]
                rows.append("%s %08x %08x %s" % (t, eip, esp, " ".join("%08x" % w for w in ws)))
            x.cmd("go")
            out.write("\n".join(rows) + "\n")
            n += 1
            time.sleep(period)
    print("samples", n)


def main(argv):
    global XBOX
    XBOX = xbox_name()
    if len(argv) >= 2 and argv[0] == "--xbox":
        XBOX = argv[1]
        argv = argv[2:]
    if not argv:
        print(__doc__)
        return
    op = argv[0]
    if op == "push":
        src = argv[1]
        tool("xbcp", "/y", "/q", GAME_DIR + r"\default.xbe", GAME_DIR + r"\default.prev.xbe", check=False)
        tool("xbcp", "/y", "/q", src, GAME_DIR + r"\default.xbe")
        print("pushed", src)
    elif op == "run":
        seconds = float(argv[1]) if len(argv) > 1 else 60.0
        log = argv[2] if len(argv) > 2 else None
        listen(seconds, log, launch=GAME_DIR + r"\default.xbe")
    elif op == "listen":
        listen(float(argv[1]), argv[2] if len(argv) > 2 else None)
    elif op == "shot":
        shot(argv[1])
        print("captured", argv[1])
    elif op == "profile":
        profile(float(argv[1]), float(argv[2]), argv[3])
    elif op == "reboot":
        tool("xbreboot")
        print("rebooted")
    elif op == "cmd":
        x = Xbdm(XBOX)
        for l in x.cmd(" ".join(argv[1:])):
            print(l)
    else:
        raise SystemExit("unknown command " + op)


if __name__ == "__main__":
    main(sys.argv[1:])
