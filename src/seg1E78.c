/* seg1E78.c -- recovered segment 1E78 of RAD V3.1
 *              (BIOS video/keyboard, PC-speaker ports, timing helpers).
 *
 * Recovered from analysis/reko/RAD_1E78.{c,asm,dis}.  Ground truth = the .asm.
 * Function order = ascending offset; Reko offset comments retained.
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   int 10h (the single instruction in renamed_1e78_0609, reached with many AH
 *            subfunctions) -> pal_bios_int10(regs) with regs = AX,BX,CX,DX.
 *            C has no AH/AL registers, so the recovered callers stage the
 *            register values in the file-scope g_bios10_* block exactly
 *            where the original loaded AH/AL/BX/... before `call 0609h`;
 *            renamed_1e78_0609() copies them into regs, dispatches, and copies the
 *            outputs back.  AH=00 set mode and AH=0F get mode keep sharing
 *            the mode state with bios_video_*(); the BIOS text services
 *            (AH=01/02/03/06/07/08/09/0A/0E/10/11/12) are now handled by
 *            pal_bios_int10 (see pal/int.c); no service remains dropped.
 *   int 16h AH=01 -> bios_kbd_check_keystroke; AH=00 -> bios_kbd_get_keystroke
 *   int 23h -> dropped (renamed_1e78_0143)
 *   in al,61h / out 61h,al -> pal_inport(0x61) / pal_outport(0x61, ...)
 *   out 43h,al             -> pal_outport(0x43, ...)
 *   out 42h,al             -> pal_outport(0x42, ...)
 *   int 21h AH=25h (renamed_1e78_002e) -> msdos_set_interrupt_vector
 *
 * The BIOS Data Area cells read directly by the original (0040:0000,
 * 0040:006C tick counter, 0040:0087 video control) have no pal.h mapping and
 * are kept as file-static bytes so the recovered arithmetic still compiles.
 */

#include <stdint.h>
#include <time.h>

#include "seg1E78.h"
#include "seg1EDA.h"
#include "seg0800.h"
#include "globals.h"
#include "pal.h"

/* BIOS Data Area stand-ins.  0040:006C is the BIOS tick counter low byte,
 * emulated by the PAL at 18.2065 Hz (pal.h); 0000/0087 are plain flags. */
#define g_bda_006C (*pal_bda_tick_byte())
static u8 g_bda_0000;   /* 0040:0000 */
static u8 g_bda_0087;   /* 0040:0087 (video control byte) */

/* Emulated-machine delay pacing (see renamed_1e78_029c / renamed_1e78_02bf below).  After
 * the startup calibration this holds the real-time cost of ONE spin iteration
 * of the 02BFh busy-wait on the machine the calibration measured; on era
 * hardware that is ~1ms/[0xB8B4], which is exactly the value stored here.  A
 * host whose spin is far denser than the emulated CPU's gets the difference
 * held in 02BFh's cx-exhaustion exit, so one calibrated unit stays one
 * game-millisecond of real time.  0 = never calibrated (no pacing). */
static unsigned long long g_029C_iter_ns;

/* Busy-hold for ns nanoseconds of wall time.  This is the hardware-timing
 * stand-in for the original's calibrated spin: on the machine the startup
 * calibration measured, one 02BFh busy-wait of [0xB8B4] iterations consumed
 * exactly this long.  The bulk is yielded to the OS with nanosleep and only
 * the final ~200us are spun with the monotonic clock, so a hold costs the
 * requested wall time without hogging the host for long waits.
 *
 * Each hold also pumps the host event queue (pal_input_pump): on the
 * original machine time passed asynchronously here -- the int-8/int-9
 * hardware filled the key buffer and the mode-12h VRAM writes of the
 * animation were visible on the CRT as they happened.  The port's shadow
 * framebuffer only reaches the window through the input pump's throttled
 * present, so without this pump every animation that does not poll the
 * keyboard (climb, crate drag, fuse, burn, recoil) would sit at ~1 fps --
 * the rate at which the game's own clock-repaint path happens to poll the
 * mouse driver -- while the walk (which polls 02FB per pixel) animates
 * normally.  Pumping here restores both the asynchronous key delivery and
 * the per-retrace visibility; the throttled present keeps its own ~70 Hz
 * gate, so the hold's wall time is unaffected. */
