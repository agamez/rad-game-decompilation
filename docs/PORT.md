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
