# Recovery notes — small segments

## 1206

Scope: `src/seg1206.c` (11 functions, ascending offsets `0000`..`0217`),
recovered from `analysis/slices/1206/1206_<off>.{c,asm}` (Reko skeleton +
ground-truth disassembly) and `analysis/reko/RAD_1206.{asm,c}`.  Frozen
prototypes adopted verbatim from `src/seg1206.h` (generated from
`analysis/summary/iface.tsv`).  No header was modified.

### What the segment does

Segment 1206 is the mouse (INT 33h) interface used by the text-mode menu
screens.  Every wrapper builds a 0x14-byte register frame (`enter 14h`) and
issues INT 33h through `fn1E5F_000B` (1E5F:000B), the register-frame
interrupt trampoline (PAL: `pal_int_dispatch()`), then stores/returns the
post-interrupt register set:

| function | offset | INT 33h function | role |
|---|---|---|---|
| `fn1206_0000` | 0000 | — | constant 1 (driver query helper) |
| `fn1206_000D` | 000D | 0 | reset / driver status |
| `fn1206_0038` | 0038 | 1 | show cursor (guarded by 597Eh/598Ch) |
| `fn1206_0066` | 0066 | 2 | hide cursor (guarded) |
| `fn1206_0094` | 0094 | 3 | get position + buttons |
| `fn1206_00D1` | 00D1 | 4 | set cursor position |
| `fn1206_00FF` | 00FF | 7 | set horizontal range |
| `fn1206_012D` | 012D | 8 | set vertical range |
| `fn1206_015B` | 015B | 3 (via 0094) | poll + latch cursor/buttons |
| `fn1206_01AC` | 01AC | 0,3,7,8,4 | full mouse init sequence |
| `fn1206_0217` | 0217 | — | init wrapper: calls 01AC with constants |

DGROUP words: `597Ah`/`597Ch` (reset status), `597Eh` (mouse-present),
`5980h` (button latch), `5982h`/`5984h` (cursor x/y), `598Ch`
(cursor-shown latch).

### Dispatch sites (kept literal; hardware replaced downstream)

All seven interrupt issues go through `fn1E5F_000B((u8 *)&r, 0x33)` — raw
IVT dispatch is preserved literally per CONVENTIONS.md rule 4:

`1206:000D`, `1206:0038`, `1206:0066`, `1206:0094`, `1206:00D1`,
`1206:00FF`, `1206:012D` (each ONE `fn1E5F_000B` call).  `fn1206_015B`,
`fn1206_01AC` and `fn1206_0217` reach the interrupt only through those
wrappers.

There is **no** direct `int 10h`/`int 16h`/`int 21h`, **no** `in`/`out`
port site, **no** `__cli`/`__sti` and **no** `int 23h` in segment 1206.

### Reko artifacts resolved

* Every `MemN[ds:0xHHHH:t]` became `LG8`/`LG16` (DGROUP offsets 597Ah,
  597Ch, 597Eh, 5980h, 5982h, 5984h, 598Ch).
* `Eq_17 ds` value parameters and `Eq_17`/selector output parameters are
  dropped in the flat model; the frozen `dsOut` slots are left unwritten,
  exactly as in `seg13C8.c`/`seg13C1.c`.
* DGROUP far pointers are `(u16 *)&g_dgroup[0xHHHH]`; the register frame is
  the file-local `TRegFrame` (layout proved by the 1E5F:0045 store-back
  sequence, not invented).
* Reko's `ss->*bp_NN` frame dereferences were re-expressed as direct
  `TRegFrame` field reads.

### Portability fix

`TRegFrame` locals are zero-initialised.  The original relied on whatever
the DOS stack happened to contain; zeroing makes the wrappers
deterministic and is observable only in the lossy cases below.

### Sites that could not be recovered literally (rule 7)

