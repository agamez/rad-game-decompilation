# RAD V3.1 — Linux port notes

This file documents ONLY: hardware interfaces that were replaced, portability
fixes, compiler compatibility fixes, and portions that could not be recovered
literally. It is not a design document. (See CONVENTIONS.md for the rules.)

## Hardware interfaces replaced

### INT 10h VGA detection (pal/int.c)
The adapter detection chain (fn1AB8_19EE -> 1EE3 -> 1F19 -> 1FED/1F80) probes
VGA presence through BIOS services.  The PAL answers:
- AH=1Ah AL=00h -> AL=0x1A, BX=0x0008 (VGA with color analog display).  This
  is what makes the loader select the EGAVGA driver record (index 1).
- AH=12h BL=10h -> BH=0 (color), BL=1 (memory), CL=09h (switches; < 0x0C so
  the EGA-era check fn1AB8_1F80 falls through), CH=0.

### BIOS Data Area (pal/dos.c, seg1E78)
- 0040:006C tick counter: emulated at 18.2065 Hz from CLOCK_MONOTONIC
  (pal_bda_tick_byte).  The tick byte and the fn1E78_02BF pointer parameter
  are `volatile`-qualified; without it gcc hoists the busy-wait loads and
  the speed calibration spins forever.
- 0040:0000: a static byte (never changes, same as a machine with no COM
  activity); fn1E78_029C's delay units time out through it as on DOS.

## Far-call ABI: argument positions recovered from the asm
Reko names stack arguments by their offset in the ORIGINAL frame, which
differs from the flat C argument order whenever the original pushed fewer
words than the frozen prototype lists.  Ground truth from ndisasm:
- fn1EDA_023F/0254 (far-heap alloc/free): the SIZE is the word at [bp+6],
  i.e. the FIRST C argument.  0254's block far pointer follows at [bp+8]
  (offset) and [bp+0xA] (segment).  106 call sites corrected.
- fn1EDA_10BB (record read): takes a FOURTH argument -- the destination far
  pointer loaded by `lds dx,[bp+0xC]` -- which the frozen prototype dropped.
  It is now parameter 3 (a materialized host pointer); the read lands in the
  caller's block, not a fixed buffer.  All 12 call sites pass their asm
  destination (allocated blocks, DGROUP buffers or frame locals).

## Far heap (fn1EDA_0308/03D3/0432)
- Node format: {next off, next seg, quantum (0/8), paragraphs} -- the size
  fields are NOT a 32-bit byte count.  fn1EDA_0491 returns AX=(size+7)&0x08
  (literally) and DX=(size+7)>>4 paragraphs.
- The heap top starts AT the base ([0x5360] = [0x534E]) and grows toward the
  PSP memtop [0x5364] as allocations extend it (l1EDA_039C).  All heap words
  ship as zero in dgroup_data.bin; nothing fabricates an extent.
- The free-list node accessors resolve EVERY segment through far_ptr()
  (64 KiB-aligned arenas), not just DGROUP.

## Host pointer -> 16:16 reverse mapping
The draw wrappers re-stage ES:BX register images from materialized host
pointers.  far_seg_of() (globals.c) recovers the segment: image segments by
base comparison, heap arenas via g_arena_tab (arenas are 64 KiB aligned, so
the offset half is the low 16 bits of the host address).

## Graphics driver layer (pal_bgi_dispatch, pal/video.c)
The game's graphics stack is three layers: (1) the game's wrappers in seg1AB8
(fn1AB8_1ACE/1AF6/1B3E/1B90/1E3C/1E54/1E6B/1E9F...), (2) the embedded driver
blob (1AB8:2093, relocated; its wrapper handlers decoded from the binary with
ndisasm), and (3) the real VGA raster layer the blob chains into
(`jmp far [cs:0x70]`).  pal_bgi_dispatch replaces layers 2+3 with the merged
semantics; the draw target is the single 64 KiB linear 0xA000 shadow addressed
as (y*320 + x) & 0xFFFF (see Presentation below -- the earlier separate
640x480 canvas and its x/2, y*5/12 sampling were a wrong model and are gone).
The 640/480 values below remain: they are the LOGICAL coordinate space the
mode-info block reports and the game's clip gates compare against, while the
framebuffer addressing itself wraps 16-bit at the 64 KiB segment.

Verified contracts (decoded from the driver binary, not guessed):
- 0x00: AL=0 install -> ES:BX = a mode-info block staged at DGROUP 0xBD20
  (word[1]=640 max x, word[2]=480 max y).  The game copies 19 bytes of it to
  DGROUP 0xB7C0; offsets +2/+4 land at 0xB7C2/0xB7C4 = the screen dims the
  clip gates compare against (fn0C74_05B8's flood loop, fn1AB8_13D7's gate).
  AL=1 -> CX = rows (fn1AB8_1C93 subtracts 1).
- 0x02: publishes [0xB7C2]=640 / [0xB7C4]=480 (fn1AB8_0F93 window validation).
- 0x08: move pen only, (AX=x, BX=y) translated by the viewport origin.  NO draw.
- 0x0A/0x12: line from the pen to (AX+ox, BX+oy), color = the current color;
  the pen advances.
- 0x1E: set the current draw color (the driver handler is literally
  `mov [0x9a],ax`).
- 0x2E: get pixel (AX=x, BX=y, translated) -> returned in DL (fn1AB8_1E3C).
- 0x30: put pixel (AX=x, BX=y, DL=color), translated.
- 0x34: OFFSCREEN fill -- fn1AB8_1E6B writes {width,height} into the block at
  ES:BX and the real driver fills the BLOCK's payload (w*h bytes at +4) with
  the current color.  fn0C74_05B8 allocates a fresh row block per scanline,
  fills it, and blits it -- this is the game's flood/scanline animation.
- 0x36: blit -- ES:BX = {w,h,payload} sprite (0 = transparent), CX = dest x,
  DX = dest y (both origin-translated).  fn1AB8_13D7 clips and calls it.
- 0x38: set viewport/clip: (AX&0x7FFF, BX) = min corner, (CX,DX) = max corner;
  the min corner becomes the origin added by every coordinate-taking function.
- 0x14: capture -- copy the canvas rect at the pen into the ES:BX block's
  payload (the benchmark fn0800_3CFA times it; id 90).
- 0x3A: AL=0 -> CX/BX dims; AL=1 -> ES:BX = a 17-byte info record staged at
  DGROUP 0xBD00 (Pascal-style name string, consumed by fn1AB8_129A).

Palette: the game uploads it with INT 10h AH=10h AL=12h (Set DAC Color Block)
from fn0C43_001E -- the palette data is the 0x300-record read into DGROUP 0x5582
(each byte then shifted right by 2 to 6-bit DAC range).  pal_int_dispatch
implements AL=12h via pal_video_set_dac_block().

Status: the game boots, loads its driver from the embedded image, loads and
decodes the RAD.TIT title art with the correct game palette, and displays the
title screen (verified against analysis/ref/title_reference.png: blue border,
green RAD logo panels, the central robot emblem, PRESSEZ UNE TOUCHE prompt all
in place; coarse similarity ~0.84 at 80x50).  The known remaining difference is
the flood/wireframe effect (palette index 64) that our port draws over the
left-center of the title while it is up -- the effect sequencing/scheduling of
the menu engine, not the driver layer or the art path.

### Presentation (interactive)
`present_frame()` fires on the emulated 70 Hz retrace (port 0x3BA/0x3DA polling)
AND via `pal_video_present_throttled()` from the input pump -- without the
latter the menu/mouse phases (which never poll the retrace port) would leave
the window permanently black.  Mode 13h presents the single framebuffer
directly: the driver's draw target IS the 64 KiB linear 0xA000 shadow
(`g_shadow[0..65535]`).  Every driver primitive addresses it as
`offset = (y*320 + x) & 0xFFFF` -- the natural 16-bit wrap -- which is how the
original's effect windows with logical y up to 480 land back inside the
visible 320x200 area (e.g. the menu blits at (121, 411) write rows 6..).
The separate 640x480 logical canvas and the x/2, y*5/12 sampling were removed;
the earlier canvas-over-shadow composite mis-modeled the driver and left the
title art invisible behind effect output.

On mode 13h set the VGA BIOS's default 256-entry palette is loaded (EGA 16,
gray 16, three 72-entry hue wheels, 8 black); the game's own DAC upload
(AH=10h AL=12h from fn0C43_001E) overrides it at the title load.

Data files resolve against $RAD_DATA, then ./data, then the executable's own
directory tree (build/rad -> ../data), then "." -- so the binary runs from any
working directory.

MODE 12h IMPLEMENTED (this round): pal/video.c now has a logical 640x480
8bpp canvas (g_vga12), a gameplay DAC palette extracted from the DOSBox level
capture (g_lvl_dac), mode-aware plot/line/blit/capture primitives (mode 13h =
the packed wrapped 320x200 as before; mode 12h = clipped 640x480 direct), and
a 640x480 present branch.  Mode 12h activates via the BGI display-init op
(blob 0x02) -- the game itself never issues INT 10h AH=00h AL=12h; the real
BGI driver's init does it, and the port replaces that driver.

DOS create-mode open fixed (pal/dos.c): a write-mode open of a missing file
now CREATES it (DOS AH=3Ch semantics).  The game's RAD.MEM player-name save
(the original writes "SIDNEY\r\n" on first boot under DOSBox) relied on this;
without it the F1 level-launch path took the fatal "Impossible d'acceder"
branch.  With the fix the level playfield renders on the mode-12h canvas
(the level's cyan/blue colors appear).  Remaining blocker: the port's
premature "flood effect" (the timer-driven staircase, documented above)
paints ~84k out-of-range values (255/252/248) over the level -- effect
scheduling, not rendering.

## CRITICAL finding: the game uses TWO video modes

Automated side-by-side comparison (harness: /tmp/opencode/cmp/harness.sh runs
the original under DOSBox and the port under Xvfb with the same key script and
captures normalized screenshots per stage) plus color-count analysis of the
DOSBox captures established:

- The TITLE screen = 255 distinct colors = mode 13h (320x200x256, packed).
  The port's title render matches the original PIXEL-PERFECTLY (64,000/64,000
  pixels after correct crop alignment).
- The MENU = 11 distinct colors and the GAMEPLAY LEVEL = 15 distinct colors
  (EGA-like palette: 0,0,170 / 0,170,170 / 0,255,255 / 170,85,0 / 0,85,255...)
  = a 16-color PLANAR mode at 640x480 (VGA mode 12h).  Supporting evidence:
  the blob's 0x38 viewport ops during the level stage set (0,0)-(640,480);
  the 0x36 blits land at coords like (331,353) -- native mode-12h positions;
  the 0x1E color words like 0x030B carry (flags<<8)|color where the color
  nibble doubles as the planar map mask (color 0xB -> planes 0,1,3).
