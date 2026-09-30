;; fn1229_0C58: 1229:0C58
;;   Called from:
;;     1229:0CFA (in fn1229_0CCE)
;;     1229:10CB (in fn1229_0DCC)
fn1229_0C58 proc
	enter	4h,0h
	mov	al,[6CBAh]
	mov	[bp-3h],al
	mov	byte ptr [bp-1h],0h
	jmp	0C6Bh

l1229_0C68:
	inc	byte ptr [bp-1h]

l1229_0C6B:
	mov	byte ptr [bp-2h],0h
	jmp	0C74h

l1229_0C71:
	inc	byte ptr [bp-2h]

l1229_0C74:
	mov	al,[bp-2h]
	xor	ah,ah
	imul	ax,ax,16h
	add	ax,59h
	push	ax
	mov	al,[bp-1h]
	xor	ah,ah
	imul	ax,ax,16h
	add	ax,187h
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5992h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	inc	byte ptr [bp-3h]
	cmp	byte ptr [bp-2h],18h
	jnz	0C71h

l1229_0CAC:
	cmp	byte ptr [bp-1h],3h
	jnz	0C68h

l1229_0CB2:
	leave
	ret
1229:0CB4             04 53 77 61 70 03 3C 3C 2D 03 2B 3E     .Swap.<<-.+>
1229:0CC0 3E 04 54 65 73 74 04 51 75 69 74 00 01 25       >.Test.Quit..%