extern void pal_input_pump(void);
void fn1E78_pace_ns(unsigned long long ns)
{
	struct timespec t0, now;
	int64_t done;

	/* -s/--speed: hold for ns/speed of wall time.  Every pacing delay of the
	 * game funnels through here (029Ch/02BFh), so this single divide makes
	 * movement animation and all timed sequences run proportionally faster
	 * without touching any game logic. */
	if (g_game_speed != 1.0)
		ns = (unsigned long long)((long double)ns / g_game_speed);

	clock_gettime(CLOCK_MONOTONIC, &t0);
	pal_input_pump();
	if (ns > 400000ull)
	{
		struct timespec sl;
		sl.tv_sec = (time_t)((ns - 200000ull) / 1000000000ull);
		sl.tv_nsec = (long)((ns - 200000ull) % 1000000000ull);
		while (nanosleep(&sl, &sl) != 0 && sl.tv_nsec != 0)
			;
	}
	for (;;)
	{
		clock_gettime(CLOCK_MONOTONIC, &now);
		done = (int64_t)(now.tv_sec - t0.tv_sec) * 1000000000ll +
		       (now.tv_nsec - t0.tv_nsec);
		if (done >= (int64_t)ns)
			break;
	}
}

/* int 10h register gateway: C has no AH/AL/BH/BL/CH/CL/DH/DL registers, so
 * callers stage the values here before invoking renamed_1e78_0609(), exactly as the
 * original loaded them before `call 0609h`. */
static u16 g_bios10_ax;
static u16 g_bios10_bx;
static u16 g_bios10_cx;
static u16 g_bios10_dx;

// 1E78:0000: void renamed_1e78_0000(void)
void renamed_1e78_0000(void)
{
	renamed_1e78_002e();
	renamed_1e78_032f(&g_dgroup[0xB8BC]);
	renamed_1eda_0565(&g_dgroup[0xB8BC]);
	renamed_1e78_032f(&g_dgroup[0xB9BC]);
	renamed_1eda_056a(&g_dgroup[0xB9BC]);
}

// 1E78:002E: void renamed_1e78_002e(void)
void renamed_1e78_002e(void)
{
	u8 al_6;
	u16 dx_117;
	u8 ah_38;
	u8 al_58;
	u16 ax_38;
	u16 count;

	g_bios10_ax = 0x0F00;                            /* AH=0Fh get mode */
	al_6 = (u8)renamed_1e78_0609();
	if (al_6 != 0x07 && al_6 > 0x03)
		renamed_1e78_0097(0x03);
	renamed_1e78_00e5(&dx_117);
	g_bios10_ax = 0x0800;                            /* AH=08h read char */
	g_bios10_bx = (u16)(g_bios10_bx & 0xFF00);       /* BH=0 */
	ax_38 = renamed_1e78_0609();
	ah_38 = (u8)(ax_38 >> 8);
	LG8(0xB8B8) = (u8)(ah_38 & 0x7F);
	LG8(0xB8AE) = (u8)(ah_38 & 0x7F);
	LG8(0xB8A9) = 0x00;
	LG8(0xB8B9) = 0x00;
	LG8(0xB8BA) = 0x00;
	LG8(0xB8A8) = 0x01;

	al_58 = g_bda_006C;
	while (al_58 == g_bda_006C)
		;
	al_58 = g_bda_006C;
	count = renamed_1e78_02bf(&g_bda_006C, al_58, 0xFFFF);
	LG16(0xB8B4) = (u16)((u16)~count / 0x37);
	/* The emulated machine's per-iteration spin cost: one calibrated unit
	 * (one 029Ch millisecond) is [0xB8B4] iterations, so one iteration is
	 * 1ms / [0xB8B4].  029Ch's waits hold this real time per unit below
	 * (02BFh), whatever the host's raw spin density is. */
	if (LG16(0xB8B4) != 0x0000)
		g_029C_iter_ns = 1000000ull / (unsigned long long)LG16(0xB8B4);   /* ns per iteration */
	/* CS:12Dh Ctrl-Break handler; flat model passes the segment-image address */
	msdos_set_interrupt_vector(0x1B, (void *)&g_seg1E78[0x12D]);
}

