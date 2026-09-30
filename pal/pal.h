/* pal.h — RAD Linux port: platform abstraction layer contract.
 *
 * Purpose: emulate the DOS/BIOS/x86-hardware services that RAD.EXE used,
 * so recovered gameplay code needs no changes beyond swapping the raw
 * hardware instructions for these calls.
 *
 * Implemented with SDL2 (video, input, audio) + Nuked OPL2 (AdLib).
 */
#ifndef RAD_PAL_H
#define RAD_PAL_H

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t  u8;   typedef uint16_t u16;  typedef uint32_t u32;
typedef int8_t   s8;   typedef int16_t  s16;  typedef int32_t  s32;

/* ---------------- lifecycle ---------------- */
void pal_init(void);            /* window, audio, input */
void pal_shutdown(void);
bool pal_quit_requested(void);  /* window closed */

/* ---------------- x86 I/O ports ----------------
 * The recovered code keeps its literal port numbers and calls these.
 * Handled ports:
 *   0x40..0x43  8253 PIT (channel 2 feeds the PC speaker)
 *   0x61        speaker gate / PPI
 *   0x388,0x389 AdLib (OPL2) register/data; 0x388 read = status
 *   0x3BA       VGA input status 1 (retrace wait -> frame pacing)
 *   0x3C7,3C8,3C9 VGA palette read/write
 * Unknown ports: no-op / return 0. */
void pal_outport(u16 port, u8 val);
u8   pal_inport(u16 port);

/* VGA memory (0xA0000 linear shadow, 128 KiB).
 * The recovered code stores this pointer where the original did
 * `MK_FP(0xA000, 0)`. Writes land in the shadow; pal_video_present()
 * interprets it according to the current mode and blits to the window. */
u8  *pal_vga_memory(void);
void  pal_composed_frame(u8 *out320x200);   /* diagnostic: mode-13h frame */
void  pal_video_set_dac_block(u16 first, u16 count, const u8 *rgb6);
void pal_video_present(void);

/* ---------------- BIOS video (int 10h) ---------------- */
void bios_video_set_mode(u8 mode);                   /* AH=00 */
void bios_video_get_current_video_mode(u8 *mode_out, u8 *page_out); /* AH=0F */

/* ---------------- BIOS keyboard (int 16h) ---------------- */
bool bios_kbd_check_keystroke(void);                 /* AH=01 */
u16  bios_kbd_get_keystroke(void);                   /* AH=00; low=ascii, high=scan */

/* ---------------- DOS services (int 21h) ---------------- */
int   msdos_direct_console_input(void);              /* AH=06 dl=FF: 0 = none */
void  msdos_terminate(u8 code);                      /* AH=4C */
u8    msdos_get_dos_version(void);                   /* AH=30, major version */
u16   msdos_open_file(const char *path, u8 mode);    /* AH=3D; handle or 0xFFFF */
u16   msdos_close_file(u16 handle);                  /* AH=3E */
u16   msdos_read_file(u16 handle, void *buf, u16 count);   /* AH=3F -> read */
u16   msdos_write_file(u16 handle, const void *buf, u16 count); /* AH=40 */
s32   msdos_set_file_position(u16 handle, s32 offset, u8 origin); /* AH=42 */
void  msdos_set_DTA(void *dta);                      /* AH=1A */
bool  msdos_find_first_file(const char *pattern, u8 *dta); /* AH=4E, fills 44-byte DTA */
void  msdos_get_system_time(u8 *h, u8 *m, u8 *s, u8 *hs);   /* AH=2C */
void  msdos_set_interrupt_vector(u8 vec, void *handler);    /* AH=25 */
void *msdos_get_interrupt_vector(u8 vec);            /* AH=35 */
void  msdos_get_current_directory(char *buf);        /* AH=47 */
u8    msdos_get_current_default_drive(void);         /* AH=19 */

/* ---------------- contract extensions ------------------------------------
 * Appended by the PAL implementation; not in the original contract.
 * The recovered RAD code issues int 21h AH=4F ("find next") after
 * msdos_find_first_file() (see fn1E5F_00DE -> 1E5F:0120).  Without a
 * find-next entry point a wildcard enumeration would only ever yield the
 * first match, so this helper is genuinely required.  It advances the
 * directory scan started by msdos_find_first_file() and fills the same
 * 44-byte DTA, returning false when the scan is exhausted. */
bool  msdos_find_next_file(u8 *dta);                 /* AH=4F */

/* Diagnostic used by tools/pal_test.c so the test can report the linked SDL
 * version without including any SDL header itself (SDL stays confined to
 * pal/).  Any of the out pointers may be NULL. */
void  pal_get_sdl_version(int *major, int *minor, int *patch);

/* ---------------- register-frame interrupt dispatch --------------------
 * Appended by the hardware-abstraction repair; not in the original contract.
 * The recovered fn1E5F_000B (1E5F:000B) is a register-frame interrupt
 * trampoline: its callers (seg13C8 mouse, seg13C1 cursor save, seg1206,
 * seg0C43) build a 0x14-byte register image and ask it to dispatch INT 33h
 * (mouse) or INT 10h (video).  fn1E78_0609 (1E78:0609) is the equivalent
 * single-instruction int 10h gateway.  C has no AH/AL/BH/... registers, so
 * both entry points take a word array.  See
 * docs/notes-1E5F-1E78-11C8.md and docs/notes-13C1-13C8.md.
 *
 * pal_int_dispatch: invoke software interrupt `vec` with a 10-word register
 * image, in/out:
 *   frame[0..9] = AX, BX, CX, DX, BP, SI, DI, DS, ES, FLAGS
 * The frame layout is exactly the one 1E5F:0045 writes back.
 *   0x10 video: AH=00/01/02/03/06/07/08/09/0A/0E/10/11/12 are handled;
 *               AH=00/0F share the mode state with bios_video_*().
 *   0x33 mouse: functions 0/1/2/3/4/7/8/13h over the SDL pointer.
 *   other vectors: no-op.
 * FLAGS (frame[9]) is consumed but never modified (carry is not set). */
void pal_int_dispatch(u16 vec, u16 *frame);

/* BIOS video gateway used by fn1E78_0609: regs[0..3] = AX, BX, CX, DX
 * (in/out).  Runs the same int 10h implementations as pal_int_dispatch(0x10)
 * and shares the cursor/attribute state with it.  AH=0F returns the real
 * column count (40/80; mode 13h reports 40 per BIOS convention). */
void pal_bios_int10(u16 *regs);

#endif /* RAD_PAL_H */

/* ---- BIOS Data Area tick (int 8 -> 0040:006C) ----
 * The recovered code calibrates its speed against the BIOS dword tick
 * counter at 0040:006C (18.2065 Hz).  The PAL emulates that counter from
 * the host clock; *pal_bda_tick_byte() is the low byte, safe to spin on. */
volatile u8 *pal_bda_tick_byte(void);

/* ---- BGI driver dispatch (the EGAVGA.BGI hardware layer) ----
 * The original loads Borland's EGAVGA.BGI (embedded in segment 13E2) and
 * dispatches into it with a function number in SI and a 7-word register
 * image {ax,bx,cx,dx,si,di,es}.  The PAL implements the driver over the
 * emulated VGA (see pal/video.c).  Returns nonzero if the number was
 * handled; the register image is updated in place. */
u16 pal_bgi_dispatch(u16 si, u16 *regs);

/* Register the game's video-mode byte (DGROUP 0xB8A3) so the driver's
 * set-mode function reads the same value the recovered code sees. */
void pal_set_mode_byte(u8 *p);
