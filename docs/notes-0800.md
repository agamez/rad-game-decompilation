# notes-0800 -- segment 0800 recovery notes

Ground truth = `analysis/slices/0800/0800_<off>.asm` (Reko structure from
`analysis/reko/RAD_0800.c`); frozen prototypes from `src/seg0800.h`
(`analysis/summary/iface.tsv`) adopted exactly.

## part 1

Source: `src/seg0800_part1.c` -- functions 0800:0000, 0024, 005A, 00C1, 0103,
0147, 01FE, 031B, 03F8, 04CC, 04E3 (ascending offset).

### Functions converted

| off  | prototype |
|---|---|
| 0000 | `u16 fn0800_0000(void)` |
| 0024 | `void fn0800_0024(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)` |
| 005A | `void fn0800_005A(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)` |
| 00C1 | `u8 fn0800_00C1(u16 wArg02, u16 wArg04, u16 * dxOut)` |
| 0103 | `void fn0800_0103(void)` |
| 0147 | `u16 fn0800_0147(void)` |
| 01FE | `void fn0800_01FE(void)` |
| 031B | `u16 fn0800_031B(u16 * bpOut, u16 * dsOut)` |
| 03F8 | `u16 fn0800_03F8(void)` |
| 04CC | `s16 fn0800_04CC(u8 bArg02)` |
| 04E3 | `u8 fn0800_04E3(u16 * dsOut)` |

### Hardware / dispatch sites

**None.** No `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port instruction,
no `__cli`/`__sti` and no `int 23h` occur in 0000..04E3. All BIOS/DOS traffic
reached from here is owned by the callee segments and is replaced there:
`fn1E5F_0159`/`fn1E5F_0171` (AH=35h/25h vector save/restore on vector 1Ch,
replacing the int 21h inside 1E5F), `fn1E78_016B` (keyboard/PIT), and the
1EDA/0C74/11C8/1206 file+video+AdLib helpers.

### Flat-model far-pointer / ABI adaptations

* **Far-heap blocks.** `fn1EDA_023F` returns the 16:16 allocation as
  `(segment << 16) | offset`, the convention used by `seg1AB8`/`seg1229`. The
  `.asm` pushes only the size word and the frozen prototype carries it in
  `wArg04` (the `wArg00`/`wArg02` are the far return words), so every call is
  `fn1EDA_023F(0, 0, size, &dsOut)` (see `docs/notes-1EDA.md` ## chunk 2a
  uncertainty 5, which flags the older `seg1AB8_part2.c` calls that put the size
  in `wArg00`).
* **`0x5992`/`0x5994` and `0x5388`/`0x538A` far-pointer tables.** Stored as two
  literal words (low = offset, high = segment) exactly as 0147/03F8 write them;
  01FE rebuilds the block as `(high << 16) | low` for `fn1AB8_13D7`.
* **`fn1EDA_0254`** is called `(0, 0, size, block, &dxOut, &dsOut)` as in
  `seg1229_part1.c`, matching the part-2a implementation.

### Uncertain sites / not recovered literally

1. **`fn0800_00C1` return value and `dxOut`.** The `.asm` returns whatever AX
   the AH=25h wrapper left; Reko models the wrapper's `byte` result, zero-extends
   it and slices the high byte, i.e. 0. The surviving callers ignore the return
   value, so the Reko derivation is kept. `dx` (the wrapper's DX output) is also
   only produced on the install path in the original; it is seeded 0 here so the
   unconditional `*dxOut = dx` is defined.
2. **`fn0800_031B` `bpOut`/`dsOut`.** Both are Reko `Register out` artifacts; the
   `.asm` only sets AL and returns. They are written as 0 ("saved-BP output; not
   meaningful here", matching `seg133F.c`). The original also pushes a 0 word
   before each `fn1206_015B` call; the frozen prototype cannot carry that word
   (same class of dropped argument as `fn1EDA_10BB`), so the two calls use the
   frozen four-pointer form.
3. **`fn0800_031B` default switch arm.** The `.asm` switch over index 0..8 has no
   default, leaving `[bp-7h]` uninitialised if the `idiv` yields anything else.
   C requires a definite value, so the attribute byte is seeded 0 before the
   switch.
4. **Dropped coordinates in `fn0C74_004B`.** The original pushes two extra words
   (the on-screen x/y: 12Fh/163h/197h and 18Dh, then 130h/164h/198h and 18Eh)
   after the far pointer; the frozen prototype exposes only
   `(u32 dwArg04, u8 * ptrArg08)`, so those coordinates are dropped at all six
   call sites in `fn0800_04E3` (recorded in comments).
5. **Dropped data buffer in `fn1EDA_10BB`.** In 0147/03F8 the record is read into
   the freshly allocated heap block; that pointer is the dropped `[bp+0Ch]`
   argument, modelled by the port as `g_1EDA_io_buffer` (default
   `DGROUP:0x5CB4`). In 01FE the real buffer *is* `DGROUP:0x5CB4`, so the default
   is exact there; for 0147/03F8 the heap allocation is not host memory and the
   default buffer is used instead.
6. **`fn1EDA_1085` data pointer.** Same dropped-argument class; the 01FE call
   matches the default `g_1EDA_io_buffer = DGROUP:0x5CB4`.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0800_part1.c` -- exit 0, zero diagnostics
  (also clean with `-Wextra`).
* Reko-token grep (`Eq_[0-9]`, `<invalid>`, `<unknown>`, `SEQ(`, `CONVERT(`,
  `Mem[0-9]*[`, `segptr`) -- 0 hits.
* `nm` reports all 11 functions (`fn0800_0000` .. `fn0800_04E3`) as `T`.

## part 2

Source: `src/seg0800_part2.c` -- functions 0800:0619, 0768, 0877, 08C0, 08E9,
09C2, 0AA1 (ascending offset).  Ground truth = `analysis/slices/0800/0800_<off>.asm`;
frozen prototypes from `src/seg0800.h`.

### Functions converted

| off  | prototype |
|---|---|
| 0619 | `u16 fn0800_0619(void)` |
| 0768 | `s16 fn0800_0768(u16 * bpOut, u16 * dsOut)` |
| 0877 | `u8 fn0800_0877(void)` |
| 08C0 | `u16 fn0800_08C0(void)` |
| 08E9 | `s16 fn0800_08E9(s16 dx)` |
| 09C2 | `u8 fn0800_09C2(u8 bArg02, u16 * bpOut, u16 * dsOut)` |
| 0AA1 | `u16 fn0800_0AA1(u16 * dsOut)` |

### Hardware / dispatch sites

**None direct.** No `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port
instruction, no `__cli`/`__sti` and no `int 23h` occur in 0619..0AA1.  All
BIOS/DOS/mouse traffic reached from here goes through the already-converted
callees: `fn1AB8_*` (video), `fn1EDA_*` (records/data files), `fn0C74_*`
(menus), `fn1206_0066`/`fn1206_0038`/`fn1206_015B` (mouse cursor, INT 33h via
`fn1E5F_000B`) and `fn1E78_02FB`/`fn1E78_030D` (keyboard/PIT).

### Segment data referenced

Length-prefixed records in the 0800 image, read exactly as the original:
`cs:0605` = {4,"DEMO"} (grid-select comparison), `cs:060A` = {3,"000"},
`cs:060E` = {1,"0"}, `cs:0610` = {8,"MISSION "}, `cs:0755` = {7,"PRESSEZ"},
`cs:075D` = {10,"UNE TOUCHE"}, `cs:0A9F` = {1,"0"}.

### Flat-model far-pointer / ABI adaptations

* **DGROUP far pointers** at 0x598E (RAD.STR record) and 0x58DC (0AA1's record)
  are read as the two literal words: `fn0C74_004B(LG32(0xHHHH), buf)`.
* **0x5388 far-pointer table** (RAD.BUT, written by 03F8): `09C2` reads
  `blk = (u8 *)(uintptr_t)LG32(0x5388 + bArg02*4)` (`les di,[di+5388h]`) and
  passes it to `fn1AB8_13D7(0, blk, 0x0198, wLoc02)`.
* **`fn1EDA_0A39` / `fn1EDA_0A1F` / `fn1EDA_0AAC` third/register arguments.**
  In the original the source/record pointers of these helpers are passed in
  DS:SI / ES:DI (never pushed); the frozen prototypes expose them as ordinary
  pointer parameters, so every site passes the live buffer explicitly
  (`bLoc04`, `abBuf`) exactly as `seg1AB8`/`seg1229`/`seg133F` already do.
* **`fn1AB8_112E` / `fn1AB8_10F4` / `fn1AB8_13D7` arguments** are passed in the
  frozen left-to-right order matching the cdecl push order of the .asm.

### Uncertain sites / not recovered literally

1. **`fn0800_0619` return.** iface.tsv documents the return as the dropped
   DGROUP selector; the .asm ends `leave; ret` with AX left by the last
   `fn1AB8_1D82` call.  The callee's `fn1AB8_1536` writes 0 to `dsOut`, so
   `return ds_43;` (= 0), consistent with part 1's 0147/03F8.
2. **`fn0800_08C0` return.** iface.tsv says "returns DGROUP selector", but the
   .asm's only return write is `mov al,[bp-1h]` (the 0/1 flag); the frozen
   prototype is `u16`, so the flag is returned.  All eight callers
   (`2401`/`2827`/`2C0C`/`31B7`) discard it (`call 08C0h` with no AX/DX use).
3. **`fn0800_09C2` second `fn1EDA_0CD4` branch polarity.** The machine code is
   `74 03` (JZ, skip `04E3` when the tested bit is CLEAR) for the first call and
   `75 05` (JNZ, skip `fn1206_0038` when the tested bit is SET) for the second;
   Reko decompiled both as `if (!fn1EDA_0CD4(...))`.  The .asm is followed:
   `== 0x00 -> 04E3`, `!= 0x00 -> 0038`.
4. **`fn0800_09C2` `wLoc02` computation is missing from Reko** (it emits only the
   bare `fn0800_04CC(...)` calls).  Recovered from the .asm:
   `wLoc02 = bArg02*8 + (04CC(bArg02<<1) + 0x16)` for 0..8 and
   `(bArg02-9)*8 + (04CC((bArg02-9)<<1) + 0x16)` for 9..16; 0 if neither.
5. **Uninitialised / reused 030D stack argument (`wArg02`).** In `08E9` the
   second argument of `fn1E78_030D` is `[bp-4]`, never written by the function;
   in `0768` the same register-passed slot is the wait counter / scratch word.
   Reko models both as uninitialised.  Both are seeded `0x0000` for
   determinism (the callers of `fn1E78_030D` here ignore its outputs).
6. **`fn0800_08E9` DX threading.** Reko threads the DX register as
   `(dh from 030D's DX output, dl from 1E3C's DL output)`; the .asm never moves
   DX explicitly.  Reko's dataflow is reproduced (`dh_156`/`dl_67`) and the
   function returns Reko's `dx_134` (the original's AX/DX at `leave; ret`);
   `fn0800_0C71` discards the value.
7. **`bpOut` outputs.** Per part 1 / `seg133F.c` convention, the "saved-BP"
   outputs of `0768` and `09C2` and the frame-walk pointer of `0AA1` cannot be
   represented in the flat host model; they are written as `0x0000`
   ("not meaningful here").  Reko derives them from the mouse driver BP
   (`fn1206_0066`/`fn1206_0038` register image), which the PAL returns as 0.
8. **`fn0800_0AA1` return.** Reko returns `[bp_206]` (a frame-walk
   dereference); the port returns the raw BP-register output `bp_206` (0).
   `fn0800_0C71`/`fn0800_0BEC` use it only as an opaque frame pointer.
9. **Reko's phantom `bLoc06` (0619) / `bLoc04` comparison (0AA1).** Reko caches
   `[bp-4]` once, but the .asm re-reads the length byte before each branch and
   `fn1EDA_0A39` rewrites it; the code re-reads `bLoc04[0]` each time.
10. **`fn1EDA_0A39` destination in `0619`/`0AA1` is `[bp-4h]`** (`fp-6` in Reko,
    which is the same address because Reko's `fp = bp+2`), modelled as a
    4-byte `bLoc04` buffer.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0800_part2.c` -- exit 0, zero diagnostics
  (also clean with `-Wextra`).
* Reko-token grep (`Eq_[0-9]`, `<invalid>`, `<unknown>`, `SEQ(`, `CONVERT(`,
  `Mem[0-9]*[`, `segptr`) -- 0 hits.
* `nm` reports all 7 functions (`fn0800_0619` .. `fn0800_0AA1`) as `T`.

## part 5

Source: `src/seg0800_part5.c` -- functions 0800:184C, 19E1 (ascending offset).
Ground truth = `analysis/slices/0800/0800_<off>.asm`; frozen prototypes from
`src/seg0800.h`.

### Functions converted

| off  | prototype |
|---|---|
| 184C | `u16 fn0800_184C(void * dsOut)` |
| 19E1 | `u8 fn0800_19E1(u8 flag, u8 * label, u16 y, u16 x, u16 slot, u16 * dxOut, void * bpOut, void * dsOut)` |

### Hardware / dispatch sites

