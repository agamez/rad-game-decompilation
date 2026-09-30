# Notes: segments 1E5F, 1E78, 11C8

Recovery notes for `src/seg1E5F.c`, `src/seg1E78.c`, `src/seg11C8.c`.
Ground truth = `analysis/reko/RAD_<seg>.asm`; structure from `RAD_<seg>.c`.
These are candidates for the "Hardware interfaces replaced" / "Portions not
recovered literally" sections of `docs/PORT.md` (that file is frozen for this
task).

## Hardware-site map (original -> PAL call)

### seg1E5F (DOS utility wrappers)
| offset | original | replacement |
| --- | --- | --- |
| 1E5F:000B | far call through `IVT[vec]` with a 9-word register image; callers use vec 33h (mouse) / 10h (video); `__cli` | **dropped** — `pal.h` has no "invoke interrupt vector with register block" entry. The register-image block reads that Reko recovered are kept. The vector number lives in the original 3rd stack word and is absent from the frozen prototype. |
| 1E5F:0081 | `int 21h` AH=2Ch | `msdos_get_system_time` |
| 1E5F:0128 | `int 21h` AH=1Ah | `msdos_set_DTA` |
| 1E5F:0124 | `int 21h` AH=4Eh | `msdos_find_first_file` (CX attribute mask = `wArg08` is unused: no PAL parameter) |
| 1E5F:0128 | `int 21h` AH=1Ah (find-next wrapper) | `msdos_set_DTA` |
| 1E5F:012A | `int 21h` AH=4Fh | `msdos_find_next_file` |
| 1E5F:0191 | `int 21h` AH=35h | `msdos_get_interrupt_vector` |
| 1E5F:0213 | `int 21h` AH=25h | `msdos_set_interrupt_vector` |

### seg11C8 (AdLib / OPL2 + Sound Blaster detection)
All raw port I/O kept its literal port numbers:
| offset | original | replacement |
| --- | --- | --- |
| 11C8:0282 | `out dx,al` dx=388h; `in al,dx` x6 | `pal_outport(0x0388,...)`; `pal_inport(0x0388)` |
| 11C8:0296 | `out dx,al` dx=389h; `in al,dx` dx-- (=388h) x35h | `pal_outport(0x0389,...)`; `pal_inport(0x0388)` |
| 11C8:0092 | dynamic `mov dx,ax; in/out al,dx` at base+6/+A/+C/+E, base from `[5978h]` | `pal_inport`/`pal_outport` with `LG16(0x5978)+k` |
| 11C8:0236 | dynamic `out` at base+4/+5 | `pal_outport` with `LG16(0x5978)+k` |

### seg1E78 (BIOS video/keyboard, speaker, timing)
| offset | original | replacement |
| --- | --- | --- |
| 1E78:0609 | `int 10h` (generic gateway, many AH) | AH=00 -> `bios_video_set_mode`; AH=0F -> `bios_video_get_current_video_mode`; other AH dropped (no PAL equivalent) |
| 1E78:0143 | `int 16h` AH=01 / AH=00 (drain loop) | `bios_kbd_check_keystroke` / `bios_kbd_get_keystroke` |
| 1E78:02FB | `int 16h` AH=01 | `bios_kbd_check_keystroke` |
| 1E78:030D | `int 16h` AH=00 | `bios_kbd_get_keystroke` |
| 1E78:0150 | `int 23h` | dropped (Ctrl-C) |
| 1E78:00E9 | `in al,61h` | `pal_inport(0x61)` |
| 1E78:00F3/0101 | `out 61h,al` | `pal_outport(0x61,...)` |
| 1E78:00F7 | `out 43h,al` | `pal_outport(0x43,0xB6)` |
| 1E78:010B/0110 | `out 42h,al` (divisor lo/hi) | `pal_outport(0x42,...)` |
| 1E78:0213 | `int 21h` AH=25h vec 1Bh | `msdos_set_interrupt_vector(0x1B, &g_seg1E78[0x12D])` |

## Portions not recovered literally / uncertainties

1. **`fn1E78_0609` is a generic `int 10h` multiplexer.** The frozen prototype
   is `u16 fn1E78_0609(void)` (Reko did not model AH as an input). C has no
   AH/AL/BH/BL/CH/CL/DH/DL registers, so the recovered callers stage register
   values in the file-scope `g_bios10_*` block before calling, exactly where
   the original loaded them. Only AH=00 (set mode) and AH=0F (get mode) have
   `pal.h` equivalents; AH=02/03/06/07/08/09/0E/10/11/12 (cursor, scroll,
   read/write char, font, palette/alt-select) are dropped. The `.dis` mapping
   `int 10h -> bios_video_get_current_video_mode` was followed for AH=0F.
2. **BIOS text column count.** `int 10h` AH=0F returns AH = column count; the
   PAL call only returns mode (AL) and page (BH). `fn1E78_00E5` therefore
   computes its max column from the staged AH (0Fh) rather than the real
   column count. Not reconstructable from `pal.h`.
3. **BIOS Data Area stubs.** `0040:0000`, `0040:006C` (tick counter low byte)
   and `0040:0087` (video control) have no `pal.h` mapping and are file-static
   bytes. Consequently the `fn1E78_002E` busy-wait on `0040:006C` would not see
   the counter change and the derived calibration `g_B8B4` is not meaningful.
4. **`fn1E78_030D` `mov al,3h`.** On the early-return path `fn1E78_0143`
   returns its incoming AX unchanged; the frozen prototype has no AX input, so
   the port returns 0 instead of the staged AL=3. `fn1E78_0143`'s early path is
   likewise emitted as `return 0`.
