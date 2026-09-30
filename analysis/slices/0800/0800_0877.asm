;; fn0800_0877: 0800:0877
;;   Called from:
;;     0800:27FA (in fn0800_2401)
;;     0800:2AE1 (in fn0800_2827)
;;     0800:2AF5 (in fn0800_2827)
;;     0800:308A (in fn0800_2C0C)
;;     0800:30B1 (in fn0800_2C0C)
;;     0800:364D (in fn0800_31B7)
;;     0800:365E (in fn0800_31B7)
fn0800_0877 proc
	enter	2h,0h
	mov	byte ptr [bp-1h],0h
	mov	byte ptr [bp-2h],0h
	jmp	0888h

l0800_0885:
	inc	byte ptr [bp-2h]

l0800_0888:
	mov	al,[bp-2h]
	xor	ah,ah
	mov	di,ax
	cmp	byte ptr [di+5EB0h],5Eh
	jnz	08B1h

l0800_0896:
	mov	al,[bp-2h]
	xor	ah,ah
	imul	ax,ax,16h
	add	ax,0Bh
	push	ax
	push	176h
	call	far 1AB8h:1E3Ch
	cmp	ax,0Fh
	jz	08B1h

l0800_08AF:
	jmp	08BBh

l0800_08B1:
	cmp	byte ptr [bp-2h],1Ch
	jnz	0885h

l0800_08B7:
	mov	byte ptr [bp-1h],1h

l0800_08BB:
	mov	al,[bp-1h]
	leave
	ret
