# Notes: segment 1AB8 (VIDEO)

Recovery notes for the chunked port of `src/seg1AB8*.c`.
Ground truth = `analysis/reko/RAD_1AB8.asm`; structure from `RAD_1AB8.c`
and the per-function slices under `analysis/slices/1AB8/`.

## chunk 2

Functions converted (ascending offset), all defined in `src/seg1AB8_part2.c`:

| offset | function | frozen prototype |
| --- | --- | --- |
| 1AB8:097B | `fn1AB8_097B` | `u8 fn1AB8_097B(u8 * ptrArg02, u16 wArg06, u16 * dsOut)` |
| 1AB8:0AEE | `fn1AB8_0AEE` | `u16 fn1AB8_0AEE(void)` |
| 1AB8:0BAE | `fn1AB8_0BAE` | `u16 fn1AB8_0BAE(u8 * ptrArg04, s16 * ptrArg08, u8 * ptrArg0C)` |
| 1AB8:0E88 | `fn1AB8_0E88` | `void fn1AB8_0E88(void)` |
| 1AB8:0EB5 | `fn1AB8_0EB5` | `void fn1AB8_0EB5(void)` |

### Hardware-site map

**None.** This chunk contains no `int 10h`/`int 16h`/`int 21h`, no `in`/`out`
port instructions, no `__cli`/`__sti` and no `int 23h`. All BIOS/DOS traffic is
reached indirectly through segment 1EDA (`fn1EDA_0A39`, `0A1F`, `0AAC`, `04A2`,
`10BB`, `1051`, `1202`, `11DF`, `023F`, `0254`, `116A`) and is replaced in the
1EDA port, not here.

### VGA far-pointer sites

**None.** No far pointer with segment 0xA000 occurs in this chunk. The
`fn1EDA_*` routines are the string/memory helpers used to build the mode/path
names; they operate on DGROUP, stack and code-segment pointers only.

### Far (non-VGA) pointer sites — flat-model adaptations

* `[0xB828]`/`[0xB82A]` (DGROUP) is a 32-bit allocation pointer returned by the
  `[0xB6C2]` callback and consumed by `[0xB6C6]`, `fn1EDA_10BB` and
  `fn1AB8_05D3`. Kept in the two DGROUP words exactly as the original; where a
  flat pointer is required it is reconstructed as
  `(u8 *)(uintptr_t)LG32(0xB828)` (097B, 1AB8:0AA4) and noted inline.
* `[0xB83A]`/`[0xB83C]` (DGROUP) holds the far pointer handed to
  `fn1EDA_11DF` at 1AB8:0E3F; reconstructed as
  `(u8 *)(uintptr_t)LG32(0xB83A)` and noted inline.
* `0x1AB8:0x2073` is an embedded code-segment pointer (`g_seg1AB8`); the two
  pointers passed to `fn1AB8_0569` at 1AB8:0BEE are `&g_seg1AB8[0x2075]` and
  `&g_seg1AB8[0x2073]` (see uncertainty 4).

### Shared staging

**None required.** No file-scope variable is shared with a function outside
097B..0EB5; `src/seg1AB8_shared.h` was therefore not created. The only
non-frozen helpers (`fn1AB8_051F`, `fn1AB8_0538`, `fn1AB8_call_0B896`) are
targets of DGROUP far code pointers and are file-static in the part file.

### Uncertain sites / not recovered literally

1. **Indirect calls through `[0xB6C2]`/`[0xB6C4]` and `[0xB6C6]`/`[0xB6C8]`.**
   `fn1AB8_17AE` assigns the constant far code pointers `1AB8:051F` and
   `1AB8:0538` to these DGROUP slots; the call sites read the slot and far-call
   it. Flat C cannot call a 16:16 code pointer and the two targets are not
   functions in `analysis/summary/functions.tsv` (they are unnamed thunks at
   1AB8:051F and 1AB8:0538). They are therefore recovered as file-static
   helpers (`fn1AB8_051F` = allocate into a 32-bit slot via `fn1EDA_023F`,
   `fn1AB8_0538` = free via `fn1EDA_0254` then clear the slot) and the call
   sites call them directly. The DGROUP slot writes/reads are otherwise kept
   literal.
2. **Indirect call through `[0xB896]`/`[0xB898]` (1AB8:0C39).** The target is
   the display-driver record callback at record `+0x12`/`+0x14`
   (records at DGROUP `0x50FC + n*0x1A`). The shipped image (`dgroup_data.bin`)
   leaves every one of those fields zero, so the preceding
   `(offset|segment) != 0` guard never reaches the call. A 16:16 code pointer
   is not callable from flat C and no record callback maps to a recovered
   function; `fn1AB8_call_0B896` reads the staged `[0xB896]`/`[0xB898]` pair
   and returns the AX value (0) the caller consumes.
3. **`ds` register results.** `fn1AB8_097B`, `fn1AB8_0AEE` and `fn1AB8_0BAE`
   return the DGROUP selector in `DS` (and/or store it through the `dsOut`
   pointer). The selector is dropped in the flat model: `*dsOut` is stored as 0
   and the two `u16`-returning functions return 0. The `dsOut` pass-through
   values (`fn1AB8_0887`, `fn1AB8_1536`) are likewise dummies.
4. **`fn1AB8_0569` call convention (1AB8:0BEE).** The original pushes three
   copies of the far pointer held at `[0xB820]` (one +2) plus its offset and
   segment words and pops 12 bytes. The frozen prototype names only four
   in-parameters, so the offset/segment pair is passed as the plain values
   `0x2073` and `0x1AB8` (`wArg0A`, `wArg0C`) and the two pointers as
   `&g_seg1AB8[...]`, matching the way `fn1AB8_05D3` calls the same function.
   The unspecified extra words (`wArg02`/`wArg04`) are not present in the
   frozen prototypes and are omitted.
5. **`fn1EDA_10BB` read buffer (1AB8:0A82).** The original pushes four
   arguments; Reko's recovery and the frozen `fn1EDA_10BB` prototype carry only
   three (the `int 21h` read buffer is not represented). The call site passes
   the three frozen parameters: the output word, `[0xB82C]`, and the
   `0xB6CA` file-record pointer.
