/* seg1EDA_part3c.c -- RAD V3.1 preservation port, segment 1EDA, chunk 3c.
 *
 * Recovered stream callbacks 1EDA:060C .. 1EDA:0775.  Reko never sliced this
 * region: analysis/reko/RAD_1EDA.asm shows it as raw bytes inside
 * renamed_1eda_05fb's symbol range, so the ground truth is the disassembly of
 * data/segments/seg1EDA.bin at those offsets (analysis/slices/1EDA/1EDA_05FB.asm
 * carries the same raw bytes).  See docs/notes-1EDA.md ("## chunk 3c").
 *
 * The Turbo-C stream block built by renamed_1eda_04f5 (offset 0x00 relative to the
 * block pointer):
 *   +0x00 handle           +0x02 id (0xD7B0 closed / 0xD7B1 read /
 *                                     0xD7B2 write / 0xD7B3 append)
 *   +0x04 buffer limit      +0x08 cursor
 *   +0x0C buffer far ptr (flat offset = block+0x80)
 *   +0x14 fill/flush callback (far)   +0x18 second callback (far)
 *   +0x1C close callback (far)        +0x30 NUL-terminated name
 *
 * ABI (derived from the dispatch sites, which push the far block pointer and
 * then `call dword ptr` the slot): every callback receives exactly one far
 * block pointer and returns its AX in the low half of an int; 0 means success.
 * The flat dispatch type is therefore `u16 (*)(u8 * block)` -- the same shape
 * renamed_1eda_05fb / renamed_1eda_0879 already cast to.  No AX/BX/CX/DX register
 * arguments are passed (the pushed block is the only argument; the callbacks'
 * `retf 4` pops it).
 *
 * Functions and boundaries (ascending, all in this TU):
 *   060C..068D  renamed_1eda_060c  open/create (+0x10): 3Dh vs 3Ch, 44h ioctl,
 *                            installs +0x14/+0x18/+0x1C, sets id 0xD7B2
 *   068E..06E7  renamed_1eda_068e  near helper (`call 068Eh` from 060C:0665): trims
 *                            an append stream at the ^Z terminator
 *   06E8..0717  renamed_1eda_06e8  read callback: 3Fh into the block buffer
 *   0718..073C  renamed_1eda_0718  checked write callback: 40h, 0 or 65h
 *   073D..075C  renamed_1eda_073d  unchecked write callback: 40h, 0 on success
 *   075D..0775  renamed_1eda_075d  close callback: 3Eh (handles > 4 only)
 *
 * The brief listed five entries (060C/068E/06E8/0718/075D); the disassembly
 * shows a sixth, 073D, which 060C installs for character devices.  It is a
 * distinct entry point (its own `retf 4`) and is recovered here as well so the
 * region is complete; see the notes/report.
 *
 * DOS-service map (site -> AH -> pal entry):
 *   060C:0637  AH=3Dh        -> msdos_open_file           (mode = AL)
 *   060C:0637  AH=3Ch        -> dos_create_file           (PAL gap: no entry)
 *   060C:0650  AH=44h AL=00h -> dos_get_device_info       (PAL gap: no entry)
 *   068E:0697  AH=42h AL=02h -> msdos_set_file_position   (origin 2)
 *   068E:06AE  AH=42h AL=00h -> msdos_set_file_position   (origin 0)
 *   068E:06BB  AH=3Fh        -> msdos_read_file
 *   068E:06DD  AH=42h AL=02h -> msdos_set_file_position   (origin 2)
 *   068E:06E5  AH=40h        -> msdos_write_file          (CX = 0)
 *   06E8:06FC  AH=3Fh        -> msdos_read_file
 *   0718:072E  AH=40h        -> msdos_write_file
 *   073D:0753  AH=40h        -> msdos_write_file
 *   075D:076D  AH=3Eh        -> msdos_close_file
 *
 * PAL-contract gaps: pal/pal.h exposes 3Dh/3Eh/3Fh/40h/42h but neither 3Ch
 * (create) nor 44h (ioctl get device info).  The chunk constraint forbids
 * editing pal/, so both are file-static helpers below (the same practice as
 * chunk 2a's dos_console_output).  The integrator must add real
 * msdos_create_file / msdos_get_device_info PAL entry points; see notes.
 *
 * Flat model: the original loads the block as a far pointer via lds/les and
 * stores far callback pointers (offset word + segment word).  There is a
 * single flat block pointer and no segment registers, so the callback-slot
 * segment words keep the literal code selector 0x1EDA (the value chunk 1
 * stored for cs at DGROUP:0x5370) and the +0x0C buffer far pointer is
 * collapsed to its block-relative offset (always block+0x80; see
 * block_buffer()).  The return-value paths preserve the original
 * carry-tested control flow with the pal return conventions (0xFFFF is the
 * failure sentinel of the msdos_* entry points).
 */

