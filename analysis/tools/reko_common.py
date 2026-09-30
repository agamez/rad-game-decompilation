#!/usr/bin/env python3
# reko_common.py -- shared, stdlib-only parsing helpers for the RAD analysis tools.
#
# Reads the Reko decompiler output in analysis/reko/ (never modifies it) and
# exposes the function model used by scan_functions.py, gen_prototypes.py and
# summarize.py.  See analysis/tools/README.md.

import os
import re
from collections import OrderedDict, Counter

# ---------------------------------------------------------------------------
# paths
# ---------------------------------------------------------------------------
TOOLS_DIR = os.path.dirname(os.path.abspath(__file__))
ANALYSIS_DIR = os.path.dirname(TOOLS_DIR)
REPO_DIR = os.path.dirname(ANALYSIS_DIR)
REKO_DIR = os.path.join(ANALYSIS_DIR, "reko")
SUMMARY_DIR = os.path.join(ANALYSIS_DIR, "summary")
SRC_DIR = os.path.join(REPO_DIR, "src")

# The single global-equivalence struct offset in ds: space at/above which RAD.h
# treats values as segment pointers (ptr1AB80@1AB80, ptr1EDA0@1EDA0,
# t20140@20140) rather than DGROUP data.
SEGPTR_MIN = 0x1AB80


def ensure_dir(path):
    os.makedirs(path, exist_ok=True)


# ---------------------------------------------------------------------------
# segments
# ---------------------------------------------------------------------------
def segment_ids():
    """Return the code/data segment ids (e.g. '0800', '2014_0000'), sorted by
    paragraph address.  Derived from the RAD_<seg>.c file names."""
    segs = []
    for name in os.listdir(REKO_DIR):
        m = re.fullmatch(r"RAD_([0-9A-Fa-f_]+)\.c", name)
        if m:
            segs.append(m.group(1))
    return sorted(segs, key=seg_para)


def seg_para(seg):
    return int(seg.split("_")[0], 16)


def seg_end_map():
    """Map segment id -> end offset (byte offset within the segment) using the
    paragraph distance to the next segment.  Segments are contiguous in the
    original load image.  The last segment is sized from the raw byte dumps."""
    segs = segment_ids()
    by_para = sorted(segs, key=seg_para)
    out = {}
    for i, seg in enumerate(by_para):
        if i + 1 < len(by_para):
            nxt = by_para[i + 1]
            out[seg] = (seg_para(nxt) - seg_para(seg)) * 16
        else:
            out[seg] = asm_max_end(seg)
    return out


def read_lines(path):
    with open(path, "r", encoding="utf-8", errors="replace") as fh:
        return fh.read().split("\n")


ASM_DUMP_RE = re.compile(r"^([0-9A-F]{4}):([0-9A-F]{4})\s+(.*)$")
HEX_BYTE_RE = re.compile(r"\b[0-9A-Fa-f]{2}\b")


def asm_max_end(seg):
    """Highest address+length reachable from the raw byte dump lines of a
    segment's .asm file (used only for the final segment)."""
    path = os.path.join(REKO_DIR, "RAD_%s.asm" % seg)
    if not os.path.exists(path):
        return 0
    end = 0
    for ln in read_lines(path):
        m = ASM_DUMP_RE.match(ln)
        if not m:
            continue
        off = int(m.group(2), 16)
        rest = m.group(3)
        # bytes are the leading hex tokens before the ascii margin (col 58)
        hexpart = rest[: 58 - 10] if len(rest) > 58 - 10 else rest
        nbytes = len(HEX_BYTE_RE.findall(hexpart))
        if nbytes:
            end = max(end, off + nbytes)
    return end


# ---------------------------------------------------------------------------
# .c function definitions
# ---------------------------------------------------------------------------
DEF_RE = re.compile(r"^([^\s/].*?)\bfn([0-9A-F]{4})_([0-9A-F]{4})\s*\(")
FN_IN_TEXT_RE = re.compile(r"\bfn([0-9A-F]{4})_([0-9A-F]{4})\s*\(")


