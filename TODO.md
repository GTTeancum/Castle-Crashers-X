# TODO

Deferred until the port is fully playable.

## Rewrite plan (direction set 2026-10-02)

The port must be an original Xbox game at its core; the recompiled Xbox 360
code is the oracle that native code is checked against, then replaced.

**What the game is** (call-graph and string survey of the image, 2026-10-02;
map in `logs/` is not kept, re-derive from `runtime*/generated` if needed):
gameplay is ActionScript bytecode inside the SWF assets (packed in the .pak
files), run by a native Flash-style VM: ~350 functions / 65k translated
lines at 0x8207B000-0x82096FFF (ActionScript ops `sub_82088CF0`,
`sub_82087F70`; built-in method table `sub_820906A8`; parser; MovieClip
display list with the sprite leaf `sub_820855D8`). The scripts call ~105
native functions registered by `sub_8206FDB8` (f_BSP*, waypoints, quit,
f_ChangeLevel, ...) and `sub_82070F68` (ChangeMovie, GetFlashGlobal,
WriteSaveGame, UnlockAchievement, session calls), dispatched by
`sub_82071280`. Native game code around the VM: main loop / game manager
(0x8206E000-0x8207AFFF, `sub_82070AC8` init+loop, `sub_82075C88` update,
`sub_820759A8` render), BSP collision (`sub_8206F988`), scene graph + pak
loader + game heap (0x82097000-0x8209DFFF, `sub_8209A728`, `sub_8209C550`,
`sub_8209BDD8`/`sub_8209BF18`), vector-shape rasterizer (0x820B0000-
0x820B4FFF), front-end menus (0x82054000-0x8206DFFF), audio manager
(0x8209E000). About 60% of the 3,614 functions (2,550 / 352k lines) are
Xbox 360 glue: D3D/Xenos device layer (465 functions), XAudio/XMA (426),
Live/network middleware (719), XAM/voice (271), CRT (522), zlib (30).

**Order of native replacement** (each step oracle-checked on the host:
bit-identical outputs for pure functions, pixel-identical captured frames
for drawing, identical verification counts for everything else):
1. Drawing tail (in progress): exact bind skipped; native cull
   `sub_820A8DD8`; native quad emitter `sub_820A9308`; next the sprite
   corners `sub_82085110`, matrix push `sub_82086090` / multiply
   `sub_82085AD8`, colour `sub_82084100`. Then the sprite leaf itself and
   the display-list walk that calls it.
2. Platform glue replaced outright by the Xbox side (already: renderer,
   audio mixer, pad, clock, files; remaining: whatever the game still calls
   in the D3D/XAudio/XAM/Live clusters, which should be stubbed or routed,
   never translated).
3. Scene graph, pak loader and game heap natively (the game's data in plain
   Xbox memory, no address lookup).
4. The Flash VM: ActionScript interpreter, MovieClip display list, timeline,
   parser, vector rasterizer. This is the core of the rewrite; the
   recompiled VM stays as the oracle for script behaviour (same SWF bytes
   in, same display list out).
5. Main loop, menus, BSP collision, audio manager.

