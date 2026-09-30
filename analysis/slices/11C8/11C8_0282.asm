;; fn11C8_0282: 11C8:0282
;;   Called from:
;;     11C8:02BC (in fn11C8_02AB)
;;     11C8:02D1 (in fn11C8_02CC)
;;     11C8:02E2 (in fn11C8_02DB)
fn11C8_0282 proc
	push	bp
	mov	bp,sp
	mov	al,[bp+4h]
	mov	dx,388h
	out	dx,al
	mov	cx,6h

l11C8_028F:
	in	al,dx
	loop	028Fh

l11C8_0292:
	leave
	ret	2h
