/* seg1229_part1.c -- RAD V3.1 preservation port, segment 1229, part 1.
 *
 * Functions 1229:0000 .. 1229:061B (6 functions, ascending offset):
 *   0000 0040 039D 0486 050A 061B
 * Literal recovery from analysis/slices/1229/1229_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg1229.h
 * (analysis/summary/iface.tsv).  See CONVENTIONS.md,
 * analysis/SEGMAP.md and docs/notes-1229.md ("## part 1").
 *
 * Hardware / DOS services: none of these functions issues an int 10h /
 * int 16h / int 21h or a port I/O directly.  Every DOS/BIOS/hardware
 * service reached from here goes through segment 1AB8 (video/text),
 * 1EDA (DOS file/string) or 1E78 (keyboard/PIT), replaced there.
 *
 * Cross-segment callees are declared by their frozen headers.  The dropped
 * `ds` register arguments and the `dsOut` register outputs (which the
 * original carried in the DS register, not on the stack) are adapted per
 * CONVENTIONS.md: the flat port stores 0 (the DGROUP selector has no flat
 * meaning).  The original's "caller stages a persistent far pointer on the
 * stack and shares it with the following string calls" idiom is recovered
 * with explicit pointer arguments, following the part-4b/part-5a
 * convention already used for fn1EDA_0A39/0A1F/0AAC/1085/0F71.
 *
 * The `enter N,0` frames are reproduced as local buffers named by their
 * bp-relative offset (kept in comments).  Note that fn1229_0040's
 * accumulated text buffer [bp-0206h] is a full 0x100-byte record that grows
 * up to [bp-0107h], immediately below the block-pointer words at
 * [bp-0106h].
 */

#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1229.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1E78.h"
#include "seg13C1.h"

// 1229:0000: void fn1229_0000(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)
void fn1229_0000(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)
{
	u16 ax_10CE;
	u16 ax_10E1;

	/* push [bp+0Ch..6h] ; push 1h ; far 1AB8:0F93 */
	fn1AB8_0F93(0x01, wArg04, wArg06, wArg08, wArg0A);
	fn1AB8_1028();
	/* mov ax,[0B7C2h] (10CE), then 10E1, then pop the two staged zeros */
	ax_10CE = fn1AB8_10CE();
	ax_10E1 = fn1AB8_10E1();
	fn1AB8_0F93(0x01, ax_10E1, ax_10CE, 0x00, 0x00);
}