- The port currently renders everything on the mode-13h 320x200 canvas, so
  after the title: the menu's filled shapes never appear (draws land wrapped
  into the wrong addresses, only the text and frame lines are visible), and
  the gameplay level renders an entirely black screen (shadow verified all
  zero while 900+ draw ops fired).

NEXT MAJOR STEP: implement mode 12h in the PAL -- planar framebuffer (4 planes
x 38400 bytes, byte = 8 pixels, plane = color bit; write via map mask = the
color's bits), blob draw ops become mode-aware (mode 13h = packed 320x200 with
the 16-bit wrap as now; mode 12h = planar 640x480 direct), the EGA 16-color
DAC on the mode set, and a 640x480 present branch.  The driver op contracts
already decoded (0x08/0x0A/0x0C/0x12/0x14/0x26/0x2C/0x34/0x36) stay the same;
only the plot primitive and the present change per mode.

## Round: title wait, F1 crash, menu rendering (segment 1E78/0800/0C74 fixes)

Verification now runs the ORIGINAL under DOSBox (Xvfb + xdotool, see
/tmp/opencode/dosbox/) so every fix is compared against real captures:
the title is static until a keypress; SPACE opens a menu drawn with the
BGI driver on the mode-13h canvas (teal window, seven beveled buttons
F1:JEU..F7:RETOUR AU DOS); F1 launches the level.

- **Blocking INT 16h AH=00h** (pal/input.c): the original blocks until a key
  is available; the port returned 0 immediately, so the "PRESSEZ UNE TOUCHE"
  wait (fn0800_4255 calls 1E78:030D right after fn0C43_00B9) fell through and
  the title flashed for ~1 s.  bios_kbd_get_keystroke() now pumps/yields until
  a key arrives (the quit flag breaks the wait).
- **RAD_FAKE_KEYS="T:name,..."** (pal/input.c): timed SDL-key injection so
  the whole flow (title -> SPACE -> menu -> F1) is reproducible headlessly.
- **76 raw far-pointer casts fixed** (seg0C74_part3/4/5/5b/6/8/9, seg1AB8_part5a):
  `(u8 *)(uintptr_t)dw` on u32 offset|seg<<16 values -> far_ptr(dw).  This was
  the F1 SIGSEGV (fn1AB8_1E6B received 0x4e8e0008 as a host pointer), plus two
  follow-ups: the sprite-table block in fn0800_01FE and a 16-bit segment-wrap
  on the sprite source read in the 0x36 blit.
- **fn0800_19E1 interface repaired** (the documented "main loss"): the
  prototype now carries (flag, label, y, x, slot); all 30 call sites decoded
  from the original push sequences (slot, x, y, ds, label, flag).  With the
  old zero-seeded args every button drew at (0,0) and a 0x12 edge line swept
  the whole screen flat-filling it -- the reported "whole screen goes orange".
- **Driver text ops 0x24/0x26/0x28** (pal/video.c): 0x24 = text metrics/flags,
  0x26 = draw the Pascal string at ES:BX (count CX) with the 8x8 CP437 font
  (pal/font8x8.h, byte-identical to DOSBox int10_font_08) at the pen with the
  alignment pre-adjust, 0x28 = string width.  Button labels render.
- **Driver op 0x0C** (pal/video.c): the two-endpoint line (both ends
  origin-translated) -- button bevels/frames.
- **SS-resident label buffers** staged into DGROUP (0xFB00/0xFA00/0xF900):
  in the tiny model SS==DS, so [bp-xxx] frame buffers are DGROUP-resident and
  far_seg_of() can materialize them for ES:BX.
- **0x1E color word**: the game stages 0x4040/0x400F/0x0040; the low nibble is
  the palette index (the DOSBox menu shows black fills and white bevels), so
  g_drv_color = ax & 0x0F.

Verified: both compilers build clean; title frame byte-identical to the
pre-round capture; F1 path runs 15 s+ under gdb without SIGSEGV; menu buttons
and labels render with black fills and bevel lines.

Known remaining menu gaps vs the DOSBox capture: the teal window fill and the
background clear behind the menu (the game repaints the whole screen at the
menu transition; the op sequence is not yet identified), and the menu's
flat 7-color look (the original reprograms the DAC at the transition by an
unidentified mechanism -- blob op 0x1A is a bare `ret`, and no AH=10h AL=10h
staging exists in the recovered code).

## Console stream (segment 1E78) and the boot palette chain

The game opens two CONSOLE stream blocks at boot (fn1E78_0000: a read block at
DGROUP:0xB8BC, a write block at DGROUP:0xB9BC, each initialised by
fn1E78_032F with the open callback 1E78:035A at block+0x10).  The stream
dispatcher (fn1EDA_05FB) resolves the slot's 16-bit offset through
seg1EDA_stream_cb(); the console offsets were missing there, every console
open failed with AX=0xFFFF, the error latched into DGROUP:0x5380 and the very
next fn1EDA_04A2() check aborted the RAD.TIT title load (the screen then showed
only the menu effect patterns).  Recovered from the seg1E78.bin disassembly:

- fn1E78_035A (open/arm): for a D7B1 block arms {+14: 0392 read, +18/+1C: 0470};
  otherwise sets id D7B2 and arms {+14/+18: 043F write, +1C: 0470}.  Returns 0.
- fn1E78_0392 (read): line input with editing (BS/ctrl-S erase one, ESC/ctrl-A
  erase the line via the wrapped `loop`, ctrl-D/ctrl-F re-echo forward, ctrl-Z
  honours [B8A9], CR appends 0Dh 0Ah and stores the length at +0Ah).
- fn1E78_043F (write): emits [block+8] bytes from the block buffer and clears
  the count.  The original's [B8AA] direct-B800 branch (1E78:0504) is not
  recovered: the port does not emulate the text plane, so both branches route
  through the BIOS teletype helper fn1E78_047C (whose AH=09/0E output is a
  documented no-op).  Count and state effects are identical.
- fn1E78_0470: dummy op, returns 0.

Two related conversions were corrected against the disassembly:

- fn1E78_030D now returns the acquired character (AL) as the original's `retf`
  does; the pending-key/int16 logic is unchanged.  Callers that only drain the
  buffer discard the return.
- fn1E78_047C takes its cursor position from the AH=03h result of fn1E78_04F6
  (the original overwrites DX before every path; the caller's DX is preserved
  but ignored), instead of trusting the caller's argument.

The DAC upload chain also had one staging bug: fn0C43_001E stages the register
frame's ES:DX from the host pointer's own address halves.  The caller pushes
the far pointer DGROUP:5582h, so ES must be the port's DGROUP segment (2014h,
cf. far_ptr/far_seg_of) and DX the DGROUP-relative offset.  With the old
staging the AH=10h AL=12h handler dereferenced a fresh zero arena and the
whole game palette uploaded as black.

Set RAD_IO_LOG=1 to trace msdos_read_file/msdos_set_file_position calls
(handle, file, count/offset, result) in pal/dos.c.

## Portions not recovered literally
- The embedded driver image beyond 1AB8:2072 (Reko emitted data): the batch
  B handlers (0x0E..0x18) are decoded in src/seg1AB8_driverB.c; batches
  A/C/D and the wrapper dispatch table at driver 0x0013 remain unconverted.
  pal_bgi_dispatch implements the wrapper-level contracts instead.
- fn1AB8_050B (the allocator grow-stub, Reko-missed): `mov word [bp-2],1;
  mov ax,[bp-2]; retf 2` -- returns AL=1 (growth authorized); recovered by
  hand from the binary and documented here rather than converted.

## Portability fixes
(not yet populated)

## Compiler compatibility fixes
(not yet populated)

## Portions not recovered literally
(not yet populated)

## Mode 12h sprite/driver contracts (measured + decoded, session 3)

### Sprite block payload (mode 12h)
A sprite block = {u16 w, u16 h} header + payload of
`(h+1) * wbr * 4 + 2` bytes where `wbr = ceil(w/8)`:
four bit planes, ROW-INTERLEAVED (each row = 4 groups of wbr bytes,
group g carries colour bit 3-g), drawing `(h+1)` rows and `(w+1)`
columns (the extra row/column are the blue mortar lattice between
tiles: constant pattern `ff ff fc 00 00 00 00 00 00 ff ff fc` =
index 9), + a 2-byte per-record trailer (not a gate; RAD.STR
trailers vary, RAD.DES are all 0000).
Sizes are pinned by the original's own fn1AB8_19A6/13A3 formula
`4*wbr*(h+1)+6`: RAD.STR stride 270 = 4*3*22+6 (21x21 tiles),
RAD.DES stride 1062 = 4*24*44+2 (43x43 robot frames), RAD.BUT 1086.
Consuming only h rows desyncs every script stream that carries an
inline block -- this was the source of the "flood" (~84k garbage
ops); the flood is gone with the correct sizes.

### Blob driver op semantics (mode 12h) -- corrected
- op 0x36 = putimage COPY_PUT: writes ALL (h+1)x(w+1) pixels
  including colour 0 (it erases the previous frame; the robot
  descent relies on this).  NOT a transparent mask.
- op 0x34 = getimage: captures the inclusive (CX,DX) rectangle of
  (h+1)x(w+1) pixels INTO the row-interleaved planar layout that
  0x36 reads back (save-under).  NOT an offscreen fill.
- op 0x1E colour word = (fill<<8)|line: low byte = line/foreground,
  high byte = fill/background (0x030B = cyan bevels on teal fill).
  op 0x12 = filled rectangle (AX,BX+1)-(CX+1,DX) using the fill
  nibble, not a line.
- op 0x2A = text-justify latch (AL=horiz 0/1/2 = left/center/right,
  AH=vert 0/1/2 = bottom/center/top), driver 0x1922/0x1955:
  W = sum(widths)*num/den, hor 1 -> pen_x -= W/2-1, 2 -> pen_x -= W;
  H = (asc-desc)*num/den, ver 1 -> pen_y += H/2, 2 -> pen_y += H.
- op 0x24 = text metrics: AL=0 = 8x8 bitmap (BX==0 -> BX=CX=8 via
  the driver 0x3561 clamp), AL=1 = stroke font with
  scale = chrscale[min(BX,10)] from the 11-entry driver table at
  file 0x3597 ({3,5},{2,3},{3,4},{1,1},{4,3},{5,3},{2,1},{5,2},
  {3,1},{4,1},{4,1}); AL=2 = compact half-size (advance 6, glyph
  columns 0-5, rows 0-6).