def _scan_code_only(lines, start):
    """Yield (line_index, char) for real code characters starting at line
    `start`, skipping // and /* */ comments and string/char literals."""
    in_block = False
    for li in range(start, len(lines)):
        line = lines[li]
        i = 0
        n = len(line)
        while i < n:
            c = line[i]
            if in_block:
                if c == "*" and i + 1 < n and line[i + 1] == "/":
                    in_block = False
                    i += 2
                    continue
                i += 1
                continue
            if c == "/" and i + 1 < n and line[i + 1] == "/":
                break
            if c == "/" and i + 1 < n and line[i + 1] == "*":
                in_block = True
                i += 2
                continue
            if c == '"' or c == "'":
                quote = c
                i += 1
                while i < n:
                    if line[i] == "\\":
                        i += 2
                        continue
                    if line[i] == quote:
                        i += 1
                        break
                    i += 1
                continue
            yield li, c
            i += 1


def _find_matching_brace(lines, start):
    """Return (open_line, close_line) of the first top-level { }, or None."""
    open_line = None
    depth = 0
    for li, c in _scan_code_only(lines, start):
        if c == "{":
            if open_line is None:
                open_line = li
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0 and open_line is not None:
                return open_line, li
    return None


def _collect_signature(lines, start):
    """Collect the (possibly multi-line) function signature beginning at
    `start`, returning (signature_text, line_index_where_it_closes)."""
    buf = lines[start]
    i = start
    # expand until the parameter list parentheses balance (only needed when the
    # signature truly spans lines; the fn-name '(' must have appeared)
    while i + 1 < len(lines):
        depth = buf.count("(") - buf.count(")")
        opened = buf.count("(") > 0
        if opened and depth <= 0:
            break
        i += 1
        buf += " " + lines[i]
    m = FN_IN_TEXT_RE.search(buf)
    if not m:
        return buf.strip(), i
    open_idx = buf.find("(", m.end() - 1)
    depth = 0
    for j in range(open_idx, len(buf)):
        if buf[j] == "(":
            depth += 1
        elif buf[j] == ")":
            depth -= 1
            if depth == 0:
                return buf[: j + 1].strip(), i
    return buf.strip(), i


def parse_c_functions():
    """Return an OrderedDict seg -> list of dicts with keys:
    seg, func, name, line (1-based), sig (normalised), c_line_count."""
    segs = segment_ids()
    result = OrderedDict()
    for seg in segs:
        path = os.path.join(REKO_DIR, "RAD_%s.c" % seg)
        lines = read_lines(path)
        entries = []
        for idx, line in enumerate(lines):
            m = DEF_RE.match(line)
            if not m:
                continue
            name = "fn%s_%s" % (m.group(2), m.group(3))
            # The decompiled C name is a single token; re-parse it to normalise.
            raw_name = re.search(r"fn[0-9A-F]{4}_[0-9A-F]{4}", line)
            if not raw_name or raw_name.group(0) != name:
                # return type may precede; the name found is the real one
                pass
            sig, close_line = _collect_signature(lines, idx)
            sig_norm = re.sub(r"\s+", " ", sig).strip()
            body = _find_matching_brace(lines, idx)
            if body:
                c_line_count = body[1] - body[0] + 1
            else:
                c_line_count = close_line - idx + 1
            entries.append(
                {
                    "seg": m.group(2),
                    "func": m.group(3),
                    "name": "fn%s_%s" % (m.group(2), m.group(3)),
                    "line": idx + 1,
                    "sig": sig_norm,
                    "c_line_count": c_line_count,
                }
            )
        result[seg] = entries
    return result


# ---------------------------------------------------------------------------
# .asm functions
# ---------------------------------------------------------------------------
PROC_RE = re.compile(r"^(fn([0-9A-F]{4})_([0-9A-F]{4}))\s+proc\s*$")
ASM_LABEL_COMMENT_RE = re.compile(r"^;;\s*fn[0-9A-F]{4}_[0-9A-F]{4}:")

