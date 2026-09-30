;; fn1AB8_1F80: 1AB8:1F80
;;   Called from:
;;     1AB8:1F2C (in fn1AB8_1F19)
;;     1AB8:1F52 (in fn1AB8_1F19)
fn1AB8_1F80 proc
	mov	ax,1200h
	mov	bl,10h
	mov	bh,0FFh
	mov	cl,0Fh
	int	10h
	cmp	cl,0Ch
	jge	1F9Ch

l1AB8_1F90:
	cmp	bh,1h
	jg	1F9Ch

l1AB8_1F95:
	cmp	bl,3h
	jg	1F9Ch

l1AB8_1F9A:
	stc
	ret

l1AB8_1F9C:
	clc
	ret
