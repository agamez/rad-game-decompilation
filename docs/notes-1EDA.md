# Notes: segment 1EDA (chunk 1)

Chunk 1 = functions `1EDA:0000 .. 1EDA:01DF` (12 functions):
`0000, 00E2, 00E9, 00ED, 00FC, 011B, 01A5, 01B3, 01BF, 01CD, 01D4, 01DF`.
Output: `src/seg1EDA_part1.c`.  Ground truth = `analysis/slices/1EDA/1EDA_<off>.asm`;
structure from the Reko decompilation.  Frozen prototypes adopted verbatim from
`src/seg1EDA.h`; no header was modified.

## chunk 1

### Functions converted

| offset | function | role |
| --- | --- | --- |
| 0000 | `fn1EDA_0000` | CRT DGROUP/heap init: saves the 0x13 vectors listed at `1EDA:01EE`, installs handlers 00/23/24/3F, builds the `DGROUP:0B8BC`/`0B9BC` blocks |
| 00E2 | `fn1EDA_00E2` | `pop cx ; pop bx ; jmp 00EDh` tail entry into the fatal-error dispatcher |
| 00E9 | `fn1EDA_00E9` | `fn1EDA_00ED(ax, 0, 0)` |
| 00ED | `fn1EDA_00ED` | stores `ax` into `5376h`, dispatches to `011B` (exit) or `00FC` (lookup) |
| 00FC | `fn1EDA_00FC` | walks the `DGROUP:5354` block chain, converts the match to a DGROUP-relative offset |
| 011B | `fn1EDA_011B` | releases the two blocks, restores the 0x13 vectors, prints the Borland "Runtime error" banner, `msdos_terminate` |
| 01A5 | `fn1EDA_01A5` | prints a NUL-terminated image string via `01E7` |
| 01B3 | `fn1EDA_01B3` | prints a byte as decimal (two `01BF` calls) |
| 01BF | `fn1EDA_01BF` | unsigned divide, prints quotient digit, returns remainder |
| 01CD | `fn1EDA_01CD` | prints AX as two hex bytes |
| 01D4 | `fn1EDA_01D4` | prints AL as two hex nibbles |
| 01DF | `fn1EDA_01DF` | prints a nibble as a hex digit |

### DOS service map (int 21h)

| site | AH | replacement |
| --- | --- | --- |
| `1EDA:0034` (loop, 0x13 entries from the table at `1EDA:01EE`) | 35h | `msdos_get_interrupt_vector` |
| `1EDA:0062/006C/0076/0080` | 25h | `msdos_set_interrupt_vector` (vec 00, 23, 24, 3F) |
| `1EDA:015C` (loop, 0x13 entries) | 25h | `msdos_set_interrupt_vector` (restore) |
| `1EDA:019E` | 4Ch | `msdos_terminate` |
| `1EDA:00F2` | - | `sti` dropped (CONVENTIONS.md rule 4) |
| `1EDA:012D` | - | far jump through `DGROUP:5372` dropped (Reko drops it; the chain is never installed) |

`fn1EDA_01E7` (out of range, offset 01E7) issues the `int 21h` AH=06h console
write; it is only called here.

### Shared staging

None.  All state lives in DGROUP (`g_dgroup`) or the segment image
(`g_seg1EDA`); no file-scope variable is shared with a function outside this
chunk, so `src/seg1EDA_shared.h` was not created.

### Uncertain sites / portability

1. **Saved interrupt vectors are stored as 32-bit values.**  The original stores
   the `BX:ES` pair at `DGROUP:0BABC + i*4`; the port stores
   `(u32)(uintptr_t)msdos_get_interrupt_vector(vec)` and restores it with
   `(void *)(uintptr_t)LG32(...)`.  This matches the existing convention in
   `fn1E5F_0159`.
2. **Heap-base words (`5348/534E/5350/5352/535C/5360/5368`).**  `fn1EDA_0000`
   computes `ss + ((sp + 0x13) >> 4)` from the real-mode SS:SP registers, which
   do not exist in the flat host.  Both stand-ins are zero, so the derived words
   are not meaningful.  `[5348]` is zero in `dgroup_data.bin`, so
   `[5352] = [535C] = [5360] = [5368] = ax_15`; the only downstream readers are
   the (unconverted) allocator/blit helpers.  Documented, not invented.
3. **`DGROUP:5370 = cs`.**  Stored as the literal code selector `0x1EDA`
   (consistent with `fn1AB8` storing `0x1AB8` and `DGROUP:536E = 0xA9`).
4. **`DGROUP:537C = es`.**  The original stores the PSP selector; the flat port
   stores the low word of the `es` pointer.  Only consumed by the (dead)
   `00FC` block-chain arithmetic.
5. **`DGROUP:5354` block chain (`fn1EDA_00FC`).**  No recovered code ever writes
   this cell (it stays 0), so the chain walk is unreachable; the segmented node
   fetches are modelled by a file-static `far_heap_word()` returning 0.
6. **`fn1EDA_0000` return.**  The `.asm` leaves AX = 0 on the normal path
   (REPORT.md); the sole caller only keeps the word as a dropped ds selector.
   The port returns `0`.
7. **`fn1EDA_00ED`/`fn1EDA_00E9` return.**  The DOS DS selector `2014h` is
   returned as the flat DGROUP base `g_dgroup`; callers only pass it as a
   (dropped) ds argument.
