# RAD.EXE memory / file layout (verified against relocations and entry bytes)

Load base P0 = 0x0800. File image offset of segment S = (S - 0x800)*16.
DGROUP = segment 2014 (fn1EDA_0000: `mov dx,2014h ; mov ds,dx`).
File image size = 0x1D4D0. e_minalloc area (DGROUP BSS + stack) is not in the file.

| Reko seg | file img off | size (to next seg / img end) | role |
|---|---|---|---|
| 0800 | 0x00000 | 0x04430 | code+entry (CRT fn0800_4255) |
| 0C43 | 0x04430 | 0x00310 | code |
| 0C74 | 0x04740 | 0x05540 | code |
| 11C8 | 0x09C80 | 0x003E0 | code |
| 1206 | 0x0A060 | 0x00230 | code |
| 1229 | 0x0A290 | 0x01160 | code |
| 133F | 0x0B3F0 | 0x00820 | code |
| 13C1 | 0x0BC10 | 0x00070 | code |
| 13C8 | 0x0BC80 | 0x001A0 | code |
| 13E2 | 0x0BE20 | 0x06D60 | code + ~27KB data tables |
| 1AB8 | 0x12B80 | 0x03A70 | code |
| 1E5F | 0x165F0 | 0x00190 | code |
| 1E78 | 0x16780 | 0x00620 | code |
| 1EDA | 0x16DA0 | 0x013A0 | code |
| 2014 | 0x18140 | 0x05390 | DGROUP: _DATA (file) + _BSS (zeroed) + stack |
| (DGROUP _BSS+stack) | beyond EOF | 0x06780 BSS + 0x44F0 stack | zeroed at load |

Runtime DGROUP layout: _DATA 0x0000..0x5390 (file-backed, = dgroup_data.bin),
_BSS 0x5390..0xBB10 (zeroed), STACK 0xBB10..0x10000 (e_ss=0x23C5-0x800 rel -> off 0xBB10, e_sp=0xFDE8).

Extraction: data/segments/segNNNN.bin (file bytes per segment), dgroup_data.bin (_DATA only).
