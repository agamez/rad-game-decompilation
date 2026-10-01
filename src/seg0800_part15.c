/* seg0800_part15.c -- RAD V3.1 preservation port, segment 0800, part 15.
 *
 * Functions 0800:4168 and 0800:4255 (ascending offset).  4255 is the MZ
 * entry point (e_ip=0x4255, e_cs=0 in the header; see analysis/SEGMAP.md),
 * i.e. the recovered Turbo C runtime startup plus the top-level game
 * dispatch.  Literal recovery from analysis/slices/0800/0800_<off>.asm
 * (ground truth) and the Reko decompilation; the frozen prototypes from
 * src/seg0800.h (analysis/summary/iface.tsv) are adopted exactly.  See
 * CONVENTIONS.md and docs/notes-0800.md ("## part 15").
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   None direct.  Neither function contains an int 10h / int 16h / int 21h,
 *   an `in`/`out` port instruction, __cli / __sti or int 23h, and the raw
 *   IVT dispatch fn1E5F_000B is never invoked from here.  Every BIOS / DOS /
 *   mouse service is owned by the callees and was replaced in their own
 *   segments: seg1EDA (runtime init 0000, the stream layer 0FA2/0FD0/04A9/
 *   116A/1051/0AD8/1216/0F71/1265/129E/0CD4/0E07), seg1E78 (keyboard and PIT
 *   through fn1E78_0000/02FB/030D), seg1206 (mouse through fn1206_0217/00FF/
 *   012D/00D1, INT 33h via fn1E5F_000B), seg1AB8 (video/text through
 *   fn1AB8_17AE/1CBA/1342/1536/14F4/10CE/1D82/1175), seg13E2 (BGI startup
 *   0220/0001/0193/003B), the video-mode / mouse init in seg13C8 / 13C1 /
 *   133F, the AdLib teardown in seg11C8, and the menus / fatal-error / file
 *   load in seg0C74 and seg0C43.  No PAL call is issued in this file.
 *
 * Flat-model far pointers (CONVENTIONS.md memory model):
 *   cs:4160h = {7,"RAD.DAT"}, cs:41C7h = {1,'S'}, cs:41C9h = {1,'s'},
 *   cs:41CBh and cs:421Eh (the fn1EDA_0CD4 bit tables), cs:41EBh =
 *   {7,"RAD.TIT"}, cs:41F3h (the "je ne fonctionne que sur carte VGA"
 *   length-prefixed record) and cs:423Eh = {0x16,"Chargement en cours..."}
 *   all resolve to &g_seg0800[0x....] (verified against
 *   data/segments/seg0800.bin).  The runtime destinations stay DGROUP:
 *   ds:550Eh (1EDA:129E path buffer), ds:53D4h (1EDA:0F71 parse word) are
 *   &g_dgroup[0x550E] / [0x53D4]; all other DGROUP state is read/written
 *   through LG8/LG16 at its literal offset.
 *
 * Stack-image reconstruction (the task's central item):
 *   4255 builds its far-call argument blocks by pushing them, and several
 *   callees deliberately leave part of their argument block on the stack for
 *   the next call (Turbo C stack reuse / register-preserving `retf`).  Those
 *   sites are recovered as explicit C arguments with the exact same values,
 *   and the comments record the original push order.
 *     1EDA:1216 is a `retf 2h` helper: it reads the word token index and a
 *     far destination pointer but pops only the token index.  In 4255 the
 *     two "select startup path" calls also push a leading cs: far pattern
 *     (cs:41C7h / cs:41C9h) that 1216 never reads; following the frozen
 *     `(es_si, wArg04, ptrArg06)` prototype it is passed as es_si.  The
 *     immediately following 1EDA:0AD8 call pushes nothing and consumes the
 *     two far pointers 1216 left on the stack as (text, pattern).  In the
 *     token-count loop the leftover is the ss:bp-102h destination, and
 *     1EDA:0F71 reads it as its source text while the explicitly pushed
 *     ds:53D4h is its destination word.
 *     1EDA:04A9 is a register-preserving `retf` trap: the original pushes
 *     nothing, so its wArg00/wArg02 words (only read by the never-returning
 *     fatal-error tail) are seeded 0, matching parts 9/10/12.
 *     1E78:030D likewise takes no stack argument here; wArg02 is seeded 0 and
 *     the DX register is threaded exactly as the Reko dataflow.
 *     1206:00FF/012D/00D1 and 1AB8:1CBA/1342/1536/14F4 have no prototype
 *     slots for the original's extra far-call words (00FF cx/dx, 012D cx/dx,
 *     00D1 cx/dx, the four 1CBA coordinates); the calls are kept at the same
 *     points so the call order and side effects survive, and the dropped
 *     constants are recorded in the source comments.
 */

