/* seg1AB8_part9.c -- RAD V3.1 preservation port, segment 1AB8 (VIDEO),
 * chunk 9 of N: function 1AB8:2043 (fn1AB8_2043).
 *
 * Literal recovery from analysis/slices/1AB8/1AB8_2043.asm (ground truth),
 * cross-checked against the per-function Reko slice and RAD_1AB8.dis; the
 * frozen prototype from src/seg1AB8.h (analysis/summary/iface.tsv) is adopted
 * exactly.  See CONVENTIONS.md and docs/notes-1AB8.md ("## chunk 9").
 *
 * fn1AB8_2043 is a video-adapter probe: it issues INT 10h AH=30h (AL=06h) and,
 * when the BIOS returns CX:DX as a (non-null) far pointer, reads the byte at
 * CX:DX+2 and -- if that byte is 0 or 2 and I/O port 188h has bit 4 set --
 * reports the adapter present (AX=1).  A true result drives fn1AB8_1F19 to
 * stage LG8(0xB89C)=0Ah, the IBM 8514-class mode record (0x1EB9 table index
 * 0x0A -> record 5 "IBM851").
 *
 * Hardware replaced (CONVENTIONS.md rule 4):
 *   1AB8:2043  int 10h AH=30h AL=06h -> pal_bios_int10(regs).  There is no
 *              named bios_video_* entry for AH=30h, so the generic int 10h
 *              register-frame gateway (the appended int-dispatch contract) is
 *              used; CX/DX are read back for the far-pointer return.
 *   1AB8:2064  in al,188h -> pal_inport(0x0188)  (the literal port constant
 *              is kept; pal.h services 0x188 as an AdLib/OPL2 bus port).
 *   No int 16h / int 21h / __cli / __sti / int 23h occurs in this function.
 *
 * Far-pointer site: the CX:DX returned by INT 10h AH=30h is a far pointer into
 * video-BIOS memory the PAL does not emulate (its int10 core does not
 * implement AH=30h, so it leaves CX/DX unchanged).  The byte the original
 * reads at CX:DX+2 is recovered against the file-static zero-filled g_vbios_30
 * page below (16-bit offset arithmetic), the same stand-in treatment chunk 8
 * gave the C000 ROM (g_rom_c000) and chunk 5b gave the BDA byte (g_bda_0010).
 * Because the PAL leaves CX/DX as 0, the probe returns 0 before the
 * dereference, exactly like a machine whose BIOS lacks AH=30h; on a real
 * adapter it can succeed.  See docs/notes-1AB8.md ("## chunk 9").
 */
#include "radtypes.h"
#include "globals.h"
#include "seg1AB8.h"
#include "pal.h"

/* Stand-in for the video-BIOS data page addressed by the INT 10h AH=30h
 * return pointer.  No BIOS ROM/BDA image is emulated by the PAL and there is
 * no pal.h mapping, so the recovered dereference reads this zero-filled page
 * (chunk 8 g_rom_c000 / chunk 5b g_bda_0010 precedent).  The original offsets
 * into DS:BX with 16-bit arithmetic, so the index wraps mod 0x10000. */
static u8 g_vbios_30[0x10000];

// 1AB8:2043: u16 fn1AB8_2043(void)
u16 fn1AB8_2043(void)
{
	u16 regs[4];
	u16 cx;
	u16 dx;
	u8 al_20;

	/* original: mov al,6h ; xor cx,cx ; xor dx,dx ; mov ah,30h ; int 10h
	 * (AH=30h video-BIOS probe; returns CX:DX.  BX is not set by the
	 *  original and is staged as 0, as in chunks 5b/6/8.) */
	regs[0] = 0x3006;   /* AX: AH=30h, AL=06h */
	regs[1] = 0x0000;   /* BX (not set by the original) */
	regs[2] = 0x0000;   /* CX */
	regs[3] = 0x0000;   /* DX */
	pal_bios_int10(regs);
	cx = regs[2];
	dx = regs[3];

	/* original: mov ax,cx ; or ax,dx ; jz 2070h */
	if ((cx | dx) == 0x0000)
		return 0x0000;                  /* l1AB8_2070 */

	/* l1AB8_2053: push ds ; mov ds,cx ; mov bx,dx ; mov al,[bx+2h] ;
	 * pop ds.  DS:BX (CX:DX) is the returned far pointer; its target page
	 * is not emulated, so the +2 byte is read from the zero-filled
	 * g_vbios_30 stand-in with the original's 16-bit offset arithmetic
	 * (the segment CX selects the BIOS page and is not part of the
	 * stand-in).  Unreachable on the port while CX:DX stay 0. */
	al_20 = g_vbios_30[(u16)(dx + 0x02)];

	/* original: or al,al ; jz 2064h ; cmp al,2h ; jnz 2070h */
	if (al_20 == 0x00 || al_20 == 0x02)
	{
		/* l1AB8_2064: mov dx,188h ; in al,dx ; test al,4h ; jz 2070h */
		if ((pal_inport(0x0188) & 0x04) != 0x00)
		{
			/* l1AB8_206C: mov ax,1h ; ret */
			return 0x0001;
		}
	}
	return 0x0000;                          /* l1AB8_2070 */
}