// 1229:0040: u8 fn1229_0040(u8 * ptrArg04, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E, u8 * ptrArg10, void * dsOut)
u8 fn1229_0040(u8 * ptrArg04, u16 wArg08, u16 wArg0A, u16 wArg0C, u16 wArg0E, u8 * ptrArg10, void * dsOut)
{
	u8  buf410[0x100];   /* [bp-0410h] final assembled string */
	u8  buf310[0x100];   /* [bp-0310h] field scratch */
	u16 wLoc212;         /* [bp-0210h] 5000/10000 blink counter */
	u16 wLoc20E;         /* [bp-020Eh] fn1AB8_10A8() saved for the '8' branch */
	u16 wLoc20C;         /* [bp-020Ch] midpoint of wArg08/wArg0C */
	u16 wLoc20A;         /* [bp-020Ah] fn1AB8_10A8() latched at loop entry */
	u8  bLoc207;         /* [bp-0207h] current key */
	u8  buf206[0x100];   /* [bp-0206h] accumulated length-prefixed text */
	u16 wLoc106;         /* [bp-0106h] fn1AB8_13A3 result */
	u16 wLoc104;         /* [bp-0104h] allocated block offset */
	u16 wLoc102;         /* [bp-0102h] allocated block segment */
	u8  buf100[0x100];   /* [bp-0100h] first format buffer */
	u16 ax_56;
	u32 dx_ax_1306;
	u16 dx_1308;
	u16 ds_75;
	u16 ds_171;
	u16 ds_976;
	u8  ch_1309;
	u16 dx_1310;
	u16 dx_1311;
	u16 dx_451;
	u16 dx_1312;
	u16 dx_1313;
	u16 dx_1314;
	u16 dx_1315;
	s16 ret_0254;

	/* fn1EDA_0A39(0FFh, ss:bp-0100h, ptrArg04) : copy the caller's prompt */
	fn1EDA_0A39(0xFF, buf100, ptrArg04, &dx_1308);
	fn1AB8_1C32(0x0B);
	ax_56 = fn1AB8_13A3(wArg08, wArg0A, wArg0C, wArg0E);
	wLoc106 = ax_56;
	/* fn1EDA_023F: allocate ax_56 bytes; DX:AX = far block.  The frozen
	 * wArg00/wArg02 are the far return-address words (the .asm pushes only
	 * the one size word). */
	dx_ax_1306 = fn1EDA_023F(ax_56, 0x0000, 0x0000, &ds_75);
	wLoc104 = (u16)dx_ax_1306;
	wLoc102 = (u16)(dx_ax_1306 >> 16);
	fn1AB8_1E6B(far_ptr(((u32)wLoc102 << 16) | (u32)wLoc104),
	            wArg08, wArg0A, wArg0C, wArg0E);
	fn1229_0000(wArg08, wArg0A, wArg0C, wArg0E);
	fn1AB8_112E(wArg08, wArg0A, wArg0C, wArg0E);
	fn1AB8_1536(0x01, 0x00, 0x00, &ds_171);
	fn1AB8_14F4(0x01, 0x00);
	/* mov ax,[bp+0Ah] ; sub ax,[bp+0Eh] ; shr ax,1 ; add ax,[bp+0Eh] */
	wLoc20C = (u16)(((u16)(wArg08 - wArg0C) >> 0x01) + wArg0C);
	fn1AB8_1D82(buf100, wLoc20C,
	            (u16)(fn1AB8_1E0B(&g_seg1229[0x0036]) + wArg0E), &ch_1309);
	fn1EDA_0A1F(&g_seg1229[0x0039], buf310);
	fn1EDA_0AAC(buf100, buf310);
	fn1AB8_108B(wLoc20C, (u16)(fn1AB8_1E0B(buf310) + wArg0E));
	wLoc20A = fn1AB8_10A8();
	buf206[0] = 0x00;
	bLoc207 = 0x25;      /* '%' */
	wLoc212 = 0x0000;

	for (;;)
	{
		++wLoc212;
		if (wLoc212 == 0x1388)
		{
			u16 ax1;
			u16 ax2;

			fn1AB8_1C32(0x0B);
			ax1 = fn1AB8_10A8();
			ax2 = fn1AB8_10A8();
			fn1AB8_1AF6((u16)(wLoc20C - 0x0006), ax2,
			            (u16)(wLoc20C + 0x0006), ax1, &dx_1310);
		}
		if (wLoc212 == 0x2710)
		{
			u16 ax1;
			u16 ax2;

			wLoc212 = 0x0000;
			fn1AB8_1C32(0x00);
			ax1 = fn1AB8_10A8();
			ax2 = fn1AB8_10A8();
			fn1AB8_1AF6((u16)(wLoc20C - 0x0006), ax2,
			            (u16)(wLoc20C + 0x0006), ax1, &dx_1311);
		}

		if (fn1E78_02FB() != 0x00)
		{
			u16 ax1;
			u16 ax2;

			fn1AB8_1C32(0x00);
			ax1 = fn1AB8_10A8();
			ax2 = fn1AB8_10A8();
			fn1AB8_1AF6((u16)(wLoc20C - 0x0006), ax2,
			            (u16)(wLoc20C + 0x0006), ax1, &dx_451);
			fn1AB8_1C32(0x0A);
			bLoc207 = (u8)fn1EDA_1384(
				(u8)fn1E78_030D((s16)dx_451, 0x000A, &dx_1312));

			if (bLoc207 >= 0x15)
			{
				/* l1229_0202: accept the character only while the
				 * cursor column (10A8) is left of (wArg0A - fieldlen). */
				u16 ax_788;
				s32 v_a;
				s32 v_b;

				ax_788 = (u16)(wArg0A - fn1AB8_1E0B(&g_seg1229[0x0036]));
				v_a = (s32)(s16)fn1AB8_10A8();
				v_b = (s32)(u32)ax_788;
				if (v_a < v_b)
				{
					/* l1229_0229 */
					fn1EDA_0B4F(bLoc207, buf310);
					fn1AB8_1492(buf310);
					fn1EDA_0A1F(buf206, buf410);
					fn1EDA_0B4F(bLoc207, buf310);
					fn1EDA_0AAC(buf310, buf410);
					fn1EDA_0A39(0xFF, buf206, buf410, &dx_1313);
				}
			}
			else if (bLoc207 == 0x08)
			{
				/* l1229_027C / l1229_029C: backspace */
				u16 ax_488;
				s32 v_a;
				s32 v_b;
				u16 q1;
				u16 p2;
				u16 r1;
				u16 s1;
				u16 q2;
				u16 p3;
				u16 r2;
				u16 s2;
				u16 diff1;
				u16 diff3;
				u16 sum2;
				u16 sum4;

				ax_488 = fn1AB8_10A8();
				v_a = (s32)(u16)wLoc20A;
				v_b = (s32)(s16)ax_488;
				if (v_a < v_b)
				{
					wLoc20E = fn1AB8_10A8();
					q1 = fn1AB8_1E0B(&g_seg1229[0x003E]);
					p2 = fn1AB8_10A8();
					diff1 = (u16)(p2 - q1);
					r1 = fn1AB8_1783(&g_seg1229[0x003E]);
					s1 = fn1AB8_10BB();
					diff3 = (u16)(s1 - (u16)(r1 >> 0x01));
					q2 = fn1AB8_1E0B(&g_seg1229[0x003E]);
					p3 = fn1AB8_10A8();
					sum2 = (u16)(p3 + q2);
					r2 = fn1AB8_1783(&g_seg1229[0x003E]);
					s2 = fn1AB8_10BB();
					sum4 = (u16)(s2 + (u16)(r2 >> 0x01));
					fn1229_0000(sum4, sum2, diff3, diff1);
					fn1AB8_108B(wLoc20C,
					            (u16)(wLoc20E -
					                  fn1AB8_1E0B(&g_seg1229[0x003E])));
					/* l1229_0353: the .asm pushes buf206[0]; Reko's
					 * `0` constant is shadowed here by the real byte. */
					fn1EDA_0BD0(0x01, (u16)buf206[0], buf206);
				}
			}
		}

		if (bLoc207 == 0x0D)
			break;
	}

	/* l1229_0353: repaint the block, free it, then format the result into
	 * the caller's persistent pointer ptrArg10 ([bp+12h]). */
	fn1AB8_13D7(0x00,
	            far_ptr(((u32)wLoc102 << 16) | (u32)wLoc104),
	            wArg0C, wArg0E);
	ret_0254 = fn1EDA_0254(wLoc106, wLoc104, wLoc102, 0,
	                       &dx_1314, &ds_976);
	fn1EDA_0A39(0xFF, buf206, ptrArg10, &dx_1315);
	*(u16 *)dsOut = ds_976;   /* DGROUP selector dropped in the flat model */
	return (u8)((u16)ret_0254 >> 8);
}

