/* input.c — RAD Linux port: SDL2 keyboard -> BIOS/DOS keyboard services.
 *
 * The recovered RAD code reads keys only through:
 *   int 16h AH=00  get keystroke   -> bios_kbd_get_keystroke()  (AL=ascii, AH=scan)
 *   int 16h AH=01  check keystroke -> bios_kbd_check_keystroke() (ZF semantics)
 *   int 21h AH=06 DL=FF direct console input -> msdos_direct_console_input()
 *
 * DECISIONS:
 *   - One shared FIFO is fed by SDL_KEYDOWN and drained by both BIOS and the
 *     DOS direct-console call, exactly as a single 8042/BIOS keyboard buffer
 *     would be.
 *   - SDL scancodes (USB HID) are translated to the x86 set-1 "make" codes
 *     that the BIOS reports in AH.  Extended keys (arrows, F1..F10, Home/
 *     End/PgUp/PgDn/Ins/Del, keypad +/-) report ASCII 0x00 in AL and their
 *     set-1 code in AH, i.e. *ascii==0.
 *   - Shift toggles letter and digit case.  Ctrl/Alt are ignored for now
 *     (the brief says Shift/Ctrl state is not needed initially).
 *   - Key-repeat events from SDL are queued like any other keydown so that
 *     held keys auto-repeat, matching BIOS typematic behaviour.
 *   - SDL_QUIT (and the window close button) latches the quit flag read by
 *     pal_quit_requested().
 */
#include <SDL2/SDL.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "pal.h"
#include "pal_internal.h"

#define KFIFO_SIZE 64

typedef struct {
    SDL_Scancode sc;
    u8 scan;      /* x86 set-1 make code reported in AH */
    u8 a0;        /* AL with no modifier (0 = extended key) */
    u8 a1;        /* AL with Shift held */
} KeyMap;

