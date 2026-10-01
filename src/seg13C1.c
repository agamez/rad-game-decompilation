/* seg13C1.c -- RAD V3.1 segment 13C1, recovered from RAD_13C1.asm.
 *
 * Literal recovery.  This segment contains no direct hardware instruction:
 * the two BIOS video calls in stub_get_video_info (INT 10h AH=0Fh / AH=03h) are
 * dispatched through dos_interrupt_trampoline (1E5F:000B), the register-frame interrupt
 * trampoline, so no bios_video_ / msdos_ PAL call is needed here.  There
 * are no in/out port sites, no __cli/__sti and no int 23h sites.
 *
 * The frozen prototypes in seg13C1.h (from analysis/summary/iface.tsv) are
 * adopted exactly.  See docs/notes-13C1-13C8.md for the Reko artifacts that
 * could not be represented by them.
 */
#include "radtypes.h"
#include "globals.h"
#include "seg13C1.h"
#include "seg1EDA.h"
#include "seg1E5F.h"

/* Register frame exchanged with dos_interrupt_trampoline.  Its post-interrupt
 * continuation at 1E5F:0045 stores AX,BX,CX,DX,BP,SI,DI,DS,ES,FLAGS at
 * byte offsets 0,2,...,0x12 (ten words); every wrapper below reserves
 * exactly this 0x14-byte frame (`enter 14h`). */
typedef struct {
    u16 ax, bx, cx, dx, bp, si, di, ds, es, flags;
} TRegFrame;

// 13C1:0000: u16 stub_get_video_info(void * dsOut)
u16 stub_get_video_info(void * dsOut) /* was fn13C1_0000 */
{
    TRegFrame r = {0};

    ((u8 *)&r.ax)[1] = 0x0F;    /* AH=0Fh: get current video mode */
    dos_interrupt_trampoline((u8 *)&r, 0x10);

    ((u8 *)&r.ax)[1] = 0x03;    /* AH=03h: get cursor shape */
    dos_interrupt_trampoline((u8 *)&r, 0x10);

    LG16(0xB6A8) = (u16)((u8 *)&r.cx)[1];   /* CH -> cursor start scan line */
    LG16(0xB6AA) = (u16)((u8 *)&r.cx)[0];   /* CL -> cursor end scan line   */
    return (u16)(u8)r.cx;                    /* AX = zero-extended CL */
}

// 13C1:0036: void stub_dword_to_string(u32 dwArg04, u8 * ptrArg08)
void stub_dword_to_string(u32 dwArg04, u8 * ptrArg08) /* was fn13C1_0036 */
{
    u8 abBuf0100[0x100];    /* [bp-0100h]: scratch text buffer */
    void *dx_89 = 0;

    fn1EDA_0F26(0xFF, abBuf0100, 0x00, dwArg04);
    fn1EDA_0A39(0xFF, ptrArg08, abBuf0100, &dx_89);
}

// 13C1:0067: void * stub_init_video_info(void)
void * stub_init_video_info(void) /* was fn13C1_0067 */
{
    void *ds_14 = 0;

    stub_get_video_info(&ds_14);
    return ds_14;
}