These are interface losses caused by the frozen prototypes (derived from
Reko's incomplete signatures), not by the conversion.  The argument order
follows the 13C8 finding: **the last-pushed argument is the first C
parameter**.

1. **`fn1206_00D1` / `fn1206_00FF` / `fn1206_012D`** — the ASM reads two
   stack word arguments (`[bp+06h]` -> DX, `[bp+08h]` -> CX) into the frame
   before the INT 33h fn 4/7/8 call (`retf 4h`), but the frozen prototypes
   have no slots for them.  The argument-derived frame words stay at the
   zero-initialised value.  Call sites confirm they are not constant
   (`fn1206_01AC` forwards its own args; `0800:33B2`/`0800:4255` push
   `1D1h/198h`, `1B4h/9Ch`, ...).
2. **`fn1206_015B`** — the ASM compares `[bp+06h]` (one word argument,
   `retf 2h`) against the button state; the frozen prototype has no slot.
   Every caller in the image pushes `0` (`push 0h ; call far 1206h:015Bh`),
   so the comparison is modelled with the constant 0.
3. **`fn1206_01AC`** — the ASM takes six word arguments (`retf 0Ch`) and
   forwards them to 00FF/012D/00D1; the frozen prototype has none.  The
   in-file caller `fn1206_0217` and the external callers
   (`0800:19D5`, `0800:3E3C`) pass non-constant values, which are lost.
4. **`fn1206_0217`** — the ASM pushes six constant words
   (`0,0,27Fh,1DFh,0,0`) to `fn1206_01AC`; the frozen prototype of 01AC
   cannot carry them.
5. **Register-output pointer parameters** (`chOut`, `dxOut`, `bpOut`,
   `siOut`, `esOut`) are materialised from the trampoline frame after the
   dispatch, following `seg13C8.c`.  Where the ASM has real far-pointer
   memory stores (`fn1206_000D`: AX/BX; `fn1206_0094`: DX/CX/BX) those
   stores are mapped onto the pointer parameters in stack-offset order
   (`[bp+06h]`, `[bp+0Ah]`, `[bp+0Eh]`).  `dsOut` is always the dropped DS
   selector and is never written.
6. **Return values** — the 1E5F:0045 continuation leaves AX = FLAGS; C
   cannot observe it.  Where the ASM explicitly reloads AX after the
   dispatch the loaded word is returned (`fn1206_000D` -> BX,
   `fn1206_0094` -> BX); the remaining wrappers return the frame AX word
   (or `(u8)(AX >> 8)` for the AH-returning 0038/0066).  No caller of the
   dropped-argument routines uses these returns.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1206.c` — clean (exit 0).
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>` — no matches.
* All 11 functions defined with the exact frozen prototypes (`seg1206.h`
  included, so a signature mismatch would fail the compile).
* `nm` reports all 11 as `T`.

## 0C43

Scope: `src/seg0C43.c` (6 functions, ascending offsets
`0000`/`001E`/`0056`/`0095`/`00B9`/`02FB`), recovered from
`analysis/slices/0C43/0C43_<off>.{c,asm}` (Reko skeleton + ground-truth
disassembly) and `analysis/reko/RAD_0C43.{asm,c}`.  Frozen prototypes
adopted verbatim from `src/seg0C43.h` (generated from
`analysis/summary/iface.tsv`).  No header was modified.

### What the segment does

Segment 0C43 is the mode-13h picture loader reached from `fn0800_4255`:

| function | offset | role |
|---|---|---|
| `fn0C43_0000` | 0000 | INT 10h AH=00 (set mode, AL=bArg02) via the frame |
| `fn0C43_001E` | 001E | INT 10h AH=10h AL=12h (set palette block) via the frame |
| `fn0C43_0056` | 0056 | RLE expand `ds:5884/5886` -> VRAM (`es=[5882h]`) |
| `fn0C43_0095` | 0095 | close the stream block and free the far-heap block |
| `fn0C43_00B9` | 00B9 | open/load/decompress a file, drive the in-loop menu |
| `fn0C43_02FB` | 02FB | seed VRAM selector `5882h = 0A000h` |

DGROUP words: `5882h` (VRAM selector, only ever `0A000h`), `5884h`/`5886h`
(far-heap block, split offset/segment), `5892h` (RLE run counter), `5894h`
(chunk byte count), `589Ah` (VRAM destination offset), `556Eh` (menu
abort flag), and the 0x14-byte INT 10h register frame at `589Ch..58AFh`.

### Dispatch sites (kept literal; hardware replaced downstream)

Two interrupt issues, both vector 10h, both through
`fn1E5F_000B((u8 *)&g_dgroup[0x589C], 0x10)`:

* `0C43:0015` in `fn0C43_0000` (AH=00 set mode),
* `0C43:004D` in `fn0C43_001E` (AH=10h AL=12h).

`fn0C43_00B9` reaches the interrupt only through those two wrappers.
There is **no** direct `int 10h`/`int 16h`/`int 21h`, **no** `in`/`out`
port site, **no** `__cli`/`__sti` and **no** `int 23h` in segment 0C43.

### Reko artifacts resolved

* Every `MemN[ds:0xHHHH:t]` became `LG8`/`LG16`/`LG32`.
* `Eq_17 ds` value parameters and `Eq_17`/selector output parameters are
  dropped in the flat model (`(void)dsOut`, `(void)ds_*`), exactly as in
  `seg13C8.c`/`seg1206.c`.
* The 0x14-byte frame at `589Ch` is passed to `fn1E5F_000B` as
  `(u8 *)&g_dgroup[0x589C]`; the post-interrupt words are read back with
  `LG16` (`58A2h` DX, `58A4h` BP, `58ACh` ES, `58AEh` FLAGS).
* `fn0C43_001E`'s far `ptrArg02` is split into frame ES/DX with the
  established flat convention `(u16)(uintptr_t)p` /
  `(u16)((uintptr_t)p >> 16)` (cf. `seg1AB8_part1.c`).
* `es = [5882h]` is `pal_vga_memory()` (the only value ever stored there is
  `0A000h`, by `fn0C43_02FB`); `ds:5884/5886` is the flat pointer
  `(u8 *)(uintptr_t)LG32(0x5884)`.
* Reko's `ss->*bp_NN` frame dereferences were re-expressed as direct
  `FLOC(off)`/`FL16`/`FL8` accesses (below).

### Portability fixes (rule 7)

1. **`fn0C43_00B9` local frame is file-static.**  The original's helpers are
   handed `SS:bp-0D4h` as a u16 word (`fn0C43_0095`: `mov di,[bp+4h] ;
   add di,0FF2Ch`).  The frame is modelled as
   `static u8 g_frame0C43_00B9[0xE4]`; `fn0C43_00B9` passes the frame top
   `0x00E4` as `wArg02`, and `fn0C43_0095` reconstructs the stream block
   with the literal 16-bit add `g_frame0C43_00B9 + (u16)(wArg02 + 0xFF2C)`
   (= frame offset `10h`).  The buffer is therefore `.bss`-zeroed and
   persists between calls rather than living on the host stack; the
   original also reads several frame words before writing them, so zeroing
   makes them deterministic (same trade-off as `seg1206`'s `TRegFrame`).
2. **`fn1EDA_116A` DX loss.**  `1EDA:116A` leaves `DX:AX` = the 32-bit
   record length; the frozen prototype returns only AX.  The original then
   does `call 04A9h` (a register-preserving trap) and `sub ax,301h ;
   sbb dx,0h`, using the DX:AX that `04A9` preserved.  The flat
   `fn1EDA_04A9` returns 0 on the surviving path, so the code keeps
   `116A`'s AX for the low word and cannot recover the high word; the DX
   half stays as produced by `04A9` (0).  This is the only place the
   recovered subtraction differs, and it traces to the frozen 1EDA
   interfaces (documented in `docs/notes-1EDA.md`).
3. **Register-preserving `04A9` + AL.**  Where the ASM branches on AL
   after `call 04A9h` (the `fn1EDA_1185` EOF test at `0202h`), the code
   keeps `fn1EDA_1185`'s low byte rather than `04A9`'s return, because the
   flat `04A9` cannot preserve AL.
4. **Dropped data buffer (`fn1EDA_10BB`).**  Every `10BB` call passes the
   read target on the stack; the frozen prototype has no slot for it and
   the flat `1EDA_10BB` reads into its own `g_1EDA_io_buffer` instead
   (`docs/notes-1EDA.md`).  The frame read buffers (`bp-0E0h`, `bp-0DDh`)
   therefore keep their zero value, which only affects the lossy
   menu/status compares already noted for the sister segments.
5. **`0x5884/0x5886` block is never populated** for the same reason: the
   original streams records into the far-heap block that `fn1EDA_023F`
   allocated, but the flat `10BB` discards the target.  `fn0C43_0056`'s
   source pointer is modelled flat per the convention; this is an
   inherited 1EDA-interface loss, not a 0C43 conversion choice.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C43.c` — clean (exit 0); also clean
  under `-std=c99 -Wall -Wextra`.
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>` — no matches.
* All 6 functions defined with the exact frozen prototypes (`seg0C43.h`
  included, so a signature mismatch would fail the compile).
* `nm` reports all 6 as `T`.
