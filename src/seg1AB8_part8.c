/* seg1AB8_part8.c -- RAD V3.1 preservation port, segment 1AB8 (VIDEO),
 * chunk 8 of N: functions 1AB8:1E3C .. 1AB8:2011 (12 functions, ascending).
 *
 * Literal recovery from analysis/slices/1AB8/1AB8_<off>.asm (ground truth),
 * cross-checked against the per-function Reko slices / RAD_1AB8.dis.  Frozen
 * prototypes from src/seg1AB8.h (analysis/summary/iface.tsv) are adopted
 * exactly.  See CONVENTIONS.md and docs/notes-1AB8.md ("## chunk 8").
 *
 * Hardware replaced (CONVENTIONS.md rule 4):
 *   1AB8:1F19  int 10h AH=0Fh        -> bios_video_get_current_video_mode()
 *   1AB8:1F80  int 10h AH=12h BL=10h -> pal_bios_int10(regs)  (return EGA
 *              information; there is no named bios_video_* entry for it, and
 *              the appended int-dispatch section handles AH=12h)
 *   1AB8:1FED  int 10h AH=1Ah AL=00h -> pal_bios_int10(regs)  (display
 *              combination code; same reason)
 *   1AB8:2011  in al,3BAh            -> pal_inport(0x3BA)  (VGA input
 *              status 1; the literal port constant is kept)
 *   No int 16h / int 21h / __cli / __sti / int 23h occurs in this range.
 *
 * VGA far-pointer sites:
 *   1AB8:1F64  the B800:0000 text-buffer presence probe (`mov ax,es:[si] ;
 *              not ax ; not word ptr es:[si] ; cmp ax,es:[si]`) is addressed
 *              as pal_vga_memory()+0x18000: the 128 KiB shadow stands in for
 *              linear 0A0000h..0C0000h, so B8000h is +18000h into it.
 *   1AB8:1FBB  the C000:0039 VGA/EGA BIOS signature probe has no pal.h
 *              mapping and no ROM image is emulated, so it reads the
 *              file-static zero-filled g_rom_c000 stand-in (no signature is
 *              found, so mode 9 is not selected).  See notes, uncertain site.
 *   No far pointer with segment 0xA000 is constructed here; pal_vga_memory()
 *   is reached only through the B800 shadow offset above.
 *
 * The four dispatch functions (1E3C/1E54/1E6B/1E9F) reach the runtime
 * graphics driver through the 16:16 far code pointer held at DGROUP
 * 0xB820/0xB822 (`call dword ptr [0B820h]`), modelled by the file-static
 * fn1AB8_call_0B820 stand-in below (same treatment as chunks 5b/6/7).  The
 * stand-in, the register-image type, and the C000 ROM stand-in are all
 * file-static, so no src/seg1AB8_shared.h is required.
 */
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1AB8.h"
#include "pal.h"

/* No C000:xxxx BIOS ROM image is emulated by the PAL (there is no pal.h
 * mapping).  1AB8:1FBB probes C000:0039 for the EGA/VGA BIOS signature
 * words 345Ah/3934h; the zero-filled stand-in makes the probe fail exactly
 * like a machine whose C000 ROM lacks those words. */
static u8 g_rom_c000[0x40];

/* Register image for the runtime graphics-driver dispatch (same idea as
 * chunks 5b/6/7's TRegs1AB8, extended with DI because 1AB8:1E6B passes the
 * rect height in DI). */
typedef struct {
	u16 ax;
	u16 bx;
	u16 cx;
	u16 dx;
	u16 si;   /* driver function selector (`mov si,<code>`) */
	u16 di;
	u16 es;   /* ES of the far-pointer argument (ES:BX) */
} TRegs1AB8;

/* Stand-in for `call dword ptr [0B820h]` (1AB8:1E3C, 1E54, 1E6B, 1E9F).
 *
 * DGROUP 0xB820/0xB822 hold the driver entry as a 16:16 far code pointer, so
 * LG32(0xB820) = offset | segment<<16.  The loaded driver (relocated blob
 * headed at 1AB8:2073) is not recovered as C; the only recovered target is
 * the default fn1AB8_008B (1AB8:008B, "graphics not initialized") staged by
 * fn1AB8_0813.  When that default is staged the call is issued; otherwise the
 * external driver call has no recovered implementation and is a no-op that
 * leaves the staged register values unchanged.  Same flat-model treatment as
 * chunks 5b/6/7 (fn1AB8_call_0B820 there). */
