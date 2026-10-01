/* seg1AB8_driverB.c -- RAD V3.1 preservation port, segment 1AB8 (VIDEO),
 * graphical-driver "batch B": the driver code occupying file offsets
 * 0x2500..0x3000 of the embedded graphics-driver image.
 *
 * Ground truth: data/segments/seg1AB8.bin (raw bytes), decoded with
 *   ndisasm -b16 -o 0x2500    and   objdump -D -b binary -mi8086.
 * No Reko listing covers this region (Reko stopped at bgi_detect_video_adapter / 1AB8:2072
 * and emitted 1AB8:2073.. as data).
 *
 * ---------------------------------------------------------------------------
 * The embedded driver
 * ---------------------------------------------------------------------------
 * The driver image starts at 1AB8:2073.  Its header is
 *     2073: word 0x0020   entry offset (+0x20 -> 1AB8:2093)
 *     2075: word 0x19D0   image size
 * The loader (bgi_load_bgi_driver at 1AB8:0BB4) points DGROUP [0xB820]/[0xB822] at
 * 1AB8:2073 and calls bgi_reloc_copy_with_alignment, which relocates/copies the image into its
 * own segment and returns the entry far pointer.  The wrappers in
 * seg1AB8_part5b/6/7/8.c stage SI = function number and execute
 * `call dword ptr [0B820h]`.
 *
 * The relocated driver's segment base is such that driver offset 0 is file
 * offset 0x2093.  Proof: the driver's own far dispatcher at 1AB8:245A
 * (`push ds; push cs; pop ds; mov di,si; mov si,0x39E; ...; call di`) indexes
 * the (key,handler) table at CS:0x39E, which decodes as the byte run at file
 * 0x2431 only when the base is 0x2093.  Hence driver offset X == file
 * 0x2093+X.
 *
 * Two dispatch tables exist, both driver-relative:
 *   - 1AB8:2093 (driver 0x0000): `push ds/push cs/pop ds; push si;
 *     call word [si+0x13]; pop si; pop ds; jmp far [cs:0x70]`.  It indexes
 *     the 30-word near-offset table at driver 0x0013 (file 0x20A6) with
 *     SI = the wrapper function number.  Every non-default target lies in
 *     batch A (file 0x2167..0x23B4) or beyond (0x34B3 for fn 0x24), so the
 *     wrapper protocol's own implementations are NOT in this batch.
 *   - 1AB8:245A (driver 0x03C7): the driver's own far dispatcher.  Its
 *     (fn,handler) table at driver 0x039E (file 0x2431) is
 *         0x0E->0x0B83  0x10->0x071A  0x12->0x0493  0x14->0x0823
 *         0x16->0x08A2  0x18->0x087F  0x20->0x045A  0x24->0x1437
 *         0x26->0x18C9  0x28->0x1713  (0x0000 terminator)
 *     With base 0x2093 the entries 0x0E,0x10,0x12,0x14,0x16,0x18 land in
 *     THIS batch (0x2C16,0x27AD,0x2526,0x28B6,0x2935,0x2912); 0x20,0x24,0x26,
 *     0x28 land in batch A / batch C.  The task's guessed numbers
 *     0x1A/0x1C/0x1E/0x22 do NOT map into this range (see docs).
 *
 * ---------------------------------------------------------------------------
 * Hardware / flat model
 * ---------------------------------------------------------------------------
 * CONVENTIONS.md rule 4.  This batch contains NO int 10h/16h/21h, NO raw port
 * I/O (the EC/EE/E4/E6 bytes seen by a linear disassembler are immediate or
 * ModRM operand bytes, not I/O instructions), no __cli/__sti and no int 23h.
 * No 0xA000 far pointer is constructed.  No pal_* entry point is referenced.
 *
 * Driver state is kept in the file-static mirror g_drv[] (driver-relative
 * offsets), seeded from the relocated image.  `call far [0x70]` (the device
 * driver) and all cross-batch helpers are documented stand-ins.
 *
 * Cross-batch continuations (other batches, not converted here):
 *   batch A: 1AB8:221C, 248B, 2478, 24C7, 24E0, 2369
 *   batch C: 1AB8:326F, 3423, 3470, 3008, 302A, 30B3, 30DA, 30EC, 3101, 3116
 */
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"

/* ================================================================== */
/* Driver segment mirror                                              */
/* ================================================================== */
#define DRV_BASE 0x2093
#define DRV_SIZE 0x19D0

static u8 g_drv[DRV_SIZE];
static u8 g_drv_ready;

#define D8(off)  (*(u8  *)&g_drv[(off)])
#define D16(off) (*(u16 *)&g_drv[(off)])
#define D32(off) (*(u32 *)&g_drv[(off)])

/* Backing store for the driver's clip-run list.  The original holds a 16:16
 * far pointer at driver 0x0533/0x0535; the flat port keeps the offset and uses
 * this buffer for ES:[DI] accesses. */
static u8 g_clipbuf[0x10000];
#define CLIPW(o) (*(u16 *)(void *)&g_clipbuf[(o) & 0xFFFF])

/* ------------------------------------------------------------------ */
/* Forward declarations                                               */
/* ------------------------------------------------------------------ */
static void d2526(u16 *r);
static void d2563(u16 *r);
static void d256F(u16 *r);
static void d257C(u16 *r);
static void d25B3(u16 *r);
static void d25D0(u16 *r);
static void d25F0(u16 *r);
static void d2602(u16 *r);
static void d260E(u16 *r, u16 al);
static void d2654(u16 *r);
static void d2659(u16 *r);
static void d267E(u16 *r);
static void d2684(u16 *r);
static void d2692(u16 *r);
static void d26B1(u16 *r);
static void d2702(u16 *r);
static void d2705(u16 *r);
static void d270F(u16 *r);
static void d2720(u16 *r);
static u8  d2728(u16 *r);
static u8  d277C(u16 ax, u16 bx);
static void d279E(u16 *r);
static void d27AD(u16 *r);
static void d2856(u16 *r);
static void d287B(u16 *r);
static void d289A(u16 *r);
static void d28B6(u16 *r);
static void d2906(u16 *r);
static void d2912(u16 *r);
static void d2935(u16 *r);
static void d2A02(u16 *r);
static void d2A19(u16 *r);
static void d2AC2(u16 *r);
static void d2B15(u16 *r);
static void d2B22(u16 *r);
static void d2B31(u16 *r);
static void d2B3D(u16 *r);
static void d2B49(u16 *r);
static void d2B68(u16 *r);
static void d2B94(u16 *r);
static void d2BE7(u16 *r);
static void d2C16(u16 *r);
static void d2C5A(u16 *r, u16 *f);
static void d2C9B(u16 *r, u16 *f);
static u16  d2CE2(u16 *f, u16 bx);
static void d2D09(u16 *f, u16 ax);
static void d2D39(u16 *f);
static void d2D68(u16 *r, u16 *f);
static void d2D9D(u16 ax, u16 bx);
static void d2DAF(u16 ax, u16 bx);
static void d2E18(u16 *r);
static void d2E78(void);
static void d2E83(u16 *r);
static void d2E83_args(u16 *r, u16 a4, u16 a6, u16 a8, u16 aA, u16 aC,
                       u16 aE, u16 a10, u16 a12, u16 a14, u16 a16);
