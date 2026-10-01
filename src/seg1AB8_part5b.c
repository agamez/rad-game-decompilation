/* seg1AB8_part5b.c -- RAD V3.1 preservation port, segment 1AB8 (VIDEO),
 * chunk 5b of N: functions 1AB8:1807 .. 1AB8:19A6 (9 functions, ascending).
 *
 * Literal recovery from analysis/slices/1AB8/1AB8_<off>.asm (ground truth;
 * cross-checked against the raw bytes in data/segments/seg1AB8.bin) and the
 * per-function Reko slices / RAD_1AB8.{c,dis}.  Frozen prototypes from
 * src/seg1AB8.h (analysis/summary/iface.tsv) are adopted exactly.  See
 * CONVENTIONS.md and docs/notes-1AB8.md ("## chunk 5b").
 *
 * Hardware replaced (CONVENTIONS.md rule 4):
 *   1AB8:180A  int 10h AH=0Fh -> bios_video_get_current_video_mode()
 *   1AB8:18E3  int 10h AH=00h -> bios_video_set_mode()
 *   The BIOS Data Area equipment-word low byte at 0040:0010, read by 180A and
 *   written back by 180A/18E3, has no pal.h entry and is kept as a file-static
 *   byte (g_bda_0010), the same treatment seg1E78.c gives 0040:0000/006C/0087.
 *   No raw port I/O, no int 16h/21h, no __cli/__sti and no int 23h occur.
 *
 * Graphics-driver dispatch [0xB820]/[0xB822]: all nine functions except 180A
 * (and 1807 itself) reach the runtime graphics driver through the 16:16 far
 * code pointer held at DGROUP 0xB820/0xB822 (`call dword ptr [0B820h]`).  The
 * file-static bgi_call_graphics_driver stand-in below mirrors
 * src/seg1AB8_part6.c's bgi_call_graphics_driver: the entry is a 16:16 code pointer
 * (LG32(0xB820) = offset | segment<<16); the only recovered target is the
 * default bgi_error_not_initialized ("graphics not initialized") staged by bgi_init_graphics_error.
 * The loaded driver (relocated blob headed at 1AB8:2073) is not recovered as C
 * and is therefore a no-op that leaves the staged registers unchanged.
 *
 * VGA far-pointer sites: **none**.  No far pointer with segment 0xA000 occurs
 * in this chunk, so pal_vga_memory() is not referenced.  The far pointers here
 * are DGROUP slots (LG macros), the unrecovered driver 16:16 code pointers, and
 * caller-supplied far pointers carried as the port's off | seg<<16 scalar.
 */
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1AB8.h"
#include "pal.h"

/* BIOS Data Area equipment-word low byte at 0040:0010 (no pal.h mapping).
 * Only 1AB8:180A and 1AB8:18E3 touch it, so it is not shared outside this
 * chunk and stays file-static (as seg1E78.c keeps its BDA cells). */
static u8 g_bda_0010;   /* 0040:0010 */

/* Register image for the runtime graphics-driver dispatch (same idea as
 * seg1AB8_part6.c's TRegs1AB8, with ES added because 1AB8:1855 stores the
 * call's ES:BX back to DGROUP 0xB83A/0xB83C). */
typedef struct {
	u16 ax;
	u16 bx;
	u16 cx;
	u16 dx;
	u16 si;   /* driver function selector */
	u16 es;   /* far-pointer segment returned by the driver (1855) */
} TRegs1AB8;

/* Stand-in for `call dword ptr [0B820h]` (1AB8:1855, 1895, 18E3, 194E, 1968
 * (x2), 1992, 19A6).
 *
 * DGROUP 0xB820/0xB822 hold the driver entry as a 16:16 far code pointer, so
 * LG32(0xB820) = offset | segment<<16.  The loaded driver is the relocated blob
 * headed at 1AB8:2073 ([0x2073] = +0x20 -> entry 1AB8:2093); Reko left that
 * region as data and the port does not recover it as C.  The only recovered
 * target is the default bgi_error_not_initialized (1AB8:008B, "graphics not initialized"),
 * which bgi_init_graphics_error stages.  When that default is staged the call is issued;
 * otherwise the external driver call has no recovered implementation and is a
 * no-op that leaves the staged register values unchanged.  This is the same
 * flat-model treatment as chunk 6's bgi_call_graphics_driver. */
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

