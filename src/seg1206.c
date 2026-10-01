/* seg1206.c -- RAD V3.1 segment 1206, recovered from RAD_1206.asm.
 *
 * Literal recovery.  Segment 1206 is the mouse (INT 33h) interface used by
 * the text-mode menus: every wrapper builds a 0x14-byte register frame and
 * issues the interrupt through dos_interrupt_trampoline (1E5F:000B), the register-frame
 * interrupt trampoline (PAL: pal_int_dispatch()).  There is no direct
 * int 10h / int 16h / int 21h instruction, no in/out port site, no
 * __cli/__sti and no int 23h here, so no PAL call is issued in this file.
 *
 * The prototypes in seg1206.h (frozen, derived from
 * analysis/summary/iface.tsv) are adopted exactly.  Like the sister mouse
 * segment 13C8, they express Reko's register outputs as pointer parameters
 * and omit several stack word arguments the original passes.  The sites that
 * therefore could not be recovered literally are listed in
 * docs/notes-small-segs.md ("## 1206").
 *
 * DGROUP offsets: 0x597A, 0x597C (reset status), 0x597E (mouse-present
 * flag), 0x5980 (button latch), 0x5982/0x5984 (cursor x/y), 0x598C
 * (cursor-shown latch).  All became LG8/LG16 per CONVENTIONS.md.
 */
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1206.h"
#include "seg1E5F.h"

/* Register frame exchanged with dos_interrupt_trampoline.  Its post-interrupt
 * continuation at 1E5F:0045 stores AX,BX,CX,DX,BP,SI,DI,DS,ES,FLAGS at
 * byte offsets 0,2,...,0x12 (ten words); every wrapper below reserves
 * exactly this 0x14-byte frame (`enter 14h`). */
typedef struct {
    u16 ax, bx, cx, dx, bp, si, di, ds, es, flags;
} TRegFrame;

// 1206:0000: u8 renamed_1206_0000(void)
u8 renamed_1206_0000(void)
{
    return 0x01;
}

// 1206:000D: u16 renamed_1206_000d(u16 * siOut, void * esOut, void * dsOut)
u16 renamed_1206_000d(u16 *siOut, void *esOut, void *dsOut)
{
    TRegFrame r = {0};

    r.ax = 0x0000;              /* INT 33h function 0: driver status / reset */
    dos_interrupt_trampoline((u8 *)&r, 0x33);

    *siOut = r.bx;              /* [bp+06h] <- BX (frame word 1) */
    *(u16 *)esOut = r.ax;       /* [bp+0Ah] <- AX (frame word 0) */
    (void)dsOut;                /* DS selector output dropped in flat model */
    return r.bx;                /* AX at retf = frame word 1 */
}

// 1206:0038: u8 renamed_1206_0038(u8 * chOut, u16 * dxOut, void * bpOut, u16 * dsOut)
u8 renamed_1206_0038(u8 *chOut, u16 *dxOut, void *bpOut, u16 *dsOut)
{
    TRegFrame r = {0};

    if (LG8(0x597E) != 0x00 && LG8(0x598C) == 0x00)
    {
        LG8(0x598C) = 0x01;
        r.ax = 0x0001;          /* INT 33h function 1: show mouse cursor */
        dos_interrupt_trampoline((u8 *)&r, 0x33);

        *chOut = (u8)(r.cx >> 8);   /* CH register output */
        *dxOut = r.dx;              /* DX register output */
        *(u16 *)bpOut = r.bp;       /* BP register output */
        (void)dsOut;                /* DS selector output dropped */
        return (u8)(r.ax >> 8);     /* AH */
    }
    return 0x00;
}

// 1206:0066: u8 renamed_1206_0066(void * bpOut, u16 * dsOut)
u8 renamed_1206_0066(void *bpOut, u16 *dsOut)
{
    TRegFrame r = {0};

    if (LG8(0x597E) != 0x00 && LG8(0x598C) != 0x00)
    {
        LG8(0x598C) = 0x00;
        r.ax = 0x0002;          /* INT 33h function 2: hide mouse cursor */
        dos_interrupt_trampoline((u8 *)&r, 0x33);

        *(u16 *)bpOut = r.bp;   /* BP register output */
        (void)dsOut;            /* DS selector output dropped */
        return (u8)(r.ax >> 8); /* AH */
    }
    return 0x00;
}

