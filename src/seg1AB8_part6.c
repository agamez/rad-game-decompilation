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

/* Caller-frame image handed to bgi_sync_text_mode.
 *
 * The original 1AB8:1A62 builds no frame of its own: it reads its caller's
 * (bgi_select_text_mode) [bp+6h] (= ptrArg04) and [bp+0Ah] (= ptrArg08) far pointers
 * directly.  Flat C has no caller bp, so bgi_select_text_mode passes the two pointers
 * explicitly through this image; it is the only caller of bgi_sync_text_mode. */
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
 * recovered target is the default bgi_error_not_initialized (1AB8:008B, "graphics not
 * initialized"), which bgi_init_graphics_error stages.  When that default is staged the
 * call is issued; otherwise the external driver call has no recovered
 * implementation and is a no-op that leaves the staged register values
 * unchanged.  This is the same flat-model treatment as the [0xB896]
 * display-driver callback in chunk 2 (bgi_call_display_driver_cb). */
static void bgi_call_graphics_driver(TRegs1AB8 * r)  /* was fn1AB8_call_0B820 */
{
	if (LG16(0xB820) == 0x008B && LG16(0xB822) == 0x1AB8)
		(void)bgi_error_not_initialized();
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

// 1AB8:19EE: void bgi_select_text_mode(u8 * ptrArg04, u8 * ptrArg08, u8 * ptrArg0C)
void bgi_select_text_mode(u8 * ptrArg04, u8 * ptrArg08, u8 * ptrArg0C)  /* was fn1AB8_19EE */
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
		bgi_sync_text_mode(&frame);
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

// 1AB8:1A62: void bgi_sync_text_mode(void * ss_bp)
void bgi_sync_text_mode(void * ss_bp)  /* was fn1AB8_1A62 */
{
	TFrame1A62 * frame = (TFrame1A62 *)ss_bp;
	u8 al_22;
	u16 ax_27;

	bgi_init_video_mode_info();
	al_22 = LG8(0xB89C);
	ax_27 = (u16)al_22;
	if (al_22 == 0xFF)
		ax_27 = (u16)(((u16)al_22 << 8) | (u16)al_22);   /* mov ah,al */
	*(u16 *)frame->ptrArg08 = ax_27;                     /* les di,[bp+0Ah] */
	*(u16 *)frame->ptrArg04 = (u16)LG8(0xB89B);          /* les di,[bp+6h]  */
}

// 1AB8:1A84: void bgi_clear_video_state(void)
void bgi_clear_video_state(void)  /* was fn1AB8_1A84 */
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

// 1AB8:1AA6: void bgi_set_active_font(u8 * ptrArg04)
void bgi_set_active_font(u8 * ptrArg04)  /* was fn1AB8_1AA6 */
{
	TRegs1AB8 r;

	bgi_init_video_mode();
	/* original: les bx,[bp+6h] ; mov [0B89Fh],bx ; mov [0B8A1h],es
	 * (store the incoming 16:16 far pointer's offset and segment words). */
	LG16(0xB89F) = (u16)(uintptr_t)ptrArg04;
	LG16(0xB8A1) = far_seg_of(ptrArg04);
	r.ax = 0x0000;
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.si = 0x0002;
	bgi_call_graphics_driver(&r);
}

// 1AB8:1AC2: void bgi_clear_text_window(void)
void bgi_clear_text_window(void)  /* was fn1AB8_1AC2 */
{
	TRegs1AB8 r;

	r.ax = 0x0000;
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.si = 0x0004;
	bgi_call_graphics_driver(&r);
}

// 1AB8:1ACE: void bgi_set_text_window_position(u16 wArg04, u16 wArg06)
void bgi_set_text_window_position(u16 wArg04, u16 wArg06)  /* was fn1AB8_1ACE */
{
	TRegs1AB8 r;

	/* original: mov ax,[bp+8h] (wArg06) ; mov bx,[bp+6h] (wArg04) */
	r.ax = wArg06;
	r.bx = wArg04;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.si = 0x0008;
	bgi_call_graphics_driver(&r);
}

// 1AB8:1AF6: u8 bgi_set_pixel(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A, u16 * dxOut)
u8 bgi_set_pixel(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A, u16 * dxOut)  /* was fn1AB8_1AF6 */
{
	TRegs1AB8 r;

	/* original: ax=[bp+0Ch] bx=[bp+0Ah] cx=[bp+8h] dx=[bp+6h] */
	r.ax = wArg0A;
	r.bx = wArg08;
	r.cx = wArg06;
	r.dx = wArg04;
	r.si = 0x000C;
	bgi_call_graphics_driver(&r);
	*dxOut = r.dx;
	return (u8)(r.ax >> 8);   /* return SLICE(ax, byte, 8) */
}

// 1AB8:1B3E: void bgi_draw_rectangle(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)
void bgi_draw_rectangle(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)  /* was fn1AB8_1B3E */
{
	TRegs1AB8 r;

	/* original: ax=[bp+0Ch] bx=[bp+0Ah] cx=[bp+8h] dx=[bp+6h] */
	r.ax = wArg0A;
	r.bx = wArg08;
	r.cx = wArg06;
	r.dx = wArg04;
	r.si = 0x0012;
	bgi_call_graphics_driver(&r);
}

// 1AB8:1B90: void bgi_draw_scaled_text(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E)
void bgi_draw_scaled_text(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E)  /* was fn1AB8_1B90 */
{
	TRegs1AB8 r;

	/* first dispatch: ax=[bp+10h] (wArg0E) ; bx=[bp+0Eh] (wArg0C) ; si=8 */
	r.ax = wArg0E;
	r.bx = wArg0C;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.si = 0x0008;
	bgi_call_graphics_driver(&r);
	/* second dispatch: ax=[bp+0Ch] bx=[bp+0Ah] cx=[bp+8h] dx=[bp+6h] ; si=14h */
	r.ax = wArg0A;
	r.bx = wArg08;
	r.cx = wArg06;
	r.dx = wArg04;
	r.si = 0x0014;
	bgi_call_graphics_driver(&r);
}

// 1AB8:1C32: u8 bgi_get_text_cursor_attributes(u8 bArg04)
u8 bgi_get_text_cursor_attributes(u8 bArg04)  /* was fn1AB8_1C32 */
{
	TRegs1AB8 r;

	/* original: mov al,[bp+6h] ; mov [0B83Eh],al ; mov ah,[0B83Fh] */
	LG8(0xB83E) = bArg04;
	r.ax = (u16)(((u16)LG8(0xB83F) << 8) | bArg04);
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.si = 0x001E;
	bgi_call_graphics_driver(&r);
	return (u8)(r.ax >> 8);   /* return AH */
}

// 1AB8:1C4A: u16 bgi_get_char_width(void)
u16 bgi_get_char_width(void)  /* was fn1AB8_1C4A */
{
	TRegs1AB8 r;

	/* original: xor al,al ; si=3Ah ; call [0B820h] ; mov ax,cx */
	r.ax = 0x0000;
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.si = 0x003A;
	bgi_call_graphics_driver(&r);
	return r.cx;
}

// 1AB8:1C5A: u16 bgi_get_char_cell_height(void)
u16 bgi_get_char_cell_height(void)  /* was fn1AB8_1C5A */
{
	TRegs1AB8 r;

	/* original: xor al,al ; si=3Ah ; call [0B820h] ; mov ax,bx */
	r.ax = 0x0000;
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.si = 0x003A;
	bgi_call_graphics_driver(&r);
	return r.bx;
}