### Stroke font (menu RAD logo, vector text)
The original embeds the Borland BGI stroked fonts in RAD.EXE
segment 13E2 (a duplicate of the driver segment data):
TRIP header at file 0xF65A (chars 223, first 32, ascender 24,
baseline 0, descender -7, strokes at +0x02AD), stroke stream at
0xF907; LITT at 0x136FB.  The TRIP block is byte-identical to the
standard Turbo C TRIP.CHR.  Stroke vertices = 2 bytes:
`byte0 = op_hi<<7 | (x & 0x7F)`, `byte1 = op_lo<<7 | (y & 0x7F)`,
opcode = op_hi*2+op_lo (0=end, 2=move, 3=draw), signed 7-bit coords,
y up; every glyph ends with MOVE(width,0) = the advance.
pal/font_stroke.h holds the extracted 16549-byte TRIP block;
pal/video.c op-0x26 mode 1 interprets it (scale 4/1 for the
size-24 logo -> ink x203-427 y49-133 matching DOSBox 0.95;
3/4 for the size-3 button labels).

### DAC mechanism (RESOLVED: blob op 0x1A)
The "bare ret" op 0x1A was a misrecovered handler.  It is the
DAC-entry upload: AX = 0x8000|index with BX=R, CX=G, DX=B (6-bit
each); AX = 0xFFFF is fn1AB8_1CA4's attribute-controller path
(no-op in the port).  The menu painter installs index 8 =
(0x15,0x15,0x15) grey (drop shadows) and DAC 2 = black (which is
why the fn1AB8_112E green rectangle at canvas (106,365)-(515,457)
is invisible in the original); the level installer sets index 8 =
black; both set index 15 = white (0x3f,0x3f,0x3f).  Drivers:
fn13E2_0080 (menu) / fn13E2_00FB (level) loop all 16 entries from
DGROUP 0x50CC; fn13E2_003B blanks all 16 (the loader progress-bar
cells drawn while blanked are the former "white line" artifact).
g_lvl_dac remains the mode-set default (15 = white).

### SS-resident staging (recurring bug class)
Turbo C tiny model: SS==DS==DGROUP, so ss:[bp-xxx] frame buffers
are DGROUP-resident and the far pointers staged for driver ops
resolve.  Any port function that builds a string/block in a C
STACK local stages far_seg_of()=0 and the driver reads a zeroed
arena (NUL glyphs / empty fills).  Convention: stage in DGROUP
scratch (0xF6E0/0xF6F0/0xF700/0xF800/0xF900/0xFB00/0xFC00/0xFD00
verified collision-free).  Fixed instances: fn0800_19E1 labels,
fn0800_21E7 version line, fn0800_0619 MISSION concat, fn0800_0B42/
fn0800_0AA1 TIME digit halves.

### Comparison harness
/tmp/opencode/cmp/harness.sh: DOSBox crop (80,100) is 640x400 for
the mode-13h title but 640x476 for the mode-12h screens (the DOSBox
window letterboxes 640x480 into 476 rows); the port game shot is
taken at F1+6s (the port finishes the level load ~1.5s later than
DOSBox; canvas transitions settle at F1+5).  Pair metric: fraction
of the 320x200-normalized pixels within tolerance 48.

### Verification status (session 3 end)
- title: pixel-identical (md5-equal, metric 1.000).
- menu: 0.886 harness / 0.912 canvas-level; RAD logo matches 0.95
  in its box; robot mascot coherent; labels 7 glyph rows; version
  line "Version enregistree : 103 tableaux" at x219-422 y148-154.
- level: 0.734 harness / 0.82 canvas-level (tiles 91.5% at the
  +1px crop alignment); blue mortar 11396 px vs DOSBox 11408;
  robot descent clean (no trail), robot on platform 0.945; status
  bar TIME:00.00 / MISSION 001 / SCORE painted; zero (85,85,85).
- RAD.MEM = "SIDNEY\r\n" byte-identical to DOSBox first boot.
- Title regression fb.bin top-3 = 1:5142 3:3657 2:2417 exact;
  15s gdb soak rc=124 (no SIGSEGV).

### Known remaining gaps
- Menu button metrics: buttons ~2px lower / ~7px narrower than the
  original, F7 outline difference; version line style (blocky vs
  dotted vector) differs.
- HUD text sits 1-2px above the resized DOSBox crop (cross-correlated
  global +1px vertical offset; asm-faithful positions kept).
- Mouse arrow = the classic DOS shape, not the original's exact
  sprite; homed to the canvas centre headless.
- RAD.BUT button-sprite decode (7*6*44+6=1854 contract) not yet
  exercised against the reference beyond the metrics.

### Session 3 final polish
- op 0x1A implemented; menu/level DAC splits verified (menu idx8
  grey 1437 px vs ref 1728 at 320x200; level idx8 = black).
- Level crate (index 15) renders white: 221/221 white px in the
  crate box, tol-48 fraction 1.0; the loader-bar console band is
  cleaned of stale index-15 pixels when white installs.
- Menu canvas fraction 0.9221; level 0.8058 (canvas-level metric).
- Mouse arrow composited with fixed white/black RGB (93 white px
  in the presented frame, 0 in g_vga12).
- Independent visual review at the true framebuffer grid: title
  byte-identical, menu 3.3% differing, level 1.2% differing
  (the 0.73 window metric = nearest-neighbour aliasing of the
  1px 50% dither, not a content gap).

## Gameplay contracts (session 4 -- playability)

### Level loop = fn0800_2C0C (mission browser AND game)
Key read (0800_2C0C asm 2E71..2EA3): 1E78:030D returns AL=ASCII;
ASCII==0 stashes the scan code in 0B8B9h and the immediate re-call
returns it, so arrows arrive as set-1 scan codes in ds:53D2.
Translation (2EA9): only a "DEMO" record (0B24 equal) substitutes
keys with 5CBB's script bytes; NORMAL missions dispatch the raw
key.  (The port had this polarity inverted -- normal missions were
having their arrow keys rewritten with the mission-title letters
"JUST..." -- the same 0B24 inversion class fixed earlier for the
HUD branch.)

Dispatch (asm 2ED2..3078):
- F1/F2/F3 (0x3B/3C/3D): program-slot counters (53DB/DC/DE), pose
  repaint via 09C2.
- 0x3F / 0x2C: full frame reset+repaint (fn0800_2401).
- ESC (0x1B): restore the timer vector, back to the menu.
- SPACE (0x20): pause (the clock snapshot 58D8/58DA->58D0/58D2,
  the clock off, wait for the next key, re-arm).
- 'D' (0x44): toggle 58B0 (the pacing/calibration gate).
- UP 0x48: climb -- fn0C74_51AA -> fn1B3B: mast pixels (1E54 at
  x=58B4+0x17..0x19), rise 58B8-- up to 88 steps while clear.
- DOWN 0x50: fn0C74_51B2 descend attempt.
- LEFT 0x4B / RIGHT 0x4D: fn0C74_54F0/54B1 -> 37C3/3615 walk
  (up to 88 hw px = 4 cells per press, 1E3C edge probes,
  floor required); blocked LEFT -> 09C2(0xE)+08C0 (the crate
  push path), blocked RIGHT -> 08C0.
- 3087: 0C71 clock tick, then 0877 the win check every frame.

There is NO mission browse on the arrows anywhere in 2C0C.

### Robot / push state (DGROUP)
58B4/58B6 = robot left/right x (sprite width 0x2B), 58B8 = top y,
58BA = floor y (176), 5968 = mode (1 = on wire, 0xFFFF = released).
2AD9 = gravity (the saved sprite falls 58B8++ per 070D tick until
58B8 = 58BA-0x2B).  3236 = the crate push: save the 22x22 cell
(13A3/023F/1E6B), drag it 22 px in paced 1-px steps (13D7), the
arm extension up to 20 px, then 2BBD gravity-falls it (the probe at
the crate centre x = left+11), the arm retraction, the robot steps
22 px, F1 counter (53DB) --.  THE CRATE IS PIXEL-BASED: its
position lives only in the canvas (the mission grid is never
rewritten; only the transient blit blocks exist in DGROUP).
Verified press-for-press byte-identical against DOSBox: crate
331->353->375->397 then falls 4 rows through the row-8 gap.

### Win / lose / mission advance
Win = fn0800_0877 every frame: 5EB0[0..28] (the grid's BOTTOM row
16, cols 0..28; 5EB0 = 5CB4+508 inside the 537-byte record) ==
0x5E (the goal-slot tile) AND a white (0x0F) pixel at
(x = i*22+11, y = 0x176).  On win: the frame loop exits, 0768
("PRESSEZ UNE TOUCHE" wait), the record position 598E:5990 +1
(the wrap/end checks transcribed), fn0800_01FE reloads the next
mission (002 = "LONDON"/"UNE ODEUR DE POUDRE."), the MISSION
counter (fn0800_0619) renders the new number.
Lose = fn0800_0C71 tail fires fn0800_08E9 when 58DA<0 or
(58DA==0 && 58D8==0): the destruction sweep (fn0C74_076B wipes the
white cells, ESC latches 58B3) then fn0C74_0A35 lowers the robot
back to the start; the timer is not re-armed.

### Session hygiene
The fake-key injector now accepts 128 keys / 2048 bytes.  Keys
injected before the intro settle completes (5.6-12s after launch,
varies) show the settle repaint in diffs; inject keys >=12s for
clean per-key captures.  Ten latent raw far-pointer casts fixed
(seg0C74_part7 x6, seg1229_part1 x2, seg0800_part3 x2) -- the
first push SIGSEGV'd in fn1AB8_1E6B.  RAD_WIN_TRACE=1 = the win
check diagnostic; RAD_DUMP_SECS also dumps the 640x480 canvas.

### Verified playable session (headless, scripted)
46s: title SPACE -> menu F1 -> settle -> 3 RIGHTs (walk + 2
pushes, byte-identical to DOSBox) -> DOWN -> UP -> SPACE
pause/unpause -> ESC -> F1 -> moves -> ESC -> F7 -> rc=0.  60s
111-key stress: alive, canvas 0..12, no corruption.  Regressions:
title exact, 15s soak rc=124.

## Timing contracts (session 5 -- pacing, clock, bomb)

### Root cause of the burst pacing (the "robot moves too fast" defect)
The original self-times to whatever machine it runs on through two
calibrations, and both broke on the host because the host's spin loops are
thousands of times denser than the emulated CPU's:

1. `fn1E78_002E` sizes DGROUP:0xB8B4 so that one `fn1E78_02BF` busy-wait of
   [0xB8B4] iterations = 1/55 of a BIOS tick = one game millisecond.  The
   measurement (`02BF(&bda_tick, al, 0xFFFF)`) saturates its u16 cx budget on
   the host (one 55ms tick >> 65535 host iterations), so it stored the
   saturated 0xFFFF/0x37 = 1191, and 1191 host iterations take ~0.4us --
   every `fn1E78_029C(n)` "n millisecond" delay collapsed to ~n microseconds.