#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0800.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1E78.h"
#include "seg1206.h"
#include "seg13E2.h"
#include "seg13C8.h"
#include "seg13C1.h"
#include "seg133F.h"
#include "seg11C8.h"
#include "seg0C74.h"
#include "seg0C43.h"

// 0800:4168: u16 fn0800_4168(void)
// Reko models a dropped DGROUP-selector parameter and return (both are
// discarded in the flat model).  Loads the RAD.DAT data-file stream: it
// probes cs:4160h ("RAD.DAT") with engine_probe_file; on failure it runs
// fn0800_0000 (the terminate path).  It then (re)initialises the stream block
// at [bp-80h] (1EDA:0FA2), opens record 219h (1EDA:0FD0), reads it back
// through 1EDA:04A9/116A/04A9, stores (record length - 2) into DGROUP:5CB2h
// and closes the block with 1EDA:1051.  Returns the dropped DGROUP selector
// (the port leaves it 0).  Called from 0800:43FE (in fn0800_4255).
u16 fn0800_4168(void)
{
	u8  abBuf[0x80];      /* [bp-80h] RAD.DAT stream block / record buffer */
	u16 dx_189 = 0x0000;  /* 0C74:0000 dxOut                               */
	u16 dx_190 = 0x0000;  /* 1EDA:0FD0 dxOut                               */
	u8  ch_192;           /* 1EDA:04A9 chOut                               */
	u16 ds_95 = 0x0000;   /* 1EDA:04A9 dsOut (dropped DGROUP selector)     */
	u16 ds_113 = 0x0000;  /* 1EDA:116A dsOut (dropped DGROUP selector)     */
	u8  ch_193;           /* 1EDA:04A9 chOut                               */
	u16 ds_123 = 0x0000;  /* 1EDA:04A9 dsOut (dropped DGROUP selector)     */
	u32 ax_120;           /* 1EDA:04A9 return (DX:AX record length)        */
	u8  ch_196;           /* 1EDA:04A9 chOut                               */
	u16 ds_154 = 0x0000;  /* 1EDA:04A9 dsOut (dropped DGROUP selector)     */

	/* mov di,4160h ; push cs ; push di ; call far 0C74h:0000h ;
	 * or al,al ; jnz 417Dh */
	if (engine_probe_file(&g_seg0800[0x4160], &dx_189) == 0x00)
	{
		/* l0800_417A: call 0000h (near) -- the terminate path. */
		(void)fn0800_0000();
	}

	/* l0800_417D: push ss:bp-80h ; push cs:4160h ;
	 * call far 1EDAh:0FA2h (re-init the stream block with "RAD.DAT"). */
	fn1EDA_0FA2(&g_seg0800[0x4160], abBuf);

	/* push 219h ; push ss:bp-80h ; call far 1EDAh:0FD0h (open record 219h). */
	(void)fn1EDA_0FD0(0x0219, abBuf, &dx_190);

	/* call far 1EDAh:04A9h: register-preserving trap, no pushed words. */
	(void)fn1EDA_04A9(0x0000, 0x0000, &ch_192, &ds_95);

	/* push ss:bp-80h ; call far 1EDAh:116Ah (seek/read the record header).
	 * DX:AX = the RAD.DAT record count (105 for the 56385-byte file with
	 * 219h-byte records); the following 04A9h trap preserves it in the
	 * original (register-preserving retf), so the flat port keeps the
	 * 116Ah result here instead of the trap's 0. */
	ax_120 = fn1EDA_116A(abBuf, &ds_113);

	/* call far 1EDAh:04A9h ; sub ax,2h ; sbb dx,0h ; mov [5CB2h],al */
	(void)fn1EDA_04A9(0x0000, 0x0000, &ch_193, &ds_123);
	LG8(0x5CB2) = (u8)((u16)ax_120 - 0x0002);

	/* push ss:bp-80h ; call far 1EDAh:1051h (AL = low byte of ax_120 - 2). */
	(void)fn1EDA_1051((u8)((u16)ax_120 - 0x0002), abBuf);

	/* call far 1EDAh:04A9h ; leave ; ret */
	(void)fn1EDA_04A9(0x0000, 0x0000, &ch_196, &ds_154);

	/* The original returns the DGROUP selector threaded by 04A9h (0 here). */
	return ds_154;
}

