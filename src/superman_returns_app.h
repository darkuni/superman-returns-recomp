// superman_returns - ReXGlue Recompiled Project
//
// App hooks: default paths, GPU plugin, first-launch
// defaults, and the F1/Esc settings menu (src/game_menu.*).

#pragma once

#include <cstdlib>
#include <filesystem>
#include <string>

#include <rex/cvar.h>
#include <rex/filesystem.h>
#include <rex/filesystem/vfs.h>
#include <rex/input/input_system.h>
#include <rex/logging.h>
#include <rex/rex_app.h>
#include <rex/runtime.h>
#include <rex/ui/keybinds.h>

void InstallCrashHandler();  // src/crash_handler.cpp

#include <imgui.h>

#include "game_keys.h"
#include "game_menu.h"
#include "disc_setup.h"

class SupermanReturnsApp : public rex::ReXApp {
 public:
  using rex::ReXApp::ReXApp;

  static std::unique_ptr<rex::ui::WindowedApp> Create(
      rex::ui::WindowedAppContext& ctx) {
    return std::unique_ptr<SupermanReturnsApp>(new SupermanReturnsApp(ctx, "superman_returns",
        PPCImageConfig));
  }

  // Default the game data folder to "assets" next to the exe, so the game
  // runs with a plain double-click. --game_data_root still overrides it.
  void OnConfigurePaths(rex::PathConfig& paths) override {
    if (paths.game_data_root.empty()) {
      paths.game_data_root =
          rex::filesystem::GetExecutableFolder() / "assets";
      // First start: make "assets" from the player's own disc image next to the exe.
      if (!disc_setup_first_run(rex::filesystem::GetExecutableFolder(),
                                paths.game_data_root, 0x454107EDu,
                                "Superman Returns")) {
        std::exit(1);
      }
    }
    // Only the exact executable this build was recompiled from can run.
    if (!xex_version_check(paths.game_data_root, "26e439bba8fba7e86b19019a59727880ab6033b1", 9973760u, "Superman Returns")) {
      std::exit(1);
    }
    config_path_ = paths.config_path;
  }

  void OnPreSetup(rex::RuntimeConfig& config) override {
    // GPU emulation is opt-in in ReXGlue (gpu_plugin cvar). Default to the
    // Xenos plugin so the game actually renders; --gpu_plugin still overrides.
    if (config.gpu_plugin.empty()) {
      config.gpu_plugin = "xenos";
    }
    // First launch: windowed, keyboard on, default key layout. After this
    // everything comes from superman_returns.toml (edited by the F1 menu).
    if (!rex::cvar::Query<bool>("recomp_defaults_applied")) {
      rex::cvar::SetFlagByName("fullscreen", "false");
      rex::cvar::SetFlagByName("window_width", "1280");
      rex::cvar::SetFlagByName("window_height", "720");
      rex::cvar::SetFlagByName("mnk_mode", "true");
      recomp_ui::GameMenu::ApplyDefaultKeys();
      rex::cvar::SetFlagByName("recomp_defaults_applied", "true");
      if (!config_path_.empty()) {
        rex::cvar::SaveConfig(config_path_);
      }
      REXLOG_INFO("First launch: wrote default settings to {}",
                  config_path_.filename().string());
    }
    // Defaults added by later builds, applied once on top of existing settings.
    if (rex::cvar::Query<int32_t>("recomp_defaults_version") < 2) {
      rex::cvar::SetFlagByName("audio_maxqframes",
                               std::to_string(recomp_ui::game_keys::kDefaultAudioFrames));
      rex::cvar::SetFlagByName("recomp_defaults_version", "2");
      if (!config_path_.empty()) rex::cvar::SaveConfig(config_path_);
    }
    // Steam Deck (Steam sets SteamDeck=1, natively and under Proton): texture
    // filtering off and the small audio buffer, applied once. Same defaults
    // the Lode Runner recomp settled on for the Deck.
    const char* deck = std::getenv("SteamDeck");
    if (deck && deck[0] == '1' && rex::cvar::Query<int32_t>("recomp_defaults_version") < 3) {
      rex::cvar::SetFlagByName("anisotropic_override", "0");
      rex::cvar::SetFlagByName("audio_maxqframes", "8");
      rex::cvar::SetFlagByName("recomp_defaults_version", "3");
      if (!config_path_.empty()) rex::cvar::SaveConfig(config_path_);
      REXLOG_INFO("Steam Deck detected: texture filtering off, small audio buffer");
    }
    // v0.0.3 (test 2: all audio died when flight started, then a crash in the
    // reverb's command queue). XMA frames that run into the next streaming
    // buffer before the game marks it valid raised decode error 4 in the stock
    // decoder; wait for the buffer as the hardware does. xma_trace logs XMA
    // setup and errors so the next log shows what the audio engine hit.
    if (rex::cvar::Query<int32_t>("recomp_defaults_version") < 4) {
      rex::cvar::SetFlagByName("xma_stall_on_missing_packet", "true");
      rex::cvar::SetFlagByName("xma_trace", "true");
      rex::cvar::SetFlagByName("recomp_defaults_version", "4");
      if (!config_path_.empty()) rex::cvar::SaveConfig(config_path_);
      REXLOG_INFO("Defaults v4: xma_stall_on_missing_packet on, xma_trace on");
    }
    // v0.0.4 (test 3): xma_trace logged ~1000 lines/s from the audio thread and
    // shifted its timing enough to hit a voice-release race (now guarded in
    // src/xma_guard.cpp, which also logs decode errors). Trace back off.
    if (rex::cvar::Query<int32_t>("recomp_defaults_version") < 5) {
      rex::cvar::SetFlagByName("xma_trace", "false");
      rex::cvar::SetFlagByName("recomp_defaults_version", "5");
      if (!config_path_.empty()) rex::cvar::SaveConfig(config_path_);
      REXLOG_INFO("Defaults v5: xma_trace off");
    }
    // v0.0.5 (test 4): the stall setting never fired in test 3; back to the stock
    // decoder behaviour test 2 had, so the mixer watchdog (src/audio_hooks.cpp)
    // is the only change being measured.
    if (rex::cvar::Query<int32_t>("recomp_defaults_version") < 6) {
      rex::cvar::SetFlagByName("xma_stall_on_missing_packet", "false");
      rex::cvar::SetFlagByName("recomp_defaults_version", "6");
      if (!config_path_.empty()) rex::cvar::SaveConfig(config_path_);
      REXLOG_INFO("Defaults v6: xma_stall_on_missing_packet off");
    }
    REXLOG_INFO("Audio buffer: {} frames", rex::cvar::Query<int32_t>("audio_maxqframes"));
  }

