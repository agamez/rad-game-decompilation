# Recovery notes — segment 13C1 and segment 13C8

Scope: `src/seg13C1.c` (3 functions) and `src/seg13C8.c` (10 functions),
recovered from `analysis/slices/13C1/` and `analysis/slices/13C8/`
(Reko `.c` skeleton + ground-truth `.asm`).  Frozen prototypes adopted
verbatim from `src/seg13C1.h` / `src/seg13C8.h` (generated from
`analysis/summary/iface.tsv`).  No header was modified.

## What the segments do

Both segments are wrappers around `fn1E5F_000B` (1E5F:000B), the
register-frame interrupt trampoline used throughout the program.

* **13C1** is called from the CRT init chain: `fn13C1_0067` (via
  `fn0800_4255`) reads the current video mode (INT 10h AH=0Fh) and the
  cursor shape (INT 10h AH=03h) and stores the cursor start/end scan
  lines into DGROUP `0xB6A8` / `0xB6AA`.  `fn13C1_0036` is a text-format
  helper (called from `fn1229_050A`) that renders a string through
  `fn1EDA_0F26` / `fn1EDA_0A39`.
* **13C8** is the mouse (INT 33h) interface: driver presence
  (`fn13C8_0000`), reset/status (`fn13C8_000D`), cursor show/hide
  (`fn13C8_0038` / `fn13C8_004F`), position+buttons (`fn13C8_0066`),
  cursor move (`fn13C8_009A`), range set (`fn13C8_00BF` / `fn13C8_00E4`),
  speed threshold (`fn13C8_0111`) and the init routine `fn13C8_0139`
  called early by the CRT.

## The interrupt frame

`fn1E5F_000B` is dispatched by every wrapper above.  Its own continuation
at `1E5F:0045` (`pushf/push es/push di/push bp` … `stosw`) writes the
post-interrupt register set back into the caller's frame:

| byte offset | word | register |
|-------------|------|----------|
| 0x00 | 0 | AX |
| 0x02 | 1 | BX |
| 0x04 | 2 | CX |
| 0x06 | 3 | DX |
| 0x08 | 4 | BP |
| 0x0A | 5 | SI |
| 0x0C | 6 | DI |
| 0x0E | 7 | DS |
| 0x10 | 8 | ES |
| 0x12 | 9 | FLAGS |

Every wrapper allocates exactly this 0x14-byte frame (`enter 14h`).  Both
files model it with the file-local `TRegFrame` typedef (its layout is
proved by the `1E5F:0045` store-back sequence, not invented).

## Hardware interfaces replaced

**None directly.**  There is no raw `int 10h` / `int 16h` / `int 21h`, no
`in`/`out` port site, no `__cli`/`__sti` and no `int 23h` instruction in
either segment.  Every interrupt is issued indirectly through
`fn1E5F_000B`, which is itself recovered code, so the calls are kept
literally:

* INT 10h in `fn13C1_0000` (AH=0Fh, AH=03h) → `fn1E5F_000B` with vector 0x10.
* INT 33h in every 13C8 wrapper → `fn1E5F_000B` with vector 0x33.

`pal/pal.h` exposes no mouse (INT 33h) entry point, and the cursor-shape
half of `fn13C1_0000` (AH=03h) has no `bios_video_*` equivalent, so a
full PAL substitution was neither possible nor attempted.  The
trampoline is the literal mechanism.

## Reko artifacts resolved

* Every `MemN[ds:0xHHHH:word16]` became `LG16(0xHHHH)` (byte → `LG8`,
  dword → `LG32`).  DGROUP offsets used: `0xB6A8`, `0xB6AA`, `0xB6AE`,
  `0xB6B0`, `0xB6B2`, `0xB6B4`, `0xB6B6`, `0xB6B8`.
* `Eq_17` / `ds` / `selector` value and output parameters that Reko
  synthesised are dropped in the flat model (DS is a constant).  Only the
  frozen `dsOut` parameters remain in the signatures; they are not
  written, exactly as the selector drop in `CONVENTIONS.md` prescribes.
