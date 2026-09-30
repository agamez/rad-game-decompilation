#!/usr/bin/env python3
# scan_functions.py -- build analysis/summary/functions.tsv.
#
# One row per function definition found in analysis/reko/RAD_*.c, joined with
# the matching .asm function (size, direct+transitive hardware touches and the
# statically resolvable call graph).  See analysis/tools/README.md.

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import reko_common as rc  # noqa: E402


def main():
    cfuncs = rc.parse_c_functions()
    afuncs = rc.parse_asm_functions()
    edges, reverse, _ = rc.build_call_graph(cfuncs, afuncs)

    rows = []
    for seg in rc.segment_ids():
        # index .asm functions by offset for this segment
        asm_by_off = {e["func"]: e for e in afuncs.get(seg, [])}
        for cf in cfuncs.get(seg, []):
            off = int(cf["func"], 16)
            af = asm_by_off.get(off)
            if af is None:
                size = 0
                touches = ""
            else:
                size = af["size"]
                touches = rc.format_touches(
                    rc.transitive_touches(edges, afuncs, (af["seg"], af["func"]))
                )
            key = (cf["seg"], off)
            n_callers = len(reverse.get(key, ()))
            n_callees = len(edges.get(key, ()))
            rows.append(
                [
                    cf["seg"],
                    cf["func"],
                    str(cf["line"]),
                    str(size),
                    str(n_callers),
                    str(n_callees),
                    touches,
                    str(cf["c_line_count"]),
                ]
            )

    rc.ensure_dir(rc.SUMMARY_DIR)
    out_path = os.path.join(rc.SUMMARY_DIR, "functions.tsv")
    with open(out_path, "w", encoding="utf-8") as fh:
        fh.write(
            "seg\tfunc\tline_in_c\tsize_bytes\tn_callers\tn_callees\ttouches\tc_line_count\n"
        )
        for r in rows:
            fh.write("\t".join(r) + "\n")
    print("wrote %s (%d rows)" % (out_path, len(rows)))


if __name__ == "__main__":
    main()
