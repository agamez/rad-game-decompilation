;; fn13E2_00FB: 13E2:00FB
;;   Called from:
;;     0800:293D (in fn0800_2827)
;;     0800:2DDB (in fn0800_2C0C)
fn13E2_00FB proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [0B6C1h],0h
	jz	0108h

l13E2_0105:
	jmp	018Fh

l13E2_0108:
	mov	byte ptr [0B6C1h],1h
	mov	byte ptr [0B6BEh],0h
	jmp	0118h

l13E2_0114:
	inc	byte ptr [0B6BEh]

l13E2_0118:
	cmp	byte ptr [0B6BEh],8h
	jnz	0132h

l13E2_011F:
	mov	al,[0B6BEh]
	xor	ah,ah
	push	ax
	push	0h
	push	0h
	push	0h
	call	far 1AB8h:1CBAh
	jmp	0179h

l13E2_0132:
	mov	al,[0B6BEh]
	xor	ah,ah
	push	ax
	mov	al,[0B6BEh]
	xor	ah,ah
	mov	di,ax
	mov	si,di
	shl	di,1h
	add	di,si
	mov	al,[di+50CCh]
	xor	ah,ah
	push	ax
	mov	al,[0B6BEh]
	xor	ah,ah
	mov	di,ax
	mov	si,di
	shl	di,1h
	add	di,si
	mov	al,[di+50CDh]
	xor	ah,ah
	push	ax
	mov	al,[0B6BEh]
	xor	ah,ah
	mov	di,ax
	mov	si,di
	shl	di,1h
	add	di,si
	mov	al,[di+50CEh]
	xor	ah,ah
	push	ax
	call	far 1AB8h:1CBAh

l13E2_0179:
	mov	al,[0B6BEh]
	xor	ah,ah
	push	ax
	mov	al,[0B6BEh]
	push	ax
	call	far 1AB8h:1342h
	cmp	byte ptr [0B6BEh],0Fh
	jnz	0114h

l13E2_018F:
	leave
	retf
13E2:0191    01 07                                         ..