// 1E78:0097: void renamed_1e78_0097(u16 ax)
void renamed_1e78_0097(u16 ax)
{
	u8 al = (u8)ax;
	u8 ah = (u8)(ax >> 8);
	u16 ax_18 = ax;

	g_bda_0087 = (u8)(g_bda_0087 & ~0x01);
	if (al != 0x07)
	{
		if (al >= 0x04)
			ax_18 = (u16)(((u16)ah << 8) | 0x03);
	}
	g_bios10_ax = (u16)(u8)ax_18;                    /* AH=0 set mode, AL=ax_18 */
	renamed_1e78_0609();
	if (ah != 0x00)
	{
		g_bios10_ax = 0x1112;                        /* AH=11h AL=12h */
		g_bios10_bx = (u16)(g_bios10_bx & 0xFF00);   /* BL=0 */
		renamed_1e78_0609();
		g_bios10_ax = 0x1130;                        /* AH=11h AL=30h */
		g_bios10_bx = (u16)(g_bios10_bx & 0x00FF);   /* BH=0 */
		g_bios10_dx = (u16)(g_bios10_dx & 0xFF00);   /* DL=0 */
		renamed_1e78_0609();
		if ((u8)g_bios10_dx == 0x2A)
		{
			g_bda_0087 = (u8)(g_bda_0087 | 0x01);
			g_bios10_ax = 0x0100;
			g_bios10_cx = 0x0600;
			renamed_1e78_0609();
			g_bios10_ax = (u16)((g_bios10_ax & 0x00FF) | 0x1200);
			g_bios10_bx = (u16)((g_bios10_bx & 0xFF00) | 0x0020);
			renamed_1e78_0609();
		}
	}
}

// 1E78:00E5: u8 renamed_1e78_00e5(u16 * dxOut)
u8 renamed_1e78_00e5(u16 * dxOut)
{
	u16 ax_71;
	u8 ah_5;
	u8 al_6;
	u8 cl_20 = 0x00;
	u8 dl_21;
	u16 ax_41;
	u16 dx_50;

	g_bios10_ax = 0x0F00;                            /* AH=0Fh get mode */
	ax_71 = renamed_1e78_0609();
	g_bios10_ax = 0x1130;                            /* AH=11h AL=30h */
	g_bios10_bx = (u16)(g_bios10_bx & 0x00FF);       /* BH=0 */
	g_bios10_dx = (u16)(g_bios10_dx & 0xFF00);       /* DL=0 */
	renamed_1e78_0609();
	ah_5 = (u8)(ax_71 >> 8);
	al_6 = (u8)ax_71;
	dl_21 = (u8)g_bios10_dx;
	if (dl_21 == 0x00)
	{
		dl_21 = 0x18;
		if (al_6 <= 0x03)
			cl_20 = 0x01;
	}
	ax_41 = (u16)al_6;
	dx_50 = (u16)(((u16)dl_21 << 8) | (u8)(ah_5 - 0x01));
	if (dl_21 > 0x18)
		ax_41 = (u16)(0x0100 | (u16)al_6);
	LG16(0xB8AC) = ax_41;
	LG16(0xB8B6) = dx_50;
	LG8(0xB8AB) = cl_20;
	LG8(0xB8AA) = 0x01;
	LG16(0xB8B0) = 0x0000;
	LG16(0xB8B2) = dx_50;
	*dxOut = dx_50;
	return 0x00;
}