// 1206:0094: u8 renamed_1206_0094(u16 * dxOut, u16 * bpOut, u16 * dsOut)
u8 renamed_1206_0094(u16 *dxOut, u16 *bpOut, u16 *dsOut)
{
    TRegFrame r = {0};

    if (LG8(0x597E) != 0x00)
    {
        r.ax = 0x0003;          /* INT 33h function 3: get position, buttons */
        dos_interrupt_trampoline((u8 *)&r, 0x33);

        *dxOut = r.dx;          /* [bp+06h] <- DX (cursor y) */
        *bpOut = r.cx;          /* [bp+0Ah] <- CX (cursor x) */
        *dsOut = r.bx;          /* [bp+0Eh] <- BX (button state) */
        return (u8)r.bx;        /* AX at retf = frame word 1 */
    }
    return 0x00;
}

// 1206:00D1: u16 renamed_1206_00d1(void * ds, u16 * siOut, void * esOut, void * dsOut)
u16 renamed_1206_00d1(void *ds, u16 *siOut, void *esOut, void *dsOut)
{
    TRegFrame r = {0};

    (void)ds;                   /* DGROUP selector input dropped */
    if (LG8(0x597E) != 0x00)
    {
        r.ax = 0x0004;          /* INT 33h function 4: set cursor position */
        /* original: r.cx <- [bp+08h] (arg2), r.dx <- [bp+06h] (arg1);
         * the frozen prototype has no slots for these two word arguments,
         * so the frame words stay at their zero-initialised value. */
        dos_interrupt_trampoline((u8 *)&r, 0x33);
    }
    *siOut = r.si;              /* SI register output */
    *(u16 *)esOut = r.es;       /* ES register output */
    (void)dsOut;                /* DS selector output dropped */
    return r.ax;                /* AX at retf (trampoline register image) */
}

// 1206:00FF: u16 renamed_1206_00ff(u16 * dsOut)
u16 renamed_1206_00ff(u16 *dsOut)
{
    TRegFrame r = {0};

    if (LG8(0x597E) != 0x00)
    {
        r.ax = 0x0007;          /* INT 33h function 7: set horizontal range */
        /* original: r.cx <- [bp+08h], r.dx <- [bp+06h]; not representable
         * in the frozen prototype, frame words stay zero. */
        dos_interrupt_trampoline((u8 *)&r, 0x33);
    }
    (void)dsOut;                /* DS selector output dropped */
    return r.ax;
}

// 1206:012D: u16 renamed_1206_012d(void * ds, void * dsOut)
u16 renamed_1206_012d(void *ds, void *dsOut)
{
    TRegFrame r = {0};

    (void)ds;                   /* DGROUP selector input dropped */
    if (LG8(0x597E) != 0x00)
    {
        r.ax = 0x0008;          /* INT 33h function 8: set vertical range */
        /* original: r.cx <- [bp+08h], r.dx <- [bp+06h]; not representable
         * in the frozen prototype, frame words stay zero. */
        dos_interrupt_trampoline((u8 *)&r, 0x33);
    }
    (void)dsOut;                /* DS selector output dropped */
    return r.ax;
}

