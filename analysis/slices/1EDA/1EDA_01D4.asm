;; fn1EDA_01D4: 1EDA:01D4
;;   Called from:
;;     1EDA:01D0 (in fn1EDA_01CD)
;;     1EDA:01D3 (in fn1EDA_01CD)
fn1EDA_01D4 proc
	push	ax
	mov	cl,4h
	shr	al,cl
	call	01DFh
	pop	ax
	and	al,0Fh