static void fn1AB8_call_0B820(TRegs1AB8 * r)
{
	if (LG16(0xB820) == 0x008B && LG16(0xB822) == 0x1AB8)
		(void)fn1AB8_008B();
	else {
		/* The EGAVGA.BGI driver is installed: dispatch into the PAL's
		 * BGI implementation (the original enters the relocated 16-bit
		 * driver code, which the port cannot execute). */
		u16 regs[7] = { r->ax, r->bx, r->cx, r->dx, r->si, r->di, r->es };
		(void)pal_bgi_dispatch(r->si, regs);
		r->ax = regs[0];
		r->bx = regs[1];
		r->cx = regs[2];
		r->dx = regs[3];
		r->di = regs[5];
		r->es = regs[6];
	}
}

// 1AB8:1E3C: u16 fn1AB8_1E3C(u16 wArg04, u16 wArg06, u8 * dlOut)
u16 fn1AB8_1E3C(u16 wArg04, u16 wArg06, u8 * dlOut)
{
	TRegs1AB8 r;

	/* original: mov ax,[bp+8h] ; mov bx,[bp+6h] ; mov si,2Eh ;
	 *           call [0B820h] ; xor ah,ah ; mov al,dl */
	r.ax = wArg06;
	r.bx = wArg04;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.si = 0x002E;
	r.di = 0x0000;
	r.es = 0x0000;
	fn1AB8_call_0B820(&r);
	*dlOut = (u8)r.dx;          /* out dlOut = dl */
	return (u16)(u8)r.dx;       /* xor ah,ah ; mov al,dl */
}

// 1AB8:1E54: u8 fn1AB8_1E54(u8 bArg04, u16 wArg06, u16 wArg08)
u8 fn1AB8_1E54(u8 bArg04, u16 wArg06, u16 wArg08)
{
	TRegs1AB8 r;

	/* original: mov ax,[bp+0Ah] ; mov bx,[bp+8h] ; mov dl,[bp+6h] ;
	 *           mov si,30h ; call [0B820h]
	 * Reko recovers the byte result as the driver's DL output (the body
	 * never moves AL); the callers observed (fn0C74_0A35, fn0C74_076B)
	 * discard it.  See docs/notes-1AB8.md ("## chunk 8", uncertain site). */
	r.ax = wArg08;
	r.bx = wArg06;
	r.cx = 0x0000;
	r.dx = (u16)bArg04;
	r.si = 0x0030;
	r.di = 0x0000;
	r.es = 0x0000;
	fn1AB8_call_0B820(&r);
	return (u8)r.dx;
}

// 1AB8:1E6B: void fn1AB8_1E6B(u8 * ptrArg04, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E)
void fn1AB8_1E6B(u8 * ptrArg04, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E)
{
	TRegs1AB8 r;
	u16 cx_10;
	u16 dx_11;
	u16 si_12;
	u16 di_13;

	/* original: les bx,[bp+6h] ; mov cx,[bp+10h] ; mov dx,[bp+0Eh] ;
	 *           mov si,[bp+0Ch] ; mov di,[bp+0Ah] ;
	 *           cmp cx,si ; jc ; xchg cx,si ; cmp dx,di ; jc ; xchg dx,di
	 * (cx/si -> min/max x, dx/di -> min/max y) */
	cx_10 = wArg0E;
	dx_11 = wArg0C;
	si_12 = wArg0A;
	di_13 = wArg08;
	if (wArg0E >= wArg0A)
	{
		cx_10 = wArg0A;
		si_12 = wArg0E;
	}
	if (wArg0C >= wArg08)
	{
		dx_11 = wArg08;
		di_13 = wArg0C;
	}

	/* original: sub si,cx ; mov es:[bx],si ; sub di,dx ;
	 *           mov es:[bx+2h],di
	 * (width = xmax-xmin at ptrArg04[0], height = ymax-ymin at [2]) */
	*(u16 *)ptrArg04 = (u16)(si_12 - cx_10);
	*(u16 *)(ptrArg04 + 0x02) = (u16)(di_13 - dx_11);

	/* original: mov si,34h ; call [0B820h].  ES:BX is the rect pointer,
	 * CX/DX the box minimum, DI the height.  (BX/ES words of the incoming
	 * far pointer, flat-model off | seg<<16 convention.) */
	r.ax = 0x0000;
	r.bx = (u16)(uintptr_t)ptrArg04;
	r.cx = cx_10;
	r.dx = dx_11;
	r.si = 0x0034;
	r.di = (u16)(di_13 - dx_11);
	r.es = far_seg_of(ptrArg04);
	fn1AB8_call_0B820(&r);
}

