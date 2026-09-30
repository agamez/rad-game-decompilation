;; fn1AB8_0813: 1AB8:0813
;;   Called from:
;;     1AB8:0CE2 (in fn1AB8_0BAE)
;;     1AB8:0D6B (in fn1AB8_0BAE)
;;     1AB8:0DDC (in fn1AB8_0BAE)
;;     1AB8:0E5C (in fn1AB8_0BAE)
;;     1AB8:0F05 (in fn1AB8_0EB5)
;;     1AB8:17C0 (in fn1AB8_17AE)
fn1AB8_0813 proc
	push	bp
	mov	bp,sp
	mov	ax,8Bh
	mov	dx,1AB8h
	mov	[0B820h],ax
	mov	[0B822h],dx
	mov	ax,8Bh
	mov	dx,1AB8h
	mov	[0B832h],ax
	mov	[0B834h],dx
	xor	ax,ax
	mov	[0B824h],ax
	mov	[0B826h],ax
	xor	ax,ax
	mov	[0B836h],ax
	mov	[0B838h],ax
	xor	ax,ax
	mov	[0B828h],ax
	mov	[0B82Ah],ax
	xor	ax,ax
	mov	[0B82Eh],ax
	mov	[0B830h],ax
	xor	ax,ax
	mov	[0B7E0h],ax
	mov	[0B7E2h],ax
	xor	ax,ax
	mov	[0B7E4h],ax
	xor	ax,ax
	mov	[0B7FAh],ax
	mov	[0B7FCh],ax
	xor	ax,ax
	mov	[0B7FEh],ax
	mov	byte ptr [0B7EAh],0h
	mov	word ptr [0B84Ah],1h
	mov	word ptr [0B84Ch],1h
	xor	ax,ax
	mov	[0B74Ah],ax
	mov	byte ptr [0B84Eh],0h
	pop	bp
	ret