// 1206:015B: u16 renamed_1206_015b(u8 * chOut, u16 * dxOut, void * bpOut, u16 * dsOut)
u16 renamed_1206_015b(u8 *chOut, u16 *dxOut, void *bpOut, u16 *dsOut)
{
    u8  bResult = 0x00;         /* [bp-1h] result flag */
    u16 wLoc04 = 0x0000;        /* [bp-4h] BX (button state) after 0094 */
    u16 wLoc06 = 0x0000;        /* [bp-6h] CX (cursor x) after 0094 */
    u16 wLoc08 = 0x0000;        /* [bp-8h] DX (cursor y) after 0094 */
    u16 wArg06 = 0x0000;        /* [bp+6h] stack argument: every caller of
                                 * 1206:015B pushes 0 and the frozen
                                 * prototype has no slot for it. */

    if (LG8(0x597E) != 0x00)
    {
        /* original: renamed_1206_0094(ss:bp-8, ss:bp-6, ss:bp-4) */
        (void)renamed_1206_0094(&wLoc08, &wLoc06, &wLoc04);

        LG16(0x5982) = wLoc06;      /* mov [5982h],ax  (cursor x) */
        LG16(0x5984) = wLoc08;      /* mov [5984h],ax  (cursor y) */

        if (wLoc04 != 0x00)
        {
            if (wArg06 == 0x00)
                bResult = 0x01;
            else if (wLoc04 == wArg06)
                bResult = 0x01;
        }
    }

    *chOut = (u8)(wLoc06 >> 8);     /* CH register output */
    *dxOut = wLoc08;                /* DX register output */
    *(u16 *)bpOut = 0x0000;         /* BP register-preservation artifact */
    (void)dsOut;                    /* DS selector output dropped */

    /* AX at retf = frame word 3 (DX) with AL replaced by the result flag. */
    return (u16)((wLoc08 & 0xFF00) | (u16)bResult);
}

// 1206:01AC: u16 renamed_1206_01ac(u16 * siOut, void * esOut, u16 * dsOut)
u16 renamed_1206_01ac(u16 *siOut, void *esOut, u16 *dsOut)
{
    u16  siLoc = 0x0000;
    void *esLoc = 0;
    u16  dsLoc = 0x0000;
    u16  bpLoc = 0x0000;

    LG8(0x597E) = 0x00;         /* mov byte ptr [597Eh],0h */

    if (renamed_1206_0000() != 0x00)
    {
        /* original: renamed_1206_000d(ds:597Ch, ds:597Ah) */
        bpLoc = renamed_1206_000d((u16 *)&g_dgroup[0x597C],
                            (void *)&g_dgroup[0x597A], &dsLoc);

        if (LG16(0x597A) != 0x00)   /* cmp word ptr [597Ah],0h */
            LG8(0x597E) = 0x01;

        if (LG8(0x597E) != 0x00)
        {
            LG8(0x598C) = 0x00;

            /* original: renamed_1206_0094(ds:5984h, ds:5982h, ds:5980h) */
            (void)renamed_1206_0094((u16 *)&g_dgroup[0x5984],
                              (u16 *)&g_dgroup[0x5982],
                              (u16 *)&g_dgroup[0x5980]);

            /* The original pushes two word arguments before each call; the
             * frozen prototypes carry none (see notes).  Only the register
             * outputs can be forwarded. */
            (void)renamed_1206_00ff(&dsLoc);
            (void)renamed_1206_012d(0, &dsLoc);
            bpLoc = renamed_1206_00d1(0, &siLoc, &esLoc, &dsLoc);
        }
    }

    *siOut = siLoc;
    *(u16 *)esOut = (u16)(uintptr_t)esLoc;
    (void)dsOut;                /* DS selector output dropped */
    return bpLoc;
}

// 1206:0217: u8 * fn1206_0217(u16 * bpOut, void * dsOut)
u8 *fn1206_0217(u16 *bpOut, void *dsOut)
{
    u16  siLoc = 0x0000;
    void *esLoc = 0;
    u16  dsLoc = 0x0000;
    u16  bpLoc;

    /* original pushes 0,0,27Fh,1DFh,0,0 (six word args) for renamed_1206_01ac;
     * the frozen prototype of 01AC has no slots for them. */
    bpLoc = renamed_1206_01ac(&siLoc, &esLoc, &dsLoc);

    *bpOut = bpLoc;             /* BP register output of 01AC */
    (void)dsOut;                /* DS selector output dropped */
    return (u8 *)(uintptr_t)siLoc;  /* SI register output of 01AC */
}
