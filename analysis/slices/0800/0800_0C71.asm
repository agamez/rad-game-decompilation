;; fn0800_0C71: 0800:0C71
;;   Called from:
;;     0800:27F7 (in fn0800_2401)
;;     0800:2ADE (in fn0800_2827)
;;     0800:3087 (in fn0800_2C0C)
;;     0800:364A (in fn0800_31B7)
fn0800_0C71 proc
	push	bp
	mov	bp,sp
	mov	ax,[58D8h]
	mov	dx,[58DAh]
	mov	cx,3Ch
	xor	bx,bx
	call	far 1EDAh:098Ah
	mov	[58CCh],ax
	mov	[58CEh],dx
	mov	ax,[58D8h]
	mov	dx,[58DAh]
	mov	cx,3Ch
	xor	bx,bx
	call	far 1EDAh:098Ah
	mov	ax,cx
	mov	dx,bx
	mov	[58DCh],ax
	mov	[58DEh],dx
	mov	ax,[58DCh]
	mov	dx,[58DEh]
	cmp	dx,[58CAh]
	jnz	0CBBh

l0800_0CB5:
	cmp	ax,[58C8h]
	jz	0CCCh

l0800_0CBB:
	call	0AA1h
	mov	ax,[58DCh]
	mov	dx,[58DEh]
	mov	[58C8h],ax
	mov	[58CAh],dx

l0800_0CCC:
	mov	ax,[58CCh]
	mov	dx,[58CEh]
	cmp	dx,[58C6h]
	jnz	0CDFh

l0800_0CD9:
	cmp	ax,[58C4h]
	jz	0CF0h

l0800_0CDF:
	call	0B42h
	mov	ax,[58CCh]
	mov	dx,[58CEh]
	mov	[58C4h],ax
	mov	[58C6h],dx

l0800_0CF0:
	cmp	word ptr [58DAh],0h
	jl	0D00h

l0800_0CF7:
	jg	0D05h

l0800_0CF9:
	cmp	word ptr [58D8h],0h
	ja	0D05h

l0800_0D00:
	call	08E9h
	jmp	0D05h

l0800_0D05:
	leave
	ret
0800:0D07                      07 52 41 44 2E 4D 45 4D 02        .RAD.MEM.
0800:0D10 41 41 04 41 41 41 41 01 41 06 41 41 41 41 41 41 AA.AAAA.A.AAAAAA
