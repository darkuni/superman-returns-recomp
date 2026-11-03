// First-run setup: extracts the player's own Xbox 360 disc image (XGD1/2/3 ISO, or a plain
// XISO) into the assets folder, so no extra tools are needed. XDVDFS reader.
#include "disc_setup.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <set>
#include <system_error>
#include <vector>

namespace fs = std::filesystem;

namespace {
constexpr uint64_t kSector = 2048;
// Game partition offsets: plain XISO, XGD2, XGD3, XGD1.
constexpr uint64_t kBases[] = {0, 0xFD90000ull, 0x2080000ull, 0x18300000ull};
constexpr char kMagic[] = "MICROSOFT*XBOX*MEDIA";

uint32_t le32(const uint8_t* p) { return p[0] | p[1] << 8 | p[2] << 16 | (uint32_t)p[3] << 24; }
uint16_t le16(const uint8_t* p) { return (uint16_t)(p[0] | p[1] << 8); }
uint32_t be32(const uint8_t* p) { return (uint32_t)p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]; }

void sha1(const uint8_t* data, size_t len, uint8_t out[20]) {
  uint32_t h[5] = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};
  auto rol = [](uint32_t x, int n) { return (x << n) | (x >> (32 - n)); };
  auto block = [&](const uint8_t* p) {
    uint32_t w[80];
    for (int i = 0; i < 16; i++) w[i] = (uint32_t)p[4 * i] << 24 | p[4 * i + 1] << 16 | p[4 * i + 2] << 8 | p[4 * i + 3];
    for (int i = 16; i < 80; i++) w[i] = rol(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);
    uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4];
    for (int i = 0; i < 80; i++) {
      uint32_t f, k;
      if (i < 20) { f = (b & c) | (~b & d); k = 0x5A827999; }
      else if (i < 40) { f = b ^ c ^ d; k = 0x6ED9EBA1; }
      else if (i < 60) { f = (b & c) | (b & d) | (c & d); k = 0x8F1BBCDC; }
      else { f = b ^ c ^ d; k = 0xCA62C1D6; }
      uint32_t t = rol(a, 5) + f + e + k + w[i];
      e = d; d = c; c = rol(b, 30); b = a; a = t;
    }
    h[0] += a; h[1] += b; h[2] += c; h[3] += d; h[4] += e;
  };
  size_t full = len / 64 * 64;
  for (size_t o = 0; o < full; o += 64) block(data + o);
  uint8_t tail[128] = {0};
  size_t rem = len - full;
  memcpy(tail, data + full, rem);
  tail[rem] = 0x80;
  size_t tl = rem + 9 <= 64 ? 64 : 128;
  uint64_t bits = (uint64_t)len * 8;
  for (int i = 0; i < 8; i++) tail[tl - 1 - i] = (uint8_t)(bits >> (8 * i));
  block(tail);
  if (tl == 128) block(tail + 64);
  for (int i = 0; i < 5; i++)
    for (int k = 0; k < 4; k++) out[4 * i + k] = (uint8_t)(h[i] >> (24 - 8 * k));
}

struct Entry {
  std::string path;  // relative, '/'-separated
  uint32_t sector;
  uint32_t size;
};

struct Disc {
  std::ifstream f;
  uint64_t base = 0;

  bool read(uint64_t off, void* dst, size_t n) {
    f.clear();
    f.seekg(static_cast<std::streamoff>(off));
    f.read(static_cast<char*>(dst), static_cast<std::streamsize>(n));
    return static_cast<size_t>(f.gcount()) == n;
  }

  bool open(const fs::path& p, std::string& err) {
    f.open(p, std::ios::binary);
    if (!f) { err = "can't open " + p.filename().string(); return false; }
    for (uint64_t b : kBases) {
      char m[20];
      if (read(b + 0x10000, m, sizeof m) && memcmp(m, kMagic, 20) == 0) { base = b; return true; }
    }
    err = p.filename().string() + " is not an Xbox 360 disc image";
    return false;
  }

