/* seg1EDA_part4.c -- RAD V3.1 preservation port, segment 1EDA, chunk 4.
 *
 * Functions 1EDA:081A .. 1EDA:0A1F (11 functions, ascending offset):
 *   081A 0848 086C 0879 0896 08CE 0918 0953 096F 098A 0A1F
 * Literal recovery from analysis/slices/1EDA/1EDA_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg1EDA.h.
 * See CONVENTIONS.md and docs/notes-1EDA.md ("## chunk 4").
 *
 * Hardware / DOS services: none of these functions issue a raw int 10h / int
 * 21h or port I/O.  The DOS error word DGROUP:0x5380 is read/written directly
 * through the LG16() macro; fn1EDA_098A's divide-by-zero path tail-calls the
 * same-segment fatal-error dispatcher fn1EDA_00E2(200,...).
 *
 * Buffered-stream helper model (Reko's stream-block object) -- these functions are
 * the read/write drivers of the Turbo-C style stream blocks built by
 * fn1EDA_04F5/fn1EDA_0565/fn1EDA_056A:
 *   +0x02 id (0xD7B0/0xD7B1/0xD7B2)   +0x04 limit (07B6/07DA path)
 *   +0x08 cursor  +0x0A limit (0776/079A path)
 *   +0x0C..0x0E buffer far pointer     +0x14/+0x18 far callbacks
 *   +0x1A callback-segment word
 * The cursor and limit are 16-bit buffer offsets; per iface.tsv they are
 * carried in the pointer-typed slots (`u8 *`).  When a value crosses between
 * a u16 producer (0776/07B6/07DA) and the pointer-typed 079A slot, the exact
 * 16-bit bits are preserved with (u16)(uintptr_t) / (u8 *)(uintptr_t) casts.
 *
 * POLARITY (asm ground truth): 0776/07B6 return the ZF the original callers
 * test with `jnz skip` -- Z set (our `ok` = 1) means the stream is a valid
 * read (0xD7B1) / write (0xD7B2) stream and the DGROUP error word 0x5380 is
 * clear, so the byte transfer PROCEEDS; `ok` = 0 skips it (07B6 also latches
 * error 0x69 for a wrong-id stream, 0776 error 0x68).  Every transfer loop
 * below is therefore entered with `if (ok)`.
 */

#include <stdint.h>
#include <string.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1EDA.h"
#include "seg1EDA_shared.h"
#include "pal.h"
#include <stdlib.h>
#include <stdio.h>

/* 079A carries its DX cursor as a pointer (`u8 *`) while 0776/07B6/07DA
 * produce a u16; a union keeps the single 16-bit slot addressable under both
 * interpretations without overrunning the caller's storage. */
typedef union { u16 w; u8 *p; } dx_cur_t;

/* 1EDA:081A -- read a line into the stream's buffer up to CR, consuming a
 * following LF.  Calls 0776 (setup), 079A (getc) and 0879 (flush). */
u16 fn1EDA_081A(u16 cx, u8 * ptrArg04)
{
	u8 *es_bx_112 = NULL;
	u8 *es_bx_109;
	void *bx_17;
	dx_cur_t dx_19;
	u16 di_18;
	u8 ok;

	/* iface.tsv types the es_bx cursor as `u8 *`; it is the Reko `segptr32 &`
	 * out-param, so pass the address with the width the header declares. */
	ok = fn1EDA_0776(ptrArg04, (u8 *)&es_bx_112, &dx_19.w, &di_18);
	bx_17 = (void *)(uintptr_t)es_bx_112;
	if (ok)
	{
		u8 al_114;
		u8 al_116;
		u8 *es_40 = NULL;
		u16 cx_117;
		u16 di_119;
		void *es_120 = NULL;

		es_bx_109 = es_bx_112;
		for (;;)
		{
			(void)fn1EDA_079A(es_bx_109, cx, dx_19.p, di_18, ptrArg04,
			                  &al_114, &cx, (void *)&dx_19, &bx_17, &di_18,
			                  (void *)&es_40);
			if (al_114 == 0x1A)                 /* jz 083Bh (no inc bx) */
				goto l1EDA_083B;
			bx_17 = (u8 *)bx_17 + 1;            /* inc bx */
			es_bx_109 = (u8 *)es_40 + (uintptr_t)bx_17;
			if (al_114 == 0x0D)                 /* jz 083Bh (after inc bx) */
				break;
		}

		/* LF after the CR: consume one more character. */
		(void)fn1EDA_079A(es_bx_109, cx, dx_19.p, di_18, ptrArg04,
		                  &al_116, &cx_117, (void *)&dx_19, &bx_17, &di_119,
		                  (void *)&es_120);
		if (al_116 == 0x0A)
			bx_17 = (u8 *)bx_17 + 1;            /* inc bx */
	}
l1EDA_083B:
	*(u16 *)(ptrArg04 + 0x08) = (u16)(uintptr_t)bx_17;
	fn1EDA_0879(ptrArg04);
	/* Original returns DS (DGROUP selector); dropped in the flat model. */
	return 0x0000;
}