#include <stdint.h>
#include <stdio.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1EDA_shared.h"
#include "pal.h"

/* 060C:0650 int 21h AH=44h AL=00h (IOCTL "get device information").
 * pal/pal.h has no msdos_* entry, so this file-static helper models it: DOS
 * returns DX with bit 7 set for a character device.  The port's file handles
 * start at 5 (pal/dos.c HANDLE_BASE); 0..4 are the predefined device handles,
 * which is exactly the "empty name -> predefined handle" case of 060C (the
 * handle word is bumped to 1 for the write/append paths and stays 0 for
 * read).  Only DL bit 7 is consumed (060C:0659). */
static u16 dos_get_device_info(u16 handle)
{
	return (handle < 0x0005) ? 0x0080 : 0x0000;
}

/* 060C:0637 int 21h AH=3Ch (create).  pal/pal.h has no create entry and its
 * file-handle table is private, so the file is created through stdio (DOS 3Ch
 * truncates an existing file, like "w+b") and then re-opened through
 * msdos_open_file() so the resulting handle works with the other msdos_* file
 * calls.  Path resolution differs from the pal layer (stdio uses the process
 * CWD); documented deviation, see docs/notes-1EDA.md. */
static u16 dos_create_file(const char *path)
{
	FILE *f = fopen(path, "w+b");

	if (f != NULL)
		fclose(f);
	return msdos_open_file(path, 2);
}

/* Flat reconstruction of `lds dx,[es:di+0Ch]`.  renamed_1eda_04f5 stores the
 * buffer's block-relative offset (always +0x80) in the +0x0C word and drops
 * the segment half at +0x0E, so the flat buffer pointer is the block plus the
 * stored offset minus the block's own low word. */
static u8 *block_buffer(u8 * block)
{
	return block + (u16)(*(u16 *)(block + 0x0C) - (u16)(uintptr_t)block);
}

/* 1EDA:060C -- open/create callback installed at +0x10 by renamed_1eda_04f5.
 * 060C:0615 clears the handle word; 060C:0617..062C picks the DOS service by
 * id (0xD7B1 -> 3Dh AL=0; 0xD7B3 -> 3Dh AL=2 and [block]=1; else 3Ch AL=2);
 * 060C:062E..063B issues it (skipped for an empty name) and stores the handle,
 * returning the DOS error on carry.  060C:063D..066D installs the fill/flush
 * callbacks: 0xD7B1 -> +0x14 = 06E8; otherwise the 44h ioctl selects
 * +0x14/+0x18 = 073D for a character device, or +0x14 = 0718 (after 068Eh
 * trims an append stream).  060C:066F sets id 0xD7B2 and stores the close
 * callback 075D at +0x1C. */
u16 renamed_1eda_060c(u8 * block)
{
	u16 ax_12;
	u16 cx_16;
	u16 bx_17;

	*(u16 *)(block + 0x00) = 0x0000;           /* xor cx,cx ; mov [di],cx */
	ax_12 = 0x3D00;                            /* mov ax,3D00h */
	if (*(u16 *)(block + 0x02) != 0xD7B1)      /* cmp [di+2],0D7B1h ; jz 062Eh */
	{
		ax_12 = 0x3D02;                        /* mov al,2 */
		++*(u16 *)(block + 0x00);              /* inc word [di] */
		if (*(u16 *)(block + 0x02) != 0xD7B3)  /* cmp [di+2],0D7B3h ; jz 062Eh */
			ax_12 = 0x3C02;                    /* mov ah,3Ch */
	}
	if (block[0x30] != 0x00)                   /* cmp byte [di+30h],0 ; jz 063Dh */
	{
		u16 handle;

		if ((u8)(ax_12 >> 8) == 0x3C)
			handle = dos_create_file((char *)(block + 0x30));            /* AH=3Ch */
		else
			handle = msdos_open_file((char *)(block + 0x30), (u8)ax_12); /* AH=3Dh */
		if (handle == 0xFFFF)                  /* jc 068Ah */
			return handle;
		*(u16 *)(block + 0x00) = handle;       /* mov [di],ax */
	}

	ax_12 = 0x06E8;                            /* mov ax,6E8h */
	cx_16 = 0x0000;                            /* xor cx,cx */
	bx_17 = cx_16;                             /* mov bx,cx */
	if (*(u16 *)(block + 0x02) != 0xD7B1)      /* cmp [di+2],0D7B1h ; jz 0674h */
	{
		u16 dx_dev;

		bx_17 = *(u16 *)(block + 0x00);        /* mov bx,[di] */
		dx_dev = dos_get_device_info(bx_17);   /* mov ax,4400h ; int 21h -> DX */
		ax_12 = 0x073D;                        /* mov ax,73Dh */
		cx_16 = ax_12;                         /* mov cx,ax */
		bx_17 = 0x1EDA;                        /* mov bx,cs */
		if ((dx_dev & 0x0080) == 0x0000)       /* test dl,80h ; jnz 066Fh */
		{
			if (*(u16 *)(block + 0x02) == 0xD7B3)  /* cmp [di+2],0D7B3h ; jnz 0668h */
				(void)renamed_1eda_068e(block);      /* call 068Eh */
			ax_12 = 0x0718;                    /* mov ax,718h */
			cx_16 = 0x0000;                    /* xor cx,cx */
			bx_17 = cx_16;                     /* mov bx,cx */
		}
	}
	*(u16 *)(block + 0x02) = 0xD7B2;           /* mov word [di+2],0D7B2h */
	*(u16 *)(block + 0x14) = ax_12;            /* mov [di+14h],ax */
	*(u16 *)(block + 0x16) = 0x1EDA;           /* mov [di+16h],cs */
	*(u16 *)(block + 0x18) = cx_16;            /* mov [di+18h],cx */
	*(u16 *)(block + 0x1A) = bx_17;            /* mov [di+1Ah],bx */
	*(u16 *)(block + 0x1C) = 0x075D;           /* mov word [di+1Ch],75Dh */
	*(u16 *)(block + 0x1E) = 0x1EDA;           /* mov [di+1Eh],cs */
	return 0x0000;                             /* xor ax,ax ; pop ds ; retf 4 */
}

