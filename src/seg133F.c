/* seg133F.c -- RAD V3.1 preservation port, segment 133F (15 functions,
 * ascending offset: 0056 .. 0816).
 *
 * Literal recovery from analysis/slices/133F/133F_<off>.asm (ground truth)
 * and analysis/reko/RAD_133F.{asm,c}; frozen prototypes from src/seg133F.h
 * (analysis/summary/iface.tsv).  See CONVENTIONS.md and docs/notes-133F.md.
 *
 * Hardware / DOS: this segment has no direct `int 10h` / `int 16h` /
 * `int 21h`, no `in`/`out` port instruction, no __cli/__sti and no int 23h.
 * The keyboard reads in vgaerr_read_input go through segment 1E78
 * (fn1E78_02FB / fn1E78_030D) and the mouse cursor calls through segment
 * 13C8; both already translate their interrupt traffic to the PAL.  No
 * segment-0xA000 VGA far pointer literal occurs here either.  Far pointers
 * are DGROUP (g_dgroup + off), code-segment (g_seg133F + off) or stack
 * locals.
 */
#include "radtypes.h"
#include "globals.h"
#include "seg133F.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg13C8.h"
#include "seg1E78.h"

// 133F:0056: u16 vgaerr_init_bgi(u16 * dsOut)
u16 vgaerr_init_bgi(u16 * dsOut) /* was fn133F_0056 */
{
    u16 wLoc6;                 /* [bp-6]  bgi_get_error_code result */
    s16 wLoc4;                 /* [bp-4]  bgi_load_bgi_driver ptrArg08 out */
    u16 wLoc2 = 0x0000;        /* [bp-2]  bgi_load_bgi_driver ptrArg0C out */
    u8  abLoc020C[0x206];      /* [bp-0x20C] formatted-message buffer */
    u16 cx_87;
    u16 cx_107;
    u16 cx_146;
    u16 cx_185;
    void *ds_211 = 0;

    /* original: bgi_load_bgi_driver(cs:0000, ss:bp-4, ss:bp-2); DS result dropped */
    (void)bgi_load_bgi_driver(g_seg133F, &wLoc4, (u8 *)&wLoc2);
    wLoc6 = bgi_get_error_code();
    if (wLoc6 != 0x00)
    {
        fn1EDA_08CE(0x00, &g_seg133F[0x0001], &g_dgroup[0xB9BC], &cx_87);
        bgi_color_name_to_string(wLoc6, abLoc020C);
        fn1EDA_08CE(0x00, abLoc020C, &g_dgroup[0xB9BC], &cx_107);
        (void)fn1EDA_0848(0x00, cx_107, &g_dgroup[0xB9BC]);
        fn1EDA_08CE(0x00, &g_seg133F[0x0014], &g_dgroup[0xB9BC], &cx_146);
        (void)fn1EDA_0848(0x00, cx_146, &g_dgroup[0xB9BC]);
        fn1EDA_08CE(0x00, &g_seg133F[0x003D], &g_dgroup[0xB9BC], &cx_185);
        (void)fn1EDA_0848(0x00, cx_185, &g_dgroup[0xB9BC]);
        (void)fn1EDA_00E9(0x0001);   /* fatal BGI error dispatcher */
    }

    if (config_mouse_is_present() != 0x00)
    {
        /* original: config_mouse_reset(ds:0B6B0, ds:0B6AE) */
        (void)config_mouse_reset((u16 *)&g_dgroup[0xB6B0], (u16 *)&g_dgroup[0xB6AE], &ds_211);
        if (LG16(0xB6AE) != 0x00)
        {
            /* original: config_set_h_range(027Fh, 0000h) */
            (void)config_set_h_range(0x027F, 0x0000);
            /* original: config_set_v_range(01DFh, 0000h) */
            (void)config_set_v_range(0x01DF, 0x0000, &ds_211);
        }
    }

    LG8(0xB59D) = 0x00;
    LG8(0xB5A2) = 0x00;
    LG8(0x6CD0) = 0x00;
    LG8(0xB59C) = 0x00;
    bgi_set_text_color_attribute(0x0000);
    (void)bgi_get_text_cursor_attributes(0x0F);

    *dsOut = 0x0000;   /* DGROUP selector dropped in the flat model */
    return 0x0000;
}

