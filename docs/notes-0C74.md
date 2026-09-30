# Segment 0C74 (GAME CORE) — port notes

## part 1

Functions `0C74:0000 .. 0C74:02D8` (8 functions, ascending offset):

```
0000 004B 007C 00B2 00DB 011E 020C 02D8
```

Recovered into `src/seg0C74_part1.c`.  Ground truth =
`analysis/slices/0C74/0C74_<off>.asm` plus `analysis/reko/RAD_0C74.{asm,c,dis}`;
frozen prototypes adopted from `src/seg0C74.h` (`analysis/summary/iface.tsv`) with
no edits.

### Hardware / dispatch sites

**None.**  No `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port instruction,
no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch occur in 0000..02D8.
The only hardware-touching calls are indirect, into already-ported segments:

* `fn1206_0066` / `fn1206_0038` — INT 33h mouse wrappers (`seg1206.c`), reached
  from `0C74:011E` and `0C74:020C`.
* `fn1E78_029C` — keyboard/pacing helper (`seg1E78.c`), reached from
  `0C74:02D8`.
* DOS file probing `fn1E5F_00DE` (find-first, `seg1E5F.c`) from `0C74:0000`.

### Segment data referenced

* `cs:00FCh` = {1,"0"} — single-digit pad record for the seconds field (011E).
* `cs:01EAh` = {1,"0"} — single-digit pad record for the minutes field (020C).
* `cs:00FEh` / `cs:01ECh` — bitmask byte tested by `fn1EDA_0CD4` (bit
  `0x58E4 & 7`), i.e. the "clock field visible" flag.

### Flat-model / ABI adaptations

1. **`fn1AB8_1285` AX return.** The frozen prototype is `void`, but
   1AB8:1285 materialises `AX = (u16)LG8(0xB83E)` and 011E/020C consume it
   (`call far 1AB8h:1285h ; mov [bp-6h],ax`).  The value is re-read from DGROUP
   right after the call: `wLoc06 = (u16)LG8(0xB83E);` (the interpretation
   already recorded in `seg1AB8_part4.c`).
2. **Stack-reuse string helpers.** `fn1EDA_0A1F` / `0AAC` / `0A39` use the CPU
   stack as a persistent scratch area: a callee leaves a far pointer staged for
   the next call (e.g. `fn0C74_004B`'s `retf 4h` leaves the caller-pushed
   `ss:bp-0106h` buffer pointer on the stack, which the following `0A39` reuses
   as its `src`).  Reko recovered those staged values (`ptrLoc010C_298/308`);
   here the buffer address is passed explicitly, matching seg0800 parts 1/3 and
   seg1229 part 2b.  Argument order is the last-pushed-first C order recovered
   from each callee body: `0A39(count, dest, src)`, `0A1F(src, dest)`,
   `0AAC(src, dest)`.
3. **Saved-BP / register outputs.** `fn1206_0066` / `fn1206_0038` have BP and
   DS register outputs, and `fn0C74_011E` / `020C` / `02D8` return Reko's saved
   BP word.  These are frame artifacts with no flat-C equivalent (the PAL mouse
   frame is zero-initialised).  Per `docs/notes-0800.md`, the output pointers
   receive `0`, the functions return `0`, and the `dsOut` slots receive `0`
   (DGROUP selector dropped).
4. **`fn1EDA_0CD4` esOut.** The frozen prototype's `void * esOut` is written by
   the callee as `*(u8 **)esOut = ptrArg04`, i.e. a full host pointer.  The two
   011E/020C call sites therefore pass address-of-`u8 *` locals
   (`u8 *es_344`, `u8 *es_348`), not the 2-byte words used by some older
   call sites (which would overrun).
5. **`fn1EDA_098A` outputs.** Both 02D8 call sites are the literal identical
   divide of `LG32(0x58D8)` by `0x3C`; the first stores the quotient
   (`DX:AX`) to `58CCh:58CEh`, the second the remainder (`BX:CX`) to
   `58DCh:58DEh`.  `dsOut` is `void *` per the frozen prototype and receives a
   `void *` local.  The extra `wArg00`/`wArg02` stack words the prototype
   requires read only on the divide-by-zero fatal path (not reachable with
   divisor 3Ch), so they are seeded `0` (same choice as `seg0800_part3.c`).
6. **`fn0C74_0000` `dxOut`.** Reko assigns the DX register left by
   `fn1E5F_00DE` (the 44-byte DTA offset) to `dxOut`.  Every caller ignores it,
   so the flat port writes `0` and records the loss.

### Uncertain sites / not recovered literally

* **Saved-BP returns of 011E/020C/02D8.**  Reko returns `Mem[ss:bp]` (the
  caller's frame word).  The flat model has no BP chain; `0` is returned.  All
  intra-part callers ignore it; the 02D8 callers in later chunks that use the
  return as a frame pointer must apply the same documented convention.
* **`fn0C74_0000` `dxOut`.**  Written `0`; value is dead in every caller.
* **02D8 loop guard.**  The `.asm` computes `count = wArg02 / 7` then tests
  `0 <= count` unsigned (`jbe`), which is always taken; the recovered
  `if (wLoc04 >= 0x0000)` preserves the original (empty) alternative exit.
* **`fn1EDA_0F26` first argument** (`0xFF` in 0000/004B) is kept literal; it is
  the field width/flag consumed by the already-ported formatter.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part1.c` — 0 errors, 0 warnings.
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(`
  over `src/seg0C74_part1.c` — 0 matches.
* All 8 in-range functions defined with the exact `src/seg0C74.h` prototype;
  `nm` shows all eight as `T`.

## part 2

Functions `0C74:03D4 .. 0C74:076B` (5 functions, ascending offset):

```
03D4 05B8 06B7 070D 076B
```

Recovered into `src/seg0C74_part2.c`.  Ground truth =
`analysis/slices/0C74/0C74_<off>.asm` plus `analysis/reko/RAD_0C74.{asm,c}`;
frozen prototypes adopted from `src/seg0C74.h` (`analysis/summary/iface.tsv`)
with no edits.  Each function's call arguments were re-derived from the
callee's own `.asm` (the frozen prototype parameter order is last-pushed
first, verified against `1EDA:08CE`, `1EDA:0848`, `1EDA:10BB`, `1AB8:1E3C`,
`1AB8:1E54`, `1AB8:13D7`, `1AB8:1E6B`).

### Hardware / dispatch sites

**None.**  No `int 10h` / `int 16h` / `int 21h`, no raw `in`/`out` port
instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch occur
in 03D4..076B.  Hardware-touching work is reached only through already-ported
callees:

* `fn1E78_016B` / `fn1E78_029C` — keyboard/pacing helpers (`seg1E78.c`),
  reached from 03D4 / 076B.
* `fn11C8_0354` / `fn11C8_033B` — sound helpers (`seg11C8.c`), reached from
  070D / 076B (guarded by DGROUP `0x58B0`).
* `fn1EDA_0FA2` / `0FD0` / `10BB` / `1051` / `023F` / `0254` — DOS stream and
  far-heap helpers (`seg1EDA*.c`), reached from 03D4 / 05B8.
* `fn1AB8_*` — video driver (`seg1AB8*.c`).

### Far-heap blocks (`fn1EDA_023F` / `fn1EDA_0254`)

The 023F/0254 call sites here use the same convention as `seg0800_part1.c`:
the returned `DX:AX` 16:16 pair is stored as two DGROUP words and reconstructed
as `(segment << 16) | offset`, cast to `u8 *`.  In the shipped port the
far-heap node fetches in `fn1EDA_0308` resolve to zero, so these blocks are
`NULL`; that is the established project behaviour, not introduced here.

### Cross-segment adaptation (note, no header edited)

`src/seg1AB8.h` declares `fn1AB8_13D7` with a `void` return while
`seg1AB8_part4.c` defines it returning `u16`.  The frozen header is what this
part honours (`seg1AB8_13D7(...)` is called as a statement); the mismatch is
in the 1AB8 part, not here, and no header was modified.

### Flat-model / ABI adaptations

1. **`fn0C74_076B` frame layout.**  The function's `enter 30EEh` frame is
   addressed by literal BP displacement and contains three *deliberately
   overlapping* arrays: the X/Y word pairs indexed at `bp-0x2724`
   (`0D8DCh`/`0D8DEh`), the byte attribute array indexed at `bp-0x30E5`
   (`0CF1Bh`), and the named scalars at `bp-0x30EE..bp-1`.  `abFrame[0x30EE]`
   with the `F8`/`F16`/`AATTR`/`AX_ARR`/`AY_ARR` access macros reproduces the
   exact byte layout (including the `attr[0]` overlap with `wLoc30E6`'s high
   byte and the `wLoc30E7` byte sharing a word with an unused slot).  The
   index arithmetic applies the original 16-bit `shl di,2`.
   *Uncertain site:* the original can overrun this 0x30EE frame when the
   computed point count is large (the loop runs `area` times); the port keeps
   the same expressions and would overrun out of `abFrame` in the same way.
   No bounds clamp was added (literal recovery).
2. **`fn0C74_076B` area / loop count.**  The `.asm` does
   `mul dx` (unsigned, discarding `DX`) then `imul ax,ax,15h`, so only the
   low 16 bits survive; recovered as `(u16)(low16(...) * 0x0F)`.  The value is
   compared unsigned (`jbe`, `jz`).
3. **`fn0C74_070D` scale.**  Literal `mov ax,[bp+4h] ; mul [58E6h] ; cwd ;
   idiv cx(9)` — the `cwd` overwrites the `mul` high word, so the operation
   is `(s16)(u16)(wArg02 * LG16(0x58E6)) / 9`.  Kept exactly, truncated
   toward zero.
4. **`fn0C74_05B8` / `076B` signed compares.**  The 10E1-bound tests are
   full 32-bit signed compares (`cwd` + `jl`/`jg`/`jc`).  With a `cwd` high
   word of only `0`/`-1`, both reduce to `(s16)v >= 0 && (u16)[58BAh] < v`;
   written in that equivalent form.
5. **Saved-BP / DS outputs.**  `03D4`, `05B8`, `070D` and `06B7` return
   Reko's saved-BP word and/or a dropped DGROUP selector.  Per
   `docs/notes-0800.md` the out pointers receive `0` and the artifact return
   is `0`.  `05B8`'s return is ignored by every caller; `070D`'s `void * dsOut`
   is written as a `u16` zero (matching part 1's `dsOut = 0` convention and
   `seg0800_part1.c`), not as a selector value.
6. **`03D4` `wLoc8A`.**  The second `fn1AB8_13A3(2Bh,2Bh,0,0)` result
   (`[bp+0FF76h]`) is stored and never read anywhere in the segment; the call
   is kept and the store is kept (`(void)wLoc8A`) to preserve the side
   effects of `1AB8:13A3`.
7. **`03D4` `fn1EDA_10BB` data buffer.**  The read target (`ES:DI` block) is
   the dropped `[bp+0Ch]` argument of `10BB`; the flat prototype has no such
   parameter (the callee reads into its own `g_1EDA_io_buffer`), so the block
   pointers computed for `10BB` are only stored to their DGROUP tables and the
   call passes the stream block for `ptrArg0E` (same as `seg0800_part1.c`).
8. **`03D4` `0254` -> `1051` AL.**  The low byte of `fn1EDA_0254`'s return is
   forwarded to `fn1EDA_1051`, matching `l0C74_059Ah`.

### Uncertain sites / not recovered literally

* **`076B` frame overrun** (item 1 above): the exact wrap of the original
  16-bit `BP + di + 0D8DCh` addressing outside the frame is not modelled; the
  in-frame layout is exact.
* **`076B` `imul ax,ax,15h` high bits**: discarded by the original in 16-bit
  AX; reproduced by taking the low 16 bits.
* **Saved-BP / selector artifacts** (item 5): `0` substituted, as elsewhere.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part2.c` — 0 errors, 0 warnings
  (`-Wall -Wextra` likewise clean).
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(`
  over `src/seg0C74_part2.c` — 0 matches.
* All 5 in-range functions defined with the exact `src/seg0C74.h` prototype;
  `nm` shows `T fn0C74_03D4`, `T fn0C74_05B8`, `T fn0C74_06B7`,
  `T fn0C74_070D`, `T fn0C74_076B`.

## part 4

Function `0C74:0FA1` (one of the two largest functions of the program):

```
0FA1
```

Recovered into `src/seg0C74_part4.c`.  Ground truth =
`analysis/slices/0C74/0C74_0FA1.asm` plus the Reko slice `0C74_0FA1.c` /
`analysis/reko/RAD_0C74.{c,dis}`.  Frozen prototype adopted exactly from
`src/seg0C74.h` (`analysis/summary/iface.tsv`):

```c
u8 fn0C74_0FA1(void * bpOut, u16 * dsOut);
```

### Hardware / dispatch sites

**None directly.**  `0FA1` contains no `int 10h` / `int 16h` / `int 21h`, no
raw `in`/`out` port instruction, no `__cli`/`__sti`, no `int 23h` and no raw
IVT dispatch (`fn1E5F_000B` is never called here).  The only hardware-reaching
call is **indirect**: `fn0C74_0E2E` (0C74:0E2E), which owns the PC-speaker /
AdLib port I/O (`analysis/summary/functions.tsv` lists
`port42h;port43h;port61h;port388h;port389h` for it) and is handled by its own
chunk.  Every other callee is an already-ported file/video helper:
`fn1AB8_13A3/13D7/10F4/1AF6/1C32/1E3C/1E54/1E6B`, `fn1EDA_023F/0254/096F/098A`,
`fn0C74_02D8/070D/05B8/0A35` (part 1/2 code).

### Flat-model / ABI adaptations

1. **Reko `bp_XXXX` frame pointers folded to the local frame.**  After every
   `fn0C74_070D` / `02D8` / `0E2E` call the Reko `bp_1039` (and later `bp_1129`,
   `bp_1645`, `bp_1926`, `bp_2200`, `bp_2412`, `bp_2530`, `bp_2694`) is
   re-bound to the callee's AX/pointer return and then used as
   `ss:[bp_XXXX - k]`.  Those reads are always the current function's own
   frame (`[bp-0Ah]`, `[bp-04h]`, …); the translations use the literal locals
   directly, per the part 1 §3 convention.
2. **16:16 far blocks.**  The heap blocks returned by `fn1EDA_023F` are carried
   as `u32` (`offset | segment<<16`, low word at the lower address, matching the
   original `[bp-10h]/[bp-0Eh]`, `[bp-14h]/[bp-12h]`, `[bp-18h]/[bp-16h]`,
   `[bp-1Ch]/[bp-1Ah]`) and materialised at the call sites with
   `(u8 *)(uintptr_t)dw`, the same convention as `seg0800_part3.c` /
   `seg1229_part1.c`.
3. **`fn1EDA_098A` `void * dsOut`.**  Receives a `void *` local (`dsv`), as its
   implementation stores a full pointer (`*(void **)dsOut`); cf. part 1 §5.
4. **Leftover-stack words seeded 0.**  `fn1EDA_023F` (frozen `wArg00`/`wArg02`),
   `fn1EDA_098A` (`wArg00`/`wArg02`) and `fn1EDA_0254` (`wArg00`/`wArg02`) take
   stack words the original never pushes (far-return-address / leftover slots,
   read only on the fatal divide-by-zero dispatcher path).  All are seeded `0`
   (same choice as `seg0800_part3.c` / part 1 §5).
5. **`fn0C74_0E2E` caller-frame argument seeded 0.**  The four call sites
   `push bp` before `call 0E2Eh`; 0E2E reads `ss:[wArg02-4]` (the caller's
   `[bp-04h]`, i.e. the index in `wLoc04`).  Flat C has no `SS:BP` chain, so
   the frozen `u16 wArg02` slot receives `0` (notes-0800.md / `seg0800_part5.c`
   precedent); recorded as an interface loss below.
6. **`bpOut` / `dsOut` register outputs.**  Reko writes the caller's saved BP
   and the DGROUP selector; both receive `0` (part 1 §3).  The distinct `[bp-01h]`
   return byte is preserved and returned.

### Uncertain sites / not recovered literally

* **`fn0C74_0E2E` `wArg02` (item 5).**  Cannot pass the caller's `SS:BP`; seeded
  `0`, so the two `0E2E` rectangles are drawn with a zero caller-frame offset.
* **`fn1EDA_096F` BX argument.**  The `.asm` sets BX = sign-extension of
  `LG16(0x58E6)` (`mov ax,[58E6h] ; cwd ; mov cx,ax ; mov bx,dx`) before the
  multiply; the Reko slice passed `0x00` for BX.  The `.asm` is followed here
  (`(u16)(s16)LG16(0x58E6)`), which is identical to the 16-bit product unless
  `[58E6h]` is negative.
* **Dead `098A` `wArg00`/`wArg02`.**  Item 4; the divisor is always `4`.
* **`0C74:1310`/`1329` `cmp word [5968h],0FFh`.**  Recovery (and
  `RAD_0C74.dis` IR) shows the immediate is sign-extended to `0xFFFF`, tested
  as `LG16(0x5968) == 0xFFFF` (cf. notes-1AB8.md item 4).
* **Far-block pointers.**  `(u8*)(uintptr_t)dw` reproduces the original
  segment:offset value as an integer; it is not a host pointer (the same
  documented convention as `seg0800_part3.c`).  `fn1AB8_1E6B`/`13D7`
  split it back into `(u16)`/`(u16)(p>>16)`, so the arithmetic is exact; the
  heap paths themselves are not exercised by the build.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part4.c` — 0 errors, 0 warnings
  (`-Wall -Wextra` likewise clean).
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(`
  over `src/seg0C74_part4.c` — 0 matches.
* `fn0C74_0FA1` defined with the exact `src/seg0C74.h` prototype (the TU
  includes the header, so gcc rejects any divergence); `nm` shows
  `T fn0C74_0FA1`.

## part 3

Functions `0C74:0A35 .. 0C74:0E2E` (6 functions, ascending offset):

```
0A35 0CFA 0D43 0D94 0DE5 0E2E
```

Recovered into `src/seg0C74_part3.c`.  Ground truth =
`analysis/slices/0C74/0C74_<off>.asm` plus the Reko slices
`0C74_0A35.c` / `0CFA.c` / `0D43.c` / `0D94.c` / `0DE5.c` / `0E2E.c` and
`analysis/reko/RAD_0C74.{c,dis}`.  Frozen prototypes adopted exactly from
`src/seg0C74.h` (`analysis/summary/iface.tsv`) with no edits.  Every callee
argument order was re-derived from the callee's own `.asm` (the frozen
parameter list is last-pushed first): `1AB8:13A3/13D7/1E3C/1E54/1E6B`,
`1EDA:0D80/023F/0254`, `1E78:029C`, `11C8:033B/0354`, `0C74:070D/02D8`.

### Hardware / dispatch sites

**None directly.**  No `int 10h` / `int 16h` / `int 21h`, no raw `in`/`out`
port instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch
occur in `0A35..0E2E`.  Hardware is reached only indirectly through
already-ported callees:

* `fn0C74_070D` -> `fn0C74_02D8` and `fn11C8_0354` / `fn11C8_033B` — the
  sound helpers (`seg11C8.c`), guarded by DGROUP `0x58B0`; `070D` is used by
  `0CFA`/`0D43`/`0D94`/`0DE5`/`0E2E`.
* `fn1E78_029C` — keyboard/pacing helper (`seg1E78.c`), reached from `0A35`.
* `fn1AB8_*` — the text/video driver (`seg1AB8*.c`).
* `fn1EDA_0D80` / `023F` / `0254` — random helper and far-heap helpers.

The PC-speaker / AdLib ports (`port42h;43h;61h;388h;389h`) that
`analysis/summary/functions.tsv` attributes to `fn0C74_0E2E` are **transitive**
(the `0E2E` body itself issues no port I/O; the ports belong to its `070D` ->
`02D8`/`11C8` descendants).  Corrected here; the part 4 note calling `0E2E`
the port owner inherits that functions.tsv attribution.

### Flat-model / ABI adaptations

1. **`fn0C74_0A35` frame layout.**  `enter 30ECh`; the same two deliberately
   overlapping arrays as `fn0C74_076B` (part 2): X/Y word pairs indexed at
   `bp-0x2724` (`0D8DCh`/`0D8DEh`) and the byte attribute array indexed at
   `bp-0x30E5` (`0CF1Bh`), plus the scalars `bp-0x30E8`/`0x30EA`/`0x30EC`.
   The positive BP displacements `0CF14h`/`0CF16h`/`0CF18h`/`0CF1Bh` are the
   16-bit-wrapped forms of `bp-0x30EC`/`0x30EA`/`0x30E8`/`0x30E5`.  `abFrame[]`
   with `F8`/`F16`/`AATTR`/`AX_ARR`/`AY_ARR` reproduces the exact byte layout;
   the index arithmetic applies the original 16-bit `shl di,2`.
   *Uncertain site:* as with `076B`, a large point count can overrun the frame;
   the port keeps the same expressions (no clamp added — literal recovery).
2. **`fn0C74_0A35` attribute copy.**  The byte stored at `[bp+0CF1Bh]`
   (`0ACBh`) and copied into `AATTR(n)` is `AATTR(0)` here (same offset), so the
   array store is written `AATTR(n) = AATTR(0);`.  The second `1E3C` in the
   free branch (`0B71h`) is only tested, never stored, and is kept that way.
3. **`fn0C74_0CFA`/`0D43`/`0D94`/`0DE5` index loops.**  The four blit loops are
   literal do/while shapes recovered from the labels: `bArg02` down to `1`
   (`0CFA`), `1` up to `bArg02` (`0D43`), `0x15` down to `bArg02` (`0D94`),
   `bArg02` up to `0x15` (`0DE5`).  The bound tests keep the original unsigned
   `jc`/`ja` sense (`0D94` continues iff `bArg02 <= 0x15`, etc.).
4. **`DGROUP:0x5904` far-pointer table.**  `les di,[di+5904h]` with
   `di = index*4` is recovered as
   `(u8 *)(uintptr_t)LG32((u16)(0x5904 + (index << 2)))`, the same convention as
   `seg1229_part2b.c`'s `0x5992` table.
5. **`fn0C74_0E2E` caller-frame argument seeded 0.**  The four `fn0C74_0FA1`
   call sites `push bp` before `call 0E2Eh`; `0E2E` reads `ss:[wArg02-4]` (the
   caller's `[bp-04h]` index).  Flat C has no `SS:BP` chain and the frozen
   `u16 wArg02` slot carries only the BP word, so cross-part callers seed it `0`
   (part 4 §5, `seg0800_part5.c` precedent); `0E2E` models the read as `0` and
   `(void)wArg02;`.  Recorded as an interface loss below.
6. **`0E2E` far blocks.**  The two `fn1EDA_023F` results are carried as `u32`
   (`offset | segment<<16`) and materialised with `(u8 *)(uintptr_t)dw`, the
   part 2 / `seg0800_part3.c` convention.  The original stores the words at
   `[bp-0Ah]/[bp-08h]` (blk6) and `[bp-0Eh]/[bp-0Ch]` (blk4); the same
   low-word-first layout is used.
7. **Leftover-stack words / register outputs.**  `fn1EDA_023F` and
   `fn1EDA_0254` take `wArg00`/`wArg02` stack words the original never pushes
   (far-return-address words, read only on the fatal-error path); seeded `0`.
   Saved-BP / DS outputs of `0CFA`/`0D43` receive `0` and those two functions
   return `0`; `0D94`/`0DE5`/`0E2E` return `NULL`; `dsOut` slots receive `0`.

### Uncertain sites / not recovered literally

* **`0E2E` `ss:[wArg02-4]` (item 5).**  Cannot pass the caller's `SS:BP`;
  seeded `0`, so the blit loop runs once and the two rectangles are drawn with
  a zero caller-frame offset.  The `or al,al ; jc` guard at `0F25h` cannot be
  taken (`or` clears CF), which Reko also renders as `if (true)`; the loop
  therefore always executes, and the recovered loop matches that.
* **`0A35` frame overrun** (item 1): the exact 16-bit wrap of `BP+DI+0D8DCh` /
  `BP+DI+0CF1Bh` outside the frame is not modelled; the in-frame layout is
  exact.
* **`0A35` return value.**  The original leaves AX/DX undefined (Reko models
  the last `0D80` DX); no caller of `0A35` consumes it, so `0` is returned.
* **`0D94`/`0DE5`/`0E2E` return values.**  Reko returns the saved-BP frame
  pointer; no caller consumes it, so `NULL` is returned.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part3.c` — 0 errors, 0 warnings
  (`-Wall -Wextra` likewise clean).
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(`
  over `src/seg0C74_part3.c` — 0 matches.
* All 6 in-range functions defined with the exact `src/seg0C74.h` prototype;
  `nm` shows `T fn0C74_0A35`, `T fn0C74_0CFA`, `T fn0C74_0D43`,
  `T fn0C74_0D94`, `T fn0C74_0DE5`, `T fn0C74_0E2E`.
* All four `src/seg0C74_part{1,2,3,4}.c` compile together with no duplicate
  `fn0C74_*` symbols.

## part 6

Function `0C74:1F08` (one of the two largest functions; sibling of `0FA1`):

```
1F08
```

Recovered into `src/seg0C74_part6.c`.  Ground truth =
`analysis/slices/0C74/0C74_1F08.asm` plus the Reko slice `0C74_1F08.c` and
`analysis/reko/RAD_0C74.{asm,c,dis}`.  Frozen prototype adopted exactly from
`src/seg0C74.h` (`analysis/summary/iface.tsv`) with no edits:

```
u8 fn0C74_1F08(u16 *bpOut, u16 *dsOut)
```

Every callee argument order was re-derived from the callee's own `.asm` (the
frozen parameter list is last-pushed first): `1AB8:13A3/13D7/10F4/1AF6/1C32/`
`1E3C/1E54/1E6B`, `1EDA:023F/0254/096F/098A`, `0C74:02D8/070D/05B8/0A35/1D95`.

### Hardware / dispatch sites

**None directly.**  No `int 10h` / `int 16h` / `int 21h`, no raw `in`/`out`
port instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch
(`fn1E5F_000B` is never called) occur in `1F08`.  Hardware is reached only
indirectly through already-ported callees:

* `fn1AB8_*` — the text/video driver (`seg1AB8*.c`), the bulk of the routine.
* `fn1EDA_023F/0254/096F/098A` — far-heap allocate/free and the 32-bit
  multiply/divide pair (`seg1EDA*.c`).
* `fn0C74_02D8` / `070D` / `05B8` — the tick/sound/frame drivers (parts 1/2).
* `fn0C74_1D95` — the caller-frame blit helper (its own chunk); it owns no
  port I/O itself but reads `ss:[wArg02-4]`.

### Segment data referenced

* `cs`-relative tables are not used here; the routine reads DGROUP geometry
  words `0x58B4` / `0x58B6` / `0x58B8` / `0x58BA` (window bounds), `0x58E6`
  (scale), `0x4D0C` (tick seed) and the state word `0x5968`.

### Flat-model / ABI adaptations

1. **Reko `bp_XXXX` frame pointers folded to the local frame.**  After every
   `fn0C74_070D` / `02D8` / `1D95` call the Reko `bp_1039` / `bp_1105` /
   `bp_1644` / `bp_1938` / `bp_2652` is re-bound to the callee's AX/pointer
   return and then read as `ss:[bp_XXXX - k]`.  Those reads are always the
   current function's own frame; the translation uses the literal locals
   directly, per the part 1 §3 convention.
2. **16:16 far blocks.**  The heap blocks returned by `fn1EDA_023F` are carried
   as `u32` (`offset | segment<<16`, low word at the lower address, matching the
   original `[bp-10h]/[bp-0Eh]`, `[bp-14h]/[bp-12h]`, `[bp-18h]/[bp-16h]`,
   `[bp-1Ch]/[bp-1Ah]`) and materialised with `(u8 *)(uintptr_t)dw` at the call
   sites, the same convention as `seg0800_part3.c` / `seg0C74_part4.c`.
3. **`fn1EDA_098A` `void * dsOut`.**  Receives a `void *` local (`dsv`), as its
   implementation stores a full pointer (point 1 §5).  The seven identical
   "time tick" sequences are emitted through a `TICK()` macro; the 098A
   cx/dx/bx/ds outputs are overwritten by each call and only its AX result is
   consumed (pushed to `fn0C74_02D8`), matching `seg0C74_part4.c`.
4. **Leftover-stack words seeded 0.**  `fn1EDA_023F` (`wArg00`/`wArg02`),
   `fn1EDA_098A` (`wArg00`/`wArg02`) and `fn1EDA_0254` (`wArg00`/`wArg02`) take
   stack words the original never pushes (far-return-address leftover slots,
   read only on the fatal divide-by-zero dispatcher path).  All are seeded `0`
   (part 1 §5 / part 4 §4 convention).
5. **`fn0C74_1D95` caller-frame argument seeded 0.**  The four call sites
   (`2250`, `23BA`, `2518`, `2A7B`) do `push bp` before `call 1D95h`; 1D95
   reads `ss:[wArg02-4]` (the caller's `[bp-04h]`, i.e. the index in `wLoc04`).
   Flat C has no `SS:BP` chain, so the frozen `u16 wArg02` slot receives `0`
   (part 4 §5, `seg0800_part5.c` precedent); recorded as an interface loss.
6. **`bpOut` / `dsOut` register outputs.**  Reko writes the caller's saved BP
   and the DGROUP selector; both receive `0` (part 1 §3).  The distinct
   `[bp-01h]` return byte is preserved and returned.
7. **`fn1EDA_096F` BX argument.**  The `.asm` sets BX = sign-extension of
   `LG16(0x58E6)` (`mov ax,[58E6h] ; cwd ; mov cx,ax ; mov bx,dx`) before the
   multiply; the call is `fn1EDA_096F(LG16(0x4D0C), LG16(0x58E6), 0, (u16)(s16)LG16(0x58E6))`
   (part 4 §uncertain item), which is identical to the 16-bit product unless
   `[58E6h]` is negative.
8. **`0x5968` `0FFh` immediate.**  `cmp word [5968h],0FFh` at `2276` is the
   sign-extended `0xFFFF` form (`RAD_0C74.dis`: `== 0xFFFF`), tested as
   `LG16(0x5968) == 0xFFFF` (cf. notes-0C74 part 4).

### Uncertain sites / not recovered literally

* **`fn0C74_1D95` `wArg02` (item 5).**  Cannot pass the caller's `SS:BP`; seeded
  `0`, so the `1D95` frame offset is read as zero.
* **Far-block pointers.**  `(u8*)(uintptr_t)dw` reproduces the original
  segment:offset value as an integer, not a host pointer (same documented
  convention as `seg0800_part3.c`).  `fn1AB8_1E6B`/`13D7` split it back into
  `(u16)`/`(u16)(p>>16)`, so the arithmetic is exact; the far-heap paths are not
  exercised by the build.
* **Dead `098A` `wArg00`/`wArg02`.**  Item 4; the divisor is always `4`.
* **Sibling divergence from `0FA1`.**  `1F08` is not a byte-for-byte twin: its
  edge-scan loops use `070D(0Fh,E6h)` (vs `19h`), its shrink sequence
  (`2680`..`2733`, `070D(14h,32h)`, subtract `[5968h]` down to `2Ch`) and its
  final `28EC`.. blocks (`070D(0Ch,E6h)`) have no `0FA1` counterpart, and its
  win checks use `[58B4h]+1` / `[58B6h]-1`.  All were translated from the
  `1F08` `.asm` directly; the `.asm` is authoritative.
* **`2AC8` trailing flag.**  `1F08` clears `[bp-01h]` after `05B8`/`0A35`
  (the `0FA1` twin leaves it set); this is kept literally, so the routine
  returns `0` on the successful `05B8` path.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part6.c` — 0 errors, 0 warnings
  (`-Wall -Wextra` likewise clean; `-Wunused-label` forced three purely
  fall-through Reko labels to be kept as offset comments).
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(`
  over `src/seg0C74_part6.c` — 0 matches.
* `fn0C74_1F08` defined with the exact `src/seg0C74.h` prototype (the TU
  includes the header, so gcc rejects any divergence); `nm` shows
  `T fn0C74_1F08` (and only that global).

## part 8

Function `0C74:2E5A` (1 function):

```
2E5A
```

Recovered into `src/seg0C74_part8.c`.  Ground truth =
`analysis/slices/0C74/0C74_2E5A.asm` plus `analysis/reko/RAD_0C74.{asm,dis}`;
the frozen prototype adopted exactly from `src/seg0C74.h`
(`analysis/summary/iface.tsv`) with no edits:

```c
u8 fn0C74_2E5A(u16 *bpOut, u16 *dsOut)
```

The five `fn1AB8_1E3C` edge probes at `2E6C..2EBB` gate the whole body; the
argument order was re-derived from each call's push sequence (last-pushed
first, `1AB8:1E3C(wArg04, wArg06, &dl)`), giving the literal
`([58BAh], [58B4h]-1)`, `([58B8h]+16h, [58B4h]-9)`, `([58BAh], [58B4h]-17h)`,
`([58B8h], [58B4h]-1)`, `([58B8h]+16h, [58B4h]-17h)` chain used in the C
`if (... && ...)`.

### Hardware / dispatch sites

**None.**  No `int 10h` / `int 16h` / `int 21h`, no raw `in`/`out` port
instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch occur in
2E5A.  Hardware-touching work is reached only through already-ported callees:
the 1AB8 video driver (`13A3`/`13D7`/`10F4`/`1AF6`/`1C32`/`1E3C`/`1E54`/`1E6B`),
the 1EDA far-heap helpers (`023F`/`0254`), `fn1E78_029C` (keyboard/pacing),
`fn11C8_033B`/`0354` (sound, guarded by DGROUP `0x58B0`), and the 0C74 helpers
`070D`/`02D8`/`2BBD`.

### Segment data referenced

* `DGROUP:0x58B0` byte — sound-enable flag (`0354` vs `033B` branch).
* `DGROUP:0x58B4` / `0x58B6` words — live bar Y / cached Y (decremented once
  per pull-in step; also `0x58B4` is the gate and rectangle origin).
* `DGROUP:0x58B8` word — bar X origin.
* `DGROUP:0x58BA` word — cached/left bar X.
* `DGROUP:0x58E6` word — loop-delay value (`idiv 2` then `1E78:029C`).
* `DGROUP:0x58F4` — table of 4-byte far pointers (sprite/row blocks), indexed
  by `[bp-02h]` (the 5..1 cycling animation counter).

### Flat-model / ABI adaptations

1. **Saved-BP / DS outputs.**  `fn0C74_070D` / `02D8` return Reko's saved-BP
   word and several callees have dropped DGROUP selectors; none exists in flat
   C.  `bpOut` / `dsOut` receive `0` and the artifact returns are ignored,
   per notes-0C74 part 1 §3.
2. **Far blocks (`fn1EDA_023F` / `0254`).**  The two scratch blocks are carried
   as `u32` (`offset | segment<<16`, low word at the lower address — the asm
   stores the 023F `AX`/`DX` pair to `[bp-0Eh]/[bp-0Ch]` and
   `[bp-1Eh]/[bp-1Ch]`) and materialised with `(u8 *)(uintptr_t)dw`, the
   convention of `seg0C74_part4.c` / part6.c / part2.c.  Block #1 is filled and
   freed; block #2 is filled, freed, reallocated one column left, filled
   again, and freed a second time.
3. **`023F` / `0254` leading stack words.**  The frozen prototypes carry
   `wArg00`/`wArg02` words the original never pushes (they are the far
   return-address words read only on the fatal divide-by-zero dispatcher path);
   they are seeded `0` (part4/part6).
4. **`0x58F4` far-pointer table.**  `les di,[di+58F4h]` with `di = [bp-02h]*4`
   is recovered as `(u8 *)(uintptr_t)LG32((u16)(0x58F4 + (u16)(bLoc02 * 4)))`,
   the same round-trip convention as `seg0C74_part2.c` (which fills the table
   from `023F` results).
5. **Frame-pointer locals.**  Reko's `bp_XXXX`, re-bound after each `070D` /
   `02D8` call, are the current function's own frame; folded back onto the
   literal `[bp-..]` locals (notes-0C74 part 1 §3).

### Uncertain sites / not recovered literally

* **`or al,al ; jc 31A5h` at `3162`.**  The asm computes `AX=[bp-8h]+16h` then
  `or al,al ; jc 31A5h`.  `or al,al` clears the carry flag, so the branch is
  never taken; `RAD_0C74.dis` folds it to a constant-false branch and the
  recovered C runs the block unconditionally (Reko's `if (true)`).  This is
  almost certainly a compiler artifact, but it is preserved as-is.
* **Far-block pointers.**  `(u8*)(uintptr_t)dw` reproduces the original
  segment:offset integer, not a host pointer (same documented convention as
  `seg0800_part3.c` / `seg0C74_part2.c`).  In the shipped port the far-heap
  node fetches resolve to zero, so these blocks are `NULL`; the arithmetic is
  still exact.  Not introduced here.
* **`0x58F4` table contents.**  Filled elsewhere (`seg0C74_part2.c` from the
  `023F` results), so the read here is a faithful u32 round-trip but its
  runtime pointer value depends on that sibling chunk.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part8.c` — 0 errors, 0 warnings.
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(`
  over `src/seg0C74_part8.c` — 0 matches.
* `fn0C74_2E5A` defined with the exact `src/seg0C74.h` prototype (the TU
  includes the header, so gcc rejects any divergence); `nm` shows
  `T fn0C74_2E5A`.

## part 7

Functions `0C74:2AD9 .. 0C74:2BBD` (2 functions, ascending offset):

```
2AD9 2BBD
```

Recovered into `src/seg0C74_part7.c`.  Ground truth =
`analysis/slices/0C74/0C74_<off>.asm` plus `analysis/reko/RAD_0C74.{asm,c,dis}`;
frozen prototypes adopted from `src/seg0C74.h` (`analysis/summary/iface.tsv`)
with no edits:

```c
u16 fn0C74_2AD9(u16 * dsOut);
u16 fn0C74_2BBD(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08);
```

### Hardware / dispatch sites

**None directly.**  No `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port
instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch occur in
2AD9..2BBD.  All hardware-touching work is reached indirectly through
already-ported callees:

* `fn1AB8_13A3` / `1E6B` / `13D7` / `1C32` / `1AF6` / `1E3C` / `1E54` — 1AB8
  video/text driver (`seg1AB8_*.c`).
* `fn1EDA_023F` / `0254` / `096F` / `098A` — 1EDA far-heap + 16x16/32-bit
  multiply + signed long-divide (`seg1EDA_*.c`).
* `fn1E78_029C` — keyboard/pacing helper (`seg1E78.c`), reached from 2BBD.
* `fn11C8_0354` / `033B` — sound (`seg11C8.c`), reached from 2BBD.
* `fn0C74_02D8` / `070D` / `0D43` / `0D94` / `0CFA` / `0DE5` / `1F08` / `076B`
  — 0C74 helpers owned by parts 1/2/3/6/8.

### Segment / DGROUP data referenced

* `[595Eh]` — the 13A3-returned size, reused as the 0254 free size (2AD9).
* `[58B8h]` / `[58B4h]` / `[58BAh]` — rectangle origin / right edge.
* `[58B3h]` — "stop" byte; when set, 2AD9 skips the final field advance + free.
* `[5968h]` — state word (1 = left field, else right field).
* `[58E6h]` — signed speed value (fed to 096F/098A in 2AD9, idiv-by-4 in 2BBD).
* `[4D0Ch]` — multiplier constant in the 2AD9 time-tick product.
* `[4D0Ah]` — 2BBD loop bound (byte), compared against `[bp-0Eh]`.
* `[58B0h]` — sound-enable byte (2BBD nested fade).

### Flat-model / ABI adaptations

1. **Reko `bp_121` / `bp_158` / `bp_325` frame pointers.**  `0D43`/`D94`/`070D`
   return the caller's saved BP in AX (the Turbo-C "return the pointer to my
   own frame" idiom); Reko dereferences it as `(ss->*bp_XXXX)` and writes
   `[bp-06h]`/`[bp-04h]`.  In flat C this is simply the current frame, so the
   returned value is ignored and the literal locals `wLoc06`/`wLoc04` are used
   (`bpOut` receives `0`, the part 1 §3 / part 4/6 convention).
2. **16:16 far blocks from `fn1EDA_023F`.**  Carried as `u32`
   (`(segment<<16)|offset`, low word at the lower address) and materialised
   with `(u8 *)(uintptr_t)dw`, the same convention as parts 2/4/6.
3. **`fn1EDA_098A` `dsOut`.**  Frozen `void *`; receives a `void *` local
   (`dsv`), so the fatal divide-by-zero path's 8-byte store stays in-bounds.
4. **Leftover stack words.**  `fn1EDA_023F` / `098A` / `0254` take stack words
   the original never pushes (far-return-address / leftover slots, read only on
   the fatal divide-by-zero dispatcher path); they are seeded `0`.
5. **`fn1EDA_0254` argument mapping.**  Per the ported callee
   (`seg1EDA_part2a.c`), the third frozen parameter (`wArg04`) is the size
   (`AX` = `[bp+6]`) and `ptrArg06` is the 16:16 block (`[bp+8]:[bp+10]`).
   Both 2AD9/2BBD call sites therefore pass
   `fn1EDA_0254(0, 0, size, block, ...)`, matching `seg0C74_part2.c`.
6. **Saved-BP / DS register "outputs".**  `bpOut` / `dsOut` are the caller's
   saved BP and the DGROUP selector; both receive `0`, and the `u16` returns of
   2AD9/2BBD are dead in every caller (`51B2`, `54B1`, `54F0`; `2E5A`, `3236`,
   `5258` all ignore AX after `call 2AD9h`/`2BBDh`), so `0` is returned.

### Correction to the sibling TICK() idiom (2AD9:2B79)

`0FA1` (`seg0C74_part4.c`) and `1F08` (`seg0C74_part6.c`) carry seven/eight
identical "time tick" sequences and pass the `fn1EDA_096F` 4th argument as
`(u16)(s16)LG16(0x58E6)`.  The `.asm` for that sequence is:

```
mov ax,[58E6h] ; cwd ; mov cx,ax ; mov bx,dx
mov ax,[4D0Ch] ; xor dx,dx ; call 096Fh
```

so the multiplier high word (`BX`, the frozen 4th parameter) is `DX` left by
`cwd`, i.e. `0x0000` for a non-negative `[58E6h]` and `0xFFFF` for a negative
one — *not* the value itself.  `096F` uses `BX`, and other call sites confirm
the meaning of the slot (e.g. `seg0800_part12.c` passes `0x0005` as the
multiplier high word of `0x07E40h`).  Part 7 therefore recovers it literally as

```c
(u16)((s16)LG16(0x58E6) < 0 ? 0xFFFFu : 0x0000u)
```

which yields `[4D0Ch] * [58E6h]` (signed 16x16->32) as intended.  The parts 4/6
expression is arithmetically different whenever `[58E6h] != 0`; that sibling
divergence is flagged here rather than silently copied (the parts 4/6 call
sites are outside this chunk's range and were left untouched).

### Uncertain sites / not recovered literally

* **Saved-BP returns of 2AD9/2BBD.**  Reko's return values are the saved-BP
  frame word / selector; flat C has no BP chain and no caller consumes them, so
  `0` is returned (item 6 above).
* **`fn1EDA_096F` sign word (item above).**  Recovered from the `.asm` `cwd` as
  a sign word; sibling parts 4/6 encode it differently.  This is a deliberate,
  documented correction, not a literal match of the sibling TUs.
* **2AD9 final-free size / Reko `wLoc1C_753`.**  Reko's slice feeds
  `wLoc1C_753` (a re-bound stack alias) to the trailing `fn1EDA_0254` and even
  overwrites it with `0x0161`.  The `.asm` is unambiguous: the free pushes
  `[bp+06h]` (`LG16(0x595E)`, the 13A3 size), `[bp-06h]` (offset) and
  `[bp-04h]` (segment).  The literal `.asm` mapping is used.
* **`fn1AB8_1E54` first argument width.**  Pushed as a 16-bit `AX`, truncated
  by the frozen `u8 bArg04`; the truncating `(u8)` casts reproduce the original
  `mov al,[bp-12h]` / `sub ax,8h` split exactly.
* **Unsigned`%3`/`idiv` in 2BBD.**  The `cwd` is redundant for the positive
  byte dividend (1..15h / 0..0Ah); it is kept as `(u16)bLoc10 % 0x0003` (DX=0
  makes the original unsigned `div` exact) and `idiv 4` as
  `(s16)LG16(0x58E6) / 4`.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part7.c` — 0 errors, 0 warnings
  (`-Wall -Wextra` likewise clean).
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(`
  over `src/seg0C74_part7.c` — 0 matches.
* Both in-range functions are defined with the exact `src/seg0C74.h`
  prototypes (the TU includes the header, so gcc rejects any divergence);
  `nm /tmp/opencode/seg0C74_part7.o` shows `T fn0C74_2AD9` and
  `T fn0C74_2BBD`.
* Compiling every existing `src/seg0C74_part*.c` (1,2,3,4,6,7,8) together
  produces no duplicate global definitions.

## part 5a

Function `0C74:1B3B` (the rocket/explosion trajectory animation; called only from
`fn0C74_51AA`):

```
1B3B
```

Recovered into `src/seg0C74_part5.c`.  Ground truth =
`analysis/slices/0C74/0C74_1B3B.asm` (268 lines) plus the Reko slice
`0C74_1B3B.c`; frozen prototype adopted exactly from `src/seg0C74.h`
(`analysis/summary/iface.tsv`) with no edits:

```c
u16 fn0C74_1B3B(void * dsOut);
```

Every callee argument order was re-derived from the callee's own `.asm`
(the frozen parameter list is last-pushed first): `1AB8:1E54/13A3/1E3C/1E6B/`
`13D7`, `1EDA:023F/0254/096F/098A`, `0C74:070D/02D8/0CFA/0D43/0D94/0DE5/0FA1`.

### Hardware / dispatch sites

**None directly.**  No `int 10h` / `int 16h` / `int 21h`, no raw `in`/`out`
port instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch
(`fn1E5F_000B` is never called) occur in `1B3B`.  Hardware is reached only
indirectly through already-ported callees: the `fn1AB8_*` text/video driver,
`fn0C74_02D8`/`070D` (parts 1/2) and `fn1EDA_023F/0254/096F/098A` (far heap
and the 32-bit multiply/divide pair).  `fn0C74_070D` in turn reaches the
11C8 sound helpers (PC-speaker/AdLib), all guarded by DGROUP `0x58B0`.

### Stack frame (asm `enter 6h,0h`)

* `[bp-01h]` — `u8` loop counter, initialised 0, bounded by `0x58` in loop A
  and by `0` (unsigned) in loops B/C (`bCount`).
* `[bp-06h]`/`[bp-04h]` — the `fn1EDA_023F` far heap block; `[bp-06h]` = AX =
  offset (low address), `[bp-04h]` = DX = segment.  Carried as
  `u32 dwBlock = offset | segment<<16` and materialised at the call sites with
  `(u8 *)(uintptr_t)dwBlock` (part 2 / part 4 convention).  `[bp-02h]`/`[bp-03h]`
  are unused padding.

### Section-by-section conversion

1. **Prologue (1B3B..1B98).**  Three `fn1AB8_1E54` put-pixel calls with colors
   `3,1,1` at `([58B8]+0x1C, [58B4]+0x17/0x18/0x19)`.  Push order is
   `[58B4]+k`, `[58B8]+0x1C`, `color` → args `(color, x, y)`.
2. **Block allocation (1B99..1BCE).**  `fn1AB8_13A3([58B8]+0x1C, [58B4]+0x2B,
   [58B8], [58B4])` is stored to `LG16(0x595E)` (**not** `0x596E` as the task
   brief suggested — the `.asm` has `[595Eh]` throughout, 22878).  That word is
   the `fn1EDA_023F` allocation size.  The returned `DX:AX` is stored to
   `[bp-04h]/[bp-06h]`, then `fn1AB8_1E6B(block, [58B8]+0x1C, [58B4]+0x2B,
   [58B8], [58B4])` fills it.
3. **Loop A (1BCF..1C1D, `bCount < 0x58`).**  Per iteration: two
   `fn1AB8_1E3C([58B8]-1, [58B4])` / `([58B8]-1, [58B6])` probes with
   `break` on nonzero; `fn0C74_070D(0x0A, 0xC8, &dsTmp)`; `[58B8] -= 1`;
   `fn1AB8_13D7(0, block, [58B8], [58B4])`; `++bCount`.
4. **Tick (1C1E..1C3D).**  `fn1EDA_096F([4D0C], [58E6], 0, sign([58E6]))`
   feeds `fn1EDA_098A(0x0004, <that>, 0, 0, ...)`; the low word is pushed to
   `fn0C74_02D8`.  BX is the sign extension of `[58E6]` (`cwd`/`mov bx,dx`),
   followed here as in part 4 (the Reko slice dropped it to 0).
5. **Loop B (1C3E..1C92, `bCount > 0`).**  Mirror of loop A with
   `fn1AB8_1E3C([58B8]+0x2C, [58B4]-1)` / `([58B8]+0x2C, [58B6]+1)`, `[58B8] += 1`,
   and `--bCount`.
6. **`bCount == 0` (1C93..1CAA).**  `fn1EDA_0254(0, 0, LG16(0x595E), block,
   &dxTmp, &dsTmp)` frees the block and jumps to the epilogue.
7. **`bCount != 0` (1CAB..1CF5).**  Branch on `LG16(0x5968) == 1`:
   * `==1`: `02D8(0xC8)`, `0D43(0x15)`, `02D8(0xC8)`, `0CFA(0x15)`,
     `02D8(0xC8)`, `0D43(0x0B)`.
   * `!=1`: `02D8(0xC8)`, `0CFA(0x15)`, `02D8(0xC8)`, `0D43(0x15)`,
     `02D8(0xC8)`, `0D94(0x0B)`.
8. **Frame hand-off (1CF6..1D47).**  `fn1AB8_1E6B(block, [58B8]+0x1C,
   [58B4]+0x2B, [58B8], [58B4])`, then `fn0C74_0FA1(&bpTmp, &dsTmp)`.  If it
   returns 0, loop C (1D1D..1D47, `bCount > 0`: `070D(0x0A,0xC8)`, `[58B8]+=1`,
   `13D7(0, block, [58B8], [58B4])`, `--bCount`).
9. **Free + final sweep (1D48..1D92).**  `fn1EDA_0254(..., LG16(0x595E),
   block, ...)`; if `LG8(0x58B3)==0`, tick (step 4 shape) then
   `fn0C74_0DE5(0x0B, &dsTmp)` when `LG16(0x5968)==1`, else
   `fn0C74_0CFA(0x0B, &bpTmp, &dsTmp)`.
10. **Epilogue (1D93).**  `leave; ret`.

### `.asm`-verified callee argument orders

| callee | frozen prototype | pushed (last = first arg) | C call |
|---|---|---|---|
| `fn1AB8_1E54` | `(u8 bArg04, u16 wArg06, u16 wArg08)` | `[58B4]+k`, `[58B8]+1Ch`, color | `(color, x, y)` |
| `fn1AB8_13A3` | `(wArg04, wArg06, wArg08, wArg0A)` | `[58B4]`, `[58B8]`, `[58B4]+2Bh`, `[58B8]+1Ch` | `([58B8]+1Ch, [58B4]+2Bh, [58B8], [58B4])` |
| `fn1AB8_1E3C` | `(u16 wArg04, u16 wArg06, u8 *dlOut)` | `[58B4]/[58B6]`, `[58B8]±k` | `(x, y, &dl)` |
| `fn1AB8_1E6B` | `(u8 *ptrArg04, wArg08, wArg0A, wArg0C, wArg0E)` | `[58B4]`, `[58B8]`, `[58B4]+2Bh`, `[58B8]+1Ch`, es, di | `(block, [58B8]+1Ch, [58B4]+2Bh, [58B8], [58B4])` |
| `fn1AB8_13D7` | `(u8 bArg04, u8 *ptrArg06, wArg0A, wArg0C)` | `[58B4]`, `[58B8]`, es, di, `0` | `(0, block, [58B8], [58B4])` |
| `fn1EDA_023F` | `(wArg00, wArg02, wArg04, u16 *dsOut)` | `[595E]` only (wArg00/02 dead) | `(0, 0, LG16(0x595E), &dsTmp)` |
| `fn1EDA_0254` | `(wArg00, wArg02, wArg04, u8 *ptrArg06, dxOut, dsOut)` | `[bp-04h]`, `[bp-06h]`, `[595E]` | `(0, 0, LG16(0x595E), block, &dxTmp, &dsTmp)` |
| `fn1EDA_096F` | `(u16 ax, u16 cx, u16 dx, u16 bx)` | registers | `([4D0C], [58E6], 0, (u16)(s16)[58E6])` |
| `fn1EDA_098A` | `(u32 bx_cx, u32 dx_ax, wArg00, wArg02, cxOut, dxOut, bxOut, void *dsOut)` | BX=0,CX=4 ; DX:AX=096F | `(0x0004, <096F>, 0, 0, &cxT, &dxT, &bxT, &dsv)` |
| `fn0C74_070D` | `(u16 wArg02, u16 wArg04, void *dsOut)` | `0x64` then `0x0A` | `(0x0A, 0x00C8, &dsTmp)` |
| `fn0C74_02D8` | `(u16 wArg02, u16 *dsOut)` | one word | `(value, &dsTmp)` |
| `fn0C74_0CFA`/`0D43` | `(u8 bArg02, void *bpOut, u16 *dsOut)` | one byte | `(0x15`/`0x0B, &bpTmp, &dsTmp)` |
| `fn0C74_0D94`/`0DE5` | `(u8 bArg02, u16 *dsOut)` | one byte | `(0x0B, &dsTmp)` |
| `fn0C74_0FA1` | `(void *bpOut, u16 *dsOut)` | none | `(&bpTmp, &dsTmp)` |

For the far-called 1AB8/1EDA entries the first argument is at `[bp+6]` (the far
return address occupies `[bp+2]/[bp+4]`), which is why the last-pushed word is
the first C parameter; the near-called 0C74 entries put it at `[bp+4]`.

### Flat-model / ABI adaptations

1. **Reko `bp_139`/`bp_240` frame pointers folded to the local frame.**  After
   every `fn0C74_070D` / `02D8` / `0FA1` call, Reko re-binds `bp_139`/`bp_240`
   to the callee's AX return (the caller's saved BP, preserved across each
   `push bp`/`leave`) and then reads `ss:[bp_XXXX-1]`.  Those reads are the
   current function's own `[bp-01h]` counter; the translation uses `bCount`
   directly (notes-0C74.md part 1 §3).
2. **16:16 far block.**  `fn1EDA_023F`'s `DX:AX` is carried as
   `u32 dwBlock = offset | segment<<16` (low word at the lower address,
   matching `[bp-06h]/[bp-04h]`) and materialised with `(u8 *)(uintptr_t)dwBlock`
   at the `1E6B`/`13D7`/`0254` call sites (seg0800_part3.c / part 2 / part 4
   convention).  The original stores the words directly at `[bp-06h]=AX`
   (offset) and `[bp-04h]=DX` (segment), so the integer round-trips exactly.
3. **`fn1EDA_098A` `void * dsOut`.**  Receives the `void *` local `dsv`
   (the callee stores a full pointer); `fn0C74_070D`'s `void * dsOut` receives
   the `u16` scratch `dsTmp`, matching `seg0C74_part2.c`.
4. **Leftover-stack words seeded 0.**  `fn1EDA_023F` (`wArg00`/`wArg02`),
   `fn1EDA_098A` (`wArg00`/`wArg02`) and `fn1EDA_0254` (`wArg00`/`wArg02`) take
   stack words the original never pushes (far-return-address / leftover slots,
   read only on the fatal divide-by-zero dispatcher path); all are seeded `0`
   (part 1 §5 / part 4 §4).
5. **`bpOut` / `dsOut` register outputs.**  `fn0C74_0FA1` / `0CFA` / `0D43`
   write the caller's saved BP and DGROUP selector; both receive `0`
   (part 1 §3).  The final `*dsOut = 0` writes the DGROUP selector as 0.
6. **Return value.**  The `.asm` epilogue is a bare `leave; ret`: Reko models
   the return as `(ss->*bp_240.u3).t0000.u2`, the saved-BP frame word left by
   the last `02D8`/`0FA1` call.  It is a frame artifact with no flat-C
   equivalent; `0` is returned.  The only caller, `fn0C74_51AA`, discards it.

### Uncertain sites / not recovered literally

* **`[595Eh]` vs the brief's `[596Eh]`.**  The `.asm` uses `[595Eh]` at
  1B3B, 1C99, 1D48 and 1D87; `LG16(0x595E)` (22878) is used throughout.
* **`fn1EDA_096F` BX argument.**  The `.asm` sets BX = sign extension of
  `[58E6]`; the Reko slice passed `0`.  The `.asm` is followed
  (`(u16)(s16)LG16(0x58E6)`), as in part 4.
* **`fn0C74_0FA1` `bpOut`.**  The flat `0FA1` writes 0 into `bpTmp`; the
  original re-bound the frame from it.  No later read in `1B3B` depends on the
  value (the counter is `bCount`).
* **Dead `098A` `wArg00`/`wArg02`.**  Item 4; the divisor is always `4`.
* **Far-block pointers.**  `(u8*)(uintptr_t)dwBlock` reproduces the original
  segment:offset value as an integer, not a host pointer (same documented
  convention as seg0800_part3.c); `fn1AB8_1E6B`/`13D7` split it back into
  `(u16)`/`(u16)(p>>16)`, so the arithmetic is exact.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part5.c` — 0 errors, 0 warnings.
* `gcc -c -Wall -Wextra -Isrc -Ipal src/seg0C74_part5.c` — likewise clean.
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|SLICE\(`
  over `src/seg0C74_part5.c` — 0 matches.
* `fn0C74_1B3B` defined with the exact `src/seg0C74.h` prototype (the TU
  includes the header, so gcc rejects any divergence); `nm` shows
  `T fn0C74_1B3B`.

## part 9

Functions `0C74:3236 .. 0C74:3615` (2 functions, ascending offset):

```
3236 3615
```

Recovered into `src/seg0C74_part9.c`.  Ground truth =
`analysis/slices/0C74/0C74_<off>.asm` plus the Reko slices `0C74_3236.c` /
`0C74_3615.c`; frozen prototypes adopted exactly from `src/seg0C74.h`
(`analysis/summary/iface.tsv`) with no edits:

```c
u8 fn0C74_3236(u16 *bpOut, u16 *dsOut);
u8 fn0C74_3615(u16 *dxOut, u16 *bpOut, u16 *dsOut);
```

Every callee argument order was re-derived from the callee's own `.asm` (the
frozen parameter list is last-pushed first): `1AB8:13A3/13D7/10F4/1AF6/1C32/`
`1E3C/1E54/1E6B`, `1EDA:023F/0254`, `1E78:029C/02FB`, `11C8:033B/0354`,
`1206:015B`, `0C74:070D/02D8/2BBD/0CFA`.

### Hardware / dispatch sites

**None directly.**  No `int 10h` / `int 16h` / `int 21h`, no raw `in`/`out`
port instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch
(`fn1E5F_000B` is never called) occur in 3236..3615.  Hardware is reached only
indirectly through already-ported callees:

* `fn1AB8_*` — the text/video driver (`seg1AB8*.c`).
* `fn1EDA_023F/0254` — the far-heap allocate/free helpers (`seg1EDA*.c`).
* `fn1E78_029C` / `fn1E78_02FB` — keyboard-pacing and input-poll helpers
  (`seg1E78.c`).
* `fn11C8_0354` / `fn11C8_033B` — sound helpers (`seg11C8.c`), guarded by
  DGROUP `0x58B0`.
* `fn1206_015B` — INT 33h mouse wrapper (`seg1206.c`), reached from `3615`'s
  `58B2h` input poll.  Its `push 0h` stack word has no slot in the frozen
  prototype and is seeded `0` inside the callee (notes-small-segs "1206").
* `fn0C74_070D` / `02D8` / `2BBD` / `0CFA` — 0C74 helpers owned by parts
  1/2/3/7.

### Segment / DGROUP data referenced

* `0x58B0` byte — sound-enable flag.
* `0x58B1` byte — "stop"/result flag set by the input polls.
* `0x58B2` byte — input-poll enable flag.
* `0x58B4` / `0x58B6` words — live bar X/Y (the `3615` gate tests `0x58B6`).
* `0x58B8` / `0x58BA` words — left/top rectangle origin.
* `0x58BC` / `0x58BD` bytes — latch counter / latch bound (`3615` restart).
* `0x58E0` byte — mouse-stop flag.
* `0x58E4` — table of 4-byte far pointers (sprite rows), indexed by the
  animation counter.
* `0x58E6` word — loop delay (`idiv 2` in 3236; `<<1` in 3615).
* `0x5968` word — state word (`0FFFFh` selects the `0CFA` half-bar path).

### Flat-model / ABI adaptations

1. **Reko `bp_XXXX` frame pointers folded to the local frame.**  After every
   `fn0C74_070D` / `02D8` call the Reko `bp_1030` / `bp_111` is re-bound to the
   callee's AX/pointer return and then read as `ss:[bp_XXXX - k]`.  Those reads
   are always the current function's own frame; the translation uses the literal
   locals directly, per notes-0C74 part 1 section 3.
2. **16:16 far blocks.**  The heap blocks returned by `fn1EDA_023F` are carried
   as `u32` (`offset | segment<<16`, low word at the lower address, matching the
   original `[bp-0Ch]/[bp-0Ah]` and `[bp-1Ch]/[bp-1Ah]`) and materialised with
   `(u8 *)(uintptr_t)dw` at the call sites, the same convention as parts
   2/3/4/6/7/8.
3. **`023F` / `0254` leading stack words.**  The frozen prototypes carry
   `wArg00`/`wArg02` words the original never pushes (far-return-address words
   read only on the fatal divide-by-zero dispatcher path); seeded `0`.
4. **`0x58E4` far-pointer table.**  `les di,[di+58E4h]` with
   `di = counter*4` is recovered as
   `(u8 *)(uintptr_t)LG32((u16)(0x58E4 + (counter << 2)))`, the same
   round-trip convention as parts 2/3/8.
5. **`bpOut` / `dsOut` register outputs.**  Reko writes the caller's saved BP
   and the dropped DGROUP selector; both receive `0` (part 1 section 3).
   `fn0C74_3615` also has a `dxOut`: Reko carries the DX register left by the
   `1E3C` / `13D7` / `11C8:033B` calls, but neither observed caller
   (`0C74:542B`, `0C74:54B1`) reads DX after `call 3615h`.  The flat port writes
   `0` and records the loss (same treatment as `fn0C74_0000`'s `dxOut`,
   part 1 section 6).
6. **`fn0C74_3236` `[bp-6h]+15h` guard.**  The asm computes `AX=[bp-6h]+15h`
   then `or al,al ; jc 3584h`.  `or` does **not** affect CF, so the branch tests
   the preceding `add`'s carry.  `[bp-6h]` is a byte-derived value (0..14h), so
   the sum never carries and the wipe block always runs (Reko's `if (true)`).
   Recovered as `ax_3541 = wLoc06 + 15h; if (!(ax_3541 < wLoc06)) { ... }`,
   preserving the guarded shape.
7. **`fn0C74_3236` `[bp-14h]` dead store.**  The asm increments `[bp-14h]` once
   per shrink step but never reads it.  Kept literally (plus a `(void)wLoc14;`
   to keep `-Wall` quiet); `wLoc12` is the value actually pushed.
8. **`1206_015B` stack word.**  The original pushes one `0h` before
   `call 1206h:015Bh`; the frozen prototype has no slot for it, so the callee
   seeds its internal `wArg06` with `0` (notes-small-segs "1206").
9. **`0x5968` `0FFh` immediate.**  `cmp word [5968h],0FFh` is the
   sign-extended `0xFFFF` form, tested as `LG16(0x5968) == 0xFFFF` (cf. parts
   4/6).

### Uncertain sites / not recovered literally

* **`fn0C74_3615` `dxOut` (item 5).**  Cannot reproduce the original DX chain
  (the high byte is the caller's incoming DH); written `0`.  Dead in every
  observed caller.
* **Far-block pointers.**  `(u8*)(uintptr_t)dw` reproduces the original
  segment:offset integer, not a host pointer (same documented convention as
  `seg0800_part3.c` / `seg0C74_part2.c`).  In the shipped port the far-heap
  node fetches resolve to zero, so these blocks are `NULL`; the arithmetic is
  still exact.
* **`0C74:377F`/`3780` (`EB 1F`).**  Two bytes between the `3770` shrink block
  and the `3781` blit block.  The preceding `jmp 37BEh` is unconditional and no
  branch targets them, so they are unreachable stray data; omitted, as the Reko
  slice also does.
* **`0x58E4` table contents.**  Filled elsewhere (`seg0C74_part2.c` from the
  `023F` results), so the read here is a faithful `u32` round-trip whose
  runtime pointer value depends on that sibling chunk.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part9.c` — 0 errors, 0 warnings
  (`-Wall -Wextra` likewise clean).
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(`
  over `src/seg0C74_part9.c` — 0 matches.
* Both in-range functions are defined with the exact `src/seg0C74.h`
  prototypes (the TU includes the header, so gcc rejects any divergence);
  `nm /tmp/opencode/seg0C74_part9.o` shows `T fn0C74_3236` and
  `T fn0C74_3615`, with every callee `U`.
* No other `src/seg0C74_*.c` defines `fn0C74_3236` / `fn0C74_3615`.

## part 10

Function `0C74:37C3` (one function):

```
37C3
```

Recovered into `src/seg0C74_part10.c`.  Ground truth =
`analysis/slices/0C74/0C74_37C3.asm` plus the Reko slice `0C74_37C3.c` and
`analysis/reko/RAD_0C74.{c,asm,dis}`.  Frozen prototype adopted exactly from
`src/seg0C74.h` (`analysis/summary/iface.tsv`):

```c
u8 fn0C74_37C3(u16 * dxOut, u16 * bpOut, u16 * dsOut);
```

`37C3` is the **mirror** of `fn0C74_3615` (part 9): the same four-edge-probe
game-core march, but it retracts the live bar instead of extending it.  It
returns early when `[58B4h] <= 1`, clears `[58B1h]`, and either runs the `0D43`
full redraw when `[5968h] == 1` or enters the march: tick `02D8` with
`[58E6h]*2`, decrement the animation counter 5..1 (reset to 4 at zero, `11C8`
sound), retract the live position while `[58B4h] > 1`, poll input / mouse
(`02FB`, `1206:015B`) or the `[58BCh]`/`[58BDh]` latch, then repeatedly probe
four edges; on success blit `DGROUP:0x58F4[counter]`; after `16h` rows either
bump `[58BCh]` and restart or stop; a failed probe advances the position one
step and stops.  Returns the `[bp-1h]` byte (0 = gate failed).

### Hardware / dispatch sites

**None directly.**  No `int 10h` / `int 16h` / `int 21h`, no raw `in`/`out`
port instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch
(`fn1E5F_000B` is never called here).  Every hardware-touching action is
reached through already-ported callees:

* `fn1AB8_1E3C` / `fn1AB8_13D7` — the text/video driver (`seg1AB8*.c`).
* `fn1E78_02FB` — keyboard input poll (`seg1E78.c`).
* `fn1206_015B` — the INT 33h mouse wrapper (`seg1206.c`).
* `fn11C8_033B` / `fn11C8_0354` — the sound helpers (`seg11C8.c`), guarded by
  DGROUP `0x58B0`.
* `fn0C74_0D43` — the `1AB8:13D7` + `070D` redraw helper (part 3).
* `fn0C74_02D8` — the delay/tick helper (part 1).

### Segment data referenced

* `0x58F4` qword table — five 4-byte sprite far pointers, filled by
  `fn0C74_076B` (part 2) from the `1EDA:023F` allocations.
* `0x58E6` word — loop delay (`shl ax,1h` before the `02D8` tick).
* `0x5968` word — state word (`1` selects the `0D43` redraw path).
* `0x58B0` byte — sound-enable gate.
* `0x58B1` byte — stop/abort flag; `0x58B2` byte — input-poll gate;
  `0x58B4`/`0x58B6` words — live X/Y position; `0x58B8`/`0x58BA` words —
  cached X/Y origin; `0x58BC`/`0x58BD` bytes — completion latch;
  `0x58E0` byte — mouse-click flag.

### Flat-model / ABI adaptations

1. **Reko `bp_111` frame pointer folded to the local frame.**  After the
   `fn0C74_02D8` call Reko re-binds `bp_111` to the callee's AX return (the
   caller's saved BP) and then reads `ss:[bp_111 - k]`; those reads are always
   the current function's own frame, so the translation uses the literal
   locals `[bp-1h]`/`[bp-2h]`/`[bp-3h]` directly, per notes-0C74 part 1
   section 3.
2. **`0x58F4` far-pointer table.**  `les di,[di+58F4h]` with
   `di = [bp-2h]*4` is recovered as
   `(u8 *)(uintptr_t)LG32((u16)(0x58F4 + ((u16)bLoc02 << 2)))`, the same
   round-trip convention as parts 2/3/8/9.
3. **`bpOut` / `dsOut` register outputs.**  Reko writes the caller's saved BP
   and the dropped DGROUP selector; both receive `0` (part 1 section 3).
4. **`dxOut` register output.**  Reko carries the DX register left by the
   `1E3C` / `13D7` / `11C8:033B` calls (and the `0D43` return); neither observed
   caller (`0C74:542B`, `0C74:54F0`) reads DX after `call 37C3h`.  The flat
   port writes `0` and records the loss (same treatment as `fn0C74_0000`'s and
   `fn0C74_3615`'s `dxOut`; part 1 section 6 / part 9).
5. **`1206_015B` stack word.**  The original pushes one `0h` before
   `call 1206h:015Bh`; the frozen prototype has no slot for it, so the callee
   seeds its internal `wArg06` with `0` (part 9 item 8).
6. **`0x5968 == 1` state word.**  The asm `cmp word [5968h],1h` is kept as
   `LG16(0x5968) == 0x0001` (contrast part 9's `0CFA` path, which uses the
   `0FFFFh` form).
7. **`02D8` argument.**  `mov ax,[58E6h] ; shl ax,1h` is recovered as
   `(u16)(LG16(0x58E6) << 1)` (the cast keeps the 16-bit wrap).
8. **Control flow.**  The exact label topology of the asm is preserved with
   `goto` (`3847`/`384D`/`3850`/`391B`/`392C`/`3954`/`3969`), including the
   inner row counter restarting at `3847` when the latch flag `[58B1h]` is
   clear.

### Uncertain sites / not recovered literally

* **`fn0C74_37C3` `dxOut` (item 4).**  Cannot reproduce the original DX chain
  (the high byte is the caller's incoming DH); written `0`.  Dead in every
  observed caller.
* **Far-pointer table contents.**  `(u8*)(uintptr_t)LG32(...)` reproduces the
  original segment:offset integer as an integer, not a host pointer (same
  documented convention as `seg0800_part3.c` / `seg0C74_part2.c`); the entry
  value is whatever part 2 stored.
* **`0C74:392A` (`EB 1F`).**  Two bytes between the `391B` advance block and
  the `392C` blit block.  The preceding `jmp 3969h` is unconditional and no
  branch targets them, so they are unreachable stray data; omitted, as the Reko
  slice also does.
* **`bLoc02` underflow.**  The animation counter is decremented without a
  guard (`dec byte [bp-2h]`); it never reaches zero-with-no-reset in practice
  because the zero case is mapped to `4h`, and the literal `--bLoc02`/`== 0`
  test reproduces the original 8-bit behaviour.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part10.c` — 0 errors, 0 warnings
  (`-Wall -Wextra` likewise clean).
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(`
  over `src/seg0C74_part10.c` — 0 matches.
* `fn0C74_37C3` is defined with the exact `src/seg0C74.h` prototype (the TU
  includes the header, so gcc rejects any divergence);
  `nm /tmp/opencode/seg0C74_part10.o` shows `T fn0C74_37C3`, with every callee
  `U` (`fn0C74_02D8`, `fn0C74_0D43`, `fn11C8_033B`, `fn11C8_0354`,
  `fn1206_015B`, `fn1AB8_13D7`, `fn1AB8_1E3C`, `fn1E78_02FB`, `g_dgroup`).
* No other `src/seg0C74_*.c` defines `fn0C74_37C3`.

## part 11

Function `0C74:396E` (one function):

```
396E
```

Recovered into `src/seg0C74_part11.c`.  Ground truth =
`analysis/slices/0C74/0C74_396E.asm` (641 lines) plus the Reko slice
`0C74_396E.c` and `analysis/reko/RAD_0C74.{c,asm,dis}`.  Frozen prototype
adopted exactly from `src/seg0C74.h` (`analysis/summary/iface.tsv`) with no
edits:

```c
u8 fn0C74_396E(void * bpOut, u16 * dsOut);
```

`396E` is the game-core "pull-in" update: it scans a row upward drawing a
13h/12h rectangle each step until the row reaches `39h`, a `1E3C` edge probe
fires, or the row passes `27Eh`.  If the row never reached `39h` it erases the
drawn column back down and clears the `[bp-1h]` flag (return 0).  If it did, it
runs the two-stage bar animation (grow, `02D8` wait, shrink, closing erase),
leaving `[bp-1h]` set (return 1).  Every path increments `[58B4h]`.

Every callee argument order was re-derived from the callee's own `.asm` (the
frozen parameter list is last-pushed first): `1AB8:10F4/1AF6/1C32/1E3C/1E54`,
`0C74:070D/02D8`.

### Hardware / dispatch sites

**None directly.**  No `int 10h` / `int 16h` / `int 21h`, no raw `in`/`out`
port instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch
(`fn1E5F_000B` is never called) occur in `396E`.  Hardware is reached only
indirectly through already-ported callees:

* `fn1AB8_10F4` / `1AF6` / `1C32` / `1E3C` / `1E54` — the text/video driver
  (`seg1AB8*.c`).
* `fn0C74_070D` / `02D8` — the 0C74 tick/frame drivers (parts 1/2); `070D`
  in turn reaches the `11C8` PC-speaker/AdLib helpers, all guarded by DGROUP
  `0x58B0`.

### Segment / DGROUP data referenced

* `0x58B4` word — live row/edge position (bumped once on every path).
* `0x58B8` word — left X origin of the pulled rectangle.
* `0x4D0F`, `0x4D23`, `0x4D37`, `0x4D4B` — four byte tables read at a common
  index (`di = bLoc03`, `bLoc03-1` or `bLoc03-2`).  The `.asm` reads
  `[di+4D4Bh]`/`[di+4D37h]`/`[di+4D23h]`/`[di+4D0Fh]`, i.e. four columns with a
  `0x14` stride (`X1` at `+0x14`/`X2` at `+0x3C`, `Y1` at `+0x00`/`Y2` at
  `+0x28`); recovered with the literal per-call `di` displacements.

### Flat-model / ABI adaptations

1. **Reko `bp_XXXX` frame pointers folded to the local frame.**  After every
   `fn0C74_070D` / `02D8` call, Reko re-binds `bp_1114` / `bp_210` / `bp_641`
   to the callee's AX return (the caller's saved BP) and then reads
   `ss:[bp_XXXX - k]`.  Those reads are always the current function's own
   frame; the translation uses the literal locals
   `[bp-01h]`/`[bp-02h]`/`[bp-03h]`/`[bp-06h]`/`[bp-08h]` directly, per
   notes-0C74 part 1 section 3.
2. **`di` table index.**  The `.asm` computes `di` as a 16-bit value
   (`(u16)bLoc03 - 2`, `(u16)bLoc03`, `(u16)bLoc03 - 1`) before each table
   read; the translation keeps an explicit `u16 di` local to mirror that.
3. **`bpOut` / `dsOut` register outputs.**  Reko writes the caller's saved BP
   and the dropped DGROUP selector; both receive `0` (part 1 section 3).  The
   distinct `[bp-01h]` byte is preserved and returned.
4. **`fn0C74_070D` `void * dsOut`.**  Receives the `void *` local `dsv`; the
   `fn0C74_02D8` `u16 * dsOut` receives `dsTmp`, matching part 2.

### Uncertain sites / not recovered literally

* **The two `(u8)(bLoc02-1) >= 1Dh` guards** (`39FB`, `3F1A`).  The `.asm` does
  `mov al,[bp-2h] ; xor ah,ah ; dec ax ; cmp al,1Dh ; jc <skip>`, i.e. it tests
  the low byte of `bLoc02-1`.  Reko instead tests `(u8)bLoc02 >= 1Eh`.  The two
  are equivalent for every reachable `bLoc02` (the loop only ever leaves
  `bLoc02` in `1Eh..38h`); the `.asm`-literal `(u8)(bLoc02 - 1) >= 0x1D` form is
  used.
* **`bpOut` / `dsOut` artifacts (item 3).**  Cannot reproduce the saved-BP word
  / DGROUP selector in flat C; written `0`, as in every sibling chunk.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part11.c` — 0 errors, 0 warnings
  (`-Wall -Wextra` likewise clean).
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(`
  over `src/seg0C74_part11.c` — 0 matches.
* `fn0C74_396E` is defined with the exact `src/seg0C74.h` prototype (the TU
  includes the header, so gcc rejects any divergence);
  `nm /tmp/opencode/seg0C74_part11.o` shows `T fn0C74_396E`.
* Compiling every existing `src/seg0C74_part*.c` in one pass produces no
  duplicate global definitions; `fn0C74_396E` is provided only by part 11.

## part 5b

Function `0C74:1D95` (the BP-frame blit helper called from `0C74:1F08`):

```
1D95
```

Recovered into `src/seg0C74_part5b.c`.  Ground truth =
`analysis/slices/0C74/0C74_1D95.asm` (152 lines) plus the Reko slice
`0C74_1D95.c` and `analysis/reko/RAD_0C74.{asm,c,dis}`; the frozen prototype is
adopted exactly from `src/seg0C74.h` (`analysis/summary/iface.tsv`) with no edits:

```c
u16 fn0C74_1D95(u16 wArg02, void * dsOut)
```

Every callee argument order was re-derived from the callee's own `.asm` (the
frozen parameter list is last-pushed first): `1AB8:13A3/13D7/1E6B`,
`1EDA:023F/0254`, `0C74:070D`.

### Hardware / dispatch sites

**None directly.**  No `int 10h` / `int 16h` / `int 21h`, no raw `in`/`out`
port instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch occur
in `1D95`.  Hardware is reached only indirectly through already-ported callees:
the `fn1AB8_*` text/video driver (`13A3`/`13D7`/`1E6B`), the `fn1EDA_023F`/`0254`
far-heap helpers, and `fn0C74_070D` (parts 2/3), which owns the PC-speaker /
AdLib pacing.

### What `1D95` does with the caller's BP-relative data

`1D95` is entered as `push bp ; call far 1D95h` from four sites in
`fn0C74_1F08` — `2250`, `23BA`, `2518`, `2A7B` (see the `.asm` "Called from"
header and `seg0C74_part6.c`).  Its own frame is `enter 0Eh,0h`, so the first
argument is at `[bp+4h]`; the function reads it into `di` and dereferences
`ss:[di-4h]`, i.e. the **caller's own `[bp-4]` local** (in `1F08` that is
`wLoc04`, the field-scan index).  The `.asm` uses that word for a single,
well-defined purpose, in two forms:

* **Full-word Y offset.**  Every `1AB8:13A3` rectangle origin is either
  `[58B4h] + const + ss:[di-4h]` (`const` = `19h` / `1Dh`) or
  `[58B4h] + const - ss:[di-4h]` (`const` = `0Dh` / `11h`).  The caller local
  therefore shifts the two field-edge rectangles vertically.
* **Low-byte loop count.**  `mov al,ss:[di-4h] ; or al,al ; jc 1EE8h` loads the
  low byte into `AL`, stores it at `[bp-1h]` (`1E8C`), and the tick/blit loop
  (`1E8C`..`1E94`) decrements it until zero.  `or al,al` clears CF, so the `jc`
  is never taken (Reko's `if (true)`): the loop always runs at least once.

No other use of `ss:[wArg02-4]` occurs; the only DGROUP reads are the geometry
words `0x58B4` / `0x58B8` (handled with `LG16`), and only the two `fn1EDA_023F`
results are stored as far blocks.

### Flat-model / ABI adaptations

1. **Caller-frame read modelled 0.**  Flat C has no `SS:BP` chain, and the
   frozen `u16 wArg02` carries only the pushed BP word (the four `1F08` call
   sites pass `0x0000`).  The read is therefore modelled as the documented
   constant `wCallerL4 = 0x0000`, with `(void)wArg02;` — the same treatment as
   `fn0C74_0E2E` (part 3 item 5) and the seeded-0 cross-part convention recorded
   in part 4 item 6 / part 6 item 5.
2. **16:16 far blocks.**  The two `fn1EDA_023F` results are carried as `u32`
   (`offset | segment<<16`, low word at the lower address — the asm stores
   `AX`/`DX` to `[bp-0Ah]/[bp-08h]` and `[bp-0Eh]/[bp-0Ch]`) and materialised
   with `(u8 *)(uintptr_t)dw` at the `1E6B`/`13D7`/`0254` call sites, the
   parts 3/4/6 convention.
3. **`023F` / `0254` leading stack words.**  The frozen prototypes carry
   `wArg00`/`wArg02` words the original never pushes (far-return-address /
   leftover slots, read only on the fatal divide-by-zero dispatcher path);
   seeded `0` (part 1 item 5 / parts 4/6).
4. **`070D` `dsOut`.**  `fn0C74_070D`'s frozen `void * dsOut` receives the same
   `u16 dsTmp` scratch slot used for `023F`/`0254` (its implementation writes a
   2-byte zero), matching `seg0C74_part3.c`'s `0E2E`.
5. **`dsOut` / saved-BP artifact.**  Reko writes the DGROUP selector to `dsOut`
   and models the return as the saved-BP frame word.  Flat C has neither, so
   `*(void **)dsOut = NULL` and the function returns `0` (parts 1/3/4/6).  All
   four callers discard the return.

### `.asm`-verified callee argument mapping

* `fn1AB8_13A3([58B8h]+1Bh, [58B4h]+1Dh+N, [58B8h]+0Dh, [58B4h]+19h+N)`
  → `wLoc04` (`[bp-04h]`)
* `fn1AB8_13A3([58B8h]+1Bh, [58B4h]+11h-N, [58B8h]+0Dh, [58B4h]+0Dh-N)`
  → `wLoc06` (`[bp-06h]`)
* `dwLoc0A = fn1EDA_023F(0, 0, wLoc06, &dsTmp)`;
  `dwLoc0E = fn1EDA_023F(0, 0, wLoc04, &dsTmp)`
* `fn1AB8_1E6B(blockB=dwLoc0E, [58B8h]+1Bh, [58B4h]+1Dh+N, [58B8h]+0Dh,
  [58B4h]+19h+N)`
* `fn1AB8_1E6B(blockA=dwLoc0A, [58B8h]+1Bh, [58B4h]+11h-N, [58B8h]+0Dh,
  [58B4h]+0Dh-N)`
* loop: `fn0C74_070D(0Ah, 0E6h, &dsTmp)`;
  `fn1AB8_13D7(0, blockB, [58B8h]+0Dh, [58B4h]+19h+c)`;
  `fn1AB8_13D7(0, blockA, [58B8h]+0Dh, [58B4h]+0Dh-c)`
* frees: `fn1EDA_0254(0, 0, wLoc06, blockA, &dxTmp, &dsTmp)`;
  `fn1EDA_0254(0, 0, wLoc04, blockB, &dxTmp, &dsTmp)`

### Uncertain sites / not recovered literally

* **`ss:[wArg02-4]` (item 1).**  Cannot pass the caller's `SS:BP`; modelled `0`,
  so both rectangles get a zero Y offset and the blit loop runs once
  (counter `0`).  Mirrors `fn0C74_0E2E`.
* **`or al,al ; jc 1EE8h` guard.**  `or` clears CF so the branch is never taken;
  preserved as an unconditional loop entry (Reko `if (true)`), and the loop
  always runs at least once.
* **Return value.**  The asm leaves `AX` as the trailing `fn1EDA_0254` result
  (an artifact); Reko models the saved-BP word.  No caller consumes it, so `0`
  is returned.
* **Far-block pointers.**  `(u8 *)(uintptr_t)dw` reproduces the original
  segment:offset integer, not a host pointer (same documented convention as
  `seg0800_part3.c` / `seg0C74_part2.c`).  `fn1AB8_1E6B`/`13D7` split it back
  into `(u16)`/`(u16)(p>>16)`, so the arithmetic is exact; the far-heap paths
  are not exercised by the build.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part5b.c` — 0 errors, 0 warnings
  (`-Wall -Wextra` likewise clean).
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(`
  over `src/seg0C74_part5b.c` — 0 matches.
* `fn0C74_1D95` is defined with the exact `src/seg0C74.h` prototype (the TU
  includes the header, so gcc rejects any divergence);
  `nm /tmp/opencode/seg0C74_part5b.o` shows `T fn0C74_1D95`.
* No other `src/seg0C74_*.c` defines `fn0C74_1D95`.

## part 12

Function `0C74:3F74` (called only from `fn0C74_5258`):

```
3F74
```

Recovered into `src/seg0C74_part12.c`.  Ground truth =
`analysis/slices/0C74/0C74_3F74.asm` plus the Reko slice `0C74_3F74.c` and
`analysis/reko/RAD_0C74.{asm,dis}`; the frozen prototype is adopted exactly
from `src/seg0C74.h` (`analysis/summary/iface.tsv`) with no edits:

```c
u8 fn0C74_3F74(void * bpOut, u16 * dsOut)
```

Every callee argument order was re-derived from the callee's own `.asm` (the
frozen parameter list is last-pushed first): `1AB8:10F4/1C32/1AF6/1E3C/1E54`,
`0C74:070D/02D8`.

### Hardware / dispatch sites

**None directly.**  No `int 10h` / `int 16h` / `int 21h`, no raw `in`/`out`
port instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch
(`fn1E5F_000B` is never called) occur in 3F74.  Hardware is reached only
indirectly through already-ported callees: the `fn1AB8_*` text/video driver
(`10F4`/`1C32`/`1AF6`/`1E3C`/`1E54`) and the 0C74 helpers `fn0C74_070D` /
`fn0C74_02D8` (parts 1/2), whose `070D -> 02D8/11C8` chain owns the
PC-speaker / AdLib port I/O (guarded by DGROUP `0x58B0`).

### Segment / DGROUP data referenced

* `0x58B4` word — live bar X (incremented on entry, decremented on every exit
  path); `0x58B8` word — playfield origin Y (the patch x base).
* `0x4D5E` word table and `0x4D87` / `0x4D9B` / `0x4DAF` byte tables — the
  three-segment patch geometry, indexed by the loop counter (the word table is
  indexed doubled, `shl di,1`).  All are `_DATA` offsets (`LG16`/`LG8`).

### Flat-model / ABI adaptations

1. **Reko `bp_XXXX` frame pointers folded to the local frame.**  After every
   `fn0C74_070D` / `02D8` call Reko re-binds `bp_1159` / `bp_245` / `bp_681` to
   the callee's AX/far return and then reads `ss:[bp_XXXX - k]`.  Those reads
   are always the current function's own frame; the translation uses the literal
   locals `wLoc04`/`wLoc06`/`wLoc08`/`wLoc0A` directly (part 1 section 3).
2. **Table patch macro `PATCH3(idx)`.**  Each of the six three-segment patches
   is `fn1AB8_1AF6([58B8h]+tAF[idx], [58B4h]-t9B[idx], [58B8h]+t87[idx],
   [58B4h]-t16[idx*2], &dxTmp)`.  The macro evaluates the index expression for
   every table read, exactly as the original reloads DI from `[bp-06h]` before
   each access.  The `0x4D87`/`0x4D9B`/`0x4DAF` reads in the "minus two" and
   "minus one" passes of the asm are kept with the asm's own index form, which
   is byte-identical to Reko's folded bases (`0x4D85`/`0x4D99`/`0x4DAD` with a
   raw `[bp-06h]`).
3. **`bpOut` / `dsOut` register outputs.**  Reko writes the caller's saved BP
   and the dropped DGROUP selector; both receive `0` (`*(u16 *)bpOut = 0`,
   `*dsOut = 0`, part 1 section 3).  The distinct `[bp-01h]` return byte is
   preserved and returned.

### Uncertain sites / not recovered literally

* **`0FFF3h` immediate.**  The disassembly prints `cmp word ptr [bp-4h],0F3h`,
  but `RAD_0C74.dis` normalises the branch operand to `0xFFF3` (`== 0xFFF3`),
  i.e. the encoding is the sign-extended imm8 `-13`.  That is the only reading
  consistent with the `dec` walking `0Dh -> 00h -> FFF3h` (26 steps rather than
  65306); the port compares against `0xFFF3u`, as Reko does (`~0x0C`).
* **First-loop continue test.**  The asm computes the 32-bit sign-extended
  `[58B4h] + [bp-04h]` and tests `dx < 0` / `dx > 0` / `(dx==0) ax > 1`; Reko
  folded this to a bare `ax > 1`.  The literal three-case test is kept
  (`u32 v`, `s16 vhi`), so the negative/high-word exits are preserved.
* **`bpOut` / `dsOut` artifacts.**  No flat-C equivalent; `0` written.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part12.c` — 0 errors, 0 warnings
  (`-Wall -Wextra` likewise clean).
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(`
  over `src/seg0C74_part12.c` — 0 matches.
* `fn0C74_3F74` is defined with the exact `src/seg0C74.h` prototype (the TU
  includes the header, so gcc rejects any divergence);
  `nm /tmp/opencode/seg0C74_part12.o` shows `T fn0C74_3F74`, with every callee
  (`fn0C74_02D8`, `fn0C74_070D`, `fn1AB8_10F4/1AF6/1C32/1E3C/1E54`) `U`.
* No other `src/seg0C74_*.c` defines `fn0C74_3F74`.

## part 13

Function `0C74:45CE` only (1 function):

```
45CE
```

Recovered into `src/seg0C74_part13.c`.  Ground truth =
`analysis/slices/0C74/0C74_45CE.asm` plus `analysis/reko/RAD_0C74.{asm,c,dis}`
(the raw instruction offsets in the source comments were re-derived with
`ndisasm -b16` from `_original/rad/RAD.EXE` at raw file offset
`0x1F90 + 0x4740 + 0x45CE`).  Frozen prototype adopted from `src/seg0C74.h`
(`analysis/summary/iface.tsv`) with no edits:

```c
u8 fn0C74_45CE(void *bpOut, u16 *dsOut)
```

### Hardware / dispatch sites

**None.**  No `int 10h` / `int 16h` / `int 21h`, no raw `in`/`out` port
instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch occur in
45CE.  Every hardware-touching action is reached indirectly through
already-ported callees:

* `fn1AB8_10F4` / `1C32` / `1AF6` / `1E3C` / `13D7` — 1AB8 video/text driver
  (`seg1AB8*.c`).
* `fn0C74_070D` / `02D8` / `076B` — 0C74 tick/frame/starfield drivers
  (`seg0C74_part1.c` / `part2.c`), themselves leading to `1E78` keyboard/pacing.
* `fn11C8_0354` / `033B` — sound helpers (`seg11C8*.c`).

### Segment data referenced

* Geometry/state words `0x58B0` (byte sound gate), `0x58B3` (byte latch),
  `0x58B4` / `0x58B6` / `0x58B8` / `0x58BA` (words).
* Rectangle cache `0x596C` / `0x596E` / `0x5970` / `0x5972` (words).
* Sprite far-pointer table at `0x58E4` (4 bytes/entry, read as a single
  `LG32` — the table's second word is reused as the `0x58E6` scale factor by
  `070D`).

### `.asm`-verified callee argument mapping

* `1AF6([58B8h]+13h, bLoc02/bLoc03+[58B4h], [58B8h]+12h, bLoc02/bLoc03+[58B4h], &dxTmp)`
* `1E3C([58B8h]+13h, bLoc02+[58B4h], &dlTmp)`
* `070D(14h, 12Ch, &dsv)`, `02D8(0F4h/0Ah/1Eh, &dsTmp)`
* `13D7(0, (u8*)(uintptr_t)LG32(0x58E4 + bLoc02*4), [58B8h], [58B4h])`
* `076B([5972h], [5970h], [58B8h], [58B4h])` (4965) /
  `076B([5972h], [5970h], [596Eh], [596Ch])` (4980)

### Flat-model / ABI adaptations

1. **Reko frame-pointer locals folded onto literals.**  Reko re-binds
   `bp_39` / `bp_137` to the value returned by `fn0C74_070D` / `fn0C74_02D8`
   (the caller's saved BP word) and then addresses `[bp-Nh]` through them.  In
   the original BP never changes here, so the accesses are folded back onto the
   fixed locals `bLoc01..bLoc04`, `wLoc06`, `wLoc08` (same convention as parts
   1/9/11).
2. **Sprite table far pointer.**  `les di,[di+58E4h]` is read as one `u32`
   (`offset | segment<<16`) and cast to a host pointer with
   `(u8 *)(uintptr_t)`, matching parts 2/8/9; the `es` push is dropped because
   the pointer is flat.
3. **Register outputs.**  `bpOut` is Reko's saved-BP artifact and `dsOut` the
   dropped DGROUP selector; both receive `0` (part 1 section 3).  The `1AF6`
   `dxOut` and `1E3C` `dlOut` values are dead in the original and are written
   to scratch locals.
4. **`(u8)(bLoc02 - 1) >= 1Dh`.**  The asm `dec ax ; cmp al,1Dh ; jc` is
   recovered literally (not folded to Reko's `>= 1Eh`), matching part 11.

### Uncertain sites / not recovered literally

* **Saved-BP / DS outputs.**  No flat-C BP chain exists; the trailing
  `bpOut` / `dsOut` stores are both `0` (documented loss).
* **`1AF6` / `1E3C` register outputs.**  Dead in every call site; scratch
  locals are passed.
* **Signed 32-bit edge compare (494Bh).**  The asm builds `DX:BX = 0:0`,
  `CX = [58BAh]+17h`, sign-extends `[5972h]` with `cwd`, compares the high
  words `cmp dx,bx` and then `cmp ax,cx` unsigned.  Recovered as
  `(s32)(s16)LG16(0x5972) <= (s32)cx`, which is exact for all 16-bit inputs.
* **Uninitialised `wLoc06` / `wLoc08` on the early-return path.**  The
  `bLoc02 != 3Ah` branch returns before touching them; they are initialised
  `0` in flat C.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part13.c` — 0 errors, 0 warnings
  (`-Wall -Wextra` likewise clean).
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(`
  over `src/seg0C74_part13.c` — 0 matches.
* `fn0C74_45CE` is defined with the exact `src/seg0C74.h` prototype (the TU
  includes the header, so gcc rejects any divergence);
  `nm /tmp/opencode/seg0C74_part13.o` shows `T fn0C74_45CE`.
* No other `src/seg0C74_*.c` defines `fn0C74_45CE`.

## part 15

Functions `0C74:4DAC .. 0C74:51B2` (4 functions, ascending offset):

```
4DAC 4FD7 51AA 51B2
```

Recovered into `src/seg0C74_part15.c`.  Ground truth =
`analysis/slices/0C74/0C74_<off>.asm` plus the Reko slices `0C74_4DAC.c` /
`0C74_4FD7.c` / `0C74_51AA.c` / `0C74_51B2.c`; frozen prototypes adopted
exactly from `src/seg0C74.h` (`analysis/summary/iface.tsv`) with no edits:

```c
u8  fn0C74_4DAC(u16 *bpOut, u16 *dsOut);
u8  fn0C74_4FD7(u16 *bpOut, u16 *dsOut);
u16 fn0C74_51AA(void);
u16 fn0C74_51B2(void);
```

Every callee argument order was re-derived from the callee's own `.asm` (the
frozen parameter list is last-pushed first): `1AB8:13A3/13D7/1AF6/1C32/1E3C/`
`1E54/1E6B`, `1EDA:023F/0254`, `0C74:070D/02D8/1B3B/2AD9`.

### Hardware / dispatch sites

**None directly.**  No `int 10h` / `int 16h` / `int 21h`, no raw `in`/`out`
port instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch
(`fn1E5F_000B` is never called) occur in `4DAC..51B2`.  Hardware is reached
only indirectly through already-ported callees:

* `fn1AB8_13A3` / `13D7` / `1AF6` / `1C32` / `1E3C` / `1E54` / `1E6B` — the
  text/video driver (`seg1AB8*.c`).
* `fn1EDA_023F` / `0254` — the far-heap allocate/free helpers (`seg1EDA*.c`).
* `fn0C74_070D` / `02D8` — the 0C74 tick/frame drivers (parts 1/2); `070D`
  in turn reaches the `11C8` PC-speaker/AdLib helpers, guarded by DGROUP
  `0x58B0`.
* `fn0C74_1B3B` (part 5a) — the rocket/explosion trajectory animation, called
  only by `4DAC`'s far wrapper `51AA`.
* `fn0C74_2AD9` (part 7) — the field advance/animation helper, called by `51B2`.

### Segment / DGROUP data referenced

* `0x58B4` / `0x58B6` words — live X/Y position; `0x58B8` / `0x58BA` words —
  cached X/Y origin (the `4DAC`/`4FD7` columns are drawn at
  `[58B8h]+12h/13h/14h`, `[58B4h]+counter`, and the scratch rectangles span
  `[58B8h]+11h..+14h` x `[58B4h]-16h..-1` (4DAC) / `[58B4h]+2Ch..+41h` (4FD7)).
* `0x5968` word — direction/state word: `1` selects the left-bar probes in
  `51B2`; `0FFFFh` selects the right-bar probes; any other value sets the
  `[bp-1]` flag without probing.
* `0x4D0Ch`/`0x58E6` — not touched directly here (reached inside `1B3B`/`2AD9`).

### Flat-model / ABI adaptations

1. **Reko `bp_XXXX` frame pointers folded to the local frame.**  After every
   `fn0C74_070D` / `02D8` / `13A3` / `023F` call Reko re-binds `bp_104` /
   `bp_129` / `bp_240` etc. to the callee's AX/far return and then reads
   `ss:[bp_XXXX - k]`.  Those reads are always the current function's own
   frame; the translation uses the literal locals
   (`[bp-01h]`/`[bp-04h]`/`[bp-06h]`/`[bp-08h]`) directly, per notes-0C74
   part 1 section 3.
2. **16:16 far blocks (`fn1EDA_023F`).**  The `DX:AX` results are carried as
   `u32` (`offset | segment<<16`, low word at the lower address — the asm of
   `4DAC` stores `AX`/`DX` to `[bp-0Ch]`/`[bp-0Ah]`, `4FD7` to
   `[bp-0Ah]`/`[bp-08h]`) and materialised with `(u8 *)(uintptr_t)blk` at the
   `1E6B`/`13D7`/`0254` call sites, the part 2/3/4/6/7/8/9 convention.
3. **`023F` / `0254` leading stack words.**  The frozen prototypes carry
   `wArg00`/`wArg02` words the original never pushes (far-return-address words
   read only on the fatal divide-by-zero dispatcher path); they are seeded `0`
   (parts 4/6/7/8/9).
4. **`fn1EDA_0254` argument mapping.**  Per the ported callee, the third frozen
   parameter (`wArg04`) is the `13A3` block size and `ptrArg06` is the 16:16
   block.  Both call sites therefore pass
   `fn1EDA_0254(0, 0, size, (u8 *)(uintptr_t)blk, &dxTmp, &dsTmp)`, matching
   parts 2/7.
5. **`bpOut` / `dsOut` register outputs.**  `4DAC`/`4FD7` write the caller's
   saved BP and the dropped DGROUP selector; both receive `0`, and the distinct
   `[bp-01h]` byte is preserved and returned (part 1 section 3).
6. **`51AA` / `51B2` DS handling.**  `fn0C74_51AA` is a bare far wrapper:
   `return fn0C74_1B3B(&dsTmp);` forwards `1B3B`'s AX return to the caller and
   gives the dropped DS output a local scratch.  `fn0C74_51B2` has no DS use at
   all; its `[5968h]` state word is read with `LG16` and the `2AD9` DS output is
   a local scratch.

### Uncertain sites / not recovered literally

* **`0E9h` immediate is sign-extended.**  `4DAC`'s `cmp word ptr [bp-4h],0E9h`
  (`4E2?`) and `cmp word ptr [bp-4h],0E9h` (`4E6F`) are the `83 /7 ib` form, so
  the imm8 `0E9h` sign-extends to `0FFE9h` (= `~0x16`, exactly what the Reko
  slice writes).  The counter starts at `0Dh` and walks
  `0Dh -> 00h -> 0FFE9h` (36 steps), not 65306.  The port compares against
  `0xFFE9` at both sites (same class of correction as part 12's `3F74`
  `0FFF3h`).  The `.asm` mnemonic text alone (`0E9h`) is misleading.
* **`4DAC` first-loop continue test.**  The asm computes the 32-bit
  sign-extended `[bp-4h] + [58B4h]` and tests `dx < 0` / `dx > 0` /
  `(dx==0) ax > 1`; Reko folded this to a bare `ax > 1`.  The literal
  three-case test is kept (`s32 sum = (s32)(s16)wLoc04 + (s32)(u16)LG16(0x58B4)`),
  so the negative/high-word exits are preserved.
* **`4FD7` 8-bit counters.**  `[bp-2h]` (`bLoc02`) and `[bp-3h]` (`bLoc03`) are
  bytes in the original; every increment/decrement is masked with a `(u8)` cast
  so the 8-bit wrap is exact (the `.asm` uses `inc`/`dec byte ptr`).
* **`4FD7` erase guard.**  The `.asm` does `mov al,[bp-2h] ; xor ah,ah ; dec ax
  ; cmp al,1Dh ; jc 50BBh`, i.e. it tests the low byte of `bLoc02-1`; recovered
  as `(u8)(bLoc02 - 0x01) >= 0x1D` (compare against the part 11 `396E` form).
* **Far-block pointers.**  `(u8 *)(uintptr_t)blk` reproduces the original
  segment:offset integer, not a host pointer (same documented convention as
  `seg0800_part3.c` / `seg0C74_part2.c`).  `fn1AB8_1E6B`/`13D7` split it back
  into `(u16)`/`(u16)(p>>16)`, so the arithmetic is exact; the far-heap paths
  are not exercised by the build.  In the shipped port the far-heap node fetches
  resolve to zero, so these blocks are `NULL` (established project behaviour).
* **`51AA` return value.**  `1B3B`'s flat implementation returns `0`; the far
  wrapper forwards it.  Every caller of `51AA` discards AX.

### `.asm`-verified callee argument order

| callee | frozen prototype | pushed (last = first arg) | C call |
|---|---|---|---|
| `fn1AB8_1E54` | `(bArg04, wArg06, wArg08)` | `y`, `x`, `color` | `(color, x, y)` |
| `fn1AB8_1E3C` | `(wArg04, wArg06, dlOut)` | `y`, `x` | `(x, y, &dlTmp)` |
| `fn1AB8_1AF6` | `(wArg04, wArg06, wArg08, wArg0A, dxOut)` | `y`, `x1`, `y`, `x2` | `(x2, y, x1, y, &dxTmp)` |
| `fn1AB8_13A3` | `(wArg04, wArg06, wArg08, wArg0A)` | `y0`, `x0`, `y1`, `x1` | `(x1, y1, x0, y0)` |
| `fn1AB8_13D7` | `(bArg04, ptrArg06, wArg0A, wArg0C)` | `y`, `x`, es, di, `0` | `(0, block, x, y)` |
| `fn1AB8_1E6B` | `(ptrArg04, wArg08, wArg0A, wArg0C, wArg0E)` | `y0`, `x0`, `y1`, `x1`, es, di | `(block, x1, y1, x0, y0)` |
| `fn1EDA_023F` | `(wArg00, wArg02, wArg04, dsOut)` | `size` only | `(0, 0, size, &dsTmp)` |
| `fn1EDA_0254` | `(wArg00, wArg02, wArg04, ptrArg06, dxOut, dsOut)` | `hi`, `lo`, `size` | `(0, 0, size, block, &dxTmp, &dsTmp)` |
| `fn0C74_070D` | `(wArg02, wArg04, dsOut)` | `0x12C`, `0x14` | `(0x14, 0x12C, &dsv)` |
| `fn0C74_02D8` | `(wArg02, dsOut)` | one word | `(value, &dsTmp)` |
| `fn0C74_2AD9` | `(dsOut)` | none | `(&dsTmp)` |
| `fn0C74_1B3B` | `(dsOut)` | none | `(&dsTmp)` |

For the far-called `1AB8`/`1EDA` entries the first argument is at `[bp+6]` (the
far return address occupies `[bp+2]/[bp+4]`), which is why the last-pushed word
is the first C parameter; the near-called `0C74` entries put it at `[bp+4]`.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part15.c` — 0 errors, 0 warnings
  (`-Wall -Wextra` likewise clean).
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(|SLICE\(`
  over `src/seg0C74_part15.c` — 0 matches.
* All four in-range functions are defined with the exact `src/seg0C74.h`
  prototype (the TU includes the header, so gcc rejects any divergence);
  `nm /tmp/opencode/seg0C74_part15.o` shows `T fn0C74_4DAC`,
  `T fn0C74_4FD7`, `T fn0C74_51AA`, `T fn0C74_51B2`, with every callee `U`.
* No other `src/seg0C74_*.c` defines `fn0C74_4DAC` / `4FD7` / `51AA` / `51B2`.

## part 16

Functions `0C74:522C .. 0C74:552F` (6 functions, ascending offset):

```
522C 5258 542B 54B1 54F0 552F
```

Recovered into `src/seg0C74_part16.c`.  Ground truth =
`analysis/slices/0C74/0C74_<off>.asm` plus the Reko slices `0C74_522C.c` /
`0C74_5258.c` / `0C74_542B.c` / `0C74_54B1.c` / `0C74_54F0.c` /
`0C74_552F.c`.  Frozen prototypes adopted exactly from `src/seg0C74.h`
(`analysis/summary/iface.tsv`) with no edits:

```c
u8   fn0C74_522C(u16 *bpOut, void *dsOut);
u8   fn0C74_5258(u16 *dsOut);
u8   fn0C74_542B(u16 *dsOut);
u8   fn0C74_54B1(u16 *dxOut, u16 *bpOut, void *dsOut);
u8   fn0C74_54F0(u16 *dxOut, u16 *bpOut, void *dsOut);
void fn0C74_552F(void);
```

Every callee argument order was re-derived from the callee's own `.asm` (the
frozen parameter list is last-pushed first): `1AB8:1E3C/1E54/13A3/1E6B/10F4/`
`1C32/1AF6/13D7`, `1EDA:023F/0254`, `0C74:3236/2E5A/05B8/396E/45CE/3F74/4999/`
`4DAC/4FD7/3615/37C3/2AD9/2BBD`.  These are the last six functions of segment
0C74; `fn0C74_552F` is the CRT startup hook called from `fn0800_4255`.

### Role of each function

* **`522C`** — frame dispatch on the `[5968h]` state word: state `1` runs the
  pull helper `fn0C74_3236`, state `0FFFFh` runs `fn0C74_2E5A`, then the `05B8`
  scroll driver ticks.  Returns the `[bp-1h]` byte.
* **`5258`** — the extended "pull-in" frame update.  Two edge probes per state
  gate the state's drawing pair (`396E`/`45CE` for `1`, `3F74`/`4999` for
  `0FFFFh`), then the `[596C]`/`[5970]`/`[596E]` geometry is used to pick a
  scan row, which is walked back by `16h` while a `1E3C` probe returns `8h`.
  When the row moved it builds a `13A3`-sized block (`023F`), blits with
  `1E6B`, sets colour (`10F4`/`1C32`), draws (`1AF6`), runs the `2BBD` grow
  animation, blits (`13D7`) and frees (`0254`).
* **`542B`** — state-`1` probes `([58BAh]+1,[58B6h]±1)`, state-`0FFFFh` probes
  `([58BAh]±1,[58B4h]-1)`; on the empty/occupied pair it runs
  `4FD7`+`3615` or `4DAC`+`37C3`, else clears the flag.
* **`54B1` / `54F0`** — mirrored latch helpers: set `[58BCh]=1`, probe the two
  edge pairs and conditionally run `2AD9`, then tail-run `3615` / `37C3` and
  return its `[bp-1h]` byte.
* **`552F`** — arms the `[58B2h]` input-poll latch.

### Hardware / dispatch sites

**None directly.**  No `int 10h` / `int 16h` / `int 21h`, no raw `in`/`out`
port instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch
(`fn1E5F_000B` is never called) occur in `522C..552F`.  Hardware is reached
only indirectly through already-ported callees:

* `fn1AB8_1E3C` / `1E54` / `13A3` / `1E6B` / `10F4` / `1C32` / `1AF6` / `13D7`
  — the 1AB8 text/video driver (`seg1AB8*.c`).
* `fn1EDA_023F` / `0254` — the 1EDA far-heap allocate/free helpers
  (`seg1EDA*.c`).
* `fn0C74_3236` / `2E5A` / `05B8` / `396E` / `45CE` / `3F74` / `4999` / `4DAC`
  / `4FD7` / `3615` / `37C3` / `2AD9` / `2BBD` — their own chunks own the port
  I/O, reached transitively via `02D8` / `070D` -> `11C8` (PC speaker / AdLib),
  all guarded by DGROUP `0x58B0`.

### Segment / DGROUP data referenced

* `0x5968` word — state/direction word (`1` = one axis, `0FFFFh` = the other).
* `0x596C` / `0x596E` / `0x5970` words — cached rectangle origins.
* `0x58B2` byte — input-poll latch (armed by `552F`).
* `0x58B4` / `0x58B6` / `0x58B8` / `0x58BA` words — live X/Y and cached
  left/top rectangle origins; `0x58BC` byte — completion latch (`54B1`/`54F0`).

### Flat-model / ABI adaptations

1. **Reko `bp_XXXX` frame pointers folded to the local frame.**  After every
   `fn0C74_*` / `fn1AB8_*` call Reko re-binds `bp_148` / `bp_166` / `bp_83` /
   `bp_61` etc. to the callee's returned pointer and then reads
   `ss:[bp_XXXX - k]`.  Those reads are always the current function's own frame;
   the translation uses the literal locals (`bLoc01`/`bLoc02`, `wLoc04`..`wLoc10`)
   directly, per notes-0C74 part 1 section 3.
2. **Saved-BP / DS / DX register outputs.**  `bpOut`, `dsOut` and `dxOut` are
   the caller's saved BP word, the dropped DGROUP selector and the threaded DX
   artifact; each receives `0` (part 1 section 3, parts 9/10/11).  Where the
   frozen prototype spells the slot `void *` (522C / 54B1 / 54F0 `dsOut`), a
   2-byte zero is written (`*(u16 *)dsOut = 0`), matching part 2's `fn0C74_070D`
   `void * dsOut` precedent and never over-running a caller that passed a
   `u16 *` (several callers in seg0800 part 8/9 pass a `u16` scratch, one a
   `void *`; the callers never read the value).
3. **`push cs` before `call 05B8h`.**  `522C:524F` pushes CS before the near
   call into the `enter`-framed `fn0C74_05B8`, which never reads `[bp+4]`; the
   extra word is dropped exactly as in part 2's `fn0C74_06B7`, and the call is
   `(void)fn0C74_05B8(&dsTmp);`.
4. **State dispatch shape.**  `522C`/`5258`/`542B` each read `[5968h]` once
   into AX (`mov ax,[5968h]`) and compare against `1` and `0FFFFh`; recovered as
   a `switch (LG16(0x5968))` with the two cases in the same order as the asm
   (`cmp ax,1h` then `cmp ax,0FFFFh`).  `5258` re-reads `[5968h]` twice more at
   `52EE`/`5306` (both `cmp word [5968h],1h`), kept as literal `LG16` reads.
5. **16:16 far blocks (`fn1EDA_023F` / `0254`).**  `5258` carries the `023F`
   `DX:AX` result as `u32` (`offset | segment<<16`, low word at `[bp-0Eh]` =
   `wLoc0E`, high at `[bp-0Ch]` = `wLoc0C`) and materialises it with
   `(u8 *)(uintptr_t)` at the `1E6B`/`13D7`/`0254` call sites, the
   parts 2/3/4/6/7/8/9/15 convention.  The `wArg00`/`wArg02` leading stack words
   are seeded `0` (read only on the fatal divide-by-zero dispatcher path).
6. **`fn1EDA_0254` argument mapping.**  Per the ported callee, the third frozen
   parameter (`wArg04`) is the `13A3` block size and `ptrArg06` the 16:16 block;
   the call is `fn1EDA_0254(0, 0, wLoc10, block, &dxTmp, &dsTmp)`, matching
   parts 2/7/15.
7. **`3615` / `37C3` return capture.**  In `542B` the `[bp-1h]` flag comes from
   `4FD7` / `4DAC` and the `3615` / `37C3` return is discarded
   (`(void)fn0C74_3615(...)`), matching Reko (`bFFFF = fn0C74_4FD7(...);
   fn0C74_3615(...)`).  In `54B1` / `54F0` the `[bp-1h]` flag is the
   `3615` / `37C3` return (`bLoc01 = fn0C74_3615(...)`).

### Uncertain sites / not recovered literally

* **Saved-BP / DS / DX artifacts (item 2).**  Cannot reproduce the original
  BP-chain word, DGROUP selector or threaded DX in flat C; written `0`.  The
  `3615`/`37C3` `dxOut` chain is itself a documented loss (parts 9/10), so the
  `54B1`/`54F0` `dxOut` is `0` for the same reason.
* **`5258` far-block pointers.**  `(u8 *)(uintptr_t)` reproduces the original
  segment:offset integer, not a host pointer (same documented convention as
  `seg0800_part3.c` / `seg0C74_part2.c`).  `fn1AB8_1E6B`/`13D7` split it back
  into `(u16)`/`(u16)(p>>16)`, so the arithmetic is exact; the far-heap paths are
  not exercised by the build.  In the shipped port the far-heap node fetches
  resolve to zero, so these blocks are `NULL` (established project behaviour).
* **`522C` / `5258` probe-gated helper calls.**  The `.asm` structure
  (`jz`/`jnz` around each `fn1AB8_1E3C`) is preserved literally.  In particular,
  when the *first* probe is empty `5258` still runs the second helper
  (`45CE`/`4999`) because `[bp-2h]` keeps its initial `1` — this is the
  original behaviour (Reko's nested `if` + flag test also reproduces it), not a
  bug introduced here.
* **`5258` early-exit.**  The `[bp-2h] == 0` test at `52E5` jumps to the common
  `5420` return; the distinct `[bp-1h]` word is only ever produced there
  (`mov al,[bp-2h] ; mov [bp-1h],al`), so the flat port simply returns
  `bLoc02`.
* **`552F` has no `enter`** (`push bp ; mov bp,sp ; ... ; leave ; retf`); no
  frame bytes are addressed, so the flat C body is a single `LG8` store.

### `.asm`-verified callee argument order

| callee | frozen prototype | pushed (last = first arg) | C call |
|---|---|---|---|
| `fn1AB8_1E3C` | `(wArg04, wArg06, dlOut)` | `y`, `x` | `(x, y, &dlTmp)` |
| `fn1AB8_1E54` | `(bArg04, wArg06, wArg08)` | `y`, `x`, `color` | `(color, x, y)` |
| `fn1AB8_13A3` | `(wArg04, wArg06, wArg08, wArg0A)` | `y0`, `x0`, `y1`, `x1` | `(x1, y1, x0, y0)` |
| `fn1AB8_1E6B` | `(ptrArg04, wArg08, wArg0A, wArg0C, wArg0E)` | `y0`, `x0`, `y1`, `x1`, es, di | `(block, x1, y1, x0, y0)` |
| `fn1AB8_13D7` | `(bArg04, ptrArg06, wArg0A, wArg0C)` | `y`, `x`, es, di, `0` | `(0, block, x, y)` |
| `fn1AB8_10F4` | `(wArg04, wArg06, wArg08)` | `0`, `0`, `1` | `(1, 0, 0)` |
| `fn1AB8_1AF6` | `(wArg04, wArg06, wArg08, wArg0A, dxOut)` | `y`, `x1`, `y`, `x2` | `(x2, y, x1, y, &dxTmp)` |
| `fn1EDA_023F` | `(wArg00, wArg02, wArg04, dsOut)` | `size` only | `(0, 0, size, &dsTmp)` |
| `fn1EDA_0254` | `(wArg00, wArg02, wArg04, ptrArg06, dxOut, dsOut)` | `hi`, `lo`, `size` | `(0, 0, size, block, &dxTmp, &dsTmp)` |
| `fn0C74_2BBD` | `(wArg02, wArg04, wArg06, wArg08)` | (`a`,`b`,`c`,`d`) | `(d, c, b, a)` at `5258:53FB` = `(wLoc0A, wLoc08, wLoc06, wLoc04)` |

For the far-called `1AB8`/`1EDA` entries the first argument is at `[bp+6]` (the
far return address occupies `[bp+2]/[bp+4]`), so the last-pushed word is the
first C parameter; the near-called `0C74` entries put it at `[bp+4]`.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part16.c` — 0 errors, 0 warnings.
* `gcc -c -Wall -Wextra -Isrc -Ipal src/seg0C74_part16.c` — likewise clean.
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(|SLICE\(`
  over `src/seg0C74_part16.c` — 0 matches.
* All six in-range functions are defined with the exact `src/seg0C74.h`
  prototype (the TU includes the header, so gcc rejects any divergence);
  `nm /tmp/opencode/seg0C74_part16.o` shows `T fn0C74_522C`, `T fn0C74_5258`,
  `T fn0C74_542B`, `T fn0C74_54B1`, `T fn0C74_54F0`, `T fn0C74_552F`, with
  every callee `U` (`fn0C74_05B8/2AD9/2BBD/2E5A/3236/3615/37C3/396E/3F74/45CE/`
  `4999/4DAC/4FD7`, `fn1AB8_10F4/13A3/13D7/1AF6/1C32/1E3C/1E54/1E6B`,
  `fn1EDA_023F/0254`, `g_dgroup`).
* Compiling every existing `src/seg0C74_part*.c` in one pass produces no
  duplicate global definitions; each of the six symbols is provided exactly
  once, by part 16.

## part 14

Function `0C74:4999` (called only from `fn0C74_5258`):

```
4999
```

Recovered into `src/seg0C74_part14.c`.  Ground truth =
`analysis/slices/0C74/0C74_4999.asm` plus the Reko slice `0C74_4999.c` and
`analysis/reko/RAD_0C74.{asm,dis}`; the frozen prototype is adopted exactly
from `src/seg0C74.h` (`analysis/summary/iface.tsv`) with no edits:

```c
u8 fn0C74_4999(void * bpOut, u16 * dsOut)
```

Every callee argument order was re-derived from the callee's own `.asm` (the
frozen parameter list is last-pushed first): `1AB8:10F4/1AF6/1C32/1E3C/13D7`,
`0C74:070D/02D8/076B`, `11C8:033B/0354`.

### Hardware / dispatch sites

**None directly.**  No `int 10h` / `int 16h` / `int 21h`, no raw `in`/`out`
port instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch
(`fn1E5F_000B` is never called) occur in 4999.  Hardware is reached only
indirectly through already-ported callees: the `fn1AB8_*` text/video driver
(`10F4`/`1AF6`/`1C32`/`1E3C`/`13D7`) and the 0C74 tick/frame drivers
`fn0C74_070D` / `02D8`, whose `070D -> 02D8/11C8` chain owns the PC-speaker /
AdLib port I/O, all guarded by DGROUP `0x58B0`.

### Segment / DGROUP data referenced

* `0x58B0` byte — sound-enable gate.
* `0x58B3` byte — "stop"/win flag set on the successful `076B` path.
* `0x58B4` word — live bar Y (incremented on entry, decremented on every exit
  path); `0x58B6` word — live bar X.
* `0x58B8` / `0x58BA` words — cached left/top rectangle origins.
* `0x596C` / `0x596E` / `0x5970` / `0x5972` words — derived cached rectangle.
* `0x58F4` table — 4-byte far pointers (sprite/row blocks), indexed by the
  animation counter `wLoc04` (5..1), the same table read by parts 2/3/8/9/10.

### Flat-model / ABI adaptations

1. **Reko `bp_XXXX` frame pointers folded to the local frame.**  After every
   `fn0C74_070D` / `02D8` call Reko re-binds `bp_39` / `bp_172` to the callee's
   AX return (the caller's saved BP) and then reads `ss:[bp_XXXX - k]`.  Those
   reads are always the current function's own frame; the translation uses the
   literal locals `wLoc04`..`wLoc0C` / `bLoc01` directly, per notes-0C74 part 1
   section 3.
2. **`0x58F4` far-pointer table.**  `les di,[di+58F4h]` with
   `di = wLoc04*4` is recovered as
   `(u8 *)(uintptr_t)LG32((u16)(0x58F4 + (u16)(wLoc04 << 2)))`, the same
   round-trip convention as parts 2/3/8/9/10.
3. **`bpOut` / `dsOut` register outputs.**  Reko writes the caller's saved BP
   and the dropped DGROUP selector; both receive `0` (`*(u16 *)bpOut = 0`,
   `*dsOut = 0`, part 1 section 3).  The distinct `[bp-01h]` return byte is
   preserved and returned.
4. **`1AF6` dxOut / `1E3C` dlOut.**  Both register outputs are unused by the
   original; scratch locals (`dxTmp`, `dlTmp`) are passed.
5. **`push cs` before `call 076Bh`.**  The two `076B` call sites
   (`4D78`, `4D93`) push CS before the near call; the extra word is dropped
   exactly as in parts 13/16 (`fn0C74_076B` reads only its four word
   arguments).  The call argument order follows parts 13/16:
   `(last, third, second, first-pushed)`.
6. **Control flow.**  The exact label topology of the `.asm` is preserved with
   `goto` (`4A49`/`4AAC`/`4AB7`/`4BBB`/`4BE8`/`4C88`/`4CA0`/`4CD0`/`4D22`/
   `4D4F`/`4DA7`), including the shared probe-branch labels and the single
   downward loop over `wLoc06` (1..2Ch).

### Uncertain sites / not recovered literally

* **`0FFF1h` immediate at `49FE` / `4A49`.**  The slice `.asm` prints
  `cmp word ptr [bp-4h],0F1h`, but the raw encoding is `83 7E FC F1`
  (sign-extended imm8), i.e. the comparison value is `0xFFF1`, matching Reko's
  `~0x0E`.  Verified with `ndisasm` against `data/segments/seg0C74.bin`; the
  port compares against `0xFFF1u`.  (Cross-check, not changed here: the
  sibling part 15 `fn0C74_4DAC` / `4FD7` `cmp word [bp-4h],0E9h` is encoded
  `83 7E FC E9`, a sign-extended imm8 `0xFFE9`, but part 15 wrote `0x00E9`;
  that is outside this chunk's range and was left untouched.)
* **Saved-BP / selector artifacts.**  No flat-C equivalent; written `0`.
* **`1AF6`/`1E3C` register outputs.**  The `dxOut`/`dlOut` values are dead in
  every path here; scratch locals are discarded.
* **Far-pointer table value.**  `(u8 *)(uintptr_t)LG32(...)` reproduces the
  original segment:offset integer as an integer, not a host pointer (same
  documented convention as `seg0800_part3.c` / `seg0C74_part2.c`); the entry
  value is whatever part 2 stored.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0C74_part14.c` — 0 errors, 0 warnings
  (`-Wall -Wextra` likewise clean).
* Reko-token grep `Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>|SEQ\(|CONVERT\(|SLICE\(`
  over `src/seg0C74_part14.c` — 0 matches.
* `fn0C74_4999` is defined with the exact `src/seg0C74.h` prototype (the TU
  includes the header, so gcc rejects any divergence);
  `nm /tmp/opencode/seg0C74_part14.o` shows `T fn0C74_4999`.
* No other `src/seg0C74_*.c` defines `fn0C74_4999`.
