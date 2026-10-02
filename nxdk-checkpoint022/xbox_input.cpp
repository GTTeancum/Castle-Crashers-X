// SPDX-License-Identifier: MIT
// Original-Xbox controller input for the port: the first connected pad, read
// through nxdk's SDL game-controller layer and returned in Xbox 360 XINPUT
// terms (the game reads it through XamInputGetState). The Duke/S pad's white
// and black buttons arrive as the left and right shoulder buttons.
#include <SDL.h>
#include <cstdint>

namespace {
bool g_init = false, g_ok = false;
SDL_GameController* g_pad = nullptr;

int16_t stick(SDL_GameControllerAxis a, bool invert) {
  int v = SDL_GameControllerGetAxis(g_pad, a);
  if (invert) v = -v - 1;  // SDL: down is positive; XINPUT: up is positive
  if (v < -32768) v = -32768;
  if (v > 32767) v = 32767;
  return static_cast<int16_t>(v);
}
uint8_t trigger(SDL_GameControllerAxis a) {
  const int v = SDL_GameControllerGetAxis(g_pad, a);
  return static_cast<uint8_t>(v <= 0 ? 0 : v >> 7);
}
}  // namespace

// Poll the pad once per game input read. Returns false when no pad is
// connected. Buttons use the XINPUT_GAMEPAD_* bit values.
bool cc_xbox_pad(uint32_t* buttons, int16_t* lx, int16_t* ly, int16_t* rx, int16_t* ry,
                 uint8_t* lt, uint8_t* rt) {
#ifdef CC_NO_PAD
  return false;
#endif
  if (!g_init) {
    g_init = true;
    g_ok = SDL_Init(SDL_INIT_GAMECONTROLLER) == 0;
  }
  if (!g_ok) return false;
  SDL_GameControllerUpdate();
  if (g_pad && !SDL_GameControllerGetAttached(g_pad)) {
    SDL_GameControllerClose(g_pad);
    g_pad = nullptr;
  }
  if (!g_pad) {
    for (int i = 0; i < SDL_NumJoysticks() && !g_pad; ++i)
      if (SDL_IsGameController(i)) g_pad = SDL_GameControllerOpen(i);
    if (!g_pad) return false;
  }
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
    if (SDL_GameControllerGetButton(g_pad, m.b)) b |= m.bit;
  *buttons = b;
  *lx = stick(SDL_CONTROLLER_AXIS_LEFTX, false);
  *ly = stick(SDL_CONTROLLER_AXIS_LEFTY, true);
  *rx = stick(SDL_CONTROLLER_AXIS_RIGHTX, false);
  *ry = stick(SDL_CONTROLLER_AXIS_RIGHTY, true);
  *lt = trigger(SDL_CONTROLLER_AXIS_TRIGGERLEFT);
  *rt = trigger(SDL_CONTROLLER_AXIS_TRIGGERRIGHT);
  return true;
}
