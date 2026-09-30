/* seg1AB8_part6.c -- RAD V3.1 preservation port, segment 1AB8 (VIDEO),
 * chunk 6 of N: functions 1AB8:19EE .. 1AB8:1C5A (12 functions, ascending).
 *
 * Literal recovery from analysis/slices/1AB8/1AB8_<off>.asm (ground truth)
 * and the per-function Reko slices; frozen prototypes from src/seg1AB8.h
 * (analysis/summary/iface.tsv) are adopted exactly.  See CONVENTIONS.md and
 * docs/notes-1AB8.md ("## chunk 6").
 *
 * Hardware: this chunk issues no raw port I/O and no int 10h/16h/21h, no
 * __cli/__sti and no int 23h, so it references no pal_* entry point.  It also
 * contains no 0xA000 VGA far pointer.  The only far pointers here are the
 * DGROUP state bytes/words (accessed through the LG macros) and the runtime
 * 16:16 graphics-driver dispatch pointer staged at DGROUP 0xB820/0xB822
 * (`call dword ptr [0B820h]`), modelled by the file-static stand-in below.
 */
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "pal.h"
#include "seg1AB8.h"

/* Caller-frame image handed to fn1AB8_1A62.
 *
 * The original 1AB8:1A62 builds no frame of its own: it reads its caller's
 * (fn1AB8_19EE) [bp+6h] (= ptrArg04) and [bp+0Ah] (= ptrArg08) far pointers
 * directly.  Flat C has no caller bp, so fn1AB8_19EE passes the two pointers
 * explicitly through this image; it is the only caller of fn1AB8_1A62. */
typedef struct {
	u8 * ptrArg04;   /* original [bp+6h]  */
	u8 * ptrArg08;   /* original [bp+0Ah] */
} TFrame1A62;

/* Register image for the runtime graphics-driver dispatch.
 *
 * The original reaches the driver with `mov si,<code> / call dword ptr
 * [0B820h]`, passing AX/BX/CX/DX and reading results back from AX/CX/BX.  The
 * flat model keeps those register arguments explicit. */
typedef struct {
	u16 ax;
	u16 bx;
	u16 cx;
	u16 dx;
	u16 si;   /* driver function selector */
} TRegs1AB8;

/* Stand-in for `call dword ptr [0B820h]` (1AB8:1AA6, 1AC2, 1ACE, 1AF6, 1B3E,
 * 1B90, 1C32, 1C4A, 1C5A).
 *
 * DGROUP 0xB820/0xB822 hold the driver entry as a 16:16 far code pointer, so
 * LG32(0xB820) = offset | segment<<16.  The loaded driver is the relocated
 * blob headed at 1AB8:2073 ([0x2073] = +0x20 -> entry 1AB8:2093); Reko left
 * that region as data and the port does not recover it as C.  The only
 * recovered target is the default fn1AB8_008B (1AB8:008B, "graphics not
 * initialized"), which fn1AB8_0813 stages.  When that default is staged the
 * call is issued; otherwise the external driver call has no recovered
 * implementation and is a no-op that leaves the staged register values
 * unchanged.  This is the same flat-model treatment as the [0xB896]
 * display-driver callback in chunk 2 (fn1AB8_call_0B896). */
static void fn1AB8_call_0B820(TRegs1AB8 * r)
{
	if (LG16(0xB820) == 0x008B && LG16(0xB822) == 0x1AB8)
		(void)fn1AB8_008B();
	else {
		/* The EGAVGA.BGI driver is installed: dispatch into the PAL's
		 * BGI implementation (the original enters the relocated 16-bit
		 * driver code, which the port cannot execute). */
		u16 regs[7] = { r->ax, r->bx, r->cx, r->dx, r->si, 0, 0 };
		(void)pal_bgi_dispatch(r->si, regs);
		r->ax = regs[0];
		r->bx = regs[1];
		r->cx = regs[2];
		r->dx = regs[3];
	}
}