2. `fn0800_3CFA` measures the machine speed index: it counts
   `fn1AB8_122E`+`fn0800_3C72` polls during a fixed 100-centisecond window
   and stores count*8/100 at DGROUP:0x58E6 (min 7).  On era hardware and in
   DOSBox this lands on the game's own startup default 7 (fn0800_4255:
   `mov word [58E6h],7h`); on the host the poll is thousands of times
   cheaper, so the window admitted tens of thousands of polls and 58E6h came
   out 1400..11000, varying per run.  Every animation takes its tick count
   from 58E6h (02D8/070D), so the walk, pushes, fuse and burns all re-timed
   themselves to garbage.

### Fix (emulated-hardware timing, gameplay arithmetic untouched)
- `fn1E78_029C`/`fn1E78_02BF` (src/seg1E78.c): the recovered spin and its cx
  budget are kept literally; on the cx-exhaustion exit (the watched byte --
  0040:0000 -- never changes, exactly as on real hardware) the call is held
  for cx * (1ms/[0xB8B4]) of real time, which is the duration the same spin
  consumed on the machine the calibration measured.  The byte-change exit
  (the calibration watching the 0040:006C tick) is not held.  One 029C unit
  = one real millisecond on any host; the bulk is yielded with nanosleep and
  only the tail is spun (fn1E78_pace_ns).
- `fn1AB8_122E` (src/seg1AB8_part4.c): paced to ~10.5ms -- the emulated
  machine's BGI text-draw cost -- so the 3CFA window yields ~95 polls and
  58E6h = 7, the designed and DOSBox-observed value.  122E's ONLY caller in
  the whole program is the 3CFA poll, so nothing else re-times.

