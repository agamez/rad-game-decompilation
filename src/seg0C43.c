/* seg0C43.c -- RAD V3.1 segment 0C43, recovered from RAD_0C43.asm.
 *
 * Literal recovery.  Segment 0C43 (6 functions, ascending offset
 * 0000/001E/0056/0095/00B9/02FB) is the mode-13h file/picture loader used by
 * renamed_0800_4255:
 *   - renamed_0c43_0000 / renamed_0c43_001e build the register frame at DGROUP:589Ch and
 *     issue INT 10h through dos_interrupt_trampoline (1E5F:000B), the register-frame
 *     interrupt trampoline (PAL: pal_int_dispatch()).  Both are vector 10h.
 *   - renamed_0c43_0056 is an RLE decoder that expands the far-heap block at
 *     ds:5884/5886 into VGA memory (es = [5882h] = 0A000h, set by 02FB).
 *   - renamed_0c43_0095 closes the stream block at ss:bp-0D4h and frees the far
 *     heap block.
 *   - renamed_0c43_00b9 opens a file, loads/decompresses it into VRAM and drives
 *     the small in-loop menu.
 *   - renamed_0c43_02fb seeds the VRAM selector word 5882h = 0A000h.
 *
 * There is no direct int 10h/int 16h/int 21h, no in/out port site, no
 * __cli/__sti and no int 23h in this segment; the two INT 10h issues go
 * through dos_interrupt_trampoline, whose PAL replacement is hardware, not this file.
 *
 * The frozen prototypes in seg0C43.h (from analysis/summary/iface.tsv) are
 * adopted exactly.  See docs/notes-small-segs.md ("## 0C43") for the sites
 * that the frozen cross-segment prototypes cannot carry.
 */
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C43.h"
#include "seg1EDA.h"
#include "seg1E5F.h"
#include "pal.h"

/* renamed_0c43_0000 / renamed_0c43_001e share the DGROUP register frame the trampoline
 * writes back.  1E5F:0045 stores AX,BX,CX,DX,BP,SI,DI,DS,ES,FLAGS at byte
 * offsets 0,2,...,0x12, so the frame occupies 589Ch..58AFh:
 *   589Ch AX  589Eh BX  58A0h CX  58A2h DX  58A4h BP
 *   58A6h SI  58A8h DI  58AAh DS  58ACh ES  58AEh FLAGS
 * (0x58AC is the ES word 001E fills; 0x58A2 the DX word.) */

/* renamed_0c43_00b9 runs with `enter 0E4h`: its locals are [bp-0E4h]..[bp-1h].
 * The original hands a pointer into this frame (SS:bp-0D4h) to renamed_0c43_0095
 * as a u16 word, so the frame is modelled as a file-static image whose base
 * stands in for SS.  FLOC(off) is the [bp-off] byte address. */
static u8 g_frame0C43_00B9[0x00E4];
#define FLOC(off) (g_frame0C43_00B9 + (u16)(0x00E4 - (off)))
#define FL16(off) (*(u16 *)FLOC(off))
#define FL8(off)  (*(u8  *)FLOC(off))

// 0C43:0000: u16 renamed_0c43_0000(u8 bArg02, void * dsOut)
u16 renamed_0c43_0000(u8 bArg02, void * dsOut)
{
    LG8(0x589D) = 0x00;                     /* AH = 00h */
    LG8(0x589C) = bArg02;                   /* AL = mode    */
    dos_interrupt_trampoline((u8 *)&g_dgroup[0x589C], 0x10);
    (void)dsOut;                            /* DS selector dropped (flat) */
    /* Reko returns the frame BP word (its bp_21 output); no caller consumes it. */
    return LG16(0x58A4);
}

// 0C43:001E: u16 renamed_0c43_001e(u8 * ptrArg02, u16 * bpOut, void * dsOut)
u16 renamed_0c43_001e(u8 * ptrArg02, u16 * bpOut, void * dsOut)
{
    LG8(0x589D) = 0x10;                     /* AH = 10h */
    LG8(0x589C) = 0x12;                     /* AL = 12h */
    /* les di,[bp+4h] twice: the caller pushes the far pointer DGROUP:5582h
     * (materialized flat as &g_dgroup[0x5582]).  Re-stage the frame's ES:DX
     * as the port's DGROUP segment (2014h, cf. far_ptr/far_seg_of) plus the
     * DGROUP-relative offset -- the host pointer's own address halves are
     * meaningless to the 16:16 register image. */
    LG16(0x58AC) = 0x2014;
    LG16(0x58A2) = (u16)((uintptr_t)ptrArg02 - (uintptr_t)g_dgroup);
    LG16(0x589E) = 0x0000;                  /* BX = 0   */
    LG16(0x58A0) = 0x0100;                  /* CX = 100h */
    dos_interrupt_trampoline((u8 *)&g_dgroup[0x589C], 0x10);
    *bpOut = LG16(0x58A4);                  /* Reko: frame BP word (bp_34) */
    (void)dsOut;                            /* DS selector dropped (flat) */
    /* AX at retf is the trampoline FLAGS word; no caller consumes it. */
    return LG16(0x58AE);
}

