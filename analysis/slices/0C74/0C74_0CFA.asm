;; fn0C74_0CFA: 0C74:0CFA
;;   Called from:
;;     0C74:1CC5 (in fn0C74_1B3B)
;;     0C74:1CDD (in fn0C74_1B3B)
;;     0C74:1D90 (in fn0C74_1B3B)
;;     0C74:2BA9 (in fn0C74_2AD9)
;;     0C74:3636 (in fn0C74_3615)
fn0C74_0CFA proc
	enter	2h,0h
	mov	word ptr [5968h],1h
	mov	al,[bp+4h]
	cmp	al,1h
	jc	0D3Fh

l0C74_0D0B:
	mov	[bp-1h],al
	jmp	0D13h

l0C74_0D10:
	dec	byte ptr [bp-1h]

l0C74_0D13:
	push	64h
	push	14h
	call	070Dh
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5904h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	byte ptr [bp-1h],1h
	jnz	0D10h

l0C74_0D3F:
	leave
	ret	2h