// 1229:039D: void fn1229_039D(void)
void fn1229_039D(void)
{
	u8  abBuf80[0x80];   /* [bp-0080h] 0x80-byte DOS stream block */
	u16 dx_357;
	u16 dx_358;
	u16 dx_359;
	u16 dx_361;
	u16 dx_362;
	u16 ax_355;
	u16 ax_356;
	u8  bLoc83;          /* [bp-0081h] byte loop index */
	u8  al_158;

	if (LG8(0x6BBA) != 0x00)
		fn1EDA_0A39(0x06, &g_dgroup[0x6BB2], &g_dgroup[0x6BBA], &dx_358);
	else
		fn1EDA_0A39(0x06, &g_dgroup[0x6BB2], &g_seg1229[0x038E], &dx_357);

	/* b = 1 ; do { encode(6BB2[b]) ; } while (++b != 6) */
	bLoc83 = 0x01;
	for (;;)
	{
		LG8((u16)(0x6BB2 + bLoc83)) =
			(u8)fn1EDA_1384(LG8((u16)(0x6BB2 + bLoc83)));
		if (bLoc83 == 0x06)
			break;
		++bLoc83;
	}

	fn1EDA_0FA2(&g_seg1229[0x0395], abBuf80);   /* cs:0395 = {7,"RAD.DAT"} */
	al_158 = fn1EDA_0FD0(0x0219, abBuf80, &dx_359);
	LG16(0x598E) = 0xFFFF;
	LG16(0x5990) = 0xFFFF;

	for (;;)
	{
		fn1EDA_1085(al_158, abBuf80);
		LG32(0x598E) = (u32)(LG32(0x598E) + 0x00000001u);
		if ((u8)fn1EDA_1185(abBuf80) != 0x00)   /* 1185: position >= size */
			break;
		if (fn1EDA_0B24(&g_dgroup[0x6BB2], &g_dgroup[0x5CB4],
		                &ax_355, &dx_361) != 0x00)   /* jz 0472: equal -> stop */
			break;
		if (fn1EDA_0B24(&g_seg1229[0x038E], &g_dgroup[0x5CB4],
		                &ax_356, &dx_362) != 0x00)   /* jnz 0426: unequal -> loop */
			break;
	}
	/* fn1EDA_1051 ignores its `al` argument */
	fn1EDA_1051(0x00, abBuf80);
}

