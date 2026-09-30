;; fn1AB8_17AE: 1AB8:17AE
;;   Called from:
;;     0800:425F (in fn0800_4255)
fn1AB8_17AE proc
	push	bp
	mov	bp,sp
	xor	ax,ax
	mov	[0B818h],ax
	mov	word ptr [0B7B6h],1000h
	push	cs
	call	1A84h
	call	0813h
	mov	ax,51Fh
	mov	dx,1AB8h
	mov	[0B6C2h],ax
	mov	[0B6C4h],dx
	mov	ax,538h
	mov	dx,1AB8h
	mov	[0B6C6h],ax
	mov	[0B6C8h],dx
	mov	byte ptr [0B74Ch],0h
	mov	byte ptr [0B756h],0h
	mov	word ptr [0B7B8h],6h
	mov	word ptr [0B7BAh],0Ah
	mov	word ptr [fn0800_3850],1h
	mov	word ptr [0B84Ah],1h
	mov	word ptr [0B84Ch],1h
	pop	bp
	retf