// 133F:0137: u8 vgaerr_show_cursor(u16 * dxOut, u16 * bpOut, void * dsOut)
u8 vgaerr_show_cursor(u16 * dxOut, u16 * bpOut, void * dsOut) /* was fn133F_0137 */
{
    /* pure forwarding wrapper: call 13C8:004F ("show cursor", INT 33h fn 1);
     * its AL/DX/BP/DS outputs are the wrapper's outputs (asm: leave; retf). */
    return config_hide_cursor(dxOut, bpOut, dsOut);
}

// 133F:0141: u8 vgaerr_hide_cursor(s16 * dxOut, u16 * bpOut, void * dsOut)
u8 vgaerr_hide_cursor(s16 * dxOut, u16 * bpOut, void * dsOut) /* was fn133F_0141 */
{
    /* pure forwarding wrapper: call 13C8:0038 ("hide cursor", INT 33h fn 2) */
    return config_show_cursor((u16 *)dxOut, bpOut, dsOut);
}

// 133F:014B: u8 vgaerr_draw_error_rect(u8 * ptrArg04, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E, u16 * dxOut, u16 * dsOut)
u8 vgaerr_draw_error_rect(u8 *ptrArg04, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E, u16 *dxOut, u16 *dsOut) /* was fn133F_014B */
{
    u8  abLoc0100[0x100];      /* [bp-0x100] */
    u16 dx_296;                /* ignored 1EDA_0A39 out */
    u16 dx_214;                /* second bgi_draw_text_rectangle result -> *dxOut */
    u8  ch_297;                /* bgi_get_char_size_info chOut (unused) */
    u16 n1783_a, n1783_b;
    u16 n1E0B_a, n1E0B_b;
    u16 x1783, x1E0B;
    u16 p1, p2, p3, p4;
    u16 ax10CE, ax10E1;

    /* original: fn1EDA_0A39(FFh, ss:bp-100h, ptrArg04) */
    fn1EDA_0A39(0xFF, abLoc0100, ptrArg04, &dx_296);
    bgi_set_text_rectangle(0x01, 0x01);
    /* original: bgi_load_video_driver_file(wArg08, 0, wArg0A, out ds) */
    (void)bgi_load_video_driver_file(wArg08, 0x00, wArg0A, dsOut);

    /* first rect: 0F93(1, wArg0C + X1783, wArg0E + X1E0B,
     *                  wArg0C - X1783, wArg0E - X1E0B) */
    n1E0B_a = bgi_advance_text_pointer(abLoc0100);
    x1E0B = (u16)((n1E0B_a >> 1) + 1);
    p1 = (u16)(wArg0E - x1E0B);
    n1783_a = bgi_display_error_string(abLoc0100);
    x1783 = (u16)((n1783_a >> 1) + 1);
    p2 = (u16)(wArg0C - x1783);
    n1E0B_b = bgi_advance_text_pointer(abLoc0100);
    x1E0B = (u16)((n1E0B_b >> 1) + 1);
    p3 = (u16)(wArg0E + x1E0B);
    n1783_b = bgi_display_error_string(abLoc0100);
    x1783 = (u16)((n1783_b >> 1) + 1);
    p4 = (u16)(wArg0C + x1783);
    (void)bgi_draw_text_rectangle(0x01, p4, p3, p2, p1);

    bgi_update_text_window_position();
    ax10CE = bgi_get_text_cols();
    ax10E1 = bgi_get_text_rows();
    /* original: bgi_draw_text_rectangle(1, AX_10E1, AX_10CE, 0, 0) */
    dx_214 = bgi_draw_text_rectangle(0x01, ax10E1, ax10CE, 0x00, 0x00);
    /* original: bgi_get_char_size_info(ss:bp-100h, wArg0C, wArg0E, out ch) */
    (void)bgi_get_char_size_info(abLoc0100, wArg0C, wArg0E, &ch_297);

    *dxOut = dx_214;
    return 0x00;   /* Reko: return 0x00; asm leaves 1D82's AL (ignored) */
}

