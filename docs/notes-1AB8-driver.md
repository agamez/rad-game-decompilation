# Notes: 1AB8 graphics-driver blob (`src/seg1AB8_driverB.c`)

Recovery notes for the embedded BGI-style graphics driver that lives inside
segment 1AB8.  Ground truth = raw bytes of `data/segments/seg1AB8.bin`,
decoded with `ndisasm -b16 -o 0x2500` and
`objdump -D -b binary -mi8086 --adjust-vma=0x2500`.  No Reko listing covers
this region (Reko stopped at `fn1AB8_2043` / `1AB8:2072` and emitted
`1AB8:2073..` as data).

## batch B

### What is in this batch

`src/seg1AB8_driverB.c` recovers the driver code at **file offsets
0x2500..0x3000** (driver-relative 0x046D..0x0F6D).  The batch's only exported
symbol is

```c
u16 seg1AB8_driver_batchB(u16 si, u16 *regs);
```

which returns 1 when `si` is handled and 0 otherwise.

### The embedded driver and its segment base

The driver image begins at `1AB8:2073`:

| offset | bytes | meaning |
| --- | --- | --- |
| 0x2073 | `20 00` | entry offset (+0x20 -> `1AB8:2093`) |
| 0x2075 | `D0 19` | image size (0x19D0) |

`fn1AB8_0BAE` (1AB8:0BB4) points DGROUP `[0xB820]`/`[0xB822]` at `1AB8:2073`
and calls `fn1AB8_0569`, which relocates/copies the image into its own segment
and returns the entry far pointer.  The wrappers in
`src/seg1AB8_part5b.c`/`part6.c`/`part7.c`/`part8.c` stage `SI` = function
number and execute `call dword ptr [0B820h]`.

The relocated driver's segment base makes **driver offset 0 == file offset
0x2093**.  This is proved, not assumed: the driver's own far dispatcher at
`1AB8:245A` runs

```
push ds / push cs / pop ds
push ax / mov di,si / mov si,0x39E
lodsw-test-cmp loop -> call di
pop ds / retf
```

and the `(key,handler)` table it indexes at `CS:0x39E` decodes as the byte run
at file **0x2431** only when the base is 0x2093.  All ten handler offsets then
land exactly on routine starts.  Driver-internal offset `X` therefore maps to
file `0x2093 + X`.

### Dispatch mechanics

Two dispatch tables exist, both driver-relative.

**1. The wrapper table — `1AB8:2093` (driver 0x0000).**

```
1AB8:2093  1E        push ds
1AB8:2094  0E        push cs
1AB8:2095  1F        pop ds
1AB8:2096  56        push si
1AB8:2097  FF 94 13 00   call word [si+0x13]
1AB8:209B  5E        pop si
1AB8:209C  1F        pop ds
1AB8:209D  2E FF 2E 70 00  jmp far [cs:0x70]
```

The near-call table is at driver offset 0x0013 (file 0x20A6), indexed directly
by `SI` = wrapper function number.  Its non-default entries are
`020C 0296 013A 0145 0192 00D6 0189 01A8 01B1 02E1 02F0 0321 1420 01D8
01DE 0202 0161 0180 019E 00DD`; the repeated `00D4` word is the no-op default
it resolves to `1AB8:2167` (`ret`).  **Every non-default target lies in batch A
(file 0x2167..0x23B4) or beyond (0x34B3 for fn 0x24)** — none in this batch.
So the wrapper protocol's own implementations are *not* in batch B; batch B
holds the helpers/handlers of the driver's inner dispatch.

**2. The driver's own table — `1AB8:245A` (driver 0x03C7).**

Its `(fn,handler)` table at driver offset 0x039E (file 0x2431) is