/* 1EDA:0848 -- append CR LF to the stream (07B6 setup, 07DA two putc). */
u16 fn1EDA_0848(u8 ah, u16 cx, u8 * ptrArg04)
{
	u8 *es_bx_93 = NULL;
	void *bx_17;
	u16 dx_19;
	u16 di_18;
	u8 ok;

	(void)ah;   /* AH is only an output channel of 07DA here */
	ok = fn1EDA_07B6(ptrArg04, (u8 *)&es_bx_93, &dx_19, &di_18);
	bx_17 = (void *)(uintptr_t)es_bx_93;
	if (ok)
	{
		u8 *es_bx_94 = NULL;
		u8 *es_bx_98 = NULL;
		u8 ah_96;
		u8 ah_99;
		u16 cx_32;
		u16 cx_100;
		u16 dx_35;
		u16 dx_101;
		u16 di_33;
		u16 di_102;

		(void)fn1EDA_07DA(es_bx_93, 0x0D, cx, dx_19, di_18, ptrArg04,
		                  (u8 *)&es_bx_94, &ah_96, &cx_32, &dx_35, &di_33);
		(void)fn1EDA_07DA(es_bx_94, 0x0A, cx_32, dx_35, di_33, ptrArg04,
		                  (u8 *)&es_bx_98, &ah_99, &cx_100, &dx_101, &di_102);
		bx_17 = (void *)(uintptr_t)es_bx_98;
	}
	*(u16 *)(ptrArg04 + 0x08) = (u16)(uintptr_t)bx_17;
	fn1EDA_0879(ptrArg04);
	/* Original returns DS (DGROUP selector); dropped in the flat model. */
	return 0x0000;
}

/* 1EDA:086C -- flush the stream (0879 only). */
void fn1EDA_086C(u8 * ptrArg04)
{
	fn1EDA_0879(ptrArg04);
}

/* 1EDA:0879 -- if the block has a callback (segment word at +0x1A nonzero)
 * and no pending error, invoke the callback at +0x18 with the block pointer
 * and latch a nonzero result into DGROUP:0x5380.
 *
 * Flat model: the far callback at +0x18/+0x1A is represented as a host
 * function pointer stored at +0x18; the +0x1A "is it installed" test is kept
 * literally (for a real host pointer those bytes are nonzero). */
void fn1EDA_0879(u8 * es_di)
{
	u16 ax_18;

	if (*(u16 *)(es_di + 0x1A) == 0x00)
		return;
	if (LG16(0x5380) == 0x00)
	{
		/* Slot +0x18 holds a 16-bit callback OFFSET (segment 1EDA) --
		 * resolve via the chunk-3c table. */
		{
			u16 (*cb)(u8 *) = seg1EDA_stream_cb(*(u16 *)(es_di + 0x18));
			ax_18 = cb ? cb(es_di) : 0xFFFF;
		}
		if (ax_18 != 0x00)
			LG16(0x5380) = ax_18;
	}
}

/* 1EDA:0896 -- read a length-prefixed line of at most wArg04 bytes from the
 * stream into ptrArg06 (0776 setup, 079A getc).  Returns the byte count. */