static void d2FC1(u16 *r, u16 *f);
static void d2FE6(u16 *r, u16 *f);

/* Cross-batch stand-ins (owned by another batch; linked as no-ops here). */
static void d221C(u16 *r);
static void d248B(u16 *r);
static void d24C7(u16 *r);
static void d2478(u16 *r);
static void d24E0(u16 *r);
static void d2369(u16 *r);
static u8  d326F(u16 *r);
static void d3470(u16 *r);
static u16 d3101(u16 a);
static void d3116(void);
static u16 d30B3(u16 a, u16 b);
static u16 d30DA(void);
static u8  d30EC(void);
static void d302A(void);
static void d3008(void);

/* Register-frame indices: the wrappers' TRegs1AB8 field order used by
 * seg1AB8_part8.c (ax,bx,cx,dx,si,di,es).  The SI selector is also supplied
 * as the first argument of seg1AB8_driver_batchB. */
#define R_AX 0
#define R_BX 1
#define R_CX 2
#define R_DX 3
#define R_SI 4
#define R_DI 5
#define R_ES 6

/* ------------------------------------------------------------------ */
/* Device driver callback `call far [0x70]`                           */
/* ------------------------------------------------------------------ */
/* The driver forwards low-level operations to the device driver held at
 * driver 0x0070/0x0072 (installed by the 1AB8:229F initialiser, batch A).
 * That driver is loaded from a separate file and is not part of the recovered
 * image, so the call is a no-op stand-in; SI is the forwarded sub-function. */
static void drv_call70(u16 si)
{
	(void)si;
}

/* ================================================================== */
/* 1AB8:2526  (driver 0x0493)  -- fn 0x12 handler                     */
/* ================================================================== */
/* `push cs/pop es` (ES=CS) is a no-op in the flat model.  Builds the
 * 0x18-byte request block at driver 0x0463 and forwards SI=0x0E. */
static void d2526(u16 *r)
{
	u16 ax = r[R_AX];
	u16 bx = r[R_BX];
	u16 cx = r[R_CX];
	u16 dx = r[R_DX];
	u16 di;

	bx = (u16)(bx + 1);
	cx = (u16)(cx + 1);
	di = bx;

	D16(0x0463) = ax;
	D16(0x0465) = di;
	D16(0x0467) = ax;
	D16(0x0469) = dx;
	D16(0x046B) = cx;
	D16(0x046D) = dx;
	D16(0x046F) = cx;
	D16(0x0471) = di;
	D16(0x0473) = ax;
	D16(0x0475) = di;
	D16(0x0477) = 0x8000;
	D16(0x0479) = 0x8000;

	drv_call70(0x000E);

	r[R_AX] = ax;
	r[R_BX] = bx;
	r[R_CX] = cx;
	r[R_DX] = dx;
	r[R_DI] = di;
}

/* ================================================================== */
/* 1AB8:2563 / 256F                                                   */
/* ================================================================== */
static void d2563(u16 *r)
{
	if (d2728(r))
		return;                                  /* jc 0x257B */
	if (D8(0x009F) >= 3) {                       /* cmp [0x9F],3 ; jnc */
		d257C(r);
		return;
	}
	d256F(r);
}

static void d256F(u16 *r)
{
	if (!d326F(r))                               /* call 0x326F ; jnc ret */
		return;
	drv_call70(0x000C);                          /* mov si,0x0C ; call [0x70] */
}

/* ================================================================== */
/* 1AB8:257C  (driver 0x04E9)  -- thick line via driver 0x0B80 width  */
/* ================================================================== */
static void d257C(u16 *r)
{
	u16 di, si, bord;

	d25B3(r);

	di = (u16)(r[R_AX] - r[R_CX]);
	if ((s16)di < 0)
		di = (u16)(-(s16)di);
	si = (u16)(r[R_BX] - r[R_DX]);
	if ((s16)si < 0)
		si = (u16)(-(s16)si);

	bord = D16(0x0B80);

	if (di >= si) {                              /* cmp di,si ; jnc 0x25A6 */
		r[R_BX] = (u16)(r[R_BX] - bord);
		r[R_DX] = (u16)(r[R_DX] - bord);
		d25B3(r);
		bord = (u16)(bord << 1);
		r[R_BX] = (u16)(r[R_BX] + bord);
		r[R_DX] = (u16)(r[R_DX] + bord);
		d25B3(r);
	} else {
		r[R_AX] = (u16)(r[R_AX] - bord);
		r[R_CX] = (u16)(r[R_CX] - bord);
		d25B3(r);
		bord = (u16)(bord << 1);
		r[R_AX] = (u16)(r[R_AX] + bord);
		r[R_CX] = (u16)(r[R_CX] + bord);
		d25B3(r);
	}
}

static void d25B3(u16 *r)
{
	d256F(r);
}

/* ================================================================== */
/* 1AB8:25D0  internal clip/state dispatcher                          */
/* ================================================================== */
/* Table at driver 0x054D (file 0x25E0) = 055D 05C1 05FF 05C6 056F 05EB
 * 0575 0579 -> 1AB8:25F0,2654,2692,2659,2602,267E,2608,260C. */
static void d25D0(u16 *r)
{
	u16 al = (u16)(u8)r[R_AX];
	u16 di;

	if (al >= 8)
		al = 5;
	di = (u16)((u8)al << 1);

	switch (D16(0x054D + di)) {
	case 0x055D: d25F0(r); break;
	case 0x05C1: d2654(r); break;
	case 0x05FF: d2692(r); break;
	case 0x05C6: d2659(r); break;
	case 0x056F: d2602(r); break;
	case 0x05EB: d267E(r); break;
	case 0x0575: d260E(r, 0x0000); break;
	case 0x0579: d260E(r, 0x00FF); break;
	default: break;
	}
}

/* 1AB8:25F0 */
static void d25F0(u16 *r)
{
	(void)r;
	D8(0x052E) = 0x01;
	D16(0x0531) = 0x0000;
	D16(0x0537) = 0x0000;
}

/* 1AB8:2602 */
static void d2602(u16 *r)
{
	(void)r;
	D8(0x052E) = 0x02;
}

/* 1AB8:267E */
static void d267E(u16 *r)
{
	(void)r;
	D8(0x052E) = 0x00;
}

