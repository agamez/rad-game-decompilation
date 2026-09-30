;; fn1EDA_07E9: 1EDA:07E9
;;   Called from:
;;     1EDA:07A9 (in fn1EDA_079A)
fn1EDA_07E9 proc
	push	cx
	push	si
	push	ds
	mov	dx,2014h
	mov	ds,dx
	mov	es:[di+8h],bx
	push	es
	push	di
	push	es
	push	di
	call	dword ptr es:[di+14h]
	or	ax,ax
	jz	0804h
