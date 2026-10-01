/* seg0800_part9.c -- RAD V3.1 preservation port, segment 0800, part 9.
 *
 * Function 0800:2827 only (1 function).
 *
 * Literal recovery from analysis/slices/0800/0800_2827.asm (ground truth)
 * and the Reko decompilation; the frozen prototype from src/seg0800.h
 * (analysis/summary/iface.tsv) is adopted exactly.  See CONVENTIONS.md and
 * docs/notes-0800.md ("## part 9").
 *
 * 2827 is the RAD.HLP playback screen (the demo/mission recorder): probe
 * "Rad.hlp", load the RAD.DAT grid (01FE), compare the selected record name
 * against "NONAME", open the RAD.HLP stream, read one 0x100-byte record and
 * interpret it as a queue of menu/command bytes (';','<','=','H','K','M','P',
 * ESC) until fn0800_0877 reports completion or DGROUP:58B3 is set.
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   None direct.  No int 10h / int 16h / int 21h, no `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch occur in
 *   2827.  Every BIOS/DOS/hardware service reached from here is owned by the
 *   callee segments and replaced there: segment 1E78 (keyboard/PIT: 02FB/030D),
 *   1206 (mouse cursor, INT 33h via fn1E5F_000B: 0066/0038/015B), 0C74 (menus,
 *   the engine_probe_file "Rad.hlp" open probe and the 51xx/52xx/54xx handlers),
 *   1EDA (the RAD.HLP stream layer: 0FA2/0FD0/1123/1085/1051/0A39/0B24), 1AB8
 *   (video/text) and 13E2.
 *
 * Frame (enter 282h,0h):
 *   [bp-0x180] abStream[0x80]  RAD.HLP stream block (0FA2/0FD0/1123/1085/1051)
 *   [bp-0x181] bFE7F           command-queue read index
 *   [bp-0x100] abRecord[0x100] RAD.HLP record / command queue
 *
 * Dropped-argument adaptation (see docs/notes-0800.md "## part 9"):
 *   fn1EDA_1085's dropped data-buffer far pointer is the caller's [bp-0x100]
 *   buffer; the port's record-I/O layer reads through the shared slot
 *   g_1EDA_io_buffer (src/seg1EDA_shared.h), which the caller must point at its
 *   own buffer.  2827 does so (and restores it) around the call.
 */

#include <stddef.h>
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0800.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1EDA_shared.h"
#include "seg13E2.h"
#include "seg1E78.h"
#include "seg0C74.h"
#include "seg1206.h"

