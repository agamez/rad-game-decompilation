/* dos.c — RAD Linux port: MS-DOS int 21h service emulation.
 *
 * Implemented services (all reached through the named pal.h entry points):
 *   AH=3D/3E/3F/40/42  file open/close/read/write/seek (stdio)
 *   AH=1A/4E/4F        set DTA / find first / find next (dirent + fnmatch)
 *   AH=2C              get system time
 *   AH=30              get DOS version
 *   AH=19              get current default drive
 *   AH=47              get current directory
 *   AH=25/35           set/get interrupt vector
 *   AH=4C              terminate
 *
 * DECISIONS:
 *   - Paths are resolved against a data directory: $RAD_DATA if set, else
 *     "./data" when it exists, else ".".  Absolute paths bypass this.  DOS
 *     is case-insensitive; fnmatch uses FNM_CASEFOLD.
 *   - Handles start at 5, mirroring DOS (0..4 are the predefined devices).
 *     Open returns 0xFFFF on failure, like DOS AX on error.
 *   - DOS open mode 0=read, 1=write, 2=read/write.  Since DOS open never
 *     truncates, modes 1 and 2 both map to "r+b" (the file must exist).
 *     The design has no create-file service because the recovered code does
 *     not issue int 21h AH=3C.
 *   - Reads/writes return the byte count (DOS AX) and 0xFFFF for an invalid
 *     handle.  Seek returns the new 32-bit position, or -1.
 *   - The DTA name at offset 0x1E is written as an uppercase 8.3 ASCIIZ
 *     filename with a dot (e.g. "RAD.DAT"), which is exactly what DOS
 *     AH=4E returns and what the recovered consumer (fn1E5F_0136) scans for
 *     a terminating NUL.  (The brief's phrase "space-padded" describes the
 *     FCB name layout; the find-first DTA uses the dotted ASCIIZ form.)
 *   - Setting interrupt vector 0x23 (Ctrl-C) is a no-op: Ctrl-C suppression
 *     is achieved by never invoking the handler.  Stored vectors are never
 *     called, per the port's no-real-interrupts design.
 */
#define _GNU_SOURCE 1   /* FNM_CASEFOLD (case-insensitive DOS wildcards) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fnmatch.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>

#include "pal.h"
#include "pal_internal.h"

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

#define HANDLE_BASE 5
#define MAX_HANDLES  32

static FILE *g_file[MAX_HANDLES];
static bool  g_file_used[MAX_HANDLES];

static u8 *g_dta = NULL;

/* Directory scan state for AH=4E / AH=4F. */
static DIR  *g_find_dir = NULL;
static char  g_find_pat[PATH_MAX];

static char  g_data_dir[PATH_MAX];
static bool  g_data_dir_ready = false;

/* ------------------------------------------------------------------ */
/* data directory                                                      */
/* ------------------------------------------------------------------ */

static const char *data_dir(void)
{
    const char *env;
    if (g_data_dir_ready)
        return g_data_dir;
    env = getenv("RAD_DATA");
    if (env && env[0]) {
        snprintf(g_data_dir, sizeof(g_data_dir), "%s", env);
    } else if (access("./data", F_OK) == 0) {
        snprintf(g_data_dir, sizeof(g_data_dir), "./data");
    } else {
        /* Also try relative to the executable: build/rad -> ../data. */
        ssize_t n = readlink("/proc/self/exe", g_data_dir, sizeof(g_data_dir) - 8);
        if (n > 0) {
            char *slash;
            g_data_dir[n] = '\0';
            slash = strrchr(g_data_dir, '/');
            if (slash) {
                *slash = '\0';
                strcat(g_data_dir, "/data");
                if (access(g_data_dir, F_OK) == 0) {
                    g_data_dir_ready = true;
                    return g_data_dir;
                }
                slash = strrchr(g_data_dir, '/');
                if (slash) {
                    *slash = '\0';
                    strcat(g_data_dir, "/data");
                    if (access(g_data_dir, F_OK) == 0) {
                        g_data_dir_ready = true;
                        return g_data_dir;
                    }
                }
            }
        }
        snprintf(g_data_dir, sizeof(g_data_dir), ".");
    }
    g_data_dir_ready = true;
    return g_data_dir;
}

