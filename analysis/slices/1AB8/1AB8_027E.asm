;; fn1AB8_027E: 1AB8:027E
;;   Called from:
;;     133F:009B (in fn133F_0056)
fn1AB8_027E proc
	push	bp
	mov	bp,sp
	sub	sp,200h
	mov	ax,[bp+6h]
	cmp	ax,0h
	jnz	02A3h

l1AB8_028D:
	mov	di,0D9h
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_02A3:
	cmp	ax,0FFFFh
	jnz	02BEh

l1AB8_02A8:
	mov	di,0E2h
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_02BE:
	cmp	ax,0FFFEh
	jnz	02D9h

l1AB8_02C3:
	mov	di,0FFh
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_02D9:
	cmp	ax,0FFFDh
	jnz	0313h

l1AB8_02DE:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	di,11Eh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,0B756h
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,13Dh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_0313:
	cmp	ax,0FFFCh
	jnz	034Dh

l1AB8_0318:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	di,13Fh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,0B756h
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,13Dh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_034D:
	cmp	ax,0FFFBh
	jnz	0368h

l1AB8_0352:
	mov	di,15Ch
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_0368:
	cmp	ax,0FFFAh
	jnz	0383h

l1AB8_036D:
	mov	di,17Dh
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_0383:
	cmp	ax,0FFF9h
	jnz	039Eh

l1AB8_0388:
	mov	di,198h
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_039E:
	cmp	ax,0FFF8h
	jnz	03D8h

l1AB8_03A3:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	di,1B4h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,0B74Ch
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,13Dh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_03D8:
	cmp	ax,0FFF7h
	jnz	03F3h

l1AB8_03DD:
	mov	di,1CAh
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_03F3:
	cmp	ax,0FFF6h
	jnz	040Eh

l1AB8_03F8:
	mov	di,1E9h
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_040E:
	cmp	ax,0FFF5h
	jnz	0429h

l1AB8_0413:
	mov	di,213h
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_0429:
	cmp	ax,0FFF4h
	jnz	0444h

l1AB8_042E:
	mov	di,222h
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_0444:
	cmp	ax,0FFF3h
	jnz	047Dh

l1AB8_0449:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	di,235h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,0B74Ch
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,13Dh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_047D:
	cmp	ax,0FFF2h
	jnz	0497h

l1AB8_0482:
	mov	di,249h
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_0497:
	cmp	ax,0FFEEh
	jnz	04B1h

l1AB8_049C:
	mov	di,25Dh
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_04B1:
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	mov	di,26Dh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	ax,[bp+6h]
	cwd
	push	dx
	push	ax
	call	0000h
	call	far 1EDAh:0AACh
	mov	di,13Dh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h

l1AB8_04ED:
	mov	sp,bp
	pop	bp
	retf	2h
