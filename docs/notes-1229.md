# notes-1229 -- segment 1229 recovery notes

## part 1

Source: `src/seg1229_part1.c` -- functions 1229:0000, 0040, 039D, 0486, 050A,
061B (ascending offset).  Ground truth = `analysis/slices/1229/1229_<off>.asm`;
frozen prototypes from `src/seg1229.h` adopted exactly.

### Functions converted

| off  | prototype |
|---|---|
| 0000 | `void fn1229_0000(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)` |
| 0040 | `u8 fn1229_0040(u8 * ptrArg04, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E, u8 * ptrArg10, void * dsOut)` |
| 039D | `void fn1229_039D(void)` |
| 0486 | `u16 fn1229_0486(void)` |
| 050A | `u16 fn1229_050A(u8 bArg02, u8 * ptrArg04, u16 * dsOut)` |
| 061B | `u16 fn1229_061B(s16 * dxOut, u16 * dsOut)` |

### Hardware / dispatch sites

**None.**  No int 10h / int 16h / int 21h, no `in`/`out`, no `__cli`/`__sti`
and no int 23h in 0000..061B.  All DOS/BIOS/keyboard/PIT work is performed by
the callees in segments 1AB8 (text/video), 1EDA (DOS files/strings) and 1E78
(keyboard/PIT), which already own the PAL replacements.

### Stack-frame / calling-convention recovery

* The original's string helpers (`fn1EDA_0A39`, `0A1F`, `0AAC`, `1085`,
  `0F71`) use the CPU stack as a persistent scratch area: a destination far
  pointer is pushed once and left there while the callee pops only its own
  source word(s), reading the staged pointer from `[bx+8]` / `[bx+0Ah]`.  As
  the earlier 1EDA parts did, this is recovered with explicit pointer
  arguments; the buffer offsets (`bp-...`) are kept in comments.
* `fn1229_0040` is reached through a *near* `call` preceded by `push cs`, so
  its far return pointer is `cs:IP`; `retf 0Ch` consumes the 12 bytes of
  `ptrArg04` + four words.  Its output pointer `ptrArg10` ([bp+12h]) is a
  staged far pointer that sits **above** the popped arguments, which is why
  the frozen signature exposes it as an ordinary parameter and why the
  original caller (050A/061B) never pops it explicitly (`leave` discards it).
* `dsOut` parameters are register outputs in the original (DS), not stack
  arguments; the flat port stores 0 (`*(u16 *)dsOut = ...`), per the
  established convention.

### Uncertain / divergent sites

1. **fn1EDA_023F / fn1EDA_0254 argument positions (0040).**  The 1EDA
   implementations bind the real size to `wArg04` and the block pointer to
   `ptrArg06` (`wArg00`/`wArg02` are the far return-address words).  The
   already-committed seg1AB8 thunks (`seg1AB8_part2.c` 051F, `part5a.c`)
   instead pass the size in `wArg00`.  This part follows the 1EDA
   implementation (the code that actually runs), i.e.
   `fn1EDA_023F(0, 0, size, &ds)` and
   `fn1EDA_0254(0, 0, size, block, &dx, &ds)`.  Flagged for cross-part
   reconciliation; no header was modified.
2. **Far-heap block pointer (0040).**  `fn1EDA_023F` returns a 16:16 far
   pointer; the flat port keeps it as `u32` (words at [bp-0104h]/[bp-0102h])
   and casts to `u8 *` when passing it to `fn1AB8_1E6B` / `fn1AB8_13D7` /
   `fn1EDA_0254`, exactly as `seg1AB8` does.  The heap itself is not modelled
   by the port, so the value is a literal 16-bit segment:offset.
3. **fn1EDA_0B24 flag polarity.**  Reko's 1229 slices invert both tests
   relative to the `.asm` (it emits `while (fn1EDA_0B24(...))` at 039D and
   `if (!fn1EDA_0B24(...))` at 061B).  The `.asm` (`jz`/`jnz` after the call)
   and the accepted seg1AB8 convention (nonzero return = strings equal) are
   followed here: break/assign when the return is nonzero.
4. **fn1EDA_0BD0 second argument (0040).**  The `.asm` pushes
   `buf206[0]` (`mov al,[bp+0FDFAh]`); Reko hard-codes `0`.  The `.asm` value
   is used.
5. **fn1E78_030D register inputs (0040).**  The original pushes no arguments;
   Reko hands it the preceding `fn1AB8_1AF6` DX output and `0x0A`.  Reko's
   choice is replicated (it only reaches the rare Ctrl-Break path of
   `fn1E78_0143`; the common path returns the keystroke in AX).
