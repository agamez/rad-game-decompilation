#!/usr/bin/env python3
# gen_iface.py -- derive the canonical C interface table for every function.
#
# Ground truth for the conversion rules is analysis/reko/RAD_<seg>.asm; the
# Reko decompilation (RAD_<seg>.c) supplies the structural types.  This tool
# applies the CONVENTIONS.md "Interface conversion" rules to each function's
# *definition* signature (the line ending in `{`) and writes
# analysis/summary/iface.tsv with columns:
#
#     seg <TAB> func <TAB> prototype <TAB> confidence <TAB> notes
#
# In the definition signature Reko spells an output parameter `TYPE & name`
# and a pointer parameter `TYPE * name`.
#
# confidence:  mech   -- fully derived by the mechanical rules
#              semi   -- rules + a judgement (union width / return use)
#              manual -- could not be derived mechanically (best guess + note)
#
# stdlib only; never writes into analysis/reko/.

import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import reko_common as rc  # noqa: E402

IFACE_PATH = os.path.join(rc.SUMMARY_DIR, "iface.tsv")
FUNCS_TSV = os.path.join(rc.SUMMARY_DIR, "functions.tsv")

# ---------------------------------------------------------------------------
# scalar type map (CONVENTIONS.md "Type system"/"Interface conversion")
# ---------------------------------------------------------------------------
BASE = {
    "void": "void",
    "byte": "u8",
    "uint8": "u8",
    "cu8": "u8",
    "bu8": "u8",
    "int8": "s8",
    "word16": "u16",
    "uint16": "u16",
    "ui16": "u16",
    "cup16": "u16",
    "cui16": "u16",
    "int16": "s16",
    "ci16": "s16",
    "word32": "u32",
    "uint32": "u32",
    "ui32": "u32",
    "int32": "s32",
    "char": "char",
    "bool": "u8",
    # Reko "member pointer into ds" is a 16-bit offset in the flat model.
    "mp16": "u16",
}
BASE_CONF = {k: "mech" for k in BASE}

CONF_ORDER = {"mech": 0, "semi": 1, "manual": 2}

