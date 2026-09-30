/* pal_internal.h — private interfaces shared between the pal C translation units.
 *
 * NOT part of the public contract (pal.h).  No SDL types may appear here,
 * so gameplay code and any non-pal file never sees SDL.
 *
 * Decisions documented at each implementation site. */
#ifndef RAD_PAL_INTERNAL_H
#define RAD_PAL_INTERNAL_H

#include "pal.h"

/* ---- pal.c lifecycle plumbing ---- */
void pal_input_pump(void);        /* poll SDL events (input.c) */
bool pal_input_quit_flag(void);   /* SDL_QUIT observed? (input.c) */

/* ---- video.c ---- */
void pal_video_init(void);
void pal_video_shutdown(void);
void pal_video_outport(u16 port, u8 val);   /* 0x3C7/0x3C8/0x3C9 */
u8   pal_video_inport(u16 port);            /* 0x3BA, 0x3C7/0x3C8/0x3C9 */
void pal_video_on_mode_set(u8 mode);        /* texture/palette reset */
void pal_video_present_internal(void);      /* implicit present from retrace */
void pal_video_present_throttled(void);     /* fallback present from the pump */
u8  *pal_vga12_canvas(void);                /* mode-12h 640x480 index canvas */

/* ---- video.c, added for pal/int.c (interrupt dispatch) ----
 * The int 10h dispatch and the SDL mouse scaling need the current mode's
 * geometry; g_mode lives in video.c, so these accessors keep a single copy
 * of the mode state (see pal/int.c). */
u8   pal_video_get_mode(void);               /* current mode or 0xFF if unset */
void pal_video_get_framebuffer_size(int *w, int *h);  /* mode display geometry */
void pal_video_get_window_size(int *w, int *h);       /* SDL window size (0 if none) */

/* ---- video.c, mode 0x03 text plane ----
 * The BIOS text screen is 80x25 cells of {char, attr}.  The accessor returns
 * the raw 80*25*2-byte array in row-major order (char, attr interleaved);
 * present_frame() renders it as a 720x400 framebuffer (9-px column pitch,
 * 16-px row pitch, 8x8 glyph at the top of each cell). */
#define PAL_TEXT_COLS 80
#define PAL_TEXT_ROWS 25
u8  *pal_video_text_plane(void);

/* ---- int.c: shared cursor state ----
 * The single BIOS cursor (graphics and text modes share it) lives in int.c.
 * bios_video_set_mode() homes it on a mode set, exactly like the BIOS. */
void pal_int_cursor_home(void);

/* Mouse (INT 33h) state, read by the mode-12h present-time cursor overlay.
 * Returns true when the software cursor is shown (show_count > 0) and fills
 * the virtual pointer position in the current mode's framebuffer space. */
bool pal_int_mouse_get(u16 *x, u16 *y, u16 *show_count);

/* ---- input.c ---- */
void pal_input_init(void);
void pal_input_shutdown(void);

/* ---- audio.c ---- */
void pal_audio_init(void);
void pal_audio_shutdown(void);
void pal_audio_outport(u16 port, u8 val);   /* 0x40..0x43, 0x61, 0x388/0x389/0x188 */
u8   pal_audio_inport(u16 port);

/* ---- dos.c ---- */
void pal_dos_init(void);                    /* resolve data directory */

#endif /* RAD_PAL_INTERNAL_H */
