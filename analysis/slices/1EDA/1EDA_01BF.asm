;; fn1EDA_01BF: 1EDA:01BF
;;   Called from:
;;     1EDA:01B5 (in fn1EDA_01B3)
;;     1EDA:01BA (in fn1EDA_01B3)
fn1EDA_01BF proc
	xor	ah,ah
	div	cl

l1EDA_01C3:
	add	al,30h
	push	ax
	call	01E7h
	pop	ax
	mov	al,ah
	ret
