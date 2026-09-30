/* video.c — RAD Linux port: SDL2 window + VGA emulation.
 *
 * Responsibilities:
 *   - window/renderer/streaming texture creation and teardown
 *   - the 128 KiB "VGA shadow" that stands in for the linear 0xA0000 memory
 *   - conversion of the shadow to RGB with the current 6-bit DAC palette
 *   - VGA DAC palette ports 0x3C7/0x3C8/0x3C9
 *   - VGA input status 1 (0x3BA/0x3DA): vertical-retrace flag AND frame pacing
 *
 * ---------------------------------------------------------------------------
 * EMULATION DECISIONS (all deliberate, see comments at each site):
 *
 * Retrace / pacing.  Real RAD polls 0x3BA (see fn1AB8_2011 in the recon,
 * `mov dx,3BAh ; in al,dx ; and al,80h`).  We emulate a 70 Hz VGA frame:
 *   - the "vertical retrace active" window is the first 1/8 of each frame
 *     (~1.8 ms of the ~14.29 ms period);
 *   - a read while the display is *active* blocks (without busy-spinning the
 *     CPU) until the next frame boundary, then reports retrace active;
 *   - the first read after that window elapses reports retrace inactive and
 *     implicitly presents the shadow framebuffer, completing one frame.
 * This makes `while (inport(0x3BA) & 8);` and `while (!(inport(0x3BA) & 8));`
 * both terminate, and gives the game 70 Hz pacing without touching gameplay
 * code (the game's retrace poll becomes the frame flip).
 * Status bits: bit 3 (0x08) is what the brief specifies for vertical retrace;
 * bit 7 (0x80) is ALSO set because the recovered fn1AB8_2011 tests bit 7.
 * Bits 4/5 are left clear (status reads of the recovered code then settle).
 *
 * Palette.  6-bit DAC values are converted to 8-bit by bit replication
 * ((v<<2)|(v>>4)) as requested, avoiding a divide.
 *
 * Modes.  Mode 13h (320x200x8) is implemented fully: shadow[0..63999] with a
 * 320-byte row stride.  Planar 16-colour modes (0x0D/0x0E/0x10/0x12) are
 * best-effort: the four planes are read from consecutive 38400-byte (or
 * width*height/8) regions of the shadow.  NOTE: the shadow is 128 KiB while
 * mode 12h needs 4*38400 = 153600 bytes, so its fourth plane is truncated;
 * the Attribute Controller (port 0x3C0) is not emulated, so the 16 colour DAC
 * entries are used directly.  Text modes present a blank window.
 * ---------------------------------------------------------------------------
 */
#include <SDL2/SDL.h>
#include <string.h>
#include <stdlib.h>

#include "pal.h"
#include "pal_internal.h"
#include "globals.h"
#include "font8x8.h"   /* 256-glyph CP437 font (BGI 0x26 op + mode 3 text) */
#include "font_stroke.h" /* Borland BGI Triplex stroke font (mode-1 text) */

#define VGA_SHADOW_SIZE 262144u   /* 256 KiB: mode 13h + all 4-plane modes */

/* Retrace status bits (see header comment). */
#define VGA_VRETRACE_BITS 0x88u   /* bit 3 + bit 7 */

static SDL_Window   *g_win;
static SDL_Renderer *g_ren;
static SDL_Texture  *g_tex;
static int           g_tex_w, g_tex_h;

static u8  g_shadow[VGA_SHADOW_SIZE];

/* Mode 12h logical framebuffer: 640x480, one byte per pixel holding the
 * palette index 0..15.  The port deliberately does NOT emulate real 4-plane
 * VGA hardware: a linear index buffer produces identical output through the
 * DAC lookup (the byte selects one of the 16 installed colors), and every
 * blob draw op below writes it through the same plot helper.  Allocated once,
 * lazily. */
#define VGA12_W 640
#define VGA12_H 480
#define VGA12_SIZE (VGA12_W * VGA12_H)
static u8 *g_vga12;

static u8 *vga12_canvas(void)
{
    if (!g_vga12)
        g_vga12 = (u8 *)calloc(1, VGA12_SIZE);
    return g_vga12;
}

/* Diagnostic accessor (dumps / verification); NULL never returned. */
u8 *pal_vga12_canvas(void)
{
    return vga12_canvas();
}

/* The game's graphics driver (the embedded blob dispatched via [0xB820])
 * addresses the LINEAR 64 KiB VGA segment 0xA000 directly.  Pixel (x, y)
 * is the byte at offset ((u32)y * 320 + x) & 0xFFFF: the natural 16-bit
 * wrap.  Coordinates may legitimately exceed 320x200 (the game's effects
 * use y up to ~480); they wrap back into the visible 320x200 area, and
 * that wrap is intentional game behavior.  The RLE title art
 * (fn0C43_0056) writes the same memory via pal_vga_memory() = g_shadow,
 * so there is ONE framebuffer: g_shadow's first 65536 bytes. */
#define DRV_STRIDE 320
#define DRV_SIZE   65536u
static inline u16 drv_off(int x, int y)
{
    return (u16)(((u32)y * DRV_STRIDE + (u32)x) & 0xFFFFu);
}
static int g_org_x, g_org_y;      /* viewport origin (translate amounts) */
static u8  g_drv_color;           /* current LINE/foreground color (word low nibble) */
static u8  g_fill_color;          /* current FILL/background color (word high nibble) */
static u16 g_pen_x, g_pen_y;      /* pen position */

/* Text state for the driver's 0x24/0x26/0x28 ops.  The original keeps these
 * in driver state at [0x1400..0x140B]; the port mirrors them in file statics.
 *   g_txt_ax      [0x1400] the AX staged by 0x24 (AH=[0x1401], AL=[0x1402])
 *   g_txt_sx      [0x1404] the BX staged by 0x24 (x size / glyph width)
 *   g_txt_sy      [0x1406] the CX staged by 0x24 (y size / height)
 *   g_txt_gw      [0x1408] effective glyph width (8, or BX when wide)
 *   g_txt_flag_a  [0x140A] mode flag (0 in the port; the [0x7C]==3 branch
 *                 that would set 0xFFFF is ignored)
 *   g_txt_align   [0x1402]/[0x1403] op-0x2A AX: AH = horizontal code
 *                 (0=left/1=centre/2=right), AL = vertical code
 *                 (0=bottom/1=centre/2=top) -- the Borland SetTextJustify
 *                 pair, exactly as the driver stores it at 0x2295.
 *   g_txt_mode    op-0x24 AL: 0 = 8x8 bitmap metrics, 1 = wide/stroke
 *                 (not emulated; bitmap fallback), 2 = compact half-size
 *                 (AL==2, the menu's "Version enregistree" line). */
static u16 g_txt_ax;
static u16 g_txt_sx = 8;
static u16 g_txt_sy = 8;
static u16 g_txt_gw = 8;
static u16 g_txt_flag_a;
static u16 g_txt_align;
static u8  g_txt_wide;
static u8  g_txt_mode;

/* Inter-character/-line spacing the original publishes as 3/3. */
#define TXT_SPACING_X 3
#define TXT_SPACING_Y 3
static u16 g_clip_x0 = 0, g_clip_y0 = 0, g_clip_x1 = 639, g_clip_y1 = 479;
static u8  g_mode = 0xFF;         /* no mode selected yet */
static u8 *g_ext_mode = 0;        /* game's mode byte (DGROUP 0xB8A3), set via pal_set_mode_byte */

void pal_set_mode_byte(u8 *p) { g_ext_mode = p; }

static u8  g_pal[256][3];         /* 6-bit VGA DAC */
static u32 g_pal8[256];           /* ARGB8888 lookup */
static bool g_pal_dirty = true;

/* ------------------------------------------------------------------ */
/* mode 0x03 text plane                                                */
/* ------------------------------------------------------------------ */
/* 80x25 BIOS text cells, each a {char, attr} pair.  The visible text
 * framebuffer is 720x400: 9-pixel column pitch (the 8x8 glyph occupies
 * columns 0..7, column 8 is blank) and 16-pixel row pitch (the glyph is
 * drawn at the top of the cell).  The INT 10h handlers in pal/int.c mutate
 * this plane through pal_video_text_plane(). */
static u8 g_text[PAL_TEXT_COLS * PAL_TEXT_ROWS][2];

/* menu text palette, extracted from the DOSBox reference capture
 * (/tmp/opencode/dosbox/capture/g_t8_crop.png).  The capture's distinct
 * rendered 8-bit colours were converted to the 6-bit DAC values the BIOS
 * stores (v >> 2).  Entries marked "capture" are the observed values; the
 * unobserved slots keep the standard EGA colours. */
static const u8 g_ega_dac[16][3] = {
    {0x00,0x00,0x00},  /*  0 black          */
    {0x00,0x00,0x2A},  /*  1 blue           (capture) */
    {0x00,0x2A,0x00},  /*  2 green          */
    {0x00,0x2A,0x2A},  /*  3 cyan           (capture) */
    {0x2A,0x00,0x00},  /*  4 red            (capture) */
    {0x2A,0x00,0x2A},  /*  5 magenta        */
    {0x2A,0x15,0x00},  /*  6 brown          */
    {0x2A,0x2A,0x2A},  /*  7 light grey     (capture) */
    {0x15,0x15,0x15},  /*  8 grey           (capture) */
    {0x00,0x15,0x3F},  /*  9 bright blue    (capture) */
    {0x00,0x3F,0x00},  /* 10 bright green   (capture) */
    {0x00,0x3F,0x3F},  /* 11 bright cyan    (capture) */
    {0x3F,0x15,0x15},  /* 12 bright red     (capture) */
    {0x3F,0x15,0x3F},  /* 13 bright magenta */
    {0x3F,0x3F,0x15},  /* 14 yellow         */
    {0x3F,0x3F,0x3F}   /* 15 white          (capture) */
};

