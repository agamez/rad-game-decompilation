/* seg0C74_part6.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 6 of N: function 0C74:1F08 (one of the two largest functions).
 *
 * Literal recovery from analysis/slices/0C74/0C74_1F08.asm (ground truth) and
 * the Reko slice 0C74_1F08.c; frozen prototype from src/seg0C74.h
 * (analysis/summary/iface.tsv) adopted exactly:
 *
 *   u8 engine_per_frame_level(u16 *bpOut, u16 *dsOut)
 *
 * See CONVENTIONS.md, analysis/SEGMAP.md and docs/notes-0C74.md ("## part 6").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   NONE directly.  No `int 10h/16h/21h`, no raw `in`/`out` port instruction,
 *   no __cli/__sti, no int 23h and no raw IVT dispatch occur in 1F08.  The
 *   only hardware-touching work is reached indirectly through already-ported
 *   callees: the 1AB8 video driver (13A3/13D7/10F4/1AF6/1C32/1E3C/1E54/1E6B)
 *   and the 1EDA far-heap helpers (023F/0254/096F/098A).  engine_clock_tick / 070D /
 *   05B8 / 1D95 are 0C74 helpers handled by their own chunks; 1D95 and 05B8
 *   reach the video/PC-speaker paths indirectly.
 *
 * Flat-model / ABI adaptations (recorded in docs/notes-0C74.md "## part 6"):
 *   - Reko's `bp_XXXX` frame-pointer locals (re-bound after each call to
 *     engine_scale_and_tick_clock / 02D8 / 1D95 whose AX/pointer return is the caller's saved
 *     BP) are the current function's own frame; they are folded back onto the
 *     literal locals below (documented convention, notes-0C74.md part 1 §3).
 *   - The 16:16 far blocks allocated by fn1EDA_023F are carried as `u32`
 *     (offset | segment<<16, low word at the lower address, matching the
 *     original [bp-10h]/[bp-0Eh], [bp-14h]/[bp-12h], [bp-18h]/[bp-16h],
 *     [bp-1Ch]/[bp-1Ah]) and materialised with `far_ptr(dw)` at the
 *     call sites, the same convention as seg0800_part3.c / seg0C74_part4.c.
 *   - renamed_1eda_098a's frozen `void * dsOut` receives a `void *` local (`dsv`).
 *   - fn1EDA_023F / 098A / 0254 take stack words the original never pushes
 *     (far-return-address / leftover slots, read only on the fatal
 *     divide-by-zero dispatcher path); they are seeded 0.
 *   - `push bp` before engine_blit_field_edges is a caller-frame pointer (1D95 reads
 *     ss:[wArg02-4]); flat C has no SS:BP chain, so the frozen `u16 wArg02`
 *     slot receives 0 (notes-0C74.md part 4 item 5 precedent).
 *   - `bpOut` / `dsOut` register outputs are the caller's saved BP and the
 *     DGROUP selector; both receive 0.
 *
 * The seven identical "time tick" sequences
 *   ax=[58E6h]; cwd; cx=ax; bx=dx; ax=[4D0Ch]; xor dx,dx; call 096Fh
 *   cx=4h; xor bx,bx; call 098Ah; push ax; call 02D8h
 * are emitted through the TICK() macro; the 098A outputs are overwritten by
 * each call (as in seg0C74_part4.c).
 */

#include <stddef.h>
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C74.h"
#include "seg1AB8.h"
#include "seg1EDA.h"

#define TICK() \
	do { \
		cxT = 0; dxT = 0; bxT = 0; dsv = NULL; \
		(void)engine_clock_tick((u16)renamed_1eda_098a(0x0004, \
		        fn1EDA_096F(LG16(0x4D0C), LG16(0x58E6), 0x0000, \
		                    (u16)(s16)LG16(0x58E6)), \
		        0x0000, 0x0000, &cxT, &dxT, &bxT, &dsv), &dsTmp); \
	} while (0)