6. **`fn1EDA_0A39`/`0A1F`/`0AAC` stack re-use.** The original leaves a far
   pointer on the stack across three consecutive helper calls (the callees pop
   4/4/10 bytes respectively). This is a compiler stack-reuse trick; the
   recovered code passes the shared buffer explicitly to each call, exactly as
   Reko does, which is behaviour-equivalent.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1AB8_part2.c` — zero errors, zero warnings.
* `grep -cE "Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>" src/seg1AB8_part2.c` — 0.
* Prototype check TU (`-Werror=incompatible-pointer-types`) against
  `src/seg1AB8.h` — OK.
* `nm` — `T fn1AB8_097B`, `T fn1AB8_0AEE`, `T fn1AB8_0BAE`, `T fn1AB8_0E88`,
  `T fn1AB8_0EB5`.

## chunk 1

Functions converted (ascending offset), all defined in `src/seg1AB8_part1.c`:

| offset | function | frozen prototype |
| --- | --- | --- |
| 1AB8:0000 | `fn1AB8_0000` | `void fn1AB8_0000(u32 dwArg02, u8 * ptrArg06)` |
| 1AB8:008B | `fn1AB8_008B` | `u16 fn1AB8_008B(void)` |
| 1AB8:027E | `fn1AB8_027E` | `void fn1AB8_027E(u16 wArg04, u8 * ptrArg06)` |
| 1AB8:04F3 | `fn1AB8_04F3` | `u16 fn1AB8_04F3(void)` |
| 1AB8:0569 | `fn1AB8_0569` | `u16 fn1AB8_0569(u8 * ptrArg02, u8 * ptrArg06, u16 wArg0A, void * wArg0C, u16 * dxOut)` |
| 1AB8:05D3 | `fn1AB8_05D3` | `u16 fn1AB8_05D3(u8 * ptrArg04)` |
| 1AB8:06CA | `fn1AB8_06CA` | `u16 fn1AB8_06CA(u8 * ptrArg04)` |
| 1AB8:0813 | `fn1AB8_0813` | `u16 fn1AB8_0813(void * dxOut)` |
| 1AB8:0887 | `fn1AB8_0887` | `u8 fn1AB8_0887(u16 wArg02, u8 * ptrArg04, u8 * ptrArg08, u8 * ptrArg0C, u16 * dsOut)` |

### Hardware-site map

**None.** No `int 10h`/`int 16h`/`int 21h`, no `in`/`out` port instruction,
no `__cli`/`__sti` and no `int 23h` appears anywhere in 0000..0887. All
BIOS/DOS traffic is reached through segment 1EDA (`fn1EDA_0F26`, `0A39`,
`0A1F`, `0AAC`, `0B24`, `0B61`, `0FA2`, `0FD0`, `04A2`, `04A9`, `0848`,
`08CE`, `1051`, `116A`, `11DF`, `00E9`, `023F`/`0254` via the 1AB8:0538
thunk) and is replaced in the 1EDA port, not here.

### VGA far-pointer sites

**None.** No far pointer with segment 0xA000 occurs in this chunk, so
`pal_vga_memory()` is not referenced. The far pointers here are DGROUP,
code-segment, stack or runtime allocation values.

### Far (non-VGA) pointer sites — flat-model adaptations

* `0x1AB8:0x0036` / `0x006A` (008B), `0x1AB8:0x00D9..0x026D` (027E),
  `0x1AB8:0x05D0` (05D3), `0x1AB8:0x06C7` (06CA) — embedded code-segment
  strings, recovered as `&g_seg1AB8[off]`.
* `0xB6CA` (0887) is the file/stream block; DGROUP, recovered as
  `&g_dgroup[0xB6CA]`.
* `[0xB6C6]` (06CA:079D) is the DGROUP far code pointer assigned `1AB8:0538`
  by `fn1AB8_17AE`. Flat C cannot call a 16:16 code pointer; recovered as a
  file-static `fn1AB8_0538` (a private copy; part2 defines the same static for
  its own call sites) and documented inline.
* `fn1AB8_0569` receives a runtime segment:offset pair (`wArg0A` = offset,
  `wArg0C` = segment) plus two host pointers to the caller's record. The
  `fn1EDA_11DF` copy reconstructs both 16:16 addresses as `off | seg<<16`,
  the flat convention already used by `fn1AB8_0BAE`'s 1EDA:11DF call.
* `fn1AB8_05D3` / `fn1AB8_06CA` recover the original far offset/segment words
  from the incoming pointer as `(u16)(uintptr_t)ptrArg04` and
  `(u16)((uintptr_t)ptrArg04 >> 16)` (Reko's `(word16)ptrArg04` /
  `SLICE(...,word16,16)`); this is exact when the caller passes the 32-bit
  far value, e.g. `fn1AB8_0BAE`'s `(u8 *)(uintptr_t)LG32(0xB828)`.

### Shared staging

**None required.** No file-scope variable is shared with a function outside
0000..0887; `src/seg1AB8_shared.h` was not created. The only non-frozen
helper (`fn1AB8_0538`) is file-static in the part file.

### Uncertain sites / not recovered literally

1. **`fn1EDA_0B24` return polarity.** The .asm is ZF-based: `jz` at 05D3:0613
   and 06CA:06F6 means "strings equal", `jnz` at 06CA:0794 means "not equal".
   This port assumes the frozen `u8` return is **nonzero on equality**
   (matching Reko's `if (fn1EDA_0B24(...))` outer usage); the 06CA inner loop
   is therefore written as `if (fn1EDA_0B24(...) != 0) break;`, which is the
   asm-correct branch and differs from Reko's internally inconsistent
   `if (!fn1EDA_0B24(...)) break;`.
2. **`fn1AB8_0813` `dxOut`.** Frozen type is `void *`; Reko assigns the
   16-bit code selector `seg1AB8`. Both existing call sites
   (`fn1AB8_0BAE`, `fn1AB8_0EB5`) pass the address of a `u16` scratch, so the
   port writes a 16-bit `0x1AB8` rather than a host pointer, to avoid
   overrunning the caller's storage.
3. **`fn1AB8_008B` return.** Reko returns the `fn1EDA_00E9(1)` result (the
   fatal-error dispatcher; it terminates in DOS). Recovered as
   `(u16)(uintptr_t)fn1EDA_00E9(0x01)` for literal AX fidelity; the value is
   unused by both callers.
4. **`fn1EDA_04A9` at 008B:00C7 has no stack arguments in the .asm** (it only
   reads DGROUP:0x5380). Reko supplies the `fn1EDA_0848` result and `0xB9BC`
   as the first two frozen parameters; they are passed as dummies here.
5. **Runtime 16:16 far addresses** (0569's `fn1EDA_11DF`, 05D3/06CA's 0569
   call, `[0xB828]`-derived pointers) cannot be mapped to a host array from
   static data. They are preserved as the port's `off | seg<<16` scalar
   convention; correct dereferencing depends on the eventual 1EDA allocator
   (`fn1EDA_023F`/`0254`) representation.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1AB8_part1.c` — zero errors, zero warnings
  (`-Wall -Wextra` also clean).
* `grep -cE "Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>" src/seg1AB8_part1.c` — 0.
* Header inclusion in the same TU makes gcc reject any prototype divergence
  from `src/seg1AB8.h` — clean.
* `nm` — `T fn1AB8_0000`, `T fn1AB8_008B`, `T fn1AB8_027E`, `T fn1AB8_04F3`,
  `T fn1AB8_0569`, `T fn1AB8_05D3`, `T fn1AB8_06CA`, `T fn1AB8_0813`,
  `T fn1AB8_0887` (plus static `t fn1AB8_0538`).

## chunk 6

Functions converted (ascending offset), all defined in `src/seg1AB8_part6.c`:

| offset | function | frozen prototype |
| --- | --- | --- |
| 1AB8:19EE | `fn1AB8_19EE` | `void fn1AB8_19EE(u8 * ptrArg04, u8 * ptrArg08, u8 * ptrArg0C)` |
| 1AB8:1A62 | `fn1AB8_1A62` | `void fn1AB8_1A62(void * ss_bp)` |
| 1AB8:1A84 | `fn1AB8_1A84` | `void fn1AB8_1A84(void)` |
| 1AB8:1AA6 | `fn1AB8_1AA6` | `void fn1AB8_1AA6(u8 * ptrArg04)` |
| 1AB8:1AC2 | `fn1AB8_1AC2` | `void fn1AB8_1AC2(void)` |
| 1AB8:1ACE | `fn1AB8_1ACE` | `void fn1AB8_1ACE(u16 wArg04, u16 wArg06)` |
| 1AB8:1AF6 | `fn1AB8_1AF6` | `u8 fn1AB8_1AF6(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A, u16 * dxOut)` |
| 1AB8:1B3E | `fn1AB8_1B3E` | `void fn1AB8_1B3E(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)` |
| 1AB8:1B90 | `fn1AB8_1B90` | `void fn1AB8_1B90(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E)` |
| 1AB8:1C32 | `fn1AB8_1C32` | `u8 fn1AB8_1C32(u8 bArg04)` |
| 1AB8:1C4A | `fn1AB8_1C4A` | `u16 fn1AB8_1C4A(void)` |
| 1AB8:1C5A | `fn1AB8_1C5A` | `u16 fn1AB8_1C5A(void)` |

### Hardware-site map

**None.** No `int 10h`/`int 16h`/`int 21h`, no `in`/`out` port instruction, no
`__cli`/`__sti` and no `int 23h` occurs anywhere in 19EE..1C5A, so no `pal_*`
call is emitted. (`fn1AB8_1C32`/`1C4A`/`1C5A`/`1AF6`/`1B3E`/`1B90` look like they
could be hardware-shaped, but they are the register gateway to the *runtime
graphics driver*, not to the BIOS/video hardware; see below.)

### VGA far-pointer sites

**None.** No far pointer with segment 0xA000 occurs in this chunk, so
`pal_vga_memory()` is not referenced.

### Far (non-VGA) pointer sites — flat-model adaptations