/* ================================================================== */
/* 1AB8:260E  clip-list flush                                         */
/* ================================================================== */
static void d260E(u16 *r, u16 al)
{
	u16 cx = r[R_CX];
	u16 ax = al;

	if (cx == 0)                                     /* jcxz 0x2653 */
		return;

	r[R_AX] = 0x0000;                                /* xor ax,ax */
	d25D0(r);
	do {
		d270F(r);
		d221C(r);
		d2705(r);
	} while (cx != 0);                               /* and cx,cx ; jnz 0x261C */

	if ((u8)ax == 0) {                               /* and al,al ; jz 0x2650 */
		r[R_AX] = 0x0001;
	} else {
		d248B(r);
		r[R_AX] = 0x0003;
		if (D8(0x009A) != 0)
			r[R_AX] = 0x0002;                /* dec ax */
		d25D0(r);
	}
}

/* ================================================================== */
/* 1AB8:2654 / 2659 / 2692 / 2684                                     */
/* ================================================================== */
static void d2654(u16 *r)
{
	d2684(r);
	d26B1(r);
}

static void d2659(u16 *r)
{
	u16 saved_ax = r[R_AX];
	d2684(r);
	if (D16(0x0531) < D16(0x052F) && D16(0x0531) >= 0x0004) {
		D8(0x052E) = 0x00;
		r[R_AX] = saved_ax;
		drv_call70(0x000E);
	} else {
		D8(0x052E) = 0x00;
	}
}

static void d2692(u16 *r)
{
	if (D16(0x0097) >= 0x00B4)                       /* cmp [0x97],0B4h ; jc */
		D8(0x0B82) = 0xFF;
	if (D8(0x0B82) != 0x00) {                        /* cmp [0x0B82],0 ; jz */
		d2684(r);
		d26B1(r);
		if (D16(0x0531) < D16(0x052F) && D16(0x0531) >= 0x0004) {
			D8(0x052E) = 0x00;
			drv_call70(0x000E);
		} else {
			D8(0x052E) = 0x00;
		}
	} else {
		d2659(r);
	}
}

static void d2684(u16 *r)
{
	r[R_AX] = 0x8000;
	r[R_BX] = 0x8000;
	d248B(r);
	D8(0x052E) = 0x00;
}

/* ================================================================== */
/* 1AB8:26B1  flush one clip run                                      */
/* ================================================================== */
static void d26B1(u16 *r)
{
	u16 di = D16(0x0533);
	u16 cx = D16(0x0531);
	u16 save_ax = r[R_AX], save_bx = r[R_BX];

	(void)di;
	D8(0x052E) = 0x00;
	if (cx >= D16(0x052F))
		goto l279E;
	if (cx < 0x0002)
		goto l267E;

	for (;;) {
		d2702(r);
		d270F(r);
		if ((u8)(r[R_BX] >> 8) == 0x80) {
			if ((u8)r[R_BX] == 0x00)
				break;
			d2702(r);
			if (r[R_CX] != 0)
				continue;
			break;
		}
		r[R_AX] = save_ax;
		r[R_BX] = save_bx;
		d24C7(r);
		if (r[R_CX] != 0)
			continue;
		break;
	}
l267E:
	D8(0x052E) = 0x00;
	return;
l279E:
	d279E(r);
}

/* ================================================================== */
/* 1AB8:2702 / 2705 / 270F                                            */
/* ================================================================== */
static void d2702(u16 *r)
{
	d270F(r);
	d2705(r);
}

static void d2705(u16 *r)
{
	d248B(r);
}

static void d270F(u16 *r)
{
	u16 di = r[R_DI];

	r[R_BX] = 0x8000;
	if (r[R_CX] == 0)                                /* jcxz 0x271F */
		return;
	r[R_AX] = CLIPW(di + 0);
	di = (u16)(di + 2);
	r[R_BX] = CLIPW(di + 0);
	di = (u16)(di + 2);
	r[R_CX] = (u16)(r[R_CX] - 1);
	r[R_DI] = di;
}

/* ================================================================== */
/* 1AB8:2720 / 2728 / 277C / 279E                                     */
/* ================================================================== */
static void d2720(u16 *r)
{
	d2728(r);
}

static u8 d2728(u16 *r)
{
	u16 ax = r[R_AX];
	u16 bx = r[R_BX];

	if (D8(0x052E) == 0x00)
		return 0;

	if (D8(0x052E) == 0x02) {
		r[R_DX] = (u16)((u16)D8(0x009A) | (r[R_DX] & 0xFF00));
		d3470(r);
		/* jnc 0x2756: stand-in clears carry, so the forward is skipped. */
		return 0;
	}

	if (D16(0x0537) != 0x0000) {
		if (ax != D16(0x0539) || bx != D16(0x053B))
			return d277C(ax, bx);
		if (D16(0x0537) == 0x0001)
			return 1;
		d277C(ax, bx);
		ax = 0x8001;
		bx = ax;
		d277C(ax, bx);
		D16(0x0537) = 0x0000;
		return 0;
	}

	D16(0x0539) = ax;
	D16(0x053B) = bx;
	return d277C(ax, bx);
}

static u8 d277C(u16 ax, u16 bx)
{
	u16 di, base;

	D16(0x0537) = (u16)(D16(0x0537) + 1);
	di = D16(0x0531);
	if (di >= D16(0x052F))                           /* jnc 0x279E */
		return 1;
	di = (u16)(di << 1);
	di = (u16)(di << 1);
	base = D16(0x0533);
	di = (u16)(di + base);
	CLIPW(di + 0) = ax;                              /* stosw */
	CLIPW(di + 2) = bx;                              /* es:[di] */
	D16(0x0531) = (u16)(D16(0x0531) + 1);
	return 1;                                        /* stc */
}

static void d279E(u16 *r)
{
	(void)r;
	/* push es/push bx ; les bx,[0x78] ; mov word [es:bx],0FFFAh ; pop ;
	 * stc.  The [0x78] far pointer's backing store is not part of the
	 * driver image; only the carry (returned by the caller) is modelled. */
}

/* ================================================================== */
/* 1AB8:27AD  (driver 0x071A)  -- fn 0x10 handler (line)              */
/* ================================================================== */
static u8 d289A_carry;