  bool walk(uint32_t sector, uint32_t size, const std::string& prefix, std::vector<Entry>& out, int depth) {
    if (size == 0) return true;
    if (depth > 32 || size > 16u << 20) return false;
    std::vector<uint8_t> d(size);
    if (!read(base + sector * kSector, d.data(), size)) return false;
    std::set<uint32_t> seen;
    std::vector<uint32_t> todo{0};
    while (!todo.empty()) {
      uint32_t o = todo.back() * 4;
      todo.pop_back();
      if (o + 14 > size || !seen.insert(o).second) continue;
      if (d[o] == 0xFF && d[o + 1] == 0xFF) continue;
      uint16_t l = le16(&d[o]), r = le16(&d[o + 2]);
      uint32_t s = le32(&d[o + 4]), sz = le32(&d[o + 8]);
      uint8_t attr = d[o + 12], nl = d[o + 13];
      if (o + 14 + nl > size) return false;
      std::string name(reinterpret_cast<char*>(&d[o + 14]), nl);
      if (name.empty() || name == "." || name == ".." || name.find_first_of("/\\:") != std::string::npos)
        return false;
      std::string p = prefix.empty() ? name : prefix + "/" + name;
      if (attr & 0x10) {
        if (!walk(s, sz, p, out, depth + 1)) return false;
      } else {
        out.push_back({p, s, sz});
      }
      if (l) todo.push_back(l);
      if (r) todo.push_back(r);
    }
    return true;
  }

  bool list(std::vector<Entry>& out, std::string& err) {
    uint8_t h[8];
    if (!read(base + 0x10000 + 20, h, 8)) { err = "can't read the disc header"; return false; }
    if (!walk(le32(h), le32(h + 4), "", out, 0)) { err = "the disc's file table is damaged"; return false; }
    return true;
  }

  // Title ID from default.xex's execution info header (key 0x40006).
  uint32_t title_id(const std::vector<Entry>& files) {
    for (const auto& e : files) {
      if (e.path != "default.xex") continue;
      std::vector<uint8_t> h(std::min<uint32_t>(e.size, 0x10000));
      if (h.size() < 24 || !read(base + e.sector * kSector, h.data(), h.size())) return 0;
      if (memcmp(h.data(), "XEX2", 4) != 0) return 0;
      uint32_t n = be32(&h[20]);
      for (uint32_t i = 0; i < n && 32 + i * 8 <= h.size(); i++) {
        if (be32(&h[24 + i * 8]) != 0x40006) continue;
        uint32_t off = be32(&h[28 + i * 8]);
        if (off + 16 <= h.size()) return be32(&h[off + 12]);
      }
    }
    return 0;
  }
};
}  // namespace

bool disc_extract(const fs::path& iso, const fs::path& out, std::string& err,
                  void (*progress)(uint64_t done, uint64_t total)) {
  Disc d;
  std::vector<Entry> files;
  if (!d.open(iso, err) || !d.list(files, err)) return false;
  uint64_t total = 0, done = 0;
  for (const auto& e : files) total += e.size;
  // Extract into a temporary folder and rename at the end, so a cancelled run never
  // leaves a half-made assets folder that looks complete.
  fs::path tmp = out;
  tmp += ".partial";
  std::error_code ec;
  fs::remove_all(tmp, ec);
  std::vector<char> buf(8u << 20);
  for (const auto& e : files) {
    if (e.path.rfind("$SystemUpdate", 0) == 0) { total -= e.size; continue; }
    fs::path dst = tmp / fs::path(e.path);
    fs::create_directories(dst.parent_path(), ec);
    std::ofstream o(dst, std::ios::binary | std::ios::trunc);
    if (!o) { err = "can't write " + dst.string(); return false; }
    uint64_t pos = d.base + e.sector * kSector, left = e.size;
    while (left) {
      size_t n = static_cast<size_t>(std::min<uint64_t>(left, buf.size()));
      if (!d.read(pos, buf.data(), n)) { err = "read error in " + e.path + " (is the image complete?)"; return false; }
      o.write(buf.data(), static_cast<std::streamsize>(n));
      if (!o) { err = "write error on " + dst.string() + " (disk full?)"; return false; }
      pos += n;
      left -= n;
      done += n;
      if (progress) progress(done, total);
    }
  }
  fs::rename(tmp, out, ec);
  if (ec) { err = "can't rename " + tmp.string() + " to " + out.string() + ": " + ec.message(); return false; }
  return true;
}