* **`[0xB820]`/`[0xB822]` — graphics-driver dispatch (10 calls across the 9
  dispatch wrappers `1AA6`,`1AC2`,`1ACE`,`1AF6`,`1B3E`,`1B90`(x2),`1C32`,
  `1C4A`,`1C5A`).**
  `LG32(0xB820)` is the driver entry as a 16:16 far code pointer
  (`offset | segment<<16`).  The loaded driver is the relocated blob headed at
  `1AB8:2073` (`[0x2073] = +0x20` -> entry `1AB8:2093`, copied at run time by
  `fn1AB8_0569` -> `fn1EDA_11DF`); Reko left that region as data, so it is not
  recovered as C.  The only recovered target is the default `fn1AB8_008B`
  (`1AB8:008B`) staged by `fn1AB8_0813`, so `fn1AB8_call_0B820` issues that
  direct call when it is staged and is otherwise a no-op pass-through.  Same
  treatment as `fn1AB8_call_0B896` in chunk 2.
* **`fn1AB8_1AA6` (1AB8:1AA6).**  `les bx,[bp+6h] ; mov [0B89Fh],bx ;
  mov [0B8A1h],es` stores the incoming 16:16 far pointer's offset/segment
  words; recovered as `(u16)(uintptr_t)ptrArg04` / `(u16)((uintptr_t)ptrArg04
  >> 16)`, the same convention part 1 adopted for `fn1AB8_05D3`/`06CA`.  The
  caller (`fn1AB8_0BAE`) passes `&g_dgroup[0xB7D4]`; the two slots are only
  written here and never read inside the recovered image.  Note this deviates
  in value for DGROUP buffers (see uncertainty 3).
* **`fn1AB8_19EE`/`1A62`.**  Both `ptrArg0C` (`[bp+0Eh]`) and `ptrArg08`
  (`[bp+0Ah]`) / `ptrArg04` (`[bp+6h]`) receive word stores
  (`xor ah,ah ; mov es:[di],ax`) though the frozen prototypes type them
  `u8 *`; the stores are cast to `*(u16 *)` and documented inline.

### Shared staging

**None required.**  No file-scope variable is shared with a function outside
19EE..1C5A; `src/seg1AB8_shared.h` is not created.  The only non-frozen
helpers are file-static in this part: `fn1AB8_call_0B820` (the `[0xB820]`
dispatch stand-in) and the local `TFrame1A62`/`TRegs1AB8` types.

### Uncertain sites / not recovered literally

1. **The `[0xB820]` driver dispatch is not recovered.**  As in chunk 2's
   `[0xB896]` callback, a 16:16 runtime code pointer cannot be called from
   flat C and the target (the relocated `1AB8:2093` driver) is not a recovered
   function.  `fn1AB8_call_0B820` therefore only issues the recovered default
   `fn1AB8_008B` when `[0xB820]==0x008B:0x1AB8`; for a loaded driver it is a
   no-op that leaves the staged AX/BX/CX/DX unchanged.  Consequently the
   driver results consumed by `fn1AB8_1AF6` (return + `dxOut`),
   `fn1AB8_1C32` (return), `fn1AB8_1C4A`/`1C5A` (returns) are the staged input
   values (0 where the original left the register undefined), not real driver
   output; `fn1AB8_0AEE` therefore sees `fn1AB8_1C5A()==0` and
   `fn1AB8_1C4A()==0` instead of driver-reported values.
2. **`fn1AB8_1A62` caller frame.**  The original reads its caller's
   `[bp+6h]`/`[bp+0Ah]`; flat C has no caller `bp`, so `fn1AB8_19EE` (its only
   caller) passes the two pointers through the private `TFrame1A62` image.
   The frozen `void * ss_bp` parameter is honoured.
3. **`fn1AB8_1AA6` far offset/segment.**  `(u16)(uintptr_t)ptrArg04` is exact
   only when the caller passes a synthetic `off | seg<<16` value; the actual
   caller passes `&g_dgroup[0xB7D4]`, so the stored words are the host
   pointer's low/high halves.  The slots are write-only in the recovered code,
   so this is behaviourally inert here.
4. **`fn1AB8_1AF6` return / `fn1AB8_1C32` return.**  `1AF6` returns
   `SLICE(ax, byte, 8)` (AH) and writes `dxOut`; `1C32` returns AH (Reko:
   `return ah_16`).  With the stand-in these are the staged `LG8(0xB83F)` /
   `wArg0A` high bytes.  Both are ignored by the recovered callers within this
   segment.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1AB8_part6.c` — zero errors, zero warnings
  (`-Wall -Wextra` also clean).
* `grep -cE "Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>" src/seg1AB8_part6.c` — 0.
* Header inclusion in the same TU makes gcc reject any prototype divergence
  from `src/seg1AB8.h` — clean.
* `nm` — `T fn1AB8_19EE`, `T fn1AB8_1A62`, `T fn1AB8_1A84`, `T fn1AB8_1AA6`,
  `T fn1AB8_1AC2`, `T fn1AB8_1ACE`, `T fn1AB8_1AF6`, `T fn1AB8_1B3E`,
  `T fn1AB8_1B90`, `T fn1AB8_1C32`, `T fn1AB8_1C4A`, `T fn1AB8_1C5A`
  (plus static `t fn1AB8_call_0B820`).

## chunk 5b

Functions converted (ascending offset), all defined in `src/seg1AB8_part5b.c`:

| offset | function | frozen prototype |
| --- | --- | --- |
| 1AB8:1807 | `fn1AB8_1807` | `void fn1AB8_1807(void)` |
| 1AB8:180A | `fn1AB8_180A` | `void fn1AB8_180A(void)` |
| 1AB8:1855 | `fn1AB8_1855` | `void fn1AB8_1855(u8 * ptrArg04)` |
| 1AB8:1895 | `fn1AB8_1895` | `u16 fn1AB8_1895(u8 bArg04, u16 wArg06, u16 wArg08, u16 wArg0A, u16 wArg0C)` |
| 1AB8:18E3 | `fn1AB8_18E3` | `void fn1AB8_18E3(void)` |
| 1AB8:194E | `fn1AB8_194E` | `void fn1AB8_194E(u8 bArg04)` |
| 1AB8:1968 | `fn1AB8_1968` | `void fn1AB8_1968(u8 bArg04, u8 * ptrArg06)` |
| 1AB8:1992 | `fn1AB8_1992` | `void fn1AB8_1992(u8 bArg04, u8 bArg06)` |
| 1AB8:19A6 | `fn1AB8_19A6` | `u16 fn1AB8_19A6(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)` |

### Hardware-site map

* **1AB8:180A** — `mov ah,0Fh ; int 10h` -> `bios_video_get_current_video_mode(&mode, &page)`;
  the returned AL (mode) is stored to DGROUP `0xB8A3`, exactly as the original
  `mov [0B8A3h],al`.
* **1AB8:18E3** — `xor ah,ah ; mov al,[0B8A3h] ; int 10h` ->
  `bios_video_set_mode(LG8(0xB8A3))`.
* **0040:0010** — the BIOS equipment-word low byte read by 180A and written back
  by 180A/18E3.  No `pal.h` mapping exists, so it is a file-static `g_bda_0010`,
  the same treatment `src/seg1E78.c` gives `0040:0000/006C/0087`.
* No raw port I/O, no `int 16h`/`int 21h`, no `__cli`/`__sti` and no `int 23h`
  occur anywhere in 1807..19A6.

### VGA far-pointer sites

**None.** No far pointer with segment `0xA000` occurs in this chunk, so
`pal_vga_memory()` is not referenced.  The far pointers here are DGROUP slots
(accessed through the `LG` macros), the unrecovered driver 16:16 code pointers,
and caller-supplied far pointers carried as the port's `off | seg<<16` scalar
(`fn1AB8_1855`'s `(u16)(uintptr_t)ptrArg04` / `>>16`, `fn1AB8_1968`'s
`ptrArg06` likewise, matching part6's `fn1AB8_1AA6`).

### Shared staging

**None required.**  No file-scope variable or helper is shared with a function
outside 1807..19A6, so `src/seg1AB8_shared.h` was not created.  The
non-frozen helper `fn1AB8_call_0B820` (the `[0xB820]` dispatch stand-in), the
register-image type `TRegs1AB8`, and the BDA byte `g_bda_0010` are all
file-static in the part file (1807 and the two 0040:0010 users are inside this
chunk).

### Uncertain sites / not recovered literally

1. **The `[0xB820]` driver dispatch is not recovered.**  As documented for
   chunk 6, a 16:16 runtime code pointer cannot be called from flat C and the
   loaded driver (the blob headed at `1AB8:2073`) is not a recovered function.
   `fn1AB8_call_0B820` issues the recovered default `fn1AB8_008B` only when
   `[0xB820]==0x008B:0x1AB8`; otherwise it is a no-op that leaves the staged
   registers unchanged.  Consequently the driver results consumed here are the
   staged input values, not real driver output.
2. **`fn1AB8_1807` (original `push es / push bx / retf`).**  It is a trampoline
   that far-calls the code at ES:BX (the driver routine selected by 194E from
   driver-structure `+0x0E` and by 19A6 from `+0x08`) and returns to the caller
   when that routine `retf`s.  The target is part of the unrecovered driver, so
   the trampoline is a no-op stand-in.  Its frozen prototype is `void(void)`,
   so the callers stage nothing through it.
3. **1AB8:194E / 1AB8:19A6 driver-pointer field reads.**
   `mov bx,es:[bx+0Eh]` (194E) and `mov bx,es:[bx+8h]` (19A6) load the far-call
   target from the driver structure returned by the `si=32h` dispatch.  The
   structure pointer is unrecovered and may be a non-host 16:16 value, so the
   field is **not** dereferenced; only the `fn1AB8_1807` call site is kept.  The
   `push ax`/`pop ax` argument-cleanup around the 194E shared epilogue nets to
   nothing and is not modelled.
4. **`fn1AB8_19A6` driver AX return (`ax_33`).**  The original feeds the AX
   returned by the `si=32h` dispatch (and by the `fn1AB8_1807` far call) into
   the first `mul bx`.  With the no-op stand-in that value is the staged input
   AX (`ax_19 >> 2`), so `ax_33 = r.ax` after the dispatch.  This is the same
   "staged input stands in for the unrecovered driver output" convention as
   chunk 6.
5. **`fn1AB8_19A6` multiply widths.**  The `.asm` does `mul bx` (16x16->32,
   DX:AX) then `mul cx` (32x16->32, truncated mod 2^32); Reko instead truncates
   the first product to 16 bits (`uint16 ax_56 = ... * ax_33`).  The port keeps
   the asm's two full 32-bit products (`u32 ax_56 = (u32)ax_33 * (ax_19>>2)`,
   then `* (cx_47+1)`).
6. **`fn1AB8_19A6` overflow test.**  The `.asm` is `add ax,6h ; jc -> 0 ;
   and dx,dx ; jnz -> 0`, i.e. zero on 16-bit carry out of `ax_58+6`
   (`ax_58 >= 0xFFFA`) or nonzero `dx`.  Reko's IR/C inverted the carry branch
   (`ax_58 < 0xFFFA`); the port follows the raw bytes (`jc` = 0x72, confirmed in
   `data/segments/seg1AB8.bin`).
7. **The disassembler symbol `fn0800_3850`.**  The `.asm` prints the 180A/18E3
   compare operand as `[fn0800_3850]`; the raw bytes are `80 3E 50 B8 A5`
   (`cmp byte ptr [0B850h],0A5h`) and Reko's IR/`globals.tsv` agree on
   `ds:0xB850`, so `LG8(0xB850)` is used (the symbol is a linear-address
   artifact of the disassembler).

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1AB8_part5b.c` — zero errors, zero warnings
  (`-Wall -Wextra -Werror` also clean).
