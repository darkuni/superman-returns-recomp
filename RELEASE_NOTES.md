First public test build of the Superman Returns recompilation: native Windows and Linux (Steam Deck / SteamOS) builds of the Xbox 360 game, no emulator.

Game files are NOT included. You need your own Superman Returns (USA) Xbox 360 disc image.

## Setup
- **Windows:** unzip `superman_returns-v0.1.0-win-amd64.zip`, put your `.iso` next to `superman_returns.exe` and run it. If a DLL such as `VCRUNTIME140.dll` is missing, install the [Visual C++ Redistributable 2015-2022 (x64)](https://aka.ms/vs/17/release/vc_redist.x64.exe).
- **Linux / Steam Deck:** extract `superman_returns-v0.1.0-linux-amd64.tar.gz`, put your `.iso` next to `superman_returns` and run it (needs glibc 2.38 or newer - SteamOS 3.6+, Ubuntu 24.04+, Fedora 39+).
- The first start extracts the game files from the `.iso` into an `assets` folder (about 2 GB); after that the `.iso` isn't needed.

F1 / Esc: settings. F11: fullscreen. A controller is recommended; keyboard + mouse also work (see README.txt).

## Status
- Tested through the first two missions on Windows, with sound (music, voice-over, effects) through cinematics and flight.
- Sound workarounds are in place for EA's audio streaming: brief clicks or hitches can still occur.
- Superman appeared in a white suit in the second mission - not yet known whether that's an unlocked costume or a rendering bug.
- Expect rendering glitches and crashes further in.

## Reporting problems
Please open an issue with:
- what you were doing, and Windows or Linux / Steam Deck
- the log from the `logs` folder
- for a crash, the `crash-*.txt` and `.dmp` files next to the executable

Unofficial fan project, not affiliated with or endorsed by Electronic Arts, Warner Bros. or Microsoft.