// 1229:0486: u16 fn1229_0486(void)
u16 fn1229_0486(void)
{
	u8  abBuf80[0x80];   /* [bp-0080h] 0x80-byte DOS stream block */
	u16 dx_215;
	u16 dx_219;
	u16 ax_102;
	u8  ch_218;
	u16 ds_168;

	fn1EDA_0FA2(&g_seg1229[0x047E], abBuf80);   /* cs:047E = {7,"RAD.DAT"} */
	fn1EDA_0FD0(0x0219, abBuf80, &dx_215);
	/* seek to record [5990h]:[598Eh], then read one record; the record id
	 * in AL is passed on to 1085 (the data pointer ds:5CB4 is dropped). */
	fn1EDA_1085((u8)fn1EDA_1123(LG16(0x598E), LG16(0x5990), abBuf80), abBuf80);

	/* int 21h error word 5380h: if set, step the record index back one and
	 * delay ~500 ms (speaker). */
	if (fn1EDA_04A2() != 0x00)
	{
		LG32(0x598E) = (u32)(LG32(0x598E) - 0x00000001u);
		fn1E78_02C7(0x0096);
		fn1E78_029C(0x01F4, &dx_219);
		ax_102 = fn1E78_02F4();
	}
	else
		ax_102 = 0x0000;

	fn1EDA_1051((u8)ax_102, abBuf80);
	fn1EDA_04A9(0x0000, 0x0000, &ch_218, &ds_168);
	return 0x0000;   /* original returns the dropped DGROUP selector */
}