/* Ordered only for readability; lookup is a linear scan of this small table. */
static const KeyMap keymap[] = {
    { SDL_SCANCODE_ESCAPE,       0x01, 0x1B, 0x1B },
    { SDL_SCANCODE_1,            0x02, '1',  '!'  },
    { SDL_SCANCODE_2,            0x03, '2',  '@'  },
    { SDL_SCANCODE_3,            0x04, '3',  '#'  },
    { SDL_SCANCODE_4,            0x05, '4',  '$'  },
    { SDL_SCANCODE_5,            0x06, '5',  '%'  },
    { SDL_SCANCODE_6,            0x07, '6',  '^'  },
    { SDL_SCANCODE_7,            0x08, '7',  '&'  },
    { SDL_SCANCODE_8,            0x09, '8',  '*'  },
    { SDL_SCANCODE_9,            0x0A, '9',  '('  },
    { SDL_SCANCODE_0,            0x0B, '0',  ')'  },
    { SDL_SCANCODE_MINUS,        0x0C, '-',  '_'  },
    { SDL_SCANCODE_EQUALS,       0x0D, '=',  '+'  },
    { SDL_SCANCODE_BACKSPACE,    0x0E, 0x08, 0x08 },
    { SDL_SCANCODE_TAB,          0x0F, 0x09, 0x09 },
    { SDL_SCANCODE_Q,            0x10, 'q',  'Q'  },
    { SDL_SCANCODE_W,            0x11, 'w',  'W'  },
    { SDL_SCANCODE_E,            0x12, 'e',  'E'  },
    { SDL_SCANCODE_R,            0x13, 'r',  'R'  },
    { SDL_SCANCODE_T,            0x14, 't',  'T'  },
    { SDL_SCANCODE_Y,            0x15, 'y',  'Y'  },
    { SDL_SCANCODE_U,            0x16, 'u',  'U'  },
    { SDL_SCANCODE_I,            0x17, 'i',  'I'  },
    { SDL_SCANCODE_O,            0x18, 'o',  'O'  },
    { SDL_SCANCODE_P,            0x19, 'p',  'P'  },
    { SDL_SCANCODE_LEFTBRACKET,  0x1A, '[',  '{'  },
    { SDL_SCANCODE_RIGHTBRACKET, 0x1B, ']',  '}'  },
    { SDL_SCANCODE_RETURN,       0x1C, 0x0D, 0x0D },
    { SDL_SCANCODE_LCTRL,        0x1D, 0x00, 0x00 },
    { SDL_SCANCODE_A,            0x1E, 'a',  'A'  },
    { SDL_SCANCODE_S,            0x1F, 's',  'S'  },
    { SDL_SCANCODE_D,            0x20, 'd',  'D'  },
    { SDL_SCANCODE_F,            0x21, 'f',  'F'  },
    { SDL_SCANCODE_G,            0x22, 'g',  'G'  },
    { SDL_SCANCODE_H,            0x23, 'h',  'H'  },
    { SDL_SCANCODE_J,            0x24, 'j',  'J'  },
    { SDL_SCANCODE_K,            0x25, 'k',  'K'  },
    { SDL_SCANCODE_L,            0x26, 'l',  'L'  },
    { SDL_SCANCODE_SEMICOLON,    0x27, ';',  ':'  },
    { SDL_SCANCODE_APOSTROPHE,   0x28, '\'', '"'  },
    { SDL_SCANCODE_GRAVE,        0x29, '`',  '~'  },
    { SDL_SCANCODE_LSHIFT,       0x2A, 0x00, 0x00 },
    { SDL_SCANCODE_BACKSLASH,    0x2B, '\\', '|'  },
    { SDL_SCANCODE_Z,            0x2C, 'z',  'Z'  },
    { SDL_SCANCODE_X,            0x2D, 'x',  'X'  },
    { SDL_SCANCODE_C,            0x2E, 'c',  'C'  },
    { SDL_SCANCODE_V,            0x2F, 'v',  'V'  },
    { SDL_SCANCODE_B,            0x30, 'b',  'B'  },
    { SDL_SCANCODE_N,            0x31, 'n',  'N'  },
    { SDL_SCANCODE_M,            0x32, 'm',  'M'  },
    { SDL_SCANCODE_COMMA,        0x33, ',',  '<'  },
    { SDL_SCANCODE_PERIOD,       0x34, '.',  '>'  },
    { SDL_SCANCODE_SLASH,        0x35, '/',  '?'  },
    { SDL_SCANCODE_RSHIFT,       0x36, 0x00, 0x00 },
    { SDL_SCANCODE_KP_MULTIPLY,  0x37, '*',  '*'  },
    { SDL_SCANCODE_LALT,         0x38, 0x00, 0x00 },
    { SDL_SCANCODE_SPACE,        0x39, 0x20, 0x20 },
    { SDL_SCANCODE_CAPSLOCK,     0x3A, 0x00, 0x00 },
    { SDL_SCANCODE_F1,           0x3B, 0x00, 0x00 },
    { SDL_SCANCODE_F2,           0x3C, 0x00, 0x00 },
    { SDL_SCANCODE_F3,           0x3D, 0x00, 0x00 },
    { SDL_SCANCODE_F4,           0x3E, 0x00, 0x00 },
    { SDL_SCANCODE_F5,           0x3F, 0x00, 0x00 },
    { SDL_SCANCODE_F6,           0x40, 0x00, 0x00 },
    { SDL_SCANCODE_F7,           0x41, 0x00, 0x00 },
    { SDL_SCANCODE_F8,           0x42, 0x00, 0x00 },
    { SDL_SCANCODE_F9,           0x43, 0x00, 0x00 },
    { SDL_SCANCODE_F10,          0x44, 0x00, 0x00 },
    { SDL_SCANCODE_NUMLOCKCLEAR, 0x45, 0x00, 0x00 },
    { SDL_SCANCODE_SCROLLLOCK,   0x46, 0x00, 0x00 },
    { SDL_SCANCODE_KP_7,         0x47, '7',  '7'  },
    { SDL_SCANCODE_KP_8,         0x48, '8',  '8'  },
    { SDL_SCANCODE_KP_9,         0x49, '9',  '9'  },
    { SDL_SCANCODE_KP_MINUS,     0x4A, '-',  '-'  },
    { SDL_SCANCODE_KP_4,         0x4B, '4',  '4'  },
    { SDL_SCANCODE_KP_5,         0x4C, '5',  '5'  },
    { SDL_SCANCODE_KP_6,         0x4D, '6',  '6'  },
    { SDL_SCANCODE_KP_PLUS,      0x4E, '+',  '+'  },
    { SDL_SCANCODE_KP_1,         0x4F, '1',  '1'  },
    { SDL_SCANCODE_KP_2,         0x50, '2',  '2'  },
    { SDL_SCANCODE_KP_3,         0x51, '3',  '3'  },
    { SDL_SCANCODE_KP_0,         0x52, '0',  '0'  },
    { SDL_SCANCODE_KP_PERIOD,    0x53, '.',  '.'  },
    /* Extended keys: set-1 code in AH, ASCII 0x00 in AL. */
    { SDL_SCANCODE_UP,           0x48, 0x00, 0x00 },
    { SDL_SCANCODE_DOWN,         0x50, 0x00, 0x00 },
    { SDL_SCANCODE_LEFT,         0x4B, 0x00, 0x00 },
    { SDL_SCANCODE_RIGHT,        0x4D, 0x00, 0x00 },
    { SDL_SCANCODE_HOME,         0x47, 0x00, 0x00 },
    { SDL_SCANCODE_END,          0x4F, 0x00, 0x00 },
    { SDL_SCANCODE_PAGEUP,       0x49, 0x00, 0x00 },
    { SDL_SCANCODE_PAGEDOWN,     0x51, 0x00, 0x00 },
    { SDL_SCANCODE_INSERT,       0x52, 0x00, 0x00 },
    { SDL_SCANCODE_DELETE,       0x53, 0x00, 0x00 },
    { SDL_SCANCODE_F11,          0x57, 0x00, 0x00 },
    { SDL_SCANCODE_F12,          0x58, 0x00, 0x00 },
};

