/* seg0800_part8.c -- RAD V3.1 preservation port, segment 0800, part 8.
 *
 * Function 0800:2401 only (1 function).
 *
 * Literal recovery from analysis/slices/0800/0800_2401.asm (ground truth)
 * and the Reko decompilation; the frozen prototype from src/seg0800.h
 * (analysis/summary/iface.tsv) is adopted exactly.  See CONVENTIONS.md and
 * docs/notes-0800.md ("## part 8").
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   None direct.  No int 10h / int 16h / int 21h, no `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch occur in
 *   2401.  Every BIOS/DOS/hardware service reached from here is owned by the
 *   callee segments and replaced there: segment 0C74 (menus, the
 *   engine_probe_file file-open probe and the fn0C74_51xx/52xx/54xx handlers),
 *   1EDA (the DOS RAD.HLP stream layer: 0FA2/0FD0/1123/1085/1051/0A39/0B24),
 *   1AB8 (video/text), 1E78 (keyboard/PIT) and 1206 (mouse cursor, INT 33h).
 *
 * Frame (enter 282h,0h):
 *   [bp-0x180] abStream[0x80]  RAD.HLP stream block (0FA2/0FD0/1123/1085/1051)
 *   [bp-0x181] bFE7F           command-queue read index
 *   [bp-0x100] abRecord[0x100] RAD.HLP record / command queue
 *   [bp-0x282]..[bp-0x182]     unused frame padding (no asm reference)
 *
 * Dropped-argument adaptation (see docs/notes-0800.md "## part 8"):
 *   fn1EDA_1085's third, dropped data-buffer far pointer is the caller's
 *   [bp-0x100] buffer.  The port's record-I/O layer reads through the shared
 *   slot g_1EDA_io_buffer (src/seg1EDA_shared.h), which the caller must point
 *   at its own buffer; 2401 does so around the call (and restores it).
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0800.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1EDA_shared.h"
#include "seg1E78.h"
#include "seg0C74.h"
#include "seg1206.h"

/* Wall seconds since the first RAD_AUTO_TRACE use (diagnostics only). */
static double rad_auto_now(void)
{
	static struct timespec t0;
	static int ok;
	struct timespec ts;
	if (!ok)
	{
		clock_gettime(CLOCK_MONOTONIC, &t0);
		ok = 1;
	}
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (double)(ts.tv_sec - t0.tv_sec) +
	       (double)(ts.tv_nsec - t0.tv_nsec) / 1e9;
}

