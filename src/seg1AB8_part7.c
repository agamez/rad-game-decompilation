/* seg1AB8_part7.c -- RAD V3.1 preservation port, segment 1AB8 (VIDEO),
 * chunk 7 of N: functions 1AB8:1C6A .. 1AB8:1E26 (12 functions, ascending).
 *
 * Literal recovery from analysis/slices/1AB8/1AB8_<off>.asm (ground truth)
 * and the per-function Reko slices / RAD_1AB8.dis IR; frozen prototypes from
 * src/seg1AB8.h (analysis/summary/iface.tsv) are adopted exactly.  See
 * CONVENTIONS.md and docs/notes-1AB8.md ("## chunk 7").
 *
 * Hardware: this chunk issues no raw port I/O, no int 10h/16h/21h, no
 * __cli/__sti and no int 23h, so it references no pal_* entry point.  It also
 * contains no 0xA000 VGA far pointer.
 *
 * The only far pointers here are:
 *   - the DGROUP state bytes/words accessed through the LG macros;
 *   - the runtime 16:16 graphics-driver dispatch pointer staged at DGROUP
 *     0xB820/0xB822 (`call dword ptr [0B820h]`, twelve call sites), modelled
 *     by the file-static bgi_call_graphics_driver stand-in below (same treatment as
 *     chunks 5b/6);
 *   - the runtime 16:16 slots at DGROUP 0xB83A/0xB83C (far driver record) and
 *     the caller-supplied far pointers carried as the port's `off | seg<<16`
 *     scalar convention (see chunks 1/2/5).
 */
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "pal.h"
#include "seg1AB8.h"

/* Register image for the runtime graphics-driver dispatch.
 *
 * The original reaches the driver with `mov si,<code> / call dword ptr
 * [0B820h]`, passing AX/BX/CX/DX (and, for the far-pointer sites, ES:DI/BX)
 * and reading results back from AX/BX/CX/DX/ES.  Flat C has no registers, so
 * the flat model keeps those register arguments explicit.  si is the driver
 * function selector (the `mov si,<code>` value). */
typedef struct {
	u16 ax;
	u16 bx;
	u16 cx;
	u16 dx;
	u16 es;   /* driver far-pointer segment (1C6A result; ES:DI/BX args) */
	u16 si;   /* driver function selector */
} TRegs1AB8;

/* Stand-in for `call dword ptr [0B820h]` (1AB8:1C6A, 1C93, 1CA4, 1CBA,
 * 1CD7, 1CED, 1CFF, 1D5B (x2), 1D82 (x2), 1DA6, 1E0B, 1E26).
 *
 * DGROUP 0xB820/0xB822 hold the driver entry as a 16:16 far code pointer, so
 * LG32(0xB820) = offset | segment<<16.  The loaded driver is the relocated
 * blob headed at 1AB8:2073; Reko left that region as data and the port does
 * not recover it as C.  The only recovered target is the default
 * bgi_error_not_initialized (1AB8:008B, "graphics not initialized"), which bgi_init_graphics_error
 * stages.  When that default is staged the call is issued; otherwise the
 * external driver call has no recovered implementation and is a no-op that
 * leaves the staged register values unchanged.  This is the same flat-model
 * treatment as chunks 5b/6 (bgi_call_graphics_driver there). */
static void bgi_call_graphics_driver(TRegs1AB8 * r)  /* was fn1AB8_call_0B820 */
{
	if (LG16(0xB820) == 0x008B && LG16(0xB822) == 0x1AB8)
		(void)bgi_error_not_initialized();
	else {
		/* The EGAVGA.BGI driver is installed: dispatch into the PAL's
		 * BGI implementation (the original enters the relocated 16-bit
		 * driver code, which the port cannot execute). */
		u16 regs[7] = { r->ax, r->bx, r->cx, r->dx, r->si, 0, r->es };
		(void)pal_bgi_dispatch(r->si, regs);
		r->ax = regs[0];
		r->bx = regs[1];
		r->cx = regs[2];
		r->dx = regs[3];
		r->es = regs[6];
	}
}

