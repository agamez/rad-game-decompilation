;; fn1EDA_086C: 1EDA:086C
;;   Called from:
;;     0800:0D6F (in fn0800_0D20)
;;     11C8:0217 (in fn11C8_0092)
fn1EDA_086C proc
	push	bp
	mov	bp,sp
	les	di,[bp+6h]
	call	0879h
	pop	bp
	retf	4h