// 133F:0200: void vgaerr_set_text_window(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)
void vgaerr_set_text_window(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A) /* was fn133F_0200 */
{
    LG16(0x6CC8) = wArg0A;
    LG16(0x6CCA) = wArg08;
    LG16(0x6CCC) = wArg06;
    LG16(0x6CCE) = wArg04;
}

// 133F:021F: u8 vgaerr_clamp_coordinates(u16 wArg04, u16 wArg06)
u8 vgaerr_clamp_coordinates(u16 wArg04, u16 wArg06) /* was fn133F_021F */
{
    u16 ax_13 = wArg06;

    if ((s16)wArg06 > (s16)LG16(0x6CC8))
    {
        ax_13 = wArg06;
        if ((s16)wArg06 < (s16)LG16(0x6CCC))
        {
            ax_13 = wArg04;
            if ((s16)wArg04 > (s16)LG16(0x6CCA))
            {
                ax_13 = wArg04;
                if ((s16)wArg04 < (s16)LG16(0x6CCE))
                {
                    LG16(0x6CC4) = wArg06;
                    LG16(0x6CC6) = wArg04;
                    ax_13 = wArg04;
                }
            }
        }
    }
    return (u8)(ax_13 >> 8);
}

// 133F:0256: void vgaerr_set_cursor_step(u16 wArg04, u16 wArg06)
void vgaerr_set_cursor_step(u16 wArg04, u16 wArg06) /* was fn133F_0256 */
{
    LG16(0x6CC0) = wArg06;
    LG16(0x6CC2) = wArg04;
}

// 133F:026B: u8 vgaerr_display_position_error(u16 wArg04, u16 wArg06, u16 * dxOut, void * dsOut)
u8 vgaerr_display_position_error(u16 wArg04, u16 wArg06, u16 *dxOut, void *dsOut) /* was fn133F_026B */
{
    u8  abLoc0108[0x108];      /* [bp-0x108] assembled message */
    u8  abLoc08[4];            /* [bp-8]  formatted number 1 */
    u8  abLoc04[4];            /* [bp-4]  formatted number 2 */
    s32 num;
    s16 quot;
    u32 dw;

    /* (6CC4-6CC8)/6CC0 sign-extended, then cwd -> sign-extended quotient */
    num = (s32)(s16)(u16)(LG16(0x6CC4) - LG16(0x6CC8));
    quot = (s16)(num / (s16)LG16(0x6CC0));
    dw = (u32)(s32)quot;
    fn1EDA_0F26(0x02, abLoc04, 0x02, dw);

    num = (s32)(s16)(u16)(LG16(0x6CC6) - LG16(0x6CCA));
    quot = (s16)(num / (s16)LG16(0x6CC2));
    dw = (u32)(s32)quot;
    fn1EDA_0F26(0x02, abLoc08, 0x02, dw);

    fn1EDA_0A1F(abLoc04, abLoc0108);
    fn1EDA_0AAC(&g_seg133F[0x0269], abLoc0108);
    fn1EDA_0AAC(abLoc08, abLoc0108);
    /* original: vgaerr_draw_error_rect(ss:bp-108h, 1, 0, wArg04, wArg06) */
    (void)vgaerr_draw_error_rect(abLoc0108, 0x01, 0x00, wArg04, wArg06, dxOut, (u16 *)dsOut);
    return 0x00;   /* Reko: return 0x00 (asm leaves 014B's AL, ignored) */
}