# ---------------------------------------------------------------------------
# documented special-case corrections (hardware-abstraction repair)
# ---------------------------------------------------------------------------
# The mechanical rules below derive each prototype from the Reko *definition*
# signature.  For the functions listed here Reko's model dropped stack
# arguments or typed a return incorrectly; the ground truth is the named
# analysis/slices/ .asm file (analysed instruction by instruction).  Each
# entry replaces the derived prototype, confidence and notes verbatim.
# These overrides exist so iface.tsv / src/seg*.h carry the true contract the
# reworked segments (src/seg1E5F.c, src/seg13C1.c, src/seg13C8.c) adopt.
SPECIAL_CASES = {
    # fn1E5F_000B: register-frame interrupt trampoline.  Reko modelled only
    # the frame register marshalling; the real 3rd stack arg is the interrupt
    # vector ([bp+0Ch], retf 6).  Caller fn13C8_000D pushes vec first, then
    # ss:off; under the C convention the last-pushed frame pointer is the first
    # parameter, so the order is (frame ptr, vec).
    ("1E5F", "000B"): (
        "void fn1E5F_000B(u8 * ptrArg04, u16 wArg06)", "semi",
        "asm slices/1E5F/1E5F_000B.asm: [bp+8]=frame off, [bp+0Ah]=frame seg, "
        "[bp+0Ch]=INT vector (retf 6). Reko dropped the vector; C order is "
        "(frame ptr, vec)."),
    # fn13C8_000D: two far out-pointer stack args [bp+6]/[bp+0Ah] receive
    # AX/BX of INT 33h fn0 (retf 8).  Both known callers (fn13C8_0139,
    # fn133F_0056) pass ds:0B6B0 and ds:0B6AE.
    ("13C8", "000D"): (
        "u16 fn13C8_000D(u16 * ptrArg06, u16 * ptrArg0A, void * dsOut)", "semi",
        "asm slices/13C8/13C8_000D.asm: far out-ptr args [bp+6]->BX, "
        "[bp+0Ah]->AX (retf 8); Reko dropped both. Callers pass ds:0B6B0 / "
        "ds:0B6AE."),
    # fn13C8_0066: three far out-pointer stack args [bp+6]/[bp+0Ah]/[bp+0Eh]
    # receive DX/CX/BX of INT 33h fn3 (retf 0Ch).  The callers disagree on the
    # targets (fn13C8_0139: 0B6B8/0B6B6/0B6B4; fn133F_0528: 62D2/62CE/62D0),
    # which is why real pointer parameters are required.
    ("13C8", "0066"): (
        "u16 fn13C8_0066(u16 * ptrArg06, u16 * ptrArg0A, u16 * ptrArg0E, "
        "void * bpOut, void * dsOut)", "semi",
        "asm slices/13C8/13C8_0066.asm: far out-ptr args [bp+6]->DX, "
        "[bp+0Ah]->CX, [bp+0Eh]->BX (retf 0Ch); Reko dropped all three. "
        "Callers disagree on targets (fn13C8_0139 0B6B8/0B6B6/0B6B4; "
        "fn133F_0528 62D2/62CE/62D0)."),
    # fn13C8_009A/00BF/00E4 each read two word stack args [bp+6]/[bp+8] into
    # frame DX/CX before INT 33h fn4/7/8 (retf 4).  Reko dropped them.
    ("13C8", "009A"): (
        "u16 fn13C8_009A(u16 wArg06, u16 wArg08, void * bpOut, void * dsOut)",
        "semi",
        "asm slices/13C8/13C8_009A.asm: stack words [bp+6]->frame DX, "
        "[bp+8]->frame CX before INT 33h fn4 (retf 4); Reko dropped them."),
    ("13C8", "00BF"): (
        "u16 fn13C8_00BF(u16 wArg06, u16 wArg08)", "semi",
        "asm slices/13C8/13C8_00BF.asm: stack words [bp+6]->frame DX, "
        "[bp+8]->frame CX before INT 33h fn7 (retf 4); Reko dropped them."),
    ("13C8", "00E4"): (
        "u16 fn13C8_00E4(u16 wArg06, u16 wArg08, void * dsOut)", "semi",
        "asm slices/13C8/13C8_00E4.asm: stack words [bp+6]->frame DX, "
        "[bp+8]->frame CX before INT 33h fn8 (retf 4); Reko dropped them."),
    # fn13C8_0111 is a far proc (retf 2): its single stack argument is at
    # [bp+6]; Reko named it wArg04 as if the call were near.
    ("13C8", "0111"): (
        "void * fn13C8_0111(u16 wArg06)", "semi",
        "asm slices/13C8/13C8_0111.asm: far proc, one word arg at [bp+6] "
        "(retf 2); Reko named it wArg04. fn1EDA_04B7's AX is stored to frame "
        "DX before INT 33h fn13h."),
    # fn1EDA_04B7 returns AX (unchanged on the in-range retf at 04D8, 00C9h on
    # the out-of-range path); fn13C8_0111 captures it.
    ("1EDA", "04B7"): (
        "u16 fn1EDA_04B7(u16 ax, s16 dx, u8 * di, u16 wArg00, u16 psegArg02)",
        "semi",
        "asm slices/1EDA/1EDA_04B7.asm: returns AX (in-range retf at 04D8 "
        "leaves it; out-of-range sets 00C9h). Caller fn13C8_0111 captures AX."),
}


def worst(a, b):
    return a if CONF_ORDER[a] >= CONF_ORDER[b] else b


def norm_union(t):
    t = t.strip()
    if t.startswith("union "):
        t = t[6:].strip()
    return t


