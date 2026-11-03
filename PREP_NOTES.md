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

## Linux build (checked in this session, Ubuntu 24.04 / clang 20)
- Compiles and links. Boots under Xvfb + Mesa llvmpipe: Vulkan up, XEX loads, recompiled code runs into
  the game's own archive loading (`d:\DATA\*.AST`). Without fmv.AST / sound.AST it waits there.
- Needs glibc 2.38 and GLIBCXX_3.4.32 (librexruntime.so / librexgpu-xenos.so). Static libstdc++ was tried
  and dropped: two runtime copies (exe + each .so) made shutdown abort.
- The SDK's host file lookup falls back to case-insensitive, so `TEXT.AST` finds `text.AST` on Linux.

## Next steps
1. First CI build (Windows + Linux) and a test run.
2. Rendering / audio / input issues from testing.