**None direct.** No `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port
instruction, no `__cli`/`__sti` and no `int 23h` occur in 184C..19E1.  The
mouse cursor is hidden/shown through `fn1206_0066` / `fn1206_0038` (segment
1206's INT 33h wrappers, replaced in `seg1206.c`); all other video/text and
record traffic goes through `fn1AB8_*` and `fn1EDA_0A39`, replaced there.

### Flat-model far-pointer / ABI adaptations

* **`cs:1830h..1848h`** button-label strings drawn by `fn1AB8_1D82` become
  `&g_seg0800[0x1830] .. &g_seg0800[0x1848]` (`fn0800_184C`).
* **`ds:541Eh + 1Ah*slot`** destination of the `fn1EDA_0A39(19h,...)` copy
  becomes `&g_dgroup[(u16)(0x541E + 0x001A * slot)]` (`fn0800_19E1`).
* **cdecl argument order** follows the last-pushed-first convention: e.g.
  `fn1AB8_1D82(ptr, 01CEh, X, &ch)` for the `push X; push 01CEh; push cs; push di`
  sequence, and `fn1AB8_1AF6(w4,w6,w8,wA)` for `push wA; push w8; push w6; push w4`.

### Uncertain sites / not recovered literally

1. **`fn0800_19E1` omitted frame arguments -- REPAIRED in this round:**
   prototype now carries `flag/label/y/x/slot` (the six word args, `ret 0Ch`);
   all 30 call sites pass the decoded pushes (see the sites).
2. **`fn0800_19E1` return value.** The .asm's `leave; ret 0Ch` returns whatever
   `call far 1206h:0038h` leaves in AL; the port returns `fn1206_0038`'s byte
   result.  Reko instead returns `SLICE(cx_765, byte, 8)` from an
   uninitialised `cx_765`, which is a register-dataflow artefact.
3. **`fn0800_19E1` `bpOut` dereference.** Reko stores
   `bpOut = *(bp_763)` (the frame-chain word at 0038's returned BP); the flat
   model cannot dereference a raw BP, so `*(u16 *)bpOut = 0` is written,
   matching part 1 / `seg133F.c` ("saved-BP output; not meaningful here").
4. **`fn0800_184C` `fn1206_01AC` dropped arguments.** The .asm stages six words
   (`push 1h; push 198h; push 16h; call 04CCh -> AX; push ax; push 1D1h;
   push 9Ch; push 1B4h`) for the 1206:01AC far call; the frozen prototype has
   only `siOut/esOut/dsOut`, so the words are dropped.  The pure
   `fn0800_04CC(16h)` call is kept to preserve the call order.
5. **`fn0800_184C` `dsOut`.** Reko assigns the DS selector from `fn1206_0038`;
   DS has no flat meaning, so `0` is stored (the 0038 port leaves its `dsOut`
   untouched, so `ds_517 == 0`).
6. **`fn0800_184C` `wArg02` shared slot.** The `[bp+0Ah]` word in
   `fn0800_19E1`'s sibling blocks is re-read after each store; kept literal.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0800_part5.c` -- exit 0, zero diagnostics
  (also clean with `-Wextra`).
* Reko-token grep (`Eq_[0-9]`, `<invalid>`, `<unknown>`, `SEQ(`, `CONVERT(`,
  `Mem[0-9]*[`, `segptr`) -- 0 hits.
* `nm` reports both functions (`fn0800_184C`, `fn0800_19E1`) as `T`.

## part 4

Source: `src/seg0800_part4.c` -- functions 0800:11EF, 1315, 149F, 166D
(ascending offset).  Ground truth = `analysis/slices/0800/0800_<off>.asm`;
frozen prototypes from `src/seg0800.h` (`analysis/summary/iface.tsv`).

### Functions converted

| off  | prototype |
|---|---|
| 11EF | `u16 fn0800_11EF(void)` |
| 1315 | `u8 fn0800_1315(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)` |
| 149F | `u16 fn0800_149F(void)` |
| 166D | `u16 fn0800_166D(void)` |

### Hardware / dispatch sites

**None direct.** No `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port
instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch occur in
11EF..166D.  The mouse cursor is hidden/shown through `fn1206_0066` /
`fn1206_0038` (segment 1206's INT 33h wrappers), the delay/keyboard through
`fn1E78_029C` / `fn1E78_030D` / `fn1E78_02FB` (segment 1E78, replaced there
with `pal_outport`/`pal_inport`/`bios_kbd_*`), and every text/record operation
through `fn1AB8_*` / `fn1EDA_*`.  All replaced in those segments, not here.
`fn0800_0D20` (the "Code Mission" dialog, not in this part's range) is called
by 11EF and is provided by its own part.

### Flat-model far-pointer / ABI adaptations

* **`cs:11D8h` / `cs:11E7h`.** 11EF passes `&g_seg0800[0x11D8]` to
  `fn0800_0D20` (the dialog label) and `&g_seg0800[0x11E7]` to
  `fn0C74_0000` / `fn1EDA_0FA2` (`{7,"RAD.DAT"}`).
* **`cs:147Fh` (149F) / `cs:164Dh` (166D).** The bit-table pointers of
  `fn1EDA_0CD4` become `&g_seg0800[0x147F]` / `&g_seg0800[0x164D]`.
* **Local buffers.** 11EF's `enter 18Ch` frame becomes `buf18C[100h]`
  (`[bp-018Ch]`, the `fn0800_0D20` `ptrArg0E` destination), `buf88[80h]`
  (`[bp-0088h]`, the RAD.DAT stream block) and `buf8[6]` (`[bp-0008h]`, the
  saved record head).  149F/166D become `buf10E[100h]` (`[bp-010Eh]`, the
  `fn1EDA_0B4F`/`fn1AB8_1D82` string) plus the `[bp-2h..bp-0Dh]` scalars.
* **Pass-through BP outputs.** `fn1206_0066`/`fn1206_0038` return the caller's
  BP; Reko's `bp_12 - N` / `bp_108 - N` uses are recovered as the local buffers
  at those bp offsets (as parts 2a/3/5 did for `fn133F_0137`).
* **`fn1EDA_0A39` argument order** follows the last-pushed-first convention:
  `fn1EDA_0A39(size, dest, src, &dxOut)`.  The first 11EF copy reuses the
  `ss:bp-018Ch` word pair that the (argument-less) `fn1AB8_10CE` call left on
  the original stack as the source pointer, so it is passed explicitly.
* **32-bit position counter `ds:598Eh`/`ds:5990h`** (`add word,1 ; adc word,0`)
  is `LG32(0x598E)`, initialised through two `LG16` writes to 0FFFFFFFFh.

### Uncertain sites / not recovered literally

1. **11EF loop-condition high word.** The .asm compares the `cwd` sign
   extension of `(byte ds:0002h) - 1` (`dx`) against `[5990h]` and `ax` against
   `[598Eh]`; Reko folded `dx` into `[5990h] != 0`, which differs when
   `ds:0002h == 0` (then `dx == FFFFh`).  The .asm is followed literally
   (`dx_320 = (ax_324 & 8000h) ? FFFFh : 0`).
2. **11EF `ax_324` / 1051 `al`.** `ax_324` is assigned at the end of every
   iteration but is read by `fn1EDA_1051` after a `break` taken *before* the
   assignment; the original then passes the stale AX (1051 overwrites AH, so
   AL is behaviourally dead).  Seeded `0` for a defined C value.
3. **11EF `al_235`.** After `fn1EDA_0FD0` the original leaves AL live across
   the register-preserving `fn1EDA_04A9` trap and passes it to
   `fn1EDA_1085`; the port captures it from `fn1EDA_0FD0`'s return (the port's
   04A9 returns 0 on the surviving path).  `fn1EDA_1085` ORs AL into `3F00h`,
   so AL is dead.
4. **`fn1E78_030D` stale `wArg02`.** The original calls 030D with no pushed
   argument (`retf`); the frozen prototype requires one.  Following Reko /
   parts 2/5, the value is taken from the preceding `fn1E78_029C` push
   (`0x01F4`) for the calls at 1609/17EC, and seeded `0x0000` for 166D's
   initial key-drain loop where Reko itself used an uninitialised local.
   `dx` is the `dxOut` of the preceding 029C (0).
5. **149F/166D table addressing.** 149F's table base is `FF06h` (effective
   DGROUP `0006h` + `row*100h` via 16-bit wrap; rows 1..12h read
   `006h,106h,..,1106h`); 166D's is `1106h` (`1206h..2306h`).  Both are indexed
   with the exact 16-bit wrap of the original (`(u16)((row << 8) ± const)`),
   not normalised.
6. **149F `wLoc02`/`wLoc06`.** After the initial `fn0800_1315` call the two
   origin words are incremented by 8 (to `32h`/`72h`); Reko folded them into
   the 1D82 constants (`31h`/`71h` and `32h`/`72h`).  The live locals are kept.
7. **`fn0800_0D20` argument mapping.** 11EF's stack is reused across the two
   `fn1AB8_10CE` calls; the frozen prototype resolves to
   `(cs:11D8h, 0A0h, 10CE/2+68h, 8Eh, 10CE/2-68h, bp-018Ch)` (Reko's order).
8. **Returns.** 11EF/149F/166D return the dropped DGROUP selector (0); 1315
   returns Reko's `0x00`.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0800_part4.c` -- exit 0, zero diagnostics
  (also clean with `-Wall -Wextra`).
* Reko-token grep (`Eq_[0-9]`, `<invalid>`, `<unknown>`, `SEQ(`, `CONVERT(`,
  `Mem[0-9]*[`, `segptr`) -- 0 hits.
* `nm` reports all four functions (`fn0800_11EF`, `fn0800_1315`, `fn0800_149F`,
  `fn0800_166D`) as `T`.

## part 6

Source: `src/seg0800_part6.c` -- functions 0800:1D55, 1E3F, 2004
(ascending offset).  Ground truth = `analysis/slices/0800/0800_<off>.asm`;
frozen prototypes from `src/seg0800.h` (`analysis/summary/iface.tsv`).

### Functions converted

| off  | prototype |
|---|---|
| 1D55 | `u8 fn0800_1D55(u16 * dxOut, void * bpOut, u16 * dsOut)` |
| 1E3F | `u16 fn0800_1E3F(s16 dx, u16 * dsOut)` |
| 2004 | `u16 fn0800_2004(void)` |

### Hardware / dispatch sites

**None direct.**  No `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port
instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch occur in
1D55..2004.  The mouse cursor/position/button is polled through segment 1206
(`fn1206_0094` / `fn1206_0066` / `fn1206_015B`), the keyboard and the PIT
delay through segment 1E78 (`fn1E78_02FB` / `fn1E78_030D` / `fn1E78_029C`),
the text/drawing primitives through segment 1AB8 (`fn1AB8_10CE` / `14F4` /
`1536` / `1C32` / `1D82`) and the bit test through segment 1EDA
(`fn1EDA_0CD4`).  All of those are replaced in their own segments
(`seg1206.c`, `seg1E78.c`, `seg1AB8_*.c`, `seg1EDA_part4b.c`), so no PAL call
is issued here.

### Flat-model far-pointer / ABI adaptations

* **DGROUP label tables.** 1E3F stages `ds:2306h + (row<<8)` as
  `&g_dgroup[(u16)((row << 8) + 0x2306)]`; 2004 stages `ds:3706h + (row<<8)`
  as `&g_dgroup[(u16)((row << 8) + 0x3706)]`.  Both are `push ds ; push di`
  far pointers, i.e. DGROUP-relative, and stay inside `_DATA` (max offset
  0x4C06 < 0x5390).
* **0800-image bit tables / label pointers.** `cs:1DE0h` / `cs:1E1Fh` (1E3F)
  and `cs:1FB5h` / `cs:1FE4h` (2004) become `&g_seg0800[0x1DE0]` /
  `[0x1E1F]` / `[0x1FB5]` / `[0x1FE4]`.  The `fn0800_19E1` label pointers
  become `&g_seg0800[0x1E00]` (1E3F) and `&g_seg0800[0x1FD5]` (2004).
* **DGROUP scalars.** `53D8h` (selected flag) and `0002h` (deferred action
  byte) are `LG8(0x53D8)` / `LG8(0x0002)`.
* **1206 register outputs.** The INT 33h wrappers expose their register
  outputs as pointer parameters.  In 1D55 the poll call maps
  `fn1206_0094(&wLoc08, &wLoc06, &wLoc04)` (arg1 = dxOut = cursor y → `DX`,
  arg2 = bpOut = cursor x → `CX`, arg3 = dsOut = button state → `BX`),
  matching the asm push order `ss:bp-4 / ss:bp-6 / ss:bp-8` (last pushed =
  first argument) and the 1206:0094 bodies.
* **cdecl argument order** follows the last-pushed-first convention
  throughout: e.g. `fn1AB8_1D82(ptr, y, x, &ch)` for
  `push x ; push y ; push ds ; push di`, and
  `fn0800_1315(w8, w4, w6, w2)` for `push [bp-2h] ; [bp-6h] ; [bp-4h] ; [bp-8h]`.

### Uncertain sites / not recovered literally

1. **`fn0800_1D55` poll-loop locals seeded 0.**  `[bp-4h]`/`[bp-6h]`/`[bp-8h]`
   are written by `fn1206_0094` only when a mouse driver is present; the
   original reads `[bp-4h]` after the first call regardless.  They are seeded
   `0` so a missing driver terminates the `do..while` deterministically.
2. **`fn0800_1D55` signed edge comparisons.**  The `.asm` compares the edge
   tables with `jge`/`jle` (signed); the port casts both operands to `s16`
   (`(s16)LG16(...)`, `(s16)wLoc06`/`wLoc08`).  Reko emitted unsigned-looking
   `>=`/`<=`, so the signed form is recovered from the machine code.
3. **`fn0800_1D55` register outputs.**  The only caller (fn0800_3D9D:3ED9)
   reads AL.  Reko's `dxOut` is 1206:0094's cursor-y output, threaded here as
   `*dxOut = wLoc08`; `bpOut` is the saved caller-BP frame word (`[bp+0]`,
   not representable in the flat model) and `dsOut` is the dropped DGROUP
   selector, both written `0` (part 1 / `seg133F.c` convention).
4. **`fn0800_1E3F` / `fn0800_2004` `fn1EDA_0CD4` polarity.**  The `.asm`
   branches are `jz` after the `test`, i.e. the taken path corresponds to
   `0CD4 != 0` (tested bit CLEAR, see `seg1EDA_part4b.c`).  The loop sites
   therefore select attribute `0Bh` when `fn1EDA_0CD4(...) != 0` and `0Ah`
   when it is `0` (the `!fn1EDA_0CD4 -> 0Ah` form used by part 4 is
   equivalent); the key-test sites proceed only when `fn1EDA_0CD4(...) == 0`
   (bit SET).  Reko's `!fn1EDA_0CD4` inversion is not followed blindly -- the
   machine-code branch direction was re-checked against the `test`-sets-ZF
   implementation.
5. **`fn1EDA_0CD4` `esOut` storage width.**  The port's `fn1EDA_0CD4` writes
   a full pointer (`*(u8 **)esOut = ptrArg04`), so the local `esOut` slots
   here are declared `u8 *` (unlike parts 2/4 which use `u16`); the value is
   the dropped selector and unused.
6. **`fn1E78_030D` stale `wArg02`.**  The original calls 030D with no pushed
   argument (`retf`), so the frozen prototype's `wArg02` is a stale word,
   seeded `0` here (part 2/4 convention).  The drain loop re-threads the
   incoming `dx` parameter through `dxOut` exactly as Reko's dataflow; the
   later 030D calls use the preceding `fn0800_19E1`/`fn1206_015B` `dx_251`.
7. **`fn0800_19E1` dropped arguments.**  Both 1E3F and 2004 stage the six
   words `5h / 140h / 14Ah / cs:label / 0h|1h`; the frozen `fn0800_19E1`
   prototype carries only the label pointer plus its register outputs (see
   part 5 note 1), so the coordinate/flag words are dropped and the call is
   `fn0800_19E1(&g_seg0800[label], &dx, &bp, &ds)`.
8. **`bpOut` register artifacts.**  `fn1206_0066` / `fn1206_015B` /
   `fn0800_19E1` BP outputs are pass-through caller-frame pointers with no
   flat meaning; the locals are seeded `0`.  `fn0800_1E3F`'s return is
   Reko's `(ss->*bp_382).w0000` (saved BP frame word); it is returned as `0`.
9. **`fn0800_2004` return.**  Reko returns `fn0800_1E3F`'s `dsOut`
   (the dropped DGROUP selector); the call discards it, so `ds_381` (== 0)
   is returned.
10. **Dead frame words.**  `fn0800_1D55`'s `[bp-2h]` / `[bp-0Ah]` and
   `fn0800_1E3F`'s `[bp-0Ah]` word hold no live value in the recovered
   control flow and are not modelled.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0800_part6.c` -- exit 0, zero diagnostics
  (also clean with `-Wall -Wextra`).
