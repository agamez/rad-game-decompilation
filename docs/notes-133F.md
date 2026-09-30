# Notes: segment 133F (15 functions, 0056..0816)

Recovery notes for `src/seg133F.c`.
Ground truth = `analysis/slices/133F/133F_<off>.asm` (and `analysis/reko/RAD_133F.asm`);
structure from `analysis/reko/RAD_133F.c`; frozen prototypes from `src/seg133F.h`
(derived from `analysis/summary/iface.tsv`). See `CONVENTIONS.md`.

## Functions converted (ascending offset)

| offset | function | frozen prototype |
| --- | --- | --- |
| 133F:0056 | `fn133F_0056` | `u16 fn133F_0056(u16 * dsOut)` |
| 133F:0137 | `fn133F_0137` | `u8 fn133F_0137(u16 * dxOut, u16 * bpOut, void * dsOut)` |
| 133F:0141 | `fn133F_0141` | `u8 fn133F_0141(s16 * dxOut, u16 * bpOut, void * dsOut)` |
| 133F:014B | `fn133F_014B` | `u8 fn133F_014B(u8 * ptrArg04, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E, u16 * dxOut, u16 * dsOut)` |
| 133F:0200 | `fn133F_0200` | `void fn133F_0200(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)` |
| 133F:021F | `fn133F_021F` | `u8 fn133F_021F(u16 wArg04, u16 wArg06)` |
| 133F:0256 | `fn133F_0256` | `void fn133F_0256(u16 wArg04, u16 wArg06)` |
| 133F:026B | `fn133F_026B` | `u8 fn133F_026B(u16 wArg04, u16 wArg06, u16 * dxOut, void * dsOut)` |
| 133F:02DF | `fn133F_02DF` | `void fn133F_02DF(u8 * ptrArg04, u8 bArg08)` |
| 133F:0352 | `fn133F_0352` | `u16 fn133F_0352(u8 * ptrArg04, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E, u8 bArg10)` |
| 133F:04A7 | `fn133F_04A7` | `void fn133F_04A7(void)` |
| 133F:04B1 | `fn133F_04B1` | `u16 fn133F_04B1(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A, void * dsOut)` |
| 133F:04DE | `fn133F_04DE` | `u16 fn133F_04DE(u8 * ptrArg04)` |
| 133F:0528 | `fn133F_0528` | `u16 fn133F_0528(s16 dx, u8 * ptrArg06, u8 * ptrArg0A, u8 * ptrArg0E, s16 * dxOut, u16 * bpOut, u16 * dsOut)` |
| 133F:0816 | `fn133F_0816` | `u16 fn133F_0816(void)` |

`fn133F_0816` is the CRT-chain initialiser called from `fn0800_4255`
(`fn1206_0217(fn133F_0816(fn13C1_0067()))`); it forwards to `fn133F_0056`,
which validates the BGI driver via `fn1AB8_0BAE`/`fn1AB8_04F3`.

## Hardware / dispatch sites

**No direct hardware in this segment.** There is no `int 10h` / `int 16h` /
`int 21h`, no `in`/`out` port instruction, no `__cli`/`__sti` and no `int 23h`
anywhere in 133F. There is also no raw IVT dispatch (`fn1E5F_000B`) and no
segment-0xA000 VGA far-pointer literal. All hardware traffic is indirect and is
replaced in the callee segments:

* keyboard: `fn133F_0528` calls `fn1E78_02FB` (INT 16h AH=01) and
  `fn1E78_030D` (INT 16h AH=00), replaced in `src/seg1E78.c`.
* mouse (INT 33h): `fn133F_0056` calls `fn13C8_0000/000D/00BF/00E4`,
  `fn133F_0137` calls `13C8:004F`, `fn133F_0141` calls `13C8:0038`,
  `fn133F_0528` calls `13C8:0066/009A`, `fn133F_04B1` calls
  `13C8:00BF/00E4` and `fn133F_04DE` calls `13C8:009A`; every one of them is
  replaced in `src/seg13C8.c` (INT 33h via `fn1E5F_000B` -> `pal_int_dispatch`).

## Far-pointer / flat-model adaptations

* DGROUP data is addressed with `LG8`/`LG16` at the literal offsets; the
  `~0x4643` / `0xB6xx` / `0x50CA` / `0x6CC0..0x6DCA` offsets are preserved.
* `cs:0000`, `cs:0001`, `cs:0014`, `cs:003D` and `cs:0269` become
  `g_seg133F[0x0000]`, `[0x0001]`, `[0x0014]`, `[0x003D]`, `[0x0269]`.
* The out-parameter pointers (`dxOut`, `bpOut`, `dsOut`) are forwarded to the
  callees exactly as the frozen prototypes require. The DGROUP selector (`DS`)
  outputs are dropped in the flat model: `*dsOut` is stored as 0 (`fn133F_0056`,
  `fn133F_0528`) and functions that returned the selector return the value their
  callees wrote (`fn133F_0352`, `fn133F_04DE`) or the frozen `u16` return.
