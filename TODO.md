# TODO

Deferred until the port is fully playable.

## Memory budget (biggest known porting constraint)

**Decision (2026-09-28): retail 64 MB consoles only.** No 128 MB
(modded/devkit) target, not even as a stepping stone.

**Measured 2026-09-27** in the host test harness, counting only the
graphics/streaming ("physical") memory the game allocates:

- main menu: about 62 MB live
- loading the first level (MAIN.PAK, FX.PAK, level music): past 100 MB
- character select with the level loading behind it: about 183 MB peak

The Xbox 360 has 512 MB; the original Xbox has 64 MB in total, shared by
code, game data, graphics and audio. The test harness currently gives the
game a 224 MB pool so gameplay can be reached and measured; the native Xbox
build cannot do that.

**Breakdown, measured 2026-09-28** (`CC_MEM_REPORT=<frame>` in the host
harness; frame 9000 is inside the first level):

- 166 MB live in the level. **158 MB of it is ~2,800 sprite textures**
  stored as uncompressed 32-bit colour (A8R8G8B8), created by the asset
  loader (texture records built in `sub_82091AC0`). Only ~27 MB of those
  textures have actually been drawn in the first ~2,000 frames of the
  level; the rest is preloaded art for the whole level.
- ~5 MB audio stream buffers, 2 MB font, <1 MB everything else.
- Menu: 62 MB live, ~32 MB of it textures already drawn on the menu.

What that means for the budget: the original Xbox GPU reads DXT-compressed
textures natively. DXT5 is 4x smaller than 32-bit colour, so the level's
158 MB of textures would be ~40 MB; 16-bit colour would be ~79 MB.
Compressing at load time (or converting the pak art offline) is the main
lever; unloading art the level no longer needs is the second.

**Rough 64 MB budget (first pass):**

| Item | Now (level) | Target |
| --- | --- | --- |
| Kernel + system reserve | — | ~4 MB |
| Game code (XBE) | 10 MB | 10 MB |
| Game data image (guest globals) | 3 MB | 3 MB |
| Framebuffers 640x480, double buffered | — | 2.5 MB |
| Game's own memory pool | 16 MB reserved, 12.6 MB used | ~13 MB |
| General heap | ~20 KB | ~0 |
| Sprite textures | 158 MB (32-bit) -> streamed DXT5 cache, 16 MB limit, 2-7 MB used | 16 MB |
| Texture job snapshots (596 B each) | 1.7 MB | 1.7 MB |
| Rasterizer temporaries (one texture at a time) | up to ~6 MB for a 512x512 | ~6 MB |
| Audio | 5 MB (music stream buffers; audio stubbed) | ~6 MB |
| Everything else | <1 MB | ~1 MB |

The textures cannot all be resident even compressed (~40 MB as DXT5), so
the level's art has to be streamed: keep what is on or near the screen,
load the rest as the camera approaches. About 27 MB (32-bit) had actually
been drawn in the first ~2,000 frames of level 1, ~7 MB as DXT5.

**Streaming policy (user direction 2026-09-28):** stream music; preload
sound effects where possible; stream art wherever it can be streamed.

**To do:**

- [x] Measure the true gameplay peak once a level is running.
- [x] Break it down by what it is (textures, audio, vertex data, render
      targets) to see where the space goes.
- [x] Check what the textures look like after DXT5 compression.
      `render_capture.py --dxt5` / `--argb4444` re-renders a captured frame
      with every texture round-tripped through the format. Level frame 9362:
      DXT5 mean colour error 1.6/255, visible only as faint blocking where
      two flat colours meet; 16-bit colour 3.5/255, a slight tone shift.
      Side-by-side: `logs/frames_full/texture_format_compare.png`
      (original | DXT5 | 16-bit, 3x zoom). DXT5 is the better and smaller
      choice.
- [x] Compress textures to DXT5 as they are created. Done 2026-09-28:
      the art is vector shapes rasterized at load (`sub_820B1078` allocates
      and parses, `sub_820B1478` rasterizes). The port shrinks each texture
      block to its DXT5 size at allocation, lets the rasterizer write into
      one transient 32-bit scratch block, and compresses into the texture.
      Level 1: **166 MB -> 47 MB live, peak 184 MB -> 51 MB**; the game runs
      the identical instruction/memory-op counts (it never reads texture
      pixels on the CPU) and frames look right (`logs/frames_dxt/`).
      `CC_TEXTURE_DXT5=0` turns it off on the host for comparison.
- [x] Stream the art. Done 2026-09-28: each texture keeps a 596-byte
      snapshot of its rasterizer job; the compressed pixels live in a cache
      (16 MB limit, least recently drawn evicted) and a missing texture is
      re-rasterized by replaying the exact rasterizer on its next bind.
      Textures are rasterized on first bind, not at load. Every replay is
      checked against the hash of the first compression: a 2 MB stress
      cache forced 45,614 replays over 10,000 frames with **zero
      mismatches**. Level 1 graphics memory: **10 MB live, 12 MB peak**
      (was 166 / 184 MB). Working set: ~1 MB drawn per frame, <3 MB per
      10 s window. Host knobs: `CC_TEX_CACHE_KB`, `CC_TEX_EAGER=1`,
      `CC_WORKSET=1`.
- [ ] Measure re-rasterization cost on the Xbox CPU (one core, 733 MHz)
      and decide whether to pre-rasterize textures near the camera.
- [ ] Measure the whole session against 64 MB on the Xbox build itself
      (arenas sized for retail, not the harness's 224 MB).
- [ ] Audio: re-encode (XMA is not playable on the original Xbox), stream
      music, preload sound effects.

## Xbox 360 leftovers in the menus

- [ ] Starting a story game shows "Sign in to Xbox LIVE to post your score
      to the leaderboards" (A continues). Remove it on the original Xbox.
- [ ] The main menu still lists Xbox LIVE Game, Leaderboards,
      Achievements and Download Content; hide them or grey them out.

## Language

The console reports North America / English, so the game shows English
text. The 360 build carries 9 languages; the original Xbox dashboard
language could select among them later (read it at boot and map it).

## Profiles and saves

**Decision (2026-09-27):** one shared profile on the original Xbox. Every
player levels up the same set of characters; progress lives in one save
folder on the Xbox hard drive.

**Current temporary state:** nobody is ever signed in. The menu's profile
check (the `sub_82053C70` wrapper in `runtime021/bodies.inc`) runs with its
"needs a signed-in profile" argument cleared, the sign-in state reports
not-signed-in for every controller, and the Xbox 360 sign-in screen is
fail-closed. This is only there to reach gameplay; it gets removed when the
shared profile is built.

**To do:**

- [ ] Find out how Castle Crashers saves: what triggers a save, and whether
      each save covers one character or rewrites the whole profile.
- [ ] If saves rewrite the whole profile, merge at save time so two players
      on the same profile can't overwrite each other's progress (keep the
      higher level; unlocks stay unlocked). This needs the save file layout.
- [ ] Build the shared profile: every controller that joins counts as a
      player on it; player names shown as "Player 1" to "Player 4" by
      controller slot.
- [ ] Remove the `sub_82053C70` wrapper so the game's own sign-in check runs
      unmodified against the shared profile.
- [ ] Route profile settings and save content (`XamUserReadProfileSettings`,
      `XamUserWriteProfileSettings`, `XamContentCreateEx`) to the shared save
      folder on the hard drive.