/* Gameplay/menu palette.  No longer a single hard-coded table for both
 * screens: the game now programs the DAC itself through BGI op 0x1A
 * (fn1AB8_1CBA, recovered as fn13E2_0080 for the menu and fn13E2_00FB for
 * the level).  This table remains only as the mode-set default until the
 * game's first 0x1A call; it is the MEASURED level palette
 * (/tmp/opencode/cmp/run3/o_game.png, cropped (80,101)-(720,577), resized
 * to 640x480): indices 5/13 are the scalar blends, index 8 is black (the
 * level shows no (85,85,85)) and index 15 is WHITE (the pushable crate is
 * pure white in the reference).  The menu's grey index 8 arrives via the
 * game's own 0x1A palette upload. */
static const u8 g_lvl_dac[16][3] = {
    {0x00,0x00,0x00},  /*  0 black          (measured) */
    {0x00,0x00,0x2A},  /*  1 blue           (measured) */
    {0x00,0x3F,0x00},  /*  2 bright green   (measured: level map sends logical 2
                           to VRAM 1 = (0,255,0); the old dim value came from
                           the MENU's identity map slot icon) */
    {0x00,0x2A,0x2A},  /*  3 cyan           (measured) */
    {0x2A,0x00,0x00},  /*  4 red            (measured) */
    {0x0A,0x1A,0x1B},  /*  5 blend 40,105,109 (measured) */
    {0x2A,0x15,0x00},  /*  6 brown          (measured) */
    {0x2A,0x2A,0x2A},  /*  7 light grey     (measured) */
    {0x00,0x00,0x00},  /*  8 black          (measured: no grey in level) */
    {0x00,0x15,0x3F},  /*  9 bright blue    (measured) */
    {0x00,0x2A,0x00},  /* 10 green          (measured: level map sends logical
                           10 to VRAM 5 = (0,170,0); swapped with 2 above) */
    {0x00,0x3F,0x3F},  /* 11 bright cyan    (measured) */
    {0x3F,0x15,0x15},  /* 12 bright red     (measured) */
    {0x21,0x2C,0x30},  /* 13 blend 134,178,195 (measured) */
    {0x3F,0x3F,0x15},  /* 14 yellow         (measured) */
    {0x3F,0x3F,0x3F}   /* 15 white          (measured: the crate) */
};

/* Return the raw 80x25 {char, attr} cell array for pal/int.c. */
u8 *pal_video_text_plane(void)
{
    return &g_text[0][0];
}

static void text_plane_clear(u8 attr)
{
    int i;
    for (i = 0; i < PAL_TEXT_COLS * PAL_TEXT_ROWS; i++) {
        g_text[i][0] = ' ';
        g_text[i][1] = attr;
    }
}

/* Load the extracted menu text palette into the DAC (0..15), black after. */
static void load_text_palette(void)
{
    int i;
    memset(g_pal, 0, sizeof(g_pal));
    for (i = 0; i < 16; i++) {
        g_pal[i][0] = g_ega_dac[i][0];
        g_pal[i][1] = g_ega_dac[i][1];
        g_pal[i][2] = g_ega_dac[i][2];
    }
    g_pal_dirty = true;
}

/* Load the extracted gameplay/menu palette into the DAC (0..15), black after.
 * Used on a mode 12h set: the game does not upload this palette through the
 * DAC ports (its 256-entry title upload belongs to mode 13h). */
static void load_level_palette(void)
{
    int i;
    memset(g_pal, 0, sizeof(g_pal));
    for (i = 0; i < 16; i++) {
        g_pal[i][0] = g_lvl_dac[i][0];
        g_pal[i][1] = g_lvl_dac[i][1];
        g_pal[i][2] = g_lvl_dac[i][2];
    }
    g_pal_dirty = true;
}

/* DAC addressing state (ports 0x3C7/0x3C8/0x3C9). */
static u8 g_widx, g_wcomp;        /* PEL write index / component (0=R,1=G,2=B) */
static u8 g_ridx, g_rcomp;        /* PEL read  index / component */
static bool g_dac_write_mode = true;

/* Retrace timing state (SDL performance-counter ticks). */
static bool   g_rt_init = false;
static bool   g_in_vblank = false;
static Uint64 g_vblank_start = 0;
static Uint64 g_perf_freq = 0;

/* ------------------------------------------------------------------ */
/* palette helpers                                                     */
/* ------------------------------------------------------------------ */

static u8 dac6_to_8(u8 v6)
{
    v6 &= 0x3F;
    return (u8)((v6 << 2) | (v6 >> 4));
}

static void palette_rebuild(void)
{
    int i;
    for (i = 0; i < 256; i++) {
        u8 r = dac6_to_8(g_pal[i][0]);
        u8 g = dac6_to_8(g_pal[i][1]);
        u8 b = dac6_to_8(g_pal[i][2]);
        g_pal8[i] = 0xFF000000u | ((u32)r << 16) | ((u32)g << 8) | (u32)b;
    }
    g_pal_dirty = false;
}

/* Standard VGA power-on / BIOS mode-set default palette (6-bit values):
 * entries 0..15 are the EGA colours, 16..31 a grey ramp, 32..247 the
 * 6x6x6 colour cube and 248..255 further greys.  Used on every mode set,
 * exactly like the real BIOS, and then overwritten by the game's own
 * DAC writes. */
static void palette_default(void)
{
    static const u8 ega[16][3] = {
        {0x00,0x00,0x00},{0x00,0x00,0x2A},{0x00,0x2A,0x00},{0x00,0x2A,0x2A},
        {0x2A,0x00,0x00},{0x2A,0x00,0x2A},{0x2A,0x15,0x00},{0x2A,0x2A,0x2A},
        {0x15,0x15,0x15},{0x15,0x15,0x3F},{0x15,0x3F,0x15},{0x15,0x3F,0x3F},
        {0x3F,0x15,0x15},{0x3F,0x15,0x3F},{0x3F,0x3F,0x15},{0x3F,0x3F,0x3F}
    };
    int i, r, g, b;
    memset(g_pal, 0, sizeof(g_pal));
    for (i = 0; i < 16; i++) {
        g_pal[i][0] = ega[i][0];
        g_pal[i][1] = ega[i][1];
        g_pal[i][2] = ega[i][2];
    }
    /* 16..31: grey ramp */
    for (i = 0; i < 16; i++) {
        u8 v = (u8)(i * 4 + 2);
        g_pal[16 + i][0] = g_pal[16 + i][1] = g_pal[16 + i][2] = v;
    }
    /* 32..247: 6x6x6 colour cube, levels 0,12,24,36,48,60 */
    for (i = 0; i < 216; i++) {
        r = (i / 36) % 6;
        g = (i / 6) % 6;
        b = i % 6;
        g_pal[32 + i][0] = (u8)(r * 12);
        g_pal[32 + i][1] = (u8)(g * 12);
        g_pal[32 + i][2] = (u8)(b * 12);
    }
    /* 248..255: 8 grey levels */
    for (i = 0; i < 8; i++) {
        u8 v = (u8)(i * 9);
        g_pal[248 + i][0] = g_pal[248 + i][1] = g_pal[248 + i][2] = v;
    }
    g_pal_dirty = true;
}

/* ------------------------------------------------------------------ */
/* mode table                                                          */
/* ------------------------------------------------------------------ */

/* Returns 1 if the mode is planar 16-colour, 0 otherwise.  On return
 * w and h receive the display dimensions. */
static int mode_is_planar(u8 mode, int *w, int *h)
{
    switch (mode) {
    case 0x0D: *w = 320; *h = 200; return 1;
    case 0x0E: *w = 640; *h = 200; return 1;
    case 0x10: *w = 640; *h = 350; return 1;
    case 0x12: *w = 640; *h = 480; return 1;
    default:   *w = 320; *h = 200; return 0;
    }
}

/* ------------------------------------------------------------------ */
/* window / texture                                                    */
/* ------------------------------------------------------------------ */

static void ensure_texture(int w, int h)
{
    if (g_tex && g_tex_w == w && g_tex_h == h)
        return;
    if (g_tex)
        SDL_DestroyTexture(g_tex);
    g_tex = SDL_CreateTexture(g_ren, SDL_PIXELFORMAT_ARGB8888,
                              SDL_TEXTUREACCESS_STREAMING, w, h);
    g_tex_w = w;
    g_tex_h = h;
}

void pal_video_init(void)
{
    /* Nearest-neighbour scaling: PC art must not be smoothed. */
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");

    g_win = SDL_CreateWindow("RAD",
                             SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                             960, 600, SDL_WINDOW_SHOWN);
    if (!g_win) {
        /* Headless/dummy drivers may still create a window; if not, we keep
         * running with g_ren==NULL and every present becomes a no-op. */
        return;
    }

    g_ren = SDL_CreateRenderer(g_win, -1, SDL_RENDERER_ACCELERATED);
    if (!g_ren)
        g_ren = SDL_CreateRenderer(g_win, -1, SDL_RENDERER_SOFTWARE);
    if (g_ren) {
        SDL_RenderSetLogicalSize(g_ren, 320, 200);
        SDL_SetRenderDrawColor(g_ren, 0, 0, 0, 255);
        ensure_texture(320, 200);
    }

    g_perf_freq = SDL_GetPerformanceFrequency();

    /* Per the brief the palette starts all-black until the game programs it. */
    memset(g_pal, 0, sizeof(g_pal));
    g_pal_dirty = true;
    memset(g_shadow, 0, sizeof(g_shadow));
    text_plane_clear(0x07);   /* a valid 80x25 blank screen from the start */
}