static u8  g_k_ascii[KFIFO_SIZE];
static u8  g_k_scan[KFIFO_SIZE];
static int g_k_head, g_k_tail, g_k_count;
static bool g_quit = false;

static void fifo_push(u8 ascii, u8 scan)
{
    if (g_k_count >= KFIFO_SIZE)
        return;                     /* buffer full: key dropped */
    g_k_ascii[g_k_tail] = ascii;
    g_k_scan[g_k_tail] = scan;
    g_k_tail = (g_k_tail + 1) % KFIFO_SIZE;
    g_k_count++;
}

static bool fifo_pop(u8 *ascii, u8 *scan)
{
    if (g_k_count == 0)
        return false;
    *ascii = g_k_ascii[g_k_head];
    *scan  = g_k_scan[g_k_head];
    g_k_head = (g_k_head + 1) % KFIFO_SIZE;
    g_k_count--;
    return true;
}

static bool map_key(SDL_Scancode sc, SDL_Keymod mod, u8 *ascii, u8 *scan)
{
    size_t i;
    for (i = 0; i < sizeof(keymap) / sizeof(keymap[0]); i++) {
        if (keymap[i].sc == sc) {
            *scan = keymap[i].scan;
            *ascii = (mod & KMOD_SHIFT) ? keymap[i].a1 : keymap[i].a0;
            return true;
        }
    }
    return false;
}

void pal_input_init(void)
{
    g_k_head = g_k_tail = g_k_count = 0;
    g_quit = false;
}

void pal_input_shutdown(void)
{
    /* nothing owned beyond SDL itself */
}

static void fake_pump(void);

void pal_input_pump(void)
{
    fake_pump();
    SDL_Event ev;
    pal_video_present_throttled();
    while (SDL_PollEvent(&ev)) {
        switch (ev.type) {
        case SDL_QUIT:
            g_quit = true;
            break;
        case SDL_WINDOWEVENT:
            if (ev.window.event == SDL_WINDOWEVENT_CLOSE)
                g_quit = true;
            break;
        case SDL_KEYDOWN: {
            u8 ascii, scan;
            if (map_key(ev.key.keysym.scancode, (SDL_Keymod)ev.key.keysym.mod,
                        &ascii, &scan))
                fifo_push(ascii, scan);
            break;
        }
        default:
            break;
        }
    }
}

bool pal_input_quit_flag(void)
{
    return g_quit;
}