INT_RE = re.compile(r"\bint\s+([0-9A-Fa-f]+)h")
OUT_DIRECT_RE = re.compile(r"\bout\s+([0-9A-Fa-f]+)h\s*,\s*al\b")
IN_DIRECT_RE = re.compile(r"\bin\s+al\s*,\s*([0-9A-Fa-f]+)h\b")
OUT_DX_RE = re.compile(r"\bout\s+dx\s*,\s*al\b")
IN_DX_RE = re.compile(r"\bin\s+al\s*,\s*dx\b")
MOV_DX_IMM_RE = re.compile(r"\bmov\s+dx\s*,\s*([0-9A-Fa-f]+)h\b")

CALL_FAR_RE = re.compile(r"^\s*call\s+far\s+([0-9A-Fa-f]+)h:([0-9A-Fa-f]+)h")
CALL_NEAR_RE = re.compile(r"^\s*call\s+([0-9A-Fa-f]+)h\s*$")


def port_token(value):
    return "port%Xh" % value


def int_token(value):
    return "int%Xh" % value


def direct_touch_counter(body_text):
    """Count direct hardware touchpoints in an .asm function body."""
    c = Counter()
    for m in INT_RE.finditer(body_text):
        c[int_token(int(m.group(1), 16))] += 1
    for m in OUT_DIRECT_RE.finditer(body_text):
        c[port_token(int(m.group(1), 16))] += 1
    for m in IN_DIRECT_RE.finditer(body_text):
        c[port_token(int(m.group(1), 16))] += 1
    # port constants loaded into dx are only ports when the body performs
    # dx-relative I/O.
    if OUT_DX_RE.search(body_text) or IN_DX_RE.search(body_text):
        for m in MOV_DX_IMM_RE.finditer(body_text):
            c[port_token(int(m.group(1), 16))] += 1
    return c


def extract_calls(body_text, seg):
    """Return a list of (target_seg, target_off) resolved syntactically."""
    calls = []
    for ln in body_text.split("\n"):
        m = CALL_FAR_RE.match(ln)
        if m:
            calls.append((m.group(1).upper(), int(m.group(2), 16)))
            continue
        m = CALL_NEAR_RE.match(ln)
        if m:
            calls.append((seg.upper(), int(m.group(1), 16)))
    return calls


def parse_asm_functions():
    """Return OrderedDict seg -> list of dicts with keys:
    seg, func, name, offset, start_line, end_line, body, size,
    direct_touches (Counter), calls (list)."""
    ends = seg_end_map()
    segs = segment_ids()
    result = OrderedDict()
    for seg in segs:
        path = os.path.join(REKO_DIR, "RAD_%s.asm" % seg)
        lines = read_lines(path)
        # locate proc lines and the following ;; fn comment boundaries
        procs = []
        for idx, line in enumerate(lines):
            m = PROC_RE.match(line)
            if m:
                procs.append((idx, m.group(1), m.group(2), int(m.group(3), 16)))
        # collect boundary lines (next ;; fn comment) for end-of-body
        fn_comments = [i for i, l in enumerate(lines) if ASM_LABEL_COMMENT_RE.match(l)]
        entries = []
        for k, (idx, name, pseg, off) in enumerate(procs):
            # body ends at the next proc line or the next ;; fn comment
            end = len(lines)
            for j in range(idx + 1, len(lines)):
                if PROC_RE.match(lines[j]) or ASM_LABEL_COMMENT_RE.match(lines[j]):
                    end = j
                    break
            body = "\n".join(lines[idx:end])
            size = None
            if k + 1 < len(procs):
                size = procs[k + 1][3] - off
            else:
                size = ends.get(seg, 0) - off
            entries.append(
                {
                    "seg": pseg,
                    "func": off,
                    "name": name,
                    "offset": off,
                    "start_line": idx + 1,
                    "end_line": end,
                    "body": body,
                    "size": size,
                    "direct_touches": direct_touch_counter(body),
                    "calls": extract_calls(body, seg),
                }
            )
        result[seg] = entries
    return result


