;; fn1AB8_1492: 1AB8:1492
;;   Called from:
;;     0800:0FF9 (in fn0800_0D20)
;;     1229:0239 (in fn1229_0040)
fn1AB8_1492 proc
	push	bp
	mov	bp,sp
	sub	sp,100h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	push	word ptr [0B844h]
	push	word ptr [0B846h]
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	cs
	call	1D82h
	cmp	word ptr [0B892h],0h
	jnz	14EEh

l1AB8_14C6:
	cmp	word ptr [0B88Eh],0h
	jnz	14EEh

l1AB8_14CD:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	cs
	call	1E0Bh
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[0B844h]
	cwd
	add	ax,cx
	adc	dx,bx
	push	ax
	push	word ptr [0B846h]
	push	cs
	call	108Bh

l1AB8_14EE:
	mov	sp,bp
	pop	bp
	retf	4h
