;; fn1E78_047C: 1E78:047C
;;   Called from:
;;     1E78:015E (in fn1E78_0143)
;;     1E78:0163 (in fn1E78_0143)
;;     1E78:0477 (in fn1E78_0475)
;;     1E78:047A (in fn1E78_0475)
fn1E78_047C proc
	push	bx
	push	cx
	push	dx
	push	es
	push	ax
	call	04F6h
	pop	ax
	cmp	al,7h
	jz	04B3h

l1E78_0489:
	cmp	al,8h
	jz	04BAh

l1E78_048D:
	cmp	al,0Dh
	jz	04C4h

l1E78_0491:
	cmp	al,0Ah
	jz	04CAh

l1E78_0495:
	mov	ah,9h
	mov	bl,[0B8AEh]
	xor	bh,bh
	mov	cx,1h
	push	dx
	call	0609h
	pop	dx
	inc	dl
	cmp	dl,[0B8B2h]
	jbe	04CDh

l1E78_04AD:
	mov	dl,[0B8B0h]
	jmp	04CAh

l1E78_04B3:
	mov	ah,0Eh
	call	0609h
	jmp	04CDh

l1E78_04BA:
	cmp	dl,[0B8B0h]
	jz	04CDh

l1E78_04C0:
	dec	dl
	jmp	04CDh

l1E78_04C4:
	mov	dl,[0B8B0h]
	jmp	04CDh

l1E78_04CA:
	call	04D5h

l1E78_04CD:
	call	04FDh
	pop	es
	pop	dx
	pop	cx
	pop	bx
	ret
