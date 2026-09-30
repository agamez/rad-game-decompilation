;; fn0C74_070D: 0C74:070D
;;   Called from:
;;     0C74:0D17 (in fn0C74_0CFA)
;;     0C74:0D66 (in fn0C74_0D43)
;;     0C74:0DB7 (in fn0C74_0D94)
;;     0C74:0E02 (in fn0C74_0DE5)
;;     0C74:0F32 (in fn0C74_0E2E)
;;     0C74:129F (in fn0C74_0FA1)
;;     0C74:1372 (in fn0C74_0FA1)
;;     0C74:1427 (in fn0C74_0FA1)
;;     0C74:14D0 (in fn0C74_0FA1)
;;     0C74:1585 (in fn0C74_0FA1)
;;     0C74:16BB (in fn0C74_0FA1)
;;     0C74:17C5 (in fn0C74_0FA1)
;;     0C74:186B (in fn0C74_0FA1)
;;     0C74:194F (in fn0C74_0FA1)
;;     0C74:1A06 (in fn0C74_0FA1)
;;     0C74:1AAE (in fn0C74_0FA1)
;;     0C74:1BFE (in fn0C74_1B3B)
;;     0C74:1C73 (in fn0C74_1B3B)
;;     0C74:1D28 (in fn0C74_1B3B)
;;     0C74:1E99 (in fn0C74_1D95)
;;     0C74:2206 (in fn0C74_1F08)
;;     0C74:22D9 (in fn0C74_1F08)
;;     0C74:238E (in fn0C74_1F08)
;;     0C74:2437 (in fn0C74_1F08)
;;     0C74:24EC (in fn0C74_1F08)
;;     0C74:263E (in fn0C74_1F08)
;;     0C74:26EE (in fn0C74_1F08)
;;     0C74:2845 (in fn0C74_1F08)
;;     0C74:28E7 (in fn0C74_1F08)
;;     0C74:299E (in fn0C74_1F08)
;;     0C74:2A46 (in fn0C74_1F08)
;;     0C74:2B53 (in fn0C74_2AD9)
;;     0C74:30A6 (in fn0C74_2E5A)
;;     0C74:3139 (in fn0C74_2E5A)
;;     0C74:3179 (in fn0C74_2E5A)
;;     0C74:3481 (in fn0C74_3236)
;;     0C74:3514 (in fn0C74_3236)
;;     0C74:3558 (in fn0C74_3236)
;;     0C74:39BF (in fn0C74_396E)
;;     0C74:3A3B (in fn0C74_396E)
;;     0C74:3A7C (in fn0C74_396E)
;;     0C74:3AA5 (in fn0C74_396E)
;;     0C74:3BB7 (in fn0C74_396E)
;;     0C74:3C80 (in fn0C74_396E)
;;     0C74:3D56 (in fn0C74_396E)
;;     0C74:3E6E (in fn0C74_396E)
;;     0C74:3EEA (in fn0C74_396E)
;;     0C74:3F1A (in fn0C74_396E)
;;     0C74:3F62 (in fn0C74_396E)
;;     0C74:3FD6 (in fn0C74_3F74)
;;     0C74:407E (in fn0C74_3F74)
;;     0C74:40BD (in fn0C74_3F74)
;;     0C74:40E4 (in fn0C74_3F74)
;;     0C74:41FE (in fn0C74_3F74)
;;     0C74:42C8 (in fn0C74_3F74)
;;     0C74:439F (in fn0C74_3F74)
;;     0C74:44BF (in fn0C74_3F74)
;;     0C74:4537 (in fn0C74_3F74)
;;     0C74:4565 (in fn0C74_3F74)
;;     0C74:45BC (in fn0C74_3F74)
;;     0C74:461F (in fn0C74_45CE)
;;     0C74:469B (in fn0C74_45CE)
;;     0C74:486E (in fn0C74_45CE)
;;     0C74:4891 (in fn0C74_45CE)
;;     0C74:49FB (in fn0C74_4999)
;;     0C74:4AA3 (in fn0C74_4999)
;;     0C74:4C7F (in fn0C74_4999)
;;     0C74:4CA5 (in fn0C74_4999)
;;     0C74:4E21 (in fn0C74_4DAC)
;;     0C74:4EC9 (in fn0C74_4DAC)
;;     0C74:4F67 (in fn0C74_4DAC)
;;     0C74:4FC9 (in fn0C74_4DAC)
;;     0C74:5033 (in fn0C74_4FD7)
;;     0C74:50B2 (in fn0C74_4FD7)
;;     0C74:514B (in fn0C74_4FD7)
;;     0C74:519C (in fn0C74_4FD7)
fn0C74_070D proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+4h]
	mul	word ptr [58E6h]
	cwd
	mov	cx,9h
	idiv	cx
	mov	[bp+4h],ax
	cmp	byte ptr [58B0h],0h
	jz	072Fh

l0C74_0727:
	push	word ptr [bp+6h]
	call	far 11C8h:0354h

l0C74_072F:
	push	word ptr [bp+4h]
	call	02D8h
	cmp	byte ptr [58B0h],0h
	jz	0741h

l0C74_073C:
	call	far 11C8h:033Bh

l0C74_0741:
	push	word ptr [bp+4h]
	call	02D8h
	leave
	ret	4h
0C74:074B                                  21 20 00 00 00            ! ...
0C74:0750 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0C74:0760 00 00 00 00 00 00 00 00 00 00 00                ...........
