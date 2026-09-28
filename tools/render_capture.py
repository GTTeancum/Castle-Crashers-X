#!/usr/bin/env python3
"""Render a CCFRAME1 capture (runtime021 host harness) to a PNG.

Reconstructs one frame from the textures and quad draws the recovered game
code submitted, so the harness state can be checked by eye.

usage: render_capture.py <frame.ccframe> [out.png] [--size WxH] [--origin X,Y]
                        [--dxt5 | --argb4444]  (simulate a smaller texture format)
"""
import struct
import sys

import numpy as np
from PIL import Image


def tiled_offsets(w, h, log_bpp):
    """Byte offsets of each (y, x) texel in a Xenos 2D tiled surface."""
    y, x = np.mgrid[0:h, 0:w].astype(np.int64)
    aligned = (w + 31) & ~31
    macro = ((x >> 5) + (y >> 5) * (aligned >> 5)) << (log_bpp + 7)
    micro = ((x & 7) + ((y & 0xE) << 2)) << log_bpp
    off = macro + ((micro & ~0xF) << 1) + (micro & 0xF) + ((y & 1) << 4)
    return (((off & ~0x1FF) << 3) + ((y & 16) << 7) + ((off & 0x1C0) << 2)
            + (((((y & 8) >> 2) + (x >> 3)) & 3) << 6) + (off & 0x3F))


