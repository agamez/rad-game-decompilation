;; fn1EDA_126C: 1EDA:126C
;;   Called from:
;;     1EDA:1220 (in fn1EDA_1216)
;;     1EDA:1267 (in fn1EDA_1265)
fn1EDA_126C proc
	mov	es,[537Ch]
	mov	di,80h
	mov	cl,es:[di]
	xor	ch,ch
	inc	di
	xor	bx,bx

l1EDA_127B:
	jcxz	1286h

l1EDA_127D:
	cmp	byte ptr es:[di],20h
	ja	1286h

l1EDA_1283:
	inc	di
	loop	127Dh

l1EDA_1286:
	mov	si,di
	jcxz	1293h

l1EDA_128A:
	cmp	byte ptr es:[di],20h
	jbe	1293h

l1EDA_1290:
	inc	di
	loop	128Ah

l1EDA_1293:
	mov	ax,di
	sub	ax,si
	jz	129Dh

l1EDA_1299:
	inc	bx
	dec	dx
	jnz	127Bh

l1EDA_129D:
	ret