# ---------------------------------------------------------------------------
# call graph / touch propagation
# ---------------------------------------------------------------------------
def build_call_graph(cfuncs, afuncs):
    """Return (edges, reverse, key_ok) where edges[key] = set of callee keys,
    reverse[key] = set of caller keys.  key = (seg, off_int)."""
    key_ok = set()
    for seg, entries in afuncs.items():
        for e in entries:
            key_ok.add((e["seg"], e["func"]))
    edges = {k: set() for k in key_ok}
    reverse = {k: set() for k in key_ok}
    for seg, entries in afuncs.items():
        for e in entries:
            src = (e["seg"], e["func"])
            for tgt in e["calls"]:
                if tgt in key_ok:
                    edges[src].add(tgt)
                    reverse[tgt].add(src)
    return edges, reverse, key_ok


def transitive_touches(edges, afuncs, key):
    """Union of direct touch tokens for `key` and every function reachable from
    it through the (statically resolvable) call graph."""
    direct = {}
    for seg, entries in afuncs.items():
        for e in entries:
            direct[(e["seg"], e["func"])] = e["direct_touches"]
    seen = set()
    stack = [key]
    out = set()
    while stack:
        cur = stack.pop()
        if cur in seen:
            continue
        seen.add(cur)
        out.update(direct.get(cur, {}).keys())
        for nxt in edges.get(cur, ()):
            if nxt not in seen:
                stack.append(nxt)
    return out


def touch_sort_key(token):
    m = re.match(r"int([0-9A-F]+)h", token)
    if m:
        return (0, int(m.group(1), 16))
    m = re.match(r"port([0-9A-F]+)h", token)
    if m:
        return (1, int(m.group(1), 16))
    return (2, token)


def format_touches(tokens):
    return ";".join(sorted(tokens, key=touch_sort_key))


# ---------------------------------------------------------------------------
# strings
# ---------------------------------------------------------------------------
QUOTED_RE = re.compile(r'"((?:[^"\\]|\\.)*)"')
ASCII_RUN_RE = re.compile(r"[ -~]{4,}")


def _keep_ascii_run(run):
    run = run.strip()
    if len(run) < 4:
        return None
    alpha = sum(ch.isalpha() for ch in run)
    if alpha < 4 or alpha * 2 < len(run):
        return None
    return run


def extract_strings_from_c(lines):
    out = []
    seen = set()
    for ln in lines:
        if ln.lstrip().startswith("#include"):
            continue
        for m in QUOTED_RE.finditer(ln):
            s = m.group(1)
            if len(s) < 4:
                continue
            if s in seen:
                continue
            seen.add(s)
            out.append(s)
    return out


def extract_strings_from_asm(lines):
    out = []
    seen = set()
    for ln in lines:
        m = ASM_DUMP_RE.match(ln)
        if not m:
            continue
        # Reko dumps 16 byte slots of 3 chars after "XXXX:XXXX ", then the
        # matching 16-character ascii margin.
        rest = ln[10:] if len(ln) >= 10 else ""
        slots = [rest[i : i + 3] for i in range(0, 48, 3)]
        ascii_field = rest[48:64]
        chars = []
        for i in range(16):
            slot = slots[i] if i < len(slots) else ""
            if re.fullmatch(r"[0-9A-Fa-f]{2} ?", slot) and slot.strip():
                chars.append(ascii_field[i] if i < len(ascii_field) else " ")
            else:
                chars.append(" ")
        ascii_text = "".join(chars).rstrip()
        for r in ASCII_RUN_RE.finditer(ascii_text):
            s = _keep_ascii_run(r.group(0))
            if s and s not in seen:
                seen.add(s)
                out.append(s)
    return out