// 133F:02DF: void vgaerr_strip_trailing_space(u8 * ptrArg04, u8 bArg08)
void vgaerr_strip_trailing_space(u8 *ptrArg04, u8 bArg08) /* was fn133F_02DF */
{
    u8 abLoc0200[0x100];       /* [bp-0x200] */
    u8 abLoc0100[0x100];       /* [bp-0x100] */
    u16 dx_170;
    u16 dx_172;
    u16 dx_171;

    fn1EDA_0A39(0xFF, abLoc0100, ptrArg04, &dx_170);

l133F_02F6:
    if (abLoc0100[abLoc0100[0]] == 0x20)
    {
        /* original: fn1EDA_0A6B(bLen-1, 1, ss:bp-100h, ss:bp-200h) */
        fn1EDA_0A6B((u16)(abLoc0100[0] - 0x01), 0x01, abLoc0100, abLoc0200);
        fn1EDA_0A39(0xFF, abLoc0100, abLoc0200, &dx_172);
        goto l133F_02F6;
    }

    /* original: fn1EDA_0A39(FFh, ds:(bArg08<<8)+6DEAh, ss:bp-100h) */
    fn1EDA_0A39(0xFF, &g_dgroup[(u16)(((u16)bArg08 << 8) + 0x6DEA)],
                abLoc0100, &dx_171);
}

// 133F:0352: u16 vgaerr_setup_text_rectangle(u8 * ptrArg04, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E, u8 bArg10)
u16 vgaerr_setup_text_rectangle(u8 *ptrArg04, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E, u8 bArg10) /* was fn133F_0352 */
{
    u8  abLoc0100[0x100];      /* [bp-0x100] */
    u16 dx_325;
    u16 dx_326, dx_327, dx_328, dx_329, dx_330, dx_331;
    u16 ds_240 = 0x0000;
    u16 w50CA;
    s16 d1, d2, q1, q2;
    u16 t1, t2;

    fn1EDA_0A39(0xFF, abLoc0100, ptrArg04, &dx_325);

    LG8(0x6CD0) = (u8)(LG8(0x6CD0) + 0x01);
    LG8((u16)(LG8(0x6CD0) + 0x6DCA)) = bArg10;
    LG16((u16)(LG8(0x6CD0) * 0x02 + 0x6CD2)) = wArg0E;
    LG16((u16)(LG8(0x6CD0) * 0x02 + 0x6D10)) = wArg0A;
    LG16((u16)(LG8(0x6CD0) * 0x02 + 0x6D4E)) = wArg0C;
    LG16((u16)(LG8(0x6CD0) * 0x02 + 0x6D8C)) = wArg08;
    (void)bgi_clip_text_rectangle(wArg08, wArg0A, wArg0C, wArg0E);

    w50CA = LG16(0x50CA);
    (void)bgi_set_pixel((u16)(wArg0C + w50CA), (u16)(wArg0E - w50CA),
                      wArg0C, wArg0E, &dx_326);
    (void)bgi_set_pixel((u16)(wArg08 + w50CA), (u16)(wArg0E - w50CA),
                      (u16)(wArg0C + w50CA), (u16)(wArg0E - w50CA), &dx_327);
    (void)bgi_set_pixel((u16)(wArg08 + w50CA), (u16)(wArg0A - w50CA),
                      (u16)(wArg08 + w50CA), (u16)(wArg0E - w50CA), &dx_328);
    (void)bgi_set_pixel((u16)(wArg08 + w50CA), (u16)(wArg0A - w50CA),
                      wArg08, wArg0A, &dx_329);
    (void)bgi_set_pixel(wArg08, wArg0E, (u16)(wArg08 + w50CA),
                      (u16)(wArg0E - w50CA), &dx_330);

    /* original: vgaerr_draw_error_rect(buf, 1, 0,
     *            wArg0C + (wArg08-wArg0C)/2, wArg0E + (wArg0A-wArg0E)/2) */
    d2 = (s16)(u16)(wArg08 - wArg0C);
    q2 = (s16)(d2 / 2);
    t2 = (u16)(q2 + wArg0C);
    d1 = (s16)(u16)(wArg0A - wArg0E);
    q1 = (s16)(d1 / 2);
    t1 = (u16)(q1 + wArg0E);
    (void)vgaerr_draw_error_rect(abLoc0100, 0x01, 0x00, t2, t1, &dx_331, &ds_240);

    vgaerr_strip_trailing_space(abLoc0100, LG8(0x6CD0));
    return ds_240;   /* DGROUP selector returned by the original */
}