static void d27AD(u16 *r)
{
	u16 cx = r[R_CX];
	u16 dx = r[R_DX];

	D16(0x0394) = r[R_AX];
	D16(0x0396) = r[R_BX];
	D16(0x0390) = D16(0x0380);
	D16(0x0392) = D16(0x0382);

	d289A(r);                                        /* call 0x289A */
	r[R_AX] = (u16)((u16)D8(0x009A) | (r[R_AX] & 0xFF00));
	if (d289A_carry == 0) {                          /* jc 0x27D7 */
		u16 al = (u8)r[R_AX];
		r[R_AX] = (u16)((al << 8) | (r[R_AX] >> 8));   /* xchg al,ah */
		drv_call70(0x001E);                      /* mov si,0x1E */
	}

	r[R_BX] = D16(0x0396); r[R_AX] = D16(0x0390); d24C7(r);
	r[R_AX] = D16(0x0394); d24C7(r);
	r[R_AX] = D16(0x0394); r[R_BX] = D16(0x0392); d24C7(r);
	r[R_AX] = D16(0x0390); d24C7(r);
	r[R_AX] = D16(0x0394); r[R_BX] = D16(0x0392); d248B(r);

	if (cx == 0)                                     /* or cx,cx ; jz 0x284B */
		goto l284B;

	{
		u16 d = cx;
		u16 tmp = (u16)(d + (u16)(d << 1));
		tmp = (u16)(tmp >> 1);
		tmp = (u16)(tmp >> 1);
		if (D8(0x0092) != 0) {                   /* cmp [0x92],0 ; jz */
			tmp = (u16)(0u - tmp);           /* neg cx */
			if (dx == 0) {                   /* and di,di ; jnz */
				d287B(r);
				goto l284B;
			}
		}
		r[R_AX] = (u16)(r[R_AX] + tmp);
		r[R_BX] = (u16)(r[R_BX] - tmp);
		d24C7(r);
		r[R_BX] = D16(0x0396);
		r[R_BX] = (u16)(r[R_BX] - tmp);
		d24C7(r);
		if (dx != 0)
			d2856(r);
	}
l284B:
	r[R_AX] = (u16)((u16)D8(0x009A) | (r[R_AX] & 0xFF00));
	drv_call70(0x001E);
	r[R_CX] = cx;
	r[R_DX] = dx;
}

/* 1AB8:2856 */
static void d2856(u16 *r)
{
	u16 cx = r[R_CX];
	u16 dx = r[R_DX];
	r[R_AX] = (u16)(D16(0x0390) + cx); d24C7(r);
	r[R_AX] = D16(0x0390);
	r[R_BX] = D16(0x0396);
	d24C7(r);
	r[R_AX] = D16(0x0394); d248B(r);
	r[R_AX] = (u16)(D16(0x0394) + cx);
	r[R_BX] = (u16)(D16(0x0396) - dx);
	d24C7(r);
}

/* 1AB8:287B */
static void d287B(u16 *r)
{
	u16 cx = r[R_CX];
	u16 dx = r[R_DX];
	r[R_AX] = D16(0x0390);
	r[R_BX] = D16(0x0396);
	d248B(r);
	r[R_BX] = (u16)(D16(0x0396) - dx);
	r[R_AX] = (u16)(D16(0x0390) + cx);
	d24C7(r);
	r[R_AX] = (u16)(D16(0x0394) + cx);
	d24C7(r);
}

/* 1AB8:289A normalises the rectangle and issues 1AB8:24E0 (stc). */
static void d289A(u16 *r)
{
	u16 ax = r[R_AX], bx = r[R_BX], cx = r[R_CX], dx = r[R_DX];

	if ((s16)ax < (s16)cx) { /* jl 0x289F */ }
	else { u16 t = ax; ax = cx; cx = t; }            /* xchg ax,cx */
	if ((s16)bx < (s16)dx) { /* jnl 0x28A5 */ }
	else { u16 t = bx; bx = dx; dx = t; }            /* xchg dx,bx */
	ax = (u16)(ax + 1);
	cx = (u16)(cx - 1);
	bx = (u16)(bx - 1);
	dx = (u16)(dx + 1);
	r[R_AX] = ax; r[R_BX] = bx; r[R_CX] = cx; r[R_DX] = dx;
	d24E0(r);
	d289A_carry = 1;                                 /* stc */
}

/* ================================================================== */
/* 1AB8:28B6  (driver 0x0823)  -- fn 0x14 handler                     */
/* ================================================================== */
static void d28B6(u16 *r)
{
	D8(0x0822) = 0x00;
	d2A02(r);
	if (D8(0x009F) >= 3)                             /* jnc 0x28D7 */
		goto l28D7;
	r[R_SI] = 0x0004;                                /* mov si,4 */
	if (D8(0x0B82) != 0x00)                          /* jnz 0x28D7 */
		goto l28D7;
	if (D16(0x0097) < 0x00B4) {                      /* jc 0x2906 */
		d2906(r);
		return;
	}
l28D7:
	{
		u16 ax = r[R_AX], bx = r[R_BX];
		r[R_AX] = (u16)(ax & 0xFF00);            /* xor al,al */
		r[R_CX] = 0x0001;
		drv_call70(0x0022);
		r[R_AX] = 0x0000;
		d25D0(r);
		r[R_AX] = ax; r[R_BX] = bx;
		d2B94(r);
		d2B68(r);
		r[R_AX] = 0x0001;
		d25D0(r);
		r[R_AX] = (u16)((u16)D8(0x009E) | (r[R_AX] & 0xFF00));
		r[R_CX] = 0x0001;
		drv_call70(0x0022);
	}
}

static void d2906(u16 *r)
{
	d2A19(r);
	d2B68(r);
	r[R_AX] = 0x0005;
	d25D0(r);
}

/* ================================================================== */
/* 1AB8:2912  (driver 0x087F)  -- fn 0x18 handler                     */
/* ================================================================== */
static void d2912(u16 *r)
{
	u16 ax = r[R_AX], bx = r[R_BX];
	u16 b80 = D16(0x0380);
	u16 b82 = D16(0x0382);
	u16 di = (u16)(b80 + ax);
	u16 si = b82;

	d2E83_args(r, si, di, si, di, 0x0000, D8(0x009A), bx, ax, b82, b80);
}

