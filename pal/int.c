/* int.c — RAD Linux port: software-interrupt register-frame dispatch.
 *
 * Appended for the recovered interrupt trampoline fn1E5F_000B (1E5F:000B) and
 * the BIOS video gateway renamed_1e78_0609 (1E78:0609).  The DOS-era code invoked
 * INT 10h (video) and INT 33h (mouse) with a register image; C has no
 * AH/AL/BH/... registers, so the recovered wrappers pass a word array.
 *
 * Frame layout (proved by the 1E5F:0045 store-back sequence):
 *   [0]=AX [1]=BX [2]=CX [3]=DX [4]=BP [5]=SI [6]=DI [7]=DS [8]=ES [9]=FLAGS
 *
 * EMULATION DECISIONS (all deliberate; see docs/notes-1E5F-1E78-11C8.md and
 * docs/notes-13C1-13C8.md):
 *   - INT 10h: AH=00 set mode and AH=0F get mode delegate to video.c so the
 *     mode state stays shared with bios_video_*().  Cursor shape/position,
 *     scroll and character services have no visible effect but keep state
 *     where the recovered code reads it back (AH=03).  AH=0F returns the real
 *     BIOS column count (40/80, mode 13h = 40).
 *   - INT 33h: a virtual "mouse" driven by SDL.  The SDL pointer is scaled
 *     from the window to the current mode's framebuffer, then doubled
 *     horizontally (the DOS mouse reports 2x the pixel column in mode 13h).
 *     Position is read on demand from SDL; function 4 overrides it until the
 *     pointer physically moves.  No event pump is run here (a read must not
 *     re-enter the input queue).
 *   - FLAGS is never modified: neither emulated service sets carry.
 */
#include <SDL2/SDL.h>
#include <string.h>

#include "pal.h"
#include "pal_internal.h"
#include "globals.h"

/* ------------------------------------------------------------------ */
/* int 10h (video) state                                              */
/* ------------------------------------------------------------------ */

static u8 g_cursor_start = 0;   /* CH from AH=01 */
static u8 g_cursor_end   = 0;   /* CL from AH=01 */
static u8 g_cursor_row   = 0;   /* DH from AH=02 */
static u8 g_cursor_col   = 0;   /* DL from AH=02 */
static u8 g_cursor_page  = 0;   /* BH from AH=02 (stored, not read back) */
static u8 g_attr[16];           /* AH=10h palette attribute registers */
static u8 g_scanline_mode = 0;  /* AH=12h BL=30h scan-line mode (stored) */

/* Called by bios_video_set_mode() (pal/video.c): the BIOS homes the cursor
 * (row 0, column 0) on every mode set.  Graphics and text modes share the
 * one g_cursor_row/g_cursor_col pair. */
void pal_int_cursor_home(void)
{
    g_cursor_row = 0;
    g_cursor_col = 0;
}

/* ---- mode 0x03 text-plane helpers ---------------------------------- */

/* One cell is 2 bytes: {char, attr}. */
#define TC(row, col)  ((size_t)(row) * PAL_TEXT_COLS + (size_t)(col))

/* AH=06h (up) / AH=07h (down) over the CX..DX window.  AL=0 clears the
 * window; AL>=1 shifts its cells by AL rows and blanks the vacated lines
 * with (space, attr).  Rows outside the plane are ignored. */
static void text_scroll(u8 *tp, int up, u8 al, u8 attr,
                        int top, int left, int bottom, int right)
{
    int rows, width, n, r, c;

    if (top < 0) top = 0;
    if (left < 0) left = 0;
    if (bottom >= PAL_TEXT_ROWS) bottom = PAL_TEXT_ROWS - 1;
    if (right >= PAL_TEXT_COLS) right = PAL_TEXT_COLS - 1;
    if (top > bottom || left > right)
        return;
    rows  = bottom - top + 1;
    width = right - left + 1;

    if (al == 0) {                              /* clear the window */
        for (r = top; r <= bottom; r++)
            for (c = left; c <= right; c++) {
                tp[TC(r, c) * 2 + 0] = ' ';
                tp[TC(r, c) * 2 + 1] = attr;
            }
        return;
    }

    n = (al > rows) ? rows : al;
    if (up) {
        for (r = top; r <= bottom - n; r++)
            memmove(&tp[TC(r, left) * 2], &tp[TC(r + n, left) * 2],
                    (size_t)width * 2);
        for (r = bottom - n + 1; r <= bottom; r++)
            for (c = left; c <= right; c++) {
                tp[TC(r, c) * 2 + 0] = ' ';
                tp[TC(r, c) * 2 + 1] = attr;
            }
    } else {
        for (r = bottom; r >= top + n; r--)
            memmove(&tp[TC(r, left) * 2], &tp[TC(r - n, left) * 2],
                    (size_t)width * 2);
        for (r = top; r <= top + n - 1; r++)
            for (c = left; c <= right; c++) {
                tp[TC(r, c) * 2 + 0] = ' ';
                tp[TC(r, c) * 2 + 1] = attr;
            }
    }
}

