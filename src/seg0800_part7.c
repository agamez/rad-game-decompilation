/* seg0800_part7.c -- RAD V3.1 preservation port, segment 0800, part 7.
 *
 * Functions 0800:21E7 .. 0800:21E7 (1 function):
 *   21E7
 *
 * Literal recovery from analysis/slices/0800/0800_21E7.asm (ground truth)
 * and the Reko decompilation; frozen prototype from src/seg0800.h
 * (analysis/summary/iface.tsv):  u16 fn0800_21E7(void).
 * See CONVENTIONS.md and docs/notes-0800.md ("## part 7").
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   None.  No int 10h / int 16h / int 21h, no `in`/`out` port instruction,
 *   no __cli/__sti and no int 23h occur in 21E7.  All text/video and
 *   string/number work goes through fn1AB8_* (video), fn1EDA_0A1F /
 *   fn1EDA_0AAC (length-prefixed string copy / append) and fn0C74_004B
 *   (number formatting), which are replaced in those segments.
 *
 * Flat-model far pointers:
 *   The 13 labels at cs:2155h/2159h/2170h/217Ah/217Eh/2180h/218Ch/2197h/
 *   21A2h/21ADh/21B9h/21C5h/21D0h become &g_seg0800[0xHHHH]; the runtime
 *   string at ds:5ED6h becomes &g_dgroup[0x5ED6], and the number source at
 *   ds:5CB2h becomes LG8(0x5CB2).
 *   The two SS-resident line buffers are staged in DGROUP (SS==DS in the
 *   tiny model) so the far pointers fn1AB8_1D82 / fn1AB8_1E0B / fn0800_19E1
 *   materialize for them resolve to 0x2014:offset instead of ES=0 (a
 *   zeroed far arena): the "Version enregistree" banner is read by the
 *   driver's text op through such a pointer, and with a stack staging it
 *   rendered as 34 NUL glyphs (invisible).  0xFC00/0xFD00 are free
 *   DGROUP stack scratch, above the 0xF900/0xFA00/0xFB00 slots used by
 *   seg0800_part13/part12/part5.
 *
 * Stack / callee convention note: fn1EDA_0A1F and fn1EDA_0AAC each end in
 * `retf 4`, i.e. they consume only the last-pushed far source pointer and
 * leave the first-pushed far destination pointer on the stack.  The frozen
 * prototypes take both pointers explicitly (src, dest) and reproduce the
 * same copies; the leftover destination is what the following fn1AB8_1D82 /
 * fn0800_19E1 call reads as its own first argument, exactly as in the
 * original (Reko models it as ptrLoc020A_611 / ptrLoc020C_636).
 */

#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0800.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg0C74.h"