* Reko's `ss->*bp_23` frame dereferences (which used the returned BP as a
  frame base) were re-expressed as direct `TRegFrame` field reads.
* `fn1EDA_04B7`'s `di = 0x109` (a raw code-segment offset) became
  `&g_seg1EDA[0x0109]`.

## Sites that could not be recovered literally

These are interface losses caused by the frozen prototypes (derived from
Reko signature errors), not by the conversion.  They are recorded here as
required by `CONVENTIONS.md` rule 7.

1. **`fn13C8_000D`** — the ASM writes AX/BX to two caller-supplied far
   pointers (`[bp+0Ah]`, `[bp+06h]`); the frozen prototype has only
   `void * dsOut`.  Both known callers (`fn13C8_0139`, `fn133F_0056`)
   pass `ds:0B6AE` and `ds:0B6B0`, so those two DGROUP words are written
   directly instead.  Behaviour preserved for both callers.

2. **`fn13C8_0066`** — the ASM writes CX/DX/BX to three caller-supplied
   far pointers; the frozen prototype has only `void * bpOut,
   void * dsOut`.  The callers do **not** agree: `fn13C8_0139` passes
   `0B6B6/0B6B8/0B6B4`, while `fn133F_0528` passes `62CE/62D0/62D2`.
   With the pointers unavailable the stores are omitted (documented in
   the body); the wrapper still performs INT 33h function 3.

3. **`fn13C8_009A`, `fn13C8_00BF`, `fn13C8_00E4`** — each reads two stack
   arguments (`[bp+06h]`/`[bp+08h]`) into frame CX/DX before INT 33h
   (function 4/7/8), but the frozen prototypes take no arguments.  The
   argument-derived words are left at the zero-initialised frame value.
   Call sites show these are not constant: `fn13C8_0139` uses
   `0280h/0`, `fn133F_0056` uses `027Fh/0`, `fn133F_04B1` forwards its
   own arguments.

4. **`fn13C8_0111`** — the ASM stores the AX result of `fn1EDA_04B7`
   into frame DX; the canonical `fn1EDA_04B7` prototype returns `void`,
   so the result cannot be captured.  That frame word is left zero.

5. **`fn13C8_0038` / `fn13C8_004F`** — Reko's `bpOut` (the preserved BP
   register chain) is modelled as the frame BP word; the original value
   is only a register-preservation artifact, so the exact Reko
   dereference could not be reproduced.  `dxOut` (DX result) and the AH
   return are faithful.

6. **`fn13C1_0036`** — the ground-truth ASM ends with `retf 4h` although
   8 bytes of arguments are pushed by the caller (`fn1229_050A`); this is
   an original code quirk.  It has no effect on the C model (the two
   frozen parameters cover all eight bytes).

## Portability fixes

* `TRegFrame` locals are zero-initialised.  The original relied on whatever
  the DOS stack happened to contain; zeroing makes the wrappers
  deterministic.  It is observable only in the lossy cases 3 and 4 above.
* No other deviation from the disassembly.

## Validation

* `gcc -c -Wall -Isrc -Ipal src/seg13C1.c src/seg13C8.c` — clean.
* Reko-token grep (`Eq_[0-9]`, `MemN[`, `<invalid>`, `<unknown>`) — no
  matches in either file.
* All 13 functions are defined with the exact frozen prototypes.
* `nm` reports all 13 as `T` in the corresponding object files.

## Hardware-abstraction repair (restored stack arguments)