// 1E78:0143: u16 renamed_1e78_0143(s16 dx, u16 wArg04, s16 * dxOut)
u16 renamed_1e78_0143(s16 dx, u16 wArg04, s16 * dxOut)
{
	u16 ax = 0;
	u16 dx_42;
	u16 ax_39;

	if (LG8(0xB8BA) != 0x00)
	{
		LG8(0xB8BA) = 0x00;
		while (bios_kbd_check_keystroke())
			(void)bios_kbd_get_keystroke();
		renamed_1e78_047c(0x5E, dx);
		renamed_1e78_047c(0x43, dx);
		renamed_1e78_0475(0x00, dx);
		/* int 23h dropped */
		ax_39 = renamed_1e78_016b(wArg04, &dx_42);
		*dxOut = (s16)dx_42;
		return ax_39;
	}
	*dxOut = dx;
	return ax;
}

// 1E78:016B: u16 renamed_1e78_016b(u16 wArg04, u16 * dxOut)
u16 renamed_1e78_016b(u16 wArg04, u16 * dxOut)
{
	u16 dx_22;

	renamed_1e78_0097(wArg04);
	renamed_1e78_00e5(&dx_22);
	LG8(0xB8AE) = LG8(0xB8B8);
	*dxOut = dx_22;
	return (u16)LG8(0xB8B8);
}

// 1E78:01C0: void renamed_1e78_01c0(void)
void renamed_1e78_01c0(void)
{
	g_bios10_ax = 0x0600;                            /* AH=06h scroll */
	g_bios10_bx = (u16)((g_bios10_bx & 0xFF00) | (u16)LG8(0xB8AE));
	g_bios10_cx = LG16(0xB8B0);
	g_bios10_dx = LG16(0xB8B2);
	renamed_1e78_0609();
	g_bios10_dx = LG16(0xB8B0);
	renamed_1e78_04fd();
}

/* ---- RAD_PACE_TRACE: env-gated pacing diagnostics (host-only) ----
 * Logs every pacing-primitive call with a monotonic timestamp so the
 * per-phase wall time can be compared against the asm's tick counts. */
#include <stdio.h>
#include <stdlib.h>
int rad_pace_trace_on(void)
{
	static int on = -1;
	if (on < 0)
		on = (getenv("RAD_PACE_TRACE") != NULL);
	return on;
}
void rad_pace_trace(const char *site, unsigned a, unsigned b, long long ns)
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	fprintf(stderr, "PACE %lld %s %u %u %lld\n",
	        (long long)ts.tv_sec * 1000000000ll + ts.tv_nsec,
	        site, a, b, ns);
}

// 1E78:029C: u8 renamed_1e78_029c(u16 wArg04, u16 * dxOut)
//
// Pacing primitive: waits wArg04 ticks of the calibrated delay unit.  On the
// original hardware renamed_1e78_002e's startup calibration sizes DGROUP:0xB8B4 so
// that one 02BFh busy-wait = 1/55 of a BIOS tick = one game millisecond, on
// whatever CPU is running.  The Linux host's spin loop is thousands of times
// denser than the emulated machine's, so the raw spin of [0xB8B4] iterations
// no longer takes that unit of real time.  The emulation therefore gives each
// 02BFh call the emulated machine's per-iteration cost (g_029C_iter_ns below,
// derived from the calibration result itself): the spin and its cx budget stay
// literal, and the call is held for cx * g_029C_iter_ns of real time when the
// watched byte never changed -- exactly what the calibrated spin delivered on
// the original machine.  One 029Ch unit = one millisecond, as calibrated.
u8 renamed_1e78_029c(u16 wArg04, u16 * dxOut)
{
	u16 dx_33 = wArg04;
	u16 ax = 0;
	long long t0 = 0;

	if (rad_pace_trace_on())
	{
		struct timespec ts;
		clock_gettime(CLOCK_MONOTONIC, &ts);
		t0 = (long long)ts.tv_sec * 1000000000ll + ts.tv_nsec;
	}

	/* Time passes here on real hardware: the int-1Ch handler fires during
	 * this wait.  Service the emulated handler's state (the game-clock
	 * countdown at 58D8h) before and after the delay. */
	fn0800_timer_service();
	if (wArg04 != 0x00)
	{
		u8 al_19 = g_bda_0000;
		u16 bx_21 = LG16(0xB8B4);
		do
		{
			renamed_1e78_02bf(&g_bda_0000, al_19, bx_21);
			--dx_33;
			ax = (u16)al_19;
		} while (dx_33 != 0x00);
	}
	fn0800_timer_service();
	if (rad_pace_trace_on())
	{
		struct timespec ts;
		long long t1;
		clock_gettime(CLOCK_MONOTONIC, &ts);
		t1 = (long long)ts.tv_sec * 1000000000ll + ts.tv_nsec;
		rad_pace_trace("029C", wArg04, LG16(0xB8B4), t1 - t0);
	}
	*dxOut = dx_33;
	return (u8)(ax >> 8);
}