void pal_dos_init(void)
{
    (void)data_dir();
}

static void resolve_path(const char *path, char *out, size_t outsz)
{
    if (path[0] == '/') {
        snprintf(out, outsz, "%s", path);
    } else {
        snprintf(out, outsz, "%s/%s", data_dir(), path);
    }
}

/* ------------------------------------------------------------------ */
/* files                                                               */
/* ------------------------------------------------------------------ */

static char g_handle_name[MAX_HANDLES][64];
static int g_io_trace_on = -1;

u16 msdos_open_file(const char *path, u8 mode)
{
    char full[PATH_MAX];
    const char *cmode;
    int i;

    if (!path)
        return 0xFFFFu;
    resolve_path(path, full, sizeof(full));

    switch (mode & 0x03) {
    case 0: cmode = "rb";  break;   /* read          */
    case 1: cmode = "r+b"; break;   /* write, no truncation */
    case 2: cmode = "r+b"; break;   /* read/write    */
    default: cmode = "rb"; break;
    }

    for (i = 0; i < MAX_HANDLES; i++) {
        if (!g_file_used[i]) {
            FILE *f = fopen(full, cmode);
            if (!f && (mode & 0x03) != 0) {
                /* DOS create-or-open (AH=3Ch): a write-mode open of a
                 * missing file CREATES it (the game's RAD.MEM player-name
                 * save relies on this; DOSBox creates it on first boot). */
                f = fopen(full, "w+b");
            }
            if (!f) {
                if (getenv("RAD_IO_LOG"))
                    fprintf(stderr, "OPEN FAIL: %s (mode %u)\n", full, mode);
                return 0xFFFFu;
            }
            g_file[i] = f;
            g_file_used[i] = true;
            snprintf(g_handle_name[i], sizeof(g_handle_name[i]), "%s", path);
            return (u16)(HANDLE_BASE + i);
        }
    }
    return 0xFFFFu;                 /* handle table full */
}

static FILE *handle_file(u16 handle)
{
    int i;
    if (handle < HANDLE_BASE)
        return NULL;
    i = handle - HANDLE_BASE;
    if (i < 0 || i >= MAX_HANDLES || !g_file_used[i])
        return NULL;
    return g_file[i];
}

u16 msdos_close_file(u16 handle)
{
    int i;
    if (handle < HANDLE_BASE)
        return 0xFFFFu;
    i = handle - HANDLE_BASE;
    if (i >= MAX_HANDLES || !g_file_used[i])
        return 0xFFFFu;
    fclose(g_file[i]);
    g_file[i] = NULL;
    g_file_used[i] = false;
    return 0;
}

u16 msdos_read_file(u16 handle, void *buf, u16 count)
{
    FILE *f = handle_file(handle);
    size_t n;
    if (!f)
        return 0xFFFFu;
    n = fread(buf, 1, count, f);
    if (g_io_trace_on < 0)
        g_io_trace_on = (getenv("RAD_IO_LOG") != NULL);
    if (g_io_trace_on)
        fprintf(stderr, "IO: read h%u(%s) cnt=%u -> %ld @%ld\n", handle,
                g_handle_name[handle - HANDLE_BASE], count, (long)n,
                (long)ftell(f));
    return (u16)n;
}

u16 msdos_write_file(u16 handle, const void *buf, u16 count)
{
    FILE *f = handle_file(handle);
    size_t n;
    if (!f)
        return 0xFFFFu;
    n = fwrite(buf, 1, count, f);
    /* DOS AH=40h is synchronous (the bytes are in the file when the call
     * returns); flush so e.g. the RAD.MEM player-name save is on disk even
     * when a headless verification terminates the process mid-run. */
    fflush(f);
    return (u16)n;
}