// 1AB8:1807: void bgi_driver_trampoline(void)
void bgi_driver_trampoline(void)  /* was fn1AB8_1807 */
{
	/* Original bytes 06 53 CB: push es / push bx / retf -- a trampoline that
	 * transfers control to the far code pointer ES:BX (the driver routine
	 * 1AB8:194E / 1AB8:19A6 select from the driver structure) and returns to
	 * the instruction after the `call 1807h` when that routine retf's.  A
	 * 16:16 code pointer cannot be called from flat C and the loaded driver
	 * is not recovered, so this trampoline is a no-op stand-in. */
}

// 1AB8:180A: void bgi_init_video_mode(void)
void bgi_init_video_mode(void)  /* was fn1AB8_180A */
{
	u8 bMode_181E;
	u8 bPage_181F;
	u8 al_18;

	if (LG8(0xB8A3) != 0xFF)
		return;
	if (LG8(0xB850) != 0xA5)
	{
		/* original: mov ah,0Fh ; int 10h ; mov [0B8A3h],al */
		bios_video_get_current_video_mode(&bMode_181E, &bPage_181F);
		LG8(0xB8A3) = bMode_181E;
		/* original: mov ax,40h ; mov es,ax ; mov bx,10h ;
		 *           mov al,es:[bx] ; mov [0B8A4h],al */
		al_18 = g_bda_0010;
		LG8(0xB8A4) = al_18;
		if (LG8(0xB89C) != 0x05 && LG8(0xB89C) != 0x07)
			/* original: and al,0CFh ; or al,20h ; mov es:[bx],al */
			g_bda_0010 = (u8)((al_18 & 0xCF) | 0x20);
	}
	else
		LG8(0xB8A3) = 0x00;
}

// 1AB8:1855: void bgi_set_text_cursor_position(u8 * ptrArg04)
void bgi_set_text_cursor_position(u8 * ptrArg04)  /* was fn1AB8_1855 */
{
	TRegs1AB8 r;
	u16 ch_1855;
	u16 bx_1882;
	u16 es_1882;

	LG8(0xB8A3) = 0xFF;
	/* original: xor ax,ax ; mov ch,[0B89Dh] ; cmp [0B89Ch],5 ;
	 *           (mode 5 -> mov ch,3h) ; mov cl,[0B89Bh] */
	ch_1855 = LG8(0xB89D);
	if (LG8(0xB89C) == 0x05)
		ch_1855 = 0x03;
	r.ax = 0x0100;                       /* xor ax,ax ; mov ah,1h */
	r.cx = (u16)((ch_1855 << 8) | LG8(0xB89B));

	/* original: les bx,[bp+6h] -- offset/segment words of the incoming far
	 * pointer (flat-model off | seg<<16 convention). */
	bx_1882 = (u16)(uintptr_t)ptrArg04;
	es_1882 = far_seg_of(ptrArg04);
	r.dx = 0x0000;                       /* not set by the original */
	if (ptrArg04[0x16] == 0x00)          /* cmp byte es:[bx+16h],0 */
	{
		/* original: xor ah,ah ; les bx,[0B832h] */
		r.ax = 0x0000;
		bx_1882 = LG16(0xB832);
		es_1882 = LG16(0xB834);
	}
	r.bx = bx_1882;
	r.es = es_1882;
	r.si = 0x0000;
	bgi_call_graphics_driver(&r);
	LG16(0xB83A) = r.bx;                 /* mov [0B83Ah],bx */
	LG16(0xB83C) = r.es;                 /* mov [0B83Ch],es */
}