/* 1EDA:068E -- near helper, entered only by `call 068Eh` at 1EDA:0665 with DI
 * already holding the block (DS was switched to the block segment by 060C).
 * For an append stream it repositions to max(0, size-0x80), reads up to 0x80
 * bytes into the block buffer, scans for the ^Z (1Ah) text terminator and,
 * when found, seeks to it and issues a zero-length write.  Returns the last AX
 * (read count, or write result when a ^Z was trimmed). */
u16 renamed_1eda_068e(u8 * block)
{
	u16 ax_9;
	u16 dx_10;
	u16 bx_11;
	u16 ret_ax;
	s32 pos;

	/* 0692 mov bx,[di] ; 0694 AH=42h AL=02h : seek end to get the size. */
	pos = msdos_set_file_position(*(u16 *)(block + 0x00), 0, 2);
	dx_10 = (u16)((u32)pos >> 16);
	ax_9 = (u16)pos;

	/* 0699 sub ax,80h ; 069C sbb dx,0 ; 069F jnc : clamp to 0 on borrow. */
	{
		u32 size = ((u32)dx_10 << 16) | ax_9;

		if (size < 0x00000080u)
		{
			ax_9 = 0x0000;                     /* 06A1 xor ax,ax */
			dx_10 = 0x0000;                    /* 06A3 xor dx,dx */
		}
		else
		{
			u32 off = size - 0x00000080u;

			ax_9 = (u16)off;
			dx_10 = (u16)(off >> 16);
		}
	}

	/* 06A5 mov cx,dx ; 06A7 mov dx,ax ; 06AB AH=42h AL=00h : seek to off. */
	(void)msdos_set_file_position(*(u16 *)(block + 0x00),
	                              (s32)(((u32)dx_10 << 16) | ax_9), 0);

	/* 06B0 lea dx,[di+80h] ; 06B4 mov cx,80h ; 06B9 AH=3Fh : read. */
	ax_9 = msdos_read_file(*(u16 *)(block + 0x00), block_buffer(block), 0x0080);
	if (ax_9 == 0xFFFF)                        /* 06BD jnc skips this */
		ax_9 = 0x0000;                         /* 06BF xor ax,ax (read error) */
	ret_ax = ax_9;

	/* 06C1 xor bx,bx ; 06C3 cmp bx,ax ; 06C7 cmp byte [bx+di+80h],1Ah. */
	for (bx_11 = 0x0000; bx_11 != ax_9; ++bx_11)
	{
		if (block_buffer(block)[bx_11] != 0x1A)
			continue;
		/* 06D1 mov dx,bx ; 06D3 sub dx,ax ; 06D5 mov cx,0FFFFh ;
		 * 06DA AH=42h AL=02h : seek (bx-count) from EOF. */
		dx_10 = (u16)(bx_11 - ax_9);
		(void)msdos_set_file_position(*(u16 *)(block + 0x00),
		                              (s32)(((u32)0xFFFFu << 16) | dx_10), 2);
		/* 06DF xor cx,cx ; 06E3 AH=40h : zero-length write. */
		ret_ax = msdos_write_file(*(u16 *)(block + 0x00), block_buffer(block), 0x0000);
		break;
	}
	return ret_ax;                             /* 06E7 ret */
}