u16 fn1EDA_0896(u16 wArg04, u8 * ptrArg06, u8 * ptrArg0A)
{
	u8 *es_bx_117 = NULL;
	u8 *es_bx_113;
	void *bx_19;
	dx_cur_t dx_21;
	u16 di_20;
	u16 cx_28;
	u8 *si;
	u8 ok;

	ok = fn1EDA_0776(ptrArg0A, (u8 *)&es_bx_117, &dx_21.w, &di_20);
	es_bx_113 = es_bx_117;
	bx_19 = (void *)(uintptr_t)es_bx_117;
	cx_28 = 0x00;
	si = ptrArg06;
	if (ok)
	{
		for (;;)
		{
			u8 al_118;
			u8 *es_44 = NULL;

			(void)fn1EDA_079A(es_bx_113, cx_28, dx_21.p, di_20, ptrArg0A,
			                  &al_118, &cx_28, (void *)&dx_21, &bx_19, &di_20,
			                  (void *)&es_44);
			if (al_118 == 0x0D || al_118 == 0x1A)
				break;
			bx_19 = (u8 *)bx_19 + 1;
			++cx_28;
			++si;
			*si = al_118;
			if (cx_28 == wArg04)
				break;
			es_bx_113 = (u8 *)es_44 + (uintptr_t)bx_19;
		}
	}
	si -= cx_28;
	*si = (u8)cx_28;
	*(u16 *)(ptrArg0A + 0x08) = (u16)(uintptr_t)bx_19;
	return cx_28;
}

/* 1EDA:08CE -- write the length-prefixed string ptrArg06 to the stream,
 * space-padded on the right up to width wArg04 (07B6 setup, 07DA putc). */
u8 fn1EDA_08CE(u16 wArg04, u8 * ptrArg06, u8 * ptrArg0A, u16 * cxOut)
{
	u8 *es_bx_197 = NULL;
	u16 bx_111;
	u16 dx_125;
	u16 di_124;
	u16 ax = 0x0000;
	u16 cx = 0x0000;
	u8 ah_ret = 0x00;
	u8 ok;

	ok = fn1EDA_07B6(ptrArg0A, (u8 *)&es_bx_197, &dx_125, &di_124);
	bx_111 = (u16)(uintptr_t)es_bx_197;
	if (ok)
	{
		u8 *es_bx_188;
		u16 cx_36;
		u8 ah_207;
		u16 cx_53;
		u8 *es_bx_194;
		u8 *es_bx_204;
		u8 ah_208;
		u16 cx_90;
		u8 *si;

		ax = (u16)ptrArg06[0];
		cx_36 = (u16)(wArg04 - ax);
		es_bx_188 = es_bx_197;
		if ((s16)cx_36 > 0)
		{
			while (cx_36 != 0x00)
			{
				(void)fn1EDA_07DA(es_bx_188, 0x20, cx_36, dx_125, di_124,
				                  ptrArg0A, (u8 *)&es_bx_197, &ah_207, &cx_53,
				                  &dx_125, &di_124);
				es_bx_188 = es_bx_197;
				--cx_36;
			}
			ax = (u16)ptrArg06[0];
		}
		bx_111 = (u16)(uintptr_t)es_bx_197;
		cx = ax;
		es_bx_194 = es_bx_197;
		es_bx_204 = es_bx_197;
		si = ptrArg06 + 1;
		while (cx != 0x00)
		{
			(void)fn1EDA_07DA(es_bx_194, *si, cx, dx_125, di_124, ptrArg0A,
			                  (u8 *)&es_bx_204, &ah_208, &cx_90, &dx_125, &di_124);
			es_bx_194 = es_bx_204;
			bx_111 = (u16)(uintptr_t)es_bx_204;
			ah_ret = ah_208;
			++si;
			--cx;
		}
	}
	*(u16 *)(ptrArg0A + 0x08) = bx_111;
	*cxOut = cx;
	return ah_ret;
}

/* 1EDA:0918 -- scan one stream character; returns 1 on Ctrl-Z (1Ah) or on a
 * CR that the caller's CL bit 1 accepts, else 0 (0776 setup, 079A getc). */