/* AH=0Eh teletype.  BEL is a no-op; BS moves left; CR homes the column;
 * LF advances a row.  A printable char is written with the cell's existing
 * attribute and advances the cursor, wrapping at column 80 and scrolling
 * when the last row is passed. */
static void text_teletype(u8 *tp, u8 ch)
{
    switch (ch) {
    case 0x07:                                  /* BEL */
        return;
    case 0x08:                                  /* BS */
        if (g_cursor_col > 0)
            --g_cursor_col;
        return;
    case 0x0D:                                  /* CR */
        g_cursor_col = 0;
        return;
    case 0x0A:                                  /* LF */
        ++g_cursor_row;
        break;
    default:
        tp[TC(g_cursor_row, g_cursor_col) * 2 + 0] = ch;
        if (++g_cursor_col >= PAL_TEXT_COLS) {
            g_cursor_col = 0;
            ++g_cursor_row;
        }
        break;
    }
    if (g_cursor_row >= PAL_TEXT_ROWS) {
        text_scroll(tp, 1, 1, 0x07, 0, 0, PAL_TEXT_ROWS - 1, PAL_TEXT_COLS - 1);
        g_cursor_row = PAL_TEXT_ROWS - 1;
    }
}

static u8 columns_for_mode(u8 mode)
{
    /* BIOS convention: 40 columns for modes 0/1, 80 for 2/3/7; mode 13h
     * reports 40 (320 px / 8 px per cell).  Other modes: 80. */
    switch (mode) {
    case 0x00: case 0x01: return 40;
    case 0x13:            return 40;
    default:              return 80;
    }
}

static void int10_core(u16 *ax, u16 *bx, u16 *cx, u16 *dx)
{
    u8 ah = (u8)(*ax >> 8);
    u8 al = (u8)*ax;

    switch (ah) {
    case 0x00:                     /* set video mode */
        bios_video_set_mode(al);
        break;
    case 0x0F: {                   /* get mode: AL=mode AH=cols BH=page */
        u8 mode = 0, page = 0;
        bios_video_get_current_video_mode(&mode, &page);
        *ax = (u16)(((u16)columns_for_mode(mode) << 8) | (u16)mode);
        *bx = (u16)(((u16)page << 8) | ((u8)*bx));
        break;
    }
    case 0x01:                     /* set cursor shape (CH=start CL=end) */
        g_cursor_start = (u8)(*cx >> 8);
        g_cursor_end   = (u8)*cx;
        break;
    case 0x02:                     /* set cursor position (DH row DL col) */
        g_cursor_row  = (u8)(*dx >> 8);
        g_cursor_col  = (u8)*dx;
        g_cursor_page = (u8)(*bx >> 8);
        break;
    case 0x03:                     /* read cursor: CX=shape DX=position */
        (void)g_cursor_page;       /* stored for AH=02 completeness */
        *cx = (u16)(((u16)g_cursor_start << 8) | g_cursor_end);
        *dx = (u16)(((u16)g_cursor_row << 8) | g_cursor_col);
        break;
    case 0x06:                     /* scroll up   */
    case 0x07:                     /* scroll down */
        if (pal_video_get_mode() == 0x03) {
            /* AL = lines (0 = clear), BH = blank attr, CX = top-left,
             * DX = bottom-right. */
            text_scroll(pal_video_text_plane(), ah == 0x06, al, (u8)(*bx >> 8),
                        (u8)(*cx >> 8), (u8)*cx, (u8)(*dx >> 8), (u8)*dx);
        }
        break;
    case 0x08:                     /* read char/attr at cursor */
        if (pal_video_get_mode() == 0x03) {
            u8 *tp = pal_video_text_plane();
            u8 ch = tp[TC(g_cursor_row, g_cursor_col) * 2 + 0];
            u8 at = tp[TC(g_cursor_row, g_cursor_col) * 2 + 1];
            *ax = (u16)(((u16)at << 8) | ch);
        } else {
            *ax = (u16)((0x07u << 8) | 0x20u);   /* AL=' ' AH=7 */
        }
        break;
    case 0x09:                     /* write char/attr (no cursor advance) */
    case 0x0A:                     /* write char (keep existing attr)     */
        if (pal_video_get_mode() == 0x03) {
            u8 *tp = pal_video_text_plane();
            u16 count = *cx;
            u8 attr = (u8)*bx;
            int row = g_cursor_row, col = g_cursor_col;
            u16 i;
            for (i = 0; i < count; i++) {
                size_t off = TC(row, col) * 2;
                tp[off] = al;
                if (ah == 0x09)
                    tp[off + 1] = attr;
                if (++col >= PAL_TEXT_COLS) {
                    col = 0;
                    row = (row + 1) % PAL_TEXT_ROWS;
                }
            }
        }
        break;
    case 0x0E:                     /* teletype output */
        if (pal_video_get_mode() == 0x03)
            text_teletype(pal_video_text_plane(), al);
        break;                     /* graphics: no visible effect */
    case 0x10:                     /* palette / attribute controller */
        if (al == 0x00)            /* set one attribute register: BL=idx BH=val */
            g_attr[(u8)*bx & 0x0F] = (u8)(*bx >> 8);
        else if (al == 0x03)       /* toggle blink/intensity */
            g_attr[0] = (u8)(g_attr[0] ^ 0x01);
        break;                     /* AL=01/02 have no storage model */
    case 0x11:                     /* font services: no-op */
        break;
    case 0x12:                     /* alternate select */
        if (((u8)*bx) == 0x30) {   /* BL=30h: scan-line mode */
            g_scanline_mode = 1;
        } else if (((u8)*bx) == 0x10) {
            /* BL=10h: return EGA information.  The emulated machine is a
             * VGA: per RBIL a VGA BIOS answers BH=0 (color), BL=0/1 (256K
             * memory), CL=09h (switches -- < 0Ch so EGA-era detection
             * falls through to the VGA check), CH=0. */
            *ax = (*ax & 0xFF00);
            *bx = 0x0100;          /* BH=0 (color), BL=1 (memory) */
            *cx = 0x0009;          /* CL=09h switches, CH=0 */
        }
        (void)g_scanline_mode;
        break;
    case 0x1A:                     /* display combination (VGA+) */
        if (((u8)*ax) == 0x00) {
            /* AL=00h get: AL=1Ah identifies VGA BIOS, BX=0008h = VGA with
             * color analog display (the detected class the game maps to
             * its EGAVGA record). */
            *ax = 0x001A;
            *bx = 0x0008;
        }
        /* AL=01h set: stored only */
        break;
    default:
        break;
    }
}