/* ================================================================== */
/* 1AB8:2935  (driver 0x08A2)  -- fn 0x16 handler                     */
/* ================================================================== */
static void d2935(u16 *r)
{
	u16 ax = r[R_AX], bx = r[R_BX], cx = r[R_CX], dx = r[R_DX];
	u16 di, si, q;
	u16 loop_ax, loop_bx;

	D8(0x0822) = 0xFF;
	if (D8(0x0092) != 0) {                           /* cmp [0x92],0 ; jz */
		u16 t = dx; dx = cx; cx = t;             /* xchg dx,cx */
	}
	r[R_AX] = ax; r[R_BX] = bx; r[R_CX] = cx; r[R_DX] = dx;
	d2A02(r);

	if (!(D8(0x0B82) == 0 && D16(0x0097) < 0x00B4)) {
		d2BE7(r);
		return;
	}

	dx = 0x0000;
	r[R_DX] = dx;
	D8(0x0821) = 0x00;
	D16(0x081D) = dx;
	D16(0x081F) = dx;
	D16(0x0394) = dx;
	D16(0x0396) = dx;
	D16(0x0398) = dx;
	D16(0x039A) = dx;

	d2B49(r);
	ax = r[R_AX]; bx = r[R_BX];
	loop_ax = ax; loop_bx = bx;
	q = (u16)(ax / 0x5A);
	di = q;
	q = (u16)(bx / 0x5A);
	if (q >= 4)
		q = 3;
	si = q;

	if (si != di) {
		u16 t;
		di = (u16)(di + 1);
		t = (u16)((u16)(0x5A * di));             /* mul di (AX only) */
		r[R_AX] = loop_ax; r[R_BX] = t; r[R_SI] = 0x0000;
		{
			u8 nz = (u16)(loop_ax - t) != 0;
			d2A19(r);
			if (nz)
				d2AC2(r);
		}
		r[R_AX] = loop_ax; r[R_BX] = loop_bx;
		/* loop 0x2979 -- one more pass */
		d2B49(r);
		ax = r[R_AX]; bx = r[R_BX];
		q = (u16)(ax / 0x5A); di = q;
		q = (u16)(bx / 0x5A); if (q >= 4) q = 3; si = q;
	}
	{
		u8 zf = (ax == bx);
		r[R_AX] = ax; r[R_BX] = bx; r[R_SI] = 0x0000;
		d2A19(r);
		if (!zf)
			d2AC2(r);
	}
	{
		u16 cx2 = D16(0x081D);
		u16 dx2 = D16(0x081F);
		ax = D16(0x0380);
		bx = D16(0x0382);
		D16(0x0394) = cx2;
		D16(0x0396) = dx2;
		if (D8(0x0822) != 0) {
			cx2 = (u16)(cx2 + ax);
			dx2 = (u16)(dx2 + bx);
			r[R_AX] = ax; r[R_BX] = bx; r[R_CX] = cx2; r[R_DX] = dx2;
			d2563(r);
			cx2 = D16(0x0398);
			dx2 = D16(0x039A);
			cx2 = (u16)(cx2 + ax);
			dx2 = (u16)(dx2 + bx);
			r[R_AX] = ax; r[R_BX] = bx; r[R_CX] = cx2; r[R_DX] = dx2;
			d2563(r);
		}
		d2B68(r);
	}
}

/* ================================================================== */
/* 1AB8:2A02                                                          */
/* ================================================================== */
static void d2A02(u16 *r)
{
	D16(0x0390) = r[R_CX];
	D16(0x0392) = r[R_DX];
	D16(0x0384) = D16(0x0380);
	D16(0x0386) = D16(0x0382);
}

/* ================================================================== */
/* 1AB8:2A19  (driver 0x0986)  -- scan converter for fn 0x16          */
/* ================================================================== */
/* Keeps its scratch in a bp frame shared with 1AB8:2FC1/2FE6/2E83. */
static void d2A19(u16 *r)
{
	u16 ax = r[R_AX], bx = r[R_BX];
	u16 cx = D16(0x0390), dx = D16(0x0392);
	u16 di;

	if (D8(0x0092) != 0) {                           /* cmp [0x92],0 ; jz */
		ax = (u16)(ax + 0x5A);
		bx = (u16)(bx + 0x5A);
	}
	di = (u16)(bx - ax);
	D16(0x0093) = di;
	if (di == 0)                                     /* and di,di ; jz 2AFC */
		return;

	/* push [0x380]/[0x382]/cx/dx/[0x9A], di=0xFFFF, si, bx,bx, ax,ax */
	r[R_AX] = ax; r[R_BX] = bx; r[R_CX] = cx; r[R_DX] = dx;
	d2B15(r);                                        /* call 0x2B15 */
	D16(0x0394) = r[R_AX];
	r[R_AX] = ax; r[R_BX] = bx; r[R_CX] = cx; r[R_DX] = dx;
	d2B22(r);                                        /* call 0x2B22 */
	D16(0x0396) = r[R_AX];
	r[R_AX] = ax; r[R_BX] = bx; r[R_CX] = cx; r[R_DX] = dx;
	d2B15(r);
	D16(0x0398) = r[R_AX];
	r[R_AX] = ax; r[R_BX] = bx; r[R_CX] = cx; r[R_DX] = dx;
	d2B22(r);
	D16(0x039A) = r[R_AX];

	/* call 1AB8:25D0 with AX = SI selector */
	r[R_AX] = r[R_SI];
	d25D0(r);

	if (D16(0x0394) == D16(0x0398) && D16(0x0396) == D16(0x039A)) {
		if (D16(0x0093) >= 0x015E)
			goto l2ABE;
	} else {
		if (D16(0x0093) >= 0x0002)
			goto l2ABE;
	}
	r[R_AX] = (u16)(D16(0x0398) + D16(0x0380));
	r[R_BX] = (u16)(D16(0x039A) + D16(0x0382));
	d248B(r);
	return;
l2ABE:
	d2E83(r);
}

/* ================================================================== */
/* 1AB8:2AC2                                                          */
/* ================================================================== */
static void d2AC2(u16 *r)
{
	if (D8(0x0822) == 0x00) {                        /* jnz 0x2AD1 */
		r[R_AX] = 0x0001;
		d25D0(r);
		return;
	}
	d2478(r);
	r[R_AX] = CLIPW(D16(0x0533) + 0);
	r[R_BX] = CLIPW(D16(0x0533) + 2);
	D16(0x0537) = 0x0000;
	d248B(r);
	r[R_AX] = 0x0003;
	d25D0(r);
	if (D16(0x0531) >= 0x0003) {
		D16(0x0531) = (u16)(D16(0x0531) - 3);
		d26B1(r);
	}
}

/* ================================================================== */
/* 1AB8:2B15 / 2B22 / 2B31 / 2B3D / 2B49 / 2B68 / 2B94 / 2BE7          */
/* ================================================================== */
static void d2B15(u16 *r)
{
	/* call 1AB8:2B31 with AX/DX=SX ... result to AX; the batch-C callee
	 * (1AB8:31EA) is not recovered, so the staged AX is returned. */
	d2B31(r);
}

static void d2B22(u16 *r)
{
	/* call 1AB8:2B31 then neg ax (batch-C 1AB8:31F7 not recovered). */
	d2B31(r);
	r[R_AX] = (u16)(0u - r[R_AX]);
}

static void d2B31(u16 *r)
{
	/* 1AB8:2B31: dx=ax ; ax=bx ; bx=cx ; call 2B3D ; ax=dx ; ret */
	u16 ax = r[R_AX], bx = r[R_BX], cx = r[R_CX], dx;
	dx = ax;
	ax = bx;
	bx = cx;
	r[R_AX] = ax; r[R_BX] = bx; r[R_CX] = cx; r[R_DX] = dx;
	d2B3D(r);
	r[R_AX] = r[R_DX];
	(void)ax; (void)bx; (void)cx;
}