/* 1EDA:06E8 -- read callback (+0x14 when id 0xD7B1).  Reads the buffer limit
 * (+0x04) bytes from the handle into the block buffer, stores the count at
 * +0x0A and resets the cursor +0x08.  Returns 0 on success, the DOS error on
 * failure (0704 vs 0710). */
u16 renamed_1eda_06e8(u8 * block)
{
	u16 ax_15;

	ax_15 = msdos_read_file(*(u16 *)(block + 0x00),        /* 06F7 mov bx,[es:di] */
	                        block_buffer(block),            /* 06EF lds dx,[es:di+0Ch] */
	                        *(u16 *)(block + 0x04));        /* 06F3 mov cx,[es:di+4] */
	if (ax_15 == 0xFFFF)                                    /* 06FE jc 0710h */
	{
		*(u16 *)(block + 0x0A) = 0x0000;                    /* 0710 mov [es:di+0Ah],0 */
	}
	else
	{
		*(u16 *)(block + 0x0A) = ax_15;                     /* 0700 mov [es:di+0Ah],ax */
		ax_15 = 0x0000;                                     /* 0704 xor ax,ax */
	}
	*(u16 *)(block + 0x08) = 0x0000;                        /* 0706 mov [es:di+8h],0 */
	return ax_15;
}

/* 1EDA:0718 -- checked write callback (+0x14 for a file).  Writes the cursor
 * (+0x08) bytes from the buffer, resets the cursor, and returns 0 on a
 * complete write, 0x65 on a short write, or the DOS error. */
u16 renamed_1eda_0718(u8 * block)
{
	u16 cx_11;
	u16 ax_12;

	cx_11 = *(u16 *)(block + 0x08);                        /* 0725 xchg [es:di+8h],cx */
	*(u16 *)(block + 0x08) = 0x0000;
	ax_12 = msdos_write_file(*(u16 *)(block + 0x00),        /* 0729 mov bx,[es:di] */
	                         block_buffer(block),           /* 071F lds dx,[es:di+0Ch] */
	                         cx_11);                        /* mov cx */
	if (ax_12 != 0xFFFF)                                    /* 0730 jc 0739h */
	{
		ax_12 = (u16)(ax_12 - cx_11);                       /* 0732 sub ax,cx */
		if (ax_12 != 0x0000)                                /* 0734 jz 0739h */
			ax_12 = 0x0065;                                 /* 0736 mov ax,65h */
	}
	return ax_12;                                           /* 073A retf 4 */
}

/* 1EDA:073D -- unchecked write callback (+0x14/+0x18 for a character device).
 * Same body as 0718 but any non-error write (full or short) returns 0. */
u16 renamed_1eda_073d(u8 * block)
{
	u16 cx_11;
	u16 ax_12;

	cx_11 = *(u16 *)(block + 0x08);                        /* 074A xchg [es:di+8h],cx */
	*(u16 *)(block + 0x08) = 0x0000;
	ax_12 = msdos_write_file(*(u16 *)(block + 0x00),        /* 074E mov bx,[es:di] */
	                         block_buffer(block),           /* 0744 lds dx,[es:di+0Ch] */
	                         cx_11);                        /* mov cx */
	if (ax_12 != 0xFFFF)                                    /* 0755 jc 0759h */
		ax_12 = 0x0000;                                     /* 0757 xor ax,ax */
	return ax_12;                                           /* 075A retf 4 */
}

/* 1EDA:075D -- close callback (+0x1C).  Closes the handle only when it is
 * greater than 4 (the predefined DOS device handles are left alone).  Returns
 * 0 on the no-op/success paths and the DOS error otherwise. */
u16 renamed_1eda_075d(u8 * block)
{
	u16 bx_8;
	u16 ax_9;

	bx_8 = *(u16 *)(block + 0x00);                          /* 0763 mov bx,[es:di] */
	ax_9 = 0x0000;                                          /* 0771 xor ax,ax */
	if (bx_8 > 0x0004)                                      /* 0766 cmp bx,4 ; jna 0771h */
	{
		ax_9 = msdos_close_file(bx_8);                      /* 076B AH=3Eh */
		if (ax_9 != 0xFFFF)                                 /* 076F jc 0773h */
			ax_9 = 0x0000;                                  /* 0771 xor ax,ax */
	}
	return ax_9;                                            /* 0773 retf 4 */
}
