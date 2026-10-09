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

**ActionScript interpreter map** (read-only survey 2026-10-02; host level
profile: game update ~55% of a frame, most of it script execution):
- Fetch/dispatch loop in four copies, each naming itself by its error
  string: `sub_8207BAE8` OnEnterFrame, `sub_8207B8B8` OnLoad,
  `sub_8207B630` ProcessEndOfFrameAction (frame scripts), `sub_8207B150`
  CallCustomFunction (user functions). Opcode = code[pc] (code ptr at
  this+20); >= 0x80 has an LE u16 length; handler table 0x8215A518 (0xA5
  entries), handler(AS*, AS*, rec{+0 op, +4 len, +8 data}, ?, done*) returns
  an extra pc delta. Standard AVM1 actions plus fused A0 (GetVariable with
  inline name, `sub_82081C08`), A2 (GetMember inline name, `sub_82081E18`,
  hot), A4 (SetVariable inline, `sub_820822D8`), A1/A3. No DefineFunction2.
- Values: 12-byte pool slots (1256 at P+5028, P = VM+10372, in-use byte
  +8, allocator `sub_82082488` scans linearly from a rover at P+20100);
  operand stack of Value* at P+0, count at P+5024. Tag +0: 0x80000000
  undefined, 2 bool, 4 int, 8 string (u16 interned id), 16 number (float),
  object types 1/64/128 (MovieClip)/1024/4096/8192/0x4000/0x40000;
  refcounted mask 0x7C6C1 (u16 refcount at obj+24 via `sub_82066EA8`).
- Names are u16 ids (`sub_8209D948` hash Σc[i]*(119+i), linear probe;
  builtin ids from `sub_820906A8`). GetVariable `sub_8207AF80`: locals
  `sub_82079BE0`, then object map `sub_8208C140` (sorted map lookup
  `sub_82082390`), then the scope stack. Clip GetMember `sub_8208B438`.
  `sub_82088CF0` (38% inclusive) is Clip::CharToFunc, the builtin/user
  function call wrapper reached from CallFunction `sub_8207E048`.
- Per frame: `sub_8209DE50` -> `sub_820915F0` -> root advance
  `sub_82088A08` -> MovieClip::Tick `sub_8208A228` (runs OnEnterFrame /
  OnLoad and frame scripts on clip+160, recurses into children). Render
  traversal is `sub_82091248` (separate).
- Native so far: `sub_82082390` map lookup, `sub_82079BE0` locals read,
  `sub_82066EA8` refcount step, `sub_8206F918`, pool allocator, push decode.
