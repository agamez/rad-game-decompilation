;; fn133F_0352: 133F:0352
;;   Called from:
;;     1229:0D0E (in fn1229_0CCE)
;;     1229:0D24 (in fn1229_0CCE)
;;     1229:0D3A (in fn1229_0CCE)
;;     1229:0D50 (in fn1229_0CCE)
;;     1229:0D66 (in fn1229_0CCE)
fn133F_0352 proc
	enter	104h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	inc	byte ptr [6CD0h]
	mov	dl,[bp+12h]
	mov	al,[6CD0h]
	xor	ah,ah
	mov	di,ax
	mov	[di+6DCAh],dl
	mov	dx,[bp+10h]
	mov	al,[6CD0h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	[di+6CD2h],dx
	mov	dx,[bp+0Ch]
	mov	al,[6CD0h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	[di+6D10h],dx
	mov	dx,[bp+0Eh]
	mov	al,[6CD0h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	[di+6D4Eh],dx
	mov	dx,[bp+0Ah]
	mov	al,[6CD0h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	[di+6D8Ch],dx
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	call	far 1AB8h:112Eh
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	mov	ax,[bp+10h]
	sub	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Eh]
	add	ax,[50CAh]
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+10h]
	sub	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Eh]
	add	ax,[50CAh]
	push	ax
	mov	ax,[bp+10h]
	sub	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Ah]
	add	ax,[50CAh]
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+10h]
	sub	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Ah]
	add	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Ch]
	sub	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Ah]
	add	ax,[50CAh]
	push	ax
	call	far 1AB8h:1AF6h
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	mov	ax,[bp+0Ch]
	sub	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Ah]
	add	ax,[50CAh]
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+10h]
	sub	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Ah]
	add	ax,[50CAh]
	push	ax
	push	word ptr [bp+10h]
	push	word ptr [bp+0Ah]
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ch]
	sub	ax,[bp+10h]
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,[bp+10h]
	push	ax
	mov	ax,[bp+0Ah]
	sub	ax,[bp+0Eh]
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,[bp+0Eh]
	push	ax
	push	0h
	push	1h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	cs
	call	014Bh
	mov	al,[6CD0h]
	push	ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	cs
	call	02DFh
	leave
	retf	0Eh