# ---------------------------------------------------------------------------
# parsing helpers
# ---------------------------------------------------------------------------
def split_params(text):
    """Split a parameter list on top-level commas."""
    out, cur, depth = [], "", 0
    for ch in text:
        if ch in "(<[":
            depth += 1
        elif ch in ")>]":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur)
    return [p.strip() for p in out if p.strip()]


MEMBER_PTR_RE = re.compile(r"::\*")


# ---------------------------------------------------------------------------
# RAD.h union widths (used for Reko Eq_N value/return types)
# ---------------------------------------------------------------------------
_UNIONS = None


def parse_unions():
    global _UNIONS
    if _UNIONS is not None:
        return _UNIONS
    path = os.path.join(rc.REKO_DIR, "RAD.h")
    unions = {}
    cur = None
    members = []
    with open(path, "r", encoding="utf-8", errors="replace") as fh:
        for line in fh:
            m = re.match(r"\s*typedef union (Eq_\d+) \{", line)
            if m:
                cur = m.group(1)
                members = []
                continue
            if cur is not None:
                if re.match(r"\s*\}\s*%s\s*;" % cur, line):
                    unions[cur] = members
                    cur = None
                    continue
                mm = re.match(r"\s*(.*?)\s+\w+\s*;\s*$", line)
                if mm:
                    members.append(mm.group(1).strip())
    _UNIONS = unions
    return unions


def union_width(t):
    """Classify a Reko Eq_N union by its member widths."""
    m = re.fullmatch(r"Eq_(\d+)", t)
    if not m:
        return 16
    members = parse_unions().get(t, [])
    has32 = has16 = has8 = hasptr = False
    for mem in members:
        if re.search(r"\b(uint32|word32|int32|ui32)\b", mem):
            has32 = True
        elif re.search(r"\b(uint16|word16|int16|ci16|cup16|cui16)\b", mem):
            has16 = True
        elif re.search(r"\b(uint8|int8|cu8|byte|char)\b", mem):
            has8 = True
        if "*" in mem or "::*" in mem:
            hasptr = True
    if has32:
        return 32
    if has16:
        return 16
    if hasptr and has8:
        return 16  # Eq_526-style: a bp/DGROUP offset
    if hasptr:
        return "ptr"
    if has8:
        return 8
    return 16


NAME_BYTE_RE = re.compile(r"^(bArg[0-9A-F]+|al|ah|bl|bh|cl|ch|dl|dh)$")
NAME_SEGPAIR_RE = re.compile(r"^(es_di|es_si|es_bx|ss_bp|ds_si|ds_di)$")
NAME_PAIR_RE = re.compile(r"^(bx_cx|cx_bx|dx_ax|ax_bx|cx_dx)$")


def eq_by_name(name, t):
    """Map a generic Reko Eq_N value from its argument/register name."""
    if NAME_BYTE_RE.match(name):
        return "u8"
    if name.startswith("dw"):
        return "u32"
    if name.startswith("ptr"):
        return "u8 *"
    if name.startswith("pseg"):
        return "u16"
    if NAME_SEGPAIR_RE.match(name):
        return "u8 *"
    if NAME_PAIR_RE.match(name):
        return "u32"
    if name in ("es", "ss", "ds", "cs"):
        return "u16"
    w = union_width(t)
    if w == 32:
        return "u32"
    if w == 8:
        return "u8"
    if w == "ptr":
        return "void *"
    return "u16"


def map_pointer(base):
    """Map the pointee of `base *` to the flat pointer type."""
    base = norm_union(base)
    if base in BASE and base != "void":
        return BASE[base] + " *"
    if re.fullmatch(r"Eq_\d+", base):
        return "u8 *"
    return "void *"