// 133F:04A7: void vgaerr_reset_message_counter(void)
void vgaerr_reset_message_counter(void) /* was fn133F_04A7 */
{
    LG8(0x6CD0) = 0x00;
}

// 133F:04B1: u16 vgaerr_configure_text_area(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A, void * dsOut)
u16 vgaerr_configure_text_area(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A, void *dsOut) /* was fn133F_04B1 */
{
    vgaerr_set_text_window(wArg04, wArg06, wArg08, wArg0A);
    /* original: config_set_h_range(wArg06, wArg0A) */
    (void)config_set_h_range(wArg06, wArg0A);
    /* original: config_set_v_range(wArg04, wArg08); its AX is the result */
    return config_set_v_range(wArg04, wArg08, dsOut);
}

// 133F:04DE: u16 vgaerr_init_text_area(u8 * ptrArg04)
u16 vgaerr_init_text_area(u8 *ptrArg04) /* was fn133F_04DE */
{
    u8  abLoc0100[0x100];      /* [bp-0x100] */
    u16 dx_129;
    u16 ax10CE, ax10E1;
    u16 ds_61 = 0x0000;
    u16 dx_132 = 0, bp_99 = 0, ds_103 = 0;
    u16 bp_130 = 0, ds_131 = 0;

    fn1EDA_0A39(0xFF, abLoc0100, ptrArg04, &dx_129);
    ax10CE = bgi_get_text_cols();
    ax10E1 = bgi_get_text_rows();
    /* original: vgaerr_configure_text_area(10E1, 10CE, 0, 0) */
    (void)vgaerr_configure_text_area(ax10E1, ax10CE, 0x0000, 0x0000, &ds_61);
    /* The original reads two further incoming words [bp+0Eh]/[bp+10h]
     * (0x0192 / 0x0064 at the sole call site 1229:0D79) that the frozen
     * prototype cannot carry; see docs/notes-133F.md ("Uncertain sites"). */
    LG16(0xB6B6) = 0x0064;
    LG16(0xB6B8) = 0x0192;
    /* original: config_mouse_set_position([bp+0Eh], [bp+10h]) */
    (void)config_mouse_set_position(0x0192, 0x0064, &bp_130, &ds_131);
    (void)vgaerr_hide_cursor((s16 *)&dx_132, &bp_99, &ds_103);
    return ds_103;   /* DGROUP selector returned by the original */
}