// 0C43:0056: void renamed_0c43_0056(void)
void renamed_0c43_0056(void)
{
    /* mov es,[5882h] ; mov di,[589Ah] ; xor cx,cx ; mov cl,[5892h] ;
     * mov bx,[5894h] ; push ds ; lds si,[5884h] ; add bx,si */
    u8 *es = pal_vga_memory();              /* [5882h] = 0A000h (set by 02FB) */
    u16 di = LG16(0x589A);
    u8  cl = LG8(0x5892);
    u16 si = LG16(0x5884);
    u16 start = si;                         /* low word of the ds:5884 pointer */
    u16 bx = (u16)(LG16(0x5894) + si);
    u8 *src = far_ptr(LG32(0x5884)); /* ds:si far pointer, flat */

    while (si != bx)
    {
        u8 al = src[(u16)(si - start)];     /* lodsb */
        ++si;
        if ((s8)cl <= 0x00)                 /* cmp cl,0h ; jg 0087h */
        {
            if (al >= 0xC0)                 /* cmp al,0C0h ; jc 0084h */
                cl = (u8)(al ^ 0xC0);       /* run-length prefix */
            else
            {
                es[di] = al;                /* stosb */
                ++di;
            }
        }
        else
        {
            while (cl != 0x00)              /* rep stosb */
            {
                es[di] = al;
                ++di;
                --cl;
            }
        }
    }
    LG16(0x589A) = di;
    LG8(0x5892) = cl;
}

// 0C43:0095: u16 renamed_0c43_0095(u16 ax, u16 wArg02, void * dsOut)
u16 renamed_0c43_0095(u16 ax, u16 wArg02, void * dsOut)
{
    /* mov di,[bp+4h] ; add di,0FF2Ch : the original resolves SS:bp-0D4h.
     * wArg02 is the caller's frame top as a 16-bit word (0E4h here); the
     * literal 16-bit add lands on the stream block at frame offset 10h. */
    u8 *pStream = g_frame0C43_00B9 + (u16)(wArg02 + 0xFF2C);
    u16 dx_41 = 0x0000;
    u16 ds_40 = 0x0000;
    u16 blkSeg = LG16(0x5886);
    u16 blkOff = LG16(0x5884);               /* push [5886h] ; push [5884h] */

    renamed_1eda_1051((u8)ax, pStream);           /* call far 1EDAh:1051h */
    (void)renamed_1eda_0254(0x00F1, blkOff, blkSeg, 0, &dx_41, &ds_40);
    (void)ds_40;
    (void)dsOut;                            /* DS selector dropped (flat) */
    return dx_41;
}