| fn | handler (driver) | handler (file) | in this batch? |
| --- | --- | --- | --- |
| 0x0E | 0x0B83 | 1AB8:2C16 | yes |
| 0x10 | 0x071A | 1AB8:27AD | yes |
| 0x12 | 0x0493 | 1AB8:2526 | yes |
| 0x14 | 0x0823 | 1AB8:28B6 | yes |
| 0x16 | 0x08A2 | 1AB8:2935 | yes |
| 0x18 | 0x087F | 1AB8:2912 | yes |
| 0x20 | 0x045A | 1AB8:24ED | no (batch A) |
| 0x24 | 0x1437 | 1AB8:34CA | no (batch C) |
| 0x26 | 0x18C9 | 1AB8:395C | no (batch C) |
| 0x28 | 0x1713 | 1AB8:37A6 | no (batch C) |

`seg1AB8_driver_batchB` therefore handles **0x0E, 0x10, 0x12, 0x14, 0x16,
0x18** and returns 0 for everything else.

The task brief "expected among them 0x12 (fill rect), 0x14 (bitblt), 0x1A
(cursor shape), 0x1C (set text buffer ptr), 0x1E (palette/viewport), 0x20
(write char), 0x22 (write char+attr)".  Verifying against the actual tables:
only **0x12 and 0x14** land in this batch (as expected); **0x1A and 0x1C** are
`00D4` defaults in the wrapper table (no-op `ret` at 1AB8:2167); **0x1E, 0x20,
0x22** map to batch-A handlers `1AB8:2374`, `1AB8:2383`, `1AB8:23B4`
respectively.  None of 0x1A/0x1C/0x1E/0x20/0x22 has an implementation in
0x2500..0x3000.

### Register conventions / the `regs` image

`regs` is the staged register image the wrappers build, in the field order of
`TRegs1AB8` as declared by `src/seg1AB8_part8.c`
(`ax, bx, cx, dx, si, di, es`):

| index | register | role |
| --- | --- | --- |
| 0 | AX | in/out |
| 1 | BX | in/out |
| 2 | CX | in/out |
| 3 | DX | in/out |
| 4 | SI | selector (also the first argument of the batch entry) |
| 5 | DI | in/out |
| 6 | ES | segment of a far-pointer argument/result |

The dispatched routines take/return their parameters through AX/BX/CX/DX and
use SI/DI as scratch.  The file defines `R_AX..R_ES` accordingly.

### Driver state, tables and the [0x70] callback

* Driver-internal state is kept in the **file-static mirror** `g_drv[0x19D0]`,
  indexed by driver-relative offset via `D8`/`D16`/`D32`.  It is seeded from
  the relocated image (`drv_seg_init()`, first call of the batch entry) so the
  initial values survive — e.g. driver 0x0095 = 100, 0x0097 = 100, 0x009A = 1,
  0x009F = 1, 0x0B80 = 1, 0x0822 = 0xFF.
* `call far [0x70]` is a **no-op stand-in** (`drv_call70(si)`).  Driver
  0x0070/0x0072 is the far entry of the *device* driver, installed by the
  1AB8:229F initialiser (batch A) from a run-time-loaded external file; it is
  not part of the recovered image.  The forwarded `si` sub-codes seen here are
  0x0C, 0x0E, 0x1E, 0x22, 0x30.
* The clip-run list is held by driver 0x0533/0x0535 as a 16:16 far pointer.
  The flat port keeps the offset and backs `ES:[DI]` with the file-static
  `g_clipbuf[0x10000]` (`CLIPW`).
* `1AB8:25D0` dispatches on AL (clamped to 5 when AL >= 8) through the 8-word
  table at driver 0x054D.  The table is read literally
  (`D16(0x054D + di)`) and dispatched by value; it decodes to driver offsets
  0x055D 0x05C1 0x05FF 0x05C6 0x056F 0x05EB 0x0575 0x0579 -> 1AB8:25F0, 2654,
  2692, 2659, 2602, 267E, 2608, 260C.
* `1AB8:2E18` walks a 5-byte-per-entry table based at driver 0x0D49
  (file 0x2DDC) selected by `AL = [0x90]-1`, and uses the width word at driver
  0x0B80.

