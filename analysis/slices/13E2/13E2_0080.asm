;; fn13E2_0080: 13E2:0080
;;   Called from:
;;     0800:1676 (in fn0800_166D)
;;     0800:3DBA (in fn0800_3D9D)
fn13E2_0080 proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [0B6C1h],0h
	jz	008Ch

l13E2_008A:
	jmp	00F9h

l13E2_008C:
	mov	byte ptr [0B6C1h],1h
	mov	byte ptr [0B6BEh],0h
	jmp	009Ch

l13E2_0098:
	inc	byte ptr [0B6BEh]

l13E2_009C:
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
	mov	al,[0B6BEh]
	xor	ah,ah
	push	ax
	mov	al,[0B6BEh]
	push	ax
	call	far 1AB8h:1342h
	cmp	byte ptr [0B6BEh],0Fh
	jnz	0098h

l13E2_00F9:
	leave
	retf