// 1E78:02BF: u16 renamed_1e78_02bf(volatile u8 * es_di, u8 al, u16 cx)
// Spin until *es_di differs from al, at most cx iterations (the literal
// recovered loop).  On the cx-exhaustion exit the call additionally occupies
// cx * g_029C_iter_ns of real time: that is the duration the same cx-iteration
// spin consumed on the machine the startup calibration measured, which is what
// every 029Ch delay unit is defined against.  The byte-change exit (the
// calibration watching the 0040:006Ch tick byte) returns immediately, as the
// original's does when the tick arrives.
u16 renamed_1e78_02bf(volatile u8 * es_di, u8 al, u16 cx)
{
	u16 left = cx;

	while (al == *es_di)
	{
		--left;
		if (left == 0x00)
		{
			/* cx exhausted: hold the emulated machine's spin duration. */
			if (g_029C_iter_ns != 0)
				fn1E78_pace_ns((unsigned long long)cx * g_029C_iter_ns);
			return left;
		}
	}
	return left;
}

// 1E78:02C7: void renamed_1e78_02c7(u16 wArg04)
void renamed_1e78_02c7(u16 wArg04)
{
	if (wArg04 > 0x12)
	{
		u16 ax_15 = (u16)(0x1234DDu / wArg04);
		u8 al_17 = pal_inport(0x61);
		if ((al_17 & 0x03) == 0x00)
		{
			pal_outport(0x61, (u8)(al_17 | 0x03));
			pal_outport(0x43, 0xB6);
		}
		pal_outport(0x42, (u8)ax_15);
		pal_outport(0x42, (u8)(ax_15 >> 8));
	}
}

// 1E78:02F4: u8 renamed_1e78_02f4(void)
u8 renamed_1e78_02f4(void)
{
	u8 al_4 = pal_inport(0x61);
	pal_outport(0x61, (u8)(al_4 & 0xFC));
	return (u8)(al_4 & 0xFC);
}

// 1E78:02FB: u8 renamed_1e78_02fb(void)
u8 renamed_1e78_02fb(void)
{
	if (LG8(0xB8B9) == 0x00)
	{
		if (!bios_kbd_check_keystroke())
			return 0x00;
	}
	return 0x01;
}

// 1E78:030D: u16 renamed_1e78_030d(s16 dx, u16 wArg02, u16 * dxOut)
u16 renamed_1e78_030d(s16 dx, u16 wArg02, u16 * dxOut)
{
	s16 dx_38;
	u16 ax_35;
	u8 al_6 = LG8(0xB8B9);

	LG8(0xB8B9) = 0x00;
	if (al_6 == 0x00)
	{
		u16 ax = bios_kbd_get_keystroke();
		al_6 = (u8)ax;
		if (al_6 == 0x00)
		{
			LG8(0xB8B9) = (u8)(ax >> 8);
			if ((u8)(ax >> 8) == 0x00)
				al_6 = 0x03;             /* mov al,3h */
		}
	}
	/* The original's AL carries through 0143's normal `ret`; the ctrl-C
	 * branch terminates via int 23h (dropped). */
	ax_35 = renamed_1e78_0143(dx, wArg02, &dx_38);
	(void)ax_35;                             /* kept for the side effect */
	*dxOut = (u16)dx_38;
	return al_6;
}

