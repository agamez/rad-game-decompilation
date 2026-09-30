;; fn1EDA_1123: 1EDA:1123
;;   Called from:
;;     0800:022B (in fn0800_01FE)
;;     0800:2452 (in fn0800_2401)
;;     0800:28A5 (in fn0800_2827)
;;     0800:3696 (in fn0800_31B7)
;;     0C43:0177 (in fn0C43_00B9)
;;     0C43:0229 (in fn0C43_00B9)
;;     1229:04B3 (in fn1229_0486)
;;     1229:0935 (in fn1229_0735)
fn1EDA_1123 proc
	push	bp
	mov	bp,sp
	les	di,[bp+0Ah]
	call	1076h
	jnz	114Fh

l1EDA_112E:
	mov	ax,[bp+8h]
	mul	word ptr es:[di+4h]
	mov	cx,ax
	mov	ax,[bp+6h]
	mul	word ptr es:[di+4h]
	add	cx,dx
	mov	dx,ax
	mov	bx,es:[di]
	mov	ax,4200h
	int	21h
	jnc	114Fh

l1EDA_114C:
	mov	[5380h],ax

l1EDA_114F:
	pop	bp
	retf	8h
1EDA:1153          E8 44 00 72 0F 26 8B 4D 04 83 F9 01 74    .D.r.&.M....t
1EDA:1160 06 33 DB 0E E8 23 F8 CA 04 00                   .3...#....