// 0C43:00B9: u16 renamed_0c43_00b9(u8 * ptrArg04, u16 * dsOut)
u16 renamed_0c43_00b9(u8 * ptrArg04, u16 * dsOut)
{
    u16 ds_45 = 0x0000;
    u16 ds_126 = 0x0000;
    u16 ds_172 = 0x0000;
    u16 ds_207 = 0x0000;
    u16 ds_217 = 0x0000;
    u16 ds_254 = 0x0000;
    u16 ds_307 = 0x0000;
    u16 ds_429 = 0x0000;
    u16 ds_470 = 0x0000;
    u16 ds_528 = 0x0000;
    u16 ds_602 = 0x0000;
    u8  ch_765 = 0x00;
    u8  ch_766 = 0x00;
    u8  ch_768 = 0x00;
    u8  ch_770 = 0x00;
    u8  ch_772 = 0x00;
    u8  ch_774 = 0x00;
    u8  ch_776 = 0x00;
    u8  ch_778 = 0x00;
    u16 dx_762 = 0x0000;
    u16 dx_621 = 0x0000;
    u16 bp_598 = 0x0000;
    u16 ax_754;
    u16 ax_758;
    u16 ax_597;
    u16 ax_392;
    u16 dx_393;
    u32 dx_ax_763;
    u32 dx_ax_757;

    (void)dsOut;                            /* DS selector dropped (flat) */

    /* les di,[bp+6h] ; push es ; push di ; lea di,[bp-50h] ; ... push 4Fh */
    (void)renamed_1eda_0a39(0x4F, FLOC(0x50), ptrArg04, &dx_762);
    /* push 13h ; call 0000h */
    (void)renamed_0c43_0000(0x13, &ds_45);
    /* lea di,[bp+0FF2Ch] ; ... lea di,[bp-50h] ; call 0FA2h */
    renamed_1eda_0fa2(FLOC(0x50), FLOC(0xD4));
    /* lea di,[bp+0FF2Ch] ; push 1h ; call 0FD0h */
    (void)renamed_1eda_0fd0(0x0001, FLOC(0xD4), &dx_621);

    {
        u16 ax_95 = renamed_1eda_04a2();
        LG8(0x556E) = (u8)((ax_95 != 0x0000) ? 0x01 : 0x00);
    }
    if (LG8(0x556E) != 0x00)
        return dx_621;                      /* 0106: jmp 02F7h */

    dx_ax_763 = fn1EDA_023F(0x00F1, 0x0000, 0x0000, &ds_126);
    LG16(0x5884) = (u16)dx_ax_763;          /* mov [5884h],ax */
    LG16(0x5886) = (u16)(dx_ax_763 >> 16);  /* mov [5886h],dx */
    /* lea di,[bp-0E0h] data buffer (dropped by 10BB), push 2, 0, 0 */
    (void)renamed_1eda_10bb((u8 *)0, 0x0002, FLOC(0xE0), FLOC(0xD4));
    (void)fn1EDA_04A9(0x0000, 0x0000, &ch_765, &ds_172);
    /* cmp byte [bp-0DFh],5h ; mov al,0 ; jnc */
    ax_754 = (u16)((FL8(0xDF) < 0x05) ? 0x0001 : 0x0000);
    LG8(0x556E) = (u8)ax_754;
    if (LG8(0x556E) != 0x00)
    {
        /* push bp */
        dx_621 = renamed_0c43_0095(ax_754, 0x00E4, &ds_45);
        return dx_621;                      /* 0147: jmp 02F7h */
    }

    /* 014E */
    {
        /* push 0F1h ; call 023Fh ; mov [5884h],ax ; mov [5886h],dx done above;
         * here: lea di,[bp-0FF2Ch] ; call 116Ah ; call 04A9h ;
         *       sub ax,301h ; sbb dx,0h ; mov [bp-0FF28h],ax ; [bp-0FF2Ah],dx */
        u16 ax_116A = renamed_1eda_116a(FLOC(0xD4), &ds_207);
        dx_ax_757 = fn1EDA_04A9(0x0000, 0x0000, &ch_766, &ds_217);
        /* The flat fn1EDA_04A9 cannot return the register-preserved DX (it
         * returns 0); keep 116Ah's AX and leave the high word as produced. */
        dx_ax_757 = (dx_ax_757 & 0xFFFF0000u) | (u32)ax_116A;
        FL16(0xD8) = (u16)((u16)dx_ax_757 - 0x0301);
        FL16(0xD6) = (u16)((u16)(dx_ax_757 >> 16) -
                           (u16)((u16)dx_ax_757 < 0x0301));
    }
    /* lea di,[bp-0FF2Ch] ; push 0h ; push 80h ; call 1123h ; call 04A9h */
    (void)renamed_1eda_1123(0x0080, 0x0000, FLOC(0xD4));
    (void)fn1EDA_04A9(0x0000, 0x0000, &ch_768, &ds_254);
    FL16(0xDC) = 0x0080;                    /* mov word [bp-0FF24h],80h */
    FL16(0xDA) = 0x0000;                    /* mov word [bp-0FF26h],0 */
    LG8(0x5892) = 0x00;                     /* mov byte [5892h],0 */
    LG16(0x589A) = 0x0000;                  /* xor ax,ax ; mov [589Ah],ax */

    /* l0C43_0197 */
    for (;;)
    {
        u16 r_1185;

        /* lea di,[bp-0FF2Ch] ; les di,[5884h] ; push 0F1h ;
         * mov di,5894h ; call 10BBh ; call 04A9h */
        (void)renamed_1eda_10bb((u8 *)&g_dgroup[0x5894], 0x00F1,
                          (u8 *)far_ptr(LG32(0x5884)), FLOC(0xD4));
        (void)fn1EDA_04A9(0x0000, 0x0000, &ch_776, &ds_307);

        /* mov ax,[5894h] ; xor dx,dx ; add [bp-0FF24h],ax ; adc [bp-0FF26h],dx */
        {
            u16 add = LG16(0x5894);
            u16 lo = FL16(0xDC);
            u16 hi = FL16(0xDA);
            u16 sum = (u16)(lo + add);
            u16 carry = (u16)(sum < lo);
            FL16(0xDC) = sum;
            FL16(0xDA) = (u16)(hi + carry);
        }
        /* mov ax,[bp-0FF24h] ; mov dx,[bp-0FF26h] ;
         * cmp dx,[bp-0FF2Ah] ; jg 01D7h ; jl 01EBh ;
         * cmp ax,[bp-0FF28h] ; jbe 01EBh */
        {
            u16 ax_322 = FL16(0xDC);
            u16 dx_323 = FL16(0xDA);
            u16 tgt_hi = FL16(0xD6);
            u16 tgt_lo = FL16(0xD8);
            if (dx_323 > tgt_hi || (dx_323 >= tgt_hi && ax_322 > tgt_lo))
            {
                /* mov ax,[bp-0FF24h] ; mov dx,[bp-0FF26h] ;
                 * sub ax,[bp-0FF28h] ; sbb dx,[bp-0FF2Ah] ;
                 * sub [5894h],ax */
                u16 lo = FL16(0xDC);
                u16 tlo = FL16(0xD8);
                LG16(0x5894) = (u16)(LG16(0x5894) - (u16)(lo - tlo));
            }
        }
        /* l0C43_01EB: call 0056h */
        renamed_0c43_0056();
        /* lea di,[bp-0FF2Ch] ; call 1185h ; call 04A9h ; or al,al ; jnz 021Bh */
        r_1185 = renamed_1eda_1185(FLOC(0xD4));
        (void)fn1EDA_04A9(0x0000, 0x0000, &ch_770, &ds_254);
        /* The flat 04A9 preserves no AL; keep 1185's low byte. */
        if ((u8)r_1185 != 0x00)
            break;
        ax_392 = FL16(0xDC);
        dx_393 = FL16(0xDA);
        /* while (dx <= tgt_hi && (dx < tgt_hi || ax < tgt_lo)) */
        if (!(dx_393 <= FL16(0xD6) &&
              (dx_393 < FL16(0xD6) || ax_392 < FL16(0xD8))))
            break;
    }

    /* l0C43_021B */
    (void)renamed_1eda_1123(FL16(0xD8), FL16(0xD6), FLOC(0xD4));
    (void)fn1EDA_04A9(0x0000, 0x0000, &ch_772, &ds_429);
    (void)renamed_1eda_10bb((u8 *)0, 0x0001, FLOC(0xDD), FLOC(0xD4));
    (void)fn1EDA_04A9(0x0000, 0x0000, &ch_774, &ds_470);
    /* cmp byte [bp-0FF23h],0Ch ; mov al,0 ; jz */
    ax_758 = (u16)((FL8(0xDD) != 0x0C) ? 0x0001 : 0x0000);
    LG8(0x556E) = (u8)ax_758;
    if (LG8(0x556E) != 0x00)
    {
        dx_621 = renamed_0c43_0095(ax_758, 0x00E4, &ds_45);
        return dx_621;                      /* 0263: jmp 02F7h */
    }

    /* l0C43_026A */
    (void)renamed_1eda_10bb((u8 *)0, 0x0300, &g_dgroup[0x5582], FLOC(0xD4));
    (void)fn1EDA_04A9(0x0000, 0x0000, &ch_778, &ds_528);
    FL8(0x51) = 0x00;                       /* mov byte [bp-51h],0 */
    for (;;)
    {
        /* mov al,[bp-51h] ; xor ah,ah ; mov di,ax ; mov si,di ;
         * shl di,1h ; add di,si ; add di,5582h */
        u16 idx = (u16)FL8(0x51);
        u16 di = (u16)((u16)(((u16)idx << 1) + idx) + 0x5582);
        u8 *p = &g_dgroup[di];

        /* les di,[bp-0FF1Ch] ; mov al,es:[di] ; shr ax,2h ; mov es:[di],al
         * (repeated for +1 and +2) */
        p[0] = (u8)((u16)p[0] >> 2);
        p[1] = (u8)((u16)p[1] >> 2);
        p[2] = (u8)((u16)p[2] >> 2);

        if (FL8(0x51) == 0xFF)              /* cmp byte [bp-51h],0FFh ; jnz */
            break;
        FL8(0x51) = (u8)(FL8(0x51) + 0x01);
    }

    /* l0C43_02EB: mov di,5582h ; push ds ; push di ; call 001Eh */
    ax_597 = renamed_0c43_001e((u8 *)&g_dgroup[0x5582], &bp_598, &ds_602);
    (void)bp_598;
    /* push bp ; call 0095h */
    dx_621 = renamed_0c43_0095(ax_597, 0x00E4, &ds_45);

    (void)ds_602;
    return dx_621;
}

// 0C43:02FB: void renamed_0c43_02fb(void)
void renamed_0c43_02fb(void)
{
    LG16(0x5882) = 0xA000;                  /* mov word [5882h],0A000h */
}
