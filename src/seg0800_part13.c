/* seg0800_part13.c -- RAD V3.1 preservation port, segment 0800, part 13+14.
 *
 * Functions 0800:3CFA .. 0800:3D9D (2 functions, ascending offset):
 *   3CFA  (the completion-time / "difficulty" timer, called by 3D9D)
 *   3D9D  (the top-level "quit / main menu" driver, called by fn0800_4255)
 *
 * Literal recovery from analysis/slices/0800/0800_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg0800.h
 * (analysis/summary/iface.tsv) adopted exactly:
 *   u16 fn0800_3CFA(void);
 *   u16 fn0800_3D9D(void).
 * See CONVENTIONS.md and docs/notes-0800.md ("## part 13+14").
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   None direct.  No int 10h / int 16h / int 21h, no `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch occur in
 *   3CFA/3D9D.  Every BIOS/DOS/hardware service reached from here is owned by
 *   the callee segments and replaced there: segment 1206 (mouse cursor via the
 *   INT 33h trampoline fn1E5F_000B), 1E78 (keyboard/PIT), 1AB8 (video/text),
 *   1EDA (DOS stream + string helpers), 0C74 (menu handlers), 13E2
 *   (palette/video), 1229 (the mission browser, itself INT-heavy).  The
 *   quit-to-DOS tail calls fn0800_0000 (converted in part 1), which runs the
 *   AdLib teardown and the CRT fatal exit fn1EDA_00E9(0).
 *
 * Flat-model far pointers (CONVENTIONS.md Memory model):
 *   cs:3D5Ah / cs:3D7Fh / cs:3D83h / cs:3D85h become &g_seg0800[0xHHHH];
 *   ds:5438h / ds:5452h / ds:546Ch / ds:5486h / ds:54A0h / ds:54BAh /
 *   ds:54D4h / ds:5ED6h and the ds:541Ch..ds:5436h coordinate words become
 *   g_dgroup[0xHHHH] / LG16(0xHHHH).  3CFA's interval record is ds:555Eh.
 *
 * Dropped-argument adaptations (see docs/notes-0800.md "## part 13+14"):
 *   fn0800_19E1's prototype now carries (flag, label, y, x, slot); the six
 *   words the original pushes are passed at each call site (repaired in this
 *   round, see notes part 5).
 *   fn1206_01AC's six staged words are likewise not representable (part 5).
 *   fn1E78_030D takes no stack argument in the original (`retf`), so its
 *   stale wArg02 is seeded 0 (parts 2/4/6/11 convention).
 *   fn0800_2C0C ignores its s16 dx argument; the value asm leaves in DX
 *   (fn0800_184C's return) is threaded through anyway.
 */

#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0800.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1206.h"
#include "seg0C74.h"
#include "seg1E78.h"
#include "seg1229.h"
#include "seg13E2.h"

/* 0800:3CFA: u16 fn0800_3CFA(void)
 * Time the "completion" hold: set the 53DFh "timed already" flag, select video
 * attribute 0, stamp the ds:555Eh interval record with the current clock
 * (fn0800_3BF2), then poll every clock tick (fn1AB8_122E + fn0800_3C72) until
 * the elapsed interval is positive or reaches 100 ticks.  The tick count * 8
 * / 100 (minimum 7) is stored at ds:58E6h.  Called from fn0800_3D9D. */