// 133F:0528: u16 vgaerr_read_input(s16 dx, u8 * ptrArg06, u8 * ptrArg0A, u8 * ptrArg0E, s16 * dxOut, u16 * bpOut, u16 * dsOut)
u16 vgaerr_read_input(s16 dx, u8 *ptrArg06, u8 *ptrArg0A, u8 *ptrArg0E,
                s16 *dxOut, u16 *bpOut, u16 *dsOut) /* was fn133F_0528 */
{
    u8  bLoc1;                 /* [bp-1]  result flag (AL at retf) */
    u8  bLoc2;                 /* [bp-2]  key code / scan code */
    u8  bLoc3;                 /* [bp-3]  table key */
    u8  bLoc4;                 /* [bp-4]  loop index */
    u8  bLoc5;                 /* [bp-5]  6CD0 count */
    /* [bp+6]: the original's first stack argument.  The frozen prototype's
     * scalar `dx` parameter carries it in the flat port (see notes). */
    u8  bFlag = (u8)dx;
    s16 dx_cur = dx;           /* DX value tracked across the calls */
    u16 bp_tmp = 0;            /* 13C8 out (ignored) */
    u16 ds_tmp = 0;            /* 13C8 out (ignored) */

    bLoc1 = 0x00;
    *(u16 *)ptrArg0E = 0x0000;             /* key  */
    *(u16 *)ptrArg0A = LG16(0x6CC4);       /* x    */
    *(u16 *)ptrArg06 = LG16(0x6CC6);       /* y    */

    if (fn1E78_02FB() == 0x00)
        goto l133F_0715;

    /* ---- character available ---- */
    bLoc2 = (u8)fn1E78_030D(dx_cur, 0x0000, (u16 *)&dx_cur);
    if (bLoc2 == 0x0D)
    {
        *(u16 *)ptrArg0E = 0x0001;         /* Enter */
        goto l133F_065D;
    }
    if (bLoc2 == 0x1B)
    {
        *(u16 *)ptrArg0E = 0x001B;         /* Esc */
        goto l133F_065D;
    }
    if (bLoc2 >= 0x21 && bLoc2 <= 0x7D)
    {
        *(u16 *)ptrArg0E = (u16)fn1EDA_1384(bLoc2);
        goto l133F_065D;
    }
    if (bLoc2 != 0x00)
        goto l133F_065D;

    /* ---- extended (scan) code ---- */
    bLoc2 = (u8)fn1E78_030D(dx_cur, 0x0000, (u16 *)&dx_cur);
    if (bLoc2 >= 0x3B && bLoc2 <= 0x40)
    {
        *(u16 *)ptrArg0E = (u16)bLoc2;
        goto l133F_065D;
    }
    if (bLoc2 == 0x4B)                     /* left */
    {
        dx_cur = (s16)config_mouse_set_position(LG16(0x6CC6), (u16)(LG16(0x6CC4) - LG16(0x6CC0)),
                                  &bp_tmp, &ds_tmp);
        (void)vgaerr_clamp_coordinates(LG16(0x6CC6), (u16)(LG16(0x6CC4) - LG16(0x6CC0)));
        goto l133F_065D;
    }
    if (bLoc2 == 0x48)                     /* up */
    {
        dx_cur = (s16)config_mouse_set_position((u16)(LG16(0x6CC6) - LG16(0x6CC2)), LG16(0x6CC4),
                                  &bp_tmp, &ds_tmp);
        (void)vgaerr_clamp_coordinates((u16)(LG16(0x6CC6) - LG16(0x6CC2)), LG16(0x6CC4));
        goto l133F_065D;
    }
    if (bLoc2 == 0x50)                     /* down */
    {
        dx_cur = (s16)config_mouse_set_position((u16)(LG16(0x6CC6) + LG16(0x6CC2)), LG16(0x6CC4),
                                  &bp_tmp, &ds_tmp);
        (void)vgaerr_clamp_coordinates((u16)(LG16(0x6CC6) + LG16(0x6CC2)), LG16(0x6CC4));
        goto l133F_065D;
    }
    if (bLoc2 == 0x4D)                     /* right */
    {
        dx_cur = (s16)config_mouse_set_position(LG16(0x6CC6), (u16)(LG16(0x6CC4) + LG16(0x6CC0)),
                                  &bp_tmp, &ds_tmp);
        (void)vgaerr_clamp_coordinates(LG16(0x6CC6), (u16)(LG16(0x6CC4) + LG16(0x6CC0)));
        goto l133F_065D;
    }

l133F_065D:
    if (*(u16 *)ptrArg0E == 0x0000)
        goto l133F_06FE;
    bLoc1 = 0x01;
    if (*(u16 *)ptrArg0E != 0x0001)
        goto l133F_06FE;
    bLoc5 = LG8(0x6CD0);
    if ((u8)0x01 > bLoc5)
        goto l133F_06FE;
    bLoc4 = 0x01;
    goto l133F_068E;

l133F_068B:
    ++bLoc4;

l133F_068E:
    {
        u16 off = (u16)(bLoc4 * 0x02);
        if ((s16)LG16((u16)(off + 0x6CD2)) >= (s16)LG16(0x6CC4))
            goto l133F_06F6;
        if ((s16)LG16((u16)(off + 0x6D10)) <= (s16)LG16(0x6CC4))
            goto l133F_06F6;
        if ((s16)LG16((u16)(off + 0x6D4E)) >= (s16)LG16(0x6CC6))
            goto l133F_06F6;
        if ((s16)LG16((u16)(off + 0x6D8C)) <= (s16)LG16(0x6CC6))
            goto l133F_06F6;
        bLoc3 = LG8((u16)(bLoc4 + 0x6DCA));
        *(u16 *)ptrArg0E = (u16)bLoc3;
        goto l133F_080F;
    }

l133F_06F6:
    if (bLoc4 != bLoc5)
        goto l133F_068B;

l133F_06FE:
    if (bFlag != 0x00)
        (void)vgaerr_display_position_error(0x017F, 0x026A, (u16 *)&dx_cur, dsOut);
    bLoc1 = 0x01;
    goto l133F_080F;

l133F_0715:
    if (LG8(0xB6B2) == 0x00)
        goto l133F_080F;

    /* original: config_mouse_get_position(ptrArg06, ptrArg0A, ptrArg0E) */
    dx_cur = (s16)config_mouse_get_position((u16 *)ptrArg06, (u16 *)ptrArg0A, (u16 *)ptrArg0E,
                              &bp_tmp, &ds_tmp);
    if (*(u16 *)ptrArg0E == 0x0000)
        goto l133F_07D3;
    bLoc1 = 0x01;
    if (*(u16 *)ptrArg0E != 0x0001)
        goto l133F_07D3;
    bLoc5 = LG8(0x6CD0);
    if ((u8)0x01 > bLoc5)
        goto l133F_07D3;
    bLoc4 = 0x01;
    goto l133F_0764;

l133F_0761:
    ++bLoc4;

l133F_0764:
    {
        u16 off = (u16)(bLoc4 * 0x02);
        if ((s16)LG16((u16)(off + 0x6CD2)) >= (s16)LG16(0x6CC4))
            goto l133F_07CB;
        if ((s16)LG16((u16)(off + 0x6D10)) <= (s16)LG16(0x6CC4))
            goto l133F_07CB;
        if ((s16)LG16((u16)(off + 0x6D4E)) >= (s16)LG16(0x6CC6))
            goto l133F_07CB;
        if ((s16)LG16((u16)(off + 0x6D8C)) <= (s16)LG16(0x6CC6))
            goto l133F_07CB;
        bLoc3 = LG8((u16)(bLoc4 + 0x6DCA));
        *(u16 *)ptrArg0E = (u16)bLoc3;
        goto l133F_080F;
    }

l133F_07CB:
    if (bLoc4 != bLoc5)
        goto l133F_0761;

l133F_07D3:
    if (*(u16 *)ptrArg0A != LG16(0x6CC4))
        goto l133F_07EB;
    if (*(u16 *)ptrArg06 == LG16(0x6CC6))
        goto l133F_080F;

l133F_07EB:
    (void)vgaerr_clamp_coordinates(*(u16 *)ptrArg06, *(u16 *)ptrArg0A);
    bLoc1 = 0x01;
    if (bFlag != 0x00)
        (void)vgaerr_display_position_error(0x017F, 0x026A, (u16 *)&dx_cur, dsOut);

l133F_080F:
    *dxOut = dx_cur;
    *bpOut = 0x0000;   /* Reko-modelled saved-BP output; not meaningful here */
    *dsOut = 0x0000;   /* DGROUP selector dropped in the flat model */
    return (u16)bLoc1;
}

// 133F:0816: u16 vgaerr_init(void)
u16 vgaerr_init(void) /* was fn133F_0816 */
{
    u16 ds_15;

    (void)vgaerr_init_bgi(&ds_15);
    return ds_15;
}