6. **Return values.**  `fn1229_0040` returns the AH byte of `fn1EDA_0254`'s
   result (Reko `SLICE(...,byte,8)`); every caller ignores it.
   `fn1229_050A`/`061B` return only AL meaningfully (AH is unspecified in the
   original); AH is returned as 0.  `fn1229_0486` returns the dropped DGROUP
   selector -> 0.
7. **fn1EDA_1051 `al` argument (039D/0486).**  The recovered callee ignores
   `al`; 0 is passed.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1229_part1.c` -> exit 0, no warnings.
* Reko-artifact token grep (`Mem7[`, `Eq_N`, `<invalid>`, `<unknown>`,
  `SEQ(`, `SLICE(`, `CONVERT(`, `Register `, `Stack `, `out `) -> 0 matches.
* `nm` shows `T` (global text) for fn1229_0000, 0040, 039D, 0486, 050A, 061B.
* Definition signatures compared byte-for-byte against the `extern`
  declarations in the frozen `src/seg1229.h` -> all 6 match.

## part 3

Source: `src/seg1229_part3.c` -- functions 1229:0CCE, 0DCC (ascending offset).
Ground truth = `analysis/slices/1229/1229_<off>.asm`; frozen prototypes from
`src/seg1229.h` adopted exactly.  Part 3 is the in-game mouse/keyboard level
editor loop (`0DCC`) and the "build the menu" helper it calls first (`0CCE`).

### Functions converted

| off  | prototype |
|---|---|
| 0CCE | `void fn1229_0CCE(void)` |
| 0DCC | `u16 fn1229_0DCC(u8 * ptrArg04, u16 * bpOut, u16 * dsOut)` |

### Hardware / dispatch sites

**None.**  Neither function contains an int 10h / int 16h / int 21h, a raw
`in`/`out`, `__cli`/`__sti` or int 23h, so no `pal.h` entry point is
referenced.  All BIOS/hardware traffic goes through segment 133F (mode/menu
drawing, mouse show/hide via 133F:0137/0141), 1AB8 (video primitives, driver
dispatch 1CBA/13D7), 1E78 (beep 02C7/029C/02F4), 13C8 (mouse INT 33h,
`fn13C8_0111`) and 1EDA (DOS/string helpers), replaced in their own ports.

### Cross-segment call adaptations (frozen prototypes are incomplete)

1. **`fn133F_0528` is missing its 7th stack word ([50C7h]).**  The .asm pushes
   three far out-pointers (`ds:62D2`, `ds:62D0`, `ds:62CE`) plus the byte at
   `DGROUP:0x50C7` and `retf 0Eh` pops seven words.  The frozen prototype
   exposes only `(s16 dx, u8 *ptrArg06, u8 *ptrArg0A, u8 *ptrArg0E, ...)`, so
   the `[bp+6h]` flag byte has no slot.  Reko threaded the DX register into
   `dx` instead.  The flag byte is the only value ever placed at that slot, so
   the port passes `(s16)LG8(0x50C7)` as the first argument (the only C slot
   reaching `[bp+6h]`); the callee only tests its low byte.  All five call
   sites go through the file-static `seg1229_scan_0528()`.  The `dx` register
   value Reko fed in is dead (the callee overwrites `dx` before reading it).
2. **`fn133F_04DE` exposes only `ptrArg04`.**  The .asm pushes four more words
   (call value 64h, 192h, 0, 0); the callee reads `[bp+0Eh]`/`[bp+10h]`
   (stored to `0B6B6`/`0B6B8`).  With no parameters they are dropped;
   `fn133F_04DE(&g_seg1229[0x0CCB])` is called, matching the frozen contract.
   Same class of loss documented for 13C8 in notes-13C1-13C8.md.
3. **`fn1EDA_0A39` in `0CCE`.**  Reko's decompiled call arguments
   (`sp+2`, `sp`, `sp+4`) do not match the callee's `[bx+4]/[bx+6]/[bx+0Ah]`
   frame (its negative-offset staging was modelled inconsistently).  The .asm
   push order is used: `bArg04 = 0FFh`, `ptrArg06 = ds:62DEh` (destination),
   `ptrArg0A = cs:0CCCCh` (source).  The two `0DCC` sites agree with Reko.
4. **`fn1229_0735` `bpOut`/`dsOut`** are `void *` in the frozen prototype
   (Reko modelled `bp` as a `memptr`); dummy `u16` locals are passed, as
   seg13C8's wrappers ignore the same slots.
5. **`fn1EDA_0B24` flag polarity.**  The accepted port returns 1 when the two
   records are equal (`seg1EDA_part4b.c`).  The .asm test at 1229:1119 is
   `jnz 112Eh` (ZF clear -> unequal -> restore the name buffers), so the port
   restores when the return is 0 and resets `[5990h:598Eh] = 1` otherwise.

### Uncertain sites

1. **`DGROUP:0x5992` far-pointer table.**  Both `fn1AB8_13D7` sites load a
   32-bit far pointer from `0x5992[idx*4]` (idx = `[62CBh]`, or entry 0 for
   the erase path).  The table is filled at startup by the (unported) 0800
   loader from `fn1EDA_023F` and is all zero in `dgroup_data.bin` (0x5992 is
   in _BSS).  The pointer is reconstructed as
   `(u8 *)(uintptr_t)LG32(slot)`, the convention used for the analogous
   DGROUP slots in docs/notes-1AB8.md.  The far heap itself is not modelled,
   so the value would only be meaningful once the loader/allocator are.
2. **`fn133F_0352` labels.**  The five menu strings are the length-prefixed
   records at `cs:0CB4/0CB9/0CBD/0CC1/0CC6` (`"Swap"`, `"<<-"`, `"+>>"`,
   `"Test"`, `"Quit"`); verified byte-for-byte against `seg1229.bin`.
3. **`dx_1022` (DX register chain).**  The original threads the DX register
   through `133F:0141`/`133F:0528`; it is captured as an `s16` local exactly
   as Reko names it.  Because of adaptation 1 its value no longer reaches the
   0528 call as the `dx` input, which is dead anyway.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1229_part3.c` -> exit 0, no warnings.
* Reko-artifact token grep (`Eq_[0-9]`, `Mem[0-9]+[`, `<invalid>`,
  `<unknown>`, `word16`, `Register `, `Stack `) -> 0 matches.
* `nm src/seg1229_part3.o` -> `T fn1229_0CCE`, `T fn1229_0DCC`
  (`t seg1229_scan_0528` for the file-static helper).
* Definition signatures match the frozen `src/seg1229.h` declarations (the
  header is included, so a mismatch would be a compile error).

## part 2b

Source: `src/seg1229_part2b.c` -- functions 1229:09F9, 0AA8, 0C58 (ascending
offset).  Ground truth = `analysis/slices/1229/1229_<off>.asm`; frozen
prototypes from `src/seg1229.h` adopted exactly.  `0AA8` is the "build the
editor status line / repaint the cell grid" routine called from `0CCE`/`0DCC`;
`0C58` repaints the 4x25 tile board after a `Swap`; `09F9` is the shared
zero-padded 3-digit number formatter.

### Functions converted

| off  | prototype |
|---|---|
| 09F9 | `void fn1229_09F9(u8 bArg02, u8 * ptrArg04)` |
| 0AA8 | `u16 fn1229_0AA8(void)` |
| 0C58 | `void fn1229_0C58(void)` |

### Hardware / dispatch sites

**None.**  No int 10h / int 16h / int 21h, no raw `in`/`out`, no `__cli`/`__sti`
and no int 23h in 09F9..0C58.  All video/text work is performed by the callees
in segment 1AB8 (`0F93`, `1028`, `14F4`, `1536`, `13D7`, `1D82`) and all
DOS/string work by segment 1EDA (`0F26`, `0A1F`, `0AAC`, `0A39`), replaced in
their own ports.

### Stack-frame / staging recovery

* `09F9` is called via a *near* `call` with the output far pointer pushed first
  and the byte argument pushed last; `ret 2h` pops only the byte, leaving the
  output pointer staged on the caller's stack.  The caller `0AA8` then chains
  several `fn1EDA_0AAC` appends against that same staged pointer.  Recovered
  with an explicit `u8 *` argument, per the part 1/3 convention.
* `0AA8`'s `enter 602h` frame holds six 0x100-byte records:
  `[bp-0202h]` (the accumulated line / staged destination),
  `[bp-0302h]`/`[bp-0402h]`/`[bp-0502h]`/`[bp-0602h]` (the four `09F9` scratch
  outputs) and `[bp-0102h]` (the final rendered line).  Each `09F9` result is
  immediately appended into `[bp-0202h]` (`0AAC` with src = scratch, dest =
  accumulator), exactly reproducing the original's push/`retf 4h` chain.
* `09F9` zero-pads its number to 3 digits by *prepending* the literal
  `cs:09F7h` (`{1,"0"}`): the `< 0Ah` branch prepends twice, the `< 64h` branch
  prepends once, so 0..9 -> "00X", 10..99 -> "0XX", >=100 -> "XXX".

### Uncertain / divergent sites

1. **`0x5992` far-pointer table.**  Both `fn1AB8_13D7` sites load a 32-bit far
   pointer from `DGROUP:0x5992[idx*4]` (idx = the cell byte, or the running
   `[6CBAh]` index).  Reconstructed as `(u8 *)(uintptr_t)LG32(...)` with the
   whole sum cast to `u16`, the convention already used in part 3 and
   docs/notes-1AB8.md.  The table is filled at startup by the (unported) 0800
   loader and is zero in `dgroup_data.bin`; the heap is not modelled.
2. **Reko struct-member string offsets (`&cs->t0A8B + n`).**  Reko names the
   literals as members of `struct Eq_53657`; the `.asm` `mov di,<imm>` values
   are used verbatim: `0A8Bh` `{1," "}`, `0A8Dh` `{5,"TIME:"}`, `0A93h`
   `{6," PUSH:"}`, `0A9Ah` `{6," BLOW:"}`, `0AA1h` `{6," PASS:"}` (verified
   byte-for-byte against `data/segments/seg1229.bin`).
3. **`fn1229_09F9` `< 64h` test.**  Reko prints `100`; the `.asm` is an
   unsigned `cmp byte ptr [bp+4h],64h` / `jnc`, so `if (bArg02 < 100)`.
4. **Return value of `0AA8`.**  Reko returns `ds_227` (the DS register output of
   `fn1AB8_1536`), a dropped DGROUP selector; the frozen prototype is `u16`, so
   the captured `ds_227` is returned (the 1AB8 port stores 0 there).  All
   callers cast it to `void`.  Same convention as `fn1229_0486` in part 1.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1229_part2b.c` -> exit 0, 0 warnings.
* Reko-artifact token grep (`Mem[0-9]*[`, `Mem7[`, `Eq_[0-9]`, `<invalid>`,
  `<unknown>`, `SEQ(`, `SLICE(`, `CONVERT(`, `Register `, `Stack `) -> 0 matches.
* `nm` -> `T fn1229_09F9`, `T fn1229_0AA8`, `T fn1229_0C58`.
* Definition signatures match the frozen `src/seg1229.h` declarations (the
  header is included, so a mismatch would be a compile error).

## part 2a

Source: `src/seg1229_part2a.c` -- function 1229:0735 (one function).  Ground
truth = `analysis/slices/1229/1229_0735.asm`; frozen prototype from
`src/seg1229.h` adopted exactly.  0735 is the in-game "edit the saved-game
record" dialog: it draws two name/box rectangles, runs two `fn1229_0040`
text-entry dialogs, re-encodes the five edited fields with `fn1229_050A`, then
rewrites the 0x219h-byte RAD.DAT record through the 1EDA stream helpers.

### Functions converted

| off  | prototype |
|---|---|
| 0735 | `u8 fn1229_0735(s16 * dxOut, void * bpOut, void * dsOut)` |

### Hardware / dispatch sites

**None.**  0735 contains no int 10h / int 16h / int 21h, no raw `in`/`out`, no
`__cli`/`__sti`, no int 23h and no raw IVT dispatch.  All BIOS/hardware
traffic goes through segment 133F (mouse cursor show/hide 0137/0141 ->
13C8 INT 33h), segment 1AB8 (video/text primitives 10CE/10E1/1C32) or segment
1EDA (DOS stream file helpers 0FA2/0FD0/1123/108C/116A/1051 plus the
pending-error trap 04A9), all replaced in their own ports.  No `pal.h` entry
point is referenced.

### Stack-frame / staging recovery

* `enter 79Ch,0` frame, reproduced as named buffers whose bp-relative offsets
  are kept in comments: `[bp-079Ch]` (2nd 0040 output), `[bp-069Ch]` (1st
  0040 output, later 0A6B scratch), `[bp-059Ch]` (staged prompt / 0040 input),
  `[bp-049Ch]` / `[bp-039Ch]` (name copies), `[bp-0080h]` (DOS stream block).
  Note `[bp-029Ah]` .. `[bp-082h]` is one contiguous 0x219h record (exactly the
  size passed to `fn1EDA_0FD0`), carved into the fields the original writes
  individually: `buf29A[6]`, `bLoc293`, `buf274[6]`, `buf26E[0x1ED]`.
* As in parts 1/2b/3, the 1EDA record helpers stage a destination far pointer
  on the CPU stack and pop only their own source (`retf 4h` for
  0A1F/0AAC, `retf 8h` for 0A6B), or pop all arguments (0A39 `retf 0Ah`,
  0953 `retf 0Ah`).  Recovered with explicit pointer arguments.  The staged
  destinations are `[bp-059Ch]` for the 0A1F/0AAC prompt chain and
  `[bp-069Ch]` for the lone "append the 0A6B result" 0AAC.
* The four rectangle words per dialog are pushed before the string chain and
  consumed later by `fn1229_0040`'s `retf 0Ch`; the persistent output pointer
  `[bp-069Ch]` / `[bp-079Ch]` sits above the popped arguments.  This is why
  the two `fn1229_0040` calls are `fn1229_0040(buf59C, wArg08, wArg0A, wArg0C,
  wArg0E, outbuf, &ds)` in the frozen signature.
* `fn133F_0137` returns BP (a pass-through of the caller's frame pointer).
  Every Reko `bp_11 - N` reference is recovered as the local buffer at that
  bp-relative offset, exactly as part 3 did for `fn1229_0DCC`; the captured
  `bp_11` itself is only passed and discarded.

### Uncertain / divergent sites

1. **`fn1EDA_04A9` is register-preserving.**  In the original, 04A9 only
   inspects DGROUP:0x5380 and `retf`s without touching DX:AX, so the
   `or al,al` (at 1229:0941) and the `sub ax,2h ; sbb dx,0h` (at
   1229:09C4) consume the value left by the preceding helper
   (1185 / 116A).  The port's `fn1EDA_04A9` returns 0 on the surviving path
   (its `retf` cannot be reproduced), so the value is captured from the
   helper itself (`b_1185 = fn1EDA_1185(...)`, `ax_920 = fn1EDA_116A(...)`)
   and the 04A9 trap is still issued for the fatal-error path.  Tests the
   1185 result after the trap, matching the original AL.  The `al` passed to
   the two `fn1EDA_108C` calls (`al_758` from 1123, `al_825` from the first
   0A39) reproduces the surviving AX; the port's 1091 ignores AL.
2. **`fn1EDA_108C`/`1091` drop the record data buffer.**  The original pushes
   the data buffer far pointer (`ds:5CB4h` for the first write, `[bp-029Ah]`
   for the second) as 1091's `[bp+6h]`; the frozen prototype dropped it and the
   flat port reads `g_1EDA_io_buffer`.  Consequently the bytes written to
   `buf274`/`bLoc293` (part of the second record) have no visible reader in
   the port; the writes are recovered literally and the buffers marked read
   to keep `-Wall` clean.  Same documented divergence as part 1's 039D/0486.
3. **Reko `bpOut` dereference.**  Reko emits `bp_977 = (…) (ss->*bp_962)`,
   i.e. it dereferences the BP output of 133F:0141 at the segment/offset it
   names.  Since the flat port has no SS selector and the caller (0DCC) passes
   a throwaway `u16` and ignores it, the raw `bp_962` is stored, matching
   part 3's convention.
4. **`fn133F_0137`/`0141` `bpOut`/`dsOut` are register outputs.**  The
   prototype types `dsOut` as `void *`; the flat port stores the dropped
   selectors (0) there.
5. **Rectangle sign.**  The four `cwd ; idiv cx` pairs are signed 16-bit
   divisions by 2 followed by `add/sub`; recovered as
   `(u16)(((s16)fn1AB8_10CE() / 2) +/- const)` exactly as part 1's 050A/061B.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1229_part2a.c` -> exit 0, 0 warnings.
* Reko-artifact token grep (`Mem[0-9]*[`, `Mem7[`, `Eq_[0-9]`, `<invalid>`,
  `<unknown>`, `SEQ(`, `SLICE(`, `CONVERT(`, `Register `, `Stack `, `word16`,
  `out `) -> 0 matches.
* `nm` -> `T fn1229_0735`.
* Definition signature matches the frozen `src/seg1229.h` declaration
  `u8 fn1229_0735(s16 * dxOut, void * bpOut, void * dsOut)` (the header is
  included, so a mismatch would be a compile error).
