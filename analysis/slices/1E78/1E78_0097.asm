;; fn1E78_0097: 1E78:0097
;;   Called from:
;;     1E78:003E (in fn1E78_002E)
;;     1E78:0171 (in fn1E78_016B)
fn1E78_0097 proc
	mov	dx,40h
	mov	es,dx
	and	byte ptr es:[0087h],0FEh
	cmp	al,7h
	jz	00ACh

l1E78_00A6:
	cmp	al,4h
	jc	00ACh

l1E78_00AA:
	mov	al,3h

l1E78_00AC:
	push	ax
	mov	ah,0h
	call	0609h
	pop	ax
	or	ah,ah
	jz	00E4h

l1E78_00B7:
	mov	ax,1112h
	mov	bl,0h
	call	0609h
	mov	ax,1130h
	mov	bh,0h
	mov	dl,0h
	call	0609h
	cmp	dl,2Ah
	jnz	00E4h

l1E78_00CE:
	or	byte ptr es:[0087h],1h
	mov	ax,100h
	mov	cx,600h
	call	0609h
	mov	ah,12h
	mov	bl,20h
	call	0609h

l1E78_00E4:
	ret