// 0800:21E7: u16 fn0800_21E7(void)
// Draw the mission-selection screen.  Pick the mode from ds:0002h, paint the
// "Version enregistree : N tableaux" banner (when the mode is > 1Eh) and the
// "RAD" header, then draw the eight button slots (fn0800_19E1) with
// mode/record-dependent labels.
u16 fn0800_21E7(void)
{
	u8 *buf200 = g_dgroup + 0xFD00;
	u8 *buf100 = g_dgroup + 0xFC00;
	/* [bp-0200h] banner / slot label (Reko ptrLoc020A_611) and [bp-0100h]
	 * number / slot label (Reko ptrLoc020E_618, ptrLoc020C_636).  Both are
	 * SS-resident in the original; SS==DS in the tiny model, so they are
	 * staged in DGROUP for the ES:BX materialization of the driver text /
	 * width ops (see the file header). */
	u16 ds_102 = 0x0000; /* 1AB8:1536 dsOut (dropped DGROUP selector) */
	u16 ds_234 = 0x0000; /* 0800:19E1 dsOut (dropped DGROUP selector) */
	u16 ds_356 = 0x0000;
	u16 ds_385 = 0x0000;
	u16 ds_416 = 0x0000;
	u16 ds_481 = 0x0000;
	u16 ds_543 = 0x0000;
	u16 ds_572 = 0x0000;
	u8  ch_650;          /* 1AB8:1D82 chOut */
	u8  ch_651;
	u16 dx_654;          /* 0800:19E1 dxOut */
	u16 dx_652;
	u16 dx_656;
	u16 dx_658;
	u16 dx_662;
	u16 dx_660;
	u16 dx_666;
	u16 dx_664;
	u16 dx_668;
	u16 dx_670;
	void *bp_655;        /* 0800:19E1 bpOut (frame ptr; flat model = 0) */
	void *bp_653;
	void *bp_657;
	void *bp_659;
	void *bp_663;
	void *bp_661;
	void *bp_667;
	void *bp_665;
	void *bp_669;
	void *bp_568;

	/* push 1h ; push 0h ; push 18h ; call far 1AB8h:1536h */
	fn1AB8_1536(0x0018, 0x0000, 0x0001, &ds_102);
	/* push 1h ; push 1h ; call far 1AB8h:14F4h */
	fn1AB8_14F4(0x0001, 0x0001);
	/* push 9Ch ; push 14h ; push 1E0h ; push 16Ah ; call 1315h */
	(void)fn0800_1315(0x016A, 0x01E0, 0x0014, 0x009C);
	/* push 0Ah ; call far 1AB8h:1C32h */
	(void)fn1AB8_1C32(0x0A);
	/* push 140h ; push 47h ; push cs:2155h ("RAD") ; call far 1AB8h:1D82h */
	(void)fn1AB8_1D82(&g_seg0800[0x2155], 0x0047, 0x0140, &ch_650);

	/* cmp byte ptr [0002h],1Eh ; jbe 2273h */
	if (LG8(0x0002) > 0x1E)
	{
		/* push 2h ; push 0h ; push 4h ; call far 1AB8h:1536h */
		fn1AB8_1536(0x0004, 0x0000, 0x0002, &ds_102);
		/* push 140h ; push 96h ; push ss:bp-0200h ; push cs:2159h
		 * ("Version enregistree : ") ; call far 1EDAh:0A1Fh */
		fn1EDA_0A1F(&g_seg0800[0x2159], buf200);
		/* push ss:bp-0100h ; push dx:ax = (u32) ds:5CB2h ;
		 * call far 0C74h:004Bh */
		fn0C74_004B((u32)LG8(0x5CB2), buf100);
		/* call far 1EDAh:0AACh -- append the formatted number to buf200 */
		fn1EDA_0AAC(buf100, buf200);
		/* push cs:2170h (" tableaux") ; call far 1EDAh:0AACh */
		fn1EDA_0AAC(&g_seg0800[0x2170], buf200);
		/* call far 1AB8h:1D82h -- draw buf200 at (96h,140h) */
		(void)fn1AB8_1D82(buf200, 0x0096, 0x0140, &ch_651);
	}

	/* cmp word ptr [5990h],0h ; jnz 2281h
	 * cmp word ptr [598Eh],1h ; jz 22B4h */
	if (LG16(0x5990) == 0x0000 && LG16(0x598E) == 0x0001)
	{
		/* push 1h ; push 0F0h ; push 0B4h ; push cs:2180h ("  F1:JEU   ") ;
		 * push 0h ; call 19E1h */
		fn0800_19E1(0x00, &g_seg0800[0x2180], 0x00B4, 0x00F0, 0x0001,
		            &dx_654, &bp_655, &ds_234);
	}
	else
	{
		/* push 1h ; push 0F0h ; push 0B4h ;
		 * push ss:bp-0100h ; push cs:217Ah ("F1:") ; call far 1EDAh:0A1Fh */
		fn1EDA_0A1F(&g_seg0800[0x217A], buf100);
		/* push ds:5ED6h ; call far 1EDAh:0AACh */
		fn1EDA_0AAC(&g_dgroup[0x5ED6], buf100);
		/* push cs:217Eh (" ") ; call far 1EDAh:0AACh */
		fn1EDA_0AAC(&g_seg0800[0x217E], buf100);
		/* push 0h ; call 19E1h -- the label is the leftover ss:bp-0100h */
		fn0800_19E1(0x00, buf100, 0x00B4, 0x00F0, 0x0001, &dx_652, &bp_653,
		            &ds_234);
	}

	/* push 2h ; push 190h ; push 0B4h ; push cs:218Ch ("F2:MISSION") ;
	 * push 0h ; call 19E1h */
	fn0800_19E1(0x00, &g_seg0800[0x218C], 0x00B4, 0x0190, 0x0002, &dx_656,
	            &bp_657, &ds_356);
	/* push 3h ; push 0F0h ; push 0E6h ; push cs:2197h ("  F3:DEMO ") ;
	 * push 0h ; call 19E1h */
	fn0800_19E1(0x00, &g_seg0800[0x2197], 0x00E6, 0x00F0, 0x0003, &dx_658,
	            &bp_659, &ds_385);

	/* cmp byte ptr [58B0h],0h ; jz 2305h */
	if (LG8(0x58B0) != 0x00)
	{
		/* push 4h ; push 190h ; push 0E6h ; push cs:21A2h ("F4:SILENCE") ;
		 * push 0h ; call 19E1h */
		fn0800_19E1(0x00, &g_seg0800[0x21A2], 0x00E6, 0x0190, 0x0004,
		            &dx_662, &bp_663, &ds_416);
	}
	else
	{
		/* push 4h ; push 190h ; push 0E6h ; push cs:21A2h ("F4:SILENCE") ;
		 * push 1h ; call 19E1h */
		fn0800_19E1(0x01, &g_seg0800[0x21A2], 0x00E6, 0x0190, 0x0004,
		            &dx_660, &bp_661, &ds_416);
	}

	/* cmp byte ptr [0002h],1Eh ; jbe 2332h */
	if (LG8(0x0002) > 0x1E)
	{
		/* push 5h ; push 0F0h ; push 118h ; push cs:21ADh ("  F5:EDIT  ") ;
		 * push 0h ; call 19E1h */
		fn0800_19E1(0x00, &g_seg0800[0x21AD], 0x0118, 0x00F0, 0x0005,
		            &dx_666, &bp_667, &ds_481);
	}
	else
	{
		/* push 5h ; push 0F0h ; push 118h ; push cs:21B9h ("  F5:INFO  ") ;
		 * push 0h ; call 19E1h */
		fn0800_19E1(0x00, &g_seg0800[0x21B9], 0x0118, 0x00F0, 0x0005,
		            &dx_664, &bp_665, &ds_481);
	}

	/* push 6h ; push 190h ; push 118h ; push cs:21C5h ("F6:NOTICE ") ;
	 * push 0h ; call 19E1h */
	fn0800_19E1(0x00, &g_seg0800[0x21C5], 0x0118, 0x0190, 0x0006, &dx_668,
	            &bp_669, &ds_543);
	/* push 7h ; push 140h ; push 14Ah ; push cs:21D0h
	 * ("   F7:RETOUR AU DOS   ") ; push 0h ; call 19E1h */
	fn0800_19E1(0x00, &g_seg0800[0x21D0], 0x014A, 0x0140, 0x0007, &dx_670,
	            &bp_568, &ds_572);

	return ds_572;   /* original returns the dropped DGROUP selector */
}