// 1229:050A: u16 fn1229_050A(u8 bArg02, u8 * ptrArg04, u16 * dsOut)
u16 fn1229_050A(u8 bArg02, u8 * ptrArg04, u16 * dsOut)
{
	u8  buf40A[0x100];   /* [bp-040Ah] fn1229_0040 output (persistent ptrArg10) */
	u8  buf30A[0x100];   /* [bp-030Ah] formatted number */
	u8  buf20A[0x100];   /* [bp-020Ah] assembled prompt / 0040 input */
	u16 wLoc10A;         /* [bp-010Ah] fn1EDA_0F71 result */
	u16 wLoc108;         /* [bp-0108h] fn1EDA_0F71 cursor out */
	u8  buf106[0x04];    /* [bp-0106h] 2-byte field (1..3 written) */
	u8  buf102[0x100];   /* [bp-0102h] prompt copy */
	u8  bLoc01;          /* [bp-0001h] result byte */
	u16 dx_399;
	u16 ax_55;
	u16 ax_71;
	u16 ax_87;
	u16 ax_103;
	u16 ds_231;
	u16 dx_400;
	u16 si_401;
	void *es_402;

	fn1EDA_0A39(0xFF, buf102, ptrArg04, &dx_399);

	/* idiv by 2 is signed (cwd + idiv).  Push order in the .asm is
	 * ax_55, ax_71, ax_87, ax_103 (so 0040 receives D,C,B,A). */
	ax_55 = (u16)(((s16)fn1AB8_10CE() / 0x0002) - 0x0068);
	ax_71 = (u16)(((s16)fn1AB8_10E1() / 0x0002) - 0x0010);
	ax_87 = (u16)(((s16)fn1AB8_10CE() / 0x0002) + 0x0068);
	ax_103 = (u16)(((s16)fn1AB8_10E1() / 0x0002) + 0x0010);

	fn1EDA_0A1F(&g_seg1229[0x0503], buf20A);     /* cs:0503 = {1," "} */
	fn1EDA_0AAC(buf102, buf20A);
	fn1EDA_0AAC(&g_seg1229[0x0505], buf20A);     /* cs:0505 = {1,"("} */
	fn13C1_0036((u32)bArg02, buf30A);
	fn1EDA_0AAC(buf30A, buf20A);
	fn1EDA_0AAC(&g_seg1229[0x0507], buf20A);     /* cs:0507 = {2,"):"} */

	fn1229_0040(buf20A, ax_103, ax_87, ax_71, ax_55, buf40A, &ds_231);

	fn1EDA_0A39(0x02, buf106, buf40A, &dx_400);
	wLoc10A = fn1EDA_0F71((u8 *)&wLoc108, buf106, &si_401, &es_402);
	if (wLoc108 != 0x0000)
		wLoc10A = (u16)bArg02;
	bLoc01 = (u8)wLoc10A;
	/* original: wait for the keyboard buffer to drain */
	while (fn1E78_02FB() != 0x00)
		;
	*dsOut = ds_231;
	/* The original's AH at the ret is unspecified (the Reko register is
	 * undefined); the callers consume only AL. */
	return (u16)bLoc01;
}

// 1229:061B: u16 fn1229_061B(s16 * dxOut, u16 * dsOut)
u16 fn1229_061B(s16 * dxOut, u16 * dsOut)
{
	u8  buf208[0x100];   /* [bp-0208h] fn1229_0040 output (persistent ptrArg10) */
	u8  buf108[0x100];   /* [bp-0108h] assembled prompt / 0040 input */
	u8  buf4[0x04];      /* [bp-0004h] 2-byte answer field */
	u8  bLoc01;          /* [bp-0001h] result byte */
	u16 ax_29;
	u16 ax_45;
	u16 ax_61;
	u16 ax_77;
	u16 ds_145;
	u16 dx_289;
	u16 ax_290;
	u16 dx_191;

	bLoc01 = 0x00;

	ax_29 = (u16)(((s16)fn1AB8_10CE() / 0x0002) - 0x00B0);
	ax_45 = (u16)(((s16)fn1AB8_10E1() / 0x0002) - 0x0010);
	ax_61 = (u16)(((s16)fn1AB8_10CE() / 0x0002) + 0x00B0);
	ax_77 = (u16)(((s16)fn1AB8_10E1() / 0x0002) + 0x0010);

	fn1EDA_0A1F(&g_seg1229[0x05F8], buf108);     /* cs:05F8 = {1," "} */
	fn1EDA_0AAC(&g_dgroup[0x5CB4], buf108);
	fn1EDA_0AAC(&g_seg1229[0x05FA], buf108);     /* cs:05FA = {0x1E," A ETE ..."} */

	fn1229_0040(buf108, ax_77, ax_61, ax_45, ax_29, buf208, &ds_145);

	fn1EDA_0A39(0x01, buf4, buf208, &dx_289);
	/* if the answer record equals cs:0619 ({1,"O"}) -> bLoc01 = 1 */
	if (fn1EDA_0B24(&g_seg1229[0x0619], buf4, &ax_290, &dx_191) != 0x00)
		bLoc01 = 0x01;

	fn1AB8_1C32(0x0F);
	/* original: wait for the keyboard buffer to drain */
	while (fn1E78_02FB() != 0x00)
		;

	*dxOut = (s16)dx_191;   /* DS selector left in DX (dropped) */
	*dsOut = ds_145;
	return (u16)bLoc01;
}
