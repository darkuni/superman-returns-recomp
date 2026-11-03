// First-run setup from the player's own Xbox 360 disc image (see disc_setup.cpp).
#pragma once
#include <cstdint>
#include <filesystem>
#include <string>

// Extracts every file from the game partition of an Xbox 360 disc image (XDVDFS)
// into out. Skips $SystemUpdate. progress (optional) gets bytes done / total.
bool disc_extract(const std::filesystem::path& iso, const std::filesystem::path& out, std::string& err,
                  void (*progress)(uint64_t done, uint64_t total) = nullptr);

// Finds a disc image (*.iso) next to the exe whose default.xex has title_id and extracts it into assets.
// 1 = extracted, 0 = no image found, -1 = failed (err says why)
int disc_setup_auto(const std::filesystem::path& exe_dir, const std::filesystem::path& assets, uint32_t title_id,
                    std::string& err, std::string& used);

// Runs on start-up: makes the assets folder from a disc image next to the exe if it isn't there yet.
// Returns false (after telling the player why) when the game can't start.
bool disc_setup_first_run(const std::filesystem::path& exe_dir, const std::filesystem::path& assets, uint32_t title_id,
                          const std::string& game);

// Checks that assets/default.xex is the exact executable this build was
// recompiled from (size + SHA-1). A different version can't run: tells the
// player why and returns false.
bool xex_version_check(const std::filesystem::path& assets, const char* expected_sha1_hex,
                       uint64_t expected_size, const std::string& game);