// 1E78:032F: void renamed_1e78_032f(void * ptrArg04)
void renamed_1e78_032f(void * ptrArg04)
{
	u8 *p = (u8 *)ptrArg04;
	*(u16 *)(p + 0x02) = 0xD7B0;
	*(u16 *)(p + 0x04) = 0x0080;
	*(u16 *)(p + 0x0C) = (u16)((uintptr_t)ptrArg04 + 0x80);
	*(u16 *)(p + 0x0E) = 0x0000;   /* DS selector dropped in flat model */
	*(u16 *)(p + 0x10) = 0x035A;
	*(u16 *)(p + 0x12) = 0x0000;   /* CS selector dropped in flat model */
	*(u8  *)(p + 0x30) = 0x00;
}

/* 1E78:035A -- console stream OPEN callback (the +0x10 slot stored by
 * renamed_1e78_032f).  Arms the operation slots for the new mode:
 *   id D7B1 (read) : {+14: 0392 read-line, +18: 0470 dummy, +1C: 0470}
 *   otherwise      : id <- D7B2 (write), {+14: 043F, +18: 043F, +1C: 0470}
 * The original stores far pointers (offset,CS) in the three slots; the flat
 * port keeps the offset words only -- the resolver (seg1EDA_stream_cb) is
 * offset-keyed and 0392/043F/0470 do not collide with the 1EDA file-stream
 * slots.  AX = 0 (success). */
u16 renamed_1e78_035a(u8 * block)
{
	u16 ax = 0x0392;
	u16 bx = 0x0470;
	u16 cx = bx;

	if (*(u16 *)(block + 0x02) != 0xD7B1)
	{
		*(u16 *)(block + 0x02) = 0xD7B2;
		ax = 0x043F;
		bx = ax;                            /* CX stays 0470h */
	}
	*(u16 *)(block + 0x14) = ax;            /* +16h = CS: dropped */
	*(u16 *)(block + 0x18) = bx;            /* +1Ah = CS: dropped */
	*(u16 *)(block + 0x1C) = cx;            /* +1Eh = CS: dropped */
	return 0x0000;
}

/* 1E78:0470 -- console stream dummy op. */
u16 renamed_1e78_0470(u8 * block)
{
	(void)block;
	return 0x0000;                          /* xor ax,ax ; retf 4 */
}

/* 1E78:043F -- console stream WRITE op: emit [block+8] bytes from the
 * block's buffer, clear the count.  The original branches on [B8AA]
 * (direct B800 writer at 0504h) vs the BIOS teletype (047Ch); the port does
 * not emulate the text plane, so both branches route through the teletype
 * helper (documented deviation -- the count/state effects are identical).
 * Tail-calls 0143h (the ctrl-C check; int 23h dropped).  AX = 0. */
u16 renamed_1e78_043f(u8 * block)
{
	u16 cx = *(u16 *)(block + 0x08);
	s16 dxTmp;

	*(u16 *)(block + 0x08) = (u16)(*(u16 *)(block + 0x08) - cx);
	if (cx != 0x0000)
	{
		u8 *buf = g_dgroup + *(u16 *)(block + 0x0C);
		u16 i;

		for (i = 0; i < cx; i++)
			renamed_1e78_047c(buf[i], 0);         /* DX ignored (04F6 re-reads) */
	}
	(void)renamed_1e78_0143(0, 0, &dxTmp);
	return 0x0000;
}