// 1AB8:19EE: void fn1AB8_19EE(u8 * ptrArg04, u8 * ptrArg08, u8 * ptrArg0C)
void fn1AB8_19EE(u8 * ptrArg04, u8 * ptrArg08, u8 * ptrArg0C)
{
	u8 al_16;
	u8 al_48 = 0x00;

	LG8(0xB89A) = 0xFF;
	LG8(0xB89B) = 0x00;
	LG8(0xB89D) = 0x0A;
	al_16 = *ptrArg08;
	LG8(0xB89C) = al_16;
	if (al_16 == 0x00)
	{
		TFrame1A62 frame;

		frame.ptrArg04 = ptrArg04;
		frame.ptrArg08 = ptrArg08;
		fn1AB8_1A62(&frame);
		al_48 = LG8(0xB89A);
	}
	else
	{
		u8 bl_31;
		u8 al_38;

		LG8(0xB89B) = *ptrArg04;
		bl_31 = *ptrArg08;
		if ((s8)bl_31 < 0x00)          /* and bl,bl ; js -> return */
			return;
		al_38 = (u8)(0x0A - bl_31);    /* mov al,0Ah ; sub al,bl */
		if ((u16)0x0A < (u16)bl_31)    /* borrow -> neg al */
			al_48 = (u8)(0x00 - al_38);
		else
		{
			u16 bx_45 = (u16)bl_31;    /* xor bh,bh */

			/* cs:[bx+1ED5h] / cs:[bx+1EB9h] are segment 1AB8 tables */
			LG8(0xB89D) = g_seg1AB8[(u16)(bx_45 + 0x1ED5)];
			al_48 = g_seg1AB8[(u16)(bx_45 + 0x1EB9)];
			LG8(0xB89A) = al_48;
		}
	}
	/* original: xor ah,ah ; mov es:[di],ax (word store to ptrArg0C) */
	*(u16 *)ptrArg0C = (u16)al_48;
}

// 1AB8:1A62: void fn1AB8_1A62(void * ss_bp)
void fn1AB8_1A62(void * ss_bp)
{
	TFrame1A62 * frame = (TFrame1A62 *)ss_bp;
	u8 al_22;
	u16 ax_27;

	fn1AB8_1EE3();
	al_22 = LG8(0xB89C);
	ax_27 = (u16)al_22;
	if (al_22 == 0xFF)
		ax_27 = (u16)(((u16)al_22 << 8) | (u16)al_22);   /* mov ah,al */
	*(u16 *)frame->ptrArg08 = ax_27;                     /* les di,[bp+0Ah] */
	*(u16 *)frame->ptrArg04 = (u16)LG8(0xB89B);          /* les di,[bp+6h]  */
}

// 1AB8:1A84: void fn1AB8_1A84(void)
void fn1AB8_1A84(void)
{
	LG8(0xB89A) = 0xFF;
	LG8(0xB89B) = 0x00;
	LG8(0xB89C) = 0x00;
	LG8(0xB89D) = 0x00;
	LG8(0xB89E) = 0x00;
	LG16(0xB89F) = 0x0000;
	LG16(0xB8A1) = 0x0000;
	LG8(0xB8A3) = 0xFF;
	LG8(0xB8A4) = 0x00;
}

// 1AB8:1AA6: void fn1AB8_1AA6(u8 * ptrArg04)
void fn1AB8_1AA6(u8 * ptrArg04)
{
	TRegs1AB8 r;

	fn1AB8_180A();
	/* original: les bx,[bp+6h] ; mov [0B89Fh],bx ; mov [0B8A1h],es
	 * (store the incoming 16:16 far pointer's offset and segment words). */
	LG16(0xB89F) = (u16)(uintptr_t)ptrArg04;
	LG16(0xB8A1) = far_seg_of(ptrArg04);
	r.ax = 0x0000;
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.si = 0x0002;
	fn1AB8_call_0B820(&r);
}

