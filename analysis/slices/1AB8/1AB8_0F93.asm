;; fn1AB8_0F93: 1AB8:0F93
;;   Called from:
;;     0800:0035 (in fn0800_0024)
;;     0800:0051 (in fn0800_0024)
;;     0C74:008D (in fn0C74_007C)
;;     0C74:00A9 (in fn0C74_007C)
;;     1229:0011 (in fn1229_0000)
;;     1229:002D (in fn1229_0000)
;;     1229:0AB8 (in fn1229_0AA8)
;;     1229:0ACE (in fn1229_0AA8)
;;     1229:0B55 (in fn1229_0AA8)
;;     1229:0B6B (in fn1229_0AA8)
;;     133F:01CA (in fn133F_014B)
;;     133F:01E6 (in fn133F_014B)
;;     1AB8:0B10 (in fn1AB8_0AEE)
fn1AB8_0F93 proc
	push	bp
	mov	bp,sp
	cmp	word ptr [bp+0Eh],0h
	jl	0FE0h

l1AB8_0F9C:
	cmp	word ptr [bp+0Ch],0h
	jl	0FE0h

l1AB8_0FA2:
	mov	ax,[0B7C2h]
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0Ah]
	cwd
	cmp	dx,bx
	jg	0FE0h

l1AB8_0FB3:
	jl	0FB9h

l1AB8_0FB5:
	cmp	ax,cx
	ja	0FE0h

l1AB8_0FB9:
	mov	ax,[0B7C4h]
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+8h]
	cwd
	cmp	dx,bx
	jg	0FE0h

l1AB8_0FCA:
	jl	0FD0h

l1AB8_0FCC:
	cmp	ax,cx
	ja	0FE0h

l1AB8_0FD0:
	mov	ax,[bp+0Ah]
	cmp	ax,[bp+0Eh]
	jl	0FE0h

l1AB8_0FD8:
	mov	ax,[bp+8h]
	cmp	ax,[bp+0Ch]
	jge	0FE8h

l1AB8_0FE0:
	mov	word ptr [0B818h],0FFF5h
	jmp	1024h

l1AB8_0FE8:
	mov	ax,[bp+0Eh]
	mov	[0B852h],ax
	mov	ax,[bp+0Ch]
	mov	[0B854h],ax
	mov	ax,[bp+0Ah]
	mov	[0B856h],ax
	mov	ax,[bp+8h]
	mov	[0B858h],ax
	mov	al,[bp+6h]
	mov	[0B85Ah],al
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	mov	al,[bp+6h]
	push	ax
	push	cs
	call	1895h
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	push	cs
	call	108Bh

l1AB8_1024:
	pop	bp
	retf	0Ah