/* 1E78:0392 -- console stream READ op: line input with editing into the
 * block's buffer.  Terminated by CR (stores 0Dh 0Ah, count -> +0Ah, the
 * pending count +08h clears) or ctrl-Z when [B8A9] is set.  Special keys:
 * 08h/13h erase one char, 1Bh/01h erase the line (the original's `loop`
 * wraps at CX=0 and stops at the empty line), 04h/06h re-echo forward from
 * the high-water mark, AL < 20h is swallowed.  The original clears the
 * pending-key byte [B8B9] before each 030Dh call, so extended-key scan
 * codes pended by 030Dh are dropped -- transcribed as-is.  AX = 0. */
u16 renamed_1e78_0392(u8 * block)
{
	u16 dxLimit = (u16)(*(u16 *)(block + 0x04) - 2);
	u16 siHi = *(u16 *)(block + 0x08);
	u8 *buf = g_dgroup + *(u16 *)(block + 0x0C);
	u16 bx = 0x0000;
	u16 dxTmp;
	u8 al;
	u16 cx;

	for (;;)
	{
		LG8(0xB8B9) = 0x00;                 /* 03A8h */
		al = (u8)renamed_1e78_030d(0, 0, &dxTmp); /* push cs ; call 30Dh */
		cx = 0x0001;
		if (al == 0x08 || al == 0x13)
			goto l3EC;
		if (al == 0x04)
			goto l404;
		cx = 0x0000;
		if (al == 0x1B || al == 0x01)
			goto l3EC;
		if (al == 0x06)
			goto l404;
		if (al == 0x1A)
			goto l417;
		if (al == 0x0D)
			goto l424;
		if (al < 0x20)
			continue;                       /* jc 03A8h */
		if (bx == dxLimit)
			continue;                       /* line full */
		buf[bx] = al;
		++bx;
		renamed_1e78_047c(al, 0);                 /* echo */
		if (bx > siHi)
			siHi = bx;
		continue;

	l3EC:                                   /* backspace family */
		for (;;)
		{
			if (bx == 0x0000)
				break;                      /* or bx,bx ; jz 03A8h */
			renamed_1e78_047c(0x08, 0);
			renamed_1e78_047c(0x20, 0);
			renamed_1e78_047c(0x08, 0);
			--bx;
			if (--cx == 0x0000)
				break;                      /* loop falls through */
		}
		continue;                           /* jmp 03A8h */

	l404:                                   /* re-echo forward */
		for (;;)
		{
			if (bx == siHi)
				break;
			al = buf[bx];
			if (al < 0x20)
				break;
			renamed_1e78_047c(al, 0);
			++bx;
			if (--cx == 0x0000)
				break;
		}
		continue;

	l417:                                   /* ctrl-Z */
		if (LG8(0xB8A9) == 0x00)
			continue;
		buf[bx] = al;
		++bx;
		goto l42E;

	l424:                                   /* CR: CRLF + terminator */
		renamed_1e78_0475(0x00, 0);
		buf[bx] = 0x0D;                     /* mov word,0A0Dh (little-endian) */
		buf[bx + 1] = 0x0A;
		++bx;
		++bx;

	l42E:
		*(u16 *)(block + 0x08) = 0x0000;
		*(u16 *)(block + 0x0A) = bx;
		return 0x0000;
	}
}

// 1E78:0475: void renamed_1e78_0475(u8 ah, s16 dx)
void renamed_1e78_0475(u8 ah, s16 dx)
{
	(void)ah;
	renamed_1e78_047c(0x0D, dx);
	renamed_1e78_047c(0x0A, dx);
}