// 1AB8:1AC2: void fn1AB8_1AC2(void)
void fn1AB8_1AC2(void)
{
	TRegs1AB8 r;

	r.ax = 0x0000;
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.si = 0x0004;
	fn1AB8_call_0B820(&r);
}

// 1AB8:1ACE: void fn1AB8_1ACE(u16 wArg04, u16 wArg06)
void fn1AB8_1ACE(u16 wArg04, u16 wArg06)
{
	TRegs1AB8 r;

	/* original: mov ax,[bp+8h] (wArg06) ; mov bx,[bp+6h] (wArg04) */
	r.ax = wArg06;
	r.bx = wArg04;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.si = 0x0008;
	fn1AB8_call_0B820(&r);
}

// 1AB8:1AF6: u8 fn1AB8_1AF6(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A, u16 * dxOut)
u8 fn1AB8_1AF6(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A, u16 * dxOut)
{
	TRegs1AB8 r;

	/* original: ax=[bp+0Ch] bx=[bp+0Ah] cx=[bp+8h] dx=[bp+6h] */
	r.ax = wArg0A;
	r.bx = wArg08;
	r.cx = wArg06;
	r.dx = wArg04;
	r.si = 0x000C;
	fn1AB8_call_0B820(&r);
	*dxOut = r.dx;
	return (u8)(r.ax >> 8);   /* return SLICE(ax, byte, 8) */
}

// 1AB8:1B3E: void fn1AB8_1B3E(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)
void fn1AB8_1B3E(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)
{
	TRegs1AB8 r;

	/* original: ax=[bp+0Ch] bx=[bp+0Ah] cx=[bp+8h] dx=[bp+6h] */
	r.ax = wArg0A;
	r.bx = wArg08;
	r.cx = wArg06;
	r.dx = wArg04;
	r.si = 0x0012;
	fn1AB8_call_0B820(&r);
}

// 1AB8:1B90: void fn1AB8_1B90(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E)
void fn1AB8_1B90(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E)
{
	TRegs1AB8 r;

	/* first dispatch: ax=[bp+10h] (wArg0E) ; bx=[bp+0Eh] (wArg0C) ; si=8 */
	r.ax = wArg0E;
	r.bx = wArg0C;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.si = 0x0008;
	fn1AB8_call_0B820(&r);
	/* second dispatch: ax=[bp+0Ch] bx=[bp+0Ah] cx=[bp+8h] dx=[bp+6h] ; si=14h */
	r.ax = wArg0A;
	r.bx = wArg08;
	r.cx = wArg06;
	r.dx = wArg04;
	r.si = 0x0014;
	fn1AB8_call_0B820(&r);
}

// 1AB8:1C32: u8 fn1AB8_1C32(u8 bArg04)
u8 fn1AB8_1C32(u8 bArg04)
{
	TRegs1AB8 r;

	/* original: mov al,[bp+6h] ; mov [0B83Eh],al ; mov ah,[0B83Fh] */
	LG8(0xB83E) = bArg04;
	r.ax = (u16)(((u16)LG8(0xB83F) << 8) | bArg04);
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.si = 0x001E;
	fn1AB8_call_0B820(&r);
	return (u8)(r.ax >> 8);   /* return AH */
}

// 1AB8:1C4A: u16 fn1AB8_1C4A(void)
u16 fn1AB8_1C4A(void)
{
	TRegs1AB8 r;

	/* original: xor al,al ; si=3Ah ; call [0B820h] ; mov ax,cx */
	r.ax = 0x0000;
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.si = 0x003A;
	fn1AB8_call_0B820(&r);
	return r.cx;
}

// 1AB8:1C5A: u16 fn1AB8_1C5A(void)
u16 fn1AB8_1C5A(void)
{
	TRegs1AB8 r;

	/* original: xor al,al ; si=3Ah ; call [0B820h] ; mov ax,bx */
	r.ax = 0x0000;
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.si = 0x003A;
	fn1AB8_call_0B820(&r);
	return r.bx;
}