* `grep -cE "Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>" src/seg1AB8_part5b.c` — 0.
* Prototype check TU (`-Werror=incompatible-pointer-types`) assigning every
  function to an exactly-typed pointer against `src/seg1AB8.h` — OK.
* `nm` — `T fn1AB8_1807`, `T fn1AB8_180A`, `T fn1AB8_1855`, `T fn1AB8_1895`,
  `T fn1AB8_18E3`, `T fn1AB8_194E`, `T fn1AB8_1968`, `T fn1AB8_1992`,
  `T fn1AB8_19A6` (plus static `t fn1AB8_call_0B820`, `b g_bda_0010`).

## chunk 5a

Files: `src/seg1AB8_part5a.c`.  Functions: `fn1AB8_1536` (1AB8:1536),
`fn1AB8_1783` (1AB8:1783), `fn1AB8_17AE` (1AB8:17AE).

### The 17AE driver/dispatch table

`fn1AB8_17AE` installs these DGROUP words (values are 16-bit; the code-pointer
pairs use the `off | seg<<16` flat convention):

| DGROUP | value | meaning |
|---|---|---|
| `[0xB818]` | `0000` | error/status word |
| `[0xB7B6]` | `1000` | allocation granularity/transfer size |
| `[0xB6C2]`/`[0xB6C4]` | `1AB8:051F` | driver-blob **allocate** thunk |
| `[0xB6C6]`/`[0xB6C8]` | `1AB8:0538` | driver-blob **free** thunk |
| `[0xB74C]` | `00` (byte) | current driver file-name buffer |
| `[0xB756]` | `00` (byte) | driver path/suffix buffer |
| `[0xB7B8]` | `0006` | record count (video modes) |
| `[0xB7BA]` | `000A` | record count (display drivers) |
| `[0xB850]` | `0001` | |
| `[0xB84A]` | `0001` | |
| `[0xB84C]` | `0001` | |

`fn1AB8_1A84()` is also called first (it zeroes the `0xB89A..0xB8A4` state
block), then `fn1AB8_0813()` (which stages the **default** dispatch
`[0xB820]`/`[0xB822] = 1AB8:008B`, "graphics not initialized", plus the
`0xB824..0xB838`, `0xB7E0..`, `0xB74A` slots — see chunk 1).

**Correction to the brief.**  The brief described 17AE as pointing
`[0xB820]`/`[0xB822]` at the driver blob headed at `1AB8:2073` (entry
`2093`).  The raw bytes (`data/segments/seg1AB8.bin` at `0x17AE..0x1806`) and
`.asm` show 17AE only reaches `[0xB820]`/`[0xB822]` **indirectly**, through
`fn1AB8_0813`, which installs the `1AB8:008B` default.  The `1AB8:2073`
blob/`2093` entry is staged by `fn1AB8_0BAE` (chunk 2,
`LG16(0xB820)=0x2073; LG16(0xB822)=0x1AB8`), not by 17AE.  The 17AE table
above is complete and literal.

**Disassembler symbol artifact.**  The Reko `.asm` prints the `[0xB850]`
store as `mov word ptr [fn0800_3850],1h`.  The raw bytes are
`C7 06 50 B8 01 00` (`mov word ptr [0B850h],1`); this is the same
linear-address symbol artifact already recorded in item 7 of the chunk 5b
notes for the `0B850h` compare operand.  `LG16(0xB850)` is used.

### fn1AB8_1536 (video-driver loader)

* Literal recovery of the 0x0F-stride driver records at DGROUP `0x520B`
  (fields +0..+8; the same `TRec520B` layout chunk 2 documented).  The record
  is addressed with byte offsets (`pRec + n`) exactly as the `.asm` does.
* The two DGROUP far code pointers are called indirectly in the original:
  `call dword ptr [0B6C2h]` once (allocate) and `call dword ptr [0B6C6h]`
  twice (free).  As in chunks 1-2, the flat model calls the recovered
  file-static helpers `fn1AB8_051F`/`fn1AB8_0538` directly (each TU keeps its
  own `static` copy; the far-pointer thunks cannot be invoked from flat C).
* **Allocation read-out convention.**  `fn1EDA_10BB` is called with output
  pointer `0` (the `.asm` pushes `xor ax,ax` twice), count `wLoc02` and the
  `0xB6CA` FCB, matching the frozen 3-argument prototype; the original's
  separate buffer far pointer (`es:di = [bp-6h]`) has no slot in that
  prototype and is dropped, exactly as in chunks 1-2 (`fn1EDA_10BB`'s
  iface.tsv signature collapses the 4th stack argument).
* **`fn1EDA_1051` AL argument.**  The two `call far 1EDA:1051` sites push only
  the FCB; the frozen prototype's `al` is a register argument.  At 1AB8:16AC
  AX is 0 (the immediately preceding `or` jnz path leaves AX = 0); at
  1AB8:16DF AL is the low byte of the `fn1EDA_10BB` return — both are passed
  explicitly.
* **`fn1AB8_0887` `dsOut`.**  The frozen prototype's `u16 *dsOut` is a
  register-out artifact; a local `ds_1536` dummy is passed (as chunk 2 does
  with `ds_097B`).
