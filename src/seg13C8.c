/* seg13C8.c -- RAD V3.1 segment 13C8, recovered from RAD_13C8.asm.
 *
 * This segment is the mouse (INT 33h) interface.  Every wrapper builds a
 * 0x14-byte register frame and invokes INT 33h through dos_interrupt_trampoline
 * (1E5F:000B), the register-frame interrupt trampoline, which dispatches
 * through pal_int_dispatch() (vector 0x33, SDL mouse emulation; see
 * pal/int.c).  There are no direct int 10h/16h/21h instructions, no in/out
 * port sites, no __cli/__sti and no int 23h here.
 *
 * The prototypes in seg13C8.h (regenerated from analysis/summary/iface.tsv)
 * carry the far out-pointer stack arguments the original wrappers write, so
 * the stores the earlier frozen prototypes forced us to drop are restored.
 * See docs/notes-13C1-13C8.md for the repair.
 */
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg13C8.h"
#include "seg1EDA.h"
#include "seg1E5F.h"

/* Register frame exchanged with dos_interrupt_trampoline.  Its post-interrupt
 * continuation at 1E5F:0045 stores AX,BX,CX,DX,BP,SI,DI,DS,ES,FLAGS at
 * byte offsets 0,2,...,0x12 (ten words); every wrapper below reserves
 * exactly this 0x14-byte frame (`enter 14h`). */
typedef struct {
    u16 ax, bx, cx, dx, bp, si, di, ds, es, flags;
} TRegFrame;

// 13C8:0000: u8 config_mouse_is_present(void)
u8 config_mouse_is_present(void) /* was fn13C8_0000 */
{
    return 0x01;
}

// 13C8:000D: u16 config_mouse_reset(u16 * ptrArg06, u16 * ptrArg0A, void * dsOut)
u16 config_mouse_reset(u16 * ptrArg06, u16 * ptrArg0A, void * dsOut) /* was fn13C8_000D */
{
    TRegFrame r = {0};

    r.ax = 0x0000;      /* INT 33h function 0: driver status / reset */
    dos_interrupt_trampoline((u8 *)&r, 0x33);

    *ptrArg0A = r.ax;       /* [bp+0Ah] <- AX (driver status) */
    *ptrArg06 = r.bx;       /* [bp+06h] <- BX (button count)  */
    return r.bx;            /* AX at retf after the second store */
}

// 13C8:0038: u8 config_show_cursor(u16 * dxOut, u16 * bpOut, void * dsOut)
u8 config_show_cursor(u16 * dxOut, u16 * bpOut, void * dsOut) /* was fn13C8_0038 */
{
    TRegFrame r = {0};

    r.ax = 0x0001;      /* INT 33h function 1: show mouse cursor */
    dos_interrupt_trampoline((u8 *)&r, 0x33);

    *dxOut = r.dx;
    *bpOut = r.bp;
    return (u8)(r.ax >> 8);     /* AH */
}

// 13C8:004F: u8 config_hide_cursor(u16 * dxOut, u16 * bpOut, void * dsOut)
u8 config_hide_cursor(u16 * dxOut, u16 * bpOut, void * dsOut) /* was fn13C8_004F */
{
    TRegFrame r = {0};

    r.ax = 0x0002;      /* INT 33h function 2: hide mouse cursor */
    dos_interrupt_trampoline((u8 *)&r, 0x33);

    *dxOut = r.dx;
    *bpOut = r.bp;
    return (u8)(r.ax >> 8);     /* AH */
}

// 13C8:0066: u16 config_mouse_get_position(u16 * ptrArg06, u16 * ptrArg0A, u16 * ptrArg0E, void * bpOut, void * dsOut)
u16 config_mouse_get_position(u16 * ptrArg06, u16 * ptrArg0A, u16 * ptrArg0E, void * bpOut, void * dsOut) /* was fn13C8_0066 */
{
    TRegFrame r = {0};

    r.ax = 0x0003;      /* INT 33h function 3: get position and buttons */
    dos_interrupt_trampoline((u8 *)&r, 0x33);

    *ptrArg0A = r.cx;       /* [bp+0Ah] <- CX (x)      */
    *ptrArg06 = r.dx;       /* [bp+06h] <- DX (y)      */
    *ptrArg0E = r.bx;       /* [bp+0Eh] <- BX (buttons)*/
    return r.bx;            /* AX at retf after the last load */
}

