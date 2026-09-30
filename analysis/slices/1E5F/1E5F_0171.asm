;; fn1E5F_0171: 1E5F:0171
;;   Called from:
;;     0800:00F5 (in fn0800_00C1)
;;     0800:0119 (in fn0800_0103)
fn1E5F_0171 proc
	push	bp
	mov	bp,sp
	push	ds
	lds	dx,[bp+6h]
	mov	al,[bp+0Ah]
	mov	ah,25h
	int	21h
	pop	ds
	pop	bp
	retf	6h
1E5F:0184             00 00 00 00 00 00 00 00 00 00 00 00     ............