* **`fn1AB8_06CA` validation.**  The `.asm` sign-extends the u16 return with
  `cwd` and compares the zero-extended `wArg08` against `DX:AX`, i.e. it
  matches only when `(s16)ret >= 0` and `ret == wArg08`.  The port keeps the
  16-bit signed comparison `(s32)(s16)ax_06CA != (s32)wArg08` rather than
  Reko's plain `u16` equality.
* **`fn1AB8_1DA6` return/`void *`.**  1536's frozen return type is `void *`
  while the callee's is `u16` (a driver selector).  The port mirrors chunk 1's
  pointer-from-integer convention: `(void *)(uintptr_t)fn1AB8_1DA6(...)`.
  `*dsOut = 0` (DGROUP selector dropped flat-model).
* **Unreachable bounds check.**  `cmp [bp+0Ah],0 ; jc` (1AB8:1543) is the
  16-bit "below zero" test and is unreachable after the preceding
  `ja 14h` unsigned guard; kept as the 16-bit signed `(s16)wArg08 < 0`.

### fn1AB8_1783

* `fn1EDA_0A39(0xFF, abBuf, ptrArg04, &dx_60)` then returns `fn1AB8_1E26()`.
  The 0x102-byte frame is the 0x100-byte string destination (`bp-0x102`) plus
  the `u16` result slot (`bp-2`).  No hardware, no far pointer beyond the
  caller-supplied one.

### Hardware / VGA far pointers

Neither function in this range issues a raw port I/O, an `int 10h/16h/21h`
or `__cli`/`__sti`, and no `0xA000` VGA far-pointer literal occurs.  All
BIOS/DOS work is reached through segment 1EDA.  The only far pointers are
DGROUP (`g_dgroup + off`), the code segment (`g_seg1AB8 + 0x1531`) and the
16:16 allocation slots documented above.

### Shared staging

None.  The two dispatch helpers the chunk consumes are functions, not
variables, and are kept as file-static copies (chunks 1-2 precedent); no
`src/seg1AB8_shared.h` entry was needed.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1AB8_part5a.c` — zero errors, zero warnings
  (`-Wall -Wextra -Werror` also clean).
* `grep -cE "Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>" src/seg1AB8_part5a.c` — 0.
* `nm` — `T fn1AB8_1536`, `T fn1AB8_1783`, `T fn1AB8_17AE`
  (plus static `t fn1AB8_051F`, `t fn1AB8_0538`).
* Prototypes match `src/seg1AB8.h` exactly.

## chunk 7

Functions converted (ascending offset), all defined in `src/seg1AB8_part7.c`
(12 functions):

| offset | function | frozen prototype |
| --- | --- | --- |
| 1AB8:1C6A | `fn1AB8_1C6A` | `u8 * fn1AB8_1C6A(void)` |
| 1AB8:1C93 | `fn1AB8_1C93` | `u16 fn1AB8_1C93(void)` |
| 1AB8:1CA4 | `fn1AB8_1CA4` | `void fn1AB8_1CA4(u8 bArg04)` |
| 1AB8:1CBA | `fn1AB8_1CBA` | `u16 fn1AB8_1CBA(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)` |
| 1AB8:1CD7 | `fn1AB8_1CD7` | `u8 fn1AB8_1CD7(s16 wArg04, u16 wArg06)` |
| 1AB8:1CED | `fn1AB8_1CED` | `void fn1AB8_1CED(u8 * ptrArg04)` |
| 1AB8:1CFF | `fn1AB8_1CFF` | `void fn1AB8_1CFF(u8 bArg04, u16 wArg06, u16 wArg08)` |
| 1AB8:1D5B | `fn1AB8_1D5B` | `void fn1AB8_1D5B(u8 bArg04, u8 bArg06)` |
| 1AB8:1D82 | `fn1AB8_1D82` | `u8 fn1AB8_1D82(u8 * ptrArg04, u16 wArg08, u16 wArg0A, u8 * chOut)` |
| 1AB8:1DA6 | `fn1AB8_1DA6` | `u16 fn1AB8_1DA6(u8 bArg04, u8 bArg06, u8 bArg08)` |
| 1AB8:1E0B | `fn1AB8_1E0B` | `u16 fn1AB8_1E0B(u8 * ptrArg04)` |
| 1AB8:1E26 | `fn1AB8_1E26` | `u16 fn1AB8_1E26(void)` |

### Hardware-site map

**None.** No `int 10h`/`int 16h`/`int 21h`, no `in`/`out` port instruction, no
`__cli`/`__sti` and no `int 23h` occurs anywhere in 1C6A..1E26, so no `pal_*`
call is emitted.  All twelve functions are wrappers around the runtime
graphics-driver dispatch (`call dword ptr [0B820h]`), not BIOS/video hardware.

### VGA far-pointer sites

**None.** No far pointer with segment `0xA000` occurs in this chunk, so
`pal_vga_memory()` is not referenced.

### Far (non-VGA) pointer sites — flat-model adaptations

* **`[0xB820]`/`[0xB822]` — graphics-driver dispatch (12 calls across the 12
  wrappers).**  `LG32(0xB820)` is the driver entry as a 16:16 far code pointer
  (`offset | segment<<16`).  Same file-static `fn1AB8_call_0B820` stand-in as
  chunks 5b/6 (each TU keeps its own `static` copy): it issues the recovered
  default `fn1AB8_008B` only when `[0xB820]==0x008B:0x1AB8` and is otherwise a
  no-op that leaves the staged AX/BX/CX/DX/ES unchanged.
* **`fn1AB8_1C6A` (1AB8:1C6A).**  `mov dx,es ; mov ax,bx` returns the far
  pointer ES:BX from the `si=3Ah` dispatch; recovered as the port's
  `off | seg<<16` scalar (`(u8 *)(uintptr_t)((u32)r.es<<16 | r.bx)`), the same
  convention chunks 1/2/5 use for runtime 16:16 far addresses (its only
  caller, `fn1AB8_1384`, takes AX=offset/DX=segment).  ES is a staged
  register here (see uncertainty 1).
* **`fn1AB8_1CED`, `fn1AB8_1D82`, `fn1AB8_1E0B` (caller-supplied far
  pointers).**  Each does `les bx,[bp+6h]`; the offset/segment are recovered
  as `(u16)(uintptr_t)ptrArg04` and `(u16)((uintptr_t)ptrArg04 >> 16)`, the
  same convention part6 used for `fn1AB8_1AA6`.
* **`fn1AB8_1DA6` DGROUP far pointer `[0xB83A]`/`[0xB83C]`.**  Reconstructed
  as `(u8 *)(uintptr_t)LG32(0xB83A)` (the `+0x10` field read and the `+1`
  byte read); same treatment chunk 2 gave this slot.
* **`fn1AB8_1E26` ES:BX = 1AB8:1E24.**  `push cs ; pop es ; mov bx,1E24h`
  builds a code-segment far pointer to the embedded two-byte string at
  `g_seg1AB8[0x1E24]`; staged as `es=0x1AB8`, `bx=0x1E24`.

### Shared staging

**None required.**  No file-scope variable is shared with a function outside
1C6A..1E26, so `src/seg1AB8_shared.h` was not created.  The only non-frozen
helpers are file-static in this part: `fn1AB8_call_0B820` (the `[0xB820]`
dispatch stand-in) and the local `TRegs1AB8` register-image type.  No existing
part file had to be touched.

### Uncertain sites / not recovered literally

1. **The `[0xB820]` driver dispatch is not recovered.**  As documented for
   chunks 5b/6, a 16:16 runtime code pointer cannot be called from flat C and
   the loaded driver (the relocated blob headed at `1AB8:2073`) is not a
   recovered function.  For every wrapper the consumed driver results
   (`fn1AB8_1C6A` ES:BX, `fn1AB8_1CBA` DX, `fn1AB8_1CD7` AH, `fn1AB8_1D82`
   AH/CH, `fn1AB8_1E0B` BX, `fn1AB8_1E26` CX, `fn1AB8_1C93` CX-1) are the
   staged input register values, not real driver output.
2. **`fn1AB8_1DA6` return value.**  The raw `.asm` `retf 6h` returns AX (the
   unrecovered `si=24h` driver result), but Reko's IR/live-out
   (`RAD_1AB8.dis`: `LiveOut: es:[0..15]-fn1AB8_1536`, `return es_11`) and the
   `selector` return type recover the value as the ES selector loaded from the
   `[0xB83A]`/`[0xB83C]` far pointer (`LG16(0xB83C)`).  The port follows Reko
   here because the driver call is unrecoverable and the only caller
   (`fn1AB8_1536`) consumes the result as that selector; the value is unused
   by every recovered caller of 1536.  The `si=24h` dispatch and its computed
   BX/CX/DX/AX arguments are still staged.
3. **`fn1AB8_1CBA` return register.**  Reko (`return dx_26`) and the actual
   13E2 caller (`dx = fn1AB8_1CBA(...)`) show the result is DX, not AX; the
   port returns `r.dx`.  With the stand-in this is the staged `wArg04`.
4. **AH inputs left as-is in the original.**  `fn1AB8_1C6A` sets only AL=1,
   `fn1AB8_1C93` only AL=1 before the dispatch; AH is whatever the caller
   left.  The stand-in does not model caller AH, so it is staged as 0 (no
   recovered caller reads it back for these two).
5. **`fn1AB8_1DA6` `mul` widths.**  The `.asm` uses `mul dl` (8x8 -> AX)
   twice; the port keeps the 8-bit factors `(u8)(bx_15>>8)*bArg04` and
   `(u8)bx_15*bArg04`, truncated through `(u16)` exactly as the original.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1AB8_part7.c` — zero errors, zero warnings
  (`-Wall -Wextra -Werror` also clean).
