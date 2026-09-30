#!/usr/bin/env python3
"""Slice Reko per-segment .c/.asm into per-function files under analysis/slices/.
Each slice: <seg>_<off>.c (Reko decompiled body), <seg>_<off>.asm (ground truth),
plus index.tsv (off, kind, prototype, c_lines). Deterministic; read-only on reko/."""
import os, re, csv, sys

REKO = "analysis/reko"
OUT  = "analysis/slices"
SEGS = ["0800","0C43","0C74","11C8","1206","1229","133F","13C1","13C8","13E2","1AB8","1E5F","1E78","1EDA"]

def load_iface():
    proto = {}
    with open("analysis/summary/iface.tsv") as f:
        r = csv.DictReader(f, delimiter='\t')
        for row in r:
            proto[(row["seg"], row["func"])] = row["prototype"]
    return proto

def slice_c(seg):
    """Return list of (off, kind, text). kind: fn|data"""
    txt = open(f"{REKO}/RAD_{seg}.c").read()
    lines = txt.split("\n")
    items = []
    cur_off = None; cur_kind = None; cur = []
    pat = re.compile(r"^// ([0-9A-F]{4}):([0-9A-F]{4}): ")
    dat = re.compile(r"^<anonymous> (g_t[0-9A-F]+) = <code>; // ([0-9A-F]{4}):([0-9A-F]{4})")
    def flush():
        if cur_off is not None and cur:
            items.append((cur_off, cur_kind, "\n".join(cur).rstrip()+"\n"))
    for ln in lines:
        m = pat.match(ln)
        d = dat.match(ln)
        if m or d:
            flush()
            cur = []
            if m:
                cur_off = m.group(2); cur_kind = "fn"
                cur.append(ln)
            else:
                cur_off = d.group(3); cur_kind = "data"
                cur.append(ln)
        else:
            if cur_off is not None:
                cur.append(ln)
    flush()
    return items

def slice_asm(seg):
    """Return dict off -> asm text (from ';; fn<seg>_<off>:' or '<fn> proc' to next fn marker)."""
    txt = open(f"{REKO}/RAD_{seg}.asm").read()
    lines = txt.split("\n")
    marks = []  # (line_idx, off)
    pat = re.compile(r"^;; fn[0-9A-F]{4}_([0-9A-F]{4}):")
    for i, ln in enumerate(lines):
        m = pat.match(ln)
        if m: marks.append((i, m.group(1)))
    ranges = {}
    for k, (i, off) in enumerate(marks):
        end = marks[k+1][0] if k+1 < len(marks) else len(lines)
        ranges[off] = "\n".join(lines[i:end]).rstrip()+"\n"
    return ranges

def main():
    os.makedirs(OUT, exist_ok=True)
    proto = load_iface()
    total = 0
    for seg in SEGS:
        d = f"{OUT}/{seg}"; os.makedirs(d, exist_ok=True)
        items = slice_c(seg); asms = slice_asm(seg)
        rows = []
        for off, kind, text in items:
            open(f"{d}/{seg}_{off}.c","w").write(text)
            if kind == "fn" and off in asms:
                open(f"{d}/{seg}_{off}.asm","w").write(asms[off])
            p = proto.get((seg, off), "")
            rows.append([seg, off, kind, p, text.count("\n")])
            total += 1
        with open(f"{d}/index.tsv","w",newline="") as f:
            w = csv.writer(f, delimiter='\t')
            w.writerow(["seg","off","kind","prototype","c_lines"])
            w.writerows(rows)
    print(f"sliced {total} items across {len(SEGS)} segments -> {OUT}/")

if __name__ == "__main__":
    main()