* Reko-token grep (`Eq_[0-9]`, `<invalid>`, `<unknown>`, `SEQ(`, `CONVERT(`,
  `Mem[0-9]*[`, `segptr`, `Eq_17`) -- 0 hits.
* `nm` reports all three functions (`fn0800_1D55`, `fn0800_1E3F`,
  `fn0800_2004`) as `T`.
* Frozen-prototype cross-check (`gcc -Wall` on a TU assigning the three
  `seg0800.h` prototypes to matching function pointers) -- exit 0.

## part 3

Source: `src/seg0800_part3.c` -- functions 0800:0B42, 0BEC, 0C71, 0D20
(ascending offset).  Ground truth = `analysis/slices/0800/0800_<off>.asm`;
frozen prototypes from `src/seg0800.h` (`analysis/summary/iface.tsv`).

### Functions converted

| off  | prototype |
|---|---|
| 0B42 | `u16 fn0800_0B42(void * dsOut)` |
| 0BEC | `u16 fn0800_0BEC(void)` |
| 0C71 | `s16 fn0800_0C71(void * bpOut, u16 * dsOut)` |
| 0D20 | `u16 fn0800_0D20(u8 * ptrArg02, u16 wArg06, u16 wArg08, u16 wArg0A, u16 wArg0C, u8 * ptrArg0E)` |

0B42 is the `TIME:` clock redraw, 0BEC resets the time state, 0C71 is the
clock-tick handler (divide DGROUP:58D8h by 60 with `fn1EDA_098A`, repaint on
change, animate while zero), and 0D20 is the "Code Mission" keypad dialog
(copy the prompt, open RAD.MEM via `fn1EDA_04F5`/`0565`/`0896`/`086C`/`05BF`,
allocate the screen buffer with `fn1EDA_023F`, run the 5000/10000-tick cursor
blink loop, then free the buffer with `fn1EDA_0254`).

### Hardware / dispatch sites

**None direct.** No `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port
instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch occur in
0B42..0D20.  Mouse cursor hide/show goes through `fn1206_0066` / `fn1206_0038`
(segment 1206's INT 33h wrappers, replaced in `seg1206.c`); keyboard polling
through `fn1E78_02FB` / `fn1E78_030D` (replaced in `seg1E78.c`); every
text/record/heap operation through `fn1AB8_*` / `fn1EDA_*` / `fn0C74_*`.

### Segment data referenced

* `cs:0B40h` = {1,"0"} (single-digit time pad, 0B42).
* `cs:0BE1h` = {10,"TIME:00.00"} (0BEC).
* `cs:0D07h` = {7,"RAD.MEM"} (0D20 stream name).
* `cs:0D0Fh` = {2,"AA"}, `cs:0D12h` = {4,"AAAA"}, `cs:0D17h` = {1,"A"},
  `cs:0D19h` = {6,"AAAAAA"} (0D20 field-label records).

### Flat-model far-pointer / ABI adaptations

* **DGROUP far pointers** are read as the two literal words: 0B42's
  `fn0C74_004B(LG32(0x58CC), buf)`, 0C71's `fn1EDA_098A(..., LG32(0x58D8), ...)`.
* **`fn1EDA_098A` output ABI.** Its `dsOut` is `void *` and the port writes a
  full host pointer through it (`*(void **)dsOut`), so 0C71 passes
  `void *ds_23` / `void *ds_110`, not a `u16`.
* **`fn1EDA_0254` argument mapping.** The .asm pushes segment, offset, size;
  the frozen prototype's real arguments are `wArg04` (size) and `ptrArg06`
  (block), so the call is `fn1EDA_0254(0, 0, ax_181, block, &dx, &ds)` -- the
  same convention as part 1's 03F8.
* **`fn1EDA_023F` argument mapping.** The single pushed word is the size; per
  part 1 it is placed in `wArg04`: `fn1EDA_023F(0, 0, ax_181, &ds_200)`.
* **`fn1206_0038`'s BP output.** Reko models 0B42's return as
  `ss->*bp_212` (the caller's saved BP read through the 0038 BP output).  The
  PAL materialises that BP as 0, so the dereference has no flat-C meaning;
  0B42 returns 0 (both surviving callers ignore it).
* **`fn1206_0066`/`fn1206_0038` BP pass-through.** In 0C71 and 0D20 the
  original reuses the mouse BP output (`bp_122 - 4`, `bp_206`) as pointers to
  the caller's own stack locals.  As in parts 2/4/5, those are recovered as
  the real local buffers at the documented bp offsets (`bLoc06`, `abLoc0100`,
  ...) instead of dereferencing the returned BP.
* **`fn1EDA_023F` block far pointer.** The block is kept as the u32
  `dx_ax_1868 = (segment << 16) | offset` and passed as
  `(u8 *)(uintptr_t)dx_ax_1868` to `fn1AB8_1E6B` / `fn1AB8_13D7` /
  `fn1EDA_0254`; the asm's two stores at `[bp-0104h]`/`[bp-0102h]` are this
  value's two halves.
* **`fn1EDA_0A39` order** follows the last-pushed-first convention:
  `fn1EDA_0A39(size, dest, src, &dxOut)`.
* **0D20 frame.** `enter 518h` becomes the documented local buffers
  `abLoc0100[100h]`, `bLoc0206[100h]`, `abStream0310[100h]`, `bLoc0318[8]`,
  `abLoc0418[100h]`, `abLoc0518[100h]` plus the `[bp-0106h]`..`[bp-0210h]`
  scalars, matching the .asm offsets.

### Uncertain sites / not recovered literally

1. **Register-output / saved-BP artifacts.** `bpOut` in 0C71 and the implicit
   BP return of 0B42 are Reko register-dataflow artifacts with no flat-C
   equivalent (the PAL's 1206 mouse frame is zero-initialised, so the BP word
   is 0).  Following part 1 / `seg133F.c`, `*(u16 *)bpOut = 0` is written and
   0B42 returns 0; the surviving callers ignore both (`0BEC`/`0C71` reload
   their locals from DGROUP immediately after each call).
2. **`dsOut` (0B42 semantics, 0C71).** DS has no flat meaning; `0` is stored.
   0BEC/0D20 return the dropped DGROUP selector as `0`.
3. **`fn1E78_030D` stale `dx`/`wArg02`.** The .asm calls 030D with no pushed
   argument (`retf`); the frozen prototype requires `dx` and `wArg02`.
   Following Reko (and part 4's finding), the first 0D20 call uses
   `dx = dx_684` (the preceding `fn1AB8_1AF6` DX output) and `wArg02 = 0x000A`
   (the constant the `push 0Ah; call 1C32h` left in the register/stack slot);
   the second uses `dx = dx_696` (first 030D's DX output) and
   `wArg02 = ax_693` (first 030D's return).
4. **`fn1EDA_098A` `wArg00`/`wArg02`.** The .asm passes no stack words (the
   function reads only registers); the frozen prototype's two word slots are
   only consumed by the divide-by-zero fatal path, which cannot be taken with
   divisor 3Ch, so they are seeded `0`.
5. **`fn1EDA_0A1F`/`0AAC`/`0A39` source pointers reused from the stack.** The
   Turbo C "stack-reuse" calls in 0B42 and 0D20 leave a far pointer from a
   preceding callee on the stack and reuse it as the next call's argument.
   Reko recovered the values (`ptrLoc010A_234`, `ptrLoc051E_*`); they are
   passed explicitly here (the far pointer the caller pushed for the
   immediately preceding call), which reproduces the original stack contents.
6. **0D20 branch conditions.** The flag tests
   `cmp dx,bx ; jl/jg ; cmp ax,cx ; jnc` in the printable-code and left-arrow
   branches are reproduced with the full signed/unsigned logic, not Reko's
   folded `ax < width` comparison (which differs when `fn1AB8_10A8()` has the
   sign bit set).
7. **`fn1AB8_10A8` argument evaluation order.** The original calls the getter
   twice around the `ax_317 ± 6` arithmetic before `fn1AB8_1AF6`; the two
   results are captured in source order (`a3` first, `a4` second) so the call
   sequence is preserved despite C's unspecified argument order.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0800_part3.c` -- exit 0, zero diagnostics.
* Reko-token grep (`Eq_[0-9]`, `<invalid>`, `<unknown>`, `SEQ(`, `CONVERT(`,
  `Mem[0-9]*[`, `segptr`) -- 0 hits.
* `nm` reports all four functions (`fn0800_0B42` .. `fn0800_0D20`) as `T`.
* Note: `-Wextra` additionally reports `bLoc0209 <= 0xFF` as always-true
  (`u8`); that comparison is the literal `cmp al,0FFh ; ja` of the .asm and is
  kept for fidelity.

## part 7

Source: `src/seg0800_part7.c` -- function 0800:21E7.  Ground truth =
`analysis/slices/0800/0800_21E7.asm`; frozen prototype from `src/seg0800.h`
(`analysis/summary/iface.tsv`, note: *returns DGROUP selector (dropped in flat
model); Eq_N return -> u16; dropped Eq_17 ds*).

### Functions converted

| off  | prototype |
|---|---|
| 21E7 | `u16 fn0800_21E7(void)` |