Dropped as translation-layer tuning: flat page table, exact-body trims,
30 Hz update, GPU vertex transform.

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
- [ ] Direction (user, 2026-10-02): this is a rewrite. The port must be an
      original Xbox game at its core, not a 360 program behind a translation
      layer; the recompiled 360 code is the oracle that native code is
      checked against (bit-identical outputs, pixel-identical frames on the
      host), then replaced. Reviews of 2026-10-02: level frame 45 ms, 4 of 5
      instructions are translation overhead (memory path 32%, register file
      25%, FP glue 10%, calls 8%), so tuning the layer gives 1-2 FPS a step.
      Native replacement order: (1) per-sprite drawing tail: [x] exact bind
      sub_820A89F8 skipped (360 device state), pixel-identical at frames
      7500/9362; [x] native cull sub_820A8DD8; [x] native quad emitter
      sub_820A9308 (both pixel-identical at frames 7500 and 9362 together
      with the bind skip, 2026-10-02; clean XEMU run of CC-H7-native.iso:
      level 1 tavern 24 FPS (update 21 ms, draw 17 ms), castle hall 31-34
      FPS (update 12-16 ms, draw 15-16 ms), busiest fight 16-20 FPS with
      update 25-35 ms; menus 40-57 FPS. Drawing is no longer the larger
      half; the game update is. The host capture now records the
      texture from the bind wrapper itself, since it used to read it in the
      exact bind's prologue hook; written from the exact
      body: count != 4 maps points to pixels x' = w(x+0.5), y' = h(y+0.5);
      colour bytes [R G B A] -> premultiplied ARGB (x*a>>8); z = 100; ring
      at 0x822673D8; modes 2/6/10/11/14/15 stay exact; host probe
      CC_QUADLOG confirmed the colour rule and uv order on 24 quads);
      (2) native sprite math sub_82085AD8/sub_82085110/sub_82084100/
      sub_82086090 with host bit-identity checks; (3) the sprite/scene
      objects themselves in plain Xbox memory (no address lookup); (4) the
      main loop. Dropped as translation-layer tuning: flat page table,
      exact-body trims, 30 Hz update, GPU vertex transform.
- [ ] Memory: Xbox code size matters (it shares the 64 MB). Inlining the
      memory slow path once grew .text 12.2 -> 16.9 MB and the game failed
      to boot; keep slow paths out of line. Now ~9.8 MB with SDL.
- [x] The 4 MB texture zone thrashed the menus without the swap (menus draw
      ~4.5 MB per frame); zone raised to 6 MB.

## Diagnostics on the Xbox

- The play build shows a harness stop on screen: a dark red bar with the
  error code (Error enum: 8 capacity, 9 unsupported, 3 memory, ...) and the
  guest address in hex (cc_xr_show_fail). 2026-10-02: Quit stopped at
  9 @ 0x8214A584 = the direct NtClose import, which was fail-closed; the
  play build now closes file handles and accepts other handles there.

## Xbox 360 leftovers in the menus

- [x] Main menu (user, 2026-10-01): Local Game, Player Statistics, Help &
      Options, Quit; bottom-aligned where Return to Arcade was. Play build
      only (bodies.inc "Main menu trim"): the exact constructor
      sub_820623C0 builds eight items via sub_82067020 (text, string id) +
      sub_82065F78 (append, centred layout, 30 px apart); the port drops
      ids 387/597/598/600/601 at the append, shifts the rest down 60 px,
      no-ops text updates on a missing item (sub_82067230) and the slot-6
      refresh (sub_82062990), and rewrites string 602's English text
      ("Return to Arcade" at 0x8201545C) to "Quit". Quit ->
      __imp__XamLoaderLaunchTitle -> cc_xbox_return_to_dashboard()
      (XLaunchXBE C:\xboxdash.xbe, else HalReturnToFirmware). Verified
      on the host play-mode build (frame 2000 capture) and in XEMU (menu,
      book, character select, level 1). Quit verified in XEMU 2026-10-02
      (SCRIPT=quit disc: the game leaves to the dashboard; XEMU without a
      dashboard shows "Please insert an Xbox disc"). On the way out the play
      build needed: NtClose accepting non-file handles, main-thread waits on
      unknown objects returning signalled (NtWaitForSingleObjectEx; started
      worker threads must still park there or they spin forever: that was
      the black screen of the first Quit disc), NtWriteFile /
      NtFlushBuffersFile / XMsgCancelIORequest / NtFreeVirtualMemory
      tolerant stubs. The five dropped item objects are left allocated
      (~300 B per menu build).
- [x] 2026-10-02 XEMU text went nearly invisible after the pack-aware
      texture change: text textures are registered before their shapes are
      written, so the registration-time pack lookup missed and the Xbox
      rasterized them itself. Fixed by retrying the lookup at first bind.
      Also: linear (A8R8G8B8/A4R4G4B4) textures such as the font atlas are
      now re-sampled on every bind (every 61st byte) and reconverted when
      they change, since the game draws new glyphs into the atlas after
      the renderer's first copy.
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
