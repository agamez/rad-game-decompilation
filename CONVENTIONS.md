# RAD Linux Port — Porting Conventions (READ FIRST)

This is a **software-preservation port**: we recover the original implementation of
RAD V3.1 (MS-DOS, Borland Turbo C, 16-bit real mode) from the executable and recompile
it for modern Linux with a thin SDL2 hardware-abstraction layer.

**The executable is the source of truth.** Reference material lives in `analysis/reko/`:
* `RAD_<seg>.asm` — raw disassembly per segment (ground truth for control flow)
* `RAD_<seg>.c`   — Reko decompiled C (ground truth for structure/types)
* `RAD_<seg>.dis` — annotated disassembly
* `RAD.h`, `RAD.globals.c` — generated types / globals map

## Absolute rules
1. Preserve original control flow, algorithms, arithmetic, data layouts, lookup
   tables, state machines, evaluation order, and bugs.
2. Never refactor, simplify, "clean up", or optimize recovered code.
3. Never change integer widths. 16-bit semantics must be preserved:
   - unsigned 16-bit arithmetic wraps: use `u16` and let it wrap.
   - signed 16-bit overflow in the original compiled to 16-bit wrap too; emulate with
     `(i16)(u16)expr` casts, never rely on C signed-overflow behavior.
   - division/shift/modulo widths must match the original.
4. Replace ONLY DOS/hardware dependencies:
   - `int 10h` → named `bios_video_*` calls (see pal/pal.h)
   - `int 16h` → named `bios_kbd_*` calls
   - `int 21h` → named `msdos_*` calls
   - raw port I/O `in al,dx` / `out dx,al` → `pal_inport(port)` / `pal_outport(port, val)`
     (KEEP the literal port constants in the recovered code!)
   - `__cli()` / `__sti()` → drop (no-ops)
   - `int 23h` (Ctrl-C) → drop
5. Everything else must be recovered literally. If the recovered code looks ugly,
   inefficient, or redundant — keep it exactly that way.
6. Do not invent behavior. When in doubt, read the .asm, not the .c (the .asm is
   ground truth; the .c is Reko's interpretation).
7. Every deviation from literal recovery must be recorded in `docs/PORT.md`.

## Naming
* Functions: keep Reko names `fn<seg>_<off>` until the original meaning is *certain*
  (string references, doc cross-refs, unambiguous behavior). Then rename to a
  descriptive snake_case name and keep the original as a comment on the definition:
  `/* fn1AB8_1F19 */`.
* Globals (DGROUP data at ds-relative offsets): declare `g_<hex offset>` (e.g. `g_B8A3`)
  in `src/globals.c` with correct type/size; rename only when certain.
* Do not invent struct layouts beyond what the decompilation proves.

## Type system
`src/radtypes.h` defines: `u8 u16 u32 s8 s16 s32` plus `word16 word32 byte` aliases.
Far pointers (seg:off) in the original become flat pointers (`u8 *`, typed structs).
DGROUP is flat: `Mem7[ds:0xB8A3:word16]` in Reko output = `g_B8A3` here.

## File organization
* `src/seg<seg>.c` — one translation unit per original code segment.
* `src/globals.c`  — DGROUP data variables.
* `pal/` — SDL2 platform layer. Gameplay code never includes SDL; only pal/ does.
* `docs/PORT.md` — documentation of replaced hardware interfaces, portability fixes,
  compiler compatibility fixes, and anything that could not be recovered literally.

## Memory model (authoritative — see analysis/SEGMAP.md)
* DGROUP = original segment 2014 (ds register at runtime). Represent it as a
  flat 64 KiB array `u8 g_dgroup[0x10000]` in `src/globals.c`.
* Reko `Mem7[ds:0xB8A3:word16]` → `LG16(0xB8A3)` (macro reading/writing
  `*(u16*)&g_dgroup[0xB8A3]`). Offsets stay literal — this preserves aliases,
  pointer arithmetic and layout exactly.
* DGROUP _DATA (offsets 0x0000..0x5390) is file-backed: `pal`/init copies
  `data/segments/dgroup_data.bin` into g_dgroup at startup (this is what the
  DOS loader did). _BSS (0x5390..0xBB10) is zero-initialized. Stack (0xBB10..)
  unused (we run on the host stack).
* Other segments' embedded data (e.g. seg13E2 tables) are exposed as
  `seg13E2_bytes[]` arrays loaded from `data/segments/segNNNN.bin`;
  `seg13E2:0x594F` → `seg13E2_bytes[0x594F]`.
* Far pointers (Reko `Eq_17`, `selector`, `ptr16 Eq_N`) become `u8 *` / typed
  pointers in the flat host space; `MK_FP(seg,off)` constructions become
  pointers into the corresponding array.

## Interface conversion (cross-segment calls)
* Canonical interface table: `analysis/summary/iface.tsv` — one derived C
  prototype per function (358 total). `analysis/tools/gen_segheaders.py`
  turns it into `src/seg<seg>.h` (one header per segment, include-guarded).
  Segment conversions MUST adopt the iface.tsv prototype exactly; if the
  .asm proves it wrong, correct iface.tsv and regenerate — never diverge
  silently. `src/prototypes.h` (41 expressible Reko prototypes) is superseded
  by this table and kept only as reference.
* Derivation rules (ground truth = .asm register usage):
  - Reko implicit `Eq_17 ds` / segment & selector parameters: drop entirely.
  - `out X` / `Register out` parameters → pointer parameters (`u16 *`, `u8 *`…).
  - `Eq_N` register-group value parameters → the concrete register/type the
    .asm shows (usually u16 or u8; DX:AX pairs → u32 or two u16s per usage).
  - Return value: AL → u8, AX → u16, DX:AX → u32 (or split into out params
    the way the .asm consumers read them).
  - Far data pointers (`ptr16 Eq_N`, `struct Eq_N *`) → typed pointers into
    the flat space (see Memory model).
* When the .asm is ambiguous, choose the type that reproduces the arithmetic
  exactly (16-bit ops stay 16-bit), and record the choice in iface.tsv notes.