// 1AB8:1C6A: u8 * bgi_get_char_info(void)
u8 * bgi_get_char_info(void)  /* was fn1AB8_1C6A */
{
	TRegs1AB8 r;

	/* original: mov al,1h ; mov si,3Ah ; call [0B820h] ;
	 *           mov dx,es ; mov ax,bx ; retf
	 * (AX = BX, DX = ES; returns the far pointer ES:BX.  AL=1 is the only
	 *  register input the original sets; AH is left as-is.  ES is not
	 *  trashed by the call in Reko's IR, so it is the staged value.) */
	r.ax = 0x0001;
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.es = 0x0000;
	r.si = 0x003A;
	bgi_call_graphics_driver(&r);
	/* Runtime 16:16 far address in a u32 slot: off | seg<<16 (port
	 * convention, chunks 1/2/5).  Materialize it for flat access. */
	return (u8 *)far_ptr(((u32)r.es << 16) | (u32)r.bx);
}

// 1AB8:1C93: u16 bgi_get_current_page(void)
u16 bgi_get_current_page(void)  /* was fn1AB8_1C93 */
{
	TRegs1AB8 r;

	/* original: mov al,1h ; mov si,0 ; call [0B820h] ; mov ax,cx ; dec ax */
	r.ax = 0x0001;
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.es = 0x0000;
	r.si = 0x0000;
	bgi_call_graphics_driver(&r);
	return (u16)(r.cx - 0x0001);
}

// 1AB8:1CA4: void bgi_select_text_font(u8 bArg04)
void bgi_select_text_font(u8 bArg04)  /* was fn1AB8_1CA4 */
{
	TRegs1AB8 r;

	/* original: mov bl,[bp+6h] ; xor bh,bh ; mov ax,0FFFFh ; mov si,1Ah ;
	 *           call [0B820h] */
	r.ax = 0xFFFF;
	r.bx = (u16)bArg04;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.es = 0x0000;
	r.si = 0x001A;
	bgi_call_graphics_driver(&r);
}

// 1AB8:1CBA: u16 bgi_get_pixel(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)
u16 bgi_get_pixel(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)  /* was fn1AB8_1CBA */
{
	TRegs1AB8 r;

	/* original: mov ax,[bp+0Ch] ; or ah,80h ; mov bx,[bp+0Ah] ;
	 *           mov cx,[bp+8h] ; mov dx,[bp+6h] ; mov si,1Ah ;
	 *           call [0B820h]
	 * (Reko returns dx_26 -> DX, the driver result.) */
	r.ax = (u16)(wArg0A | 0x8000);
	r.bx = wArg08;
	r.cx = wArg06;
	r.dx = wArg04;
	r.es = 0x0000;
	r.si = 0x001A;
	bgi_call_graphics_driver(&r);
	return r.dx;
}

// 1AB8:1CD7: u8 bgi_text_cell_color(s16 wArg04, u16 wArg06)
u8 bgi_text_cell_color(s16 wArg04, u16 wArg06)  /* was fn1AB8_1CD7 */
{
	TRegs1AB8 r;

	/* original: mov ax,[bp+8h] ; xor ah,ah ; mov bx,[bp+6h] ; mov si,1Ah ;
	 *           call [0B820h] ; return AH */
	r.ax = (u16)((u8)wArg06);
	r.bx = (u16)wArg04;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.es = 0x0000;
	r.si = 0x001A;
	bgi_call_graphics_driver(&r);
	return (u8)(r.ax >> 8);   /* SLICE(ax, byte, 8) */
}

// 1AB8:1CED: void bgi_set_text_style_attribute(u8 * ptrArg04)
void bgi_set_text_style_attribute(u8 * ptrArg04)  /* was fn1AB8_1CED */
{
	TRegs1AB8 r;

	/* original: les bx,[bp+6h] ; inc bx ; mov si,1Ch ; call [0B820h]
	 * (BX = ptrArg04 offset + 1, ES = ptrArg04 segment; 16:16 far pointer
	 *  split into the port's off/seg words.) */
	r.ax = 0x0000;
	r.bx = (u16)((u16)(uintptr_t)ptrArg04 + 1);
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.es = far_seg_of(ptrArg04);
	r.si = 0x001C;
	bgi_call_graphics_driver(&r);
}