// 0800:2827: u16 fn0800_2827(u16 * dsOut)
u16 fn0800_2827(u16 *dsOut)
{
	/* enter 282h,0h */
	u8  abStream[0x80];      /* [bp-0x180] RAD.HLP stream block                 */
	u8  bFE7F = 0x00;        /* [bp-0x181] command-queue read index             */
	u8  abRecord[0x100];     /* [bp-0x100] RAD.HLP record / command queue       */
	u8 *saved_io;            /* g_1EDA_io_buffer saved around fn1EDA_1085       */

	u16 dx_1236 = 0x0000;    /* engine_probe_file dxOut / fn1E78_030D DX              */
	u16 ds_226 = 0x0000;     /* fn1AB8_1536 dsOut                               */
	u16 ax_1369 = 0x0000;    /* fn1EDA_0B24 axOut                               */
	u16 dx_1370 = 0x0000;    /* fn1EDA_0B24 dxOut                               */
	u16 dx_1371 = 0x0000;    /* fn1EDA_0FD0 dxOut                               */
	u8  al_183;              /* fn1EDA_1123 return                              */
	u16 ax_184;              /* fn1EDA_1085 return                              */
	u16 ds_318 = 0x0000;     /* fn0800_04E3 dsOut                               */
	u16 dx_1375 = 0x0000;    /* fn1EDA_0A39 dxOut                               */
	u16 ds_408 = 0x0000;     /* fn1206_0066 dsOut (second)                      */
	u16 bp_1376 = 0x0000;    /* fn1206_0066 bpOut (second)                      */
	u8  ch_1377;             /* fn1206_0038 chOut                               */
	u16 dx_1378 = 0x0000;    /* fn1206_0038 dxOut                               */
	u16 dx_1379 = 0x0000;    /* fn0800_00C1 dxOut                               */
	u16 ax_422;              /* fn0800_04CC(DGROUP:53D9h)                       */
	u16 ax_423;              /* fn0800_04CC(DGROUP:53DAh)                       */
	u16 ax_482;              /* DGROUP:53DDh * 0x3C                             */
	u16 dx_482;              /* cwd(ax_482)                                     */
	u16 ax_1183;             /* DGROUP:0002h (record limit low)                 */
	u8  al_546;              /* dispatch byte (DGROUP:53D2h)                    */
	u8  ch_1373;             /* fn1AB8_1D82 chOut (first)                       */
	u8  ch_1374;             /* fn1AB8_1D82 chOut (second)                      */
	u8  ch_1380;             /* fn1206_015B chOut                               */
	u16 dx_1381 = 0x0000;    /* fn1206_015B dxOut                               */
	u16 bp_1121 = 0x0000;    /* 1206 frame-pointer preservation artifact        */
	u16 ds = 0x0000;         /* dropped DGROUP selector                         */

	/* 09C2 / 0C74 register-output scratch (all dead outputs; the original
	 * keeps them in separate stack slots, kept separate here).  The dsOut of
	 * engine_frame_dispatch / 54F0 / 54B1 is a far block pointer (Reko assigns a
	 * struct pointer), so those sinks are void*; part 8 used u16 there -- see
	 * docs/notes-0800.md "## part 9". */
	u16 bp_1382 = 0x0000, bp_1383 = 0x0000, bp_1384 = 0x0000;
	void *ds_1059 = NULL;
	u16 bp_982 = 0x0000, ds_1014 = 0x0000, bp_1385 = 0x0000;
	u16 bp_1386 = 0x0000, ds_923 = 0x0000, bp_1387 = 0x0000;
	u16 bp_1388 = 0x0000, ds_864 = 0x0000, bp_1389 = 0x0000;
	u16 bp_740 = 0x0000, ds_744 = 0x0000;
	u16 dx_1390 = 0x0000, bp_1391 = 0x0000;
	void *ds_770 = NULL;
	u16 bp_1393 = 0x0000, ds_792 = 0x0000, bp_1394 = 0x0000, bp_1392 = 0x0000;
	u16 bp_620 = 0x0000, ds_624 = 0x0000;
	u16 dx_1395 = 0x0000, bp_1396 = 0x0000;
	void *ds_650 = NULL;
	u16 bp_1398 = 0x0000, ds_672 = 0x0000, bp_1399 = 0x0000, bp_1397 = 0x0000;
	u16 bp_1400 = 0x0000, ds_574 = 0x0000, bp_1401 = 0x0000;

	for (;;)   /* l0800_282B */
	{
		/* mov di,2810h ; push cs ; push di ; call far 0C74h:0000h
		 * (cs:2810h = {7,"Rad.hlp"}; al==0 -> l0800_2839 jmp 2B41h). */
		if (engine_probe_file(&g_seg0800[0x2810], &dx_1236) == 0x00)
			break;

		/* l0800_283C: drain the pending-key queue.  fn1E78_030D takes no
		 * stack argument in the original (`retf`); Reko threads the DX
		 * register through dx_1236 (written by engine_probe_file above).  The
		 * frozen prototype's wArg02 slot is seeded 0. */
		while (fn1E78_02FB() != 0x00)
			(void)fn1E78_030D((s16)dx_1236, 0x0000, &dx_1236);

		/* l0800_284C */
		(void)fn1206_0066(&bp_1121, &ds);
		(void)fn13E2_003B();
		fn0800_01FE();

		/* mov di,5ECEh ; push ds ; push di ; mov di,2818h ; push cs ;
		 * push di ; call far 1EDAh:0B24h  (cs:2818h = {6,"NONAME"}).
		 * The .asm is `jnz 2879h` (ZF=0 = not equal -> continue), so the
		 * reset at l0800_286A runs on EQUALITY.  Reko emitted the inverted
		 * `if (!fn1EDA_0B24(...))` here; this port follows the .asm.
		 * (port fn1EDA_0B24 returns nonzero on equality, 0 otherwise) */
		if (fn1EDA_0B24(&g_seg0800[0x2818], &g_dgroup[0x5ECE],
		                &ax_1369, &dx_1370) != 0x00)
		{
			/* l0800_286A: record name == "NONAME" -> reset and exit. */
			LG16(0x598E) = 0x0001;
			LG16(0x5990) = 0x0000;
			break;
		}

		/* l0800_2879: open the RAD.HLP stream (cs:281Fh = {7,"RAD.HLP"}). */
		fn1EDA_0FA2(&g_seg0800[0x281F], abStream);
		(void)fn1EDA_0FD0(0x0100, abStream, &dx_1371);
		al_183 = (u8)fn1EDA_1123(LG16(0x598E), LG16(0x5990), abStream);
		/* fn1EDA_1085's dropped data-buffer argument is the caller's
		 * [bp-0x100] buffer (the two far pointers pushed are abStream =
		 * stream block and abRecord = data buffer).  Point the port's
		 * shared record-I/O slot at it, then restore. */
		saved_io = g_1EDA_io_buffer;
		g_1EDA_io_buffer = abRecord;
		ax_184 = fn1EDA_1085(al_183, abStream);
		g_1EDA_io_buffer = saved_io;
		(void)fn1EDA_1051((u8)ax_184, abStream);

		/* cmp byte ptr [bp+0FF01h],20h ; jnz 28D3h  ([bp-0FFh] = abRecord[1]) */
		if (abRecord[1] == 0x20)
			break;                     /* l0800_28D0: jmp 2B41h */

		/* l0800_28D3: paint the RAD.HLP frame and load the mission state. */
		(void)fn1AB8_1536(0x0001, 0x0000, 0x0000, &ds_226);
		fn1AB8_14F4(0x0001, 0x0001);
		/* push 0Fh ; push 184h ; push 114h ; push 18Fh ; call 005Ah */
		fn0800_005A(0x018F, 0x0114, 0x0184, 0x000F);
		(void)fn1AB8_1C32(0x08);
		/* push 94h ; push 18Ah ; push ds:5CBBh ; call far 1AB8h:1D82h */
		(void)fn1AB8_1D82(&g_dgroup[0x5CBB], 0x018A, 0x0094, &ch_1373);
		(void)fn1AB8_1C32(0x0A);
		(void)fn1AB8_1D82(&g_dgroup[0x5CBB], 0x018A, 0x0094, &ch_1374);
		(void)fn0800_04E3(&ds_318);
		/* mov di,5ECEh ; push ds ; push di ; mov di,5ED6h ; push ds ;
		 * push di ; push 6h ; call far 1EDAh:0A39h  (dst 5ED6, src 5ECE) */
		(void)fn1EDA_0A39(0x06, &g_dgroup[0x5ED6], &g_dgroup[0x5ECE],
		                  &dx_1375);
		(void)fn0800_0619();
		(void)fn0800_0BEC();
		fn13E2_00FB();
		/* push 8h ; push 0h ; call far 1AB8h:1342h */
		(void)fn1AB8_1342(0x00, 0x08);
		(void)fn1206_0066(&bp_1376, &ds_408);
		/* mov al,[53D9h] ; push ax ; call 04CCh ; push ax ;
		 * mov al,[53DAh] ; push ax ; call 04CCh ; push ax ;
		 * call far 0C74h:06B7h.  The 06B7 result is the argument of the
		 * following 1206:0038 call, which does not read it (the frozen
		 * 0038 prototype has no input slot); 06B7's side effects are kept
		 * and its result dropped. */
		ax_422 = (u16)fn0800_04CC((u8)LG8(0x53D9));
		ax_423 = (u16)fn0800_04CC((u8)LG8(0x53DA));
		(void)engine_arm_window_geometry(ax_423, ax_422);
		(void)fn1206_0038(&ch_1377, &dx_1378, &bp_1121, &ds);
		/* mov al,[53DDh] ; xor ah,ah ; imul ax,ax,3Ch ; cwd ;
		 * push dx ; push ax ; call 00C1h */
		ax_482 = (u16)((u16)LG8(0x53DD) * 0x003C);
		dx_482 = (u16)((ax_482 & 0x8000) ? 0xFFFF : 0x0000);
		(void)fn0800_00C1(ax_482, dx_482, &dx_1379);
		/* mov byte ptr [bp+0FE7Fh],1h */
		bFE7F = 0x01;

		/* l0800_297D: command loop. */
		do
		{
			if (fn1E78_02FB() != 0x00)
				goto l0800_2991;
			/* push 0h ; call far 1206h:015Bh */
			if ((u8)fn1206_015B(&ch_1380, &dx_1381, &bp_1121, &ds) != 0x00)
				goto l0800_2991;

			/* l0800_2997: pop the next command byte from the record. */
			if (bFE7F < 0xFF)
			{
				LG8(0x53D2) = abRecord[bFE7F];
				++bFE7F;
			}

			/* l0800_29B1: dispatch. */
			al_546 = LG8(0x53D2);
			switch (al_546)
			{
			case 0x3B:                             /* ';' */
				(void)fn0800_09C2(0x0E, &bp_1382, &ds);
				if (LG8(0x53DB) > 0x00)
				{
					if (engine_frame_dispatch(&bp_1384, &ds_1059) != 0x00)
						LG8(0x53DB) = (u8)(LG8(0x53DB) - 0x01);
				}
				(void)fn0800_09C2(0x05, &bp_1383, &ds);
				break;
			case 0x3C:                             /* '<' */
				(void)fn0800_09C2(0x0F, &bp_982, &ds_1014);
				LG8(0x58BD) = abRecord[bFE7F];
				++bFE7F;
				if (LG8(0x53DC) > 0x00)
				{
					if (engine_frame_retract(&ds_1014) != 0x00)
						LG8(0x53DC) = (u8)(LG8(0x53DC) - 0x01);
				}
				(void)fn0800_09C2(0x06, &bp_1385, &ds);
				break;
			case 0x3D:                             /* '=' */
				(void)fn0800_09C2(0x10, &bp_1386, &ds_923);
				if (LG8(0x53DE) > 0x00 && engine_frame_pull_in_extended(&ds_923) != 0x00)
					LG8(0x53DE) = (u8)(LG8(0x53DE) - 0x01);
				(void)fn0800_09C2(0x07, &bp_1387, &ds);
				break;
			default:
				if (al_546 == 0x1B)                /* ESC */
					goto l0800_2A3A;
				if (al_546 == 0x48)                /* 'H' */
				{
					(void)fn0800_09C2(0x09, &bp_1388, &ds_864);
					(void)engine_call_rocket_trajectory();
					(void)fn0800_09C2(0x00, &bp_1389, &ds);
				}
				else if (al_546 == 0x4B)           /* 'K' */
				{
					(void)fn0800_09C2(0x0A, &bp_740, &ds_744);
					LG8(0x58BD) = abRecord[bFE7F];
					++bFE7F;
					if (engine_probe_march_left(&dx_1390, &bp_1391,
					                &ds_770) == 0x00)
					{
						(void)fn0800_09C2(0x0E, &bp_1393, &ds_792);
						(void)fn0800_08C0();
						(void)fn0800_09C2(0x05, &bp_1394, &ds);
					}
					(void)fn0800_09C2(0x01, &bp_1392, &ds);
				}
				else if (al_546 == 0x4D)           /* 'M' (77) */
				{
					(void)fn0800_09C2(0x0C, &bp_620, &ds_624);
					LG8(0x58BD) = abRecord[bFE7F];
					++bFE7F;
					if (engine_probe_march_right(&dx_1395, &bp_1396,
					                &ds_650) == 0x00)
					{
						(void)fn0800_09C2(0x0E, &bp_1398, &ds_672);
						(void)fn0800_08C0();
						(void)fn0800_09C2(0x05, &bp_1399, &ds);
					}
					(void)fn0800_09C2(0x03, &bp_1397, &ds);
				}
				else if (al_546 == 0x50)           /* 'P' */
				{
					(void)fn0800_09C2(0x0D, &bp_1400, &ds_574);
					(void)engine_edge_collision_probe();
					(void)fn0800_09C2(0x04, &bp_1401, &ds);
				}
				break;
			}

			/* l0800_2ADE: fn0800_0C71(ds,out bp,out ds) ; the loop test is
			 * `fn0800_0877() == 0 && DGROUP:58B3h == 0`. */
			(void)fn0800_0C71(&bp_1121, &ds);
		} while (fn0800_0877() == 0x00 && LG8(0x58B3) == 0x00);

		/* l0800_2AF2 */
		fn0800_0103();
		if (fn0800_0877() != 0x00)
		{
			/* add word ptr [598Eh],1h ; adc word ptr [5990h],0h */
			LG32(0x598E) = (u32)(LG32(0x598E) + 0x00000001u);
			ax_1183 = (u16)LG8(0x0002);
			if (LG16(0x5990) == 0x0000 && ax_1183 == LG16(0x598E))
			{
				(void)fn0800_166D();
				break;                 /* l0800_2B19: jmp 2B41h */
			}
			if (LG16(0x5990) == 0x0000 && LG16(0x598E) == 0x00FA)
			{
				LG16(0x598E) = 0x0001;
				LG16(0x5990) = 0x0000;
			}
		}

		/* l0800_2B39 */
		(void)fn1206_0066(&bp_1121, &ds);
	}

	/* l0800_2B41: leave ; ret */
	*dsOut = 0x0000;               /* DGROUP selector dropped in flat model */
	return 0x0000;                 /* AX at retf; its caller (0800:3D9D) ignores it */

l0800_2991:
l0800_2A3A:
	/* l0800_2991 / l0800_2A3A: call 0103h ; jmp 2B41h */
	fn0800_0103();
	*dsOut = 0x0000;
	return 0x0000;
}