/* ------------------------------------------------------------------ */
/* int 33h (mouse) state                                              */
/* ------------------------------------------------------------------ */

static struct {
    u16 show_count;      /* fn1/fn2 show/hide nesting counter */
    u16 x, y;            /* virtual position */
    u16 xmin, xmax;      /* fn7 horizontal range */
    u16 ymin, ymax;      /* fn8 vertical range */
    u16 threshold;       /* fn13h speed threshold (stored, unused) */
    bool override_pos;   /* set by fn4 until the SDL pointer moves */
    bool have_last;      /* last_mx/last_my are valid */
    int last_mx, last_my;
} g_mouse = { 0, 0, 0, 0, 639, 0, 199, 0, false, false, 0, 0 };

static u16 mouse_clamp(int v, u16 lo, u16 hi)
{
    if (v < (int)lo) return lo;
    if (v > (int)hi) return hi;
    return (u16)v;
}

/* Scale the SDL window pointer into the current mode's framebuffer, then
 * double x for mode 13h only (the DOS mouse reports 2x the pixel column
 * there).  The 640x480 mode-12h canvas is 1:1.  Result is clamped to the
 * fn7/fn8 range. */
static void mouse_pos_from_sdl(int mx, int my, u16 *ox, u16 *oy)
{
    int fw = 320, fh = 200, ww = 0, wh = 0;
    int fx, fy, mult;

    pal_video_get_framebuffer_size(&fw, &fh);
    pal_video_get_window_size(&ww, &wh);
    if (fw <= 0) fw = 320;
    if (fh <= 0) fh = 200;
    if (ww <= 0) ww = fw;
    if (wh <= 0) wh = fh;

    fx = (mx * fw) / ww;
    fy = (my * fh) / wh;
    if (fx < 0) fx = 0;
    if (fx >= fw) fx = fw - 1;
    if (fy < 0) fy = 0;
    if (fy >= fh) fy = fh - 1;

    mult = (pal_video_get_mode() == 0x13) ? 2 : 1;
    *ox = mouse_clamp(fx * mult, g_mouse.xmin, g_mouse.xmax);
    *oy = mouse_clamp(fy, g_mouse.ymin, g_mouse.ymax);
}

/* Mouse state for the mode-12h present-time cursor overlay (pal/video.c).
 * Returns true while the software cursor is shown. */
bool pal_int_mouse_get(u16 *x, u16 *y, u16 *show_count)
{
    if (x)
        *x = g_mouse.x;
    if (y)
        *y = g_mouse.y;
    if (show_count)
        *show_count = g_mouse.show_count;
    return g_mouse.show_count > 0;
}