// 0C74:1F08: u8 engine_per_frame_level(u16 * bpOut, u16 * dsOut)
//
// Game-core per-frame update (sibling of 0FA1).  Paints the two status fields,
// scans the left/right field edges, then depending on the state word at
// 0x5968 (0xFFFF / 0x0001) runs the corresponding edge-extension animation and
// finally the victory sequence; on obstacle/abort it frees both scratch blocks
// and returns 0.  Returns the [bp-1] byte (0 = abort/keep waiting, 1 = advance).
u8 engine_per_frame_level /* was fn0C74_1F08 */(u16 *bpOut, u16 *dsOut)
{
	u8  bLoc01 = 0x00;      /* [bp-01h] return flag (Reko al_3377) */
	u16 wLoc04 = 0x0000;    /* [bp-04h] primary index */
	u16 wLoc06 = 0x0000;    /* [bp-06h] inner index */
	u16 wLoc08 = 0x0000;    /* [bp-08h] bar/scan counter */
	u16 wLoc0A = 0x0000;    /* [bp-0Ah] right-edge x */
	u16 wLoc0C = 0x0000;    /* [bp-0Ch] left-edge x */
	u32 dwLoc10 = 0x00000000; /* [bp-10h]/[bp-0Eh] far block #1 */
	u32 dwLoc14 = 0x00000000; /* [bp-14h]/[bp-12h] far block #2 */
	u32 dwLoc18 = 0x00000000; /* [bp-18h]/[bp-16h] far block #3 */
	u32 dwLoc1C = 0x00000000; /* [bp-1Ch]/[bp-1Ah] far block #4 */
	u16 wLoc1E = 0x0000;    /* [bp-1Eh] 13A3 size #3 */
	u16 wLoc20 = 0x0000;    /* [bp-20h] 13A3 size #1 */
	u16 wLoc22 = 0x0000;    /* [bp-22h] 13A3 size #2 */
	u16 wLoc24 = 0x0000;    /* [bp-24h] */
	u16 wLoc26 = 0x0000;    /* [bp-26h] */
	u16 wLoc28 = 0x0000;    /* [bp-28h] 13A3 size #4 */
	u16 wLoc2A = 0x0000;    /* [bp-2Ah] */
	u16 dsTmp = 0x0000;     /* reusable u16 dsOut (023F/0254/02D8/05B8) */
	void *dsv = NULL;       /* reusable void * dsOut (098A/070D/1D95) */
	u16 dxTmp = 0x0000;     /* bgi_set_pixel / renamed_1eda_0254 dxOut */
	u8  dlTmp = 0x00;       /* bgi_draw_line dlOut */
	s16 cxT = 0, dxT = 0, bxT = 0;  /* renamed_1eda_098a outs (cx/dx/bx) */

	/* --- prologue 1F08..2142: paint the two status rectangles --------- */
	wLoc20 = bgi_clamp_rectangle_coords(0x001B, 0x001C, 0x000D, 0x0019);
	dwLoc10 = fn1EDA_023F(wLoc20, 0x0000, 0x0000, &dsTmp);
	dwLoc14 = fn1EDA_023F(wLoc20, 0x0000, 0x0000, &dsTmp);
	/* first 1E6B draws into the [bp-14h] block */
	bgi_draw_clip_rectangle(far_ptr(dwLoc14), (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(LG16(0x58B4) + 0x001C), (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x0019));
	/* second 1E6B draws into the [bp-10h] block */
	bgi_draw_clip_rectangle(far_ptr(dwLoc10), (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(LG16(0x58B4) + 0x0011), (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x000E));
	wLoc24 = (u16)(LG16(0x58B4) + 0x000E);
	wLoc26 = (u16)(LG16(0x58B4) + 0x0019);
	--wLoc24;
	++wLoc26;

	TICK();

	bgi_signed_rectangle_intersect(0x00, far_ptr(dwLoc10),
	            (u16)(LG16(0x58B8) + 0x000D), wLoc24);
	bgi_signed_rectangle_intersect(0x00, far_ptr(dwLoc14),
	            (u16)(LG16(0x58B8) + 0x000D), wLoc26);
	(void)renamed_1eda_0254(wLoc20, (u16)((dwLoc10) & 0xFFFFu), (u16)((dwLoc10) >> 16), 0,
	                  &dxTmp, &dsTmp);
	(void)renamed_1eda_0254(wLoc20, (u16)((dwLoc14) & 0xFFFFu), (u16)((dwLoc14) >> 16), 0,
	                  &dxTmp, &dsTmp);
	bgi_set_text_background_color(0x0001, 0x0000, 0x0000);
	(void)bgi_get_text_cursor_attributes(0x00);
	bgi_set_pixel((u16)(LG16(0x58B8) + 0x001B), (u16)(LG16(0x58B4) + 0x0019),
	            (u16)(LG16(0x58B8) + 0x000D), (u16)(LG16(0x58B4) + 0x0019),
	            &dxTmp);
	bgi_set_pixel((u16)(LG16(0x58B8) + 0x001B), (u16)(LG16(0x58B4) + 0x0011),
	            (u16)(LG16(0x58B8) + 0x000D), (u16)(LG16(0x58B4) + 0x0011),
	            &dxTmp);
	bgi_get_line_attributes(0x0B, (u16)(LG16(0x58B8) + 0x0012),
	            (u16)(LG16(0x58B4) + 0x0019));
	bgi_get_line_attributes(0x03, (u16)(LG16(0x58B8) + 0x0013),
	            (u16)(LG16(0x58B4) + 0x0019));
	bgi_get_line_attributes(0x09, (u16)(LG16(0x58B8) + 0x0014),
	            (u16)(LG16(0x58B4) + 0x0019));
	bgi_get_line_attributes(0x0B, (u16)(LG16(0x58B8) + 0x0012),
	            (u16)(LG16(0x58B4) + 0x0011));
	bgi_get_line_attributes(0x03, (u16)(LG16(0x58B8) + 0x0013),
	            (u16)(LG16(0x58B4) + 0x0011));
	bgi_get_line_attributes(0x09, (u16)(LG16(0x58B8) + 0x0014),
	            (u16)(LG16(0x58B4) + 0x0011));

	/* --- 2167..2248: second pair of blocks, then scan to 14h ---------- */
	wLoc20 = bgi_clamp_rectangle_coords(0x001B, 0x001D, 0x000D, 0x0019);
	dwLoc10 = fn1EDA_023F(wLoc20, 0x0000, 0x0000, &dsTmp);
	dwLoc14 = fn1EDA_023F(wLoc20, 0x0000, 0x0000, &dsTmp);
	bgi_draw_clip_rectangle(far_ptr(dwLoc14), (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(LG16(0x58B4) + 0x001D), (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x0019));
	bgi_draw_clip_rectangle(far_ptr(dwLoc10), (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(LG16(0x58B4) + 0x0011), (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x000D));

	wLoc04 = 0x0001;

l0C74_2153:
	if (wLoc04 >= 0x0014)
		goto l0C74_2249;
	if (bgi_draw_line((u16)(LG16(0x58B8) + 0x001B),
	                (u16)(LG16(0x58B4) + 0x000C - wLoc04), &dlTmp) != 0)
		goto l0C74_2249;
	if (bgi_draw_line((u16)(LG16(0x58B8) + 0x001B),
	                (u16)(LG16(0x58B4) + 0x001E + wLoc04), &dlTmp) != 0)
		goto l0C74_2249;
	if (bgi_draw_line((u16)(LG16(0x58B8) + 0x000D),
	                (u16)(LG16(0x58B4) + 0x000C - wLoc04), &dlTmp) != 0)
		goto l0C74_2249;
	if (bgi_draw_line((u16)(LG16(0x58B8) + 0x000D),
	                (u16)(LG16(0x58B4) + 0x001E + wLoc04), &dlTmp) != 0)
		goto l0C74_2249;
	if (bgi_draw_line((u16)(LG16(0x58B8) + 0x0016),
	                (u16)(LG16(0x58B4) + 0x000C - wLoc04), &dlTmp) != 0)
		goto l0C74_2249;
	if (bgi_draw_line((u16)(LG16(0x58B8) + 0x0016),
	                (u16)(LG16(0x58B4) + 0x001E + wLoc04), &dlTmp) != 0)
		goto l0C74_2249;

	(void)engine_scale_and_tick_clock(0x000F, 0x00E6, &dsv);
	bgi_signed_rectangle_intersect(0x00, far_ptr(dwLoc10),
	            (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x000D - wLoc04));
	bgi_signed_rectangle_intersect(0x00, far_ptr(dwLoc14),
	            (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x0019 + wLoc04));
	++wLoc04;
	goto l0C74_2153;

	/* --- 2249: obstacle/abort: free both blocks and return 0 ---------- */
l0C74_2249:
	if (wLoc04 == 0x0014)
		goto l0C74_2276;
	(void)engine_blit_field_edges(wLoc04, &dsv);   /* the caller's [bp-4] word */
	(void)renamed_1eda_0254(wLoc20, (u16)((dwLoc10) & 0xFFFFu), (u16)((dwLoc10) >> 16), 0,
	                  &dxTmp, &dsTmp);
	(void)renamed_1eda_0254(wLoc20, (u16)((dwLoc14) & 0xFFFFu), (u16)((dwLoc14) >> 16), 0,
	                  &dxTmp, &dsTmp);
	bLoc01 = 0x00;
	goto l0C74_2AD4;

	/* --- 2276: the scan reached 14h ----------------------------------- */
l0C74_2276:
	wLoc0A = (u16)(LG16(0x58B4) + 0x001A + wLoc04);
	wLoc0C = (u16)(LG16(0x58B4) + 0x000D - wLoc04 + 0x0001 + 0x0001);
	if (LG16(0x5968) == 0xFFFF)
		goto l0C74_229A;
	goto l0C74_23EE;

	/* --- 229A: 5968h == FFFFh: extend the right field ----------------- */
l0C74_229A:
	if (wLoc04 >= 0x0041)
		goto l0C74_22FE;
	if (bgi_draw_line((u16)(LG16(0x58B8) + 0x001B),
	                (u16)(LG16(0x58B4) + 0x001E + wLoc04), &dlTmp) != 0)
		goto l0C74_22FE;
	if (bgi_draw_line((u16)(LG16(0x58B8) + 0x000D),
	                (u16)(LG16(0x58B4) + 0x001E + wLoc04), &dlTmp) != 0)
		goto l0C74_22FE;

	(void)engine_scale_and_tick_clock(0x000F, 0x00E6, &dsv);
	bgi_signed_rectangle_intersect(0x00, far_ptr(dwLoc14),
	            (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x0019 + wLoc04));
	++wLoc04;
	goto l0C74_229A;

	/* --- 22FE --------------------------------------------------------- */
l0C74_22FE:
	if (wLoc04 == 0x0041)
		goto l0C74_23E2;
	(void)renamed_1eda_0254(wLoc20, (u16)((dwLoc14) & 0xFFFFu), (u16)((dwLoc14) >> 16), 0,
	                  &dxTmp, &dsTmp);
	wLoc22 = bgi_clamp_rectangle_coords((u16)(LG16(0x58B8) + 0x001B),
	                     (u16)(LG16(0x58B4) + 0x001D + wLoc04),
	                     (u16)(LG16(0x58B8) + 0x000D),
	                     (u16)(LG16(0x58B4) + 0x0019 + wLoc04));
	dwLoc14 = fn1EDA_023F(wLoc22, 0x0000, 0x0000, &dsTmp);
	bgi_draw_clip_rectangle(far_ptr(dwLoc14),
	            (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(LG16(0x58B4) + 0x001D + wLoc04),
	            (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x0019 + wLoc04));

	if (wLoc04 >= 0x0013)
	{
		wLoc06 = wLoc04;
l0C74_2389:
		(void)engine_scale_and_tick_clock(0x0019, 0x00E6, &dsv);
		bgi_signed_rectangle_intersect(0x00, far_ptr(dwLoc14),
		            (u16)(LG16(0x58B8) + 0x000D),
		            (u16)(LG16(0x58B4) + 0x0019 + wLoc06));
		if (wLoc06 != 0x0013)
		{
			--wLoc06;
			goto l0C74_2389;
		}
	}

	/* --- 23B4: abort path of the 0FFh branch -------------------------- */
	wLoc04 = 0x0014;
	(void)engine_blit_field_edges(wLoc04, &dsv);   /* the caller's [bp-4] word */
	(void)renamed_1eda_0254(wLoc20, (u16)((dwLoc10) & 0xFFFFu), (u16)((dwLoc10) >> 16), 0,
	                  &dxTmp, &dsTmp);
	(void)renamed_1eda_0254(wLoc22, (u16)((dwLoc14) & 0xFFFFu), (u16)((dwLoc14) >> 16), 0,
	                  &dxTmp, &dsTmp);
	bLoc01 = 0x00;
	goto l0C74_2AD4;

	/* --- 23E2: reached the right edge (0FFh branch) ------------------- */
l0C74_23E2:
	wLoc0A = (u16)(LG16(0x58B4) + 0x001A + wLoc04);

	/* --- 23EE: 5968h state dispatch ----------------------------------- */
l0C74_23EE:
	if (LG16(0x5968) != 0x0001)
		goto l0C74_254E;

	/* --- 23F8: 5968h == 1: extend the left field ---------------------- */
l0C74_23F8:
	if (wLoc04 >= 0x0041)
		goto l0C74_245C;
	if (bgi_draw_line((u16)(LG16(0x58B8) + 0x001B),
	                (u16)(LG16(0x58B4) + 0x000C - wLoc04), &dlTmp) != 0)
		goto l0C74_245C;
	if (bgi_draw_line((u16)(LG16(0x58B8) + 0x000D),
	                (u16)(LG16(0x58B4) + 0x000C - wLoc04), &dlTmp) != 0)
		goto l0C74_245C;

	(void)engine_scale_and_tick_clock(0x000F, 0x00E6, &dsv);
	bgi_signed_rectangle_intersect(0x00, far_ptr(dwLoc10),
	            (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x000D - wLoc04));
	++wLoc04;
	goto l0C74_23F8;

	/* --- 245C --------------------------------------------------------- */
l0C74_245C:
	if (wLoc04 == 0x0041)
		goto l0C74_2540;
	(void)renamed_1eda_0254(wLoc20, (u16)((dwLoc10) & 0xFFFFu), (u16)((dwLoc10) >> 16), 0,
	                  &dxTmp, &dsTmp);
	wLoc22 = bgi_clamp_rectangle_coords((u16)(LG16(0x58B8) + 0x001B),
	                     (u16)(LG16(0x58B4) + 0x0011 - wLoc04),
	                     (u16)(LG16(0x58B8) + 0x000D),
	                     (u16)(LG16(0x58B4) + 0x000D - wLoc04));
	dwLoc10 = fn1EDA_023F(wLoc22, 0x0000, 0x0000, &dsTmp);
	bgi_draw_clip_rectangle(far_ptr(dwLoc10),
	            (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(LG16(0x58B4) + 0x0011 - wLoc04),
	            (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x000D - wLoc04));

	if (wLoc04 >= 0x0013)
	{
		wLoc06 = wLoc04;
l0C74_24E7:
		(void)engine_scale_and_tick_clock(0x000F, 0x00E6, &dsv);
		bgi_signed_rectangle_intersect(0x00, far_ptr(dwLoc10),
		            (u16)(LG16(0x58B8) + 0x000D),
		            (u16)(LG16(0x58B4) + 0x000D - wLoc06));
		if (wLoc06 != 0x0013)
		{
			--wLoc06;
			goto l0C74_24E7;
		}
	}

	/* --- 2512: abort path of the 01h branch --------------------------- */
	wLoc04 = 0x0014;
	(void)engine_blit_field_edges(wLoc04, &dsv);   /* the caller's [bp-4] word */
	(void)renamed_1eda_0254(wLoc20, (u16)((dwLoc10) & 0xFFFFu), (u16)((dwLoc10) >> 16), 0,
	                  &dxTmp, &dsTmp);
	(void)renamed_1eda_0254(wLoc20, (u16)((dwLoc14) & 0xFFFFu), (u16)((dwLoc14) >> 16), 0,
	                  &dxTmp, &dsTmp);
	bLoc01 = 0x00;
	goto l0C74_2AD4;

	/* --- 2540: reached the left edge (01h branch) --------------------- */
l0C74_2540:
	wLoc0C = (u16)(LG16(0x58B4) + 0x000D - wLoc04 + 0x0001 + 0x0001);

	/* --- 254E: edge-bar animation ------------------------------------- */
l0C74_254E:
	TICK();
	wLoc04 = (u16)(LG16(0x58B8) + 0x001C);
	wLoc06 = (u16)(LG16(0x58B8) + 0x001C);

l0C74_2580:
	if (bgi_draw_line(wLoc06, wLoc0C, &dlTmp) != 0 &&
	    bgi_draw_line(wLoc04, wLoc0A, &dlTmp) != 0)
		goto l0C74_2644;

	/* --- 25A1 --- */
	if ((u16)(LG16(0x58BA) + 0x0059) <= wLoc04)
		goto l0C74_2644;
	if ((u16)(LG16(0x58BA) + 0x0059) <= wLoc06)
		goto l0C74_2644;

	if (bgi_draw_line(wLoc06, wLoc0C, &dlTmp) == 0)
	{
		bgi_get_line_attributes(0x0B, wLoc06, wLoc0C);
		bgi_get_line_attributes(0x03, wLoc06, (u16)(wLoc0C + 0x0001));
		bgi_get_line_attributes(0x09, wLoc06, (u16)(wLoc0C + 0x0002));
		++wLoc06;
	}

	if (bgi_draw_line(wLoc04, wLoc0A, &dlTmp) == 0)
	{
		bgi_get_line_attributes(0x0B, wLoc04, wLoc0A);
		bgi_get_line_attributes(0x03, wLoc04, (u16)(wLoc0A + 0x0001));
		bgi_get_line_attributes(0x09, wLoc04, (u16)(wLoc0A + 0x0002));
		++wLoc04;
	}

	(void)engine_scale_and_tick_clock(0x000F, 0x00FA, &dsv);
	goto l0C74_2580;

	/* --- 2644: victory shrink / score sequence ------------------------ */
l0C74_2644:
	TICK();
	if ((u16)(LG16(0x58BA) + 0x0059) <= wLoc04)
		goto l0C74_2761;
	if ((u16)(LG16(0x58BA) + 0x0059) <= wLoc06)
		goto l0C74_2761;

	/* --- 2680: shrink the bar toward the centre ----------------------- */
	wLoc28 = bgi_clamp_rectangle_coords(LG16(0x58BA), LG16(0x58B6),
	                     LG16(0x58B8), LG16(0x58B4));
	dwLoc1C = fn1EDA_023F(wLoc28, 0x0000, 0x0000, &dsTmp);
	bgi_draw_clip_rectangle(far_ptr(dwLoc1C), LG16(0x58BA), LG16(0x58B6),
	            LG16(0x58B8), LG16(0x58B4));

	TICK();

	wLoc08 = 0x0001;
l0C74_26EA:
	(void)engine_scale_and_tick_clock(0x0014, 0x0032, &dsv);
	LG16(0x58B4) = (u16)(LG16(0x58B4) - LG16(0x5968));
	LG16(0x58B6) = (u16)(LG16(0x58B6) - LG16(0x5968));
	bgi_signed_rectangle_intersect(0x00, far_ptr(dwLoc1C), LG16(0x58B8),
	            LG16(0x58B4));
	if (wLoc08 == 0x002C)
		goto l0C74_2733;
	++wLoc08;
	goto l0C74_26EA;

l0C74_2733:
	TICK();
	(void)renamed_1eda_0254(wLoc28, (u16)((dwLoc1C) & 0xFFFFu), (u16)((dwLoc1C) >> 16), 0,
	                  &dxTmp, &dsTmp);

	/* --- 2761: win sequence ------------------------------------------- */
l0C74_2761:
	if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001), LG16(0x58B4),
	                &dlTmp) != 0)
		goto l0C74_2876;
	if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001), LG16(0x58B6),
	                &dlTmp) != 0)
		goto l0C74_2876;

	/* --- 278B --------------------------------------------------------- */
	wLoc1E = bgi_clamp_rectangle_coords(LG16(0x58BA), LG16(0x58B6),
	                     (u16)(LG16(0x58BA) - 0x000E), LG16(0x58B4));
	bgi_get_line_attributes(0x03, (u16)(LG16(0x58BA) - 0x000E),
	            (u16)(LG16(0x58B4) + 0x0017));
	bgi_get_line_attributes(0x01, (u16)(LG16(0x58BA) - 0x000E),
	            (u16)(LG16(0x58B4) + 0x0018));
	bgi_get_line_attributes(0x01, (u16)(LG16(0x58BA) - 0x000E),
	            (u16)(LG16(0x58B4) + 0x0019));
	dwLoc18 = fn1EDA_023F(wLoc1E, 0x0000, 0x0000, &dsTmp);
	bgi_draw_clip_rectangle(far_ptr(dwLoc18), LG16(0x58BA), LG16(0x58B6),
	            (u16)(LG16(0x58BA) - 0x000E), LG16(0x58B4));

	wLoc08 = 0x0000;
l0C74_2815:
	if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001),
	                (u16)(LG16(0x58B4) + 0x0001), &dlTmp) != 0)
		goto l0C74_2868;
	if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001),
	                (u16)(LG16(0x58B6) - 0x0001), &dlTmp) != 0)
		goto l0C74_2868;
	if (wLoc08 >= 0x0059)
		goto l0C74_2868;

	(void)engine_scale_and_tick_clock(0x001E, 0x0064, &dsv);
	LG16(0x58BA) = (u16)(LG16(0x58BA) + 0x0001);
	++wLoc08;
	bgi_signed_rectangle_intersect(0x00, far_ptr(dwLoc18),
	            (u16)(LG16(0x58BA) - 0x000E), LG16(0x58B4));
	goto l0C74_2815;