* `grep -cE "Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>" src/seg1AB8_part7.c` — 0.
* Prototype check TU (`-Werror=incompatible-pointer-types`) assigning every
  function to an exactly-typed pointer against `src/seg1AB8.h` — OK.
* `nm` — `T fn1AB8_1C6A`, `T fn1AB8_1C93`, `T fn1AB8_1CA4`, `T fn1AB8_1CBA`,
  `T fn1AB8_1CD7`, `T fn1AB8_1CED`, `T fn1AB8_1CFF`, `T fn1AB8_1D5B`,
  `T fn1AB8_1D82`, `T fn1AB8_1DA6`, `T fn1AB8_1E0B`, `T fn1AB8_1E26`
  (plus static `t fn1AB8_call_0B820`).

## chunk 8

Functions converted (ascending offset), all defined in `src/seg1AB8_part8.c`:

| offset | function | frozen prototype |
| --- | --- | --- |
| 1AB8:1E3C | `fn1AB8_1E3C` | `u16 fn1AB8_1E3C(u16 wArg04, u16 wArg06, u8 * dlOut)` |
| 1AB8:1E54 | `fn1AB8_1E54` | `u8 fn1AB8_1E54(u8 bArg04, u16 wArg06, u16 wArg08)` |
| 1AB8:1E6B | `fn1AB8_1E6B` | `void fn1AB8_1E6B(u8 * ptrArg04, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E)` |
| 1AB8:1E9F | `fn1AB8_1E9F` | `u16 fn1AB8_1E9F(u8 bArg04, u8 * ptrArg06, u16 wArg0A, u16 wArg0C)` |
| 1AB8:1EE3 | `fn1AB8_1EE3` | `void fn1AB8_1EE3(void)` |
| 1AB8:1F19 | `fn1AB8_1F19` | `void fn1AB8_1F19(void)` |
| 1AB8:1F80 | `fn1AB8_1F80` | `u8 fn1AB8_1F80(u8 * clOut, u16 * bxOut)` |
| 1AB8:1F9E | `fn1AB8_1F9E` | `void fn1AB8_1F9E(u8 cl, u16 bx)` |
| 1AB8:1FDE | `fn1AB8_1FDE` | `u8 fn1AB8_1FDE(u8 cl)` |
| 1AB8:1FED | `fn1AB8_1FED` | `u8 fn1AB8_1FED(void)` |
| 1AB8:200E | `fn1AB8_200E` | `u8 fn1AB8_200E(void)` |
| 1AB8:2011 | `fn1AB8_2011` | `u8 fn1AB8_2011(void)` |

### Hardware-site map

* **1AB8:1F19** — `mov ah,0Fh ; int 10h` -> `bios_video_get_current_video_mode(&mode, &page)`;
  the returned AL (mode) drives the `cmp al,7h` branch, exactly as the original.
* **1AB8:1F80** — `mov ax,1200h ; mov bl,10h ; mov bh,0FFh ; mov cl,0Fh ; int 10h`
  (AH=12h BL=10h, "return EGA information") -> `pal_bios_int10(regs)` with
  `regs = {AX,BX,CX,DX}`.  There is no named `bios_video_*` entry for AH=12h;
  the appended int-dispatch contract (`pal_bios_int10`) handles AH=12h (and
  stores BL=30h scan-line mode).  The CL/BH/BL the original tests are read
  back out of `regs`; CL is also the `clOut` passed on to `fn1AB8_1F9E`.