The function paints the mission-selection screen: `fn1AB8_1536` /
`fn1AB8_14F4` / `fn0800_1315` / `fn1AB8_1C32` set up the frame, the ds:0002h
mode byte selects the banner (`> 1Eh` draws the "Version enregistree : N
tableaux" line built in the two frame buffers), and the eight button slots are
drawn with `fn0800_19E1` using the mode/record-dependent `cs:` labels.

### Hardware / dispatch sites

**None direct.** No `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port
instruction, no `__cli`/`__sti` and no `int 23h` occur in 21E7.  All video text
goes through `fn1AB8_1D82` / `fn1AB8_1C32` / `fn1AB8_*`; all string and number
work through `fn1EDA_0A1F` / `fn1EDA_0AAC` (length-prefixed copy/append) and
`fn0C74_004B` (number formatting), replaced in those segments.

### Flat-model far-pointer / ABI adaptations

* The 13 embedded labels resolve to `&g_seg0800[0xHHHH]`; verified against the
  length-prefixed strings in `data/segments/seg0800.bin`: 2155h `{3,"RAD"}`,
  2159h `{22,"Version enregistree : "}`, 2170h `{9," tableaux"}`,
  217Ah `{3,"F1:"}`, 217Eh `{1," "}`, 2180h `{11,"  F1:JEU   "}`,
  218Ch `{10,"F2:MISSION"}`, 2197h `{10,"  F3:DEMO "}`,
  21A2h `{10,"F4:SILENCE"}`, 21ADh `{11,"  F5:EDIT  "}`,
  21B9h `{11,"  F5:INFO  "}`, 21C5h `{10,"F6:NOTICE "}`,
  21D0h `{22,"   F7:RETOUR AU DOS   "}`.
* `ds:5ED6h` (the slot-1 runtime string appended to "F1:") becomes
  `&g_dgroup[0x5ED6]`; the banner's number source `ds:5CB2h` becomes
  `LG8(0x5CB2)` (both DGROUP _BSS).
* **`fn1EDA_0A1F` / `fn1EDA_0AAC` stack convention.**  The `.asm` functions end
  in `retf 4`: each consumes only the last-pushed far source and leaves the
  first-pushed far destination on the stack.  In 21E7 that leftover
  destination is exactly the first argument of the following `fn1AB8_1D82`
  (222Ah block: `ss:bp-0200h`) or `fn0800_19E1` (2281h block:
  `ss:bp-0100h`).  The frozen prototypes take both pointers explicitly
  (`(src, dest)`), which reproduces the copies and lets the following call take
  the buffer directly, matching Reko (`ptrLoc020A_611` / `ptrLoc020C_636`).
* Frame: `enter 200h,0h` -> `buf200[0x100]` (`[bp-0200h]`) and `buf100[0x100]`
  (`[bp-0100h]`); the argument staging Reko models below SP becomes the direct
  C call arguments.

### Uncertain sites / not recovered literally

1. **`fn0800_19E1` dropped frame arguments (main loss).** Every call in 21E7
   supplies six words (`ret 0Ch`): `[bp+04h]` flag, `[bp+06h]/[bp+08h]` far
   label pointer, `[bp+0Ah]` y/coordinate, `[bp+0Ch]` x/coordinate,
   `[bp+0Eh]` slot index.  The frozen prototype carries only `ptrArg04`, so the
   flag, coordinates and slot index are dropped at all ten call sites; only the
   label pointer is passed.  The `.asm` values are recorded in the source
   comments: slot indices 1..7 (the 2281h/22B4h pair both being slot 1), edge
   coordinates `0B4h/0F0h/190h/0E6h/118h/14Ah`, and flags 0/1.  `fn0800_19E1`
   itself seeds the missing arguments 0 (`src/seg0800_part5.c`), so the flag
   distinction is unobservable until the prototype is repaired (same class of
   loss as parts 5/6).
2. **`fn0800_19E1` branch halves.**  The 22F1h (flag 0) and 2305h (flag 1)
   arms now issue identical calls (`cs:21A2h`); the branch and both call sites
   are kept so the control flow (the `ds:58B0h` test) survives verbatim.
3. **DGROUP selectors.**  The `dsOut` selectors returned by `fn1AB8_1536` and
   each `fn0800_19E1` (`ds_102`, `ds_234` .. `ds_572`) are dropped in the flat
   model; `fn0800_21E7` returns `ds_572` (the last selector) as the frozen
   prototype requires.  All DGROUP reads use the literal offsets
   (`LG8(0x0002)`, `LG16(0x5990)`, `LG16(0x598E)`, `LG8(0x58B0)`,
   `LG8(0x5CB2)`) exactly as the `.asm`.
4. **`fn0800_19E1` `bpOut` outputs** are frame-pointer artifacts of
   segment 1206; per parts 5/6 they are address-taken and left at their seeded
   0 ("not meaningful here").

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0800_part7.c` -- exit 0, zero diagnostics
  (also clean with `-Wall -Wextra`).
* Reko-token grep (`Eq_[0-9]`, `<invalid>`, `<unknown>`, `SEQ(`, `CONVERT(`,
  `Mem[0-9]*[`, `segptr`) -- 0 hits.
* `nm` reports `fn0800_21E7` as `T`, matching the frozen prototype exactly.

## part 8

Source: `src/seg0800_part8.c` -- function 0800:2401 only.  Ground truth =
`analysis/slices/0800/0800_2401.asm`; frozen prototype from `src/seg0800.h`
(`analysis/summary/iface.tsv`).

### Functions converted

| off  | prototype |
|---|---|
| 2401 | `u16 fn0800_2401(void)` |

2401 is the RAD.HLP help/menu screen.  It probes `Rad.hlp`
(`fn0C74_0000(cs:236Ah)`), opens the RAD.HLP stream (`cs:2372h`), seeks to
record `[598Eh]:[5990h]` and reads one 0x100-byte record; unless the record's
second byte is 0x20 (`[bp-0FFh]` = `abRecord[1]`) it hides the cursor, paints
the frame (`fn0800_1315` + the `cs:237A/238E/23AC/23C3` banners), waits for a
key, copies the mission parameters from `ds:5CDEh`, blits the 0x1D x 0x11
mission grid from `ds:5CE0h` through the `0x5992` far-pointer table, compares
the selected record with `cs:23E1h` (`{6,"NONAME"}`), draws the menu banner
(`cs:23E8h`), runs `fn0800_0619`/`fn0800_0BEC`, and then executes the byte
command loop (`;`, `<`, `=`, `H`, `K`, `M`, `P`, Esc) over the loaded record
until `fn0800_0877` completes or `ds:58B3h` is set.

### Hardware / dispatch sites

**None direct.**  No `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port
instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch occur in
2401.  Every BIOS/DOS/hardware service reached from here is owned by the callee
segments and replaced there: segment 0C74 (menus and the
`fn0C74_0000`/`51AA`/`51B2`/`522C`/`5258`/`542B`/`54F0`/`54B1` handlers),
1EDA (DOS RAD.HLP stream layer `0FA2`/`0FD0`/`1123`/`1085`/`1051`/`0A39`/`0B24`),
1AB8 (video/text `10CE`/`1315`/`1536`/`14F4`/`1C32`/`1D82`/`13D7`), 1E78
(keyboard/PIT `02FB`/`030D`) and 1206 (mouse cursor `0066`/`0038`/`015B`, INT 33h
through `fn1E5F_000B`).

### Frame / flat-model far pointers

* `enter 282h` is recovered as three local buffers at the exact asm offsets:
  `abStream[0x80]` at `[bp-0x180]` (the RAD.HLP stream block),
  `bFE7F` at `[bp-0x181]` (the command-queue read index) and
  `abRecord[0x100]` at `[bp-0x100]` (the record read from RAD.HLP, later the
  command queue).  `[bp-0x282]`..`[bp-0x182]` is unused frame padding.
* `cs:236Ah` = `{7,"Rad.hlp"}`, `cs:2372h` = `{7,"RAD.HLP"}`, `cs:237Ah` =
  `{19,"ENTREE EN MODE AUTO"}`, `cs:238Eh` = `{29,"Pressez une touche
  quelconque"}`, `cs:23ACh` = `{22,"pour l'action suivante"}`, `cs:23C3h` =
  `{29,"ou ESC pour reprendre la main"}`, `cs:23E1h` = `{6,"NONAME"}` and
  `cs:23E8h` = `{24,"MODE AUTO (ESC = RETOUR)"}`; all are passed as
  `&g_seg0800[0x....]`.
* The mission-grid block is `LG32(0x5992 + (byte<<2))` exactly as the original
  `les di,[di+5992h]`; `DGROUP:5ECEh`/`5ED6h` copies use `&g_dgroup[...]`.
* The 0x100-byte record read by `fn1EDA_1085` is the caller's `[bp-0x100h]`
  data buffer (1091 loads it from `[bp+6h]`; the stream block from `[bp+0Ah]`).
  The frozen `fn1EDA_1085` prototype cannot carry that dropped far pointer, so
  the call site -- as `src/seg1EDA_shared.h` requires ("callers outside chunk 6
  must point it at their buffer before invoking the record-I/O helpers") --
  saves `g_1EDA_io_buffer`, points it at `abRecord`, calls `fn1EDA_1085`, and
  restores it.  Unlike part 1/4 (whose buffers already are `DGROUP:5CB4h`), this
  is a stack buffer, so the save/restore is required.
* `fn0800_09C2`'s and `fn0C74_*`'s `bpOut`/`dsOut` register outputs are dead;
  they are kept in distinct Reko-named locals and passed through.

### Uncertain sites / not recovered literally

1. **`fn1EDA_0B24` branch direction (main loss/divergence).**  The asm is
   `call far 1EDAh:0B24h ; jnz 25B2h` (verified at file offset 0x25A1: `75 0F`),
   so the reset at `l0800_25A3` (set `[598Eh]:[5990h]` = 1:0) runs when the
   selected record **equals** `cs:23E1h`.  Reko emitted the inverted
   `if (!fn1EDA_0B24(...))` here (RAD_0800.c:2236), contradicting its own
   correct uses of the same return in `fn0800_0619`/`fn0800_11EF` and the port's
   `fn1EDA_0B24` (which returns nonzero on equality, 0 otherwise -- verified
   against part 2's `0619` and part 4's `11EF`).  The `.asm` is followed:
   `if (fn1EDA_0B24(...) != 0x00) { reset; return; }`.  Same inversion exists
   in Reko's `fn0800_2C0C` site (not this part).
2. **`dx_1493` (0C74:0000 `dxOut`).**  `fn0C74_0000` never writes its `dxOut`
   (it ends `mov al,[bp-1h] ; leave ; retf 4h`), so Reko's `out dx_1493` is a
   dataflow artifact.  It is seeded 0 and threaded through the two
   `fn1E78_030D` drain calls (`fn1E78_030D` has no stack argument in the
   original, so `wArg02` is seeded 0), the same convention as parts 2/4.
3. **`fn1E78_030D` stale `wArg02`.**  In the loop's `l0800_267B` call the
   original pushes nothing (`retf`); Reko's `sp_1436 - 2` slot is seeded 0.
   The drain calls at `l0800_2416`/`l0800_264E` likewise use 0.
4. **`fn0C74_06B7` result.**  Reko nests the return as the dropped `ds`
   argument of the following `fn1206_0038`, which the frozen prototype cannot
   carry; the call is kept for its side effects (it paints the mission name at
   `ds:58B4h`/`58B8h` etc.) and its result discarded.
5. **`ds` threading.**  DS has no flat meaning.  Every `out ds`/`ds_N`
   register output is a write-only local; the `ds_796` result of
   `fn0800_031B` is copied to `ds` as Reko does.  No call passes DS as input.
6. **`bp_1428` frame pointer.**  The mouse/video wrappers return the caller's BP
   (`bp_1428`), which Reko uses as the base for `(ss->*bp_1428).bFE7F`,
   `[bp_1428-0x0181]` and `[bp_1428-0x0100+idx]`.  As in parts 2/4/5, those are
   recovered directly as the `bFE7F` / `abRecord[]` locals; `bp_1428` is kept as
   an address-taken `u16` output only.
7. **Return value.**  `leave; ret` returns the dropped DGROUP selector; the port
   returns 0 (the single caller, `fn0800_2C0C` at 2F51, discards it).

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0800_part8.c` -- exit 0, zero diagnostics
  (also clean with `-Wall -Wextra`).
* Reko-token grep (`Eq_[0-9]`, `<invalid>`, `<unknown>`, `SEQ(`, `CONVERT(`,
  `Mem[0-9]*[`, `segptr`) -- 0 hits.
* `nm` reports `fn0800_2401` as `T`, matching the frozen prototype exactly
  (`u16 fn0800_2401(void)`).

## part 12

Source: `src/seg0800_part12.c` -- functions 0800:36E6, 3850, 391E, 3BF2,
3C72 (ascending offset).  Ground truth = `analysis/slices/0800/0800_<off>.asm`;
frozen prototypes from `src/seg0800.h` (`analysis/summary/iface.tsv`).

### Functions converted

| off  | prototype |
|---|---|
| 36E6 | `void fn0800_36E6(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)` |
| 3850 | `u8 fn0800_3850(u8 * chOut, u16 * bpOut, u16 * dsOut)` |
| 391E | `u16 fn0800_391E(void)` |
| 3BF2 | `void fn0800_3BF2(void * ptrArg04)` |
| 3C72 | `u16 fn0800_3C72(void * ptrArg04, s16 * dxOut)` |

36E6 draws the twelve bevels of a button box with `fn1AB8_1AF6` (three colour
groups of four, `fn1AB8_1C32(0Bh)` between them); 3850 hit-tests the mouse
cursor (`fn1206_0094`) against the slot edge tables (53E2h/53FEh/53F0h/540Ch)
and returns the `4D07h + index` key byte; 391E is the "SUITE" module browser
(open RAD.DOC via `fn1EDA_04F5`/`0565`, list rows 1..14h through
`fn1EDA_0896`/`081A`/`1D82`, modal key/mouse loop with `fn1E78_02FB`/`030D`,
`fn1206_015B`/`0038`/`0066`, `fn1EDA_0918`/`0CD4`/`1384`/`05BF/04A9`, selection
code 53h/46h); 3BF2 and 3C72 convert the `fn1E5F_00A2` clock fields
(hours/minutes/seconds/hundredths) to a 32-bit interval with
`fn1EDA_096F` + `1770h`/`64h` scaling.

### Hardware / dispatch sites

**None direct.**  No `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port
instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch occur in
36E6..3C72.  The mouse cursor is polled/hidden/shown through segment 1206
(`fn1206_0094`/`0066`/`0038`/`015B`, INT 33h wrappers replaced in
`seg1206.c`); the keyboard and PIT delay through segment 1E78
(`fn1E78_02FB`/`030D`/`029C`, replaced in `seg1E78.c`); all text/record/stream
work through segment 1AB8 and segment 1EDA (replaced there); and the
system-clock read of 3BF2/3C72 goes through **fn1E5F_00A2** (1E5F:00A2), whose
INT 21h AH=2Ch is already replaced by `msdos_get_system_time` in
`src/seg1E5F.c`.  No PAL call is issued in this file.

### Segment / DGROUP data referenced

* `cs:38E0h` = `{7,"RAD.DOC"}` (391E stream name), `cs:38E8h` =
  `{11," S : SUITE "}` and `cs:38F4h` = `{9," F : FIN "}` (button labels),
  `cs:38FEh` (bit table for `fn1EDA_0CD4`); verified against
  `data/segments/seg0800.bin`.
* `ds:4D07h` (slot key table: [1]=53h 'S', [2]=46h 'F'), `ds:4D06h`
  (function-key code for `fn1AB8_1C32`), `ds:53D2h` (pending key code),
  `ds:53E2h/53FEh/53F0h/540Ch` (slot edges) and `ds:53E4h/53F2h/5400h/540Eh`
  (selection box) -- all via `LG8`/`LG16`.

### Flat-model far-pointer / ABI adaptations

* **391E frame.**  `enter 210h,0h` becomes the documented locals
  `abStream[0x100]` (`[bp-0110h]`, the RAD.DOC stream block) and
  `abBuf[0x100]` (`[bp-0210h]`, the line buffer), matching the asm offsets.
* **Stack-reuse far pointer.**  At 0800:3A5D the original pushes the block far
  pointer `ss:bp-0110h` once; `fn1EDA_0896` (`retf 6`) consumes only the size
  and destination words, leaving the block pointer as `fn1EDA_081A`'s
  (`retf 4`) argument.  The flat code passes `abStream` to both calls
  explicitly (`fn1EDA_081A(fn1EDA_0896(0FFh, abBuf, abStream), abStream)`).
* **3BF2/3C72 `fn1E5F_00A2` output slots.**  The register handles
  (`bp-6h..bp-0Ch`) become ordinary `u16` locals; 3BF2 passes
  `(base+6, base+4, base+2, base)` and reads the four clock fields back into
  `w0/w2/w4/w6`, 3C72 passes `(&wLoc0C, &wLoc0A, &wLoc08, &wLoc06)`.
* **32-bit `fn1EDA_096F` + carry chain.**  Reproduced exactly with `u32`
  accumulators (low 16 bits + high 16 bits, `adc` = 32-bit wrap); `imul`'s
  discarded high half is modelled by `(u16)` truncation of the 16-bit product.
* **Embedded far pointers** (`push cs ; push di`) resolve to
  `&g_seg0800[...]`.

### Uncertain sites / not recovered literally

1. **`fn0800_3850` register outputs.**  `chOut` is Reko's `<invalid>` CH
   register slice; `bpOut` is the original's pushed caller BP (the caller
   pushes `bp` before `call 3850h`, and 3850 returns it via `[bp+0]`); neither
   has a flat-C meaning, so following part 1 / `seg133F.c` `*chOut = 0`,
   `*bpOut = 0` and the dropped DGROUP selector `*dsOut = 0` are written.  The
   only caller (391E:3B31) uses AL only.
2. **`fn0800_0850`/`fn0800_3850` poll locals seeded 0.**  `[bp-4h]`/`[bp-6h]`/
   `[bp-8h]` are written by `fn1206_0094` only when a mouse driver is present;
   the original reads `[bp-4h]` after the first call regardless, so they are
   seeded `0` for a deterministic poll exit (same as parts 1/6).
3. **`fn0800_3850` signed edge tests.**  The asm uses `jge`/`jle` after the
   edge comparisons, so both operands are cast to `s16` (part-6 convention),
   not Reko's unsigned-looking `>=`/`<=`.
4. **`fn1EDA_04A9` "preserved AL" tests.**  In 391E the pattern
   `call 0918h ; call 04A9h ; or al,al ; jz/jnz` tests AL, which the
   register-preserving `retf` of 04A9 leaves untouched -- i.e. the result of
   the preceding `fn1EDA_0918`.  The flat `fn1EDA_04A9` returns 0 on the
   surviving path, so the code captures `0918`'s return first and then calls
   `04A9` (part-4 convention).  The four `wn`/`tn` words of `04A9` are seeded
   `0x0000` (only the never-returning fatal path reads them).
5. **`fn1EDA_0918` `ch` argument.**  The original passes the block far pointer
   on the stack; the `ch` register argument is Reko dataflow.  For the first
   call (3A9B) the asm's CH is the `fn1AB8_1D82` `chOut` of the last row, so
   it is threaded (`ch_412`); for the two later calls (3B38, 3B84) Reko's
   `ch_652`/`ch_760` come from an undefined CX slice, so `0` is passed (the
   value only feeds the refill path of `fn1EDA_079A` via CH).
6. **`fn1E78_030D` stale `wArg02`.**  The original calls 030D with no pushed
   argument (`retf`), so the frozen prototype's `wArg02` is a stale word,
   seeded `0x0000` (parts 2/4/6 convention); the `dx` threading follows Reko
   (`dx_42` in the drain loop, `dx_480`/`dx_550` in the modal loop).
7. **`fn0800_19E1` dropped arguments (main loss).**  Every 19E1 call in 391E
   stages six words (`ret 0Ch`): flag, far label, y, x, slot index.  The frozen
   prototype carries only `ptrArg04`, so the flag/coordinate/index words are
   dropped; the labels `cs:38E8h`/`cs:38F4h` are passed.  Asm values are in
   comments (flags 0/1, x = 0F0h/190h, y = 14Eh, indices 1/2).  (Same class of
   loss as parts 5/6/7.)
8. **`fn0800_19E1` / `fn1206_00xx` `bpOut` pass-through.**  Reko reconstructs
   the stream-block base as `bp_604 - 0110h` from the BP returned by
   1206:015B/3850; that is exactly 391E's `ss:bp-0110h` = `abStream` in the
   flat model, so the 0918 calls pass `abStream` directly instead of a BP
   dereference.  The `bpOut` locals are address-taken and left at their seeded
   0 ("not meaningful here", parts 5/6).
9. **`fn0800_391E` return.**  Reko returns the dropped DGROUP selector (`ds`);
   the only caller (fn0800_3D9D:4129) discards it, so `0` is returned.
10. **`fn0800_3BF2`/`3C72` clock argument mapping.**  Reko's `wLoc08/wLoc0A/
    wLoc0C/wLoc0E` labels are shifted relative to the asm addresses, so the
    bp-offset names were recovered from the `.asm` (`[bp-6h]` = hours = CH,
    `[bp-8h]` = minutes = CL, `[bp-0Ah]` = seconds = DH, `[bp-0Ch]` =
    hundredths = DL, matching `fn1E5F_00A2`'s `ptrArg04=DL / ptrArg08=DH /
    ptrArg0C=CL / ptrArg10=CH` stores).  3C72's `wLoc04`/`wLoc02` are the low
    and high words of the 32-bit difference (`sub`/`sbb`).

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0800_part12.c` -- exit 0, zero diagnostics
  (also clean with `-Wall -Wextra`).
* Reko-token grep (`Eq_[0-9]`, `<invalid>`, `<unknown>`, `SEQ(`, `CONVERT(`,
  `Mem[0-9]*[`, `segptr`, `Eq_17`) -- 0 hits.
* `nm` reports all five functions (`fn0800_36E6`, `fn0800_3850`,
  `fn0800_391E`, `fn0800_3BF2`, `fn0800_3C72`) as `T`.
* Frozen-prototype cross-check (`gcc -Wall` on a TU assigning the five
  `seg0800.h` prototypes to matching function pointers) -- exit 0.

## part 11

Source: `src/seg0800_part11.c` -- function 0800:31B7 only (the mission input
dialog driver, ~612 Reko C lines, the largest in the segment).  Ground truth =
`analysis/slices/0800/0800_31B7.asm`; frozen prototype from `src/seg0800.h`
(`analysis/summary/iface.tsv`) adopted exactly.

### Function converted

| off  | prototype |
|---|---|
| 31B7 | `u16 fn0800_31B7(s16 dx, u16 * dsOut)` |

### Hardware / dispatch sites

**None direct.**  No `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port
instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch occur in
31B7.  All BIOS/DOS/hardware traffic is reached through the callee segments,
already replaced there: segment 0C74 (`fn0C74_06B7`, `51AA`, `51B2`, `522C`,
`5258`, `542B`, `54B1`, `54F0`), 1EDA (`0FA2`/`0FD0`/`1123`/`108C`/`1051`/
`04A9`/`0A39`/`0CD4`), 1AB8 (video/text), 1206 (mouse cursor; INT 33h reaches
`fn1E5F_000B` inside `seg1206.c`) and 1E78 (keyboard/PIT).  No PAL call is
issued in this file.

### Flat-model far pointers / ABI adaptations

* **`cs:3112h` record copy.**  `fn1EDA_0A39(0FFh, buf204, &g_seg0800[0x3112h],
  ...)` -- dest = `[bp-0204h]` (`buf204`), src = code-segment image bytes.
* **DGROUP record copies.**  `ds:5CB4h -> ds:5CECh` and `ds:5CB4h -> ds:5ED6h`
  become `&g_dgroup[0x...]` pairs (6 bytes each), preserving the two-update
  order.
* **`ds:5CBBh` label rows** become `&g_dgroup[0x5CBB]`.
* **`cs:316Fh` / `cs:318Fh` bit tables** become `&g_seg0800[0x316F]` /
  `&g_seg0800[0x318F]` (the `fn1EDA_0CD4` bit-test), and the stream name
  `cs:31AFh` becomes `&g_seg0800[0x31AF]`.
* **Dropped 1206:00FFh / 012Dh / 00D1h stack words.**  The frozen 1206
  prototypes carry no slots for the parameters the two 8086 stack words encode
  (CX=1/DX=`04CC(16h)` for `00FFh`; the `198h/1D1h` and `9Ch/1B4h` pairs for
  `012Dh`/`00D1h`).  `seg1206.c` already documents that the frame words stay
  zero; the calls here pass only the frozen out pointers.  The `04CC(16h)` is
  still executed (its result was the dropped DX word) so the instruction flow
  is preserved.
* **Dropped `fn1EDA_108C` data-buffer pointer (main loss).**  The original
  pushes two far pointers: the stream block `[bp-0284h]` and the line buffer
  `[bp-0204h]`; `fn1EDA_108C`'s frozen prototype keeps only the stream block
  (`ptrArg08`), and the port's record-I/O layer writes through the shared slot
  `g_1EDA_io_buffer` (`src/seg1EDA_shared.h`).  The call therefore points
  `g_1EDA_io_buffer` at `buf204` around `fn1EDA_108C` and restores it
  afterwards -- the same adaptation part 8 used for `fn1EDA_1085`.  Without
  this the final record write would have used the default DGROUP:5CB4h buffer.

### Uncertain sites / not recovered literally

1. **Return value.**  The only caller (`fn0800_3D9D:40EA`) ignores AX and
   branches on DGROUP 58B3h; Reko returns a frame word
   (`(ss->*bp_1120).a0000[0].u1`) with no flat-C meaning.  `0` is returned and
   `*dsOut` is the dropped DGROUP selector (0), following parts 1/3/6.
2. **`fn1E78_030D` stale `wArg02`.**  The original calls 030D with no pushed
   argument (`retf`), so the frozen prototype's `wArg02` is a stale word; it is
   seeded `0x0000` at every call (parts 2/4/6 convention) and the `dx` register
   is threaded through `dx_1012` as Reko models.
3. **`fn0800_00C1` DX output.**  The "arm the timer" path sign-extends
   `60*[53DDh]` with `cwd` (`dx_high` is always 0 for the byte range) and passes
   the DX:AX pair to `00C1`; the returned DX (the timer vector offset, only
   meaningful on the first install) becomes `dx_1012`, the DX input of the
   following `fn1E78_030D` calls.
4. **`fn0800_031B` AH.**  The command-byte path keeps AH from `031B`'s return
   for the later `0CD4` push; `0CD4` reads AL only, so only the low byte is
   stored in `[53D2h]` (the switch value) and AH is not modelled.
5. **`[53D2h]` latched once.**  The asm loads AL from `[53D2h]` once at 34ADh
   and compares that value through the dispatch chain; the port latches
   `al_1056` the same way.  The 35FAh store block re-reads `[53D2h]` exactly as
   the original does.
6. **`fn0C74_51AA` / `fn0C74_51B2` return selectors.**  Reko threads their
   DGROUP-selector returns into the following `fn0800_09C2`; in the flat model
   every selector is 0, so the returns are discarded and the following 09C2
   uses the seeded `ds_1001`.
7. **`fn0800_0768` / tail loop.**  The final keyboard drain threads `0768`'s
   DX return through `fn1E78_030D` (`dx_2026`); `fn1E78_030D`'s `wArg02` is
   seeded 0 as above.

### Validation

* `gcc -c -Wall -Wextra -Isrc -Ipal src/seg0800_part11.c` -- exit 0, zero
  diagnostics.
* Reko-token grep (`Eq_[0-9]`, `<invalid>`, `<unknown>`, `SEQ(`, `CONVERT(`,
  `Mem[0-9]*[`, `segptr`, `Eq_17`) -- 0 hits.
* `nm` reports `fn0800_31B7` as `T`.
* Call-site parity: all 116 `call` sites in the `.asm` are represented (per
  callee counts match exactly, e.g. 23x `fn0800_09C2`, 16x `fn1AB8_1D82`,
  7x `fn1E78_02FB`).

## part 9

Source: `src/seg0800_part9.c` -- function 0800:2827 only.  Ground truth =
`analysis/slices/0800/0800_2827.asm`; frozen prototype from `src/seg0800.h`
(`analysis/summary/iface.tsv`).

### Functions converted

| off  | prototype |
|---|---|
| 2827 | `u16 fn0800_2827(u16 * dsOut)` |

2827 is the RAD.HLP playback screen (the demo/mission recorder).  It probes
`Rad.hlp` (`fn0C74_0000(cs:2810h)`), drains pending keys, hides the mouse,
calls `13E2:003B` and reloads the RAD.DAT mission grid (`fn0800_01FE`), then
compares the selected record name `ds:5ECEh` against `cs:2818h` (`{6,"NONAME"}`).
On equality it resets `[598Eh]:[5990h]` to 1:0 and exits; otherwise it opens the
RAD.HLP stream (`cs:281Fh` = `{7,"RAD.HLP"}`), seeks to record
`[598Eh]:[5990h]`, reads one 0x100-byte record and interprets it as a queue of
command bytes (`;`, `<`, `=`, `H`, `K`, `M`, `P`, Esc) in a loop guarded by
`fn0800_0877()` and `ds:58B3h`, repainting the HUD each iteration; when the loop
ends normally it advances the 32-bit record counter and either exits
(`fn0800_166D`) or wraps `[598Eh]` from 0FAh back to 1.

### Hardware / dispatch sites

**None direct.**  No `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port
instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch occur in
2827.  Every BIOS/DOS/hardware service reached from here is owned by the callee
segments and replaced there: segment 1E78 (keyboard/PIT `02FB`/`030D`), 1206
(mouse cursor `0066`/`0038`/`015B`, INT 33h through `fn1E5F_000B` inside
`seg1206.c`), 0C74 (the `fn0C74_0000` "Rad.hlp" probe and the
`51AA`/`51B2`/`522C`/`5258`/`542B`/`54F0`/`54B1` handlers), 1EDA (DOS RAD.HLP
stream layer `0FA2`/`0FD0`/`1123`/`1085`/`1051`/`0A39`/`0B24`), 1AB8
(video/text `1536`/`14F4`/`1342`/`1C32`/`1D82`), 13E2 (`003B`/`00FB`) and
`fn0800_*` (the menu/HUD helpers `01FE`/`04E3`/`0619`/`0BEC`/`005A`/`00C1`/
`0103`/`0877`/`08C0`/`09C2`/`0C71`/`166D`).  No PAL call is issued in this file.

### Frame / flat-model far pointers

* `enter 282h` is recovered as three local buffers at the exact asm offsets:
  `abStream[0x80]` at `[bp-0x180]` (RAD.HLP stream block), `bFE7F` at
  `[bp-0x181]` (command-queue read index) and `abRecord[0x100]` at `[bp-0x100]`
  (the record read from RAD.HLP, later the command queue).
* `cs:2810h` = `{7,"Rad.hlp"}` (`fn0C74_0000`), `cs:2818h` = `{6,"NONAME"}`
  (`fn1EDA_0B24`) and `cs:281Fh` = `{7,"RAD.HLP"}` (`fn1EDA_0FA2`); all are
  passed as `&g_seg0800[0x....]`.  Verified against `data/segments/seg0800.bin`.
* `ds:5ECEh`/`5ED6h` (the `fn1EDA_0A39` 6-byte copy) and the `ds:5CBBh` label
  row used by the two `fn1AB8_1D82` calls become `&g_dgroup[...]`.
* `fn0800_09C2`'s and `fn0C74_*`'s `bpOut`/`dxOut` register outputs are dead;
  they are kept in distinct Reko-named locals and passed through.
* **`fn1EDA_0A39` order** follows the last-pushed-first convention:
  `fn1EDA_0A39(size, dest, src, &dxOut)`; the asm's `mov di,5ECEh` (first push =
  src) / `mov di,5ED6h` (second push = dest) / `push 6h` becomes
  `fn1EDA_0A39(0x06, &g_dgroup[0x5ED6], &g_dgroup[0x5ECE], &dx_1375)`.

### Dropped-argument adaptation (fn1EDA_1085)

The original pushes two far pointers for the record read: the stream block
(`[bp-0x180h]`) and the data destination (`[bp-0x100h]`).  The frozen
`fn1EDA_1085` prototype keeps only the stream block (`ptrArg08`); the port's
record-I/O layer writes through the shared slot `g_1EDA_io_buffer`
(`src/seg1EDA_shared.h`).  As that header requires ("callers outside chunk 6
must point it at their buffer before invoking the record-I/O helpers"), the call
site saves `g_1EDA_io_buffer`, points it at `abRecord`, calls `fn1EDA_1085`, and
restores it.  Unlike part 1/4 (whose buffers already are `DGROUP:5CB4h`), this
is a stack buffer, so the save/restore is required -- the same adaptation part 8
and part 11 used.

### Uncertain sites / not recovered literally

1. **`fn1EDA_0B24` branch direction (main divergence).**  The asm is
   `call far 1EDAh:0B24h ; jnz 2879h`, so the reset at `l0800_286A` (set
   `[598Eh]:[5990h]` = 1:0) runs when the selected record **equals**
   `cs:2818h`, and the long open/play block at `l0800_2879` runs when it does
   **not**.  Reko emitted the inverted `if (!fn1EDA_0B24(...))` here
   (RAD_0800.c), contradicting the port's `fn1EDA_0B24` (nonzero on equality, 0
   otherwise; verified against parts 2/4 and `seg1EDA_part4b.c`) and the `.asm`
   itself.  The `.asm` is followed:
   `if (fn1EDA_0B24(...) != 0x00) { reset; break; }`.  This is exactly the same
   inversion part 8 documented for the sibling 0800:2401 site.
2. **`fn0C74_0727`-class open probe (`fn0C74_0000`) `dxOut`.**  The port's
   `fn0C74_0000` writes its `dxOut` (Reko: `dxOut = dx_53`, the DOS find-first
   result); `dx_1236` is threaded into the two `fn1E78_030D` drain calls as Reko
   models.  `fn1E78_030D` itself takes no stack argument in the original
   (`retf`), so its frozen `wArg02` slot is seeded `0x0000` (parts 2/4/8/11
   convention).
3. **`fn0C74_06B7` result.**  Reko nests the return as the argument of the
   following `fn1206_0038`, which the frozen 0038 prototype cannot carry (its
   asm reads no `[bp+6h]` argument); the call is kept for its side effects
   (it sets `DGROUP:5968h`, clears `58B3h` and paints the mission name) and its
   result discarded, the same divergence part 8 recorded.
4. **`fn0C74_522C` / `54F0` / `54B1` `dsOut` is a far block pointer.**  Their
   Reko slices assign a struct pointer (`dsOut = ds_57` / `ds_86`), so those
   sinks are `void *` here (`ds_1059`, `ds_770`, `ds_650`) to give the callee a
   full host pointer to write; part 8 passed a `u16` there.  `fn0C74_542B` /
   `5258` assign the dropped DS selector and use `u16` sinks, as before.
5. **DS threading.**  DS has no flat meaning; no call passes DS as input (the
   asm's `ds_880`/`ds_808`/`ds_770`/`ds_650`/`ds_370` selector chains are
   dropped).  The generic `ds` local is the write-only output of every 09C2 /
   1206 / 0C71 call.
6. **`bp_1121` frame pointer.**  The mouse wrappers return the caller's BP,
   which Reko uses as the base for `(ss->*bp_1121).bFE7F` and
   `[bp_1121-0x0181]`.  As in parts 2/4/5/8, those are recovered directly as the
   `bFE7F` / `abRecord[]` locals; `bp_1121` is kept as an address-taken `u16`
   output only (the PAL's 1206 frame is zero-initialised).
7. **Return value.**  `leave; ret` returns whatever AX the last callee left;
   Reko models it as a frame word (`(ss->*bp_1121).a0000[0].u1`) with no flat-C
   meaning.  `0` is returned and `*dsOut` is the dropped DGROUP selector (0);
   the single caller (`fn0800_3D9D:3EF3`) discards both.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0800_part9.c` -- exit 0, zero diagnostics
  (also clean with `-Wall -Wextra`).
* Reko-token grep (`Eq_[0-9]`, `<invalid>`, `<unknown>`, `SEQ(`, `CONVERT(`,
  `Mem[0-9]*[`, `segptr`) -- 0 hits.
* `nm` reports `fn0800_2827` as `T`, matching the frozen prototype exactly
  (`u16 fn0800_2827(u16 * dsOut)`); it is the only defined symbol in the object.

## part 10

`src/seg0800_part10.c` — function `0800:2C0C` (`u16 fn0800_2C0C(s16 dx, u16 *dsOut)`,
the largest UI function at ~576 Reko lines).  Literal recovery from
`analysis/slices/0800/0800_2C0C.asm` (ground truth); frozen prototype from
`src/seg0800.h` (iface.tsv) adopted exactly.

### Hardware / DOS / dispatch sites

None direct.  `2C0C` contains **no** `int 10h`, `int 16h`, `int 21h`, no
`in`/`out` port instruction, no `cli`/`sti`, no `int 23h` and no raw IVT
dispatch.  Every service is reached through a callee segment and is replaced
there:

* **Keyboard/BIOS key reads** — `fn1E78_02FB` / `fn1E78_030D` / `fn1E78_016B`
  (segment 1E78; `bios_kbd_*` inside).
* **Mouse** — `fn1206_0066` / `fn1206_0038` / `fn1206_015B` (segment 1206;
  INT 33h via the `fn1E5F_000B` register-frame trampoline -> `pal_int_dispatch`).
* **Timer vector** — `fn0800_00C1` / `fn0800_0103` are the int 1Ch install/
  restore wrappers recovered in `seg0800_part1.c` (they use `fn1E5F_0159` /
  `fn1E5F_0171`, i.e. `msdos_get/set_interrupt_vector`).  No `int 1Ch`
  instruction appears in `2C0C`.
* **File/stream, video/text, palette, clock** — all via segment 1EDA, 1AB8,
  13E2 and 0C74.

The `fn0800_2C0C` call sites that the asm marks as far dispatch are ordinary
cross-segment calls, not IVT dispatch.

### Flat-model far pointers / DGROUP cells

* `cs:2B43h` = `&g_seg0800[0x2B43]` (`{06,"NONAME"}`);
  `cs:2B4Ah` = `&g_seg0800[0x2B4A]` (`{04,"DEMO"}`);
  `cs:2B4Fh` = `&g_seg0800[0x2B4F]` (the `"RAD.MEM"` stream name);
  `cs:2B57h/2B82h/2BAFh/2BDAh` = the four error lines;
  `cs:2BEDh` = the alternate title string.
* `ds:5ECEh` / `ds:5ED6h` / `ds:5CBBh` -> `&g_dgroup[0x5ECE]` / `[0x5ED6]` /
  `[0x5CBB]`; `ds:B8ACh` -> `LG16(0xB8AC)`; `ds:B9BCh` -> `&g_dgroup[0xB9BC]`.
* `[bp-0102h]` (Reko `bp - 0x0102`) is the one 0x102-byte local, the RAD.MEM
  stream block; `[bp-01h]` (Reko `.bFFFF`) is `bLoc01`, the cs:5CBBh table
  index.

### fn1EDA_0B24 polarity (asm ground truth)

The frozen `fn1EDA_0B24` returns 1 when the two records are equal.  Every
branch in `2C0C` was recovered from the raw `.asm`:

* `jz T`  -> `if (fn1EDA_0B24(...) != 0) goto T;`
* `jnz T` -> `if (fn1EDA_0B24(...) == 0) goto T;`

This matters at `2C37` (`jnz 2C4D`), `2C57` (`jnz 2C61`), `2D5E` (`jz 2D77`),
`2D98` (`jz 2DB1`), `2E12` (`jz 2E37`), `2E67` (`jz 2E71`), `2EB3`
(`jnz 2ED2`) and `30A8` (`jnz 30B1`).  (The Reko listing inverts the `jnz`
sites; the `.asm` bytes were checked and followed.)

### Recovered stack/push sites

* `fn1EDA_08CE` pushes `[block][source-string][width]`; it is a `retf 6h`
  service, so the block pointer is left on the stack and is consumed by the
  following `fn1EDA_0848` (`retf 4h`).  Both calls are recovered with the
  frozen prototypes: `08CE(width, src, block, &cx)` then
  `0848(0, cx, block)`.
* `fn1EDA_0A39` pushes `[source][dest][count]` -> `0A39(count, dest, src, &dx)`.
* `fn1206_015B` is called after a `push 0h` word in the original; the frozen
  prototype has no slot for it (`seg1206.c` models it internally as
  `wArg06 = 0`), so the push is not reproduced.

### Uncertain sites / not recovered literally

1. **Return value.**  At `l0800_3110` the original is just `leave; ret`; Reko
   returns a frame word (`(ss->*bp_1005).t0000.u1`) with no flat-C meaning.
   Both callers (`fn0800_3D9D:3F26` and `:400E`) ignore AX, so `0` is returned
   and `*dsOut` is the dropped DGROUP selector (0), following parts 1/3/6.
2. **`fn1E78_030D` stale `wArg02`.**  The original calls 030D with no pushed
   argument (`retf`), so the frozen `wArg02` slot is a stale word; it is
   seeded `0x0000` at every call (parts 2/4/6/11 convention) and the `dx`
   register is threaded through `dx_1020` / `dx_1028` / `dx_1999` as Reko
   models.
3. **`l0800_2D21` `fn1E78_030D` arguments.**  This call has no pushes: after
   the register-preserving `fn1EDA_04A9` the surviving DX:AX and the selector
   `ds_410` are 0 in the flat model, so `030D(0, 0, &dx_2278)` reproduces the
   register state (the Reko `SLICE(04A9(...), word16, 16)` high word is the
   dropped selector).
4. **`fn0800_00C1` at `2E37`.**  The original `imul ax,ax,3Ch; cwd; push dx;
   push ax`; since `[53DDh]` is 0..255 the product is < 0x8000 and `cwd`
   yields DX = 0, so `00C1(3Ch*[53DDh], 0x0000, &dx_1020)` is exact.  The DX
   returned by `00C1` (timer vector offset, only meaningful on the first
   install) is `dx_1020`, the input of the following `030D` drain.
5. **`04CCh` stale AH.**  At `2DF2` the original pushes `AX` after
   `mov al,[53D9h]` (stale AH) and again after `mov al,[53DAh]` (AH =
   result-1 high byte).  `04CCh` reads AL only, so both calls are recovered as
   independent `04CC((u8)LG8(...))` (same as parts 8/9; part 11 keeps the
   intermediate word explicitly).
6. **`fn0C74_51AA` / `fn0C74_51B2` / `fn0800_08C0` return selectors.**  Reko
   threads their returns into the following `fn0800_09C2` as the DS input; in
   the flat model every selector is 0, so the returns are discarded and the
   following 09C2 uses the persistent `ds_1065`.
7. **`fn0800_0768` / tail loop.**  The final keyboard drain threads `0768`'s
   DX return through `fn1E78_030D` (`dx_1999`); `030D`'s `wArg02` is seeded 0
   as in item 2.
8. **`fn1EDA_00E9` fatal exit.**  The error path calls it as the last
   statement; the flat implementation returns the DGROUP pointer, so the
   recovered assignment `ds_1065 = (u16)(uintptr_t)fn1EDA_00E9(0)` follows the
   part 1 / seg13E2 convention for this never-returning CRT exit.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0800_part10.c` -- exit 0, zero diagnostics
  (also clean under `-Wextra`).
* Reko-token grep (`Eq_[0-9]`, `<invalid>`, `<unknown>`, `SEQ(`, `CONVERT(`,
  `Mem[0-9]*[`, `segptr`, `Eq_17`) -- 0 hits.
* `nm` reports `fn0800_2C0C` as `T`.
* Call-site parity vs the `.asm`: 8x `fn1EDA_0B24`, 22x `fn0800_09C2`,
  6x `fn1AB8_1D82`, 7x `fn1E78_02FB`, 6x `fn1E78_030D`, 5x `fn1EDA_08CE` /
  `fn1EDA_0848`, 4x `fn1EDA_04A9`, 3x `fn1206_0066` / `fn1206_015B` /
  `fn0800_0103`, 2x each of `fn0800_005A` / `fn0800_00C1` / `fn0800_0877` /
  `fn0800_08C0` / `fn1AB8_1536` / `fn1AB8_14F4`, and all remaining callees
  once.

## part 13+14

Source: `src/seg0800_part13.c` -- functions 0800:3CFA and 0800:3D9D
(ascending offset).  Ground truth = `analysis/slices/0800/0800_<off>.asm`;
frozen prototypes from `src/seg0800.h` (`analysis/summary/iface.tsv`).

### Functions converted

| off  | prototype |
|---|---|
| 3CFA | `u16 fn0800_3CFA(void)` |
| 3D9D | `u16 fn0800_3D9D(void)` |

3CFA is the completion-time timer: it sets the 53DFh "already timed" flag,
selects video attribute 0 (`fn1AB8_1C32`), stamps the ds:555Eh interval record
with the current clock (`fn0800_3BF2`), then polls (`fn1AB8_122E` + `fn0800_3C72`)
until the elapsed interval is positive or reaches 100 ticks and stores
`tick * 8 / 100` (minimum 7) at ds:58E6h.  The only caller is 3D9D:3DB7.

3D9D is the top-level menu driver and one of the three callers of the
terminate/deinit path `fn0800_0000` (part 1).  It hides the cursor
(`fn1206_0066`), brings up the palette/video (`fn13E2_003B/0080`,
`fn1AB8_0F80`), runs the timer when 53DFh is clear, paints the "GICIEL" banner
(`fn1AB8_1D82` + cs:3D5Ah) and button frame (`fn0C74_06B7`, `fn1206_01AC`,
`fn1206_0038`), then runs the modal loop.  Each iteration services the two
0C74 clock handlers (`fn0C74_54B1`/`54F0`), reads a key (`fn1E78_02FB`/
`030D`) or a mouse hit (`fn0800_1D55`), and dispatches on `[bp-1h]`:

* `21h` -- leave the nested "Fichier" editor and return (`fn1206_0066`,
  `fn0800_184C`, `fn0800_2827`).
* `3Bh` -- the SUITE-ish screen: `fn0800_19E1(ds:5438h)`, `fn0C74_51AA`,
  `fn1206_0066`, `fn0800_184C`, `fn0800_2C0C`; return.
* `3Ch` -- the mission/slot frame: two `fn0800_19E1(ds:5452h)`, `fn0800_11EF`,
  `fn1AB8_1175/1B3E`, then either the built label `F1:+ds:5ED6+` " "
  (cs:3D7Fh/cs:3D83h coalesced into `[bp-0106h]` when 5990h!=0 or 598Eh!=1)
  or the literal cs:3D85h label (`fn0800_19E1`); falls through to 4134h.
* `3Dh` -- `fn0800_19E1(ds:546Ch)`, reset 598Eh/5990h, `fn1206_0066`,
  `fn0800_149F`, `fn0800_184C`, `fn0800_2C0C`, restore the position; return.
* `3Eh` -- toggle 58B0h and repaint the ds:5486h button; falls through to 4134h.
* `3Fh` -- the system screen: `fn0800_19E1(ds:54A0h)`, `fn1206_0066`,
  `fn1E78_029C(100)`; if DGROUP 0002h <= 1Eh, draw `fn0800_2004` + `fn0800_21E7`
  and fall through to 4134h, otherwise run the modal RAD.MEM browser
  (`fn1AB8_1CBA`/`1342`, `fn1206_0066`, `fn1EDA_0B24`/`0A39`,
  `fn1229_0DCC`, `fn0800_31B7`) until 5CB3h is set, then return.
* `40h` -- the options screen: `fn0800_19E1(ds:54BAh)`, `fn1E78_029C(100)`,
  `fn1206_0066`, `fn0800_391E`, `fn0800_21E7`, `fn1206_0038`; falls through to
  4134h.
* at 4134h, `[bp-1h] != 41h` loops back to 3E46h; `41h` ('A') repaints the
  ds:54D4h button, runs `fn0C74_0A35`, hides the cursor (`fn1206_0066`) and
  quits through `fn0800_0000`.

### Hardware / dispatch sites

**None direct.**  No `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port
instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch occur in
3CFA or 3D9D.  The mouse goes through segment 1206 (`fn1206_0066`/`0038`/
`01AC`, INT 33h wrappers replaced in `seg1206.c`), the keyboard through segment
1E78 (`fn1E78_02FB`/`030D`/`029C`), video/text through segment 1AB8, DOS
stream/string work through segment 1EDA, the menus through segment 0C74,
palette/video through segment 13E2 and the mission browser through segment
1229.  The quit-to-DOS tail calls `fn0800_0000` (part 1), which owns the AdLib
(`fn11C8_03BB`) teardown and the CRT fatal exit `fn1EDA_00E9(0)`.  No PAL call
is issued in this file.

### Segment / DGROUP data referenced

* `cs:3D5Ah` = `{36,"UN LOGICIEL NEXTDOOR DE MAX GAILLARD"}` (banner blitted by
  `fn1AB8_1D82` at 3DBA).
* `cs:3D7Fh` = `{3,"F1:"}`, `cs:3D83h` = `{1," "}`, `cs:3D85h` =
  `{11,"  F1:JEU   "}`, `cs:3D91h` = `{4,"DEMO"}`, `cs:3D96h` =
  `{6,"NONAME"}` (all length-prefixed; verified against
  `data/segments/seg0800.bin`).
* `ds:5ED6h` -- the current mission/record name buffer copied and compared by
  the 3Fh browser (`fn1EDA_0B24` vs cs:3D91h, `fn1EDA_0A39` from cs:3D96h,
  `fn1229_0DCC`).
* `ds:58E0h` (event flag), `ds:58B0h` (3Eh toggle), `ds:58B2h` (21h guard),
  `ds:58E6h` (3CFA result), `ds:53DFh` ("timed" flag), `ds:598Eh`/`5990h`
  (record position), `ds:5CB3h` (browser-done flag), `ds:0002h` (system-screen
  selector) -- all via `LG8`/`LG16`.
* `ds:541Ch..ds:5436h` slot coordinates and `ds:5438h`/`5452h`/`546Ch`/`5486h`/
  `54A0h`/`54BAh`/`54D4h` button-label buffers.  These offsets are >= 0x5390,
  i.e. in DGROUP `_BSS`, so they are runtime buffers (zero in the file image)
  filled by earlier 1AB8/1EDA work, not static strings.
* 3CFA's clock interval record is `ds:555Eh`.

### Flat-model far-pointer / ABI adaptations

* **Built label buffer.**  The original `enter 106h,0h` reserves one 0x106-byte
  frame: the menu label at `[bp-0106h]` and the dispatched key at `[bp-01h]`.
  The port models them as `abBuf[0x105]` (`[bp-0106h]..[bp-02h]`) plus the
  separate `bLoc01` (`[bp-01h]`).  In the 3Ch "else" path the coalesced label is
  built at `[bp-0106h]` by `fn1EDA_0A1F`/`0AAC` and passed to `fn0800_19E1`
  (the stack-resident destination pointer is the one the original leaves on the
  stack across the `retf 4h` chain).
* **`fn0800_19E1` argument loss.**  The frozen prototype keeps only the far
  string pointer.  The original also reads `[bp+04h]` flag, `[bp+0Ah]` y,
  `[bp+0Ch]` x and `[bp+0Eh]` slot index from its own frame (ret 0Ch); those
  four words are not representable and are omitted at all eleven call sites
  (part 5 convention).  The recovered strings are, in offset order:
  ds:5438h, ds:5452h (x2), cs:3D85h, the `abBuf` label, ds:546Ch, ds:5486h
  (x2), ds:54A0h, ds:54BAh, ds:54D4h.
* **`fn1206_01AC` argument loss.**  The original stages six words
  (`9Ch,14h,1E0h,16Ah,140h,0B4h`); the frozen prototype carries only the
  siOut/esOut/dsOut register handles (part 5 convention), so the staged words
  are not reproduced.
* **Embedded far pointers** (`push cs ; push di` or `push ds ; push di`)
  resolve to `&g_seg0800[...]` / `&g_dgroup[...]`.
* **3CFA record.**  `ds:555Eh` is passed as `&g_dgroup[0x555E]` to
  `fn0800_3BF2`/`fn0800_3C72` (the latter writes the high word through
  `dxOut`).  The `tick * 8 / 100` division is kept as unsigned 16-bit
  (`(u16)(((u16)wLoc04 << 3) / 0x64)`).

### Uncertain sites / not recovered literally

1. **Return values (dropped selectors).**  Both functions end in a bare
   `leave; ret`; Reko types the result as the implicit DGROUP selector
   (`Eq_17`), and the frozen prototypes return `u16`.  Following parts
   1/3/6/10, the flat code returns 0 at every exit and never consumes the
   callee returns that Reko threads as selectors.  Note 3CFA's AX at `ret` is
   actually the `div` quotient (the caller ignores AX), so 0 is only
   behaviourally equivalent, not register-identical.
2. **`fn1E78_030D` stale `wArg02`.**  The original calls 030D with no pushed
   argument (`retf`), so the frozen `wArg02` slot is a stale word; it is seeded
   `0x0000` at all three call sites and the `dx` register is threaded through
   `dx_1109` as Reko models (parts 2/4/6/11 convention).
3. **`fn0800_2C0C` dead `dx`.**  The frozen prototype takes `s16 dx` but the
   callee never reads it.  The 3Bh/3Dh sites pass `fn0800_184C`'s return (the
   DX the asm leaves live, Reko's model); the other sites pass the value
   through `dx_184C`.  Any value is behaviourally equivalent.
4. **`fn1206_0066(fn0C74_51AA(...))` (3Bh).**  Reko uses the `fn0C74_51AA`
   return as 0066's `bpOut` pointer (a register-flow/type artifact); the asm
   simply calls 51AA and then 0066.  Recovered as two sequential calls with a
   scratch `bp_1601` output.
5. **`fn1206_0038(fn0800_21E7(fn0800_2004(...)))` (3Fh) and
   `fn1206_0038(fn0800_21E7(fn0800_391E(...)))` (40h).**  Same artifact: the
   nested returns are the register chain, not a `chOut` pointer.  Recovered as
   sequential `fn0800_2004`/`391E` -> `fn0800_21E7` -> `fn1206_0038(&ch,...)`.
6. **`fn1E78_030D`/`fn0800_1D55`/`54B1`/`54F0` output handles.**  `bp_1104`
   appears both as the Reko model of `[bp-01h]` and as the BP output of these
   wrappers.  The port keys off the separate `bLoc01` local, so the writes
   through `bp_1104` are harmless.
7. **`ds_16` / `ds_1108` etc.**  Every selector output is a dropped DGROUP
   selector in the flat model; the locals are seeded 0 and only satisfy the
   frozen pointer signatures.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0800_part13.c` -- exit 0, zero diagnostics
  (also clean under `-Wextra`).
* Reko-token grep (`Eq_[0-9]`, `<invalid>`, `<unknown>`, `SEQ(`, `CONVERT(`,
  `Mem[0-9]*[`, `segptr`, `Eq_17`) -- 0 hits.
* `nm` reports `fn0800_3CFA` and `fn0800_3D9D` as `T`, both with the exact
  frozen `u16 f(void)` prototype (confirmed by including `seg0800.h`).
* Call-site parity vs the `.asm`: 11x `fn0800_19E1`, 9x `fn1206_0066`,
  6x `fn1E78_02FB`, 3x each of `fn1206_0038` / `fn1E78_030D` / `fn1AB8_1342` /
  `fn1AB8_1C32` / `fn0800_184C` / `fn0800_21E7`, 2x each of
  `fn0C74_54B1` / `fn0C74_54F0` / `fn1AB8_1CBA` / `fn1E78_029C` /
  `fn0800_2C0C` / `fn1EDA_0AAC`, and every remaining callee exactly once, plus
  3CFA's `fn1AB8_1C32`/`fn0800_3BF2`/`fn1AB8_122E`/`fn0800_3C72`.

## part 15

Source: `src/seg0800_part15.c` -- functions 0800:4168 and 0800:4255 (ascending
offset).  Ground truth = `analysis/slices/0800/0800_<off>.asm`; frozen
prototypes from `src/seg0800.h` (`analysis/summary/iface.tsv`).

### Functions converted

| off  | prototype |
|---|---|
| 4168 | `u16 fn0800_4168(void)` |
| 4255 | `void fn0800_4255(void * es)` |

4168 loads the RAD.DAT data file: it probes `cs:4160h` (`{7,"RAD.DAT"}`) with
`fn0C74_0000` (on failure it runs the terminate path `fn0800_0000`), re-inits
the `[bp-80h]` stream block (`fn1EDA_0FA2`), opens record `219h`
(`fn1EDA_0FD0`), reads it via `fn1EDA_04A9`/`116A`/`04A9`, stores
`recordlen - 2` at `DGROUP:5CB2h` and closes the block (`fn1EDA_1051`).

4255 is the **MZ entry point** (`e_ip=0x4255`): the CRT startup plus the
top-level game dispatch.  `src/main.c` passes the fabricated PSP `g_psp` as
`es`.

### The full CRT init sequence (call order + arguments)

The original is a flat sequence of eleven far calls (no argument pushes; DS is
threaded through the dropped selector):

| # | call | port call |
|---|---|---|
| 1 | `far 1EDAh:0000h` | `(void)fn1EDA_0000(es)` (runtime init; `es` = PSP, returns DGROUP) |
| 2 | `far 1E78h:0000h` | `fn1E78_0000()` |
| 3 | `far 1AB8h:17AEh` | `fn1AB8_17AE()` |
| 4 | `far 13E2h:0220h` | `fn13E2_0220()` (BGI device probe) |
| 5 | `far 13C8h:0139h` | `fn13C8_0139((void *)(uintptr_t)fn13E2_0220())` -- 0139h's DS argument is 0220h's return |
| 6 | `far 13C1h:0067h` | `(void)fn13C1_0067()` (video-mode save) |
| 7 | `far 133Fh:0816h` | `(void)fn133F_0816()` |
| 8 | `far 1206h:0217h` | `es_si_736 = fn1206_0217(&bp_98, &ds_102)` (mouse init; SI return kept) |
| 9 | `far 11C8h:03CFh` | `fn11C8_03CF()` (AdLib/OPL init) |
| 10 | `far 0C74h:552Fh` | `fn0C74_552F()` (menu system) |
| 11 | `far 0C43h:02FBh` | `fn0C43_02FB()` (resource/palette) |

Then `enter 200h,0h` and the startup-path selection (below), the token scan
(`DGROUP:5CB2h`/`58E6h`), the palette/banner block, and finally the endless
`while (1) fn0800_3D9D();` main loop.

### Stack-image reconstruction (explicit arguments)

The task's central issue: the original builds far-call argument blocks by
pushing, and several callees deliberately leave part of a block on the stack
for the next call.  Recovered as explicit C arguments with identical values:

* **1EDA:1216** ends in `retf 2h`: it reads the word token index `[bp+6]` and
  the far destination `[bp+8]`, but pops only the word.  In 4255 the two
  "select startup path" calls push three words -- `cs:41C7h` (or `cs:41C9h`),
  `ss:bp-100h` (or `ss:bp-200h`), `1h` -- so the leading `cs:` far pointer is
  the frozen prototype's `es_si` (never read when the token index is non-zero)
  and the destination is the frame buffer.  The **immediately following
  1EDA:0AD8** pushes nothing and consumes the two far pointers 1216h left on
  the stack as `(text, pattern)`: `fn1EDA_0AD8(&abFrame[0x100],
  &g_seg0800[0x41C7], &ax_141)` (pattern `{1,'S'}`) and the `bp-200h` /
  `cs:41C9h` (`{1,'s'}`) pair.  In the token loop the leftover destination is
  `ss:bp-102h` = `&abFrame[0x0FE]`, and **1EDA:0F71** reads that as its source
  text while the explicitly pushed `ds:53D4h` is its destination word:
  `fn1EDA_0F71(&g_dgroup[0x53D4], &abFrame[0x0FE], &si_278, &es_277)`.
  `es_si_736`/`737`/`738`/`741` keep the Reko register names.
* **1EDA:04A9** (4168) is a register-preserving `retf` trap: the asm pushes
  nothing, so `wArg00`/`wArg02` (read only by the never-returning fatal tail
  `fn1EDA_00E2`) are seeded `0x0000`, matching parts 9/10/12.  `ax_120` is its
  DX:AX return; `[5CB2h] = (u8)(ax_120 - 2)` reproduces `sub ax,2h ; sbb dx,0h
  ; mov [5CB2h],al`, and `fn1EDA_1051((u8)(ax_120 - 2), abBuf)` the following
  `retf 4h` call.
* **1E78:030D** takes no stack argument in 4255: `wArg02` is seeded 0 and the
  DX register is threaded exactly as Reko's dataflow (`dx = fn0C43_00B9`
  return, then the loop re-threads 030D's own `dxOut`).
* **1EDA:129E** is `retf 8h` with a register `DH` argument; the port passes
  `(0x00, 0x004F, &g_dgroup[0x550E], 0x00)` (DH, width, destination buffer,
  drive selector 0 = default drive).  The `push ax` before the following
  0CD4 call is the word `(129E return << 8) | DGROUP:550F`, so `0CD4`'s bit
  index is `DGROUP:550F` (the built path's drive letter).
* **fn1EDA_0CD4** polarity: the asm is `jz 43D7h` (skip the palette block when
  ZF=1, i.e. when 0CD4 returns 1 = tested bit CLEAR).  Reko's
  `if (!fn1EDA_0CD4(...))` is therefore correct here; the port writes
  `if (fn1EDA_0CD4(...) == 0x00) { palette block }`, matching parts 9/10.

### Dropped-argument sites (frozen prototypes have no slots)

| callee | original words dropped | port call |
|---|---|---|
| `fn1206_00FF` | `1h`, `fn0800_04CC(0x16)` result (cx/dx) | `fn0800_04CC(0x16); fn1206_00FF(&ds_657)` |
| `fn1206_012D` | `1B0h`, `1D1h` (cx/dx) | `fn1206_012D(0, &ds_676)` |
| `fn1206_00D1` | `64h`, `1C2h` (cx/dx) | `fn1206_00D1(0, &si_744, &es_745, &ds_695)` |
| `fn1AB8_1CBA` | coordinates `0Fh/3Fh/3Fh/3Fh` are present | `fn1AB8_1CBA(0x3F,0x3F,0x3F,0x0F)` |
| `fn1AB8_1536` | none dropped | `fn1AB8_1536(0x0004,0x0000,0x0001,&ds_384)` |

The calls are kept at their original points so call order and side effects
survive; the port's `fn1206_00FF`/`012D`/`00D1` implementations already leave
the range words at zero and document the same loss.

### Hardware / dispatch sites

**None direct.**  No `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port
instruction, no `__cli`/`__sti`, no `int 23h` and no raw IVT dispatch
(`fn1E5F_000B`) occur in 4168 or 4255.  Every BIOS/DOS/mouse request is made by
the callees and replaced there: segment 1EDA (`0000` runtime init, the stream
layer `0FA2`/`0FD0`/`04A9`/`116A`/`1051`/`0AD8`/`1216`/`0F71`/`1265`/`129E`/
`0CD4`/`0E07`), 1E78 (`0000`/`02FB`/`030D`), 1206 (`0217`/`00FF`/`012D`/
`00D1`, INT 33h via `fn1E5F_000B`), 1AB8 (`17AE`/`1CBA`/`1342`/`1536`/`14F4`/
`10CE`/`1D82`/`1175`), 13E2 (`0220`/`0001`/`0193`/`003B`), 13C8/13C1/133F
(video-mode and mouse init), 11C8 (`03CF`) and 0C74/0C43 (menus, fatal report,
file load).

### Segment / DGROUP data referenced

* `cs:4160h` = `{7,"RAD.DAT"}` (4168 stream name), `cs:41C7h` = `{1,'S'}`,
  `cs:41C9h` = `{1,'s'}` (startup-path patterns), `cs:41CBh` / `cs:421Eh`
  (16-byte `fn1EDA_0CD4` bit tables), `cs:41EBh` = `{7,"RAD.TIT"}`,
  `cs:41F3h` = the `{42,"*D\x82sol\x82, je ne fonctionne que sur carte VGA"}`
  record and `cs:423Eh` = `{0x16,"Chargement en cours..."}`; all verified
  against `data/segments/seg0800.bin`.
* `ds:550Eh` (1EDA:129E path buffer, `550Fh` = drive letter), `ds:53D4h`
  (1EDA:0F71 destination word), `ds:53D6h` (token index), `ds:53DFh` (parsed
  value), `ds:58E6h` (record count/selector), `ds:58BEh`, `ds:58E2h`,
  `ds:58B0h`, `ds:598Eh`/`5990h` (record position) -- `LG8`/`LG16` at the
  literal offsets; `&g_dgroup[0x550E]` / `[0x53D4]` where a pointer is needed.

### Uncertain sites / not recovered literally

1. **Startup-path `fn1EDA_1216` `es_si`.**  The two path-selection calls push
   a leading `cs:` far pointer that 1216 never reads (it is only a fallback
   for token index 0, and the original always passes 1).  Per the frozen
   `(es_si, wArg04, ptrArg06)` prototype it is threaded from the preceding
   return (`fn1206_0217` / `fn1EDA_0AD8`); the token-count-loop call has no
   such word on the stack, so it threads the `fn1EDA_1265` / `0F71` `si` value
   (also unread).  Behaviour is identical either way.
2. **`fn13C8_0139` / `fn133F_0816` arguments.**  The original threads the
   13E2:0220h / 13C1:0067h selectors into 0139h / 0816h through a register;
   the frozen 0816h prototype is `(void)` so the 0067h return is dropped (both
   calls are kept in order).  `fn13C8_0139` ignores its `ds` parameter, so the
   `(void *)(uintptr_t)` cast of 0220h's selector is dead.
3. **`fn0800_4168` return.**  The original returns the DGROUP selector left by
   the final `fn1EDA_04A9` (0 in the flat port); the sole caller discards it.
4. **`fn1EDA_04A9` words (4168).**  `wArg00`/`wArg02` are seeded 0 (only the
   never-returning `fn1EDA_00E2` tail reads them).
5. **`fn1E78_030D` stale `wArg02`.**  Seeded 0 (parts 9/10/12 convention); the
   DX first argument is the `fn0C43_00B9` return on the first call and 030D's
   own `dxOut` in the drain loop, exactly as Reko's dataflow.
6. **`fn1206_00FF`/`012D`/`00D1` range words.**  `1h`/`04CC` result,
   `1B0h`/`1D1h` and `64h`/`1C2h` have no prototype slots and are dropped; the
   port's wrappers keep the corresponding frame words at zero (see
   `docs/notes-small-segs.md` "## 1206").
7. **`fn0800_04CC` width.**  The original pushes `1h` then `16h`; 04CC reads
   the last-pushed word as `bArg02` and `ret 2h` pops only it, so the call is
   `fn0800_04CC(0x16)` (the `1h` is a discarded stack word; the code then
   pushes the result for 00FF, which the frozen prototype drops).
8. **Frame overlap.**  The `enter 200h` frame is modelled as one
   `u8 abFrame[0x200]`: `[bp-0x200] = &abFrame[0x000]`,
   `[bp-0x100] = &abFrame[0x100]`, `[bp-0x102] = &abFrame[0x0FE]`; the original
   reuses the same storage for all three token buffers.
9. **`fn0800_3D9D` endless loop.**  `while (1) (void)fn0800_3D9D();` -- the
   function owns the quit path (`fn0800_0000`), so 4255 never returns.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg0800_part15.c` -- exit 0, zero diagnostics
  (also clean with `-Wall -Wextra`).
* Reko-token grep (`Eq_[0-9]`, `<invalid>`, `<unknown>`, `SEQ(`, `CONVERT(`,
  `Mem[0-9]*[`, `segptr`, `Eq_17`) -- 0 hits.
* `nm` reports `fn0800_4168` and `fn0800_4255` as `T`.
* Frozen-prototype cross-check (`gcc -Wall` on a TU assigning both
  `seg0800.h` prototypes to matching function pointers) -- exit 0.
