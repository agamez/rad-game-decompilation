;; fn11C8_0236: 11C8:0236
;;   Called from:
;;     11C8:034E (in fn11C8_033B)
;;     11C8:038C (in fn11C8_0354)
fn11C8_0236 proc
	push	bp
	mov	bp,sp
	mov	ax,[5978h]
	add	ax,4h
	mov	dx,ax
	mov	al,4h
	out	dx,al
	mov	ax,[5978h]
	add	ax,5h
	mov	dx,ax
	mov	al,[bp+6h]
	out	dx,al
	mov	ax,[5978h]
	add	ax,4h
	mov	dx,ax
	mov	al,22h
	out	dx,al
	mov	ax,[5978h]
	add	ax,5h
	mov	dx,ax
	mov	al,[bp+6h]
	out	dx,al
	mov	ax,[5978h]
	add	ax,4h
	mov	dx,ax
	mov	al,26h
	out	dx,al
	mov	ax,[5978h]
	add	ax,5h
	mov	dx,ax
	mov	al,[bp+6h]
	out	dx,al
	leave
	retf	2h
