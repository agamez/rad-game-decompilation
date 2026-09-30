;; fn1229_0000: 1229:0000
;;   Called from:
;;     1229:00A7 (in fn1229_0040)
;;     1229:0315 (in fn1229_0040)
fn1229_0000 proc
	push	bp
	mov	bp,sp
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	1h
	call	far 1AB8h:0F93h
	call	far 1AB8h:1028h
	push	0h
	push	0h
	call	far 1AB8h:10CEh
	push	ax
	call	far 1AB8h:10E1h
	push	ax
	push	1h
	call	far 1AB8h:0F93h
	leave
	retf	8h
1229:0036                   02 41 41 04 41 41 41 41 01 41       .AA.AAAA.A