8. **`fn1EDA_00E2` outputs.**  `cxOut` receives the popped CX (Reko's `wArg00`).
   The dispatcher never returns, so `dxOut`/`bxOut` are left unwritten and the
   `dsOut` selector output is dropped (CONVENTIONS.md).
9. **`fn1EDA_01D4`.**  Reko read an uninitialised AX; the `.asm` shows
   `push ax ... pop ax`, so the input `al` is used directly.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1EDA_part1.c` — zero errors, zero warnings
  (also clean with `-Wextra`).
* Reko-token grep (`Eq_[0-9]`, `MemN[`, `<invalid>`, `<unknown>`) — 0 matches.
* All 12 functions defined with the exact frozen prototypes and reported `T`
  by `nm`.

## chunk 4

Range: 1EDA:081A .. 1EDA:0A1F (11 functions, ascending).
Source: `src/seg1EDA_part4.c`.  Ground truth = `analysis/slices/1EDA/1EDA_<off>.asm`.

### Functions converted

| offset | function | role |
| --- | --- | --- |
| 081A | `fn1EDA_081A` | read to CR, consume one following LF, then flush (0776/079A/0879) |
| 0848 | `fn1EDA_0848` | append CR LF (07B6/07DA/0879) |
| 086C | `fn1EDA_086C` | flush only (0879) |
| 0879 | `fn1EDA_0879` | invoke block callback at +0x18; latch AX into DGROUP:0x5380 |
| 0896 | `fn1EDA_0896` | read length-prefixed line (max `wArg04`) into `ptrArg06` (0776/079A) |
| 08CE | `fn1EDA_08CE` | write length-prefixed string, right-padded to width `wArg04` (07B6/07DA) |
| 0918 | `fn1EDA_0918` | single-char scan; returns 1 on 1Ah (0776/079A) |
| 0953 | `fn1EDA_0953` | `rep movsb` copy (`wArg04` bytes `ptrArg0A` -> `ptrArg06`) |
| 096F | `fn1EDA_096F` | 16.16 fixed multiply via the 8086 `mul` sequence |
| 098A | `fn1EDA_098A` | signed 32-bit restoration division (`dx:ax / bx:cx`) |
| 0A1F | `fn1EDA_0A1F` | length-prefixed string copy (`lodsb`/`stosb`/`rep movsb`) |

### DOS-service map (int 21h)

None. No function in this range issues int 10h / int 16h / int 21h or port
I/O.  The only external effects are the DGROUP error word 0x5380 (`LG16`) and
`fn1EDA_098A`'s divide-by-zero tail-call into the same-segment fatal-error
dispatcher `fn1EDA_00E2(200, wArg00, wArg02, ...)`.

### Shared staging

None.  No file-scope variable is shared with a function outside this range;
all state is DGROUP (`g_dgroup` / LG macros) or the caller-supplied stream
block.  `src/seg1EDA_shared.h` was not created.

### Uncertain sites / portability

1. **Cursor out-params are pointer-typed in iface.tsv.**  `fn1EDA_0776`,
   `fn1EDA_07B6` and `fn1EDA_07DA` declare `es_bxOut` as `u8 *` although Reko
   models it as a `segptr32 &` output.  The call sites pass
   `(u8 *)&cursor_var` (the frozen header cannot be changed); the callee is
   expected to reinterpret it as `u8 **`, consistent with the Reko out-param.
   Reko local names are kept.
2. **079A's DX slot width.**  `fn1EDA_079A` takes `dx` as `u8 *` and `dxOut`
   as `void *`, while `0776`/`07B6` produce a `u16` DX.  A local union
   (`dx_cur_t { u16 w; u8 *p; }`) carries both interpretations of the same
   16-bit cursor/limit word without overrunning the caller's storage.
3. **Stream block model.**  The block is the Turbo-C stream descriptor built
   by `fn1EDA_04F5`/`fn1EDA_0565`/`fn1EDA_056A`: +0x02 id, +0x04 limit (07B6
   path), +0x08 cursor, +0x0A limit (0776 path), +0x0C/+0x0E buffer far
   pointer, +0x14/+0x18 callbacks, +0x1A callback segment word.  Cursor and
   limit are 16-bit offsets carried in pointer-typed slots; `obj[+8]` stores
   the final cursor.
4. **`fn1EDA_0879` callback.**  +0x18/+0x1A is a far callback; the flat port
   treats +0x18 as a host function pointer and keeps the literal +0x1A
   "installed?" test (nonzero for a real host pointer).  Callback signature
   `u16 (*)(u8 *)`; a nonzero result is latched into 0x5380.
5. **`fn1EDA_081A` / `fn1EDA_0848` return.**  Reko returns DS (the DGROUP
   selector), dropped in the flat model; both return 0.  The only caller
   (`fn0800_391E`) ignores it.
6. **`fn1EDA_0918` return.**  The .asm sets AL = 0/1 (`mov al,0h`/`mov al,1h`
   at 0943/0947); the iface.tsv note calls it a dropped DGROUP selector.  The
   recovered code returns the ground-truth `0`/`1` as `u16` (all callers
   ignore it).
7. **`fn1EDA_0896` cursor advance.**  079A does not advance the cursor; the
   caller's `inc bx` does.  Reko folded the increment into
   `es_bx = es + (bx+1) + 1` (an extra +1); the recovered code advances exactly
   once (`es_bx = es + bx_after_inc`), matching the .asm.
8. **`fn1EDA_08CE` return AH.**  Rests on 07DA's `ahOut`; the last non-refill
   write leaves AH = 0.  The recovered code returns the captured AH (only
   `fn13E2_0193` consumes it).
9. **`fn1EDA_096F`.**  Reko emits
   `SEQ((word16)p + bx*ax + cx*dx, SLICE(p,16,16))`, which byte-swaps the
   result (wrong even for dx=bx=0).  Recovered per the .asm `mul` sequence:
   `low = low(ax*cx)`; `high = high(ax*cx) + low(ax*bx) + low(dx*cx)`.
10. **`fn1EDA_098A`.**  Literal 33-iteration restoring division with explicit
    16-bit sign handling (the `pushf`/`popf` pairs).  `dsOut` is written as the
    flat DGROUP base `g_dgroup` (Reko leaves it uninitialised on the normal
    path); the divide-by-zero path forwards `fn1EDA_00E2`'s `dsOut`.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1EDA_part4.c` — exit 0, zero diagnostics
  (also clean with `-Wextra`).
* Reko-token grep (`Eq_[0-9]`, `Mem[0-9]*[`, `<invalid>`, `<unknown>`) — 0.
* `nm` reports all 11 functions `T` with the exact frozen prototypes.
* Link/run harnesses (stubs for the out-of-range callees) exercised
  `fn1EDA_096F` (incl. a nonzero dx/bx product), `fn1EDA_098A` (+/-, 32-bit and
  divide-by-zero cases), `fn1EDA_0953`, `fn1EDA_0A1F`, and the stream drivers
  `fn1EDA_0896` / `fn1EDA_081A` / `fn1EDA_08CE` / `fn1EDA_0848` /
  `fn1EDA_0918` — all pass.

## chunk 2b

Range: 1EDA:03D3 .. 1EDA:04B7 (6 functions, ascending).
Source: `src/seg1EDA_part2b.c`.  Ground truth = `analysis/slices/1EDA/1EDA_<off>.asm`.

### Functions converted

| offset | function | role |
| --- | --- | --- |
| 03D3 | `fn1EDA_03D3` | validate a free-list insertion range and relink (0491/0432) |
| 0432 | `fn1EDA_0432` | coalesce/split helper: normalizes the low byte, relinks a node |
| 0491 | `fn1EDA_0491` | `AX=(ax+7)&8`; also leaves `DX=((ax+7)>>4)\|(CF<<12)` |
| 04A2 | `fn1EDA_04A2` | atomic read-and-clear of the DOS error word DGROUP:0x5380 |
| 04A9 | `fn1EDA_04A9` | pending-error trap: tail-enters `00E2` if DGROUP:0x5380 != 0 |
| 04B7 | `fn1EDA_04B7` | INT 33h fn 13h bounds check; signs `dx`, `ax` unsigned |

### DOS-service map (int 21h)

None issued directly in this range.  `fn1EDA_04A9` (1EDA:04B1) and
`fn1EDA_04B7` (1EDA:04D9) tail-jump to the same-segment fatal-error dispatcher
`fn1EDA_00E2`, which performs the `msdos_set_interrupt_vector` /
`msdos_terminate` work (chunk 1).  The dispatcher never returns.  `04B7`'s
`wArg00`/`psegArg02` are the caller's return-address words that `00E2` pops as
the error location (the same convention as chunk 1's `fn1EDA_00E2`).

### Shared staging

`src/seg1EDA_shared.h` was **created** (include guard `SEG1EDA_SHARED_H`).
`fn1EDA_0491` computes a 32-bit DX:AX result but its frozen prototype returns
only AX, so the high half is latched in the file-scope `u16 g_0491_dx`,
declared `extern` in the shared header and defined in `src/seg1EDA_part2b.c`.
`fn1EDA_03D3` (in range) reads it; `fn1EDA_0308` (offset 0308, out of range)
consumes the same DX in its free-list walk and must include the shared header.
Within-range helpers (`far_heap_word`, `far_heap_setword`) stay file-static.

### Uncertain sites / portability

1. **Far-heap model (03D3/0432).**  The original walks and relinks a far-heap
   free list headed at DGROUP:0x5366 (nodes addressed `segment:offset`).  The
   flat port does not re-create the DOS far heap (its base words are zero; see
   chunk 1, note 2), so reads/writes are modelled by static
   `far_heap_word`/`far_heap_setword` accessors, exactly as chunk 1 did for
   `fn1EDA_00FC`.  Segment 0x2014 (DGROUP) is resolved through the LG macros so
   the head pointer reads the flat image; other segments return 0 / ignore
   writes.  With the uninitialised heap the 03D3 walk cannot terminate for a
   nonzero block segment, but the path is unreachable in the port.
2. **Far values carried in pointer slots.**  Per the project convention,
   segment:offset values cross the `u8 *` parameters of `fn1EDA_0432` by bit
   casting (`(u8 *)(uintptr_t)value`, recovered as
   `(u16)(uintptr_t)p` / `(u16)((uintptr_t)p >> 16)`), matching part4's rule.
3. **`fn1EDA_03D3` `dxOut` width.**  iface.tsv types `dxOut` as `void *`, but
   the register output is the 16-bit DX of the second `fn1EDA_0432` call (the
   caller `fn1EDA_0254` declares its own `dxOut` as `u16 *`).  Two bytes are
   stored; the error/zero paths store 0 where Reko leaves DX uninitialised.
4. **`fn1EDA_04A9` return.**  The taken `retf` (DGROUP:0x5380 == 0) leaves
   DX:AX untouched so the caller's `AL` survives (`or al,al` idiom).  The flat
   prototype cannot express a register-preserving return, so the surviving
   path returns 0 — documented, not invented.  The `chOut` register output is
   Reko's `<undefined>` and is not written.
5. **`fn1EDA_04B7` segment source.**  The frozen `di` is a flat `u8 *`; the
   original's `mov es,ss:[si+2h]` recovers the caller's CS (segment 13C8) so
   that `es:[di+...]` reads the caller-local structure at CS:0109.  The flat
   caller passes that structure's address directly, so `di` is dereferenced as
   a flat pointer and `wArg00`/`psegArg02` remain only the fatal-error words.
6. **`fn1EDA_0491` carry.**  The .asm uses the carry out of the 16-bit
   `add ax,7h` as the carry-in to `rcr dx,1` (Reko models this as bit 1 of the
   32-bit sum); recovered as `((u32)ax + 7) > 0xFFFF`.
7. **`fn1EDA_04A2` return.**  The emitted prototype returns `u8` (AL) although
   the .asm's `xchg` loads a full word into AX; the low byte is returned.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1EDA_part2b.c` — exit 0, zero diagnostics
  (also clean with `-Wextra`, and with `-Wconversion`).
* Reko-token grep (`Eq_[0-9]`, `Mem[0-9]*[`, `<invalid>`, `<unknown>`) — 0.
* `nm` reports `fn1EDA_03D3`, `fn1EDA_0432`, `fn1EDA_0491`, `fn1EDA_04A2`,
  `fn1EDA_04A9`, `fn1EDA_04B7` as `T`; only the two far-heap helpers are `t`.
* The definitions were compiled against `src/seg1EDA.h`, so any signature
  divergence from the frozen prototypes would have been a compile error.

## chunk 3a

Range: 1EDA:04F5 .. 1EDA:05FB (6 functions, ascending).
Source: `src/seg1EDA_part3a.c`.  Ground truth = `analysis/slices/1EDA/1EDA_<off>.asm`.

### Functions converted

| offset | function | role |
| --- | --- | --- |
| 04F5 | `fn1EDA_04F5` | build a stream block (id `0xD7B0`, 0x80-byte buffer pointer, zeroed `+0x14..+0x2F` callback slots, source string copied to `+0x30` truncated to `0x4F`) |
| 0565 | `fn1EDA_0565` | `mov dx,0D7B1h ; jmp 0572h` tail thunk; returns the surviving DX |
| 056A | `fn1EDA_056A` | `mov dx,0D7B2h ; jmp 0572h` tail thunk |
| 0572 | `fn1EDA_0572` | id-select + reopen: `0xD7B1/0xD7B2` -> close old buffer via 05BF, then install id, clear cursor/limit, dispatch `+0x10` open callback through 05FB; unknown id -> error word `0x66` |
| 05BF | `fn1EDA_05BF` | close: `0xD7B1` -> dispatch `+0x1C`; `0xD7B2` -> dispatch `+0x14` then `+0x1C`; unknown id -> error word `0x67`; forces id `0xD7B0` |
| 05FB | `fn1EDA_05FB` | indirect dispatch of the callback at `block+BX` (`call dword ptr es:[bx+di]`), latch nonzero AX into DGROUP:0x5380, return ZF as `AX==0` |

### DOS-service map (int 21h)

None issued by any of the six functions.  They are the stream open/close layer;
the int 21h file services (3Ch/3Dh/3Eh/3Fh/40h/42h/44h) live in the original
stream callbacks at `1EDA:060C/068E/06E8/0718/075D`, which are **not** recovered
functions (see "Uncertain sites" below).

### Shared staging

None.  No file-scope variable is shared with a function outside this range; all
state is DGROUP (`g_dgroup` / `LG16(0x5380)`) or the caller-supplied stream
block.  `src/seg1EDA_shared.h` was not modified (its existing `g_0491_dx` is not
used here).

### Uncertain sites / portability

1. **Unrecovered stream callbacks (the central gap).**  04F5 stores the literal
   open-callback offset `0x060C` at `+0x10`, and 05BF/0572 dispatch the slots at
   `+0x14`/`+0x1C`; those targets (`1EDA:060C`, and the `068E/06E8/0718/075D`
   thunks it installs) are the region Reko left undecoded inside
   `fn1EDA_05FB`'s symbol range.  They are absent from
   `analysis/slices/1EDA/index.tsv` and `analysis/summary/iface.tsv` (no frozen
   prototype), so no translation unit defines them and they cannot be invoked
   from flat C.  Following the chunk-4 `fn1EDA_0879` convention, 05FB treats the
   slot as a host function pointer (`(u16 (*)(u8 *))*(void **)(es_bx+di)`); the
   block is therefore not actually openable until those callbacks are recovered.
   The stream open/close path is reached at startup (`fn1EDA_0000` -> 0565/056A)
   and shutdown (`fn1EDA_011B` -> 05BF), so this is a real project-level gap, not
   a local one.  Recorded, not invented.
2. **Selector fields dropped.**  04F5's buffer far pointer keeps its literal
   offset `((word16)base + 0x80)` at `+0x0C` but its DS selector is stored as 0 at
   `+0x0E`; the `+0x10` callback offset `0x060C` keeps a 0 CS selector at `+0x12`
   (same convention as `fn1E78_032F` in `src/seg1E78.c`).  Reko's `t000E = es`
   / `t0012 = cs` selectors have no flat representation.
3. **05FB ABI.**  At entry the original has BX = callback-slot offset
   (`0x10/0x14/0x1C`) and ES:DI = block, so `es:[bx+di]` resolves to
   `block + BX`.  The frozen prototype is `(u8 * es_bx, u16 di)`; the flat call
   sites pass `(block, offset)` (the header cannot be changed).  The two `push
   es ; push di` pairs are the saved-register pair plus the one far block
   argument the callback's `retf 4h` pops; they collapse to a single C argument.
4. **05FB return / 05BF return.**  `or ax,ax` sets the ZF the callers test; the
   frozen `u8` return therefore carries `(callbackAX == 0)`.  `fn1EDA_05BF`
   starts with `mov al,1h` but leaves AX = the last 05FB AL at the `retf`; its
   `u16` return is modelled as that AL (the original AH is undefined).  Reko's
   `return ptrArg04` for 05BF is not supported by the `.asm`; callers
   (`fn0800_0D20`, `fn0800_2C0C`, `fn0800_391E`, `fn1EDA_011B`) all discard it.
5. **`fn1EDA_0565` return.**  The `jmp 0572h` tail means DX = `0xD7B1` survives
   the callee's `retf 4h`; Reko models that as the `u16` result, so the flat
   function returns the literal constant.  Every caller ignores it.
6. **0572 vs Reko's switch (ground-truth correction).**  Reko's decompilation
   groups id `0xD7B0` with `default` (store error `0x66` and return).  The `.asm`
   compares `ax,0D7B0h ; jz 059Bh`, i.e. `0xD7B0` **falls through to the 059B
   body**.  The recovered code follows the `.asm`: only an id other than
   `0xD7B1/0xD7B2/0xD7B0` takes the error path.
7. **Out-of-scope bytes.**  The `.asm` slices end with undecoded trailing bytes
   that belong to neighbouring routines: `1EDA:053A..0564` (inside
   `fn1EDA_04F5`'s symbol range; a 3-stack-word block-field setter with no caller
   anywhere in the image) and `1EDA:060C..0775` (inside `fn1EDA_05FB`'s symbol
   range).  Neither is an `index.tsv` `kind=fn` row in this range, so neither is
   converted here.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1EDA_part3a.c` — exit 0, zero diagnostics
  (also clean with `-Wextra`).
* Reko-token grep (`Eq_[0-9]`, `Mem[0-9]*[`, `<invalid>`, `<unknown>`) — 0.
* `nm` reports all six functions `T`: `fn1EDA_04F5`, `fn1EDA_0565`,
  `fn1EDA_056A`, `fn1EDA_0572`, `fn1EDA_05BF`, `fn1EDA_05FB`.

## chunk 2a

Range: 1EDA:01E7 .. 1EDA:0308 (4 functions, ascending).
Source: `src/seg1EDA_part2a.c`.  Ground truth = `analysis/slices/1EDA/1EDA_<off>.asm`.

### Functions converted

| offset | function | role |
| --- | --- | --- |
| 01E7 | `fn1EDA_01E7` | `int 21h` AH=06h direct console output (DL=AL) |
| 023F | `fn1EDA_023F` | allocate: call 0308; success -> DX:AX = block, failure -> error 0xCB |
| 0254 | `fn1EDA_0254` | free: call 03D3; failure -> error 0xCC |
| 0308 | `fn1EDA_0308` | far-heap allocator core: free-list walk, split/exact-fit relink, high-water grow |

### DOS-service map (int 21h)

| site | AH | replacement |
| --- | --- | --- |
| `1EDA:01EB` | 06h (DL != FF) | **none in `pal/pal.h`.** See uncertainty 1: the byte is written to the host console by the file-static `dos_console_output()`. |

No other function in the range issues an `int 10h`/`int 16h`/`int 21h` or port I/O.

### Shared staging

`fn1EDA_0308` consumes the DX half of `fn1EDA_0491`'s result through the
existing `extern u16 g_0491_dx` in `src/seg1EDA_shared.h` (defined in
`src/seg1EDA_part2b.c`); `src/seg1EDA_shared.h` was **not** modified.  No new
cross-part state is required.  The within-range helpers `far_heap_word`,
`far_heap_setword`, `heap_grow` and `dos_console_output` are file-static.

### Uncertain sites / portability

1. **Console-output entry point missing from the PAL contract.**  The original
   at `1EDA:01E7` is `mov dl,al ; mov ah,6h ; int 21h` (direct console output).
   `pal/pal.h` exposes only `msdos_direct_console_input()` (the sibling AH=06h
   DL=FF input half) and no output entry point; the chunk constraints forbid
   editing `pal.h`.  The byte is therefore written to the host console by
   `dos_console_output()` (`putchar`).  This is the only DOS/hardware deviation
   in the chunk and is required for the Borland "Runtime error" banner (called
   from `fn1EDA_011B`) to remain visible.
2. **Far-heap model (0308), same convention as chunks 1 and 2b.**  The original
   walks a free list of `segment:offset` nodes headed at DGROUP:0x5366.  The flat
   port cannot re-create the DOS far heap, so `far_heap_word`/`far_heap_setword`
   resolve only segment `0x2014` (DGROUP) through the `LG` macros and treat every
   other segment as 0 / ignore writes.  In particular the remainder node and the
   high-water block computed by 0308 land in the paragraph-advanced segment
   (e.g. `0x2016`), so their fields are not physically stored; only the DGROUP
   list pointers are updated.  The allocator is therefore not runnable in the
   port until the heap is modelled — recorded, not invented.
3. **Indirect far call through DGROUP:0x536E / 0x5370.**  `1EDA:039C` and
   `1EDA:03BB` `call dword ptr [536Eh]`.  `fn1EDA_0000` installs the shipped
   stub `1EDA:00A9` (`xor ax,ax ; retf 2`, consumes one word and returns 0)
   there; `seg1AB8` temporarily installs `1AB8:050B` only around its own direct
   helper call and restores the vector before any allocator use.  A 16:16 code
   pointer is not callable from flat C, so both sites call the file-static
   `heap_grow()` stub.  At `039C` the argument is 0; at `03BB` it is the requested
   size `[0BB08h]`.
4. **`ds` register outputs (023F, 0254).**  Both write the DGROUP selector in DS
   (`dsOut = ds`).  The selector is dropped in the flat model: the `u16 *dsOut`
   slots are stored as 0, matching `fn1EDA_04A9` (chunk 2b) and `fn1AB8_0887`.
5. **Pre-existing caller mismatch in `src/seg1AB8_part2.c` (not modified).**
   `fn1AB8_051F` calls `fn1EDA_023F(wArg06, 0, 0, &dsOut)` and `fn1AB8_0538`
   calls `fn1EDA_0254(wArg06, lo, hi, 0, ...)`, i.e. they place the allocation
   size in the **first** parameter.  The `.asm` (and therefore the frozen
   prototype) puts the first real argument — the size — in `wArg04`
   (`mov ax,[bp+6h]`) and the 16:16 block address in `ptrArg06`
   (`les cx,[bp+8h]`); `wArg00`/`wArg02` are the far return-address words that
   `fn1EDA_00E2` pops.  Under this chunk's (asm-faithful) reading those call
   sites would allocate 0 and free a null pointer.  The chunk constraints allow
   only `src/seg1EDA_part2a.c` to be created/modified, so the call sites were
   left untouched and are flagged here for the orchestrator (they need
   `(0, 0, size, block)` / `(0, 0, size, block, ...)`).
6. **Error paths never return in the original.**  023F (`jmp 00E2h`) and 0254
   (`jmp 00E2h`) tail-enter the fatal-error dispatcher, which in the original
   terminates the process.  Chunk 1's flat `fn1EDA_00E2` returns, so the
   recovered code keeps the Reko `SEQ(dx, ax)` result on those branches.
7. **0308 `ax == 0` DX output.**  The original `or ax,ax ; jz 0382h` leaves DX
   undefined (Reko's `dx` is uninitialised).  The flat `dx` is initialised to 0,
   so `dxOut` reads 0 there instead of an undefined register.
8. **0308 grow-failure AX.**  On the `al < 1` path out of `1EDA:03BB` the
   register AX is the `1EDA:00A9` stub return (0), not the requested size; the
   recovered `axOut` uses the callback result (the `.asm` is ground truth; Reko
   sliced `ax_12`).  The `al == 1` path returns `DX:AX = 0` with carry clear.
   `fn1EDA_0308` returns 1 only on the grow-failure branch, 0 otherwise; 023F
   and 0254 treat a nonzero return as failure.
9. **Internal merge labels.**  `l1EDA_030C/0328/0330/0376` are fall-through /
   merge points without an explicit `goto` in the recovered C; they are kept as
   comments to preserve the asm offset landmarks.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1EDA_part2a.c` — exit 0, zero diagnostics
  (also clean with `-Wextra`).
* Reko-token grep (`Eq_[0-9]`, `Mem[0-9]*[`, `<invalid>`, `<unknown>`) — 0.
* `nm` reports `fn1EDA_01E7`, `fn1EDA_023F`, `fn1EDA_0254`, `fn1EDA_0308` as
  `T`; the four helpers are `t`.
* Prototype-conformance TU (`-Werror=incompatible-pointer-types`) taking the
  address of each function through `src/seg1EDA.h` — OK.
* Stub harness exercised `fn1EDA_0308`: `ax == 0` (carry clear, `axOut = 0`),
  exact-fit relink (returns the node, head advanced to its successor), split
  (returns the node, head advanced to the computed remainder) and the
  high-water branch (`[535E]/[5360]` updated, old high-water returned) — all
  match the `.asm` under the flat-heap convention of uncertainty 2.

## chunk 3c (recovered stream callbacks)

Range: 1EDA:060C .. 1EDA:0775.  Source: `src/seg1EDA_part3c.c`.  Ground truth:
the raw bytes of `data/segments/seg1EDA.bin` at 0x060C..0x0775 (identical to the
raw bytes carried after the `fn1EDA_05FB` label in
`analysis/reko/RAD_1EDA.asm` / `analysis/slices/1EDA/1EDA_05FB.asm`), disassembled
for this recovery because Reko never sliced the region.

The region contains **six** entry points, not five; the brief listed
060C/068E/06E8/0718/075D, and 073D is an additional distinct entry point that
060C installs for character devices (it has its own `retf 4` at 073A, so it is a
separate function, not a branch of 0718).  All six are recovered so the region is
complete.

### Functions and boundaries

| offset range | function | size | role |
| --- | --- | --- | --- |
| 060C..068D | `fn1EDA_060C` | 0x82 | open/create callback (installed at +0x10): chooses 3Dh vs 3Ch, calls 44h ioctl, installs +0x14/+0x18/+0x1C callbacks, sets id 0xD7B2 |
| 068E..06E7 | `fn1EDA_068E` | 0x5A | near helper (`call 068Eh` from 060C:0665, returns with a near `ret`): trims an append stream at the 1Ah ^Z terminator |
| 06E8..0717 | `fn1EDA_06E8` | 0x30 | read callback (+0x14 for id 0xD7B1): 3Fh into the block buffer |
| 0718..073C | `fn1EDA_0718` | 0x25 | checked write callback (+0x14 for a file): 40h, returns 0 / 0x65 / DOS error |
| 073D..075C | `fn1EDA_073D` | 0x20 | unchecked write callback (+0x14/+0x18 for a character device): 40h, returns 0 on success |
| 075D..0775 | `fn1EDA_075D` | 0x19 | close callback (+0x1C): 3Eh for handles > 4 |

### ABI

The dispatchers push the far block pointer and then `call dword ptr` the slot,
so every callback receives exactly **one far block pointer** and returns its AX
in the low half of an int (0 = success; nonzero is latched into DGROUP:0x5380 by
05FB/0879):

* `fn1EDA_05FB` (chunk 3a): `push es; push di; push es; push di; call dword ptr
  es:[bx+di]` — the first pair saves 05FB's registers, the second is the single
  argument the callback's `retf 4` pops.  It already casts the slot to
  `u16 (*)(u8 *)`.
* `fn1EDA_0879` (chunk 4): `push es; push di; call dword ptr es:[di+18h]`, same
  single argument; it already casts `(u16 (*)(u8 *))`.
* `fn1EDA_07E9` (not yet converted; frozen prototype in `src/seg1EDA.h`):
  `push es; push di; push es; push di; call dword ptr es:[di+14h]`, same single
  argument.
* `fn1EDA_068E` is the exception: it is entered by a **near** `call 068Eh` at
  060C:0665 with DI already holding the block (DS was switched to the block
  segment by 060C's `lds`), and it returns with a near `ret` at 06E7.  It is not
  a dispatched slot.

So the flat signatures are `u16 fnXXXX(u8 * block)`.  The brief's suggested
`u16 fn(u8 *block, u16 ax, u16 bx, u16 cx, u16 dx)` is **not** what any dispatch
site passes; no register arguments cross the call (only the pushed block).

### DOS-service map (int 21h)

| site | AH | pal entry |
| --- | --- | --- |
| 060C:0637 | 3Dh | `msdos_open_file(path, mode)` (mode = AL: 0 read / 2 read-write) |
| 060C:0637 | 3Ch | **no pal entry** — file-static `dos_create_file()` (see gap 1) |
| 060C:0650 | 44h AL=00h | **no pal entry** — file-static `dos_get_device_info()` (see gap 2) |
| 068E:0697 | 42h AL=02h | `msdos_set_file_position(handle, 0, 2)` |
| 068E:06AE | 42h AL=00h | `msdos_set_file_position(handle, off, 0)` |
| 068E:06BB | 3Fh | `msdos_read_file(handle, buffer, 0x80)` |
| 068E:06DD | 42h AL=02h | `msdos_set_file_position(handle, (bx-count), 2)` |
| 068E:06E5 | 40h | `msdos_write_file(handle, buffer, 0)` (CX = 0) |
| 06E8:06FC | 3Fh | `msdos_read_file(handle, buffer, [block+4])` |
| 0718:072E | 40h | `msdos_write_file(handle, buffer, [block+8])` |
| 073D:0753 | 40h | `msdos_write_file(handle, buffer, [block+8])` |
| 075D:076D | 3Eh | `msdos_close_file(handle)` |

The carry results of the original (`jc`) are modelled with the pal failure
sentinels (`msdos_*` return 0xFFFF for an invalid handle / -1 for seek); the
relative distinction success vs failure is preserved, the exact DOS error code
is not (documented, not invented).

### Uncertain sites / portability

1. **AH=3Ch create has no PAL entry.**  `pal/pal.h` and `pal/dos.c` expose
   3Dh/3Eh/3Fh/40h/42h but no create (`pal/dos.c` even documents "the recovered
   code does not issue int 21h AH=3Ch", which this chunk proves stale), and its
   handle table is private.  The chunk constraint forbids editing `pal/`, so
   `dos_create_file()` creates the file with stdio `fopen(path, "w+b")` (DOS 3Ch
   truncates, like "w+b") and then re-opens it through `msdos_open_file()` so the
   handle interoperates with the other `msdos_*` calls.  Path resolution is the
   process CWD for the stdio create vs pal's data directory for the re-open — a
   documented deviation.  The integrator should add a real `msdos_create_file()`
   to `pal/dos.c` and call it from 060C.
2. **AH=44h AL=00h ioctl has no PAL entry.**  `dos_get_device_info(handle)`
   returns DX directly: bit 7 set (0x0080) for the predefined device handles
   0..4, clear for the stdio file handles >= 5 (`pal/dos.c` HANDLE_BASE = 5).
   Only DL bit 7 is consumed (060C:0659), which is the "character device"
   selector that picks the 073D write callback; the exact DOS device-info word is
   not reproduced.
3. **CS selectors stored literally.**  The original stores the CS register at
   block +0x16 / +0x1E (always) and at +0x1A for the device case.  Flat C has no
   CS; the recovered code stores the literal code selector `0x1EDA`, the same
   value chunk 1 stored for `cs` at DGROUP:0x5370.  This keeps the +0x1A
   "installed?" test in `fn1EDA_0879` (and the far-pointer segment halves) true,
   which matters because only the device path installs a +0x18 callback.
4. **Buffer far pointer (+0x0C).**  `lds dx,[es:di+0Ch]` loads a far buffer
   pointer whose segment half (+0x0E) is dropped by fn1EDA_04F5 (stored 0).  The
   flat `block_buffer()` therefore reconstructs the flat pointer from the stored
   block-relative offset (`stored - low16(block)`, always +0x80).
5. **Return of 060C.**  The normal path's `xor ax,ax` → 0; the carry path returns
   the pal failure sentinel 0xFFFF (nonzero) instead of the DOS error code.
6. **068E is reached only by the near call at 060C:0665** and only for the
   append id 0xD7B3 with a non-device handle; it is not installed anywhere.
7. **`fn1EDA_073D` was not in the brief's five-entry list.**  It is a real
   second entry point: 060C installs it at both +0x14 and +0x18 for character
   devices, so it is required for the device write path.  It is defined `T` in
   `src/seg1EDA_part3c.c` alongside the five named entries.

### Dispatch wiring (for the integrator)

The block currently stores **16-bit callback offsets** (and the literal 0x1EDA
segment) in the +0x14/+0x18/+0x1C slots; the existing dispatch sites instead
read the slot as a **host function pointer** (`*(void **)(block+slot)`), which
cannot work with a 4-byte slot on a 64-bit host.  The recommended wiring is to
resolve the stored offset to one of the recovered host functions at the dispatch
site.  The common shape is:

```c
typedef u16 (*stream_cb_t)(u8 * block);

static stream_cb_t resolve_stream_cb(u16 off)
{
	switch (off) {
	case 0x060C: return fn1EDA_060C;
	case 0x06E8: return fn1EDA_06E8;
	case 0x0718: return fn1EDA_0718;
	case 0x073D: return fn1EDA_073D;
	case 0x075D: return fn1EDA_075D;
	default:     return (stream_cb_t)0;   /* 068E is a near helper, not a slot */
	}
}
```

Concretely:

* `fn1EDA_05FB` (chunk 3a): replace
  `((u16 (*)(u8 *))*(void **)(es_bx + di))(es_bx)` with
  `resolve_stream_cb(*(u16 *)(es_bx + di))(es_bx)` (guard a null resolver
  result).  The `di` slot values it is called with are 0x10/0x14/0x1C.
* `fn1EDA_0879` (chunk 4): keep the `*(u16 *)(es_di + 0x1A) != 0` installed
  test and replace the `*(void **)(es_di + 0x18)` dereference with
  `resolve_stream_cb(*(u16 *)(es_di + 0x18))(es_di)`.
* `fn1EDA_07E9` (frozen prototype `src/seg1EDA.h`, not yet converted): the
  `call dword ptr es:[di+14h]` becomes
  `resolve_stream_cb(*(u16 *)(es_di + 0x14))(es_di)`.
* `fn1EDA_04F5` (chunk 3a) already stores the literal 0x060C at +0x10 with a 0
  segment; no change is needed for the offset-based resolver.
* `fn1EDA_060C` calls `fn1EDA_068E(block)` directly (the original near call), so
  068E needs no slot.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1EDA_part3c.c` — exit 0, zero diagnostics
  (also clean with `-Wextra`).
* Reko-token grep (`Eq_[0-9]`, `Mem[0-9]*[`, `<invalid>`, `<unknown>`) — 0.
* `nm` reports `fn1EDA_060C`, `fn1EDA_068E`, `fn1EDA_06E8`, `fn1EDA_0718`,
  `fn1EDA_073D`, `fn1EDA_075D` as `T`; `block_buffer`, `dos_create_file` and
  `dos_get_device_info` are `t`.  (`fopen`/`fclose`/`msdos_*` remain undefined
  in the object until linked, as usual.)
* `src/seg1EDA_shared.h` gained `extern` declarations for the six functions;
  existing contents were not changed.

## chunk 3b-i

Range: 1EDA:0776 .. 1EDA:07B6 (3 functions, ascending).
Source: `src/seg1EDA_part3bi.c`.  Ground truth = `analysis/slices/1EDA/1EDA_<off>.asm`.

### Functions converted

| offset | function | role |
| --- | --- | --- |
| 0776 | `fn1EDA_0776` | getc prelude: validate id `0xD7B1` against DGROUP:0x5380, load BX=`+0x08`, DX=`+0x0A`, ES:DI=`+0x0C` |
| 079A | `fn1EDA_079A` | getc body: `cmp bx,dx`; refill through `fn1EDA_07E9` on exhaustion, else return `buffer[BX]` (0x1A + carry at EOF) |
| 07B6 | `fn1EDA_07B6` | putc prelude (write twin of 0776): id `0xD7B2`, error `0x69`, DX=`+0x04` |

### DOS-service map (int 21h)

None.  No function in this range issues int 10h / int 16h / int 21h or port
I/O.  The only external effect is the DGROUP error word 0x5380 (`LG16`), plus
the same-segment call `079A:07A9 -> fn1EDA_07E9` (which is where the refill
callback -- and its int 21h file services -- lives; 07E9 is out of range).

### Findings on 079A (the unresolved-register function)

`fn1EDA_079A` is one of the two segment functions whose Reko out-register
types are unresolved.  Recovering from the `.asm`:

* **Return type.**  The `.asm` never touches SI, but Reko propagates the SI
  word that the refill callee `fn1EDA_07E9` leaves and types the result as a
  DS:SI far pointer (`ptr32`/`ds_si`).  The real register is therefore **SI**
  (16-bit, paired with DS as selector); the frozen `u8 *` return is fed
  `(u8 *)(uintptr_t)si` at the boundary.  Without a refill Reko's result is
  uninitialised, so the recovered code returns 0 there.  All callers discard
  it.
* **dxOut / bxOut / esOut.**  all three are register outputs, not data
  pointers: `dxOut` is the 16-bit DX (`mov dx,ax` on the refill path, else the
  incoming DX), `bxOut` is the 16-bit BX cursor, and `esOut` is the ES
  selector.  The call sites (chunk 4) pass pointer-sized storage for `bxOut`
  and `esOut`, so the recovered code writes them as `u8 *` (cursor word) and
  `u8 *` (0), while `dxOut` writes the 16-bit word.
* **`ptrArg02`.**  the original reloads ES:DI from the stack (`mov di,sp ;
  les di,ss:[di+2h]`), i.e. the block pointer the caller pushed for 0776; in
  flat C that is the same argument, passed as `ptrArg02`.
* **Carry.**  the read path ends `clc` and the EOF path `stc`; C has no carry
  out, and the frozen prototype has no flag output, so it is dropped.  Every
  caller tests AL (`1Ah`/`0Dh`/`0Ah`/`20h`), never carry.

### Uncertain sites / portability

1. **`es_bxOut` in 0776/07B6.**  iface.tsv types it `u8 *` although Reko models
   a far-pointer out-param.  Per the frozen header it is reinterpreted as
   `u8 **`; the stored value is the 16-bit BX cursor as
   `(u8 *)(uintptr_t)bx`, the ES half being dropped (the original's ES comes
   from `block[+0x0E]`, which `fn1EDA_04F5` stores as 0).  This is what the
   chunk-4 call sites consume (`(uintptr_t)es_bx...` as the BX word).
2. **`esOut` dropped.**  the buffer selector is not representable, so 079A
   always writes 0 into `esOut`; the chunk-4 callers reconstruct the next
   `es_bx` as `esOut + bx`, which then equals the cursor word.
3. **Buffer byte source.**  `mov al,es:[bx+di]` (ES:DI = buffer far pointer,
   BX = cursor index) is read from the flat block buffer `block+0x80`, using
   the same `stored - low16(block)` recovery chunk 3c's `block_buffer` uses.
4. **0776/07B6 return polarity (cross-chunk integration finding).**  The
   frozen prototypes convert Reko's FlagGroup bool return to `u8`; the `.asm`
   leaves the ZF of the final `cmp` (success = 1 when DGROUP:0x5380 is clear
   **and** the id matches the read/write mode, failure = 0), the same
   convention as chunk 3a's `fn1EDA_05FB`.  The chunk-4 call sites,
   `fn1EDA_081A`/`0896`/`0918` (0776) and `fn1EDA_0848`/`08CE` (07B6), test it
   as `if (!ok) { read/write loop }`.  The `.asm` (`call 0776h ; jnz <after
   loop>`) enters that loop when ZF = 1, i.e. on success, so those callers
   select the loop on the failure value.  The recovered functions keep the
   literal `.asm`/iface.tsv convention (return ZF); the chunk-4 callers are the
   side that diverges and are outside this chunk's edit scope.  Integrator:
   invert the `!ok` tests (or document the behavioural difference).
5. **`fn1EDA_07E9` not yet converted.**  079A calls it through the frozen
   `src/seg1EDA.h` prototype; the definition belongs to another part file
   (chunk 3b-ii).  The link stays unresolved until that part exists.

### Shared staging

None.  `stream_buffer` is file-static; no file-scope variable is shared with a
function outside this range, so `src/seg1EDA_shared.h` is unchanged.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1EDA_part3bi.c` — exit 0, zero diagnostics
  (also clean with `-Wextra`).
* Reko-token grep (`Eq_[0-9]`, `Mem[0-9]*[`, `<invalid>`, `<unknown>`) — 0.
* `nm` reports `fn1EDA_0776`, `fn1EDA_079A`, `fn1EDA_07B6` as `T`;
  `stream_buffer` is `t`.  (`fn1EDA_07E9` remains undefined until chunk 3b-ii,
  as usual.)
* The definitions were compiled against `src/seg1EDA.h`, so any divergence from
  the frozen prototypes would have been a compile error.

## chunk 5a

Range: 1EDA:0E07 .. 1EDA:0E8E (3 functions, ascending).
Source: `src/seg1EDA_part5a.c`.  Ground truth = `analysis/slices/1EDA/1EDA_<off>.asm`.

### Functions converted

| offset | function | role |
| --- | --- | --- |
| 0E07 | `fn1EDA_0E07` | latch the DOS time: `int 21h` AH=2Ch, store `CX` at DGROUP:0x5382 (hour:minute) and `DX` at DGROUP:0x5384 (second:hundredths) |
| 0E14 | `fn1EDA_0E14` | format signed 32-bit DX:AX into the ES:DI buffer as a variable-width decimal string, reading the 10-entry power-of-ten table at `1EDA:0E66`; returns the byte count in CX |
| 0E8E | `fn1EDA_0E8E` | ASCII-to-integer scanner: optional `+`/`-`, then decimal or `$`-prefixed hex, overflow-checked, accumulating into DX:AX; outputs AX/CX/SI/DI and returns the original carry as `u8` |

### DOS-service map (int 21h)

| site | AH | replacement |
| --- | --- | --- |
| `1EDA:0E08` | 2Ch | `msdos_get_system_time(h, m, s, hs)` |

`pal.h` maps the service as `(u8 *h, u8 *m, u8 *s, u8 *hs)` = CH/CL/DH/DL; the
recovered code passes `&ch_5, &cl_8, &dh_6, &dl_7`, matching the register order
exactly.  No other function in the range issues an int 10h / int 16h / int 21h
or port I/O.

### Shared staging

None.  No file-scope variable is shared with a function outside this range;
all state is DGROUP (`g_dgroup` / `LG16`) or the caller-supplied buffer.
`src/seg1EDA_shared.h` was **not** modified; the only file-scope symbol added is
the file-static `seg1EDA_dword`.

### Power-of-ten table

`1EDA:0E66` is a 40-byte little-endian table of ten `u32` powers of ten
(`1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1`).
Reko mis-decoded it as a two-field struct; the recovered code reads it from the
loaded segment image through the file-static `seg1EDA_dword` (`cs:[si]` /
`cs:[si+2h]`), per the `segXXXX:off` -> `g_segXXXX[off]` rule.

### Uncertain sites / portability

1. **`fn1EDA_0E14` return type.**  The `.asm` returns the written byte count in
   **CX** (`mov cx,di ; pop di ; sub cx,di`).  The frozen prototype types the
   return as `u8 *` (from Reko's `memptr` return), so the recovered function
   carries the 16-bit count as a pointer-sized value
   (`(u8 *)(uintptr_t)(u16)count`).  A caller recovering the count must cast it
   back: `(u16)(uintptr_t)fn1EDA_0E14(...)`.
2. **`fn1EDA_0E14` `u16 di, void * es`.**  Reko's `di` here is a plain 16-bit
   register and `es` a segment pointer, so ES is the flat base and DI the byte
   offset: the effective byte is `(u8 *)es + di`.  This matches the existing
   `fn1E5F_0136` convention ("ES is the flat base, DI the byte offset; the port
   passes DI = 0 and ES = the pointer").  The caller `fn1EDA_0F26` (chunk 5b)
   must pass the buffer pointer as `es` and the offset as `di`.
3. **`fn1EDA_0E8E` `u8 * di, void * es`.**  Reko's `di` is a
   `(memptr (ptr16 ...) byte)`; per the port's memptr rule (see chunk 1's
   `fn1EDA_01A5`, which dereferences its memptr argument) it is the **flat byte
   pointer**, used directly (`*di`, `++di`); the redundant `es` byte-segment
   parameter is dropped (`(void)es`).  This is what makes the chunk-5b caller's
   count formula `diOut - start` natural.
4. **`fn1EDA_0E8E` out parameters.**  `axOut`/`cxOut`/`siOut` receive the final
   AX/CX/SI words; `diOut` is Reko's `memptr` out.  Following the part-4
   `es_bxOut` convention, `diOut` (frozen as `u8 *`) is reinterpreted as
   `u8 **` and receives the final flat `di` pointer.  The caller must pass the
   address of a `u8 *` variable, cast to `u8 *`.
5. **`fn1EDA_0E8E` return.**  The original signals success/failure with CF
   (`stc` at 0EEF, `clc` at 0EED); the frozen `u8` return carries the carry
   (1 = error/overflow, 0 = success), matching Reko's `bool` and the caller
   `fn1EDA_0F71`'s `if (fn1EDA_0E8E(...) || cx != 0)`.  The `dec si` result is
   exposed through `siOut` (0 when a `-` sign was present, 0xFFFF otherwise on
   success), exactly as the `.asm` leaves it.
6. **Hex prefix is `$`.**  The scanner treats a leading `$` (0x24, after the
   optional sign) as the hex introducer; the `.asm` is ground truth even though
   Turbo-C `strtol` would use `0x`.  Kept literally.
7. **Overflow and sign.**  Reko models the decimal accumulation convolutedly;
   the recovered code uses the exact arithmetic `dx:ax = dx:ax*10 + digit`
   (mod 2^32, equal to the shift/add sequence) with the original's two checks
   (`test dx,0F000h` before and `js` after).  The hex path shifts four times,
   testing bit 15 of DX before each shift (`rcl` carry).
8. **`fn1EDA_0E14` minus sign.**  The `stosb` writes `'-'` into ES:DI before the
   digits; the negation is the full 32-bit `~dx_ax + 1`.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1EDA_part5a.c` — exit 0, zero diagnostics
  (also clean with `-Wextra`).
* Reko-token grep (`Eq_[0-9]`, `Mem[0-9]*[`, `<invalid>`, `<unknown>`) — 0.
* `nm` reports `fn1EDA_0E07`, `fn1EDA_0E14`, `fn1EDA_0E8E` as `T`;
  `seg1EDA_dword` is `t`.  (`msdos_get_system_time` remains undefined until
  linked, as usual.)
* Prototype-conformance TU (`-Werror=incompatible-pointer-types`) taking the
  address of each function through `src/seg1EDA.h` — OK.
* Stub harness (table seeded with the ten powers of ten, a time stub) exercised
  `fn1EDA_0E14` (0, single digit, 12345, 1e9, `-1`, `-2147483648`,
  `2147483647`, 999), `fn1EDA_0E07` (0x1234/0x5678 staged), and `fn1EDA_0E8E`
  (`""` -> error; `"123"`; `"-45"`; `"+7"`; `"$FF"`/`"$ff"`; `"abc"` ->
  success with AX=0; `"12x"` -> stop at cx=1; `"2147483648"` -> overflow error
  with cx=1, si=0, di=9) — all match the `.asm`.

## chunk 5b

Range: 1EDA:0F26 .. 1EDA:1051 (5 functions, ascending).  Source:
`src/seg1EDA_part5b.c`.  Ground truth = `analysis/slices/1EDA/1EDA_<off>.asm`;
frozen prototypes adopted exactly from `src/seg1EDA.h`.

### Functions converted

| offset | function | role |
| --- | --- | --- |
| 0F26 | `fn1EDA_0F26` | decimal-format `dwArg0C` into a width-padded field at `ptrArg06` (0E14 conversion helper) |
| 0F71 | `fn1EDA_0F71` | parse a number from the length-prefixed string `ptrArg08` (0E8E); leftover count/`siOut`/`esOut` |
| 0FA2 | `fn1EDA_0FA2` | (re)initialise a stream block: id 0xD7B0, zero +4..+0x2F, copy the name to +0x30 |
| 0FD0 | `fn1EDA_0FD0` | open/append the block (AH=3Dh; id checks, 1051 reset, handle+limit store) |
| 1051 | `fn1EDA_1051` | close/re-arm the block (1076 check, AH=3Eh close for handles > 4, id back to 0xD7B0) |

### DOS-service map (int 21h)

| site | AH | replacement |
| --- | --- | --- |
| `0FD0:100F` | 3Dh | `msdos_open_file(path, mode)` (`mode` = `DGROUP:0x5386`, path at block+0x30) |
| `1051:1066` | 3Eh | `msdos_close_file(handle)` (only when `handle > 4`) |

No other function in the range issues `int 10h` / `int 16h` / `int 21h`, port
I/O, `__cli`/`__sti` or `int 23h` sites.  `DGROUP:0x5380` (DOS error word) and
`DGROUP:0x5386` (open mode) are accessed through `LG16`/`LG8`.

### Shared staging

None.  No file-scope variable is shared with a function outside this range; all
state is DGROUP (`g_dgroup` / LG macros) or the caller-supplied stream block.
`src/seg1EDA_shared.h` was **not** modified.

### Uncertain sites / portability

1. **`fn1EDA_0E14` returns a count in a pointer-typed slot.**  The `.asm`'s
   return is `mov cx,di ; pop di ; sub cx,di` (the decimal digit count in CX),
   but iface.tsv types the Reko member-pointer return as `u8 *`.  `fn1EDA_0F26`
   recovers the 16-bit count with `(s16)(uintptr_t)fn1EDA_0E14(...)`; the 0E14
   chunk must therefore return `(u8 *)(uintptr_t)count`.  This is the same
   16-bit-value-through-a-pointer-slot convention used by chunk 2b/part4.
2. **Flat calling convention of `fn1EDA_0E14(u32, u16 di, void *es)`.**  The
   original passes `ES = SS`, `DI = [bp-20h]`; following `fn1E5F_0136` (already
   in the tree), the recovered call passes `di = 0` and `es = tLoc22`, i.e. the
   callee computes `(u8 *)es + di`.  If the 0E14 chunk instead treats `di` as a
   flat address the scratch must be passed in `di` — interface decided by the
   1E5F precedent; recorded here for the integrator.
3. **`fn1EDA_0E8E` flag return / `diOut` width.**  `0F71` branches on
   `err || cx_34 != 0`, where `err` is the frozen `u8` return (Reko's
   `FlagGroup bool`: 1 = carry set = parse error, per iface.tsv note 0E8E).
   The frozen `diOut` is declared `u8 *` but carries the recovered flat `u8 *`
   end pointer (part4's `es_bxOut` convention); the caller passes
   `(u8 *)&di_35` and subtracts `ptrArg08` to get the consumed length.
4. **`fn1EDA_1076` flag return (frozen `u32`).**  The original `1051` branches
   on the ZF left by `1076`'s `cmp [di+2],0D7B3h`; iface.tsv exposes that as a
   `u32` flags value with no defined encoding.  `1051` calls
   `(void)fn1EDA_1076(ptrArg04)` for its side effect (latches `0x67`) and then
   recomputes the identical condition `*(u16 *)(ptrArg04 + 2) == 0xD7B3` from
   the unmodified block, so the control flow is exact regardless of the
   encoding the 1076 chunk chooses.
5. **`fn1EDA_0F71` `esOut` (frozen `void *`).**  The original stores the ES
   selector of `ptrArg04`.  There is no selector in the flat model; the flat
   selector analog of `ptrArg04` is the pointer itself, so `esOut` receives
   `(u8 *)ptrArg04` (the same base-pointer-through-`void *` convention part4's
   `079A` caller uses).  `siOut` is 0E8E's sign word unchanged.
6. **`fn1EDA_1051` return.**  The original leaves AX undefined at `retf 4h`
   (Reko's pointer return is an artifact); no caller consumes it.  The flat
   function returns 0 (documented, not invented).
7. **DOS error sentinel.**  On `msdos_open_file` / `msdos_close_file` failure
   the pal `0xFFFF` sentinel is latched into `0x5380` instead of the exact DOS
   error code (chunk 3c's convention); success/failure control flow is
   preserved.
8. **Embedded `0FD9` create entry.**  The bytes at `1EDA:0FD9`
   (`mov ax,3C00h ; mov dx,0001h`) are a second entry point that falls into the
   shared body at 0FDF, but `1EDA:0FD9` is not an `index.tsv` `kind=fn` row and
   has no frozen prototype, so it is not converted here.  Function `0FD0`'s own
   entry always sets AH=3Dh (open); its `jmp 0FD0h+0F` skips 0FD9.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1EDA_part5b.c` — exit 0, zero diagnostics
  (also clean with `-Wextra`).
* Reko-token grep (`Eq_[0-9]`, `Mem[0-9]*[`, `<invalid>`, `<unknown>`) — 0.
* `nm` reports `fn1EDA_0F26`, `fn1EDA_0F71`, `fn1EDA_0FA2`, `fn1EDA_0FD0`,
  `fn1EDA_1051` as `T`.  The definitions were compiled against
  `src/seg1EDA.h`, so any divergence from the frozen prototypes would have been
  a compile error.
* A stub harness (out-of-range callees 0E14/0E8E/1076 and `msdos_open_file`/
  `msdos_close_file` stubbed) exercised all functions and branches: 0FA2
  header/zero-fill/name-copy at +0x30, 0F26 padding+digits, 0F71 success,
  error and `siOut`/`esOut`, 0FD0 open, empty-name dummy (xchg dx,ax) and
  unknown-id paths, and 1051 close/no-close/close-failure paths — all pass.
* An end-to-end integration build linking `src/seg1EDA_part5a.c` (the real
  0E14 and 0E8E) with `src/seg1EDA_part5b.c` (against the loaded
  `data/segments/seg1EDA.bin` power-of-ten table) confirms the cross-range
  interfaces: 0F26 formats 42 as `04 20 20 34 32`, 0F71 parses `"123"` -> 123
  (leftover 0, siOut 0xFFFF), `"$FF"` -> 255, and the `"+x"` error path returns
  0 with the consumed count 2 — all pass.

## chunk 6

Range: 1EDA:1076 .. 1EDA:1384 (16 functions, ascending).
Source: `src/seg1EDA_part6.c`.  Ground truth = `analysis/slices/1EDA/1EDA_<off>.asm`.

### Functions converted

| offset | function | role |
| --- | --- | --- |
| 1076 | `fn1EDA_1076` | stream-id guard: `cmp es:[di+2],[0xD7B3]`; returns the raw ZF (1 = id open); mismatch sets `DGROUP:0x5380 = 0x67` |
| 1085 | `fn1EDA_1085` | read-record thunk (`mov ah,3Fh ; mov dx,64h`) -> 1091 |
| 108C | `fn1EDA_108C` | write-record thunk (`mov ah,40h ; mov dx,65h`) -> 1091 |
| 1091 | `fn1EDA_1091` | record read/write (INT 21h AH=3F/40), count = block[+4] |
| 10BB | `fn1EDA_10BB` | read `wArg08` records of block[+4] bytes; store whole-record count at `*ptrArg04`; on short/zero transfer latches the 0x64 sentinel |
| 1123 | `fn1EDA_1123` | seek to record `wArg06:wArg04` (INT 21h AH=42 AL=00), offset = index * block[+4] |
| 116A | `fn1EDA_116A` | record count = file size / block[+4] (via 119A + 098A) |
| 1185 | `fn1EDA_1185` | 1 if current position >= file size else 0 (via 119A) |
| 119A | `fn1EDA_119A` | size + restore seek (3x INT 21h AH=42); out BX:CX=size, DX:AX=position, ES:DI=block; returns the last seek's carry |
| 11DF | `fn1EDA_11DF` | `rep movsb` copy, direction chosen from the 16-bit SI/DI offsets |
| 1202 | `fn1EDA_1202` | `rep stosb` fill |
| 1216 | `fn1EDA_1216` | argv/environment fill: `wArg04 != 0` -> 126C token; else program path from PSP:002C (DOS >= 3), fallback `es_si` |
| 1265 | `fn1EDA_1265` | `xor dx,dx ; call 126C ; xchg bx,ax` -> token count in `*axOut`, last-scan pointer returned |
| 126C | `fn1EDA_126C` | PSP command-line tokenizer (PSP:0080 length / 0081 text) |
| 129E | `fn1EDA_129E` | build length-prefixed `"X:\cwd"` (INT 21h AH=19 / AH=47) |
| 1384 | `fn1EDA_1384` | a-z -> A-Z (unsigned) |

### DOS service map (int 21h)

| site | AH | replacement |
| --- | --- | --- |
| `1EDA:1091` (1085/108C entry) | 3Fh / 40h | `msdos_read_file` / `msdos_write_file` |
| `1EDA:10BB` (read entry) | 3Fh | `msdos_read_file` |
| `1EDA:1123` | 42h AL=00 | `msdos_set_file_position(handle, off, 0)` |
| `1EDA:119A` | 42h AL=01 / 02 / 00 | `msdos_set_file_position(handle, 0, 1)`, `(handle, 0, 2)`, `(handle, pos, 0)` |
| `1EDA:1216` | 30h | `msdos_get_dos_version` |
| `1EDA:129E` | 19h | `msdos_get_current_default_drive` |
| `1EDA:129E` | 47h | `msdos_get_current_directory` |

No int 10h / int 16h / port I/O in the range.  The write entry `1EDA:10C2`
(`mov bl,40h ; mov cx,65h`) shares 10BB's body but has no frozen prototype and
no caller anywhere in the image (verified by grepping `10C2h`); the flat
`fn1EDA_10BB` therefore always issues the read service, matching Reko
(`SEQ(0x3F, ...)`).

### Shared staging

`src/seg1EDA_shared.h` was appended (never redefined) with two slots; both are
defined in `src/seg1EDA_part6.c`:

* `u8 *g_1EDA_io_buffer` — the data-buffer far pointer that the frozen
  prototypes of **1091** and **10BB** dropped.  The original loaded it from the
  stack *between* the named arguments (`lds dx,[bp+6h]` / `lds dx,[bp+0Ch]`)
  and handed it to INT 21h AH=3F/40; Reko folded it into its dropped `ds`
  register parameter, so neither iface.tsv nor the header can carry it.
  Default `(u8 *)&g_dgroup[0x5CB4]` — the DGROUP buffer of the startup load
  path `fn0800_01FE -> fn1EDA_1085/1091` (verified at `0800:026A`: the pushed
  `ds:5CB4` is `[bp+6h]`, the `ss:bp-80` file struct is `[bp+0Ah]`).  Callers
  outside chunk 6 must repoint it before invoking the record-I/O helpers.
* `u8 *g_1EDA_psp` — the PSP base for **126C**/**1216**.  DGROUP:0x537C holds
  the DOS PSP selector, which the flat model cannot resolve (`fn1EDA_0000`
  stores only `(u16)(uintptr_t)es`; see chunk 1, note 4).  Default `g_dgroup`;
  a caller that owns the real PSP (`main.c`'s `g_psp`, passed to
  `fn0800_4255`) can point it there.

Within-range state (`fn1EDA_1091`, `fn1EDA_10BB`, `fn1EDA_126C`) is otherwise
stateless.

### Uncertain sites / portability

1. **Dropped data-buffer argument (1091 / 10BB).**  This is the one serious
   iface loss in the chunk.  The original signatures are effectively
   `(block, buffer)` for 1091 and `(result, count, buffer, block)` for 10BB;
   iface.tsv keeps only the block.  The recovered code performs the INT 21h
   call against `g_1EDA_io_buffer` and documents the gap; the file-record I/O
   is therefore not functionally wired until the frozen prototypes are
   corrected (or the callers set `g_1EDA_io_buffer`).  The 64 KiB static
   `g_dgroup` image is *not* used directly for the buffer because the record
   byte count (block[+4], or `wArg08*block[+4]` for 10BB) is a full 16-bit
   value and would overrun the tail of DGROUP.
2. **Write entry 1EDA:10C2.**  No frozen prototype, no caller; not converted
   (see the DOS map above).
3. **1091/10BB carry modelling.**  The original tests the INT 21h carry flag;
   pal.h exposes no carry, only `msdos_read_file`/`msdos_write_file` returning
   the byte count (0xFFFF on an invalid handle) and `msdos_set_file_position`
   returning -1.  The recovered code uses `== 0xFFFF` (1091/10BB) and `< 0`
   (1123/119A) as the error proxy; DOS's real error code is not recoverable.
4. **119A outputs.**  BX:CX = file size (BX high, CX low) and DX:AX = current
   position (DX high, AX low) cross the frozen `u32 *`/`s32 *` out-params
   directly; ES:DI = the block crosses the `u8 *` `es_diOut` as a `u8 **`
   (the same convention part4 uses for its `segptr32 &` out-params).  On the
   id-mismatch path the original leaves the outputs undefined; the port writes
   0/0/block.
5. **11DF offset comparison.**  `cmp si,di` compares the *16-bit* offsets
   only (segments ignored).  The flat port compares `(u16)(uintptr_t)`; for
   real flat addresses inside one array this matches, but the existing
   seg1AB8 callers pass packed far values (`(u8 *)(uintptr_t)LG32(...)`), so
   the direction choice is only meaningful when both pointers are genuine
   flat addresses.
6. **1216 environment walk.**  The flat model has no environment segment
   (`mov es,[537Ch] ; mov es,es:[002Ch]`).  A file-static all-zero 0x200-byte
   stand-in yields the empty program path; the branch stays faithful
   (`repne scasb` walks, `di += 3`, the 0x100-byte scan, `xchg cx,ax ; not al`)
   and cannot over-read.  The `es_si` fallback is used only for the
   (unreachable) DOS < 3 path.
7. **126C / 129E PSP access.**  126C reads `g_1EDA_psp[0x80]`
   (command-tail length) and `[0x81..]`; with the `g_dgroup` default the tail
   is empty (filename selection then falls back in the caller).  129E keeps
   the literal `X`, `:`, `\` prefix (`mov [si],al ; mov word ptr [si],5C3Ah`)
   and the `int 21h` AH=47 success path; pal's `msdos_get_current_directory`
   reports no failure, so the carry path (`mov byte ptr [si],0`) is
   unreachable.  The AH=47 DL drive selector is dropped by the pal entry point.
8. **129E return.**  Reko returns `0x47` (AH); the frozen `u8` caller ignores
   it.  Kept as 0x47.
9. **1076 flag return.**  Reko's `FlagGroup ui32` is returned as the raw ZF
   (1 when `block[+2] == 0xD7B3`), following the chunk-2a/3a convention
   (`fn1EDA_0308` returns the raw CF).  Every in-range caller branches
   `if (fn1EDA_1076(...) == 0) goto skip;`.  **Cross-chunk contract:** chunk 5b's
   `fn1EDA_1051` calls this function (asm `call 1076h ; jnz 1073h`), so it must
   execute its body when the return is *nonzero*.
10. **10BB result pointer.**  The original checks the far pointer `ES:DI != 0`
    with `or dx,di`; the flat model checks `ptrArg04 != NULL` (a genuine flat
    NULL loses the packed-far-value corner case).  The division by
    `block[+4]` is guarded against a zero divisor (which would trap on the
    8086).

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1EDA_part6.c` — exit 0, zero diagnostics
  (also clean with `-Wextra`).
* Reko-token grep (`Eq_[0-9]`, `Mem[0-9]*[`, `<invalid>`, `<unknown>`) — 0.
* `nm` reports all 16 functions `T`: `fn1EDA_1076`, `1085`, `108C`, `1091`,
  `10BB`, `1123`, `116A`, `1185`, `119A`, `11DF`, `1202`, `1216`, `1265`,
  `126C`, `129E`, `1384`.
* A conformance TU taking each function's address through `src/seg1EDA.h`
  compiles with `-Werror=incompatible-pointer-types`.
* A stub harness (pal DOS services + `fn1EDA_098A` stubbed, `g_dgroup` defined)
  exercised 1384, 1202, 11DF (forward + overlapping backward), 1076 (open and
  mismatch), 1085/1091 (record read into `g_1EDA_io_buffer`), 1123 (seek to
  record 2 * 4), 119A (size/position/restore), 116A (20/4 = 5), 1185
  (position < / >= size), 10BB (3 records read), 129E (`"C:\DIR"`), 126C and
  1265 (token count / returned stop pointer) — all pass.

## chunk 4b

Range: 1EDA:0A39 .. 1EDA:0DCF (12 functions, ascending).
Source: `src/seg1EDA_part4b.c`.  Ground truth =
`analysis/slices/1EDA/1EDA_<off>.asm`; frozen prototypes adopted exactly from
`src/seg1EDA.h` (no header modified).

### Functions converted

| offset | function | role |
| --- | --- | --- |
| 0A39 | `fn1EDA_0A39` | copy a length-prefixed record, clamped to `bArg04` payload bytes |
| 0A6B | `fn1EDA_0A6B` | extract `substring(src, offset wArg06, max wArg04)` as a record |
| 0AAC | `fn1EDA_0AAC` | append record `ptrArg04` to record `ptrArg08` (0xFF saturation) |
| 0AD8 | `fn1EDA_0AD8` | startup path selector: length-prefixed-string matcher (text in `ptrArg04`, pattern in `ptrArg08`) |
| 0B24 | `fn1EDA_0B24` | length-prefixed string compare, nonzero on equality |
| 0B4F | `fn1EDA_0B4F` | build the 2-byte record `{1, bArg04}` |
| 0B61 | `fn1EDA_0B61` | build the record `{wArg04, ptrArg06[0..]}` (count = full word) |
| 0B7C | `fn1EDA_0B7C` | record concatenation via two 0x100-byte stack buffers |
| 0BD0 | `fn1EDA_0BD0` | as 0B7C, only when `wArg04 > 0` |
| 0CD4 | `fn1EDA_0CD4` | bitmap bit test (`test es:[bx+di],al`), returns the ZF |
| 0D80 | `fn1EDA_0D80` | divide the 0DCF counter DX by `wArg04` (`div bx` on DX:AX = 0:DX) |
| 0DCF | `fn1EDA_0DCF` | advance the 32-bit pseudo-random counter at DGROUP:0x5382/0x5384, return DX |

### DOS-service map (int 21h)

None.  No function in this range issues `int 10h` / `int 16h` / `int 21h`, port
I/O, `__cli`/`__sti` or `int 23h`.  The only external state is DGROUP
(`g_dgroup` via `LG16(0x5382)` / `LG16(0x5384)`) and the code-segment constant
`cs:[0E05h]` (read from `g_seg1EDA`, see below).

### Shared staging

None.  No file-scope variable is shared with a function outside this range, so
`src/seg1EDA_shared.h` was **not** modified.  All state is DGROUP or the
caller-supplied buffers.  The only file-scope symbol added is the file-static
`seg1EDA_word`.

### The "stack-reuse" pattern (0B7C / 0BD0)

The original pushes a destination far pointer (`buffer1`) as the 4th argument of
an `0A6B` call and then lets `retf 8h` pop only the *other* arguments, leaving
that pointer on the stack as the 2nd argument of the immediately following
`0AAC`/`0A39` call; the same happens with `buffer2`.  (Verified: `push cs` + near
`call` + `retf 8h` nets exactly −4 bytes, preserving the first-pushed far
pointer.)  Following the part-4 convention, the recovered code passes the
buffer explicitly to each call; the two buffers are C locals
`buf1[0x100]`/`buf2[0x100]` in ascending-address-reuse order.  The
`fn0800_4255` startup path (`0AD8`) and the 0B7C/0BD0 record concatenations were
exercised against hand-computed results (see Validation).

### Uncertain sites / portability

1. **0AD8 return value is the advanced SI.**  Reko returns `si_158` (the
   pointer just past the matched pattern) and writes the 0-based match offset
   into `axOut`.  The `.asm` leaves SI in the same place and AX = `di - ptrArg04`;
   the recovered function returns the flat pattern pointer and stores the
   offset.  A zero-length text returns `axOut = 0`; a zero-length pattern
   returns `axOut = 1` (the `.asm` jumps to `0B1Ah` with `di = ptrArg04 + 1`);
   a single-byte pattern uses the `repne scasb` scan.  Every branch was checked
   against the `.asm`.
2. **16-bit `add si,cx` wrap in 0AD8.**  The mismatch rewind computes
   `cx = leftover - ax` (a 16-bit two's-complement negative) and adds it to
   SI/DI.  In flat C this must be applied as a *signed* displacement
   (`si += (s16)cx`); adding the raw `u16` would advance the 64-bit host
   pointer by ~64 KiB and fault.  This is the one place where the 16-bit wrap
   had to be made explicit rather than relying on `u16` arithmetic.
3. **0B24 return = ZF.**  The `.asm`'s final ZF is `1` on equality, so the
   function returns nonzero on a match — the same correction documented in
   `src/seg1AB8_part1.c` (its callers test `!= 0`).  `*axOut` receives the AX
   left by the compare path (`ah = ptrArg04[0]`, `al = ptrArg08[0]`), which
   Reko marked undefined; every in-tree caller ignores it.  `dxOut` is the
   dropped DS selector (2 bytes stored as 0; the in-tree callers pass `u16 *`).
4. **0CD4 return polarity.**  `test es:[bx+di],al` sets ZF when the tested bit is
   CLEAR, and the callers branch on the callee's ZF across the `retf`
   (e.g. `0800:0A83 call 0CD4h ; jz 0A86h`).  Reko exposes that ZF as a `bool`,
   so the recovered `u8` returns `1` when the bit is clear.  A flat caller must
   therefore write `if (!fn1EDA_0CD4(...))` for the original's
   `call ; jz`-fall-through and `if (fn1EDA_0CD4(...))` for `call ; jz`.
5. **0CD4 `esOut`.**  Reko's `esOut = es_18 = SLICE(ptrArg04,selector,16)`;
   following the identical part-5b `fn1EDA_0F71` case, the flat selector analog
   is stored as `*(u8 **)esOut = ptrArg04` (the frozen prototype types the slot
   `void *`).  The only callers live in the not-yet-converted `seg0800` /
   `0C74`, whose integration will pass a pointer-sized slot.
6. **0A39 / 0B24 `dxOut`.**  Reko's `dxOut = ds` restores the caller's DS after
   the internal `lds`/`les`; the flat model drops the selector (2 bytes, 0).
   The in-tree callers (`seg1AB8`, `seg11C8`, `seg13C1`) all pass `u16 *`.
7. **0DCF constant and return half.**  `mul word ptr cs:[0E05h]` multiplies by
   the word `0x8405` embedded at 1EDA:0E05; it is read from the loaded segment
   image via the file-static `seg1EDA_word(0x0E05)` (same convention as part-5a's
   `seg1EDA_dword`).  The frozen `u16` return is the high half (DX), which is the
   half `fn1EDA_0D80` consumes (`xor ax,ax` after the call); the low half is
   stored to DGROUP:0x5382.
8. **0DCF byte adds.**  `add ch,cl` and `add dh,bl` are 8-bit adds that do not
   carry into CL/BL; the recovered code rebuilds DX from the modified high byte
   and the untouched low byte, in the exact `.asm` order (including the second
   `add dh,bl` after `shl bx,cl`).
9. **0D80 `div` overflow.**  The original divides DX:AX = 0:DX by `wArg04`, so
   the quotient always fits in 16 bits; the flat `u16` division reproduces that
   range, and `wArg04 == 0` skips the division (DX passthrough, remainder 0).
10. **Out-of-scope trailing bytes.**  The `.asm` slices carry undecoded
    neighbours (`1EDA:0A5D`, `0C26`, `0C53`, `0C5B`, `0C80`, `0CB6`, `0CF5`,
    `0D11`, `0D2F`, `0D5E`, `0D96`, `0DB3`) that have no `index.tsv` `kind=fn`
    row and no frozen prototype, so none is converted here.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1EDA_part4b.c` — exit 0, zero diagnostics
  (also clean with `-Wextra`).
* Reko-token grep (`Eq_[0-9]`, `Mem[0-9]*[`, `<invalid>`, `<unknown>`) — 0.
* `nm` reports all 12 functions `T` (`fn1EDA_0A39`, `0A6B`, `0AAC`, `0AD8`,
  `0B24`, `0B4F`, `0B61`, `0B7C`, `0BD0`, `0CD4`, `0D80`, `0DCF`); only
  `seg1EDA_word` is `t`.
* A prototype-conformance TU taking each function's address through
  `src/seg1EDA.h` compiles with `-Werror=incompatible-pointer-types`.
* A stub harness (`g_dgroup` / `g_seg1EDA` seeded, `g_seg1EDA[0x0E05] = 0x8405`)
  exercised 0A39 (clamp/full), 0A6B (offsets 0/1/2/6 → `hello`/`hel`/`ello`/0),
  0AAC (append + 0xFF saturation with partial copy), 0B4F, 0B61, 0B24
  (equal/unequal/length mismatch/empty), 0CD4 (set/clear bits, `esOut`), 0AD8
  (`ll`@3, `e`@2, empty pattern→1, no-match, zero-length text), 0B7C
  (`"hello"+'X'` → `"heXllo"`), 0BD0 (`"hello"` → `"ho"`), and 0DCF/0D80
  (step 0 → `[5382]=1,DX=0`; step from `[5382]=1` → `[5382]=0x8406,DX=0x0808`;
  `0x8405 / 0x100` → quotient `0x84`, remainder `5`; `/0` passthrough) — all
  pass.
