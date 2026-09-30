;; fn1AB8_11A0: 1AB8:11A0
;;   Called from:
;;     1AB8:0B5F (in fn1AB8_0AEE)
;;     1AB8:106D (in fn1AB8_1028)
fn1AB8_11A0 proc
	push	bp
	mov	bp,sp
	sub	sp,8h
	les	di,[bp+8h]
	push	es
	push	di
	lea	di,[bp-8h]
	push	ss
	push	di
	mov	ax,8h
	push	ax
	call	far 1EDAh:0953h
	push	cs
	call	1C4Ah
	cmp	ax,[bp+6h]
	jnc	11CAh

l1AB8_11C2:
	mov	word ptr [0B818h],0FFF5h
	jmp	11F5h

l1AB8_11CA:
	mov	word ptr [0B862h],0Ch
	mov	ax,[bp+6h]
	mov	[0B864h],ax
	lea	di,[bp-8h]
	push	ss
	push	di
	mov	di,0B866h
	push	ds
	push	di
	mov	ax,8h
	push	ax
	call	far 1EDAh:0953h
	lea	di,[bp-8h]
	push	ss
	push	di
	push	word ptr [bp+6h]
	push	cs
	call	1968h

l1AB8_11F5:
	mov	sp,bp
	pop	bp
	retf	6h