static void d2B3D(u16 *r)
{
	/* 1AB8:2B3D: 32x16 mul helper (ax*dx / bx*dx ...). */
	u32 p;
	u16 ax = r[R_AX], dx = r[R_DX], bx = r[R_BX], cx;
	cx = ax;
	ax = dx;
	p = (u32)ax * (u32)bx;
	r[R_AX] = (u16)(p & 0xFFFF);
	r[R_DX] = (u16)(p >> 16);
	(void)cx;
}

static void d2B49(u16 *r)
{
	/* 1AB8:2B49: reduce AX and BX modulo 0x168 and order them. */
	u16 ax = (u16)(r[R_AX] % 0x168);
	u16 bx = (u16)(r[R_BX] % 0x168);
	if (ax >= bx) { u16 t = ax; ax = bx; bx = t; }
	r[R_AX] = ax; r[R_BX] = bx;
}

static void d2B68(u16 *r)
{
	/* 1AB8:2B68: translate 0x384/0x386 and rebuild 0x394..0x39A. */
	u16 b84 = (u16)(D16(0x0384) - D16(0x0084));
	u16 b86 = (u16)(D16(0x0386) - D16(0x0086));
	D16(0x0384) = b84;
	D16(0x0386) = b86;
	D16(0x0384) = (u16)(D16(0x0394) + b84);
	D16(0x0386) = (u16)(D16(0x0396) + b86);
	D16(0x0384) = (u16)(D16(0x0398) + b84);
	D16(0x0386) = (u16)(D16(0x039A) + b86);
	(void)r;
}

static void d2B94(u16 *r)
{
	u16 ax = r[R_AX], bx = r[R_BX];
	u16 t;

	if ((s16)ax < (s16)bx) {                         /* cmp ax,bx ; jc 2BA3 */
		t = ax; ax = bx; bx = t;
	} else {
		bx = (u16)(bx + 0x168);
	}
	if (D8(0x0092) != 0) { ax = (u16)(ax + 0x5A); bx = (u16)(bx + 0x5A); }
	r[R_AX] = ax; r[R_BX] = bx;
	r[R_CX] = D16(0x0390);
	D16(0x0390) = r[R_CX];
	r[R_CX] = D16(0x0392);
	D16(0x0392) = r[R_CX];
}

static void d2BE7(u16 *r)
{
	u16 ax = r[R_AX], bx = r[R_BX];
	u16 cur, v1 = 0;

	r[R_AX] = 0x0000;
	d25D0(r);                                        /* call 0x25D0 */

	if ((s16)ax < (s16)bx) { }                       /* cmp ax,bx ; jc */
	else { u16 t = ax; ax = bx; bx = t; }
	if (D8(0x0092) != 0) { ax = (u16)(ax + 0x5A); bx = (u16)(bx + 0x5A); }
	for (cur = ax; (s16)cur <= (s16)bx; cur = (u16)(cur + 1)) {
		r[R_AX] = cur; r[R_BX] = bx;
		d2B15(r);
		D16(0x039C) = r[R_AX];
		v1 = r[R_AX];
		r[R_AX] = cur; r[R_BX] = bx;
		d2B22(r);
		r[R_AX] = (u16)(v1 + D16(0x0380));
		r[R_BX] = (u16)(r[R_AX] + D16(0x0382));
		d248B(r);
	}
	d2478(r);
	r[R_AX] = CLIPW(D16(0x0533) + 0);
	r[R_BX] = CLIPW(D16(0x0533) + 2);
	d248B(r);
	r[R_AX] = 0x0002;
	d25D0(r);
}

/* ================================================================== */
/* 1AB8:2C16  (driver 0x0B83)  -- fn 0x0E handler (scanline fill)      */
/* ================================================================== */
static u8 d2C16_carry;

static void d2C16(u16 *r)
{
	u16 f[0x0C];
	u16 ax = r[R_AX], bx = r[R_BX], cx = r[R_CX], dx = r[R_DX];
	u16 i;

	for (i = 0; i < 0x0C; ++i)
		f[i] = 0;

	if (D16(0x0097) >= 0x00B4)                       /* cmp [0x97],0B4h ; jc */
		D8(0x0B82) = 0xFF;

	if (ax < 0x0003)                                 /* cmp ax,3 ; jc 2C53 */
		goto l2C53;

	f[0x10 >> 1] = cx;                               /* [bp-0x10] */
	f[0x02 >> 1] = bx;                               /* [bp-0x02] */
	f[0x08 >> 1] = ax;                               /* [bp-0x08] */
	ax = (u16)(ax << 1);
	ax = (u16)(ax << 1);
	bx = (u16)(bx + ax);
	f[0x04 >> 1] = bx;                               /* [bp-0x04] */

	/* push [0x9A] ; call 0x2E18 */
	{
		u16 t = (u16)((u16)D8(0x009A) | (ax & 0xFF00));
		ax = t;
	}
	d2E18(r);
	if (d2C16_carry == 0)
		goto l2C53;
	d2C5A(r, f);
	d2E78();
	if (d2C16_carry == 0)
		goto l2C53;
	d2C5A(r, f);

l2C53:
	r[R_AX] = ax; r[R_BX] = bx; r[R_CX] = cx; r[R_DX] = dx;
	d2369(r);
}

/* 1AB8:2C5A */
static void d2C5A(u16 *r, u16 *f)
{
	u16 ax, bx;
	d2D39(f);
	bx = f[0x0C >> 1];
	f[0x0A >> 1] = bx;
	f[0x12 >> 1] = 0x0000;
	d2C9B(r, f);
	d2D68(r, f);
	ax = f[0x14 >> 1];
	if (f[0x18 >> 1] < 0x0002)                       /* cmp [bp-18h],2 ; jc */
		goto l2C8B;
	f[0x12 >> 1] = (u16)(f[0x12 >> 1] + 1);
	bx = f[0x16 >> 1];
	if (bx != f[0x12 >> 1])                          /* jnz 0x2C8B */
		goto l2C8B;
	f[0x12 >> 1] = 0x0000;
	ax = (u16)((s16)ax * (s16)bx);                   /* imul bx (AX only) */
l2C8B:
	f[0x0A >> 1] = (u16)(f[0x0A >> 1] + ax);
}

/* 1AB8:2C9B */
static void d2C9B(u16 *r, u16 *f)
{
	(void)r;
	f[0x06 >> 1] = 0x0000;
	for (;;) {
		u16 bx = f[0x02 >> 1];
		u16 cx, dx, di, ax;

		bx = (u16)(bx + 2);
		cx = CLIPW(bx);
		ax = f[0x0A >> 1];
		bx = (u16)(bx + 4);
		di = cx;
		dx = CLIPW(bx);
		cx = dx;
		if ((u8)(dx >> 8) == 0x80) {
			if ((u8)dx != 0x01)
				return;
			bx = (u16)(bx + 4);
			cx = CLIPW(bx);
			if ((u8)(cx >> 8) != 0x80)
				continue;
			return;
		}
		if ((s16)dx < (s16)di) { /* jl 0x2CF5 */ }
		else { u16 t = dx; dx = di; di = t; }
		if ((s16)ax < (s16)dx)
			continue;
		if ((s16)ax >= (s16)di)
			continue;
		{
			u16 t = d2CE2(f, bx);
			ax = t;
		}
		d2D09(f, ax);
	}
}