static void int33_core(u16 *ax, u16 *bx, u16 *cx, u16 *dx)
{
    pal_input_pump();          /* the menu phase is mouse-driven: refresh
                                * SDL events (and the throttled present). */
    switch (*ax) {
    case 0x0000:               /* reset / driver status */
        *ax = 0xFFFF;          /* a mouse is always present */
        *bx = 2;               /* left + right (fn3 bit0/bit1) */
        /* The DOS driver homes the pointer to the screen centre on reset.
         * The canvas for mode 12h is 640x480, so centre = (320,240). */
        g_mouse.x = 320;
        g_mouse.y = 240;
        g_mouse.override_pos = true;   /* keep it until the pointer moves */
        break;
    case 0x0001:               /* show cursor */
        if (g_mouse.show_count != 0xFFFF)
            ++g_mouse.show_count;
        break;
    case 0x0002:               /* hide cursor */
        if (g_mouse.show_count != 0)
            --g_mouse.show_count;
        break;
    case 0x0003: {             /* get position + buttons */
        int mx = 0, my = 0;
        u32 st = SDL_GetMouseState(&mx, &my);
        bool moved = !g_mouse.have_last ||
                     mx != g_mouse.last_mx || my != g_mouse.last_my;
        if (moved || !g_mouse.override_pos) {
            g_mouse.have_last = true;
            g_mouse.last_mx = mx;
            g_mouse.last_my = my;
            g_mouse.override_pos = false;
            mouse_pos_from_sdl(mx, my, &g_mouse.x, &g_mouse.y);
        }
        *bx = (u16)(((st & SDL_BUTTON_LMASK) ? 0x01u : 0x00u) |
                    ((st & SDL_BUTTON_RMASK) ? 0x02u : 0x00u) |
                    ((st & SDL_BUTTON_MMASK) ? 0x04u : 0x00u));
        *cx = g_mouse.x;
        *dx = g_mouse.y;
        break;
    }
    case 0x0004:               /* set position (overrides until moved) */
        /* Recovery artifacts: the frozen prototypes of the 13C8 wrappers
         * cannot carry the original's stack arguments, so several call
         * sites stage CX=DX=0 (see docs/notes-133F.md "Uncertain sites").
         * Treating that as "move to the top-left corner" pins the cursor
         * there in headless runs; keep the reset-homed centre instead. */
        if (*cx == 0 && *dx == 0)
            break;
        g_mouse.x = mouse_clamp((int)*cx, g_mouse.xmin, g_mouse.xmax);
        g_mouse.y = mouse_clamp((int)*dx, g_mouse.ymin, g_mouse.ymax);
        /* Remember the raw pointer position so fn3 keeps returning the
         * requested position until the physical pointer actually moves. */
        (void)SDL_GetMouseState(&g_mouse.last_mx, &g_mouse.last_my);
        g_mouse.have_last = true;
        g_mouse.override_pos = true;
        break;
    case 0x0007:               /* set horizontal range */
        g_mouse.xmin = *cx;
        g_mouse.xmax = *dx;
        break;
    case 0x0008:               /* set vertical range */
        g_mouse.ymin = *cx;
        g_mouse.ymax = *dx;
        break;
    case 0x0013:               /* set speed threshold (stored, unused) */
        g_mouse.threshold = *bx;
        (void)g_mouse.threshold;
        break;
    default:
        break;
    }
}

/* ------------------------------------------------------------------ */
/* public dispatch                                                    */
/* ------------------------------------------------------------------ */

void pal_int_dispatch(u16 vec, u16 *frame)
{
    switch (vec) {
    case 0x10:
        if ((u8)(frame[0] >> 8) == 0x10 && (u8)frame[0] == 0x12) {
            /* AH=10h AL=12h: Set DAC Color Block.  BX = the first index,
             * CX = the count, ES:DX = the 6-bit RGB triples.  The DAC lives
             * in the video PAL, and ES is only present in the frame. */
            pal_video_set_dac_block(frame[1], frame[2],
                                    (const u8 *)far_ptr(((u32)frame[8] << 16) |
                                                        (u32)frame[3]));
            break;
        }
        int10_core(&frame[0], &frame[1], &frame[2], &frame[3]);
        break;
    case 0x33:
        int33_core(&frame[0], &frame[1], &frame[2], &frame[3]);
        break;
    default:
        break;
    }
    /* frame[9] (FLAGS) is intentionally left untouched: neither emulated
     * service sets carry. */
}

void pal_bios_int10(u16 *regs)
{
    int10_core(&regs[0], &regs[1], &regs[2], &regs[3]);
}
