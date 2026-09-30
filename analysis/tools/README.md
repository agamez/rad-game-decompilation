# RAD analysis tools

Stdlib-only Python 3 helpers that read the Reko decompiler output in
`analysis/reko/` (read-only) and materialise the derived prelude files and
summary tables used by the Linux port. Run every script from anywhere; paths are
resolved relative to this file.

Shared helper: `reko_common.py` centralises the Reko path constants and the
parsers for `RAD_<seg>.c` function definitions and `RAD_<seg>.asm` procedures
(function extents, direct hardware touches and the statically resolvable call
graph). The other scripts import it; it emits no output of its own.

`scan_functions.py` joins every `.c` function definition with its `.asm`
procedure and writes `analysis/summary/functions.tsv` (columns: seg, func,
line_in_c, size_bytes, n_callers, n_callees, touches, c_line_count). Function
sizes come from the offset distance to the next `proc`/`;; fn` label in the same
segment (or the segment end for the last function); `touches` is the semicolon
list of `intNh`/`portNNh` tokens reachable from the function through the
resolved call graph, so a wrapper reports the hardware its callees touch.
Usage: `python3 analysis/tools/scan_functions.py`.

`gen_prototypes.py` classifies every `.c` signature and writes
`src/prototypes.h` plus `analysis/summary/complex_sigs.txt`. Signatures that use
only the flat type vocabulary (`void`, `u8/u16/u32/s8/s16/s32`, `char`,
`struct Eq_N *`/`&` mapped to `void *`) become `extern` prototypes; everything
with `Eq_N` value types, `Mem` accessors, `::` member pointers or other exotic
Reko types is listed as a manual-recovery worklist. Usage:
`python3 analysis/tools/gen_prototypes.py`.

`gen_prelude.py` writes the fixed type prelude `src/radtypes.h` (include guard
`RADTYPES_H`, the `u8/u16/u32/s8/s16/s32` typedefs and the `word16`, `word32`,
`byte` aliases from CONVENTIONS.md, nothing else). Usage:
`python3 analysis/tools/gen_prelude.py`.

`gen_globals.py` scans all `RAD_*.c` for DGROUP references (`MemN[ds:0xHHHH:type]`,
decimal offsets, two's-complement `~0xHHHH` forms and the `<width>` form) and
writes `src/globals.c` (symbols named `g_<hex offset>`; overlapping or contiguous
byte refs are merged into `u8` arrays, isolated refs stay typed scalars) and
`analysis/summary/globals.tsv` (offset_hex, size, type, symbol, n_refs,
segments_referencing, flags). Offsets at/above the RAD.h segment-pointer base are
flagged `segptr` and left undefined; types with no known width are flagged
`unmapped`. Usage: `python3 analysis/tools/gen_globals.py`.

`summarize.py` writes `analysis/summary/REPORT.md` with project totals (functions,
code bytes, C lines) and, per segment, function/byte counts, direct hardware
touchpoint tallies, raw-margin string literals and the ten largest functions.
Usage: `python3 analysis/tools/summarize.py`.