  void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {
    (void)drawer;
    rex::ui::RegisterBind("bind_menu", "F1", "Open/close the settings menu",
                          [this] { ToggleMenu(); });
    rex::ui::RegisterBind("bind_menu_alt", "Escape", "Open/close the settings menu",
                          [this] { ToggleMenu(); });
    rex::ui::RegisterBind("bind_fullscreen", "F11", "Toggle fullscreen", [this] {
      if (menu_ && menu_->capturing()) return;
      bool fs = !window()->IsFullscreen();
      rex::cvar::SetFlagByName("fullscreen", fs ? "true" : "false");
      window()->SetFullscreen(fs);
      if (!config_path_.empty()) rex::cvar::SaveConfig(config_path_);
    });
  }

  // The game must not see keys/buttons while the menu is open.
  void OnPostSetup() override {
    InstallCrashHandler();  // re-assert after SDL/runtime init
    auto* input_sys = static_cast<rex::input::InputSystem*>(runtime()->input_system());
    if (input_sys && imgui_drawer()) {
      input_sys->SetActiveCallback([this]() {
        if (menu_) return false;
        return !imgui_drawer()->GetIO().WantCaptureMouse;
      });
    }
  }

 private:
  void ToggleMenu() {
    if (menu_) {
      if (menu_->capturing()) return;  // Esc cancels the key capture instead
      delete menu_;                    // removes itself from the drawer
      menu_ = nullptr;
      return;
    }
    if (!imgui_drawer()) return;
    recomp_ui::MenuHost host;
    host.title = "SUPERMAN RETURNS";
    host.config_path = config_path_;
    host.set_fullscreen = [this](bool fs) {
      app_context().CallInUIThreadDeferred([this, fs] { window()->SetFullscreen(fs); });
    };
    host.quit = [this] {
      app_context().CallInUIThreadDeferred([this] { window()->RequestClose(); });
    };
    host.on_closed = [this] { menu_ = nullptr; };
    menu_ = new recomp_ui::GameMenu(imgui_drawer(), std::move(host));
  }

  std::filesystem::path config_path_;
  recomp_ui::GameMenu* menu_ = nullptr;  // owned by the ImGui drawer
};
