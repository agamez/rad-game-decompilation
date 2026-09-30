;; fn1AB8_0887: 1AB8:0887
;;   Called from:
;;     1AB8:0A1C (in fn1AB8_097B)
;;     1AB8:1649 (in fn1AB8_1536)
fn1AB8_0887 proc
	push	bp
	mov	bp,sp
	sub	sp,302h
	les	di,[bp+0Eh]
	push	es
	push	di
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	les	di,[bp+0Ah]
	push	es
	push	di
	lea	di,[bp+0FDFEh]
	push	ss
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	mov	byte ptr [bp-1h],0h
	mov	word ptr [0B818h],0FFFDh
	les	di,[bp+6h]
	xor	ax,ax
	mov	es:[di],ax
	mov	di,0B6CAh
	push	ds
	push	di
	lea	di,[bp+0FCFEh]
	push	ss
	push	di
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FDFEh]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	call	far 1EDAh:0FA2h
	mov	di,0B6CAh
	push	ds
	push	di
	mov	ax,1h
	push	ax
	call	far 1EDAh:0FD0h
	call	far 1EDAh:04A2h
	or	ax,ax
	jz	0939h

l1AB8_0905:
	cmp	byte ptr [bp+0FEFEh],0h
	jnz	0910h

l1AB8_090C:
	jmp	096Dh
1AB8:090E                                           EB 29               .)

l1AB8_0910:
	mov	di,0B6CAh
	push	ds
	push	di
	lea	di,[bp+0FDFEh]
	push	ss
	push	di
	call	far 1EDAh:0FA2h
	mov	di,0B6CAh
	push	ds
	push	di
	mov	ax,1h
	push	ax
	call	far 1EDAh:0FD0h
	call	far 1EDAh:04A2h
	or	ax,ax
	jz	0939h

l1AB8_0937:
	jmp	096Dh

l1AB8_0939:
	xor	ax,ax
	mov	[0B818h],ax
	mov	di,0B6CAh
	push	ds
	push	di
	call	far 1EDAh:116Ah
	les	di,[bp+6h]
	mov	es:[di],ax
	les	di,[bp+6h]
	cmp	word ptr es:[di],0FFh
	jbe	0969h

l1AB8_0957:
	mov	ax,[bp+4h]
	mov	[0B818h],ax
	mov	di,0B6CAh
	push	ds
	push	di
	call	far 1EDAh:1051h
	jmp	096Dh

l1AB8_0969:
	mov	byte ptr [bp-1h],1h

l1AB8_096D:
	mov	al,[bp-1h]
	mov	sp,bp
	pop	bp
	ret	0Eh
1AB8:0976                   04 2E 42 47 49                      ..BGI