l0C74_2868:
	(void)renamed_1eda_0254(wLoc1E, (u16)((dwLoc18) & 0xFFFFu), (u16)((dwLoc18) >> 16), 0,
	                  &dxTmp, &dsTmp);

	/* --- 2876 --------------------------------------------------------- */
l0C74_2876:
	bgi_set_text_background_color(0x0001, 0x0000, 0x0000);
	(void)bgi_get_text_cursor_attributes(0x00);

	/* --- 2888: vertical sweep of the two bars ------------------------- */
l0C74_2888:
	if ((u16)(LG16(0x58B8) + 0x001C) < wLoc06)
		goto l0C74_289E;
	if ((u16)(LG16(0x58B8) + 0x001C) >= wLoc04)
		goto l0C74_28EC;

l0C74_289E:
	if ((u16)(LG16(0x58B8) + 0x001C) >= wLoc06)
		goto l0C74_28C0;
	--wLoc06;
	bgi_set_pixel(wLoc06, (u16)(wLoc0C + 0x0002), wLoc06, wLoc0C, &dxTmp);

l0C74_28C0:
	if ((u16)(LG16(0x58B8) + 0x001C) >= wLoc04)
		goto l0C74_28E2;
	--wLoc04;
	bgi_set_pixel(wLoc04, (u16)(wLoc0A + 0x0002), wLoc04, wLoc0A, &dxTmp);