// 13C8:009A: u16 config_mouse_set_position(u16 wArg06, u16 wArg08, void * bpOut, void * dsOut)
u16 config_mouse_set_position(u16 wArg06, u16 wArg08, void * bpOut, void * dsOut) /* was fn13C8_009A */
{
    TRegFrame r = {0};

    r.ax = 0x0004;      /* INT 33h function 4: set cursor position */
    r.cx = wArg08;      /* [bp+08h] -> CX */
    r.dx = wArg06;      /* [bp+06h] -> DX */
    dos_interrupt_trampoline((u8 *)&r, 0x33);

    return r.ax;
}

// 13C8:00BF: u16 config_set_h_range(u16 wArg06, u16 wArg08)
u16 config_set_h_range(u16 wArg06, u16 wArg08) /* was fn13C8_00BF */
{
    TRegFrame r = {0};

    r.ax = 0x0007;      /* INT 33h function 7: set horizontal range */
    r.cx = wArg08;      /* [bp+08h] -> CX */
    r.dx = wArg06;      /* [bp+06h] -> DX */
    dos_interrupt_trampoline((u8 *)&r, 0x33);

    return r.ax;
}

// 13C8:00E4: u16 config_set_v_range(u16 wArg06, u16 wArg08, void * dsOut)
u16 config_set_v_range(u16 wArg06, u16 wArg08, void * dsOut) /* was fn13C8_00E4 */
{
    TRegFrame r = {0};

    r.ax = 0x0008;      /* INT 33h function 8: set vertical range */
    r.cx = wArg08;      /* [bp+08h] -> CX */
    r.dx = wArg06;      /* [bp+06h] -> DX */
    dos_interrupt_trampoline((u8 *)&r, 0x33);

    return r.ax;
}

// 13C8:0111: void * config_mouse_speed_threshold(u16 wArg06)
void * config_mouse_speed_threshold(u16 wArg06) /* was fn13C8_0111 */
{
    TRegFrame r = {0};
    u16 wLoc1A = 0;
    u16 psegLoc18 = 0;
    void *ds_41 = 0;

    r.ax = 0x0013;      /* INT 33h function 19h: speed threshold */
    /* fn1EDA_04B7's AX result is stored to frame DX (the original
     * `mov [bp-0Eh],ax`), so the prototype returns u16. */
    r.dx = fn1EDA_04B7(wArg06, (s16)wArg06, &g_seg1EDA[0x0109], wLoc1A, psegLoc18);
    dos_interrupt_trampoline((u8 *)&r, 0x33);
    ds_41 = (void *)(uintptr_t)r.ds;   /* Reko-modelled DS return (flat: 0) */
    return ds_41;
}

// 13C8:0139: void config_mouse_init(void * ds)
void config_mouse_init(void * ds) /* was fn13C8_0139 */
{
    LG8(0xB6B2) = 0x00;
    if (config_mouse_is_present() != 0x00)
    {
        void *ds_32 = 0;

        /* original: config_mouse_reset(ds:0B6B0, ds:0B6AE) */
        config_mouse_reset((u16 *)&g_dgroup[0xB6B0], (u16 *)&g_dgroup[0xB6AE], &ds_32);
        if (LG16(0xB6AE) != 0x00)
            LG8(0xB6B2) = 0x01;
        if (LG8(0xB6B2) != 0x00)
        {
            void *bp_171 = 0;
            void *ds_172 = 0;
            void *ds_173 = 0;

            /* original: config_mouse_get_position(ds:0B6B8, ds:0B6B6, ds:0B6B4) */
            config_mouse_get_position((u16 *)&g_dgroup[0xB6B8], (u16 *)&g_dgroup[0xB6B6],
                        (u16 *)&g_dgroup[0xB6B4], &bp_171, &ds_172);
            /* original: config_set_h_range(0280h, 0000h) */
            config_set_h_range(0x0280, 0x0000);
            /* original: config_set_v_range(01E0h, 0000h) */
            config_set_v_range(0x01E0, 0x0000, &ds_173);
        }
    }
}
