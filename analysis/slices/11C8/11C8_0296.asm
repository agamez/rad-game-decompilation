;; fn11C8_0296: 11C8:0296
;;   Called from:
;;     11C8:02C1 (in fn11C8_02AB)
;;     11C8:02D6 (in fn11C8_02CC)
;;     11C8:02E9 (in fn11C8_02DB)
fn11C8_0296 proc
	push	bp
	mov	bp,sp
	mov	al,[bp+4h]
	mov	dx,389h
	out	dx,al
	mov	cx,35h
	dec	dx

l11C8_02A4:
	in	al,dx
	loop	02A4h

l11C8_02A7:
	leave
	ret	2h