/* 1AB8:2CE2 */
static u16 d2CE2(u16 *f, u16 bx)
{
	u16 si = CLIPW(bx - 6);
	u16 di = CLIPW(bx - 4);
	u16 cx = CLIPW(bx - 2);
	u16 dx = CLIPW(bx);
	u16 ax, q;

	if ((s16)dx >= (s16)di) { /* jl 0x2CF5 */ }
	else { u16 t; t = si; si = cx; cx = t; t = di; di = dx; dx = t; }
	ax = cx;
	di = (u16)(di - dx);
	if (di == 0)
		return ax;
	ax = (u16)(f[0x0A >> 1] - dx);
	si = (u16)(si - cx);
	q = (u16)((s16)si * (s16)ax);                    /* imul si */
	q = (u16)((s16)q / (s16)di);                     /* idiv di */
	ax = (u16)(q + cx);
	return ax;
}

/* 1AB8:2D09 */
static void d2D09(u16 *f, u16 ax)
{
	u16 dx = ax;
	u16 si = f[0x04 >> 1];

	ax = f[0x06 >> 1];
	if (ax >= f[0x10 >> 1])                          /* cmp ; jnc 0x2D38 */
		return;
	f[0x06 >> 1] = (u16)(f[0x06 >> 1] + 1);
	if (ax == 0)
		goto l2D32;
	ax = (u16)(ax - 1);
	for (;;) {
		u16 bx = (u16)(ax << 1);
		u16 cx = CLIPW((u16)(bx + si));
		ax = (u16)(ax + 1);
		if ((s16)cx < (s16)dx)
			break;
		bx = (u16)(ax << 1);
		CLIPW((u16)(bx + si)) = cx;
		ax = (u16)(ax - 1);
		if (ax != 0)
			continue;
		break;
	}
l2D32:
	{
		u16 bx = (u16)(ax << 1);
		CLIPW((u16)(bx + si)) = dx;
	}
}

/* 1AB8:2D39 */
static void d2D39(u16 *f)
{
	f[0x0C >> 1] = 0x7FFF;
	f[0x0E >> 1] = 0x8000;
	for (;;) {
		u16 bx = f[0x02 >> 1];
		u16 ax;
		bx = (u16)(bx + 2);
		ax = CLIPW(bx);
		bx = (u16)(bx + 2);
		if ((u8)(ax >> 8) == 0x80) {
			if ((u8)ax == 0x01)
				continue;
			return;
		}
		if ((s16)ax < (s16)f[0x0C >> 1])
			f[0x0C >> 1] = ax;
		if ((s16)ax < (s16)f[0x0E >> 1])
			continue;
		f[0x0E >> 1] = ax;
	}
}

/* 1AB8:2D68 */
static void d2D68(u16 *r, u16 *f)
{
	u16 si = f[0x04 >> 1];
	u16 ax = 0;
	(void)r;
	if (f[0x06 >> 1] == 0)
		return;
	do {
		u16 bx = (u16)(ax << 1);
		u16 v = CLIPW((u16)(bx + si));
		if ((ax & 1) == 0)
			d2D9D(v, f[0x0A >> 1]);
		else
			d2DAF(v, f[0x0A >> 1]);
		ax = (u16)(ax + 1);
	} while (ax < f[0x06 >> 1]);
}

/* 1AB8:2D9D / 2DAF */
static void d2D9D(u16 ax, u16 bx)
{
	if (D16(0x0DE3) != 0)
		d2E78();
	D16(0x0D06) = ax;
	D16(0x0D08) = bx;
}

static void d2DAF(u16 ax, u16 bx)
{
	u16 rr[8];

	if (D16(0x0DE3) != 0)
		d2E78();
	{
		u16 cx = D16(0x0D06);
		u16 dx = D16(0x0D08);
		D16(0x0D06) = ax;
		D16(0x0D08) = bx;
		if (ax >= cx) { /* jc over */ }
		else { u16 t = ax; ax = cx; cx = t; }
		(void)dx;
	}
	if (D8(0x0B82) != 0) {
		drv_call70(0x000C);
		return;
	}
	rr[R_AX] = ax; rr[R_BX] = bx;
	d24E0(&rr[0]);
}

/* ================================================================== */
/* 1AB8:2E18 / 2E78                                                   */
/* ================================================================== */
static void d2E18(u16 *r)
{
	D16(0x0DE3) = 0x0000;
	{
		u8 al = (u8)(D8(0x0090) - 1);
		if ((s8)al < 0) {
			d2C16_carry = 0;
			return;
		}
		if (D8(0x0B82) == 0)
			al = 0;
		{
			u16 bl = (u8)al;
			u16 bx;
			bl = (u8)((u16)bl + ((u16)bl << 2));    /* bl*5 */
			bx = (u16)(0x0D49 + (u16)(u8)bl);
			/* mov si,bx ; lodsb x4 ; imul word [0xB80] ; ... */
			{
				u16 p = bx;
				u16 b18 = D8(p);
				u16 b16;
				u16 b14;
				u16 b12;
				p = (u16)(p + 1);
				b16 = D8(p);
				p = (u16)(p + 1);
				b14 = (u16)((u16)D8(p) * D16(0x0B80));   /* imul [0xB80] */
				p = (u16)(p + 1);
				b12 = D8(p);
				(void)b18; (void)b16; (void)b14; (void)b12;
			}
		}
	}
	(void)r;
	d2C16_carry = 1;                                 /* clc? -> caller jnc path */
}

static void d2E78(void)
{
	d2C16_carry = 0;                                 /* xor al,al ; ret */
}

