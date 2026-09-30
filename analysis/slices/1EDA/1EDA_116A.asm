;; fn1EDA_116A: 1EDA:116A
;;   Called from:
;;     0800:41A3 (in fn0800_4168)
;;     0C43:0154 (in fn0C43_00B9)
;;     1229:09CE (in fn1229_0735)
;;     1AB8:0943 (in fn1AB8_0887)
fn1EDA_116A proc
	call	119Ah
	jc	1182h

l1EDA_116F:
	mov	ax,cx
	mov	dx,bx
	mov	cx,es:[di+4h]
	cmp	cx,1h
	jz	1182h

l1EDA_117C:
	xor	bx,bx
	push	cs
	call	098Ah

l1EDA_1182:
	retf	4h