// 1AB8:1E9F: u16 fn1AB8_1E9F(u8 bArg04, u8 * ptrArg06, u16 wArg0A, u16 wArg0C)
u16 fn1AB8_1E9F(u8 bArg04, u8 * ptrArg06, u16 wArg0A, u16 wArg0C)
{
	TRegs1AB8 r;

	/* original: les bx,[bp+8h] ; mov cx,[bp+0Eh] ; mov dx,[bp+0Ch] ;
	 *           mov al,[bp+6h] ; mov si,36h ; call [0B820h]
	 * (only AL of AX is set by the original; Reko recovers the word
	 *  result as the driver's DX output -- the sole caller, fn1AB8_13D7
	 *  at 1AB8:147E, ignores it.) */
	r.ax = (u16)bArg04;
	r.bx = (u16)(uintptr_t)ptrArg06;
	r.cx = wArg0C;
	r.dx = wArg0A;
	r.si = 0x0036;
	r.di = 0x0000;
	r.es = far_seg_of(ptrArg06);
	fn1AB8_call_0B820(&r);
	return r.dx;
}

// 1AB8:1EE3: void fn1AB8_1EE3(void)
void fn1AB8_1EE3(void)
{
	u8 bl_18;

	/* original: mov byte ptr [0B89Ah],0FFh ;
	 *           mov byte ptr [0B89Ch],0FFh ;
	 *           mov byte ptr [0B89Bh],0h ; call 1F19h */
	LG8(0xB89A) = 0xFF;
	LG8(0xB89C) = 0xFF;
	LG8(0xB89B) = 0x00;
	fn1AB8_1F19();

	/* original: mov bl,[0B89Ch] ; cmp bl,0FFh ; jz 1F18h ;
	 *           xor bh,bh ;
	 *           mov al,cs:[bx+1EB9h] ; mov [0B89Ah],al ;
	 *           mov al,cs:[bx+1EC7h] ; mov [0B89Bh],al ;
	 *           mov al,cs:[bx+1ED5h] ; mov [0B89Dh],al */
	bl_18 = LG8(0xB89C);
	if (bl_18 == 0xFF)
		return;                     /* l1AB8_1F18 */
	LG8(0xB89A) = g_seg1AB8[(u16)bl_18 + 0x1EB9];
	LG8(0xB89B) = g_seg1AB8[(u16)bl_18 + 0x1EC7];
	LG8(0xB89D) = g_seg1AB8[(u16)bl_18 + 0x1ED5];
}

// 1AB8:1F19: void fn1AB8_1F19(void)
void fn1AB8_1F19(void)
{
	u8 bMode;
	u8 bPage;
	u8 cl;
	u16 bx;

	/* original: mov ah,0Fh ; int 10h ; cmp al,7h ; jz 1F52h */
	bios_video_get_current_video_mode(&bMode, &bPage);
	if (bMode == 0x07)
		goto l1AB8_1F52;

	/* l1AB8_1F21: call 200Eh ; jnc 1F2Ch ; [1F26] mov [0B89Ch],6h ; ret
	 * (200E clears CF, so the set-6 return is never reached here.) */
	if (fn1AB8_200E())
	{
		LG8(0xB89C) = 0x06;
		return;
	}

	/* l1AB8_1F2C: call 1F80h ; jnc 1F35h ; call 1F9Eh ; ret */
	if (fn1AB8_1F80(&cl, &bx))
		goto l1AB8_1F31;

	/* l1AB8_1F35: call 2043h ; and ax,ax ; jz 1F42h ;
	 *             mov [0B89Ch],0Ah ; ret */
	if (fn1AB8_2043() != 0x0000)
	{
		LG8(0xB89C) = 0x0A;
		return;
	}

	/* l1AB8_1F42: mov [0B89Ch],1h ; call 1FEDh ; jnc 1F51h ;
	 *             mov [0B89Ch],2h */
	LG8(0xB89C) = 0x01;
	if (fn1AB8_1FED())
		LG8(0xB89C) = 0x02;
	return;                             /* l1AB8_1F51 */

l1AB8_1F52:
	/* original: call 1F80h ; jc 1F31h */
	if (fn1AB8_1F80(&cl, &bx))
		goto l1AB8_1F31;

	/* l1AB8_1F57: call 2011h ; and al,al ; jz 1F64h ;
	 *             mov [0B89Ch],7h ; ret */
	if (fn1AB8_2011() != 0x00)
	{
		LG8(0xB89C) = 0x07;
		return;
	}

	/* l1AB8_1F64: mov si,0B800h ; mov es,si ; xor si,si ;
	 *           mov ax,es:[si] ; not ax ; not word ptr es:[si] ;
	 *           nop ; nop ; cmp ax,es:[si] ; jnz 1F7Fh ;
	 *           mov [0B89Ch],1h
	 * (B800:0000 text-buffer presence test; the shadow covers linear
	 *  0A0000h..0C0000h, so B8000h is pal_vga_memory()+0x18000h.) */
	{
		u16 *p = (u16 *)(void *)(pal_vga_memory() + 0x18000);
		u16 ax_38 = *p;
		ax_38 = (u16)~ax_38;
		*p = (u16)~*p;
		if (ax_38 == *p)
			LG8(0xB89C) = 0x01;
	}

	return;                             /* l1AB8_1F7F */

l1AB8_1F31:
	/* original: call 1F9Eh ; ret -- reached from 1F2C and 1F52 with the
	 * CL/BX the 1F80 int 10h AH=12h return left behind. */
	fn1AB8_1F9E(cl, bx);
}

