;; fn133F_02DF: 133F:02DF
;;   Called from:
;;     133F:049F (in fn133F_0352)
fn133F_02DF proc
	enter	200h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h

l133F_02F6:
	mov	al,[bp+0FF00h]
	xor	ah,ah
	mov	di,ax
	cmp	byte ptr [bp+di+0FF00h],20h
	jnz	0330h

l133F_0305:
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	1h
	mov	al,[bp+0FF00h]
	xor	ah,ah
	dec	ax
	push	ax
	call	far 1EDAh:0A6Bh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	jmp	02F6h

l133F_0330:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	al,[bp+0Ah]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,6DEAh
	push	ds
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	leave
	retf	6h