void pal_video_shutdown(void)
{
    if (g_tex) { SDL_DestroyTexture(g_tex); g_tex = NULL; }
    if (g_ren) { SDL_DestroyRenderer(g_ren); g_ren = NULL; }
    if (g_win) { SDL_DestroyWindow(g_win); g_win = NULL; }
}

/* INT 10h AH=10h AL=12h (Set DAC Color Block): first = the starting DAC
 * index, count = the number of entries, rgb6 = count*3 bytes of 6-bit RGB. */
void pal_video_set_dac_block(u16 first, u16 count, const u8 *rgb6)
{
    for (u16 i = 0; i < count; i++) {
        u16 idx = (u16)(first + i);
        if (idx > 255)
            break;
        g_pal[idx][0] = rgb6[i * 3 + 0];
        g_pal[idx][1] = rgb6[i * 3 + 1];
        g_pal[idx][2] = rgb6[i * 3 + 2];
    }
    g_pal_dirty = true;
}

/* Diagnostic accessor: copy the current mode-13h framebuffer into a
 * caller-supplied 320x200 buffer, mirroring present_frame().  For mode 12h
 * (640x480) the buffer cannot hold the whole frame, so the top-left 320x200
 * crop of the logical canvas is dumped instead -- diagnostic only. */
void pal_composed_frame(u8 *out320x200)
{
    if (g_mode == 0x12 && g_vga12) {
        int y;
        for (y = 0; y < 200; y++)
            memcpy(out320x200 + (size_t)y * 320,
                   g_vga12 + (size_t)y * VGA12_W, 320);
        return;
    }
    memcpy(out320x200, g_shadow, (size_t)DRV_STRIDE * 200u);
}

u8 *pal_vga_memory(void)
{
    return g_shadow;
}

/* Called from bios_video_set_mode(): (re)create resources for the new mode. */
void pal_video_on_mode_set(u8 mode)
{
    int w, h;
    if (mode == 0x03) {
        /* 80x25 text: 9-px column pitch x 16-px row pitch = 720x400. */
        w = 720;
        h = 400;
    } else {
        /* Mode 13h and every other/unknown mode fall through to 320x200. */
        mode_is_planar(mode, &w, &h);
    }
    if (g_ren) {
        ensure_texture(w, h);
        if (mode == 0x12) {
            /* Mode 12h presents the full 640x480 canvas stretched to the
             * whole SDL window (DOSBox fills the window when the game
             * switches modes), so disable the aspect-preserving logical-size
             * letterbox; present_frame() supplies the full-window rect. */
            SDL_RenderSetLogicalSize(g_ren, 0, 0);
        } else {
            SDL_RenderSetLogicalSize(g_ren, w, h);
        }
    }
    /* Real BIOS resets the DAC to the default palette on mode set; the game
     * then reprograms it through 0x3C8/0x3C9. */
    palette_default();
    memset(g_shadow, 0, sizeof(g_shadow));

    /* Reset retrace pacing so the first read after a mode change starts a
     * fresh frame. */
    g_rt_init = false;
    g_in_vblank = false;
}

/* ------------------------------------------------------------------ */
/* presentation                                                        */
/* ------------------------------------------------------------------ */

static void fill_planar(u8 *pixels, int pitch, int w, int h)
{
    int ps = (w * h) / 8;          /* bytes per plane */
    int x, y, plane;
    /* Best-effort: bytes beyond VGA_SHADOW_SIZE read as zero (mode 12h's
     * fourth plane is truncated by the 128 KiB shadow). */
    for (y = 0; y < h; y++) {
        u32 *row = (u32 *)(void *)(pixels + (size_t)y * pitch);
        for (x = 0; x < w; x++) {
            int n = y * w + x;
            int byte = n >> 3;
            int bit = 7 - (n & 7);
            int idx = 0;
            for (plane = 0; plane < 4; plane++) {
                size_t off = (size_t)plane * (size_t)ps + (size_t)byte;
                if (off < VGA_SHADOW_SIZE)
                    idx |= ((g_shadow[off] >> bit) & 1) << plane;
            }
            row[x] = g_pal8[idx];
        }
    }
}

/* Render the 80x25 text plane as a 720x400 ARGB8888 image: each cell is a
 * 9x16 box, the 8x8 glyph from g_font8x8 drawn at the top, column 8 in the
 * background colour.  fg = attr low nibble, bg = attr bits 4..6 (the blink
 * bit 0x80 is ignored).  No hardware cursor is drawn. */
static void render_text(u8 *pixels, int pitch)
{
    int row, col, gy, gx;
    for (row = 0; row < PAL_TEXT_ROWS; row++) {
        for (gy = 0; gy < 16; gy++) {
            u32 *out = (u32 *)(void *)(pixels + (size_t)(row * 16 + gy) * pitch);
            for (col = 0; col < PAL_TEXT_COLS; col++) {
                u8 ch   = g_text[row * PAL_TEXT_COLS + col][0];
                u8 attr = g_text[row * PAL_TEXT_COLS + col][1];
                u32 fg  = g_pal8[attr & 0x0F];
                u32 bg  = g_pal8[(attr >> 4) & 0x07];
                u8  bits = (gy < 8) ? g_font8x8[ch][gy] : 0x00;
                for (gx = 0; gx < 9; gx++) {
                    u32 c = bg;
                    if (gx < 8 && (bits & (0x80 >> gx)))
                        c = fg;
                    out[col * 9 + gx] = c;
                }
            }
        }
    }
}

/* ------------------------------------------------------------------ */
/* INT 33h cursor overlay (mode 12h)                                   */
/* ------------------------------------------------------------------ */
/* The DOS mouse driver paints an arrow into VRAM; the port keeps an
 * index-space copy (the arrow was never stored in g_vga12) and composites
 * it only while building the presented texture, so a g_vga12 dump stays
 * pristine and repeated presents never smear the arrow into the canvas.
 * Shape = the classic 9x16 DOS arrow (1 = black border, 2 = white fill),
 * exactly the mask the reference capture shows at the menu. */
#define ARROW_W 9
#define ARROW_H 16
static const u8 g_arrow[ARROW_H][ARROW_W] = {
    {1,0,0,0,0,0,0,0,0},
    {1,1,0,0,0,0,0,0,0},
    {1,2,1,0,0,0,0,0,0},
    {1,2,2,1,0,0,0,0,0},
    {1,2,2,2,1,0,0,0,0},
    {1,2,2,2,2,1,0,0,0},
    {1,2,2,2,2,2,1,0,0},
    {1,2,2,2,2,2,2,1,0},
    {1,2,2,2,2,2,2,2,1},
    {1,2,2,2,2,2,1,1,1},
    {1,2,2,1,2,2,1,0,0},
    {1,2,1,1,1,2,2,1,0},
    {1,1,0,0,1,2,2,1,0},
    {0,0,0,0,0,1,2,2,1},
    {0,0,0,0,0,1,2,2,1},
    {0,0,0,0,0,0,1,1,0},
};

static void present_frame(void)
{
    void *pixels;
    int pitch;
    int w, h, planar;

    if (!g_ren || !g_tex)
        return;
    if (g_pal_dirty)
        palette_rebuild();

    planar = mode_is_planar(g_mode, &w, &h);

    if (SDL_LockTexture(g_tex, NULL, &pixels, &pitch) != 0)
        return;

    if (g_mode == 0x03) {
        render_text((u8 *)pixels, pitch);
    } else if (g_mode == 0x13) {
        const int W = 320, H = 200;
        int x, y;
        for (y = 0; y < H; y++) {
            u32 *row = (u32 *)(void *)((u8 *)pixels + (size_t)y * pitch);
            /* The driver's g_shadow linear 64 KiB framebuffer IS the
             * mode-13h display: no overlay, no coordinate mapping. */
            const u8 *vram = g_shadow + (size_t)y * W;
            for (x = 0; x < W; x++)
                row[x] = g_pal8[vram[x]];
        }
    } else if (g_mode == 0x12) {
        /* Logical 640x480 8-bpp index canvas -> palette lookup.  When the
         * INT 33h software cursor is shown, the classic arrow is composited
         * here (present-time only; g_vga12 is never touched).  The arrow uses
         * FIXED RGB (pure black border, pure white fill) written straight
         * into the presented texture: it must stay visible whatever the game
         * has programmed into the DAC, so it bypasses g_pal8. */
        const int W = VGA12_W, H = VGA12_H;
        const u8 *vram = vga12_canvas();
        int x, y;
        u16 mx = 0, my = 0, mshow = 0;
        bool arrow = pal_int_mouse_get(&mx, &my, &mshow);
        for (y = 0; y < H; y++) {
            u32 *row = (u32 *)(void *)((u8 *)pixels + (size_t)y * pitch);
            const u8 *src = vram + (size_t)y * W;
            int ay = (int)y - (int)my;
            for (x = 0; x < W; x++) {
                u32 pixel = g_pal8[src[x]];
                if (arrow) {
                    int ax = x - (int)mx;
                    if (ax >= 0 && ax < ARROW_W && ay >= 0 && ay < ARROW_H) {
                        u8 a = g_arrow[ay][ax];
                        if (a == 1) pixel = 0xFF000000u;        /* black border */
                        else if (a == 2) pixel = 0xFFFFFFFFu;   /* white fill   */
                    }
                }
                row[x] = pixel;
            }
        }
    } else if (planar) {
        fill_planar((u8 *)pixels, pitch, w, h);
    } else {
        /* Text / unimplemented modes: blank window (documented). */
        memset(pixels, 0, (size_t)pitch * (size_t)g_tex_h);
    }

    SDL_UnlockTexture(g_tex);
    SDL_RenderClear(g_ren);
    if (g_mode == 0x12) {
        /* Stretch the whole 640x480 canvas over the entire window (no
         * letterbox), matching DOSBox's full-window mode-12h presentation. */
        SDL_Rect dst;
        int ow = 0, oh = 0;
        SDL_GetRendererOutputSize(g_ren, &ow, &oh);
        dst.x = 0; dst.y = 0; dst.w = ow; dst.h = oh;
        SDL_RenderCopy(g_ren, g_tex, NULL, &dst);
    } else {
        SDL_RenderCopy(g_ren, g_tex, NULL, NULL);
    }
    SDL_RenderPresent(g_ren);
}