The earlier conversion was forced to drop stack arguments because the frozen
prototypes (derived from Reko's incomplete signatures) had no slots for them.
Those prototypes are now corrected in `analysis/tools/gen_iface.py` (documented
`SPECIAL_CASES`) and regenerated into `src/seg13C8.h` / `src/seg13C1.h`.  The
wrappers call `fn1E5F_000B(frame, vec)` (the repaired trampoline, see
`docs/notes-1E5F-1E78-11C8.md`) and restore the omitted stores.

| function | old prototype | new prototype |
| --- | --- | --- |
| `fn13C8_000D` | `u16 fn13C8_000D(void * dsOut)` | `u16 fn13C8_000D(u16 * ptrArg06, u16 * ptrArg0A, void * dsOut)` |
| `fn13C8_0066` | `u16 fn13C8_0066(void * bpOut, void * dsOut)` | `u16 fn13C8_0066(u16 * ptrArg06, u16 * ptrArg0A, u16 * ptrArg0E, void * bpOut, void * dsOut)` |
| `fn13C8_009A` | `u16 fn13C8_009A(void * bpOut, void * dsOut)` | `u16 fn13C8_009A(u16 wArg06, u16 wArg08, void * bpOut, void * dsOut)` |
| `fn13C8_00BF` | `u16 fn13C8_00BF(void)` | `u16 fn13C8_00BF(u16 wArg06, u16 wArg08)` |
| `fn13C8_00E4` | `u16 fn13C8_00E4(void * dsOut)` | `u16 fn13C8_00E4(u16 wArg06, u16 wArg08, void * dsOut)` |
| `fn13C8_0111` | `void * fn13C8_0111(u16 wArg04)` | `void * fn13C8_0111(u16 wArg06)` |
| `fn1EDA_04B7` | `void fn1EDA_04B7(...)` | `u16 fn1EDA_04B7(...)` |

The parameter names/order follow the stack offsets proved by the slices
(`retf` counts and `les di,[bp+NN]`): the last-pushed argument is the first C
parameter.  `fn13C8_0111` is a far proc, so its single argument really is at
`[bp+06h]` (`retf 2`); Reko's `wArg04` was a near-call artefact and is renamed
`wArg06`.  `fn1EDA_04B7` returns AX (unchanged on the in-range `retf` at
`04D8`, `00C9h` otherwise), which `fn13C8_0111` stores into frame DX.

Resolved sites:

1. **`fn13C8_000D`** — the two far out pointers are real parameters again.
   `fn13C8_0139` passes `ds:0B6B0` / `ds:0B6AE` (first/second stack arg), so
   `[bp+06h] <- BX` and `[bp+0Ah] <- AX` land in 0B6B0 / 0B6AE exactly as the
   original.
2. **`fn13C8_0066`** — the three far out pointers are real parameters.  The
   callers genuinely disagree (`fn13C8_0139`: 0B6B8/0B6B6/0B6B4;
   `fn133F_0528`: 62D2/62CE/62D0), which is precisely why pointer parameters
   are required; `fn13C8_0139`'s targets are passed.
3. **`fn13C8_009A` / `00BF` / `00E4`** — the two word arguments
   (`[bp+06h] -> DX`, `[bp+08h] -> CX`) are parameters again.  `fn13C8_0139`
   passes `0280h/0` (fn7) and `01E0h/0` (fn8) exactly as the original.
4. **`fn13C8_0111`** — `fn1EDA_04B7`'s AX is captured and stored into frame
   DX (`mov [bp-0Eh],ax`), completing the INT 33h fn13h setup.

Still owed / notes:

* **`fn13C8_0038` / `fn13C8_004F`** (unchanged from before): Reko's `bpOut` is
  a register-preservation artefact; the frame BP word is returned and the ASM
  itself reads nothing back.  Their signatures were not part of this repair.
* **`fn13C8_0139`** keeps the original `ds_32`/`bp_171`/`ds_172`/`ds_173`
  locals for the (unwritten) `dsOut`/`bpOut` register outputs; the out-pointer
  arguments are passed as `(u16 *)&g_dgroup[0x....]` because the targets are
  DGROUP words.
* **`prototypes.h` identity.**  The regenerated `src/seg13C8.h` now differs
  from `src/prototypes.h` for `fn13C8_000D`, `fn13C8_0066`, `fn13C8_009A`,
  `fn13C8_00BF`, `fn13C8_00E4` (5 of the 41 entries).  This is intentional:
  `prototypes.h` is the superseded Reko-derived reference, while `iface.tsv`
  now carries the asm-corrected contract.  (`fn1E5F_000B` and `fn1EDA_04B7`
  are not present in `prototypes.h`.)
