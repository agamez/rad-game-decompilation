/* seg13E2.c -- RAD V3.1 preservation port, segment 13E2 (6 functions,
 * ascending offset: 0001 .. 0220).
 *
 * Literal recovery from analysis/slices/13E2/13E2_<off>.asm (ground truth)
 * and analysis/reko/RAD_13E2.{asm,c,dis}; frozen prototypes adopted exactly
 * from src/seg13E2.h (analysis/summary/iface.tsv).  See CONVENTIONS.md.
 *
 * Hardware / DOS (CONVENTIONS.md rule 4): this segment contains no direct
 * `int 10h` / `int 16h` / `int 21h`, no `in`/`out` port instruction, no
 * __cli/__sti and no int 23h.  All video/text work is reached through
 * segment 1AB8 (bgi_get_pixel / 1342), segment 1E78 (renamed_1e78_016b) and
 * segment 1EDA (BGI text output helpers); those ports carry the hardware
 * translation.  The implicit DS selector parameter is dropped (flat model)
 * and the Reko `out ds` parameters are dropped.
 *
 * Code-segment data (cs-relative): the ~27 KB of tables embedded in 13E2
 * (0x0278 BGI EGAVGA driver, 0x182A stroked font, 0x594F TRIP font, plus
 * the 0x0208 error string and 0x0191 beep string) are exposed as
 * g_seg13E2 (data/segments/seg13E2.bin, 0x6D60 bytes); every cs-relative
 * offset below indexes that array literally.  DGROUP globals 0xB6C1
 * (installed flag), 0xB6BE (loop index), 0xB8AC and the 0x50CC/0x50CD/
 * 0x50CE colour table are LG accesses.  See docs/notes-small-segs.md
 * ("## 13E2").
 */
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg13E2.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1E78.h"

// 13E2:0001: u8 renamed_13e2_0001(u16 * dsOut)
// Initialise the BGI driver state: bgi_load_bgi_driver(cs:0000, ss:bp-6, ss:bp-4)
// then report whether bgi_get_error_code found a pending BGI error (0 -> success,
// 1 -> error).  The DS selector returned by 0BAE is the `dsOut` output.
u8 renamed_13e2_0001(u16 *dsOut)
{
    u16 wLoc4 = 0x0000;   /* [bp-4]  bgi_load_bgi_driver ptrArg0C (prologue zeroes it) */
    s16 wLoc6;            /* [bp-6]  bgi_load_bgi_driver ptrArg08 (char-height out) */
    u16 wLoc8;            /* [bp-8]  bgi_get_error_code result */
    u8  bLoc1;            /* [bp-1]  result flag (AL at retf) */
    u16 ds_36;            /* bgi_load_bgi_driver DS return (dropped selector, flat model) */

    /* original: push ss:bp-4 ; push ss:bp-6 ; push cs:0000 ; call 1AB8:0BAE */
    ds_36 = bgi_load_bgi_driver(&g_seg13E2[0x0000], &wLoc6, (u8 *)&wLoc4);
    wLoc8 = bgi_get_error_code();
    if (wLoc8 != 0x0000)
        bLoc1 = 0x00;
    else
        bLoc1 = 0x01;
    *dsOut = ds_36;
    return bLoc1;
}

// 13E2:003B: u8 renamed_13e2_003b(void)
// Uninstall/blank the BGI text: if the installed flag at 0B6C1h is set,
// clear it and blank all 16 colour slots (0Fh down to 00h) by re-invoking
// the driver with a zero colour.  Reko returns SLICE(dx, byte, 8).
u8 renamed_13e2_003b(void)
{
    u16 dx = 0x0000;   /* bgi_get_pixel DX result */

    if (LG8(0xB6C1) != 0x00)
    {
        LG8(0xB6C1) = 0x00;
        LG8(0xB6BE) = 0x0F;
        for (;;)
        {
            dx = bgi_get_pixel(0x0000, 0x0000, 0x0000, (u16)LG8(0xB6BE));
            (void)bgi_set_text_character_color((u8)LG8(0xB6BE), (u16)LG8(0xB6BE));
            if (LG8(0xB6BE) == 0x00)
                break;
            LG8(0xB6BE) = (u8)(LG8(0xB6BE) - 0x01);
        }
    }
    return (u8)(dx >> 8);   /* SLICE(dx, byte, 8) */
}

// 13E2:0080: u16 renamed_13e2_0080(void)
// Install the BGI text: if not already installed, program all 16 colour
// slots (00h..0Fh) from the 3-byte-per-entry table at 50CCh/50CDh/50CEh,
// passing each entry as the driver's (R,G,B) components.  Returns the last
// bgi_get_pixel DX value.
u16 renamed_13e2_0080(void)
{
    u16 dx = 0x0000;   /* bgi_get_pixel DX result */

    if (LG8(0xB6C1) == 0x00)
    {
        LG8(0xB6C1) = 0x01;
        LG8(0xB6BE) = 0x00;
        for (;;)
        {
            u16 idx = (u16)LG8(0xB6BE);
            /* asm: di = idx*3 ; al = [di+50CEh] / [di+50CDh] / [di+50CCh] */
            dx = bgi_get_pixel((u16)LG8((u16)(0x50CE + idx * 0x03)),
                             (u16)LG8((u16)(0x50CD + idx * 0x03)),
                             (u16)LG8((u16)(0x50CC + idx * 0x03)),
                             idx);
            (void)bgi_set_text_character_color((u8)idx, idx);
            if (LG8(0xB6BE) == 0x0F)
                break;
            LG8(0xB6BE) = (u8)(LG8(0xB6BE) + 0x01);
        }
    }
    return dx;
}

