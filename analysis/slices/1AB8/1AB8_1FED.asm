;; fn1AB8_1FED: 1AB8:1FED
;;   Called from:
;;     1AB8:1F47 (in fn1AB8_1F19)
;;     1AB8:1FB6 (in fn1AB8_1F9E)
fn1AB8_1FED proc
	mov	ax,1A00h
	int	10h
	cmp	al,1Ah
	jnz	200Ch

l1AB8_1FF6:
	cmp	bl,7h
	jz	200Ah

l1AB8_1FFB:
	cmp	bl,8h
	jz	200Ah

l1AB8_2000:
	cmp	bl,0Bh
	jc	200Ch

l1AB8_2005:
	cmp	bl,0Ch
	ja	200Ch

l1AB8_200A:
	stc
	ret

l1AB8_200C:
	clc
	ret