// 1AB8:1895: u16 bgi_draw_text(u8 bArg04, u16 wArg06, u16 wArg08, u16 wArg0A, u16 wArg0C)
u16 bgi_draw_text(u8 bArg04, u16 wArg06, u16 wArg08, u16 wArg0A, u16 wArg0C)  /* was fn1AB8_1895 */
{
	TRegs1AB8 r;

	/* original: ax=[bp+0Eh] bx=[bp+0Ch] cx=[bp+0Ah] dx=[bp+8h] */
	r.ax = wArg0C;
	r.bx = wArg0A;
	r.cx = wArg08;
	r.dx = wArg06;
	r.es = 0x0000;                       /* not set by the original */
	if (bArg04 == 0x00)                  /* cmp byte [bp+6h],0 */
		r.ax |= 0x8000;                  /* or ah,80h */
	r.si = 0x0038;
	bgi_call_graphics_driver(&r);
	return r.dx;                         /* dx_32 */
}

// 1AB8:18E3: void bgi_set_video_mode(void)
void bgi_set_video_mode(void)  /* was fn1AB8_18E3 */
{
	TRegs1AB8 r;

	if (LG8(0xB8A3) != 0xFF)
	{
		r.ax = 0x0000;
		r.bx = 0x0000;
		r.cx = 0x0000;
		r.dx = 0x0000;
		r.es = 0x0000;
		r.si = 0x0006;
		bgi_call_graphics_driver(&r);
		if (LG8(0xB850) != 0xA5)
		{
			/* original: mov ax,40h ; mov es,ax ; mov bx,10h ;
			 *           mov al,[0B8A4h] ; mov es:[bx],al ;
			 *           xor ah,ah ; mov al,[0B8A3h] ; int 10h */
			g_bda_0010 = LG8(0xB8A4);
			bios_video_set_mode(LG8(0xB8A3));
		}
	}
	LG8(0xB8A3) = 0xFF;
}

// 1AB8:194E: void bgi_set_text_style(u8 bArg04)
void bgi_set_text_style(u8 bArg04)  /* was fn1AB8_194E */
{
	TRegs1AB8 r;

	r.ax = (u16)bArg04;                  /* mov al,[bp+6h] ; xor ah,ah */
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.es = 0x0000;
	r.si = 0x0032;
	bgi_call_graphics_driver(&r);
	/* original: mov bx,es:[bx+0Eh] then the shared epilogue at 1AB8:1945
	 * (`pop ax / push cs / call 1807h`) -- the driver-structure field at
	 * +0x0E is the far-call target of bgi_driver_trampoline.  The loaded driver is not
	 * recovered so the field read is not modelled; only the trampoline call
	 * (a stand-in) is preserved. */
	bgi_driver_trampoline();
}

// 1AB8:1968: void bgi_set_text_cursor_attributes(u8 bArg04, u8 * ptrArg06)
void bgi_set_text_cursor_attributes(u8 bArg04, u8 * ptrArg06)  /* was fn1AB8_1968 */
{
	TRegs1AB8 r;
	u16 off_1968;
	u16 seg_1968;

	LG8(0xB83F) = bArg04;                /* mov [0B83Fh],ah */
	/* original: mov ah,[bp+6h] ; mov al,[0B83Eh] */
	r.ax = (u16)(((u16)bArg04 << 8) | LG8(0xB83E));
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.es = 0x0000;
	r.si = 0x001E;
	bgi_call_graphics_driver(&r);
	LG8(0xB842) = 0x0C;                  /* mov byte ptr [0B842h],0Ch */
	/* original: les bx,[bp+8h] -- offset/segment words of the incoming far
	 * pointer (flat-model off | seg<<16 convention). */
	off_1968 = (u16)(uintptr_t)ptrArg06;
	seg_1968 = far_seg_of(ptrArg06);
	r.ax = 0xFFFF;
	r.bx = off_1968;
	r.es = seg_1968;
	r.si = 0x0020;
	bgi_call_graphics_driver(&r);
}

