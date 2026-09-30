;; fn0800_0BEC: 0800:0BEC
;;   Called from:
;;     0800:2619 (in fn0800_2401)
;;     0800:293A (in fn0800_2827)
;;     0800:2DD8 (in fn0800_2C0C)
;;     0800:340D (in fn0800_31B7)
fn0800_0BEC proc
	push	bp
	mov	bp,sp
	mov	al,[53DDh]
	xor	ah,ah
	xor	dx,dx
	mov	[58CCh],ax
	mov	[58CEh],dx
	xor	ax,ax
	mov	[58DCh],ax
	mov	[58DEh],ax
	mov	ax,[58CCh]
	mov	dx,[58CEh]
	mov	[58C4h],ax
	mov	[58C6h],dx
	mov	ax,[58DCh]
	mov	dx,[58DEh]
	mov	[58C8h],ax
	mov	[58CAh],dx
	mov	byte ptr [53E0h],0h
	mov	byte ptr [53E1h],0h
	mov	al,[53DDh]
	xor	ah,ah
	imul	ax,ax,5Fh
	cwd
	mov	[58D4h],ax
	mov	[58D6h],dx
	push	8h
	call	far 1AB8h:1C32h
	push	233h
	push	196h
	mov	di,0BE1h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0Ah
	call	far 1AB8h:1C32h
	push	234h
	push	197h
	mov	di,0BE1h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	call	0B42h
	call	0AA1h
	leave
	ret
