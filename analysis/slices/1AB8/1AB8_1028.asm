;; fn1AB8_1028: 1AB8:1028
;;   Called from:
;;     0800:003A (in fn0800_0024)
;;     0C74:0092 (in fn0C74_007C)
;;     1229:0016 (in fn1229_0000)
;;     1229:0ABD (in fn1229_0AA8)
;;     1229:0B5A (in fn1229_0AA8)
;;     133F:01CF (in fn133F_014B)
fn1AB8_1028 proc
	push	bp
	mov	bp,sp
	sub	sp,4h
	mov	ax,[0B862h]
	mov	dx,[0B864h]
	mov	[bp-4h],ax
	mov	[bp-2h],dx
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	push	cs
	call	1175h
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	mov	ax,[0B856h]
	sub	ax,[0B852h]
	push	ax
	mov	ax,[0B858h]
	sub	ax,[0B854h]
	push	ax
	push	cs
	call	1B3Eh
	cmp	word ptr [bp-4h],0Ch
	jnz	1073h

l1AB8_1065:
	mov	di,0B866h
	push	ds
	push	di
	push	word ptr [bp-2h]
	push	cs
	call	11A0h
	jmp	107Dh

l1AB8_1073:
	push	word ptr [bp-4h]
	push	word ptr [bp-2h]
	push	cs
	call	1175h

l1AB8_107D:
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	push	cs
	call	108Bh
	mov	sp,bp
	pop	bp
	retf