// 1AB8:1F80: u8 fn1AB8_1F80(u8 * clOut, u16 * bxOut)
u8 fn1AB8_1F80(u8 * clOut, u16 * bxOut)
{
	u16 regs[4];
	u8 cl_9;
	u16 bx_10;

	/* original: mov ax,1200h ; mov bl,10h ; mov bh,0FFh ; mov cl,0Fh ;
	 *           int 10h
	 * AH=12h BL=10h (return EGA information): CH not set by the original,
	 * DX not set at all; the PAL int 10h core handles AH=12h. */
	regs[0] = 0x1200;   /* AX */
	regs[1] = 0xFF10;   /* BX: BH=0FFh, BL=10h */
	regs[2] = 0x000F;   /* CX: CL=0Fh */
	regs[3] = 0x0000;   /* DX (not set by the original) */
	pal_bios_int10(regs);
	cl_9 = (u8)regs[2];
	bx_10 = regs[1];
	*clOut = cl_9;      /* out clOut */
	*bxOut = bx_10;     /* out bxOut */

	/* original: cmp cl,0Ch ; jge 1F9Ch (signed) */
	if ((s8)cl_9 >= 0x0C)
		return 0x00;    /* clc */
	/* original: cmp bh,1h ; jg 1F9Ch (signed) */
	if ((s8)(u8)(bx_10 >> 8) > 0x01)
		return 0x00;
	/* original: cmp bl,3h ; jg 1F9Ch (signed) */
	if ((s8)(u8)bx_10 > 0x03)
		return 0x00;
	return 0x01;        /* stc */
}

// 1AB8:1F9E: void fn1AB8_1F9E(u8 cl, u16 bx)
void fn1AB8_1F9E(u8 cl, u16 bx)
{
	u8 bh = (u8)(bx >> 8);
	u8 bl = (u8)bx;

	/* original: mov byte ptr [0B89Ch],4h ; cmp bh,1h ; jz 1FD8h */
	LG8(0xB89C) = 0x04;
	if (bh == 0x01)
	{
		/* l1AB8_1FD8: mov byte ptr [0B89Ch],5h ; ret */
		LG8(0xB89C) = 0x05;
		return;
	}

	/* l1AB8_1FA8: call 1FDEh ; jc 1FD7h */
	if (fn1AB8_1FDE(cl))
		return;                     /* l1AB8_1FD7 */
	/* l1AB8_1FAD: and bl,bl ; jz 1FD7h */
	if (bl == 0x00)
		return;

	/* l1AB8_1FB1: mov byte ptr [0B89Ch],3h ; call 1FEDh ; jc 1FD2h */
	LG8(0xB89C) = 0x03;
	if (fn1AB8_1FED())
		goto l1AB8_1FD2;

	/* l1AB8_1FBB: mov bx,0C000h ; mov es,bx ; mov bx,39h ;
	 *             cmp word ptr es:[bx],345Ah ; jnz 1FD7h */
	if (*(u16 *)(void *)(g_rom_c000 + 0x39) != 0x345A)
		return;                     /* l1AB8_1FD7 */
	/* l1AB8_1FCA: cmp word ptr es:[bx+2h],3934h ; jnz 1FD7h */
	if (*(u16 *)(void *)(g_rom_c000 + 0x3B) != 0x3934)
		return;

l1AB8_1FD2:
	/* mov byte ptr [0B89Ch],9h */
	LG8(0xB89C) = 0x09;
}

