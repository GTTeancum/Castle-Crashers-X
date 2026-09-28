# TODO

Deferred until the port is fully playable.

## Memory budget (biggest known porting constraint)

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
- [ ] Compress textures to DXT5 when the loader creates them on the Xbox
      (hook at the texture records built in `sub_82091AC0`).
- [ ] Plan the cuts: smaller or recompressed textures (360 formats are
      larger than needed at 640x480), audio re-encoded (see the audio item),
      streaming instead of loading everything up front.

## Xbox 360 leftovers in the menus

- [ ] Starting a story game shows "Sign in to Xbox LIVE to post your score
      to the leaderboards" (A continues). Remove it on the original Xbox.
- [ ] The main menu still lists Xbox LIVE Game, Leaderboards and
      Achievements; hide them or grey them out.

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