def dxt_colors(c0, c1, four):
    def rgb565(c):
        return np.stack([((c >> 11) & 31) * 255 // 31, ((c >> 5) & 63) * 255 // 63,
                         (c & 31) * 255 // 31], -1).astype(np.int32)
    a, b = rgb565(c0), rgb565(c1)
    four_m = four[..., None]
    c2 = np.where(four_m, (2 * a + b) // 3, (a + b) // 2)
    c3 = np.where(four_m, (a + 2 * b) // 3, 0)
    return np.stack([a, b, c2, c3], -2)


def decode_dxt(raw, w, h, kind):
    bw, bh = w // 4, h // 4
    bs = 8 if kind == 1 else 16
    blocks = np.frombuffer(raw[:bw * bh * bs], np.uint8).reshape(bh, bw, bs)
    # Xenos DXT data is 16-bit big-endian word swapped
    blocks = blocks.reshape(bh, bw, bs // 2, 2)[..., ::-1].reshape(bh, bw, bs)
    cb = blocks[..., bs - 8:]
    c0 = cb[..., 0].astype(np.int32) | (cb[..., 1].astype(np.int32) << 8)
    c1 = cb[..., 2].astype(np.int32) | (cb[..., 3].astype(np.int32) << 8)
    idx = (cb[..., 4].astype(np.uint32) | (cb[..., 5].astype(np.uint32) << 8)
           | (cb[..., 6].astype(np.uint32) << 16) | (cb[..., 7].astype(np.uint32) << 24))
    four = (c0 > c1) | (kind != 1)
    pal = dxt_colors(c0, c1, four)
    out = np.zeros((bh, 4, bw, 4, 4), np.uint8)
    for i in range(16):
        sel = (idx >> (2 * i)) & 3
        col = np.take_along_axis(pal, sel[..., None, None].astype(np.int64), -2)[..., 0, :]
        out[:, i // 4, :, i % 4, :3] = col
        if kind == 1:
            out[:, i // 4, :, i % 4, 3] = np.where((~four) & (sel == 3), 0, 255)
    if kind == 2:
        ab = blocks[..., :8]
        bits = np.zeros((bh, bw), np.uint64)
        for k in range(8):
            bits |= ab[..., k].astype(np.uint64) << np.uint64(8 * k)
        for i in range(16):
            out[:, i // 4, :, i % 4, 3] = ((bits >> np.uint64(4 * i)) & np.uint64(15)).astype(np.uint8) * 17
    elif kind == 3:
        ab = blocks[..., :8]
        a0 = ab[..., 0].astype(np.int32)
        a1 = ab[..., 1].astype(np.int32)
        bits = np.zeros((bh, bw), np.uint64)
        for k in range(6):
            bits |= ab[..., 2 + k].astype(np.uint64) << np.uint64(8 * k)
        eight = a0 > a1
        tab = [a0, a1]
        for j in range(1, 7):
            tab.append(np.where(eight, ((7 - j) * a0 + j * a1) // 7,
                                ((5 - j) * a0 + j * a1) // 5 if j < 5 else 0))
        tab[6] = np.where(eight, tab[6], 0)
        tab[7] = np.where(eight, (a0 + 6 * a1) // 7, 255)
        tab = np.stack(tab[:8], -1)
        for i in range(16):
            sel = ((bits >> np.uint64(3 * i)) & np.uint64(7)).astype(np.int64)
            out[:, i // 4, :, i % 4, 3] = np.take_along_axis(tab, sel[..., None], -1)[..., 0]
    return out.reshape(h, w, 4)


def decode_texture(w, h, fmt, raw):
    if fmt == 1:
        # the harness keeps surfaces linear; tiled_offsets() is for real GPU dumps
        offs = np.mgrid[0:h, 0:w][0] * (w * 4) + np.mgrid[0:h, 0:w][1] * 4
        b = np.frombuffer(raw, np.uint8)
        offs = np.clip(offs, 0, len(b) - 4)
        a, r, g, bl = (b[offs + k] for k in range(4))
        return np.stack([r, g, bl, a], -1)
    if fmt == 5:
        offs = np.mgrid[0:h, 0:w][0] * (w * 2) + np.mgrid[0:h, 0:w][1] * 2
        b = np.frombuffer(raw, np.uint8)
        offs = np.clip(offs, 0, len(b) - 2)
        v = (b[offs].astype(np.uint16) << 8) | b[offs + 1]
        chans = [((v >> s) & 15).astype(np.uint8) * 17 for s in (8, 4, 0, 12)]
        return np.stack(chans, -1)
    if fmt == 7:
        return decode_dxt(raw, w, h, 1)
    if fmt in (8, 9):
        return decode_dxt(raw, w, h, 2)
    if fmt in (10, 11):
        return decode_dxt(raw, w, h, 3)
    return np.full((h, w, 4), (255, 0, 255, 255), np.uint8)


def simulate(tex, mode):
    """Round-trip a decoded RGBA texture through a candidate Xbox format."""
    if mode == 'dxt5':
        import io
        h, w = tex.shape[:2]
        buf = io.BytesIO()
        Image.fromarray(np.ascontiguousarray(tex)).save(buf, 'DDS', pixel_format='DXT5')
        buf.seek(0)
        return np.asarray(Image.open(buf).convert('RGBA'))[:h, :w]
    if mode == 'argb4444':
        return ((tex >> 4) * 17).astype(np.uint8)
    return tex


def load(path):
    d = open(path, 'rb').read()
    assert d[:8] == b'CCFRAME1'
    frame, nt, nd = struct.unpack_from('<III', d, 8)
    off = 20
    texs = {}
    for _ in range(nt):
        data, w, h, fmt, nb = struct.unpack_from('<IIIII', d, off)
        off += 20
        texs[data] = (w, h, fmt, d[off:off + nb])
        off += nb
    draws = []
    for _ in range(nd):
        prim, count, stride, blend, tex = struct.unpack_from('<IIIII', d, off)
        off += 20 + 64
        vb, = struct.unpack_from('<I', d, off)
        off += 4
        verts = [struct.unpack_from('>5fI', d, off + i * stride)
                 for i in range(min(count, vb // max(stride, 1)))] if stride >= 24 else []
        off += vb
        draws.append((prim, count, blend, tex, verts))
    return frame, texs, draws


def raster_tri(canvas, tex, p, uv, col, blend):
    H, W = canvas.shape[:2]
    x0, x1 = int(max(0, np.floor(p[:, 0].min()))), int(min(W, np.ceil(p[:, 0].max())))
    y0, y1 = int(max(0, np.floor(p[:, 1].min()))), int(min(H, np.ceil(p[:, 1].max())))
    if x0 >= x1 or y0 >= y1:
        return
    ys, xs = np.mgrid[y0:y1, x0:x1].astype(np.float64) + 0.5
    (ax, ay), (bx, by), (cx, cy) = p
    den = (by - cy) * (ax - cx) + (cx - bx) * (ay - cy)
    if abs(den) < 1e-9:
        return
    l0 = ((by - cy) * (xs - cx) + (cx - bx) * (ys - cy)) / den
    l1 = ((cy - ay) * (xs - cx) + (ax - cx) * (ys - cy)) / den
    l2 = 1 - l0 - l1
    m = (l0 >= -1e-6) & (l1 >= -1e-6) & (l2 >= -1e-6)
    if not m.any():
        return
    u = l0 * uv[0, 0] + l1 * uv[1, 0] + l2 * uv[2, 0]
    v = l0 * uv[0, 1] + l1 * uv[1, 1] + l2 * uv[2, 1]
    c = (l0[..., None] * col[0] + l1[..., None] * col[1] + l2[..., None] * col[2]) / 255.0
    if tex is not None:
        th, tw = tex.shape[:2]
        tx = np.clip((u * tw).astype(np.int64), 0, tw - 1)
        ty = np.clip((v * th).astype(np.int64), 0, th - 1)
        s = tex[ty, tx].astype(np.float64) / 255.0
        s = s * c
    else:
        s = c
    dst = canvas[y0:y1, x0:x1]
    a = s[..., 3:4]
    if blend == 0x00010001:
        out = s[..., :3]
    elif blend == 0x07010701:  # ONE, INV_SRC_ALPHA (premultiplied)
        out = s[..., :3] + dst * (1 - a)
    elif blend == 0x01010101 or (blend & 0xFF) == 0x01 and (blend >> 8 & 0xFF) == 0x01:
        out = np.clip(s[..., :3] + dst, 0, 1)
    else:  # SRC_ALPHA, INV_SRC_ALPHA
        out = s[..., :3] * a + dst * (1 - a)
    dst[m] = out[m]


def main():
    args = sys.argv[1:]
    size = None
    origin = (0.0, 0.0)
    if '--size' in args:
        i = args.index('--size')
        size = tuple(int(x) for x in args[i + 1].split('x'))
        del args[i:i + 2]
    recompress = None
    for flag in ('--dxt5', '--argb4444'):
        if flag in args:
            recompress = flag[2:]
            args.remove(flag)
    if '--origin' in args:
        i = args.index('--origin')
        origin = tuple(float(x) for x in args[i + 1].split(','))
        del args[i:i + 2]
    src = args[0]
    dst = args[1] if len(args) > 1 else src.rsplit('.', 1)[0] + '.png'
    frame, texs, draws = load(src)
    if size is None:
        # The game's vertex constants are an orthographic 640x480 projection
        # (c0 = 2/640, c1 = -2/480; found in the command ring), matching the
        # 640x480 video mode the console reports: vertices are screen pixels.
        size = (640, 480)
    W, H = size
    canvas = np.zeros((H, W, 3))
    cache = {}
    for prim, count, blend, taddr, verts in draws:
        if taddr in texs and taddr not in cache:
            cache[taddr] = simulate(decode_texture(*texs[taddr]), recompress)
        tex = cache.get(taddr)
        if prim == 13:
            groups = [verts[i:i + 4] for i in range(0, len(verts) - 3, 4)]
            tris = [(g[0], g[1], g[2]) for g in groups] + [(g[0], g[2], g[3]) for g in groups]
        elif prim == 4:
            tris = [tuple(verts[i:i + 3]) for i in range(0, len(verts) - 2, 3)]
        elif prim == 5:
            tris = [tuple(verts[i:i + 3]) for i in range(len(verts) - 2)]
        else:
            continue
        for t in tris:
            p = np.array([(v[0] - origin[0], v[1] - origin[1]) for v in t])
            uv = np.array([(v[3], v[4]) for v in t])
            col = np.array([((v[5] >> 16) & 255, (v[5] >> 8) & 255, v[5] & 255, v[5] >> 24)
                            for v in t], np.float64)
            raster_tri(canvas, tex, p, uv, col, blend)
    Image.fromarray((np.clip(canvas, 0, 1) * 255).astype(np.uint8)).save(dst)
    print(f'frame {frame}: {len(draws)} draws, {len(texs)} textures, {W}x{H} -> {dst}')


if __name__ == '__main__':
    main()
