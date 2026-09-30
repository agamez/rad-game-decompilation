/* seg1EDA_shared.h -- file-scope state shared across segment 1EDA part files.
 *
 * Created by chunk 2b (functions 1EDA:03D3..04B7).  Only variables that must
 * be visible to functions in other part files live here; within-part helpers
 * stay static in their own translation unit.
 */
#ifndef SEG1EDA_SHARED_H
#define SEG1EDA_SHARED_H

#include "radtypes.h"

/* 1EDA:0491 (chunk 2b) computes a 32-bit DX:AX result, but its frozen
 * prototype `u16 fn1EDA_0491(u16 ax)` returns only AX.  The high half (DX,
 * the segment-arithmetic result) is latched here so that callers which
 * consume both halves can recover it:
 *   1EDA:03D3 (chunk 2b)      stores AX at [block+4], DX at [block+6];
 *   1EDA:0308 (another part)  uses DX in its free-list walk.
 * The defining translation unit is src/seg1EDA_part2b.c. */
extern u16 g_0491_dx;

/* chunk 3c -- stream-block callbacks recovered from 1EDA:060C .. 1EDA:0775
 * (definitions in src/seg1EDA_part3c.c).  They use the ABI of the existing
 * dispatch sites (fn1EDA_05FB / fn1EDA_0879 / fn1EDA_07E9): `u16 (*)(u8 *)`,
 * one far block pointer argument, AX return, 0 = success.  A dispatcher that
 * holds a callback-slot offset (0x10/0x14/0x18/0x1C) must resolve it to one
 * of these host functions; see docs/notes-1EDA.md ("## chunk 3c"). */
extern u16 fn1EDA_060C(u8 * block);
extern u16 fn1EDA_068E(u8 * block);
extern u16 fn1EDA_06E8(u8 * block);
extern u16 fn1EDA_0718(u8 * block);
extern u16 fn1EDA_073D(u8 * block);
extern u16 fn1EDA_075D(u8 * block);

/* Added by chunk 6 (functions 1EDA:1076..1384).

 * Data-buffer far pointer dropped by the frozen prototypes of the record-I/O
 * helpers fn1EDA_1091 (1EDA:1091) and fn1EDA_10BB (1EDA:10BB).  The original
 * loaded that pointer from the stack between the named arguments and handed
 * it to INT 21h AH=3F/40; Reko folded it into its dropped `ds` register
 * parameter, so the iface.tsv prototypes cannot carry it.  The defining
 * translation unit is src/seg1EDA_part6.c (default: DGROUP:0x5CB4, the buffer
 * of the startup load path fn0800_01FE -> fn1EDA_1085/1091).  Callers outside
 * chunk 6 must point it at their buffer before invoking the record-I/O
 * helpers. */
extern u8 *g_1EDA_io_buffer;

/* PSP (program segment prefix) base used by fn1EDA_126C / fn1EDA_1216
 * (chunk 6).  DGROUP:0x537C holds the DOS PSP selector, which the flat model
 * cannot resolve; the defining part file defaults this to g_dgroup.  A caller
 * that owns the real PSP (main.c's g_psp, passed to fn0800_4255) can point it
 * at that buffer. */
extern u8 *g_1EDA_psp;

/* chunk 3b-ii -- resolve a callback-slot OFFSET (0x060C/0x06E8/0x0718/
 * 0x073D/0x075D) to the recovered host function; defined in
 * src/seg1EDA_part3bii.c, used by the dispatch sites (05FB/0879/07E9). */
u16 (*seg1EDA_stream_cb(u16 off))(u8 *);

#endif /* SEG1EDA_SHARED_H */