* Compiler stack-reuse tricks (the original leaves a far pointer on the stack
  across consecutive `fn1EDA_08CE`/`0A1F`/`0AAC` calls that pop 6/4/4 bytes, and
  the `push cs ; call near` self-segment pseudo-far calls in 0200/026B/02DF/
  04B1/0141) are not reproduced; the recovered code passes the shared buffers
  explicitly to each call, which is behaviour-equivalent.

## Uncertain sites / not recovered literally

1. **`fn133F_04DE` missing stack arguments (133F:04DE, retf 0Ch).** The real
   frame is `far ptr (bp+6..9)` + four words (`bp+A`, `bp+C`, `bp+E`, `bp+10`);
   `fn133F_04DE` reads `[bp+0Eh]`/`[bp+10h]` and stores them to `[0B6B6]`/
   `[0B6B8]` and passes them to `fn13C8_009A`. The frozen prototype carries only
   `u8 * ptrArg04`, so these two values cannot be represented. The sole caller
   (1229:0D79, inside `fn1229_0DCC`) pushes the literals `0064h` (-> `[bp+10h]`)
   and `0192h` (-> `[bp+0Eh]`), so the stores and the `fn13C8_009A` call are
   kept with those recovered constants to preserve the executable's behaviour.
   The other two caller words (`[bp+0Ah]`/`[bp+0Ch]`, both 0) are unused by
   `fn133F_04DE`.
2. **`fn133F_0528` first stack word (133F:0528, retf 0Eh).** The original frame
   is `word flag (bp+6)` + three far out-pointers (`bp+8` y, `bp+0Ch` x,
   `bp+10h` key); `bp+6` is the `[50C7h]` word every caller pushes. Reko did not
   model it as a parameter, so the frozen prototype exposes the scalar `dx`
   parameter instead of it. The recovered code takes `bFlag = (u8)dx` and uses
   it for the two `cmp byte ptr [bp+6],0` tests; the port's callers must pass the
   flag in that first argument. `dx_cur` also starts from `dx` and is updated by
   `fn13C8_009A`/`fn1E78_030D` exactly as Reko's `dx` local.
3. **`fn133F_0528` `bpOut`/`dsOut`.** At `retf` only `AL` (`[bp-1]`) and `DX`
   are meaningful; Reko modelled `bpOut` as the saved BP (a frame artefact) and
   `dsOut` as the dropped DGROUP selector. The recovered code stores 0 to both.
4. **`fn133F_0137`/`fn133F_0141` return value.** They are pure forwarding
   wrappers (`call 13C8:004F` / `0038`, then `leave; retf`), so the recovered
   code returns the callee's `AL`; Reko modelled the return as constant `0x00`.
   All callers ignore it.
5. **`fn133F_0056` / `fn133F_014B` / `fn133F_026B` return values.** Reko models
   `0x00`; the asm's `AL` is whatever the last callee left (`fn1AB8_1C32`,
   `fn1AB8_1D82`, `fn133F_014B` respectively). Reko's `0x00` is kept; all callers
   ignore the result.
6. **`fn133F_04DE` `fn13C8_009A` out-params.** `bp_130`/`ds_131` are passed as
   distinct locals mirroring Reko; the translated `fn13C8_009A` does not write
   them.
7. **`fn133F_026B` 16-bit division overflow.** The original `idiv` traps on a
   16-bit quotient overflow; the recovered `s32/s16` division truncates with the
   same low-16 result otherwise. The divisor (`[6CC0h]`/`[6CC2h]`) being zero
   traps in the original and is undefined in C; kept as division.
8. **`fn1E78_030D` call arguments (133F:0556 / 133F:05A2).** The asm calls
   `030D` with no pushes, but the frozen prototype is
   `u16 fn1E78_030D(s16 dx, u16 wArg02, u16 * dxOut)`. Reko passed its `dx`
   local, the (dropped) `ds` selector and `dxOut`. The recovered calls pass
   `(dx_cur, 0x0000, &dx_cur)`: `wArg02` is the dropped `ds` (0) and the value
   only reaches `fn1E78_0143`, which uses it solely on its Ctrl-Break path
   (`LG8(0xB8BA) != 0`).

## Validation

* `gcc -c -Wall -Isrc -Ipal src/seg133F.c` — zero errors, zero warnings
  (also clean with `-Wextra`).
* Reko-token grep `grep -cE "Eq_[0-9]|Mem[0-9]*\[|<invalid>|<unknown>"`
  on `src/seg133F.c` — 0.
* All 15 functions from `analysis/slices/133F/index.tsv` (kind=fn) defined in
  ascending offset order with the exact frozen `src/seg133F.h` prototypes.
* `nm /tmp/seg133F.o` shows `T` for all 15 symbols.