Result: walk = 02D8(2*58E6) = 14ms/px designed, ~19ms/px measured (the SDL
pump per step); one 22px cell ~0.42s (the original's 0.3-0.6s band);
deterministic across runs.  The push, fuse, explosion and burn all pace off
the same constants.

### Emulated int-1Ch handler (cs:007Bh) -- the game clock
The handler installed by fn0800_00C1 adds 37h to the millisecond accumulator
53E2h per BIOS tick and, on reaching 3E8h, resets it and decrements the
32-bit clock 58D8h:58DAh (signed-high/unsigned-low guard, `sbb` borrow).
The port has no asynchronous interrupt source, so the identical state
transition is applied lazily from the host monotonic clock
(fn0800_timer_service in seg0800_part1.c, driven from fn0800_0C71 per frame
and from fn1E78_029C where time passes inside waits; fn0800_timer_reset
re-arms the phase at every 00C1 arm / 0103 disarm).  53E2h advances 55 per
18.2065 Hz tick; the clock loses one second per 19 ticks = 1.0436s, exactly
as the binary's reset-to-zero (not subtract) behaves.  TIME now counts down
and the time-up lose path (0C71 -> 08E9) is reachable.

### Mission-001 win + mission-002 explosive (headless, keyboard-driven)
The shipped RAD.HLP record for the current level is the level's solution
(`4D 05 | 3B 3B 3B | 4B 01 | 4B 08 | 50 | 4D 01 | 4D 0A | 3B x6`).  F5 in
the mission loop (scan 0x3F/0x2C) enters fn0800_2401 MODE AUTO, which
executes one recorded command per keypress with the exact 58BC/58BD cell
counts.  Script: `+1.5:space,+1.5:f1,+8:d,+6:f5` then 20x `+7:space` wins
mission 001 for real (fn0800_0877 ret=1: every '^' goal cell white at
(x=i*22+11,y=374)), the record position advances and mission 002 (LONDON,
F1=30/F3=1) reloads.  In 002, `+14:right,+3:right,+3:f3` walks the robot to
the crate and fires the real explosive: 5258 -> 396E (arm placement) ->
45CE (fuse sweep, 02D8(0x1F4) fuse wait, descending burn, 076B blast
scatter, the recoil walk-back; retreat < 22px would set 58B3 = the robot is
disintegrated) and 53DE 1 -> 0.  Total chain ~12-14s at the fixed pacing.

### Input responsiveness
The walk polls 1E78:02FB per 1px step; a key pressed mid-walk stops the walk
at the END of the current 22px cell (58B1 latch) and the main loop then
dispatches it.  Verified: LEFT pressed 0.5s into a RIGHT walk stops the walk
at exactly x=243 (2 cells) and the LEFT is processed (blocked at the well
edge -- correct game behavior).  Held keys walk continuously through BIOS
typematic repeats (SDL key repeat is queued like the BIOS buffer).

### Fake-key injector extensions (pal/input.c)
`RAD_FAKE_KEYS` entries may prefix the time with `+` ("+2:f1") to make the
delay relative to the previous key of the chain instead of process start --
robust against the variable startup settle.  Absolute "T:key" entries are
unchanged.

### Re-verified regressions (post-fix)
- Title fb.bin top-3 = 1:5142 3:3657 2:2417 EXACT (unchanged).
- 15s gdb soak keys 1.5:space,3.5:f1 -> rc=124 (no crash).
- Push sequence: crate 331->353->375->397 then the 4-row fall through the
  row-8 gap: the fallen crate box = (397..418, 243..264) in the 640x480
  canvas -- identical to the previously verified positions; only the timing
  changed (legitimately, per the pacing fix).
- Mission-001 win + advance to 002, and the 002 explosive chain (above).

## Round: climb/push/bomb presentation, arm-retraction residue, mission records (session 6)

### Root cause of the "animations 5-10x too slow" defect (D1)
The recovered pacing arithmetic was verified correct against the .asm (see
"Timing contracts", session 5): `029C(n)` = n calibrated units, `02D8(n)` with
the clock armed (58BEh=1) = (n/7 + 1) loop iterations x (029Ch(2) x 2), `070D(a,b)`
= 2 x 02D8((a*58E6h)/9) with a non-blocking 11C8:0354h/033Bh sound bracket.  With
B8B4h=1191 (1 unit = 1 real ms) that gives walk = 12 ms/px, climb step 16 ms,
crate drag 24 ms -- exactly the asm's tick counts.  The defect was in the
PRESENTATION layer: the shadow framebuffer only reaches the window through
`pal_input_pump()` -> `pal_video_present_throttled()`, which ran solely from
keyboard/mouse polls.  The walk polls 02FBh per pixel and animated normally
(~10 presented fps), but the climb, crate drag, fuse, burn and recoil never poll
-- the only polls inside them are the game-clock repaints (011Eh/020Ch -> the
int-33h hide/show cursor calls) once per game-second, so those animations sat at
~1 presented fps (measured under Xvfb: 4 presents for a whole climb).  On the
original machine the mode-12h VRAM writes are the CRT content; the port's
equivalent is the throttled present.

Fix: `fn1E78_pace_ns` (the emulated machine's busy-wait hold) now pumps the host
event queue on every hold (`extern void pal_input_pump(void)` -- a PAL-internal
symbol wired directly from seg1E78.c, gameplay-SDL separation untouched).  Each
pacing window absorbs the pump/present cost instead of extending it (the hold's
monotonic deadline is unchanged), so every animation now presents at the ~70 Hz
throttle: the same UP climb that showed 4 frames now shows one per step.

Consequence for the walk: the per-pixel game pacing is untouched (02D8h(2*58E6h)
= 12 ms designed, verified 12.2 ms/call), but the wall time per pixel dropped
from ~19 ms to ~12.2 ms (0.42 -> 0.27 s/cell): the ~7 ms pump/present overhead
that used to serialize AFTER each wait now hides inside the next pacing window.
The 19 ms figure was itself port serialization overhead, not game arithmetic;
DOSBox walks the same distance at ~4.5 ms/px.

### Root cause of the "sprites kept at the left/right, robot stuck" defect (D3)
`fn0C74_0E2E` (the arm-retraction sweep of fn0C74_0FA1) reads the caller's
[bp-4h] word through the `push bp` caller-frame pointer (`mov di,[bp+4h] ;
... ss:[di-4h]`).  Every call site is in 0FA1: the 12E8h abort passes the arm
extension index the loop reached, and the 2476h/15ABh/1ACFh sites store
14h/14h/13h into [bp-4h] immediately before the call.  The port modelled the
value as 0, so the retraction captured its two save-under blocks and swept only
the 5-px base strips: the extended arm blocks (up to 20, and along the completion
path up to 41h, steps -- tips at 58B4h-52h and 58B4h+54h, i.e. across the walk
probe columns) stayed on the canvas as stale sprites at the left and right of
the robot, and the 54B1h/54F0h/3615h edge probes then read them as walls --
the reported stuck state.  Fix: the call sites pass the caller's [bp-4h] VALUE
(wLoc04) and 0E2E consumes it as the sweep start (13 retraction ticks observed
after a 12-step abort where the old code emitted 1).  iface.tsv's 0E2E note
updated.

### Mission record counters and the explosive (D2)
The RAD.DAT mission records are 537 bytes; record offsets 26h..2Bh seed
53DBh/53DCh/53DDh/53DEh (F1/F2/time/F3).  Mission 001 ("SIDNEY/JUSTE POUSSER")
has F3=0 -- F3 is correctly INERT there (the 2C0Ch dispatch gates on 53DEh>0);
mission 002 ("LONDON/UNE ODEUR DE POUDRE") has F3=1.  An F3 press on 001 does
nothing by design.

End-to-end on mission 002 (headless, after really winning 001 via F5 auto-mode):
settle -> RIGHT x2 -> F3 fires fn0C74_5258 (53DEh=1) -> 396Eh (arm/placement) ->
45CEh: fuse sweep 070Dh(14h,12Ch) x162, fuse wait 02D8h(1F4h), descending burn
02D8h(1Eh)/row, blast, recoil -> 076Bh finale.  Total chain ~10.5 s wall at the
1 ms/unit pacing (174.4 -> 184.9 s of the run log).  The canvas dump shows the
crate and the surrounding tiles wiped (the blast crater, rows 312-352 x 180-330)
and no robot sprite anywhere: the robot stood inside its own blast (bomb entry
B4=177/B8=309), so the <22px retreat rule latched 58B3h=1 -- the disintegration
is the asm's correct geometry for adjacent placement.

### Diagnostics added (all env-gated, inert by default)
- RAD_PACE_TRACE=1: stderr log of every 029Ch/02D8h/070Dh call (monotonic ns,
  args, duration; 02D8h also logs the repaint count taken inside its loop).
- RAD_ROBOT_TRACE=1: robot state at the 1B3Bh rise/sweep boundaries and the
  5258h bomb entry.
- The RAD_DUMP_SECS handler also writes /tmp/opencode/dac.bin (the 256-entry
  DAC snapshot) for cross-checking canvas indices against DOSBox captures.

### MODE AUTO mission-001 replay re-verified end-to-end (all 15 commands)
Full RAD.HLP record 1 replay (M(5) F1 F1 F1 K(1) K(8) P M(1) M(10) F1 x6),
headless, 5 s key pacing (the 0800:264Eh command loop drains queued keys at
l264E, so keys arriving while an animation runs are discarded -- original
behaviour; pacing must exceed the longest command, the ~12.5 s P descend).
Per-command end state, port vs the same replay in DOSBox (Xvfb :96, template
match + white-box measurement at canvas origin (80,100)): robot (58B4h,58B8h)
and crate agree EXACTLY on every command:
start 199/133; M(5) 287; F1 309/331/353 (crate 331->353->375->397, fall to
397..418 x 243..264); K(1) turn only (5968h 1 -> FFFF, 0D43h, no move);
K(8) 353 -> 199 (the 58BCh latch starts at 1, so param N walks N-1 cells --
faithful to 54F0h/37C3h, DOSBox identical); P descends: 51B2h FFFF probes both
clear -> 2AD9h: 0D94h frames, 1F08h edge scan, 26EAh shrink slides xL 199->155,
2815h probe descent 58BAh 176->264, 2AD9h fall loop 58B8h 133->221;
M(1) turn only; M(10) 155 -> 353 (adjacent to the crate, xp=396); F1 x6 push
the crate 397->419->441->463->485->507->529 with the robot tracking
375/397/419/441/463/485.  The 6th push puts the crate over the row-14 gap
(529..616 on the lower floor): it falls to (529..550, 353..374), the goal
probe fn0800_0877 pixel (539,374) reads 0Fh, 0877h returns 1 -- WIN; the
victory recolour wipes the crate white except the goal row (identical to the
DOSBox post-win frames).  PRESSEZ + key advances 598Eh:5990h 1.0 -> 2.0 and
mission 002 "LONDON" loads (robot intro drop to xL=1, top=309 -- DOSBox
template match (1,309), identical).  The earlier "robot stuck at x~353, final
pushes no-op" report was the pre-0E2E-fix stale-arm-sprite defect (above) plus
a 2.5 s harness pacing artifact; with the fix and correct pacing there is no
divergence.

## Session 7 -- full-campaign auto-play (work in progress)

### The AUTO-mode key accounting (from the per-command traces)
- fn0800_2401's entry banner ("ENTREE EN MODE AUTO", asm 0800:2505)
  consumes ONE keypress before the command loop starts.  A schedule
  must send F5 + 1 banner key + one key per command + 1 advance key
  (0768 "PRESSEZ UNE TOUCHE" after the win) per mission.
- The command loop (0800:264E) drains queued keys each iteration:
  a key arriving while a command still animates is DISCARDED.  The
  waits must exceed every animation: walk 0.27s/cell, F1 push cycle
  ~4.5s, bomb chain ~9.4s (fuse sweep 162 rows ~3.9s + wait + burn +
  blast + recoil), climb ~1.4s+demolition sweeps, descend ~12.5s.
- Mission 001 replays and wins byte-identically (the crate reaches
  the col-24 goal slot; 0877=1; 598E advances; the mission 002
  loads; the victory recolor matches DOSBox).
- Mission 002 trace (/tmp/opencode/m2d.txt): RIGHT(9) walks
  1->177 exactly, the F3 bomb inserts and recoils correctly, but
  one pre-scheduled key lands inside the bomb animation and is
  drained, shifting the remaining commands by one (the observed
  "F1"-labeled walks of exactly 4 cells = the shifted RIGHT(5)).
- Playthrough tooling: RAD_FAKE_KEYS_FILE (the 128KB script),
  the /proc/pid/mem record-position set (598E=2 at the menu =
  the direct mission-002 load), the 40ms state poller
  (/tmp/opencode/trace_m2c.py pattern).

### Status of the 103-mission campaign
- Missions 1..101 have shipped solutions (RAD.HLP records); 102
  (MYRIAM "LE BON CHEMIN !") and 103 (DUMONT "CA VA TOMBER !")
  have none = the manual play required; record 104 = "NONAME" =
  the end marker.
- The parallel port-vs-DOSBox comparison harness =
  /tmp/opencode/play/ (the keys file, the per-mission captures,
  the compare log).  Mission 001 = the diff 0.205 raw (the dither
  aliasing; the true-grid difference ~1-3%).
- REMAINING: the per-command waits = the bomb-margin (the F3
  sequence needs >10s + the margin), then the full run; the
  missions 102/103 = the manual solving from the live grid.

## Session 8 -- the DOWN-residue investigation: the wire state machine decoded
### The reported bug
User report (mission 001/002 manual play): after DOWN, "sprites / wire
column remain at left-right of robot; robot gets stuck".  The earlier
repro attempts (downtest/downtest2/downtest3) used RELATIVE '+' fake-key
schedules, so their key times were cumulative and the DOWN/RIGHT keys
fired at unintended moments (or never); their residue numbers were
artifacts of that.

### The robot state machine (verified against the asm slices)
- 58B4/58B6 = robot box x-left/x-right; 58B8 = y-top; 58BA = the
  descent-floor y (the intro descent tracks BA=B8+43; the bounce and
  the walks leave BA at the level floor).
- 5968 (word): 1 = the wire retracted / normal, 0xFFFF = the wire
  fully extended (the climb-grab / wire-walk states).
- UP ('H' -> 51AA -> 1B3B): capture 43x28 box, ascend <= 0x58 px
  (070D(0Ah,0C8h)/px, probes above), then descend back; the return is
  interruptible by the below-probes -> the ledge-grab path (direction
  sweeps + 0FA1/0E2E arm sprites + 0DE5/0CFA(0Bh)).  A full bounce
  ends where it started; 5968 restored to 1.
- DOWN ('P' -> 51B2): with 5968==1 probes (BA+1,B6+1)/(BA+1,B6+17h);
  with 0xFFFF probes (BA+1,B4-1)/(BA+1,B4-17h); any hit = refuse.
  On pass -> 2AD9: entry sweep 0D43(0Bh) (5968->0FFFF) or 0D94(0Bh)
  (5968->1), save-under march while (BA-2Bh)>B8 (B8++/px, the
  captured block re-blitted; the block's row 0 carries the wire
  cross-section = the wire column painted behind the descending
  robot - the intended rendering), exit sweep 0DE5/0CFA(0Bh) unless
  58B3<>0, then 02D8(4D0Ch*58E6h/4).
- LEFT ('K' -> 54F0): probes -> optional 2AD9 fall check -> 37C3.
  37C3 with 5968==1 calls 0D43(15h) = the FULL wire extension
  (5968->0FFFF) and returns 1 = the walk animation is skipped;
  with 5968<>1 it runs the edge-probe march (B4--).
- RIGHT ('M' -> 54B1): probes -> optional 2AD9 -> 3615; 3615 with
  5968==0FFFF calls 0CFA(15h) = the full wire retraction (5968->1)
  and returns 1; otherwise the march (B4++).  (The asm `cmp word
  [5968h],0FFh` is an 83 /7 ib SIGN-EXTENDED imm8 = 0FFFFh.)
- So the first LEFT while hanging on the wire ALWAYS extends the
  wire instead of walking, and a DOWN only descends where the
  descent floor 58BA is more than 43 px below 58B8 (else a no-op
  sweep blip).  Both leave wire tiles painted at the robot by
  design; the descent paints the wire column behind the robot.

### Verification (this session)
- The port sweeps 0CFA/0D43/0D94/0DE5, 2AD9, 1B3B, 51B2, 54F0/54B1,
  3615/37C3 match the asm slices literally (incl. the sign-extended
  0FFFFh compare in 3615).
- Side-by-side with DOSBox (Xvfb :99 + xdotool + 0.1s root captures,
  /tmp/opencode/dn_dos2.sh vs /tmp/opencode/dn_port3.py), the
  identical schedule d/F1/d/UP/RIGHT/LEFT/LEFT/DOWN/RIGHT produces
  IDENTICAL phase behavior: the bounce (net ~140 px), the 4-cell
  walk into the crate, the LEFT wire-extension (173 px, no walk),
  the LEFT walk back, the DOWN reposition (199->155, BA 176->264)
  + the real descent 133->221, and no response to the final RIGHT
  (only the timer) - in BOTH implementations.
- Mid-animation keys are buffered and executed after the animation
  (the command loop), matching the original's BIOS-buffer behavior.
- The 64-entry key FIFO >= the BIOS 16-key ring; the visible-window
  present path uploads the full canvas every frame (no stale
  regions; the dummy-driver canvas equals the presented texture).

### Verdict
The current build reproduces the reference on every tested path; the
painted wire column after a descent and the first-LEFT wire extension
are original behavior.  The user's exact repro (keys/mission/build)
is requested; if it predates the presentation fix (the per-step event
pump in fn1E78_pace_ns), the stale-sprite appearance is explained by
that earlier defect.

## Session 9 -- the residue root-cause hunt: the driver is 1-based in y (block ops), the 0/8 fill split, and why the full switch breaks the replay

Repro of record (user's exact sequence, mission 001): settle -> LEFT
(wire extension) -> DOWN.  The port leaves two 4x15 strips on the upper
floor that DOSBox does not: x199-202 (wire colours 3/9) and, after the
experiments below, x150-153 (body colours B/7); rows 145-159 with the
1-based anchors, 146-160 without.

What was established:

- The DOWN path is 51B2 -> 2AD9 -> 1F08.  1F08 (0C74:1F08, 1317 lines)
  is the "lower through the hole" routine: it captures two 4-wide
  strips of the robot-box band (rows B8+0Dh..B8+1Bh): blk [bp-10h] =
  x[B4+0Eh,B4+11h] (body edge colours) and blk [bp-14h] =
  x[B4+19h,B4+1Ch] (wire colours); stamps them 1 px outward (gap
  close); re-captures 5-wide versions (x[B4+0Dh,B4+11h] and
  x[B4+19h,B4+1Dh]); runs the 2153 open-loop (i=1..14h, stamps
  dwLoc10 at B4+0Dh-i and dwLoc14 at B4+19h+i, six 1E3C probes per
  step); the 23EE leftward march (5968==1, i up to 41h, probes
  (B8+1Bh,B4+0Ch-i)/(B8+0Dh,B4+0Ch-i), stamps dwLoc10 at B4+0Dh-i);
  re-seal loops; then the slide at 2680 (B4 -= 5968 sign-extended, 44
  stamps of the full-window block captured at (B4,B8) via 13A3/1E6B),
  gated probes, and finally 2AD9's march.  The port's part6.c is a
  faithful transcription; the leftovers are the final stamps of the
  marching loops whose STOP positions differ.
- The RAD.DES frame 1 block (58E8) is byte-identical to the file
  record, yet DOSBox renders it exactly 1 px higher than the port's
  putimage.  Same for the grid: with op 0x36/0x34 anchored at y-1 the
  crate becomes (331,154)-(352,175) = pixel-identical to DOSBox, the
  floor edge lands on y=176 = 8*22, and the whole settle scene --
  robot, crates, walls, floor -- becomes PIXEL-IDENTICAL to the
  DOSBox reference (only the timer HUD and a 42%-of-screen 0-vs-8
  encoding difference remain).  The game's grid passes 22*k+1 and the
  driver renders at 22*k: the EGAVGA driver is 1-BASED IN Y for the
  block ops.  x is 0-based (putpixel-verified wire column).
- With block-ops y-1 the descent stop needs the getpixel to be
  1-based too (probe 1E3C(BA+1,x) must read row BA) to stop at
  B8=133 like DOSBox; with that the stop and the robot position match
  exactly and the DOWN path differs from the reference by ONLY 130 px
  (the two strips above).
- BUT the full switch (0x34 y-1, 0x36 y-1, 0x2E y-1) BREAKS the
  mission-001 F5 replay: the crates stop at (397,418) instead of
  falling over the goal, rec stays 1.0 (fullrun.py END goalpix=0).
  Reverted; baseline (committed build) still wins (rec=2.0,
  goalpix=6).
- The 0-vs-8 encoding split (129720 px at the settle!) is real and
  probe-relevant: the reference paints palette index 8 (renders
  black) where the port paints 0 in large background areas (ceiling
  rows 0-135 match, but the shaft/hole interior and big dither
  regions differ).  Probes are "!= 0", so every probe result that
  touches an 8-region differs between the implementations.  THE NEXT
  SESSION'S #1 LEAD: find why the port's fill/background is 0 where
  the original is 8 (fill op colour, tile backing, or the 1229
  engine's empty cells), make the canvases agree INCLUDING 0/8, and
  only then re-apply the 1-based y model (block ops + getpixel) and
  re-test the replay.  The strips should then vanish because the
  marching loops' probes will stop exactly where the original's do.
- Reference data captured this session: dn_p6_*.bin + dn_p6_log.txt
  (the strip appears at t=25.71 right before the march), p6/p5 patch
  dumps, frame_58E8/EC/F0/F4.bin (the robot frame blocks),
  port_settle.bin (post-fix), full_fixtest.{log,txt} (the broken
  replay), full_base.txt (the restored win).

### Session 9 addendum (BGI-trace session): the residue mechanism fully decoded, the diverging call found

Instrumented pal_bgi_dispatch (BLIT/PROBE/CAP trace via RAD_BGI_LOG=1) and ran
the exact repro (settle -> LEFT -> DOWN).  The complete chain:

1. 1F08 prologue: captures the LEFT strip (CAP 213,146 w3: 11,11,11,7..) and
   RIGHT strip (CAP 224,146 w3: 3,9,9,9..) of the robot box band
   (rows 146-160), gap-close stamps them 1 px outward (BLIT 212 w3, BLIT 225 w3),
   frees them, then re-captures 5-wide versions (CAP 212 w4: 11,11,11,7,0 /
   CAP 224 w4: 0,3,9,9,9).
2. 2153 open loop (i=1..19): stamps dwLoc10 at B4+0Dh-i and dwLoc14 at
   B4+19h+i; six 1E3C probes per step -- ALL RETURN 0 (clear) at every step,
   so the loop runs to its counter bound in the port.
3. 23EE leftward march (i=1..64): 4-wide stamps B4+0Dh-i, probes
   (B8+1Bh,B4+0Ch-i)/(B8+0Dh,B4+0Ch-i) -- again all clear, runs to 0x41.
4. Re-seal: CAP (147,146) w5 = 0,11,11,11,7 (the march's OWN paint!) and 3
   rightward stamps x147-149 -> LEFTOVER STRIP x150-153 (body colours).
5. Marches from captures at (244,146) w5 = 3,9,9,9,0 (the march's own paint
   again!) leftward 244->199 -> LEFTOVER STRIP x199-202 (wire colours).
6. Then captures (180,146)/(168,146), stamps x180/x168, PROBE (156,265)=11,
   and the slide (B4 199->155, 44 stamps of the 43x28 window block) whose
   stamps erase x155-198 -- which is why only the two strips remain.

DOSBox shows NONE of the strips: its equivalent sequence erases the band
completely.  Two hard facts measured against DOSBox:

- Post-DOWN, columns x210 and x218 (rows 144-162) are palette index 8 in the
  reference but 0 in the port.  Those are exactly the eraser lines 1F08's
  prologue draws over the wire columns (1AF6 = line op si=0x0C).
- THE PORT'S PROLOGUE 1AF6 CALLS (seg0C74_part6.c:127-132) NEVER DISPATCH
  si=0x0C: the full 2.7M-line trace contains no "si=0c ax=00da bx=0092"
  (line x=218 y146-161) nor ax=00d2 (x=210).  The 1C32(0x00) right before
  them DOES dispatch (si=1e ax=0300).  So the eraser lines are simply never
  drawn by the port, the band is never sealed, the later marches run over
  live wire/body pixels, capture their own paint and spread it -- the
  leftovers.  In the original the lines are drawn (colour 8), the probes at
  (210/218, 146) then hit, and the marches never run.

Attempts that did NOT work (both reverted, both verified against fullrun.py):
- Global getpixel y-1 (plus block-op y-1 anchors): settle becomes pixel-perfect
  and the stop matches DOSBox, but the mission-001 F5 replay desyncs (crates
  stop at x397 instead of the goal; rec stays 1.0).
- Line colour 0->8 globally: same replay desync.

NEXT SESSION'S PRECISE TASK: make the port's 1F08 prologue actually emit the
two eraser lines the way the original does.  Why fn1AB8_1AF6 (si=0x0C) from
part6.c:127-132 never reaches pal_bgi_dispatch is unknown: check whether
fn1AB8_10F4(1,0,0) before them changes the dispatch path, whether the 1AF6
wrapper should be a different driver op, or whether the prologue's control
flow diverges earlier than assumed.  A scoped fix (only those two lines, or
the 1F08-local state) is required: global line-colour / probe changes break
the recorded replay.  The 0-vs-8 background encoding split (129720 px) remains
a secondary lead for the probe semantics.

### Session 9 round 2: the UP precedent, the transparent-blit experiment, and the narrowed root cause

User lead: "you solved it for going up -- learn from that commit."  Findings:

- There is no separate UP-fix source commit: def4adc is the initial code dump
  and the three later commits are docs-only.  The UP path (51AA -> 1B3B) was
  BORN correct: it is a pure save-under (1E6B capture of the 43x28 box, then
  13D7 re-blits of the same block while B8 bounces) and never uses 1AF6/1C32
  eraser lines at all.  The analogous UP-path bug that WAS fixed is documented
  in session 6 (D3): fn0C74_0E2E (arm retraction) consumed a hardcoded 0
  instead of the caller's [bp-4h] loop index, leaving stale arm sprites on the
  canvas; the fix was to pass the caller's value.  LESSON: these residues come
  from transcription-level parameter/flow errors in the erase paths, not from
  a global driver-convention difference.
- BGI-trace forensics (bgi_down.log): the 1F08 prologue's 1AF6 eraser lines
  ARE dispatched -- at x=224 (B4+0x19) and x=216 (B4+0x11), y=146..160, in
  both the port and (per the same asm) the original.  The earlier "never
  dispatched / +6 offset" notes were an arithmetic misread (0x19=25, 0x11=17).
  The six 1E54 clamp putpixels follow at (x=216/224, y=151..153) exactly as
  the asm says.  The prologue is faithful.
- Experiment A -- op 0x36 skips payload-zero pixels (transparent) in mode 12h:
  the two strips VANISH (0 px), but the whole DOWN is then refused (the
  probes read the colour-8 background as a hit; only 62 px change; the robot
  never descends).  This proves the strips are the marches painting over live
  pixels, and that the probe clear/hit distinction is exactly the 0-vs-8
  background encoding.
- Experiment B -- op 0x36 lands payload zeroes as index 8 (H1-hard) plus
  getpixel treats 8 as clear: the background encoding then matches DOSBox,
  but the strips REMAIN and the slide's erase trail becomes visible in the
  corridor (1276 px where the reference has 0).  Reverted.
- Both experiments verified to break/re-break fullrun.py; baseline restored
  and re-verified (rec=2.0, goalpix=6).

REMAINING CONTRADICTION TO RESOLVE (next session, cheapest first):
1. The 23EE's first probe reads (210,146) and returns v=0 in the trace, yet
   the settle canvas there is the wire colour 11.  Something between the
   settle and that probe erases (210,146) -- dump a small canvas region
   (x205-215, y144-148) at the moment of the first 23EE probe (the PROBE
   instrumentation is already in place in git history; re-add temporarily)
   and identify the erasing op.  In DOSBox the same probe must return a hit
   (the marches there never run: the band stays clean).
2. The 0-vs-8 split is real (129720 px) but neither global encoding change
   is correct: the original's background is 8 in SOME regions and 0 in
   others, so the split must originate in a specific op (the mission fill,
   the tile records' own 0/8 pixels, or the 1229 engine), not a convention.
3. Keep the D3 lesson in mind: check every [bp-4h]/index value the 1F08
   band phases consume against the asm; the D3 bug was exactly a consumed
   constant-0 instead of the caller's index.

### Session 9 round 3: THE FIX -- 1D95 consumes the caller's [bp-4h] (the D3 lesson applied to DOWN)

User lead: "reread the code that performs the up movement and compare with the
down. it shouldnt be much different."  That was exactly right.

- The UP arm-retraction twin fn0C74_0E2E (part3.c) was fixed in session 6 (D3)
  to consume wArg02 = the caller's [bp-4] word.  Its byte-identical DOWN twin
  fn0C74_1D95 (part5b.c) still modelled it as 0 ("unrecoverable in flat C"),
  and all four 1F08 call sites passed 0x0000.
- 1D95 builds the final band seal from that index: capture rects
  x=[B4+19h+N..B4+1Dh+N] and x=[B4+0Dh-N..B4+11h-N] plus a blit loop of N+1
  inward stamps.  With N=0 the rects degenerate to zero-width and the loop to
  one stamp, so the marched band was never resealed -- the wire/body colour
  strips the user saw.
- FIX (same shape as the 0E2E fix):
  * src/seg0C74_part5b.c: u16 wCallerL4 = wArg02; (was 0x0000 + (void)wArg02)
  * src/seg0C74_part6.c: the four 1D95 call sites (2249/23B4/2512/2A67 paths)
    now pass wLoc04 -- the port's [bp-4h] -- matching the asm, which stores
    the abort index / 14h / 14h / 13h into [bp-4] right before each call.
- VERIFIED:
  * dn_port4 repro: residue strips 0 px (was 120); settle->post changes in the
    old-tile region 367 px (reference 370), reposition region 0 px (reference
    0); strip positions x148-154/x198-204 y144-161 vs DOSBox post-DOWN capture:
    0 differing pixels.
  * fullrun.py F5-AUTO replay still wins: END rec=2.0 goalpix=6 (twice).
- Note (separate, pre-existing, NOT this bug): a full-canvas 0==8 comparison
  against DOSBox shows ~26% differing pixels dominated by full-width rows
  (y=0, 352-354, 374-381, 473) where the reference has index 10/11 bars and
  the port 0/8 -- present identically at settle and post-DOWN, so untouched
  by this fix.  Candidate next investigation: mission HUD/border rendering or
  a DAC palette nuance in the reference captures.

### Session 9 round 4: the "26% full-canvas diff" decoded -- colour-space archaeology, NOT a port bug

First-ever full-canvas port-vs-DOSBox comparison of the mission field showed
~26% differing pixels.  Investigation (all measurements on the post-DOWN and
settle states, dnz_*.png reference captures):

- The DOSBox PNG palette is a *scrambled* permutation of the EGA colours
  (pal[1]=bright green, pal[2]=bright cyan, pal[8]=yellow, pal[12]=red...).
  The game's DAC uploads via BGI op 0x1A (AX=0x8000|idx) are the plain
  DGROUP 0x50CC table (standard-ish order, 8=black for the level via 00FB)
  -- both the port and the real game upload the SAME values (verified in the
  BGI trace).  The scrambled PNG palette is therefore the *effective*
  per-attribute colour, i.e. the game runs a SetPalette attr->DAC map the
  port does not model.
- The map machinery in the original: fn1AB8_1384 copies a 17-byte default
  from driver op 0x3A/AL=1 (found in EGAVGA.BGI at 0x289:
  {10,0,1,2,3,4,5,14h,7,38h..3Fh}) into DGROUP 0xB87A; fn1AB8_129A installs
  it; fn1AB8_1342(dac,attr) rewrites entries at runtime; fn1AB8_1CD7/1CA4
  are the driver calls.  The port transcribes all of these but (a) stages a
  "name record" instead of the default palette for op 0x3A/AL=1, (b) ignores
  the 0x1A AX=attr/BX=entry form, and (c) never applies any map at display.
- HOWEVER: window-level forensics prove the composed colours are IDENTICAL
  for the dominant pairs (port 7 <-> ref 9 grey, port 14 <-> ref 8 yellow,
  port 11 <-> ref 2 bright cyan, port 9 <-> ref 4 bright blue).  The port's
  canvas lives in the game's LOGICAL colour space and the author's g_lvl_dac
  composes it correctly for most entries.  A 3-entry "correction" experiment
  (attrs 3/10/11) made the diff WORSE and was reverted: the port's attr-3
  content matches ref attr 3 for ~25k px and mismatches for ~17k -- i.e. the
  residual is CONTENT, not palette.
- CONCLUSION: the ~26% = (a) a large attribute-space difference that is
  cosmetically neutral (the composed RGBs agree), plus (b) ~20-30k px of REAL
  field-rendering differences: the port picks dim/bright colour variants
  differently for parts of the field, and ~10k px where the port draws black
  (attrs 0/8) while the reference draws colour ((0,0,0)->(0,255,255) 2982 px,
  ->(0,170,170) 2319, ->(170,85,0) 1726, ->(0,255,0) 1268, (0,0,0)->(0,85,255)
  2013).  Category (b) = the port MISSING DRAWS the game performs -- the
  prime suspect for the mission-002+ autoplay desync (probe-visible).
- Baseline re-verified after the revert: fullrun.py rec=2.0 goalpix=6.

NEXT SESSION: find the missing draws.  Leading hypotheses: the game's driver
translates logical colour 0/8 through the palette map for certain ops (the
port writes them raw); or the tile-variant selection in the 1229 field
renderer diverges.  Approach: dump the op stream around a known
(0,0,0)->(0,255,255) pixel cluster from bgi_down.log and compare against the
asm of the drawing routine.

### Session 9 round 5: the level colour map decoded; g_lvl_dac[2]<->[10] swapped

Same-pixel window forensics (the port's canvas attr vs the DOSBox VRAM attr at
identical coordinates) yielded the game's LEVEL colour map, logical -> VRAM:
  1->7, 2->1, 3->3, 4->12, 5->14, 6->6, 7->9, 9->4, 11->2, 12->11, 14->8,
  0/8->0 (background).  Composing g_lvl_dac[a] = capture_pal[map(a)] proves
the author's measured table was correct for every entry EXCEPT 2 and 10,
which are swapped: the level sends logical 2 to VRAM 1 (bright green) and
logical 10 to VRAM 5 (dim green); the old values came from the MENU's
identity-map measurements (2 = "slot icon", 10 = "TIME digits").

- FIX: pal/video.c g_lvl_dac[2] = (0,3F,0) bright green, g_lvl_dac[10] =
  (0,2A,0) green.  Pure display change (the canvas attrs are untouched, so
  the probes and the recorded replay are unaffected).  fullrun.py re-verified:
  rec=2.0 goalpix=6.  The composed-RGB field diff improves by ~4k px.
- REMAINING full-canvas diff (~78k px), now fully characterized:
  1. ~40k px cyan dim/bright inversion, CONTENT-DEPENDENT (the port's attr-11
     pixels match ref attr 2 in some regions and ref attr 3 in others): the
     port's tile/variant render path assigns the wrong cyan variant per tile.
     NOT a palette issue -- next deep dive (the 1229 tile loader / the wire
     drawing routines).
  2. ~10k px HUD-region (y>=374, above the probe area): the port's status
     panel interiors stay background black where the reference fills them
     blue (the game's fill = logical 1 -> VRAM 7), a 2px bright-cyan strip at
     y378-379 is missing (the port's strip is half-height), and the HUD text
     colours differ.  Cosmetic; no gameplay impact.
  3. ~10k px scattered singles = 1px-off content noise.
- Probe relevance: every field-region (y<374) diff above is display-only
  (the canvas attrs are identical), so the mission-002+ desync is NOT caused
  by any of this.  The desync hunt returns to the engine side (the settle
  driver, the 1229 decisions), with the tile-variant render path as the
  visual-fidelity follow-up.

### Session 10: the per-level timer (TIME:00.00) -- mechanism verified, display located

User report: "each level starts a timer after the first movement, displayed at
the right bottom; it only seems to work properly on level 1."

MECHANISM (all verified live with /proc/mem probes + a temporary ARM/DISARM
trace, since reverted):
- Arm: fn0800_00C1(minutes*60) -- called at the mission screen (fn0800_2401,
  after the briefing key), value = [0x53DD]*60.  [0x53DD] = the "Dlai de jeu"
  (game delay) setting = 4 minutes, a PLAYER-CONFIGURED value (the setup-menu
  field via fn1229_050A), identical for every level -- NOT a per-level value.
- Countdown: the emulated int-1Ch handler (lazy-serviced from the host clock)
  decrements [0x58D8:0x58DA] once per second; fn0800_0C71 (per loop iteration)
  divides it into minutes/seconds, caches them at 58C8/58CC and repaints the
  digits via fn0800_0AA1/0B42 only when they change.
- Display: the "TIME:00.00" label (cs:0BE1) at game (x=563, y=406); the digits
  repaint over the "00.00" at x=595..640, y=406..414 -- bottom right.
- SPACE = pause: snapshot 58D8->58D0, DISARM, wait, re-arm from the snapshot.
- Mission advance: fn0800_2827's outer loop = load -> arm -> execution ->
  disarm -> win? -> [0x598E]+=1 -> next tableau, all inside one call.

VERIFICATION ON MISSION 002 (won 001 via the F5 demo, rode the transition):
- The arm fires at the mission-002 screen entry; the clock = 240 (4:00) and
  counts down 1/s; the seconds cache updates; the digits repaint.  The timer
  is MECHANICALLY WORKING on mission 002 in the port.
- DOSBox reference (two scripted runs, 96+76 captures): mission 1 ticks;
  mission 2 with no movement and no keys = static; mission 2 with keys
  arriving = ticking between pauses.  Each SPACE = a pause (freeze) in both
  implementations; a run with 30 queued spaces makes the mission-2 timer look
  frozen the whole time (arm/disarm thrash) in the port, matching the
  original's pause semantics.
- The digits' attr (10) was affected by the session-9 2<->10 swap: the TIMER
  digits now render dim green.  DOSBox's digit colour is green-family but
  bright vs dim is not yet discriminated -- the HUD text may need an
  exception to the field-derived colour map.

NOT YET REPRODUCED: a concrete "does not work properly" failure on level 2+
-- the mechanism checks out end-to-end.  Candidate remaining differences:
(a) arm timing (screen entry vs first movement) is the same in both,
(b) digit colour after the 2<->10 swap, (c) pause semantics on other keys.
NEEDS USER INPUT: the exact visual symptom on level 2+ (frozen digits? wrong
value? wrong colour? not visible?).

### Session 10 round 2: the "--.--" symptom reproduced -- digits blanked during moves

User clarified the symptom: while the robot animates a movement the timer
shows TIME: --.-- (blanked digits / shadow stubs); the real value reappears
when the move finishes.  The clock itself counts correctly throughout.

REPRODUCED (canvas band x555-620, y400-412 sampled at 5 Hz through mission-001
program execution): the digit pairs erase down to their shadow stubs and stay
blank for 1-5 s at a time, ALTERNATING between the minutes pair (x564-580) and
the seconds pair (x587-605); the background repaints as panel cyan 3.

MECHANISM (traced):
- Painters: fn0800_0AA1 (seconds) and fn0800_0B42 (minutes) each do
  erase-fill (005A -> 1B3E -> op 0x12 filled rect with g_fill_color = panel
  cyan 3, correct rects x587-605/y403-411 and x564-580/y403-411) followed by
  the shadow (colour 8) and digit (colour 10) glyph passes (1D82 -> op 0x08
  pen at (595,406)/(563,406) + op 0x26 text from the DGROUP-staged records at
  0xF6E0/0xF6F0 -- the stack-buffer segment-0 bug is already fixed).
- Trigger: fn0800_0C71 repaints only when the cached seconds/minutes change;
  it runs per iteration of the screen command loops (2401/3D9D/2827/31B7).
  During a movement the loop is blocked inside the dispatch, so no 0C71 runs
  and nothing repaints.
- BGI op trace (RAD_BGI_LOG, re-added temporarily, then reverted): the timer
  paints appear only at screen setup; no per-second repaints occur while
  moves animate.
- 1E78:029C (the wait primitive used inside moves) is a pure BIOS-tick delay
  in the original -- it services the clock lazily but does NOT repaint.

ROOT CAUSE SHAPE: something in the movement path erases the digit rects (the
panel repaint, likely fn0800_09C2 stage repaints or the 0C74 scroll/window
redraw) without re-invoking the digit painters, and the digit painters only
run on a seconds/minutes CHANGE from the screen loop, which is blocked during
the move.  The original keeps the digits visible during moves (DOSBox captures
dm2/dm3: digits change every sample while the demo executes).

NEXT STEPS (concrete): (1) trace which op writes the erase into x564-605,
y403-411 during a move -- add the temporary RAD_BGI_LOG back, run one move,
and correlate the erase op with the caller (09C2 stage vs 05B8 scroll);
(2) either suppress that erase for the digit rects or re-invoke 0AA1/0B42
after it, mirroring where the original repaints.
Baseline re-verified after reverting the trace: fullrun.py rec=2.0 goalpix=6.

### Session 10 round 3: FIXED -- clock digits blanked during moves

ROOT CAUSE: fn0C74_011E/020C (the 02D8 move-animation repaint path's
seconds/minutes digit painters) passed a C STACK buffer (u8 bLoc06[4]) to
fn1AB8_1D82, which materializes the record as ES:BX for the driver's 0x26
text op.  A stack buffer resolves to segment 0 in the flat model, so the op
read a zeroed arena: length 0, zero glyphs.  The preceding erase-fill (00DB,
panel cyan 3) still fired, so during every move animation the digits vanished
(user-visible as "TIME: --.--"), reappearing only when the screen loop's own
0AA1/0B42 repaint ran with a real value.  The original's tiny model had
SS==DS, so the stack buffer worked there; the flat port broke it.

The same bug class was already fixed in fn0800_0AA1 (DGROUP 0xF6E0),
fn0800_0B42 (0xF6F0) and fn0800_04E3 (0xF700) -- 011E/020C were missed
because their caller (02D8) is engine-side rather than screen-loop-side.

FIX: stage the 2-digit records in DGROUP -- 011E at 0xF800, 020C at 0xF820
(free space beyond 04E3's 0xF700 scratch), with comments pointing at the
bug-class note.

VERIFIED:
- Timer band (x555-620, y400-412) sampled at 5 Hz through mission-001 program
  execution: BOTH digit pairs now persist with live-changing glyphs through
  every move animation (previously they alternated blank for 1-5 s).
- fullrun.py F5-AUTO replay still wins: rec=2.0 goalpix=6 (twice: with the
  temporary RAD_BGI_LOG trace present and after reverting it).

### Session 10 round 4: FIXED -- minutes showed "14" during moves (098A dsOut overflow)

Symptom: during move animations the clock displayed a fixed "14" in the
minutes field (seconds correct).  Data probe: DGROUP:58CEh = 0x55E1 (21985)
instead of 0, so fn0C74_020C formatted the 32-bit 0x55E10003 = 1440133187 and
its 2-char record kept the leading digits "14".

ROOT CAUSE: fn1EDA_098A (and 3 sibling sites) wrote their "dropped DGROUP
selector" out-param as *(void **)dsOut = an 8-byte pointer, while every caller
stores that output in a 16-BIT local (e.g. fn0C74_02D8's
u16 ds_44).  The 6 overflow bytes landed on the adjacent local dx_45 (the
quotient-high out-param), which had just been set to 0 and was then stored
into DGROUP:58CEh.  0x55E1 is the high word of the PIE-mapped g_dgroup
address.  The screen loop's fn0800_0C71 path only looked correct because
0BEC explicitly zeroes 58CEh and the clobber pattern differed there.

FIX: all four dsOut sites now write 2 bytes (the 16-bit selector the ABI
actually carries):
- seg1EDA_part4.c fn1EDA_098A normal path + divide-by-zero path
- seg1AB8_part4.c fn1AB8_11FB (propagated the 8-byte value)
- seg0C74_part5b.c (wrote 8 zero bytes)

VERIFIED: during full mission-001 program execution DGROUP:58CEh stays 0,
the 020C record reads "03" (023033...) and the 011E record "59"; both digit
pairs render correctly for the whole run.  fullrun.py F5-AUTO replay still
wins: rec=2.0 goalpix=6.

### Session 10 round 5: FIXED -- F2 mission-code dialog (Code Mission)

User symptom: "F2: MISSION should ask for a string ('MADRID'); then F1 goes
to that level directly.  The input box is not properly working and it doesn't
go to that level."  Four stacked defects, all fixed:

1. SEGV opening the dialog (seg0800_part3.c renamed_0800_0d20): the dialog
   feeds the prompt/answer/composition records straight into the BGI 0x26
   text op, which materializes them as 16:16 far pointers.  Six C stack
   buffers resolved to segment 0 -> the driver read pixel garbage as a glyph
   count/pointer -> SIGSEGV in pal_bgi_dispatch.  Same SS==DS class as the
   timer-digit fix.  All six buffers staged in DGROUP 0xF840..0xFD47.

2. Typed characters never appeared (seg1AB8_part4.c fn1AB8_1492): its local
   record copy buf[0x100] was also a stack buffer handed to 1D82.  Staged at
   DGROUP 0xFD50.

3. Typed characters silently dropped (seg0800_part3.c 0D20 insert test
   0FB6..0FE5): the original is a 32-bit signed compare (cwd; cmp dx,bx; jl
   insert; jg no; cmp ax,cx; jnc no) -- insert iff (s16)pen < 0 ||
   pen < limit.  A spurious `== 0 &&` restricted insertion to pen == 0.
   Also fixed: the 1492 draw and the insert both depend on the driver pen;
   field-full typing is dropped exactly as in the original (the DOSBox
   reference shows the same 0-diff behaviour with a full field).

4. The RAD.DAT name sweep never matched (two bugs):
   a. seg1EDA_part3c.c renamed_1eda_060c (the stream open callback): the
      original's `je 0674h` keeps id 0xD7B1 on the read-stream path; the
      transcription set 0xD7B2 unconditionally, so the 0776 read prelude
      latched error 0x68 and the RAD.MEM pre-fill (the last mission name)
      never loaded -- the dialog opened empty.
   b. seg0800_part4.c renamed_0800_11ef (the sweep): the original's
      1EDA:1085 reads each 0x219-byte RAD.DAT record into ds:5CB4, but the
      port's 1091 reads the shared g_1EDA_io_buffer slot, so the 0B24
      compare saw only the stale NONAME.  The slot is now redirected to
      ds:5CB4 around the read (the established part11 pattern).
   c. buf8, the saved record head, was declared 6 bytes; the original frame
      spans [bp-8h..bp-2h] = SEVEN (0A39 copies the length byte plus 6
      payload chars and the 0B24 compare reads 6 chars).  Resized to 7.

VERIFIED (fake-key drives, headless):
- RAD.MEM pre-fill loads (PREFILL err=0000); the sweep compares all 105
  chunks; typing "MADRID" after erasing the pre-fill sets the live answer
  record to [06]"MADRID" and the sweep match lands at position 8
  (MADRID = mission 8 in RAD.DAT); F1 loads it.  Three consecutive runs.
- fullrun.py F5-AUTO replay still wins: rec=2.0 goalpix=6.

NOTE: the RAD.MEM file (data/RAD.MEM, "LONDON\r\n" in git) is the shipped
save state; the dialog pre-fills it and the game rewrites it when a mission
is played.  RAD.DAT holds 105 fixed 537-byte chunks: chunk 0 = the DEMO
entry, chunks 1..105 = [06][name][hint][level data] with the name at the
chunk start.

## Session 12 -- game speed command line (-s/--speed)

User request: a command line parameter to accelerate the game -- movement
faster, the mission clock counts down faster -- without cheating the timer
(no timer freeze, no score hack): a global game-time multiplier, like the
DOSBox cycles control.

Design: ALL game time funnels through exactly two game-time -> host-time
conversion points, so a single multiplier applied there speeds up the whole
simulation uniformly while leaving every piece of game logic untouched:

1. src/seg1E78.c fn1E78_pace_ns (the 029Ch/02BFh pacing primitive): the
   wall-time hold is divided by the factor.  Every animation delay
   (walk per-pixel, climb, crate drag, fuse, burn, recoil, intro slides)
   goes through here.
2. src/seg0800_part1.c fn0800_timer_service (the emulated int-1Ch): the
   host-elapsed -> 18.2 Hz tick count is multiplied by the factor, so the
   mission countdown at DGROUP 0x58D8 drains proportionally faster while
   keeping the exact original tick semantics (18.2065 Hz, +37h ms/tick).

The factor lives in `double g_game_speed` (globals.c/globals.h, default
1.0).  src/main.c parse_speed_args() extracts:

  -s2  -s 2  --speed=2  --speed 2   (factor 0.1..100, fractional ok)
  RAD_SPEED env                     (when no option given)

and STRIPS the speed options from the fabricated PSP command tail, so the
DOS game never sees them.  Invalid factors print
"rad: invalid speed factor '...' (allowed 0.1..100)" and exit 2; the
notice "rad: game speed xN" goes to stderr when the factor != 1.  Speeds
below 1 slow the game down symmetrically (slow motion).

VERIFIED (headless, fake-key drives):
- Clock drain measured at DGROUP 0x58D8 during an armed mission,
  game-seconds consumed per wall-second: 0.5x = 0.44, 1x = 0.93 (base),
  2x = 1.78, 4x = 3.67 -- i.e. 0.47x / 1.0 / 1.91x / 3.95x relative.
- fullrun.py F5-AUTO replay at default speed (factor untouched at 1.0:
  the pace_ns divide is skipped, timer target x1.0): still ends
  rec=2.0 goalpix=6.
- fullrun.py flow re-run with -s4: IDENTICAL result (rec=2.0, goalpix=6)
  at ~43s wall vs ~105s at 1x (the remaining wall delta is the unscaled
  ~2.5s boot plus harness key-schedule offsets, not game time).

Harness notes (for future probing): the intro is two pages -- the SPACE
advances page 1 and F1 (any key) dismisses the PRESSEZ box; the mission
briefing then loads in ~1.1s of REAL time and RETURN arms the clock.  Key
schedules therefore do not scale uniformly with the speed factor: at -s4
use "2.5:space,3.0:f1,5.5:return,6.5:return", at 0.5x
"3.7:space,6.0:f1,9.0:return,10.5:return".  The process ignores SIGTERM
(pre-existing SDL/pal behaviour, also on the baseline binary); test
harnesses must SIGKILL.

data/RAD.MEM restored before commit (test drives replay missions).