// 1AB8:1FDE: u8 fn1AB8_1FDE(u8 cl)
u8 fn1AB8_1FDE(u8 cl)
{
	/* original: cmp cl,2h ; jc 1FECh ;
	 *           cmp cl,6h ; cmc ; jnc 1FECh ;
	 *           cmp cl,8h ; [1FECh] ret
	 * Carry (true) iff cl < 2 or 6 <= cl < 8. */
	if (cl < 0x02)
		return 0x01;                /* CF=1 */
	if (cl < 0x06)
		return 0x00;                /* cmc -> CF=0 */
	return (u8)(cl < 0x08);         /* cmp cl,8h */
}

// 1AB8:1FED: u8 fn1AB8_1FED(void)
u8 fn1AB8_1FED(void)
{
	u16 regs[4];
	u8 al_6;
	u8 bl_6;

	/* original: mov ax,1A00h ; int 10h ; cmp al,1Ah ; jnz 200Ch ;
	 *           cmp bl,7h ; jz 200Ah ; cmp bl,8h ; jz 200Ah ;
	 *           cmp bl,0Bh ; jc 200Ch ; cmp bl,0Ch ; ja 200Ch ;
	 *           [200Ah] stc ; ret ; [200Ch] clc ; ret
	 * AH=1Ah AL=00h (display combination code); BX not set by the
	 * original. */
	regs[0] = 0x1A00;   /* AX */
	regs[1] = 0x0000;   /* BX (not set by the original) */
	regs[2] = 0x0000;   /* CX (not set by the original) */
	regs[3] = 0x0000;   /* DX (not set by the original) */
	pal_bios_int10(regs);
	al_6 = (u8)regs[0];
	bl_6 = (u8)regs[1];

	if (al_6 != 0x1A)
		return 0x00;                /* l1AB8_200C */
	if (bl_6 == 0x07)
		return 0x01;                /* l1AB8_200A */
	if (bl_6 == 0x08)
		return 0x01;
	if (bl_6 < 0x0B)
		return 0x00;                /* jc 200Ch */
	if (bl_6 > 0x0C)
		return 0x00;                /* ja 200Ch */
	return 0x01;                    /* l1AB8_200A */
}

// 1AB8:200E: u8 fn1AB8_200E(void)
u8 fn1AB8_200E(void)
{
	/* original: xor al,al ; ret -- AL=0 and CF=0.  The sole caller
	 * (fn1AB8_1F19) branches on the carry (jnc 1F2Ch). */
	return 0x00;
}

// 1AB8:2011: u8 fn1AB8_2011(void)
u8 fn1AB8_2011(void)
{
	u8 al_6;
	u8 ah_7;
	u8 bl_19 = 0x00;
	u16 cx_12;

	/* original: mov dx,3BAh ; xor bl,bl ; in al,dx ; and al,80h ;
	 *           mov ah,al ; mov cx,8000h */
	al_6 = pal_inport(0x3BA);
	ah_7 = (u8)(al_6 & 0x80);
	cx_12 = 0x8000;

	/* l1AB8_201E: in al,dx ; and al,80h ; cmp al,ah ; jz 202Ch ;
	 *             inc bl ; cmp bl,0Ah ; jnc 2031h ;
	 *             [202Ch] loop 201Eh */
	for (; cx_12 != 0x00; --cx_12)
	{
		al_6 = (u8)(pal_inport(0x3BA) & 0x80);
		if (al_6 != ah_7)
		{
			++bl_19;
			if (bl_19 >= 0x0A)
				goto l1AB8_2031;
		}
	}
	/* l1AB8_202E: xor al,al ; ret */
	return 0x00;

l1AB8_2031:
	/* original: mov cx,8000h ; [2034] in al,dx ; and al,30h ;
	 *           cmp al,10h ; jnz 2040h ; loop 2034h ;
	 *           [203D] mov al,2h ; ret ; [2040] mov al,1h ; ret */
	cx_12 = 0x8000;
	for (; cx_12 != 0x00; --cx_12)
	{
		if ((pal_inport(0x3BA) & 0x30) != 0x10)
			return 0x01;            /* l1AB8_2040 */
	}
	return 0x02;                        /* l1AB8_203D */
}