u16 fn0800_3CFA(void)
{
	u16 wLoc04 = 0x0000;   /* [bp-0002h] tick counter */
	s16 dx_78 = 0x0000;    /* fn0800_3C72 high word / comparison */
	u16 ax_74;             /* fn0800_3C72 low word / comparison */

	/* mov byte ptr [53DFh],1h */
	LG8(0x53DF) = 0x01;
	/* push 0h ; call far 1AB8h:1C32h */
	(void)fn1AB8_1C32(0x00);
	/* push ds:555Eh ; call 3BF2h */
	fn0800_3BF2(&g_dgroup[0x555E]);

	/* l0800_3D18: push 64h ; push 64h ; push 5Ah ; call far 1AB8h:122Eh ;
	 * inc [bp-2h] ; push ds:555Eh ; call 3C72h ; cmp dx,0. */
	do
	{
		(void)fn1AB8_122E(0x005A, 0x0064, 0x0064);
		++wLoc04;
		ax_74 = fn0800_3C72(&g_dgroup[0x555E], &dx_78);
	} while (dx_78 <= 0x0000 && (dx_78 < 0x0000 || ax_74 <= 0x0064));

	/* mov ax,[bp-2h] ; shl ax,3h ; xor dx,dx ; mov cx,64h ; div cx ;
	 * mov [58E6h],ax */
	LG16(0x58E6) = (u16)(((u16)wLoc04 << 0x03) / 0x0064);
	/* cmp word [58E6h],7h ; jge ; else mov word [58E6h],7h */
	if (LG16(0x58E6) < 0x0007)
		LG16(0x58E6) = 0x0007;

	/* leave ; ret -- original returns the dropped DGROUP selector (0). */
	return 0x0000;
}

/* 0800:3D9D: u16 fn0800_3D9D(void)
 * Top-level driver: bring up the video/mouse/keyboard state, load the menu
 * data (fn0800_3CFA when 53DFh is clear), paint the initial "GICIEL" button
 * frame, then run the modal key/mouse loop dispatching on [bp-1h].  21h
 * leaves the nested editor and returns; 3Bh/3Ch/3Dh/3Eh/3Fh/40h drive the
 * nested screens (0C74 menu handlers, fn0800_11EF/149F/2004/391E/21E7 and the
 * 1229 mission browser); 41h ('A') quits: repaint the exit button, run
 * engine_scatter_muck and terminate through fn0800_0000.  Called from fn0800_4255. */