// 1AB8:1CFF: void bgi_set_color_attributes(u8 bArg04, u16 wArg06, u16 wArg08)
void bgi_set_color_attributes(u8 bArg04, u16 wArg06, u16 wArg08)  /* was fn1AB8_1CFF */
{
	TRegs1AB8 r;

	/* original: mov ax,[bp+0Ah] ; mov [0B841h],al ; mov bx,[bp+8h] ;
	 *           mov cl,[bp+6h] ; mov [0B89Eh],cl ; xor ch,ch ; mov si,22h ;
	 *           call [0B820h] */
	LG8(0xB841) = (u8)wArg08;
	LG8(0xB89E) = bArg04;
	r.ax = wArg08;             /* AH retains wArg08 high byte */
	r.bx = wArg06;
	r.cx = (u16)bArg04;
	r.dx = 0x0000;
	r.es = 0x0000;
	r.si = 0x0022;
	bgi_call_graphics_driver(&r);
}

// 1AB8:1D5B: void bgi_set_text_color_attributes(u8 bArg04, u8 bArg06)
void bgi_set_text_color_attributes(u8 bArg04, u8 bArg06)  /* was fn1AB8_1D5B */
{
	TRegs1AB8 r;

	/* first dispatch: mov ah,[bp+6h] ; mov [0B83Fh],ah ;
	 *                 mov al,[0B83Eh] ; mov si,1Eh ; call [0B820h] */
	LG8(0xB83F) = bArg04;
	r.ax = (u16)(((u16)bArg04 << 8) | (u16)LG8(0xB83E));
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.es = 0x0000;
	r.si = 0x001E;
	bgi_call_graphics_driver(&r);
	/* second dispatch: mov al,[bp+8h] ; mov [0B842h],al ; mov ah,al ;
	 *                  mov si,20h ; call [0B820h] */
	LG8(0xB842) = bArg06;
	r.ax = (u16)(((u16)bArg06 << 8) | (u16)bArg06);
	r.si = 0x0020;
	bgi_call_graphics_driver(&r);
}

// 1AB8:1D82: u8 bgi_get_char_size_info(u8 * ptrArg04, u16 wArg08, u16 wArg0A, u8 * chOut)
u8 bgi_get_char_size_info(u8 * ptrArg04, u16 wArg08, u16 wArg0A, u8 * chOut)  /* was fn1AB8_1D82 */
{
	TRegs1AB8 r;

	/* first dispatch: mov ax,[bp+0Ch] ; mov bx,[bp+0Ah] ; mov si,8h ;
	 *                 call [0B820h] */
	r.ax = wArg0A;
	r.bx = wArg08;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.es = 0x0000;
	r.si = 0x0008;
	bgi_call_graphics_driver(&r);
	/* second dispatch: les bx,[bp+6h] ; mov cl,es:[bx] ; xor ch,ch ;
	 *                  inc bx ; mov si,26h ; call [0B820h] */
	r.bx = (u16)(uintptr_t)ptrArg04;
	r.es = far_seg_of(ptrArg04);
	r.cx = (u16)(*ptrArg04);   /* mov cl,es:[bx] ; xor ch,ch */
	r.bx = (u16)(r.bx + 1);    /* inc bx */
	r.si = 0x0026;
	bgi_call_graphics_driver(&r);
	*chOut = (u8)(r.cx >> 8);    /* out chOut = ch_33 */
	return (u8)(r.ax >> 8);      /* SLICE(ax, byte, 8) */
}