u16 fn1EDA_0918(u8 ch, u8 * ptrArg04)
{
	u8 *es_bx_185 = NULL;
	void *bx_18;
	u16 cx_30;
	dx_cur_t dx_20;
	u16 di_19;
	u8 ok;

	cx_30 = (u16)((u16)ch << 8);        /* SEQ(ch, 0x00) */
	ok = fn1EDA_0776(ptrArg04, (u8 *)&es_bx_185, &dx_20.w, &di_19);
	bx_18 = (void *)(uintptr_t)es_bx_185;
	if (ok)
	{
		u8 *es_bx_180 = es_bx_185;

		for (;;)
		{
			u8 al_189;
			u16 cx_37;
			u8 *es_41 = NULL;
			u8 al_47;
			u8 cl_50;

			(void)fn1EDA_079A(es_bx_180, cx_30, dx_20.p, di_19, ptrArg04,
			                  &al_189, &cx_37, (void *)&dx_20, &bx_18, &di_19,
			                  (void *)&es_41);
			al_47 = al_189;
			cl_50 = (u8)cx_37;
			if (al_47 == 0x1A || (((cl_50 & 0x01) != 0x00) && al_47 == 0x0D))
				goto l1EDA_0947;
			cx_30 = cx_37;
			if ((cl_50 & 0x02) == 0x00 || al_47 > 0x20)
				goto l1EDA_0943;
			es_bx_180 = (u8 *)es_41 + (uintptr_t)bx_18 + 1;
		}
	}
l1EDA_0943:
	*(u16 *)(ptrArg04 + 0x08) = (u16)(uintptr_t)bx_18;
	return 0x0000;
l1EDA_0947:
	*(u16 *)(ptrArg04 + 0x08) = (u16)(uintptr_t)bx_18;
	return 0x0001;
}

/* 1EDA:0953 -- copy wArg04 bytes from ptrArg0A to ptrArg06 (rep movsb). */
void fn1EDA_0953(u16 wArg04, u8 * ptrArg06, u8 * ptrArg0A)
{
	memcpy(ptrArg06, ptrArg0A, (u32)wArg04);
}

/* 1EDA:096F -- 32-bit multiply helper, recovered as the literal 8086 `mul`
 * sequence: result low word = low(ax*cx); result high word = high(ax*cx) +
 * low(ax*bx) + low(dx*cx), all mod 2^16.  (Reko's SEQ argument order
 * byte-swaps this; the .asm is ground truth -- see notes.) */
u32 fn1EDA_096F(u16 ax, u16 cx, u16 dx, u16 bx)
{
	u32 dx_ax_9 = (u32)cx * (u32)ax;
	u16 lo = (u16)dx_ax_9;
	u16 hi = (u16)(dx_ax_9 >> 16);

	hi = (u16)(hi + (u16)((u32)ax * (u32)bx) + (u16)((u32)dx * (u32)cx));
	return ((u32)hi << 16) | lo;
}

/* 1EDA:098A -- signed 32-bit division.  Divisor bx_cx / dividend dx_ax in the
 * original ABI; quotient -> dx:ax (returned in AX, high word via dxOut),
 * remainder -> bx:cx (cxOut/bxOut).  Recovered as the literal 33-iteration
 * restoring long division of 1EDA:0991..09EF (sign handling via pushf/popf).
 * The bx_cx==0 case tail-calls the fatal-error dispatcher fn1EDA_00E2(200). */