// 13E2:00FB: void renamed_13e2_00fb(void)
// Same installation sweep as renamed_13e2_0080, except slot 08h is programmed
// with a zero colour (the driver reserves it) instead of its table entry.
void renamed_13e2_00fb(void)
{
    if (LG8(0xB6C1) == 0x00)
    {
        LG8(0xB6C1) = 0x01;
        LG8(0xB6BE) = 0x00;
        for (;;)
        {
            u16 idx = (u16)LG8(0xB6BE);
            if (LG8(0xB6BE) == 0x08)
                (void)bgi_get_pixel(0x0000, 0x0000, 0x0000, idx);
            else
                (void)bgi_get_pixel((u16)LG8((u16)(0x50CE + idx * 0x03)),
                                  (u16)LG8((u16)(0x50CD + idx * 0x03)),
                                  (u16)LG8((u16)(0x50CC + idx * 0x03)),
                                  idx);
            (void)bgi_set_text_character_color((u8)idx, idx);
            if (LG8(0xB6BE) == 0x0F)
                break;
            LG8(0xB6BE) = (u8)(LG8(0xB6BE) + 0x01);
        }
    }
}

// 13E2:0193: u16 renamed_13e2_0193(u8 * ptrArg04)
// Report a fatal BGI error: format ptrArg04 into [bp-0100h], tear the video
// driver down (bgi_shutdown_video_driver / 0E88), run the 1E78 teardown (renamed_1e78_016b), copy the
// message to [bp-0200h], append the 0x0191 beep string three times, emit the
// result through the BGI stream at ds:0B9BCh and terminate via the CRT fatal
// exit fn1EDA_00E9(0) (no return).
u16 renamed_13e2_0193(u8 *ptrArg04)
{
    u8  abLoc0100[0x100];   /* [bp-0100h] formatted message */
    u8  abLoc0200[0x100];   /* [bp-0200h] accumulated message (carried to 08CE) */
    u16 dx_228;             /* renamed_1eda_0a39 dxOut (ignored) */
    u16 dx_229;             /* renamed_1e78_016b dxOut (ignored) */
    u16 cx_160;             /* renamed_1eda_08ce cxOut, fed to renamed_1eda_0848 */

    /* original: push 0FFh ; push ss:bp-0100h ; push ptrArg04 ; call 1EDA:0A39 */
    renamed_1eda_0a39(0xFF, abLoc0100, ptrArg04, &dx_228);
    bgi_shutdown_video_driver();
    bgi_swap_graphics_gateway();
    /* original: push [0B8ACh] ; call far 1E78:016B */
    (void)renamed_1e78_016b(LG16(0xB8AC), &dx_229);
    /* original: 0A1F(src=ss:bp-0100h, dst=ss:bp-0200h) then three 0AAC
     * appends of cs:0191h into ss:bp-0200h (the 0AAC dst is carried on the
     * stack across the calls; see docs/notes-small-segs.md). */
    renamed_1eda_0a1f(abLoc0100, abLoc0200);
    renamed_1eda_0aac(&g_seg13E2[0x0191], abLoc0200);
    renamed_1eda_0aac(&g_seg13E2[0x0191], abLoc0200);
    renamed_1eda_0aac(&g_seg13E2[0x0191], abLoc0200);
    /* original: push 0h ; call 1EDA:08CE(0, ss:bp-0200h, ds:0B9BCh) ;
     *           call 1EDA:0848(0, CX, ds:0B9BCh) */
    (void)renamed_1eda_08ce(0x0000, abLoc0200, &g_dgroup[0xB9BC], &cx_160);
    (void)renamed_1eda_0848(0x00, cx_160, &g_dgroup[0xB9BC]);
    return (u16)(uintptr_t)fn1EDA_00E9(0x0000);   /* fatal exit (no return) */
}

// 13E2:0220: u16 renamed_13e2_0220(void)
// CRT startup hook (called from renamed_0800_4255): probe/load the three BGI
// drivers embedded in this segment (13E2:0278 EGAVGA, 13E2:182A stroked
// font, 13E2:594F TRIP font).  A negative (signed) register result means
// the driver is missing -> fatal report through renamed_13e2_0193.  Finally set
// the installed flag at 0B6C1h and return the threaded DS selector.
u16 renamed_13e2_0220(void)
{
    u16 ds = 0x0000;   /* DGROUP selector threaded through renamed_13e2_0193 */

    /* original: push 13E2h:0278h ; call far 1AB8:05D3 ; or ax,ax ; jge */
    if ((s16)bgi_find_video_driver_index(&g_seg13E2[0x0278]) < 0x0000)
        ds = renamed_13e2_0193(&g_seg13E2[0x0208]);
    /* original: push 13E2h:182Ah ; call far 1AB8:06CA ; or ax,ax ; jge */
    if ((s16)bgi_unload_video_driver(&g_seg13E2[0x182A]) < 0x0000)
        ds = renamed_13e2_0193(&g_seg13E2[0x0208]);
    /* original: push 13E2h:594Fh ; call far 1AB8:06CA ; or ax,ax ; jge */
    if ((s16)bgi_unload_video_driver(&g_seg13E2[0x594F]) < 0x0000)
        ds = renamed_13e2_0193(&g_seg13E2[0x0208]);
    LG8(0xB6C1) = 0x01;
    return ds;
}