// 1AB8:1DA6: u16 bgi_get_text_color_selector(u8 bArg04, u8 bArg06, u8 bArg08)
u16 bgi_get_text_color_selector(u8 bArg04, u8 bArg06, u8 bArg08)  /* was fn1AB8_1DA6 */
{
	TRegs1AB8 r;
	u16 bx_15;
	u16 es_11 = LG16(0xB83C);   /* selector of the [0xB83A] far pointer */

	/* original: les bx,[0B83Ah] ; mov bx,es:[bx+10h] ; and bx,7F7Fh
	 * ([0xB83A]/[0xB83C] is a DGROUP far pointer; see chunk 2.) */
	bx_15 = (u16)(*(u16 *)(far_ptr(LG32(0xB83A)) + 0x10) & 0x7F7F);

	/* original: mov dl,[bp+6h] ; mov al,bh ; mul dl ; mov cx,ax ;
	 *           mov al,bl ; mul dl ; mov bx,ax */
	r.cx = (u16)((u8)(bx_15 >> 8) * bArg04);
	r.bx = (u16)((u8)bx_15 * bArg04);

	/* original: mov al,[bp+0Ah] ; mov ah,[bp+8h] ; and al,al ; jz 1DE3h */
	r.ax = (u16)(((u16)bArg06 << 8) | (u16)bArg08);
	r.dx = 0x0000;
	r.si = 0x0024;
	r.es = (u16)(LG32(0xB83A) >> 16);
	if (bArg08 != 0x00)
	{
		/* original: les di,[0B83Ah] ; cmp byte ptr es:[di+1h],3h ;
		 *           jz 1DE3h */
		if (*(u8 *)(far_ptr(LG32(0xB83A)) + 1) == 0x03)
			goto l1AB8_1DE3;
		/* l1AB8_1DD9: mov cl,dl ; xor ch,ch ; mov bx,cx ;
		 *              mov dx,[0B838h] */
		r.cx = (u16)bArg04;
		r.bx = r.cx;
		r.dx = LG16(0xB838);
	}

l1AB8_1DE3:
	/* original: mov si,24h ; call [0B820h] ; return ES selector.
	 * Reko's dataflow (RAD_1AB8.dis) recovers the return as the ES
	 * selector loaded from the [0xB83A]/[0xB83C] far pointer; the raw
	 * `retf 6h` returns AX, which is the unrecovered driver result.  See
	 * docs/notes-1AB8.md ("## chunk 7", uncertain site 1). */
	bgi_call_graphics_driver(&r);
	return es_11;
}

// 1AB8:1E0B: u16 bgi_advance_text_pointer(u8 * ptrArg04)
u16 bgi_advance_text_pointer(u8 * ptrArg04)  /* was fn1AB8_1E0B */
{
	TRegs1AB8 r;

	/* original: les bx,[bp+6h] ; mov cl,es:[bx] ; xor ch,ch ; inc bx ;
	 *           mov si,28h ; call [0B820h] ; mov ax,bx */
	r.bx = (u16)(uintptr_t)ptrArg04;
	r.es = far_seg_of(ptrArg04);
	r.cx = (u16)(*ptrArg04);   /* mov cl,es:[bx] ; xor ch,ch */
	r.bx = (u16)(r.bx + 1);    /* inc bx */
	r.ax = 0x0000;
	r.dx = 0x0000;
	r.si = 0x0028;
	bgi_call_graphics_driver(&r);
	return r.bx;               /* mov ax,bx */
}

// 1AB8:1E26: u16 bgi_get_string_length(void)
u16 bgi_get_string_length(void)  /* was fn1AB8_1E26 */
{
	TRegs1AB8 r;

	/* original: mov cx,1h ; push cs ; pop es ; mov bx,1E24h ;
	 *           mov si,28h ; call [0B820h] ; mov ax,cx
	 * ES:BX = 1AB8:1E24 points at the embedded two-byte string in the
	 * code segment (g_seg1AB8[0x1E24]); the segment is CS = 0x1AB8. */
	r.ax = 0x0000;
	r.bx = 0x1E24;
	r.cx = 0x0001;
	r.dx = 0x0000;
	r.es = 0x1AB8;
	r.si = 0x0028;
	bgi_call_graphics_driver(&r);
	return r.cx;               /* mov ax,cx */
}