u16 fn0800_3D9D(void)
{
	u8 *abBuf = g_dgroup + 0xF900;   /* [bp-0106h] built menu label (0A1F/0AAC dest, 19E1 src); [bp-0106h] is SS-resident, and SS==DS in the tiny model, so stage at DGROUP 0xF900 for the ES:BX materialization */
	u8  bLoc01;            /* [bp-0001h] dispatched key / result byte */
	u16 bp_1592 = 0x0000;  /* [bp-2h] 1206:0066 bpOut (first)              */
	u16 ds_16 = 0x0000;    /* dropped DGROUP selector out of 1206:0066     */
	u16 ds_106 = 0x0000;   /* dropped selector out of 1AB8:1536            */
	u16 bp_1593 = 0x0000;  /* 1206:0066 bpOut (second)                     */
	u16 ds_118 = 0x0000;   /* 1206:0066 dsOut (second)                     */
	u8  ch_1594;           /* 1AB8:1D82 chOut                              */
	u16 si_1595 = 0x0000;  /* 1206:01AC siOut                              */
	void *es_1596 = 0;     /* 1206:01AC esOut                              */
	u16 ds_250 = 0x0000;   /* 1206:01AC dsOut                              */
	u8  ch_1597;           /* 1206:0038 chOut                              */
	u16 dx_1109 = 0x0000;  /* threaded DX (030D / 0066 / 029C / 19E1)      */
	u16 bp_1104 = 0x0000;  /* threaded BP frame artifact                   */
	u16 ds_1108 = 0x0000;  /* threaded dropped DGROUP selector             */
	u16 dx_184C;           /* fn0800_184C return (DX), then 2C0C's dx      */

	/* 21h branch. */
	u16 bp_1598 = 0x0000;  /* 1206:0066 bpOut                              */
	u16 ds_1465 = 0x0000;  /* 1206:0066 dsOut                              */
	u16 ds_1479 = 0x0000;  /* fn0800_184C dsOut                            */
	u16 ds_1009 = 0x0000;  /* dropped selector threaded out of the branch  */

	/* 3Bh branch. */
	u16 dx_1599 = 0x0000, bp_1600 = 0x0000, ds_1388 = 0x0000;
	u16 bp_1601 = 0x0000, ds_1420 = 0x0000;
	u16 ds_1434 = 0x0000;

	/* 3Ch branch. */
	u16 dx_1602 = 0x0000, bp_1603 = 0x0000, ds_527 = 0x0000;
	u16 dx_1604 = 0x0000, bp_570 = 0x0000, ds_574 = 0x0000;

	/* 3Dh branch. */
	u16 dx_1605 = 0x0000, bp_1606 = 0x0000, ds_1291 = 0x0000;
	u16 bp_1607 = 0x0000, ds_1313 = 0x0000, ds_1340 = 0x0000;

	/* 3Fh branch. */
	u16 dx_1611 = 0x0000, bp_1612 = 0x0000, ds_770 = 0x0000;
	u16 bp_1613 = 0x0000, dx_1614 = 0x0000;
	u16 bp_1621 = 0x0000, ds_894 = 0x0000;
	u16 ax_1622 = 0x0000, dx_1623 = 0x0000, dx_1625 = 0x0000;
	u16 bp_1624 = 0x0000;
	s16 dx_981 = 0x0000;
	u8  ch_1620;           /* 1206:0038 chOut (2004/21E7 path)             */

	/* 40h branch. */
	u16 dx_1615 = 0x0000, bp_1616 = 0x0000, ds_1035 = 0x0000;
	u16 dx_1617 = 0x0000, bp_1618 = 0x0000, ds_1064 = 0x0000;
	u8  ch_1619;           /* 1206:0038 chOut (391E/21E7 path)             */

	/* 41h branch. */
	u16 dx_1608 = 0x0000, bp_1609 = 0x0000, ds_1223 = 0x0000;
	u16 bp_1610 = 0x0000, ds_1250 = 0x0000;

	/* call far 1206h:0066h ; call far 13E2h:003Bh ; call far 1AB8h:0F80h */
	fn1206_0066(&bp_1592, &ds_16);
	(void)fn13E2_003B();
	fn1AB8_0F80();
	/* cmp byte ptr [53DFh],0h ; jnz 3DBAh ; else call 3CFAh */
	if (LG8(0x53DF) == 0x00)
		(void)fn0800_3CFA();

	/* l0800_3DBA: call far 13E2h:0080h ; call 21E7h */
	(void)fn13E2_0080();
	(void)fn0800_21E7();
	/* push 7h ; call far 1AB8h:1C32h */
	(void)fn1AB8_1C32(0x07);
	/* push 1h ; push 0h ; push 2h ; call far 1AB8h:1536h */
	(void)fn1AB8_1536(0x02, 0x00, 0x01, &ds_106);
	/* call far 1206h:0066h */
	fn1206_0066(&bp_1593, &ds_118);
	/* push 140h ; push 1CEh ; push cs:3D5Ah ; call far 1AB8h:1D82h */
	(void)fn1AB8_1D82(&g_seg0800[0x3D5A], 0x01CE, 0x0140, &ch_1594);
	/* push 2h ; push 0h ; push 0h ; push 0h ; call far 1AB8h:1CBAh */
	(void)fn1AB8_1CBA(0x00, 0x00, 0x00, 0x02);
	/* push 2h ; push 2h ; call far 1AB8h:1342h */
	(void)fn1AB8_1342(0x02, 0x02);
	/* push 2h ; call far 1AB8h:1C32h */
	(void)fn1AB8_1C32(0x02);
	/* push 0h ; push 0h ; push 1h ; call far 1AB8h:10F4h */
	fn1AB8_10F4(0x01, 0x00, 0x00);
	/* push 6Ah ; push 16Dh ; push 203h ; push 1C9h ; call far 1AB8h:112Eh */
	(void)fn1AB8_112E(0x01C9, 0x0203, 0x016D, 0x006A);
	/* push 79h ; push 19Bh ; call far 0C74h:06B7h (the returned DGROUP
	 * selector is dropped in the flat model). */
	(void)engine_arm_window_geometry(0x019B, 0x0079);
	/* push 9Ch ; push 14h ; push 1E0h ; push 16Ah ; push 140h ; push 0B4h ;
	 * call far 1206h:01ACh (the six staged words are dropped by the frozen
	 * prototype, see docs/notes-0800.md part 5). */
	(void)fn1206_01AC(&si_1595, &es_1596, &ds_250);
	/* call far 1206h:0038h */
	(void)fn1206_0038(&ch_1597, &dx_1109, &bp_1104, &ds_1108);

l0800_3E46:
	/* l0800_3E46: mov byte ptr [58E0h],0h ; mov byte ptr [bp-1h],0FFh */
	LG8(0x58E0) = 0x00;
	bLoc01 = 0xFF;

	/* Four identical "if no key and no 58E0h flag, service the 0C74 clock"
	 * guards (3E58/3E6D/3E82/3E97): first two 54B1h, last two 54F0h. */
	if (fn1E78_02FB() == 0x00 && LG8(0x58E0) == 0x00)
		(void)engine_probe_march_right(&dx_1109, &bp_1104, &ds_1108);
	if (fn1E78_02FB() == 0x00 && LG8(0x58E0) == 0x00)
		(void)engine_probe_march_right(&dx_1109, &bp_1104, &ds_1108);
	if (fn1E78_02FB() == 0x00 && LG8(0x58E0) == 0x00)
		(void)engine_probe_march_left(&dx_1109, &bp_1104, &ds_1108);
	if (fn1E78_02FB() == 0x00 && LG8(0x58E0) == 0x00)
		(void)engine_probe_march_left(&dx_1109, &bp_1104, &ds_1108);

	/* l0800_3EA3: if a key is pending consume it (and drain the queue). */
	if (fn1E78_02FB() != 0x00)
	{
		bLoc01 = (u8)fn1E78_030D((s16)dx_1109, 0x0000, &dx_1109);
		if (bLoc01 == 0x00)
			bLoc01 = (u8)fn1E78_030D((s16)dx_1109, 0x0000, &dx_1109);
		while (fn1E78_02FB() != 0x00)
			(void)fn1E78_030D((s16)dx_1109, 0x0000, &dx_1109);
	}
	/* l0800_3ED2: cmp byte [58E0h],0h ; jz 3EDFh ; else call 1D55h. */
	if (LG8(0x58E0) != 0x00)
		bLoc01 = fn0800_1D55(&dx_1109, &bp_1104, &ds_1108);

	/* l0800_3EDF: mov al,[bp-1h] ; cmp al,21h ; jnz 3F01h */
	if (bLoc01 == 0x21)
	{
		/* l0800_3EE6: hide the cursor, redraw the 184Ch panel, clear
		 * 58B2h, run 2827h, set 58B2h and return to the caller. */
		fn1206_0066(&bp_1598, &ds_1465);
		(void)fn0800_184C(&ds_1479);
		LG8(0x58B2) = 0x00;
		(void)fn0800_2827(&ds_1009);
		LG8(0x58B2) = 0x01;
		return 0x0000;   /* jmp l0800_415E */
	}

	/* l0800_3F01: cmp al,3Bh ; jnz 3F2Fh */
	if (bLoc01 == 0x3B)
	{
		/* l0800_3F05: the F1/hotkey screen. */
		(void)fn0800_19E1(0x01, &g_dgroup[0x5438], LG16(0x542A),
		                  LG16(0x541C), 0x0001, &dx_1599, &bp_1600,
		                  &ds_1388);
		(void)engine_call_rocket_trajectory();
		fn1206_0066(&bp_1601, &ds_1420);
		dx_184C = fn0800_184C(&ds_1434);
		(void)fn0800_2C0C((s16)dx_184C, &ds_1009);
		return 0x0000;   /* jmp l0800_415E */
	}

	/* l0800_3F2F: cmp al,3Ch ; jz 3F36h else jmp 3FE3h */
	if (bLoc01 != 0x3C)
		goto l0800_3FE3;

	/* l0800_3F36: 3Ch -- the mission/slot frame. */
	(void)fn0800_19E1(0x01, &g_dgroup[0x5452], LG16(0x542C), LG16(0x541E),
	                  0x0002, &dx_1602, &bp_1603, &ds_527);
	(void)fn0800_11EF();
	(void)fn0800_19E1(0x00, &g_dgroup[0x5452], LG16(0x542C), LG16(0x541E),
	                  0x0002, &dx_1604, &bp_570, &ds_574);
	/* push 1h ; push 3h ; call far 1AB8h:1175h */
	fn1AB8_1175(0x03, 0x01);
	/* mov ax,[53E4h]-4 ; [53F2h]-1 ; [5400h]+4 ; [540Eh]+3 ;
	 * call far 1AB8h:1B3Eh */
	(void)fn1AB8_1B3E((u16)(LG16(0x540E) + 0x0003),
	                  (u16)(LG16(0x5400) + 0x0004),
	                  (u16)(LG16(0x53F2) - 0x0001),
	                  (u16)(LG16(0x53E4) - 0x0004));
	/* cmp word [5990h],0h ; jnz 3F97h ; cmp word [598Eh],1h ; jz 3FCCh */
	if (LG16(0x5990) == 0x0000 && LG16(0x598E) == 0x0001)
	{
		/* l0800_3FCC */
		(void)fn0800_19E1(0x00, &g_seg0800[0x3D85], LG16(0x542A),
		                  LG16(0x541C), 0x0001, &dx_1109, &bp_1104,
		                  &ds_1108);
	}
	else
	{
		/* l0800_3F97: build "..." in [bp-0106h] and draw it. */
		fn1EDA_0A1F(&g_seg0800[0x3D7F], abBuf);
		fn1EDA_0AAC(&g_dgroup[0x5ED6], abBuf);
		fn1EDA_0AAC(&g_seg0800[0x3D83], abBuf);
		(void)fn0800_19E1(0x00, abBuf, LG16(0x542A), LG16(0x541C), 0x0001,
		                  &dx_1109, &bp_1104, &ds_1108);
	}
	goto l0800_4134;

l0800_3FE3:
	/* l0800_3FE3: cmp al,3Dh ; jnz 4023h */
	if (bLoc01 == 0x3D)
	{
		/* l0800_3FE7 */
		(void)fn0800_19E1(0x01, &g_dgroup[0x546C], LG16(0x542E),
		                  LG16(0x5420), 0x0003, &dx_1605, &bp_1606,
		                  &ds_1291);
		LG16(0x598E) = 0x0000;
		LG16(0x5990) = 0x0000;
		fn1206_0066(&bp_1607, &ds_1313);
		(void)fn0800_149F();
		dx_184C = fn0800_184C(&ds_1340);
		(void)fn0800_2C0C((s16)dx_184C, &ds_1009);
		LG16(0x598E) = 0x0001;
		LG16(0x5990) = 0x0000;
		return 0x0000;   /* jmp l0800_415E */
	}

	/* l0800_4023: cmp al,3Eh ; jnz 4065h */
	if (bLoc01 == 0x3E)
	{
		/* l0800_4027: toggle 58B0h and repaint the 5486h button. */
		if (LG8(0x58B0) != 0x00)
		{
			LG8(0x58B0) = 0x00;
			(void)fn0800_19E1(0x01, &g_dgroup[0x5486], LG16(0x5430),
			                  LG16(0x5422), 0x0004, &dx_1109, &bp_1104,
			                  &ds_1108);
		}
		else
		{
			LG8(0x58B0) = 0x01;
			(void)fn0800_19E1(0x00, &g_dgroup[0x5486], LG16(0x5430),
			                  LG16(0x5422), 0x0004, &dx_1109, &bp_1104,
			                  &ds_1108);
		}
		goto l0800_4134;
	}

	/* l0800_4065: cmp al,3Fh ; jz 406Ch else jmp 4105h */
	if (bLoc01 == 0x3F)
	{
		/* l0800_406C: the "F5"/system screen. */
		(void)fn0800_19E1(0x01, &g_dgroup[0x54A0], LG16(0x5432),
		                  LG16(0x5424), 0x0005, &dx_1611, &bp_1612,
		                  &ds_770);
		fn1206_0066(&bp_1613, &ds_1009);
		(void)fn1E78_029C(0x0064, &dx_1614);
		/* cmp byte ptr [0002h],1Eh ; jbe 40F8h */
		if (LG8(0x0002) <= 0x1E)
		{
			/* l0800_40F8 */
			(void)fn0800_2004();
			(void)fn0800_21E7();
			(void)fn1206_0038(&ch_1620, &dx_1109, &bp_1104,
			                  &ds_1108);
			goto l0800_4134;
		}
		/* l0800_4093: modal RAD.MEM browser until 5CB3h is set. */
		do
		{
			(void)fn1AB8_1CBA(0x00, 0x2A, 0x00, 0x02);
			(void)fn1AB8_1342(0x02, 0x02);
			fn1206_0066(&bp_1621, &ds_894);
			(void)fn1AB8_1342(0x00, 0x08);
			/* push ds:5ED6h ; push cs:3D91h ; call far 1EDAh:0B24h ;
			 * jnz 40D9h */
			if (fn1EDA_0B24(&g_seg0800[0x3D91], &g_dgroup[0x5ED6],
			                &ax_1622, &dx_1623) == 0x00)
			{
				/* l0800_40C8: copy cs:3D96h into ds:5ED6h. */
				(void)fn1EDA_0A39(0x06, &g_dgroup[0x5ED6],
				                  &g_seg0800[0x3D96], &dx_1625);
			}
			/* l0800_40D9: push ds:5ED6h ; call far 1229h:0DCCh */
			dx_981 = (s16)fn1229_0DCC(&g_dgroup[0x5ED6], &bp_1624,
			                          &ds_1009);
			/* cmp byte [5CB3h],0h ; jnz 40EDh ; else call 31B7h */
			if (LG8(0x5CB3) == 0x00)
				(void)fn0800_31B7(dx_981, &ds_1009);
			/* l0800_40ED: cmp byte [5CB3h],0h ; jz 4093h */
		} while (LG8(0x5CB3) == 0x00);
		return 0x0000;   /* l0800_40F4: jmp l0800_415E */
	}

	/* l0800_4105: cmp al,40h ; jnz l0800_4134 */
	if (bLoc01 == 0x40)
	{
		/* l0800_4109: the "F6"/options screen. */
		(void)fn0800_19E1(0x01, &g_dgroup[0x54BA], LG16(0x5434),
		                  LG16(0x5426), 0x0006, &dx_1615, &bp_1616,
		                  &ds_1035);
		(void)fn1E78_029C(0x0064, &dx_1617);
		fn1206_0066(&bp_1618, &ds_1064);
		(void)fn0800_391E();
		(void)fn0800_21E7();
		(void)fn1206_0038(&ch_1619, &dx_1109, &bp_1104, &ds_1108);
	}

l0800_4134:
	/* l0800_4134: cmp byte [bp-1h],41h ; jz 413Dh else jmp 3E46h */
	if (bLoc01 != 0x41)
		goto l0800_3E46;

	/* l0800_413D: 'A' pressed -- repaint the 54D4h button, run the 0A35h
	 * shutdown screen, then terminate through fn0800_0000. */
	(void)fn0800_19E1(0x01, &g_dgroup[0x54D4], LG16(0x5436),
	                  LG16(0x5428), 0x0007, &dx_1608, &bp_1609, &ds_1223);
	(void)engine_scatter_muck();
	fn1206_0066(&bp_1610, &ds_1250);
	(void)fn0800_0000();

	/* l0800_415E: leave ; ret -- original returns the dropped DGROUP
	 * selector (0). */
	return 0x0000;
}