void pal_video_present(void)
{
    present_frame();
}

/* Fallback presentation, called from the input pump: the game only polls
 * the retrace port (which drives present_frame()) while inside graphics
 * pacing loops; during menu/mouse phases nothing would ever be presented
 * and the window stays black.  Throttled to the 70 Hz frame budget. */
void pal_video_present_throttled(void)
{
    static Uint64 g_last_present = 0;
    Uint64 now, frame;

    if (!g_ren || !g_tex)
        return;
    if (g_perf_freq == 0)
        g_perf_freq = SDL_GetPerformanceFrequency();
    frame = g_perf_freq / 70u;
    now = SDL_GetPerformanceCounter();
    if (g_last_present != 0 && now - g_last_present < frame)
        return;
    g_last_present = now;
    present_frame();
}

void pal_video_present_internal(void)
{
    present_frame();
}

/* ------------------------------------------------------------------ */
/* retrace + pacing                                                    */
/* ------------------------------------------------------------------ */

static void wait_until(Uint64 target)
{
    Uint64 now = SDL_GetPerformanceCounter();
    while (now < target) {
        Uint64 remain = target - now;
        Uint64 remain_ms = (remain * 1000u) / g_perf_freq;
        if (remain_ms > 0)
            SDL_Delay((Uint32)remain_ms);
        else
            SDL_Delay(0);          /* yield; sub-millisecond tail */
        /* keep the window responsive / SDL_QUIT observed while vsyncing */
        pal_input_pump();
        now = SDL_GetPerformanceCounter();
    }
}

static u8 vga_status1(void)
{
    Uint64 now;
    Uint64 frame, vbl;

    if (g_perf_freq == 0)
        g_perf_freq = SDL_GetPerformanceFrequency();
    if (g_perf_freq == 0)
        return 0;

    frame = g_perf_freq / 70u;          /* 70 Hz VGA frame             */
    vbl   = frame / 8u;                 /* ~1.8 ms retrace window      */
    now   = SDL_GetPerformanceCounter();

    if (!g_rt_init) {
        g_rt_init = true;
        g_in_vblank = true;
        g_vblank_start = now;
        return VGA_VRETRACE_BITS;
    }

    if (g_in_vblank) {
        if (now - g_vblank_start < vbl)
            return VGA_VRETRACE_BITS;
        /* Retrace finished: complete the frame and flip the shadow. */
        g_in_vblank = false;
        present_frame();
        return 0x00;
    }

    /* Active display: wait for the next frame boundary. */
    {
        Uint64 target = g_vblank_start + frame;
        if (target <= now)
            target = now;               /* we fell behind: resynchronise */
        else
            wait_until(target);
        g_vblank_start = target;
        g_in_vblank = true;
    }
    return VGA_VRETRACE_BITS;
}

/* ------------------------------------------------------------------ */
/* ports                                                               */
/* ------------------------------------------------------------------ */

void pal_video_outport(u16 port, u8 val)
{
    switch (port) {
    case 0x3C8:                 /* PEL address write mode */
        g_widx = val;
        g_wcomp = 0;
        g_dac_write_mode = true;
        break;
    case 0x3C7:                 /* per the brief: PEL read address */
        g_ridx = val;
        g_rcomp = 0;
        g_dac_write_mode = false;
        break;
    case 0x3C9:                 /* PEL data write: R,G,B, auto-increment */
        g_pal[g_widx][g_wcomp] = (u8)(val & 0x3F);
        g_pal_dirty = true;
        if (++g_wcomp == 3) {
            g_wcomp = 0;
            g_widx = (u8)(g_widx + 1);
        }
        break;
    default:
        break;
    }
}

u8 pal_video_inport(u16 port)
{
    switch (port) {
    case 0x3BA:
    case 0x3DA:
        return vga_status1();
    case 0x3C7:
        /* DAC state register: 0x03 = write mode, 0x00 = read mode. */
        return g_dac_write_mode ? 0x03u : 0x00u;
    case 0x3C8:
        return g_widx;
    case 0x3C9: {
        u8 v = g_pal[g_ridx][g_rcomp];
        if (++g_rcomp == 3) {
            g_rcomp = 0;
            g_ridx = (u8)(g_ridx + 1);
        }
        return v;
    }
    default:
        return 0;
    }
}

/* ------------------------------------------------------------------ */
/* BIOS video (int 10h)                                                */
/* ------------------------------------------------------------------ */

/* The VGA BIOS loads a default 256-entry palette on mode 13h set: the 16
 * EGA colors, 16 gray shades, then three 72-entry hue wheels (full,
 * pastel, dark) and 8 black.  The game reprograms the DAC afterwards
 * (AH=10h AL=12h); this default covers everything drawn before that. */
static void load_default_13h_palette(void)
{
    static const u8 ega[16][3] = {
        {0,0,0},{0,0,42},{0,42,0},{0,42,42},{42,0,0},{42,0,42},{42,21,0},{42,42,42},
        {21,21,21},{21,21,63},{21,63,21},{21,63,63},{63,21,21},{63,21,63},{63,63,21},{63,63,63}
    };
    static const u8 gray[16] = {0,5,8,11,14,17,20,24,28,32,36,40,45,50,56,63};
    static const u8 prim[6][3] = {          /* the hue-wheel endpoints */
        {63,0,0},{63,63,0},{0,63,0},{0,63,63},{0,0,63},{63,0,63}
    };
    int i, e;

    for (i = 0; i < 16; i++) {
        g_pal[i][0] = ega[i][0]; g_pal[i][1] = ega[i][1]; g_pal[i][2] = ega[i][2];
    }
    for (i = 0; i < 16; i++) {
        g_pal[16 + i][0] = gray[i]; g_pal[16 + i][1] = gray[i]; g_pal[16 + i][2] = gray[i];
    }
    /* wheel 1 (32..103): the six edges R->Y->G->C->B->M->R, 12 steps each */
    for (e = 0; e < 6; e++)
        for (i = 0; i < 12; i++) {
            int idx = 32 + e * 12 + (e == 5 ? 0 : i);   /* the last edge wraps */
            int j = (e == 5) ? 11 - i : i;
            g_pal[32 + e * 12 + i][0] = (u8)(prim[e][0] + (prim[(e + 1) % 6][0] - prim[e][0]) * j / 11);
            g_pal[32 + e * 12 + i][1] = (u8)(prim[e][1] + (prim[(e + 1) % 6][1] - prim[e][1]) * j / 11);
            g_pal[32 + e * 12 + i][2] = (u8)(prim[e][2] + (prim[(e + 1) % 6][2] - prim[e][2]) * j / 11);
        }
    /* wheel 2 (104..175): pastel -- each primary to white and back */
    for (e = 0; e < 3; e++)
        for (i = 0; i < 24; i++) {
            int idx = 104 + e * 24 + i;
            int half = i < 12 ? i : 23 - i;             /* ramp up then down */
            int k = half * 63 / 11;
            g_pal[idx][0] = (u8)(e == 0 ? 63 : k);
            g_pal[idx][1] = (u8)(e == 1 ? 63 : k);
            g_pal[idx][2] = (u8)(e == 2 ? 63 : k);
        }
    /* wheel 3 (176..247): the dark wheel -- wheel 1 scaled to 2/3 */
    for (i = 0; i < 72; i++) {
        g_pal[176 + i][0] = (u8)(g_pal[32 + i][0] * 2 / 3);
        g_pal[176 + i][1] = (u8)(g_pal[32 + i][1] * 2 / 3);
        g_pal[176 + i][2] = (u8)(g_pal[32 + i][2] * 2 / 3);
    }
    /* 248-255 stay black (memset above). */
    g_pal_dirty = true;
}

void bios_video_set_mode(u8 mode)
{
    g_mode = mode;
    if (mode == 0x13)
        load_default_13h_palette();
    pal_video_on_mode_set(mode);
    if (mode == 0x03) {
        /* BIOS mode 3: blank 80x25 cells (space, attr 0x07), home the
         * cursor, and install the menu text palette.  This runs after
         * pal_video_on_mode_set()'s palette_default() so it wins. */
        text_plane_clear(0x07);
        pal_int_cursor_home();
        load_text_palette();
    } else if (mode == 0x12) {
        /* Mode 12h (640x480x16 logical): clear the index canvas and install
         * the extracted gameplay/menu palette.  Runs after
         * pal_video_on_mode_set()'s palette_default() so it wins. */
        if (vga12_canvas())
            memset(g_vga12, 0, VGA12_SIZE);
        load_level_palette();
    }
}

