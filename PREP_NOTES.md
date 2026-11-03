# Superman Returns (USA) - recomp prep notes

## Source
- `Superman Returns (USA).iso` - XGD2 disc, 7,834,892,288 bytes. Game partition at 0xFD90000.
- Extracted to `assets/` (all files verified against the ISO). `$SystemUpdate` skipped.

| File | Bytes |
|---|---|
| default.xex | 9,973,760 |
| DATA/fmv.AST | 996,058,192 |
| DATA/objtiv.AST | 349,035,444 |
| DATA/sound.AST | 305,930,445 |
| DATA/metropol.AST | 245,672,344 |
| DATA/ui.AST | 89,595,420 |
| DATA/voice.AST | 87,061,326 |
| DATA/fmvlegal.AST | 42,352,054 |
| DATA/lunits.AST | 25,696,316 |
| DATA/baseworl.AST | 6,253,440 |
| DATA/preload.AST | 2,122,295 |
| DATA/text.AST | 233,532 |
| DATA/_workinp.AST | 46,047 |

## default.xex
- XEX2, retail key, encrypted, basic compression. Unpacks cleanly (`tools/xex_unpack.py` -> `work/default.pe`).
- SHA-1 26e439bba8fba7e86b19019a59727880ab6033b1, 9,973,760 bytes (for `xex_version_check`).
- Title ID 454107ED (EA), media ID 64A4002A, version 00000001, disc 1/1.
- Image base 0x82000000, image size 0x9E0000, entry 0x82468D10.
- Imports: xam.xex, xboxkrnl.exe only.
- Build: EA "SupermanNextGen", `xenon-vc-rw-dev-ship` config (RenderWare-based engine, EASTL, Apt UI).
- Links the D3DX effect compiler (runtime HLSL compile on the guest side).

## Sections
| Section | VA | Size |
|---|---|---|
| .rdata | 82000600 | 000BD43C |
| .pdata | 820BDC00 | 0002AA68 (21,837 functions) |
| .text | 820F0000 | 007FF5B8 |
| .embsec_ x7 | 828EF600-8290F5B8 | small, executable, 85 .pdata funcs total |
| .data | 82910000 | 000A2FB8 |

`.text` is ~8 MB - much bigger than the XBLA recomps. Expect a long CI build.
The seven `.embsec_` sections are extra code sections covered by `.pdata`; check codegen picks them up.

## CRT
- setjmp  0x827A45E0 (no .pdata entry; added to overrides)
- longjmp 0x827A4270
- __savefpr / __restfpr helpers at 0x8279F1F0 / 0x8279F23C (r12-based)

## Codegen (ReXGlue v0.9.0)
- 33,034 functions, 0 analysis errors, 0 undefined labels. ~147 MB of generated C++ in 77 files.
- First pass: 11 unresolved branches. Fixed with overrides:
  - 0x82627A10-0x82627F58 has no .pdata. Two functions with out-of-line tails that branch back into their
    loops were split at the tails. Pinned with explicit sizes (0x82627DE8 / 0x82627DF0 / 0x82627EA8).
  - Six tail-call-only thunks (`lwz r3,0(r3); b`, `lis/lwz/mtctr/bctr`, r3/r4 swap).
- scan_pointer_funcs.py / scan_code_addr_funcs.py: ~100 C++ adjustor thunks (`addi r3,r3,-N; b`) and
  vcall thunks (`lwz r12,0(r3); lwz r11,N(r12); bctr`) only referenced from vtables. Added.
- **Not added:** 22 `__except`/`__finally` handler blocks from the SEH scope tables at 0x820BD430-0x820BDA20
  (`{count, {try_begin, try_end, filter, handler} x count}`). They live inside their parent functions, so
  registering them splits the parent and breaks codegen. The scanners keep flagging them - that's expected.
  If a crash ever traces to an SEH path, this is where to look.
- Leftover scanner hits after the last pass: those 22 handlers plus 3 kernel import thunks. Nothing else.

