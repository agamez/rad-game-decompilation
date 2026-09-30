;; fn1E78_04D5: 1E78:04D5
;;   Called from:
;;     1E78:04CA (in fn1E78_047C)
fn1E78_04D5 proc
	inc	dh
	cmp	dh,[0B8B3h]
	jbe	04F5h

l1E78_04DD:
	dec	dh
	push	cx
	push	dx
	mov	ax,601h
	mov	bh,[0B8AEh]
	mov	cx,[0B8B0h]
	mov	dx,[0B8B2h]
	call	0609h
	pop	dx
	pop	cx

l1E78_04F5:
	ret