s32 msdos_set_file_position(u16 handle, s32 offset, u8 origin)
{
    FILE *f = handle_file(handle);
    int whence;
    if (!f)
        return -1;
    switch (origin) {
    case 0: whence = SEEK_SET; break;
    case 1: whence = SEEK_CUR; break;
    case 2: whence = SEEK_END; break;
    default: return -1;
    }
    if (fseek(f, (long)offset, whence) != 0)
        return -1;
    if (g_io_trace_on < 0)
        g_io_trace_on = (getenv("RAD_IO_LOG") != NULL);
    if (g_io_trace_on)
        fprintf(stderr, "IO: seek h%u(%s) off=%ld whence=%d -> %ld\n", handle,
                g_handle_name[handle - HANDLE_BASE], (long)offset, (int)whence,
                (long)ftell(f));
    return (s32)ftell(f);
}

/* ------------------------------------------------------------------ */
/* DTA / find first / find next                                        */
/* ------------------------------------------------------------------ */

void msdos_set_DTA(void *dta)
{
    g_dta = (u8 *)dta;
}

/* Uppercase 8.3 short name with a dot ("RAD.DAT"), ASCIIZ. */
static void make_short_name(const char *in, char *out, size_t outsz)
{
    const char *dot;
    size_t bl, el, i, o = 0;

    dot = strrchr(in, '.');
    bl = dot ? (size_t)(dot - in) : strlen(in);
    if (bl > 8) bl = 8;
    for (i = 0; i < bl && o + 1 < outsz; i++) {
        char c = in[i];
        if (c >= 'a' && c <= 'z') c = (char)(c - 'a' + 'A');
        out[o++] = c;
    }
    if (dot && dot[1] && o + 1 < outsz) {
        out[o++] = '.';
        el = strlen(dot + 1);
        if (el > 3) el = 3;
        for (i = 0; i < el && o + 1 < outsz; i++) {
            char c = dot[1 + i];
            if (c >= 'a' && c <= 'z') c = (char)(c - 'a' + 'A');
            out[o++] = c;
        }
    }
    out[o] = '\0';
}

static void fill_dta(u8 *dta, const char *name, const struct stat *st)
{
    struct tm tmv;
    time_t mt = st->st_mtime;
    u16 tw, dw;
    u32 size;
    char shortname[32];

    memset(dta, 0, 44);

    dta[0x15] = S_ISDIR(st->st_mode) ? 0x10 : 0x20;

    localtime_r(&mt, &tmv);
    tw = (u16)(((tmv.tm_hour & 0x1F) << 11) |
               ((tmv.tm_min  & 0x3F) << 5)  |
               ((tmv.tm_sec  & 0x3F) >> 1));
    dw = (u16)(((tmv.tm_year + 1900 - 1980) & 0x7F) << 9) |
         (u16)(((tmv.tm_mon + 1) & 0x0F) << 5) |
         (u16)(tmv.tm_mday & 0x1F);
    dta[0x16] = (u8)(tw & 0xFF);
    dta[0x17] = (u8)(tw >> 8);
    dta[0x18] = (u8)(dw & 0xFF);
    dta[0x19] = (u8)(dw >> 8);

    size = (u32)st->st_size;
    dta[0x1A] = (u8)(size & 0xFF);
    dta[0x1B] = (u8)((size >> 8) & 0xFF);
    dta[0x1C] = (u8)((size >> 16) & 0xFF);
    dta[0x1D] = (u8)((size >> 24) & 0xFF);

    make_short_name(name, shortname, sizeof(shortname));
    {
        size_t n = strlen(shortname);
        if (n > 12)
            n = 12;                     /* DTA name field is 13 bytes incl NUL */
        memcpy((char *)dta + 0x1E, shortname, n);
        dta[0x1E + n] = 0;
    }
}

static bool find_next(bool first)
{
    struct dirent *de;
    char full[PATH_MAX + 300];

    if (!g_find_dir)
        return false;

    while ((de = readdir(g_find_dir)) != NULL) {
        struct stat st;
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0)
            continue;
        if (fnmatch(g_find_pat, de->d_name, FNM_CASEFOLD) != 0)
            continue;
        snprintf(full, sizeof(full), "%s/%s", g_data_dir, de->d_name);
        if (stat(full, &st) != 0)
            continue;
        if (g_dta)
            fill_dta(g_dta, de->d_name, &st);
        return true;
    }

    closedir(g_find_dir);
    g_find_dir = NULL;
    (void)first;
    return false;
}