* **1AB8:1FED** — `mov ax,1A00h ; int 10h` (AH=1Ah AL=00h, "display
  combination code") -> `pal_bios_int10(regs)`; AL/BL are read back for the
  carry test.
* **1AB8:2011** — `mov dx,3BAh ; in al,dx` -> `pal_inport(0x3BA)` (literal
  port constant kept), read twice per retrace-poll iteration.
* No `int 16h` / `int 21h`, no `__cli`/`__sti`, no `int 23h` anywhere in
  1E3C..2011.

### VGA far-pointer sites

* **1AB8:1F64** — the B800:0000 text-buffer presence probe (`mov si,0B800h ;
  mov es,si ; xor si,si ; mov ax,es:[si] ; not ax ; not word ptr es:[si] ;
  cmp ax,es:[si]`) is addressed as `pal_vga_memory() + 0x18000`: the PAL's
  128 KiB shadow stands in for linear 0A0000h..0C0000h, so B8000h is exactly
  `+0x18000` into it.  Both the read and the write-back go through the same
  shadow pointer.
* **1AB8:1FBB** — the C000:0039 VGA/EGA BIOS signature probe (`cmp word ptr
  es:[39h],345Ah` / `es:[3Bh],3934h`) has no `pal.h` mapping and no ROM image
  is emulated.  It reads the file-static zero-filled `g_rom_c000` stand-in,
  so no signature is found and mode 9 is not selected.  See uncertain site 3.
* No segment-0xA000 far pointer is constructed in this range, so the only
  `pal_vga_memory()` use is the B800 shadow offset above.

### Graphics-driver dispatch (`call dword ptr [0B820h]`)

`fn1AB8_1E3C`, `fn1AB8_1E54`, `fn1AB8_1E6B`, `fn1AB8_1E9F` reach the runtime
graphics driver through the 16:16 far code pointer at DGROUP 0xB820/0xB822
(selectors SI=2Eh/30h/34h/36h).  As in chunks 5b/6/7 this is modelled by a
file-static `fn1AB8_call_0B820` stand-in over a `TRegs1AB8` register image
(extended here with DI because 1E6B passes the rect height in DI).  The loaded
driver (relocated blob headed at 1AB8:2073) is not recovered as C; when the
default `fn1AB8_008B` ("graphics not initialized") is staged the call is
issued, otherwise it is a no-op that leaves the staged registers unchanged.

### Shared staging

**None required.**  `src/seg1AB8_shared.h` was not created.  The register-image
type `TRegs1AB8`, the dispatch stand-in `fn1AB8_call_0B820`, and the C000 ROM
stand-in `g_rom_c000` are all file-static in the part file; no file-scope
variable or helper is shared with a function outside 1E3C..2011.  The `LG`
macros and `g_seg1AB8` (for the 1EE3 mode tables at 1EB9h/1EC7h/1ED5h) come
from `globals.h` as usual.

### Uncertain sites / not recovered literally

1. **`fn1AB8_200E` and Reko's inverted branch.**  The body is `xor al,al ; ret`
   (AL=0, CF=0); the sole caller, `fn1AB8_1F19`, does `call 200Eh ; jnc 1F2Ch`
   so the `mov [0B89Ch],6h` return is unreachable.  Reko (`RAD_1AB8.c`)
   recovers `if (!fn1AB8_200E())` around that block, which inverts the carry;
   the port follows the `.asm` and returns the flag (0), so the branch is not
   taken, matching the executable.
2. **`pal_bios_int10` does not model AH=12h BL=10h or AH=1Ah.**  `int10_core`
   only stores BL=30h scan-line mode for AH=12h and ignores AH=1Ah, so on the
   port `fn1AB8_1F80` stages CL=0Fh / BH=0FFh / BL=10h and therefore always
   takes the `cl >= 0Ch` "not EGA" path (returns carry clear / false), and
   `fn1AB8_1FED` sees AL=0 and always returns false.  The recovered register
   staging and flag arithmetic are exact; only the BIOS-provided AH=12h/1Ah
   *values* are absent from the PAL (a PAL limitation, not a conversion
   divergence).  On a real EGA/VGA both probes can succeed.
3. **C000:0039 ROM signature.**  No C000 BIOS ROM image exists in the port and
   `pal.h` has no mapping, so `fn1AB8_1F9E` reads the zero-filled file-static
   `g_rom_c000`; the 345Ah/3934h signature is therefore never matched and mode
   9 is only reachable through the `fn1AB8_1FED` path (which is always false
   per site 2).  The literal compare/store structure is preserved.
4. **`fn1AB8_1E54` return register.**  The body sets `DL` before the `[0B820h]`
   call and never moves `AL`; Reko recovers the byte result as `dl_17`, and
   the port returns `(u8)r.dx` to match.  Every observed caller (fn0C74_0A35,
   fn0C74_076B) discards the value, so the choice is behaviourally inert.
5. **`fn1AB8_1E9F` return register.**  Reko recovers the word result as
   `dx_17`; the port returns `r.dx`.  The sole caller (fn1AB8_13D7 at
   1AB8:147E) overwrites AX immediately after the call, so the value is
   unused.
6. **Unset registers staged as 0.**  As in prior chunks, registers the
   original leaves undefined before a dispatch / `int 10h` (e.g. CX/CH, DX in
   1F80; BX/CX/DX in 1FED; AX in 1E6B/1E9F) are staged as 0 and noted in the
   code; no recovered caller reads those fields back.
7. **`fn1AB8_1E6B` rect update.**  The `.asm` writes the two 16-bit extents
   (xmax-xmin, ymax-ymin) through the far pointer ES:BX before the dispatch;
   the port stores them at `*(u16*)ptrArg04` and `*(u16*)(ptrArg04+2)` (flat
   pointer), and DI carries the height to the driver.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1AB8_part8.c` — zero errors, zero warnings
  (`-Wall -Wextra -Werror` also clean).
* `grep -cE "Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>" src/seg1AB8_part8.c` — 0.
* Including `src/seg1AB8.h` in the TU makes gcc reject any prototype
  divergence from the frozen signatures — clean.
* `nm` — `T fn1AB8_1E3C`, `T fn1AB8_1E54`, `T fn1AB8_1E6B`, `T fn1AB8_1E9F`,
  `T fn1AB8_1EE3`, `T fn1AB8_1F19`, `T fn1AB8_1F80`, `T fn1AB8_1F9E`,
  `T fn1AB8_1FDE`, `T fn1AB8_1FED`, `T fn1AB8_200E`, `T fn1AB8_2011`
  (plus static `t fn1AB8_call_0B820`).

## chunk 4

Functions converted (ascending offset), all defined in `src/seg1AB8_part4.c`:

| offset | function | frozen prototype |
| --- | --- | --- |
| 1AB8:11FB | `fn1AB8_11FB` | `u16 fn1AB8_11FB(u16 wArg02, void * dsOut)` |
| 1AB8:122E | `fn1AB8_122E` | `u16 fn1AB8_122E(u16 wArg04, u16 wArg06, u16 wArg08)` |
| 1AB8:1250 | `fn1AB8_1250` | `void fn1AB8_1250(u16 wArg04)` |
| 1AB8:1285 | `fn1AB8_1285` | `void fn1AB8_1285(void)` |
| 1AB8:129A | `fn1AB8_129A` | `void fn1AB8_129A(void * ptrArg04)` |
| 1AB8:1342 | `fn1AB8_1342` | `u8 fn1AB8_1342(u8 bArg04, u16 wArg06)` |
| 1AB8:1384 | `fn1AB8_1384` | `void fn1AB8_1384(u8 * ptrArg04)` |
| 1AB8:13A3 | `fn1AB8_13A3` | `u16 fn1AB8_13A3(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)` |
| 1AB8:13D7 | `fn1AB8_13D7` | `u16 fn1AB8_13D7(u8 bArg04, u8 * ptrArg06, u16 wArg0A, u16 wArg0C)` |
| 1AB8:1492 | `fn1AB8_1492` | `void fn1AB8_1492(u8 * ptrArg04)` |
| 1AB8:14F4 | `fn1AB8_14F4` | `void fn1AB8_14F4(u16 wArg04, u16 wArg06)` |

### Hardware-site map

**None.** No `int 10h`/`int 16h`/`int 21h`, no `in`/`out` port instruction,
no `__cli`/`__sti` and no `int 23h` occurs anywhere in 11FB..14F4.  All
BIOS/DOS traffic is reached indirectly through segment 1EDA (`fn1EDA_096F`,
`098A`, `0953`, `11DF`, `0A39`) or through the segment-1AB8 graphics-driver
dispatch helpers (`fn1AB8_1C6A`/`1CD7`/`1CED`/`1D82`/`1E0B`) and is replaced
in those ports, not here.

### VGA far-pointer sites

**None.** No far pointer with segment 0xA000 occurs in this chunk, so
`pal_vga_memory()` is not referenced.  The far pointers here are DGROUP
(`g_dgroup + off`), stack buffers, or caller-supplied flat pointers.
No runtime 16:16 `off | seg<<16` scalar slots are produced by this chunk
either.

### Shared staging

**None required.** No file-scope variable is shared with a function outside
11FB..14F4, so `src/seg1AB8_shared.h` was not created.  The chunk defines no
non-frozen helpers (all callees are frozen prototypes from `seg1AB8.h` /
`seg1EDA.h`).

### Uncertain sites / not recovered literally

1. **`fn1AB8_1285` return value vs frozen `void` prototype (1AB8:1285).**
   The `.asm` materialises `AX = (u16)LG8(0xB83E)` (`mov al,[0B83Eh];
   xor ah,ah; mov [bp-2h],ax; mov ax,[bp-2h]`) and its only callers
   (`fn0C74_011E` 0C74:016C, `fn0C74_020C` 0C74:025A) consume it:
   `call far 1AB8h:1285h ; mov [bp-6h],ax`.  The frozen `seg1AB8.h`
   prototype (iface.tsv confidence "mech") is `void fn1AB8_1285(void)`, so
   the value cannot be returned without editing the header.  The recovered
   body keeps the original DGROUP read and discards the value.  **The frozen
   prototype should be corrected to `u16 fn1AB8_1285(void)` and the header
   regenerated**; until then `fn0C74` cannot observe the value.  This is a
   genuine iface.tsv divergence; it is flagged here and must be recorded in
   `docs/PORT.md` per CONVENTIONS.md rule 7 (this chunk was not permitted to
   touch `docs/PORT.md`).
2. **`fn1AB8_11FB` / `fn1EDA_098A` stack arguments (1AB8:11FB).**  The `.asm`
   pushes `dx:ax` (= `0 : LG16(0xB84C)`) before the `1EDA:096F` multiply and
   pops them into `bx:cx` *before* the `1EDA:098A` call, so 098A's `wArg00` /
   `wArg02` stack words are whatever remains at the caller's frame bottom (the
   original relies on leftover stack slots, only used in 098A's divide-by-zero
   fatal path).  Reko's IR recovers them as `ax_11` and `0`; the port passes
   those values.  A garbage stack read cannot be reproduced in flat C.
3. **`fn1AB8_1342` return byte (1AB8:1342).**  Reko's IR returns
   `SLICE(ax, byte, 8)` (the high byte).  The physical x86 return is `AX`, so
   the meaningful `u8` a caller reads is `AL`; Reko's slicing is an artifact.
   All recovered callers (`fn0800_*`) ignore the return, so the port keeps the
   IR's `(u8)(ax >> 8)` form.  Early-return paths, whose `AX` is undefined in
   the original, are modelled with `ax = 0`.
4. **`fn1AB8_13A3` error constant (1AB8:13C2).**  The slice text reads
   `cmp word ptr [bp-4h],0FFh`, but the encoding is `83 7E FC FF`
   (`cmp r/m16, imm8`), so the 0xFF is sign-extended and the effective compare
   is **0xFFFF** — confirmed by Reko IR (`branch ax_24 != 0xFFFF`).  The port
   tests `ax_24 == 0xFFFF`.
5. **`fn1AB8_13D7` / `fn1AB8_14F4` dead `jc` branches (1AB8:144F, 14F4:14F4).**
   The `.asm`/IR's `cmp word ptr [..],0 ; jc` (and `cmp word ptr [bp+8h],0 ;
   jc` / `[bp+6h],0 ; jc`) are *unsigned* `<u 0` tests, which are never taken
   (IR confirms `branch ... <u 0`).  They are omitted with an explanatory
   comment; the observable control flow is unchanged.  (The `.asm` bytes
   `72`/`72` confirm `jc`, not `js`.)
6. **`fn1AB8_13D7` high-word compare (1AB8:143E/1440).**  The `.asm` compares
   the 32-bit values `0:[0B7C2h]` and `sign32(wArg0C+[0B852h]) + ptrArg06[0]`
   with `cmp dx,bx ; jl ; jg ; cmp ax,cx ; jc`.  Reko's IR proves both
   high-word branches dead and keeps only `ax_66 <u ax_59`; the port does the
   same (the earlier `1444` signed test catches the negative-sum case), so the
   behaviour is identical.
7. **`fn1AB8_122E` return (1AB8:122E).**  Reko returns the DGROUP selector
   carried in `ds_36`; the flat model drops it (`return 0x0000`), matching the
   iface.tsv note.  The sole caller `fn0800_3CFA` (0800:3D18) ignores `AX`.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1AB8_part4.c` — zero errors, zero warnings
  (`-Wall -Wextra -Werror` also clean).
* `grep -cE "Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>" src/seg1AB8_part4.c` — 0.
* Including `src/seg1AB8.h` in the TU makes gcc reject any prototype
  divergence from the frozen signatures — clean.
* `nm` — `T fn1AB8_11FB`, `T fn1AB8_122E`, `T fn1AB8_1250`,
  `T fn1AB8_1285`, `T fn1AB8_129A`, `T fn1AB8_1342`, `T fn1AB8_1384`,
  `T fn1AB8_13A3`, `T fn1AB8_13D7`, `T fn1AB8_1492`, `T fn1AB8_14F4`
  (11 symbols).

## chunk 9

Function converted, defined in `src/seg1AB8_part9.c` (1 function):

| offset | function | frozen prototype |
| --- | --- | --- |
| 1AB8:2043 | `fn1AB8_2043` | `u16 fn1AB8_2043(void)` |

This is the `analysis/slices/1AB8/index.tsv` `kind=fn` row at offset 2043.  The
Reko slice's range technically continues to segment end, but the trailing bytes
(1AB8:2073 onward) are the relocated graphics-driver data blob, not code; the
conversion ends at the function's `ret` (1AB8:2072).

### Purpose (recovered)

A video-adapter probe.  It issues `INT 10h AH=30h AL=06h`; if the BIOS returns a
non-null far pointer `CX:DX`, it reads the byte at `CX:DX+2` and, when that byte
is 0 or 2 and I/O port `188h` has bit 4 set, returns `AX=1` (adapter present).
The only caller, `fn1AB8_1F19`, then stages `LG8(0xB89C)=0Ah`.  Decoding the
1AB8 mode tables (`seg1AB8.bin`): table `0x1EB9[0x0A]=0x05`, table
`0x1EC7[0x0A]=0x00`, table `0x1ED5[0x0A]=0x00`; record 5 of the DGROUP mode
records (base `0x50FC`, stride `0x1A`) is `"IBM851"`, i.e. the probe identifies
an IBM 8514-class adapter.  `LG8(0xB89B)`/`LG8(0xB89D)` become 0.

### Hardware-site map

* **1AB8:2043** — `mov al,6h ; xor cx,cx ; xor dx,dx ; mov ah,30h ; int 10h`
  -> `pal_bios_int10(regs)` with `regs = {AX,BX,CX,DX}`,
  `regs[0]=0x3006` (AH=30h AL=06h), `regs[1]=0` (BX not set by the original),
  `regs[2]=0`/`regs[3]=0` (pre-`int` CX/DX, also the return slots).  There is
  no named `bios_video_*` entry for AH=30h, so the generic int 10h gateway
  (appended int-dispatch contract, as chunk 8 did for AH=12h/1Ah) is used.
* **1AB8:2064** — `mov dx,188h ; in al,dx` -> `pal_inport(0x0188)`; the
  literal port constant is kept.  `test al,4h` is preserved as `& 0x04`.
* No `int 16h` / `int 21h` / `__cli` / `__sti` / `int 23h` occurs here.

### VGA far-pointer sites

**None.**  No segment-`0xA000` far pointer occurs, so `pal_vga_memory()` is not
referenced.  The only far pointer is the `CX:DX` BIOS return (below).

### Far-pointer site — flat-model adaptation

* **`INT 10h AH=30h` return `CX:DX` (1AB8:2053..205F).**  The original does
  `push ds ; mov ds,cx ; mov bx,dx ; mov al,[bx+2h] ; pop ds`.  The PAL does
  not emulate the video-BIOS memory that pointer addresses, so the recovered
  read indexes a file-static zero-filled page `g_vbios_30[0x10000]` with the
  original's 16-bit offset arithmetic (`(u16)(dx + 0x02)`); this is the same
  stand-in treatment chunk 8 gave the C000 ROM (`g_rom_c000`) and chunk 5b gave
  the BDA byte (`g_bda_0010`).  The pointer's segment (`CX`) selects the BIOS
  page and is not represented by the stand-in.  Reko could not model the
  pointer at all (it emitted `bios_video_unknown_1030()` plus a dead
  `if (false)` block reading `[0000:0002]`, because it treated CX/DX as still
  zero from the preceding `xor`); the `.asm` proves the branch is live on real
  hardware.

### Shared staging

**None required.**  `src/seg1AB8_shared.h` was not created.  The only non-frozen
object is the file-static zero-filled `g_vbios_30` stand-in; no file-scope
variable or helper is shared with a function outside 1AB8:2043.

### Uncertain sites / not recovered literally

1. **PAL does not implement `int 10h AH=30h`.**  `pal/int.c`'s `int10_core`
   falls through its `default:` arm and leaves `CX`/`DX` as passed in, so on
   the port the returned far pointer is `0:0`, `(cx|dx)==0`, and `fn1AB8_2043`
   always returns 0 (mode `0Ah`/IBM 8514 is never selected).  This matches a
   real machine whose BIOS lacks AH=30h; on a machine whose BIOS implements it
   the probe can succeed.  The recovered register staging and branch structure
   are exact; only the BIOS-provided pointer is absent from the PAL (a PAL
   limitation, not a conversion divergence).
2. **Unemulated `CX:DX` target memory.**  The `+2` byte read has no
   corresponding host image; it is modelled with the zero-filled `g_vbios_30`
   stand-in (see the far-pointer note above).  While unreachable on the port
   (site 1), the byte would read 0 on a machine whose BIOS returns a null
   pointer into an unemulated page; the 0/2 test is preserved literally.
3. **`int 10h AH=30h` identity.**  The exact BIOS function behind `AH=30h` is
   not documented in the standard INT 10h list; the recovered behaviour (a
   `CX:DX` far-pointer return feeding an 8514-class mode selection) is what the
   bytes prove.  The PAL's generic gateway is the faithful hardware
   replacement regardless of the vendor meaning.
4. **Unset registers staged as 0.**  `BX` is not set before the `int 10h`
   (chunk 5b/6/8 convention); no recovered code reads it back from AH=30h.

### Validation

* `gcc -c -Wall -Isrc -Ipal src/seg1AB8_part9.c` — zero errors, zero warnings
  (`-Wall -Wextra -Werror` also clean).
* `grep -cE "Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>" src/seg1AB8_part9.c` — 0.
* Prototype check TU (`-Werror=incompatible-pointer-types`) assigning
  `fn1AB8_2043` to an exactly-typed pointer against `src/seg1AB8.h` — OK.
* `nm` — `T fn1AB8_2043` (plus static `b g_vbios_30`, `U pal_bios_int10`,
  `U pal_inport`).
* Raw bytes at `data/segments/seg1AB8.bin` 0x2043..0x2072 cross-checked
  against the slice `.asm` (`b0 06 33 c9 33 d2 b4 30 cd 10 ... c3 33 c0 c3`).