// 0800:4255: void fn0800_4255(void * es)
// The MZ entry point and recovered CRT startup.  `es` is the caller-fabricated
// PSP pointer (src/main.c passes g_psp); it is handed to fn1EDA_0000, the
// runtime initialiser.  After the fixed init sequence the function selects the
// startup path from the PSP command tail, scans the command-line tokens for a
// data-file / drive selector (DGROUP:53D4h/53DFh, 58E6h), installs the VGA
// palette and "Chargement en cours..." banner, resets the main-menu state and
// then loops forever in the menu driver fn0800_3D9D.  Called only by main().
void fn0800_4255(void *es)
{
	/* enter 200h,0h: a single 0x200-byte frame reused for three overlapping
	 * command-tail token buffers -- [bp-0x100], [bp-0x200] and the
	 * per-iteration [bp-0x102] (abFrame[0x0FE]). */
	u8  abFrame[0x200];   /* [bp-200h..bp-1] local frame                     */

	u16 bp_98 = 0x0000;   /* 1206:0217 bpOut                                 */
	u16 ds_102 = 0x0000;  /* 1206:0217 dsOut (dropped DGROUP selector)        */
	u8 *es_si_736;        /* 1206:0217 SI return (startup far pointer)        */
	u16 ax_141 = 0x0000;  /* first 1EDA:0AD8 axOut (match offset)             */
	u8 *es_si_737;        /* first 1EDA:0AD8 return                           */
	u16 ax_185 = 0x0000;  /* second 1EDA:0AD8 axOut                           */
	u16 ax_220 = 0x0000;  /* 1EDA:1265 axOut (token count)                    */
	u8 *es_si_741;        /* 1EDA:1265 return                                 */
	u16 wLoc02 = 0x0000;  /* [bp-2h] token count (loop bound)                 */
	u8 *es_si_738;        /* loop-carried SI value                            */
	u16 si_278 = 0x0000;  /* 1EDA:0F71 siOut (0E8E sign word)                 */
	u16 ax_272 = 0x0000;  /* 1EDA:0F71 return (parsed byte)                   */
	u8 *es_277 = 0;       /* 1EDA:0CD4 esOut                                  */
	u16 ax_00b9 = 0x0000; /* 0C43:00B9 return                                 */
	u16 ds_346 = 0x0000;  /* 0C43:00B9 dsOut (dropped DGROUP selector)        */
	u16 dx_360 = 0x0000;  /* 1E78:030D dxOut                                  */
	u16 ds_384 = 0x0000;  /* 13E2:0001 / 1AB8:1536 dsOut                      */
	u8  bRet129E;         /* 1EDA:129E return (AH)                            */
	u16 ax_129E;          /* AX pushed to 1EDA:0CD4                           */
	u8 *es_743 = 0;       /* 1EDA:0CD4 esOut                                  */
	s16 quot_10CE;        /* 1AB8:10CE() sign-extended / 2                    */
	u8  ch_746;           /* 1AB8:1D82 chOut                                  */
	u16 ds_657 = 0x0000;  /* 1206:00FF dsOut                                  */
	u16 ds_676 = 0x0000;  /* 1206:012D dsOut                                  */
	u16 si_744 = 0x0000;  /* 1206:00D1 siOut                                  */
	u16 es_745 = 0x0000;  /* 1206:00D1 esOut                                  */
	u16 ds_695 = 0x0000;  /* 1206:00D1 dsOut (dropped DGROUP selector)        */

	/* ---- CRT initialisation (exact original call order) ----
	 * call far 1EDAh:0000h -- runtime/real-mode init; receives the PSP and
	 * returns the DGROUP selector (threaded in the original, dropped here). */
	(void)fn1EDA_0000(es);
	/* call far 1E78h:0000h -- keyboard state init. */
	fn1E78_0000();
	/* call far 1AB8h:17AEh -- BGI/video device-table init. */
	fn1AB8_17AE();
	/* call far 13E2h:0220h ; call far 13C8h:0139h -- 0139h receives 0220h's
	 * return (the DGROUP selector) as its DS argument. */
	fn13C8_0139((void *)(uintptr_t)fn13E2_0220());
	/* call far 13C1h:0067h ; call far 133Fh:0816h -- 0067h returns the
	 * video-mode selector that the original feeds to 0816h through a
	 * register; the frozen 0816h prototype takes no argument, so the calls
	 * are kept in order and the return is dropped. */
	(void)fn13C1_0067();
	(void)fn133F_0816();
	/* call far 1206h:0217h -- mouse init; returns the SI far pointer
	 * (es_si_736) consumed by the first 1EDA:1216 call. */
	es_si_736 = fn1206_0217(&bp_98, &ds_102);
	/* call far 11C8h:03CFh -- AdLib/OPL init. */
	fn11C8_03CF();
	/* call far 0C74h:552Fh -- menu system init. */
	engine_crt_startup();
	/* call far 0C43h:02FBh -- resource/palette system init. */
	fn0C43_02FB();

	/* ---- startup-path selection ----
	 * l0800_42AB block.  push cs:41C7h ; push ss:bp-100h ; push 1h ;
	 * call far 1EDAh:1216h: the word is the PSP token index; 1216h leaves
	 * cs:41C7h / ss:bp-100h on the stack (it only pops the word). */
	fn1EDA_1216(es_si_736, 0x0001, &abFrame[0x100]);
	/* call far 1EDAh:0AD8h with no pushes: the two leftover far pointers
	 * are (text = ss:bp-100h, pattern = cs:41C7h = "S"). */
	es_si_737 = fn1EDA_0AD8(&abFrame[0x100], &g_seg0800[0x41C7], &ax_141);
	/* or ax,ax ; jnz 42C6h */
	if (ax_141 == 0x00)
	{
		/* l0800_42AB: push cs:41C9h ; push ss:bp-200h ; push 1h ;
		 * call far 1EDAh:1216h (pattern "s"). */
		fn1EDA_1216(es_si_737, 0x0001, &abFrame[0x000]);
		/* call far 1EDAh:0AD8h (leftover text/pattern again). */
		(void)fn1EDA_0AD8(&abFrame[0x000], &g_seg0800[0x41C9], &ax_185);
		/* or ax,ax ; jz 42CBh */
		if (ax_185 == 0x00)
			goto l0800_42CB;
	}
	/* l0800_42C6: call far 11C8h:0394h (palette/AdLib re-arm). */
	fn11C8_0394();

l0800_42CB:
	/* ---- DGROUP:5CB2h/58E6h token scan ----
	 * mov word ptr [58E6h],7h ; mov byte ptr [53DFh],0h */
	LG16(0x58E6) = 0x0007;
	LG8(0x53DF) = 0x00;
	/* call far 1EDAh:1265h ; mov [bp-2h],ax (token count) */
	es_si_741 = fn1EDA_1265(&ax_220);
	wLoc02 = ax_220;
	/* mov ax,1h ; cmp ax,[bp-2h] ; ja 4335h -- loop while 1 <= count. */
	if (wLoc02 >= 0x0001)
	{
		/* l0800_42E6: mov [53D6h],ax (= 1) */
		LG16(0x53D6) = 0x0001;
		es_si_738 = es_si_741;
		for (;;)
		{
			/* l0800_42EF: push ss:bp-102h ; push [53D6h] ;
			 * call far 1EDAh:1216h (build the n-th token). */
			fn1EDA_1216(es_si_738, LG16(0x53D6), &abFrame[0x0FE]);
			/* mov di,53D4h ; push ds ; push di ;
			 * call far 1EDAh:0F71h: the leftover ss:bp-102h is the
			 * source text, ds:53D4h the destination word; the
			 * returned AL is the parsed value. */
			ax_272 = fn1EDA_0F71(&g_dgroup[0x53D4], &abFrame[0x0FE],
			                     &si_278, &es_277);
			LG8(0x53DF) = (u8)ax_272;
			/* cmp word ptr [53D4h],0h ; jnz 432Dh */
			if (LG16(0x53D4) == 0x0000)
			{
				/* mov al,[53DFh] ; push ax ; push cs:41CBh ;
				 * call far 1EDAh:0CD4h ; jz 432Dh.
				 * The AX pushed is the low/high pair of ax_272,
				 * so 0CD4h's bit index (AL) is ax_272's low byte. */
				if (fn1EDA_0CD4(&g_seg0800[0x41CB], (u8)ax_272,
				                &es_277) == 0x00)
					/* mov al,[53DFh] ; xor ah,ah ;
					 * imul ax,ax,7h ; mov [58E6h],ax */
					LG16(0x58E6) = (u16)((u16)LG8(0x53DF) * 0x0007);
			}
			/* l0800_432D: mov ax,[53D6h] ; cmp ax,[bp-2h] ;
			 * jnz 42EBh (inc) */
			if (LG16(0x53D6) == wLoc02)
				break;
			LG16(0x53D6) = (u16)(LG16(0x53D6) + 0x0001);
			es_si_738 = (u8 *)(uintptr_t)si_278;
		}
	}

	/* l0800_4335: mov di,41EBh ; push cs ; push di ; call far 0C43h:00B9h ;
	 * call far 1E78h:030Dh (the 00B9h return seeds 030Dh's DX). */
	ax_00b9 = fn0C43_00B9(&g_seg0800[0x41EB], &ds_346);
	(void)fn1E78_030D((s16)ax_00b9, 0x0000, &dx_360);
	/* l0800_4344: call far 1E78h:02FBh ; or al,al ; jz 4354h */
	while (fn1E78_02FB() != 0x00)
		/* l0800_434D: call far 1E78h:030Dh ; jmp 4344h */
		(void)fn1E78_030D((s16)dx_360, 0x0000, &dx_360);

	/* l0800_4354: call far 13E2h:0001h ; or al,al ; jnz 4367h */
	if (fn13E2_0001(&ds_384) == 0x00)
	{
		/* l0800_435D: mov di,41F3h ; push cs ; push di ;
		 * call far 13E2h:0193h -- report the fatal "graphics driver"
		 * record (normally does not return). */
		ds_384 = fn13E2_0193(&g_seg0800[0x41F3]);
	}
	/* l0800_4367: call far 1EDAh:0E07h (read the system clock) ;
	 * mov byte ptr [58BEh],0h ; call far 13E2h:003Bh. */
	fn1EDA_0E07();
	LG8(0x58BE) = 0x00;
	(void)fn13E2_003B();

	/* push 0h ; push ds:550Eh ; push 4Fh ; call far 1EDAh:129Eh --
	 * build the "X:\cwd" path into DGROUP:550Eh (bArg0A = 0 selects the
	 * current default drive; DH = 0). */
	bRet129E = fn1EDA_129E(0x00, 0x004F, &g_dgroup[0x550E], 0x00);
	/* mov al,[550Fh] (the built path's first character, the drive letter);
	 * push ax ; push cs:421Eh ; call far 1EDAh:0CD4h ; jz 43D7h. */
	ax_129E = (u16)(((u16)bRet129E << 8) | (u16)LG8(0x550F));
	if (fn1EDA_0CD4(&g_seg0800[0x421E], (u8)ax_129E, &es_743) == 0x00)
	{
		/* l0800_4394: push 0Fh ; push 3Fh ; push 3Fh ; push 3Fh ;
		 * call far 1AB8h:1CBAh (install the 16 VGA palette pins). */
		(void)fn1AB8_1CBA(0x3F, 0x3F, 0x3F, 0x0F);
		/* push 0Fh ; push 0Fh ; call far 1AB8h:1342h */
		(void)fn1AB8_1342(0x0F, 0x000F);
		/* push 1h ; push 0h ; push 4h ; call far 1AB8h:1536h */
		(void)fn1AB8_1536(0x0004, 0x0000, 0x0001, &ds_384);
		/* push 1h ; push 1h ; call far 1AB8h:14F4h */
		fn1AB8_14F4(0x0001, 0x0001);
		/* call far 1AB8h:10CEh ; cwd ; mov cx,2h ; idiv cx ; push ax ;
		 * push 1BAh ; push cs:423Eh ; call far 1AB8h:1D82h (centre the
		 * "Chargement en cours..." banner vertically). */
		quot_10CE = (s16)((s16)fn1AB8_10CE() / 0x0002);
		(void)fn1AB8_1D82(&g_seg0800[0x423E], 0x01BA,
		                  (u16)quot_10CE, &ch_746);
	}

	/* l0800_43D7: reset the main-menu state and enter the game loop.
	 * xor ax,ax ; mov [58E2h],ax ; push 1h ; push 0Fh ;
	 * call far 1AB8h:1175h ; mov byte [58B0h],1h ;
	 * mov word [598Eh],1h ; mov word [5990h],0. */
	LG16(0x58E2) = 0x0000;
	fn1AB8_1175(0x000F, 0x0001);
	LG8(0x58B0) = 0x01;
	LG16(0x598E) = 0x0001;
	LG16(0x5990) = 0x0000;
	/* call far 0C74h:03D4h ; call 03F8h ; call 4168h -- the original
	 * threads the DGROUP selector each returns as the next call's DS; the
	 * frozen prototypes take none, so the three calls are kept in order. */
	(void)engine_load_resources();
	(void)fn0800_03F8();
	(void)fn0800_4168();
	/* push 1h ; push 16h ; call 04CCh ; push ax ;
	 * call far 1206h:00FFh (the pushed 1h / 04CCh result are 00FFh's cx/dx
	 * words, dropped by the frozen prototype). */
	(void)fn0800_04CC(0x0016);
	(void)fn1206_00FF(&ds_657);
	/* push 1B0h ; push 1D1h ; call far 1206h:012Dh (dropped cx/dx words). */
	(void)fn1206_012D(0, &ds_676);
	/* push 64h ; push 1C2h ; call far 1206h:00D1h (dropped cx/dx words). */
	(void)fn1206_00D1(0, &si_744, &es_745, &ds_695);

	/* l0800_4423: call 3D9Dh ; jmp 4423h -- the recovered main loop never
	 * returns; fn0800_3D9D owns the menu driver and the quit path. */
	while (1)
		(void)fn0800_3D9D();
}