bool msdos_find_first_file(const char *pattern, u8 *dta)
{
    const char *slash;
    char searchdir[PATH_MAX];
    const char *namepat = pattern;

    if (dta)
        g_dta = dta;
    if (!pattern)
        return false;

    /* Split an optional directory part from the wildcard filename. */
    slash = strrchr(pattern, '/');
    if (slash) {
        size_t dlen = (size_t)(slash - pattern);
        if (dlen == 0) {
            snprintf(searchdir, sizeof(searchdir), "/");
        } else if (pattern[0] == '/') {
            snprintf(searchdir, sizeof(searchdir), "%.*s", (int)dlen, pattern);
        } else {
            snprintf(searchdir, sizeof(searchdir), "%s/%.*s",
                     data_dir(), (int)dlen, pattern);
        }
        namepat = slash + 1;
    } else {
        snprintf(searchdir, sizeof(searchdir), "%s", data_dir());
    }

    if (g_find_dir) {
        closedir(g_find_dir);
        g_find_dir = NULL;
    }
    g_find_dir = opendir(searchdir);
    if (!g_find_dir)
        return false;
    snprintf(g_find_pat, sizeof(g_find_pat), "%s", namepat);

    return find_next(true);
}

bool msdos_find_next_file(u8 *dta)
{
    if (dta)
        g_dta = dta;
    if (!g_find_dir)
        return false;
    return find_next(false);
}

/* ------------------------------------------------------------------ */
/* time / version / drive / directory                                  */
/* ------------------------------------------------------------------ */

void msdos_get_system_time(u8 *h, u8 *m, u8 *s, u8 *hs)
{
    struct timeval tv;
    struct tm tmv;
    gettimeofday(&tv, NULL);
    localtime_r(&tv.tv_sec, &tmv);
    if (h)  *h  = (u8)tmv.tm_hour;
    if (m)  *m  = (u8)tmv.tm_min;
    if (s)  *s  = (u8)tmv.tm_sec;
    if (hs) *hs = (u8)(tv.tv_usec / 10000);   /* hundredths of a second */
}

u8 msdos_get_dos_version(void)
{
    return 7;                       /* report DOS 7.x (major 7) */
}

u8 msdos_get_current_default_drive(void)
{
    return 2;                       /* 0=A, 1=B, 2=C: (DOS 0-based) */
}

void msdos_get_current_directory(char *buf)
{
    if (buf) {
        /* The data directory is the process CWD; DOS returns a path with no
         * drive letter and no leading backslash. */
        strcpy(buf, ".");
    }
}

/* ------------------------------------------------------------------ */
/* interrupt vectors                                                   */
/* ------------------------------------------------------------------ */

static void *g_vec[256];

void msdos_set_interrupt_vector(u8 vec, void *handler)
{
    if (vec == 0x23)
        return;                     /* Ctrl-C suppression: never install */
    g_vec[vec] = handler;
}

void *msdos_get_interrupt_vector(u8 vec)
{
    return g_vec[vec];
}

/* ------------------------------------------------------------------ */
/* terminate                                                           */
/* ------------------------------------------------------------------ */

void msdos_terminate(u8 code)
{
    fflush(NULL);
    pal_shutdown();
    exit((int)code);
}

/* ---- BDA tick emulation (see pal.h) ---- */
#include <time.h>
static volatile u8 g_bda_tick;
static struct timespec g_bda_epoch;
static int g_bda_init = 0;

volatile u8 *pal_bda_tick_byte(void)
{
    struct timespec now;
    if (!g_bda_init) {
        clock_gettime(CLOCK_MONOTONIC, &g_bda_epoch);
        g_bda_init = 1;
    }
    clock_gettime(CLOCK_MONOTONIC, &now);
    long ds = now.tv_sec - g_bda_epoch.tv_sec;
    long dns = now.tv_nsec - g_bda_epoch.tv_nsec;
    if (dns < 0) { ds -= 1; dns += 1000000000L; }
    /* 18.2065 Hz PIT-derived BIOS tick */
    unsigned long long ticks = (unsigned long long)((ds * 18.2065) + (dns * 18.2065 / 1e9));
    g_bda_tick = (u8)(ticks & 0xFF);
    return &g_bda_tick;
}
