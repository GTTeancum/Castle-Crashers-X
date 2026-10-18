// SPDX-License-Identifier: MIT
// Original-Xbox controller input for the port: up to four pads, read through
// nxdk's SDL game-controller layer and returned in Xbox 360 XINPUT terms
// (the game reads them through XamInputGetState, one user index per pad).
// A pad keeps its slot while it stays connected; a newly attached pad takes
// the first free slot, so a lone pad is always player 1 whatever port it is
// plugged into. The
// Duke/S pad's white and black buttons arrive as the shoulder buttons.
#include <SDL.h>
#include <xboxkrnl/xboxkrnl.h>
#include <cstdint>

namespace {
void igr_check();
bool g_init = false, g_ok = false;
SDL_GameController* g_pad[4] = {};
uint32_t g_scanned = 0xFFFFFFFFu;  // input poll count at the last attach scan

int16_t stick(SDL_GameController* pad, SDL_GameControllerAxis a, bool invert) {
  int v = SDL_GameControllerGetAxis(pad, a);
  if (invert) v = -v - 1;  // SDL: down is positive; XINPUT: up is positive
  if (v < -32768) v = -32768;
  if (v > 32767) v = 32767;
  return static_cast<int16_t>(v);
}
uint8_t trigger(SDL_GameController* pad, SDL_GameControllerAxis a) {
  const int v = SDL_GameControllerGetAxis(pad, a);
  return static_cast<uint8_t>(v <= 0 ? 0 : v >> 7);
}

// Drops pads that were unplugged and opens newly attached ones (once per
// poll of slot 0, i.e. once per game input read).
void scan() {
  for (auto& p : g_pad)
    if (p && !SDL_GameControllerGetAttached(p)) { SDL_GameControllerClose(p); p = nullptr; }
  for (int i = 0; i < SDL_NumJoysticks(); ++i) {
    if (!SDL_IsGameController(i)) continue;
    SDL_JoystickID id = SDL_JoystickGetDeviceInstanceID(i);
    bool open = false;
    for (auto* p : g_pad)
      if (p && SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(p)) == id) open = true;
    if (open) continue;
    int slot = -1;
    for (int s = 0; s < 4 && slot < 0; ++s) if (!g_pad[s]) slot = s;
    if (slot >= 0) g_pad[slot] = SDL_GameControllerOpen(i);
  }
}
}  // namespace

// Poll the pad in slot `port` (0-3). Returns false when no pad is there.
// Buttons use the XINPUT_GAMEPAD_* bit values. Slot 0's poll refreshes the
// controller state for all four (the game reads user 0 first each frame).
bool cc_xbox_pad_port(uint32_t port, uint32_t* buttons, int16_t* lx, int16_t* ly, int16_t* rx, int16_t* ry,
                      uint8_t* lt, uint8_t* rt) {
#ifdef CC_NO_PAD
  return false;
#endif
  if (port > 3u) return false;
  if (!g_init) {
    g_init = true;
    g_ok = SDL_Init(SDL_INIT_GAMECONTROLLER) == 0;
    // Pads are polled directly; nothing drains SDL's event queue, which
    // would otherwise grow to megabytes on a 64 MB machine.
    if (g_ok) { SDL_JoystickEventState(SDL_IGNORE); SDL_GameControllerEventState(SDL_IGNORE); }
  }
  if (!g_ok) return false;
  static uint32_t polls = 0;
  if (port == 0u) { SDL_GameControllerUpdate(); ++polls; }
  if (g_scanned != polls) { g_scanned = polls; scan(); igr_check(); }
  SDL_GameController* pad = g_pad[port];
  if (!pad) return false;
  struct Map { SDL_GameControllerButton b; uint32_t bit; };
  static const Map kMap[] = {
    {SDL_CONTROLLER_BUTTON_DPAD_UP, 0x0001}, {SDL_CONTROLLER_BUTTON_DPAD_DOWN, 0x0002},
    {SDL_CONTROLLER_BUTTON_DPAD_LEFT, 0x0004}, {SDL_CONTROLLER_BUTTON_DPAD_RIGHT, 0x0008},
    {SDL_CONTROLLER_BUTTON_START, 0x0010}, {SDL_CONTROLLER_BUTTON_BACK, 0x0020},
    {SDL_CONTROLLER_BUTTON_LEFTSTICK, 0x0040}, {SDL_CONTROLLER_BUTTON_RIGHTSTICK, 0x0080},
    {SDL_CONTROLLER_BUTTON_LEFTSHOULDER, 0x0100}, {SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, 0x0200},
    {SDL_CONTROLLER_BUTTON_A, 0x1000}, {SDL_CONTROLLER_BUTTON_B, 0x2000},
    {SDL_CONTROLLER_BUTTON_X, 0x4000}, {SDL_CONTROLLER_BUTTON_Y, 0x8000},
  };
  uint32_t b = 0;
  for (const Map& m : kMap)
    if (SDL_GameControllerGetButton(pad, m.b)) b |= m.bit;
  *buttons = b;
  *lx = stick(pad, SDL_CONTROLLER_AXIS_LEFTX, false);
  *ly = stick(pad, SDL_CONTROLLER_AXIS_LEFTY, true);
  *rx = stick(pad, SDL_CONTROLLER_AXIS_RIGHTX, false);
  *ry = stick(pad, SDL_CONTROLLER_AXIS_RIGHTY, true);
  *lt = trigger(pad, SDL_CONTROLLER_AXIS_TRIGGERLEFT);
  *rt = trigger(pad, SDL_CONTROLLER_AXIS_TRIGGERRIGHT);
  return true;
}

bool cc_xbox_pad(uint32_t* buttons, int16_t* lx, int16_t* ly, int16_t* rx, int16_t* ry, uint8_t* lt, uint8_t* rt) {
  return cc_xbox_pad_port(0u, buttons, lx, ly, rx, ry, lt, rt);
}

// In-game reset: LT + RT + Back + Black held together on any pad returns to
// the dashboard (the softmod convention; this port reads the pads through
// SDL, past the XInput path softmod IGR hooks watch). Read from nxdk's fixed
// physical joystick layout (axes 2 / 5 = LT / RT, buttons 6 / 5 = Back /
// Black, as Perfect Dark X does), not the remappable controller view. The
// combination must be pressed, not merely held from before (a pad still
// held at boot does not reset again). Called with each game input read
// (cc_xbox_pad_port, slot 0) and on the failure screen.
void cc_xbox_audio_stop();
[[noreturn]] void cc_xbox_return_to_dashboard();
namespace {
bool g_igr_held[4] = {true, true, true, true};
void igr_check() {
  for (int s = 0; s < 4; ++s) {
    SDL_Joystick* joy = g_pad[s] ? SDL_GameControllerGetJoystick(g_pad[s]) : nullptr;
    const bool all = joy && SDL_JoystickGetAxis(joy, 2) > 16384 && SDL_JoystickGetAxis(joy, 5) > 16384 &&
                     SDL_JoystickGetButton(joy, 6) && SDL_JoystickGetButton(joy, 5);
    if (all && !g_igr_held[s]) {
      DbgPrint("IGR: pad %d pressed LT+RT+Back+Black; returning to the dashboard\n", s + 1);
      cc_xbox_audio_stop();
      cc_xbox_return_to_dashboard();
    }
    g_igr_held[s] = all;
  }
}
}  // namespace
// The failure screen's loop: pads refreshed and the reset combination
// checked (the game no longer reads input there).
void cc_xbox_igr_poll() {
  if (!g_ok) return;
  SDL_GameControllerUpdate();
  scan();
  igr_check();
}