/* ---- RAD_FAKE_KEYS: timed key injection for headless reproduction ----
 * RAD_FAKE_KEYS="1.0:space,3.0:f1,4.5:return" queues SDL key events at the
 * given seconds after start, as if typed.  Names are SDL scancode names.
 * A leading '+' on the time ("1.0:space,+2:f1") makes that delay relative to
 * the previous key of the chain instead of process start -- robust against
 * the variable startup settle, since each step fires N seconds after the
 * previous one actually fired. */
typedef struct { double at; SDL_Scancode sc; int done; } FakeKey;
static FakeKey g_fake[8192];
static int g_fake_n = -1;          /* -1 = not parsed yet */
static Uint32 g_fake_t0;

static void fake_parse(void)
{
    const char *e = getenv("RAD_FAKE_KEYS");
    /* RAD_FAKE_KEYS_FILE: the same comma/relative format, read from a file so
     * a scripted multi-hour playthrough is not limited by env/queue sizes. */
    static char filebuf[131072];
    double prev_at = 0.0;
    g_fake_n = 0;
    g_fake_t0 = SDL_GetTicks();
    const char *fn = getenv("RAD_FAKE_KEYS_FILE");
    if (fn && *fn) {
        FILE *f = fopen(fn, "rb");
        if (f) {
            size_t rd = fread(filebuf, 1, sizeof(filebuf) - 1, f);
            filebuf[rd] = '\0';
            fclose(f);
            e = filebuf;
        }
    }
    if (!e || !*e)
        return;
    char buf[131072];
    strncpy(buf, e, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    char *save = NULL;
    for (char *tok = strtok_r(buf, ",", &save);
         tok && g_fake_n < 8192; tok = strtok_r(NULL, ",", &save)) {
        char *colon = strchr(tok, ':');
        if (!colon)
            continue;
        *colon = '\0';
        SDL_Scancode sc = SDL_GetScancodeFromName(colon + 1);
        if (sc == SDL_SCANCODE_UNKNOWN)
            continue;
        double at = atof(tok);
        if (tok[0] == '+')
            at += prev_at;             /* relative to the previous key */
        prev_at = at;
        g_fake[g_fake_n].at = at;
        g_fake[g_fake_n].sc = sc;
        g_fake[g_fake_n].done = 0;
        ++g_fake_n;
    }
}

static void fake_pump(void)
{
    if (g_fake_n < 0)
        fake_parse();
    if (g_fake_n == 0)
        return;
    double el = (double)(SDL_GetTicks() - g_fake_t0) / 1000.0;
    for (int i = 0; i < g_fake_n; i++) {
        if (g_fake[i].done || el < g_fake[i].at)
            continue;
        g_fake[i].done = 1;
        u8 ascii, scan;
        if (map_key(g_fake[i].sc, (SDL_Keymod)0, &ascii, &scan)) {
            fifo_push(ascii, scan);
            if (getenv("RAD_FAKE_TRACE"))
                fprintf(stderr, "FAKE fire %d at %.3f (sched %.3f) scan=%02X\n",
                        i, el, g_fake[i].at, scan);
        }
    }
}

/* ---- BIOS keyboard (int 16h) --------------------------------------- */

bool bios_kbd_check_keystroke(void)
{
    pal_input_pump();
    return g_k_count > 0;
}

u16 bios_kbd_get_keystroke(void)
{
    u8 ascii, scan;
    /* int 16h AH=00 BLOCKS until a key is available (the game's title-screen
     * wait relies on it: renamed_0800_4255 calls 1E78:030D right after loading
     * RAD.TIT and must not fall through).  Poll the SDL queue and yield
     * until a key arrives; the window-close flag breaks the wait so the
     * main loop's quit path stays reachable. */
    for (;;) {
        pal_input_pump();
        if (fifo_pop(&ascii, &scan))
            return (u16)(((u16)scan << 8) | ascii);
        if (pal_input_quit_flag())
            return 0;
        SDL_Delay(1);
    }
}

int msdos_direct_console_input(void)
{
    u8 ascii, scan;
    pal_input_pump();
    if (!fifo_pop(&ascii, &scan))
        return 0;
    /* AH=06 returns the ASCII byte, or 0 for extended keys. */
    return (ascii != 0) ? (int)ascii : 0;
}