# ---------------------------------------------------------------------------
# return type derivation
# ---------------------------------------------------------------------------
def classify_generic_ret(rets):
    """Resolve an ambiguous Eq_N return from the decompiled return exprs."""
    widths = set()
    for r in rets:
        r = r.strip().rstrip(";").strip()
        if re.search(r"\bal(_\d+)?\b", r) or re.search(r"\bv8(_\d+)?\b", r):
            widths.add(8)
        else:
            widths.add(16)
    if widths == {8}:
        return "u8"
    return "u16"


def convert_return(rt, rets, notes):
    rt = rt.strip()
    if rt == "void":
        return "void", "mech"
    if MEMBER_PTR_RE.search(rt):
        notes.append("member pointer return -> u8 *")
        return "u8 *", "semi"
    if rt.endswith("*"):
        return map_pointer(rt[:-1].strip()), "mech"
    if rt == "bool":
        notes.append("Reko FlagGroup bool return -> u8")
        return "u8", "semi"
    if rt in ("segptr32", "ptr32"):
        return "u8 *", "semi"
    nu = norm_union(rt)
    if nu in BASE:
        return BASE[nu], "mech"
    if re.fullmatch(r"Eq_\d+", nu):
        if rets and all(
            re.fullmatch(r"ds(_\d+)?", r.strip().rstrip(";").strip())
            or re.fullmatch(r"\d+", r.strip().rstrip(";").strip())
            for r in rets
        ):
            notes.append("returns DGROUP selector (dropped in flat model)")
        w = classify_generic_ret(rets)
        if w == "u8":
            notes.append("Eq_N return resolved to u8 (AL)")
        else:
            notes.append("Eq_N return -> u16")
        return w, "semi"
    if re.fullmatch(r"struct\s+\w+", rt):
        return "void *", "semi"
    notes.append("unmapped return %r -> u16" % rt)
    return "u16", "manual"


# ---------------------------------------------------------------------------
# parameter conversion
# ---------------------------------------------------------------------------
def convert_param(param, notes):
    toks = param.split()
    if not toks:
        return None, "mech"
    name = toks[-1]
    typ = " ".join(toks[:-1]).strip()
    is_out = typ.endswith("&")
    if is_out:
        typ = typ[:-1].strip()
    # Be robust to the comment-form qualifiers (Register/Stack/Sequence/out).
    for sc in ("Register ", "Stack ", "Sequence ", "out "):
        if typ.startswith(sc):
            typ = typ[len(sc):].strip()
    if not typ:
        return None, "mech"
    # Implicit DGROUP selector parameter -> dropped entirely.
    if typ == "Eq_17" and name == "ds" and not is_out:
        notes.append("dropped Eq_17 ds")
        return None, "mech"

    if MEMBER_PTR_RE.search(typ):
        return "u8 * " + name, "semi"
    if typ.endswith("*"):
        ctype = map_pointer(typ[:-1].strip())
        return ctype + " " + name, "mech"

    nu = norm_union(typ)
    if nu in BASE:
        ctype, conf = BASE[nu], "mech"
    elif re.fullmatch(r"Eq_\d+", nu):
        ctype = eq_by_name(name, nu)
        conf = "semi"
        notes.append("Eq_N from name/union width")
    elif re.fullmatch(r"struct\s+\w+", typ):
        ctype, conf = "void *", "semi"
    elif typ in ("<unknown>",):
        ctype, conf = "void *", "manual"
        notes.append("<unknown> -> void *")
    elif typ == "segptr32":
        ctype, conf = "u8 *", "mech"
    else:
        ctype, conf = "u16", "manual"
        notes.append("unmapped type %r -> u16" % typ)

    if is_out and not ctype.endswith("*"):
        ctype = ctype + " *"
        notes.append("out %s -> pointer" % name)
    return ctype + " " + name, conf


