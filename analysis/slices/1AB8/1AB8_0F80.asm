;; fn1AB8_0F80: 1AB8:0F80
;;   Called from:
;;     0800:14A3 (in fn0800_149F)
;;     0800:1646 (in fn0800_149F)
;;     0800:1671 (in fn0800_166D)
;;     0800:1829 (in fn0800_166D)
;;     0800:1854 (in fn0800_184C)
;;     0800:3DAB (in fn0800_3D9D)
;;     1229:0CDC (in fn1229_0CCE)
;;     1229:0DE3 (in fn1229_0DCC)
;;     1229:110A (in fn1229_0DCC)
fn1AB8_0F80 proc
	push	bp
	mov	bp,sp
	push	cs
	call	1AC2h
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	push	cs
	call	108Bh
	pop	bp
	retf