int disc_setup_auto(const fs::path& exe_dir, const fs::path& assets, uint32_t title_id, std::string& err,
                    std::string& used) {
  std::error_code ec;
  std::vector<fs::path> cands;
  for (const auto& de : fs::directory_iterator(exe_dir, ec)) {
    if (!de.is_regular_file(ec)) continue;
    std::string ext = de.path().extension().string();
    std::transform(ext.begin(), ext.end(), ext.begin(), [](unsigned char c) { return (char)std::tolower(c); });
    if (ext != ".iso") continue;
    Disc d;
    std::vector<Entry> files;
    std::string e2;
    if (d.open(de.path(), e2) && d.list(files, e2) && d.title_id(files) == title_id) cands.push_back(de.path());
  }
  if (cands.empty()) return 0;
  std::sort(cands.begin(), cands.end());
  used = cands[0].filename().string();
  fprintf(stderr, "[setup] extracting %s into %s (about 2 GB, this takes a minute)\n", used.c_str(),
          assets.string().c_str());
  if (!disc_extract(cands[0], assets, err)) return -1;
  if (!fs::exists(assets / "default.xex", ec)) { err = used + " has no default.xex"; return -1; }
  return 1;
}

#ifdef DISC_SETUP_TOOL
static void print_progress(uint64_t done, uint64_t total) {
  static int last = -1;
  int pct = total ? (int)(done * 100 / total) : 100;
  if (pct != last) { fprintf(stderr, "\r%3d%%", pct); last = pct; }
}
int main(int argc, char** argv) {
  if (argc < 3) { fprintf(stderr, "usage: %s <image.iso> <outdir> | --auto <exe_dir> <assets> <title_id_hex>\n", argv[0]); return 2; }
  std::string err;
  if (std::string(argv[1]) == "--auto" && argc >= 5) {
    std::string used;
    int r = disc_setup_auto(argv[2], argv[3], (uint32_t)strtoul(argv[4], nullptr, 16), err, used);
    fprintf(stderr, "auto: %d used '%s' err '%s'\n", r, used.c_str(), err.c_str());
    return r > 0 ? 0 : 1;
  }
  if (!disc_extract(argv[1], argv[2], err, print_progress)) { fprintf(stderr, "\nfailed: %s\n", err.c_str()); return 1; }
  fprintf(stderr, "\nok\n");
  return 0;
}
#endif

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
static void show_message(const std::string& title, const std::string& text, bool error) {
  fprintf(stderr, "%s\n", text.c_str());
#ifdef _WIN32
  MessageBoxA(nullptr, text.c_str(), title.c_str(), error ? MB_ICONERROR : MB_ICONINFORMATION);
#else
  (void)title; (void)error;
#endif
}

bool disc_setup_first_run(const fs::path& exe_dir, const fs::path& assets, uint32_t title_id, const std::string& game) {
  std::error_code ec;
  if (fs::exists(assets / "default.xex", ec)) return true;
  std::string err, used;
  int r = disc_setup_auto(exe_dir, assets, title_id, err, used);
  if (r > 0) return true;
  if (r < 0) show_message(game, "Could not set up the game from " + used + ":\n" + err, true);
  else show_message(game, "Game files not found.\n\nPut your own " + game + " Xbox 360 disc image (.iso) in the "
                          "same folder as this exe and start it again: the \"assets\" folder is made from it on the "
                          "first start (about 2 GB). After that the .iso isn't needed any more.\n\n(Already "
                          "extracted? Put default.xex and the DATA folder in an \"assets\" folder next to the exe.)",
                    true);
  return false;
}

bool xex_version_check(const fs::path& assets, const char* expected_sha1_hex, uint64_t expected_size,
                       const std::string& game) {
  const fs::path xex = assets / "default.xex";
  std::error_code ec;
  if (!fs::exists(xex, ec)) return true;  // the normal "game files not found" path handles this
  const uint64_t size = fs::file_size(xex, ec);
  std::string got = "(unreadable)";
  bool ok = false;
  if (!ec) {
    std::vector<uint8_t> data(static_cast<size_t>(size));
    FILE* f = fopen(xex.string().c_str(), "rb");
    if (f) {
      const size_t n = fread(data.data(), 1, data.size(), f);
      fclose(f);
      if (n == data.size()) {
        uint8_t h[20];
        sha1(data.data(), data.size(), h);
        char hex[41];
        for (int i = 0; i < 20; i++) snprintf(hex + i * 2, 3, "%02x", h[i]);
        got = hex;
        ok = size == expected_size && got == expected_sha1_hex;
      }
    }
  }
  if (ok) return true;
  show_message(game,
               "This build needs a different version of the game files.\n\n"
               "It was made from " + game + " with a default.xex of " + std::to_string(expected_size) +
                   " bytes (SHA-1 " + expected_sha1_hex + ").\n\n"
               "Your default.xex is " + std::to_string(size) + " bytes (SHA-1 " + got + ").\n\n"
               "This usually means a title update is applied, or the files come from another "
               "release. Use the original, unpatched game files.",
               true);
  return false;
}