5. **Cursor state.** `fn1E78_047C`/`fn1E78_04F6`/`fn1E78_04FD` read and set the
   BIOS text cursor; `pal.h` has no cursor state, so the port keeps the
   passed-in `dx` register value and the AH=02/03 calls are no-ops.
6. **`fn1E78_032F` selector fields** (`+0Eh` = DS, `+12h` = CS) are stored as 0
   in the flat model. `+0Ch` keeps the truncated 16-bit offset as Reko modelled
   it.
7. **`fn1E5F_000B`** drops the IVT dispatch (see table) and `__cli()`.
8. **`fn1E5F_00DE` returns a static buffer pointer.** Reko returned the local
   stack pattern buffer; that would be a dangling pointer, so the buffer is a
   file-static array. Callers ignore the return and read the DOS status from
   `g_B8A6` (offset B8A6h), which `fn1E5F_0136` writes exactly as the original.
9. **`fn1E5F_011C` is an extra function.** The `int 21h` AH=4Fh find-next
   wrapper at `1E5F:011C` is not listed in `analysis/summary/functions.tsv`
   (Reko did not identify it as a function). It is required by the brief, so it
   is defined with the natural prototype `void fn1E5F_011C(void * ptrArg04)`.
10. **`fn1E5F_0159`** stores the PAL interrupt-vector pointer truncated to the
    frozen `u32 *` output (the original stored offset:segment).
11. **`fn1E5F_0136` carry flag.** The original consumes the CF from the
    preceding `int 21h` find call (`jc 0155h`). C has no flag register, so
    `fn1E5F_00DE`/`fn1E5F_011C` stage it in the file-static `g_find_carry`.
12. **`fn11C8_033B`** returns `fn1E78_02F4()`'s byte on the "not detected" path;
    Reko left the return uninitialized. The detected path returns
    `fn11C8_0236(0)` (the DSP port base + 5) as in the original.

## Hardware-abstraction repair (interrupt register-frame dispatch)

This section documents the repair that replaced the two "dropped" interrupt
sites with real PAL entry points.  Added to `pal/`:

* `void pal_int_dispatch(u16 vec, u16 *frame)` (`pal/int.c`) — 10-word frame
  `AX,BX,CX,DX,BP,SI,DI,DS,ES,FLAGS`, in/out.  Handles:
  * vector `10h`: AH=00 set mode, AH=0F get mode (AL=mode, AH=*real columns*,
    BH=page), AH=01/02/03 cursor shape/position (read-back preserved),
    AH=06/07 scroll (no-op), AH=08 read char (AL=20h, AH=7), AH=09/0A/0E
    write char (no-op), AH=10h attribute registers (16-entry store),
    AH=11h/12h no-op (AH=12h BL=30h scan-line mode stored).
  * vector `33h`: DOS mouse functions 0 (AX=FFFFh, BX=button count 2),
    1/2 show/hide counter, 3 (BX=button bits bit0 left/bit1 right/bit2
    middle; CX/DX = virtual position), 4 set position, 7/8 ranges (default
    0..639 x 0..199), 13h speed threshold (stored).  The SDL pointer is
    scaled to the current mode's framebuffer and doubled horizontally
    (mode 13h DOS 2x granularity); position is read on demand, no event pump.
  * other vectors: no-op.  FLAGS is never modified.
* `void pal_bios_int10(u16 *regs)` (`pal/int.c`) — 4-word `AX,BX,CX,DX`
  in/out gateway for `fn1E78_0609`; identical int 10h core, sharing the
  cursor/attribute state with `pal_int_dispatch(0x10,...)`.
* `pal_video_get_mode`, `pal_video_get_framebuffer_size`,
  `pal_video_get_window_size` (`pal/video.c`, declared in `pal_internal.h`)
  share the one copy of the mode state that lives in `video.c`.

Changes to `src/seg1E5F.c` / `src/seg1E78.c`:

* **`fn1E5F_000B`** now adopts the asm's true shape
  `void fn1E5F_000B(u8 * ptrArg04, u16 wArg06)`: `ptrArg04` is the caller's
  0x14-byte frame, `wArg06` the interrupt vector (the original 3rd stack word
  at `[bp+0Ch]`, `retf 6`).  The 9-word image is seeded into a 10-word local
  frame, FLAGS=0, `pal_int_dispatch()` dispatches, and all ten words are
  stored back.  This resolves limitation 7 (and item 1's "dispatch dropped"):
  vectors 33h/10h now run through the PAL.
* **`fn1E78_0609`** copies the staged `g_bios10_ax/bx/cx/dx` into a 4-word
  `regs[]`, calls `pal_bios_int10(regs)`, and copies the words back (the
  original callers consume AX/BX/CX/DX after `int 10h`).  This resolves
  limitation 1 (text services dropped) and limitation 2: AH=0F now returns
  the *real* BIOS column count (40/80; mode 13h = 40), so `fn1E78_00E5`'s
  `max column = AH - 1` computation is now correct.
* Cursor state (limitation 5) now exists in the PAL, so AH=01/02/03 are no
  longer no-ops; `fn1E78_047C`'s `fn1E78_04F6` cursor read and the AH=02 set
  are backed by real state.

Still not modelled (unchanged): the BIOS Data Area stand-ins (limitation 3),
`fn1E78_030D`'s `mov al,3h` (limitation 4), `fn1E78_032F` selector fields
(limitation 6).  The default framebuffer used for mouse scaling is the mode
geometry (`video.c`), 320x200 for mode 13h and text/unknown modes.