# ---------------------------------------------------------------------------
# return expressions from the .c bodies
# ---------------------------------------------------------------------------
def load_return_exprs(cfuncs):
    files = {}
    for seg in rc.segment_ids():
        path = os.path.join(rc.REKO_DIR, "RAD_%s.c" % seg)
        with open(path, "r", encoding="utf-8", errors="replace") as fh:
            files[seg] = fh.read().split("\n")
    out = {}
    for seg, entries in cfuncs.items():
        lines = files[seg]
        for e in entries:
            start = e["line"] - 1
            depth = 0
            started = False
            rets = []
            for i in range(start, len(lines)):
                line = lines[i]
                if started:
                    m = re.search(r"\breturn\b(.*)", line)
                    if m:
                        rets.append(m.group(1).strip())
                depth += line.count("{") - line.count("}")
                if "{" in line:
                    started = True
                if started and depth == 0:
                    break
            out[(seg, e["func"])] = rets
    return out


# ---------------------------------------------------------------------------
# signature conversion
# ---------------------------------------------------------------------------
def parse_sig(sig):
    m = re.search(r"\bfn[0-9A-F]{4}_[0-9A-F]{4}\s*\(", sig)
    if not m:
        return None
    fn = re.search(r"fn[0-9A-F]{4}_[0-9A-F]{4}", sig).group(0)
    ret = sig[: m.start()].strip()
    params_raw = sig[m.end(): sig.rfind(")")].strip()
    params = [] if params_raw in ("", "void") else split_params(params_raw)
    return ret, params, fn


def convert_function(sig, rets):
    notes = []
    parsed = parse_sig(sig)
    if parsed is None:
        return None, "manual", "unparseable signature"
    ret_raw, params, fn = parsed
    c_ret, conf = convert_return(ret_raw, rets, notes)
    c_params = []
    for p in params:
        cp, pconf = convert_param(p, notes)
        conf = worst(conf, pconf)
        if cp:
            c_params.append(cp)
    params_out = ", ".join(c_params) if c_params else "void"
    proto = "%s %s(%s)" % (c_ret, fn, params_out)
    seen = set()
    uniq = []
    for n in notes:
        if n not in seen:
            seen.add(n)
            uniq.append(n)
    return proto, conf, "; ".join(uniq)


# ---------------------------------------------------------------------------
# main
# ---------------------------------------------------------------------------
def read_functions_tsv():
    rows = []
    with open(FUNCS_TSV, "r", encoding="utf-8") as fh:
        for i, line in enumerate(fh):
            if i == 0 or not line.strip():
                continue
            parts = line.rstrip("\n").split("\t")
            rows.append((parts[0], parts[1]))
    return rows


def main():
    rc.ensure_dir(rc.SUMMARY_DIR)
    cfuncs = rc.parse_c_functions()
    sig_by_key = {}
    for seg, entries in cfuncs.items():
        for e in entries:
            sig_by_key[(seg, e["func"])] = e["sig"]
    rets_by_key = load_return_exprs(cfuncs)

    rows = read_functions_tsv()
    lines = ["seg\tfunc\tprototype\tconfidence\tnotes"]
    counts = {"mech": 0, "semi": 0, "manual": 0}
    for seg, func in rows:
        key = (seg, func)
        if key not in sig_by_key:
            lines.append("%s\t%s\tvoid %s(void)\tmanual\tno signature found"
                         % (seg, func, "fn%s_%s" % (seg, func)))
            counts["manual"] += 1
            continue
        proto, conf, notes = convert_function(sig_by_key[key], rets_by_key.get(key, []))
        override = SPECIAL_CASES.get(key)
        if override is not None:
            proto, conf, notes = override
        counts[conf] += 1
        lines.append("%s\t%s\t%s\t%s\t%s" % (seg, func, proto, conf, notes))
    with open(IFACE_PATH, "w", encoding="utf-8") as fh:
        fh.write("\n".join(lines) + "\n")
    print("wrote %s (%d data rows: %d mech, %d semi, %d manual)"
          % (IFACE_PATH, len(rows), counts["mech"], counts["semi"], counts["manual"]))


if __name__ == "__main__":
    main()