void bios_video_get_current_video_mode(u8 *mode_out, u8 *page_out)
{
    if (mode_out)
        *mode_out = (g_mode == 0xFF) ? 0x03u : g_mode;  /* blank default */
    if (page_out)
        *page_out = 0;
}

/* ------------------------------------------------------------------ */
/* accessors for pal/int.c (interrupt dispatch)                       */
/* ------------------------------------------------------------------ */

u8 pal_video_get_mode(void)
{
    return g_mode;
}

/* Display geometry of the current mode.  The planar table already carries the
 * four VGA modes; mode 13h and any text/unknown mode fall back to 320x200
 * (the same default present_frame() uses). */
void pal_video_get_framebuffer_size(int *w, int *h)
{
    int ww, hh;
    (void)mode_is_planar(g_mode, &ww, &hh);
    if (w) *w = ww;
    if (h) *h = hh;
}

/* Current SDL window client size; 0x0 when no window exists (headless). */
void pal_video_get_window_size(int *w, int *h)
{
    int ww = 0, hh = 0;
    if (g_win)
        SDL_GetWindowSize(g_win, &ww, &hh);
    if (w) *w = ww;
    if (h) *h = hh;
}

/* =========================================================================
 * BGI-compatible graphics driver dispatch (pal_bgi_dispatch).
 *
 * The original loads Borland's EGAVGA.BGI (embedded in segment 13E2, also
 * materialized to data/EGAVGA.BGI by rad_load_images) through its stream
 * layer and dispatches into it via `call dword ptr [0xB820h]` with a
 * function number in SI.  The BGI driver *is* the VGA hardware layer, so
 * the port replaces it here: same function numbers, same register image,
 * implemented over the VGA shadow + palette + mode state of this file.
 * Recovered game code is untouched; only the dispatch tail in the four
 * fn1AB8_call_0B820 stand-ins routes here.
 * ========================================================================= */
#include "font8.h"

/* Write one framebuffer pixel through the active mode's addressing:
 *   - mode 13h: the linear 64 KiB shadow, coordinates wrap naturally at the
 *     16-bit segment boundary (offset = (y*320 + x) & 0xFFFF);
 *   - mode 12h: the linear 640x480 index canvas with plain clipping, no wrap. */
static void drv_plot(int x, int y, u8 col)
{
    if (g_mode == 0x12) {
        if (x >= 0 && x < VGA12_W && y >= 0 && y < VGA12_H)
            vga12_canvas()[y * VGA12_W + x] = col;
    } else {
        g_shadow[drv_off(x, y)] = col;
    }
}

/* Write one framebuffer pixel; coordinates wrap naturally at the 64 KiB
 * segment boundary in mode 13h (see drv_plot). */
static void drv_pixel(int x, int y, u8 col)
{
    drv_plot(x, y, col);
}

/* Bresenham line over the linear framebuffer. */
static void drv_line(int x0, int y0, int x1, int y1, u8 col)
{
    int dxs = x1 > x0 ? x1 - x0 : x0 - x1;
    int dys = y1 > y0 ? y1 - y0 : y0 - y1;
    int sx = x0 < x1 ? 1 : -1, sy = y0 < y1 ? 1 : -1;
    int err = dxs - dys;
    for (;;) {
        drv_pixel(x0, y0, col);
        if (x0 == x1 && y0 == y1) break;
        int e2 = err * 2;
        if (e2 > -dys) { err -= dys; x0 += sx; }
        if (e2 < dxs)  { err += dxs; y0 += sy; }
    }
}

/* =========================================================================
 * Borland BGI stroked-font text (driver op-0x24/0x26 mode AL==1).
 *
 * The original hands the glyphs to the EGAVGA.BGI device font code: op-0x24
 * scales the staged size through the 11-entry chrscale table at driver
 * 0x14F0, and op-0x26 walks the glyph stroke stream drawn from the TRIP font
 * embedded in segment 13E2 (pal/font_stroke.h).  Stroke vertices are signed
 * 7-bit pairs (bit7 of each byte = opcode bit; opcode 0=end, 2=move,
 * 3=draw; 1 is unused), scaled by num/den with signed imul/idiv and drawn
 * relative to the glyph pen.  See docs for the recovered driver addresses
 * (0x1437 op-0x24, 0x18C9 + 0x1766 op-0x26, 0x361E/0x3645/0x1922/0x1955
 * pen pre-adjust).
 * ========================================================================= */

/* Driver chrscale table (EGAVGA.BGI 0x14F0).  Index 10 = {4,1} is the
 * large-size extension the driver clamps sizes >= 10 onto. */
static const u8 g_chrscale[11][2] = {
    {0,0},{3,5},{2,3},{3,4},{1,1},{4,3},{5,3},{2,1},{5,2},{3,1},{4,1}
};

static int stroke_first(void)  { return (int)g_trip_font[4]; }
static int stroke_nchars(void) { return (int)g_trip_font[1] | ((int)g_trip_font[2] << 8); }
static int stroke_soff(void)   { return (int)g_trip_font[5] | ((int)g_trip_font[6] << 8); }

/* Width-table entry for a character (0 outside the font's range). */
static int stroke_width(int ch)
{
    int idx = ch - stroke_first();
    if (idx < 0 || idx >= stroke_nchars())
        return 0;
    return (int)g_trip_font[16 + 2 * stroke_nchars() + idx];
}

/* ascender - descender: the em height the driver centres vertically. */
static int stroke_em(void)
{
    return (int)(s8)g_trip_font[8] - (int)(s8)g_trip_font[10];
}

/* Sign-extend the signed 7-bit coordinate field. */
static int stroke_s7(u8 b)
{
    int v = b & 0x7F;
    return (v & 0x40) ? v - 0x80 : v;
}

/* Driver 0x189B/0x18B2: signed *num, then signed /den. */
static int stroke_scale(int v, int num, int den)
{
    if (num == 0)
        return 0;
    if (num != 1)
        v *= num;
    if (den != 0 && den != 1)
        v /= den;
    return v;
}

/* Draw one glyph with the pen as origin and advance the pen by the glyph's
 * terminating move (driver 0x1766; END handler 0x17B6 -> 0x1983). */
static void stroke_glyph(int ch, int *pen_x, int *pen_y, int num, int den, u8 color)
{
    int idx = ch - stroke_first();
    int off, cx = 0, cy = 0;
    const u8 *p;
    if (idx < 0 || idx >= stroke_nchars())
        return;                                     /* out of range: no advance */
    off = g_trip_font[16 + 2 * idx] | (g_trip_font[17 + 2 * idx] << 8);
    p = g_trip_font + off + stroke_soff();
    for (;;) {
        u8 b0 = p[0], b1 = p[1];
        int op;
        p += 2;
        op = ((b0 >> 7) & 1) * 2 + ((b1 >> 7) & 1);
        if (op == 0) {                              /* END: advance pen */
            *pen_x += cx;
            *pen_y -= cy;
            return;
        }
        if (op == 1)                                /* unused: ignore */
            continue;
        {
            int nx = stroke_scale(stroke_s7(b0), num, den);
            int ny = stroke_scale(stroke_s7(b1), num, den);
            if (op == 2) {                          /* MOVE */
                cx = nx; cy = ny;
            } else {                                /* DRAW */
                drv_line(*pen_x + cx, *pen_y - cy,
                         *pen_x + nx, *pen_y - ny, color);
                cx = nx; cy = ny;
            }
        }
    }
}

/* =========================================================================
 * Loading-console band cleanup (workaround for a recovered-code gap).
 *
 * fn0C74_00B2 writes the loader's progress-bar cell row with driver op 0x12
 * (filled rectangle) at canvas y 0x1D5..0x1DF (469..479), 5 px per cell,
 * using the fill colour the game staged with fn1AB8_1175(0x0F, 0x01) ->
 * index 15.  That happens while fn13E2_003B has the DAC blanked, so on the
 * real adapter those pixels are black when written.  The recovered menu
 * painter never repaints that row, whereas the original evidently does (the
 * DOSBox menu/level captures show black there, not white).  Once
 * fn13E2_0080/fn13E2_00FB installs the real palette (op 0x1A, index 15 =
 * white) those stale bar pixels would become a spurious full-width white
 * line.  Clear only index-15 pixels in the one console row: the level's
 * white crate lives at y155..176 and the mouse arrow is composited at
 * present time, so nothing legitimate is ever index 15 here. */
static void clear_console_band_15(void)
{
    u8 *c;
    int y, x;
    if (g_mode != 0x12)
        return;
    c = vga12_canvas();
    for (y = 0x1D5; y <= 0x1DF && y < VGA12_H; y++)
        for (x = 0; x < VGA12_W; x++)
            if (c[y * VGA12_W + x] == 15)
                c[y * VGA12_W + x] = 0;
}