- 2026-10-03 native interpreter (runtime021/as_native.inc and the
  as_ops*.inc files it includes; play build only): the four dispatch loops,
  native handlers for 39 opcodes (every opcode the 4P level-13 profile
  executes more than ~8k times in 4,000 frames) and the value / variable / member helpers
  they use (GetVariable `sub_8207AF80`, SetVariable `sub_8208C2A0`, Var
  assign `sub_8208BF38`, locals free `sub_82079A00`, map insert
  `sub_820936B0`, ToString-id / ToNumber / ToInt `sub_82082890` /
  `sub_82082700` / `sub_82082BB0`, clip GetMember / SetMember / property
  get / set `sub_8208B438` / `sub_8208B520` / `sub_82089C00` /
  `sub_82089F70`, timeline tag step `sub_8208AB98` / `sub_8208ADE8`), plus
  the display-list draw walk `sub_8208A7A0` and the sprite leaf
  `sub_820855D8` (runtime021/as_render.inc). Same guest memory effects as
  the recompiled bodies, which stay as sub_X_exact. Opcodes without a
  native handler run their recompiled handler from the native loop (rare
  ones: 04-09, 15, 22, 24-26, 30, 33, 34, 3A, 3B, 3F, 40, 55, 60-64, 81, 87,
  9A, 9B, 9F).
  Host checks: CC_STATE_HASH=<n> hashes every writable guest region except
  the stack each n frames (CC_STATE_DUMP=<dir> writes them); runs with
  CC_AS_EXACT=1 (all recompiled) and without must print the same hashes.
  CC_AS_GUEST=<hex ops> and CC_EXACT_FNS=sub_X,... switch single handlers
  or helpers back for bisecting (logs/statecmp.sh, logs/statediff.py).
  Two kinds of bytes legitimately differ and are excluded: the 3 padding
  bytes after a script value's in-use byte (the game copies values as three
  words, so their padding carries stale stack bytes of frame temporaries;
  the hash keeps only the first byte of a word whose word 8 bytes earlier is
  a value type), and stale heap contents those copies leave behind
  (CC_HEAP_ZERO=1 zeroes game-heap blocks at alloc and free in both runs).
  With those, native == exact at every checkpoint of the default run (47
  checkpoints to frame 9400) and of the 4P level-13 run (64 checkpoints to
  frame 16000); frames 7500/9362 pixel-identical.
  XEMU, same window, 4P level 13 real clock: burning village 25-35 FPS
  (disc H16, recompiled interpreter) -> 37-47 FPS (H17, native), walls
  20-26 -> 33-43 FPS; update 12-31 ms -> 6-18 ms, render 12-15 -> 8-11 ms.
  REAL CONSOLE (2026-10-03, dev kit via XDK tools, tools/xbox_console.py;
  the user's direction is to test only there from now on), same native
  build (disc C1): 4P level-13 combat 17-23 FPS, update 25-40 ms, render
  16-18 ms; menus 57-59 FPS. XEMU on this PC ran the game's CPU work about
  2-2.5x faster than the console, so the console numbers are the target.

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
      half; the game update is.
      2026-10-03, after the Xbox/XEMU analysis (read-only multi-agent
      review): XEMU, same scripted run, back to back in a quiet window:
      disc H12 (the 2.6 KB register-file copy in the native matrix push
      removed - it was the 31 -> 23 FPS regression of H8-H10; fast
      memcpy/memset/memmove in xbox_shims.cpp instead of nxdk's unoptimised
      PDCLib byte loops; builtin memcpy/memset in the generated range;
      fall-through memory fast path with cold slow paths; fctidz/fctiwz
      from the bit pattern without x87 control-word switches; integer fma
      guard; empty prologue on Xbox with wrappers for the 4 hooked
      functions; font atlas sampled once per frame; texture/blend state
      sent only on change; play-build cc_log off; SDL events ignored):
      castle hall ~42 FPS (update 8-9 ms, render 10 ms). Disc H13 (H12 plus
      the 64 KiB guest page table g_page_host: every guest access is a
      table load, an add and the byte swap): castle hall 58-60 FPS (update
      4 ms, render 6 ms; capped by the game's 60 Hz pacing), tavern and
      fights 48-58 FPS, menus 43-59. Host oracle and pixel checks
      identical; release verification unchanged. Disc H14 adds the
      register view (r1, r14-r31, f14-f31 and the CR fields as C++ locals
      in every generated function; save/restore helpers become no-ops;
      runtime021/view_plain.inc lists the functions that keep the plain
      Context: continuation chunks that read a callee-saved register first,
      their direct callers, the harness's split prefix/suffix functions and
      the graphics device layer, whose resume shims inspect callee-saved
      registers; CC_NO_VIEW turns it off): host oracle clean, 7500/9362
      pixel-identical; XEMU 57-61 FPS everywhere in the run, the same as H13
      under the 60 Hz cap (update ~3 ms, render ~6 ms); menus slightly
      higher. A BENCH=1 build is the way to see the remaining headroom.
      2026-10-03 four-player combat (disc CC-H16-4p-level13.iso, make
      FOURP=1 LEVEL=13: scripted pads 1-3 join, the run goes from character
      select straight into level 13, the castle keep battle, and all four
      knights fight in a loop): burning-village fight 26-42 FPS (update
      9-23 ms, render 12-14 ms), wall fight 24-39 FPS (update 10-26 ms),
      barracks 37-41 FPS. Four-player combat is the stress case: at the peaks
      the game update (scripts for four players and many enemies) is ~20-26
      ms, so the native script interpreter core is the next lever. The run
      then continues through level 19 and the map into level 11, whose load
      stops at 3 @ 0x10529000: the main pool backs only 4.5 MiB (the next
      level needs more; see "later levels' memory").
      2026-10-09 (branch speed-integ, console): flat guest window (no page
      table; .text 12.1 -> 7 MB), native interpreter fast paths, display
      list caches, fused native sprite/text drawing, native timeline seek,
      game clock = real frame time (the 30 FPS present lock had made the
      game run at half speed: movies ticked every other frame), no double
      frame wait, frame end without a GPU wait (CPU/GPU overlap), main pool
      7 MiB, full texture pack (7,009 textures, 253 MB, eager bake of
      levels 1-33, first-use order with 512 KiB read-ahead). Scripted 4P
      test (menus at the old step, fight at true speed through level 13,
      the map and level 11): steady fight seconds 80% at 30 FPS, 96% at
      28+, average 29.0; area changes and level loads dip to 10-20 FPS for
      about a second. Then the font check backs off, game files are read
      straight into guest memory (one NtReadFile per request), and audio
      top-ups moved into the vblank wait: fight seconds 88% at a full 30
      FPS, 95% at 28+, average 29.1 (runs differ in load: the real clock
      makes every console run play out differently, so compare script ops
      per frame too). Open: level 25 with four players stops on a stray
      write; area-change hitches (heap churn, texture reads, load); the
      built-in input script still runs in the play build until a pad press.
      The host capture now records the
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
- [x] Starting a story game showed "Sign in to Xbox LIVE to post your score
      to the leaderboards" (A continues). 2026-10-03: skipped in the play
      build (front-end menu 18, opened by the game-mode book's handler
      sub_82063758 for players not signed in to Live; the sub_82053BC8
      SetMenu wrapper takes the signed-in path instead: sub_82063C00 /
      sub_82063F18 / sub_82063DC8 by the mode at +12). The scripted input
      drops the two presses that landed on the notice; host CC_LIVE_NOTICE=1
      keeps it (logs/oracle.sh). Host: character select right after the
      book, frames 7500/9362 still pixel-identical to the references.
- [x] Main menu items vertically centred between the logo's bottom (y 134)
      and the "A Select" prompt's top (y 413), measured on the console
      (user, 2026-10-03): items moved up 10 px from the exact layout.
- [x] Flicker in the menus (user, XEMU 2026-10-03): pbkit's triple buffering
      only refuses a fourth queued frame, so frames faster than the display
      drew into the buffer on screen. xbox_render.cpp present() queues at
      most one frame per vertical blank.
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