// 1AB8:1992: void bgi_set_text_color_palette(u8 bArg04, u8 bArg06)
void bgi_set_text_color_palette(u8 bArg04, u8 bArg06)  /* was fn1AB8_1992 */
{
	TRegs1AB8 r;

	/* original: mov ah,[bp+8h] ; mov al,[bp+6h] */
	r.ax = (u16)(((u16)bArg06 << 8) | bArg04);
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.es = 0x0000;
	r.si = 0x002A;
	bgi_call_graphics_driver(&r);
}

// 1AB8:19A6: u16 bgi_compute_char_block_size(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)
u16 bgi_compute_char_block_size(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)  /* was fn1AB8_19A6 */
{
	TRegs1AB8 r;
	u16 ax_33;
	u16 ax_10;
	u16 ax_19;
	u32 ax_56;
	u16 cx_47;
	u32 dx_ax_57;
	u16 ax_58;
	u16 dx_62;
	u16 ax_59;

	/* original: mov ax,[bp+8h] ; sub ax,[bp+0Ch] ; jns ; neg ax */
	ax_10 = (u16)(wArg06 - wArg0A);
	if ((s16)ax_10 < 0x00)
		ax_10 = (u16)(-(s16)ax_10);
	/* original: inc ax ; add ax,7 ; shr ax,1 ; shr ax,1 ; shr ax,1
	 * -> (|diff|+8)>>3 (the bytes-per-row count of the rectangle). */
	ax_19 = (u16)((u16)(ax_10 + 0x08) >> 3);

	/* driver call si=32h ; AX in = ax_19 (the asm pushes ax_19 for the
	 * later `pop bx` and calls with the same AX). */
	r.ax = ax_19;
	r.bx = 0x0000;
	r.cx = 0x0000;
	r.dx = 0x0000;
	r.es = 0x0000;
	r.si = 0x0032;
	bgi_call_graphics_driver(&r);
	/* original: mov bx,es:[bx+8h] ; push cs ; call 1807h -- a far call to
	 * the driver routine whose AX return feeds the first mul.  The routine
	 * is not recovered; its observable contract (fixed by the shipped data)
	 * is AX_out = AX_in + 1:
	 *   RAD.STR tiles 13A3(15h,15h,0,0): (3+1)*3*22 + 6 =  270 = the
	 *     RAD.STR record stride (54000 bytes / 200 records);
	 *   RAD.BUT slots 13A3(2Bh,2Bh,0,0): (6+1)*6*44 + 6 = 1854 >= the
	 *     RAD.BUT record stride 1086 (DGROUP[0004h]).
	 * A constant 4 would under-allocate the button blocks (1062 < 1086),
	 * which the original demonstrably does not do. */
	bgi_driver_trampoline();
	ax_33 = (u16)(r.ax + 0x0001);

	/* original: pop bx (BX = the pushed ax_19) ; mul bx ; mov cx,[bp+6h] ;
	 *           sub cx,[bp+0Ah] ; jns ; neg cx ; inc cx ; mul cx.
	 * Both muls are 16x16->32 / 32x16->32 (mod 2^32); unlike Reko's
	 * decompilation the first product is not truncated to 16 bits. */
	ax_56 = (u32)ax_33 * (u32)ax_19;
	cx_47 = (u16)(wArg04 - wArg08);
	if ((s16)cx_47 < 0x00)
		cx_47 = (u16)(-(s16)cx_47);
	dx_ax_57 = ax_56 * (u32)(u16)(cx_47 + 0x01);
	ax_58 = (u16)(dx_ax_57 & 0xFFFF);
	dx_62 = (u16)(dx_ax_57 >> 16);

	/* original: add ax,6h ; jc -> 0 ; and dx,dx ; jz return ; -> 0 */
	ax_59 = (u16)(ax_58 + 0x06);
	if (ax_58 >= 0xFFFA || dx_62 != 0x00)
		ax_59 = 0x0000;
	return ax_59;
}