// 0800:2401: u16 fn0800_2401(void)
// The RAD.HLP help/menu screen.  Probe "Rad.hlp" (engine_probe_file), open the
// RAD.HLP stream block, read record [598Eh]:[5990h], then (unless the record's
// second byte is 0x20) paint the help frame, load the mission parameters,
// blit the mission grid and run the command loop: bytes of the loaded record
// are dispatched as menu commands (';','<','=','H','K','M','P', Esc) until
// fn0800_0877 reports completion or DGROUP:58B3 is set.
u16 fn0800_2401(void)
{
	u8  abStream[0x80];   /* [bp-0x180] RAD.HLP stream block                */
	u8  bFE7F = 0x00;     /* [bp-0x181] command-queue read index            */
	u8  abRecord[0x100];  /* [bp-0x100] RAD.HLP record / command queue      */

	u8 *saved_io;         /* g_1EDA_io_buffer saved around fn1EDA_1085      */

	u16 ds = 0x0000;      /* dropped DGROUP selector                        */
	u16 ds_158 = 0x0000;  /* fn1206_0066 dsOut                              */
	u16 bp_154 = 0x0000;  /* fn1206_0066 bpOut                              */
	u16 ds_459 = 0x0000;  /* bgi_load_video_driver_file dsOut                              */
	u16 ds_551 = 0x0000;  /* fn0800_04E3 dsOut                              */
	u16 bp_1652 = 0x0000; /* fn1206_0066 bpOut (second)                     */
	u16 ds_618 = 0x0000;  /* fn1206_0066 dsOut (second)                     */
	u16 bp_1428 = 0x0000; /* fn1206_0038/015B/0800:031B/09C2/0C71 frame ptr */
	u16 dx_1493 = 0x0000; /* engine_probe_file dxOut (never written) / 030D DX    */
	u16 dx_1641 = 0x0000; /* fn1EDA_0FD0 dxOut                              */
	u16 ax_1647 = 0x0000; /* fn1EDA_0B24 axOut                              */
	u16 dx_1648 = 0x0000; /* fn1EDA_0B24 dxOut                              */
	u16 dx_1651 = 0x0000; /* fn1EDA_0A39 dxOut                              */
	u16 dx_1654 = 0x0000; /* fn1206_0038 dxOut                              */
	u16 dx_1657 = 0x0000; /* fn1206_015B dxOut (second)                     */
	u16 dx_1658 = 0x0000; /* fn1E78_030D dxOut (l0800_267B)                 */
	u16 dx_1433 = 0x0000; /* fn0800_00C1 dxOut / fn1E78_030D DX             */
	u16 ds_796 = 0x0000;  /* fn0800_031B dsOut                              */
	u16 dx_1667 = 0x0000; /* engine_probe_march_left dxOut                              */	u16 dx_1672 = 0x0000; /* engine_probe_march_right dxOut                              */
	u16 bx_1668 = 0x0000; /* engine_probe_march_left bpOut                              */
	u16 bx_1673 = 0x0000; /* engine_probe_march_right bpOut                              */
	u16 bx_1661 = 0x0000; /* engine_frame_dispatch bpOut                              */

	u8  ch_1643;          /* bgi_get_char_size_info chOut (cs:237Ah)                   */
	u8  ch_1644;          /* bgi_get_char_size_info chOut (cs:238Eh)                   */
	u8  ch_1645;          /* bgi_get_char_size_info chOut (cs:23ACh)                   */
	u8  ch_1646;          /* bgi_get_char_size_info chOut (cs:23C3h)                   */
	u8  ch_1649;          /* bgi_get_char_size_info chOut (cs:23E8h, first)            */
	u8  ch_1650;          /* bgi_get_char_size_info chOut (cs:23E8h, second)           */
	u8  ch_1653;          /* fn1206_0038 chOut                              */
	u8  ch_1655;          /* fn1206_015B chOut (wait loop)                  */
	u8  ch_1656;          /* fn1206_015B chOut (mouse branch)               */

	u16 ax_10CE_a;        /* first bgi_get_text_cols() -----------------+         */
	u16 ax_10CE_b;        /* second bgi_get_text_cols() ----------------+         */
	u16 w_m82;            /* [bp-...] 10CE()/2 - 0x82             |         */
	u16 w_p82;            /* [bp-...] 10CE()/2 + 0x82             |         */
	u16 ax_632;           /* fn0800_04CC(DGROUP:53D9h)                      */
	u16 ax_633;           /* fn0800_04CC(DGROUP:53DAh)                      */
	u16 ax_692;           /* DGROUP:53DDh * 0x3C                            */
	u16 dx_692;           /* cwd(ax_692)                                    */
	u8  al_849 = 0x00;    /* dispatch byte (DGROUP:53D2h)                   */
	u8  al_1123;          /* fn1EDA_1123 return                             */
	u8  al_1085;          /* fn1EDA_1085 return                             */

	/* Diagnostic (RAD_AUTO_TRACE env): one line per l0800_26CA dispatch --
	 * record index, command byte, walk latch, counters, robot position.
	 * Inert unless the env is set (same pattern as RAD_WIN_TRACE). */
	int auto_tr = -1;
	struct timespec ts_d;
	if (auto_tr < 0)
		auto_tr = (getenv("RAD_AUTO_TRACE") != NULL);
#define RAD_AUTO_LOG(stage)                                                  \
	do {                                                                   \
		if (auto_tr)                                                     \
			fprintf(stderr,                                         \
				"AUTO t=%.2f %s idx=%u cmd=%02X BC=%u BD=%u "   \
				"F1=%u F2=%u F3=%u B4=%u B8=%u xp=%u yp=%u "    \
				"5968=%d rec=%u.%u\n",                          \
				rad_auto_now(), (stage), (unsigned)bFE7F,       \
				(unsigned)al_849,                               \
				(unsigned)LG8(0x58BC), (unsigned)LG8(0x58BD),   \
				(unsigned)LG8(0x53DB), (unsigned)LG8(0x53DC),   \
				(unsigned)LG8(0x53DE), LG16(0x58B4),            \
				LG16(0x58B8), LG16(0x58B6), LG16(0x58BA),       \
				(int)LG16(0x5968), LG16(0x598E), LG16(0x5990)); \
	} while (0)

	/* 0800:09C2 / 0C74 register-output scratch (all dead outputs; the
	 * original keeps them in separate stack slots, kept separate here). */
	u16 bp_1659 = 0x0000, bp_1660 = 0x0000, bp_1662 = 0x0000;
	u16 bp_1663 = 0x0000, bp_1664 = 0x0000, bp_1665 = 0x0000;
	u16 bp_1666 = 0x0000, bp_1669 = 0x0000, bp_1670 = 0x0000;
	u16 bp_1671 = 0x0000, bp_1674 = 0x0000, bp_1675 = 0x0000;
	u16 bp_1676 = 0x0000, bp_1677 = 0x0000, bp_1678 = 0x0000;
	u16 bp_1289 = 0x0000, bp_1047 = 0x0000, bp_927 = 0x0000;
	u16 ds_1366 = 0x0000, ds_1293 = 0x0000, ds_1230 = 0x0000;
	u16 ds_1171 = 0x0000, ds_1051 = 0x0000, ds_1077 = 0x0000;
	u16 ds_1099 = 0x0000, ds_979 = 0x0000, ds_1011 = 0x0000;
	u16 ds_931 = 0x0000, ds_881 = 0x0000;

	/* mov di,236Ah ; push cs ; push di ; call far 0C74h:0000h
	 * (cs:236Ah = {7,"Rad.hlp"}; al==0 -> l0800_2413 jmp 280Eh) */
	if (engine_probe_file(&g_seg0800[0x236A], &dx_1493) == 0x00)
		return 0x0000;

	/* l0800_2416: drain the pending-key queue.  fn1E78_030D takes no stack
	 * argument in the original (`retf`), so its wArg02 is the stale stack
	 * word; Reko threads the DX register through dx_1493.  Seeded 0/0. */
	while (fn1E78_02FB() != 0x00)
		(void)fn1E78_030D((s16)dx_1493, 0x0000, &dx_1493);

	/* l0800_2426: open the RAD.HLP stream (cs:2372h = {7,"RAD.HLP"}). */
	fn1EDA_0FA2(&g_seg0800[0x2372], abStream);
	(void)fn1EDA_0FD0(0x0100, abStream, &dx_1641);
	al_1123 = (u8)fn1EDA_1123(LG16(0x598E), LG16(0x5990), abStream);
	/* fn1EDA_1085's dropped data-buffer argument is the caller's [bp-0x100]
	 * buffer (the two far pointers pushed are abStream = stream block and
	 * abRecord = data buffer).  Point the port's shared slot at it. */
	saved_io = g_1EDA_io_buffer;
	g_1EDA_io_buffer = abRecord;
	al_1085 = (u8)fn1EDA_1085(al_1123, abStream);
	g_1EDA_io_buffer = saved_io;
	(void)fn1EDA_1051(al_1085, abStream);

	/* cmp byte ptr [bp+0FF01h],20h ; jnz 2480h  ([bp-0FFh] = abRecord[1]) */
	if (abRecord[1] == 0x20)
		return 0x0000;             /* l0800_247D: jmp 280Eh */

	/* l0800_2480: paint the help frame. */
	(void)fn1206_0066(&bp_154, &ds_158);
	ax_10CE_a = bgi_get_text_cols();
	w_m82 = (u16)(((s16)ax_10CE_a / 0x0002) - 0x0082);
	ax_10CE_b = bgi_get_text_cols();
	w_p82 = (u16)(((s16)ax_10CE_b / 0x0002) + 0x0082);
	/* push A ; push 96h ; push C ; push 0E6h ; call 1315h */
	(void)fn0800_1315(0x00E6, w_p82, 0x0096, w_m82);
	/* push 0h ; push 0h ; push 1h ; call far 1AB8h:1536h */
	(void)bgi_load_video_driver_file(0x0001, 0x0000, 0x0000, &ds_459);
	/* push 4h ; call far 1AB8h:1C32h */
	(void)bgi_get_text_cursor_attributes(0x04);
	/* cs:237Ah = {19,"ENTREE EN MODE AUTO"} */
	(void)bgi_get_char_size_info(&g_seg0800[0x237A], 0x00A4, 0x0140, &ch_1643);
	/* push 1h ; call far 1AB8h:1C32h */
	(void)bgi_get_text_cursor_attributes(0x01);
	/* cs:238Eh = {29,"Pressez une touche quelconque"} */
	(void)bgi_get_char_size_info(&g_seg0800[0x238E], 0x00B4, 0x0140, &ch_1644);
	/* cs:23ACh = {22,"pour l'action suivante"} */
	(void)bgi_get_char_size_info(&g_seg0800[0x23AC], 0x00C0, 0x0140, &ch_1645);
	/* cs:23C3h = {29,"ou ESC pour reprendre la main"} */
	(void)bgi_get_char_size_info(&g_seg0800[0x23C3], 0x00CC, 0x0140, &ch_1646);

	/* l0800_2505: wait for a key press. */
	while (fn1E78_02FB() == 0x00)
		;
	RAD_AUTO_LOG("banner-key");

	/* l0800_250E: load the mission parameters from the file record. */
	LG8(0x53D9) = LG8(0x5CDE);
	LG8(0x53DA) = LG8(0x5CDF);
	LG8(0x53DB) = LG8(0x5CDA);
	LG8(0x53DC) = LG8(0x5CDB);
	if (LG8(0x5CDC) > 0x0A)
		LG8(0x5CDC) = 0x0A;
	LG8(0x53DD) = LG8(0x5CDC);
	LG8(0x53DE) = LG8(0x5CDD);
	LG16(0x53D6) = 0x0000;

	/* l0800_2549: blit every occupied cell of the 0x1D x 0x11 grid. */
	for (;;)
	{
		LG16(0x53D4) = 0x0000;
		for (;;)
		{
			u16 wCol = LG16(0x53D4);
			u16 wRow = LG16(0x53D6);
			/* imul di,[53D6h],1Dh ; add di,ax ; mov al,[di+5CE0h] ;
			 * shl di,2 ; les di,[di+5992h] */
			u8 *blk = far_ptr(LG32(
				(u16)(0x5992 +
				      ((u16)LG8((u16)(wRow * 0x001D + wCol + 0x5CE0)) << 0x0002))));
			/* push (53D4h*16h+1) ; push (53D6h*16h+1) ; push es ;
			 * push di ; push 0 ; call far 1AB8h:13D7h */
			(void)bgi_signed_rectangle_intersect(0x00, blk,
			                  (u16)(wRow * 0x0016 + 0x0001),
			                  (u16)(wCol * 0x0016 + 0x0001));
			if (LG16(0x53D4) == 0x1C)
				break;
			LG16(0x53D4) = (u16)(LG16(0x53D4) + 0x0001);
		}
		if (LG16(0x53D6) == 0x10)
			break;
		LG16(0x53D6) = (u16)(LG16(0x53D6) + 0x0001);
	}

	/* l0800_2592: compare the selected record with cs:23E1h
	 * ({6,"NONAME"}).  The .asm is `jnz 25B2h` (ZF=0 = not equal -> continue),
	 * so the reset at l0800_25A3 runs on EQUALITY.  Reko emitted the inverted
	 * `if (!fn1EDA_0B24(...))` here; this port follows the .asm.
	 * (port fn1EDA_0B24 returns nonzero on equality, 0 otherwise) */
	if (fn1EDA_0B24(&g_seg0800[0x23E1], &g_dgroup[0x5ECE],
	                &ax_1647, &dx_1648) != 0x00)
	{
		LG16(0x598E) = 0x0001;     /* l0800_25A3: reset to record 1 */
		LG16(0x5990) = 0x0000;
		return 0x0000;             /* jmp 280Eh */
	}

	/* l0800_25B2: draw the menu frame and the mode banner. */
	(void)bgi_load_video_driver_file(0x0001, 0x0000, 0x0000, &ds_459);
	bgi_set_text_rectangle(0x0001, 0x0001);
	/* push 0Fh ; push 184h ; push 114h ; push 18Fh ; call 005Ah */
	fn0800_005A(0x018F, 0x0114, 0x0184, 0x000F);
	(void)bgi_get_text_cursor_attributes(0x08);
	/* cs:23E8h = {24,"MODE AUTO (ESC = RETOUR)"} */
	(void)bgi_get_char_size_info(&g_seg0800[0x23E8], 0x0189, 0x0093, &ch_1649);
	(void)bgi_get_text_cursor_attributes(0x0C);
	(void)bgi_get_char_size_info(&g_seg0800[0x23E8], 0x018A, 0x0094, &ch_1650);
	(void)fn0800_04E3(&ds_551);
	/* copy 6 bytes DGROUP:5ECEh -> DGROUP:5ED6h */
	(void)fn1EDA_0A39(0x06, &g_dgroup[0x5ED6], &g_dgroup[0x5ECE], &dx_1651);
	(void)fn0800_0619();
	(void)fn0800_0BEC();
	(void)fn1206_0066(&bp_1652, &ds_618);
	/* mov al,[53D9h] ; push ax ; call 04CCh ; push ax ;
	 * mov al,[53DAh] ; push ax ; call 04CCh ; push ax ;
	 * call far 0C74h:06B7h */
	ax_632 = (u16)fn0800_04CC((u8)LG8(0x53D9));
	ax_633 = (u16)fn0800_04CC((u8)LG8(0x53DA));
	(void)engine_arm_window_geometry(ax_633, ax_632);
	(void)fn1206_0038(&ch_1653, &dx_1654, &bp_1428, &ds);
	/* mov al,[53DDh] ; xor ah,ah ; imul ax,ax,3Ch ; cwd ;
	 * push dx ; push ax ; call 00C1h */
	ax_692 = (u16)((u16)LG8(0x53DD) * 0x003C);
	dx_692 = (u16)((ax_692 & 0x8000) ? 0xFFFF : 0x0000);
	(void)fn0800_00C1(ax_692, dx_692, &dx_1433);
	/* mov byte ptr [bp+0FE7Fh],1h */
	bFE7F = 0x01;

	/* l0800_264E: command loop. */
	do
	{
		/* l0800_264E: drain queued keys. */
		while (fn1E78_02FB() != 0x00)
		{
			struct timespec tsD1, tsD2;
			u8 k;
			if (auto_tr)
				clock_gettime(CLOCK_MONOTONIC, &tsD1);
			k = (u8)fn1E78_030D((s16)dx_1433, 0x0000, &dx_1433);
			if (auto_tr)
			{
				double msD;
				clock_gettime(CLOCK_MONOTONIC, &tsD2);
				msD = (double)(tsD2.tv_sec - tsD1.tv_sec) * 1e3 +
				      (double)(tsD2.tv_nsec - tsD1.tv_nsec) / 1e6;
				fprintf(stderr,
					"AUTO t=%.2f drain key=%02X %.0f ms\n",
					rad_auto_now(), k, msD);
			}
		}

		/* l0800_265E: wait for a key or a mouse event. */
		while (fn1E78_02FB() == 0x00)
		{
			if ((u8)fn1206_015B(&ch_1655, &dx_1433, &bp_1428, &ds) != 0x00)
				break;
		}

		/* l0800_2672 */
		if (fn1E78_02FB() != 0x00)
		{
			/* l0800_267B: keyboard byte (030D has no stack argument). */
			LG8(0x53D2) = (u8)fn1E78_030D((s16)dx_1433, 0x0000, &dx_1658);
			if (LG8(0x53D2) == 0x1B)
			{
				fn0800_0103();
				return 0x0000;
			}
		}
		else
		{
			/* l0800_2692: mouse-driven selection. */
			if ((u8)fn1206_015B(&ch_1656, &dx_1657, &bp_1428, &ds) != 0x00)
			{
				/* l0800_269D */
				LG8(0x53D2) = (u8)fn0800_031B(&bp_1428, &ds_796);
				ds = ds_796;
			}
		}

		/* l0800_26A3 */
		if (LG8(0x53D2) == 0x1B)
		{
			fn0800_0103();
			return 0x0000;
		}

		/* l0800_26B0: pop the next command byte from the record. */
		if (bFE7F < 0xFF)
		{
			LG8(0x53D2) = abRecord[bFE7F];
			++bFE7F;
		}

		/* l0800_26CA: dispatch. */
		al_849 = LG8(0x53D2);
		RAD_AUTO_LOG("dispatch");
		if (auto_tr)
			clock_gettime(CLOCK_MONOTONIC, &ts_d);
		if (al_849 == 0x3B)                       /* ';' */
		{
			(void)fn0800_09C2(0x0E, &bp_1659, &ds_1366);
			if (LG8(0x53DB) > 0x00)
			{
				if (engine_frame_dispatch(&bx_1661, &ds_1366) != 0x00)
					LG8(0x53DB) = (u8)(LG8(0x53DB) - 0x01);
			}
			(void)fn0800_09C2(0x05, &bp_1660, &ds);
		}
		else if (al_849 == 0x3C)                  /* '<' */
		{
			(void)fn0800_09C2(0x0F, &bp_1289, &ds_1293);
			LG8(0x58BD) = abRecord[bFE7F];
			++bFE7F;
			if (LG8(0x53DC) > 0x00)
			{
				if (engine_frame_retract(&ds_1293) != 0x00)
					LG8(0x53DC) = (u8)(LG8(0x53DC) - 0x01);
			}
			(void)fn0800_09C2(0x06, &bp_1662, &ds);
		}
		else if (al_849 == 0x3D)                  /* '=' */
		{
			(void)fn0800_09C2(0x10, &bp_1663, &ds_1230);
			if (LG8(0x53DE) > 0x00 && engine_frame_pull_in_extended(&ds_1230) != 0x00)
				LG8(0x53DE) = (u8)(LG8(0x53DE) - 0x01);
			(void)fn0800_09C2(0x07, &bp_1664, &ds);
		}
		else
		{
			if (al_849 == 0x1B)               /* ESC */
			{
				fn0800_0103();
				return 0x0000;
			}
			if (al_849 == 0x48)               /* 'H' */
			{
				(void)fn0800_09C2(0x09, &bp_1665, &ds_1171);
				(void)engine_call_rocket_trajectory();
				(void)fn0800_09C2(0x00, &bp_1666, &ds);
			}
			else if (al_849 == 0x4B)          /* 'K' */
			{
				(void)fn0800_09C2(0x0A, &bp_1047, &ds_1051);
				LG8(0x58BD) = abRecord[bFE7F];
				++bFE7F;
				if (engine_probe_march_left(&dx_1667, &bx_1668, &ds_1077) == 0x00)
				{
					(void)fn0800_09C2(0x0E, &bp_1670, &ds_1099);
					(void)fn0800_08C0();
					(void)fn0800_09C2(0x05, &bp_1671, &ds_1077);
				}
				(void)fn0800_09C2(0x01, &bp_1669, &ds);
			}
			else if (al_849 == 0x4D)          /* 'M' */
			{
				(void)fn0800_09C2(0x0C, &bp_927, &ds_931);
				LG8(0x58BD) = abRecord[bFE7F];
				++bFE7F;
				if (engine_probe_march_right(&dx_1672, &bx_1673, &ds_1011) == 0x00)
				{
					(void)fn0800_09C2(0x0E, &bp_1675, &ds_979);
					(void)fn0800_08C0();
					(void)fn0800_09C2(0x05, &bp_1676, &ds_1011);
				}
				(void)fn0800_09C2(0x03, &bp_1674, &ds);
			}
			else if (al_849 == 0x50)          /* 'P' */
			{
				(void)fn0800_09C2(0x0D, &bp_1677, &ds_881);
				(void)engine_edge_collision_probe();
				(void)fn0800_09C2(0x04, &bp_1678, &ds);
			}
		}

		/* l0800_27F7 */
		if (auto_tr)
		{
			struct timespec ts1;
			double ms;
			clock_gettime(CLOCK_MONOTONIC, &ts1);
			ms = (double)(ts1.tv_sec - ts_d.tv_sec) * 1e3 +
			     (double)(ts1.tv_nsec - ts_d.tv_nsec) / 1e6;
			if (ms > 1500.0)
				fprintf(stderr,
					"AUTO dispatch-dur cmd=%02X %.0f ms "
					"B4=%u B8=%u\n",
					(unsigned)al_849, ms,
					LG16(0x58B4), LG16(0x58B8));
		}
		{
			struct timespec ts2;
			double ms2;
			if (auto_tr)
				clock_gettime(CLOCK_MONOTONIC, &ts2);
			dx_1433 = (u16)fn0800_0C71(&bp_1428, &ds);
			if (auto_tr)
			{
				struct timespec ts3;
				clock_gettime(CLOCK_MONOTONIC, &ts3);
				ms2 = (double)(ts3.tv_sec - ts2.tv_sec) * 1e3 +
				      (double)(ts3.tv_nsec - ts2.tv_nsec) / 1e6;
				if (ms2 > 1500.0)
					fprintf(stderr,
						"AUTO 0C71-dur %.0f ms "
						"58D8=%u 58DA=%d\n", ms2,
						LG16(0x58D8), (s16)LG16(0x58DA));
			}
		}
	} while (fn0800_0877() == 0x00 && LG8(0x58B3) == 0x00);

	RAD_AUTO_LOG("loop-exit");

	/* l0800_280B: restore the saved vector; leave; ret. */
	fn0800_0103();
	return 0x0000;                 /* original returns the dropped DS selector */
}