s16 fn1EDA_098A(u32 bx_cx, u32 dx_ax, u16 wArg00, u16 wArg02, s16 * cxOut, s16 * dxOut, s16 * bxOut, void * dsOut)
{
	u16 cx_v = (u16)bx_cx;
	u16 bx_v = (u16)(bx_cx >> 16);
	u16 ax_v = (u16)dx_ax;
	u16 dx_v = (u16)(dx_ax >> 16);
	u8 v13_37;                          /* divisor (bx) sign */
	u8 v18_56;                          /* dividend (dx) sign */
	u16 si;
	u16 di;
	u16 bp;
	u8 cin;

	if ((u16)(bx_v | cx_v) == 0x00)
	{
		u16 cx_22;
		u16 dx_24;
		u16 bx_21;
		void *ds_23 = NULL;
		u16 ax_20 = fn1EDA_00E2(0xC8, wArg00, wArg02, &cx_22, &dx_24, &bx_21, &ds_23);

		*cxOut = (s16)cx_22;
		*dxOut = (s16)dx_24;
		*bxOut = (s16)bx_21;
		*(u16 *)dsOut = (u16)(uintptr_t)ds_23;  /* 16-bit dropped selector: an
		 * 8-byte write here clobbers adjacent call-site locals */
		return (s16)ax_20;
	}

	/* pushf #1 (divisor sign), then negate bx:cx if negative. */
	v13_37 = (u8)((bx_v & 0x8000) != 0x00);
	if (v13_37)
	{
		u32 t = ~bx_cx + 0x01;
		cx_v = (u16)t;
		bx_v = (u16)(t >> 16);
	}

	/* pushf #2 (dividend sign), then negate dx:ax if negative. */
	v18_56 = (u8)((dx_v & 0x8000) != 0x00);
	if (v18_56)
	{
		u32 t = ~dx_ax + 0x01;
		ax_v = (u16)t;
		dx_v = (u16)(t >> 16);
	}

	si = cx_v;
	di = bx_v;
	cx_v = 0x0000;
	bx_v = 0x0000;
	bp = 0x21;
	cin = 0x00;
	do
	{
		u8 cout;
		u32 a;
		u32 b;
		u8 borrow;
		u32 r;
		u8 qbit;
		u8 cout2;

		/* rcl cx,1 ; rcl bx,1 (32-bit shift of bx:cx, carry-in = cin) */
		cout = (u8)(bx_v >> 15);
		bx_v = (u16)((bx_v << 1) | (cx_v >> 15));
		cx_v = (u16)((cx_v << 1) | (cin & 0x01));
		cin = cout;

		/* sub cx,si ; sbb bx,di */
		a = ((u32)bx_v << 16) | cx_v;
		b = ((u32)di << 16) | si;
		borrow = (u8)(a < b);
		r = a - b;
		cx_v = (u16)r;
		bx_v = (u16)(r >> 16);
		if (borrow)
		{
			/* add cx,si ; adc bx,di (restore) */
			u32 r2 = (((u32)bx_v << 16) | cx_v) + b;
			cx_v = (u16)r2;
			bx_v = (u16)(r2 >> 16);
		}
		qbit = (u8)(borrow == 0x00);

		/* cmc ; rcl ax,1 ; rcl dx,1 */
		cout2 = (u8)(dx_v >> 15);
		dx_v = (u16)((dx_v << 1) | (ax_v >> 15));
		ax_v = (u16)((ax_v << 1) | qbit);
		cin = cout2;

		--bp;
	} while (bp != 0x00);

	/* popf (dividend sign): if negative, negate the remainder, then the
	 * divisor-sign popf decides whether the quotient is negated. */
	if (!v18_56)
	{
		if (v13_37)
		{
			u32 t = ~(((u32)dx_v << 16) | ax_v) + 0x01;
			ax_v = (u16)t;
			dx_v = (u16)(t >> 16);
		}
	}
	else
	{
		u32 t = ~(((u32)bx_v << 16) | cx_v) + 0x01;
		cx_v = (u16)t;
		bx_v = (u16)(t >> 16);
		if (!v13_37)
		{
			u32 t2 = ~(((u32)dx_v << 16) | ax_v) + 0x01;
			ax_v = (u16)t2;
			dx_v = (u16)(t2 >> 16);
		}
	}

	*cxOut = (s16)cx_v;
	*dxOut = (s16)dx_v;
	*bxOut = (s16)bx_v;
	/* Original leaves DS at the DGROUP selector; flat model stores the base. */
	*(u16 *)dsOut = (u16)(uintptr_t)g_dgroup;  /* 16-bit dropped selector: an
	 * 8-byte write here clobbers adjacent call-site locals (02D8's dx_45
	 * received g_dgroup's high word and poisoned DGROUP:58CEh) */
	return (s16)ax_v;
}

/* 1EDA:0A1F -- copy a length-prefixed string (lodsb/stosb/rep movsb). */
void fn1EDA_0A1F(u8 * ptrArg04, u8 * ptrArg08)
{
	u8 al_14 = ptrArg04[0];

	ptrArg08[0] = (u8)(s8)al_14;
	memcpy(&ptrArg08[1], &ptrArg04[1], (u32)al_14);
}
