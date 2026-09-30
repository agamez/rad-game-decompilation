;; fn1AB8_129A: 1AB8:129A
;;   Called from:
;;     1AB8:0B22 (in fn1AB8_0AEE)
fn1AB8_129A proc
	push	bp
	mov	bp,sp
	sub	sp,1Ch
	cmp	byte ptr [0B84Eh],0h
	jnz	12AAh

l1AB8_12A7:
	jmp	133Ch

l1AB8_12AA:
	les	di,[bp+6h]
	mov	[bp-1Ah],di
	mov	[bp-18h],es
	les	di,[bp-1Ah]
	cmp	byte ptr es:[di],10h
	jbe	12C2h

l1AB8_12BC:
	mov	byte ptr [bp-3h],10h
	jmp	12CBh

l1AB8_12C2:
	les	di,[bp-1Ah]
	mov	al,es:[di]
	mov	[bp-3h],al

l1AB8_12CB:
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	[bp-1Ch],ax
	xor	ax,ax
	cmp	ax,[bp-1Ch]
	jg	130Dh

l1AB8_12DB:
	mov	[bp-2h],ax
	jmp	12E3h

l1AB8_12E0:
	inc	word ptr [bp-2h]

l1AB8_12E3:
	mov	ax,[bp-2h]
	les	di,[bp-1Ah]
	add	di,ax
	cmp	byte ptr es:[di+1h],0FFh
	jle	1305h

l1AB8_12F2:
	mov	ax,[bp-2h]
	les	di,[bp-1Ah]
	add	di,ax
	mov	al,es:[di+1h]
	mov	di,[bp-2h]
	mov	[di+0B87Bh],al

l1AB8_1305:
	mov	ax,[bp-2h]
	cmp	ax,[bp-1Ch]
	jnz	12E0h

l1AB8_130D:
	les	di,[bp-1Ah]
	cmp	byte ptr es:[di+1h],0FFh
	jz	131Ch

l1AB8_1317:
	mov	byte ptr [0B840h],0h

l1AB8_131C:
	mov	di,0B87Ah
	push	ds
	push	di
	lea	di,[bp-16h]
	push	ss
	push	di
	mov	ax,11h
	push	ax
	call	far 1EDAh:11DFh
	mov	byte ptr [bp-5h],0h
	lea	di,[bp-16h]
	push	ss
	push	di
	push	cs
	call	1CEDh

l1AB8_133C:
	mov	sp,bp
	pop	bp
	retf	4h