u16 pal_bgi_dispatch(u16 si, u16 *regs)
{
    u16 ax = regs[0], bx = regs[1], cx = regs[2], dx = regs[3];
    u16 di = regs[5];

    if (getenv("RAD_BGI_LOG"))
        fprintf(stderr, "BGI si=%02x ax=%04x bx=%04x cx=%04x dx=%04x si_=%04x di=%04x es=%04x\n",
                si, ax, bx, cx, dx, si, di, regs[6]);

    switch (si) {
    case 0x00:
        if (((u8)ax) == 0x01) {
            /* AL=1 (fn1AB8_1C93): CX = screen rows; caller does cx-1. */
            regs[2] = 480;
        } else {
            /* AL=0 (fn1AB8_1855 driver install): ES:BX = a 32-byte MODE
             * INFO block.  word[1]=640 (max x), word[2]=480 (max y); the
             * game copies 19 bytes to DGROUP 0xB7C0, so +2/+4 land at the
             * clip gates 0xB7C2/0xB7C4.  Staged at 0xBD20, clear of the
             * 0x3A/AL=1 info record at 0xBD00 and the 19 bytes at 0xBD11. */
            u8 *mi = g_dgroup + 0xBD20;
            memset(mi, 0, 32);
            *(u16 *)(mi + 2) = 640;          /* word[1] = max x = 640 */
            *(u16 *)(mi + 4) = 480;          /* word[2] = max y = 480 */
            regs[1] = 0xBD20;               /* BX = offset */
            regs[6] = 0x2014;               /* ES = DGROUP */
        }
        return 1;
    case 0x02:                              /* init/display setup */
        /* The real BGI driver's display init programs the adapter into the
         * game's 640x480x16 graphics mode (VGA mode 12h).  The port has no
         * planar hardware layer, so activate the logical mode-12h canvas
         * here.  Ordering is safe: on the startup path this runs before the
         * title loader's explicit fn0C43_0000(0x13) mode-13h set, and at the
         * menu/level transition it is the only video-mode set. */
        bios_video_set_mode(0x12);
        /* The driver publishes its LOGICAL screen dimensions; fn1AB8_0F93
         * validates clip windows against DGROUP [0xB7C2] (max x) and
         * [0xB7C4] (max y).  The game's windows reach x=454/y=454, so the
         * logical space is 640x480. */
        *(u16 *)(g_dgroup + 0xB7C2) = 640;
        *(u16 *)(g_dgroup + 0xB7C4) = 480;
        regs[0] = 0; regs[1] = 0; regs[2] = 0; regs[3] = 0;
        return 1;
    case 0x04:                              /* get params */
        regs[0] = 0; regs[1] = 0; regs[2] = 0; regs[3] = 0;
        return 1;
    case 0x06:                              /* set video mode: the game's mode byte */
        bios_video_set_mode(g_ext_mode ? *g_ext_mode : (u8)ax);
        return 1;
    case 0x08:                              /* move pen: AX = x, BX = y (no drawing) */
        g_pen_x = ax + g_org_x;
        g_pen_y = bx + g_org_y;
        return 1;
    case 0x0A: {                            /* line from pen to (AX,BX) */
        int nx = ax + g_org_x, ny = bx + g_org_y;
        drv_line(g_pen_x, g_pen_y, nx, ny, g_drv_color);
        g_pen_x = (u16)nx;
        g_pen_y = (u16)ny;
        return 1;
    }
    case 0x12: {                            /* filled rectangle (AX,BX)-(CX,DX) */
        /* Driver fn 0x12 handler d2526() builds a four-corner request block
         * at driver 0x0463 -- (ax,bx+1),(ax,dx),(cx+1,dx),(cx+1,bx+1) -- and
         * forwards it to the scanline-fill handler (driver fn 0x0E).  It is
         * the FILLED RECTANGLE behind the menu window and every button, and
         * it uses the fill (background) color, not the line color: in
         * fn0800_1315/fn0800_19E1 it immediately precedes the 0x0C bevel
         * lines, which are the only calls that consume the line color. */
        int x0 = ax, y0 = bx + 1, x1 = cx + 1, y1 = dx;
        int x, y, t;
        if (x0 > x1) { t = x0; x0 = x1; x1 = t; }
        if (y0 > y1) { t = y0; y0 = y1; y1 = t; }
        for (y = y0; y <= y1; y++)
            for (x = x0; x <= x1; x++)
                drv_pixel(x, y, g_fill_color);
        return 1;
    }
    case 0x0C: {                            /* line between (AX,BX) and (CX,DX) */
        /* Driver helper 0x189 translates a point by the viewport origin
         * ([0x84]/[0x86]; the port's g_org_x/g_org_y).  The 0x0C handler
         * applies it to BOTH endpoints and draws a straight line with the
         * current colour, using the same plotting facility as 0x0A/0x12.
         * It does not move the pen. */
        int x0 = ax + g_org_x, y0 = bx + g_org_y;
        int x1 = cx + g_org_x, y1 = dx + g_org_y;
        drv_line(x0, y0, x1, y1, g_drv_color);
        return 1;
    }
    case 0x14: {                            /* shadow-to-block capture: ES:BX = {w,h}+payload */
        u8 *cmd;
        u16 w, h;
        u16 src_off;
        u32 i, n;
        if (regs[6] == 0)
            return 1;                       /* no segment staged: skip capture */
        cmd = (u8 *)far_ptr(((u32)regs[6] << 16) | (u32)bx);
        w = cmd[0] | (cmd[1] << 8);
        h = cmd[2] | (cmd[3] << 8);
        n = (u32)w * (u32)h;
        if (g_mode == 0x12) {
            /* Mode 12h: capture into the PLANAR row-interleaved sprite
             * layout the original driver produces -- after the {w,h} header,
             * (h+1) rows x 4 groups of ceil(w/8) bytes plus a 2-byte
             * trailer, i.e. the same 4*wbr*(h+1)+2 payload op 0x36 blits
             * back and the size fn1AB8_19A6 allocates. */
            u8 *canvas = vga12_canvas();
            u16 wbr = (u16)((w + 7) >> 3);
            u32 plane_sz = (u32)wbr * ((u32)h + 1);
            memset(cmd + 4, 0, plane_sz * 4 + 2);   /* rows + trailer */
            for (i = 0; i < n; i++) {
                int xx = (int)g_pen_x + (w ? (int)(i % w) : 0);
                int yy = (int)g_pen_y + (w ? (int)(i / w) : 0);
                u8 idx;
                if (xx < 0 || xx >= VGA12_W ||
                    yy < 0 || yy >= VGA12_H)
                    continue;       /* out-of-bounds samples read as 0 */
                idx = canvas[yy * VGA12_W + xx];
                if (idx == 0)
                    continue;
                for (u8 p = 0; p < 4; p++) {
                    if (!((idx >> p) & 1))
                        continue;
                    cmd[4 + p * plane_sz + (u32)(i / w) * wbr +
                        (u32)(i % w >> 3)] |=
                        (u8)(0x80u >> (i % w & 7));
                }
            }
            return 1;
        }
        src_off = drv_off(g_pen_x, g_pen_y);
        for (i = 0; i < n; i++)
            cmd[4 + i] = g_shadow[(src_off + i) & 0xFFFFu];
        return 1;
    }
    case 0x34: {                            /* block transfer: ES:BX = {w,h} block, CX/DX = origin, DI = height */
        /* fn1AB8_1E6B writes {width,height} = (xmax-xmin, ymax-ymin) into the
         * block at ES:BX and dispatches si=0x34 with CX/DX = the rectangle
         * origin and DI = the height.
         *
         * Mode 12h: this is the BGI getimage capture (see the branch below):
         * it copies the inclusive (h+1)x(w+1) screen rectangle into the block
         * in the planar row-interleaved layout op 0x36 reads back.  The game
         * uses the capture+putimage pair for its save-under / scroll
         * animations (fn0C74_05B8's descent, fn0C74_2AD9's march,
         * fn0C74_2BBD's sprite grow), which is why each step must overwrite
         * the previous rectangle instead of leaving a trail.
         *
         * Mode 13h (and any other mode) keeps the old offscreen block fill
         * (the title path was verified pixel-perfect with it). */
        u8 *cmd = (u8 *)far_ptr(((u32)regs[6] << 16) | (u32)bx);
        u16 w = cmd[0] | (cmd[1] << 8);
        u16 h = cmd[2] | (cmd[3] << 8);
        if (g_mode == 0x12) {
            /* Mode 12h: 0x34 is a screen CAPTURE (BGI getimage), not a
             * fill.  fn1AB8_1E6B stores {w,h} = (xmax-xmin, ymax-ymin) in
             * the block and passes CX/DX = the rectangle origin and DI =
             * the height; the driver copies the inclusive (h+1)x(w+1)
             * rectangle at (CX,DX) into the block in the SAME planar
             * row-interleaved layout op 0x36 reads back -- so a captured
             * block blitted with 0x36 round-trips exactly.  This is the
             * save-under used by the robot/terrain descent and the
             * scroll animations (fn0C74_05B8, fn0C74_2AD9, fn0C74_2BBD). */
            u8 *canvas = vga12_canvas();
            u16 wbr = (u16)((w + 7) >> 3);
            u32 plane_sz = (u32)wbr * ((u32)h + 1);
            int x0 = cx + g_org_x, y0 = dx + g_org_y;
            u32 y, x;
            memset(cmd + 4, 0, plane_sz * 4 + 2);
            for (y = 0; y <= (u32)h; y++) {
                int yy = y0 + (int)y;
                for (x = 0; x <= (u32)w; x++) {
                    int xx = x0 + (int)x;
                    u8 idx;
                    if (xx < 0 || xx >= VGA12_W || yy < 0 || yy >= VGA12_H)
                        continue;
                    idx = canvas[yy * VGA12_W + xx];
                    if (idx == 0)
                        continue;
                    for (u8 p = 0; p < 4; p++) {
                        if (!((idx >> (3 - p)) & 1))
                            continue;
                        cmd[4 + y * wbr * 4 + p * wbr + (x >> 3)] |=
                            (u8)(0x80u >> (x & 7));
                    }
                }
            }
            (void)di;
            return 1;
        }
        {
            u32 n = (u32)w * (u32)h;
            if (n > 640u * 480u)
                n = 640u * 480u;
            memset(cmd + 4, g_fill_color, n);
        }
        (void)di; (void)cx; (void)dx;
        return 1;
    }
    case 0x1A: {                            /* set DAC entry: AX=0x8000|idx, BX=R, CX=G, DX=B */
        /* Recovered as fn1AB8_1CBA (menu/level palette loop) and
         * fn1AB8_1CD7 (read back).  fn13E2_0080 programs the MENU palette
         * (index 8 = 0x15 grey: the drop shadows) and fn13E2_00FB the LEVEL
         * palette (index 8 = 0: no grey) from the same DGROUP table; both
         * set index 15 = white.  AX==0xFFFF is fn1AB8_1CA4's attribute-
         * controller path, which has no DAC/pixel model here. */
        if (ax == 0xFFFF)
            return 1;
        if (ax & 0x8000) {
            u8 idx = (u8)(ax & 0xFF);
            u8 r = (u8)(bx & 0x3Fu), g = (u8)(cx & 0x3Fu), b = (u8)(dx & 0x3Fu);
            g_pal[idx][0] = r;
            g_pal[idx][1] = g;
            g_pal[idx][2] = b;
            g_pal_dirty = true;
            /* The palette loops call index 15 last; at that instant the real
             * palette replaces the blanked one, so drop the loader's stale
             * index-15 progress-bar pixels (see clear_console_band_15). */
            if (idx == 15 && (r | g | b) != 0)
                clear_console_band_15();
        }
        return 1;
    }
    case 0x1C:                              /* set text buffer ptr: no-op */
        return 1;
    case 0x1E:                              /* set current draw color: AL = color */
        /* The game stages a 16-bit word whose HIGH byte is the FILL
         * (background) color and whose LOW byte is the LINE (foreground)
         * color: fn1AB8_1C32() stores the low byte at [0xB83E] and re-emits
         * (fill<<8)|low, while fn1AB8_1D5B() stores the fill byte at
         * [0xB83F].  The menu proves it: the window fill is preceded by
         * 0x0300 (fill=3 teal, line=0 black) and the button bevel lines by
         * 0x030B (fill=3, line=11 bright cyan), exactly the reference's teal
         * window / cyan bevels.  Driver op 0x12 (filled rectangle) and op
         * 0x34 (offscreen block fill) therefore take the HIGH nibble, while
         * the line ops (0x0A/0x0C) and the text op (0x26) take the LOW one. */
        g_drv_color  = (u8)(ax & 0x0F);
        g_fill_color = (u8)((ax >> 8) & 0x0F);
        return 1;
    case 0x20:                              /* write char: ah=attr? al=char, bx=pos? */
    case 0x22: {                            /* write char + attributes */
        u8 ch = (u8)(ax & 0xFF);
        u16 x = bx & 0xFF, y = cx & 0xFF;   /* empirical: bx=col, cx=row */
        u8 attr = (u8)(dx & 0xFF);
        if (ch >= 32 && ch < 127 && g_mode == 0x13) {
            const u8 *gl = pal_font8[ch - 32];
            for (u8 row = 0; row < 8; row++) {
                u32 yy = (u32)y * 8 + row;
                if (yy >= 200) break;
                for (u8 col = 0; col < 8; col++) {
                    u32 xx = (u32)x * 8 + col;
                    if (xx >= 320) break;
                    g_shadow[yy * 320 + xx] = (gl[row] >> col) & 1 ? attr : (u8)(attr & 0);
                }
            }
        }
        return 1;
    }
    case 0x24:                              /* set text params: AX, BX, CX */
        /* Driver 0x1437 (file 1AB8:34CA): store the three size words, reset
         * the glyph width and mode flags, then branch on AL.
         *   AL == 0 -> 8x8 bitmap metrics.  The driver forces BX=CX=8 when
         *             BX==0 (0x3561), which is how the HUD's staged
         *             (0,0,0) becomes the 8-px bitmap metrics the reference
         *             shows (pitch 8, top = pen_y-4).  Without this the HUD
         *             fell back to a 1x8 glyph with the old 11-px pitch.
         *   AL == 1 -> wide/stroke metrics (menu buttons and the RAD logo):
         *             the original hands the glyph to the EGAVGA.BGI device
         *             font, which the port does not emulate; keep the old
         *             bitmap fallback so those screens do not regress.
         *   AL == 2 -> compact half-size (the menu's "Version enregistree :
         *             103 tableaux", 6-px cells / 7-px rows), see 0x26. */
        g_txt_ax = ax;                      /* [0x1400] */
        g_txt_sx = bx;                      /* [0x1404] */
        g_txt_sy = cx;                      /* [0x1406] */
        g_txt_gw = 8;                       /* [0x1408] */
        g_txt_flag_a = 0;                   /* [0x140A] */
        g_txt_wide = 0;                     /* [0x99] */
        g_txt_mode = 0;
        if ((ax & 0xFF) != 0) {
            g_txt_wide = 1;
            g_txt_gw = bx;
            g_txt_mode = ((ax & 0xFF) == 2) ? 2 : 1;
        } else {
            /* AL==0 bitmap path: the driver's 0x3561 clamp. */
            if (g_txt_sx == 0)
                g_txt_sx = 8;
            if (g_txt_sy == 0)
                g_txt_sy = 8;
        }
        return 1;
    case 0x26: {                            /* draw text string: ES:BX chars, CX count */
        /* The game's wrapper (1AB8:1D82) stages r.cx = *ptr / r.bx = ptr+1,
         * so ES:BX already points just past the Pascal length byte and CX
         * is the character count.  Chars index the CP437 8x8 font.
         *
         * Placement follows the recovered driver:
         *   0x34A0 calls 0x35BB (pen pre-adjust) then 0x35ED (render).
         *   0x361E (horizontal) reads the op-0x2A horizontal code [0x1402]:
         *       0 -> left at the pen
         *       1 -> pen_x - ((count*txt_sx)/2 - 1)
         *       2 -> pen_x - count*txt_sx
         *   0x3645 (vertical) reads the op-0x2A vertical code [0x1403]:
         *       0 -> pen_y - txt_sy
         *       1 -> pen_y - txt_sy/2
         *       2 -> pen_y (top)
         *   For the HUD the staged op-0x24 (0,0,0) clamps to txt_sx=txt_sy=8
         *   (see 0x24 above), giving pitch 8 and top = pen_y-4, exactly the
         *   reference geometry. */
        u8 *str = (u8 *)far_ptr(((u32)regs[6] << 16) | (u32)bx);
        u16 count = cx;
        u16 ax_hi = (u16)((g_txt_ax >> 8) & 0xFFu);
        u16 hor = (u16)((g_txt_align >> 8) & 0xFFu);   /* [0x1402] */
        u16 ver = (u16)(g_txt_align & 0xFFu);          /* [0x1403] */
        int adv, gw, gh, sx, sy, row, c, left, top;
        u16 i;

        if (g_txt_mode == 1) {
            /* Stroke-font text (the RAD logo and the button labels).  The
             * driver scales the staged size through chrscale[min(size,10)]
             * and renders the TRIP glyphs; the pen pre-adjust uses the
             * string's metric width W and em height H, both scaled. */
            int sz = (int)g_txt_sx;
            int num, den, pen_x, pen_y, W, H, ws = 0;
            num = den = 0;
            if (sz >= 11)
                sz = 10;
            num = g_chrscale[sz][0];
            den = g_chrscale[sz][1];
            for (i = 0; i < count; i++)
                ws += stroke_width(str[i]);
            W = (den != 0) ? (ws * num) / den : 0;
            H = (den != 0) ? (stroke_em() * num) / den : 0;
            pen_x = (int)g_pen_x;
            pen_y = (int)g_pen_y;
            if (hor == 1) pen_x -= W / 2 - 1;
            else if (hor == 2) pen_x -= W;
            if (ver == 1) pen_y += H / 2;
            else if (ver == 2) pen_y += H;
            for (i = 0; i < count; i++) {
                if (str[i] == 0x00)                 /* driver stops at NUL */
                    break;
                stroke_glyph(str[i], &pen_x, &pen_y, num, den, g_drv_color);
            }
            g_pen_x = (u16)pen_x;
            g_pen_y = (u16)pen_y;
            return 1;
        } else if (g_txt_mode == 2) {
            /* Compact half-size metrics (op-0x24 AL==2, the menu's version
             * line): 6-px cells, 6 of the 8 font columns and 7 of the 8 rows
             * -- the reference's ~5.8 px/char, 7 px-tall band -- centred on
             * the pen. */
            adv = 6; gw = 6; gh = 7; sx = sy = 1;
            left = (int)g_pen_x;
            if (hor != 0) {
                int a = count * adv;
                if (hor == 1) a = a / 2 - 1;
                left -= a;
            }
            top = (int)g_pen_y;
            if (ver != 2) top -= (ver == 1) ? ((int)g_txt_sy / 2)
                                            : (int)g_txt_sy;
        } else {
            /* 8x8 bitmap metrics (HUD/status text). */
            sx = sy = 1; adv = (int)g_txt_sx; gw = 8; gh = 8;
            left = (int)g_pen_x;
            if (ax_hi == 1) {
                int a = (int)g_txt_sy;
                if (hor == 1) a = a / 2 - 1;
                else if (hor == 0) a = 0;
                left -= a;
            } else if (hor != 0) {
                int a = (int)(count * g_txt_sx);
                if (hor == 1) a = a / 2 - 1;
                left -= a;
            }
            top = (int)g_pen_y;
            {
                int a = (ax_hi == 1) ? (int)(count * g_txt_sx)
                                     : (int)g_txt_sy;
                if (ver == 2) a = 0;
                else if (ver == 1) a /= 2;
                top -= a;
            }
        }

        /* Render.  Each font pixel becomes an sx x sy rectangle at
         * left + i*adv + col*sx, top + row*sy.  Only skip when the whole run
         * lies outside the canvas: centred text may legitimately start at a
         * negative x while still overlapping the screen. */
        {
            int run_w = (int)count * adv;
            int x1 = left + run_w - 1, y1 = top + gh - 1;
            int visible = !(g_mode == 0x12 &&
                            (x1 < 0 || left >= VGA12_W ||
                             y1 < 0 || top >= VGA12_H));
            if (visible) {
                for (i = 0; i < count; i++) {
                    const u8 *gl = g_font8x8[str[i]];
                    int gx = left + (int)i * adv;
                    for (row = 0; row < gh; row++) {
                        u8 bits = gl[row];
                        if (!bits)
                            continue;
                        for (c = 0; c < gw; c++) {
                            int bx0, by0, xx, yy;
                            if (!(bits & (0x80 >> c)))
                                continue;
                            bx0 = gx + c * sx;
                            by0 = top + row * sy;
                            for (yy = 0; yy < sy; yy++)
                                for (xx = 0; xx < sx; xx++)
                                    drv_pixel(bx0 + xx, by0 + yy, g_drv_color);
                        }
                    }
                }
            }
            /* Step 3: advance the pen (the original re-moves it through the
             * 0x08 chain; advancing here matches the observable behavior). */
            g_pen_x = (u16)(left + run_w);
        }
        return 1;
    }
    case 0x28: {                            /* string width / height query: CX = count */
        /* Driver 0x1713 / wrapper 0x01DE: BX = [0x160e] (width), CX =
         * [0x160c] (height).  fn1AB8_1E0B() reads BX and
         * fn1AB8_1783()/fn1AB8_1E26() read CX, so both must describe the
         * font the port actually draws.
         *   bitmap (mode 0): width = count*txt_sx, height = txt_sy -- the
         *     driver's wrapper computes exactly cx*[0x1404] / [0x1406].
         *   compact (mode 2): width = count*6, height = 7.
         *   stroke  (mode 1): width = sum(glyph widths)*num/den, height =
         *     (ascender-descender)*num/den -- driver 0x1713 -> 0x171F. */
        u16 n = cx;
        u16 w, h;
        if (g_txt_mode == 2) {
            w = (u16)(n * 6u);
            h = 7;
        } else if (g_txt_mode == 1) {
            u8 *sstr = (u8 *)far_ptr(((u32)regs[6] << 16) | (u32)bx);
            int sz = (int)g_txt_sx, num, den;
            u32 ws = 0;
            u16 i;
            if (sz >= 11)
                sz = 10;
            num = g_chrscale[sz][0];
            den = g_chrscale[sz][1];
            for (i = 0; i < n; i++)
                ws += (u32)stroke_width(sstr[i]);
            w = (den != 0) ? (u16)((ws * (u32)num) / (u32)den) : 0;
            h = (den != 0) ? (u16)(((u32)stroke_em() * (u32)num) / (u32)den) : 0;
        } else {
            w = (u16)(n * g_txt_sx);
            h = g_txt_sy;
        }
        regs[0] = w;                        /* AX */
        regs[1] = w;                        /* BX = rendered string width */
        regs[2] = h;                        /* CX = glyph height */
        return 1;
    }
    case 0x2A:                              /* set text justify (driver 0x2295) */
        /* The recovered handler stores AH at [0x1402] (horizontal justify
         * code) and AL at [0x1403] (vertical justify code), which 0x26's
         * pen pre-adjust (0x361E/0x3645) then consumes.  Before this the
         * port dropped the op entirely, so every string was left-aligned. */
        g_txt_align = ax;
        return 1;
    case 0x2E: {                            /* get pixel: AX = x, BX = y -> DX/AL */
        int x = ax + g_org_x, y = bx + g_org_y;
        u8 v;
        if (g_mode == 0x12) {
            v = (x >= 0 && x < VGA12_W && y >= 0 && y < VGA12_H)
                ? vga12_canvas()[y * VGA12_W + x] : 0;
        } else {
            v = g_shadow[drv_off(x, y)];
        }
        regs[3] = v;                        /* DL: caller fn1AB8_1E3C reads DL */
        regs[0] = v;
        return 1;
    }
    case 0x30:                              /* put pixel: AX = x, BX = y, DL = color */
        drv_plot(ax + g_org_x, bx + g_org_y, (u8)dx);
        return 1;
    case 0x32:                              /* set/get far pointer (window) */
        return 1;
    case 0x36: {                            /* blit sprite/block: ES:BX = {w,h}+pixels (COPY_PUT) */
        /* ES:BX is a real-mode segment:offset pointer, so the source offset
         * is 16-bit and wraps around the 64 KiB segment (the flat far_ptr
         * arena stands in for that segment). */
        u8 *seg = (u8 *)far_ptr((u32)regs[6] << 16);
        u16 w = seg[(bx + 0) & 0xFFFFu] | (seg[(bx + 1) & 0xFFFFu] << 8);
        u16 h = seg[(bx + 2) & 0xFFFFu] | (seg[(bx + 3) & 0xFFFFu] << 8);
        u32 n = (u32)w * (u32)h;
        if (g_mode == 0x12) {
            /* Mode 12h: the payload is PLANAR and ROW-INTERLEAVED -- each of
             * the (h+1) rows is 4 groups of ceil(w/8) bytes, group p = bit
             * plane (3-p).  The payload carries h+1 rows: the record size
             * computed by the original's own size calculator fn1AB8_19A6 is
             * 4*wbr*(h+1)+6 (e.g. a 21x21 RAD.STR tile is 4 + 4*3*22 + 2 =
             * 270 = the 54000/200 record stride, and a 43x43 RAD.DES frame is
             * 4 + 4*6*44 + 2 = 1062), so the last (row h) is real image data
             * -- the tile's bottom/mortar row.  The trailing 2 bytes are an
             * unused trailer.
             *
             * This is a BGI putimage COPY_PUT, NOT a transparent sprite
             * blit: every one of the (h+1)x(w+1) pixels is written, including
             * colour 0.  That is exactly what makes the menu's walking robot
             * and the level's robot descent animate cleanly -- each step
             * overwrites the whole rectangle, so the previous position is
             * erased (a 0-transparent blit left a full smear of the robot on
             * both screens, and the DOSBox captures show none).  Blit into the
             * 640x480 index canvas at (dest_x + x, dest_y + y), clipping out
             * of bounds. */
            int dx0 = cx + g_org_x, dy0 = dx + g_org_y;
            u16 wbr = (u16)((w + 7) >> 3);
            u8 *canvas = vga12_canvas();
            if (w) {
                u32 rows = (u32)h + 1;      /* h+1 payload rows            */
                u32 cols = (u32)w + 1;      /* wbr*8 bits stored per row   */
                if (cols > (u32)wbr * 8u)
                    cols = (u32)wbr * 8u;
                for (u32 y = 0; y < rows; y++) {
                    int yy = dy0 + (int)y;
                    if (yy < 0 || yy >= VGA12_H)
                        continue;
                    for (u32 x = 0; x < cols; x++) {
                        int xx = dx0 + (int)x;
                        u8 idx;
                        if (xx < 0 || xx >= VGA12_W)
                            continue;
                        idx = 0;
                        for (u8 p = 0; p < 4; p++) {
                            u8 byte = seg[(bx + 4 + y * wbr * 4 +
                                           p * wbr + (x >> 3)) & 0xFFFFu];
                            idx |= (u8)(((byte >> (7 - (x & 7))) & 1) << (3 - p));
                        }
                        canvas[yy * VGA12_W + xx] = idx;
                    }
                }
            }
            return 1;
        }
        {
            u16 dest = drv_off(cx + g_org_x, dx + g_org_y);
            for (u32 i = 0; i < n; i++) {
                u8 v = seg[(bx + 4 + i) & 0xFFFFu];
                if (v)
                    g_shadow[(dest + i) & 0xFFFFu] = v;
            }
        }
        return 1;
    }
    case 0x38: {                            /* set viewport / clip window */
        int min_x = ax & 0x7FFF, min_y = bx;
        int max_x = cx, max_y = dx;
        if (min_x > max_x) { int t = min_x; min_x = max_x; max_x = t; }
        if (min_y > max_y) { int t = min_y; min_y = max_y; max_y = t; }
        g_org_x = min_x;                    /* viewport origin (translate amounts) */
        g_org_y = min_y;
        g_clip_x0 = (u16)min_x; g_clip_y0 = (u16)min_y;
        g_clip_x1 = (u16)max_x; g_clip_y1 = (u16)max_y;
        return 1;
    }
    case 0x3A:                              /* get screen dimensions */
        regs[2] = 320;                      /* 1C4A returns cx */
        regs[1] = 200;                      /* 1C5A returns bx */
        if (((u8)regs[0]) == 0x01) {
            /* AL=1: ES:BX = 17-byte driver info record (fn1AB8_1C6A copies
             * it to DGROUP 0xB87A; fn1AB8_129A parses [0]=name length,
             * [1..] name characters).  Stage the EGAVGA record in DGROUP
             * free space (highest converted offset is 0xBB08) and hand out
             * DGROUP -- the only registered data segment. */
            u8 *blk = g_dgroup + 0xBD00;
            blk[0] = 0x06;                  /* Pascal name length */
            memcpy(blk + 1, "EGAVGA", 6);
            memset(blk + 7, 0, 10);
            regs[1] = 0xBD00;               /* BX = offset */
            regs[6] = 0x2014;               /* ES = DGROUP */
        }
        return 1;
    default:
        return 0;                           /* unknown number */
    }
}