### Routines recovered (ascending file offset)

Full literal recovery: 2526, 2563, 256F, 257C, 25B3, 25D0, 25F0, 2602, 267E,
2684, 2654, 2659, 2692, 26B1, 2702, 2705, 270F, 2720, 2728, 277C, 279E, 27AD,
2856, 287B, 289A, 28B6, 2906, 2912, 2A02, 2B15, 2B22, 2B31, 2B3D, 2B49,
2B68, 2B94, 2BE7, 2C5A, 2C9B, 2CE2, 2D09, 2D39, 2D68, 2D9D, 2DAF, 2E78,
2FC1, 2FE6.

Structural recovery with documented modelling: 260E (clip-list drain),
2A19 (fn 0x16 scan converter, bp frame), 2AC2, 2935 (fn 0x16 outer loop),
2C16 (fn 0x0E scanline fill, bp frame), 2E18, 2E83 / 2E83_args (arc/scan
converter, `ret 0x14` ten-word argument frame).

### Data tables captured

* 1AB8:25E0..0x25EF — 8-word jump table for 1AB8:25D0 (driver 0x054D).
* 1AB8:2431..0x2459 — `(fn,handler)` table for 1AB8:245A (driver 0x039E).
* 1AB8:20A6..0x2104 — wrapper near-call table (driver 0x0013), documented.
* 1AB8:2DDC..0x2E17 — 5-byte stride glyph/run table used by 1AB8:2E18.
* 1AB8:2114..0x2134 — driver scalar block (e.g. 0x90, 0x95=100, 0x97=100).

### Cross-batch continuations

Recovered by other batches; not converted here (file-static no-op stand-ins
with the original site named):

* batch A: `1AB8:221C` (add origin [0x84]/[0x86] — implemented literally
  because it is a pure register op), `248B`, `2478`, `24C7`, `24E0`, `2369`.
* batch C: `1AB8:326F`, `3423`, `3470`, `3008`, `302A`, `30B3`, `30DA`,
  `30EC`, `3101`, `3116`.

`1AB8:2E83` and `1AB8:2A19` own a bp frame whose helpers (`2FC1`, `2FE6`,
`3008`, `302A`, `30B3`, `30DA`, `30EC`, `3101`, `3116`) straddle the 0x3000
batch boundary; the in-range halves (`2FC1`, `2FE6`) are recovered, the
out-of-range halves are stand-ins.

### Uncertain sites

1. **Device-driver callback `[0x70]`.** The far entry is not in the image, so
   its effects (including carry results consumed by `1AB8:256F`, `2728`,
   `2DAF`) cannot be reproduced.  Stand-ins clear carry, which selects the
   "no device forward" path; every such site is marked inline.
2. **Wrapper-table function numbers.** The brief's expected list is only
   partially supported by the actual tables (see above).  The batch handles
   the six numbers whose handler lies in range and returns 0 for the rest.
3. **`1AB8:2A19` / `1AB8:2935` / `1AB8:2C16` / `1AB8:2E83` bp frames.** These
   routines share a caller bp frame with helpers across the batch boundary;
   the flat port models the in-range arithmetic exactly but the frame
   hand-off to batch-C helpers is a stand-in.  Recorded as partial.
4. **`1AB8:2E18` table stride.** The glyph table at driver 0x0D49 is read, but
   the `imul word [0xB80]` result and the subsequent device write are modelled
   without the device driver.
5. **Clip-list backing store.** The driver allocates the list at run time;
   `g_clipbuf` stands in for the original far segment.

### Validation

```
$ gcc -c -Wall -Isrc -Ipal src/seg1AB8_driverB.c
(no output; exit 0)

$ grep -cE "Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>" src/seg1AB8_driverB.c
0

$ nm driverB.o | grep driver_batchB
0000000000002ea5 T seg1AB8_driver_batchB
```

No `int 10h/16h/21h`, no raw port I/O, no `__cli/__sti`, no `int 23h` and no
`pal_*` reference occurs in this batch.