// 1E78:047C: u8 renamed_1e78_047c(u8 al, s16 dx)
u8 renamed_1e78_047c(u8 al, s16 dx)
{
	u8 al_29 = al;
	u8 dh_38;
	u8 dl_38;

	(void)dx;   /* the original pushes DX and restores it at the end; the
	             * body always works from the CURRENT cursor read below. */

	renamed_1e78_04f6();                                   /* AH=03h read cursor shape */
	/* pal_bios_int10's AH=03 handler returns the cursor in the DX register
	 * image, which 0609 copies back to g_bios10_dx. */
	dh_38 = (u8)(g_bios10_dx >> 8);
	dl_38 = (u8)g_bios10_dx;
	if (al_29 == 0x07)
	{
		g_bios10_ax = (u16)((g_bios10_ax & 0x00FF) | (u16)(0x0E00 | al_29));
		renamed_1e78_0609();
		goto l1E78_04CD;
	}
	if (al_29 == 0x08)
	{
		if (dl_38 == LG8(0xB8B0))
			goto l1E78_04CD;
		--dl_38;
		goto l1E78_04CD;
	}
	if (al_29 == 0x0D)
	{
		dl_38 = LG8(0xB8B0);
		goto l1E78_04CD;
	}
	if (al_29 == 0x0A)
		goto l1E78_04CA;
	g_bios10_ax = (u16)((g_bios10_ax & 0x00FF) | (u16)(0x0900 | al_29));
	g_bios10_bx = (u16)LG8(0xB8AE);                  /* BL=attr, BH=0 */
	g_bios10_cx = 0x0001;
	g_bios10_dx = (u16)(((u16)dh_38 << 8) | dl_38);
	renamed_1e78_0609();
	++dl_38;
	if (dl_38 <= LG8(0xB8B2))
		goto l1E78_04CD;
	dl_38 = LG8(0xB8B0);
l1E78_04CA:
	renamed_1e78_04d5(dh_38);
l1E78_04CD:
	g_bios10_dx = (u16)(((u16)dh_38 << 8) | dl_38);
	renamed_1e78_04fd();
	return 0x00;
}

// 1E78:04D5: void renamed_1e78_04d5(u8 dh)
void renamed_1e78_04d5(u8 dh)
{
	++dh;
	if (dh <= LG8(0xB8B3))
		return;
	--dh;
	g_bios10_ax = 0x0601;                            /* AH=06h AL=1 scroll */
	g_bios10_bx = (u16)((g_bios10_bx & 0xFF00) | (u16)LG8(0xB8AE));
	g_bios10_cx = LG16(0xB8B0);
	g_bios10_dx = LG16(0xB8B2);
	renamed_1e78_0609();
}

// 1E78:04F6: void renamed_1e78_04f6(void)
void renamed_1e78_04f6(void)
{
	g_bios10_ax = (u16)((g_bios10_ax & 0x00FF) | 0x0300);   /* AH=03h */
	g_bios10_bx = (u16)(g_bios10_bx & 0xFF00);              /* BH=0 */
	renamed_1e78_0609();
}

// 1E78:04FD: u16 renamed_1e78_04fd(void)
u16 renamed_1e78_04fd(void)
{
	g_bios10_ax = (u16)((g_bios10_ax & 0x00FF) | 0x0200);   /* AH=02h */
	g_bios10_bx = (u16)(g_bios10_bx & 0xFF00);              /* BH=0 */
	return renamed_1e78_0609();
}

// 1E78:0609: u16 renamed_1e78_0609(void)
// Generic int 10h gateway (original body: push si/di/bp/es; int 10h; pop ...).
// The staged g_bios10_* words are handed to the PAL as a 4-word register
// image (AX,BX,CX,DX) and the post-interrupt values are copied back, exactly
// where the original callers consumed AX/BX/CX/DX after `int 10h`.
u16 renamed_1e78_0609(void)
{
	u16 regs[4];

	regs[0] = g_bios10_ax;
	regs[1] = g_bios10_bx;
	regs[2] = g_bios10_cx;
	regs[3] = g_bios10_dx;
	pal_bios_int10(regs);
	g_bios10_ax = regs[0];
	g_bios10_bx = regs[1];
	g_bios10_cx = regs[2];
	g_bios10_dx = regs[3];
	return g_bios10_ax;
}