/* ================================================================== */
/* 1AB8:2E83  (driver 0x0DF0)  -- elliptical arc / scan converter      */
/* ================================================================== */
static void d2E83_args(u16 *r, u16 a4, u16 a6, u16 a8, u16 aA, u16 aC,
                       u16 aE, u16 a10, u16 a12, u16 a14, u16 a16)
{
	u16 f[0x14];
	u16 ax, bx;
	u16 i;

	for (i = 0; i < 0x14; ++i)
		f[i] = 0;

	ax = d3101(aE);
	a14 = ax;
	D8(0x009A) = (u8)ax;

	f[0x26 >> 1] = d30B3(aA, a8);
	ax = d30B3(a6, a4);
	f[0x2A >> 1] = 0x0000;
	if ((s16)ax <= (s16)f[0x26 >> 1])
		f[0x2A >> 1] = 0x00FF;
	f[0x28 >> 1] = ax;

	if (a12 == 0) a12 = 1;
	if (a10 == 0) a10 = 1;
	ax = a10; bx = a12;
	if ((u16)ax <= (u16)bx)
		ax = bx;
	ax = (u16)((u16)ax * (u16)ax);                   /* mul ax */
	if (d30EC())
		goto l2FB8;
	f[0x24 >> 1] = ax;
	f[0x22 >> 1] = 0x0000;
	/* calls 0x30DA 0x30DA 0x30EC 0x30DA 0x30DA 0x30EC, loop over
	 * 0x2F49..0x2FB6; the batch-C helpers own the pixel span emission. */
	(void)d30DA();
	(void)d30DA();
	(void)d30EC();
	(void)d30DA();
	(void)d30DA();
	(void)d30EC();
l2FB8:
	(void)r; (void)ax; (void)bx; (void)aC; (void)a16;
}

static void d2E83(u16 *r)
{
	u16 ax = r[R_AX], bx = r[R_BX];
	u16 b80 = D16(0x0380);
	u16 b82 = D16(0x0382);
	u16 di = (u16)(b80 + ax);
	(void)b82;
	d2E83_args(r, b82, di, b82, di, 0x0000, D8(0x009A), bx, ax, b82, b80);
}

/* ================================================================== */
/* 1AB8:2FC1 / 2FE6  (frame helpers used by 1AB8:2E83)                 */
/* ================================================================== */
static void d2FC1(u16 *r, u16 *f)
{
	u16 ax;
	ax = (u16)(f[0x14 >> 1] + f[0x08 >> 1]);
	f[0x1C >> 1] = ax;
	ax = (u16)(f[0x12 >> 1] + f[0x06 >> 1]);         /* adc */
	f[0x1A >> 1] = ax;
	ax = (u16)(f[0x18 >> 1] - f[0x0C >> 1]);
	f[0x20 >> 1] = ax;
	ax = (u16)(f[0x16 >> 1] - f[0x0A >> 1]);         /* sbb */
	f[0x1E >> 1] = ax;
	(void)r;
}

static void d2FE6(u16 *r, u16 *f)
{
	u16 ax;
	f[0x02 >> 1] = (u16)(f[0x02 >> 1] + 1);
	ax = f[0x1C >> 1];
	f[0x10 >> 1] = (u16)(f[0x10 >> 1] + ax);
	ax = f[0x1A >> 1];
	f[0x0E >> 1] = (u16)(f[0x0E >> 1] + ax);         /* adc */
	ax = (u16)(f[0x1C >> 1] + f[0x08 >> 1]);
	f[0x14 >> 1] = ax;
	ax = (u16)(f[0x16 >> 1] + f[0x06 >> 1]);         /* adc */
	f[0x12 >> 1] = ax;
	(void)r;
}

/* ================================================================== */
/* Cross-batch stand-ins                                              */
/* ================================================================== */
static void d221C(u16 *r) { r[R_AX] = (u16)(r[R_AX] + D16(0x0084));
                            r[R_BX] = (u16)(r[R_BX] + D16(0x0086)); }
static void d248B(u16 *r) { (void)r; }
static void d24C7(u16 *r) { (void)r; }
static void d2478(u16 *r) { (void)r; }
static void d24E0(u16 *r) { (void)r; }
static void d2369(u16 *r) { (void)r; }
static u8  d326F(u16 *r) { (void)r; return 0; }
static void d3470(u16 *r) { (void)r; }
static u16 d3101(u16 a)   { return a; }
static void d3116(void)   { }
static u16 d30B3(u16 a, u16 b) { (void)b; return a; }
static u16 d30DA(void)    { return 0; }
static u8  d30EC(void)    { return 0; }
static void d302A(void)   { }
static void d3008(void)   { }

/* ================================================================== */
/* Liveness guard                                                     */
/* ================================================================== */
/* Reference every recovered routine so no translation unit local is dropped
 * silently.  These are compile-time (void) expressions, not calls. */
static void drv_keep_refs(void)
{
	(void)d2526; (void)d2563; (void)d256F; (void)d257C; (void)d25B3;
	(void)d25D0; (void)d25F0; (void)d2602; (void)d260E; (void)d2654;
	(void)d2659; (void)d267E; (void)d2684; (void)d2692; (void)d26B1;
	(void)d2702; (void)d2705; (void)d270F; (void)d2720; (void)d2728;
	(void)d277C; (void)d279E; (void)d27AD; (void)d2856; (void)d287B;
	(void)d289A; (void)d28B6; (void)d2906; (void)d2912; (void)d2935;
	(void)d2A02; (void)d2A19; (void)d2AC2; (void)d2B15; (void)d2B22;
	(void)d2B31; (void)d2B3D; (void)d2B49; (void)d2B68; (void)d2B94;
	(void)d2BE7; (void)d2C16; (void)d2C5A; (void)d2C9B; (void)d2CE2;
	(void)d2D09; (void)d2D39; (void)d2D68; (void)d2D9D; (void)d2DAF;
	(void)d2E18; (void)d2E78; (void)d2E83; (void)d2E83_args;
	(void)d2FC1; (void)d2FE6; (void)d3116; (void)d302A; (void)d3008;
}

/* Seed the driver mirror from the relocated image. */
static void drv_seg_init(void)
{
	u16 i;
	if (g_drv_ready)
		return;
	for (i = 0; i < DRV_SIZE; ++i)
		g_drv[i] = g_seg1AB8[DRV_BASE + i];
	g_drv_ready = 1;
	drv_keep_refs();
}

/* ================================================================== */
/* Public batch entry                                                 */
/* ================================================================== */
/* Handles the function numbers whose implementation lies in file offsets
 * 0x2500..0x3000 -- the entries of the driver's (fn,handler) table at driver
 * 0x039E whose handler falls in this batch: 0x0E,0x10,0x12,0x14,0x16,0x18.
 * Returns 1 when SI is handled, 0 otherwise. */
u16 seg1AB8_driver_batchB(u16 si, u16 *regs)
{
	drv_seg_init();

	switch (si) {
	case 0x000E: d2C16(regs); return 1;   /* 1AB8:2C16 */
	case 0x0010: d27AD(regs); return 1;   /* 1AB8:27AD */
	case 0x0012: d2526(regs); return 1;   /* 1AB8:2526 */
	case 0x0014: d28B6(regs); return 1;   /* 1AB8:28B6 */
	case 0x0016: d2935(regs); return 1;   /* 1AB8:2935 */
	case 0x0018: d2912(regs); return 1;   /* 1AB8:2912 */
	default: break;
	}
	return 0;
}