## Runtime
- First run extracts the player's own ISO (`src/disc_setup.cpp`, XGD1/2/3 or plain XISO, title ID checked).
  Tested against this disc's layout: all 13 files, `$SystemUpdate` skipped, xex SHA-1 matches.
- Keyboard + mouse uses the SDK's 3D layout (WASD, mouse camera); Start moved to Enter because Esc opens
  the settings menu.

## Test 1 (Windows, 2026-11-03): crash after the intro movies
- FATAL: call to unregistered function 0x826D17A0. A leaf function with no .pdata and no static
  pointer (reached through a pointer built at runtime), sitting right after a bctr thunk - codegen's
  gap-fill stops after those.
- New tools/scan_gaps.py finds every uncovered stretch of .text that starts after a return/tail jump.
  Gaps that are labels or branch targets inside existing functions are skipped (counting artifacts).
  Added 252 functions over three passes until stable: 33,286 functions, codegen still clean.

## Test 2 (Windows): all audio stopped when flight started, crash after landing
- Crash: sub_8264CE48 (pushes a command into the reverb/DSP command queue) wrote to guest 0x0000000C -
  the queue's buffer was NULL, i.e. the audio engine had already shut down.
- Xenia's tracker lists this game as apu-silent on master and playable on Canary: emulator-side audio.
- Candidate: stock XMA decoder raises error 4 when a frame runs into the next streaming input buffer
  before the game marks it valid (the hardware waits). Flight starts new streamed music.
- Build 3: SDK package p23 on both platforms (Linux applies the sdk-builds patches at tag
  sdk-v0.9.0-p23), defaults v4 turn on xma_stall_on_missing_packet + xma_trace.

## Test 3 (Windows): crash ~35 s in, inside XMAGetOutputBufferWriteOffset(NULL)
- Called from sub_826592F0 (EA's XMA stream reader: reads write/read offsets per voice, 6144-byte /
  24-block output ring). A voice still on its list had its context pointer cleared - a release race.
- The stall path never fired (no stall / error 4 in the log). xma_trace logged ~1000 lines/s from the
  same audio thread, which plausibly widened the race window.
