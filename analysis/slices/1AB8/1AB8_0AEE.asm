;; fn1AB8_0AEE: 1AB8:0AEE
;;   Called from:
;;     1AB8:0E79 (in fn1AB8_0BAE)
fn1AB8_0AEE proc
	push	bp
	mov	bp,sp
	sub	sp,8h
	cmp	byte ptr [0B84Eh],0h
	jnz	0AFFh

l1AB8_0AFB:
	push	cs
	call	008Bh

l1AB8_0AFF:
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	push	word ptr [0B7C2h]
	push	word ptr [0B7C4h]
	mov	al,1h
	push	ax
	push	cs
	call	0F93h
	mov	di,0B87Ah
	push	ds
	push	di
	push	cs
	call	1384h
	mov	di,0B87Ah
	push	ds
	push	di
	push	cs
	call	129Ah
	push	cs
	call	1C5Ah
	cmp	ax,1h
	jz	0B36h

l1AB8_0B2F:
	xor	ax,ax
	push	ax
	push	cs
	call	1250h

l1AB8_0B36:
	mov	byte ptr [0B840h],0h
	push	cs
	call	1C4Ah
	push	ax
	push	cs
	call	1C32h
	lea	di,[bp-8h]
	push	ss
	push	di
	mov	ax,8h
	push	ax
	mov	al,0FFh
	push	ax
	call	far 1EDAh:1202h
	lea	di,[bp-8h]
	push	ss
	push	di
	push	cs
	call	1C4Ah
	push	ax
	push	cs
	call	11A0h
	mov	ax,1h
	push	ax
	push	cs
	call	1C4Ah
	push	ax
	push	cs
	call	1175h
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	mov	ax,1h
	push	ax
	push	cs
	call	10F4h
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	mov	ax,1h
	push	ax
	push	cs
	call	1536h
	xor	ax,ax
	push	ax
	mov	ax,2h
	push	ax
	push	cs
	call	14F4h
	xor	ax,ax
	push	ax
	push	cs
	call	194Eh
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	push	cs
	call	108Bh
	mov	sp,bp
	pop	bp
	retf
1AB8:0BAC                                     01 5C                   .\
