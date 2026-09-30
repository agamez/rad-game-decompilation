;; fn1E78_02C7: 1E78:02C7
;;   Called from:
;;     11C8:0361 (in fn11C8_0354)
;;     1229:04E0 (in fn1229_0486)
;;     1229:0E66 (in fn1229_0DCC)
fn1E78_02C7 proc
	mov	bx,sp
	mov	bx,ss:[bx+4h]
	mov	ax,34DDh
	mov	dx,12h
	cmp	dx,bx
	jnc	02F1h

l1E78_02D7:
	div	bx
	mov	bx,ax
	in	al,61h
	test	al,3h
	jnz	02E9h

l1E78_02E1:
	or	al,3h
	out	61h,al
	mov	al,0B6h
	out	43h,al

l1E78_02E9:
	mov	al,bl
	out	42h,al
	mov	al,bh
	out	42h,al

l1E78_02F1:
	retf	2h