- Build 4: src/xma_guard.cpp overrides the 14 context-taking XMA imports (exe definitions beat the SDK
  DLL's), forwards to the SDK's *_entry, returns 0 on a NULL context (logged once per call), and logs
  each new decode/parser error pair the game polls. Defaults v5 turn xma_trace back off.

## Test 4 (Windows): same crash, but the "context" was 0x8264CE28 = the reverb command handler
- So tests 2-4 are one bug: mixer commands written outside the command buffer (over the voice list).
- Mixer (global 0x8299FDC8, init sub_8264C958): command buffer +0x20, capacity +0x24 (1 MB),
  write offset +0x28, high-water +0x2C. DSP update sub_8264C540 drains it under the mixer lock.
  Producers (reverb sub_8264CE48 16 B, effect sub_82661FC0 24 B, one 8 B inline push in
  sub_826502A8) never check capacity. Shutdown sub_8264C6D0 frees it; sub_82335E28 tears down all.
- 1 MB only overflows if DSP updates stop entirely: audio dies (updates stop), game keeps pushing
  reverb changes every frame (flight), buffer runs off its end later -> crash.
- Build 5: src/audio_hooks.cpp bounds-checks the two hookable producers (drop + log), logs
  init/shutdown/teardown with caller, fill high-water, update gaps, and a watchdog that reports a DSP
  update stuck inside (lock), updates stopping, or an XMADisableContext that never returns.
  Defaults v6: xma_stall_on_missing_packet back off (test 2 baseline).

## Test 5 (Windows): the cause - render callbacks stop when the flight cinematic starts
- Watchdog: "no DSP update for 1162 ms - the audio driver stopped calling the game" right after the
  cinematic load; nothing blocked, no XMADisableContext hang. Buffer full 5 s later (pushes dropped),
  then the unguarded 8-byte inline push corrupted a voice -> NULL context -> crash.
- SDK pacing: AudioSystem's worker waits on a 16-permit semaphore per client; a permit only returns
  when the device plays a frame the game submitted. A callback that submits nothing loses its permit;
  16 of those and the worker never calls the game again. Hardware drives the callback by timer.
- Build 6: src/audio_pacing.cpp wraps XAudioRegisterRenderDriverClient, swaps the game's callback
  (821209F0) in the FunctionDispatcher (Memory::SetFunction alone is NOT what Execute() reads), and
  submits a silent frame whenever the game's callback returns without one. Verified here with
  PulseAudio null sink + a forced 60-callback skip: callbacks kept coming.
- Local test notes: Xvfb wedges after a while (restart it); logs only flush on warnings, so use
  REXAPU_WARN for test lines; SDL here has pulseaudio, not dummy/disk.

## Test 6 (Windows): pacing fix was the wrong target
- 6864 render callbacks = 6864 frames submitted, 0 silence fills: the XAudio2 tick never stopped.
- EA audio thread sub_82650B78: KeWaitForSingleObject(obj+0x30A0, INFINITE) each pass; that event is
  only set by the XAudio2 voice callbacks sub_826509E8 (pass) / sub_82650A08 (buffer end - also clears
  the slot state at obj+0x3154/+0x3158). A pass is skipped while the current slot is in use.
- 821209F0 is XAudio2's engine tick (sub_82117F10): sets tick event 0x829AC0B8, waits on done
  0x829AC094 / abort 0x829AC0D8 (manual reset, set by XAudio2's timer routine sub_82118750), submits.
  Processing thread sub_82117810 waits on tick, runs the pass (82116D68, 82118068), sets done.
- Test 6 minidump: XAudio2 processing thread (29316) idle in its tick wait; EA thread asleep.
  So XAudio2 stopped processing EA's voice at the cinematic; why is the open question.
- Build 7: keep-alive frees EA's current slot + sets its event after 30 ms without a DSP update
  (verified here: voice callbacks dropped, DSP updates continue at ~30 Hz, no overflow). Stall report
  adds XAudio2 engine state, event states, pass / timer-routine counts, all XAudio2 calls in last 3 s.
- Minidumps: symbolize with python minidump + the build's .map (stacks are only 1-3 KB each).

## Test 7 (Windows): XAudio2 alive, EA voice stops consuming, EA thread blocked elsewhere
- Stall report: XAudio2 passes 6948 (last 5 ms ago), EA voice *pass* callbacks 6948 (still coming -
  its event IS set every pass), buffer-end callbacks stopped at 6705. Keep-alive kicked every tick
  but produced no DSP update -> the EA thread (RWAudioCore "Dac") is not in its wait.
- During the stall the XAudio2 calls come from 0x8247xxxx = the XMV movie player ("CCalChannel"):
  8 voices created, ~7600 buffer submits. The flight cinematic is an XMV movie.
- No XMA context has an error flag. Still crashed on the unguardable 8-byte inline push.
- Build 8: watchdog empties the command buffer at 90% while stalled (no overflow possible). EA
  thread call stack tracking (ea_track.h: render 8265A148, XMA stream reader 826592F0, 82658958,
  timers, lock 825FC108, wait 821169A8 ...) + XMA call count, reported at +1 s and +5 s of a stall.
- Local test env after a container restart: start pulseaudio again (else no callbacks); logs only
  flush on warnings, so a silent log is not a hang - check with gdb "thread apply all bt".

## Linux build (checked in this session, Ubuntu 24.04 / clang 20)
- Compiles and links. Boots under Xvfb + Mesa llvmpipe: Vulkan up, XEX loads, recompiled code runs into
  the game's own archive loading (`d:\DATA\*.AST`). Without fmv.AST / sound.AST it waits there.
- Needs glibc 2.38 and GLIBCXX_3.4.32 (librexruntime.so / librexgpu-xenos.so). Static libstdc++ was tried
  and dropped: two runtime copies (exe + each .so) made shutdown abort.
- The SDK's host file lookup falls back to case-insensitive, so `TEXT.AST` finds `text.AST` on Linux.

## Next steps
1. First CI build (Windows + Linux) and a test run.
2. Rendering / audio / input issues from testing.