l0C74_28E2:
	(void)engine_scale_and_tick_clock(0x000F, 0x00FA, &dsv);
	goto l0C74_2888;

	/* --- 28EC: final sequence ----------------------------------------- */
l0C74_28EC:
	TICK();
	(void)renamed_1eda_0254(wLoc20, (u16)((dwLoc10) & 0xFFFFu), (u16)((dwLoc10) >> 16), 0,
	                  &dxTmp, &dsTmp);
	(void)renamed_1eda_0254(wLoc20, (u16)((dwLoc14) & 0xFFFFu), (u16)((dwLoc14) >> 16), 0,
	                  &dxTmp, &dsTmp);

	wLoc20 = bgi_clamp_rectangle_coords((u16)(LG16(0x58B8) + 0x001B),
	                     (u16)(wLoc0A + 0x0004),
	                     (u16)(LG16(0x58B8) + 0x000D),
	                     (u16)(wLoc0A - 0x0001));
	dwLoc14 = fn1EDA_023F(wLoc20, 0x0000, 0x0000, &dsTmp);
	bgi_draw_clip_rectangle(far_ptr(dwLoc14), (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(wLoc0A + 0x0004), (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(wLoc0A - 0x0001));
	wLoc2A = (u16)(LG16(0x58B4) + 0x0019 + 0x0013);

	if ((u16)(wLoc0A - 0x0001) < wLoc2A)
		goto l0C74_29BF;
	wLoc06 = (u16)(wLoc0A - 0x0001);
l0C74_2999:
	(void)engine_scale_and_tick_clock(0x000C, 0x00E6, &dsv);
	bgi_signed_rectangle_intersect(0x00, far_ptr(dwLoc14),
	            (u16)(LG16(0x58B8) + 0x000D), wLoc06);
	if (wLoc06 != wLoc2A)
	{
		--wLoc06;
		goto l0C74_2999;
	}

l0C74_29BF:
	(void)renamed_1eda_0254(wLoc20, (u16)((dwLoc14) & 0xFFFFu), (u16)((dwLoc14) >> 16), 0,
	                  &dxTmp, &dsTmp);
	wLoc20 = bgi_clamp_rectangle_coords((u16)(LG16(0x58B8) + 0x001B),
	                     (u16)(wLoc0C + 0x0003),
	                     (u16)(LG16(0x58B8) + 0x000D),
	                     (u16)(wLoc0C - 0x0002));
	dwLoc10 = fn1EDA_023F(wLoc20, 0x0000, 0x0000, &dsTmp);
	bgi_draw_clip_rectangle(far_ptr(dwLoc10), (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(wLoc0C + 0x0003), (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(wLoc0C - 0x0002));
	wLoc2A = (u16)(LG16(0x58B4) + 0x000D - 0x0013);

	if ((u16)(wLoc0C - 0x0002) <= wLoc2A)
	{
		wLoc06 = (u16)(wLoc0C - 0x0002);
l0C74_2A41:
		(void)engine_scale_and_tick_clock(0x000C, 0x00E6, &dsv);
		bgi_signed_rectangle_intersect(0x00, far_ptr(dwLoc10),
		            (u16)(LG16(0x58B8) + 0x000D), wLoc06);
		if (wLoc06 != wLoc2A)
		{
			++wLoc06;
			goto l0C74_2A41;
		}
	}

	/* --- 2A67: finish ------------------------------------------------ */
	(void)renamed_1eda_0254(wLoc20, (u16)((dwLoc10) & 0xFFFFu), (u16)((dwLoc10) >> 16), 0,
	                  &dxTmp, &dsTmp);
	wLoc04 = 0x0013;
	(void)engine_blit_field_edges(wLoc04, &dsv);   /* the caller's [bp-4] word */

	TICK();

	bLoc01 = 0x01;
	if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001),
	                (u16)(LG16(0x58B4) + 0x0001), &dlTmp) != 0)
		goto l0C74_2AD4;
	if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001),
	                (u16)(LG16(0x58B6) - 0x0001), &dlTmp) != 0)
		goto l0C74_2AD4;

	(void)engine_scroll_blit(&dsTmp);
	(void)engine_scatter_muck();
	bLoc01 = 0x00;

l0C74_2AD4:
	/* Reko models bpOut as the caller's saved BP and dsOut as the DGROUP
	 * selector; neither exists in flat C, so both receive 0 (notes-0C74.md). */
	*(u16 *)bpOut = 0x0000;
	*dsOut = 0x0000;
	return bLoc01;
}

#undef TICK
