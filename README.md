# Superman Returns - native recompilation

Superman Returns (Xbox 360, EA, 2006) statically recompiled to native Windows and Linux (Steam Deck / SteamOS)
with the [ReXGlue SDK](https://github.com/rexglue/rexglue-sdk) v0.9.0. Same treatment as the other darkuni
Xbox 360 recomps.

**Game files are not included.** You need your own Superman Returns (USA) disc. The build only runs with the
original disc's `default.xex` (title 454107ED, 9,973,760 bytes, SHA-1 `26e439bba8fba7e86b19019a59727880ab6033b1`).

## Setup
Put your disc image (`.iso`) next to the executable and start it. On the first start it extracts the game into
an `assets` folder (about 2 GB); after that the `.iso` isn't needed. Already extracted? Put `default.xex` and the
`DATA` folder in `assets` yourself.

- **Windows:** `superman_returns.exe`
- **Linux / Steam Deck:** `./superman_returns`. Needs Vulkan, glibc 2.38+ and libstdc++ from GCC 13.2+
  (`GLIBCXX_3.4.32`). On the Deck, add it to Steam as a non-Steam game
  from Desktop Mode.

F1 / Esc opens the settings menu (display, audio buffer, keys). F11 toggles fullscreen, F3 the performance overlay.
A controller is recommended; keyboard + mouse uses WASD to move and the mouse for the camera.

## Building
GitHub Actions builds both platforms on every push to `main` (`.github/workflows/build.yml`). Run it by hand with
`release_tag` set to publish a prerelease with the Windows `.zip` and Linux `.tar.gz`.

To regenerate the recompiled code you need your own `default.xex` in `assets/`:

```
rexglue codegen superman_returns_manifest.toml
```

Codegen notes (function overrides, SEH handlers, CRT addresses) are in `superman_returns_overrides.toml` and
`PREP_NOTES.md`. `tools/` has the scanners used to find functions the analyzer misses.

## License
MIT for this project's own code. ReXGlue SDK: BSD-3-Clause (portions from Xenia). Unofficial fan project, not
affiliated with or endorsed by Electronic Arts, Warner Bros. or Microsoft.
