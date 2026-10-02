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

**64 MB budget, third pass (2026-09-28): enforced.** The host harness now
maps every guest region at its retail size, so the 10,000-frame session
(boot, menus, character select, level 1) runs inside the budget; any
overflow fails loudly. The game runs identical instruction and memory-op
counts and pixel-identical frames at these sizes.

| Item | Size | Level 1 peak |
| --- | --- | --- |
| Game heap (0x71000) | 14 MB | 13.3 MB |
| Game main pool (0x10000000, game reserves 16 MB) | 4.5 MB backed | 3.9 MB |
| CRT heap | 1 MB | 20 KB |
| Graphics arena (360 surfaces and ring aliased) | 2.1 MB | - |
| Physical: general zone | 4.5 MB | 3.3 MB |
| Physical: small-block zone | 1 MB | 0.26 MB |
| Physical: texture stub zone | 1.5 MB | 1.07 MB |
| Texture cache zone (buddy, overflow to Z: swap) | 6 MB | ~4.5 MB at menus |
| Game data image | 2.9 MB | - |
| **Guest total** | **37.5 MB** | |
| Game code (XBE) | 10 MB | |
| Sound-effect cache | 2 MB | |
| Texture job snapshots | 1.7 MB | |
| Kernel, system, framebuffers, NV2A push buffer | ~6.4 MB | |
| **Estimated total** | **~56 MB (~8 MB headroom)** | |

Not yet counted: the Xbox renderer's own buffers (still to be written) and
music stream buffers (small). Later levels may peak higher than level 1;
the zones fail loudly if they do, and the headroom above is where they
grow.

Done in this pass: graphics arena 5 -> 2.1 MB (unused 360 surfaces and
command ring aliased); game files read from disk on demand; sound effects
loaded on first play (2 MB cache, bit-identical audio); texture cache
6 -> 4 MB in its own buddy-allocated zone with a Z: scratch swap (a whole
session: 2,985 swap-ins, zero re-rasterizations, every swap-in hash
verified); separate zones for small blocks and texture stubs (the
retail-sized arena fragmented otherwise); texture stubs 16-byte aligned.

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
- [ ] Shrink the game's two heaps. End of the 10,000-frame session
      (`CC_MEM_REPORT=9990`): game heap at 0x71000 high-water 13.3 MB,
      main pool 13.5 of 16 MB, GPU command arena high-water 4.9 MB,
      graphics blocks 14 MB live. With code (10 MB), image (3 MB), kernel,
      framebuffers and job snapshots that is ~68 MB: about 4 MB over before
      audio. Next: find what fills the two heaps (loaded paks: SOUNDS.PAK
      alone is 16.5 MB; MAIN 2.7 MB, SKY 0.5-2.4 MB, LEVEL2) and which of it
      can be streamed or dropped after use.
- [x] Strip the unused MP3 data from SOUNDS.PAK (`tools/strip_sound_bank.py`):
      the SWF sound bank the game loads whole kept 9.8 MB of MP3 the 360
      never plays (effects play from game:\sounds\*.xma). Main pool
      13.5 -> 3.9 MB; identical instruction count and frames.
- [x] Audio: the port's own PlatformAudio layer (`runtime021/audio.inc`):
      effects from sfx.xab loaded when the game registers them, music
      streamed block by block from music/<name>.xad, software mixer to
      48 kHz stereo. Host recording (`CC_AUDIO_WAV=`) of the 10,000-frame
      session: music and effects throughout, music at exact speed/pitch
      (correlation 1.000 against ffmpeg's decode of the original XMA),
      0.004% clipped samples.
- [ ] Xbox audio output: feed the mixer to AC97 (nxdk `XAudioInit`) and
      verify in XEMU; put sfx.xab and music/*.xad on the disc.
- [ ] The game asks for `sound_gemsplin_loop` (the file is
      `sound_gemspin_loop`); the 360 build fails the same lookup. Decide
      whether to fix the name.

## Native (XEMU, retail 64 MB) status

- 2026-09-28: the Xbox build boots and runs the game to frame 7,500 (inside
  level 1) on XEMU's retail 64 MB configuration. No renderer yet: the
  screen shows only the diagnostic log. Speed under XEMU: ~7 frames/s in
  the intro, ~3 in the menus.
- [x] Xbox renderer (pbkit/NV2A) from the game's draw calls.
- [x] Sound: music heard in XEMU at full speed (2026-09-28).
- [x] Controller input (nxdk SDL); a real pad takes over from the script.
      In XEMU, set Machine > Input to an Xbox controller first; the game
      picks it up at the first press (2026-10-01: played through level 1
      by hand, no gameplay bugs seen, only low FPS).
- [x] Real-time game speed: the game steps by measured frame time (exact
      main loop clamps dt to 1/60..1/10 s), so the play build feeds it a
      real clock.
- [ ] Built-in input script is live in the play build until the first pad
      press (useful for unattended XEMU A/B runs; must be a build switch, off
      by default, before a playable release).
- [ ] Z: scratch swap: never exercised natively (no eviction happened with
      the 6 MB zone); the first run's 4 MB zone reported it unavailable.
- [ ] Performance toward a steady 30 FPS (33 ms). XEMU 2026-09-28 after
      the 360 draw skip and inline memory path: menu ~57 ms (17 FPS), level
      80-114 ms (update ~30, render ~56). Remaining cost is the game's own
      scene code, spread thin; next levers are 64-bit register arithmetic
      on the 32-bit CPU and x87 float rounding. XEMU speed is not real
      hardware speed; measure on a console when possible.
- [ ] Memory: Xbox code size matters (it shares the 64 MB). Inlining the
      memory slow path once grew .text 12.2 -> 16.9 MB and the game failed
      to boot; keep slow paths out of line. Now ~9.8 MB with SDL.
- [x] The 4 MB texture zone thrashed the menus without the swap (menus draw
      ~4.5 MB per frame); zone raised to 6 MB.

## Xbox 360 leftovers in the menus

- [ ] Main menu (user, 2026-10-01): keep only Local Game, Player Statistics,
      Help & Options, and "Quit" (was Return to Arcade; must exit to the
      dashboard), bottom-aligned where Return to Arcade sits now. Findings:
      the menu labels are localized string records in the image, table at
      0x8222D58C, 10 pointers per record (slot 0 English); record ids:
      Local Game 0, Xbox LIVE Game 10, Leaderboards 2110, Achievements 2120,
      Help & Options 2130, Unlock Full Game 2140, Download Content 2150,
      Return to Arcade 2160 (ids = pointer index; the English string
      "Return to Arcade" is at 0x8201545C, UTF-16 BE). "Return to Arcade"
      ends in exact sub_820B6908 (XLaunchNewImage) -> __imp__XamLoaderLaunchTitle
      (bodies.inc, fail-closed today): on the Xbox make it return to the
      dashboard (XLaunchXBE("C:\xboxdash.xbe"), else HalReturnToFirmware).
      Still to find: the function that builds the menu's item list (it uses
      string ids, not addresses; grep for the ids above in one function).

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
