// Superman Returns keyboard + mouse layout (used by game_menu.cpp).
// WASD = left stick, mouse = right stick (camera), mouse buttons = triggers.
// Buttons keep their controller names - rebind them from F1 > Edit keyboard keys.
#pragma once

namespace recomp_ui::game_keys {

struct KeyBind {
  const char* cvar;
  const char* label;
  const char* default_key;
};

inline const KeyBind kKeyBinds[] = {
    {"keybind_lstick_up", "Move forward (stick)", "W"},
    {"keybind_lstick_down", "Move back (stick)", "S"},
    {"keybind_lstick_left", "Move left (stick)", "A"},
    {"keybind_lstick_right", "Move right (stick)", "D"},
    {"keybind_dpad_up", "Up (D-pad)", "Up"},
    {"keybind_dpad_down", "Down (D-pad)", "Down"},
    {"keybind_dpad_left", "Left (D-pad)", "Left"},
    {"keybind_dpad_right", "Right (D-pad)", "Right"},
    {"keybind_a", "A button", "Space"},
    {"keybind_b", "B button", "Shift"},
    {"keybind_x", "X button", "R"},
    {"keybind_y", "Y button", "E"},
    {"keybind_left_trigger", "Left trigger (LT)", "RMB"},
    {"keybind_right_trigger", "Right trigger (RT)", "LMB"},
    {"keybind_left_shoulder", "Left bumper (LB)", "Q"},
    {"keybind_right_shoulder", "Right bumper (RB)", "F"},
    {"keybind_lstick_press", "Left stick click (LS)", "C"},
    {"keybind_rstick_press", "Right stick click (RS)", "MMB"},
    {"keybind_start", "Start / pause", "Return"},
    {"keybind_back", "Back", "Tab"},
};

// Audio frames to buffer by default.
inline constexpr int kDefaultAudioFrames = 16;

inline const char* const kUnbound[] = {"keybind_guide"};

}  // namespace recomp_ui::game_keys
